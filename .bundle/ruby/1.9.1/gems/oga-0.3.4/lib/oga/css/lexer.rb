
# line 1 "lib/oga/css/lexer.rl"

# line 3 "lib/oga/css/lexer.rl"
module Oga
  module CSS
    ##
    # Lexer for turning CSS expressions into a sequence of tokens. Tokens are
    # returned as arrays with every array having two values:
    #
    # 1. The token type as a Symbol
    # 2. The token value, or nil if there is no value.
    #
    # ## Thread Safety
    #
    # Similar to the XPath lexer this lexer keeps track of an internal state. As
    # a result it's not safe to share the same instance of this lexer between
    # multiple threads. However, no global state is used so you can use separate
    # instances in threads just fine.
    #
    class Lexer
      
# line 24 "lib/oga/css/lexer.rb"
class << self
	attr_accessor :_css_lexer_trans_keys
	private :_css_lexer_trans_keys, :_css_lexer_trans_keys=
end
self._css_lexer_trans_keys = [
	0, 0, 43, 57, 118, 118, 
	101, 101, 110, 110, 100, 
	100, 100, 100, 34, 34, 
	61, 61, 39, 39, 61, 61, 
	61, 61, 61, 61, 9, 
	126, 9, 44, 9, 32, 
	0, 0, 9, 32, 0, 0, 
	0, 0, 9, 32, 45, 
	122, 9, 32, 9, 122, 
	9, 32, 48, 57, 43, 57, 
	45, 122, 9, 126, 9, 
	32, 61, 61, 45, 122, 
	0
]

class << self
	attr_accessor :_css_lexer_key_spans
	private :_css_lexer_key_spans, :_css_lexer_key_spans=
end
self._css_lexer_key_spans = [
	0, 15, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 118, 36, 24, 
	0, 24, 0, 0, 24, 78, 24, 114, 
	24, 10, 15, 78, 118, 24, 1, 78
]

class << self
	attr_accessor :_css_lexer_index_offsets
	private :_css_lexer_index_offsets, :_css_lexer_index_offsets=
end
self._css_lexer_index_offsets = [
	0, 0, 16, 18, 20, 22, 24, 26, 
	28, 30, 32, 34, 36, 38, 157, 194, 
	219, 220, 245, 246, 247, 272, 351, 376, 
	491, 516, 527, 543, 622, 741, 766, 768
]

class << self
	attr_accessor :_css_lexer_indicies
	private :_css_lexer_indicies, :_css_lexer_indicies=
end
self._css_lexer_indicies = [
	1, 0, 1, 0, 0, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 0, 
	3, 4, 5, 4, 6, 4, 7, 4, 
	8, 4, 10, 9, 11, 4, 10, 12, 
	13, 4, 14, 4, 15, 4, 17, 16, 
	16, 16, 16, 16, 16, 16, 16, 16, 
	16, 16, 16, 16, 16, 16, 16, 16, 
	16, 16, 16, 16, 16, 17, 16, 16, 
	18, 16, 16, 16, 16, 19, 16, 20, 
	21, 22, 16, 23, 16, 16, 16, 16, 
	16, 16, 16, 16, 16, 16, 16, 24, 
	16, 16, 16, 25, 16, 16, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	27, 16, 16, 16, 26, 16, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	16, 28, 16, 29, 16, 17, 30, 30, 
	30, 30, 30, 30, 30, 30, 30, 30, 
	30, 30, 30, 30, 30, 30, 30, 30, 
	30, 30, 30, 30, 17, 30, 30, 30, 
	30, 30, 30, 30, 30, 30, 30, 30, 
	22, 30, 22, 31, 31, 31, 31, 31, 
	31, 31, 31, 31, 31, 31, 31, 31, 
	31, 31, 31, 31, 31, 31, 31, 31, 
	31, 22, 31, 32, 21, 33, 33, 33, 
	33, 33, 33, 33, 33, 33, 33, 33, 
	33, 33, 33, 33, 33, 33, 33, 33, 
	33, 33, 33, 21, 33, 34, 35, 25, 
	36, 36, 36, 36, 36, 36, 36, 36, 
	36, 36, 36, 36, 36, 36, 36, 36, 
	36, 36, 36, 36, 36, 36, 25, 36, 
	26, 37, 37, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 37, 37, 37, 
	37, 37, 37, 37, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 37, 37, 
	37, 37, 26, 37, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 37, 29, 
	38, 38, 38, 38, 38, 38, 38, 38, 
	38, 38, 38, 38, 38, 38, 38, 38, 
	38, 38, 38, 38, 38, 38, 29, 38, 
	39, 4, 4, 4, 4, 4, 4, 4, 
	4, 4, 4, 4, 4, 4, 4, 4, 
	4, 4, 4, 4, 4, 4, 4, 39, 
	4, 4, 4, 4, 4, 4, 4, 4, 
	40, 41, 1, 4, 42, 4, 4, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 4, 4, 4, 4, 4, 4, 4, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 4, 4, 4, 4, 43, 4, 
	43, 43, 43, 43, 44, 43, 43, 43, 
	43, 43, 43, 43, 43, 45, 46, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 4, 39, 47, 47, 47, 47, 
	47, 47, 47, 47, 47, 47, 47, 47, 
	47, 47, 47, 47, 47, 47, 47, 47, 
	47, 47, 39, 47, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 48, 1, 
	49, 1, 49, 49, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 49, 43, 
	50, 50, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 50, 50, 50, 50, 
	50, 50, 50, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 50, 50, 50, 
	50, 43, 50, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 50, 51, 4, 
	4, 4, 4, 4, 4, 4, 4, 4, 
	4, 4, 4, 4, 4, 4, 4, 4, 
	4, 4, 4, 4, 4, 51, 4, 9, 
	4, 52, 4, 4, 12, 4, 4, 53, 
	4, 4, 4, 4, 4, 4, 4, 4, 
	4, 4, 4, 4, 4, 4, 4, 4, 
	4, 4, 54, 4, 4, 4, 55, 55, 
	55, 55, 55, 55, 55, 55, 55, 55, 
	55, 55, 55, 55, 55, 55, 55, 55, 
	55, 55, 55, 55, 55, 55, 55, 55, 
	4, 4, 56, 57, 55, 4, 55, 55, 
	55, 55, 55, 55, 55, 55, 55, 55, 
	55, 55, 55, 55, 55, 55, 55, 55, 
	55, 55, 55, 55, 55, 55, 55, 55, 
	4, 58, 4, 59, 4, 51, 60, 60, 
	60, 60, 60, 60, 60, 60, 60, 60, 
	60, 60, 60, 60, 60, 60, 60, 60, 
	60, 60, 60, 60, 51, 60, 62, 61, 
	55, 61, 61, 55, 55, 55, 55, 55, 
	55, 55, 55, 55, 55, 61, 61, 61, 
	61, 61, 61, 61, 55, 55, 55, 55, 
	55, 55, 55, 55, 55, 55, 55, 55, 
	55, 55, 55, 55, 55, 55, 55, 55, 
	55, 55, 55, 55, 55, 55, 61, 61, 
	61, 61, 55, 61, 55, 55, 55, 55, 
	55, 55, 55, 55, 55, 55, 55, 55, 
	55, 55, 55, 55, 55, 55, 55, 55, 
	55, 55, 55, 55, 55, 55, 61, 0
]

class << self
	attr_accessor :_css_lexer_trans_targs
	private :_css_lexer_trans_targs, :_css_lexer_trans_targs=
end
self._css_lexer_trans_targs = [
	23, 1, 25, 3, 0, 4, 23, 6, 
	23, 7, 28, 28, 9, 28, 28, 28, 
	13, 14, 16, 13, 13, 17, 15, 18, 
	19, 20, 21, 13, 13, 22, 13, 13, 
	13, 13, 13, 13, 13, 13, 13, 24, 
	23, 23, 26, 27, 2, 23, 5, 23, 
	23, 23, 23, 29, 8, 30, 28, 31, 
	28, 10, 11, 12, 28, 28, 28
]

class << self
	attr_accessor :_css_lexer_trans_actions
	private :_css_lexer_trans_actions, :_css_lexer_trans_actions=
end
self._css_lexer_trans_actions = [
	1, 0, 0, 0, 0, 0, 2, 0, 
	3, 0, 4, 5, 0, 6, 7, 8, 
	11, 0, 0, 12, 13, 0, 0, 0, 
	0, 0, 0, 14, 15, 0, 16, 17, 
	18, 19, 20, 21, 22, 23, 24, 0, 
	26, 27, 28, 0, 0, 29, 0, 30, 
	31, 32, 33, 0, 0, 0, 34, 0, 
	35, 0, 0, 0, 36, 37, 38
]

class << self
	attr_accessor :_css_lexer_to_state_actions
	private :_css_lexer_to_state_actions, :_css_lexer_to_state_actions=
end
self._css_lexer_to_state_actions = [
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 9, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 25, 
	0, 0, 0, 0, 9, 0, 0, 0
]

class << self
	attr_accessor :_css_lexer_from_state_actions
	private :_css_lexer_from_state_actions, :_css_lexer_from_state_actions=
end
self._css_lexer_from_state_actions = [
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 10, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 10, 
	0, 0, 0, 0, 10, 0, 0, 0
]

class << self
	attr_accessor :_css_lexer_eof_trans
	private :_css_lexer_eof_trans, :_css_lexer_eof_trans=
end
self._css_lexer_eof_trans = [
	0, 1, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 31, 32, 
	33, 34, 35, 36, 37, 38, 39, 0, 
	48, 49, 50, 51, 0, 61, 62, 62
]

class << self
	attr_accessor :css_lexer_start
end
self.css_lexer_start = 13;
class << self
	attr_accessor :css_lexer_first_final
end
self.css_lexer_first_final = 13;
class << self
	attr_accessor :css_lexer_error
end
self.css_lexer_error = 0;

class << self
	attr_accessor :css_lexer_en_pseudo_args
end
self.css_lexer_en_pseudo_args = 23;
class << self
	attr_accessor :css_lexer_en_predicate
end
self.css_lexer_en_predicate = 28;
class << self
	attr_accessor :css_lexer_en_main
end
self.css_lexer_en_main = 13;


# line 21 "lib/oga/css/lexer.rl"

      # % fix highlight

      ##
      # @param [String] data The data to lex.
      #
      def initialize(data)
        @data = data
      end

      ##
      # Gathers all the tokens for the input and returns them as an Array.
      #
      # @see [#advance]
      # @return [Array]
      #
      def lex
        tokens = []

        advance do |type, value|
          tokens << [type, value]
        end

        return tokens
      end

      ##
      # Advances through the input and generates the corresponding tokens. Each
      # token is yielded to the supplied block.
      #
      # This method stores the supplied block in `@block` and resets it after
      # the lexer loop has finished.
      #
      # @see [#add_token]
      #
      def advance(&block)
        @block = block

        data  = @data # saves ivar lookups while lexing.
        ts    = nil
        te    = nil
        stack = []
        top   = 0
        cs    = self.class.css_lexer_start
        act   = 0
        eof   = @data.bytesize
        p     = 0
        pe    = eof

        _css_lexer_eof_trans          = self.class.send(:_css_lexer_eof_trans)
        _css_lexer_from_state_actions = self.class.send(:_css_lexer_from_state_actions)
        _css_lexer_index_offsets      = self.class.send(:_css_lexer_index_offsets)
        _css_lexer_indicies           = self.class.send(:_css_lexer_indicies)
        _css_lexer_key_spans          = self.class.send(:_css_lexer_key_spans)
        _css_lexer_to_state_actions   = self.class.send(:_css_lexer_to_state_actions)
        _css_lexer_trans_actions      = self.class.send(:_css_lexer_trans_actions)
        _css_lexer_trans_keys         = self.class.send(:_css_lexer_trans_keys)
        _css_lexer_trans_targs        = self.class.send(:_css_lexer_trans_targs)

        
# line 331 "lib/oga/css/lexer.rb"
begin
	testEof = false
	_slen, _trans, _keys, _inds, _acts, _nacts = nil
	_goto_level = 0
	_resume = 10
	_eof_trans = 15
	_again = 20
	_test_eof = 30
	_out = 40
	while true
	if _goto_level <= 0
	if p == pe
		_goto_level = _test_eof
		next
	end
	if cs == 0
		_goto_level = _out
		next
	end
	end
	if _goto_level <= _resume
	case _css_lexer_from_state_actions[cs] 
	when 10 then
# line 1 "NONE"
		begin
ts = p
		end
# line 359 "lib/oga/css/lexer.rb"
	end
	_keys = cs << 1
	_inds = _css_lexer_index_offsets[cs]
	_slen = _css_lexer_key_spans[cs]
	_wide = ( (data.getbyte(p) || 0))
	_trans = if (   _slen > 0 && 
			_css_lexer_trans_keys[_keys] <= _wide && 
			_wide <= _css_lexer_trans_keys[_keys + 1] 
		    ) then
			_css_lexer_indicies[ _inds + _wide - _css_lexer_trans_keys[_keys] ] 
		 else 
			_css_lexer_indicies[ _inds + _slen ]
		 end
	end
	if _goto_level <= _eof_trans
	cs = _css_lexer_trans_targs[_trans]
	if _css_lexer_trans_actions[_trans] != 0
	case _css_lexer_trans_actions[_trans]
	when 29 then
# line 249 "lib/oga/css/lexer.rl"
		begin
te = p+1
 begin  add_token(:T_NTH)  end
		end
	when 3 then
# line 251 "lib/oga/css/lexer.rl"
		begin
te = p+1
 begin  add_token(:T_ODD)  end
		end
	when 2 then
# line 252 "lib/oga/css/lexer.rl"
		begin
te = p+1
 begin  add_token(:T_EVEN)  end
		end
	when 26 then
# line 233 "lib/oga/css/lexer.rl"
		begin
te = p+1
 begin 
          add_token(:T_RPAREN)

          cs = 13;
         end
		end
	when 27 then
# line 160 "lib/oga/css/lexer.rl"
		begin
te = p+1
 begin 
          emit(:T_IDENT, ts, te)
         end
		end
	when 30 then
# line 244 "lib/oga/css/lexer.rl"
		begin
te = p
p = p - 1;		end
	when 32 then
# line 250 "lib/oga/css/lexer.rl"
		begin
te = p
p = p - 1; begin  add_token(:T_MINUS)  end
		end
	when 31 then
# line 193 "lib/oga/css/lexer.rl"
		begin
te = p
p = p - 1; begin 
          value = slice_input(ts, te).to_i

          add_token(:T_INT, value)
         end
		end
	when 33 then
# line 160 "lib/oga/css/lexer.rl"
		begin
te = p
p = p - 1; begin 
          emit(:T_IDENT, ts, te)
         end
		end
	when 1 then
# line 1 "NONE"
		begin
	case act
	when 0 then
	begin	begin
		cs = 0
		_goto_level = _again
		next
	end
end
	when 3 then
	begin begin p = ((te))-1; end
 add_token(:T_MINUS) end
end 
			end
	when 34 then
# line 290 "lib/oga/css/lexer.rl"
		begin
te = p+1
 begin  add_token(:T_EQ)  end
		end
	when 8 then
# line 291 "lib/oga/css/lexer.rl"
		begin
te = p+1
 begin  add_token(:T_SPACE_IN)  end
		end
	when 6 then
# line 292 "lib/oga/css/lexer.rl"
		begin
te = p+1
 begin  add_token(:T_STARTS_WITH)  end
		end
	when 5 then
# line 293 "lib/oga/css/lexer.rl"
		begin
te = p+1
 begin  add_token(:T_ENDS_WITH)  end
		end
	when 38 then
# line 294 "lib/oga/css/lexer.rl"
		begin
te = p+1
 begin  add_token(:T_IN)  end
		end
	when 7 then
# line 295 "lib/oga/css/lexer.rl"
		begin
te = p+1
 begin  add_token(:T_HYPHEN_IN)  end
		end
	when 35 then
# line 272 "lib/oga/css/lexer.rl"
		begin
te = p+1
 begin 
          add_token(:T_RBRACK)

          cs = 13;
         end
		end
	when 4 then
# line 212 "lib/oga/css/lexer.rl"
		begin
te = p+1
 begin 
          emit(:T_STRING, ts + 1, te - 1)
         end
		end
	when 36 then
# line 280 "lib/oga/css/lexer.rl"
		begin
te = p
p = p - 1;		end
	when 37 then
# line 160 "lib/oga/css/lexer.rl"
		begin
te = p
p = p - 1; begin 
          emit(:T_IDENT, ts, te)
         end
		end
	when 14 then
# line 266 "lib/oga/css/lexer.rl"
		begin
te = p+1
 begin 
          add_token(:T_LBRACK)

          cs = 28;
         end
		end
	when 15 then
# line 145 "lib/oga/css/lexer.rl"
		begin
te = p+1
 begin 
          add_token(:T_PIPE)
         end
		end
	when 12 then
# line 227 "lib/oga/css/lexer.rl"
		begin
te = p+1
 begin 
          add_token(:T_LPAREN)

          cs = 23;
         end
		end
	when 13 then
# line 160 "lib/oga/css/lexer.rl"
		begin
te = p+1
 begin 
          emit(:T_IDENT, ts, te)
         end
		end
	when 11 then
# line 315 "lib/oga/css/lexer.rl"
		begin
te = p+1
		end
	when 22 then
# line 304 "lib/oga/css/lexer.rl"
		begin
te = p
p = p - 1; begin  add_token(:T_GREATER)  end
		end
	when 19 then
# line 305 "lib/oga/css/lexer.rl"
		begin
te = p
p = p - 1; begin  add_token(:T_PLUS)  end
		end
	when 24 then
# line 306 "lib/oga/css/lexer.rl"
		begin
te = p
p = p - 1; begin  add_token(:T_TILDE)  end
		end
	when 17 then
# line 149 "lib/oga/css/lexer.rl"
		begin
te = p
p = p - 1; begin 
          add_token(:T_COMMA)
         end
		end
	when 16 then
# line 135 "lib/oga/css/lexer.rl"
		begin
te = p
p = p - 1; begin 
          add_token(:T_SPACE)
         end
		end
	when 23 then
# line 160 "lib/oga/css/lexer.rl"
		begin
te = p
p = p - 1; begin 
          emit(:T_IDENT, ts, te)
         end
		end
	when 18 then
# line 139 "lib/oga/css/lexer.rl"
		begin
 add_token(:T_HASH) 		end
# line 302 "lib/oga/css/lexer.rl"
		begin
te = p
p = p - 1;		end
	when 20 then
# line 140 "lib/oga/css/lexer.rl"
		begin
 add_token(:T_DOT) 		end
# line 302 "lib/oga/css/lexer.rl"
		begin
te = p
p = p - 1;		end
	when 21 then
# line 141 "lib/oga/css/lexer.rl"
		begin
 add_token(:T_COLON) 		end
# line 302 "lib/oga/css/lexer.rl"
		begin
te = p
p = p - 1;		end
	when 28 then
# line 1 "NONE"
		begin
te = p+1
		end
# line 250 "lib/oga/css/lexer.rl"
		begin
act = 3;		end
# line 641 "lib/oga/css/lexer.rb"
	end
	end
	end
	if _goto_level <= _again
	case _css_lexer_to_state_actions[cs] 
	when 9 then
# line 1 "NONE"
		begin
ts = nil;		end
	when 25 then
# line 1 "NONE"
		begin
ts = nil;		end
# line 1 "NONE"
		begin
act = 0
		end
# line 659 "lib/oga/css/lexer.rb"
	end

	if cs == 0
		_goto_level = _out
		next
	end
	p += 1
	if p != pe
		_goto_level = _resume
		next
	end
	end
	if _goto_level <= _test_eof
	if p == eof
	if _css_lexer_eof_trans[cs] > 0
		_trans = _css_lexer_eof_trans[cs] - 1;
		_goto_level = _eof_trans
		next;
	end
	end

	end
	if _goto_level <= _out
		break
	end
end
	end

# line 81 "lib/oga/css/lexer.rl"

        # % fix highlight
      ensure
        @block = nil
      end

      private

      ##
      # Emits a token of which the value is based on the supplied start/stop
      # position.
      #
      # @param [Symbol] type The token type.
      # @param [Fixnum] start
      # @param [Fixnum] stop
      #
      # @see [#text]
      # @see [#add_token]
      #
      def emit(type, start, stop)
        value = slice_input(start, stop)

        add_token(type, value)
      end

      ##
      # Returns the text between the specified start and stop position.
      #
      # @param [Fixnum] start
      # @param [Fixnum] stop
      # @return [String]
      #
      def slice_input(start, stop)
        return @data.byteslice(start, stop - start)
      end

      ##
      # Yields a new token to the supplied block.
      #
      # @param [Symbol] type The token type.
      # @param [String] value The token value.
      #
      # @yieldparam [Symbol] type
      # @yieldparam [String|NilClass] value
      #
      def add_token(type, value = nil)
        @block.call(type, value)
      end

      
# line 317 "lib/oga/css/lexer.rl"

    end # Lexer
  end # CSS
end # Oga
