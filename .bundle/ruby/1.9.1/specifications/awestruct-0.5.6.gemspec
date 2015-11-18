# -*- encoding: utf-8 -*-

Gem::Specification.new do |s|
  s.name = "awestruct"
  s.version = "0.5.6"

  s.required_rubygems_version = Gem::Requirement.new(">= 0") if s.respond_to? :required_rubygems_version=
  s.authors = ["Bob McWhirter", "Jason Porter", "Lance Ball", "Dan Allen", "Torsten Curdt", "other contributors"]
  s.date = "2015-08-28"
  s.description = "Awestruct is a static site baking and publishing tool. It supports an extensive list of both templating and markup languages via Tilt (Haml, Slim, AsciiDoc, Markdown, Sass via Compass, etc), provides mobile-first layout and styling via Bootstrap or Foundation, offers a variety of deployment options (rsync, git, S3), handles site optimizations (minification, compression, cache busting), includes built-in extensions such as blog post management and is highly extensible."
  s.email = ["bob@mcwhirter.org", "lightguard.jp@gmail.com", "lball@redhat.com", "dan.j.allen@gmail.com", "tcurdt@vafer.org"]
  s.executables = ["awestruct"]
  s.extra_rdoc_files = ["README.md"]
  s.files = ["bin/awestruct", "README.md"]
  s.homepage = "http://awestruct.org"
  s.licenses = ["MIT"]
  s.rdoc_options = ["--charset=UTF-8"]
  s.require_paths = ["lib"]
  s.requirements = ["Any markup languages you are using and its dependencies.\nHaml and Markdown filters are touchy things. Redcarpet or Rdiscount work well if you're running on MRI. JRuby should be using haml 4.0.0+ with Kramdown.'\n"]
  s.rubyforge_project = "awestruct"
  s.rubygems_version = "1.8.23"
  s.summary = "Static site baking and publishing tool"

  if s.respond_to? :specification_version then
    s.specification_version = 4

    if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
      s.add_runtime_dependency(%q<haml>, [">= 4.0.5", "~> 4.0"])
      s.add_runtime_dependency(%q<asciidoctor>, [">= 1.5.2", "~> 1.5"])
      s.add_runtime_dependency(%q<tilt>, [">= 2.0.1", "~> 2.0"])
      s.add_runtime_dependency(%q<mime-types>, ["~> 2.1"])
      s.add_runtime_dependency(%q<rest-client>, [">= 1.7.2", "~> 1.7"])
      s.add_runtime_dependency(%q<listen>, [">= 2.7.1", "~> 2.7"])
      s.add_runtime_dependency(%q<rack>, [">= 1.5.2", "~> 1.5"])
      s.add_runtime_dependency(%q<git>, [">= 1.2.6", "~> 1.2"])
      s.add_runtime_dependency(%q<guard-livereload>, [">= 2.1.2", "~> 2.1"])
      s.add_runtime_dependency(%q<colorize>, [">= 0.7.1", "~> 0.7"])
      s.add_runtime_dependency(%q<oga>, ["~> 0.3"])
      s.add_runtime_dependency(%q<sass>, ["~> 3.2"])
      s.add_runtime_dependency(%q<compass>, [">= 1.0.1", "~> 1"])
      s.add_runtime_dependency(%q<parallel>, ["> 1.1.1", "~> 1.1"])
      s.add_development_dependency(%q<nokogiri>, [">= 1.5.10", "~> 1.5.0"])
      s.add_development_dependency(%q<compass-960-plugin>, [">= 0.10.4", "~> 0.10"])
      s.add_development_dependency(%q<bootstrap-sass>, [">= 3.2.0.2", "~> 3"])
      s.add_development_dependency(%q<zurb-foundation>, [">= 4.3.2", "~> 4.3.2"])
      s.add_development_dependency(%q<rspec>, ["~> 3.0"])
      s.add_development_dependency(%q<guard-rspec>, ["~> 4.0"])
    else
      s.add_dependency(%q<haml>, [">= 4.0.5", "~> 4.0"])
      s.add_dependency(%q<asciidoctor>, [">= 1.5.2", "~> 1.5"])
      s.add_dependency(%q<tilt>, [">= 2.0.1", "~> 2.0"])
      s.add_dependency(%q<mime-types>, ["~> 2.1"])
      s.add_dependency(%q<rest-client>, [">= 1.7.2", "~> 1.7"])
      s.add_dependency(%q<listen>, [">= 2.7.1", "~> 2.7"])
      s.add_dependency(%q<rack>, [">= 1.5.2", "~> 1.5"])
      s.add_dependency(%q<git>, [">= 1.2.6", "~> 1.2"])
      s.add_dependency(%q<guard-livereload>, [">= 2.1.2", "~> 2.1"])
      s.add_dependency(%q<colorize>, [">= 0.7.1", "~> 0.7"])
      s.add_dependency(%q<oga>, ["~> 0.3"])
      s.add_dependency(%q<sass>, ["~> 3.2"])
      s.add_dependency(%q<compass>, [">= 1.0.1", "~> 1"])
      s.add_dependency(%q<parallel>, ["> 1.1.1", "~> 1.1"])
      s.add_dependency(%q<nokogiri>, [">= 1.5.10", "~> 1.5.0"])
      s.add_dependency(%q<compass-960-plugin>, [">= 0.10.4", "~> 0.10"])
      s.add_dependency(%q<bootstrap-sass>, [">= 3.2.0.2", "~> 3"])
      s.add_dependency(%q<zurb-foundation>, [">= 4.3.2", "~> 4.3.2"])
      s.add_dependency(%q<rspec>, ["~> 3.0"])
      s.add_dependency(%q<guard-rspec>, ["~> 4.0"])
    end
  else
    s.add_dependency(%q<haml>, [">= 4.0.5", "~> 4.0"])
    s.add_dependency(%q<asciidoctor>, [">= 1.5.2", "~> 1.5"])
    s.add_dependency(%q<tilt>, [">= 2.0.1", "~> 2.0"])
    s.add_dependency(%q<mime-types>, ["~> 2.1"])
    s.add_dependency(%q<rest-client>, [">= 1.7.2", "~> 1.7"])
    s.add_dependency(%q<listen>, [">= 2.7.1", "~> 2.7"])
    s.add_dependency(%q<rack>, [">= 1.5.2", "~> 1.5"])
    s.add_dependency(%q<git>, [">= 1.2.6", "~> 1.2"])
    s.add_dependency(%q<guard-livereload>, [">= 2.1.2", "~> 2.1"])
    s.add_dependency(%q<colorize>, [">= 0.7.1", "~> 0.7"])
    s.add_dependency(%q<oga>, ["~> 0.3"])
    s.add_dependency(%q<sass>, ["~> 3.2"])
    s.add_dependency(%q<compass>, [">= 1.0.1", "~> 1"])
    s.add_dependency(%q<parallel>, ["> 1.1.1", "~> 1.1"])
    s.add_dependency(%q<nokogiri>, [">= 1.5.10", "~> 1.5.0"])
    s.add_dependency(%q<compass-960-plugin>, [">= 0.10.4", "~> 0.10"])
    s.add_dependency(%q<bootstrap-sass>, [">= 3.2.0.2", "~> 3"])
    s.add_dependency(%q<zurb-foundation>, [">= 4.3.2", "~> 4.3.2"])
    s.add_dependency(%q<rspec>, ["~> 3.0"])
    s.add_dependency(%q<guard-rspec>, ["~> 4.0"])
  end
end
