require './stylesheets/_themes/lib/functions.rb'
require 'zurb-foundation'

Awestruct::Extensions::Pipeline.new do
  helper Awestruct::Extensions::Partial
  extension Awestruct::Extensions::Posts.new '/posts'
  extension Awestruct::Extensions::Paginator.new :posts, '/index',
    :page_name => 'posts/page/', :per_page => 5
  extension Awestruct::Extensions::Paginator.new :posts, '/blog',
    :page_name => 'posts/page/', :per_page => 10
  extension Awestruct::Extensions::Tagger.new :posts, '/index', 'posts/tag', 
    :per_page => 5
  extension Awestruct::Extensions::Atomizer.new :posts, 'feed.xml',
    :num_entries => 10

  # extension Awestruct::Extensions::Indexifier.new
  # Indexifier *must* come before Atomizer
  # extension Awestruct::Extensions::Atomizer.new :posts, '/feed.atom'
end
