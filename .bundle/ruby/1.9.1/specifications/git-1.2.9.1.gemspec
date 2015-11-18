# -*- encoding: utf-8 -*-

Gem::Specification.new do |s|
  s.name = "git"
  s.version = "1.2.9.1"

  s.required_rubygems_version = Gem::Requirement.new(">= 0") if s.respond_to? :required_rubygems_version=
  s.authors = ["Scott Chacon"]
  s.date = "2015-01-13"
  s.email = "schacon@gmail.com"
  s.extra_rdoc_files = ["README.md"]
  s.files = ["README.md"]
  s.homepage = "http://github.com/schacon/ruby-git"
  s.licenses = ["MIT"]
  s.rdoc_options = ["--charset=UTF-8"]
  s.require_paths = ["lib"]
  s.requirements = ["git 1.6.0.0, or greater"]
  s.rubygems_version = "1.8.23"
  s.summary = "Ruby/Git is a Ruby library that can be used to create, read and manipulate Git repositories by wrapping system calls to the git binary."

  if s.respond_to? :specification_version then
    s.specification_version = 4

    if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
      s.add_development_dependency(%q<rake>, [">= 0"])
      s.add_development_dependency(%q<rdoc>, [">= 0"])
      s.add_development_dependency(%q<test-unit>, ["< 4", ">= 2"])
    else
      s.add_dependency(%q<rake>, [">= 0"])
      s.add_dependency(%q<rdoc>, [">= 0"])
      s.add_dependency(%q<test-unit>, ["< 4", ">= 2"])
    end
  else
    s.add_dependency(%q<rake>, [">= 0"])
    s.add_dependency(%q<rdoc>, [">= 0"])
    s.add_dependency(%q<test-unit>, ["< 4", ">= 2"])
  end
end
