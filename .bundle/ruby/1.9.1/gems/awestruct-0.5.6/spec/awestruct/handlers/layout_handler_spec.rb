
require 'awestruct/handlers/layout_handler'
require 'awestruct/handlers/string_handler'
require 'awestruct/engine'
require 'awestruct/handler_chains'
require 'awestruct/site'
require 'awestruct/page'
require 'awestruct/page_loader'

require 'hashery'
require 'ostruct'

describe Awestruct::Handlers::LayoutHandler do


  before :all do
    @config = Hashery::OpenCascade[ { :dir=>Pathname.new( test_data_dir 'handlers' ) } ]
    @engine = Awestruct::Engine.new
    @site = Awestruct::Site.new( @engine, @config )
    layout_loader = Awestruct::PageLoader.new( @site, :layouts )
    layout = layout_loader.load_page( File.join( @config.dir, 'haml-layout.html.haml' ) )
    expect(layout.class).to eql Awestruct::Page
    expect(layout).to_not be_nil

    @site.layouts << layout

    layout = layout_loader.load_page( File.join( @config.dir, 'haml-layout-two.html.haml' ) )
    expect(layout.class).to eql Awestruct::Page
    expect(layout).to_not be_nil

    @site.layouts << layout
  end

  it "should be able to find layouts by simple name" do
    layout = @site.layouts.find_matching( 'haml-layout', '.html' )
    expect(layout.class).to eql Awestruct::Page
  end

  it "should apply the layout to its delegate's content" do
    primary_handler = Awestruct::Handlers::StringHandler.new( @site, "this is the content" )
    layout_handler = Awestruct::Handlers::LayoutHandler.new( @site, primary_handler )

    page = Awestruct::Page.new( @site, layout_handler )

    context = page.create_context
    context.page.layout = 'haml-layout'

    expect(@site.layouts.find_matching( 'haml-layout', '.html' )).to_not be_nil
    rendered = layout_handler.rendered_content( context )
    
  end

  it "should recursively apply the layout to its delegate's content" do
    primary_handler = Awestruct::Handlers::StringHandler.new( @site, "this is the content" )
    layout_handler = Awestruct::Handlers::LayoutHandler.new( @site, primary_handler )

    page = Awestruct::Page.new( @site, layout_handler )
    page.layout = 'haml-layout-two'

    context = page.create_context

    expect(@site.layouts.find_matching('haml-layout', '.html')).to_not be_nil
    rendered = layout_handler.rendered_content( context )

    haml_index = ( rendered =~ %r(This is a haml layout) )
    awestruct_index = ( rendered =~ %r(Welcome to Awestruct) )
    content_index = ( rendered =~ %r(this is the content) )

    haml_index.should > 0
    awestruct_index.should > 0
    content_index.should > 0 

    haml_index.should < awestruct_index
    awestruct_index.should < content_index
  end

end
