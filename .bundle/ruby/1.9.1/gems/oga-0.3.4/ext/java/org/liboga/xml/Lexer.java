
// line 1 "ext/java/org/liboga/xml/Lexer.rl"
package org.liboga.xml;


// line 4 "ext/java/org/liboga/xml/Lexer.rl"

import java.io.IOException;

import org.jcodings.Encoding;

import org.jruby.Ruby;
import org.jruby.RubyModule;
import org.jruby.RubyClass;
import org.jruby.RubyObject;
import org.jruby.RubyString;
import org.jruby.RubyFixnum;
import org.jruby.util.ByteList;
import org.jruby.anno.JRubyClass;
import org.jruby.anno.JRubyMethod;
import org.jruby.runtime.ThreadContext;
import org.jruby.runtime.ObjectAllocator;
import org.jruby.runtime.builtin.IRubyObject;

/**
 * Lexer support class for JRuby.
 *
 * The Lexer class contains the raw Ragel loop and calls back in to Ruby land
 * whenever a Ragel action is needed similar to the C extension setup.
 *
 * This class requires Ruby land to first define the `Oga::XML` namespace.
 */
@JRubyClass(name="Oga::XML::Lexer", parent="Object")
public class Lexer extends RubyObject
{
    /**
     * The current Ruby runtime.
     */
    private Ruby runtime;

    
// line 43 "ext/java/org/liboga/xml/Lexer.java"
private static byte[] init__java_lexer_actions_0()
{
	return new byte [] {
	    0,    1,    0,    1,    2,    1,    3,    1,    4,    1,    5,    1,
	    6,    1,    7,    1,    8,    1,    9,    1,   10,    1,   11,    1,
	   12,    1,   13,    1,   14,    1,   15,    1,   16,    1,   17,    1,
	   18,    1,   21,    1,   22,    1,   23,    1,   24,    1,   25,    1,
	   26,    1,   27,    1,   28,    1,   29,    1,   30,    1,   34,    1,
	   35,    1,   36,    1,   37,    1,   38,    1,   39,    1,   40,    1,
	   41,    1,   42,    1,   43,    1,   44,    1,   45,    1,   46,    1,
	   47,    1,   48,    1,   49,    1,   50,    1,   51,    1,   52,    1,
	   53,    1,   54,    1,   55,    1,   56,    1,   57,    1,   58,    1,
	   59,    1,   60,    1,   61,    1,   64,    1,   65,    1,   66,    1,
	   67,    1,   68,    1,   69,    1,   70,    1,   71,    1,   72,    1,
	   73,    2,    0,    1,    2,    0,   33,    2,    4,    0,    2,    4,
	   19,    2,    4,   20,    2,    4,   62,    2,    4,   63,    2,   31,
	    0,    2,   32,    0
	};
}

private static final byte _java_lexer_actions[] = init__java_lexer_actions_0();


private static short[] init__java_lexer_key_offsets_0()
{
	return new short [] {
	    0,    0,    4,    5,    7,    9,   11,   13,   15,   17,   21,   22,
	   23,   24,   25,   26,   27,   35,   45,   54,   55,   56,   57,   58,
	   59,   60,   61,   62,   63,   64,   65,   66,   67,   68,   69,   70,
	   81,   85,   93,  102,  111,  112,  113,  114,  115,  116,  117,  118,
	  119,  120,  121,  122,  123,  124,  125,  126,  144,  145,  153,  162,
	  171,  180,  189,  198,  207,  216,  225,  234,  243,  254,  262,  263,
	  271,  280,  289,  298,  300,  313,  314,  323,  324,  325,  326,  337,
	  348,  349,  350,  352,  353,  354,  355,  357
	};
}

private static final short _java_lexer_key_offsets[] = init__java_lexer_key_offsets_0();


private static char[] init__java_lexer_trans_keys_0()
{
	return new char [] {
	   45,   68,   91,  100,   45,   79,  111,   67,   99,   84,  116,   89,
	  121,   80,  112,   69,  101,   13,   32,    9,   10,   67,   68,   65,
	   84,   65,   91,   45,   95,   48,   57,   65,   90,   97,  122,   45,
	   58,   62,   95,   48,   57,   65,   90,   97,  122,   45,   95,  120,
	   48,   57,   65,   90,   97,  122,   62,   62,  115,   99,  114,  105,
	  112,  116,   62,  115,  116,  121,  108,  101,   62,   60,   33,   45,
	   47,   63,   95,   48,   57,   65,   90,   97,  122,   13,   32,    9,
	   10,   45,   95,   48,   57,   65,   90,   97,  122,   45,   95,  109,
	   48,   57,   65,   90,   97,  122,   45,   95,  108,   48,   57,   65,
	   90,   97,  122,   45,   45,   45,   93,   93,   93,   63,   63,   62,
	   39,   39,   34,   34,   93,   93,    9,   10,   13,   32,   34,   39,
	   45,   62,   80,   83,   91,   95,   48,   57,   65,   90,   97,  122,
	   10,   45,   95,   48,   57,   65,   90,   97,  122,   45,   85,   95,
	   48,   57,   65,   90,   97,  122,   45,   66,   95,   48,   57,   65,
	   90,   97,  122,   45,   76,   95,   48,   57,   65,   90,   97,  122,
	   45,   73,   95,   48,   57,   65,   90,   97,  122,   45,   67,   95,
	   48,   57,   65,   90,   97,  122,   45,   89,   95,   48,   57,   65,
	   90,   97,  122,   45,   83,   95,   48,   57,   65,   90,   97,  122,
	   45,   84,   95,   48,   57,   65,   90,   97,  122,   45,   69,   95,
	   48,   57,   65,   90,   97,  122,   45,   77,   95,   48,   57,   65,
	   90,   97,  122,   34,   39,   45,   63,   95,   48,   57,   65,   90,
	   97,  122,   45,   95,   48,   57,   65,   90,   97,  122,   62,   45,
	   95,   48,   57,   65,   90,   97,  122,   45,   58,   95,   48,   57,
	   65,   90,   97,  122,   13,   32,   34,   39,   96,    9,   10,   60,
	   62,   13,   32,   34,   39,   96,    9,   10,   60,   62,   34,   39,
	   10,   13,   45,   47,   61,   62,   95,   48,   57,   65,   90,   97,
	  122,   10,   45,   58,   95,   48,   57,   65,   90,   97,  122,   62,
	   60,   60,   33,   45,   60,   63,   95,   47,   57,   65,   90,   97,
	  122,   33,   45,   60,   63,   95,   47,   57,   65,   90,   97,  122,
	   60,   60,   47,   60,   60,   60,   60,   47,   60,   60,    0
	};
}

private static final char _java_lexer_trans_keys[] = init__java_lexer_trans_keys_0();


private static byte[] init__java_lexer_single_lengths_0()
{
	return new byte [] {
	    0,    4,    1,    2,    2,    2,    2,    2,    2,    2,    1,    1,
	    1,    1,    1,    1,    2,    4,    3,    1,    1,    1,    1,    1,
	    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    5,
	    2,    2,    3,    3,    1,    1,    1,    1,    1,    1,    1,    1,
	    1,    1,    1,    1,    1,    1,    1,   12,    1,    2,    3,    3,
	    3,    3,    3,    3,    3,    3,    3,    3,    5,    2,    1,    2,
	    3,    5,    5,    2,    7,    1,    3,    1,    1,    1,    5,    5,
	    1,    1,    2,    1,    1,    1,    2,    1
	};
}

private static final byte _java_lexer_single_lengths[] = init__java_lexer_single_lengths_0();


private static byte[] init__java_lexer_range_lengths_0()
{
	return new byte [] {
	    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    0,    0,
	    0,    0,    0,    0,    3,    3,    3,    0,    0,    0,    0,    0,
	    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    3,
	    1,    3,    3,    3,    0,    0,    0,    0,    0,    0,    0,    0,
	    0,    0,    0,    0,    0,    0,    0,    3,    0,    3,    3,    3,
	    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,    0,    3,
	    3,    2,    2,    0,    3,    0,    3,    0,    0,    0,    3,    3,
	    0,    0,    0,    0,    0,    0,    0,    0
	};
}

private static final byte _java_lexer_range_lengths[] = init__java_lexer_range_lengths_0();


private static short[] init__java_lexer_index_offsets_0()
{
	return new short [] {
	    0,    0,    5,    7,   10,   13,   16,   19,   22,   25,   29,   31,
	   33,   35,   37,   39,   41,   47,   55,   62,   64,   66,   68,   70,
	   72,   74,   76,   78,   80,   82,   84,   86,   88,   90,   92,   94,
	  103,  107,  113,  120,  127,  129,  131,  133,  135,  137,  139,  141,
	  143,  145,  147,  149,  151,  153,  155,  157,  173,  175,  181,  188,
	  195,  202,  209,  216,  223,  230,  237,  244,  251,  260,  266,  268,
	  274,  281,  289,  297,  300,  311,  313,  320,  322,  324,  326,  335,
	  344,  346,  348,  351,  353,  355,  357,  360
	};
}

private static final short _java_lexer_index_offsets[] = init__java_lexer_index_offsets_0();


private static byte[] init__java_lexer_trans_targs_0()
{
	return new byte [] {
	    2,    3,   10,    3,   34,   34,   34,    4,    4,   34,    5,    5,
	   34,    6,    6,   34,    7,    7,   34,    8,    8,   34,    9,    9,
	   34,   36,   36,   36,   34,   11,   34,   12,   34,   13,   34,   14,
	   34,   15,   34,   34,   34,   17,   17,   17,   17,   17,   34,   17,
	   16,   34,   17,   17,   17,   17,   34,   37,   37,   38,   37,   37,
	   37,   34,   40,   40,   43,   43,   22,   84,   23,   84,   24,   84,
	   25,   84,   26,   84,   27,   84,   84,   84,   29,   88,   30,   88,
	   31,   88,   32,   88,   33,   88,   88,   88,   35,   34,    1,   34,
	   16,   18,   34,   34,   34,   34,   34,   36,   36,   36,   34,   37,
	   37,   37,   37,   37,   34,   37,   37,   39,   37,   37,   37,   34,
	   37,   37,   37,   37,   37,   37,   34,   42,   41,   40,   41,   19,
	   40,   45,   44,   43,   44,   20,   43,   48,   47,   46,   47,   46,
	   46,   49,   50,   49,   50,   51,   52,   51,   52,   53,   54,   53,
	   54,   55,   55,   56,   55,   55,   55,   57,   55,   58,   63,   55,
	   57,   57,   57,   57,    0,   55,   55,   57,   57,   57,   57,   57,
	   55,   57,   59,   57,   57,   57,   57,   55,   57,   60,   57,   57,
	   57,   57,   55,   57,   61,   57,   57,   57,   57,   55,   57,   62,
	   57,   57,   57,   57,   55,   57,   57,   57,   57,   57,   57,   55,
	   57,   64,   57,   57,   57,   57,   55,   57,   65,   57,   57,   57,
	   57,   55,   57,   66,   57,   57,   57,   57,   55,   57,   67,   57,
	   57,   57,   57,   55,   57,   57,   57,   57,   57,   57,   55,   68,
	   68,   69,   70,   69,   69,   69,   69,   68,   69,   69,   69,   69,
	   69,   68,   68,   68,   72,   72,   72,   72,   72,    0,   72,   71,
	   72,   72,   72,   72,   71,   73,   73,   73,   73,   73,   73,   73,
	   74,   73,   73,   73,   73,   73,   73,   73,   74,   75,   75,   75,
	   76,   77,   78,   79,   76,   76,   78,   78,   78,   78,   76,   76,
	   76,   78,   76,   78,   78,   78,   78,   76,   76,   76,   83,   81,
	   82,   81,   80,   80,   82,   80,   80,   80,   80,   80,   81,   80,
	   80,   82,   80,   80,   80,   80,   80,   81,   86,   85,   84,   85,
	   21,   87,   84,   87,   84,   90,   89,   88,   89,   28,   91,   88,
	   91,   88,   34,   34,   34,   34,   34,   34,   34,   34,   34,   34,
	   34,   34,   34,   34,   34,   34,   34,   34,   40,   43,   84,   84,
	   84,   84,   84,   84,   84,   88,   88,   88,   88,   88,   88,   34,
	   34,   34,   34,   34,   40,   40,   43,   43,   46,   46,   49,   51,
	   53,   55,   55,   55,   55,   55,   55,   55,   55,   55,   55,   55,
	   55,   68,   68,   71,   73,   76,   76,   76,   80,   80,   80,   84,
	   84,   84,   88,   88,   88,    0
	};
}

private static final byte _java_lexer_trans_targs[] = init__java_lexer_trans_targs_0();


private static short[] init__java_lexer_trans_actions_0()
{
	return new short [] {
	    0,    0,    0,    0,  129,  113,  129,    0,    0,  129,    0,    0,
	  129,    0,    0,  129,    0,    0,  129,    0,    0,  129,    0,    0,
	  129,    1,    1,    1,  129,    0,  129,    0,  129,    0,  129,    0,
	  129,    0,  129,  115,  129,    0,    0,    0,    0,    0,  129,    0,
	    0,  119,    0,    0,    0,    0,  129,  151,  151,    0,  151,  151,
	  151,  129,    9,   13,   15,   19,    0,  105,    0,  105,    0,  105,
	    0,  105,    0,  105,    0,  105,  101,  105,    0,  111,    0,  111,
	    0,  111,    0,  111,    0,  111,  107,  111,    7,  121,    0,  117,
	    0,    0,  117,  117,  117,  117,  127,    1,    1,    1,  123,  151,
	  151,  151,  151,  151,  131,  151,  151,    0,  151,  151,  151,  125,
	  151,  151,  148,  151,  151,  151,  125,  139,    1,   11,    1,    0,
	   11,  139,    1,   17,    1,    0,   17,    1,    1,   23,    1,   21,
	   23,   25,    1,   27,    1,   29,    1,   31,    1,   33,    1,   35,
	    1,   47,   45,    0,   47,   41,   39,  145,   43,    0,    0,   37,
	  145,  145,  145,  145,    0,   45,   51,  145,  145,  145,  145,  145,
	   53,  145,    0,  145,  145,  145,  145,   49,  145,    0,  145,  145,
	  145,  145,   49,  145,    0,  145,  145,  145,  145,   49,  145,    0,
	  145,  145,  145,  145,   49,  145,  142,  145,  145,  145,  145,   49,
	  145,    0,  145,  145,  145,  145,   49,  145,    0,  145,  145,  145,
	  145,   49,  145,    0,  145,  145,  145,  145,   49,  145,    0,  145,
	  145,  145,  145,   49,  145,  142,  145,  145,  145,  145,   49,  157,
	  154,    1,    1,    1,    1,    1,    1,  136,    0,    0,    0,    0,
	    0,   57,   55,   59,    0,    0,    0,    0,    0,    0,    0,   61,
	    0,    0,    0,    0,   63,   67,   67,   65,   65,   67,   67,   67,
	    0,   69,   69,   69,   69,   69,   69,   69,    0,   73,   71,   75,
	   77,    0,    0,    0,   81,   83,    0,    0,    0,    0,   87,   77,
	   89,    0,   79,    0,    0,    0,    0,   91,   85,   93,  133,    1,
	  133,    1,   97,   97,  133,   97,   97,   97,   97,   97,    1,   95,
	   95,  133,   95,   95,   95,   95,   95,    1,  139,    1,  103,    1,
	    0,    1,  103,    1,  103,  139,    1,  109,    1,    0,    1,  109,
	    1,  109,  129,  129,  129,  129,  129,  129,  129,  129,  129,  129,
	  129,  129,  129,  129,  129,  129,  129,  129,   13,   19,  105,  105,
	  105,  105,  105,  105,  105,  111,  111,  111,  111,  111,  111,  127,
	  123,  131,  125,  125,   11,   11,   17,   17,   23,   23,   27,   31,
	   35,   51,   53,   49,   49,   49,   49,   49,   49,   49,   49,   49,
	   49,   57,   59,   63,   69,   89,   91,   93,   99,   99,   99,  103,
	  103,  103,  109,  109,  109,    0
	};
}

private static final short _java_lexer_trans_actions[] = init__java_lexer_trans_actions_0();


private static short[] init__java_lexer_to_state_actions_0()
{
	return new short [] {
	    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
	    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
	    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    3,    0,
	    0,    0,    0,    0,    3,    0,    0,    3,    0,    0,    3,    0,
	    0,    3,    0,    3,    0,    3,    0,    3,    0,    0,    0,    0,
	    0,    0,    0,    0,    0,    0,    0,    0,    3,    0,    0,    3,
	    0,    3,    0,    3,    3,    0,    0,    0,    3,    0,    0,    0,
	    3,    0,    0,    0,    3,    0,    0,    0
	};
}

private static final short _java_lexer_to_state_actions[] = init__java_lexer_to_state_actions_0();


private static short[] init__java_lexer_from_state_actions_0()
{
	return new short [] {
	    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
	    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
	    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    5,    0,
	    0,    0,    0,    0,    5,    0,    0,    5,    0,    0,    5,    0,
	    0,    5,    0,    5,    0,    5,    0,    5,    0,    0,    0,    0,
	    0,    0,    0,    0,    0,    0,    0,    0,    5,    0,    0,    5,
	    0,    5,    0,    5,    5,    0,    0,    0,    5,    0,    0,    0,
	    5,    0,    0,    0,    5,    0,    0,    0
	};
}

private static final short _java_lexer_from_state_actions[] = init__java_lexer_from_state_actions_0();


private static short[] init__java_lexer_eof_trans_0()
{
	return new short [] {
	    0,  380,  380,  380,  380,  380,  380,  380,  380,  380,  380,  380,
	  380,  380,  380,  380,  380,  380,  380,  381,  382,  389,  389,  389,
	  389,  389,  389,  389,  395,  395,  395,  395,  395,  395,    0,  396,
	  397,  398,  400,  400,    0,  402,  402,    0,  404,  404,    0,  406,
	  406,    0,  407,    0,  408,    0,  409,    0,  410,  411,  421,  421,
	  421,  421,  421,  421,  421,  421,  421,  421,    0,  422,  423,    0,
	  424,    0,  425,    0,    0,  426,  427,  428,    0,  431,  431,  431,
	    0,  434,  434,  434,    0,  437,  437,  437
	};
}

private static final short _java_lexer_eof_trans[] = init__java_lexer_eof_trans_0();


static final int java_lexer_start = 34;
static final int java_lexer_first_final = 34;
static final int java_lexer_error = 0;

static final int java_lexer_en_comment_body = 40;
static final int java_lexer_en_cdata_body = 43;
static final int java_lexer_en_proc_ins_body = 46;
static final int java_lexer_en_string_squote = 49;
static final int java_lexer_en_string_dquote = 51;
static final int java_lexer_en_doctype_inline = 53;
static final int java_lexer_en_doctype = 55;
static final int java_lexer_en_xml_decl = 68;
static final int java_lexer_en_element_name = 71;
static final int java_lexer_en_html_attribute_value = 73;
static final int java_lexer_en_xml_attribute_value = 75;
static final int java_lexer_en_element_head = 76;
static final int java_lexer_en_text = 80;
static final int java_lexer_en_html_script = 84;
static final int java_lexer_en_html_style = 88;
static final int java_lexer_en_main = 34;


// line 39 "ext/java/org/liboga/xml/Lexer.rl"

    /* Used by Ragel to keep track of the current state. */
    int act;
    int cs;
    int top;
    int lines;
    int[] stack;

    /**
     * Sets up the current class in the Ruby runtime.
     */
    public static void load(Ruby runtime)
    {
        RubyModule xml = (RubyModule) runtime.getModule("Oga")
            .getConstant("XML");

        RubyClass lexer = xml.defineClassUnder(
            "Lexer",
            runtime.getObject(),
            ALLOCATOR
        );

        lexer.defineAnnotatedMethods(Lexer.class);
    }

    private static final ObjectAllocator ALLOCATOR = new ObjectAllocator()
    {
        public IRubyObject allocate(Ruby runtime, RubyClass klass)
        {
            return new org.liboga.xml.Lexer(runtime, klass);
        }
    };

    public Lexer(Ruby runtime, RubyClass klass)
    {
        super(runtime, klass);

        this.runtime = runtime;
    }

    /**
     * Runs the bulk of the Ragel loop and calls back in to Ruby.
     *
     * This method pulls its data in from the instance variable `@data`. The
     * Ruby side of the Lexer class should set this variable to a String in its
     * constructor method. Encodings are passed along to make sure that token
     * values share the same encoding as the input.
     *
     * This method always returns nil.
     */
    @JRubyMethod
    public IRubyObject advance_native(ThreadContext context, RubyString rb_str)
    {
        Boolean html_p = this.callMethod(context, "html").isTrue();

        Encoding encoding = rb_str.getEncoding();

        byte[] data = rb_str.getBytes();

        int ts    = 0;
        int te    = 0;
        int p     = 0;
        int mark  = 0;
        int lines = this.lines;
        int pe    = data.length;
        int eof   = data.length;

        String id_advance_line        = "advance_line";
        String id_on_attribute        = "on_attribute";
        String id_on_attribute_ns     = "on_attribute_ns";
        String id_on_cdata_start      = "on_cdata_start";
        String id_on_cdata_body       = "on_cdata_body";
        String id_on_cdata_end        = "on_cdata_end";
        String id_on_comment_start    = "on_comment_start";
        String id_on_comment_body     = "on_comment_body";
        String id_on_comment_end      = "on_comment_end";
        String id_on_doctype_end      = "on_doctype_end";
        String id_on_doctype_inline   = "on_doctype_inline";
        String id_on_doctype_name     = "on_doctype_name";
        String id_on_doctype_start    = "on_doctype_start";
        String id_on_doctype_type     = "on_doctype_type";
        String id_on_element_end      = "on_element_end";
        String id_on_element_name     = "on_element_name";
        String id_on_element_ns       = "on_element_ns";
        String id_on_element_open_end = "on_element_open_end";
        String id_on_element_start    = "on_element_start";
        String id_on_proc_ins_end     = "on_proc_ins_end";
        String id_on_proc_ins_name    = "on_proc_ins_name";
        String id_on_proc_ins_start   = "on_proc_ins_start";
        String id_on_proc_ins_body    = "on_proc_ins_body";
        String id_on_string_body      = "on_string_body";
        String id_on_string_dquote    = "on_string_dquote";
        String id_on_string_squote    = "on_string_squote";
        String id_on_text             = "on_text";
        String id_on_xml_decl_end     = "on_xml_decl_end";
        String id_on_xml_decl_start   = "on_xml_decl_start";

        
// line 438 "ext/java/org/liboga/xml/Lexer.java"
	{
	int _klen;
	int _trans = 0;
	int _acts;
	int _nacts;
	int _keys;
	int _goto_targ = 0;

	_goto: while (true) {
	switch ( _goto_targ ) {
	case 0:
	if ( p == pe ) {
		_goto_targ = 4;
		continue _goto;
	}
	if ( ( this.cs) == 0 ) {
		_goto_targ = 5;
		continue _goto;
	}
case 1:
	_acts = _java_lexer_from_state_actions[( this.cs)];
	_nacts = (int) _java_lexer_actions[_acts++];
	while ( _nacts-- > 0 ) {
		switch ( _java_lexer_actions[_acts++] ) {
	case 3:
// line 1 "NONE"
	{ts = p;}
	break;
// line 467 "ext/java/org/liboga/xml/Lexer.java"
		}
	}

	_match: do {
	_keys = _java_lexer_key_offsets[( this.cs)];
	_trans = _java_lexer_index_offsets[( this.cs)];
	_klen = _java_lexer_single_lengths[( this.cs)];
	if ( _klen > 0 ) {
		int _lower = _keys;
		int _mid;
		int _upper = _keys + _klen - 1;
		while (true) {
			if ( _upper < _lower )
				break;

			_mid = _lower + ((_upper-_lower) >> 1);
			if ( data[p] < _java_lexer_trans_keys[_mid] )
				_upper = _mid - 1;
			else if ( data[p] > _java_lexer_trans_keys[_mid] )
				_lower = _mid + 1;
			else {
				_trans += (_mid - _keys);
				break _match;
			}
		}
		_keys += _klen;
		_trans += _klen;
	}

	_klen = _java_lexer_range_lengths[( this.cs)];
	if ( _klen > 0 ) {
		int _lower = _keys;
		int _mid;
		int _upper = _keys + (_klen<<1) - 2;
		while (true) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( data[p] < _java_lexer_trans_keys[_mid] )
				_upper = _mid - 2;
			else if ( data[p] > _java_lexer_trans_keys[_mid+1] )
				_lower = _mid + 2;
			else {
				_trans += ((_mid - _keys)>>1);
				break _match;
			}
		}
		_trans += _klen;
	}
	} while (false);

case 3:
	( this.cs) = _java_lexer_trans_targs[_trans];

	if ( _java_lexer_trans_actions[_trans] != 0 ) {
		_acts = _java_lexer_trans_actions[_trans];
		_nacts = (int) _java_lexer_actions[_acts++];
		while ( _nacts-- > 0 )
	{
			switch ( _java_lexer_actions[_acts++] )
			{
	case 0:
// line 56 "ext/ragel/base_lexer.rl"
	{
        if ( data[p] == '\n' ) lines++;
    }
	break;
	case 1:
// line 545 "ext/ragel/base_lexer.rl"
	{ mark = p; }
	break;
	case 4:
// line 1 "NONE"
	{te = p+1;}
	break;
	case 5:
// line 102 "ext/ragel/base_lexer.rl"
	{te = p+1;{
            callback_simple(id_on_comment_end);

            ( this.cs) = 34;
        }}
	break;
	case 6:
// line 91 "ext/ragel/base_lexer.rl"
	{te = p;p--;{
            callback(id_on_comment_body, data, encoding, ts, te);

            if ( lines > 0 )
            {
                advance_line(lines);

                lines = 0;
            }
        }}
	break;
	case 7:
// line 91 "ext/ragel/base_lexer.rl"
	{{p = ((te))-1;}{
            callback(id_on_comment_body, data, encoding, ts, te);

            if ( lines > 0 )
            {
                advance_line(lines);

                lines = 0;
            }
        }}
	break;
	case 8:
// line 141 "ext/ragel/base_lexer.rl"
	{te = p+1;{
            callback_simple(id_on_cdata_end);

            ( this.cs) = 34;
        }}
	break;
	case 9:
// line 130 "ext/ragel/base_lexer.rl"
	{te = p;p--;{
            callback(id_on_cdata_body, data, encoding, ts, te);

            if ( lines > 0 )
            {
                advance_line(lines);

                lines = 0;
            }
        }}
	break;
	case 10:
// line 130 "ext/ragel/base_lexer.rl"
	{{p = ((te))-1;}{
            callback(id_on_cdata_body, data, encoding, ts, te);

            if ( lines > 0 )
            {
                advance_line(lines);

                lines = 0;
            }
        }}
	break;
	case 11:
// line 184 "ext/ragel/base_lexer.rl"
	{te = p+1;{
            callback_simple(id_on_proc_ins_end);

            ( this.cs) = 34;
        }}
	break;
	case 12:
// line 173 "ext/ragel/base_lexer.rl"
	{te = p;p--;{
            callback(id_on_proc_ins_body, data, encoding, ts, te);

            if ( lines > 0 )
            {
                advance_line(lines);

                lines = 0;
            }
        }}
	break;
	case 13:
// line 226 "ext/ragel/base_lexer.rl"
	{te = p+1;{
            callback_simple(id_on_string_squote);

            {( this.cs) = ( this.stack)[--( this.top)];_goto_targ = 2; if (true) continue _goto;}
        }}
	break;
	case 14:
// line 200 "ext/ragel/base_lexer.rl"
	{te = p;p--;{
        callback(id_on_string_body, data, encoding, ts, te);

        if ( lines > 0 )
        {
            advance_line(lines);

            lines = 0;
        }
    }}
	break;
	case 15:
// line 236 "ext/ragel/base_lexer.rl"
	{te = p+1;{
            callback_simple(id_on_string_dquote);

            {( this.cs) = ( this.stack)[--( this.top)];_goto_targ = 2; if (true) continue _goto;}
        }}
	break;
	case 16:
// line 200 "ext/ragel/base_lexer.rl"
	{te = p;p--;{
        callback(id_on_string_body, data, encoding, ts, te);

        if ( lines > 0 )
        {
            advance_line(lines);

            lines = 0;
        }
    }}
	break;
	case 17:
// line 281 "ext/ragel/base_lexer.rl"
	{te = p+1;{ ( this.cs) = 55; }}
	break;
	case 18:
// line 270 "ext/ragel/base_lexer.rl"
	{te = p;p--;{
            callback(id_on_doctype_inline, data, encoding, ts, te);

            if ( lines > 0 )
            {
                advance_line(lines);

                lines = 0;
            }
        }}
	break;
	case 19:
// line 287 "ext/ragel/base_lexer.rl"
	{( this.act) = 13;}
	break;
	case 20:
// line 298 "ext/ragel/base_lexer.rl"
	{( this.act) = 17;}
	break;
	case 21:
// line 292 "ext/ragel/base_lexer.rl"
	{te = p+1;{ ( this.cs) = 53; }}
	break;
	case 22:
// line 211 "ext/ragel/base_lexer.rl"
	{te = p+1;{
        callback_simple(id_on_string_squote);

        {( this.stack)[( this.top)++] = ( this.cs); ( this.cs) = 49; _goto_targ = 2; if (true) continue _goto;}
    }}
	break;
	case 23:
// line 217 "ext/ragel/base_lexer.rl"
	{te = p+1;{
        callback_simple(id_on_string_dquote);

        {( this.stack)[( this.top)++] = ( this.cs); ( this.cs) = 51; _goto_targ = 2; if (true) continue _goto;}
    }}
	break;
	case 24:
// line 302 "ext/ragel/base_lexer.rl"
	{te = p+1;{
            callback_simple(id_on_doctype_end);
            ( this.cs) = 34;
        }}
	break;
	case 25:
// line 60 "ext/ragel/base_lexer.rl"
	{te = p+1;{
        advance_line(1);
    }}
	break;
	case 26:
// line 309 "ext/ragel/base_lexer.rl"
	{te = p+1;}
	break;
	case 27:
// line 298 "ext/ragel/base_lexer.rl"
	{te = p;p--;{
            callback(id_on_doctype_name, data, encoding, ts, te);
        }}
	break;
	case 28:
// line 60 "ext/ragel/base_lexer.rl"
	{te = p;p--;{
        advance_line(1);
    }}
	break;
	case 29:
// line 1 "NONE"
	{	switch( ( this.act) ) {
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
	break;
	case 30:
// line 326 "ext/ragel/base_lexer.rl"
	{te = p+1;{
            if ( lines > 0 )
            {
                advance_line(lines);

                lines = 0;
            }

            callback_simple(id_on_xml_decl_end);

            ( this.cs) = 34;
        }}
	break;
	case 31:
// line 211 "ext/ragel/base_lexer.rl"
	{te = p+1;{
        callback_simple(id_on_string_squote);

        {( this.stack)[( this.top)++] = ( this.cs); ( this.cs) = 49; _goto_targ = 2; if (true) continue _goto;}
    }}
	break;
	case 32:
// line 217 "ext/ragel/base_lexer.rl"
	{te = p+1;{
        callback_simple(id_on_string_dquote);

        {( this.stack)[( this.top)++] = ( this.cs); ( this.cs) = 51; _goto_targ = 2; if (true) continue _goto;}
    }}
	break;
	case 33:
// line 354 "ext/ragel/base_lexer.rl"
	{te = p+1;}
	break;
	case 34:
// line 340 "ext/ragel/base_lexer.rl"
	{te = p;p--;{
            if ( lines > 0 )
            {
                advance_line(lines);

                lines = 0;
            }

            callback(id_on_attribute, data, encoding, ts, te);
        }}
	break;
	case 35:
// line 354 "ext/ragel/base_lexer.rl"
	{te = p;p--;}
	break;
	case 36:
// line 387 "ext/ragel/base_lexer.rl"
	{te = p+1;{
            callback(id_on_element_ns, data, encoding, ts, te - 1);
        }}
	break;
	case 37:
// line 391 "ext/ragel/base_lexer.rl"
	{te = p;p--;{
            callback(id_on_element_name, data, encoding, ts, te);
            ( this.cs) = 76;
        }}
	break;
	case 38:
// line 406 "ext/ragel/base_lexer.rl"
	{te = p+1;{
            p--;
            ( this.cs) = 75;
        }}
	break;
	case 39:
// line 64 "ext/ragel/base_lexer.rl"
	{te = p+1;{
        p--;
        {( this.cs) = ( this.stack)[--( this.top)];_goto_targ = 2; if (true) continue _goto;}
    }}
	break;
	case 40:
// line 413 "ext/ragel/base_lexer.rl"
	{te = p;p--;{
            callback_simple(id_on_string_squote);

            callback(id_on_string_body, data, encoding, ts, te);

            callback_simple(id_on_string_squote);
        }}
	break;
	case 41:
// line 429 "ext/ragel/base_lexer.rl"
	{te = p+1;{
            callback_simple(id_on_string_squote);

            ( this.cs) = 49;
        }}
	break;
	case 42:
// line 435 "ext/ragel/base_lexer.rl"
	{te = p+1;{
            callback_simple(id_on_string_dquote);

            ( this.cs) = 51;
        }}
	break;
	case 43:
// line 64 "ext/ragel/base_lexer.rl"
	{te = p+1;{
        p--;
        {( this.cs) = ( this.stack)[--( this.top)];_goto_targ = 2; if (true) continue _goto;}
    }}
	break;
	case 44:
// line 60 "ext/ragel/base_lexer.rl"
	{te = p+1;{
        advance_line(1);
    }}
	break;
	case 45:
// line 450 "ext/ragel/base_lexer.rl"
	{te = p+1;{
            callback(id_on_attribute_ns, data, encoding, ts, te - 1);
        }}
	break;
	case 46:
// line 459 "ext/ragel/base_lexer.rl"
	{te = p+1;{
            if ( html_p )
            {
                {( this.stack)[( this.top)++] = ( this.cs); ( this.cs) = 73; _goto_targ = 2; if (true) continue _goto;}
            }
            else
            {
                {( this.stack)[( this.top)++] = ( this.cs); ( this.cs) = 75; _goto_targ = 2; if (true) continue _goto;}
            }
        }}
	break;
	case 47:
// line 471 "ext/ragel/base_lexer.rl"
	{te = p+1;{
            callback_simple(id_on_element_open_end);

            if ( html_script_p() )
            {
                ( this.cs) = 84;
            }
            else if ( html_style_p() )
            {
                ( this.cs) = 88;
            }
            else
            {
                ( this.cs) = 34;
            }
        }}
	break;
	case 48:
// line 489 "ext/ragel/base_lexer.rl"
	{te = p+1;{
            callback_simple(id_on_element_end);
            ( this.cs) = 34;
        }}
	break;
	case 49:
// line 494 "ext/ragel/base_lexer.rl"
	{te = p+1;}
	break;
	case 50:
// line 60 "ext/ragel/base_lexer.rl"
	{te = p;p--;{
        advance_line(1);
    }}
	break;
	case 51:
// line 454 "ext/ragel/base_lexer.rl"
	{te = p;p--;{
            callback(id_on_attribute, data, encoding, ts, te);
        }}
	break;
	case 52:
// line 494 "ext/ragel/base_lexer.rl"
	{te = p;p--;}
	break;
	case 53:
// line 531 "ext/ragel/base_lexer.rl"
	{te = p+1;{
            callback(id_on_text, data, encoding, ts, te);

            if ( lines > 0 )
            {
                advance_line(lines);

                lines = 0;
            }

            ( this.cs) = 34;
        }}
	break;
	case 54:
// line 545 "ext/ragel/base_lexer.rl"
	{te = p+1;{
            callback(id_on_text, data, encoding, ts, mark);

            p    = mark - 1;
            mark = 0;

            if ( lines > 0 )
            {
                advance_line(lines);

                lines = 0;
            }

            ( this.cs) = 34;
        }}
	break;
	case 55:
// line 531 "ext/ragel/base_lexer.rl"
	{te = p;p--;{
            callback(id_on_text, data, encoding, ts, te);

            if ( lines > 0 )
            {
                advance_line(lines);

                lines = 0;
            }

            ( this.cs) = 34;
        }}
	break;
	case 56:
// line 379 "ext/ragel/base_lexer.rl"
	{te = p+1;{
        callback_simple(id_on_element_end);

        ( this.cs) = 34;
    }}
	break;
	case 57:
// line 519 "ext/ragel/base_lexer.rl"
	{te = p;p--;{
        callback(id_on_text, data, encoding, ts, te);

        if ( lines > 0 )
        {
            advance_line(lines);

            lines = 0;
        }
    }}
	break;
	case 58:
// line 519 "ext/ragel/base_lexer.rl"
	{{p = ((te))-1;}{
        callback(id_on_text, data, encoding, ts, te);

        if ( lines > 0 )
        {
            advance_line(lines);

            lines = 0;
        }
    }}
	break;
	case 59:
// line 379 "ext/ragel/base_lexer.rl"
	{te = p+1;{
        callback_simple(id_on_element_end);

        ( this.cs) = 34;
    }}
	break;
	case 60:
// line 519 "ext/ragel/base_lexer.rl"
	{te = p;p--;{
        callback(id_on_text, data, encoding, ts, te);

        if ( lines > 0 )
        {
            advance_line(lines);

            lines = 0;
        }
    }}
	break;
	case 61:
// line 519 "ext/ragel/base_lexer.rl"
	{{p = ((te))-1;}{
        callback(id_on_text, data, encoding, ts, te);

        if ( lines > 0 )
        {
            advance_line(lines);

            lines = 0;
        }
    }}
	break;
	case 62:
// line 319 "ext/ragel/base_lexer.rl"
	{( this.act) = 48;}
	break;
	case 63:
// line 165 "ext/ragel/base_lexer.rl"
	{( this.act) = 51;}
	break;
	case 64:
// line 84 "ext/ragel/base_lexer.rl"
	{te = p+1;{
        callback_simple(id_on_comment_start);

        ( this.cs) = 40;
    }}
	break;
	case 65:
// line 123 "ext/ragel/base_lexer.rl"
	{te = p+1;{
        callback_simple(id_on_cdata_start);

        ( this.cs) = 43;
    }}
	break;
	case 66:
// line 369 "ext/ragel/base_lexer.rl"
	{te = p+1;{
        callback_simple(id_on_element_start);
        p--;
        ( this.cs) = 71;
    }}
	break;
	case 67:
// line 375 "ext/ragel/base_lexer.rl"
	{te = p+1;{
        callback_simple(id_on_element_end);
    }}
	break;
	case 68:
// line 505 "ext/ragel/base_lexer.rl"
	{te = p+1;{
        p--;
        ( this.cs) = 80;
    }}
	break;
	case 69:
// line 255 "ext/ragel/base_lexer.rl"
	{te = p;p--;{
        callback_simple(id_on_doctype_start);

        if ( lines > 0 )
        {
            advance_line(lines);

            lines = 0;
        }

        ( this.cs) = 55;
    }}
	break;
	case 70:
// line 165 "ext/ragel/base_lexer.rl"
	{te = p;p--;{
        callback_simple(id_on_proc_ins_start);
        callback(id_on_proc_ins_name, data, encoding, ts + 2, te);

        ( this.cs) = 46;
    }}
	break;
	case 71:
// line 505 "ext/ragel/base_lexer.rl"
	{te = p;p--;{
        p--;
        ( this.cs) = 80;
    }}
	break;
	case 72:
// line 505 "ext/ragel/base_lexer.rl"
	{{p = ((te))-1;}{
        p--;
        ( this.cs) = 80;
    }}
	break;
	case 73:
// line 1 "NONE"
	{	switch( ( this.act) ) {
	case 48:
	{{p = ((te))-1;}
        callback_simple(id_on_xml_decl_start);
        ( this.cs) = 68;
    }
	break;
	case 51:
	{{p = ((te))-1;}
        callback_simple(id_on_proc_ins_start);
        callback(id_on_proc_ins_name, data, encoding, ts + 2, te);

        ( this.cs) = 46;
    }
	break;
	}
	}
	break;
// line 1167 "ext/java/org/liboga/xml/Lexer.java"
			}
		}
	}

case 2:
	_acts = _java_lexer_to_state_actions[( this.cs)];
	_nacts = (int) _java_lexer_actions[_acts++];
	while ( _nacts-- > 0 ) {
		switch ( _java_lexer_actions[_acts++] ) {
	case 2:
// line 1 "NONE"
	{ts = -1;}
	break;
// line 1181 "ext/java/org/liboga/xml/Lexer.java"
		}
	}

	if ( ( this.cs) == 0 ) {
		_goto_targ = 5;
		continue _goto;
	}
	if ( ++p != pe ) {
		_goto_targ = 1;
		continue _goto;
	}
case 4:
	if ( p == eof )
	{
	if ( _java_lexer_eof_trans[( this.cs)] > 0 ) {
		_trans = _java_lexer_eof_trans[( this.cs)] - 1;
		_goto_targ = 3;
		continue _goto;
	}
	}

case 5:
	}
	break; }
	}

// line 137 "ext/java/org/liboga/xml/Lexer.rl"

        this.lines = lines;

        return context.nil;
    }

    /**
     * Resets the internal state of the lexer.
     */
    @JRubyMethod
    public IRubyObject reset_native(ThreadContext context)
    {
        this.act   = 0;
        this.top   = 0;
        this.stack = new int[4];
        this.cs    = java_lexer_start;

        return context.nil;
    }

    /**
     * Calls back in to Ruby land passing the current token value along.
     *
     * This method calls back in to Ruby land based on the method name
     * specified in `name`. The Ruby callback should take one argument. This
     * argument will be a String containing the value of the current token.
     */
    public void callback(String name, byte[] data, Encoding enc, int ts, int te)
    {
        ByteList bytelist = new ByteList(data, ts, te - ts, enc, true);

        RubyString value = this.runtime.newString(bytelist);

        ThreadContext context = this.runtime.getCurrentContext();

        this.callMethod(context, name, value);
    }

    /**
     * Calls back in to Ruby land without passing any arguments.
     */
    public void callback_simple(String name)
    {
        ThreadContext context = this.runtime.getCurrentContext();

        this.callMethod(context, name);
    }

    /**
     * Advances the line number by `amount` lines.
     */
    public void advance_line(int amount)
    {
        ThreadContext context = this.runtime.getCurrentContext();
        RubyFixnum lines      = this.runtime.newFixnum(amount);

        this.callMethod(context, "advance_line", lines);
    }

    /**
     * @see Oga::XML::Lexer#html_script?
     */
    public Boolean html_script_p()
    {
        ThreadContext context = this.runtime.getCurrentContext();

        return this.callMethod(context, "html_script?").isTrue();
    }

    /**
     * @see Oga::XML::Lexer#html_style?
     */
    public Boolean html_style_p()
    {
        ThreadContext context = this.runtime.getCurrentContext();

        return this.callMethod(context, "html_style?").isTrue();
    }
}


// line 224 "ext/java/org/liboga/xml/Lexer.rl"

