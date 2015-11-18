
#line 1 "ext/c/lexer.rl"
#include "lexer.h"

/*
The following two macros allow the Ragel grammar to use generic function calls
without relying on the setup of the C or Java lexer. Using these macros we can
also pass along `self` to the callback functions without having to hard-code
this in to the Ragel grammar.

In the C lexer we don't need the `data` variable (since this is pulled in based
on `ts` and `te`) so the macro ignores this argument.
*/

#define callback(name, data, encoding, start, stop) \
    liboga_xml_lexer_callback(self, name, encoding, start, stop);

#define callback_simple(name) \
    liboga_xml_lexer_callback_simple(self, name);

#define advance_line(amount) \
    rb_funcall(self, id_advance_line, 1, INT2NUM(amount));

#define html_script_p() \
    rb_funcall(self, id_html_script_p, 0) == Qtrue

#define html_style_p() \
    rb_funcall(self, id_html_style_p, 0) == Qtrue

ID id_advance_line;
ID id_html_script_p;
ID id_html_style_p;
ID id_html;


#line 34 "ext/c/lexer.rl"

/**
 * Calls a method defined in the Ruby side of the lexer. The String value is
 * created based on the values of `ts` and `te` and uses the encoding specified
 * in `encoding`.
 *
 * @example
 *  rb_encoding *encoding = rb_enc_get(...);
 *  liboga_xml_lexer_callback(self, "on_string", encoding, ts, te);
 */
void liboga_xml_lexer_callback(
    VALUE self,
    ID name,
    rb_encoding *encoding,
    const char *ts,
    const char *te
)
{
    VALUE value = rb_enc_str_new(ts, te - ts, encoding);

    rb_funcall(self, name, 1, value);
}

/**
 * Calls a method defined in the Ruby side of the lexer without passing it any
 * arguments.
 *
 * @example
 *  liboga_xml_lexer_callback_simple(self, "on_cdata_start");
 */
void liboga_xml_lexer_callback_simple(VALUE self, VALUE name)
{
    rb_funcall(self, name, 0);
}


#line 74 "ext/c/lexer.c"
static const int c_lexer_start = 34;
static const int c_lexer_first_final = 34;
static const int c_lexer_error = 0;

static const int c_lexer_en_comment_body = 40;
static const int c_lexer_en_cdata_body = 43;
static const int c_lexer_en_proc_ins_body = 46;
static const int c_lexer_en_string_squote = 49;
static const int c_lexer_en_string_dquote = 51;
static const int c_lexer_en_doctype_inline = 53;
static const int c_lexer_en_doctype = 55;
static const int c_lexer_en_xml_decl = 68;
static const int c_lexer_en_element_name = 71;
static const int c_lexer_en_html_attribute_value = 73;
static const int c_lexer_en_xml_attribute_value = 75;
static const int c_lexer_en_element_head = 76;
static const int c_lexer_en_text = 80;
static const int c_lexer_en_html_script = 84;
static const int c_lexer_en_html_style = 88;
static const int c_lexer_en_main = 34;


#line 70 "ext/c/lexer.rl"

/**
 * Lexes the String specifies as the method argument. Token values have the
 * same encoding as the input value.
 *
 * This method keeps track of an internal state using the instance variables
 * `@act` and `@cs`.
 */
VALUE oga_xml_lexer_advance(VALUE self, VALUE data_block)
{
    OgaLexerState *state;
    int lines;

    /* Whether or not HTML mode is enabled */
    int html_p = rb_funcall(self, id_html, 0) == Qtrue;

    /* Make sure that all data passed back to Ruby has the proper encoding. */
    rb_encoding *encoding = rb_enc_get(data_block);

    char *data_str_val = StringValueCStr(data_block);

    const char *p    = data_str_val;
    const char *pe   = data_str_val + strlen(data_str_val);
    const char *eof  = pe;
    const char *ts   = 0;
    const char *te   = 0;
    const char *mark = 0;

    ID id_advance_line        = rb_intern("advance_line");
    ID id_on_attribute        = rb_intern("on_attribute");
    ID id_on_attribute_ns     = rb_intern("on_attribute_ns");
    ID id_on_cdata_start      = rb_intern("on_cdata_start");
    ID id_on_cdata_body       = rb_intern("on_cdata_body");
    ID id_on_cdata_end        = rb_intern("on_cdata_end");
    ID id_on_comment_start    = rb_intern("on_comment_start");
    ID id_on_comment_body     = rb_intern("on_comment_body");
    ID id_on_comment_end      = rb_intern("on_comment_end");
    ID id_on_doctype_end      = rb_intern("on_doctype_end");
    ID id_on_doctype_inline   = rb_intern("on_doctype_inline");
    ID id_on_doctype_name     = rb_intern("on_doctype_name");
    ID id_on_doctype_start    = rb_intern("on_doctype_start");
    ID id_on_doctype_type     = rb_intern("on_doctype_type");
    ID id_on_element_end      = rb_intern("on_element_end");
    ID id_on_element_name     = rb_intern("on_element_name");
    ID id_on_element_ns       = rb_intern("on_element_ns");
    ID id_on_element_open_end = rb_intern("on_element_open_end");
    ID id_on_element_start    = rb_intern("on_element_start");
    ID id_on_proc_ins_end     = rb_intern("on_proc_ins_end");
    ID id_on_proc_ins_name    = rb_intern("on_proc_ins_name");
    ID id_on_proc_ins_start   = rb_intern("on_proc_ins_start");
    ID id_on_proc_ins_body    = rb_intern("on_proc_ins_body");
    ID id_on_string_body      = rb_intern("on_string_body");
    ID id_on_string_dquote    = rb_intern("on_string_dquote");
    ID id_on_string_squote    = rb_intern("on_string_squote");
    ID id_on_text             = rb_intern("on_text");
    ID id_on_xml_decl_end     = rb_intern("on_xml_decl_end");
    ID id_on_xml_decl_start   = rb_intern("on_xml_decl_start");

    Data_Get_Struct(self, OgaLexerState, state);

    lines = state->lines;

    
#line 161 "ext/c/lexer.c"
	{
	if ( p == pe )
		goto _test_eof;
	goto _resume;

_again:
	switch ( ( state->cs) ) {
		case 34: goto st34;
		case 35: goto st35;
		case 1: goto st1;
		case 2: goto st2;
		case 3: goto st3;
		case 4: goto st4;
		case 5: goto st5;
		case 6: goto st6;
		case 7: goto st7;
		case 8: goto st8;
		case 9: goto st9;
		case 36: goto st36;
		case 10: goto st10;
		case 11: goto st11;
		case 12: goto st12;
		case 13: goto st13;
		case 14: goto st14;
		case 15: goto st15;
		case 16: goto st16;
		case 17: goto st17;
		case 18: goto st18;
		case 37: goto st37;
		case 38: goto st38;
		case 39: goto st39;
		case 40: goto st40;
		case 41: goto st41;
		case 42: goto st42;
		case 19: goto st19;
		case 43: goto st43;
		case 44: goto st44;
		case 45: goto st45;
		case 20: goto st20;
		case 46: goto st46;
		case 47: goto st47;
		case 48: goto st48;
		case 49: goto st49;
		case 50: goto st50;
		case 51: goto st51;
		case 52: goto st52;
		case 53: goto st53;
		case 54: goto st54;
		case 55: goto st55;
		case 0: goto st0;
		case 56: goto st56;
		case 57: goto st57;
		case 58: goto st58;
		case 59: goto st59;
		case 60: goto st60;
		case 61: goto st61;
		case 62: goto st62;
		case 63: goto st63;
		case 64: goto st64;
		case 65: goto st65;
		case 66: goto st66;
		case 67: goto st67;
		case 68: goto st68;
		case 69: goto st69;
		case 70: goto st70;
		case 71: goto st71;
		case 72: goto st72;
		case 73: goto st73;
		case 74: goto st74;
		case 75: goto st75;
		case 76: goto st76;
		case 77: goto st77;
		case 78: goto st78;
		case 79: goto st79;
		case 80: goto st80;
		case 81: goto st81;
		case 82: goto st82;
		case 83: goto st83;
		case 84: goto st84;
		case 85: goto st85;
		case 86: goto st86;
		case 21: goto st21;
		case 22: goto st22;
		case 23: goto st23;
		case 24: goto st24;
		case 25: goto st25;
		case 26: goto st26;
		case 27: goto st27;
		case 87: goto st87;
		case 88: goto st88;
		case 89: goto st89;
		case 90: goto st90;
		case 28: goto st28;
		case 29: goto st29;
		case 30: goto st30;
		case 31: goto st31;
		case 32: goto st32;
		case 33: goto st33;
		case 91: goto st91;
	default: break;
	}

	if ( ++p == pe )
		goto _test_eof;
_resume:
	switch ( ( state->cs) )
	{
tr0:
	( state->cs) = 34;
#line 505 "ext/ragel/base_lexer.rl"
	{{p = ((te))-1;}{
        p--;
        ( state->cs) = 80;
    }}
	goto _again;
tr4:
	( state->cs) = 34;
#line 84 "ext/ragel/base_lexer.rl"
	{te = p+1;{
        callback_simple(id_on_comment_start);

        ( state->cs) = 40;
    }}
	goto _again;
tr17:
	( state->cs) = 34;
#line 123 "ext/ragel/base_lexer.rl"
	{te = p+1;{
        callback_simple(id_on_cdata_start);

        ( state->cs) = 43;
    }}
	goto _again;
tr20:
#line 375 "ext/ragel/base_lexer.rl"
	{te = p+1;{
        callback_simple(id_on_element_end);
    }}
	goto st34;
tr42:
	( state->cs) = 34;
#line 505 "ext/ragel/base_lexer.rl"
	{te = p+1;{
        p--;
        ( state->cs) = 80;
    }}
	goto _again;
tr44:
	( state->cs) = 34;
#line 505 "ext/ragel/base_lexer.rl"
	{te = p;p--;{
        p--;
        ( state->cs) = 80;
    }}
	goto _again;
tr46:
	( state->cs) = 34;
#line 369 "ext/ragel/base_lexer.rl"
	{te = p+1;{
        callback_simple(id_on_element_start);
        p--;
        ( state->cs) = 71;
    }}
	goto _again;
tr48:
	( state->cs) = 34;
#line 255 "ext/ragel/base_lexer.rl"
	{te = p;p--;{
        callback_simple(id_on_doctype_start);

        if ( lines > 0 )
        {
            advance_line(lines);

            lines = 0;
        }

        ( state->cs) = 55;
    }}
	goto _again;
tr49:
	( state->cs) = 34;
#line 1 "NONE"
	{	switch( ( state->act) ) {
	case 48:
	{{p = ((te))-1;}
        callback_simple(id_on_xml_decl_start);
        ( state->cs) = 68;
    }
	break;
	case 51:
	{{p = ((te))-1;}
        callback_simple(id_on_proc_ins_start);
        callback(id_on_proc_ins_name, data, encoding, ts + 2, te);

        ( state->cs) = 46;
    }
	break;
	}
	}
	goto _again;
tr50:
	( state->cs) = 34;
#line 165 "ext/ragel/base_lexer.rl"
	{te = p;p--;{
        callback_simple(id_on_proc_ins_start);
        callback(id_on_proc_ins_name, data, encoding, ts + 2, te);

        ( state->cs) = 46;
    }}
	goto _again;
st34:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof34;
case 34:
#line 1 "NONE"
	{ts = p;}
#line 381 "ext/c/lexer.c"
	if ( (*p) == 60 )
		goto tr43;
	goto tr42;
tr43:
#line 1 "NONE"
	{te = p+1;}
	goto st35;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
#line 393 "ext/c/lexer.c"
	switch( (*p) ) {
		case 33: goto st1;
		case 45: goto tr46;
		case 47: goto st16;
		case 63: goto st18;
		case 95: goto tr46;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr46;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr46;
	} else
		goto tr46;
	goto tr44;
st1:
	if ( ++p == pe )
		goto _test_eof1;
case 1:
	switch( (*p) ) {
		case 45: goto st2;
		case 68: goto st3;
		case 91: goto st10;
		case 100: goto st3;
	}
	goto tr0;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
	if ( (*p) == 45 )
		goto tr4;
	goto tr0;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
	switch( (*p) ) {
		case 79: goto st4;
		case 111: goto st4;
	}
	goto tr0;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
	switch( (*p) ) {
		case 67: goto st5;
		case 99: goto st5;
	}
	goto tr0;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
	switch( (*p) ) {
		case 84: goto st6;
		case 116: goto st6;
	}
	goto tr0;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
	switch( (*p) ) {
		case 89: goto st7;
		case 121: goto st7;
	}
	goto tr0;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
	switch( (*p) ) {
		case 80: goto st8;
		case 112: goto st8;
	}
	goto tr0;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
	switch( (*p) ) {
		case 69: goto st9;
		case 101: goto st9;
	}
	goto tr0;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
	switch( (*p) ) {
		case 13: goto tr11;
		case 32: goto tr11;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto tr11;
	goto tr0;
tr11:
#line 56 "ext/ragel/base_lexer.rl"
	{
        if ( (*p) == '\n' ) lines++;
    }
	goto st36;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
#line 503 "ext/c/lexer.c"
	switch( (*p) ) {
		case 13: goto tr11;
		case 32: goto tr11;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto tr11;
	goto tr48;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
	if ( (*p) == 67 )
		goto st11;
	goto tr0;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
	if ( (*p) == 68 )
		goto st12;
	goto tr0;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
	if ( (*p) == 65 )
		goto st13;
	goto tr0;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
	if ( (*p) == 84 )
		goto st14;
	goto tr0;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
	if ( (*p) == 65 )
		goto st15;
	goto tr0;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
	if ( (*p) == 91 )
		goto tr17;
	goto tr0;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
	switch( (*p) ) {
		case 45: goto st17;
		case 95: goto st17;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st17;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st17;
	} else
		goto st17;
	goto tr0;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
	switch( (*p) ) {
		case 45: goto st17;
		case 58: goto st16;
		case 62: goto tr20;
		case 95: goto st17;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st17;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st17;
	} else
		goto st17;
	goto tr0;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
	switch( (*p) ) {
		case 45: goto tr21;
		case 95: goto tr21;
		case 120: goto st38;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr21;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr21;
	} else
		goto tr21;
	goto tr0;
tr21:
#line 1 "NONE"
	{te = p+1;}
#line 165 "ext/ragel/base_lexer.rl"
	{( state->act) = 51;}
	goto st37;
tr52:
#line 1 "NONE"
	{te = p+1;}
#line 319 "ext/ragel/base_lexer.rl"
	{( state->act) = 48;}
	goto st37;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
#line 623 "ext/c/lexer.c"
	switch( (*p) ) {
		case 45: goto tr21;
		case 95: goto tr21;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr21;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr21;
	} else
		goto tr21;
	goto tr49;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
	switch( (*p) ) {
		case 45: goto tr21;
		case 95: goto tr21;
		case 109: goto st39;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr21;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr21;
	} else
		goto tr21;
	goto tr50;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
	switch( (*p) ) {
		case 45: goto tr21;
		case 95: goto tr21;
		case 108: goto tr52;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr21;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr21;
	} else
		goto tr21;
	goto tr50;
tr23:
#line 91 "ext/ragel/base_lexer.rl"
	{{p = ((te))-1;}{
            callback(id_on_comment_body, data, encoding, ts, te);

            if ( lines > 0 )
            {
                advance_line(lines);

                lines = 0;
            }
        }}
	goto st40;
tr24:
	( state->cs) = 40;
#line 102 "ext/ragel/base_lexer.rl"
	{te = p+1;{
            callback_simple(id_on_comment_end);

            ( state->cs) = 34;
        }}
	goto _again;
tr55:
#line 91 "ext/ragel/base_lexer.rl"
	{te = p;p--;{
            callback(id_on_comment_body, data, encoding, ts, te);

            if ( lines > 0 )
            {
                advance_line(lines);

                lines = 0;
            }
        }}
	goto st40;
st40:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof40;
case 40:
#line 1 "NONE"
	{ts = p;}
#line 716 "ext/c/lexer.c"
	if ( (*p) == 45 )
		goto tr54;
	goto tr53;
tr53:
#line 56 "ext/ragel/base_lexer.rl"
	{
        if ( (*p) == '\n' ) lines++;
    }
	goto st41;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
#line 730 "ext/c/lexer.c"
	if ( (*p) == 45 )
		goto tr55;
	goto tr53;
tr54:
#line 1 "NONE"
	{te = p+1;}
#line 56 "ext/ragel/base_lexer.rl"
	{
        if ( (*p) == '\n' ) lines++;
    }
	goto st42;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
#line 746 "ext/c/lexer.c"
	if ( (*p) == 45 )
		goto st19;
	goto tr55;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
	if ( (*p) == 62 )
		goto tr24;
	goto tr23;
tr25:
#line 130 "ext/ragel/base_lexer.rl"
	{{p = ((te))-1;}{
            callback(id_on_cdata_body, data, encoding, ts, te);

            if ( lines > 0 )
            {
                advance_line(lines);

                lines = 0;
            }
        }}
	goto st43;
tr26:
	( state->cs) = 43;
#line 141 "ext/ragel/base_lexer.rl"
	{te = p+1;{
            callback_simple(id_on_cdata_end);

            ( state->cs) = 34;
        }}
	goto _again;
tr59:
#line 130 "ext/ragel/base_lexer.rl"
	{te = p;p--;{
            callback(id_on_cdata_body, data, encoding, ts, te);

            if ( lines > 0 )
            {
                advance_line(lines);

                lines = 0;
            }
        }}
	goto st43;
st43:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof43;
case 43:
#line 1 "NONE"
	{ts = p;}
#line 800 "ext/c/lexer.c"
	if ( (*p) == 93 )
		goto tr58;
	goto tr57;
tr57:
#line 56 "ext/ragel/base_lexer.rl"
	{
        if ( (*p) == '\n' ) lines++;
    }
	goto st44;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
#line 814 "ext/c/lexer.c"
	if ( (*p) == 93 )
		goto tr59;
	goto tr57;
tr58:
#line 1 "NONE"
	{te = p+1;}
#line 56 "ext/ragel/base_lexer.rl"
	{
        if ( (*p) == '\n' ) lines++;
    }
	goto st45;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
#line 830 "ext/c/lexer.c"
	if ( (*p) == 93 )
		goto st20;
	goto tr59;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
	if ( (*p) == 62 )
		goto tr26;
	goto tr25;
tr63:
#line 173 "ext/ragel/base_lexer.rl"
	{te = p;p--;{
            callback(id_on_proc_ins_body, data, encoding, ts, te);

            if ( lines > 0 )
            {
                advance_line(lines);

                lines = 0;
            }
        }}
	goto st46;
tr64:
	( state->cs) = 46;
#line 184 "ext/ragel/base_lexer.rl"
	{te = p+1;{
            callback_simple(id_on_proc_ins_end);

            ( state->cs) = 34;
        }}
	goto _again;
st46:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof46;
case 46:
#line 1 "NONE"
	{ts = p;}
#line 871 "ext/c/lexer.c"
	if ( (*p) == 63 )
		goto tr62;
	goto tr61;
tr61:
#line 56 "ext/ragel/base_lexer.rl"
	{
        if ( (*p) == '\n' ) lines++;
    }
	goto st47;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
#line 885 "ext/c/lexer.c"
	if ( (*p) == 63 )
		goto tr63;
	goto tr61;
tr62:
#line 56 "ext/ragel/base_lexer.rl"
	{
        if ( (*p) == '\n' ) lines++;
    }
	goto st48;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
#line 899 "ext/c/lexer.c"
	if ( (*p) == 62 )
		goto tr64;
	goto tr63;
tr66:
#line 226 "ext/ragel/base_lexer.rl"
	{te = p+1;{
            callback_simple(id_on_string_squote);

            {( state->cs) = ( state->stack)[--( state->top)];goto _again;}
        }}
	goto st49;
tr67:
#line 200 "ext/ragel/base_lexer.rl"
	{te = p;p--;{
        callback(id_on_string_body, data, encoding, ts, te);

        if ( lines > 0 )
        {
            advance_line(lines);

            lines = 0;
        }
    }}
	goto st49;
st49:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof49;
case 49:
#line 1 "NONE"
	{ts = p;}
#line 932 "ext/c/lexer.c"
	if ( (*p) == 39 )
		goto tr66;
	goto tr65;
tr65:
#line 56 "ext/ragel/base_lexer.rl"
	{
        if ( (*p) == '\n' ) lines++;
    }
	goto st50;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
#line 946 "ext/c/lexer.c"
	if ( (*p) == 39 )
		goto tr67;
	goto tr65;
tr69:
#line 236 "ext/ragel/base_lexer.rl"
	{te = p+1;{
            callback_simple(id_on_string_dquote);

            {( state->cs) = ( state->stack)[--( state->top)];goto _again;}
        }}
	goto st51;
tr70:
#line 200 "ext/ragel/base_lexer.rl"
	{te = p;p--;{
        callback(id_on_string_body, data, encoding, ts, te);

        if ( lines > 0 )
        {
            advance_line(lines);

            lines = 0;
        }
    }}
	goto st51;
st51:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof51;
case 51:
#line 1 "NONE"
	{ts = p;}
#line 979 "ext/c/lexer.c"
	if ( (*p) == 34 )
		goto tr69;
	goto tr68;
tr68:
#line 56 "ext/ragel/base_lexer.rl"
	{
        if ( (*p) == '\n' ) lines++;
    }
	goto st52;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
#line 993 "ext/c/lexer.c"
	if ( (*p) == 34 )
		goto tr70;
	goto tr68;
tr72:
	( state->cs) = 53;
#line 281 "ext/ragel/base_lexer.rl"
	{te = p+1;{ ( state->cs) = 55; }}
	goto _again;
tr73:
#line 270 "ext/ragel/base_lexer.rl"
	{te = p;p--;{
            callback(id_on_doctype_inline, data, encoding, ts, te);

            if ( lines > 0 )
            {
                advance_line(lines);

                lines = 0;
            }
        }}
	goto st53;
st53:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof53;
case 53:
#line 1 "NONE"
	{ts = p;}
#line 1023 "ext/c/lexer.c"
	if ( (*p) == 93 )
		goto tr72;
	goto tr71;
tr71:
#line 56 "ext/ragel/base_lexer.rl"
	{
        if ( (*p) == '\n' ) lines++;
    }
	goto st54;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
#line 1037 "ext/c/lexer.c"
	if ( (*p) == 93 )
		goto tr73;
	goto tr71;
tr74:
#line 309 "ext/ragel/base_lexer.rl"
	{te = p+1;}
	goto st55;
tr76:
#line 60 "ext/ragel/base_lexer.rl"
	{te = p+1;{
        advance_line(1);
    }}
	goto st55;
tr78:
#line 217 "ext/ragel/base_lexer.rl"
	{te = p+1;{
        callback_simple(id_on_string_dquote);

        {( state->stack)[( state->top)++] = 55; goto st51;}
    }}
	goto st55;
tr79:
#line 211 "ext/ragel/base_lexer.rl"
	{te = p+1;{
        callback_simple(id_on_string_squote);

        {( state->stack)[( state->top)++] = 55; goto st49;}
    }}
	goto st55;
tr81:
	( state->cs) = 55;
#line 302 "ext/ragel/base_lexer.rl"
	{te = p+1;{
            callback_simple(id_on_doctype_end);
            ( state->cs) = 34;
        }}
	goto _again;
tr84:
	( state->cs) = 55;
#line 292 "ext/ragel/base_lexer.rl"
	{te = p+1;{ ( state->cs) = 53; }}
	goto _again;
tr85:
#line 60 "ext/ragel/base_lexer.rl"
	{te = p;p--;{
        advance_line(1);
    }}
	goto st55;
tr86:
#line 1 "NONE"
	{	switch( ( state->act) ) {
	case 13:
	{{p = ((te))-1;}
            callback(id_on_doctype_type, data, encoding, ts, te);
        }
	break;
	case 17:
	{{p = ((te))-1;}
            callback(id_on_doctype_name, data, encoding, ts, te);
        }
	break;
	}
	}
	goto st55;
tr87:
#line 298 "ext/ragel/base_lexer.rl"
	{te = p;p--;{
            callback(id_on_doctype_name, data, encoding, ts, te);
        }}
	goto st55;
st55:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof55;
case 55:
#line 1 "NONE"
	{ts = p;}
#line 1116 "ext/c/lexer.c"
	switch( (*p) ) {
		case 9: goto tr74;
		case 10: goto tr76;
		case 13: goto st56;
		case 32: goto tr74;
		case 34: goto tr78;
		case 39: goto tr79;
		case 45: goto tr80;
		case 62: goto tr81;
		case 80: goto st58;
		case 83: goto st63;
		case 91: goto tr84;
		case 95: goto tr80;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr80;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr80;
	} else
		goto tr80;
	goto st0;
st0:
( state->cs) = 0;
	goto _out;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
	if ( (*p) == 10 )
		goto tr76;
	goto tr85;
tr80:
#line 1 "NONE"
	{te = p+1;}
#line 298 "ext/ragel/base_lexer.rl"
	{( state->act) = 17;}
	goto st57;
tr92:
#line 1 "NONE"
	{te = p+1;}
#line 287 "ext/ragel/base_lexer.rl"
	{( state->act) = 13;}
	goto st57;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
#line 1166 "ext/c/lexer.c"
	switch( (*p) ) {
		case 45: goto tr80;
		case 95: goto tr80;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr80;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr80;
	} else
		goto tr80;
	goto tr86;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
	switch( (*p) ) {
		case 45: goto tr80;
		case 85: goto st59;
		case 95: goto tr80;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr80;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr80;
	} else
		goto tr80;
	goto tr87;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
	switch( (*p) ) {
		case 45: goto tr80;
		case 66: goto st60;
		case 95: goto tr80;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr80;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr80;
	} else
		goto tr80;
	goto tr87;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
	switch( (*p) ) {
		case 45: goto tr80;
		case 76: goto st61;
		case 95: goto tr80;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr80;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr80;
	} else
		goto tr80;
	goto tr87;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
	switch( (*p) ) {
		case 45: goto tr80;
		case 73: goto st62;
		case 95: goto tr80;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr80;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr80;
	} else
		goto tr80;
	goto tr87;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
	switch( (*p) ) {
		case 45: goto tr80;
		case 67: goto tr92;
		case 95: goto tr80;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr80;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr80;
	} else
		goto tr80;
	goto tr87;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
	switch( (*p) ) {
		case 45: goto tr80;
		case 89: goto st64;
		case 95: goto tr80;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr80;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr80;
	} else
		goto tr80;
	goto tr87;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
	switch( (*p) ) {
		case 45: goto tr80;
		case 83: goto st65;
		case 95: goto tr80;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr80;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr80;
	} else
		goto tr80;
	goto tr87;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
	switch( (*p) ) {
		case 45: goto tr80;
		case 84: goto st66;
		case 95: goto tr80;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr80;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr80;
	} else
		goto tr80;
	goto tr87;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
	switch( (*p) ) {
		case 45: goto tr80;
		case 69: goto st67;
		case 95: goto tr80;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr80;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr80;
	} else
		goto tr80;
	goto tr87;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
	switch( (*p) ) {
		case 45: goto tr80;
		case 77: goto tr92;
		case 95: goto tr80;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr80;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr80;
	} else
		goto tr80;
	goto tr87;
tr97:
#line 56 "ext/ragel/base_lexer.rl"
	{
        if ( (*p) == '\n' ) lines++;
    }
#line 354 "ext/ragel/base_lexer.rl"
	{te = p+1;}
	goto st68;
tr98:
#line 217 "ext/ragel/base_lexer.rl"
	{te = p+1;{
        callback_simple(id_on_string_dquote);

        {( state->stack)[( state->top)++] = 68; goto st51;}
    }}
#line 56 "ext/ragel/base_lexer.rl"
	{
        if ( (*p) == '\n' ) lines++;
    }
	goto st68;
tr99:
#line 211 "ext/ragel/base_lexer.rl"
	{te = p+1;{
        callback_simple(id_on_string_squote);

        {( state->stack)[( state->top)++] = 68; goto st49;}
    }}
#line 56 "ext/ragel/base_lexer.rl"
	{
        if ( (*p) == '\n' ) lines++;
    }
	goto st68;
tr102:
#line 340 "ext/ragel/base_lexer.rl"
	{te = p;p--;{
            if ( lines > 0 )
            {
                advance_line(lines);

                lines = 0;
            }

            callback(id_on_attribute, data, encoding, ts, te);
        }}
	goto st68;
tr104:
#line 354 "ext/ragel/base_lexer.rl"
	{te = p;p--;}
	goto st68;
tr105:
	( state->cs) = 68;
#line 326 "ext/ragel/base_lexer.rl"
	{te = p+1;{
            if ( lines > 0 )
            {
                advance_line(lines);

                lines = 0;
            }

            callback_simple(id_on_xml_decl_end);

            ( state->cs) = 34;
        }}
	goto _again;
st68:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof68;
case 68:
#line 1 "NONE"
	{ts = p;}
#line 1433 "ext/c/lexer.c"
	switch( (*p) ) {
		case 34: goto tr98;
		case 39: goto tr99;
		case 45: goto tr100;
		case 63: goto tr101;
		case 95: goto tr100;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr100;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr100;
	} else
		goto tr100;
	goto tr97;
tr100:
#line 56 "ext/ragel/base_lexer.rl"
	{
        if ( (*p) == '\n' ) lines++;
    }
	goto st69;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
#line 1460 "ext/c/lexer.c"
	switch( (*p) ) {
		case 45: goto st69;
		case 95: goto st69;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st69;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st69;
	} else
		goto st69;
	goto tr102;
tr101:
#line 56 "ext/ragel/base_lexer.rl"
	{
        if ( (*p) == '\n' ) lines++;
    }
	goto st70;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
#line 1484 "ext/c/lexer.c"
	if ( (*p) == 62 )
		goto tr105;
	goto tr104;
tr107:
	( state->cs) = 71;
#line 391 "ext/ragel/base_lexer.rl"
	{te = p;p--;{
            callback(id_on_element_name, data, encoding, ts, te);
            ( state->cs) = 76;
        }}
	goto _again;
tr108:
#line 387 "ext/ragel/base_lexer.rl"
	{te = p+1;{
            callback(id_on_element_ns, data, encoding, ts, te - 1);
        }}
	goto st71;
st71:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof71;
case 71:
#line 1 "NONE"
	{ts = p;}
#line 1510 "ext/c/lexer.c"
	switch( (*p) ) {
		case 45: goto st72;
		case 95: goto st72;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st72;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st72;
	} else
		goto st72;
	goto st0;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
	switch( (*p) ) {
		case 45: goto st72;
		case 58: goto tr108;
		case 95: goto st72;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st72;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st72;
	} else
		goto st72;
	goto tr107;
tr110:
#line 64 "ext/ragel/base_lexer.rl"
	{te = p+1;{
        p--;
        {( state->cs) = ( state->stack)[--( state->top)];goto _again;}
    }}
	goto st73;
tr111:
	( state->cs) = 73;
#line 406 "ext/ragel/base_lexer.rl"
	{te = p+1;{
            p--;
            ( state->cs) = 75;
        }}
	goto _again;
tr112:
#line 413 "ext/ragel/base_lexer.rl"
	{te = p;p--;{
            callback_simple(id_on_string_squote);

            callback(id_on_string_body, data, encoding, ts, te);

            callback_simple(id_on_string_squote);
        }}
	goto st73;
st73:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof73;
case 73:
#line 1 "NONE"
	{ts = p;}
#line 1575 "ext/c/lexer.c"
	switch( (*p) ) {
		case 13: goto tr110;
		case 32: goto tr110;
		case 34: goto tr111;
		case 39: goto tr111;
		case 96: goto tr110;
	}
	if ( (*p) > 10 ) {
		if ( 60 <= (*p) && (*p) <= 62 )
			goto tr110;
	} else if ( (*p) >= 9 )
		goto tr110;
	goto st74;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
	switch( (*p) ) {
		case 13: goto tr112;
		case 32: goto tr112;
		case 34: goto tr112;
		case 39: goto tr112;
		case 96: goto tr112;
	}
	if ( (*p) > 10 ) {
		if ( 60 <= (*p) && (*p) <= 62 )
			goto tr112;
	} else if ( (*p) >= 9 )
		goto tr112;
	goto st74;
tr113:
#line 64 "ext/ragel/base_lexer.rl"
	{te = p+1;{
        p--;
        {( state->cs) = ( state->stack)[--( state->top)];goto _again;}
    }}
	goto st75;
tr114:
	( state->cs) = 75;
#line 435 "ext/ragel/base_lexer.rl"
	{te = p+1;{
            callback_simple(id_on_string_dquote);

            ( state->cs) = 51;
        }}
	goto _again;
tr115:
	( state->cs) = 75;
#line 429 "ext/ragel/base_lexer.rl"
	{te = p+1;{
            callback_simple(id_on_string_squote);

            ( state->cs) = 49;
        }}
	goto _again;
st75:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof75;
case 75:
#line 1 "NONE"
	{ts = p;}
#line 1639 "ext/c/lexer.c"
	switch( (*p) ) {
		case 34: goto tr114;
		case 39: goto tr115;
	}
	goto tr113;
tr116:
#line 494 "ext/ragel/base_lexer.rl"
	{te = p+1;}
	goto st76;
tr117:
#line 60 "ext/ragel/base_lexer.rl"
	{te = p+1;{
        advance_line(1);
    }}
	goto st76;
tr121:
#line 459 "ext/ragel/base_lexer.rl"
	{te = p+1;{
            if ( html_p )
            {
                {( state->stack)[( state->top)++] = 76; goto st73;}
            }
            else
            {
                {( state->stack)[( state->top)++] = 76; goto st75;}
            }
        }}
	goto st76;
tr122:
	( state->cs) = 76;
#line 471 "ext/ragel/base_lexer.rl"
	{te = p+1;{
            callback_simple(id_on_element_open_end);

            if ( html_script_p() )
            {
                ( state->cs) = 84;
            }
            else if ( html_style_p() )
            {
                ( state->cs) = 88;
            }
            else
            {
                ( state->cs) = 34;
            }
        }}
	goto _again;
tr123:
#line 60 "ext/ragel/base_lexer.rl"
	{te = p;p--;{
        advance_line(1);
    }}
	goto st76;
tr124:
#line 454 "ext/ragel/base_lexer.rl"
	{te = p;p--;{
            callback(id_on_attribute, data, encoding, ts, te);
        }}
	goto st76;
tr125:
#line 450 "ext/ragel/base_lexer.rl"
	{te = p+1;{
            callback(id_on_attribute_ns, data, encoding, ts, te - 1);
        }}
	goto st76;
tr126:
#line 494 "ext/ragel/base_lexer.rl"
	{te = p;p--;}
	goto st76;
tr127:
	( state->cs) = 76;
#line 489 "ext/ragel/base_lexer.rl"
	{te = p+1;{
            callback_simple(id_on_element_end);
            ( state->cs) = 34;
        }}
	goto _again;
st76:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof76;
case 76:
#line 1 "NONE"
	{ts = p;}
#line 1726 "ext/c/lexer.c"
	switch( (*p) ) {
		case 10: goto tr117;
		case 13: goto st77;
		case 45: goto st78;
		case 47: goto st79;
		case 61: goto tr121;
		case 62: goto tr122;
		case 95: goto st78;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st78;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st78;
	} else
		goto st78;
	goto tr116;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
	if ( (*p) == 10 )
		goto tr117;
	goto tr123;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
	switch( (*p) ) {
		case 45: goto st78;
		case 58: goto tr125;
		case 95: goto st78;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st78;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st78;
	} else
		goto st78;
	goto tr124;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
	if ( (*p) == 62 )
		goto tr127;
	goto tr126;
tr130:
	( state->cs) = 80;
#line 531 "ext/ragel/base_lexer.rl"
	{te = p;p--;{
            callback(id_on_text, data, encoding, ts, te);

            if ( lines > 0 )
            {
                advance_line(lines);

                lines = 0;
            }

            ( state->cs) = 34;
        }}
	goto _again;
tr132:
	( state->cs) = 80;
#line 545 "ext/ragel/base_lexer.rl"
	{te = p+1;{
            callback(id_on_text, data, encoding, ts, mark);

            p    = mark - 1;
            mark = 0;

            if ( lines > 0 )
            {
                advance_line(lines);

                lines = 0;
            }

            ( state->cs) = 34;
        }}
	goto _again;
tr133:
	( state->cs) = 80;
#line 531 "ext/ragel/base_lexer.rl"
	{te = p+1;{
            callback(id_on_text, data, encoding, ts, te);

            if ( lines > 0 )
            {
                advance_line(lines);

                lines = 0;
            }

            ( state->cs) = 34;
        }}
	goto _again;
st80:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof80;
case 80:
#line 1 "NONE"
	{ts = p;}
#line 1836 "ext/c/lexer.c"
	if ( (*p) == 60 )
		goto tr129;
	goto tr128;
tr128:
#line 56 "ext/ragel/base_lexer.rl"
	{
        if ( (*p) == '\n' ) lines++;
    }
	goto st81;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
#line 1850 "ext/c/lexer.c"
	if ( (*p) == 60 )
		goto tr131;
	goto tr128;
tr131:
#line 56 "ext/ragel/base_lexer.rl"
	{
        if ( (*p) == '\n' ) lines++;
    }
#line 545 "ext/ragel/base_lexer.rl"
	{ mark = p; }
	goto st82;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
#line 1866 "ext/c/lexer.c"
	switch( (*p) ) {
		case 33: goto tr132;
		case 45: goto tr132;
		case 60: goto tr131;
		case 63: goto tr132;
		case 95: goto tr132;
	}
	if ( (*p) < 65 ) {
		if ( 47 <= (*p) && (*p) <= 57 )
			goto tr132;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr132;
	} else
		goto tr132;
	goto tr128;
tr129:
#line 56 "ext/ragel/base_lexer.rl"
	{
        if ( (*p) == '\n' ) lines++;
    }
#line 545 "ext/ragel/base_lexer.rl"
	{ mark = p; }
	goto st83;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
#line 1895 "ext/c/lexer.c"
	switch( (*p) ) {
		case 33: goto tr133;
		case 45: goto tr133;
		case 60: goto tr131;
		case 63: goto tr133;
		case 95: goto tr133;
	}
	if ( (*p) < 65 ) {
		if ( 47 <= (*p) && (*p) <= 57 )
			goto tr133;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr133;
	} else
		goto tr133;
	goto tr128;
tr27:
#line 519 "ext/ragel/base_lexer.rl"
	{{p = ((te))-1;}{
        callback(id_on_text, data, encoding, ts, te);

        if ( lines > 0 )
        {
            advance_line(lines);

            lines = 0;
        }
    }}
	goto st84;
tr34:
	( state->cs) = 84;
#line 379 "ext/ragel/base_lexer.rl"
	{te = p+1;{
        callback_simple(id_on_element_end);

        ( state->cs) = 34;
    }}
	goto _again;
tr136:
#line 519 "ext/ragel/base_lexer.rl"
	{te = p;p--;{
        callback(id_on_text, data, encoding, ts, te);

        if ( lines > 0 )
        {
            advance_line(lines);

            lines = 0;
        }
    }}
	goto st84;
st84:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof84;
case 84:
#line 1 "NONE"
	{ts = p;}
#line 1955 "ext/c/lexer.c"
	if ( (*p) == 60 )
		goto tr135;
	goto tr134;
tr134:
#line 56 "ext/ragel/base_lexer.rl"
	{
        if ( (*p) == '\n' ) lines++;
    }
	goto st85;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
#line 1969 "ext/c/lexer.c"
	if ( (*p) == 60 )
		goto tr136;
	goto tr134;
tr135:
#line 1 "NONE"
	{te = p+1;}
#line 56 "ext/ragel/base_lexer.rl"
	{
        if ( (*p) == '\n' ) lines++;
    }
	goto st86;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
#line 1985 "ext/c/lexer.c"
	switch( (*p) ) {
		case 47: goto st21;
		case 60: goto tr138;
	}
	goto tr136;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
	if ( (*p) == 115 )
		goto st22;
	goto tr27;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
	if ( (*p) == 99 )
		goto st23;
	goto tr27;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
	if ( (*p) == 114 )
		goto st24;
	goto tr27;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
	if ( (*p) == 105 )
		goto st25;
	goto tr27;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
	if ( (*p) == 112 )
		goto st26;
	goto tr27;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
	if ( (*p) == 116 )
		goto st27;
	goto tr27;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
	if ( (*p) == 62 )
		goto tr34;
	goto tr27;
tr138:
#line 56 "ext/ragel/base_lexer.rl"
	{
        if ( (*p) == '\n' ) lines++;
    }
	goto st87;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
#line 2050 "ext/c/lexer.c"
	if ( (*p) == 60 )
		goto tr138;
	goto tr136;
tr35:
#line 519 "ext/ragel/base_lexer.rl"
	{{p = ((te))-1;}{
        callback(id_on_text, data, encoding, ts, te);

        if ( lines > 0 )
        {
            advance_line(lines);

            lines = 0;
        }
    }}
	goto st88;
tr41:
	( state->cs) = 88;
#line 379 "ext/ragel/base_lexer.rl"
	{te = p+1;{
        callback_simple(id_on_element_end);

        ( state->cs) = 34;
    }}
	goto _again;
tr141:
#line 519 "ext/ragel/base_lexer.rl"
	{te = p;p--;{
        callback(id_on_text, data, encoding, ts, te);

        if ( lines > 0 )
        {
            advance_line(lines);

            lines = 0;
        }
    }}
	goto st88;
st88:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof88;
case 88:
#line 1 "NONE"
	{ts = p;}
#line 2097 "ext/c/lexer.c"
	if ( (*p) == 60 )
		goto tr140;
	goto tr139;
tr139:
#line 56 "ext/ragel/base_lexer.rl"
	{
        if ( (*p) == '\n' ) lines++;
    }
	goto st89;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
#line 2111 "ext/c/lexer.c"
	if ( (*p) == 60 )
		goto tr141;
	goto tr139;
tr140:
#line 1 "NONE"
	{te = p+1;}
#line 56 "ext/ragel/base_lexer.rl"
	{
        if ( (*p) == '\n' ) lines++;
    }
	goto st90;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
#line 2127 "ext/c/lexer.c"
	switch( (*p) ) {
		case 47: goto st28;
		case 60: goto tr143;
	}
	goto tr141;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
	if ( (*p) == 115 )
		goto st29;
	goto tr35;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
	if ( (*p) == 116 )
		goto st30;
	goto tr35;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
	if ( (*p) == 121 )
		goto st31;
	goto tr35;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
	if ( (*p) == 108 )
		goto st32;
	goto tr35;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
	if ( (*p) == 101 )
		goto st33;
	goto tr35;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
	if ( (*p) == 62 )
		goto tr41;
	goto tr35;
tr143:
#line 56 "ext/ragel/base_lexer.rl"
	{
        if ( (*p) == '\n' ) lines++;
    }
	goto st91;
st91:
	if ( ++p == pe )
		goto _test_eof91;
case 91:
#line 2185 "ext/c/lexer.c"
	if ( (*p) == 60 )
		goto tr143;
	goto tr141;
	}
	_test_eof34: ( state->cs) = 34; goto _test_eof; 
	_test_eof35: ( state->cs) = 35; goto _test_eof; 
	_test_eof1: ( state->cs) = 1; goto _test_eof; 
	_test_eof2: ( state->cs) = 2; goto _test_eof; 
	_test_eof3: ( state->cs) = 3; goto _test_eof; 
	_test_eof4: ( state->cs) = 4; goto _test_eof; 
	_test_eof5: ( state->cs) = 5; goto _test_eof; 
	_test_eof6: ( state->cs) = 6; goto _test_eof; 
	_test_eof7: ( state->cs) = 7; goto _test_eof; 
	_test_eof8: ( state->cs) = 8; goto _test_eof; 
	_test_eof9: ( state->cs) = 9; goto _test_eof; 
	_test_eof36: ( state->cs) = 36; goto _test_eof; 
	_test_eof10: ( state->cs) = 10; goto _test_eof; 
	_test_eof11: ( state->cs) = 11; goto _test_eof; 
	_test_eof12: ( state->cs) = 12; goto _test_eof; 
	_test_eof13: ( state->cs) = 13; goto _test_eof; 
	_test_eof14: ( state->cs) = 14; goto _test_eof; 
	_test_eof15: ( state->cs) = 15; goto _test_eof; 
	_test_eof16: ( state->cs) = 16; goto _test_eof; 
	_test_eof17: ( state->cs) = 17; goto _test_eof; 
	_test_eof18: ( state->cs) = 18; goto _test_eof; 
	_test_eof37: ( state->cs) = 37; goto _test_eof; 
	_test_eof38: ( state->cs) = 38; goto _test_eof; 
	_test_eof39: ( state->cs) = 39; goto _test_eof; 
	_test_eof40: ( state->cs) = 40; goto _test_eof; 
	_test_eof41: ( state->cs) = 41; goto _test_eof; 
	_test_eof42: ( state->cs) = 42; goto _test_eof; 
	_test_eof19: ( state->cs) = 19; goto _test_eof; 
	_test_eof43: ( state->cs) = 43; goto _test_eof; 
	_test_eof44: ( state->cs) = 44; goto _test_eof; 
	_test_eof45: ( state->cs) = 45; goto _test_eof; 
	_test_eof20: ( state->cs) = 20; goto _test_eof; 
	_test_eof46: ( state->cs) = 46; goto _test_eof; 
	_test_eof47: ( state->cs) = 47; goto _test_eof; 
	_test_eof48: ( state->cs) = 48; goto _test_eof; 
	_test_eof49: ( state->cs) = 49; goto _test_eof; 
	_test_eof50: ( state->cs) = 50; goto _test_eof; 
	_test_eof51: ( state->cs) = 51; goto _test_eof; 
	_test_eof52: ( state->cs) = 52; goto _test_eof; 
	_test_eof53: ( state->cs) = 53; goto _test_eof; 
	_test_eof54: ( state->cs) = 54; goto _test_eof; 
	_test_eof55: ( state->cs) = 55; goto _test_eof; 
	_test_eof56: ( state->cs) = 56; goto _test_eof; 
	_test_eof57: ( state->cs) = 57; goto _test_eof; 
	_test_eof58: ( state->cs) = 58; goto _test_eof; 
	_test_eof59: ( state->cs) = 59; goto _test_eof; 
	_test_eof60: ( state->cs) = 60; goto _test_eof; 
	_test_eof61: ( state->cs) = 61; goto _test_eof; 
	_test_eof62: ( state->cs) = 62; goto _test_eof; 
	_test_eof63: ( state->cs) = 63; goto _test_eof; 
	_test_eof64: ( state->cs) = 64; goto _test_eof; 
	_test_eof65: ( state->cs) = 65; goto _test_eof; 
	_test_eof66: ( state->cs) = 66; goto _test_eof; 
	_test_eof67: ( state->cs) = 67; goto _test_eof; 
	_test_eof68: ( state->cs) = 68; goto _test_eof; 
	_test_eof69: ( state->cs) = 69; goto _test_eof; 
	_test_eof70: ( state->cs) = 70; goto _test_eof; 
	_test_eof71: ( state->cs) = 71; goto _test_eof; 
	_test_eof72: ( state->cs) = 72; goto _test_eof; 
	_test_eof73: ( state->cs) = 73; goto _test_eof; 
	_test_eof74: ( state->cs) = 74; goto _test_eof; 
	_test_eof75: ( state->cs) = 75; goto _test_eof; 
	_test_eof76: ( state->cs) = 76; goto _test_eof; 
	_test_eof77: ( state->cs) = 77; goto _test_eof; 
	_test_eof78: ( state->cs) = 78; goto _test_eof; 
	_test_eof79: ( state->cs) = 79; goto _test_eof; 
	_test_eof80: ( state->cs) = 80; goto _test_eof; 
	_test_eof81: ( state->cs) = 81; goto _test_eof; 
	_test_eof82: ( state->cs) = 82; goto _test_eof; 
	_test_eof83: ( state->cs) = 83; goto _test_eof; 
	_test_eof84: ( state->cs) = 84; goto _test_eof; 
	_test_eof85: ( state->cs) = 85; goto _test_eof; 
	_test_eof86: ( state->cs) = 86; goto _test_eof; 
	_test_eof21: ( state->cs) = 21; goto _test_eof; 
	_test_eof22: ( state->cs) = 22; goto _test_eof; 
	_test_eof23: ( state->cs) = 23; goto _test_eof; 
	_test_eof24: ( state->cs) = 24; goto _test_eof; 
	_test_eof25: ( state->cs) = 25; goto _test_eof; 
	_test_eof26: ( state->cs) = 26; goto _test_eof; 
	_test_eof27: ( state->cs) = 27; goto _test_eof; 
	_test_eof87: ( state->cs) = 87; goto _test_eof; 
	_test_eof88: ( state->cs) = 88; goto _test_eof; 
	_test_eof89: ( state->cs) = 89; goto _test_eof; 
	_test_eof90: ( state->cs) = 90; goto _test_eof; 
	_test_eof28: ( state->cs) = 28; goto _test_eof; 
	_test_eof29: ( state->cs) = 29; goto _test_eof; 
	_test_eof30: ( state->cs) = 30; goto _test_eof; 
	_test_eof31: ( state->cs) = 31; goto _test_eof; 
	_test_eof32: ( state->cs) = 32; goto _test_eof; 
	_test_eof33: ( state->cs) = 33; goto _test_eof; 
	_test_eof91: ( state->cs) = 91; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( ( state->cs) ) {
	case 35: goto tr44;
	case 1: goto tr0;
	case 2: goto tr0;
	case 3: goto tr0;
	case 4: goto tr0;
	case 5: goto tr0;
	case 6: goto tr0;
	case 7: goto tr0;
	case 8: goto tr0;
	case 9: goto tr0;
	case 36: goto tr48;
	case 10: goto tr0;
	case 11: goto tr0;
	case 12: goto tr0;
	case 13: goto tr0;
	case 14: goto tr0;
	case 15: goto tr0;
	case 16: goto tr0;
	case 17: goto tr0;
	case 18: goto tr0;
	case 37: goto tr49;
	case 38: goto tr50;
	case 39: goto tr50;
	case 41: goto tr55;
	case 42: goto tr55;
	case 19: goto tr23;
	case 44: goto tr59;
	case 45: goto tr59;
	case 20: goto tr25;
	case 47: goto tr63;
	case 48: goto tr63;
	case 50: goto tr67;
	case 52: goto tr70;
	case 54: goto tr73;
	case 56: goto tr85;
	case 57: goto tr86;
	case 58: goto tr87;
	case 59: goto tr87;
	case 60: goto tr87;
	case 61: goto tr87;
	case 62: goto tr87;
	case 63: goto tr87;
	case 64: goto tr87;
	case 65: goto tr87;
	case 66: goto tr87;
	case 67: goto tr87;
	case 69: goto tr102;
	case 70: goto tr104;
	case 72: goto tr107;
	case 74: goto tr112;
	case 77: goto tr123;
	case 78: goto tr124;
	case 79: goto tr126;
	case 81: goto tr130;
	case 82: goto tr130;
	case 83: goto tr130;
	case 85: goto tr136;
	case 86: goto tr136;
	case 21: goto tr27;
	case 22: goto tr27;
	case 23: goto tr27;
	case 24: goto tr27;
	case 25: goto tr27;
	case 26: goto tr27;
	case 27: goto tr27;
	case 87: goto tr136;
	case 89: goto tr141;
	case 90: goto tr141;
	case 28: goto tr35;
	case 29: goto tr35;
	case 30: goto tr35;
	case 31: goto tr35;
	case 32: goto tr35;
	case 33: goto tr35;
	case 91: goto tr141;
	}
	}

	_out: {}
	}

#line 133 "ext/c/lexer.rl"

    state->lines = lines;

    return Qnil;
}

/**
 * Resets the internal state of the lexer.
 */
VALUE oga_xml_lexer_reset(VALUE self)
{
    OgaLexerState *state;

    Data_Get_Struct(self, OgaLexerState, state);

    state->act   = 0;
    state->cs    = c_lexer_start;
    state->lines = 0;
    state->top   = 0;

    return Qnil;
}

/**
 * Frees the associated lexer state struct.
 */
void oga_xml_lexer_free(void *state)
{
    free((OgaLexerState *) state);
}

/**
 * Allocates and wraps the C lexer state struct. This state is used to keep
 * track of the current position, line numbers, etc.
 */
VALUE oga_xml_lexer_allocate(VALUE klass)
{
    OgaLexerState *state = malloc(sizeof(OgaLexerState));

    return Data_Wrap_Struct(klass, NULL, oga_xml_lexer_free, state);
}


#line 182 "ext/c/lexer.rl"


void Init_liboga_xml_lexer()
{
    VALUE mOga   = rb_const_get(rb_cObject, rb_intern("Oga"));
    VALUE mXML   = rb_const_get(mOga, rb_intern("XML"));
    VALUE cLexer = rb_define_class_under(mXML, "Lexer", rb_cObject);

    id_advance_line  = rb_intern("advance_line");
    id_html_script_p = rb_intern("html_script?");
    id_html_style_p  = rb_intern("html_style?");
    id_html          = rb_intern("html");

    rb_define_method(cLexer, "advance_native", oga_xml_lexer_advance, 1);
    rb_define_method(cLexer, "reset_native", oga_xml_lexer_reset, 0);

    rb_define_alloc_func(cLexer, oga_xml_lexer_allocate);
}
