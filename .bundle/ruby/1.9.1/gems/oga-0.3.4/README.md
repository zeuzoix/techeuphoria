# Oga

Oga is an XML/HTML parser written in Ruby. It provides an easy to use API for
parsing, modifying and querying documents (using XPath expressions). Oga does
not require system libraries such as libxml, making it easier and faster to
install on various platforms. To achieve better performance Oga uses a small,
native extension (C for MRI/Rubinius, Java for JRuby).

Oga provides an API that allows you to safely parse and query documents in a
multi-threaded environment, without having to worry about your applications
blowing up.

From [Wikipedia][oga-wikipedia]:

> Oga: A large two-person saw used for ripping large boards in the days before
> power saws. One person stood on a raised platform, with the board below him,
> and the other person stood underneath them.

## Examples

Parsing a simple string of XML:

    Oga.parse_xml('<people><person>Alice</person></people>')

Parsing a simple string of HTML:

    Oga.parse_html('<link rel="stylesheet" href="foo.css">')

Parsing an IO handle pointing to XML (this also works when using
`Oga.parse_html`):

    handle = File.open('path/to/file.xml')

    Oga.parse_xml(handle)

Parsing an IO handle using the pull parser:

    handle = File.open('path/to/file.xml')
    parser = Oga::XML::PullParser.new(handle)

    parser.parse do |node|
      parser.on(:text) do
        puts node.text
      end
    end

Using an Enumerator to download and parse an XML document on the fly:

    enum = Enumerator.new do |yielder|
      HTTPClient.get('http://some-website.com/some-big-file.xml') do |chunk|
        yielder << chunk
      end
    end

    document = Oga.parse_xml(enum)

Parse a string of XML using the SAX parser:

    class ElementNames
      attr_reader :names

      def initialize
        @names = []
      end

      def on_element(namespace, name, attrs = {})
        @names << name
      end
    end

    handler = ElementNames.new

    Oga.sax_parse_xml(handler, '<foo><bar></bar></foo>')

    handler.names # => ["foo", "bar"]

Querying a document using XPath:

    document = Oga.parse_xml <<-EOF
    <people>
      <person id="1">
        <name>Alice</name>
        <age>28</name>
      </person>
    </people>
    EOF

    # The "xpath" method returns an enumerable (Oga::XML::NodeSet) that you can
    # iterate over.
    document.xpath('people/person').each do |person|
      puts person.get('id') # => "1"

      # The "at_xpath" method returns a single node from a set, it's the same as
      # person.xpath('name').first.
      puts person.at_xpath('name').text # => "Alice"
    end

Querying the same document using CSS:

    document = Oga.parse_xml <<-EOF
    <people>
      <person id="1">
        <name>Alice</name>
        <age>28</name>
      </person>
    </people>
    EOF

    # The "css" method returns an enumerable (Oga::XML::NodeSet) that you can
    # iterate over.
    document.css('people person').each do |person|
      puts person.get('id') # => "1"

      # The "at_css" method returns a single node from a set, it's the same as
      # person.css('name').first.
      puts person.at_css('name').text # => "Alice"
    end

Modifying a document and serializing it back to XML:

    document = Oga.parse_xml('<people><person>Alice</person></people>')
    name     = document.at_xpath('people/person[1]/text()')

    name.text = 'Bob'

    document.to_xml # => "<people><person>Bob</person></people>"

Querying a document using a namespace:

    document = Oga.parse_xml('<root xmlns:x="foo"><x:div></x:div></root>')
    div      = document.xpath('root/x:div').first

    div.namespace # => Namespace(name: "x" uri: "foo")

## Features

* Support for parsing XML and HTML(5)
  * DOM parsing
  * Stream/pull parsing
  * SAX parsing
* Low memory footprint
* High performance, if something doesn't perform well enough it's a bug
* Support for XPath 1.0
* CSS3 selector support
* XML namespace support (registering, querying, etc)

## Requirements

| Ruby     | Required      | Recommended |
|:---------|:--------------|:------------|
| MRI      | >= 1.9.3      | >= 2.1.2    |
| Rubinius | >= 2.2        | >= 2.2.10   |
| JRuby    | >= 1.7        | >= 1.7.12   |
| Maglev   | Not supported |             |
| Topaz    | Not supported |             |
| mruby    | Not supported |             |

Maglev and Topaz are not supported due to the lack of a C API (that I know of)
and the lack of active development of these Ruby implementations. mruby is not
supported because it's a very different implementation all together.

To install Oga on MRI or Rubinius you'll need to have a working compiler such as
gcc or clang. Oga's C extension can be compiled with both. JRuby does not
require a compiler as the native extension is compiled during the Gem building
process and bundled inside the Gem itself.

## Thread Safety

Documents parsed using Oga are thread-safe as long as they are not modified by
multiple threads at the same time. Querying documents using XPath can be done by
multiple threads just fine. Write operations, such as removing attributes, are
_not_ thread-safe and should not be done by multiple threads at once.

It is advised that you do not share parsed documents between threads unless you
_really_ have to.

## Namespace Support

Oga fully supports parsing/registering XML namespaces as well as querying them
using XPath. For example, take the following XML:

    <root xmlns="http://example.com">
        <bar>bar</bar>
    </root>

If one were to try and query the `bar` element (e.g. using XPath `root/bar`)
they'd end up with an empty node set. This is due to `<root>` defining an
alternative default namespace. Instead you can query this element using the
following XPath:

    *[local-name() = "root"]/*[local-name() = "bar"]

Alternatively, if you don't really care where the `<bar>` element is located you
can use the following:

    descendant::*[local-name() = "bar"]

And if you want to specify an explici namespace URI, you can use this:

    descendant::*[local-name() = "bar" and namespace-uri() = "http://example.com"]

Unlike Nokogiri, Oga does _not_ provide a way to create "dynamic" namespaces.
That is, Nokogiri allows one to query the above document as following:

    document = Nokogiri::XML('<root xmlns="http://example.com"><bar>bar</bar></root>')

    document.xpath('x:root/x:bar', :x => 'http://example.com')

Oga does have a small trick you can use to cut down the size of your XPath
queries. Because Oga assigns the name "xmlns" to default namespaces you can use
this in your XPath queries:

    document = Oga.parse_xml('<root xmlns="http://example.com"><bar>bar</bar></root>')

    document.xpath('xmlns:root/xmlns:bar')

When using this you can still restrict the query to the correct namespace URI:

    document.xpath('xmlns:root[namespace-uri() = "http://example.com"]/xmlns:bar')

In the future I might add an API to ease this process, although at this time I
have little interest in providing an API similar to Nokogiri.

## Documentation

The documentation is best viewed [on the documentation website][doc-website].

* {file:CONTRIBUTING Contributing}
* {file:changelog Changelog}
* {file:migrating\_from\_nokogiri Migrating From Nokogiri}
* {Oga::XML::Parser XML Parser}
* {Oga::XML::SaxParser XML SAX Parser}
* {file:xml\_namespaces XML Namespaces}

## Native Extension Setup

The native extensions can be found in `ext/` and are divided into a C and Java
extension. These extensions are only used for the XML lexer built using Ragel.
The grammar for this lexer is shared between C and Java and can be found in
`ext/ragel/base_lexer.rl`.

The extensions delegate most of their work back to Ruby code. As a result of
this maintenance of this codebase is much easier. If one wants to change the
grammar they only have to do so in one place and they don't have to worry about
C and/or Java specific details.

For more details on calling Ruby methods from Ragel see the source
documentation in `ext/ragel/base_lexer.rl`.

## Why Another HTML/XML parser?

Currently there are a few existing parser out there, the most famous one being
[Nokogiri][nokogiri]. Another parser that's becoming more popular these days is
[Ox][ox]. Ruby's standard library also comes with REXML.

The sad truth is that these existing libraries are problematic in their own
ways. Nokogiri for example is extremely unstable on Rubinius. On MRI it works
because of the non conccurent nature of MRI, on JRuby it works because it's
implemented as Java. Nokogiri also uses libxml2 which is a massive beast of a
library, is not thread-safe and problematic to install on certain platforms
(apparently). I don't want to compile libxml2 every time I install Nokogiri
either.

To give an example about the issues with Nokogiri on Rubinius (or any other
Ruby implementation that is not MRI or JRuby), take a look at these issues:

* <https://github.com/rubinius/rubinius/issues/2957>
* <https://github.com/rubinius/rubinius/issues/2908>
* <https://github.com/rubinius/rubinius/issues/2462>
* <https://github.com/sparklemotion/nokogiri/issues/1047>
* <https://github.com/sparklemotion/nokogiri/issues/939>

Some of these have been fixed, some have not. The core problem remains:
Nokogiri acts in a way that there can be a large number of places where it
*might* break due to throwing around void pointers and what not and expecting
that things magically work. Note that I have nothing against the people running
these projects, I just heavily, *heavily* dislike the resulting codebase one
has to deal with today.

Ox looks very promising but it lacks a rather crucial feature: parsing HTML
(without using a SAX API). It's also again a C extension making debugging more
of a pain (at least for me).

I just want an XML/HTML parser that I can rely on stability wise and that is
written in Ruby so I can actually debug it. In theory it should also make it
easier for other Ruby developers to contribute.

## License

All source code in this repository is licensed under the MIT license unless
specified otherwise. A copy of this license can be found in the file "LICENSE"
in the root directory of this repository.

[nokogiri]: https://github.com/sparklemotion/nokogiri
[oga-wikipedia]: https://en.wikipedia.org/wiki/Japanese_saw#Other_Japanese_saws
[ox]: https://github.com/ohler55/ox
[doc-website]: http://code.yorickpeterse.com/oga/latest/
