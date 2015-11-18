module Oga
  module XML
    ##
    # Class used for storing information about Doctypes.
    #
    # @!attribute [rw] name
    #  The name of the doctype (e.g. "HTML").
    #  @return [String]
    #
    # @!attribute [rw] type
    #  The type of the doctype (e.g. "PUBLIC").
    #  @return [String]
    #
    # @!attribute [rw] public_id
    #  The public ID of the doctype.
    #  @return [String]
    #
    # @!attribute [rw] system_id
    #  The system ID of the doctype.
    #  @return [String]
    #
    # @!attribute [rw] inline_rules
    #  The inline doctype rules.
    #  @return [String]
    #
    class Doctype
      attr_accessor :name, :type, :public_id, :system_id, :inline_rules

      ##
      # @example
      #  dtd = Doctype.new(:name => 'html', :type => 'PUBLIC')
      #
      # @param [Hash] options
      #
      # @option options [String] :name
      # @option options [String] :type
      # @option options [String] :public_id
      # @option options [String] :system_id
      #
      def initialize(options = {})
        @name         = options[:name]
        @type         = options[:type]
        @public_id    = options[:public_id]
        @system_id    = options[:system_id]
        @inline_rules = options[:inline_rules]
      end

      ##
      # Converts the doctype back to XML.
      #
      # @return [String]
      #
      def to_xml
        segments = "<!DOCTYPE #{name}"

        segments << " #{type}" if type
        segments << %Q{ "#{public_id}"} if public_id
        segments << %Q{ "#{system_id}"} if system_id
        segments << " [#{inline_rules}]" if inline_rules

        return segments + '>'
      end

      ##
      # Inspects the doctype.
      #
      # @return [String]
      #
      def inspect
        segments = []

        [:name, :type, :public_id, :system_id, :inline_rules].each do |attr|
          value = send(attr)

          if value and !value.empty?
            segments << "#{attr}: #{value.inspect}"
          end
        end

        return "Doctype(#{segments.join(' ')})"
      end
    end # Doctype
  end # XML
end # Oga
