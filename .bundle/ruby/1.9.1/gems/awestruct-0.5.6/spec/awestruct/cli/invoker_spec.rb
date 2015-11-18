require 'spec_helper'
require 'fileutils'
require 'awestruct/cli/invoker'

describe Awestruct::CLI::Invoker do
  before(:each) do
    FileUtils.mkdir_p 'spec/support/clean_invoker'
  end

  after(:each) do
    FileUtils.rm_rf 'spec/support/clean_invoker'
  end

  it "should invoke generation by default" do
    invoker = Awestruct::CLI::Invoker.new(%w(--source-dir spec/support/test-config/))
    invoker.should_not_receive( :invoke_init )
    invoker.should_not_receive( :invoke_script )
    invoker.should_not_receive( :invoke_force )
    invoker.should_receive( :invoke_generate )
    invoker.should_not_receive( :invoke_deploy )
    invoker.should_not_receive( :invoke_auto )
    invoker.should_not_receive( :invoke_server )
    invoker.invoke!
  end

  it "should only invoke initialization things when initializing" do
    invoker = Awestruct::CLI::Invoker.new(%w(--init --source-dir spec/support/test-config/))
    invoker.should_receive( :invoke_init )
    invoker.should_not_receive( :invoke_script )
    invoker.should_not_receive( :invoke_force )
    invoker.should_not_receive( :invoke_generate )
    invoker.should_not_receive( :invoke_deploy )
    invoker.should_not_receive( :invoke_auto )
    invoker.should_not_receive( :invoke_server )
    invoker.invoke!
  end

  it "should invoke generation and server when servered" do
    invoker = Awestruct::CLI::Invoker.new(%w(--server --source-dir spec/support/test-config/))
    invoker.should_not_receive( :invoke_init )
    invoker.should_not_receive( :invoke_script )
    invoker.should_not_receive( :invoke_force )
    invoker.should_receive( :invoke_generate )
    invoker.should_not_receive( :invoke_deploy )
    invoker.should_not_receive( :invoke_auto )
    invoker.should_receive( :invoke_server )
    invoker.invoke!
  end

 it "should invoke generation and server and auto when dev-mode" do
    invoker = Awestruct::CLI::Invoker.new(%w(-d --source-dir spec/support/test-config/))
    invoker.should_not_receive( :invoke_init )
    invoker.should_not_receive( :invoke_script )
    invoker.should_not_receive( :invoke_force )
    invoker.should_receive( :invoke_generate )
    invoker.should_not_receive( :invoke_deploy )
    invoker.should_receive( :invoke_auto )
    invoker.should_receive( :invoke_server )
    invoker.invoke!
  end

  it "should invoke init without generating" do
    invoker = Awestruct::CLI::Invoker.new( '--init' )
    invoker.should_receive( :invoke_init )
    invoker.should_not_receive( :invoke_script )
    invoker.should_not_receive( :invoke_force )
    invoker.should_not_receive( :invoke_generate )
    invoker.should_not_receive( :invoke_deploy )
    invoker.should_not_receive( :invoke_auto )
    invoker.should_not_receive( :invoke_server )
    invoker.invoke!
  end 

  it "should return false on failure" do
    require 'awestruct/cli/generate'
    generator = double
    Awestruct::CLI::Generate.should_receive( :new ).and_return( generator )
    generator.should_receive( :run ).and_return( false )
    expect(Awestruct::CLI::Invoker.new( %w(--source-dir spec/support/test-config --generate) ).invoke!).to be_falsey
  end


end
