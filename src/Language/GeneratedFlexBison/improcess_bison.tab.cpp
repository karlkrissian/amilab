
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008 Free Software
   Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

// Take the name prefix into account.
#define yylex   yyiplex

/* First part of user declarations.  */

/* Line 311 of lalr1.cc  */
#line 11 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"

 /*** C/C++ Declarations ***/
  //#include <stdlib.h>
  //#include <stdio.h>

// use NOMINMAX to avoid conflicts between windows.h min,max and std::min std::max ...
#define NOMINMAX

#include "driver.h"
#include "CoutwxString.h"
#include "MainFrame.h"
#include <locale.h>
#include "fonctions.h"
#include "func_isoline.hpp"

#include "ami_function.h"
#include "ami_class.h"
#include "ami_object.h"
#include "IdentifierInfo.h"

#include "localstats.h"
//#include "dist_squared.hpp"
#include "improcess_bison.tab.hpp"
#include "wrapAMIFluid.h"
#include "wrapVTK.h"
#include "wrapITK.h"
//#include "wrap_MainFrame.h"
#include "wrap_imagedraw.h"
#include "itkCannyEdgeDetector.h"
#include "wrapWII.h"
#include "wrapFilters.h"
#include "wrapSystem.h"
#include <cstdlib>

//#include "myscan.h"
#include "ImageDraw.hpp"
#include "Func_ReadCTALine.h"
#include "LineRecons.h"
//#include "PruneLines.h"

#include "wrapfunction_class.h"
#include "wrap_ImageExtent.h"
#include "wrap_SurfacePoly.h"


#ifndef __FLEX_LEXER_H
#define yyFlexLexer yyipFlexLexer
#include "FlexLexer.h"
#undef yyFlexLexer
#endif


#include "Viewer3D.hpp"

//#include "Erreurs.Main.hpp"
 // #include "Graphique.hpp"
#include "Viewer3D.hpp"
#include "DessinImage.hpp"
#include "CompareImage.hpp"
#include "bruit.hpp"
#include "CalculAireSection.hpp"
#include "reponse_cercle.hpp"
#include "func_shortestpath.h"
#include "Wrap_AnisoGS.h"
#include "LevelSetsCURVES.h"
#include "vtkwrap.h"

#include "gnuplot.hpp"

#include "xmtext.hpp"
#include "StringUtils.hpp"
//#include "histo.hpp"

#ifndef WIN32
#include <unistd.h>
#endif

#include <iostream>

#include "VarContexts.hpp"
#include "VarArray.h"
//#include "Duree.hpp"

#include "DefineClass.hpp"

#include "Variable.hpp"

//typedef std::vector<BasicVariable::ptr> VarVector;

#include "wrap_varvector.h"

/*
#include <boost/shared_ptr.hpp>
//--- string formatting using boost
#include <iostream>
#include <iomanip>
#include <cassert>
#include "boost/format.hpp"
namespace MyNS_ForOutput {
  using std::cout; using std::cerr;
  using std::string;
  using std::endl; using std::flush;

  using boost::format;
  using boost::io::group;
}
using namespace MyNS_ForOutput;
*/



//-------

#include "wx/evtloop.h"
#include "driver.h"

extern VarContexts       Vars;

//Duree            IP_time;

extern MainFrame*   GB_main_wxFrame;
extern wxApp*       GB_wxApp;
extern int          GB_argc;

extern int       GB_num_arg_parsed;
extern wxString  GB_scripts_dir;
extern wxString  GB_help_dir;


namespace AMIFluid {
extern char* FLUID_NAVIGATION_FILE;
}


DessinImage* CreateIDraw(  const std::string& title, InrImage::ptr image);
// Creation of a DessinImage pointer
// this function is distinct if compiling with all amilab

extern yyip::Driver GB_driver;

extern unsigned char        GB_debug;
extern unsigned char        GB_verbose;
extern unsigned char        verbose;
extern unsigned char        GB_nofile;

extern char program[80];

extern unsigned char DELETE_IDRAW;

//-------------------------------------------------------
class wxWaitTimer : public wxTimer
//    -----------
{
  public:
    bool finished;

    wxWaitTimer() : finished(false) {}
    //Called each time the timer's timeout expires
    void Notify()     { finished = true; }
};



//------------------------------------------------------
class wxScheduleTimer : public wxTimer
//    ---------------
{
  DEFINE_CLASS(wxScheduleTimer)
  public:
    wxScheduleTimer( Variable<AMIFunction>::ptr callback)
    {
      var = Variable<AMIFunction>::ptr(callback);
    }

    ~wxScheduleTimer()
    { 
      //cout << "~wxScheduleTimer()" << endl; 
    }

    //Called each time the timer's timeout expires
    void Notify();

  private:
    // variable of type type_ami_function
    Variable<AMIFunction>::ptr var;
};

// create a array of shared pointers
// to delete the wxScheduleTimer when necessary
static std::list<wxScheduleTimer::ptr> schedule_timers;

InrImage* ReadImage( const char* name);


//static void ( void* cd, long unsigned int *) {
//  CB_ParamWin(cd);
//}

/*
static void CB_Button(  void* cd) {
  CB_ParamWin(cd);
}
*/

extern void CB_delete_variable( void* var);

extern void CB_ParamWin( void* cd );

//------------------------------------------------------
void CB_update_imagelist( void* imagelist_gui);


#define GET_VARSTACK_VALUE(type,newvar) \
  boost::shared_ptr<type> newvar( \
    driver.var_stack.GetLastVar<type>()->Pointer());


/*! \def GET_VARSTACK_OBJECT
    \brief Gets the smart pointer to the wrapped object  (of type WrapClass_type) included in an AMIObject variable, taken from the stack of variables.
*/
#define GET_VARSTACK_OBJECT(type, obj) \
  boost::shared_ptr<type > obj; \
  {\
    Variable<AMIObject>::ptr objvar( \
      driver.var_stack.GetLastVar<AMIObject>()); \
    if (!objvar.get()) {  \
      driver.yyiperror(" Expecting an AMIObject variable."); \
      YYABORT; \
    } \
    WrapClassBase::ptr wrap_base( objvar->Pointer()->GetWrappedObject()); \
    WrapClass_##type::ptr wobj( boost::dynamic_pointer_cast<WrapClass_##type>(wrap_base));\
    if (!wobj.get()) {  \
      driver.yyiperror((boost::format(" Expecting an AMIObject variable of type %1%.")%(#type)).str().c_str()); \
      YYABORT; \
    } \
    obj = wobj->_obj; \
  }


/*! \def GET_VARSTACK_VAR_OBJECT
    \brief Gets the smart pointer to the wrapped object  (of type WrapClass_type) included in an AMIObject variable, taken from the stack of variables, and also the smart pointer to the variable.
*/
#define GET_VARSTACK_VAR_OBJECT(type, varname, obj) \
  Variable<AMIObject>::ptr varname( \
    driver.var_stack.GetLastVar<AMIObject>()); \
  if (!varname.get()) {  \
    driver.yyiperror(" Expecting an AMIObject variable."); \
    YYABORT; \
  } \
  WrapClass_##type::ptr wobj;\
  {\
    WrapClassBase::ptr wrap_base( varname->Pointer()->GetWrappedObject()); \
    wobj =  boost::dynamic_pointer_cast \
                <WrapClass_##type>(wrap_base);\
    if (!wobj.get()) {  \
      driver.yyiperror((boost::format(" Expecting an AMIObject variable of type %1%.")%(#type)).str().c_str()); \
      YYABORT; \
    } \
  } \
  boost::shared_ptr<type> obj(wobj->_obj);

/*! \def GET_VARSTACK_OBJECT2
    \brief Gets the smart pointer to the wrapped object  (of type WrapClass_type) included in an AMIObject variable, taken from the stack of variables. 
    Version where the wrapped typename is different from the type.
*/
#define GET_VARSTACK_OBJECT2(wtype, type, obj) \
  Variable<AMIObject>::ptr objvar( \
    driver.var_stack.GetLastVar<AMIObject>()); \
  if (!objvar.get()) {  \
    driver.yyiperror(" Expecting an AMIObject variable."); \
    YYABORT; \
  } \
  WrapClass_##wtype::ptr wobj; \
  { \
    WrapClassBase::ptr wrap_base( objvar->Pointer()->GetWrappedObject()); \
    wobj =  boost::dynamic_pointer_cast<WrapClass_##wtype>(wrap_base);\
    if (!wobj.get()) {  \
      driver.yyiperror((boost::format(" Expecting an AMIObject variable of type %1%.")%(#type)).str().c_str()); \
      YYABORT; \
    } \
  } \
  boost::shared_ptr<type > obj(wobj->_obj);

#define GET_VARSTACK_VAR_VAL(type,newvar, newval) \
  Variable<type>::ptr newvar(driver.var_stack.GetLastVar<type>()); \
  boost::shared_ptr<type> newval(newvar->Pointer());

#define ADD_VARSTACK_FLOAT(newval) \
    Variable<float>::ptr new_var(new Variable<float>(float_ptr(new float(newval)))); \
    driver.var_stack.AddVar(new_var);

/*! \def CHECK_VAR
    \brief Checks if the smart pointer really points to a variable, if not abort the current parsing
*/
#define CHECK_VAR(var) \
  if (!var.get()) {  \
    driver.yyiperror(" Empty variable in expression "); \
    YYABORT; }

/*! \def GET_CHECK_VARSTACK
    \brief Gets the last variable from the stack and 
        checks if the smart pointer really points to a variable, if not abort the current parsing
*/
#define GET_CHECK_VARSTACK(varname) \
  BasicVariable::ptr varname(driver.var_stack.GetLastBasicVar()); \
  if (!varname.get()) {  \
    driver.yyiperror(" Empty variable in expression "); \
    YYABORT; }

/**
  newval is a smart pointer to the new value to add
**/
#define ADD_VARSTACK_PTR(type,newval) \
    Variable<type>::ptr new_var(new Variable<type>(newval)); \
    driver.var_stack.AddVar(new_var);

/**
  newval is a pointer to the new value to add
**/
#define ADD_VARSTACK(type,newval) { \
    boost::shared_ptr<type> newval_ptr(newval); \
    Variable<type>::ptr new_var(new Variable<type>(newval_ptr)); \
    driver.var_stack.AddVar(new_var); }

#define UNARYOP_EXPR(operator,val,res)           \
  res=operator(val);






/* Line 311 of lalr1.cc  */
#line 376 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"


#include "improcess_bison.tab.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 820 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"


#include "driver.h"
#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex



/* Line 317 of lalr1.cc  */
#line 399 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


/* Line 380 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

namespace yyip {

/* Line 380 of lalr1.cc  */
#line 468 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
#if YYERROR_VERBOSE

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              /* Fall through.  */
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

#endif

  /// Build a parser object.
  Parser::Parser (class Driver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {
  }

  Parser::~Parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  Parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  Parser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  Parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
        case 56: /* "ASTRING" */

/* Line 480 of lalr1.cc  */
#line 813 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 575 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 59: /* "IDENTIFIER" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 584 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 437: /* "exprstringlist" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->string_list); };

/* Line 480 of lalr1.cc  */
#line 593 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 440: /* "primary_expr_string" */

/* Line 480 of lalr1.cc  */
#line 813 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 602 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 441: /* "instr_block" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ablock); };

/* Line 480 of lalr1.cc  */
#line 611 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 447: /* "expr_string" */

/* Line 480 of lalr1.cc  */
#line 813 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 620 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 473: /* "identifier" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 629 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;

	default:
	  break;
      }
  }

  void
  Parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  int
  Parser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    semantic_type yylval;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[2];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* User initialization code.  */
    
/* Line 553 of lalr1.cc  */
#line 364 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}

/* Line 553 of lalr1.cc  */
#line 715 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"

    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yyn == yypact_ninf_)
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval, &yylloc);
      }


    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yyn == 0 || yyn == yytable_ninf_)
	goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 22:

/* Line 678 of lalr1.cc  */
#line 859 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      int  previous_lineno=driver.yyiplineno;
      AmiInstructionBlock::ptr block((yysemantic_stack_[(8) - (7)].ablock));
      IdentifierInfo::ptr ident((yysemantic_stack_[(8) - (2)].ident));

      int_ptr varint(new int);
      Vars.AddVar<int>(ident,varint);

      for(*varint = (int) (yysemantic_stack_[(8) - (4)].adouble); *varint <= (int) (yysemantic_stack_[(8) - (6)].adouble); (*varint)++)
        {
          driver.yyiplineno = block->GetStartingLine();
          driver.parse_block(block);
        }
      Vars.deleteVar(ident->GetName().c_str());
      driver.yyiplineno=previous_lineno;
    }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 878 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      int  previous_lineno=driver.yyiplineno;
      AmiInstructionBlock::ptr block((yysemantic_stack_[(10) - (9)].ablock));
      IdentifierInfo::ptr ident((yysemantic_stack_[(10) - (2)].ident));

      float_ptr var(new float);
      Vars.AddVar<float>(ident,var);

      for(*var = (yysemantic_stack_[(10) - (4)].adouble); *var <= (yysemantic_stack_[(10) - (6)].adouble); (*var)+=(yysemantic_stack_[(10) - (8)].adouble))
      {
        driver.yyiplineno = block->GetStartingLine();
        //driver.yyiplineno=previous_lineno;
        driver.parse_block(block);
      }
      Vars.deleteVar(ident->GetName().c_str());
      driver.yyiplineno=previous_lineno;
    }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 898 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
          Iteration through a list of strings.
    **/

      std::list<std::string>* sl = (yysemantic_stack_[(6) - (4)].string_list);

      int  previous_lineno=driver.yyiplineno;
      AmiInstructionBlock::ptr block((yysemantic_stack_[(6) - (5)].ablock));
      IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (2)].ident));

      // create the variable
      string_ptr tmp(new string());
      Variable<string>::ptr var = Vars.AddVar<string>(ident,tmp);
      //cout << " *** Create temporary variable " << ident->GetName() << endl;

      std::list<std::string>::iterator sl_it;
      for (sl_it=sl->begin(); sl_it!=sl->end(); sl_it++) {

        // assign new value to the variable
        //string_ptr newval( new std::string(*sl_it));
        (*var->Pointer()) = (*sl_it);

        driver.yyiplineno = block->GetStartingLine();
        //driver.yyiplineno=previous_lineno;
        driver.parse_block(block);

      }
      // should not delete based on the name !!!
      bool res = Vars.deleteVar(ident->GetName().c_str());
      //cout << " *** Delete temporary variable " << ident->GetName() << endl;
      if (!res) {
        cout << "**********" << endl;
        cout << "**** Could not delete variable in loop"  << ident->GetName() << endl;
        cout << "**********" << endl;
      }
      driver.yyiplineno=previous_lineno;

      // forced to delete the pointer to the list here
      delete (yysemantic_stack_[(6) - (4)].string_list);

    }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 943 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Description:
        Repeats a block of instructions, and stop when an error is generated.
        Use the command 'break' to leave the loop
      See Also:
        break
     **/
        int  previous_lineno=driver.yyiplineno;
        AmiInstructionBlock::ptr block((yysemantic_stack_[(2) - (2)].ablock));
        int res;
    
        do {
  
            //driver.yyiplineno=previous_lineno;
            driver.yyiplineno = block->GetStartingLine();
            res=driver.parse_block(block);
  
        } while (res);
        driver.yyiplineno = previous_lineno;
      }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 966 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
        Description:
          Repeats the block while the variable value is higher than 0.5
      **/
        int  previous_lineno=driver.yyiplineno;
        AmiInstructionBlock::ptr block((yysemantic_stack_[(3) - (3)].ablock));
        BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
  
        float res;
        if (var->Type() == type_float) 
          res = *(boost::dynamic_pointer_cast<Variable<float> >(var))->Pointer();
        else
        if (var->Type() == type_int) 
          res = *(boost::dynamic_pointer_cast<Variable<int> >  (var))->Pointer();
        else
        if (var->Type() == type_uchar) 
          res = *(boost::dynamic_pointer_cast<Variable<unsigned char> >  (var))->Pointer();
        else {
          res = 0;
          driver.yyiperror(" while needs a numerical variable as condition \n");
        }
  
        while (res) {
  
          //driver.yyiplineno=previous_lineno;
          driver.yyiplineno = block->GetStartingLine();
          res=driver.parse_block(block);

          if (var->Type() == type_float) 
            res = *(boost::dynamic_pointer_cast<Variable<float> >(var))->Pointer();
          else
          if (var->Type() == type_int) 
            res = *(boost::dynamic_pointer_cast<Variable<int> >  (var))->Pointer();
          else
          if (var->Type() == type_uchar) 
            res = *(boost::dynamic_pointer_cast<Variable<unsigned char> >  (var))->Pointer();
          else {
            res = 0;
            driver.yyiperror(" while needs a numerical variable as condition \n");
          }
        } 
        driver.yyiplineno = previous_lineno;
      }
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 1015 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      int  previous_lineno;
      AmiInstructionBlock::ptr block((yysemantic_stack_[(4) - (3)].ablock));

      // Pb with line numbers
      previous_lineno=driver.yyiplineno;

        if ((yysemantic_stack_[(4) - (2)].adouble)>0.5)
        {
          //driver.yyiplineno=previous_lineno;
          if (!driver.parse_block(block)) YYABORT;
          driver.yyiplineno = previous_lineno;
        }
    }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 1030 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
       int  previous_lineno = driver.yyiplineno;

      AmiInstructionBlock::ptr block_if(  (yysemantic_stack_[(6) - (3)].ablock));
      AmiInstructionBlock::ptr block_else((yysemantic_stack_[(6) - (5)].ablock));

      // Pb with line numbers
      previous_lineno=driver.yyiplineno;

      bool res;
      if ((yysemantic_stack_[(6) - (2)].adouble)>0.5)
        res = driver.parse_block(block_if);
      else
        res = driver.parse_block(block_else);
      if (!res) YYABORT;
      driver.yyiplineno = previous_lineno;

    }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 1052 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GB_driver.procedure_declaration = true;
    }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 1057 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      AmiInstructionBlock::ptr body((yysemantic_stack_[(8) - (7)].ablock));
      IdentifierInfo::ptr ident((yysemantic_stack_[(8) - (2)].ident));

      AMIFunction::ptr amifunc(new AMIFunction);

      amifunc->SetName(ident->GetName().c_str());
      amifunc->SetFileName(driver.current_file);
      amifunc->SetParamList((yysemantic_stack_[(8) - (5)].paramlistdecl));
      amifunc->SetBody(     body);

      if (GB_debug)
        cout  << ident->GetName()
              << " body = "
              << body->GetBody()  << endl;

      BasicVariable::ptr newvar = Vars.AddVar<AMIFunction>( ident, amifunc);
      if (newvar.get())
        amifunc->SetContext(newvar->GetContext());

      // desactivate the flag procedure_declaration
      // which allows not to accept variables as identifiers
      GB_driver.procedure_declaration = false;
    }
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 1083 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      // allow overriding current functions
      GB_driver.procedure_declaration = true;
    }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 1089 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      AmiInstructionBlock::ptr body((yysemantic_stack_[(8) - (7)].ablock));

      GET_VARSTACK_VAR_VAL(AMIFunction, var, func);

      // delete previous variable
      std::string varname = var->Name();
      int context = Vars.GetContext(boost::static_pointer_cast<BasicVariable>(var));
      Vars.deleteVar(var);

      FILE_MESSAGE(boost::format("Redefining procedure %1%") % varname); 

      AMIFunction::ptr amifunc( new AMIFunction);

      amifunc->SetName(varname.c_str());
      amifunc->SetFileName(driver.current_file);
      amifunc->SetParamList((yysemantic_stack_[(8) - (5)].paramlistdecl));
      amifunc->SetBody(     body);
      FILE_MESSAGE(boost::format("%1%: body = %2%")
                    % varname  % body->GetBody());

      // add the variable in the same context ...
      BasicVariable::ptr newvar =
        Vars.AddVar<AMIFunction>(
                      varname,
                      amifunc,
                      context);
      if (newvar.get())
        amifunc->SetContext(newvar->GetContext());

      // desactivate the flag procedure_declaration
      // which allows not to accept variables as identifiers
      GB_driver.procedure_declaration = false;
    }
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 1128 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      AmiInstructionBlock::ptr body((yysemantic_stack_[(4) - (3)].ablock));
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (2)].ident));

      AMIClass::ptr amiclass( new AMIClass);

      amiclass->SetName(ident->GetName());
      amiclass->SetFileName(driver.current_file);
      amiclass->SetBody(     body);
      if (GB_debug) printf("%s body = %s\n", ident->GetName().c_str(),body->GetBody().c_str());

      Vars.AddVar<AMIClass>(ident, amiclass);

    }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 1145 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<AMIClass>::ptr var(driver.var_stack.GetLastVar<AMIClass>());
      AMIClass::ptr parent = var->Pointer();

      AmiInstructionBlock::ptr body((yysemantic_stack_[(7) - (6)].ablock));
      IdentifierInfo::ptr ident((yysemantic_stack_[(7) - (2)].ident));

      AMIClass::ptr amiclass( new AMIClass);

      amiclass->SetName(ident->GetName());
      amiclass->SetFileName(driver.current_file);
      amiclass->Inherit(parent);
      amiclass->SetBody(     body);
      if (GB_debug) printf("%s body = %s\n", ident->GetName().c_str(),body->GetBody().c_str());

      Vars.AddVar<AMIClass>(ident, amiclass);

    }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 1166 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<AMIClass>::ptr var(driver.var_stack.GetLastVar<AMIClass>());
      AMIClass::ptr ac = var->Pointer();
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));

      //AMIObject::ptr amiobject;
      //amiobject = AMIObject::ptr(new AMIObject);
      AMIObject::ptr amiobject( new AMIObject);

      amiobject->SetName(ident->GetName());
      amiobject->SetClass(ac);

      // execute the code of the class with the variables of the object
      driver.yyip_instanciate_object(ac,amiobject);

      Vars.AddVar<AMIObject>(ident, amiobject);

    }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 1187 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
       //driver.res_print($2);
       driver.parse_script((yysemantic_stack_[(3) - (2)].astring));
       delete [] (yysemantic_stack_[(3) - (2)].astring);
     }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 1194 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          int res;
          string name;
          string inc_cmd; // increment the command line string

          //cout << "current wd = "  <<  wxGetCwd() << endl;
          res=AskScript(name);
          if (!res) {
            driver.yyiperror(" Need script \n");
            YYABORT;
          }
          //cout << "current wd = "  <<  wxGetCwd() << endl;

        driver.res_print(name.c_str());
        driver.res_print("\n");
        driver.parse_file(name.c_str());

        // convert path delimiters to avoid pbs with \ character
        wxFileName filename(GetwxStr(name.c_str()),wxPATH_NATIVE);
        filename.Normalize(wxPATH_NORM_ALL,wxEmptyString,wxPATH_UNIX);

        wxString newname(   filename.GetVolume()+filename.GetVolumeSeparator()+
                            filename.GetPath(wxPATH_GET_VOLUME,wxPATH_UNIX)+
                            filename.GetPathSeparator(wxPATH_UNIX)+
                            filename.GetFullName());

        driver.res_print( newname.mb_str());
        driver.res_print("\n");
        inc_cmd = str(format(" \"%1%\" // from browser ") % newname.mb_str());
        if (driver.InConsole())
          GB_main_wxFrame->GetConsole()
                          ->IncCommand(wxString::FromAscii(inc_cmd.c_str()));
      }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 1229 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> input((yysemantic_stack_[(2) - (2)].astring));
      string inputstring( input.get());
      driver.parse_string( inputstring,
                          "'eval string' command");
    }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 1239 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          /**
            Description:
              Empty instruction.
          **/
          BasicVariable::ptr       var(driver.var_stack.GetLastBasicVar());
          if (var.get()) {
            switch (var->Type()) {
              // TODO: ad hoc fix to improve here, result should be a usable variable ??
              /// C++ wrapped member
              case type_class_member: {
                DYNAMIC_CAST_VARIABLE(WrapClassMember,var,m);
                m->Pointer()->CallMember(NULL);
               }
              break;
              /// language function without parameters.
              case type_ami_function: {
                DYNAMIC_CAST_VARIABLE(AMIFunction,var,vf);
                AMIFunction::ptr f(vf->Pointer());
                driver.yyip_call_function(f);
               }
              break;
              default:;
                // TODO: only do it from the command line ???
                //cout << "display var info" << endl;
                if (driver.InConsole())
                  var->display();
            }
          }

        }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 1272 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          /**
            Description:
              Empty instruction.
          **/
          BasicVariable::ptr       var(driver.var_stack.GetLastBasicVar());
          if (var.get()) {
            switch (var->Type()) {
              // TODO: ad hoc fix to improve here, result should be a usable variable ??
              /// C++ wrapped member
              case type_class_member: {
                DYNAMIC_CAST_VARIABLE(WrapClassMember,var,m);
                m->Pointer()->CallMember(NULL);
               }
              break;
              /// language function without parameters.
              case type_ami_function: {
                DYNAMIC_CAST_VARIABLE(AMIFunction,var,vf);
                AMIFunction::ptr f(vf->Pointer());
                driver.yyip_call_function(f);
               }
              break;
              default:;
                // TODO: only do it from the command line ???
                //cout << "display var info" << endl;
                if (driver.InConsole())
                  var->display();
            }
          }

        }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1304 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
         /**
          Description:
            Sets the number of command line arguments to 1 (name of the program)
          **/
          GB_argc = 1;
         }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1312 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          /**
            Description:
              Calls YYABORT to leave the current instruction block.
            See Also:
              repeat
          **/
           YYABORT;
         }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1323 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
         /**
         Description:
          Set a global context for variables,
          creates new variables as global and can only
          access global variables

         See also:
          local, global_new
         **/
       Vars.SetGlobalContext();
         }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1337 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
         /**
         Description:
          Set a global context for new variables,
          creates new variables as global,
          but allow access to lobal variables

         See also:
          local, global
         **/
       Vars.SetGlobalNew(1);
         }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1351 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
         /**
         Description:
          Set a local context for new variables,
          creates new variables as local,
          and allow access to local variables

         See also:
          local, global, global_new
         **/
       Vars.SetGlobalNew(0);
         }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1365 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
         /**
         Description:
         Set a local context for variables
         **/
       Vars.SetLastContext();
       Vars.SetGlobalNew(0);
         }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1375 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Description: waits the time given in milliseconds
        **/

        int ms = (int) (yysemantic_stack_[(4) - (3)].adouble);
        wxWaitTimer w;
        w.Start(ms,wxTIMER_ONE_SHOT);
        while (!w.finished) {
          if (GB_wxApp->Pending()) {
            GB_wxApp->Dispatch();
          }
        } // end while
      }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1391 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (3) time in ms
            (5) function to schedule
        **/

        int ms = (int) (yysemantic_stack_[(6) - (3)].adouble);
        GET_VARSTACK_VAR_VAL(AMIFunction,var,val);

        wxScheduleTimer::ptr w = wxScheduleTimer::ptr(new wxScheduleTimer( var ));
        // add to the list of schedule timers
        schedule_timers.push_back(w);
        w->Start(ms,wxTIMER_ONE_SHOT);

      }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1409 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Creates a new variable that is a reference to an existing one.
          Parameters:
            - new variable name;
            - existing variable name.
        **/
          BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
          IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (1)].ident));
          BasicVariable::ptr newvar( var->NewReference());
          Vars.AddVar(ident,newvar);
      }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 1424 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Creates a new variable that is a reference to an existing one.
          Parameters:
            - new variable name;
            - existing variable name.
        **/
          BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
          IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (1)].ident));
          BasicVariable::ptr newvar( var->NewReference());
          Vars.AddVar(ident,newvar);
      }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 1439 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Creates a new variable that is a copy of an existing one.
          Parameters:
            - new variable name;
            - existing variable name.
        **/
        BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
        // check counter of the value, not of the variable ...
        if (var.get() && (var->GetPtrCounter()>0) ) {
          cout << "GetPtrCounter == " <<  var->GetPtrCounter()<< endl;
          cout << "use_count() == " <<  var.use_count() << endl;
          if (var->GetPtrCounter()==1) {
            IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
            BasicVariable::ptr ref = var->NewReference();
            // need to run on reference to avoid renaming the own variable !!!
            Vars.AddVar(ident,ref);
          } else
          {
            BasicVariable::ptr copy = var->NewCopy();
            IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
            Vars.AddVar(ident,copy);
          }
        } else {
          driver.err_print("identifier = variable, no variable value");
          YYABORT;
        }
      }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 1470 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Creates a new variable that is a copy of an existing one, and sets its comments
          Parameters:
            - new variable name;
            - existing variable name.
        **/
        boost::shared_array<char> comments( (yysemantic_stack_[(5) - (5)].astring));
        BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
        if (var->GetPtrCounter()==1) {
          IdentifierInfo::ptr ident((yysemantic_stack_[(5) - (1)].ident));
          var->SetComments(comments.get());
          Vars.AddVar(ident,var);
        } else
        {
          if (var.get()) {
            BasicVariable::ptr copy = var->NewCopy();
            IdentifierInfo::ptr ident((yysemantic_stack_[(5) - (1)].ident));
            copy->SetComments(comments.get());
            Vars.AddVar(ident,copy);
          } else {
            driver.err_print("identifier = variable, no variable value");
          }
        }
      }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 1498 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Creates a new variable that is a copy of an existing one.
          Parameters:
            - new variable name;
            - existing variable name.
        **/

          BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());

          // first process exception cases
          if (var.get()) {
            if (var->Type()==type_class_member) {
                /// C++ wrapped member
                IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
                DYNAMIC_CAST_VARIABLE(WrapClassMember,var,m);
                ParamList::ptr param((ParamList*)NULL);
                BasicVariable::ptr res(m->Pointer()->CallMember(param.get()));
                if (!res.get()) {
                  driver.yyiperror("Class member does not return a variable \n");
                  YYABORT;
                }
                res->Rename(ident->GetName().c_str());
                Vars.AddVar(res,ident->GetCreationContext());
            }
            else
            // general case
            // for now always call new copy here, otherwise a = b would rename b to a, which is bad
/*
            if (var->GetPtrCounter()==1) {
              IdentifierInfo::ptr ident($1);
              Vars.AddVar(ident,var);
            } else
*/
            {
                BasicVariable::ptr copy = var->NewCopy();
                IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
                Vars.AddVar(ident,copy);
            }
          } else {
            driver.err_print("identifier = variable, no variable value");
            YYABORT;
          }
      }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 1571 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
            IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));
            int size = (int) (yysemantic_stack_[(6) - (5)].adouble);
            if (size<1) size = 1;
            VarArray::ptr array(new VarArray());
            array->Init(type_image,size);
            Vars.AddVar<VarArray>(ident,array);
          }
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 1582 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage,imptr);
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
          InrImage::ptr res;

          if (imptr.get()) {
            // check how many references it has, if only one, move pointer, else create new image
            if (imptr.use_count()==1) 
              res = imptr;
            else {
              // Create a copy since the image is already in use
              res = InrImage::ptr(new InrImage( imptr->GetFormat(),
                                                imptr->GetVDim(),
                                                ident->GetName().c_str(),
                                                imptr.get()));
              (*res) = (*imptr);
            }
            // this should be safe to avoid deleting the image, since the variable will copy the shared pointer
            Vars.AddVar<InrImage>(ident,res);
          }
          else
            driver.err_print((boost::format("assignment of NULL image for %1%  \n") %(yysemantic_stack_[(3) - (1)].ident)).str().c_str() );;
        }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 1608 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(VarArray, vararray, array);

          GET_VARSTACK_VALUE(InrImage,imptr);
          int  i = (int) (yysemantic_stack_[(6) - (3)].adouble);
          std::string name;

          if (imptr.get()) {
            BasicVariable::ptr var = array->GetVar(i);
            if (var.get()) {
              Variable<InrImage>::ptr varim(boost::dynamic_pointer_cast<Variable<InrImage> >(var));
              if (varim->Pointer().get())
                  driver.err_print("array element already assigned\n");
            }
            else 
            {
                  name = (boost::format("%s[%d]") % (vararray->Name().c_str()) %i).str();
                  // should be OK
                  array->InitElement<InrImage>( i, imptr, name.c_str());
            }
          }
          else
            driver.err_print("assignment of NULL image\n");
      }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 1647 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GLTransfMatrix::ptr imptr( 
            driver.gltransf_stack.GetLastMatrix());
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));

          if (imptr.get())
            Vars.AddVar<GLTransfMatrix>(ident,imptr);
          else
            driver.err_print("assignment of NULL matrix\n");
        }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 1742 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
        Description: 
          Creates a variable of type int
      **/
        IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));

        int_ptr varint (new int((int)(yysemantic_stack_[(6) - (5)].adouble)));
        Vars.AddVar<int>(ident,varint);
      }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 1754 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
      Parameters:
        - identifier: name of the new variable
        - expr: value of the new variable
        - expr_string: short description of the new variable
        Description: 
          Creates a variable of type int
      **/
        IdentifierInfo::ptr ident((yysemantic_stack_[(8) - (1)].ident));
        boost::shared_array<char> comments( (yysemantic_stack_[(8) - (8)].astring));
  
        int_ptr varint( new int((int)(yysemantic_stack_[(8) - (5)].adouble)));
        BasicVariable::ptr var=Vars.AddVar<int>(ident,varint);
        if (var.get())
          var->SetComments(comments.get());
      }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1773 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
        Description: 
          Creates a variable of type unsigned char (used for boolean type too)
      **/
        IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));
        uchar_ptr varuchar( new unsigned char((unsigned char)(yysemantic_stack_[(6) - (5)].adouble)));
        Vars.AddVar<unsigned char>(ident,varuchar);
      }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1784 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
      Parameters:
        - identifier: name of the new variable
        - expr: value of the new variable
        - expr_string: short description of the new variable
      Description: 
        creates a variable of type unsigned char (used for boolean type too)
      **/
        IdentifierInfo::ptr ident((yysemantic_stack_[(8) - (1)].ident));
        boost::shared_array<char> comments( (yysemantic_stack_[(8) - (8)].astring));

        uchar_ptr varuchar(new unsigned char((unsigned char)(yysemantic_stack_[(8) - (5)].adouble)));
        BasicVariable::ptr var=Vars.AddVar<unsigned char>(ident,varuchar);
        if (var.get())
          var->SetComments(comments.get());
      }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1871 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          IdentifierInfo::ptr ident((yysemantic_stack_[(8) - (1)].ident));
          boost::shared_array<char> filename( (yysemantic_stack_[(8) - (5)].astring));
          boost::shared_array<char> rights( (yysemantic_stack_[(8) - (7)].astring));

          FILE_ptr file(fopen(filename.get(),rights.get()),file_deleter());
          if (file.get()) {
            Vars.AddVar<FILE>(ident,file);
          } else {
            fprintf(stderr,"error opening file '%s' in mode '%s'\n",
                      filename.get(),rights.get());
          /*
          switch (errno) {
          case EEXIST: fprintf(stderr,"EEXIST \n"); break;
          case EISDIR: fprintf(stderr,"EISDIR \n"); break;
          case ETXTBSY:fprintf(stderr,"ETXTBSY \n"); break;
          case EFAULT: fprintf(stderr,"EFAULT \n"); break;
          case EACCES: fprintf(stderr,"EACCES \n"); break;
          case ENAMETOOLONG: fprintf(stderr,"ENAMETOOLONG \n"); break;
          case ENOENT: fprintf(stderr,"ENOENT \n"); break;
          case ENOTDIR:fprintf(stderr,"ENOTDIR \n"); break;
          case EMFILE: fprintf(stderr,"EMFILE \n"); break;
          case ENFILE: fprintf(stderr,"ENFILE \n"); break;
          case ENOMEM: fprintf(stderr,"ENOMEM \n"); break;
          case EROFS:  fprintf(stderr,"EROFS \n"); break;
          case ELOOP:  fprintf(stderr,"ELOOP \n"); break;
          case ENOSPC: fprintf(stderr,"ENOSPC \n"); break;
                  default: fprintf("unknown error \n");
          }
          */
          }
        }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1905 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<FILE>::ptr varfile(driver.var_stack.GetLastVar<FILE>());
          std::string filename(varfile->Name());

          if (Vars.GetVar(filename.c_str()).get())
              Vars.deleteVar(filename.c_str());

          FILE_ptr file(fopen((yysemantic_stack_[(8) - (5)].astring),(yysemantic_stack_[(8) - (7)].astring)),file_deleter());
          if (file.get()) {
              Vars.AddVar<FILE>(filename.c_str(),file);
          } else {
            fprintf(stderr,"error opening file '%s' in mode '%s'\n",
                    (yysemantic_stack_[(8) - (5)].astring),(yysemantic_stack_[(8) - (7)].astring));
          }
        }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1921 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<FILE>::ptr varfile(driver.var_stack.GetLastVar<FILE>());
          FILE_ptr file(varfile->Pointer());
          rewind(file.get());
        }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1927 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GB_debug = 1;
        }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1931 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GB_debug = 0;
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1935 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      driver.SetTraceScanning((yysemantic_stack_[(2) - (2)].adouble)>0.5);
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1939 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
       Description: 
          Activate the debugging of the parser.
       Parameters:
          bool: 1:activate 0: desactivate
       **/
      driver.SetTraceParsing((yysemantic_stack_[(2) - (2)].adouble)>0.5);
    }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1949 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 1;
      verbose = 1;
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1954 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 0;
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1958 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
       Description:
          Activate/Desactivate the display of message dialog in the language driver.
       Parameters:
          bool: 1:activate 0: desactivate
       **/
      driver.SetNoMessageDialog((yysemantic_stack_[(2) - (2)].adouble)>0.5);
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1968 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Description:
        Adds a new link to a script from the menus
      Parameters:
        - string expression: category of the script
        - string expression: menu label
        - string expression: script name
   **/
          boost::shared_array<char> category( (yysemantic_stack_[(8) - (3)].astring));
          boost::shared_array<char> label(    (yysemantic_stack_[(8) - (5)].astring));
          boost::shared_array<char> script(   (yysemantic_stack_[(8) - (7)].astring));
          GB_main_wxFrame->AddMenuScript(category.get(),label.get(),script.get());
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1983 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Parameter:
        Number: percentage of the current process that has been processed.
      Description:
        Sets the Progress bar in the Main window to the given percentage (between 0 and 100).
    **/
          GB_main_wxFrame->SetProgress((int)((yysemantic_stack_[(4) - (3)].adouble)+0.5));
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1993 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Parameter:
        String: input text
      Description:
        Set the given text in the status bar
    **/
        boost::shared_array<char> text( (yysemantic_stack_[(4) - (3)].astring));
        GB_main_wxFrame->SetStatusText( text.get() );
    }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 2003 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GB_main_wxFrame->Close(true);
        }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 2007 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          std::string titre;
          GET_VARSTACK_VAR_VAL(InrImage, imagevar, im);
          Variable<DessinImage>::ptr var;
          int var_context = Vars.GetContext(imagevar);

          Variables::ptr previous_ocontext = Vars.GetObjectContext();
          if (var_context==OBJECT_CONTEXT_NUMBER) {
            // set new object context
            Vars.SetObjectContext(imagevar->GetContext());
          }

          if ((var_context>=0)||
              (var_context==OBJECT_CONTEXT_NUMBER)) {
            titre = (boost::format("%s_draw") % imagevar->Name().c_str()).str();
            FILE_MESSAGE(boost::format("SHOW var_image  title %s") % titre);
            //if (Vars.GetCurrentContext()->GetVar(titre,&var)) {
            var = boost::dynamic_pointer_cast<Variable<DessinImage> >(Vars.GetVar(titre.c_str(),var_context));
            if (var.get()) {
              DessinImageParametres* param;
              DessinImage::ptr di( var->Pointer());
              param = di->GetParam();
              param->_MAJ.MAJCoupes();
              di->Paint();
              di->Raise();
            }
            else
            {
              FILE_MESSAGE(boost::format("SHOW var_image creating title %s ") % titre);
              DessinImage::ptr di;

              std::string varname(titre);

              di = DessinImage::Create_ptr( CreateIDraw( varname,  im));

              BasicVariable::ptr newvar = 
                Vars.AddVar<DessinImage>(titre.c_str(), di, var_context);
              di->SetCloseFunction(
                (void*) CB_delete_variable,
                (void*) (newvar.get()));
            }
          } // var_context >=0

          if (var_context==OBJECT_CONTEXT_NUMBER) {
            // Restore the object context
            Vars.SetObjectContext(previous_ocontext);
          }

        }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 2057 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im)
          string title;
          BasicVariable::ptr var;

          title = (boost::format("%s_draw") % varim->Name().c_str()).str();
          var = Vars.GetVar(title.c_str());
          if (var.get()) {
            if (var->Type() == type_imagedraw) {
                Variable<DessinImage>::ptr vard (boost::dynamic_pointer_cast<Variable<DessinImage> >(var));
                driver.err_print("Hide window \n");
                
                vard->Pointer()->Hide();
            }
            else
              fprintf(stderr,"Variable %s_draw not of type imagedraw \n",
                varim->Name().c_str());
          } else
            fprintf(stderr,"Image %s not visible \n",
          varim->Name().c_str());

        }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 2080 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          /**
            Description: rule to show a surface, since surface has moved to object wrapping
          **/
          GET_VARSTACK_VAR_OBJECT(SurfacePoly,surfvar,surf)
          string    titre;
          Viewer3D::ptr surfdraw;
          BasicVariable::ptr var;
          int var_context = Vars.GetContext(surfvar);

          Variables::ptr previous_ocontext = Vars.GetObjectContext();
          if (var_context==OBJECT_CONTEXT_NUMBER) {
            // set new object context
            Vars.SetObjectContext(surfvar->GetContext());
          }

          if ((var_context>=0)||
              (var_context==OBJECT_CONTEXT_NUMBER)) {
            titre = str(format("%s_draw") % surfvar->Name());
            var = Vars.GetVar(titre.c_str(),var_context);
            if (!var.get()) {
              surfdraw = Viewer3D::Create_ptr(
                            new Viewer3D( GB_main_wxFrame,
                                          wxString::FromAscii(titre.c_str())));

              BasicVariable::ptr newvar = 
                Vars.AddVar<Viewer3D>(  titre.c_str(),
                                        surfdraw,
                                        var_context);
              surfdraw->SetCloseFunction(
                              (void*) CB_delete_variable,
                              (void*) (newvar.get()));

              surfdraw->Show(true);
              // Add the surface to the OpenGL Object
              surfdraw->GetCanvas()->AddSurface( surf);
              surfdraw->Paint();
              surfdraw->GetCanvas()->Normalize();
              surfdraw->GetCanvas()->Center();
            } else
              cerr << " variable " << titre << " already exists " << endl;
          } // var_context >=0

          // Restore the object context
          if (var_context==OBJECT_CONTEXT_NUMBER) {
            Vars.SetObjectContext(previous_ocontext);
          }

        }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 2130 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          /**
          Parameters:
          (1) image: vectorial or RGB input image
          (5) n: component index
          (7) variable expression: numerical or image expression
  
          Description:
            assigns the number or the image to the component 'n' of the input image
          **/

          int comp = (int) (yysemantic_stack_[(8) - (5)].adouble);
          BasicVariable::ptr param2(driver.var_stack.GetLastBasicVar());
          GET_VARSTACK_VALUE(InrImage, i1);
  
          if (param2.get()) {
            if (param2->IsNumeric()) {
              double val = param2->GetValueAsDouble();
              Si (comp<0) Ou (comp>i1->GetVDim()) Alors
                fprintf(stderr,"image.SetComponent(n,number) error index too high, reset to 0 \n");
                comp = 0;
              FinSi
              Si i1->VectorialFormat()  Alors
                i1->InitBuffer();
                Repeter
                  i1->VectFixeValeur(comp,val);
                JusquA Non(i1->IncBuffer()) FinRepeter
              FinSi
            }
            else 
            if (param2->Type()==type_image) {
              DYNAMIC_CAST_VARIABLE(InrImage,param2,varim2) 
              InrImage::ptr i2(varim2->Pointer());
  
              Si (comp<0) Ou (comp>i1->GetVDim()) Alors
                fprintf(stderr,"image.SetComponent(n,image) error index too high, reset to 0 \n");
                comp = 0;
              FinSi
    
              Si i2->ScalarFormat()  Alors
                i1->InitBuffer();
                i2->InitBuffer();
                Repeter
                    i1->VectFixeValeur(comp,i2->ValeurBuffer());
                    i2->IncBuffer();
                JusquA Non(i1->IncBuffer()) FinRepeter
              Sinon
                driver.yyiperror("image.SetComponent\t second image has to be scalar \n");
                YYABORT;
              FinSi
            }
            else {
              driver.err_print("image.SetComponent(expr,expr_var) operator with this type of parameter not available");
              YYABORT;
            }
          }
        }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 2220 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
          Description: Pads the image ...
        **/
          GET_VARSTACK_VALUE(InrImage, i2);
          GET_VARSTACK_VALUE(InrImage, i1);
          int posx  = (int) (yysemantic_stack_[(16) - (3)].adouble);
          int stepx = (int) (yysemantic_stack_[(16) - (5)].adouble);
          int posy  = (int) (yysemantic_stack_[(16) - (7)].adouble);
          int stepy = (int) (yysemantic_stack_[(16) - (9)].adouble);
          int posz  = (int) (yysemantic_stack_[(16) - (11)].adouble);
          int stepz = (int) (yysemantic_stack_[(16) - (13)].adouble);

          Func_Pad(i1.get(),i2.get(),stepx,posx,stepy,posy,stepz,posz);

        }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 2246 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Vars.display();
        }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 2250 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
          Parameters:
              variable: input variable
              string expression: comments
          Description: Set comments for a variable
        **/
          BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
          boost::shared_array<char> comments( (yysemantic_stack_[(6) - (5)].astring));
          var->SetComments(comments.get());
        }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 2262 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
          Description: 
            Delete the given variable
        **/
         /*Variable* var;

         if (Vars.GetVar($2->Name(),&var))
         Vars.deleteVar($2->Name());
         */
         BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
         Vars.deleteVar(var);
        }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 2276 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
          Description: 
            Delete all variables that match the expression, where the expression can contain 
            '*' and '?' characters
        **/
        boost::shared_array<char> varmatch( (yysemantic_stack_[(2) - (2)].astring));
         Vars.deleteVars( varmatch.get());
        }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 2286 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
        Parameters:
          - string expression: command to call
        Description:
          calls a command from the system using std::system()
      **/
        boost::shared_array<char> cmd( (yysemantic_stack_[(2) - (2)].astring));
        std::system( cmd.get());
      }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 2297 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
        Description:
        Calls system 'ls' command (for unix systems)
      **/
         std::system("ls");
           }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 2305 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        driver.res_print("Topics: \n");
        driver.res_print("\t var:  variables                 \n");
            driver.res_print("\t     image:     Help for image     variables\n");
            driver.res_print("\t     imagedraw: Help for imagedraw variables\n");
        driver.res_print("\t cmd:  commands                  \n");
        driver.res_print("\t fnc:  functions                 \n");
        driver.res_print("\t loop: loops                     \n");
        driver.res_print("\t cond: conditions                \n");
            driver.res_print("\t arit: arithmetical expressions  \n");
      }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 2317 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
       if (strcmp(ident->GetName().c_str(),"var")==0) {
         driver.res_print("var types: void image float int string imagedraw surface surfacedraw \n");
         driver.res_print("\t del varname\n");
         driver.res_print("\t\t\t - deletes a variable and frees its contents from memory \n");
       }
       else
       if (strcmp(ident->GetName().c_str(),"cmd")==0) {
         driver.res_print("commands:\n");
         driver.res_print("\t sh Quit Image Show Help ls print func filter normgrad discnormgrad OpImage EDPdilate EDPerode EDPopen EDPclose\n");
       }
       else
       if (strcmp(ident->GetName().c_str(),"fnc")==0) {
         driver.res_print("functions:\n");
         driver.res_print("\t  filter normgrad gradient OpImage secdergrad ");
             driver.res_print("subimage putimage\n");
         driver.res_print("\t       OpImage( var_image, string ) \n");
         driver.res_print("\t       OpImage( var_image, var_image, string ) \n");
         driver.res_print("\t       OpImage( var_image, var_image, var_image, string ) \n");
         driver.res_print("\t       filter( var_image, expr, number, number, number ) \n");
         driver.res_print("\t       normgrad(   var_image, expr ) \n");
         driver.res_print("\t       discnormgrad(   var_image ) \n");
         driver.res_print("\t       gradient(   var_image, expr ) \n");
         driver.res_print("\t       secdergrad( var_image, expr ) \n");
         driver.res_print("\t       subimage( var_image, expr, expr, expr, expr, expr, expr ) \n");
         driver.res_print("\t       putimage( var_image, var_image, expr, expr, expr  ) \n");
         driver.res_print("\t       EDPdilate( var_image, expr, expr) \n");
         driver.res_print("\t       EDPerode(  var_image, expr, expr) \n");
         driver.res_print("\t       EDPopen(   var_image, expr, expr) \n");
         driver.res_print("\t       EDPclose(  var_image, expr, expr) \n");

         driver.res_print("\t       AnisoGS(   var_image, expr, expr, expr, expr) \n");
         driver.res_print("\t\t  expr 1: standard deviation of the Gaussian convolution  \n");
         driver.res_print("\t\t  expr 2: threshold on the gradient norm \n");
         driver.res_print("\t\t  expr 3: data attachment coefficient \n");
         driver.res_print("\t\t  expr 4: number of iterations \n");
             driver.res_print("\t       StructTensor( var_image, expr, expr ) \n");
             driver.res_print("\t       Curvatures(   var_image, expr ) \n");
       }
       else
       if (strcmp(ident->GetName().c_str(),"loop")==0) {
         driver.res_print("loops:\n");
         driver.res_print("\t  for var=expr to expr { instructions } \n");
       }
       else
       if (strcmp(ident->GetName().c_str(),"cond")==0) {
         driver.res_print("loops:\n");
         driver.res_print("\t  if expr  { instructions } \n");
         driver.res_print("\t\t  [ else { instructions } ]\n");
       }
       else
       if (strcmp(ident->GetName().c_str(),"arit")==0) {
         driver.res_print("arithmetical expressions:\n");
         driver.res_print("\t  constants: Pi\n");
         driver.res_print("\n");
         driver.res_print("\t  functions:  cos()  sin()  tan() \n");
         driver.res_print("\t             acos() asin() atan() \n");
         driver.res_print("\t              exp()   ln()  log() \n");
         driver.res_print("\t             sinh() cosh()        \n");
         driver.res_print("\t  operators:\n");
         driver.res_print("\t            *, /\n");
         driver.res_print("\t            +, -\n");
         driver.res_print("\t            <, >, <=, >=\n");
         driver.res_print("\t            ==, != \n");
         driver.res_print("\t            & \n");
         driver.res_print("\t            ^ \n");
         driver.res_print("\t            | \n");
       }
       else
       if (strcmp(ident->GetName().c_str(),"image")==0) {
         driver.res_print("variable Image\n");
         driver.res_print(" Creation:\n");
         driver.res_print("\t Image \"filename\"\n");
         driver.res_print("\t\t\t - reads an image file \n");
         driver.res_print("\t Image \n");
         driver.res_print("\t\t\t -  open browsing window for choosing the image\n");
         driver.res_print("\t Image(basic_type, size_x , size_y, size_z) \n");
         driver.res_print("\t\t\t - create an image of a basic type and the given dimensions\n");
         driver.res_print("\t\t\t - basic_type are CHAR UCHAR SHORT USHORT LONG INT FLOAT DOUBLE RGB FLOAT_VECTOR \n");
         driver.res_print("\t\t\t - size_x, size_y, size_z: float expressions \n");
         driver.res_print(" Functions that return a new image: \n");
         driver.res_print("\t OpImage( var_image, string ) \n");
         driver.res_print("\t\t\t - applies point to point operations to 1 image\n");
         driver.res_print("\t OpImage( var_image, var_image, string ) \n");
         driver.res_print("\t\t\t - applies point to point operations to 2 images\n");
         driver.res_print("\t OpImage( var_image, var_image, var_image, string ) \n");
         driver.res_print("\t\t\t - applies point to point operations to 3 images\n");
         driver.res_print("\t filter( var_image, size, number, number, number ) \n");
         driver.res_print("\t\t\t - applies Gaussian (or derivatives) convolution of sd size \n");
         driver.res_print("\t\t\t - number represent the derivation order:\n");
         driver.res_print("\t\t\t\t 0: no           derivation in this dimension\n");
         driver.res_print("\t\t\t\t 1: first order  derivation in this dimension\n");
         driver.res_print("\t\t\t\t 2: second order derivation in this dimension\n");
         driver.res_print("\t normgrad(   var_image, expr ) \n");
         driver.res_print("\t\t\t - applies Gaussian (or derivatives) convolution of sd size \n");

         driver.res_print("\t discnormgrad(   var_image ) \n");
         driver.res_print("\t\t\t - Discrete gradient norm without Gaussian convolution \n");

         driver.res_print("\t gradient(   var_image, expr ) \n");
         driver.res_print("\t\t\t - Gradient of the image using  Gaussian (and derivatives) convolution of sd size \n");

         driver.res_print("\t secdergrad( var_image, expr ) \n");
             driver.res_print("\t\t\t - Compute the second order derivative in the gradient direction.\n");


         driver.res_print("\t subimage( var_image, expr, expr, expr,");
         driver.res_print(" expr, expr, expr ) \n");
             driver.res_print("\t\t\t - extract a subimage \n");

         driver.res_print("\t AddGaussNoise( var_image, expr, expr) \n");
             driver.res_print("\t\t\t - add a Gaussian noise to the image \n");
             driver.res_print("\t\t\t - param 2: mean \n");
             driver.res_print("\t\t\t - param 3: standard deviation \n");

         driver.res_print("\t eccentricity( var_image) \n");
             driver.res_print("\t\t\t - Compute a expression of eccentricity  \n");
             driver.res_print("\t\t\t - of the image, returns an 'expr'  \n");

         driver.res_print("\t isoarea2D( var_image, expr, expr, expr) \n");
             driver.res_print("\t\t\t - Compute the surface area of the region\n");
             driver.res_print("\t\t\t   of positive intensity containing the point\n");
             driver.res_print("\t\t\t   (x,y)\n");
             driver.res_print("\t\t\t expr 1: resolution  \n");
             driver.res_print("\t\t\t expr 2: x  \n");
             driver.res_print("\t\t\t expr 3: y  \n");

         driver.res_print("\t EDPdilate( var_image, expr, expr) \n");
         driver.res_print("\t EDPerode(  var_image, expr, expr) \n");
         driver.res_print("\t EDPopen(   var_image, expr, expr) \n");
         driver.res_print("\t EDPclose(  var_image, expr, expr) \n");

         driver.res_print("\t AnisoGS(   var_image, expr, expr, expr, expr) \n");
         driver.res_print("\t\t  expr 1: sigma     \n");
         driver.res_print("\t\t  expr 2: threshold \n");
         driver.res_print("\t\t  expr 3: data attachment coefficient \n");
         driver.res_print("\t\t  expr 4: number of iterations \n");

         driver.res_print("\t image = AnisoWeickert.init( var_image, expr, expr, expr )\n");
         driver.res_print("\t\t  expr 1:    sigma  \n");
         driver.res_print("\t\t  expr 2:    theshold  \n");
         driver.res_print("\t\t  expr 3:    evolution step dt  \n");
         driver.res_print("\t AnisoWeickert.iterate\n");
         driver.res_print("\t AnisoWeickert.end\n");

         driver.res_print("\t image = AnisoCW.init( var_image, expr, expr, expr,expr, expr )\n");
         driver.res_print("\t\t  expr 1:    sigma  first Gaussian convolution\n");
         driver.res_print("\t\t  expr 2:    rho    second Gaussian convolution\n");
         driver.res_print("\t\t  expr 2:    C      threshold for the coherence\n");
         driver.res_print("\t\t  expr 2:    alpha  lowest diffusion coefficient\n");
         driver.res_print("\t\t  expr 3:    dt     evolution step \n");
         driver.res_print("\t AnisoCW.iterate\n");
         driver.res_print("\t AnisoCW.end\n");

         driver.res_print(" Operations: \n");

         driver.res_print("\t Show var_image \n");
         driver.res_print("\t\t\t - displays the image \n");

         driver.res_print("\t var_image = var_image \n");
         driver.res_print("\t\t\t - makes a copy \n");

         driver.res_print("\t var_image.initvalue( expr ) \n");
             driver.res_print("\t\t\t - initialize every point to a scalar value \n");

         driver.res_print("\t var_image.initvalue( expr, expr, expr ) \n");
             driver.res_print("\t\t\t - initialization every point to a vector or RGB value \n");

         driver.res_print("\t var_image.set( expr ) \n");
         driver.res_print("\t\t\t - change the value a the current point \n");

         driver.res_print("\t var_image.set( expr, expr, expr ) \n");
         driver.res_print("\t\t\t - change the value a the current point \n");
         driver.res_print("\t\t\t - for RGB or VECTOR FIELD images \n");

         driver.res_print("\t var_image.setpos(expr,expr,expr) \n");
         driver.res_print("\t\t\t - set the current position \n");

         driver.res_print("\t var_image.putimage(var_image,expr,expr,expr) \n");
         driver.res_print("\t\t\t - put an image at the specified position \n");

         driver.res_print("\t var_image(expr,expr) \n");
         driver.res_print("\t\t\t - return the value at a 2D position \n");

         driver.res_print("\t var_image(expr,expr,expr) \n");
         driver.res_print("\t\t\t - return the value at a 3D position \n");

         driver.res_print("\t var_image.tx \n");
         driver.res_print("\t\t\t - return size in X \n");

         driver.res_print("\t var_image.ty \n");
         driver.res_print("\t\t\t - return size in Y \n");

         driver.res_print("\t var_image.tz \n");
         driver.res_print("\t\t\t - return size in Z \n");

         driver.res_print("\t var_image.init \n");
         driver.res_print("\t\t\t - init the current position to (0,0,0) \n");

         driver.res_print("\t var_image.info \n");
         driver.res_print("\t\t\t - print information on the image \n");

         driver.res_print("\t var_image.save \"filename\" \n");
         driver.res_print("\t\t\t - save the image \n");

         driver.res_print("\t var_image.normalize \n");
         driver.res_print("\t\t\t - normalizes a vector field image \n");
       }
       else
       if (strcmp(ident->GetName().c_str(),"imagedraw")==0) {
         driver.res_print("variable imagedraw\n");
         driver.res_print(" Creation:");
         driver.res_print("\t show var_image \n");
         driver.res_print("\t\t\t - displays an image and creates a new variable\n");
         driver.res_print("\t\t\t   of type imagedraw and the name ending by _draw \n");
         driver.res_print(" Functions:\n");

         driver.res_print(" var_imagedraw.setpos( expr, expr, expr) \n");
         driver.res_print("\t\t\t   set the cursor position \n");

         driver.res_print(" var_imagedraw.showcursor( expr) \n");
         driver.res_print("\t\t\t   expr=1-->shows cursor   0-->hides cursor \n");

         driver.res_print(" var_imagedraw.update \n");
         driver.res_print("\t\t\t   update the displayed images \n");

         driver.res_print(" var_imagedraw.compare(var_image) \n");
         driver.res_print("\t\t\t   add a comparison image \n");

         driver.res_print(" var_imagedraw.setvector( number, var_image) \n");
         driver.res_print("\t\t\t   set var_image a the vector image with number \n");
         driver.res_print("\t\t\t   between 1 and 3 \n");
       }
     }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 2553 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        Displays the documentation relative to the wrapped image function.
    **/
      GET_VARSTACK_VALUE(C_wrap_imagefunction, func);
      // call with NULL paramlist pointer to trigger help message
      (*func)(NULL);
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 2563 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        Displays the documentation relative to the wrapped image function.
    **/
      GET_VARSTACK_VALUE(C_wrap_varfunction, func);
      // call with NULL paramlist pointer to trigger help message
      (*func)(NULL);
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 2573 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        Displays the documentation relative to the wrapped image function.
    **/
      GET_VARSTACK_VALUE(C_wrap_procedure, proc);
      // call with NULL paramlist pointer to trigger help message
      (*proc)(NULL);
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 2583 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        Displays the documentation relative to the wrapped c++ member.
    **/
      GET_VARSTACK_VALUE(WrapClassMember, m);
      m->ShowHelp();
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 2592 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      string  help_cmd;
      string  help_file;


      // Check for directory
      help_file = str( format("%s/%s") % GB_help_dir.c_str() % (yysemantic_stack_[(2) - (2)].astring));

      Si GB_debug AlorsFait fprintf(stderr,"3\n");
          help_cmd = str(format("test -d %s") % help_file.c_str());
          Si (std::system(help_cmd.c_str()) == 0) Alors
            printf("\nAvailable help files in %s:\n",(yysemantic_stack_[(2) - (2)].astring));
            help_cmd = str( format("cd %s; ls *.amih ") % help_file.c_str());
            std::system(help_cmd.c_str());
          Sinon

         Si GB_debug AlorsFait fprintf(stderr,"4\n");
            // Check for file
            help_file = str( format("%s/%s.amih") % GB_help_dir.c_str() %(yysemantic_stack_[(2) - (2)].astring));

            help_cmd = str(format("test -r %s") % help_file.c_str());
            Si (std::system(help_cmd.c_str()) == 0) Alors
              help_cmd = str( format("more %s") % help_file.c_str());
              std::system(help_cmd.c_str());
            Sinon
              Si GB_debug AlorsFait fprintf(stderr,"5\n");
              // Try to find it in any subdirectory of the help dir
              help_cmd = str(format("test -r `find %s -name \"%s.amih\"` 2> /dev/null")
                            % GB_help_dir.c_str()
                            % (yysemantic_stack_[(2) - (2)].astring));
              Si std::system(help_cmd.c_str())==0 Alors
                help_cmd = str(format("find %s -name \"%s.amih\" -exec ls {} \\; -exec more {} \\;")
                  % GB_help_dir.c_str()
                  % (yysemantic_stack_[(2) - (2)].astring));
                std::system(help_cmd.c_str());
              Sinon
                fprintf(stderr,"\nNo help file (%s) found for this command \n",
            help_file.c_str());
            printf("\nAvailable help directories:\n");
            help_cmd = str(format("cd %s; find . -type d  ") % GB_help_dir.c_str());
                std::system(help_cmd.c_str());

                printf("\nAvailable help files:\n");
            help_cmd = str(format("ls *.amih ") %
                std::system(help_cmd.c_str()));
          FinSi
            FinSi

          FinSi

      Si GB_debug AlorsFait fprintf(stderr,"6\n");

        }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 2657 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
          Variable<FILE>::ptr varfile(driver.var_stack.GetLastVar<FILE>());
          FILE_ptr file (varfile->Pointer());

          if (var.get()) {
            fprintf(file.get(),var->GetValueAsString().c_str());
            fflush(file.get());
          }
          else
            driver.err_print("empty variable");

      }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 2671 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
          Variable<FILE>::ptr varfile(driver.var_stack.GetLastVar<FILE>());
          FILE_ptr file (varfile->Pointer());

          if (var.get()) {
            fprintf(file.get(),var->GetValueAsString().c_str());
            fprintf(file.get(),"\n");
            fflush(file.get());
          }
          else
            driver.err_print("empty variable");

      }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 2705 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
         /**
          Description:
            Print a value of a variable, if the string conversion is defined, a message otherwise
          **/
          BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
          if (var.get())
            driver.res_print(var->GetValueAsString());
          else
            driver.err_print("empty variable");
        }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 2717 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
         /**
          Description:
            Print a value of a variable + newline, if the string conversion is defined, a message otherwise
          **/
          BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
          if (var.get())
            driver.res_print(var->GetValueAsString()+"\n");
          else
            driver.err_print("empty variable");
        }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 2758 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
         /**
          Parameters:
            string expression: information text
          Description:
            Popup an Information Dialog with the given message
          **/
          driver.info_print((yysemantic_stack_[(2) - (2)].astring));
          delete [] (yysemantic_stack_[(2) - (2)].astring);
      }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 2777 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          driver.var_stack.GetLastBasicVar();
          printf("Deprecated: No need to close files explicitly, since we use smart pointers, they will be closed when the variable is deleted. \n");
        }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 2804 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;
          DessinImageParametres* param;

          draw = DessinImage::ptr(varimd->Pointer());
          param = draw->GetParam();
          param->_pos._x = (int) (yysemantic_stack_[(10) - (5)].adouble);
          param->_pos._y = (int) (yysemantic_stack_[(10) - (7)].adouble);
          param->_pos._z = (int) (yysemantic_stack_[(10) - (9)].adouble);
          //      param->_pos.Check();
          param->_MAJ.MAJCoupes();

          draw->Paint();

        }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 2821 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;
          DessinImageParametres* param;

          draw = DessinImage::ptr(varimd->Pointer());
          param = draw->GetParam();
          param->_curseur._visible = (int) ((yysemantic_stack_[(6) - (5)].adouble)>0.5);
          //      param->_MAJ.MAJCoupes();

          draw->Paint();
        }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 2834 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;
          DessinImageParametres* param;

          draw = DessinImage::ptr(varimd->Pointer());
          param = draw->GetParam();
          param->_MAJ.MAJCoupes();
          draw->Paint();
        }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 2845 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage,    varim,  im);
          GET_VARSTACK_VAR_VAL(DessinImage, varimd, draw);
          char title[255];

            sprintf(title,"%s_draw",varim->Name().c_str());

            BasicVariable::ptr var = Vars.GetCurrentContext()->GetVar(title);
            if (var.get()) {
              Variable<DessinImage>::ptr vardi ( boost::dynamic_pointer_cast<Variable<DessinImage> >(var));
              DessinImage::ptr di(vardi->Pointer());
              DessinImageParametres* param;
              param = di->GetParam();
              param->_MAJ.MAJCoupes();
              di->Paint();

              /* already done at window creation
              std::string* varname = new std::string(title);
              di->SetCloseFunction(
                  (void*) CB_delete_imagedraw,
                  (void*) varname);
              */
              draw->CreeCompare2Image(di);
            }
            else
            {
              std::string varname(title);
              DessinImage::ptr di = 
                DessinImage::Create_ptr(CreateIDraw( varname, im));

              Variable<DessinImage>::ptr newvar = Vars.AddVar<DessinImage>(title, di);

              di->SetCloseFunction(
                  (void*) CB_delete_variable,
                  (void*) (newvar.get()));
              // get the pointer to the newly created
              // variable
              //BasicVariable::ptr var = Vars.GetVar(title);
              if (var.get())
                draw->CreeCompare2Image(newvar->Pointer());
              else
                fprintf(stderr,"Image comparison: Variable %s not found !\n",title);
            }

        }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 2891 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(DessinImage, draw2);
          GET_VARSTACK_VALUE(DessinImage, draw1);

          draw1->CreeCompare2Image(draw2);
        }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 2898 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (1) Image Draw Window
            (5)  comparison window
            (7) Vectorial image

        Description:
            Defines a displacement to apply to the cursor when
            comparing 2 image drawing windows
        **/
          GET_VARSTACK_VALUE(InrImage,    displ);
          GET_VARSTACK_VALUE(DessinImage, draw2);
          GET_VARSTACK_VALUE(DessinImage, draw);

          // TODO: check for SetCompareDisplacement, does it really work?
          draw->SetCompareDisplacement(draw2,displ);
        }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 2921 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {

          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
        driver.yyiperror( "SetCompTransf is not available at the moment");
/*
        DessinImage::ptr draw;
        FloatMatrix* mat;

        draw = *(DessinImage::ptr*) ($1->Pointer());

        mat = new FloatMatrix(4,4);
        (*mat)[0][0] = $5;
        (*mat)[0][1] = $7;
        (*mat)[0][2] = $9;
        (*mat)[0][3] = $11;
        (*mat)[1][0] = $13;
        (*mat)[1][1] = $15;
        (*mat)[1][2] = $17;
        (*mat)[1][3] = $19;
        (*mat)[2][0] = $21;
        (*mat)[2][1] = $23;
        (*mat)[2][2] = $25;
        (*mat)[2][3] = $27;

            if (draw->GetCompareWindow(0)!=NULL)
          draw->GetCompareWindow(0)->SetTransformationMatrix(mat);
        // PB: the matrix is never freed from memory ...
        // TODO use smart pointer management !!!
*/
        }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 2952 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          /**
            Parameters:
                (1) Image Drawing window
                (5) Index of the vector field to be drawned (between 1 and 3)
                (7) Vector field image
            Description:
                Assign a vector field to be draw in the given image drawing window.
          **/
          GET_VARSTACK_VALUE(InrImage,    im);
          GET_VARSTACK_VALUE(DessinImage, draw);

          draw->LoadVectImage( (int) (yysemantic_stack_[(8) - (5)].adouble), im);
        }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 2967 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;

          draw = DessinImage::ptr(varimd->Pointer());
          draw->SetVectorVisible( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 2975 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;

          draw = DessinImage::ptr(varimd->Pointer());
          draw->CB_AfficheChampVect(draw.get(),NULL);
        }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 2983 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          /**
          Parameters:
            (5) expression: vector size
            (7) expression: vector spacing

          Description:
            Sets the size and spacing of the vector drawing interface in the given
            image drawing window.
          **/
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;
          float size    = (yysemantic_stack_[(8) - (5)].adouble);
          int   spacing = (int)(yysemantic_stack_[(8) - (7)].adouble);

          draw = DessinImage::ptr(varimd->Pointer());
          draw->SetVectParam( size, spacing);
        }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 3002 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          /** 
            Parameters:
            (5)  expression: vector id
            (7)  expression: red component (0-255)
            (9)  expression: green component (0-255)
            (11) expression: blue component (0-255)

            Description:
            Sets the color of the given vector field (given by vector id),
            the color is set as (R,G,B) components, each component has a value
            between 0 and 255.
          **/
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;
          int vectid = (int) (yysemantic_stack_[(12) - (5)].adouble);
          unsigned char red   = (unsigned char) (yysemantic_stack_[(12) - (7)].adouble);
          unsigned char green = (unsigned char) (yysemantic_stack_[(12) - (9)].adouble);
          unsigned char blue  = (unsigned char) (yysemantic_stack_[(12) - (11)].adouble);

          draw = DessinImage::ptr(varimd->Pointer());
          draw->SetVectColor( vectid,red,green,blue);
        }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 3026 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw= DessinImage::ptr(varimd->Pointer());
          draw->SetVectType((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 3032 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw= DessinImage::ptr(varimd->Pointer());
          draw->SetLineThickness((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 3038 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          int xmin = (int)  (yysemantic_stack_[(16) - (5)].adouble);
          int ymin = (int)  (yysemantic_stack_[(16) - (7)].adouble);
          int zmin = (int)  (yysemantic_stack_[(16) - (9)].adouble);
          int xmax = (int) (yysemantic_stack_[(16) - (11)].adouble);
          int ymax = (int) (yysemantic_stack_[(16) - (13)].adouble);
          int zmax = (int) (yysemantic_stack_[(16) - (15)].adouble);

          DessinImage::ptr draw= DessinImage::ptr(varimd->Pointer());
          draw->SetZoom(xmin,ymin,zmin,xmax,ymax,zmax);

        }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 3052 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          int width  = (int) (yysemantic_stack_[(8) - (5)].adouble);
          int height = (int) (yysemantic_stack_[(8) - (7)].adouble);

          DessinImage::ptr draw= DessinImage::ptr(varimd->Pointer());
          draw->SetSize(width,height);
          draw->Update();


        }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 3064 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          ClasseCouleur c;

          draw = DessinImage::ptr(varimd->Pointer());
          c.FixeValeur((int)(yysemantic_stack_[(16) - (11)].adouble),(int)(yysemantic_stack_[(16) - (13)].adouble),(int)(yysemantic_stack_[(16) - (15)].adouble));
          draw->DessineCercle( (int) (yysemantic_stack_[(16) - (5)].adouble), (int) (yysemantic_stack_[(16) - (7)].adouble), (int) (yysemantic_stack_[(16) - (9)].adouble), c);
        }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 3074 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
          Description: Set a user-defined colormap.
         **/
          GET_VARSTACK_VALUE(InrImage, colmap);
          GET_VARSTACK_VALUE(DessinImage, draw);

          draw->SetUserColormap( colmap,  (yysemantic_stack_[(10) - (7)].adouble),  (yysemantic_stack_[(10) - (9)].adouble));
        }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 3084 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,    surfd);
          GET_VARSTACK_VALUE(DessinImage, draw);

          draw->SetGLWindow(surfd);
        }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 3091 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) isocontour index (0,1 or 2)
                (7) image to use for the isocontour
                (9) intensity value of the isocontour

            Description:
                Sets the image and intensity value of an isocontour in an 'image_draw' window.
            **/
          GET_VARSTACK_VALUE(InrImage,    im);
          GET_VARSTACK_VALUE(DessinImage, draw);

          draw->InitIsoContour( im, (yysemantic_stack_[(10) - (9)].adouble) , (int) (yysemantic_stack_[(10) - (5)].adouble) );
          draw->DrawIsoContour( (int) (yysemantic_stack_[(10) - (5)].adouble), true );
        }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 3108 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) image to use for the isocontour
                (7) intensity value of the isocontour

            Description:
                Sets the image and intensity value of the isocontour number 0 in an 'image_draw' window.
            **/
          GET_VARSTACK_VALUE(InrImage,    im);
          GET_VARSTACK_VALUE(DessinImage, draw);

          draw->InitIsoContour( im, (yysemantic_stack_[(8) - (7)].adouble) , 0 );
          draw->DrawIsoContour( 0, true );
        }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 3124 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) isocontour index (0,1 or 2)
                (7) isocontour thickness
                (9) isocontour style

            Description:
                Sets the parameters (line style and thickeness)
                of an isocontour in an 'image_draw' window.
            **/
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;

          draw = DessinImage::ptr(varimd->Pointer());
          draw->SetIsoContourParam( (int)(yysemantic_stack_[(10) - (5)].adouble), (int)(yysemantic_stack_[(10) - (7)].adouble), (int)(yysemantic_stack_[(10) - (9)].adouble) );
        }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 3142 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5)  isocontour index (0,1 or 2)
                (7)  isocontour thickness
                (9)  isocontour style (0,1,2 for LineSolid, LineOnOffDash, or LineDoubleDash)
                (11) cap_style (0:CapNotLast, 1:CapButt, 2:CapRound, or 3:CapProjecting)
                (13) join_style (0:JoinMiter, 1:JoinRound, or 2:JoinBevel)

            Description:
                Sets the parameters (line style and thickeness)
                of an isocontour in an 'image_draw' window.
            **/
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;

          draw = DessinImage::ptr(varimd->Pointer());
          draw->SetIsoContourParam( (int)(yysemantic_stack_[(14) - (5)].adouble), (int)(yysemantic_stack_[(14) - (7)].adouble), (int)(yysemantic_stack_[(14) - (9)].adouble) );
          draw->SetLineAttributes( (int)(yysemantic_stack_[(14) - (11)].adouble), (int)(yysemantic_stack_[(14) - (13)].adouble));
        }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 3163 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) isocontour index (0,1 or 2)
                (7) visible or not (0 or 1)

            Description:
                Sets the visibility of an isocontour in an 'image_draw' window.
            **/
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;

          draw = DessinImage::ptr(varimd->Pointer());
          draw->DrawIsoContour( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble) );
        }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 3179 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) isocontour index (0,1 or 2)
                (7)  Red   component in [0,255]
                (9)  Green component in [0,255]
                (11) Blue  component in [0,255]

            Description:
                Sets the color as RGB of an isocontour in an 'image_draw' window.
            **/
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;
          draw = DessinImage::ptr(varimd->Pointer());
          draw->SetIsoContourColor( (int) (yysemantic_stack_[(12) - (5)].adouble), (unsigned char) (yysemantic_stack_[(12) - (7)].adouble),
                                              (unsigned char) (yysemantic_stack_[(12) - (9)].adouble),
                                              (unsigned char) (yysemantic_stack_[(12) - (11)].adouble));
        }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 3198 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) boolean parameter

            Description:
                Activates or desactivates the drawing of a series of isocontours.
            **/
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;
          draw = DessinImage::ptr(varimd->Pointer());
          draw->SetDrawAllContours( (int) (yysemantic_stack_[(6) - (5)].adouble) );
        }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 3212 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) intensity step between isocontours
                (7) half size of the intensity range where to draw isocontours

            Description:
                Parameters for drawing a series of isocontours around the main isocontour.
            **/
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;
          draw = DessinImage::ptr(varimd->Pointer());
          draw->AllContoursParam(  (yysemantic_stack_[(8) - (5)].adouble) , (yysemantic_stack_[(8) - (7)].adouble) );
        }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 3227 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(AMIFunction, func);
          GET_VARSTACK_VALUE(DessinImage, draw);

          draw->SetPaintCallback( (void*) CB_ParamWin, 
                                  (void*) func.get() );
          // may be a pb to call Paint() here since it will start another interpreter ??? to check
          //draw->Paint();
        }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 3237 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
         Description:
            Setting the opacity image for the volume rendering.
            This image should have unsigned char values.
         **/
          GET_VARSTACK_VALUE(InrImage,    im);
          GET_VARSTACK_VALUE(DessinImage, imdraw);

          imdraw->SetVolRenOpacity( im.get());
        }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 3249 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          /**
          Description:
            Init the image buffer to the first voxel or pixel:
            at coordinates (0,0,0).
    
          See also:
                  inc val
    
          Example(s):
    
          i.init
          for x=0 to i.tx-1 {
            print "value at x = "; print x; print ": ";
            print i.val; print "\n";
            i.inc
          }
          **/
          GET_VARSTACK_VALUE(InrImage, im);
          im->InitBuffer();
        }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 3271 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
            /**
              Description:
                Prints the image information
            **/
            GET_VARSTACK_VAR_VAL(InrImage, varim, im);
            std::string tmp_string;
            tmp_string = (boost::format(" %s: format=%s  dim=(%d,%d,%d)x%d  vox=(%f,%f,%f) \
      translation =(%f,%f,%f) \n")
                % varim->Name()
                % im->FormatName().c_str()
                % im->_tx
                % im->_ty
                % im->_tz
                % im->GetVDim()
                % im->_size_x
                % im->_size_y
                % im->_size_z
                % im->_translation_x
                % im->_translation_y
                % im->_translation_z).str();
            driver.res_print(tmp_string);
        }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 3295 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          /**
            Description:
              Prints the object information
          **/
          GET_VARSTACK_VAR_VAL(AMIObject,varamio,o);
          
          if (o.get()) {
            cout << "var   name = " << varamio->Name() <<endl;
            if (o->GetClass().get()) {
              cout << "class name = " << o->GetClass()->GetName() <<endl;
            }
            o->GetContext()->display();
          }
    /*      std::string tmp_string;
          tmp_string = (boost::format("Object '%1%' instance of class '%2% \n")
              % $1->Name() % o->GetClass()->GetName() ).str();
          driver.res_print(tmp_string);
          o->GetContext()->display();
    */
        }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 3317 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (5) expr:  value to init the image

        Description:
          Set the whole image to the same vector value .
        **/
          GET_VARSTACK_VALUE(InrImage, im);
          (im)->InitImage((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 3329 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (5) expr:  X coord of the init vector
          (7) expr:  Y coord of the init vector
          (9) expr:  Z coord of the init vector

        Description:
          Set the whole image to the same value.
        **/
          GET_VARSTACK_VALUE(InrImage,    im);
          im->InitImage((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
        }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 3343 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          #1 expr:  scalar value

        Description:
        Set the current voxel (or pixel)
        to the specified value.
        The position of the current voxel can be set
        using 'setpos'.


        See also:
                setpos
        **/
          GET_VARSTACK_VALUE(InrImage, im);
          im->FixeValeur((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 3362 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {

        /**
        Parameters:
          #1 expr:  X coord of the vector value
          #2 expr:  Y coord of the vector value
          #3 expr:  Z coord of the vector value

        Description:
        Set the current voxel (or pixel)
        to the specified value.
        The position of the current voxel can be set
        using 'setpos'.


        See also:
                setpos
        **/
          GET_VARSTACK_VALUE(InrImage, im);
          im->VectFixeValeurs((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
        }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 3384 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (5) expr:  X position
          (7) expr:  Y position
          (9) expr:  Z position

        Description:
          Set the current voxel (or pixel) of the image
          to the specified position.

        See also:
          set
        **/
          GET_VARSTACK_VALUE(InrImage, im);
          int x = (int) round((double)(yysemantic_stack_[(10) - (5)].adouble));
          int y = (int) round((double)(yysemantic_stack_[(10) - (7)].adouble));
          int z = (int) round((double)(yysemantic_stack_[(10) - (9)].adouble));
          Si im->CoordOK( x,y,z)
          Alors
            im->BufferPos(x,y,z);
          Sinon
            std::string tmp_string;
            tmp_string = (boost::format("setpos \t coord = (%1% %2% %3%) from (%4% %5% %6%) \n")%x%y%z % (yysemantic_stack_[(10) - (5)].adouble) % (yysemantic_stack_[(10) - (7)].adouble) % (yysemantic_stack_[(10) - (9)].adouble)).str();
          driver.err_print(tmp_string);
          FinSi
        }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 3415 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (1)  var_image: image to modify
          (5)  var_image: image to insert
          (7)  expr:      X position of inserted image
          (9)  expr:      Y position
          (11) expr:      Z position

        Description:
          Insert an image (#2) in a given image (#1)
          at the specified position in voxel coordinates,
          does not use the translation information from the image.

        Example(s):
          i = Image(FLOAT,10,10,10)
          j = Image(FLOAT,5,5,5)
          i.putimage(j,2,2,2)
        **/
          Variable<InrImage>::ptr  varim2( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim1( driver.var_stack.GetLastVar<InrImage>());
          InrImage::ptr  i1(varim1->Pointer());
          InrImage::ptr  i2(varim2->Pointer());
          Func_PutImage( i1.get(), i2.get(), (int) (yysemantic_stack_[(12) - (7)].adouble), (int) (yysemantic_stack_[(12) - (9)].adouble), (int) (yysemantic_stack_[(12) - (11)].adouble));
        }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 3442 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (1)  var_image: image to modify
          (5)  var_image: image to insert

        Description:
          Insert an image  in a given image,
          uses the translation and the voxel size information
          to calculate where to insert the image.

        Example(s):
          i = Image(FLOAT,10,10,10)
          j = Image(FLOAT,5,5,5)
          i.putimage(j,2,2,2)
        **/
          Variable<InrImage>::ptr  varim2( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim1( driver.var_stack.GetLastVar<InrImage>());
          InrImage::ptr  i1(varim1->Pointer());
          InrImage::ptr  i2(varim2->Pointer());
          float tx1,ty1,tz1;
          float tx2,ty2,tz2;

          i1->GetTranslation(tx1,ty1,tz1);
          i2->GetTranslation(tx2,ty2,tz2);
          Func_PutImage( i1.get(), i2.get(),
             (int) round((double)(tx2-tx1)/i1->VoxSizeX()),
             (int) round((double)(ty2-ty1)/i1->VoxSizeY()),
             (int) round((double)(tz2-tz1)/i1->VoxSizeZ()));
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 3474 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> name((yysemantic_stack_[(6) - (5)].astring));
      GET_VARSTACK_VALUE(InrImage, im);
      im->FixeNom( name.get());
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 3671 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 3676 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {

      Func_EndWeickert();

    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 3683 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 3688 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Func_EndWeickert();
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 3928 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters
          (4) expr_string:  image name

        Description:
          Save the image to the disk, using the specified
          image name.
          The output format depends on the image type
          and on the filename extension.
          For saving images with standard 2D image format
          (jpeg, gif, etc...) you need to have a RGB image.


        Example(s):

          rgb_im = (RGB) im
          im.save "image.jpg"


        See also:
          image_cast
        **/
          GET_VARSTACK_VALUE(InrImage, im);
          boost::shared_array<char> filename((yysemantic_stack_[(4) - (4)].astring));
          im->Sauve(filename.get());
        }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 3956 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Normalizes a vector field given by a vectorial image.

        Example(s):
          v1.normalize

        **/
      GET_VARSTACK_VALUE(InrImage, im);
      Func_Normalize((im.get()));
    }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 3970 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im2);
      GET_VARSTACK_VALUE(InrImage, im1);
      Func_OrientField( im1.get() , im2.get() );
    }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 3977 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im2);
      GET_VARSTACK_VALUE(InrImage, im1);
      Func_OrientPositive( im1.get(), im2.get());
    }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 3983 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      if (strlen((yysemantic_stack_[(4) - (3)].astring))<255) {
        strcpy(AMIFluid::FLUID_NAVIGATION_FILE,(yysemantic_stack_[(4) - (3)].astring));
      } else
        fprintf(stderr,"SetFluidNavFile() \t File too long \n");
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 3992 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(DessinImage,di);
      float minlat  = (yysemantic_stack_[(20) - (5)].adouble);
      float maxlat  = (yysemantic_stack_[(20) - (7)].adouble);
      float latstep = (yysemantic_stack_[(20) - (9)].adouble);
      float latsmallsteps = (yysemantic_stack_[(20) - (11)].adouble);
      float minlon  = (yysemantic_stack_[(20) - (13)].adouble);
      float maxlon  = (yysemantic_stack_[(20) - (15)].adouble);
      float lonstep = (yysemantic_stack_[(20) - (17)].adouble);
      float lonsmallsteps = (yysemantic_stack_[(20) - (19)].adouble);

      float  lat,lon;
      float  X,Y;
      float  posx1=0,posy1=0;
      int    pos1_OK,pos2_OK;
      float  posx2=0,posy2=0;
      int    len;
      AMIFluid::TNavig nav_params;
      int    i_offset, j_offset;
      int    type=1; // Africa
      char typestring[2][255] = {"NAtl","AfGG"};

      InrImage::ptr           im    = di->GetImage();
      DessinImageParametres* param = di->GetParam();

      AMIFluid::InitCoordinates(i_offset,j_offset,nav_params, typestring[type]);
      minlat  *= PI/180.0;
      maxlat  *= PI/180.0;
      minlon  *= PI/180.0;
      maxlon  *= PI/180.0;
      latstep *= PI/180.0;
      lonstep *= PI/180.0;

      latsmallsteps *= PI/180.0;
      lonsmallsteps *= PI/180.0;

      // Lattitude lines
      for(lat=minlat;lat<=maxlat;lat+=latstep) {
        pos1_OK=0;
        for(lon=minlon;lon<=maxlon;lon+=lonsmallsteps)
          {
        AMIFluid::COOCAR1(lat,lon,X,Y,len,nav_params);
        if (len==0) {
          //          printf("len==0\n");
          X=X-i_offset;
          Y=Y-j_offset;
          posx2=(X-im->TrX())/im->VoxSizeX();
          posy2=(Y-im->TrY())/im->VoxSizeY();

          pos2_OK =  ((posx2>=param->_Zoom._xmin)&&(posx2<=param->_Zoom._xmax)&&
                  (posy2>=param->_Zoom._ymin)&&(posy2<=param->_Zoom._ymax));
          if (pos1_OK&&pos2_OK) {
            if (fabsf(lat)>1E-5)
              di->FixeParametresLigne( 1, wxSOLID, wxCAP_ROUND, wxJOIN_MITER);
            else
              di->FixeParametresLigne( 1, wxDOT, wxCAP_ROUND, wxJOIN_MITER);
            di->DrawLineZ(posx1,posy1,posx2,posy2);
          }
        }
        else pos2_OK=0;

        posx1=posx2;
        posy1=posy2;
        pos1_OK=pos2_OK;
          }
      }

      // Longitude Lines
      for(lon=minlon;lon<=maxlon;lon+=lonstep) {
        pos1_OK=0;
        for(lat=minlat;lat<=maxlat;lat+=latsmallsteps)
          {
        AMIFluid::COOCAR1(lat,lon,X,Y,len,nav_params);
        if (len==0) {
          //          printf("len==0\n");
          X=X-i_offset;
          Y=Y-j_offset;
          posx2=(X-im->TrX())/im->VoxSizeX();
          posy2=(Y-im->TrY())/im->VoxSizeY();

          pos2_OK =  ((posx2>=param->_Zoom._xmin)&&(posx2<=param->_Zoom._xmax)&&
                  (posy2>=param->_Zoom._ymin)&&(posy2<=param->_Zoom._ymax));
          if (pos1_OK&&pos2_OK) {
            if (fabsf(lon)>1E-5)
              di->FixeParametresLigne( 1, wxSOLID, wxCAP_ROUND, wxJOIN_MITER);
            else
              di->FixeParametresLigne( 1, wxDOT, wxCAP_ROUND, wxJOIN_MITER);
            di->DrawLineZ(posx1,posy1,posx2,posy2);
          }
        }
        else pos2_OK=0;

        posx1=posx2;
        posy1=posy2;
        pos1_OK=pos2_OK;
          }
      }

      }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 4092 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,sdraw);

          sdraw->GetCanvas()->UserRotate((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 4099 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_OBJECT(SurfacePoly,surf)
          GET_VARSTACK_VALUE(Viewer3D,sdraw);

          sdraw->GetCanvas()->AddSurface(surf);
          sdraw->Paint();
        }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 4107 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_OBJECT(SurfacePoly,surf)
          GET_VARSTACK_VALUE(Viewer3D,   sdraw);

          sdraw->GetCanvas()->AddSurface( surf);
          //sdraw->Paint();
        }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 4115 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_OBJECT(SurfacePoly,surf)
          GET_VARSTACK_VALUE(Viewer3D,   sdraw);

          sdraw->GetCanvas()->RemoveSurface(surf);
          sdraw->Paint();
        }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 4123 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          /**
            Description: Removes the surface without swapping the 3D buffer
          **/
          GET_VARSTACK_OBJECT(SurfacePoly,surf)
          GET_VARSTACK_VALUE(Viewer3D,   sdraw);

          sdraw->GetCanvas()->RemoveSurface(surf);
          sdraw->Paint(false);
        }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 4134 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          /**
            Description:  Swaps the 3D buffer
          **/
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw(varsurfd->Pointer());

          sdraw->GetCanvas()->AfficheBuffer();
        }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 4144 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC ( (int) (yysemantic_stack_[(6) - (5)].adouble) );
          sdraw->Paint();
        }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 4152 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
          sdraw->Paint();
        }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 4160 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());

          Si sdraw->GetCanvas()->SetCurrentObject( (int) (yysemantic_stack_[(6) - (5)].adouble) ) Alors
            sdraw->Paint();
          Sinon
            fprintf(stderr," Incorrect index \n");
          FinSi
        }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 4171 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,sdraw2);
          GET_VARSTACK_VALUE(Viewer3D,sdraw1);

          sdraw1->AddCompSurf(sdraw2);
        }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 4178 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage,im);
          GET_VARSTACK_VALUE(Viewer3D,draw);

          switch ((int) (yysemantic_stack_[(8) - (5)].adouble)) {
          case 1:
            draw->GetCanvas()->SetVectors1( im);
            break;
          case 2:
            draw->GetCanvas()->SetVectors2( im);
            break;
          }
        }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 4192 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr draw (varsurfd->Pointer());
          int num = (int) (yysemantic_stack_[(16) - (5)].adouble);
          GET_VARSTACK_VALUE(InrImage,im);
          int orientation = (int) (yysemantic_stack_[(16) - (9)].adouble);
          int pos = (int) (yysemantic_stack_[(16) - (11)].adouble);
          float Imin = (yysemantic_stack_[(16) - (13)].adouble);
          float Imax = (yysemantic_stack_[(16) - (15)].adouble);

          draw->GetCanvas()->ShowFreeSection(num,im.get(),orientation,pos,Imin,Imax);

        }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 4206 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr draw (varsurfd->Pointer());
          int num = (int) (yysemantic_stack_[(6) - (5)].adouble);
    
          draw->GetCanvas()->HideFreeSection(num);
    
        }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 4215 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,v);
          v->GetCanvas()->PrintMatrices();
        }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 4220 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->GetCanvas()->SetObjectTransform(*tr);
              sdraw->Paint();
          delete tr;
        }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 4229 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->GetCanvas()->SetObjectTransform(*tr);
          if ((yysemantic_stack_[(8) - (7)].adouble)>0.5) sdraw->Paint();
          delete tr;
        }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 4238 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->Paint();
          sdraw->Update();
          //sdraw->Raise();
          // process all pending events ...
          while (GB_wxApp->Pending()) {
            if (GB_verbose) printf("Dispatching event on GB_wxApp \n");
            GB_wxApp->Dispatch();
          }
        }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 4251 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          int lightnumber = (int) (yysemantic_stack_[(12) - (5)].adouble);
          int r = (int) (yysemantic_stack_[(12) - (7)].adouble);
          int g = (int) (yysemantic_stack_[(12) - (9)].adouble);
          int b = (int) (yysemantic_stack_[(12) - (11)].adouble);
          if (lightnumber<MAX_LIGHTS) {
                sdraw->GetCanvas()->GetLight(lightnumber)._ambient.FixeValeur(r,g,b);
            sdraw->Paint();
          }
        }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 4264 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          int lightnumber = (int) (yysemantic_stack_[(12) - (5)].adouble);
          int r = (int) (yysemantic_stack_[(12) - (7)].adouble);
          int g = (int) (yysemantic_stack_[(12) - (9)].adouble);
          int b = (int) (yysemantic_stack_[(12) - (11)].adouble);
          if (lightnumber<MAX_LIGHTS) {
                sdraw->GetCanvas()->GetLight(lightnumber)._diffuse.FixeValeur(r,g,b);
            sdraw->Paint();
          }
        }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 4277 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          int lightnumber = (int) (yysemantic_stack_[(12) - (5)].adouble);
          int r = (int) (yysemantic_stack_[(12) - (7)].adouble);
          int g = (int) (yysemantic_stack_[(12) - (9)].adouble);
          int b = (int) (yysemantic_stack_[(12) - (11)].adouble);
          if (lightnumber<MAX_LIGHTS) {
                sdraw->GetCanvas()->GetLight(lightnumber)._specular.FixeValeur(r,g,b);
            sdraw->Paint();
          }
        }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 4290 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->GetCanvas()->SetBG((int)(yysemantic_stack_[(10) - (5)].adouble),(int)(yysemantic_stack_[(10) - (7)].adouble),(int)(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 4297 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Normalizes the 3D view based on the limits in space of the current objects
        **/
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->GetCanvas()->Normalize();
        }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 4307 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Centers the 3D view based on the limits in space of the current objects
        **/
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->GetCanvas()->Center();
        }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 4317 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->SetSize((int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
          sdraw->Paint();
          sdraw->Update();
          // process all pending events ...
          while (GB_wxApp->Pending()) {
            if (GB_verbose) printf("Dispatching event on GB_wxApp \n");
            GB_wxApp->Dispatch();
          }
        }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 4331 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          Func_StructureTensor(im.get(),
                   varim->Name().c_str(),
                   (yysemantic_stack_[(8) - (5)].adouble), (yysemantic_stack_[(8) - (7)].adouble), NULL);
        }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 4339 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage,mask);
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);

          Func_StructureTensor(
            im.get(),
            varim->Name().c_str(),
            (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), mask.get());
        }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 4350 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (3) Input image
            (5) Numerical expression: sigma, Gaussian standard deviation
            (7) Numerical expression: beta, Hessian matrix coefficient
        Description:
            Computation of a Tensor that combines the standard
            gradient based structure tensor and the square
            of the Hessian matrix
            Computes eigenvalues and eigenvectors of the tensor
            and saves them in images:
            i_STHvap1, i_STHvap2, i_STHvap3
            i_STHvep1, i_STHvep2, i_STHvep3
        **/
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          Func_StructureTensorHessian(
            im.get(),
            varim->Name().c_str(),
            (yysemantic_stack_[(8) - (5)].adouble), (yysemantic_stack_[(8) - (7)].adouble), NULL);
        }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 4373 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (3) Input image
            (5) Numerical expression: sigma, Gaussian standard deviation
            (7) Numerical expression: beta, Hessian matrix coefficient
            (9) IMAGE: mask of the places to compute the tensor
        Description:
            Computation of a Tensor that combines the standard
            gradient based structure tensor and the square
            of the Hessian matrix
            Computes eigenvalues and eigenvectors of the tensor
            and saves them in images:
            i_STHvap1, i_STHvap2, i_STHvap3
            i_STHvep1, i_STHvep2, i_STHvep3
        **/
          GET_VARSTACK_VALUE(InrImage,mask);
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);

          Func_StructureTensorHessian(
            im.get(),
            varim->Name().c_str(),
            (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), mask.get());
        }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 4399 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (3) Input image
            (5) Numerical expression: sigma, Gaussian standard deviation
            (7) Numerical expression: beta, Hessian matrix coefficient
            (9) IMAGE: mask of the places to compute the tensor
            (11) NUM: boolean for saving the gradient vector
        Description:
            Computation of a Tensor that combines the standard
            gradient based structure tensor and the square
            of the Hessian matrix
            Computes eigenvalues and eigenvectors of the tensor
            and saves them in images:
            i_STHvap1, i_STHvap2, i_STHvap3
            i_STHvep1, i_STHvep2, i_STHvep3
            i_STHgrad
        **/
          GET_VARSTACK_VALUE(InrImage,mask);
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          int save_grad = (int) (yysemantic_stack_[(12) - (11)].adouble);

          Func_StructureTensorHessian(im.get(),
                   varim->Name().c_str(),
                   (yysemantic_stack_[(12) - (5)].adouble), (yysemantic_stack_[(12) - (7)].adouble), mask.get(), save_grad);
        }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 4427 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          Func_HessianMatrix(im.get(),
                 varim->Name().c_str(),
                 (yysemantic_stack_[(6) - (5)].adouble),   // sigma
                 0,   // gamma
                 NULL  // mask
                 );
        }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 4438 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          /**
            Description:
              Computes the Hessian Matrix of an image.
              Computes eigenvalues and eigenvectors of the tensor
              and saves them in images:
              i_Hvap1, i_Hvap2, i_Hvap3
              i_Hvep1, i_Hvep2, i_Hvep3
              i_Hgrad
            Parameters:
              - input image variable
              - sigma
              - gamma or mask image
          **/

          BasicVariable::ptr param3(driver.var_stack.GetLastBasicVar());
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          InrImage::ptr mask;
          float gamma = 0;

          // TODO: wrap HessianMatrix and get rid of this conflict ...
          if (param3.get()) {
            if (param3->IsNumeric())  {
              gamma = param3->GetValueAsDouble();
            } else {
              if (param3->Type()==type_image)  {
                DYNAMIC_CAST_VARIABLE(InrImage,param3,maskvar) 
                mask = InrImage::ptr(maskvar->Pointer());
              }
              else
                driver.err_print("HessianMatrix \t wrong type of parameter.");
            }
          }

          Func_HessianMatrix(im.get(),
                 varim->Name().c_str(),
                 (yysemantic_stack_[(8) - (5)].adouble),   // sigma
                 0,   // gamma
                 mask.get()  // mask
                 );
        }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 4481 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Computes the Hessian Matrix in 3D
          Parameters:
            - input image
            - Gaussian kernel standard deviation
            - Gamma normalization parameter
            - Mask image
        **/
          GET_VARSTACK_VALUE(InrImage,mask);
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);

          Func_HessianMatrix(im.get(),
                 varim->Name().c_str(),
                 (yysemantic_stack_[(10) - (5)].adouble),   // sigma
                 (yysemantic_stack_[(10) - (7)].adouble),   // gamma
                 mask.get()  // mask
                 );
        }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 4503 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (3)  input image
          (5)  expr: Gaussian standard deviation
          (7)  expr: normalization parameter gamma
          (9)  choose for 1st eigenvalue/eigenvector
          (11) choose for 1st eigenvalue/eigenvector
          (13) choose for 1st eigenvalue/eigenvector
          (15) choose for gradient vector


        Description:
            Compute information for local first and second order derivatives
         **/
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          Func_Derivatives(im.get(),
               varim->Name().c_str(),
               (yysemantic_stack_[(16) - (5)].adouble),   // sigma
               (yysemantic_stack_[(16) - (7)].adouble),   // gamma
               NULL,
               (int)(yysemantic_stack_[(16) - (9)].adouble),   // 1st eigenvalue | eigenvector?
               (int)(yysemantic_stack_[(16) - (11)].adouble),  // 2nd eigenvalue | eigenvector?
               (int)(yysemantic_stack_[(16) - (13)].adouble),  // 3rd eigenvalue | eigenvector?
               (int)(yysemantic_stack_[(16) - (15)].adouble)  // Gradient vector?
               );
        }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 4532 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage,mask);
          GET_VARSTACK_VAR_VAL(InrImage,varim,im);

          Func_Derivatives(im.get(),
               varim->Name().c_str(),
               (yysemantic_stack_[(18) - (5)].adouble),   // sigma
               (yysemantic_stack_[(18) - (7)].adouble),   // gamma
               mask.get(),  // mask
               (int)(yysemantic_stack_[(18) - (9)].adouble),   // 1st eigenvalue | eigenvector?
               (int)(yysemantic_stack_[(18) - (11)].adouble),   // 2nd eigenvalue | eigenvector?
               (int)(yysemantic_stack_[(18) - (13)].adouble),   // 3rd eigenvalue | eigenvector?
               (int)(yysemantic_stack_[(18) - (15)].adouble)   // Gradient vector?
               );
        }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 4550 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage,mask);
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);

          Func_HessianVap(im.get(),
              varim->Name().c_str(),
              (yysemantic_stack_[(12) - (5)].adouble),   // sigma
              (yysemantic_stack_[(12) - (7)].adouble),   // gamma
              mask.get(),
              (int) (yysemantic_stack_[(12) - (11)].adouble) // eigenvalue number
              );
        }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 4564 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          Func_Curvatures(im.get(), varim->Name().c_str(), (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 4575 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage,mask);
          Variable<InrImage>::ptr  varim6( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim5( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim4( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim3( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim2( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim1( driver.var_stack.GetLastVar<InrImage>());

          Func_Eigen3D(
               (char*) (yysemantic_stack_[(18) - (3)].astring),
               varim1 ->Pointer().get(),
               varim2 ->Pointer().get(),
               varim3 ->Pointer().get(),
               varim4 ->Pointer().get(),
               varim5 ->Pointer().get(),
               varim6 ->Pointer().get(),
               mask.get()  // mask
               );
        }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 4601 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {

          Variable<InrImage>::ptr  varim6( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim5( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim4( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim3( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim2( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim1( driver.var_stack.GetLastVar<InrImage>());

          Func_Eigen3D(
               (char*) (yysemantic_stack_[(16) - (3)].astring),
               varim1 ->Pointer().get(),
               varim2 ->Pointer().get(),
               varim3 ->Pointer().get(),
               varim4 ->Pointer().get(),
               varim5 ->Pointer().get(),
               varim6 ->Pointer().get(),
               NULL
               );
        }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 4627 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage,mask);
          Variable<InrImage>::ptr  varim3( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim2( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim1( driver.var_stack.GetLastVar<InrImage>());

          Func_Eigen2D(
               (char*) (yysemantic_stack_[(12) - (3)].astring),
               varim1 ->Pointer().get(),
               varim2 ->Pointer().get(),
               varim3 ->Pointer().get(),
               mask.get()  // mask
               );
        }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 4646 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<InrImage>::ptr  varim3( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim2( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim1( driver.var_stack.GetLastVar<InrImage>());
          Func_Eigen2D(
               (char*) (yysemantic_stack_[(10) - (3)].astring),
               varim1 ->Pointer().get(),
               varim2 ->Pointer().get(),
               varim3 ->Pointer().get(),
               NULL
               );
        }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 4660 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      im->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 4666 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      im->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 4672 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2( driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1( driver.var_stack.GetLastVar<InrImage>());
      InrImage::ptr im (varim2->Pointer());
      varim1->Pointer()->SetVoxelSize(
                                   im->VoxSizeX(),
                                   im->VoxSizeY(),
                                   im->VoxSizeZ());
    }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 4683 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      im->SetTranslation((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 4689 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2( driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1( driver.var_stack.GetLastVar<InrImage>());
      InrImage::ptr im (varim2->Pointer());
      varim1->Pointer()->SetVoxelSize( im->TrX(), im->TrY(), im->TrZ());
    }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 4697 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        (5) boolean, 0 little endianness, 1 big endianness

      Description:
        Forces the endianness of the image, usually before writting it to a file.
        If the endianness is different from the one of the architecture, the bytes
        are swapped before writting, and there are swapped back after.
    **/
      GET_VARSTACK_VALUE(InrImage, im);
      ((amimage*) (*(im)) )->SetEndianness((AMIENDIANNESS)(int)(yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 4712 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
      Func_DiscSecDerGrad(
        varim1->Pointer().get(),
        varim2->Pointer().get());
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 4721 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim3(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
      Func_DiscSecDerGrad(
                varim1->Pointer().get(),
                varim2->Pointer().get(),
                varim3->Pointer().get());
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 4732 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
        Description: dispatches the given number of events
      **/
      int nb_event;

      nb_event = 0;
      while (nb_event<(int)(yysemantic_stack_[(4) - (3)].adouble)) {
        if (GB_wxApp->Pending()) {
          GB_wxApp->Dispatch();
        }
        nb_event++;
      } // end while

    }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 4749 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
        Description: dispatch the given number of events
      **/
      int nb_event;

      nb_event = 0;
      while (nb_event<(int)(yysemantic_stack_[(4) - (3)].adouble)) {
        if (GB_wxApp->Pending()) {
          GB_wxApp->Dispatch();
        }
        nb_event++;
      } // end while

    }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 4765 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (3) IMAGE: 1D image to plot, where the voxel size in X is used,
            if 2D image, plot several functions, one per line
            (5) String: plot title
            (7) NUM: delay
        Description:
            Plots a 1D image using gnuplot.
        **/
      GET_VARSTACK_VALUE(InrImage, image);
      float* tabx;
      float* taby;
      GnuPlot   gnuplot;
      int x,num_courbe;
      std::string name;

      tabx = new float[image->_tx];
      taby = new float[image->_tx];

      for (int y=0; y<image->DimY(); y++) {
        Pour(x,0,image->_tx-1)
          tabx[x] = image->SpacePosX(x);
          taby[x] = (*image)(x,y,0);
          //cout << boost::format("%1%,%2% --> %3%")%x%y%taby[x] << endl;
        FinPour
        name =  (boost::format("%s_%02d")%(yysemantic_stack_[(8) - (5)].astring)%y).str();
        num_courbe = gnuplot.AddCourbe( image->_tx, tabx, taby, name.c_str());
      }

      name =  (boost::format("%s.gnuplot")%(yysemantic_stack_[(8) - (5)].astring)).str();
      gnuplot.XPlot(name.c_str(),(int)(yysemantic_stack_[(8) - (7)].adouble));

      delete [] tabx;
      delete [] taby;
      delete [] (yysemantic_stack_[(8) - (5)].astring);
    }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 4803 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      cerr << "Feature not available, needs to be updated ! " << endl;
      /*
            InrImage::ptr   image = *(InrImage::ptr*) $3->Pointer();
            Histogramme* histo;
      
            histo = new Histogramme(GB_main_window,"histo",
                        image.get(),
                        CREATE_TOPLEVEL_SHELL);
      */
      }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 4821 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (3)  IMAGE1: image to change
            (5)  IMAGE2: input image
            (7)  expression: step x
            (9)  expression: position x
            (11) expression: step y
            (13) expression: position y
            (15) expression: step z
            (17) expression: position z

        Description:
            Pads the output image (IMAGE1) using the input image (IMAGE2),
            starting from position (posx,posy,posz) in IMAGE1,
            tries to fill all the values of IMAGE2 with a voxel lattice of size
            (step x, step y, step z).
            Works for scalar or vectorial images, both images must be of the same
            type (scalar or vectorial).
        **/

            int step_x = (int) (yysemantic_stack_[(18) - (7)].adouble);
            int step_y = (int) (yysemantic_stack_[(18) - (11)].adouble);
            int step_z = (int) (yysemantic_stack_[(18) - (15)].adouble);
        int pos_x  = (int) (yysemantic_stack_[(18) - (9)].adouble);
        int pos_y  = (int) (yysemantic_stack_[(18) - (13)].adouble);
        int pos_z  = (int) (yysemantic_stack_[(18) - (17)].adouble);

      // pad the first image with the second one
      //
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());

      Func_Pad(
        varim1->Pointer().get(),
        varim2->Pointer().get(),
           step_x,step_y,step_z,
           pos_x,pos_y,pos_z);


        }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 4864 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));
      Func_GenRead(filename.get());
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 4870 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.InitCumul();
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 4875 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Debut();
    }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 4880 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Fin();
      cout << "time spent = " << driver.IP_time << endl;
    }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 4886 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          boost::shared_array<char> filename( (yysemantic_stack_[(6) - (5)].astring));
          GET_VARSTACK_VALUE(InrImage, i);
          Func_VectorImage2StructuredGrid(i.get(),filename.get());
        }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 4893 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(GLTransfMatrix, glmat);
          glmat->Print();
        }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 4899 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          boost::shared_array<char> filename( (yysemantic_stack_[(4) - (4)].astring));
          GET_VARSTACK_VALUE(GLTransfMatrix, glmat);
          Func_SaveTransform(glmat.get(),filename.get());
        }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 4906 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          AddWrapVTK();
        }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 4911 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          AddWrapWII();
        }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 4916 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          AddWrapFilters();
        }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 4927 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<InrImage>::ptr  varim7(driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim6(driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim5(driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim4(driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim3(driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());

          InrImage::ptr im1    (varim1->Pointer());
          InrImage::ptr im2    (varim2->Pointer());
          InrImage::ptr u      (varim3->Pointer());
          InrImage::ptr v      (varim4->Pointer());
          InrImage::ptr corr   (varim5->Pointer());
          InrImage::ptr conf_x (varim6->Pointer());
          InrImage::ptr conf_y (varim7->Pointer());
          int initx= (int) (yysemantic_stack_[(30) - (17)].adouble);
          int inity= (int) (yysemantic_stack_[(30) - (19)].adouble);
          int displx= (int) (yysemantic_stack_[(30) - (21)].adouble);
          int disply= (int) (yysemantic_stack_[(30) - (23)].adouble);
          int sizex= (int) (yysemantic_stack_[(30) - (25)].adouble);
          int sizey= (int) (yysemantic_stack_[(30) - (27)].adouble);
          int deform = (int) (yysemantic_stack_[(30) - (29)].adouble);
      
          amiOpticFlowCorrelation2D(
            im1.get(),
            im2.get(),
            u.get(),
            v.get(),
            corr.get(),
            conf_x.get(),
            conf_y.get(),
            initx,inity,
            displx,disply,sizex,sizey,deform);
        }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 4967 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage,v); // x component of the flow
        GET_VARSTACK_VALUE(InrImage,u); // y component of the flow
        GET_VARSTACK_VALUE(InrImage,im2);
        GET_VARSTACK_VALUE(InrImage,im1);
        float     sigma = (yysemantic_stack_[(24) - (7)].adouble);
        float     T     = (yysemantic_stack_[(24) - (9)].adouble);
        float     alpha = (yysemantic_stack_[(24) - (11)].adouble);
        long      dtype = (long) (yysemantic_stack_[(24) - (13)].adouble);      /* type of smoothness term */
        float     quantile = (yysemantic_stack_[(24) - (15)].adouble);          /* isotropy fraction */
        float     ht       = (yysemantic_stack_[(24) - (17)].adouble);          /* time step size */
        int       Niter    = (int)  (yysemantic_stack_[(24) - (23)].adouble);   /* Number of Iterations for Gauss-Seidel */

        amiOpticFlowVariational2D(
          im1.get(),
          im2.get(),
          sigma,T,alpha,dtype,quantile,ht,
          u.get(),
          v.get(),
          Niter);

        }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 5018 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (3) size of the 3D arrow basis (def: 0.05)
          (5) size of the 3D arrow head (def: 0.1)
          (7) position of the 3D arrow (def: 0.85)

        Description:
          Parameters for 3D arrows created by CreateVectors() when the vector style is 1.
          Each arrow is composed of 2 tetrahedra:
            - the basis size in proportion to the arrow size is given by the 1st parameter,
            - the head size by the 2nd parameter,
            - the lower position of the head along the arrow by the 3rd parameter.
        **/
          AMIFluid::Func_SetArrowParameters((float)(yysemantic_stack_[(8) - (3)].adouble),(float)(yysemantic_stack_[(8) - (5)].adouble),(float)(yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 5040 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = new std::list<std::string>();
            sl->push_back(string((yysemantic_stack_[(1) - (1)].astring)));
            delete [] (yysemantic_stack_[(1) - (1)].astring);
            (yyval.string_list) = sl;
        }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 5048 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = (yysemantic_stack_[(3) - (1)].string_list);
            sl->push_back(string((yysemantic_stack_[(3) - (3)].astring)));
            delete [] (yysemantic_stack_[(3) - (3)].astring);
            (yyval.string_list) = sl;
        }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 5064 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          (yyval.paramlist) = pl;
        }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 5069 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
          Description: temporary rule, added to simplify convertion of scripts.
         **/
          BasicVariable::ptr       var(driver.var_stack.GetLastBasicVar());
          if (!var.get()) {
            driver.error("Empty Variable as parameter !");
            YYABORT;
          }
          ParamList* pl = new ParamList();
          // Creating a new variable that points to the same value, and a slightly different name (with added "_ref"), comments are also copied.
          BasicVariable::ptr newvar(var->NewReference());
          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 5085 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
          Description: temporary rule, added to simplify convertion of scripts.
         **/
          BasicVariable::ptr       var(driver.var_stack.GetLastBasicVar());
          if (!var.get()) {
            driver.error("Empty Variable as parameter !");
            YYABORT;
          }
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);

          // Creating a new variable that points to the same value, and a slightly different name (with added "_ref"), comments are also copied.
          BasicVariable::ptr newvar(var->NewReference());

          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 5103 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr       var(driver.var_stack.GetLastBasicVar());
          if (!var.get()) {
            driver.error("Empty Variable as parameter !");
            YYABORT;
          }

          ParamList* pl = new ParamList();

          // Creating a new variable that points to the same value, and a slightly different name (with added "_ref"), comments are also copied.
          BasicVariable::ptr newvar(var->NewReference());

          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 5119 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr       var(driver.var_stack.GetLastBasicVar());
          if (!var.get()) {
            driver.error("Empty Variable as parameter !");
            YYABORT;
          }
          ParamList* pl =  (yysemantic_stack_[(4) - (1)].paramlist);

          // Creating a new variable that points to the same value, and a slightly different name (with added "_ref"), comments are also copied.
          BasicVariable::ptr newvar(var->NewReference());

          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 5134 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          /**
            Description: it is now a new reference to the variable, so basically similar to &variable (should be removed?)...
          **/
          BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
          if (!var.get()) {
            driver.error("Empty Variable as parameter !");
            YYABORT;
          }
          ParamList* pl(new ParamList);
          BasicVariable::ptr newvar(var->NewCopy());
          newvar->Rename("Param0");
          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 5150 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          /**
            Description: it is now a new reference to the variable, so basically similar to &variable (should be removed?)...
          **/
          BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
          if (!var.get()) {
            driver.error("Empty Variable as parameter !");
            YYABORT;
          }
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);
          std::string paramname = (boost::format("Param%1%")%pl->GetNumParam()).str();
          BasicVariable::ptr newvar(var->NewCopy());
          newvar->Rename(paramname.c_str());
          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 5169 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      //      printf("no parameters \n");
      ParamListDecl* pl = new ParamListDecl;
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 5175 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      cout << "param_list_decl: T_NUM IDENTIFIER" << endl;
      cout << ident->GetName().c_str() << endl;
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_float);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 5184 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_ami_object);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 5191 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_string);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 5198 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_image);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 5205 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 5221 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_ami_object);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 5228 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_float);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 5235 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_string);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 5242 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_image);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 5249 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 5267 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
    }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 5272 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      char* res;
      //printf("expr_string=%s*\n",$3);
      //printf("expr=%f*\n",$5);
      res = new char[strlen((yysemantic_stack_[(6) - (3)].astring))+20];
      sprintf(res,(yysemantic_stack_[(6) - (3)].astring),(yysemantic_stack_[(6) - (5)].adouble));
      //          res[strlen($3)]=0;
      delete [] (yysemantic_stack_[(6) - (3)].astring);
      //printf("res=%s*\n",res);
      (yyval.astring)=res;
    }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 5353 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      long min,hour;
      float sec;

      driver.IP_time.Fin();
      driver.IP_time.AddCumul();
      driver.IP_time.GetCumul(hour,min,sec);
      std::string res;
      if (hour>0) {
        res = (boost::format("%3d h %2d min %2d sec")%(int)hour
                        %(int)min %(int)sec).str();
      } else
        res = (boost::format("%2d min %2d sec")
                        %(int)min %(int)sec).str();
        if (min>0) {
        } else
          res = (boost::format("%2.2f sec") %sec).str();

      char* reschar = new char[res.size()+1];
      strcpy(reschar,res.c_str());
      (yyval.astring)= reschar;
    }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 5376 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      (yyval.astring)=(char*) (im)->GetName();
    }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 5382 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Description:
        Returns the name of the variable as a string
    **/
      BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
      char* resstr = (char*) var->Name().c_str();
      char* res = new char[strlen(resstr)+1];
      strcpy(res,resstr);
      (yyval.astring)= res;
    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 5394 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Description:
        Returns the name of the object instance to which this variable belongs. If this variable does not belong to an object, returns an empty string.
    **/
      BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
      boost::shared_ptr<Variables> context = var->GetContext();
      if (context.get()) {
        char* res = new char[strlen(context->GetName().c_str())+1];
        strcpy(res,context->GetName().c_str());
        (yyval.astring)= res;
      } else {
        char* empty_string;
        empty_string = new char[1];
        empty_string[0] = '\0';
        (yyval.astring) = empty_string;
      }
    }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 5414 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      char* res = new char[GB_scripts_dir.Len()+1];
      strcpy(res,(const char*)GB_scripts_dir.mb_str(wxConvUTF8));
      (yyval.astring)= res;
    }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 5447 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        (yyval.ablock)=(yysemantic_stack_[(3) - (2)].ablock);
        if (GB_debug)
          cerr << format("ablock : %s")
                  % (yysemantic_stack_[(3) - (2)].ablock)->GetBody()
                << endl;
          }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 5462 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      ADD_VARSTACK_FLOAT((yysemantic_stack_[(1) - (1)].adouble))
    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 5466 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      returns the number of arguments in the command line
    **/
      ADD_VARSTACK_FLOAT(GB_argc-GB_num_arg_parsed)
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 5474 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      Line number in the current script
    **/
      ADD_VARSTACK_FLOAT(driver.yyiplineno)
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 5482 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        the constant Pi is set to
         3.14159265358979323846
      **/
      ADD_VARSTACK_FLOAT(3.14159265358979323846)
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 5491 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
        (1) input_image
        (3) x
        (5) y

        Description:
        returns the image value at pixel (x,y,z=0) by default

        return:
        float variable
        **/
      GET_VARSTACK_VALUE(InrImage, im);
      ADD_VARSTACK_FLOAT((*im)((int) (yysemantic_stack_[(6) - (3)].adouble),(int) ( (yysemantic_stack_[(6) - (5)].adouble))));
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 5508 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
        Parameters:
          - input image variable
          - pixel position x,y,z
        Description:
          returns the pixel intensity at the given position
          the position value are rounded to the closest integer
      **/
      GET_VARSTACK_VALUE(InrImage, im);
      float val=(*im)((int) round((yysemantic_stack_[(8) - (3)].adouble)),
          (int) round( (yysemantic_stack_[(8) - (5)].adouble)), 
          (int) round((yysemantic_stack_[(8) - (7)].adouble)));
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 5524 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
        Parameters:
          - input image variable
          - pixel position x,y,z
        Description:
          returns the pixel intensity at the given position
          the position using linear interpolation
      **/
      GET_VARSTACK_VALUE(InrImage, im);
      float val=im->InterpLinIntensite(
          (yysemantic_stack_[(10) - (5)].adouble),
          (yysemantic_stack_[(10) - (7)].adouble), 
          (yysemantic_stack_[(10) - (9)].adouble));
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 5541 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
      get image component value at a given 3D voxel position.
      same as image(expr,expr,expr;expr)
      **/
      GET_VARSTACK_VALUE(InrImage, im);
      float val = 0;
      Si im->CoordOK((int) (yysemantic_stack_[(10) - (3)].adouble), (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble))
          Et ((int) (yysemantic_stack_[(10) - (9)].adouble) >=0) Et ((int)(yysemantic_stack_[(10) - (9)].adouble) <im->GetVDim()) Alors

        val=(*im)((int) (yysemantic_stack_[(10) - (3)].adouble),(int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble),
                    (int) (yysemantic_stack_[(10) - (9)].adouble) );
      Sinon
        driver.err_print("var_image(expr,expr,expr,expr) \t err coord \n");
      FinSi
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 5560 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
      get image component value at a given 3D voxel position.
      **/
      GET_VARSTACK_VALUE(InrImage, im);
      float val = 0;
      Si im->CoordOK((int) (yysemantic_stack_[(10) - (3)].adouble), (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble))
          Et ((int) (yysemantic_stack_[(10) - (9)].adouble) >=0) Et ((int)(yysemantic_stack_[(10) - (9)].adouble) <im->GetVDim()) Alors

        val=(*im)((int) (yysemantic_stack_[(10) - (3)].adouble),(int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble),
                      (int) (yysemantic_stack_[(10) - (9)].adouble) );
      Sinon
        driver.err_print("var_image(expr,expr,expr;expr) \t err coord \n");
      FinSi
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 5578 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
      get image component value at a given 2D  position. ( z component set to 0)
      **/
      GET_VARSTACK_VALUE(InrImage, im);
      float val = 0;
      Si (im->CoordOK((int) (yysemantic_stack_[(8) - (3)].adouble),   (int (yysemantic_stack_[(8) - (5)].adouble)),   0  )
        Et ((int) (yysemantic_stack_[(8) - (7)].adouble) >=0) Et ((int)(yysemantic_stack_[(8) - (7)].adouble) <im->GetVDim())) Alors
        val=(*im)((int) (yysemantic_stack_[(8) - (3)].adouble),(int) (yysemantic_stack_[(8) - (5)].adouble),0, (int) (yysemantic_stack_[(8) - (7)].adouble) );
      Sinon
        driver.err_print("var_image(expr,expr;expr) \t err coord \n");
      FinSi
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 5594 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
      get image component value at a given 1D  position. (y and z components set to 0)
      **/
      GET_VARSTACK_VALUE(InrImage, im);
      float val = 0;
      Si im->CoordOK((int) (yysemantic_stack_[(6) - (3)].adouble),   0,   0  )
        Et ((int) (yysemantic_stack_[(6) - (5)].adouble) >=0) Et ((int)(yysemantic_stack_[(6) - (5)].adouble) <3) Alors
        val=(*im)((int) (yysemantic_stack_[(6) - (3)].adouble),0,0, (int) (yysemantic_stack_[(6) - (5)].adouble) );
      Sinon
        driver.err_print("var_image(expr;expr) \t err coord \n");
      FinSi
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 5610 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->DimX();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 5616 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->DimY();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 5622 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->DimZ();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 5628 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->TrX();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 5634 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->TrY();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 5640 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->TrZ();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 5646 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->VoxSizeX();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 5652 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->VoxSizeY();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 5658 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->VoxSizeZ();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 5664 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->GetVDim();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 5670 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->IncBuffer();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 5676 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->ValeurBuffer();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 5683 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
      float val=Func_SNR(varim1->Pointer().get(),
                  varim2->Pointer().get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 5692 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      float val=Func_eccentricity(im.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 5699 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      float   resolution = (yysemantic_stack_[(10) - (5)].adouble);
      int     cx = (int) (yysemantic_stack_[(10) - (7)].adouble);
      int     cy = (int) (yysemantic_stack_[(10) - (9)].adouble);
      float    surf_inf[1];
      float    surf_sup[1];
      float    surf_interp[1];
      Point3D point;
      Vect3D<float> v1,v2;
      CalculAireSection* compute_area;

      GET_VARSTACK_VALUE(InrImage, im);

      compute_area = new CalculAireSection( im.get(),
                    resolution);
      compute_area->InitImagesSurf((InrImage*) NULL, (InrImage*) NULL,
                       (InrImage*) NULL, (InrImage*) NULL);
      surf_inf[0]  = surf_sup[0] = surf_interp[0] = 0.0;
      v1.Init( 1.0, 0.0, 0.0);
      v2.Init( 0.0, 1.0, 0.0);
      point.Init( cx,cy,0);

      float val=compute_area->Aire( 0, point, v1, v2,
                  surf_inf, surf_sup, surf_interp);

      ADD_VARSTACK_FLOAT(val);
      delete compute_area;

    }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 5730 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(InrImage, im);
      float val=Func_ComputePositiveArea( im.get() );
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 5738 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      float val[4];

      val[0] = (yysemantic_stack_[(10) - (3)].adouble);
      val[1] = (yysemantic_stack_[(10) - (5)].adouble);
      val[2] = (yysemantic_stack_[(10) - (7)].adouble);
      val[3] = (yysemantic_stack_[(10) - (9)].adouble);
      float res=Func_PositiveArea(val);
      ADD_VARSTACK_FLOAT(res);
    }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 5750 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
          Description:
          returns the of pixels (or voxels) with intensity higher than 0.5

          Parameters:
            (3) image expression

        Keywords:

        See also:
            max, mean, min, median

    **/
      GET_VARSTACK_VALUE(InrImage,im);
      float val=Func_count( im.get() );
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 5770 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
             Description:
             returns the average value of an image

             Parameters:
               (3) image expression

            Keywords:

            See also:
                min, max, median

        **/
      GET_VARSTACK_VALUE(InrImage,im);
      float val=Func_mean( im.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 5790 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
             Description: 
             returns the maximal value of an image

             Parameters:
               (3) image variable

            Keywords:

            See also:
                min, mean, median

        **/
      GET_VARSTACK_VALUE(InrImage,im);
      float val=Func_max( im.get(),NULL);
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 5810 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
             Description:
             returns the position of the maximal value of an image, the 3D position is returned as a single integer value of the position of the vector of the image intensity, where the voxels are ordered in X first,Y second and Z.

             Parameters:
               (3) image expression

            Keywords:

            See also:
                min, mean, median, max

        **/
      GET_VARSTACK_VALUE(InrImage,im);
      float val=Func_argmax( im.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 5830 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
            Description:
            returns the minimal value of an image

            Parameters:
              (3) image variable

          Keywords:

          See also:
              max, mean, median

      **/
      GET_VARSTACK_VALUE(InrImage,im);
      float val=Func_min( im.get(),NULL);
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 5850 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
            Description:
            returns the median value of an image

            Parameters:
              (3) image expression

          Keywords:

          See also:
              min, max, mean, count

      **/
      GET_VARSTACK_VALUE(InrImage,im);
      float val=Func_med( im.get(),0.5,NULL);
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 5870 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
             Description:
             returns the maximal value of an image in a region of
             interest defined by pixels (or voxels) of intensity
             higher than 0.5 in the image between []

             Parameters:
               (3) image expression: mask
               (5) image expression: input

            Keywords:

            See also:
                min, max, mean, median, count

        **/
      GET_VARSTACK_VALUE(InrImage,im);
      GET_VARSTACK_VALUE(InrImage,mask);
      float val=Func_max( im.get(),mask.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 5894 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
             Description:
             returns the minimal value of an image in a region of
             interest defined by pixels (or voxels) of intensity
             higher than 0.5 in the image between []

             Parameters:
               (3) image expression
               (5) image variable

            Keywords:

            See also:
                min, max, mean, median, count

        **/
      GET_VARSTACK_VALUE(InrImage, im);
      GET_VARSTACK_VALUE(InrImage,mask);
      float val=Func_min( im.get(),mask.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 5918 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
             Description:
             returns the median value of an image in a region of
             interest defined by pixels (or voxels) of intensity
             higher than 0.5 in the image between []

             Parameters:
               (3) image expression
               (5) image variable

            Keywords:

            See also:
                min, max, mean, median, count

        **/
      GET_VARSTACK_VALUE(InrImage, im);
      GET_VARSTACK_VALUE(InrImage,mask);
      float val=Func_med( im.get(),0.5,mask.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 5942 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      GET_VARSTACK_VALUE(InrImage, mask);
      float val=Func_med( im.get(),(float) (yysemantic_stack_[(9) - (8)].adouble),mask.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 5950 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
             Description:
             returns the average value of an image in a region of
             interest defined by pixels (or voxels) of intensity
             higher than 0.5 in the image between []

             Parameters:
               (3) image expression: defines the Region of Interest
               (5) image expression: image from which to compute the mean intensity value.

            Keywords:

            See also:
                min, max, mean, median, count

        **/
      GET_VARSTACK_VALUE(InrImage,input);
      GET_VARSTACK_VALUE(InrImage,mask);
      float val=Func_mean( input.get(),mask.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 5974 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
             Description:
             returns the maximal value of an image in a region of
             interest

             Parameters:
               (3) image variable
               (5) image expression: the pixels (or voxels) higher than 0.5
               define the Region of Interest

            Keywords:

            See also:
                min, max, mean, median, count

        **/
      GET_VARSTACK_VALUE(InrImage,mask);
      GET_VARSTACK_VALUE(InrImage, im);
      float val=Func_mean( im.get(), mask.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 5997 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      setlocale(LC_NUMERIC, "C");
      float val=atof((yysemantic_stack_[(4) - (3)].astring));
      ADD_VARSTACK_FLOAT(val);
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 6005 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = DessinImage::ptr(varimd->Pointer());
      param = draw->GetParam();
      float val=param->_Zoom._xmin;
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 6017 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = DessinImage::ptr(varimd->Pointer());
      param = draw->GetParam();
      float val=param->_Zoom._xmax;
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 6029 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = DessinImage::ptr(varimd->Pointer());
      param = draw->GetParam();
      float val=param->_Zoom._ymin;
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 6041 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = DessinImage::ptr(varimd->Pointer());
      param = draw->GetParam();
      float val=param->_Zoom._ymax;
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 6053 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = DessinImage::ptr(varimd->Pointer());
      param = draw->GetParam();
      float val=param->_Zoom._zmin;
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 6065 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = DessinImage::ptr(varimd->Pointer());
      param = draw->GetParam();
      float val=param->_Zoom._zmax;
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 6077 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw;
      DessinImageParametres* param;
      string comment;
      draw = DessinImage::ptr(varimd->Pointer());
      param = draw->GetParam();
      float val=param->_pos._x;
      ADD_VARSTACK_FLOAT(val);
      comment = str(format(" //  xpos=%3d") % param->_pos._x);
      if (driver.InConsole())
        GB_main_wxFrame->GetConsole()
                        ->IncCommand(wxString::FromAscii(comment.c_str()));
    }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 6093 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw;
      DessinImageParametres* param;
      string comment;

      draw = DessinImage::ptr(varimd->Pointer());
      param = draw->GetParam();
      float val=param->_pos._y;
      ADD_VARSTACK_FLOAT(val);

      comment = str( format(" //  ypos=%3d") % param->_pos._y);
      if (driver.InConsole())
        GB_main_wxFrame->GetConsole()
                       ->IncCommand(wxString::FromAscii(comment.c_str()));

    }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 6112 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw;
      DessinImageParametres* param;
      string comment;

      draw = DessinImage::ptr(varimd->Pointer());
      param = draw->GetParam();
      float val=param->_pos._z;
      ADD_VARSTACK_FLOAT(val);

      comment = str( format(" //  xpos=%3d") % param->_pos._z);
      if (driver.InConsole())
        GB_main_wxFrame->GetConsole()
                        ->IncCommand(wxString::FromAscii(comment.c_str()));
    }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 6153 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<FloatMatrix>::ptr varmat(driver.var_stack.GetLastVar<FloatMatrix>());
      FloatMatrix::ptr mat (varmat->Pointer());
      int i = (int)(yysemantic_stack_[(6) - (3)].adouble);
      int j = (int)(yysemantic_stack_[(6) - (5)].adouble);
      float val = (*mat)[i][j];
      // create a reference with a smart pointer without deleter ???
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 6163 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
        Description
      **/
      Variable<FloatMatrix>::ptr varmat(driver.var_stack.GetLastVar<FloatMatrix>());
      FloatMatrix::ptr mat (varmat->Pointer());
      int i = (int)(yysemantic_stack_[(10) - (5)].adouble);
      int j = (int)(yysemantic_stack_[(10) - (7)].adouble);
      float val  =  ((*mat)[i][j] = (yysemantic_stack_[(10) - (9)].adouble));
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 6175 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
    Check for the existence of a variable, returns 0
    **/
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (3)].ident));
      float val=0;
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 6185 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
    Description: 
    Check for the existence of a variable, returns 1
    **/
      BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
      float val=1;
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 6195 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      string: input filename
    Description:
      Check for the existence of the given filename
    **/
      boost::shared_array<char> name( (yysemantic_stack_[(4) - (3)].astring));
      float val = wxFileExists(wxString(name.get(),wxConvUTF8));
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 6207 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
        Description: returns the value of the pixel format type in float format
      **/
      float val = (int) (yysemantic_stack_[(3) - (1)].aint);
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 6215 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Description:
        Scans a float number in the given file and based on the
        given formatting expression.
    **/
      float res;
      GET_VARSTACK_VALUE(FILE,file);
      boost::shared_array<char> format( (yysemantic_stack_[(6) - (5)].astring));

      setlocale(LC_NUMERIC, "C");
      fscanf(file.get(),format.get(),&res);
      float val =  res;
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 6231 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(float,val_ptr);
      if (!val_ptr.get()) {
        driver.err_print("needs float variable");
        YYABORT;
      }
      GET_VARSTACK_VALUE(FILE,file);

      float*  var = val_ptr.get();
      setlocale(LC_NUMERIC, "C");
      float val = 0;
      if (var!=NULL) {
        val = fscanf(file.get(),"%f",var);
      } else {
        // TODO: error message here ...
      }
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 6250 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(std::string,st);
      GET_VARSTACK_VALUE(FILE,file);
      setlocale(LC_NUMERIC, "C");
      // not safe, TODO: use iostream or boost for files here ...
      char res[100];
      float val = fscanf(file.get(),"%s",res);
      //string_ptr var( new std::string(res));
      (*st) = res;
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 6280 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
          if (var.get())
            if (var->IsNumeric())
              (yyval.adouble)=var->GetValueAsDouble();
            else {
              (yyval.adouble)=var->GetValueAsDouble();
              driver.err_print("Numerical expression from non-numerical variable expression (check for recent changes like i[j] where i and j are images should now be rewritten as i[j.GetExtent] )...");
              YYABORT;
            }
          else {
            driver.err_print("Expression from null variable ...");
            (yyval.adouble) = 0;
          }
        }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 6298 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
          if (var->Type()==type_image)  {
            driver.var_stack.AddVar(var);
          } else {
            driver.err_print("Expecting an image variable here ... \n");
            YYABORT;
          }
        }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 6310 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          /**
            Description:  This rule is created to avoid changing a lot of code in the process of converting string operation to operations on Variable\<std::string> ...
          **/
          BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
          if (var->Type()==type_string)  {
            DYNAMIC_CAST_VARIABLE(std::string,var,varstr) 
            char* res;
            res = new char[varstr->Value().length()+1];
            strcpy(res,varstr->Value().c_str());
            (yyval.astring)= res;
          } else {
            driver.err_print("Expecting a string variable here ... \n");
            YYABORT;
          }
        }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 6331 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      driver.err_print(" char format is not available: use unsigned char \n");
      (yyval.aint)=WT_UNSIGNED_CHAR;
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 6336 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          (yyval.aint)=WT_UNSIGNED_CHAR;
       }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 6340 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_SHORT;
       }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 6344 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_SHORT;
       }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 6348 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_INT;
       }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 6352 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_INT;
       }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 6356 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_LONG;
       }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 6360 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT;
       }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 6364 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_DOUBLE;
       }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 6368 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_RGB;
       }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 6372 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT_VECTOR;
       }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 6376 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
         //        printf("format %d \n",(int) ( *(InrImage::ptr*) $1->Pointer())->GetFormat());
        GET_VARSTACK_VALUE(InrImage, im);
        (yyval.aint) = (int) im->GetFormat();
      }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 6386 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          // TODO: get rid of VAR_ARRAY ...
          GET_VARSTACK_VAR_VAL(VarArray,var,array);
          int  i = (int) (yysemantic_stack_[(4) - (3)].adouble);

          BasicVariable::ptr arrayvar = array->GetVar(i);
          if (!array.get()) {
            // create a small image to avoid problems
            InrImage::ptr im (new InrImage(1,1,1,WT_UNSIGNED_CHAR));
            string name = str(format("%s[%d]") % var->Name() % i);
            array->InitElement<InrImage>( i, im, name.c_str());
          }
          driver.var_stack.AddVar(array->GetVar(i));
          //$$=array->GetVar(i).get();
        }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 6407 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        boost::shared_array<char> st( (yysemantic_stack_[(2) - (2)].astring));
        InrImage* res = ReadImage(st.get());
        if (!res) YYABORT;
        else
          ADD_VARSTACK(InrImage,res);
      }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 6415 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
       /**
       Parameters:
        (3) STRING EXPRESSION: dicom directory

       Description:
         Reads a dicom file using VTK
       **/
        InrImage::ptr  res;
        boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));

        res = InrImage::ptr(Func_vtkDicomRead( filename.get()));

        Si (!res.get()) Alors
            driver.err_print("vtkDicomRead() error ... \n");
        FinSi

        ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 6435 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
      Parameters:
      (3) STRING EXPRESSION: filename in minc format

      Description:
        Reads a file in minc format using vtk reader for MINC.
      **/
        boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));

        InrImage::ptr res(Func_vtkMINCRead( filename.get()));

        Si (!res.get()) Alors
            driver.err_print("vtkMINCRead() error ... \n");
        FinSi

        ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 6470 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          int res;
          string name;
          string inc_cmd; // increment the command line string

          res=AskImage(name);
          if (!res) {
            driver.yyiperror(" Need Image \n");
            YYABORT;
          }
          InrImage* res1 = ReadImage((char*)name.c_str()); 
          if (!res1) YYABORT;
          else
            ADD_VARSTACK(InrImage,res1);

          wxFileName filename(GetwxStr(name));
          filename.Normalize(wxPATH_NORM_ALL,wxEmptyString,wxPATH_UNIX);
          wxString newname(   filename.GetVolume()+filename.GetVolumeSeparator()+
                              filename.GetPath(wxPATH_GET_VOLUME,wxPATH_UNIX)+
                              filename.GetPathSeparator(wxPATH_UNIX)+
                              filename.GetFullName());
          driver.res_print(newname.mb_str());
          driver.res_print("\n");
          inc_cmd = str(format(" \"%1%\" // from browser ") % newname.mb_str());

          if (driver.InConsole())
            GB_main_wxFrame->GetConsole()
                            ->IncCommand(wxString::FromAscii(inc_cmd.c_str()));
      }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 6501 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        //printf(" ********** %d %f %f %f\n", $3, $5, $7, $9);
        InrImage::ptr im (new InrImage( (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble), (WORDTYPE) (yysemantic_stack_[(10) - (3)].aint)));
        ADD_VARSTACK_PTR(InrImage,im);
      }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 6508 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
    Parameters:
      (3)  image type
      (5)  dimension in X
      (7)  dimension in Y
      (9)  dimension in Z
      (11) dimension in V: size of the vectors

    Description:
      Creates a new image
      **/
    //printf(" ********** %d %f %f %f\n", $3, $5, $7, $9);
    InrImage::ptr im( new InrImage( (int) (yysemantic_stack_[(12) - (5)].adouble), (int) (yysemantic_stack_[(12) - (7)].adouble), (int) (yysemantic_stack_[(12) - (9)].adouble), (int) (yysemantic_stack_[(12) - (11)].adouble), (WORDTYPE) (yysemantic_stack_[(12) - (3)].aint)));
    ADD_VARSTACK_PTR(InrImage,im);
    }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 6526 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3) image type
      (5) dimension in V: size of the vectors
      (7) reference image variable for the size,
            translation and voxel size.

    Description:
      Creates a new image from a reference image
    **/
      GET_VARSTACK_VAR_VAL(InrImage,var,varim);
      WORDTYPE imformat = (WORDTYPE) (yysemantic_stack_[(8) - (3)].aint);
      int vdim   = (int) (yysemantic_stack_[(8) - (5)].adouble);
      string  imname;

      imname = str(format("newimagefrom_%s.ami.gz")
                  % var->Name());

      InrImage::ptr im (new InrImage(imformat,vdim,
                        imname.c_str(),varim.get()));
      ADD_VARSTACK_PTR(InrImage,im);
    }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 6617 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
             Description:
             returns the sum of the values of an image along the specified dimension
             0 for X, 1 for Y, 2 for Z

             Parameters:
               (3) image expression
               (5) expr

            Keywords:

            See also:
                min, max, median

        **/
          GET_VARSTACK_VALUE(InrImage,im);
          InrImage* res = NULL;
          int dim = (int) (yysemantic_stack_[(6) - (5)].adouble);
          int i,j,k;
          double sum;
          // check that the image is scalar
          if (im->ScalarFormat()) {
          switch (dim) {
            case 0:
              res = new InrImage(1,im->DimY(),im->DimZ(),1,WT_FLOAT,"sumX.ami.gz");
              for(j=0;j<=im->DimY()-1;j++)
              for(k=0;k<=im->DimZ()-1;k++) {
                sum=0;
                for(i=0;i<=im->DimX()-1;i++)
                sum += (*im)(i,j,k);
                res->BufferPos(0,j,k);
                res->FixeValeur(sum);
              }
            break;
            case 1:
              res = new InrImage(im->DimX(),1,im->DimZ(),1,WT_FLOAT,"sumY.ami.gz");
              for(i=0;i<=im->DimX()-1;i++)
              for(k=0;k<=im->DimZ()-1;k++) {
                sum=0;
                for(j=0;j<=im->DimY()-1;j++)
                sum += (*im)(i,j,k);
                res->BufferPos(i,0,k);
                res->FixeValeur(sum);
              }
            break;
            case 2:
              res = new InrImage(im->DimX(),im->DimY(),1,1,WT_FLOAT,"sumZ.ami.gz");
              for(i=0;i<=im->DimX()-1;i++)
              for(j=0;j<=im->DimY()-1;j++) {
                sum=0;
                for(k=0;k<=im->DimZ()-1;k++)
          sum += (*im)(i,j,k);
                res->BufferPos(i,j,0);
                res->FixeValeur(sum);
              }
            break;
        } // end switch
      } else
      {
        driver.err_print("sum operator only for scalar images ... \n");
    }
      ADD_VARSTACK(InrImage,res);
    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 6683 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      InrImage* res =Func_localmean( im.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      ADD_VARSTACK(InrImage,res);
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 6690 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      InrImage* res =Func_localmean2( im.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      ADD_VARSTACK(InrImage,res);
    }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 6697 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, mean);
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage* res     = Func_localSD( im.get(), mean.get(), (int) (yysemantic_stack_[(8) - (7)].adouble));
      ADD_VARSTACK(InrImage,res);
    }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 6705 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, mean);
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res(Func_localSD2( im.get(), mean.get(), (int) (yysemantic_stack_[(8) - (7)].adouble)));
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 6713 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res (Func_OpImage(im.get(),
                NULL,
                NULL,
                (yysemantic_stack_[(6) - (5)].astring)));
      Si (!res.get()) Alors
        driver.err_print("OpImage() erreur ... \n");
      FinSi
  
      ADD_VARSTACK_PTR(InrImage,res);

      }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 6729 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res( Func_OpImage(im.get(),
              NULL,
              NULL,
              (yysemantic_stack_[(8) - (5)].astring),
              (WORDTYPE) (yysemantic_stack_[(8) - (7)].aint)));
    Si (!res.get()) Alors
      driver.err_print("OpImage() erreur ... \n");
    FinSi

    ADD_VARSTACK_PTR(InrImage,res);


      }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 6747 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {

      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
    InrImage::ptr res ( Func_OpImage(
              varim1->Pointer().get(),
              varim2->Pointer().get(),
              NULL,
              (yysemantic_stack_[(8) - (7)].astring)));
    Si (!res.get()) Alors
      driver.err_print("OpImage() erreur ... \n");
    FinSi

    ADD_VARSTACK_PTR(InrImage,res);

      }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 6765 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_OpImage(im.get(),
              im.get(),
              NULL,
              (yysemantic_stack_[(10) - (7)].astring),
              (yysemantic_stack_[(10) - (9)].aint)));
    Si (!res.get()) Alors
      driver.err_print("OpImage() erreur ... \n");
    FinSi

    ADD_VARSTACK_PTR(InrImage,res);

      }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 6782 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim3(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
        InrImage::ptr  res ( Func_OpImage(
            varim1->Pointer().get(),
            varim2->Pointer().get(),
            varim3->Pointer().get(),
              (yysemantic_stack_[(10) - (9)].astring)));
        Si (!res.get()) Alors
          driver.err_print("OpImage() erreur ... \n");
        FinSi

        ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 6800 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim3(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
        InrImage::ptr res (Func_OpImage(
            varim1->Pointer().get(),
            varim2->Pointer().get(),
            varim3->Pointer().get(),
              (yysemantic_stack_[(12) - (9)].astring),
              (yysemantic_stack_[(12) - (11)].aint)));
        Si (!res.get()) Alors
          driver.err_print("OpImage() erreur ... \n");
        FinSi
        ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 6820 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
        Parameters
          #1 expr_image: input image for the filter
          #2 expr:     standard deviation of the Gaussian kernel
          #3 expr:     derivation order in X coordinates
          #4 expr:     derivation order in Y coordinates
          #5 expr:     derivation order in Z coordinates

        Description:
        Apply a Gaussian filter of specified standard deviation to
        input image and returns a new image.

        Example(s):
        - Convolution with a Gaussian kernel:
        i = Image(FLOAT,10,10,10)
        j = filter(i,1,0,0,0)

     **/
        GET_VARSTACK_VALUE(InrImage,im);

        InrImage::ptr res( Func_Filter( im.get(),
                  (yysemantic_stack_[(12) - (5)].adouble),
                  (int) (yysemantic_stack_[(12) - (7)].adouble),
                  (int) (yysemantic_stack_[(12) - (9)].adouble),
                  (int) (yysemantic_stack_[(12) - (11)].adouble)));

        Si (!res.get()) Alors
          driver.err_print("Filter() erreur ... \n");
        FinSi
        ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 6853 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        float var           = (yysemantic_stack_[(10) - (7)].adouble);
        float lowthreshold  = (yysemantic_stack_[(10) - (9)].adouble);
        //float highthreshold = $11;
        GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_itkCannyEdgeDetector(  im.get(), var, lowthreshold));
        Si (!res.get()) Alors
          driver.err_print("itk.CannyEdgeDetector() error ... \n");
        FinSi
        ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 6866 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkDist( im.get()));

        Si (!res.get()) Alors
          driver.err_print("vtkDist() erreur ... \n");
        FinSi
        ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 6877 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res (Func_vtkMedianFilter3D(
            im.get(),
            (int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble)));

        Si (!res.get()) Alors
          driver.err_print("vtkMedian3D() erreur ... \n");
        FinSi
        ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 6890 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage, im);
        driver.err_print("The function AndreDist() has been removed for licence issues! \n");
/*
        InrImage::ptr  in = *(InrImage::ptr*) $3->Pointer();
        InrImage*  res;
        int ok;

        res = new InrImage(WT_FLOAT,"AndreDist.ami.gz", in.get());

        ok = dist_squared( in.get(),res);

        Si !ok Alors
          sprintf(tmp_string,"AndreDist() erreur ... \n");
          driver.err_print(tmp_string);
          delete res;
          res=NULL;
        Sinon
          ADD_VARSTACK_PTR(InrImage,res);
        FinSi
*/
    }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 6914 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, input);
        InrImage::ptr res (Func_2DFlux(input.get(),(yysemantic_stack_[(6) - (5)].adouble)));

      Si (res.get()) Alors
        driver.err_print("2DFlux() error ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 6925 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_OutFlux( im.get()));

      Si (!res.get()) Alors
        driver.err_print("OutFlux() erreur ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 6936 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_OutFluxScalar( im.get()));
    Si (!res.get()) Alors
      driver.err_print("OutFluxScalar() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 6946 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_OrientationRatio2D( im.get()));
    Si (!res.get()) Alors
      driver.err_print("OrientationRatio() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 6956 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
        Parameters:
          (3) IMAGE: input image
          (5) IMAGE: criterion for thinning
          (7) NUM: minimal threshold
          (9) NUM: maximal threshold
          (11) NUM: endpoint type 1: line 2: surface 3: line&surface
        Description:
          Creates a skeleton of the input image,
          the input image is considered binary (positive or 0 values)
          The skeletonization uses simple points.
          Usually the criterion image is an Euclidean distance
          transform to the boundaries of the object, and we
          can set than any point at distance lower than the minimal
          threshold shoud be removed automatically and any point
          at distance higher than the maximum should be kept.
      **/
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
    InrImage::ptr res ( Func_Thinning( varim1->Pointer().get(),
                 varim2->Pointer().get(),
                 (yysemantic_stack_[(12) - (7)].adouble),
                 (yysemantic_stack_[(12) - (9)].adouble),
                 (yysemantic_stack_[(12) - (11)].adouble)));

    Si (!res.get()) Alors
      driver.err_print("Skeleton() error ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 6989 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_SimplePoints( im.get() ));

    Si !res.get() Alors
      driver.err_print("SimplePoints() error ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 7001 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim4(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim3(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
        InrImage::ptr res ( Func_CircleIntegration(
          varim1 ->Pointer().get(), // gradient
          varim2 ->Pointer().get(),  // first  vector
          varim3 ->Pointer().get(),  // second vector
          (float)     (yysemantic_stack_[(12) - (9)].adouble),              // radius
          CIRCLE_RESPONSE_MEAN,          // integration type
          varim4->Pointer().get())); // mask

        Si !res.get() Alors
          driver.err_print("CircleInt() error ... \n");
        FinSi
        ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 7022 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim4(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim3(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
      InrImage::ptr res ( Func_CircleIntegration(
        varim1 ->Pointer().get(),  // gradient
        varim2 ->Pointer().get(),  // first  vector
        varim3 ->Pointer().get(),  // second vector
        (float)     (yysemantic_stack_[(12) - (9)].adouble),              // radius
        CIRCLE_RESPONSE_MEAN,        // integration type
        varim4->Pointer().get())); // mask
      Si !res.get() Alors
        driver.err_print("CircleInt() error ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 7042 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (3) gradient
          (5) first vector
          (7) second vector
          (9) radius
          (11) mask
          (13) threshold on standard deviation
          (15) threshold on excentricity

        Description:
          Compute integrations of the gradient vectors along circles
          in a plane defined by 2 vectors,
          with constraints on the standard deviation and the excentricity
          (see pub. Krissian et al. EMBS 2003)
        **/
      Variable<InrImage>::ptr  varim4(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim3(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
        InrImage::ptr res ( Func_CircleIntSdExc(
          varim1 ->Pointer().get(),  // gradient
          varim2 ->Pointer().get(),  // first  vector
          varim3 ->Pointer().get(),  // second vector
          (float)     (yysemantic_stack_[(16) - (9)].adouble),              // radius
          varim4->Pointer().get(),
          (float) (yysemantic_stack_[(16) - (13)].adouble),
          (float) (yysemantic_stack_[(16) - (15)].adouble),
          2, // pairs mode MEAN
          100, // keeps all points
          CIRCLE_RESPONSE_MEAN));

        Si !res.get() Alors
          driver.err_print("CircleIntSdExc() error ... \n");
        FinSi
        ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 7083 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
      Parameters:
        (3) gradient
        (5) first vector
        (7) second vector
        (9) radius
        (11) mask
        (13) threshold on standard deviation
        (15) threshold on excentricity
        (17) Pairs mode (0: MIN,1: MAX or 2:MEAN)
        (19) Highest percentage (Keeps only a percentage of highest boundary values)

      Description:
        Compute integrations of the gradient vectors along circles
        in a plane defined by 2 vectors,
        with constraints on the standard deviation and the excentricity
        (see pub. Krissian et al. EMBS 2003)
        with an additional constraint:
        it integrates half of the circle and takes the
        minimum between opposite values.
      **/
      Variable<InrImage>::ptr  varim4(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim3(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());

      InrImage::ptr res ( Func_CircleIntSdExc(
        varim1 ->Pointer().get(),  // gradient
        varim2 ->Pointer().get(),  // first  vector
        varim3 ->Pointer().get(),  // second vector
        (float)     (yysemantic_stack_[(20) - (9)].adouble),              // radius
        varim4->Pointer().get(),
        (float) (yysemantic_stack_[(20) - (13)].adouble),
        (float) (yysemantic_stack_[(20) - (15)].adouble),
        (int) (yysemantic_stack_[(20) - (17)].adouble),
        (int) (yysemantic_stack_[(20) - (19)].adouble),
        CIRCLE_RESPONSE_MEAN));

      Si !res.get() Alors
        driver.err_print("CircleIntSdExc() error ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 7129 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {

      Variable<InrImage>::ptr  varim4(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim3(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());

    InrImage::ptr res( Func_LocalExtrema( 
                  varim1->Pointer().get(),  // input image
                  varim2->Pointer().get(),  // first  vector
                  varim3->Pointer().get(),  // second vector
                  varim4->Pointer().get())); // mask
    Si !res.get() Alors
      driver.err_print("LocalExtrema() error ... \n");
    FinSi

    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 7149 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim4(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim3(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
    int samples = (int) (yysemantic_stack_[(12) - (11)].adouble);

    InrImage::ptr res( Func_LocalExtrema( 
                  varim1->Pointer().get(),  // input image
                  varim2->Pointer().get(),  // first  vector
                  varim3->Pointer().get(),  // second vector
                  varim4->Pointer().get(),  // mask
                 samples));                   // number of sample points around the circle

    Si !res.get() Alors
      driver.err_print("LocalExtrema() error ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 7170 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res( Func_NormalSmoothField( im.get() ));

    Si !res.get() Alors
      driver.err_print("NormalField() error ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 7181 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
    InrImage::ptr res( Func_NormalSmoothField( 
                    varim1->Pointer().get() , 
                    varim2->Pointer().get() ));

    Si !res.get() Alors
      driver.err_print("NormalField() error ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 7195 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
    InrImage::ptr res( Func_DirConnectivity( 
        varim1->Pointer().get() ,
        varim2->Pointer().get() ));

    Si res.get() Alors
      driver.err_print("DirConnectivity() error ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 7211 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, input);
  
      InrImage::ptr res ( Func_NormGrad( input.get(), (yysemantic_stack_[(6) - (5)].adouble)));
      Si (!res.get()) Alors
        driver.err_print("NormGrad() error ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 7223 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_DiscNormGrad( im.get()));
    Si !res.get() Alors
      driver.err_print("discnormgrad() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 7234 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_DiscMeanCurvature( im.get()));
    Si !res.get() Alors
      driver.err_print("DiscMeanCurvature() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 7246 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_Gradient( im.get(),
                 (yysemantic_stack_[(6) - (5)].adouble)));
    Si !res.get() Alors
      driver.err_print("Filter() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 7257 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
        Parameters:
            (3) input image.

        Description:
        Computes a discrete laplacian (sum of second order derivatives),
        in 2D or 3D depending on the image dimension.
    **/
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_Laplacian(im.get()));
    Si !res.get() Alors
      driver.err_print("Filter() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 7277 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage,im);
        InrImage::ptr res (Func_SecDerGrad( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
        Si !res.get() Alors
          fprintf(stderr,"SecDerGrad() erreur ... \n");
        FinSi
        ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 7289 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage,im);
        InrImage::ptr res ( Func_SecDerGrad2( im.get(),
                 (yysemantic_stack_[(6) - (5)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SecDerGrad2() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 7299 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage,im);
        InrImage::ptr res ( Func_AutoCrop(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
        ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 7354 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
      Parameters
        #1 var_image: input image
        #2 expr:      X min
        #3 expr:      Y min
        #4 expr:      Z min
        #5 expr:      X max
        #6 expr:      Y max
        #7 expr:      Z max

      Extract a rectangular subimage from the input image, the subimage
      keeps the information of the translation and it can be put back
      at the same position using putimage command.
      The same operation can also be achieved using the [] operator.

      Example(s):

      - Extract a subimage of size 4x4x4

      i = Image(FLOAT,10,10,10)
      j = subimage(i,5,5,5,8,8,8)

      See also:
        putimage, []

      **/
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_SubImage( im.get(),
                 (int) (yysemantic_stack_[(16) - (5)].adouble), (int) (yysemantic_stack_[(16) - (7)].adouble), (int) (yysemantic_stack_[(16) - (9)].adouble),
                 (int) (yysemantic_stack_[(16) - (11)].adouble),(int) (yysemantic_stack_[(16) - (13)].adouble),(int) (yysemantic_stack_[(16) - (15)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 7392 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_EDP_dilate( im.get(),
                   (yysemantic_stack_[(10) - (5)].adouble),  (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 7403 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_EDP_dilate( im.get(), (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 7413 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    float Imin = (yysemantic_stack_[(12) - (9)].adouble);
    float Imax = (yysemantic_stack_[(12) - (11)].adouble);
    InrImage::ptr res ( Func_EDP_dilate( im.get(), (yysemantic_stack_[(12) - (5)].adouble),  (yysemantic_stack_[(12) - (7)].adouble), Imin, Imax));
    Si (!res.get()) Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 7425 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_EDP_erode( im.get(),
                  (yysemantic_stack_[(10) - (5)].adouble),  (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 7436 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_EDP_erode( im.get(), (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 7446 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3)  initial image
      (5)  total operation size
      (7)  time step
      (9)  minimal intensity
      (11) maximal intensity
    Description:
      Grayscale morphological erosion
      using Brockett and Maragos scheme with a given
      size and time step in voxel units
      minimal and maximal intensities allow to speed up the process
    **/
      GET_VARSTACK_VALUE(InrImage, im);
    float Imin = (yysemantic_stack_[(12) - (9)].adouble);
    float Imax = (yysemantic_stack_[(12) - (11)].adouble);
    InrImage::ptr res ( Func_EDP_erode( im.get(), (yysemantic_stack_[(12) - (5)].adouble),  (yysemantic_stack_[(12) - (7)].adouble), Imin, Imax));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 7473 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3)  initial image
      (5)  total operation size
      (7)  time step
    Description:
      Grayscale morphological opening
      using Brockett and Maragos scheme with a given
      size and time step in voxel units
    **/
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_EDP_open( im.get(),
                    (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 7496 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3)  initial image
      (5)  total operation size
      (7)  time step
      (9)  minimal intensity
      (11) maximal intensity
    Description:
      Grayscale morphological opening
      using Brockett and Maragos scheme with a given
      size and time step in voxel units
      minimal and maximal intensities allow to speed up the process
    **/
      GET_VARSTACK_VALUE(InrImage, im);
    float Imin = (yysemantic_stack_[(12) - (9)].adouble);
    float Imax = (yysemantic_stack_[(12) - (11)].adouble);
    InrImage::ptr res ( Func_EDP_open( im.get(),
                    (yysemantic_stack_[(12) - (5)].adouble),  (yysemantic_stack_[(12) - (7)].adouble), Imin, Imax));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 7524 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage,im);
    InrImage::ptr res ( Func_EDP_close( im.get(),
                   (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble)));

    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 7537 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    float Imin = (yysemantic_stack_[(12) - (9)].adouble);
    float Imax = (yysemantic_stack_[(12) - (11)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_EDP_close( im.get(),
                   (yysemantic_stack_[(12) - (5)].adouble),  (yysemantic_stack_[(12) - (7)].adouble), Imin, Imax));

    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 7671 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      //
      // param 1: input image
      // 2: vector field
      // 3: data attachment coeff
      // 4: diffusion coeff
      // 5: number of iterations
      //
      int        nb_iter,i;
      float       error;

      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
      Func_InitAnisoGS( varim1->Pointer().get(),
                  1,  1, (yysemantic_stack_[(12) - (7)].adouble));


          nb_iter = (int) (yysemantic_stack_[(12) - (11)].adouble);
      if (nb_iter < 1) nb_iter = 1;

      Pour(i,1,nb_iter)
        error = Func_ItereFlux(varim2->Pointer().get(),(yysemantic_stack_[(12) - (9)].adouble));
      FinPour

      InrImage::ptr res ( Func_AnisoGS_GetOutput());
      Si !res.get() Alors
        fprintf(stderr,"AnisoGS() erreur ... \n");
      FinSi
      Func_EndAnisoGS();
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 7706 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
        Parameters:
          (3)  input image
          (5)  standard deviation for Gaussian smoothing sigma
          (7)  threshold on the gradient magnitude
          (9)  data attachment coefficient
          (11) number of iterations
          (13) number of threads

        Description:
          Anisotropic diffusion filter based on the Flux diffusion paper
          (Krissian, 2002, IEEE TMI).
      **/
      GET_VARSTACK_VALUE(InrImage, im);
      float      sigma   = (yysemantic_stack_[(14) - (5)].adouble);
      float      k       = (yysemantic_stack_[(14) - (7)].adouble);
      float      beta    = (yysemantic_stack_[(14) - (9)].adouble);
      int        nb_iter    = (int) (yysemantic_stack_[(14) - (11)].adouble);
      int        nb_threads = (int) (yysemantic_stack_[(14) - (13)].adouble);

      InrImage::ptr  res ( Func_vtkAnisoGS(  im.get(), sigma, k, beta, nb_iter, nb_threads));

      Si !res.get() Alors
        fprintf(stderr,"Func_vtkAnisoGS() erreur ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);

    }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 7739 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      int        nb_iter,i;
      float       error;

      GET_VARSTACK_VALUE(InrImage, im);
      Func_InitAnisoGS( im.get(), (yysemantic_stack_[(12) - (5)].adouble),  (yysemantic_stack_[(12) - (7)].adouble), (yysemantic_stack_[(12) - (9)].adouble));


      Func_SetSmoothedParam(1);

      nb_iter = (int) (yysemantic_stack_[(12) - (11)].adouble);
      if (nb_iter < 1) nb_iter = 1;

      Pour(i,1,nb_iter)
        error = Func_ItereAnisoGS();
      FinPour
      InrImage::ptr res ( Func_AnisoGS_GetOutput());
      Si !res.get() Alors
        fprintf(stderr,"AnisoGS() erreur ... \n");
      FinSi
      Func_EndAnisoGS();
      ADD_VARSTACK_PTR(InrImage,res);

    }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 7767 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_InitWeickert( im.get(),
                (yysemantic_stack_[(12) - (7)].adouble),  (yysemantic_stack_[(12) - (9)].adouble), (yysemantic_stack_[(12) - (11)].adouble)));

      Si !res.get() Alors
        fprintf(stderr,"Func_InitWeickert() erreur ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 7781 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_InitWeickertCoherence( im.get(),
                (yysemantic_stack_[(16) - (7)].adouble),  (yysemantic_stack_[(16) - (9)].adouble), (yysemantic_stack_[(16) - (11)].adouble), (yysemantic_stack_[(16) - (13)].adouble), (yysemantic_stack_[(16) - (15)].adouble)));

      Si !res.get() Alors
        fprintf(stderr,"Func_InitWeickert() erreur ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 7793 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_SRAD_qcoeff( im.get()));
      Si !res.get() Alors
        fprintf(stderr,"Func_SRAD_qcoeff() erreur ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 7805 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      float dt = (float) (yysemantic_stack_[(8) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(8) - (7)].adouble);

      InrImage::ptr res ( Func_SRAD( im.get(),dt,numit,
               0, // Lee mode
               0,  // Yu neighborhood
               NULL)); // no extent

      Si !res.get() Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 7823 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_OBJECT2(ImageExtent, ImageExtent<float>, extent)
      GET_VARSTACK_VALUE(InrImage, im);
      float dt = (float) (yysemantic_stack_[(10) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(10) - (7)].adouble);

      InrImage::ptr res ( Func_SRAD( im.get(),dt,numit,
               0, // Lee mode
               0, // Yu neighborhood
               extent.get()));

      Si !res.get() Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 7842 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_OBJECT2(ImageExtent, ImageExtent<float>, extent)
      GET_VARSTACK_VALUE(InrImage, im);
      float dt = (float) (yysemantic_stack_[(12) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(12) - (7)].adouble);
      int neighborhood = (int) (yysemantic_stack_[(12) - (9)].adouble);

      InrImage::ptr res ( Func_SRAD( im.get(),dt,numit,
               0, // Lee mode
               neighborhood,
               extent.get()));

      Si !res.get() Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 7862 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_OBJECT2(ImageExtent, ImageExtent<float>, extent)
      GET_VARSTACK_VALUE(InrImage, im);
      float dt = (float) (yysemantic_stack_[(10) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(10) - (7)].adouble);

      InrImage::ptr res ( Func_SRAD2( im.get(),dt,numit,
                0, // Lee function
                0, // Yu neighborhood
                extent.get()
                ));

      Si !res.get() Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
      FinSi

      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 7884 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_OBJECT2(ImageExtent, ImageExtent<float>, extent)
      GET_VARSTACK_VALUE(InrImage, im);
      float dt = (float) (yysemantic_stack_[(12) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(12) - (7)].adouble);
      int neighborhood = (int) (yysemantic_stack_[(12) - (9)].adouble);

      InrImage::ptr res ( Func_SRAD2( im.get(),dt,numit,
                0, // Lee function
                neighborhood, // neighborhood size
                extent.get() // bounding box
                ));
      Si !res.get() Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
      FinSi

      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 7904 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_OBJECT2(ImageExtent, ImageExtent<float>, extent)
      GET_VARSTACK_VALUE(InrImage, im);
      float dt = (float) (yysemantic_stack_[(10) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(10) - (7)].adouble);

      InrImage::ptr res ( Func_SRAD2( im.get(),dt,numit,
                2, // Additive mode
                0, // Yu neighborhood
                extent.get() // constant region
                ));

      Si !res.get() Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 7923 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_OBJECT2(ImageExtent, ImageExtent<float>, extent)
      GET_VARSTACK_VALUE(InrImage, im);
      float dt         = (float) (yysemantic_stack_[(12) - (5)].adouble);
      int numit        = (int) (yysemantic_stack_[(12) - (7)].adouble);
      int neighborhood = (int) (yysemantic_stack_[(12) - (9)].adouble);

      InrImage::ptr res ( Func_SRAD( im.get(),dt,numit,
               1, // Kuan's function
               neighborhood, // Yu neighborhood
               extent.get()));

      Si !res.get() Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 7943 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_OBJECT2(ImageExtent, ImageExtent<float>, extent)
      GET_VARSTACK_VALUE(InrImage, im);
      float dt = (float) (yysemantic_stack_[(12) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(12) - (7)].adouble);
      int neighborhood = (int) (yysemantic_stack_[(12) - (9)].adouble);

      InrImage::ptr res ( Func_SRAD2( im.get(),dt,numit,
                1, // Kuan's function
                neighborhood, // Yu neighborhood
                extent.get()
                ));
      Si !res.get() Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 7963 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        (3) var_image: input image
        (5) numerical expression: mode, 0 for Lee Filter, 1: Kuan Filter,
              2: additive, 3: MRI denoising
        (7) numerical expression: dt, time step
        (9) numerical expression: numit, number of iterations
        (11) numerical expression: size of the neighborhood n, neighborhood is
            (2n+1)^N, where N is the dimension of the image domain.
        (13) image extent: area of interest to calculate the noise
              standard deviation, usually a constant area, for MRI denoising: background area

      Description:
        Runs a noise reducing anisotropic diffusion, Lee and Kuan's mode are
        for speckle noise in ultrasound images, additive mode is for additive
        stationary noise and MRI is for MRI style noise. In the case of MRI,
        the filter is designed to run on the square of the image intensity.
      **/
      GET_VARSTACK_OBJECT2(ImageExtent, ImageExtent<float>, extent)
      GET_VARSTACK_VALUE(InrImage, im);
      int mode = (int) (yysemantic_stack_[(14) - (5)].adouble);
      float dt = (float) (yysemantic_stack_[(14) - (7)].adouble);
      int numit = (int) (yysemantic_stack_[(14) - (9)].adouble);
      int neighborhood = (int) (yysemantic_stack_[(14) - (11)].adouble);

      InrImage::ptr res ( Func_SRAD2( im.get(),dt,numit,
                  mode, // fiter mode
                  neighborhood, //  neighborhood size
                  extent.get()
                  ));

      Si !res.get() Alors
        fprintf(stderr,"Func_AnisoNRAD() erreur ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 8004 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, initim);
      float dt = (float) (yysemantic_stack_[(12) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(12) - (7)].adouble);
      int attach = (int) (yysemantic_stack_[(12) - (9)].adouble);
      int scheme = (int) (yysemantic_stack_[(12) - (11)].adouble);
      InrImage::ptr res;

      if (initim->DimZ()==1)
        res = InrImage::ptr( Func_RudinMultiplicative2D( initim.get(),dt,numit,attach, scheme));
      else
        res = InrImage::ptr( Func_RudinMultiplicative3D( initim.get(),dt,numit,attach, scheme));

      Si !res.get() Alors
        fprintf(stderr,"Func_AnisoRudinMult() erreur ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 8026 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
        Description:
          Add Gaussian noise with specified mean and variance.
      **/

      GET_VARSTACK_VALUE(InrImage, im);
        AjouteBruit* addnoise;
        float mean;
        float sd;
        char  resname[256];

      mean = (yysemantic_stack_[(8) - (5)].adouble);
      sd   = (yysemantic_stack_[(8) - (7)].adouble);

      sprintf(resname,"%s.noise",im->GetName());
      InrImage::ptr res( new InrImage(WT_FLOAT, resname, im.get()));

      (*res)=(*im);
      addnoise = new AjouteBruit();
      addnoise->AjouteBruitGaussien(res.get(),mean,sd);
      delete addnoise;
      ADD_VARSTACK_PTR(InrImage,res);

    }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 8054 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        - input image
        - rotation center X,Y
        - rotation angle
        - dimensions of the resulting image
      Description:
        - Performs a 2D rotation of the image
    **/

      GET_VARSTACK_VALUE(InrImage, im);
          InrImage::ptr res ( Func_rot2D( im.get(),
                (yysemantic_stack_[(14) - (5)].adouble), (yysemantic_stack_[(14) - (7)].adouble),   // rotation center
                (yysemantic_stack_[(14) - (9)].adouble),       // angle of rotation
                (yysemantic_stack_[(14) - (11)].adouble), (yysemantic_stack_[(14) - (13)].adouble)  // dimension of the new image
                ));

      ADD_VARSTACK_PTR(InrImage,res);
        }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 8075 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        Creates an new USHORT image that contains
        the X coordinates of the given image.
        This can be very useful for arithmetic
        operations on images.

        Example(s):
        - Putting the image borders in X coordinates at 0:

        x = Xpos(i)
        i = i * (x>2) * ( x < i.tx-3)

        See also:
                Ypos, Zpos
       **/

          int x,y,z;

        GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( new InrImage(WT_UNSIGNED_SHORT,1,
                   "tmp_X.inr.gz",
                   im.get()));
        res->InitBuffer();
        Pour(z,0,res->_tz-1)
        Pour(y,0,res->_ty-1)
        Pour(x,0,res->_tx-1)
          res->FixeValeur(x);
          res->IncBuffer();
        FinPour
        FinPour
        FinPour
        //cout << "(*res)(10,20,0)=" << (*res)(10,20,0) << endl;
        ADD_VARSTACK_PTR(InrImage,res);
        }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 8112 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        Creates an new USHORT image that contains
        the Y coordinates of the given image.
        This can be very useful for arithmetic
        operations on images.

        Example(s):
        - Putting the image borders in X coordinates at 0:

        y = Ypos(i)
        i = i * (y>2) * ( y < i.tx-3)

        See also:
                Xpos, Zpos
       **/

          int x,y,z;

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( new InrImage(WT_UNSIGNED_SHORT,1,
                   "tmp_X.inr.gz",
                   im.get()));
        res->InitBuffer();
        Pour(z,0,res->_tz-1)
        Pour(y,0,res->_ty-1)
        Pour(x,0,res->_tx-1)
          res->FixeValeur(y);
          res->IncBuffer();
            FinPour
            FinPour
            FinPour

        ADD_VARSTACK_PTR(InrImage,res);
        }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 8149 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        Creates an new USHORT image that contains
        the Z coordinates of the given image.
        This can be very useful for arithmetic
        operations on images.

        Example(s):
        - Putting the image borders in Z coordinates at 0:

        z = Zpos(i)
        i = i * (z>2) * ( z < i.tx-3)

        See also:
                Xpos, Ypos
       **/

          int x,y,z;

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( new InrImage(WT_UNSIGNED_SHORT,1,
                   "tmp_X.inr.gz",
                   im.get()));
        res->InitBuffer();
        Pour(z,0,res->_tz-1)
        Pour(y,0,res->_ty-1)
        Pour(x,0,res->_tx-1)
          res->FixeValeur(z);
          res->IncBuffer();
            FinPour
            FinPour
            FinPour

        ADD_VARSTACK_PTR(InrImage,res);
        }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 8186 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        Creates an new FLOAT vectorial image that contains
        the coordinates of the voxels (/pixels) of the given image.
        The coordinates are given in Real Coordinates (world),
        and are saved as vectors.


        See also:
                Xpos, Ypos, Zpos
       **/

          int x,y,z;

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( new InrImage(WT_FLOAT,3,
                   "tmp_spacepos.inr.gz",
                   im.get()));
        res->InitBuffer();
        Pour(z,0,res->_tz-1)
        Pour(y,0,res->_ty-1)
        Pour(x,0,res->_tx-1)
          res->VectFixeValeurs(res->SpacePosX(x),
                               res->SpacePosY(y),
                               res->SpacePosZ(z));
          res->IncBuffer();
        FinPour
        FinPour
        FinPour
        ADD_VARSTACK_PTR(InrImage,res);
        }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 8220 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          ADD_VARSTACK(InrImage,InrImage::ptr(( varsurfd->Pointer())->GetCanvas()->GetGLImage()));
        }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 8226 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          driver.yyiperror("Not available in new wxwidgets version of the 3D viewer ! ");
          YYABORT;
/*
          ADD_VARSTACK(InrImage,(*(Viewer3D_ptr*) $1->Pointer())->GetInrImage());
*/
    }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 8236 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(DessinImage, imdraw)
      ADD_VARSTACK(InrImage, imdraw->GetInrImage());
    }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 8242 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_ThresholdCrossing( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
       ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 8249 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_IsocontourPoints( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 8256 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_IsosurfDist( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
      ADD_VARSTACK_PTR(InrImage,res);

    }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 8264 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_vtkIsoContourDist( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 8271 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3) input image
      (5) initialization image
      (7) maximal time
    Description:
      Runs the fast marching algorithm
     **/

      // 2nd param
      GET_VARSTACK_VALUE(InrImage, init);
      // 1st param
      GET_VARSTACK_VALUE(InrImage, input);

      float   maxtime = (float) (yysemantic_stack_[(8) - (7)].adouble);

      InrImage::ptr res ( Func_vtkFastMarching( input.get(), init.get(),  maxtime));
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 8295 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3) input image
      (5) initialization
      (7) maximal time
      (9)  target point X coord
      (11)               Y
      (13)              Z
    Description:
      Runs the fast marching algorithm
     **/

      GET_VARSTACK_VALUE(InrImage,init);
      GET_VARSTACK_VALUE(InrImage,input);
      float   maxtime = (float) (yysemantic_stack_[(14) - (7)].adouble);

      InrImage::ptr res ( Func_vtkFastMarchingTarget( input.get(), init.get(),  maxtime,
              (int) round((yysemantic_stack_[(14) - (9)].adouble)),
              (int) round((yysemantic_stack_[(14) - (11)].adouble)),
              (int) round((yysemantic_stack_[(14) - (13)].adouble))
              ));
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 8322 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3)  input image
      (5)  initialization
      (7)  mean
      (9)  standard deviation
      (11) maximal time
    Description:
      Runs the fast marching algorithm
     **/

      GET_VARSTACK_VALUE(InrImage,init);
      GET_VARSTACK_VALUE(InrImage,input);
      float   mean    = (float) (yysemantic_stack_[(12) - (7)].adouble);
      float   sd      = (float) (yysemantic_stack_[(12) - (9)].adouble);
      float   maxtime = (float) (yysemantic_stack_[(12) - (11)].adouble);

      InrImage::ptr res ( Func_vtkFastMarching( input.get(), init.get(), mean, sd, maxtime));
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 8346 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3)  input image
      (5)  initialization
      (7)  mean
      (9)  standard deviation
      (11) maximal time
      (13) initialization type
    Description:
      Runs the fast marching algorithm
     **/
      /* Version without initialization */

      GET_VARSTACK_VALUE(InrImage,init);
      GET_VARSTACK_VALUE(InrImage,input);
      float   mean     = (float) (yysemantic_stack_[(14) - (7)].adouble);
      float   sd       = (float) (yysemantic_stack_[(14) - (9)].adouble);
      float   maxtime  = (float) (yysemantic_stack_[(14) - (11)].adouble);
      int     inittype = (int) (yysemantic_stack_[(14) - (13)].adouble);

      InrImage::ptr res ( Func_vtkFastMarching( input.get(), init.get(), mean, sd, maxtime,inittype));
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 8375 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3)  input image
      (5)  initialization
      (7)  track image, must be of format unsigned int
      (9)  maximal time
      (11) initialization type
    Description:
      Runs the fast marching algorithm using Dijkstra
      algorithm and tracking back the trajectories
     **/
      /* Version without initialization */

      int     inittype   = (int)   (yysemantic_stack_[(12) - (11)].adouble);
      float   maxtime    = (float) (yysemantic_stack_[(12) - (9)].adouble);
      GET_VARSTACK_VALUE(InrImage, im);
      GET_VARSTACK_VALUE(InrImage, init);
      GET_VARSTACK_VALUE(InrImage, input);

      InrImage::ptr res ( Func_vtkFastMarching(
                  input.get(),
                  init.get(),
                  im.get(),
                  maxtime,inittype));
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 8404 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im2);
      GET_VARSTACK_VALUE(InrImage, im1);
      InrImage::ptr res ( Func_Convolve(im1.get(), im2.get()));
      ADD_VARSTACK_PTR(InrImage,res);

      }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 8413 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage,mask);
        Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
        Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());

        InrImage::ptr res ( Func_ConvolveMask(varim1->Pointer().get(),
                  varim2->Pointer().get(),
                  mask.get()));
        ADD_VARSTACK_PTR(InrImage,res);

      }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 8426 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_Chamfer(im.get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble)));
        ADD_VARSTACK_PTR(InrImage,res);
        }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 8433 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
          InrImage::ptr res ( Func_Chamfer2(im.get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble)));
          ADD_VARSTACK_PTR(InrImage,res);

        }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 8441 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {

        float a = (yysemantic_stack_[(12) - (5)].adouble);
        float b = (yysemantic_stack_[(12) - (7)].adouble);
        float c = (yysemantic_stack_[(12) - (9)].adouble);
        float dmax = (yysemantic_stack_[(12) - (11)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_Chamfer2(im.get(), a,b,c,dmax));
        ADD_VARSTACK_PTR(InrImage,res);

        }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 8455 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr  res ( Func_Chamfer2(im.get(),
                  0.92644, 1.34065, 1.65849,
                  dmax));
        ADD_VARSTACK_PTR(InrImage,res);

        }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 8467 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_Chamfer2Signed(im.get(),
                    0.92644, 1.34065, 1.65849,
                    dmax));
        ADD_VARSTACK_PTR(InrImage,res);

        }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 8479 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkSignedBorgefors(im.get(),
                    dmax));
        ADD_VARSTACK_PTR(InrImage,res);
        }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 8489 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkSignedFMDist(im.get(),
                     dmax));
        ADD_VARSTACK_PTR(InrImage,res);

        }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 8500 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_PropagationDistance(im.get(),
                      dmax));
        ADD_VARSTACK_PTR(InrImage,res);
        }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 8510 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_PropagationDistance2(im.get(),
                      dmax));
        ADD_VARSTACK_PTR(InrImage,res);
        }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 8520 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

        GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_PropagationDanielsson(im.get(),
                       dmax));

        ADD_VARSTACK_PTR(InrImage,res);
        }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 8531 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkPropDanielsson(im.get(),
                       -dmax,dmax));
        ADD_VARSTACK_PTR(InrImage,res);
        }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 8541 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        float dmin = (yysemantic_stack_[(8) - (5)].adouble);
        float dmax = (yysemantic_stack_[(8) - (7)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkPropDanielsson(im.get(),
                       dmin,dmax));
        ADD_VARSTACK_PTR(InrImage,res);
        }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 8552 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (3) input image variable
          (5) threshold on the image intensity to define
              the object
          (7) minimal distance (<0)
          (9) maximal distance (>0)

        Description:
          Computes an Euclidean distance by propagation
          starting from the object, up to a given distance
          for positive and negative sides.
        **/
      GET_VARSTACK_VALUE(InrImage, im);
        float threshold = (yysemantic_stack_[(10) - (5)].adouble);
        float dmin      = (yysemantic_stack_[(10) - (7)].adouble);
        float dmax      = (yysemantic_stack_[(10) - (9)].adouble);

        printf("threshold = %f \n",threshold);
        InrImage::ptr res ( Func_vtkPropDaniel2(im.get(),
                    threshold,dmin,dmax));

        ADD_VARSTACK_PTR(InrImage,res);
        }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 8579 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (3) image expression: input image
        Description:
            Computes the connected components of the input image,
            considering the isosurface (or isocontour) of intensity value
            0 as the serapation between the components.
            The image background is supposed to have intensity values of 0.
            Returns an image of type INTEGER, and
            creates the following new variables:
                - reorder   : 1D image of the position position of the component
                    if sorted by size. The image size in X is the number of
                    components.
                    You can use image composition to get the image of the biggest
                    component, for example: reorder(cc_result) == 0.
                - inclusion :
                - cc_size   :
                - cc_sign   :
        Example(s):
            To analyze connected component from an isocontour value n for an image i,
            you can call i_cc=CC((FLOAT)i-n)
        **/
      GET_VARSTACK_VALUE(InrImage,im);
      InrImage::ptr res ( Func_CC(im.get()));
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 8627 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
     /**
       Parameters:
         (1) image1: image variable
         (3) image2: variable expression

       Description:
        if variable expression is numerical, get the image value at the corresponding pixel in X, with y=z=0,
        if variable expression is an image:
          Image Composition
          Several Cases:
          - scalar to scalar: transforms the intensity values
              of image 2 using image1 as a lookup table
          - vectorial to scalar
          - scalar to vectorial: returns the values of image1
              at the positions pointed by image2 (positions are converted
              to spatial coordinates)
          - vectorial to vectorial
      **/

      BasicVariable::ptr param1(driver.var_stack.GetLastBasicVar());
      GET_VARSTACK_VALUE(InrImage, im1);

      if (param1.get()) {
        if (param1->IsNumeric()) {
          ADD_VARSTACK_FLOAT((*im1)((int) param1->GetValueAsDouble(),0))
        }
        else
        if (param1->Type()==type_image) {

          // image composition
          // Initialy for applying a RGB colormap to an image
          DYNAMIC_CAST_VARIABLE(InrImage,param1,var_im2)
          //GET_VARSTACK_VALUE(InrImage,ref);
          InrImage::ptr im2( var_im2->Pointer());
          int pos;
    
          InrImage::ptr res ( new InrImage(
                              im1->_format,
                              im1->GetVDim(),
                              "ImComp.ami.gz",
                              im2.get()));
    
          // Several Cases:
          // 1. scalar to scalar
          // 2. scalar to vectorial
          // 3. vectorial to scalar
          // 4. vectorial to vectorial
          if (res->ScalarFormat())
            res->InitImage(0);
          else
            res->InitImage(0,0,0);
    
          // im1 is a 1D image (colormap)
          //
          if (im1->VectorialFormat()&&im2->ScalarFormat()) {
            res->InitBuffer();
            im2->InitBuffer();
    
            Repeter
    
              pos = (int) im2->ValeurBuffer();
              Si (pos<0) AlorsFait pos = 0;
              Si (pos>=im1->DimX()) AlorsFait pos = im1->DimX()-1;
              im1->BufferPos(pos,0,0);
    
              res->VectFixeValeurs(im1->VectValeurBuffer(0),
                      im1->VectValeurBuffer(1),
                      im1->VectValeurBuffer(2));
    
              im2->IncBuffer();
                JusquA Non(res->IncBuffer()) FinRepeter
          } else
          // Greyscale colormap
          if (im1->ScalarFormat()&&im2->ScalarFormat()) {
            res->InitBuffer();
            im2->InitBuffer();
            Repeter
              //pos = (int) im2->ValeurBuffer();
              int pos = (int) (im1->SpaceToVoxelX(im2->ValeurBuffer())+0.5);
              //cout << boost::format(" im2->ValeurBuffer() = %1% pos = %2%")%im2->ValeurBuffer() % pos << endl;
              Si (pos<0)  AlorsFait pos = 0;
              Si (pos>=im1->DimX()) 
                          AlorsFait pos = im1->DimX()-1;
              // convert to space coordinates
              im1->BufferPos(pos,0,0);
              res->FixeValeur(im1->ValeurBuffer());
              im2->IncBuffer();
            JusquA Non(res->IncBuffer()) FinRepeter
          } else
          // Applying a transformation ...
          if (im1->VectorialFormat()&&im2->VectorialFormat()) {
            float posx, posy, posz;
            res->InitBuffer();
            im2->InitBuffer();
            Repeter
              // linear interpolation
              posx =  im1->SpaceToVoxelX(im2->VectValeurBuffer(0));
              posy =  im1->SpaceToVoxelY(im2->VectValeurBuffer(1));
              posz =  im1->SpaceToVoxelZ(im2->VectValeurBuffer(2));
              res->VectFixeValeurs(
                im1->InterpLinIntensite(posx,posy,posz,0),
                im1->InterpLinIntensite(posx,posy,posz,1),
                im1->InterpLinIntensite(posx,posy,posz,2));
              im2->IncBuffer();
            JusquA Non(res->IncBuffer()) FinRepeter
          } else
          // Applying a transformation ...
          if (im1->ScalarFormat()&&im2->VectorialFormat()) {
            float posx, posy, posz;
            res->InitBuffer();
            im2->InitBuffer();
            Repeter
              // linear interpolation
              posx =  im1->SpaceToVoxelX(im2->VectValeurBuffer(0));
              posy =  im1->SpaceToVoxelY(im2->VectValeurBuffer(1));
              posz =  im1->SpaceToVoxelZ(im2->VectValeurBuffer(2));
              res->FixeValeur(im1->InterpLinIntensite(posx,posy,posz));
              im2->IncBuffer();
                JusquA Non(res->IncBuffer()) FinRepeter
          } else
            fprintf(stderr," Image Composition: type of composition not implemented \n");
          ADD_VARSTACK_PTR(InrImage,res);

        }
        else {
          driver.err_print("operator image(expr_var), wrong type of parameter \n");
          YYABORT;
        }
      }


    }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 8761 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
       Parameters:
         (3) image: image to compute the histogram
         (5) expr: minimal value
         (7) expr: maximal value
         (9) expr: number of intervals

       Description:
         Compute the histogram of an image and returns it
         as a 1D image
    **/
      GET_VARSTACK_VALUE(InrImage,im);
      float vmin  = (yysemantic_stack_[(10) - (5)].adouble);
      float vmax  = (yysemantic_stack_[(10) - (7)].adouble);
      int   nint = (int) (yysemantic_stack_[(10) - (9)].adouble); // number of intervals

      InrImage::ptr res ( Func_Histogram(im.get(),vmin,vmax,nint));
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 8782 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      float vmin  = (yysemantic_stack_[(10) - (5)].adouble);
      float vmax  = (yysemantic_stack_[(10) - (7)].adouble);
      int   nint = (int) (yysemantic_stack_[(10) - (9)].adouble); // number of intervals

      int* numpts;
      int  n;
      float v;
      double total = 0;

      InrImage::ptr res ( new InrImage(nint,1,1,WT_SIGNED_INT));

      numpts = new int[nint];
      Pour(n,0,nint-1)
        numpts[n]=0;
      FinPour

        im->InitBuffer();
      Repeter
        v = im->ValeurBuffer();
        Si v>=vmin Et v<vmax Alors
          n = (int) ((v-vmin)/(vmax-vmin)*nint);
          Si n==nint AlorsFait n=nint-1;
          numpts[n]++;
        FinSi
          JusquA Non(im->IncBuffer()) FinRepeter

      res->InitBuffer();
      Pour(n,0,nint-1)
        total += numpts[n];
        res->FixeValeur(1.0*total/im->Size());
        res->IncBuffer();
          FinPour

      delete [] numpts;

      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 8822 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      InrImage::ptr res;
      if (im->DimZ()>1)
        res = InrImage::ptr( Func_MeanHalfSize(im.get(),3));
      else
        res = InrImage::ptr( Func_MeanHalfSize(im.get(),2));

      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 8833 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      int dim = (int) (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage,im);
      InrImage::ptr res ( Func_MeanHalfSize(im.get(),dim));
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 8841 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        int axis=(int) (yysemantic_stack_[(6) - (5)].adouble);

        GET_VARSTACK_VALUE(InrImage,im);
        InrImage::ptr res(Func_Flip(im,axis));
        ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 8849 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            image to resize
            new dimension in X
            new dimension in Y
            new dimension in Z
            interpolation: 0: nearest neighbor, 1:linear, 2:spline
        Description:
          Image resize
        **/
            int sx = (int) (yysemantic_stack_[(12) - (5)].adouble);
            int sy = (int) (yysemantic_stack_[(12) - (7)].adouble);
            int sz = (int) (yysemantic_stack_[(12) - (9)].adouble);
            unsigned char interpolate=(unsigned char) (yysemantic_stack_[(12) - (11)].adouble);

            GET_VARSTACK_VALUE(InrImage,im);
            InrImage::ptr res ( Func_Resize(im.get(),sx,sy,sz,interpolate));
            ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 8870 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());

      FloatMatrix m(4,4);
      m[0][0] =  (yysemantic_stack_[(30) - (7)].adouble);
      m[0][1] =  (yysemantic_stack_[(30) - (9)].adouble);
      m[0][2] =  (yysemantic_stack_[(30) - (11)].adouble);
      m[0][3] =  (yysemantic_stack_[(30) - (13)].adouble);
      m[1][0] =  (yysemantic_stack_[(30) - (15)].adouble);
      m[1][1] =  (yysemantic_stack_[(30) - (17)].adouble);
      m[1][2] =  (yysemantic_stack_[(30) - (19)].adouble);
      m[1][3] =  (yysemantic_stack_[(30) - (21)].adouble);
      m[2][0] =  (yysemantic_stack_[(30) - (23)].adouble);
      m[2][1] =  (yysemantic_stack_[(30) - (25)].adouble);
      m[2][2] =  (yysemantic_stack_[(30) - (27)].adouble);
      m[2][3] =  (yysemantic_stack_[(30) - (29)].adouble);

      InrImage::ptr im1 ( varim1->Pointer());
      InrImage::ptr im2 ( varim2->Pointer());

      InrImage::ptr res ( Func_ReSlice(im1.get(),im2.get(),m));
      ADD_VARSTACK_PTR(InrImage,res);

    }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 8896 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      int   order = (int) (yysemantic_stack_[(8) - (5)].adouble);
      float resolution = (yysemantic_stack_[(8) - (7)].adouble);
      GET_VARSTACK_VALUE(InrImage,input);

      InrImage::ptr res ( Func_vtkConvexHull(input.get(),
                   order,resolution));

      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 8907 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);

      InrImage::ptr res ( AMIFluid::Func_Altitude2Position(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 8914 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      InrImage::ptr res ( AMIFluid::Func_Altitude2Position(im.get()));
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 8920 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      InrImage::ptr res ( AMIFluid::Func_GeoCoordinates(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 8926 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im.get());
      ADD_VARSTACK(InrImage,res);
    }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 8933 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**

        Description:
          Compute the altitude to the sea level based on the
          infrared channel.

        Parameters:
          (3) image containing the infrared channel
          (5) image containing 5 coefficients for the computation
              of the temperature and of the altitude,

        Keywords:
          Fluid

        **/
      GET_VARSTACK_VALUE(InrImage,coeff);
      GET_VARSTACK_VALUE(InrImage,input);
      InrImage* res;

      res = AMIFluid::Func_ComputeAltitudes(input.get(),coeff.get());
      ADD_VARSTACK(InrImage,res);

    }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 8958 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**

        Description:
        Compute the altitude to the sea level based on the
        temperature channel.

        Parameters:
        (3) image containing the temperature at the top of the clouds
        in Kelvin.

        **/
      GET_VARSTACK_VALUE(InrImage,input);
      InrImage::ptr res ( AMIFluid::Func_Temp2Altitudes(input.get()));
      ADD_VARSTACK_PTR(InrImage,res);

    }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 8976 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));
      InrImage::ptr res( AMIFluid::Func_ReadFlow(filename.get()));
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 8983 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**

      Description:
        Trying the slicing procedure to incorporate into the
        image drawing class

      Parameters:
        (3) image to slice
        (5) width orientation 1,2,3 for XY, XZ, ZY
        (7) height orientation
        (9,11,13) cursor position
        (15) expected width
        (17) expected height

        **/
        GET_VARSTACK_VALUE(InrImage,im);

        if (im->_format==WT_UNSIGNED_CHAR) {
          ImageDraw<unsigned char> imdraw;
          imdraw.SetInput((unsigned char*)im->GetData(),im->DimX(),im->DimY(),im->DimZ());
          imdraw.SetVoxelSize(im->VoxSizeX(),im->VoxSizeY(),im->VoxSizeZ());
          imdraw.SetCursorPosition((int)(yysemantic_stack_[(18) - (9)].adouble),(int)(yysemantic_stack_[(18) - (11)].adouble),(int)(yysemantic_stack_[(18) - (13)].adouble));
          imdraw.Apply((int)(yysemantic_stack_[(18) - (5)].adouble),(int)(yysemantic_stack_[(18) - (7)].adouble),(int)(yysemantic_stack_[(18) - (15)].adouble),(int)(yysemantic_stack_[(18) - (17)].adouble));
          // copy to RGB image
          InrImage::ptr res ( new InrImage(imdraw.RGB_width, imdraw.RGB_height, 1, WT_RGB));
          memcpy(res->GetData(),imdraw.RGB_image,imdraw.RGB_width*imdraw.RGB_height*3);
          ADD_VARSTACK_PTR(InrImage,res);
        } else
          fprintf(stderr,"only UCHAR format for now \n");
        }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 9016 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3) input PolyData containing lines to reconstruct
      (5) reference image for reconstruction
      (7) image of the radii associated to each point of the input PolyData (1D image)
    Description:
      Tubular reconstruction based on a set of lines and an estimated radius
      size for each point
    **/
      GET_VARSTACK_VALUE(InrImage,rad);
      GET_VARSTACK_VALUE(InrImage,ref);
      GET_VARSTACK_OBJECT(SurfacePoly,surf)

      InrImage::ptr res ( LineRecons( surf.get(), ref.get(), rad.get()));
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 9035 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3) input line read with ReadCTALine
      (5) name of the file
    Description:
      Reads the radius information and save it to an image,
      returns this image.
    **/
      GET_VARSTACK_OBJECT(SurfacePoly,surf)
      boost::shared_array<char> filename( (yysemantic_stack_[(6) - (5)].astring));

      InrImage::ptr res ( Func_ReadCTALineRadii( surf.get(), filename.get()));
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 9084 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
    Description: adds a reference to the variable in the stack
    **/
    BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->NewReference());
  }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 9093 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        primary_expr_string value to a string variable
      TODO: get completely rid of char* values
    **/
    string_ptr varstr(new std::string((yysemantic_stack_[(1) - (1)].astring)));
    Variable<std::string>::ptr new_var(new Variable<std::string>(varstr));
    driver.var_stack.AddVar(new_var);
  }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 9121 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
        Description:
          Returns an AMIObject of type WrapClass_VarVector
          containing 4 SurfacePoly variables.
          Kept for compatibility.
       **/
      int initial_size = (yysemantic_stack_[(4) - (3)].adouble);
      BasicVariable::ptr v = CreateVar_SurfacePoly( new SurfacePoly());

      // Now create the vector 
      VarVector* vv = new VarVector();
      if ((initial_size>0)&&(v.get()))  {
        for (int i=0; i<initial_size; i++)
          vv->push_back(v->NewCopy());
      }
      BasicVariable::ptr new_var = CreateVar_VarVector(vv);
      driver.var_stack.AddVar(new_var);
    }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 9142 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /** 
      Description:
        The 2 parameters can be either images or numbers,
        for 2 images:
          Returns the image corresponding to the pointwise maximum between 2 images.
        for 2 numbers:
          Returns the maximal value.


      See also:
              min, median
        **/

        BasicVariable::ptr param2(driver.var_stack.GetLastBasicVar());
        BasicVariable::ptr param1(driver.var_stack.GetLastBasicVar());

        if (param1.get()&&param2.get()) {
          if ((param1->IsNumeric())&&(param2->IsNumeric())) {
            double val1 = param1->GetValueAsDouble();
            double val2 = param2->GetValueAsDouble();
            double res = (val1>val2)?val1:val2;
            ADD_VARSTACK_FLOAT(res);
          }
          else
          if ((param1->Type()==type_image)&&(param2->Type()==type_image)) {
            DYNAMIC_CAST_VARIABLE(InrImage,param1,varim1) 
            DYNAMIC_CAST_VARIABLE(InrImage,param2,varim2) 

            InrImage::ptr im1(varim1->Pointer());
            InrImage::ptr im2(varim2->Pointer());
            double val1,val2;
            InrImage::ptr res;
            // TODO: take advantage of temporary images here??
            res = InrImage::ptr(new InrImage( im1->GetFormat(),
                                              im1->GetVDim(),
                                              "max_im_op.ami.gz",
                                              im1.get()));
            (*res) = (*im1);

            // TODO: use image iterator here
            res->InitBuffer();
            im2->InitBuffer();
            Repeter
              val1 = res->ValeurBuffer();
              val2 = im2->ValeurBuffer();
              Si val2>val1 AlorsFait res->FixeValeur(val2);
              im2->IncBuffer();
            JusquA Non(res->IncBuffer())
            FinRepeter
            Variable<InrImage>::ptr new_var(new Variable<InrImage>(res));
            driver.var_stack.AddVar(new_var);
          }
          else {
            driver.err_print("max operator with these types of parameters not available");
            YYABORT;
          }
        }

      }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 9204 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
          Description: 
            Call to a function, returning a variable
        **/
        //cout << "call to variable T_OP_PAR param_list T_CL_PAR end_instr" << endl;
        // 1. check the variable type
        GET_CHECK_VARSTACK(var)
        ParamList::ptr param((yysemantic_stack_[(4) - (3)].paramlist));

        // TODO: run this with overloading from BasicVariable ...
        if (var->Type()==type_class_member) {
          ///    Call a wrapped C++ class member.
          DYNAMIC_CAST_VARIABLE(WrapClassMember,var, var1);
          BasicVariable::ptr res ((var1->Pointer())->CallMember(param.get()));
          /*
          if (!res.get()) {
            driver.yyiperror("Class member does not return a variable \n");
            YYABORT;
          }
          */
          driver.var_stack.AddVar(res);

        } else
        if (var->Type()==type_ami_function) 
        {
          ///    Call a language function with its parameters.
          DYNAMIC_CAST_VARIABLE(AMIFunction,var, var1);
          AMIFunction::ptr f(var1->Pointer());
          BasicVariable::ptr res(driver.yyip_call_function(f,param));
          /* don't be so strict ...
          if (!res.get()) {
            driver.yyiperror("Ami function does not return a variable \n");
            YYABORT;
          }
          */
          driver.var_stack.AddVar(res);

        } else
        if (var->Type()==type_c_function) 
        {
          DYNAMIC_CAST_VARIABLE(C_wrap_varfunction,var, func);
          BasicVariable::ptr  res;
          res = (*func->Pointer())(param.get());
          /*
          if (!res.get()) {
            driver.yyiperror(" function returns NULL \n");
            YYABORT;
          }
          */
          driver.var_stack.AddVar(res);
        } else
        if (var->Type()==type_c_procedure) 
        {
          DYNAMIC_CAST_VARIABLE(C_wrap_procedure,var, func);
          BasicVariable::ptr  res;
          (*func->Pointer())(param.get());
          driver.var_stack.AddVar(res);
        } else
        if (var->Type()==type_c_image_function) 
        {
          DYNAMIC_CAST_VARIABLE(C_wrap_imagefunction,var, func);
          InrImage::ptr  im((*func->Pointer())(param.get()));
          if (!im.get()) {
            driver.yyiperror(" image function returns NULL \n");
            YYABORT;
          }
          Variable<InrImage>::ptr res(new Variable<InrImage>(im));
          driver.var_stack.AddVar(res);
        } else
        {
          // error message here
          driver.yyiperror("variable is not of a function type \n");
          driver.var_stack.AddVar(BasicVariable::ptr());
        }
      }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 9287 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
          Description: 
            Call to a function, returning a variable
        **/
        //cout << "call to variable T_OP_PAR param_list T_CL_PAR end_instr" << endl;
        // 1. check the variable type
        GET_CHECK_VARSTACK(var)
        ParamList::ptr param((yysemantic_stack_[(4) - (3)].paramlist));

        // TODO: run this with overloading from BasicVariable ...
        if (var->Type()==type_class_member) {
          ///    Call a wrapped C++ class member.
          DYNAMIC_CAST_VARIABLE(WrapClassMember,var, var1);
          BasicVariable::ptr res ((var1->Pointer())->CallMember(param.get()));
          /*
          if (!res.get()) {
            driver.yyiperror("Class member does not return a variable \n");
            YYABORT;
          }
          */
          driver.var_stack.AddVar(res);

        } else
        if (var->Type()==type_ami_function) 
        {
          ///    Call a language function with its parameters.
          DYNAMIC_CAST_VARIABLE(AMIFunction,var, var1);
          AMIFunction::ptr f(var1->Pointer());
          BasicVariable::ptr res(driver.yyip_call_function(f,param));
          /* don't be so strict ...
          if (!res.get()) {
            driver.yyiperror("Ami function does not return a variable \n");
            YYABORT;
          }
          */
          driver.var_stack.AddVar(res);

        } else
        if (var->Type()==type_c_function) 
        {
          DYNAMIC_CAST_VARIABLE(C_wrap_varfunction,var, func);
          BasicVariable::ptr  res;
          res = (*func->Pointer())(param.get());
          /*
          if (!res.get()) {
            driver.yyiperror(" function returns NULL \n");
            YYABORT;
          }
          */
          driver.var_stack.AddVar(res);
        } else
        if (var->Type()==type_c_procedure) 
        {
          DYNAMIC_CAST_VARIABLE(C_wrap_procedure,var, func);
          BasicVariable::ptr  res;
          (*func->Pointer())(param.get());
          driver.var_stack.AddVar(res);
        } else
        if (var->Type()==type_c_image_function) 
        {
          DYNAMIC_CAST_VARIABLE(C_wrap_imagefunction,var, func);
          InrImage::ptr  im((*func->Pointer())(param.get()));
          if (!im.get()) {
            driver.yyiperror(" image function returns NULL \n");
            YYABORT;
          }
          Variable<InrImage>::ptr res(new Variable<InrImage>(im));
          driver.var_stack.AddVar(res);
        } else
        {
          // error message here
          driver.yyiperror("variable is not of a function type \n");
          driver.var_stack.AddVar(BasicVariable::ptr());
        }
      }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 9364 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Logical negation (NOT) operator.
    **/
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(!(*var));
  }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 9372 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Postfix increment operator.
    **/
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar((*var)++);
  }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 9380 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Postfix decrement operator.
    **/
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar((*var)--);
  }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 9388 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Transpose operator, usefull for matrices
    **/
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->Transpose());
  }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 9398 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        Rule to apply image[image_extent]
    **/
    GET_VARSTACK_OBJECT2(ImageExtent, ImageExtent<float>, extent)
    GET_VARSTACK_VALUE(InrImage,im);

    if (!im.get()) {
      driver.err_print("var[image_extent], input variable is not an image.");
      YYABORT;
    }

    //extent->print();
    extent->SetRelative(im.get());

    //extent->print();
    //cout << "xmax = " << (int)  extent->Xmax() << endl;
    //cout << "xmax = " << (int)  round((double)extent->Xmax()) << endl;
    InrImage::ptr res ( Func_SubImage( im.get(),
                (int)  round((double)extent->Xmin()),
                (int)  round((double)extent->Ymin()),
                (int)  round((double)extent->Zmin()),
                (int)  round((double)extent->Xmax()),
                (int)  round((double)extent->Ymax()),
                (int)  round((double)extent->Zmax())
                ));
    if (!res.get()) {
      driver.err_print("SubImage() Error ... ");
      YYABORT;
    }
    else {
      Variable<InrImage>::ptr new_var(new Variable<InrImage>(res));
      driver.var_stack.AddVar(new_var);
    }

  }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 9437 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Array subscript operator.
    **/
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)[var2]);
  }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 9451 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Cast operator.
    **/
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->BasicCast( (yysemantic_stack_[(4) - (2)].aint)));

  }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 9460 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    //cout << "T_SUB  cast_var  " << endl;
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(-(*var));
  }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 9466 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(+(*var));
  }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 9471 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(++(*var));
  }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 9476 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(--(*var));
  }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 9481 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_sin());
  }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 9486 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_cos());
  }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 9491 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_sqrt());
  }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 9496 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_fabs());
  }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 9501 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_round());
  }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 9506 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_floor());
  }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 9511 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_tan());
  }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 9516 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_asin());
  }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 9521 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_acos());
  }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 9526 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_atan());
  }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 9531 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_exp());
  }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 9536 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_log());
  }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 9541 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_ln());
  }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 9546 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_norm());
  }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 9556 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)*var2);
  }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 9562 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)/var2);
  }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 9568 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)%var2);
  }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 9579 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    BasicVariable::ptr res(*var1+var2);
    driver.var_stack.AddVar(res);
  }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 9586 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    BasicVariable::ptr res((*var1)-var2);
    driver.var_stack.AddVar(res);
  }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 9601 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)<var2);
  }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 9607 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)>var2);
  }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 9613 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)<=var2);
  }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 9619 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)>=var2);
  }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 9629 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)==var2);
  }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 9635 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)!=var2);
  }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 9676 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Descriptiopn: Logical AND operator
    **/
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)&&var2);
  }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 9689 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Descriptiopn: Logical XOR operator, for vectorial images it defines the pointwise vectorial product.
    **/
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)^var2);
  }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 9702 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Descriptiopn: Logical OR operator
    **/
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)||var2);
  }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 9715 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Descriptiopn: Operation (cond?a:b) like in C/C++.
    **/
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->TernaryCondition(var1,var2));
  }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 9729 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    //cout << "assignment_var" << endl;
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    if (var1->GetPtrCounter()==1) {
      // TODO: here ...
    }
    driver.var_stack.AddVar((*var1)=var2);
  }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 9739 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    //cout << "assignment_var" << endl;
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1).left_assign(var2));
  }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 9746 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)+=var2);
  }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 9752 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)-=var2);
  }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 9758 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)*=var2);
  }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 9764 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)/=var2);
  }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 9776 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
            GET_VARSTACK_VALUE(GLTransfMatrix,glt);
            GLTransfMatrix* newglt;

            newglt = new GLTransfMatrix();
            (*newglt) = (*glt);
            driver.gltransf_stack.AddMatrix(newglt);
    
        }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 9787 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          GLTransfMatrix glt;
          GLTransfMatrix* newglt;
  
          printf("GetTransform begin \n");
          newglt = new GLTransfMatrix();
              glt = (varsurfd->Pointer())->GetCanvas()->GetObjectTransform();
          (*newglt) = (glt);
          driver.gltransf_stack.AddMatrix(newglt);
          printf("GetTransform \n");
      }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 9801 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(GLTransfMatrix,glt2);
        GET_VARSTACK_VALUE(GLTransfMatrix,glt1);
        GLTransfMatrix* newglt = NULL;
        float coeff = (yysemantic_stack_[(8) - (7)].adouble);

        newglt = Func_InterpolateTransform(glt1.get(),glt2.get(),coeff);
        driver.gltransf_stack.AddMatrix(newglt);
      }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 9812 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));
         GLTransfMatrix* newglt;
         newglt = Func_ReadTransform(filename.get());
         if (newglt!=NULL)
           driver.gltransf_stack.AddMatrix(newglt);
         else {
           fprintf(stderr,"TRANSFORM() Error reading file ...\n");
           driver.err_print("TRANSFORM() Error reading file ...\n");
           driver.gltransf_stack.AddMatrix(NULL);
           //          yyiperror(
           //          YYABORT;
         }
      }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 9830 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
         FloatMatrix::ptr m( new FloatMatrix((int)(yysemantic_stack_[(6) - (3)].adouble),(int)(yysemantic_stack_[(6) - (5)].adouble)));
         ADD_VARSTACK_PTR(FloatMatrix,m);
      }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 9836 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Description: adds a reference to the variable in the stack
        **/
        BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
        driver.var_stack.AddVar(var->NewReference());
      }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 9845 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
         Inversion of a symmetric matrix
          TODO: make a real inversion, for now it is a tranpose ...
        **/

        BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
        if (var->Type()==type_matrix)  {
          DYNAMIC_CAST_VARIABLE(FloatMatrix,var,varmat) 
          FloatMatrix::ptr res(varmat->Pointer()->Transpose());
          ADD_VARSTACK_PTR(FloatMatrix,res);
        } else {
          driver.err_print("Expecting an matrix variable here ... \n");
          YYABORT;
        }

      }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 9990 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf;
      GET_VARSTACK_VALUE(InrImage,im);
      surf = Func_isosurf(im,
              (yysemantic_stack_[(6) - (5)].adouble),
              NULL);
      if (surf==NULL) {
        driver.err_print("Isosurface failed!");
        YYABORT;
      }
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 10005 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      SurfacePoly* surf;
      surf = Func_isosurf(im,
              (yysemantic_stack_[(6) - (5)].adouble),
              NULL,
              2);
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 10017 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        image expression: input image
        expression:       isosurface threshold
        image variable:   mask
      Description:
        Computed isosurface of the input image with a given threshold within a region
        defined by the mask image.
    **/
      GET_VARSTACK_VALUE(InrImage, mask);
      GET_VARSTACK_VALUE(InrImage, im);
      SurfacePoly* surf;
      surf = Func_isosurf(im,
              (yysemantic_stack_[(8) - (5)].adouble),
              mask.get());
      if (surf==NULL) driver.err_print("Isosurface failed!");
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 10039 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
     Parameters:
        (3) input image
        (5) Gaussian standard deviation
        (7) mask

     Description:
        Computes the centerlines of bright tubular structures
        as zero-crossing of the gradient vector field in the planes
        of the 2 eigenvectors of the Hessian matrix that
        correspond to the lowest and negative eigenvalues
     **/
      GET_VARSTACK_VALUE(InrImage,mask);
      GET_VARSTACK_VALUE(InrImage,im);
      vtkPolyData* vtklines;
      CreeCrest* crestlines;
      SurfacePoly* lines;

      crestlines = Func_IsoLine(im.get(), (yysemantic_stack_[(8) - (5)].adouble), mask.get());
      printf("running conversion to vtkPolyData ...");
      vtklines = (vtkPolyData*) (*crestlines);

      lines = new SurfacePoly(vtklines);
      if (lines == NULL) {
        driver.err_print("IsoLine failed!");
        YYABORT;
      }

      BasicVariable::ptr res(CreateVar_SurfacePoly(lines));
      driver.var_stack.AddVar(res);

      delete crestlines;
    }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 10075 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_OBJECT(SurfacePoly,varsurf)
      SurfacePoly* surf;
      surf = Func_decimate( varsurf.get());
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 10084 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* newsurf;
      GET_VARSTACK_OBJECT(SurfacePoly,varsurf)

      newsurf = Func_decimate( varsurf.get(), (yysemantic_stack_[(6) - (5)].adouble) );
      BasicVariable::ptr res(CreateVar_SurfacePoly(newsurf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 10094 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf;
      GET_VARSTACK_VALUE(InrImage, im);
      surf = Func_vtkMarchingCubes(im.get(),(yysemantic_stack_[(6) - (5)].adouble));
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 10103 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* newsurf;
      GET_VARSTACK_OBJECT(SurfacePoly,surf)

      newsurf = Func_vtkSmooth(surf.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      BasicVariable::ptr res(CreateVar_SurfacePoly(newsurf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 10113 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_OBJECT(SurfacePoly,surf)
      SurfacePoly* newsurf;

      newsurf = Func_vtkWindowedSinc( surf.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      if (newsurf==NULL) {
        driver.err_print("vtkWindowedSinc failed!");
        YYABORT;
      }
      BasicVariable::ptr res(CreateVar_SurfacePoly(newsurf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 10127 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf = new SurfacePoly();
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 10134 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(2) - (2)].astring));
      SurfacePoly* surf = new SurfacePoly();
      surf->Read(filename.get());
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 10143 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (3): input filename (text file)
        Description:
            Reads a line given described in a text file
            format used in the CTA coronary segmentation challenge
        **/
        boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));
        SurfacePoly* surf;
        surf = Func_ReadCTALine(filename.get());
        BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
        driver.var_stack.AddVar(res);
      }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 10159 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (3): input filename (text file)
            (5) line type:  0: point + radius + standard dev
                            1: point
        Description:
            Reads a line given described in a text file
            format used in the CTA coronary segmentation challenge
        **/
        SurfacePoly* surf;
        boost::shared_array<char> filename( (yysemantic_stack_[(6) - (3)].astring));

        surf = Func_ReadCTALine(filename.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
        BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
        driver.var_stack.AddVar(res);
      }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 10178 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Creates lines from a skeleton image
        **/
        SurfacePoly* surf;

        GET_VARSTACK_VALUE(InrImage, im);
        surf = Func_Skeleton2lines( im.get()  );
  
        if (surf==NULL) {
          driver.err_print("Skeleton2lines() error ... \n");
          YYABORT;
        } else {
          BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
          driver.var_stack.AddVar(res);
        }
    }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 10198 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3) input polydata
    Description:
      Smooth lines based on a simple scheme of heat diffusion
      with data attachment (applied to each coordinate)
      using default parameters of
        smoothing coeff 0.1
        data coeff      0.01
        iterations      10
    **/
      GET_VARSTACK_OBJECT(SurfacePoly,insurf)
      SurfacePoly* surf;

      surf = Func_SmoothLines( insurf.get(),
                      0.1,
                      0.01,
                      10);

      if (surf==NULL) {
        driver.err_print("SmoothLines() error ... \n");
        YYABORT;
      } else {
        BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
        driver.var_stack.AddVar(res);
      }
    }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 10228 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3) input polydata
      (5) smoothing coefficient
      (7) data attachment coefficient
      (9) number of iterations
    Description:
      Smooth lines based on a simple scheme of heat diffusion
      with data attachment
    **/
      GET_VARSTACK_OBJECT(SurfacePoly,insurf)
      SurfacePoly* surf;

      surf = Func_SmoothLines( insurf.get(),
                      (yysemantic_stack_[(10) - (5)].adouble),
                      (yysemantic_stack_[(10) - (7)].adouble),
                      (int) (yysemantic_stack_[(10) - (9)].adouble));

      if (surf==NULL) {
        driver.err_print("SmoothLines() error ... \n");
        YYABORT;
      } else {
        BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
        driver.var_stack.AddVar(res);
      }
    }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 10257 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_OBJECT(SurfacePoly,insurf)
      SurfacePoly* surf;

      surf = Func_ResampleLines( insurf.get(),
                     (yysemantic_stack_[(6) - (5)].adouble));

      if (surf==NULL) {
        driver.err_print("ResampleLines() error ... \n");
        YYABORT;
      } else {
        BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
        driver.var_stack.AddVar(res);
      }
    }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 10275 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        - input polydata containing lines
        - point 1: x,y,z
        - point 2: x,y,z 
      Description:
        Finds the shortest path within the lines of the polydata
    **/
      GET_VARSTACK_OBJECT(SurfacePoly,insurf)
      SurfacePoly* surf;

      surf = Func_shortestpath( insurf.get(),
                      (yysemantic_stack_[(16) - (5)].adouble), (yysemantic_stack_[(16) - (7)].adouble), (yysemantic_stack_[(16) - (9)].adouble),
                      (yysemantic_stack_[(16) - (11)].adouble),(yysemantic_stack_[(16) - (13)].adouble),(yysemantic_stack_[(16) - (15)].adouble));

      Si surf==NULL Alors
        driver.err_print("Func_shortestpath () error ... \n");
        YYABORT;
      FinSi
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 10301 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3) input image
      (5) threshold to discard voxels
      (7)  X position of the first point
      (9)  Y position of the first point
      (11) Z position of the first point
      (13) X position of the second point
      (15) Y position of the second point
      (17) Z position of the second point
    Description:
      Finds the shortest path within the image voxels
      where the image intensity values are used to weight the edges of the graph,
      voxels are linked if their intensities are lower than the given threshold
      creates a path between the first and the second points if it exists
    **/
      GET_VARSTACK_VALUE(InrImage,im);
      SurfacePoly* surf;

      surf = Func_shortestpath_image(  im.get(),(yysemantic_stack_[(18) - (5)].adouble),
                                      (yysemantic_stack_[(18) - (7)].adouble), (yysemantic_stack_[(18) - (9)].adouble), (yysemantic_stack_[(18) - (11)].adouble),
                                      (yysemantic_stack_[(18) - (13)].adouble),(yysemantic_stack_[(18) - (15)].adouble),(yysemantic_stack_[(18) - (17)].adouble));

      Si surf==NULL Alors
        driver.err_print("Func_shortestpath_image () error ... \n");
        YYABORT;
      FinSi
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 10334 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3) input image containing the tracks as indices:
          voxel index of the preceding voxel
      (5) X coord of the starting point
      (7) Y coord of the starting point
      (9) Z coord of the starting point

    Description:
      Creates a path starting at a point in voxel coordinates
      and following the (integer) displacements given by the input vector field
      image
    **/
      GET_VARSTACK_VALUE(InrImage,im);
      SurfacePoly* surf;

      surf = Func_path_from_displ(  im.get(),
          (int) round((yysemantic_stack_[(10) - (5)].adouble)),
          (int) round((yysemantic_stack_[(10) - (7)].adouble)),
          (int) round((yysemantic_stack_[(10) - (9)].adouble))
          );

      Si surf==NULL Alors
        driver.err_print("Func_path_from_displ() error ... \n");
        YYABORT;
      FinSi
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 10370 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3)  input image as a vector field in spatial coordinates
            or as a scalar potential
      (5) time step for the evolution
      (7) maximal Euclidean distance of the path
      (9)  X coord of the starting point (in spatial coord.)
      (11)  Y coord ---
      (13)  Z coord ---
      (15)  X coord of the expected end point (in spatial coord.)
      (17)  Y coord  ---
      (19)  Z coord  ---

    Description:
      Creates a path starting at a point in spatial coordinates
      and following the displacements given by the input vector field
      image
      if the input is scalar the corresponding vector field is computed
      from its gradient by local linear interpolation
      the tracking stops in one of the following cases:
        - the maximal distance is reached
        - the closest voxel to the current location has a negative intensity
        - the current gradient is very low
    **/
      GET_VARSTACK_VALUE(InrImage,im);
      SurfacePoly* surf;

      double start[3] = {(yysemantic_stack_[(20) - (9)].adouble),(yysemantic_stack_[(20) - (11)].adouble),(yysemantic_stack_[(20) - (13)].adouble)};
      double end[3] = {(yysemantic_stack_[(20) - (15)].adouble),(yysemantic_stack_[(20) - (17)].adouble),(yysemantic_stack_[(20) - (19)].adouble)};
      surf = Func_path_from_vectfield(  im,
                                        start,end,
                                        (yysemantic_stack_[(20) - (5)].adouble), (yysemantic_stack_[(20) - (7)].adouble));

      Si surf==NULL Alors
        driver.err_print("Func_path_from_vectfield() error ... \n");
        YYABORT;
      FinSi
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 10416 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3)  input image as a vector field in spatial coordinates
            or as a scalar potential
      (5) time step for the evolution
      (7) maximal Euclidean distance of the path
      (9)  X coord of the starting point (in spatial coord.)
      (11)  Y coord ---
      (13)  Z coord ---

    Description:
      Creates a path starting at a point in spatial coordinates
      and following the displacements given by the input vector field
      image
      if the input is scalar the corresponding vector field is computed
      from its gradient by local linear interpolation
      the tracking stops in one of the following cases:
        - the maximal distance is reached
        - the closest voxel to the current location has a negative intensity
        - the current gradient is very low
    **/
      GET_VARSTACK_VALUE(InrImage,im);
      SurfacePoly* surf;

      double start[3] = {(yysemantic_stack_[(14) - (9)].adouble),(yysemantic_stack_[(14) - (11)].adouble),(yysemantic_stack_[(14) - (13)].adouble)};
      surf = Func_path_from_vectfield(  im,
                                        start,
                                        (yysemantic_stack_[(14) - (5)].adouble), (yysemantic_stack_[(14) - (7)].adouble));

      Si surf==NULL Alors
        driver.err_print("Func_path_from_vectfield() error ... \n");
        YYABORT;
      FinSi
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 10454 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_VARSTACK_VALUE(InrImage,im);
      SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get());
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 10463 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          /**

        Description:
      creates a flat triangulates mesh from the image domain,
      discarding pixels with null intensity.

        Parameters:
        (3) input image
        (5) triangle orientation:
            1: following X^Y
            other value: following -X^Y

          **/
      GET_VARSTACK_VALUE(InrImage,im);
          SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get(), (int) (yysemantic_stack_[(6) - (5)].adouble) );
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 10485 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      float minth = (yysemantic_stack_[(8) - (5)].adouble);
      float maxth = (yysemantic_stack_[(8) - (7)].adouble);
          SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get(),minth,maxth);
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 10496 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      SurfacePoly* surf;
      float minth = (yysemantic_stack_[(8) - (5)].adouble);
      float maxth = (yysemantic_stack_[(8) - (7)].adouble);

      surf = AMIFluid::Func_vtkCreateFlatMesh(im.get(),minth,maxth);
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 10507 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          CreateVolume creates a close surface composed of 2 surfaces:
          a top and a bottom, where each surface is calculated by converting
          the pixel position of 3D positions based on the 2 last parameters.
          It scans all the points of the 2D image,
          and uses their coordinates (x,y) to deduce a position in
          the input image, and interpolate a value.
            - the 2 last parameters are 2D images of 3D vectors, those vectors are used
            to set new positions (x,y,z) for each vertex of the mesh.

        Parameters:
        (3) input surface
        (5) minimal intensity value of the region of interest
        (7) maximal intensity value of the region of interest
        (9) 3D vector field image for the lower positions
        (11) 3D vector fiels image for the higher positions

       See also:
         CreateFlatMesh, ElevateMesh
         changes the position of the nodes of a 3D mesh

        **/
      GET_VARSTACK_VALUE(InrImage,highpos);
      GET_VARSTACK_VALUE(InrImage,lowpos);
      GET_VARSTACK_VALUE(InrImage,input);
      SurfacePoly* surf;
      float minth = (yysemantic_stack_[(12) - (5)].adouble);
      float maxth = (yysemantic_stack_[(12) - (7)].adouble);

      surf = AMIFluid::Func_CreateVolume(input.get(), minth, maxth, lowpos.get(), highpos.get());
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 10543 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          CreateVolume creates a closed surface composed of 2 surfaces:
          a top and a bottom, where each surface is calculated by converting
          the pixel position of 3D positions based on the 2 last parameters.
          It scans all the points of the 2D image,
          and uses their coordinates (x,y) to deduce a position in
          the input image, and interpolate a value.
            - the 2 last parameters are 2D images of 3D vectors, those vectors are used
            to set new positions (x,y,z) for each vertex of the mesh.

        Parameters:
        (3) input surface
        (5) minimal intensity value of the region of interest
        (7) maximal intensity value of the region of interest
        (9) 3D vector field image for the lower positions
        (11) 3D vector fiels image for the higher positions
        (13) RGB image to color the top surface or NULL if not used
        (15) alpha opacity value (in [0,1], 0 is fully transparent)


       See also:
         CreateFlatMesh, ElevateMesh
         changes the position of the nodes of a 3D mesh

        **/
      GET_VARSTACK_VALUE(InrImage,colors);
      GET_VARSTACK_VALUE(InrImage,highpos);
      GET_VARSTACK_VALUE(InrImage,lowpos);
      GET_VARSTACK_VALUE(InrImage,input);
      SurfacePoly* surf;
      float minth = (yysemantic_stack_[(16) - (5)].adouble);
      float maxth = (yysemantic_stack_[(16) - (7)].adouble);
      float alpha = (yysemantic_stack_[(16) - (15)].adouble);

      surf = AMIFluid::Func_CreateVolume(input.get(), minth, maxth, 
                                          lowpos.get(), highpos.get(), colors.get(), alpha);
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 10585 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          #1 expr_image:        altitudes1
          #2 expr_image:        displacement
          #3 expr_image:        altitudes2
          #4 expr:              stepx
          #5 expr:              stepy
          #6 expr:              scale
          #7 expr:              type

        Description:
        Creates a 3D vector field for visualization of the displacement of clouds
        between times t1 and t2.
        description of the input parameters:
        - altitudes1:    scalar image,    altitudes of the clouds at time t1
        - displacement:  vectorial image, displacement as a 2D vector field
        - altitudes2:    scalar image,    altitudes of the clouds at time t2
        - stepx:         spacing in pixels between successive vectors in X direction
        - stepy:         spacing in pixels between successive vectors in Y direction
        - scale:         scaling of the vectors
        - type:          0 for Altantic, 1 for Africa.

        Example(s):

        vects = CreateVectors(alt1,displ,alt2,8,8,3,1)


        See also:
                CreateFlatMesh, ElevateMesh, ComputeAltitudes, Altitudes2Position
      **/
      GET_VARSTACK_VALUE(InrImage,alt2);
      GET_VARSTACK_VALUE(InrImage,displ);
      GET_VARSTACK_VALUE(InrImage,alt1);
      int stepx   = (int) (yysemantic_stack_[(16) - (9)].adouble);
      int stepy   = (int) (yysemantic_stack_[(16) - (11)].adouble);
      float scale = (yysemantic_stack_[(16) - (13)].adouble);
      int   type  = (int) (yysemantic_stack_[(16) - (15)].adouble);
          SurfacePoly* surf;

      surf = AMIFluid::Func_CreateVectors(alt1.get(),displ.get(),alt2.get(), 
                                          stepx, stepy, scale, type);
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 10631 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          #1 expr_image:        altitudes1
          #2 expr_image:        displacement
          #3 expr_image:        altitudes2
          #4 expr:              stepx
          #5 expr:              stepy
          #6 expr:              scale
          #7 expr:              type
          expr:                 vector_style (in {0,1})

        Description:
        Creates a 3D vector field for visualization of the displacement of clouds
        between times t1 and t2.
        description of the input parameters:
        - altitudes1:    scalar image,    altitudes of the clouds at time t1
        - displacement:  vectorial image, displacement as a 2D vector field
        - altitudes2:    scalar image,    altitudes of the clouds at time t2
        - stepx:         spacing in pixels between successive vectors in X direction
        - stepy:         spacing in pixels between successive vectors in Y direction
        - scale:         scaling of the vectors
        - type:          0 for Altantic, 1 for Africa.
        - vector style   0: simple line, 1: 3D vector composed of 2 tetrahedra

        Example(s):

        vects = CreateVectors(alt1,displ,alt2,8,8,3,1,1)


        See also:
                CreateFlatMesh, ElevateMesh, ComputeAltitudes, Altitudes2Position
      **/
      GET_VARSTACK_VALUE(InrImage,alt2);
      GET_VARSTACK_VALUE(InrImage,displ);
      GET_VARSTACK_VALUE(InrImage,alt1);
      int stepx   = (int) (yysemantic_stack_[(18) - (9)].adouble);
      int stepy   = (int) (yysemantic_stack_[(18) - (11)].adouble);
      float scale = (yysemantic_stack_[(18) - (13)].adouble);
      int   type   = (int) (yysemantic_stack_[(18) - (15)].adouble);
      int   style  = (int) (yysemantic_stack_[(18) - (17)].adouble);
      SurfacePoly* surf;

      surf = AMIFluid::Func_CreateVectors(alt1.get(),
          displ.get(),
          alt2.get(), stepx, stepy, scale, type,style);
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 10681 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          #1 expr_image:        altitudes1
          #2 expr_image:        displacement
          #3 expr_image:        altitudes2
          #4 expr:              stepx
          #5 expr:              stepy
          #6 expr:              scale

        Description:
        Creates a 3D vector field for visualization of the displacement of clouds
        between times t1 and t2.
        description of the input parameters:
        - altitudes1:    scalar image,    altitudes of the clouds at time t1
        - displacement:  vectorial image, displacement as a 2D vector field
        - altitudes2:    scalar image,    altitudes of the clouds at time t2
        - stepx:         spacing in pixels between successive vectors in X direction
        - stepy:         spacing in pixels between successive vectors in Y direction
        - scale:         scaling of the vectors

        Example(s):

        vects = CreateVectors(alt1,displ,alt2,8,8,3)


        See also:
                CreateFlatMesh, ElevateMesh, ComputeAltitudes, Altitudes2Position
      **/
      GET_VARSTACK_VALUE(InrImage,alt2);
      GET_VARSTACK_VALUE(InrImage,displ);
      GET_VARSTACK_VALUE(InrImage,alt1);
      int stepx   = (int) (yysemantic_stack_[(14) - (9)].adouble);
      int stepy   = (int) (yysemantic_stack_[(14) - (11)].adouble);
      float scale = (yysemantic_stack_[(14) - (13)].adouble);
          SurfacePoly* surf;

      surf = AMIFluid::Func_CreateVectors(alt1.get(),displ.get(),alt2.get(), stepx, stepy, scale);
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 10723 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (3) expr_image:        displacement field in voxel coordinates
          (5) expr:              spacing between vectors in X direction
          (7) expr:              spacing between vectors in Y direction
          (9) expr:              spacing between vectors in Z direction
          (11) expr:             scale
          (13) vector style   0: simple line, 1: 3D vector composed of 2 tetrahedra

        Description:
        Creates a 3D vector field for visualization.

      **/
      GET_VARSTACK_VALUE(InrImage,displ);
      int stepx   = (int) (yysemantic_stack_[(14) - (5)].adouble);
      int stepy   = (int) (yysemantic_stack_[(14) - (7)].adouble);
      int stepz   = (int) (yysemantic_stack_[(14) - (9)].adouble);
      float scale = (yysemantic_stack_[(14) - (11)].adouble);
      int style = (int) (yysemantic_stack_[(14) - (13)].adouble);
      SurfacePoly* surf;

      stepx = macro_max(stepx,1);
      stepy = macro_max(stepy,1);
      stepz = macro_max(stepz,1);
      surf = AMIFluid::Func_CreateVectors(displ.get(), 
              stepx, stepy, stepz,  scale, style);
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 10754 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
        (3)  First  vector field v1
        (5)  Second vector field v2
        (7)  Third  vector field v3
        (9)  step in X dimension
        (11) step in Y dimension
        (13) step in Z dimension
        (15) resolution

    Description:
        Create 3D ellipsoids based on 3 vector fields
    **/
      GET_VARSTACK_VALUE(InrImage,v3);
      GET_VARSTACK_VALUE(InrImage,v2);
      GET_VARSTACK_VALUE(InrImage,v1);
      int stepx   = (int) (yysemantic_stack_[(16) - (9)].adouble);
      int stepy   = (int) (yysemantic_stack_[(16) - (11)].adouble);
      int stepz   = (int) (yysemantic_stack_[(16) - (13)].adouble);
      int res     = (int) (yysemantic_stack_[(16) - (15)].adouble);

          SurfacePoly* surf;

      surf = Func_CreateEllipsoids(v1.get(),
              v2.get(),
              v3.get(),
              stepx,stepy,stepz,res);
      BasicVariable::ptr varres(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(varres);
    }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 10786 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
        (3)  First  vector field v1
        (5)  Second vector field v2
        (7)  Third  vector field v3
        (9)  step in X dimension
        (11) step in Y dimension
        (13) step in Z dimension
        (15) resolution
        (17) RGB image for the colors
        (19) mask image

    Description:
        Create 3D ellipsoids based on 3 vector fields
    **/
      GET_VARSTACK_VALUE(InrImage,mask);
      GET_VARSTACK_VALUE(InrImage,colors);
      GET_VARSTACK_VALUE(InrImage,v3);
      GET_VARSTACK_VALUE(InrImage,v2);
      GET_VARSTACK_VALUE(InrImage,v1);

      int stepx   = (int) (yysemantic_stack_[(20) - (9)].adouble);
      int stepy   = (int) (yysemantic_stack_[(20) - (11)].adouble);
      int stepz   = (int) (yysemantic_stack_[(20) - (13)].adouble);
      int res     = (int) (yysemantic_stack_[(20) - (15)].adouble);

          SurfacePoly* surf;

      surf = Func_CreateEllipsoids( v1.get(),
                                    v2.get(),
                                    v3.get(),stepx,stepy,stepz,res,
                                    colors.get(),
                                    mask.get());
      BasicVariable::ptr varres(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(varres);
    }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 10844 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          // todo ... 
          // 1. check if identifier belongs to the object
          // 2. if so return corresponding variable
          Variable<AMIObject>::ptr var(driver.var_stack.GetLastVar<AMIObject>());
          AMIObject::ptr object(var->Pointer());
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (3)].ident));
          Variables::ptr previous_ocontext (Vars.GetObjectContext());
          Vars.SetObjectContext(object->GetContext());
    
          // here, need to do our own checking ...
          BasicVariable::ptr newvar( 
            Vars.GetVar(ident->GetName().c_str(),
            OBJECT_CONTEXT_NUMBER));

          // reset previous object context
          Vars.SetObjectContext(previous_ocontext);
    
          if  ((!GB_driver.procedure_declaration)&& newvar.get())   {
            //cout << "returning variable" << endl;
            //newvar->display();
            driver.var_stack.AddVar(newvar);
          } else {
            // error message here
            driver.yyiperror("Identifier does not belong to object context \n");
            YYABORT;
            //driver.var_stack.AddVar(BasicVariable::ptr());
          }
        }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 10912 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      ImageExtent<float>* extent=new ImageExtent<float>( (float)(yysemantic_stack_[(11) - (1)].adouble),(float)(yysemantic_stack_[(11) - (3)].adouble),(float)(yysemantic_stack_[(11) - (5)].adouble),
                          (float)(yysemantic_stack_[(11) - (7)].adouble),(float)(yysemantic_stack_[(11) - (9)].adouble),(float)(yysemantic_stack_[(11) - (11)].adouble));
      extent->SetMode(1); // relative
      BasicVariable::ptr res(CreateVar_ImageExtent(extent));
      driver.var_stack.AddVar(res);
    }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 10921 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      ImageExtent<float>* extent=new ImageExtent<float>((float)(yysemantic_stack_[(7) - (1)].adouble),(float)(yysemantic_stack_[(7) - (3)].adouble),(float)(yysemantic_stack_[(7) - (5)].adouble),(float)(yysemantic_stack_[(7) - (7)].adouble));
      extent->SetMode(1); // relative
      BasicVariable::ptr res(CreateVar_ImageExtent(extent));
      driver.var_stack.AddVar(res);
    }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 10929 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      #ifdef min
        #undef min
      #endif
      #ifdef max
        #undef max
      #endif
      float float_max = std::numeric_limits<float>::max();
      ImageExtent<float>* extent=new ImageExtent<float>(
          -float_max,float_max,
          -float_max,float_max,
          (float)(yysemantic_stack_[(7) - (5)].adouble),(float)(yysemantic_stack_[(7) - (7)].adouble));
      extent->SetMode(1); // relative
      BasicVariable::ptr res(CreateVar_ImageExtent(extent));
      driver.var_stack.AddVar(res);
    }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 10947 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);

      ImageExtent<float>* extent=new ImageExtent<float>();
      extent->SetMode(0); // absolute
      extent->SetXmin( im->SpacePosX(0));
      extent->SetXmax( im->SpacePosX(im->DimX()-1));
      extent->SetYmin( im->SpacePosY(0));
      extent->SetYmax( im->SpacePosY(im->DimY()-1));
      extent->SetZmin( im->SpacePosZ(0));
      extent->SetZmax( im->SpacePosZ(im->DimZ()-1));
      //extent->print();
      BasicVariable::ptr res(CreateVar_ImageExtent(extent));
      driver.var_stack.AddVar(res);
    }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 10964 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw = DessinImage::ptr(varimd->Pointer());
  
      int xmin,xmax;
      int ymin,ymax;
      int zmin,zmax;
      string comment;
  
      draw->GetZoom(xmin,ymin,zmin,xmax,ymax,zmax);
      ImageExtent<float>* extent=new ImageExtent<float>(xmin,xmax,ymin,ymax,zmin,zmax);
      extent->SetMode(1); // relative extent
  
      comment = str(format(" //  subvolume [%3d:%3d, %3d:%3d, %3d:%3d] ")
          % xmin % xmax % ymin % ymax % zmin % zmax);
      if (GB_debug) cerr << "********* extent ****" << endl;
      if (driver.InConsole()) GB_main_wxFrame->GetConsole()->IncCommand(comment);
  
      BasicVariable::ptr res(CreateVar_ImageExtent(extent));
      driver.var_stack.AddVar(res);
    }
    break;



/* Line 678 of lalr1.cc  */
#line 11635 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	default:
          break;
      }
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[0] = yylloc;
    if (yyerrstatus_ == 3)
      {
	/* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

	if (yychar <= yyeof_)
	  {
	  /* Return failure if at end of input.  */
	  if (yychar == yyeof_)
	    YYABORT;
	  }
	else
	  {
	    yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
	    yychar = yyempty_;
	  }
      }

    /* Else will try to reuse lookahead token after shifting the error
       token.  */
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;

    yyerror_range[0] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (yyn != yypact_ninf_)
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	YYABORT;

	yyerror_range[0] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[1] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval, &yylloc);

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (int yystate, int tok)
  {
    std::string res;
    YYUSE (yystate);
#if YYERROR_VERBOSE
    int yyn = yypact_[yystate];
    if (yypact_ninf_ < yyn && yyn <= yylast_)
      {
	/* Start YYX at -YYN if negative to avoid negative indexes in
	   YYCHECK.  */
	int yyxbegin = yyn < 0 ? -yyn : 0;

	/* Stay within bounds of both yycheck and yytname.  */
	int yychecklim = yylast_ - yyn + 1;
	int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
	int count = 0;
	for (int x = yyxbegin; x < yyxend; ++x)
	  if (yycheck_[x + yyn] == x && x != yyterror_)
	    ++count;

	// FIXME: This method of building the message is not compatible
	// with internationalization.  It should work like yacc.c does it.
	// That is, first build a string that looks like this:
	// "syntax error, unexpected %s or %s or %s"
	// Then, invoke YY_ on this string.
	// Finally, use the string as a format to output
	// yytname_[tok], etc.
	// Until this gets fixed, this message appears in English only.
	res = "syntax error, unexpected ";
	res += yytnamerr_ (yytname_[tok]);
	if (count < 5)
	  {
	    count = 0;
	    for (int x = yyxbegin; x < yyxend; ++x)
	      if (yycheck_[x + yyn] == x && x != yyterror_)
		{
		  res += (!count++) ? ", expecting " : " or ";
		  res += yytnamerr_ (yytname_[x]);
		}
	  }
      }
    else
#endif
      res = YY_("syntax error");
    return res;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const short int Parser::yypact_ninf_ = -1865;
  const short int
  Parser::yypact_[] =
  {
      5474, 10597,  9463,  9463,  9463, -1865, -1865, -1865,  9463,  9463,
    9463, -1865, -1865,    31,    85,    93, -1865, -1865, -1865, -1865,
    9841, -1865,   -27,    48, -1865,    28,  9463,  9463,  9463,    97,
    9463, -1865,   121,   147, -1865, -1865, -1865, -1865, -1865, -1865,
      16,     1, -1865,    -1, -1865, -1865, -1865, -1865, -1865,   122,
      -6,   104,   170,   392,  9463,   156, -1865, -1865, -1865, -1865,
     195,   199, 10219,  9463,   202,   136,   206,   159,   216,   219,
     238,   247,   278,   317,   329,   467,   468,   492,   507,   524,
     525,   534,   536,   537,   538,   539,   540, -1865, -1865, -1865,
   -1865,   541,   542,   543,   303,   307,   544,   545,   546,   547,
     549,   550,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   563,   565,   567,   568,   569,   570,   571,
     572,   235,   573,   574,   575,   576,   577,   579,   580,   581,
     582,   583,   584,   585,   587,   588,   593,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   628,   629,   631,   632,   633,
     634,   635,   636,   638,   639,   640,   641,   642,   643,   644,
     645,  7876,   646,   647,   648,   649,   651,   652, -1865, -1865,
   -1865, -1865, -1865, -1865, -1865, -1865, -1865, -1865, -1865,   654,
     655,   656,   657,   658, -1865, -1865,  9463,  9463,  9463,  9463,
    9463,  9463,  9463,  9463,  9463,  9463,  9463,  9463,  9463,  9463,
     122, -1865,   392, -1865,  9463,  7095,  9463,   659,   660,   661,
     662,    13,   122,   663,   664,   665,   666,   667,   668,   669,
     670,   671,   672,   675,   676,   677,   678,   679,   680,   681,
     682,   683,   684,   685, -1865, -1865, -1865,   686,   687,   701,
    5062, -1865, -1865, -1865, -1865, -1865, -1865, -1865,    39, -1865,
   -1865,   688,   128, -1865, -1865, -1865, -1865,    32, -1865,   191,
      15, -1865,     9,    20,   689, -1865,   690,   612,   698,    -4,
     -24, -1865, -1865,   151, -1865,   -29, -1865,   691, -1865, -1865,
    9463,   692,   693,   694,   696,   695,   697,   699,   154, -1865,
     691, -1865, -1865,    64,   703, -1865, -1865, -1865, -1865,  9463,
    9463,  9463,  9463, -1865, -1865, -1865, -1865, -1865, -1865, -1865,
   -1865, -1865, -1865, -1865, -1865, -1865, -1865, -1865,  9463, -1865,
     392,   392,   229,   -80,   630,   650,   -35,   377, -1865,   122,
   -1865,   -39,  9463, -1865, -1865, -1865, -1865, -1865, -1865, -1865,
     696, -1865,   695, -1865, -1865, -1865, -1865, -1865, -1865,   392,
    9463,  9463, -1865, -1865,  9463,  9463,  9463,  9463,  9463,  9463,
    9463,  9463,    28,  9463,  9463,    28,    28,    28,    28,    28,
    9463,    28,    28,    28,    28,    28,    28,    28,    28,    28,
    9463,  9463,    28,   358,   381,    28,    28,    28,    28,    28,
      28,    28,    28,    28,    28,  9463,    28,    28,    28,    28,
      28,    28,    28,    28,    28,    28,    28,    28,    28,    28,
    9463,  9463,  9463,  9463,  9463,  9463,  9463,    28,    28,    28,
      28,    28,    28,    28,    28,    28,   653,   673,    28,    28,
      28,    28,   674,  9463,  9463,  9463,   700,  9463,   702,  9463,
    9463,    28,    28,    28,   704,   705,    28,    28,    28,    28,
      28,    28,    28,    28,    28,    28,    28,  9463,  9463,  9463,
      28,  9463,  9463,    28,   706,    28,   707,   708,  9463,    28,
      28,  8279,  9463, -1865,  9463,  9463,    28,    28,    28,    28,
    9463,  9463,  9463,  9463,    28, -1865, -1865, -1865, -1865, -1865,
   -1865, -1865, -1865, -1865, -1865, -1865, -1865, -1865, -1865,  -101,
   -1865,   709, -1865, -1865, -1865,    39, -1865,   359,  9463,  9463,
     711, -1865, -1865,   710,  9463,  9463,    28,  9463,  9463,   282,
    9463,  9463,  9463,  9463,  9463,  9463,  9463,  9463,  9463,  9463,
    9463,  9463,  9463,   713,    28,    28,    28, -1865, -1865, -1865,
   -1865, -1865, -1865, -1865, -1865, -1865,    39, -1865,   332,  9463,
     -16,  6289,  8682, -1865, -1865, -1865,  9463,  9463,  9463,  9463,
    9463,  9463,  9463,  9463,  9463,  9463,  9463,  9463,  9463,  9463,
    9463,  9463,  9463,  9463,  9463,  9463,  9463,  9463,  9463,  9463,
     434,  9463,  5886,  6289,  -164,  -120,     8,  9463,   578,   586,
    9463,    26,  9463, -1865,   714,   715,   716,   134,   717,   719,
     721,   712,   723,   725,   727,   728,   729, -1865, -1865, -1865,
   -1865, -1865, -1865, -1865, -1865, -1865, -1865,   730,   731,   732,
   -1865,   735,   736,   737,   738, -1865,   739,   740,   741,   742,
     743,   744,   745,   746,   749,   750,   751, -1865, -1865,   752,
     755,   756,   757, -1865,   758,   759,   761,   764, -1865, -1865,
     765, -1865,   769, -1865,   770,   771,   772,   773,   774, -1865,
   -1865,  9463,  9463, -1865,   775,   776, -1865,   777, -1865, -1865,
    9463,   778,   779,   781,   780,   782, -1865,   783,   784,   785,
     788,   789,   790,   791,   792,   787,   793,   794,   795,   796,
     797,   798,   799,   800,   801,   802,   803,   804,   806,   807,
     808,   815,   810,   811,   812,   813,   821, -1865, -1865,   822,
   -1865, -1865,   823,   816,   818,   819,   820,   824,   825,   826,
     827,   828,   829,   836,   837,   838,   833,   840,   835,   839,
     841,   842,   843,    22,   844,   846,   845,   852,    82,   851,
     848,   849,   850,   853,   854,   855,   856,   857,   858,   859,
     860,   867,   862,   869,   187,   864,   865,   866,   868,   870,
     871,   872,   873,   874,   875,   210,   876,   883,   884,   879,
     880,   881,   882,   885,   886,   887,   888,   890,   892,   893,
     894,   895,   896,   897,   898,   889,   905,   906,   901,   902,
     192,   903,   904,   241,   907,   908,   909,   910,   911,   912,
   -1865,   915,   913,   918,   920,   921,   922,   923,   924,   919,
     925,   926,   927,  9463,  9463, -1865, -1865,   -13, -1865,   928,
     929,   930,   931,   933,   830,   891,   330,    39,   245,   932,
     934,   937,   938,   936,   248,   945,   948,   253,   257,   949,
     950,   958,   960,   962,   939,   971,   977,   972,   973,   974,
     978, -1865, -1865,   166,   985,   987, -1865,   988,   989, -1865,
   -1865,  9463, -1865,   990,   991,   992,   993,   994,   995,   996,
     997,   998, -1865, -1865, -1865, -1865, -1865, -1865, -1865, -1865,
   -1865, -1865, -1865, -1865, -1865,   392,   692,   693,   694,   258,
   -1865, -1865,  1000,   692,   834,   261,   999,  1001, -1865, -1865,
   -1865,   191,   191, -1865, -1865, -1865, -1865,     9,     9,    20,
   -1865,   690,   612,    -3,   698, -1865, -1865, -1865, -1865, -1865,
   -1865,  1006,  1003, -1865,  7473,  9085,  1020,  1016, -1865,  1023,
    1024,  1025,  1026,  1029, -1865, -1865,   262,  1035,    65, -1865,
    9463, -1865, -1865,  9463,  9463, -1865, -1865,  9463,  9463,  9463,
    9463,  9463,  9463,    28,  9463,  9463,    12,   733,   747,  9463,
    9463,  9463,  9463,  9463,  9463,  9463,  9463,  9463,   734,  9463,
     722,  9463,  9463,   768,  9463,  9463,  9463,  9463,  9463,   814,
     -25,   748,   753,  9463,  9463,  9463, -1865, -1865,  9463,   240,
    9463, -1865,   762,  9463, -1865,   786, -1865, -1865,  9463,  1027,
   -1865, -1865,  1039, -1865,  1040,    18,  9463,  9463, -1865,  9463,
    9463,  9463,  9463,  9463,    28,  9463,  9463,  9463,  9463,  9463,
    9463, -1865,  9463,  9463,  9463,    28,    28,    28, -1865,  9463,
    9463,  9463,  9463,  9463,  9463,  9463,  9463,    28,  9463, -1865,
   -1865, -1865,    28, -1865,    28,    28,    28,    28,    28, -1865,
      28,    28, -1865,  9463, -1865,  9463,  1041,  9463,  9463,  9463,
    9463,  9463,  9463,  9463,  9463,  9463,  9463,  9463, -1865,  9463,
   -1865, -1865,  9463,  9463,  9463,  9463,  9463,  9463,  9463,  9463,
    9463,  9463,    28, -1865,  9463,  9463, -1865, -1865,    28,    28,
      28,    28,    28,  9463,  9463,  9463,  9463,  9463,  9463,  9463,
    9463,  9463,  9463,  9463, -1865, -1865, -1865,  9463,  9463, -1865,
    9463,  9463, -1865,  9463,  9463,  9463,  9463,  9463, -1865, -1865,
   -1865,  9463, -1865, -1865, -1865, -1865, -1865, -1865,  9463,  9463,
    9463, -1865,   368,  1036, -1865, -1865, -1865, -1865, -1865, -1865,
   -1865,  9463, -1865,  -227,  -227,   720, -1865, -1865,  9463,  9463,
      28,  9463,  9463,    28, -1865,  9463,  9463,  9463, -1865,  9463,
   -1865,  9463,  9463,  9463,  9463,  9463,  9463, -1865, -1865, -1865,
    9463,  9463,    28,    28,  9463,  9463,  9463, -1865,  9463,  9463,
      28, -1865,    28,    28,  9463,  9463,  9463,  9463,  9463,  9463,
    9463, -1865, -1865,  6692,  1033,  9463,    10, -1865, -1865,  9463,
    9463,  9463, -1865, -1865,  9463,  9463,  -218,   940,  9463,  9463,
    9463,  9463, -1865, -1865,  1037,  1038,  1045,  1042,    92,  1043,
    1044,  1046,  1047,  1048,  1053,  1052,  1059,  1066,  1068,  1063,
    1074,  1075,  1077,  1078,  1085,  1086,  1081,  1082,  1083,  1084,
    1102,  1097,  1104,  1101,   265,  1116,  1117,  1112,  1115,  1118,
    1119,  1123,  1121,   267,  1129,  1124,  1125,  1126,  1133,  1134,
    1135,  1136,  1131,  9463,  1138,  1140,  1141,  9463,    28,    28,
     269,  1137,  1139,  1142,  1144,  1148,  1151,  1146,  1156,   270,
    1152,  1154,  1157,  1158,  1159,  1160,  1161,  1163,  1164,  1165,
    1169,  1170,  1174,  1175,  1183,  1184,  1185,  1186,  1188,  1189,
    1196,  1197,  1194,  1195,  1202,  1203,  1204,  1205,  1212,  1213,
    1208,  1215,  9463,  1216,  1217,  1218,  1214,  1219,  1220,  1221,
     272,  1222,  1223,  1224,  1225,  1226,  1230,  1233,  1234,  1235,
    1236,  1231,  1232,  1237,  1238,  1239,  1240,  1241,  1242,  1243,
    1244,  1245,  1246,  1247,  1248,  1255,  1256,  1257,  1258,  1259,
    1260,  1261,   279,  1262,  1263,  1264,   284,  1265,  1266,  1267,
    1271,  1272,  1268,  1273,  1269,  1270,  1274,  9463,  9463,    39,
      39,  1275,   953,   954,  1176,  1177,  1178,   289,   291, -1865,
    1277,  1276,  1278,  1279,  1280,  1281,   293,  1282,  1283,  1285,
    1290,  1286,  1287,  1288,  1289,  1291,  1292,  1296,  1293,  1294,
     105,  1295,  1297,  1302,  1298,   296,  1303,  1305,  1300,   204,
    1301,   208,  1308,   300,  1304,  1306,   301,   392, -1865, -1865,
    1307,  1309, -1865, -1865,  1311,  1310,  1312,  1317, -1865,  1313,
    1318,  1320,  1315, -1865,  9463,  9463, -1865,    28,  9463,  9463,
    9463,  9463, -1865,  9463, -1865,  9463, -1865, -1865, -1865,    28,
      28,  9463,  9463,  9463, -1865, -1865,  9463,  9463,  9463,  9463,
   -1865,  9463, -1865,  9463, -1865,  9463, -1865, -1865,  9463,  9463,
    9463,  9463, -1865,   443, -1865,  9463, -1865,    28,  9463,  9463,
   -1865, -1865, -1865, -1865,  1004, -1865, -1865, -1865, -1865,  1322,
    1323,   304, -1865,    96,    21,  9463, -1865, -1865, -1865, -1865,
    9463, -1865, -1865,    28,  9463,  9463,  9463,  9463,  9463,  9463,
    9463,  9463,  9463,  9463,  9463,  9463,  9463,  9463,  9463,  9463,
    9463,  9463,  9463,  9463, -1865, -1865,  9463,    28,    28,    28,
      28,    28, -1865, -1865,  9463, -1865,  1324, -1865, -1865, -1865,
    9463,  9463,  9463,  9463, -1865,  9463,  9463,  9463, -1865,  9463,
    9463, -1865, -1865, -1865, -1865, -1865,  9463,  9463,  9463,  9463,
    9463, -1865, -1865, -1865,  9463,  9463,    28,    28,  9463,  9463,
   -1865, -1865, -1865, -1865, -1865, -1865, -1865, -1865,  9463,  9463,
    9463,  9463, -1865,    28, -1865, -1865, -1865, -1865, -1865,  9463,
   -1865,  9463,  9463,  9463,   371, -1865, -1865, -1865,  9463, -1865,
   -1865, -1865, -1865, -1865, -1865,  -220, -1865,    39, -1865,  9463,
    9463, -1865,  9463,  9463, -1865,  9463,  9463,  9463, -1865, -1865,
    9463,  9463,  9463,  9463, -1865,  9463, -1865,    28,  9463, -1865,
    9463,  9463,  9463, -1865, -1865,  9463, -1865,  9463, -1865, -1865,
    9463, -1865,  9463, -1865, -1865, -1865,  9463,  9463,  9463, -1865,
    9463, -1865,  9463,  9463, -1865,  9463, -1865, -1865,  1179,  1319,
    1321,  1206,  1326,  1325,   244,  1327,  1328,  1329,  1330,  1331,
    1332,  1333,  1334,  1336,  1338,  1340,  1335,  1337,  1342,  1339,
    1341,  1343,  1344,  1346,  1345,  1347,  1348,  1349,  1352,  1356,
    1357,  1353,  1358, -1865, -1865, -1865,  9463,  1360,  1359,   305,
    1355,  1361,  1362,  1363,   309,   313,   320,   321,  1364,  1365,
    1366,   323,   116,  1367,  1368,  1369,  1370,   350,  1371,  1372,
    1373,  1374,  1375,  1376,  1383,  1378,  1379,  1380,  1381,  1382,
    1384,  1385, -1865,  1389,  1392,   351,   352,  1387,  1394,  1390,
    1391,  1393,  1395,  1396,  1397,  1398,  1399,  1400,  1406,  1401,
    1402,  1403,  1404,  1405,  1412,  1407,  1408,  1409,  1417,  1418,
    1419,  1414,  1415,  9463,    39,  1416,    39,  1201,  1284,  1299,
    1350,  1386,    39, -1865,  1420,  1421,  1423,  1424,  1425,  1426,
    1434,  1429,  1436,  1440,  1438,  1439,  1441,  1442,   110,  1446,
    1211,  1452,  1447,  1454,  1456,  1458,  1459,  1464,  1465,  1254,
    1354,  1466,  1468,  9463,  9463,  1475, -1865,  9463, -1865,  9463,
   -1865,  9463, -1865,  9463, -1865,  9463, -1865, -1865, -1865, -1865,
    9463,  9463, -1865,  9463,  9463,  9463,  9463, -1865,  9463,  9463,
    9463,  9463, -1865, -1865, -1865,  9463, -1865,  1477, -1865,   405,
   -1865,    96,  1437,  9463,  9463, -1865, -1865,  9463, -1865,  9463,
   -1865,  9463, -1865,  9463,  9463,  9463,  9463, -1865,  9463,  9463,
    9463,  9463,  9463,  9463, -1865,  8682,  8682,  8682,  9463,  9463,
    9463,  9463, -1865,  9463,  9463,  9463,  9463,  9463,    28,  9463,
   -1865, -1865, -1865,  9463, -1865,  9463,  9463, -1865,  9463,  9463,
    9463,  9463,  9463,  9463,  9463,  9463, -1865, -1865,  9463,    28,
      28,  9463,  9463, -1865,  9463,  9463,  9463, -1865, -1865, -1865,
    9463,  9463, -1865, -1865,  9463, -1865, -1865, -1865, -1865, -1865,
   -1865, -1865,  9463,  9463, -1865,  9463, -1865,  9463, -1865,  9463,
    9463, -1865,  9463,  9463,    28,  9463, -1865,  9463,  9463, -1865,
    9463, -1865,  9463,  9463,  9463,  9463,  9463,  9463,  9463,  9463,
    9463,  9463,  9463, -1865, -1865, -1865,   353,  1478,   354,  1474,
    1481,  1476,  1479,  1483,  1480,  1482,  1484,  1485,  1486,  1488,
    1487,  1489, -1865,  1490,   454,  1491,  1493,   455,   458,  1494,
    1495,  1517,  1519,  1496,  1520,  1521,  1522,  1523,  1524,  1525,
     481,  1533,   526,  1534,  1535,  1530,  1531,  1536,  1540,  1543,
    1544,  1545,  1546,  1547,   462,  1552,  1559,   463,  1560,  1555,
    1556,  1564,  1565,  1562,  1563,  1570,  1566,  1568,   465,  1574,
    1571,   474,  1582,  1583,  1584,  1585,  1586,    39,  1581,  1587,
    1588,  1592,  1589,  1591,  1593,  1594,  1595,  1596,  1597,  1598,
    1604,  1599,  1600,  1609,  1612,  1616,  1617,  1618,  1621, -1865,
    1619,  1622,  1624, -1865,  9463, -1865, -1865,  9463,  9463, -1865,
    9463,  9463, -1865,  9463,  9463, -1865,  9463,  9463,  9463, -1865,
    9463, -1865, -1865,    96,  9463,  9463, -1865,  9463, -1865,  9463,
    9463,  9463,  9463,  9463, -1865,  9463,  9463,  9463,  9463,  9463,
    9463,  8682, -1865,  8682, -1865, -1865,  8682,  8682,  9463,  9463,
    9463,    28,    28,    28,    28, -1865,  9463,  9463, -1865, -1865,
    9463, -1865,  9463,  9463, -1865, -1865,  9463,  9463, -1865,  9463,
    9463, -1865,  9463,    28, -1865, -1865,  9463, -1865, -1865, -1865,
   -1865, -1865, -1865,  9463,  9463,  9463, -1865,  9463,  9463,  9463,
    9463,  9463,    28,  9463, -1865, -1865,  9463,  9463, -1865, -1865,
   -1865, -1865, -1865, -1865,  9463, -1865, -1865,  1627,  1625,  1632,
    1633,  1628,  1630,  1631,  1639,  1641,  1642,  1637,  1647,  1649,
    1646,  1654,  1655,  1656,  1657,  1658,  1653,   475,  1660,  1659,
    1661,  1662,  1663,  1664,  1666,  1667,  1668,  1665,  1670,  1672,
    1673,  1674,  1669,  1671,  1676,  1675,  1678,  1679,  1677,  1680,
    1681,  1682,  1683,  1684,  1685,  1690,  1686,  1693,  1689,   476,
    1691,  1692,  1694,  1695,  1696,  1697,  1450,  1699,  1580, -1865,
    9463, -1865, -1865,  9463,  9463,  9463, -1865, -1865, -1865,  9463,
   -1865, -1865,  9463, -1865, -1865, -1865, -1865, -1865,  9463, -1865,
    9463, -1865,  9463, -1865, -1865,  9463, -1865, -1865, -1865, -1865,
    8682, -1865, -1865, -1865, -1865,  9463,  9463, -1865,  9463, -1865,
   -1865,  9463,  9463,  9463,  9463,  9463, -1865,    28, -1865,  9463,
   -1865,  9463, -1865,  9463,  9463,  9463,  9463,  9463,    28,  9463,
    9463, -1865,  9463,  1704,  1700,  1701,  1702,  1703,  1705,  1710,
    1712,  1713,  1708,  1715,  1711,  1714,  1716,  1717,  1718,  1719,
     477,  1720,  1721,  1722,  1723,  1724,   478,  1731,  1726,  1727,
    1728,  1729,  1736, -1865, -1865,  9463,  9463,  9463,  9463,  9463,
   -1865, -1865, -1865,  9463, -1865,  9463,  9463, -1865,  9463,  9463,
    9463, -1865,  9463,  9463,    28,  9463,  9463,  9463, -1865,  9463,
   -1865,  9463,  9463,    28,  9463,  1167,  1737,  1738,  1733,  1740,
    1741,  1742,  1743,  1739,   479,  1744,  1745,  1746,  1747,   486,
    1748,  1749,  1750,   488,   490,  1751,  1752,  1753,  9463, -1865,
   -1865,  9463, -1865, -1865, -1865, -1865,  9463, -1865,  9463, -1865,
    9463,  9463,  9463, -1865,  9463,  9463,  9463, -1865, -1865,  9463,
   -1865,  9463,  9463,  9463,  9463, -1865,  1754,  1756,  1763,  1764,
    1759,  1766,  1767,  1768,  1765,  1769,  1770,  1771,  1772,  1773,
    9463,  9463, -1865, -1865,  9463, -1865, -1865, -1865,  9463, -1865,
    9463,  9463,  9463,    28,  1774,  1775,  1781,  1776,  1783,  1784,
    1779,  1780,  9463, -1865, -1865,  9463, -1865, -1865,  9463,    28,
    1782,  1785,  1786,  1787,  9463,  9463,  9463,  9463,  1788,  1789,
    1790,  1797,  9463,  9463,  9463, -1865,  1792,  1793,  1794,  9463,
    9463,  9463,  1801,  1796,  1798, -1865,  9463,  9463,  1803,  1806,
   -1865, -1865
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  Parser::yydefact_[] =
  {
         2,     0,     0,     0,     0,    21,    65,    66,     0,     0,
       0,    69,    70,     0,     0,     0,   242,   247,    41,    20,
       0,   326,     0,    87,    75,     0,     0,     0,     0,     0,
       0,    86,     0,     0,   236,   246,   569,   453,   320,   450,
     578,   579,   533,   580,   571,   572,   574,   573,   575,   581,
     452,   570,   582,     0,     0,     0,    43,    46,    44,    45,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   204,   205,   238,
     206,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,     0,
       0,     0,     0,     0,   248,   249,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   244,     0,    42,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   210,   211,   212,     0,     0,     0,
       0,     4,     8,    10,    14,    16,    18,    12,     0,   451,
     454,     0,   322,   449,   455,   457,   463,   471,   491,   495,
     498,   499,   504,   507,   509,   510,   512,   514,   516,   518,
     520,   527,    40,   458,   456,     0,   583,   577,   584,    39,
       0,     0,     0,     0,   452,     0,     0,     0,   322,   465,
       0,   474,   473,     0,     0,    67,   305,    68,    71,     0,
       0,     0,     0,   323,   307,    78,    81,    76,    93,    90,
      91,    92,    89,    88,    77,    96,    97,    98,     0,    85,
       0,     0,     0,     0,     0,     0,     0,     0,    35,     0,
     131,     0,     0,   586,   587,   578,   579,   588,   580,   581,
     585,   570,   582,   589,   577,   590,   591,    83,    84,     0,
       0,     0,   475,   476,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   545,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   477,   478,   483,   484,   485,
     486,   487,   489,   488,   479,   480,   481,   482,   490,     0,
      25,     0,   244,   244,    37,     0,    38,     0,     0,     0,
       0,    31,    29,   244,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     3,     5,
       9,    11,    15,    17,    19,    13,     0,     6,     0,     0,
       0,   218,     0,   466,   467,   468,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   218,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   462,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   291,   292,   289,
     290,   287,   288,   293,   294,   295,   404,     0,     0,     0,
     102,     0,     0,     0,     0,   109,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   402,   403,     0,
       0,     0,     0,   166,     0,     0,     0,     0,   171,   172,
       0,   155,     0,   163,     0,     0,     0,     0,     0,   152,
     153,     0,     0,    99,     0,     0,    64,     0,   576,   208,
       0,     0,     0,     0,     0,     0,   306,     0,   306,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   140,   141,     0,
     142,   143,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   322,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     322,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     544,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   245,    26,     0,    36,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,   301,     0,   305,     0,   239,     0,     0,   129,
     130,     0,   145,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   319,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,     0,   578,   579,   580,     0,
     223,   219,     0,   596,     0,   322,   463,     0,   492,   493,
     494,   496,   497,   501,   500,   502,   503,   505,   506,   508,
     511,   513,   515,     0,   517,   522,   523,   524,   525,   526,
     521,     0,     0,    55,     0,     0,     0,   579,   528,     0,
     309,   312,     0,    51,    57,    53,     0,     0,     0,   472,
       0,    73,    74,     0,     0,   240,   241,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    94,    95,     0,     0,
       0,   209,   321,     0,    47,     0,   274,   276,     0,     0,
     277,   278,     0,   279,     0,     0,     0,     0,   362,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   363,     0,     0,     0,     0,     0,     0,   385,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   347,
     348,   349,     0,   351,     0,     0,     0,     0,     0,   358,
       0,     0,   270,     0,   275,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   365,     0,
     548,   549,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   546,     0,     0,   324,   325,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   429,   198,   199,     0,     0,   272,
       0,     0,   539,     0,     0,     0,     0,     0,   343,   345,
     459,     0,   534,   398,   399,   400,   401,   286,     0,     0,
       0,   201,     0,   244,   216,   243,   244,    27,   298,   299,
     300,     0,   203,   225,   225,     0,    33,   433,     0,     0,
       0,     0,     0,     0,   557,     0,     0,     0,   440,     0,
     442,     0,     0,     0,     0,     0,     0,   444,   445,   148,
       0,     0,     0,     0,     0,     0,     0,   430,     0,     0,
       0,   144,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   221,   464,     0,     0,     0,     0,   470,   469,     0,
       0,     0,    50,    49,     0,     0,     0,     0,     0,     0,
       0,     0,   461,   321,     0,     0,     0,     0,   322,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   244,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   322,
       0,   322,     0,     0,     0,     0,     0,     0,   224,   220,
       0,     0,   595,   519,     0,     0,     0,     0,   529,     0,
       0,     0,     0,    52,     0,     0,   237,     0,     0,     0,
       0,     0,   125,     0,   128,     0,   101,   104,   103,     0,
       0,     0,     0,     0,   112,   113,     0,     0,     0,     0,
     118,     0,   127,     0,   156,     0,   151,   158,     0,     0,
       0,     0,   154,     0,   164,     0,   159,     0,     0,     0,
     162,   302,   303,   304,     0,    56,    82,    48,   460,     0,
       0,     0,   335,     0,     0,     0,   361,   364,   366,   367,
       0,   368,   196,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   269,   346,     0,     0,     0,     0,
       0,     0,   359,   360,     0,   285,     0,   330,   331,   332,
       0,     0,     0,     0,   179,     0,     0,     0,   185,     0,
       0,   551,   405,   406,   407,   408,     0,     0,     0,     0,
       0,   547,   448,   414,     0,     0,     0,     0,     0,     0,
     419,   420,   421,   422,   423,   424,   425,   426,     0,     0,
       0,     0,   535,     0,   536,   540,   541,   542,   543,     0,
     532,     0,     0,     0,   244,   217,    24,    28,     0,   229,
     230,   226,   228,   227,   244,     0,   244,     0,   434,     0,
       0,   435,     0,     0,   558,     0,     0,     0,   439,   441,
       0,     0,     0,     0,   443,     0,   207,     0,     0,   250,
       0,     0,     0,   256,   139,     0,   138,     0,   146,   147,
       0,   192,     0,   194,   195,   134,     0,     0,     0,   132,
       0,   222,     0,     0,   296,     0,    54,   531,     0,    60,
      58,     0,     0,     0,   322,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   280,   281,   282,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   322,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   284,     0,     0,     0,     0,     0,   305,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    34,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    72,     0,   329,     0,
     120,     0,   123,     0,   126,     0,   107,   105,   108,   110,
       0,     0,   115,     0,     0,     0,     0,   157,     0,     0,
       0,     0,   165,   160,   173,     0,    63,     0,   336,     0,
     337,     0,     0,     0,     0,   197,   371,     0,   374,     0,
     376,     0,   378,     0,     0,     0,     0,   409,     0,     0,
       0,     0,     0,     0,   386,     0,     0,     0,     0,     0,
       0,     0,   396,     0,     0,     0,     0,     0,     0,     0,
     333,   334,   174,     0,   176,     0,     0,   180,     0,     0,
       0,     0,     0,     0,     0,     0,   447,   415,     0,     0,
       0,     0,     0,   427,     0,     0,     0,   537,   538,   200,
       0,     0,   244,    22,     0,    32,   234,   235,   232,   233,
     231,    30,     0,     0,   438,     0,   559,     0,   560,     0,
       0,   215,     0,     0,     0,     0,   251,     0,     0,   255,
       0,    79,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    61,    59,    62,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   283,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   594,
     593,     0,     0,   327,     0,   119,   121,     0,     0,   100,
       0,     0,   117,     0,     0,   150,     0,     0,     0,   170,
       0,   338,   339,     0,     0,     0,   370,     0,   373,     0,
       0,     0,     0,     0,   344,     0,     0,     0,     0,     0,
       0,     0,   387,     0,   389,   391,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   356,     0,     0,   175,   177,
       0,   181,     0,     0,   190,   550,     0,     0,   554,     0,
       0,   189,     0,     0,   416,   417,     0,   428,   271,   273,
     431,   432,    23,     0,     0,     0,   342,     0,     0,     0,
       0,     0,     0,     0,   253,   254,     0,     0,   191,   193,
     135,   136,   252,   133,     0,   297,   530,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   328,
       0,   124,   111,     0,     0,     0,   167,   168,   169,     0,
     340,   341,     0,   372,   375,   377,   379,   382,     0,   411,
       0,   413,     0,   380,   383,     0,   388,   390,   392,   393,
       0,   395,   350,   352,   353,     0,     0,   357,     0,   178,
     184,     0,     0,     0,     0,     0,   188,     0,   418,     0,
     436,     0,   561,     0,     0,     0,     0,     0,     0,     0,
       0,   137,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   592,   122,     0,     0,     0,     0,     0,
     381,   412,   410,     0,   394,     0,     0,   397,     0,     0,
       0,   556,     0,     0,     0,     0,     0,     0,   565,     0,
     566,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   114,
     116,     0,   161,   369,   384,   354,     0,   182,     0,   552,
       0,     0,     0,   187,     0,     0,     0,   562,   563,     0,
     567,     0,     0,     0,     0,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   183,   553,     0,   202,   186,   446,     0,   564,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   355,   555,     0,   568,   149,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   214,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   106,     0,     0,     0,     0,
     437,   213
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
     -1865, -1865, -1865,  -197,  1018,  1032,  1120, -1865, -1865,  1472,
    1473,  1500,  1501, -1865,   125,  -349, -1865,  -490, -1865, -1865,
   -1865,    -8,  2363,  2899,    23,  2114, -1865, -1865, -1865,     7,
     809,    27,  -175, -1865,  -193,  -150,   255, -1865,  1089,   914,
     268,   297,   349,    42,   -53,  2663,   362, -1865, -1865,   -18,
   -1865,     6,  1092,     4, -1865,  -219, -1864
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,   259,   260,   261,   262,   263,   264,   845,   844,   265,
     266,   267,   268,  1153,   909,  1397,   269,   520,   521,  1155,
     270,   914,   695,   323,   271,   308,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   316,   954,   293,   294,   295,
     296,   310,   298,   365,   366,   367,   917
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char Parser::yytable_ninf_ = -1;
  const unsigned short int
  Parser::yytable_[] =
  {
       315,   317,   318,   522,   299,   333,   297,   689,   309,   833,
       5,   681,   682,   349,   581,   582,   946,   591,   346,  1219,
     343,  2011,  2013,  2014,    19,   579,   580,   313,   524,   311,
     312,   348,   836,   837,    38,   342,  1069,   875,   876,  1272,
     657,   658,  1070,   847,   319,   571,   325,   572,   305,   948,
     627,   628,   629,   630,   631,   632,   633,   634,   635,   364,
     601,  1448,     5,   559,   876,   593,   594,   595,   596,   597,
     877,   567,    36,    38,  1290,  1247,    19,  1719,   612,    38,
     876,   602,    38,   568,   531,  1194,   598,   305,  1196,    38,
     373,   344,   345,   305,   636,   610,   305,  1442,   320,   592,
     592,   611,  1075,   305,   328,   610,   321,    36,   878,   347,
     338,   611,  1458,   583,   584,   329,   330,   331,   332,  1649,
     690,   619,   620,   351,  1956,  1650,   585,   586,  1651,   610,
    1957,   573,   574,  1958,   340,   611,  1879,   879,   657,   658,
     575,   569,   880,   881,   882,   883,   884,   570,   612,   375,
     692,   376,   350,   568,   963,  1392,  1393,    38,  1394,  1395,
     341,  1396,  1787,  1788,   599,  1789,  1790,   610,  1791,   369,
     600,   305,   378,   611,   379,   885,   886,   887,   657,   658,
     659,    36,   660,   661,   662,   352,  1194,   663,  1195,  1196,
     664,   665,   666,   667,   668,   669,   670,   671,   576,   577,
     672,  1091,   519,   578,   673,   610,  1129,  1092,   370,   674,
     675,   611,   371,   532,   533,   374,   523,   610,  1661,   377,
     676,   610,  1663,   611,  1103,   677,   678,   611,   364,   380,
    1104,   381,   382,   505,   506,   507,   508,   509,   510,   511,
     512,   513,   514,   515,   516,   517,   518,  2203,   430,  2204,
     431,   383,  2205,  2206,   834,  1132,   949,   610,  1828,  1167,
     384,  1133,  1174,   611,   299,  1168,   297,  1178,  1175,   888,
     889,  1180,  1212,  1179,   610,   890,  1232,  1181,  1213,  1484,
    1216,  1494,  1213,  1512,  1522,  1485,  1564,  1495,   891,  1513,
    1523,   385,  1565,  1597,   683,   684,   685,   686,  1602,  1598,
    1280,   890,  1281,  1624,  1603,  1626,   892,  1634,   840,  1625,
    1656,  1625,   615,  1635,  1665,  1669,  1657,   890,  1715,  1860,
    1666,  1670,   403,  1866,  1716,  1861,   404,  1868,   838,  1867,
     386,   688,   892,  1869,  1870,  1872,   326,  1877,   684,   685,
    1871,  1873,   387,  1878,   691,   617,   364,   364,   892,  1156,
     893,   894,   895,   896,   897,   898,   899,   900,   901,   902,
     903,   904,   693,   694,  1884,  1902,  1904,  2073,  2076,   871,
    1885,  1903,  1905,  2074,  2077,   364,   893,   894,   895,   896,
     897,   898,   899,   900,   901,   902,   903,   904,   923,   924,
     925,   926,   893,   894,   895,   896,   897,   898,   899,   900,
     901,   902,   903,   904,   921,   922,  2313,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,    36,   353,
      38,   354,   355,   356,   357,   358,    44,    45,    46,    47,
      48,   359,   360,   361,   362,   927,   928,   621,   622,   623,
     624,   625,   626,   627,   628,   629,   630,   631,   632,   633,
     634,   635,   353,    38,   354,   355,   356,   357,   358,    44,
      45,    46,    47,    48,   359,   360,   361,   362,  2092,  2096,
     806,   807,  2098,   809,  2093,  2097,  2125,  2129,  2099,  2141,
     388,   389,  2126,  2130,   821,  2142,   822,   636,  2145,  2259,
    2292,  2351,  2358,  2397,  2146,  2260,  2293,  2352,  2359,  2398,
    2403,  2111,  2408,  1215,  2410,   390,  2404,   637,  2409,   839,
    2411,   726,   727,   728,   313,   638,   639,   640,   641,   642,
     391,   643,   644,   645,   646,   647,   648,   649,   650,   651,
     652,   653,   654,   364,   729,   730,   731,   392,   393,   861,
     935,   936,   937,   938,   939,   940,  2113,   394,  1215,   395,
     396,   397,   398,   399,   400,   401,   402,   405,   406,   407,
     408,   873,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   911,   422,   297,   423,   916,
     424,   425,   426,   427,   428,   429,   432,   433,   434,   435,
     436,   941,   437,   438,   439,   440,   441,   442,   443,   957,
     444,   445,   958,   918,   919,   920,   446,   911,   297,   297,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   655,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   959,
    1157,   475,   476,   656,   477,   478,   479,   480,   481,   482,
    1166,   483,   484,   485,   486,   487,   488,   489,   490,   494,
     495,   496,   497,  1389,   498,   499,  1390,   500,   501,   502,
     503,   504,   527,   528,   529,   530,   534,   535,   536,   537,
     538,   853,   540,   541,   542,   543,  1211,   539,   544,   545,
     546,   547,   548,   549,   550,   551,   552,   553,   554,   555,
     556,   557,   590,   679,   603,   687,   587,   568,   588,   872,
     607,   604,   605,   606,   589,   349,   608,   613,   609,   942,
    1387,  1165,  1448,   680,  1783,   967,   774,   892,   956,   961,
     962,   726,   846,   965,   960,   966,   968,   964,   969,   729,
     970,   971,   972,   973,   974,   975,   775,   780,   976,   977,
     978,   979,   980,   981,   982,   983,   984,   985,   986,   987,
     792,   793,   988,   989,   990,   991,   835,   843,   992,   993,
     994,   995,   996,   784,   997,   786,   867,   998,   999,   813,
     815,   816,  1000,  1001,  1002,  1003,  1004,  1005,  1008,  1009,
    1010,  1249,  1399,  1262,  1012,  1014,  1016,  1017,  1260,  1013,
    1015,  1019,  1020,  1021,  1018,  1023,  1022,  1025,  1024,  1028,
    1250,  1275,  1274,  1026,  1027,  1398,  1029,  1030,  1031,  1032,
    1033,  1034,  1035,  1036,  1037,  1152,  1038,  1039,  1040,  1041,
    1042,  1043,  1044,  1045,  1046,  1047,  1049,  1048,  1050,  1051,
    1052,  1265,   929,  1163,  1053,  1054,  1055,  1056,  1057,  1058,
    1059,  1060,  1061,  1062,  1063,  1064,  1215,  1285,   932,  1065,
    1072,  1066,  1067,  1068,  1071,  1073,  1074,  1076,  1077,  1078,
    1079,   372,  1283,  1080,  1081,  1082,  1083,  1084,  1085,  1086,
    1087,  1088,  1089,  1090,  1093,  1094,  1095,  1271,  1096,   934,
    1097,  1098,  1099,  1100,  1101,  1102,  1105,  1106,  1107,  1108,
    1109,  1110,  1111,  1124,  1164,  1112,  1113,  1114,  1115,  1627,
    1116,   364,  1117,  1118,  1119,  1120,  1121,  1122,  1123,  1125,
    1126,  1127,  1128,  1130,  1131,  1138,  1139,  1134,  1135,  1136,
    1137,  1140,  1142,  1141,  1143,  1144,  1145,  1146,  1147,  1148,
     933,  1151,  1158,  1159,  1160,  1149,  1150,  1162,  1223,  1173,
     297,  1161,  1169,  1187,  1170,  1235,  1236,  1171,  1172,  1237,
    1239,  1240,  1241,  1242,  1243,  1176,  1245,  1246,  1177,  1182,
    1183,  1251,  1252,  1253,  1254,  1255,  1256,  1257,  1184,  1259,
    1185,  1261,  1186,  1263,  1264,  1188,  1266,  1267,  1268,  1269,
    1270,  1189,  1190,  1191,  1192,  1276,  1277,  1278,  1193,  1197,
    1198,  1199,  1200,  1202,  1203,  1204,  1205,  1206,  1207,  1208,
    1209,  1210,  1619,  1620,  1449,  1217,  1221,  1218,  1292,  1293,
    1214,  1294,  1295,  1296,  1297,  1298,  1220,  1300,  1301,  1302,
    1303,  1304,  1305,  1225,  1306,  1226,  1227,  1228,  1229,  1230,
    1287,  1312,  1313,  1314,  1315,  1316,  1317,  1318,  1319,  1231,
    1321,  1233,  1288,  1289,  1332,  1440,  1388,  1454,  1455,  1456,
    1712,  1462,  1457,  1459,  1460,  1330,  1461,  1464,  1463,  1333,
    1334,  1335,  1465,  1466,  1338,  1339,  1340,  1341,  1342,  1343,
    1467,  1344,  1468,  1469,  1345,  1346,  1347,  1348,  1349,  1350,
    1351,  1352,  1353,  1354,  1470,  1471,  1356,  1472,  1473,  1474,
    1475,  1476,  1477,  1478,  1479,  1363,  1364,  1365,  1366,  1367,
    1368,  1369,  1370,  1371,  1372,  1373,  1480,  1481,  1482,  1374,
    1375,  1483,  1376,  1377,  1784,  1378,  1379,  1380,  1381,  1382,
    1486,  1487,  1488,  1383,  1786,  1489,  1792,  1492,  1490,  1491,
    1493,  1385,  1386,  1496,  1497,  1498,  1499,  1500,  1501,  1502,
    1503,  1504,  1506,  1391,  1507,  1508,  1516,  1514,  1517,  1515,
    1400,  1401,  1518,  1403,  1404,  1519,  1520,  1406,  1407,  1408,
    1521,  1409,  1524,  1410,  1525,  1412,  1413,  1526,  1527,  1528,
    1529,  1530,  1416,  1531,  1532,  1533,  1420,  1421,  1422,  1534,
    1535,  1424,  1616,  1617,  1536,  1537,  1428,  1430,  1432,  1433,
    1434,  1435,  1436,  1538,  1539,  1540,  1541,  1441,  1542,  1543,
    1544,  1545,  1444,  1445,  1546,  1547,  1446,  1439,  1671,   297,
    1450,  1451,  1548,  1549,  1550,  1551,  1552,  1553,  1554,  1555,
    1557,  1558,  1559,  1960,  1560,  1621,  1622,  1623,  1568,  1561,
    1562,  1563,  1566,  1567,  1571,  1569,  1570,  1572,  1573,  1574,
    1575,  1576,  1577,  1822,  1581,  1582,  1583,  1578,  1579,  1580,
    1936,  1443,  1825,  1584,  1585,  1586,  1587,  1588,  1589,  1590,
    1591,  1592,  1593,  1594,  1595,  1596,  1969,  2388,   560,  1604,
    1605,  1606,  1599,  1600,  1601,  1607,  1608,  1610,  1609,  1611,
    1612,  1628,   561,  1631,  1613,  1618,  1629,     0,  1630,  1638,
    1632,  1633,  1636,  1637,  1639,  1644,  1640,  1641,  1642,  1643,
    1646,  1653,  1645,  1647,  1648,  1652,  1654,  1658,  1655,  1659,
    1660,  1662,  1664,     0,  1667,  1674,  1668,  1672,  1676,  1673,
    1675,  1677,  1679,  1678,  1680,  1681,  1713,  1714,  1752,  1823,
    1826,  1824,  1830,  1937,  1832,  1827,  1834,  1829,  1836,  1831,
    1837,  1833,  1838,  1835,  1839,  1840,  1842,  1841,  1938,  1843,
    1847,  1844,  1273,  1845,  1846,  1848,  1852,  1849,  1850,  1851,
    1853,  1854,  1856,  1855,  1858,  1862,  1970,  1865,  1859,  1614,
     562,  1863,  1864,     0,  1874,  1875,  1876,  1880,  1881,  1882,
    1883,  1886,  1887,  1888,  1889,  1890,  1891,  1892,  1893,  1894,
    1895,  1896,  1897,  1900,  1898,  1899,  1901,  1906,  1907,  1939,
    1908,  1909,     0,  1910,  1916,  1911,  1912,  1913,  1914,  1915,
    1917,  1918,  1919,  1920,  1921,  1922,  1923,  1924,  1925,  1926,
    1793,  1927,  1928,  1929,  1930,  1931,  1934,  1944,     0,  1946,
    1942,  1943,  2047,   364,  1945,  1940,  1947,  1683,  1948,  1949,
    1686,  1687,  1688,  1689,  1951,  1690,  1950,  1691,  1952,  1953,
    1959,  1954,  1955,  1694,  1695,  1696,  1961,  1962,  1697,  1698,
    1699,  1700,  2300,  1701,  1963,  1702,  1964,  1703,  1965,  1966,
    1704,  1705,  1706,  1707,  1967,  1968,  1971,  1708,  1972,  1975,
    1710,  1992,  2075,  1994,  2078,  2079,  2080,  2082,  2085,  2081,
    2083,  2089,  2084,   931,  2091,  2086,  2087,  1721,  2088,  2090,
    2104,  2094,  1722,  2095,  2100,  2101,  1724,  1725,  1726,  1727,
    1728,  1729,  1730,  1731,  1733,  1734,  1735,  1736,  1737,  1738,
    1739,  1740,  1741,  1742,  1743,  1744,  1717,  2102,  1745,  2103,
    2105,  2106,  2107,  2108,  2109,  2110,  1751,  2112,  2114,  2115,
    2116,  2117,  1753,  1754,  1755,  1756,  2118,  1757,  1759,  1760,
    2119,  1761,  1762,  2120,  2121,  2122,  2123,  2124,  1763,  1764,
    1765,  1766,  2127,  2128,  2131,  2132,  2133,  1769,  2134,  2135,
    1772,  1773,  2136,  2137,  2138,  2144,  2139,  1933,  2140,  1935,
    1774,  1775,  1776,  1777,  2143,  1941,  2147,  2148,  2149,  2150,
    2151,  2153,  2302,  1780,  1781,  1782,  2156,  2154,  2155,  2157,
    1785,  2158,  2164,  2159,  2160,  2161,  2162,  2163,  2165,  2166,
    2167,  1794,  1795,  2168,  1796,  1797,  2169,  1798,  1799,  1800,
    2170,  2171,  2172,  1802,  1803,  2173,  2175,  1805,  2176,  2174,
    1807,  2239,  1808,  1809,  1810,  2240,  2241,  2242,  2243,  1812,
    2244,  2245,  1813,  2246,  1814,  2247,  2248,  2249,  1815,  1816,
    1817,  2250,  1818,  2251,  1819,  1820,  2252,  1821,  2253,  2254,
    2255,  2256,  2257,  2258,  2261,  2263,  2264,   930,  2266,  2262,
    2267,  2268,  2269,  2265,  2271,  2270,  2272,  2273,  2274,  2275,
    2277,  2276,  2279,  2280,   955,  2278,     0,  2281,  2286,     0,
    2282,  2283,  2284,  2285,  2288,  2287,  2289,  2290,  1857,  2291,
       0,  2294,  2295,  2301,  2296,  2297,  2298,  2299,  2334,     0,
    2335,  2336,  2337,  2338,  2340,  2339,  2341,  2342,  2343,  2344,
    2347,  2345,   563,   564,  2346,     0,     0,  2348,  2349,  2350,
    2353,  2354,  2355,  2356,  2357,  2360,  2361,  2362,  2363,  2364,
    2365,  2389,  2390,  2391,  2392,  2393,  2394,  2395,  2399,  2396,
     565,   566,     0,     0,  2407,  2400,  2401,  2402,  2405,  2406,
       0,  2412,  2413,  2414,  2430,  1932,  2431,  2432,  2433,  2434,
    2435,  2436,  2437,  2439,     0,  2438,     0,     0,     0,  2453,
    2440,  2441,  2442,  2443,  2452,  2454,  2455,  2456,  2457,  2458,
    2459,     0,  2464,     0,     0,  2465,  2466,  2467,  2472,  2473,
    2474,  2475,  2479,  2480,  2481,  2485,  2486,  2490,  2487,  1976,
    2491,  1977,     0,  1978,     0,  1979,     0,  1980,     0,     0,
       0,     0,  1981,  1982,     0,  1983,  1984,  1985,  1986,     0,
    1987,  1988,  1989,  1990,     0,     0,     0,  1991,     0,     0,
    2152,     0,     0,     0,     0,  1995,  1996,     0,     0,  1997,
       0,  1998,     0,  1999,     0,  2000,  2001,  2002,  2003,     0,
    2004,  2005,  2006,  2007,  2008,  2009,     0,  2010,  2012,     0,
    2015,  2016,  2017,  2018,  1993,  2019,  2020,  2021,  2022,  2023,
       0,  2025,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2030,  2031,  2032,  2033,  2034,  2035,  2036,     0,     0,
    2037,     0,     0,  2040,  2041,     0,  2042,  2043,  2044,     0,
       0,     0,  2045,  2046,     0,     0,  2048,     0,     0,     0,
       0,     0,     0,     0,  2049,  2050,     0,  2051,     0,     0,
       0,  2053,  2054,     0,  2055,  2056,     0,  2058,     0,  2059,
    2060,     0,  2061,     0,  2062,  2063,  2064,  2065,  2066,  2067,
    2068,  2069,  2070,  2071,  2072,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2177,     0,     0,  2178,
    2179,     0,  2180,  2181,     0,  2182,  2183,     0,  2184,  2185,
    2186,     0,  2187,     0,     0,     0,  2189,  2190,     0,  2191,
       0,  2192,  2193,  2194,  2195,  2196,     0,  2197,  2198,  2199,
    2200,  2201,  2202,     0,     0,     0,     0,     0,     0,     0,
    2207,  2208,  2209,     0,   272,     0,  2188,     0,  2214,  2215,
       0,     0,  2216,     0,  2217,  2218,     0,     0,  2219,  2220,
       0,  2221,  2222,     0,     0,     0,   327,     0,  2225,   334,
       0,     0,     0,     0,     0,  2226,  2227,  2228,     0,     0,
    2230,  2231,  2232,  2233,     0,  2235,     0,     0,  2236,  2237,
       0,     0,     0,     0,     0,     0,  2238,   363,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2303,     0,     0,  2304,  2305,  2306,     0,     0,
       0,  2307,     0,     0,  2308,     0,     0,     0,     0,     0,
    2309,     0,  2310,     0,  2311,     0,     0,  2312,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2314,  2315,     0,
    2316,     0,     0,  2317,  2318,  2319,  2320,  2321,     0,     0,
       0,  2323,     0,  2324,     0,     0,  2326,  2327,  2328,  2329,
       0,  2331,  2332,     0,  2333,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2366,  2367,  2368,
    2369,  2370,     0,     0,     0,  2371,   363,  2372,  2373,     0,
    2374,  2375,  2376,     0,  2377,  2378,     0,  2380,  2381,  2382,
       0,  2383,     0,  2384,  2385,     0,  2387,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   272,     0,     0,     0,     0,     0,
       0,     0,     0,  2416,     0,     0,     0,     0,  2417,     0,
       0,     0,  2419,  2420,  2421,     0,     0,  2423,  2424,     0,
       0,  2425,     0,     0,  2427,  2428,  2429,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2444,  2445,     0,     0,  2446,     0,     0,     0,
    2447,     0,     0,  2449,  2450,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2460,     0,     0,  2461,     0,     0,
    2462,     0,     0,     0,   363,   363,  2468,  2469,  2470,  2471,
       0,     0,     0,     0,  2476,  2477,  2478,     0,     0,     0,
       0,  2482,  2483,  2484,     0,     0,     0,     0,  2488,  2489,
       0,     0,     0,   363,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   705,     0,     0,   708,
     709,   710,   711,   712,     0,   714,   715,   716,   717,   718,
     719,   720,   721,   722,     0,     0,   725,     0,     0,   732,
     733,   734,   735,   736,   737,   738,   739,   740,   741,     0,
     743,   744,   745,   746,   747,   748,   749,   750,   751,   752,
     753,   754,   755,   756,   758,     0,     0,     0,     0,     0,
       0,   765,   766,   767,   768,   769,   770,   771,   772,   773,
       0,     0,   776,   777,   778,   779,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   789,   790,   791,     0,     0,
     794,   795,   796,   797,   798,   799,   800,   801,   802,   803,
     804,     0,     0,     0,   808,   810,     0,   812,     0,   814,
       0,     0,     0,   818,   819,     0,     0,     0,     0,     0,
     824,   825,   826,   827,     0,     0,     0,     0,   832,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   363,     0,     0,     0,     0,     0,     0,     0,     0,
     850,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   292,     0,     0,     0,   314,   868,   869,
     870,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   324,     0,     0,   915,     0,     0,   335,
     336,   324,     0,   324,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   324,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   697,   699,
     700,   701,   702,   703,   704,     0,   706,   707,     0,     0,
       0,     0,     0,   713,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   723,   724,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   742,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   757,   759,   760,   761,   762,   763,   764,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   781,   782,   783,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     805,     0,     0,     0,   324,   811,     0,     0,     0,     0,
       0,   817,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   829,   830,   831,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   324,   324,
       0,     0,   842,     0,     0,     0,     0,   848,   849,     0,
     851,   852,     0,   854,   855,   856,   857,   858,   859,   860,
       0,   862,   863,   864,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   292,     0,     0,     0,   337,     0,   339,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   368,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   314,   943,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   324,     0,   324,   314,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   324,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   363,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   696,   698,   696,
     696,   696,   696,   696,   696,     0,   696,   696,     0,     0,
       0,     0,     0,   696,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   696,   696,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   696,     0,
     493,  1238,     0,     0,     0,     0,     0,  1244,     0,     0,
    1248,     0,     0,   696,   696,   696,   696,   696,   696,   696,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   696,   696,   696,     0,
     324,     0,   324,   324,   525,   526,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1291,
     696,     0,     0,     0,     0,   696,     0,     0,  1299,     0,
       0,   696,     0,     0,   314,     0,     0,     0,   823,  1309,
    1310,  1311,     0,   324,   696,   696,   696,     0,     0,     0,
       0,  1320,     0,     0,     0,     0,  1322,     0,  1323,  1324,
    1325,  1326,  1327,     0,  1328,  1329,     0,     0,     0,     0,
       0,   324,   696,     0,     0,     0,     0,   696,   696,     0,
     696,   696,     0,   696,   696,   696,   696,   696,   696,   696,
       0,   696,   696,   696,   324,   324,  1355,     0,   614,     0,
     616,     0,  1358,  1359,  1360,  1361,  1362,     0,     0,     0,
       0,     0,   874,     0,   910,     0,     0,   618,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   696,   953,   910,     0,     0,     0,
       0,     0,     0,   874,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1402,     0,     0,  1405,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1418,  1419,     0,     0,
       0,     0,     0,     0,  1425,     0,  1426,  1427,  1429,  1431,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1006,  1007,     0,     0,     0,  1258,
       0,     0,     0,   324,     0,     0,   785,     0,   787,   788,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   828,
       0,     0,  1510,  1511,     0,     0,  1307,  1308,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   841,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1331,     0,
       0,     0,     0,  1336,  1337,     0,     0,     0,     0,     0,
     865,   866,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   324,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   324,  1411,     0,     0,  1414,  1415,
       0,   363,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1684,
       0,  1685,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1692,  1693,     0,     0,     0,     0,  1011,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1222,   324,     0,
       0,  1709,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   324,     0,     0,     0,  1718,  1720,     0,
       0,     0,     0,     0,     0,     0,     0,  1723,     0,     0,
       0,     0,     0,     0,     0,  1732,  1505,     0,     0,   696,
    1509,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1746,  1747,  1748,  1749,  1750,     0,     0,     0,     0,
       0,   324,     0,   324,     0,     0,   324,     0,     0,     0,
       0,  1286,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1556,     0,     0,     0,     0,
    1770,  1771,     0,     0,     0,     0,   696,   696,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1778,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1154,     0,     0,     0,     0,   696,     0,
       0,     0,     0,   696,   696,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1806,     0,     0,     0,     0,     0,     0,   324,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1201,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   324,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   696,     0,     0,   696,   696,
       0,     0,     0,     0,   324,     0,     0,     0,     0,  1234,
       0,   324,  1711,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1438,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   324,     0,
       0,     0,     0,   324,   324,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1279,     0,  1282,
       0,     0,  1284,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1767,     0,     0,   696,  1768,     0,     0,
     696,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1779,     0,     0,  1718,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   696,     0,     0,     0,   915,
     915,   915,     0,  1801,  1357,     0,  1804,     0,     0,     0,
       0,     0,  2024,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2038,  2039,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1384,     0,     0,
       0,   324,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2057,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1417,     0,     0,     0,     0,     0,     0,  1423,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   324,     0,     0,
       0,     0,     0,     0,  1447,     0,     0,     0,     0,  1452,
    1453,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   696,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1718,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   915,     0,   915,  1758,     0,
     915,   915,     0,     0,     0,  2210,  2211,  2212,  2213,     0,
       0,     0,     0,   696,     0,     0,     0,   696,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2224,     0,     0,
       0,     0,     0,     0,     0,     0,  2026,     0,  2027,  2028,
       0,  2029,   696,     0,     0,     0,  2234,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1615,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   696,     0,     0,   696,     0,     0,     0,
    2052,     0,     0,     0,     0,     0,     0,     0,  1811,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1682,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   915,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2322,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2330,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2379,     0,
       0,     0,     0,     0,     0,     0,     0,  2386,     0,     0,
       0,     0,     0,     0,     0,     0,   324,   324,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2223,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2229,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2451,     0,     0,
       0,     0,     0,     0,     0,     0,   696,     0,   696,   696,
       0,   696,     0,  2463,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     696,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2325,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1973,  1974,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2415,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2418,     0,     0,     0,     0,     0,  2422,     0,     0,
       0,     0,     0,     0,  2426,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2448,     0,   696,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     696,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   696,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   696,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   696,   558,     0,     0,     0,     0,   696,     0,     0,
       0,     1,     2,     3,   696,     4,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     0,   696,    22,    23,    24,    25,    26,    27,
      28,     0,    29,    30,    31,     0,    32,    33,    34,     0,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,     0,    56,    57,    58,    59,    60,    61,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    62,    63,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,     0,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,     0,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,     0,     0,     0,   104,   105,
       0,     0,     0,     0,     0,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,     0,     0,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,     0,
       0,   173,   174,   175,   176,   177,   178,   179,   180,   181,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   182,   183,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,     0,   199,   200,   201,   202,   203,
       0,     0,     0,     0,     0,   204,   205,   206,   207,   208,
     209,   210,   211,     0,     0,   212,   213,   214,   215,   216,
     217,   218,   219,   220,     0,     0,     0,     0,   221,     0,
     222,   223,   224,     0,     0,     0,   225,   226,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     227,   228,   229,   230,     0,     0,     0,     0,     0,     0,
       0,   231,   232,     0,   233,   234,   235,   236,     0,   237,
     238,     0,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,     0,   253,   254,   255,
     256,   257,   258,     1,     2,     3,     0,     4,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     0,     0,    22,    23,    24,    25,
      26,    27,    28,     0,    29,    30,    31,     0,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,     0,    56,    57,    58,    59,    60,    61,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    62,    63,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,     0,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,     0,     0,     0,
     104,   105,     0,     0,     0,     0,     0,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,     0,     0,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,     0,     0,   173,   174,   175,   176,   177,   178,   179,
     180,   181,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   182,   183,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,     0,   199,   200,   201,
     202,   203,     0,     0,     0,     0,     0,   204,   205,   206,
     207,   208,   209,   210,   211,     0,     0,   212,   213,   214,
     215,   216,   217,   218,   219,   220,     0,     0,     0,     0,
     221,     0,   222,   223,   224,     0,     0,     0,   225,   226,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   227,   228,   229,   230,     0,     0,     0,     0,
       0,     0,     0,   231,   232,     0,   233,   234,   235,   236,
       0,   237,   238,     0,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,     0,   253,
     254,   255,   256,   257,   258,     1,     2,     3,     0,     4,
       0,     0,     0,   944,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      16,    17,     0,     0,   945,    21,     0,   946,     0,     0,
       0,     0,     0,     0,     0,     0,    29,     0,     0,     0,
      32,    33,    34,     0,    35,     0,    37,    38,    39,   906,
     947,    42,   908,    44,    45,    46,    47,    48,   359,   304,
     948,   362,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    62,    63,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
       0,    77,     0,    79,    80,    81,    82,    83,    84,    85,
      86,     0,     0,     0,    89,     0,    91,    92,    93,   306,
     307,    96,    97,    98,    99,   100,   101,   102,   103,     0,
       0,     0,   104,   105,     0,     0,     0,     0,     0,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
       0,     0,     0,     0,     0,     0,   133,     0,     0,     0,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   149,
     150,   151,   152,     0,     0,     0,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,     0,     0,
     170,   171,   172,     0,     0,   173,   174,   175,   176,   177,
     178,   179,   180,   181,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   949,   182,   183,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   184,   185,   186,   187,   188,   950,   190,
     191,   951,   193,   194,   195,   196,   197,   198,     0,   199,
       0,   201,   202,     0,   952,     0,     0,     0,     0,   204,
     205,   206,   207,   208,   209,   210,   211,     0,     0,   212,
     213,   214,   215,   216,   217,   218,   219,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   227,   228,   229,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   233,   234,
     235,   236,     0,   237,   238,     0,   239,   240,   241,   242,
     243,   244,   245,     0,   247,   248,   249,   250,     1,     2,
       3,     0,     4,     0,     0,     0,   905,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    16,    17,     0,     0,    20,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    29,
       0,     0,     0,    32,    33,    34,     0,    35,     0,    37,
      38,    39,   906,   907,    42,   908,    44,    45,    46,    47,
      48,   359,   304,   361,   362,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    62,    63,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,     0,    77,     0,    79,    80,    81,    82,
      83,    84,    85,    86,     0,     0,     0,    89,     0,    91,
      92,    93,   306,   307,    96,    97,    98,    99,   100,   101,
     102,   103,     0,     0,     0,   104,   105,     0,     0,     0,
       0,     0,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,     0,     0,     0,     0,     0,     0,   133,
       0,     0,     0,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   149,   150,   151,   152,     0,     0,     0,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,     0,     0,   170,   171,   172,     0,     0,   173,   174,
     175,   176,   177,   178,   179,   180,   181,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   182,   183,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,     0,   199,     0,   201,   202,     0,     0,     0,     0,
       0,     0,   204,   205,   206,   207,   208,   209,   210,   211,
       0,     0,   212,   213,   214,   215,   216,   217,   218,   219,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   227,   228,   229,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   233,   234,   235,   236,     0,   237,   238,     0,   239,
     240,   241,   242,   243,   244,   245,     0,   247,   248,   249,
     250,     1,     2,     3,     0,     4,     0,     0,     0,  1437,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    16,    17,     0,     0,
      20,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    29,     0,     0,     0,    32,    33,    34,     0,
      35,     0,    37,    38,    39,   906,   907,    42,   908,    44,
      45,    46,    47,    48,   359,   304,   361,   362,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    62,    63,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,     0,    77,     0,    79,
      80,    81,    82,    83,    84,    85,    86,     0,     0,     0,
      89,     0,    91,    92,    93,   306,   307,    96,    97,    98,
      99,   100,   101,   102,   103,     0,     0,     0,   104,   105,
       0,     0,     0,     0,     0,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,     0,     0,     0,     0,
       0,     0,   133,     0,     0,     0,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   149,   150,   151,   152,     0,
       0,     0,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,     0,     0,   170,   171,   172,     0,
       0,   173,   174,   175,   176,   177,   178,   179,   180,   181,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   182,   183,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,     0,   199,     0,   201,   202,     0,
       0,     0,     0,     0,     0,   204,   205,   206,   207,   208,
     209,   210,   211,     0,     0,   212,   213,   214,   215,   216,
     217,   218,   219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     227,   228,   229,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   233,   234,   235,   236,     0,   237,
     238,     0,   239,   240,   241,   242,   243,   244,   245,     0,
     247,   248,   249,   250,     1,     2,     3,     0,     4,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     5,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    16,
      17,     0,    19,    20,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    29,     0,     0,     0,    32,
      33,    34,     0,    35,     0,    37,    38,    39,   301,   302,
      42,   303,    44,    45,    46,    47,    48,     0,   304,     0,
     305,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    62,    63,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,     0,
      77,     0,    79,    80,    81,    82,    83,    84,    85,    86,
       0,     0,     0,    89,     0,    91,    92,    93,   306,   307,
      96,    97,    98,    99,   100,   101,   102,   103,     0,     0,
       0,   104,   105,     0,     0,     0,     0,     0,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,     0,
       0,     0,     0,     0,     0,   133,     0,     0,     0,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   149,   150,
     151,   152,     0,     0,     0,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,     0,     0,   170,
     171,   172,     0,     0,   173,   174,   175,   176,   177,   178,
     179,   180,   181,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   182,   183,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,     0,   199,     0,
     201,   202,     0,     0,     0,     0,     0,     0,   204,   205,
     206,   207,   208,   209,   210,   211,     0,     0,   212,   213,
     214,   215,   216,   217,   218,   219,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   227,   228,   229,     0,     0,     0,     0,
       0,     0,     1,     2,     3,     0,     4,   233,   234,   235,
     236,     0,   237,   238,     0,   239,   240,   241,   242,   243,
     244,   245,     0,   247,   248,   249,   250,    16,    17,     0,
       0,    20,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29,     0,     0,     0,    32,    33,    34,
       0,    35,     0,    37,    38,    39,   906,   907,    42,   908,
      44,    45,    46,    47,    48,   359,   304,   361,   362,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    62,    63,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,     0,    77,     0,
      79,    80,    81,    82,    83,    84,    85,    86,     0,     0,
       0,    89,     0,    91,    92,    93,   306,   307,    96,    97,
      98,    99,   100,   101,   102,   103,     0,     0,     0,   104,
     105,     0,     0,     0,     0,     0,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,     0,     0,     0,
       0,     0,     0,   133,     0,     0,     0,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   149,   150,   151,   152,
       0,     0,     0,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,     0,     0,   170,   171,   172,
       0,     0,   173,   174,   175,   176,   177,   178,   179,   180,
     181,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   182,   183,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,     0,   199,     0,   201,   202,
       0,     0,     0,     0,     0,     0,   204,   205,   206,   207,
     208,   209,   210,   211,     0,     0,   212,   213,   214,   215,
     216,   217,   218,   219,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   227,   228,   229,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   233,   234,   235,   236,     0,
     237,   238,     0,   239,   240,   241,   242,   243,   244,   245,
       0,   247,   248,   249,   250,     1,     2,     3,     0,   491,
       0,   492,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      16,    17,     0,     0,    20,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    29,     0,     0,     0,
      32,    33,    34,     0,    35,     0,    37,    38,    39,   301,
     302,    42,   303,    44,    45,    46,    47,    48,     0,   304,
       0,   305,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    62,    63,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
       0,    77,     0,    79,    80,    81,    82,    83,    84,    85,
      86,     0,     0,     0,    89,     0,    91,    92,    93,   306,
     307,    96,    97,    98,    99,   100,   101,   102,   103,     0,
       0,     0,   104,   105,     0,     0,     0,     0,     0,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
       0,     0,     0,     0,     0,     0,   133,     0,     0,     0,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   149,
     150,   151,   152,     0,     0,     0,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,     0,     0,
     170,   171,   172,     0,     0,   173,   174,   175,   176,   177,
     178,   179,   180,   181,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   182,   183,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,     0,   199,
       0,   201,   202,     0,     0,     0,     0,     0,     0,   204,
     205,   206,   207,   208,   209,   210,   211,     0,     0,   212,
     213,   214,   215,   216,   217,   218,   219,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   227,   228,   229,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   233,   234,
     235,   236,     0,   237,   238,     0,   239,   240,   241,   242,
     243,   244,   245,     0,   247,   248,   249,   250,     1,     2,
       3,     0,     4,   820,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    16,    17,     0,     0,    20,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    29,
       0,     0,     0,    32,    33,    34,     0,    35,     0,    37,
      38,    39,   301,   302,    42,   303,    44,    45,    46,    47,
      48,     0,   304,     0,   305,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    62,    63,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,     0,    77,     0,    79,    80,    81,    82,
      83,    84,    85,    86,     0,     0,     0,    89,     0,    91,
      92,    93,   306,   307,    96,    97,    98,    99,   100,   101,
     102,   103,     0,     0,     0,   104,   105,     0,     0,     0,
       0,     0,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,     0,     0,     0,     0,     0,     0,   133,
       0,     0,     0,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   149,   150,   151,   152,     0,     0,     0,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,     0,     0,   170,   171,   172,     0,     0,   173,   174,
     175,   176,   177,   178,   179,   180,   181,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   182,   183,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,     0,   199,     0,   201,   202,     0,     0,     0,     0,
       0,     0,   204,   205,   206,   207,   208,   209,   210,   211,
       0,     0,   212,   213,   214,   215,   216,   217,   218,   219,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   227,   228,   229,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   233,   234,   235,   236,     0,   237,   238,     0,   239,
     240,   241,   242,   243,   244,   245,     0,   247,   248,   249,
     250,     1,     2,     3,     0,     4,     0,     0,     0,     0,
       0,     0,     0,     0,   912,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    16,    17,     0,     0,
      20,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    29,     0,     0,     0,    32,    33,    34,     0,
      35,     0,    37,    38,    39,   913,   302,    42,   303,    44,
      45,    46,    47,    48,     0,   304,     0,   305,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    62,    63,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,     0,    77,     0,    79,
      80,    81,    82,    83,    84,    85,    86,     0,     0,     0,
      89,     0,    91,    92,    93,   306,   307,    96,    97,    98,
      99,   100,   101,   102,   103,     0,     0,     0,   104,   105,
       0,     0,     0,     0,     0,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,     0,     0,     0,     0,
       0,     0,   133,     0,     0,     0,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   149,   150,   151,   152,     0,
       0,     0,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,     0,     0,   170,   171,   172,     0,
       0,   173,   174,   175,   176,   177,   178,   179,   180,   181,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   182,   183,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,     0,   199,     0,   201,   202,     0,
       0,     0,     0,     0,     0,   204,   205,   206,   207,   208,
     209,   210,   211,     0,     0,   212,   213,   214,   215,   216,
     217,   218,   219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     227,   228,   229,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   233,   234,   235,   236,     0,   237,
     238,     0,   239,   240,   241,   242,   243,   244,   245,     0,
     247,   248,   249,   250,     1,     2,     3,     0,   322,     0,
    1224,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    16,
      17,     0,     0,    20,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    29,     0,     0,     0,    32,
      33,    34,     0,    35,     0,    37,    38,    39,   301,   302,
      42,   303,    44,    45,    46,    47,    48,     0,   304,     0,
     305,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    62,    63,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,     0,
      77,     0,    79,    80,    81,    82,    83,    84,    85,    86,
       0,     0,     0,    89,     0,    91,    92,    93,   306,   307,
      96,    97,    98,    99,   100,   101,   102,   103,     0,     0,
       0,   104,   105,     0,     0,     0,     0,     0,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,     0,
       0,     0,     0,     0,     0,   133,     0,     0,     0,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   149,   150,
     151,   152,     0,     0,     0,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,     0,     0,   170,
     171,   172,     0,     0,   173,   174,   175,   176,   177,   178,
     179,   180,   181,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   182,   183,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,     0,   199,     0,
     201,   202,     0,     0,     0,     0,     0,     0,   204,   205,
     206,   207,   208,   209,   210,   211,     0,     0,   212,   213,
     214,   215,   216,   217,   218,   219,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   227,   228,   229,     0,     0,     0,     0,
       0,     0,     1,     2,     3,     0,     4,   233,   234,   235,
     236,     0,   237,   238,     0,   239,   240,   241,   242,   243,
     244,   245,     0,   247,   248,   249,   250,    16,    17,     0,
       0,    20,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29,     0,     0,     0,    32,    33,    34,
       0,    35,     0,    37,    38,    39,   301,   302,    42,   303,
      44,    45,    46,    47,    48,     0,   304,     0,   305,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    62,    63,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,     0,    77,     0,
      79,    80,    81,    82,    83,    84,    85,    86,     0,     0,
       0,    89,     0,    91,    92,    93,   306,   307,    96,    97,
      98,    99,   100,   101,   102,   103,     0,     0,     0,   104,
     105,     0,     0,     0,     0,     0,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,     0,     0,     0,
       0,     0,     0,   133,     0,     0,     0,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   149,   150,   151,   152,
       0,     0,     0,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,     0,     0,   170,   171,   172,
       0,     0,   173,   174,   175,   176,   177,   178,   179,   180,
     181,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   182,   183,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,     0,   199,     0,   201,   202,
       0,     0,     0,     0,     0,     0,   204,   205,   206,   207,
     208,   209,   210,   211,     0,     0,   212,   213,   214,   215,
     216,   217,   218,   219,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   227,   228,   229,     0,     0,     0,     0,     0,     0,
       1,     2,     3,     0,   322,   233,   234,   235,   236,     0,
     237,   238,     0,   239,   240,   241,   242,   243,   244,   245,
       0,   247,   248,   249,   250,    16,    17,     0,     0,    20,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    29,     0,     0,     0,    32,    33,    34,     0,    35,
       0,    37,    38,    39,   301,   302,    42,   303,    44,    45,
      46,    47,    48,     0,   304,     0,   305,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      62,    63,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,     0,    77,     0,    79,    80,
      81,    82,    83,    84,    85,    86,     0,     0,     0,    89,
       0,    91,    92,    93,   306,   307,    96,    97,    98,    99,
     100,   101,   102,   103,     0,     0,     0,   104,   105,     0,
       0,     0,     0,     0,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,     0,     0,     0,     0,     0,
       0,   133,     0,     0,     0,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   149,   150,   151,   152,     0,     0,
       0,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,     0,     0,   170,   171,   172,     0,     0,
     173,   174,   175,   176,   177,   178,   179,   180,   181,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   182,   183,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,     0,   199,     0,   201,   202,     0,     0,
       0,     0,     0,     0,   204,   205,   206,   207,   208,   209,
     210,   211,     0,     0,   212,   213,   214,   215,   216,   217,
     218,   219,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   227,
     228,   229,     0,     0,     0,     0,     0,     0,     1,     0,
       0,     0,   300,   233,   234,   235,   236,     0,   237,   238,
       0,   239,   240,   241,   242,   243,   244,   245,     0,   247,
     248,   249,   250,    16,    17,     0,     0,    20,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    29,
       0,     0,     0,    32,    33,    34,     0,    35,     0,    37,
      38,    39,   301,   302,    42,   303,    44,    45,    46,    47,
      48,     0,   304,     0,   305,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,     0,    77,     0,    79,    80,    81,    82,
      83,    84,    85,    86,     0,     0,     0,    89,     0,    91,
      92,    93,   306,   307,    96,    97,    98,    99,   100,   101,
     102,   103,     0,     0,     0,   104,   105,     0,     0,     0,
       0,     0,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,     0,     0,     0,     0,     0,     0,   133,
       0,     0,     0,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   149,   150,   151,   152,     0,     0,     0,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,     0,     0,   170,   171,   172,     0,     0,   173,   174,
     175,   176,   177,   178,   179,   180,   181,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   182,   183,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,     0,   199,     0,   201,   202,     0,     0,     0,     0,
       0,     0,   204,   205,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   227,   228,   229,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     300,   233,   234,   235,   236,     0,   237,   238,     0,   239,
     240,   241,   242,   243,   244,   245,     0,   247,   248,   249,
     250,    16,    17,     0,     0,    20,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    29,     0,     0,
       0,    32,    33,    34,     0,    35,     0,    37,    38,    39,
     301,   302,    42,   303,    44,    45,    46,    47,    48,     0,
     304,     0,   305,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,     0,    77,     0,    79,    80,    81,    82,    83,    84,
      85,    86,     0,     0,     0,    89,     0,    91,    92,    93,
     306,   307,    96,    97,    98,    99,   100,   101,   102,   103,
       0,     0,     0,   104,   105,     0,     0,     0,     0,     0,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,     0,     0,     0,     0,     0,     0,   133,     0,     0,
       0,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     149,   150,   151,   152,     0,     0,     0,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,     0,
       0,   170,   171,   172,     0,     0,   173,   174,   175,   176,
     177,   178,   179,   180,   181,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   182,
     183,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,     0,
     199,     0,   201,   202,     0,     0,     0,     0,     0,     0,
     204,   205,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   227,   228,   229,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   233,
     234,   235,   236,     0,   237,   238,     0,   239,   240,   241,
     242,   243,   244,   245,     0,   247,   248,   249,   250
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
         8,     9,    10,   222,     0,    23,     0,    46,     1,   110,
      23,    46,    47,    19,     5,     6,    41,    21,    19,    22,
      19,  1885,  1886,  1887,    37,    10,    11,     4,   225,     2,
       3,    49,   522,   523,    61,    19,    14,    53,    54,    64,
     258,   259,    20,   533,    13,    13,    73,    15,    75,    74,
     214,   215,   216,   217,   218,   219,   220,   221,   222,    53,
      89,   279,    23,   260,    54,    89,    90,    91,    92,    93,
      86,   268,    59,    61,    56,    63,    37,    56,    14,    61,
      54,   110,    61,    19,    71,    20,   110,    75,    23,    61,
      63,    90,    91,    75,   258,    13,    75,    87,    13,   103,
     103,    19,    20,    75,    56,    13,    13,    59,   124,   110,
      13,    19,    20,   104,   105,    67,    68,    69,    70,    14,
     159,   340,   341,    19,    14,    20,   106,   107,    23,    13,
      20,    99,   100,    23,    13,    19,    20,   153,   258,   259,
     108,    13,   158,   159,   160,   161,   162,    19,    14,    13,
     369,    15,   158,    19,    20,   382,   383,    61,   385,   386,
      13,   388,   382,   383,    13,   385,   386,    13,   388,    13,
      19,    75,    13,    19,    15,   191,   192,   193,   258,   259,
     260,    59,   262,   263,   264,    15,    20,   267,    22,    23,
     270,   271,   272,   273,   274,   275,   276,   277,     7,     8,
     280,    14,   220,    12,   284,    13,    14,    20,    13,   289,
     290,    19,    13,   231,   232,    13,   224,    13,    14,    13,
     300,    13,    14,    19,    14,   305,   306,    19,   222,    13,
      20,    15,    13,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,  2111,    13,  2113,
      15,    13,  2116,  2117,   355,    14,   281,    13,    14,    14,
      13,    20,    14,    19,   260,    20,   260,    14,    20,   285,
     286,    14,    14,    20,    13,   291,    14,    20,    20,    14,
      19,    14,    20,    14,    14,    20,    14,    20,   304,    20,
      20,    13,    20,    14,   329,   330,   331,   332,    14,    20,
      60,   291,    62,    14,    20,    14,   322,    14,   527,    20,
      14,    20,   320,    20,    14,    14,    20,   291,    14,    14,
      20,    20,    19,    14,    20,    20,    19,    14,   525,    20,
      13,   349,   322,    20,    14,    14,   363,    14,   330,   331,
      20,    20,    13,    20,   352,   322,   340,   341,   322,   362,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   370,   371,    14,    14,    14,    14,    14,   566,
      20,    20,    20,    20,    20,   369,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   581,   582,
     583,   584,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   579,   580,  2270,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,   585,   586,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    14,    14,
     478,   479,    14,   481,    20,    20,    14,    14,    20,    14,
      13,    13,    20,    20,   492,    20,   494,   258,    14,    14,
      14,    14,    14,    14,    20,    20,    20,    20,    20,    20,
      14,    20,    14,    22,    14,    13,    20,   278,    20,   527,
      20,   153,   154,   155,   491,   286,   287,   288,   289,   290,
      13,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   527,   153,   154,   155,    13,    13,   547,
     593,   594,   595,   596,   597,   598,    20,    13,    22,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,   569,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,   571,    13,   571,    13,   572,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,   599,    13,    13,    13,    13,    13,    13,    13,   607,
      13,    13,   610,   576,   577,   578,    13,   603,   602,   603,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,   396,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,   612,
     837,    13,    13,   414,    13,    13,    13,    13,    13,    13,
     847,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,  1153,    13,    13,  1156,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,   399,    13,    13,    13,    13,   905,    19,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,     0,     4,    73,    13,   328,    17,    19,    18,   377,
      15,    19,    19,    19,   102,    19,    19,    14,    19,   285,
     352,   391,   279,    73,   353,    13,    73,   322,   603,    14,
      14,   153,    22,    14,    20,    14,    13,    20,    13,   153,
      13,    13,    13,    13,    13,    13,    73,    73,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      56,    56,    13,    13,    13,    13,    57,    56,    13,    13,
      13,    13,    13,    73,    13,    73,    63,    13,    13,    73,
      73,    73,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    58,    72,    71,    16,    14,    14,    14,    64,    20,
      20,    16,    14,    14,    20,    14,    16,    20,    16,    14,
      63,    58,    64,    20,    20,  1164,    20,    20,    20,    20,
      20,    20,    20,    20,    20,   833,    20,    20,    20,    14,
      20,    20,    20,    20,    13,    13,    20,    14,    20,    20,
      20,    73,   587,    13,    20,    20,    20,    20,    20,    20,
      14,    14,    14,    20,    14,    20,    22,    71,   590,    20,
      14,    20,    20,    20,    20,    20,    14,    16,    20,    20,
      20,    62,   110,    20,    20,    20,    20,    20,    20,    20,
      20,    14,    20,    14,    20,    20,    20,    73,    20,   592,
      20,    20,    20,    20,    20,    20,    20,    14,    14,    20,
      20,    20,    20,    14,    13,    20,    20,    20,    20,  1399,
      20,   905,    20,    20,    20,    20,    20,    20,    20,    14,
      14,    20,    20,    20,    20,    14,    14,    20,    20,    20,
      20,    16,    14,    20,    14,    14,    14,    14,    14,    20,
     591,    14,    14,    14,    14,    20,    20,    14,   944,    13,
     944,    20,    20,    14,    20,   963,   964,    20,    20,   967,
     968,   969,   970,   971,   972,    20,   974,   975,    20,    20,
      20,   979,   980,   981,   982,   983,   984,   985,    20,   987,
      20,   989,    20,   991,   992,    14,   994,   995,   996,   997,
     998,    14,    20,    20,    20,  1003,  1004,  1005,    20,    14,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    59,    59,    74,    16,    13,    16,  1026,  1027,
      20,  1029,  1030,  1031,  1032,  1033,    20,  1035,  1036,  1037,
    1038,  1039,  1040,    13,  1042,    19,    13,    13,    13,    13,
      13,  1049,  1050,  1051,  1052,  1053,  1054,  1055,  1056,    20,
    1058,    16,    13,    13,    13,    22,    20,    20,    20,    14,
      56,    14,    20,    20,    20,  1073,    20,    14,    20,  1077,
    1078,  1079,    20,    14,  1082,  1083,  1084,  1085,  1086,  1087,
      14,  1089,    14,    20,  1092,  1093,  1094,  1095,  1096,  1097,
    1098,  1099,  1100,  1101,    20,    20,  1104,    20,    20,    14,
      14,    20,    20,    20,    20,  1113,  1114,  1115,  1116,  1117,
    1118,  1119,  1120,  1121,  1122,  1123,    14,    20,    14,  1127,
    1128,    20,  1130,  1131,  1614,  1133,  1134,  1135,  1136,  1137,
      14,    14,    20,  1141,  1624,    20,  1626,    14,    20,    20,
      19,  1149,  1150,    14,    20,    20,    20,    14,    14,    14,
      14,    20,    14,  1161,    14,    14,    14,    20,    14,    20,
    1168,  1169,    14,  1171,  1172,    14,    20,  1175,  1176,  1177,
      14,  1179,    20,  1181,    20,  1183,  1184,    20,    20,    20,
      20,    20,  1190,    20,    20,    20,  1194,  1195,  1196,    20,
      20,  1199,  1389,  1390,    20,    20,  1204,  1205,  1206,  1207,
    1208,  1209,  1210,    20,    20,    20,    20,  1215,    20,    20,
      14,    14,  1220,  1221,    20,    20,  1224,  1213,  1437,  1213,
    1228,  1229,    20,    20,    20,    20,    14,    14,    20,    14,
      14,    14,    14,    22,    20,    59,    59,    59,    14,    20,
      20,    20,    20,    20,    14,    20,    20,    14,    14,    14,
      14,    20,    20,    74,    14,    14,    14,    20,    20,    20,
      59,  1219,    56,    20,    20,    20,    20,    20,    20,    14,
      14,    14,    14,    14,    14,    14,    22,   110,   260,    14,
      14,    14,    20,    20,    20,    14,    14,    14,    20,    20,
      20,    14,   260,    14,    20,    20,    20,    -1,    20,    14,
      20,    20,    20,    20,    14,    14,    20,    20,    20,    20,
      14,    14,    20,    20,    20,    20,    14,    14,    20,    14,
      20,    20,    14,    -1,    20,    14,    20,    20,    16,    20,
      20,    14,    14,    20,    14,    20,    14,    14,    14,    20,
      14,    20,    14,    59,    14,    20,    14,    20,    14,    20,
      14,    20,    14,    20,    14,    20,    14,    20,    59,    20,
      14,    20,  1000,    20,    20,    20,    14,    20,    20,    20,
      14,    14,    14,    20,    14,    20,    22,    14,    19,  1387,
     260,    20,    20,    -1,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    14,    20,    20,
      20,    20,    20,    14,    20,    20,    14,    20,    14,    59,
      20,    20,    -1,    20,    14,    20,    20,    20,    20,    20,
      14,    20,    20,    20,    20,    20,    14,    20,    20,    20,
    1627,    14,    14,    14,    20,    20,    20,    14,    -1,    14,
      20,    20,  1932,  1437,    20,    59,    20,  1455,    14,    20,
    1458,  1459,  1460,  1461,    14,  1463,    20,  1465,    20,    20,
      14,    20,    20,  1471,  1472,  1473,    14,    20,  1476,  1477,
    1478,  1479,    22,  1481,    20,  1483,    20,  1485,    20,    20,
    1488,  1489,  1490,  1491,    20,    20,    20,  1495,    20,    14,
    1498,    14,    14,    56,    20,    14,    20,    14,    14,    20,
      20,    14,    20,   589,    14,    20,    20,  1515,    20,    20,
      14,    20,  1520,    20,    20,    20,  1524,  1525,  1526,  1527,
    1528,  1529,  1530,  1531,  1532,  1533,  1534,  1535,  1536,  1537,
    1538,  1539,  1540,  1541,  1542,  1543,  1513,    20,  1546,    20,
      20,    20,    20,    20,    20,    20,  1554,    14,    14,    14,
      20,    20,  1560,  1561,  1562,  1563,    20,  1565,  1566,  1567,
      20,  1569,  1570,    20,    20,    20,    20,    20,  1576,  1577,
    1578,  1579,    20,    14,    14,    20,    20,  1585,    14,    14,
    1588,  1589,    20,    20,    14,    14,    20,  1784,    20,  1786,
    1598,  1599,  1600,  1601,    20,  1792,    14,    14,    14,    14,
      14,    20,    22,  1611,  1612,  1613,    14,    20,    20,    20,
    1618,    20,    14,    20,    20,    20,    20,    20,    14,    20,
      20,  1629,  1630,    14,  1632,  1633,    14,  1635,  1636,  1637,
      14,    14,    14,  1641,  1642,    14,    14,  1645,    14,    20,
    1648,    14,  1650,  1651,  1652,    20,    14,    14,    20,  1657,
      20,    20,  1660,    14,  1662,    14,    14,    20,  1666,  1667,
    1668,    14,  1670,    14,  1672,  1673,    20,  1675,    14,    14,
      14,    14,    14,    20,    14,    14,    14,   588,    14,    20,
      14,    14,    14,    20,    14,    20,    14,    14,    14,    20,
      14,    20,    14,    14,   602,    20,    -1,    20,    14,    -1,
      20,    20,    20,    20,    14,    20,    20,    14,  1716,    20,
      -1,    20,    20,    14,    20,    20,    20,    20,    14,    -1,
      20,    20,    20,    20,    14,    20,    14,    14,    20,    14,
      14,    20,   260,   260,    20,    -1,    -1,    20,    20,    20,
      20,    20,    20,    20,    20,    14,    20,    20,    20,    20,
      14,    14,    14,    20,    14,    14,    14,    14,    14,    20,
     260,   260,    -1,    -1,    14,    20,    20,    20,    20,    20,
      -1,    20,    20,    20,    20,  1783,    20,    14,    14,    20,
      14,    14,    14,    14,    -1,    20,    -1,    -1,    -1,    14,
      20,    20,    20,    20,    20,    14,    20,    14,    14,    20,
      20,    -1,    20,    -1,    -1,    20,    20,    20,    20,    20,
      20,    14,    20,    20,    20,    14,    20,    14,    20,  1827,
      14,  1829,    -1,  1831,    -1,  1833,    -1,  1835,    -1,    -1,
      -1,    -1,  1840,  1841,    -1,  1843,  1844,  1845,  1846,    -1,
    1848,  1849,  1850,  1851,    -1,    -1,    -1,  1855,    -1,    -1,
    2047,    -1,    -1,    -1,    -1,  1863,  1864,    -1,    -1,  1867,
      -1,  1869,    -1,  1871,    -1,  1873,  1874,  1875,  1876,    -1,
    1878,  1879,  1880,  1881,  1882,  1883,    -1,  1885,  1886,    -1,
    1888,  1889,  1890,  1891,  1861,  1893,  1894,  1895,  1896,  1897,
      -1,  1899,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1909,  1910,  1911,  1912,  1913,  1914,  1915,    -1,    -1,
    1918,    -1,    -1,  1921,  1922,    -1,  1924,  1925,  1926,    -1,
      -1,    -1,  1930,  1931,    -1,    -1,  1934,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1942,  1943,    -1,  1945,    -1,    -1,
      -1,  1949,  1950,    -1,  1952,  1953,    -1,  1955,    -1,  1957,
    1958,    -1,  1960,    -1,  1962,  1963,  1964,  1965,  1966,  1967,
    1968,  1969,  1970,  1971,  1972,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2074,    -1,    -1,  2077,
    2078,    -1,  2080,  2081,    -1,  2083,  2084,    -1,  2086,  2087,
    2088,    -1,  2090,    -1,    -1,    -1,  2094,  2095,    -1,  2097,
      -1,  2099,  2100,  2101,  2102,  2103,    -1,  2105,  2106,  2107,
    2108,  2109,  2110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2118,  2119,  2120,    -1,     0,    -1,  2093,    -1,  2126,  2127,
      -1,    -1,  2130,    -1,  2132,  2133,    -1,    -1,  2136,  2137,
      -1,  2139,  2140,    -1,    -1,    -1,    22,    -1,  2146,    25,
      -1,    -1,    -1,    -1,    -1,  2153,  2154,  2155,    -1,    -1,
    2158,  2159,  2160,  2161,    -1,  2163,    -1,    -1,  2166,  2167,
      -1,    -1,    -1,    -1,    -1,    -1,  2174,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2240,    -1,    -1,  2243,  2244,  2245,    -1,    -1,
      -1,  2249,    -1,    -1,  2252,    -1,    -1,    -1,    -1,    -1,
    2258,    -1,  2260,    -1,  2262,    -1,    -1,  2265,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2275,  2276,    -1,
    2278,    -1,    -1,  2281,  2282,  2283,  2284,  2285,    -1,    -1,
      -1,  2289,    -1,  2291,    -1,    -1,  2294,  2295,  2296,  2297,
      -1,  2299,  2300,    -1,  2302,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2335,  2336,  2337,
    2338,  2339,    -1,    -1,    -1,  2343,   222,  2345,  2346,    -1,
    2348,  2349,  2350,    -1,  2352,  2353,    -1,  2355,  2356,  2357,
      -1,  2359,    -1,  2361,  2362,    -1,  2364,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2391,    -1,    -1,    -1,    -1,  2396,    -1,
      -1,    -1,  2400,  2401,  2402,    -1,    -1,  2405,  2406,    -1,
      -1,  2409,    -1,    -1,  2412,  2413,  2414,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2430,  2431,    -1,    -1,  2434,    -1,    -1,    -1,
    2438,    -1,    -1,  2441,  2442,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2452,    -1,    -1,  2455,    -1,    -1,
    2458,    -1,    -1,    -1,   340,   341,  2464,  2465,  2466,  2467,
      -1,    -1,    -1,    -1,  2472,  2473,  2474,    -1,    -1,    -1,
      -1,  2479,  2480,  2481,    -1,    -1,    -1,    -1,  2486,  2487,
      -1,    -1,    -1,   369,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   382,    -1,    -1,   385,
     386,   387,   388,   389,    -1,   391,   392,   393,   394,   395,
     396,   397,   398,   399,    -1,    -1,   402,    -1,    -1,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,    -1,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,    -1,    -1,    -1,    -1,    -1,
      -1,   437,   438,   439,   440,   441,   442,   443,   444,   445,
      -1,    -1,   448,   449,   450,   451,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   461,   462,   463,    -1,    -1,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,    -1,    -1,    -1,   480,   481,    -1,   483,    -1,   485,
      -1,    -1,    -1,   489,   490,    -1,    -1,    -1,    -1,    -1,
     496,   497,   498,   499,    -1,    -1,    -1,    -1,   504,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   527,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     536,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     0,    -1,    -1,    -1,     4,   554,   555,
     556,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    -1,    -1,   572,    -1,    -1,    26,
      27,    28,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   375,   376,
     377,   378,   379,   380,   381,    -1,   383,   384,    -1,    -1,
      -1,    -1,    -1,   390,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   400,   401,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   415,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   430,   431,   432,   433,   434,   435,   436,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   453,   454,   455,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     477,    -1,    -1,    -1,   181,   482,    -1,    -1,    -1,    -1,
      -1,   488,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   501,   502,   503,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,
      -1,    -1,   529,    -1,    -1,    -1,    -1,   534,   535,    -1,
     537,   538,    -1,   540,   541,   542,   543,   544,   545,   546,
      -1,   548,   549,   550,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   260,    -1,    -1,    -1,    28,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   300,   601,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   319,    -1,   321,   322,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   338,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   905,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   374,   375,   376,
     377,   378,   379,   380,   381,    -1,   383,   384,    -1,    -1,
      -1,    -1,    -1,   390,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   400,   401,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   415,    -1,
     181,   967,    -1,    -1,    -1,    -1,    -1,   973,    -1,    -1,
     976,    -1,    -1,   430,   431,   432,   433,   434,   435,   436,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   453,   454,   455,    -1,
     457,    -1,   459,   460,   225,   226,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1025,
     477,    -1,    -1,    -1,    -1,   482,    -1,    -1,  1034,    -1,
      -1,   488,    -1,    -1,   491,    -1,    -1,    -1,   495,  1045,
    1046,  1047,    -1,   500,   501,   502,   503,    -1,    -1,    -1,
      -1,  1057,    -1,    -1,    -1,    -1,  1062,    -1,  1064,  1065,
    1066,  1067,  1068,    -1,  1070,  1071,    -1,    -1,    -1,    -1,
      -1,   528,   529,    -1,    -1,    -1,    -1,   534,   535,    -1,
     537,   538,    -1,   540,   541,   542,   543,   544,   545,   546,
      -1,   548,   549,   550,   551,   552,  1102,    -1,   319,    -1,
     321,    -1,  1108,  1109,  1110,  1111,  1112,    -1,    -1,    -1,
      -1,    -1,   569,    -1,   571,    -1,    -1,   338,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   601,   602,   603,    -1,    -1,    -1,
      -1,    -1,    -1,   610,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1170,    -1,    -1,  1173,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1192,  1193,    -1,    -1,
      -1,    -1,    -1,    -1,  1200,    -1,  1202,  1203,  1204,  1205,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   681,   682,    -1,    -1,    -1,   986,
      -1,    -1,    -1,   690,    -1,    -1,   457,    -1,   459,   460,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   500,
      -1,    -1,  1288,  1289,    -1,    -1,  1043,  1044,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   528,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1075,    -1,
      -1,    -1,    -1,  1080,  1081,    -1,    -1,    -1,    -1,    -1,
     551,   552,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   834,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   881,  1182,    -1,    -1,  1185,  1186,
      -1,  1437,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1455,
      -1,  1457,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1469,  1470,    -1,    -1,    -1,    -1,   690,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   944,   945,    -1,
      -1,  1497,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   960,    -1,    -1,    -1,  1513,  1514,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1523,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1531,  1283,    -1,    -1,   986,
    1287,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1547,  1548,  1549,  1550,  1551,    -1,    -1,    -1,    -1,
      -1,  1008,    -1,  1010,    -1,    -1,  1013,    -1,    -1,    -1,
      -1,  1018,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1332,    -1,    -1,    -1,    -1,
    1586,  1587,    -1,    -1,    -1,    -1,  1043,  1044,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1603,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   834,    -1,    -1,    -1,    -1,  1075,    -1,
      -1,    -1,    -1,  1080,  1081,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1647,    -1,    -1,    -1,    -1,    -1,    -1,  1105,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     881,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1182,    -1,    -1,  1185,  1186,
      -1,    -1,    -1,    -1,  1191,    -1,    -1,    -1,    -1,   960,
      -1,  1198,  1499,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1213,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1225,    -1,
      -1,    -1,    -1,  1230,  1231,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1008,    -1,  1010,
      -1,    -1,  1013,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1580,    -1,    -1,  1283,  1584,    -1,    -1,
    1287,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1609,    -1,    -1,  1861,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1332,    -1,    -1,    -1,  1885,
    1886,  1887,    -1,  1640,  1105,    -1,  1643,    -1,    -1,    -1,
      -1,    -1,  1898,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1919,  1920,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1148,    -1,    -1,
      -1,  1388,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1954,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1191,    -1,    -1,    -1,    -1,    -1,    -1,  1198,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1454,    -1,    -1,
      -1,    -1,    -1,    -1,  1225,    -1,    -1,    -1,    -1,  1230,
    1231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1499,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2093,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2111,    -1,  2113,  1565,    -1,
    2116,  2117,    -1,    -1,    -1,  2121,  2122,  2123,  2124,    -1,
      -1,    -1,    -1,  1580,    -1,    -1,    -1,  1584,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2143,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1903,    -1,  1905,  1906,
      -1,  1908,  1609,    -1,    -1,    -1,  2162,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1388,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1640,    -1,    -1,  1643,    -1,    -1,    -1,
    1947,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1655,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1454,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2270,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2287,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2298,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2354,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2363,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1823,  1824,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2142,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2157,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2443,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1903,    -1,  1905,  1906,
      -1,  1908,    -1,  2459,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1947,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2293,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1823,  1824,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2388,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2398,    -1,    -1,    -1,    -1,    -1,  2404,    -1,    -1,
      -1,    -1,    -1,    -1,  2411,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2440,    -1,  2142,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2157,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2293,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2388,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2398,     0,    -1,    -1,    -1,    -1,  2404,    -1,    -1,
      -1,     9,    10,    11,  2411,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,  2440,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    51,    52,    -1,    54,    55,    56,    -1,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    -1,    80,    81,    82,    83,    84,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,    -1,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,    -1,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,    -1,    -1,    -1,   156,   157,
      -1,    -1,    -1,    -1,    -1,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,    -1,
      -1,   249,   250,   251,   252,   253,   254,   255,   256,   257,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   282,   283,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,    -1,   323,   324,   325,   326,   327,
      -1,    -1,    -1,    -1,    -1,   333,   334,   335,   336,   337,
     338,   339,   340,    -1,    -1,   343,   344,   345,   346,   347,
     348,   349,   350,   351,    -1,    -1,    -1,    -1,   356,    -1,
     358,   359,   360,    -1,    -1,    -1,   364,   365,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     378,   379,   380,   381,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   389,   390,    -1,   392,   393,   394,   395,    -1,   397,
     398,    -1,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,    -1,   415,   416,   417,
     418,   419,   420,     9,    10,    11,    -1,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    -1,    42,    43,    44,    45,
      46,    47,    48,    -1,    50,    51,    52,    -1,    54,    55,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    -1,    80,    81,    82,    83,    84,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    99,   100,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,    -1,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,    -1,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,    -1,    -1,    -1,
     156,   157,    -1,    -1,    -1,    -1,    -1,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,    -1,    -1,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   282,   283,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,    -1,   323,   324,   325,
     326,   327,    -1,    -1,    -1,    -1,    -1,   333,   334,   335,
     336,   337,   338,   339,   340,    -1,    -1,   343,   344,   345,
     346,   347,   348,   349,   350,   351,    -1,    -1,    -1,    -1,
     356,    -1,   358,   359,   360,    -1,    -1,    -1,   364,   365,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   378,   379,   380,   381,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   389,   390,    -1,   392,   393,   394,   395,
      -1,   397,   398,    -1,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,    -1,   415,
     416,   417,   418,   419,   420,     9,    10,    11,    -1,    13,
      -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,    -1,    38,    39,    -1,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,
      54,    55,    56,    -1,    58,    -1,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    99,   100,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
      -1,   125,    -1,   127,   128,   129,   130,   131,   132,   133,
     134,    -1,    -1,    -1,   138,    -1,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,    -1,
      -1,    -1,   156,   157,    -1,    -1,    -1,    -1,    -1,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
      -1,    -1,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   223,
     224,   225,   226,    -1,    -1,    -1,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,    -1,    -1,
     244,   245,   246,    -1,    -1,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   281,   282,   283,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,    -1,   323,
      -1,   325,   326,    -1,   328,    -1,    -1,    -1,    -1,   333,
     334,   335,   336,   337,   338,   339,   340,    -1,    -1,   343,
     344,   345,   346,   347,   348,   349,   350,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   378,   379,   380,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   392,   393,
     394,   395,    -1,   397,   398,    -1,   400,   401,   402,   403,
     404,   405,   406,    -1,   408,   409,   410,   411,     9,    10,
      11,    -1,    13,    -1,    -1,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    -1,    -1,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      -1,    -1,    -1,    54,    55,    56,    -1,    58,    -1,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,    -1,   125,    -1,   127,   128,   129,   130,
     131,   132,   133,   134,    -1,    -1,    -1,   138,    -1,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,    -1,    -1,    -1,   156,   157,    -1,    -1,    -1,
      -1,    -1,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,    -1,    -1,    -1,    -1,    -1,    -1,   190,
      -1,    -1,    -1,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   223,   224,   225,   226,    -1,    -1,    -1,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,    -1,    -1,   244,   245,   246,    -1,    -1,   249,   250,
     251,   252,   253,   254,   255,   256,   257,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   282,   283,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,    -1,   323,    -1,   325,   326,    -1,    -1,    -1,    -1,
      -1,    -1,   333,   334,   335,   336,   337,   338,   339,   340,
      -1,    -1,   343,   344,   345,   346,   347,   348,   349,   350,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   378,   379,   380,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   392,   393,   394,   395,    -1,   397,   398,    -1,   400,
     401,   402,   403,   404,   405,   406,    -1,   408,   409,   410,
     411,     9,    10,    11,    -1,    13,    -1,    -1,    -1,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    -1,
      38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    -1,    -1,    -1,    54,    55,    56,    -1,
      58,    -1,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,    -1,   125,    -1,   127,
     128,   129,   130,   131,   132,   133,   134,    -1,    -1,    -1,
     138,    -1,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,    -1,    -1,    -1,   156,   157,
      -1,    -1,    -1,    -1,    -1,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,
      -1,    -1,   190,    -1,    -1,    -1,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   223,   224,   225,   226,    -1,
      -1,    -1,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,    -1,    -1,   244,   245,   246,    -1,
      -1,   249,   250,   251,   252,   253,   254,   255,   256,   257,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   282,   283,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,    -1,   323,    -1,   325,   326,    -1,
      -1,    -1,    -1,    -1,    -1,   333,   334,   335,   336,   337,
     338,   339,   340,    -1,    -1,   343,   344,   345,   346,   347,
     348,   349,   350,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     378,   379,   380,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   392,   393,   394,   395,    -1,   397,
     398,    -1,   400,   401,   402,   403,   404,   405,   406,    -1,
     408,   409,   410,   411,     9,    10,    11,    -1,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      35,    -1,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    54,
      55,    56,    -1,    58,    -1,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    -1,    73,    -1,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,    -1,
     125,    -1,   127,   128,   129,   130,   131,   132,   133,   134,
      -1,    -1,    -1,   138,    -1,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,    -1,    -1,
      -1,   156,   157,    -1,    -1,    -1,    -1,    -1,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,    -1,
      -1,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   223,   224,
     225,   226,    -1,    -1,    -1,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,   244,
     245,   246,    -1,    -1,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   282,   283,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,    -1,   323,    -1,
     325,   326,    -1,    -1,    -1,    -1,    -1,    -1,   333,   334,
     335,   336,   337,   338,   339,   340,    -1,    -1,   343,   344,
     345,   346,   347,   348,   349,   350,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   378,   379,   380,    -1,    -1,    -1,    -1,
      -1,    -1,     9,    10,    11,    -1,    13,   392,   393,   394,
     395,    -1,   397,   398,    -1,   400,   401,   402,   403,   404,
     405,   406,    -1,   408,   409,   410,   411,    34,    35,    -1,
      -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    -1,    -1,    -1,    54,    55,    56,
      -1,    58,    -1,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,    -1,   125,    -1,
     127,   128,   129,   130,   131,   132,   133,   134,    -1,    -1,
      -1,   138,    -1,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,    -1,    -1,    -1,   156,
     157,    -1,    -1,    -1,    -1,    -1,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,    -1,    -1,    -1,
      -1,    -1,    -1,   190,    -1,    -1,    -1,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   223,   224,   225,   226,
      -1,    -1,    -1,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,    -1,    -1,   244,   245,   246,
      -1,    -1,   249,   250,   251,   252,   253,   254,   255,   256,
     257,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   282,   283,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,    -1,   323,    -1,   325,   326,
      -1,    -1,    -1,    -1,    -1,    -1,   333,   334,   335,   336,
     337,   338,   339,   340,    -1,    -1,   343,   344,   345,   346,
     347,   348,   349,   350,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   378,   379,   380,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   392,   393,   394,   395,    -1,
     397,   398,    -1,   400,   401,   402,   403,   404,   405,   406,
      -1,   408,   409,   410,   411,     9,    10,    11,    -1,    13,
      -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,    -1,    38,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,
      54,    55,    56,    -1,    58,    -1,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    -1,    73,
      -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    99,   100,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
      -1,   125,    -1,   127,   128,   129,   130,   131,   132,   133,
     134,    -1,    -1,    -1,   138,    -1,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,    -1,
      -1,    -1,   156,   157,    -1,    -1,    -1,    -1,    -1,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
      -1,    -1,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   223,
     224,   225,   226,    -1,    -1,    -1,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,    -1,    -1,
     244,   245,   246,    -1,    -1,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   282,   283,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,    -1,   323,
      -1,   325,   326,    -1,    -1,    -1,    -1,    -1,    -1,   333,
     334,   335,   336,   337,   338,   339,   340,    -1,    -1,   343,
     344,   345,   346,   347,   348,   349,   350,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   378,   379,   380,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   392,   393,
     394,   395,    -1,   397,   398,    -1,   400,   401,   402,   403,
     404,   405,   406,    -1,   408,   409,   410,   411,     9,    10,
      11,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    -1,    -1,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      -1,    -1,    -1,    54,    55,    56,    -1,    58,    -1,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    -1,    73,    -1,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,    -1,   125,    -1,   127,   128,   129,   130,
     131,   132,   133,   134,    -1,    -1,    -1,   138,    -1,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,    -1,    -1,    -1,   156,   157,    -1,    -1,    -1,
      -1,    -1,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,    -1,    -1,    -1,    -1,    -1,    -1,   190,
      -1,    -1,    -1,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   223,   224,   225,   226,    -1,    -1,    -1,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,    -1,    -1,   244,   245,   246,    -1,    -1,   249,   250,
     251,   252,   253,   254,   255,   256,   257,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   282,   283,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,    -1,   323,    -1,   325,   326,    -1,    -1,    -1,    -1,
      -1,    -1,   333,   334,   335,   336,   337,   338,   339,   340,
      -1,    -1,   343,   344,   345,   346,   347,   348,   349,   350,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   378,   379,   380,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   392,   393,   394,   395,    -1,   397,   398,    -1,   400,
     401,   402,   403,   404,   405,   406,    -1,   408,   409,   410,
     411,     9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    -1,
      38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    -1,    -1,    -1,    54,    55,    56,    -1,
      58,    -1,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    -1,    73,    -1,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,    -1,   125,    -1,   127,
     128,   129,   130,   131,   132,   133,   134,    -1,    -1,    -1,
     138,    -1,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,    -1,    -1,    -1,   156,   157,
      -1,    -1,    -1,    -1,    -1,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,
      -1,    -1,   190,    -1,    -1,    -1,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   223,   224,   225,   226,    -1,
      -1,    -1,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,    -1,    -1,   244,   245,   246,    -1,
      -1,   249,   250,   251,   252,   253,   254,   255,   256,   257,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   282,   283,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,    -1,   323,    -1,   325,   326,    -1,
      -1,    -1,    -1,    -1,    -1,   333,   334,   335,   336,   337,
     338,   339,   340,    -1,    -1,   343,   344,   345,   346,   347,
     348,   349,   350,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     378,   379,   380,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   392,   393,   394,   395,    -1,   397,
     398,    -1,   400,   401,   402,   403,   404,   405,   406,    -1,
     408,   409,   410,   411,     9,    10,    11,    -1,    13,    -1,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      35,    -1,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    54,
      55,    56,    -1,    58,    -1,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    -1,    73,    -1,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,    -1,
     125,    -1,   127,   128,   129,   130,   131,   132,   133,   134,
      -1,    -1,    -1,   138,    -1,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,    -1,    -1,
      -1,   156,   157,    -1,    -1,    -1,    -1,    -1,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,    -1,
      -1,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   223,   224,
     225,   226,    -1,    -1,    -1,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,   244,
     245,   246,    -1,    -1,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   282,   283,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,    -1,   323,    -1,
     325,   326,    -1,    -1,    -1,    -1,    -1,    -1,   333,   334,
     335,   336,   337,   338,   339,   340,    -1,    -1,   343,   344,
     345,   346,   347,   348,   349,   350,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   378,   379,   380,    -1,    -1,    -1,    -1,
      -1,    -1,     9,    10,    11,    -1,    13,   392,   393,   394,
     395,    -1,   397,   398,    -1,   400,   401,   402,   403,   404,
     405,   406,    -1,   408,   409,   410,   411,    34,    35,    -1,
      -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    -1,    -1,    -1,    54,    55,    56,
      -1,    58,    -1,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    -1,    73,    -1,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,    -1,   125,    -1,
     127,   128,   129,   130,   131,   132,   133,   134,    -1,    -1,
      -1,   138,    -1,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,    -1,    -1,    -1,   156,
     157,    -1,    -1,    -1,    -1,    -1,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,    -1,    -1,    -1,
      -1,    -1,    -1,   190,    -1,    -1,    -1,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   223,   224,   225,   226,
      -1,    -1,    -1,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,    -1,    -1,   244,   245,   246,
      -1,    -1,   249,   250,   251,   252,   253,   254,   255,   256,
     257,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   282,   283,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,    -1,   323,    -1,   325,   326,
      -1,    -1,    -1,    -1,    -1,    -1,   333,   334,   335,   336,
     337,   338,   339,   340,    -1,    -1,   343,   344,   345,   346,
     347,   348,   349,   350,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   378,   379,   380,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    10,    11,    -1,    13,   392,   393,   394,   395,    -1,
     397,   398,    -1,   400,   401,   402,   403,   404,   405,   406,
      -1,   408,   409,   410,   411,    34,    35,    -1,    -1,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    -1,    -1,    -1,    54,    55,    56,    -1,    58,
      -1,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    -1,    73,    -1,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      99,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,    -1,   125,    -1,   127,   128,
     129,   130,   131,   132,   133,   134,    -1,    -1,    -1,   138,
      -1,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,    -1,    -1,    -1,   156,   157,    -1,
      -1,    -1,    -1,    -1,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,    -1,    -1,    -1,    -1,    -1,
      -1,   190,    -1,    -1,    -1,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   223,   224,   225,   226,    -1,    -1,
      -1,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,    -1,    -1,   244,   245,   246,    -1,    -1,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   282,   283,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,    -1,   323,    -1,   325,   326,    -1,    -1,
      -1,    -1,    -1,    -1,   333,   334,   335,   336,   337,   338,
     339,   340,    -1,    -1,   343,   344,   345,   346,   347,   348,
     349,   350,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   378,
     379,   380,    -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,
      -1,    -1,    13,   392,   393,   394,   395,    -1,   397,   398,
      -1,   400,   401,   402,   403,   404,   405,   406,    -1,   408,
     409,   410,   411,    34,    35,    -1,    -1,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      -1,    -1,    -1,    54,    55,    56,    -1,    58,    -1,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    -1,    73,    -1,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,    -1,   125,    -1,   127,   128,   129,   130,
     131,   132,   133,   134,    -1,    -1,    -1,   138,    -1,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,    -1,    -1,    -1,   156,   157,    -1,    -1,    -1,
      -1,    -1,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,    -1,    -1,    -1,    -1,    -1,    -1,   190,
      -1,    -1,    -1,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   223,   224,   225,   226,    -1,    -1,    -1,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,    -1,    -1,   244,   245,   246,    -1,    -1,   249,   250,
     251,   252,   253,   254,   255,   256,   257,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   282,   283,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,    -1,   323,    -1,   325,   326,    -1,    -1,    -1,    -1,
      -1,    -1,   333,   334,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   378,   379,   380,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      13,   392,   393,   394,   395,    -1,   397,   398,    -1,   400,
     401,   402,   403,   404,   405,   406,    -1,   408,   409,   410,
     411,    34,    35,    -1,    -1,    38,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,
      -1,    54,    55,    56,    -1,    58,    -1,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    -1,
      73,    -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,    -1,   125,    -1,   127,   128,   129,   130,   131,   132,
     133,   134,    -1,    -1,    -1,   138,    -1,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
      -1,    -1,    -1,   156,   157,    -1,    -1,    -1,    -1,    -1,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,    -1,    -1,    -1,    -1,    -1,    -1,   190,    -1,    -1,
      -1,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     223,   224,   225,   226,    -1,    -1,    -1,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,    -1,
      -1,   244,   245,   246,    -1,    -1,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   282,
     283,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,    -1,
     323,    -1,   325,   326,    -1,    -1,    -1,    -1,    -1,    -1,
     333,   334,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   378,   379,   380,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   392,
     393,   394,   395,    -1,   397,   398,    -1,   400,   401,   402,
     403,   404,   405,   406,    -1,   408,   409,   410,   411
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  Parser::yystos_[] =
  {
         0,     9,    10,    11,    13,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    42,    43,    44,    45,    46,    47,    48,    50,
      51,    52,    54,    55,    56,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    80,    81,    82,    83,
      84,    85,    99,   100,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   156,   157,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   282,   283,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   323,
     324,   325,   326,   327,   333,   334,   335,   336,   337,   338,
     339,   340,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   356,   358,   359,   360,   364,   365,   378,   379,   380,
     381,   389,   390,   392,   393,   394,   395,   397,   398,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   415,   416,   417,   418,   419,   420,   425,
     426,   427,   428,   429,   430,   433,   434,   435,   436,   440,
     444,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   471,   472,   473,   474,   475,   476,   477,
      13,    63,    64,    66,    73,    75,   143,   144,   449,   453,
     475,   455,   455,   448,   469,   445,   469,   445,   445,    13,
      13,    13,    13,   447,   469,    73,   363,   449,    56,    67,
      68,    69,    70,   473,   449,   469,   469,   447,    13,   447,
      13,    13,    19,    19,    90,    91,    19,   110,   473,    19,
     158,    19,    15,    60,    62,    63,    64,    65,    66,    72,
      73,    74,    75,   449,   475,   477,   478,   479,   447,    13,
      13,    13,   454,   455,    13,    13,    15,    13,    13,    15,
      13,    15,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    19,    19,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    15,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    15,   447,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,   455,   455,   455,   455,   455,
     455,   455,   455,   455,   455,   455,   455,   455,   455,   473,
     441,   442,   479,   445,   427,   447,   447,    13,    13,    13,
      13,    71,   473,   473,    13,    13,    13,    13,    13,    19,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,     0,     0,   427,
     428,   429,   430,   433,   434,   435,   436,   427,    19,    13,
      19,    13,    15,    99,   100,   108,     7,     8,    12,    10,
      11,     5,     6,   104,   105,   106,   107,    17,    18,   102,
       4,    21,   103,    89,    90,    91,    92,    93,   110,    13,
      19,    89,   110,    13,    19,    19,    19,    15,    19,    19,
      13,    19,    14,    14,   447,   445,   447,   448,   447,   479,
     479,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   258,   278,   286,   287,
     288,   289,   290,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   396,   414,   258,   259,   260,
     262,   263,   264,   267,   270,   271,   272,   273,   274,   275,
     276,   277,   280,   284,   289,   290,   300,   305,   306,    73,
      73,    46,    47,   329,   330,   331,   332,   328,   473,    46,
     159,   445,   479,   445,   445,   446,   469,   446,   469,   446,
     446,   446,   446,   446,   446,   449,   446,   446,   449,   449,
     449,   449,   449,   446,   449,   449,   449,   449,   449,   449,
     449,   449,   449,   446,   446,   449,   153,   154,   155,   153,
     154,   155,   449,   449,   449,   449,   449,   449,   449,   449,
     449,   449,   446,   449,   449,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   449,   449,   449,   446,   449,   446,
     446,   446,   446,   446,   446,   449,   449,   449,   449,   449,
     449,   449,   449,   449,    73,    73,   449,   449,   449,   449,
      73,   446,   446,   446,    73,   447,    73,   447,   447,   449,
     449,   449,    56,    56,   449,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   449,   446,   445,   445,   449,   445,
     449,   446,   449,    73,   449,    73,    73,   446,   449,   449,
      14,   445,   445,   469,   449,   449,   449,   449,   447,   446,
     446,   446,   449,   110,   355,    57,   441,   441,   427,   473,
     479,   447,   446,    56,   432,   431,    22,   441,   446,   446,
     449,   446,   446,   399,   446,   446,   446,   446,   446,   446,
     446,   445,   446,   446,   446,   447,   447,    63,   449,   449,
     449,   427,   377,   445,   469,    53,    54,    86,   124,   153,
     158,   159,   160,   161,   162,   191,   192,   193,   285,   286,
     291,   304,   322,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,    17,    63,    64,    66,   438,
     469,   477,    22,    63,   445,   449,   453,   480,   455,   455,
     455,   456,   456,   458,   458,   458,   458,   459,   459,   460,
     462,   463,   464,   466,   465,   468,   468,   468,   468,   468,
     468,   445,   285,   446,    17,    38,    41,    64,    74,   281,
     312,   315,   328,   469,   470,   476,   438,   445,   445,   455,
      20,    14,    14,    20,    20,    14,    14,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,   469,   469,    13,    13,
      13,   447,    16,    20,    14,    20,    14,    14,    20,    16,
      14,    14,    16,    14,    16,    20,    20,    20,    14,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    14,    20,    20,    20,    20,    13,    13,    14,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    14,
      14,    14,    20,    14,    20,    20,    20,    20,    20,    14,
      20,    20,    14,    20,    14,    20,    16,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    14,    20,
      14,    14,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    14,    20,    20,    14,    14,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    14,    14,    14,    20,    20,    14,
      20,    20,    14,    20,    20,    20,    20,    20,    14,    14,
      16,    20,    14,    14,    14,    14,    14,    14,    20,    20,
      20,    14,   445,   437,   447,   443,   362,   427,    14,    14,
      14,    20,    14,    13,    13,   391,   427,    14,    20,    20,
      20,    20,    20,    13,    14,    20,    20,    20,    14,    20,
      14,    20,    20,    20,    20,    20,    20,    14,    14,    14,
      20,    20,    20,    20,    20,    22,    23,    14,    13,    13,
      13,   447,    13,    13,    13,    13,    13,    13,    13,    13,
      13,   479,    14,    20,    20,    22,    19,    16,    16,    22,
      20,    13,   469,   477,    15,    13,    19,    13,    13,    13,
      13,    20,    14,    16,   447,   445,   445,   445,   449,   445,
     445,   445,   445,   445,   449,   445,   445,    63,   449,    58,
      63,   445,   445,   445,   445,   445,   445,   445,   446,   445,
      64,   445,    71,   445,   445,    73,   445,   445,   445,   445,
     445,    73,    64,   470,    64,    58,   445,   445,   445,   447,
      60,    62,   447,   110,   447,    71,   469,    13,    13,    13,
      56,   449,   445,   445,   445,   445,   445,   445,   445,   449,
     445,   445,   445,   445,   445,   445,   445,   446,   446,   449,
     449,   449,   445,   445,   445,   445,   445,   445,   445,   445,
     449,   445,   449,   449,   449,   449,   449,   449,   449,   449,
     445,   446,    13,   445,   445,   445,   446,   446,   445,   445,
     445,   445,   445,   445,   445,   445,   445,   445,   445,   445,
     445,   445,   445,   445,   445,   449,   445,   447,   449,   449,
     449,   449,   449,   445,   445,   445,   445,   445,   445,   445,
     445,   445,   445,   445,   445,   445,   445,   445,   445,   445,
     445,   445,   445,   445,   447,   445,   445,   352,    20,   441,
     441,   445,   382,   383,   385,   386,   388,   439,   439,    72,
     445,   445,   449,   445,   445,   449,   445,   445,   445,   445,
     445,   446,   445,   445,   446,   446,   445,   447,   449,   449,
     445,   445,   445,   447,   445,   449,   449,   449,   445,   449,
     445,   449,   445,   445,   445,   445,   445,    17,   469,   477,
      22,   445,    87,   467,   445,   445,   445,   447,   279,    74,
     445,   445,   447,   447,    20,    20,    14,    20,    20,    20,
      20,    20,    14,    20,    14,    20,    14,    14,    14,    20,
      20,    20,    20,    20,    14,    14,    20,    20,    20,    20,
      14,    20,    14,    20,    14,    20,    14,    14,    20,    20,
      20,    20,    14,    19,    14,    20,    14,    20,    20,    20,
      14,    14,    14,    14,    20,   446,    14,    14,    14,   446,
     449,   449,    14,    20,    20,    20,    14,    14,    14,    14,
      20,    14,    14,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    14,    14,    20,    20,    20,    20,
      20,    20,    14,    14,    20,    14,   446,    14,    14,    14,
      20,    20,    20,    20,    14,    20,    20,    20,    14,    20,
      20,    14,    14,    14,    14,    14,    20,    20,    20,    20,
      20,    14,    14,    14,    20,    20,    20,    20,    20,    20,
      14,    14,    14,    14,    14,    14,    14,    14,    20,    20,
      20,    20,    14,    20,    14,    14,    14,    14,    14,    20,
      14,    20,    20,    20,   445,   447,   427,   427,    20,    59,
      59,    59,    59,    59,    14,    20,    14,   441,    14,    20,
      20,    14,    20,    20,    14,    20,    20,    20,    14,    14,
      20,    20,    20,    20,    14,    20,    14,    20,    20,    14,
      20,    23,    20,    14,    14,    20,    14,    20,    14,    14,
      20,    14,    20,    14,    14,    14,    20,    20,    20,    14,
      20,   479,    20,    20,    14,    20,    16,    14,    20,    14,
      14,    20,   447,   445,   449,   449,   445,   445,   445,   445,
     445,   445,   449,   449,   445,   445,   445,   445,   445,   445,
     445,   445,   445,   445,   445,   445,   445,   445,   445,   449,
     445,   446,    56,    14,    14,    14,    20,   448,   449,    56,
     449,   445,   445,   449,   445,   445,   445,   445,   445,   445,
     445,   445,   449,   445,   445,   445,   445,   445,   445,   445,
     445,   445,   445,   445,   445,   445,   449,   449,   449,   449,
     449,   445,    14,   445,   445,   445,   445,   445,   469,   445,
     445,   445,   445,   445,   445,   445,   445,   446,   446,   445,
     449,   449,   445,   445,   445,   445,   445,   445,   449,   446,
     445,   445,   445,   353,   441,   445,   441,   382,   383,   385,
     386,   388,   441,   427,   445,   445,   445,   445,   445,   445,
     445,   446,   445,   445,   446,   445,   449,   445,   445,   445,
     445,   469,   445,   445,   445,   445,   445,   445,   445,   445,
     445,   445,    74,    20,    20,    56,    14,    20,    14,    20,
      14,    20,    14,    20,    14,    20,    14,    14,    14,    14,
      20,    20,    14,    20,    20,    20,    20,    14,    20,    20,
      20,    20,    14,    14,    14,    20,    14,   445,    14,    19,
      14,    20,    20,    20,    20,    14,    14,    20,    14,    20,
      14,    20,    14,    20,    20,    20,    20,    14,    20,    20,
      20,    20,    20,    20,    14,    20,    20,    20,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    20,    20,    20,
      14,    14,    14,    20,    14,    20,    20,    14,    20,    20,
      20,    20,    20,    20,    20,    20,    14,    14,    20,    20,
      20,    20,    20,    14,    20,    20,    20,    14,    14,    14,
      20,    20,   445,   427,    20,   427,    59,    59,    59,    59,
      59,   427,    20,    20,    14,    20,    14,    20,    14,    20,
      20,    14,    20,    20,    20,    20,    14,    20,    23,    14,
      22,    14,    20,    20,    20,    20,    20,    20,    20,    22,
      22,    20,    20,   447,   447,    14,   445,   445,   445,   445,
     445,   445,   445,   445,   445,   445,   445,   445,   445,   445,
     445,   445,    14,   448,    56,   445,   445,   445,   445,   445,
     445,   445,   445,   445,   445,   445,   445,   445,   445,   445,
     445,   480,   445,   480,   480,   445,   445,   445,   445,   445,
     445,   445,   445,   445,   449,   445,   446,   446,   446,   446,
     445,   445,   445,   445,   445,   445,   445,   445,   449,   449,
     445,   445,   445,   445,   445,   445,   445,   441,   445,   445,
     445,   445,   446,   445,   445,   445,   445,   449,   445,   445,
     445,   445,   445,   445,   445,   445,   445,   445,   445,   445,
     445,   445,   445,    14,    20,    14,    14,    20,    20,    14,
      20,    20,    14,    20,    20,    14,    20,    20,    20,    14,
      20,    14,    14,    20,    20,    20,    14,    20,    14,    20,
      20,    20,    20,    20,    14,    20,    20,    20,    20,    20,
      20,    20,    14,    20,    14,    14,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    14,    20,    20,    14,    14,
      20,    14,    20,    20,    14,    14,    20,    20,    14,    20,
      20,    14,    20,    20,    14,    14,    20,    14,    14,    14,
      14,    14,   427,    20,    20,    20,    14,    20,    20,    20,
      20,    20,    20,    20,    14,    14,    20,    20,    14,    14,
      14,    14,    14,    14,    20,    14,    14,   445,   445,   445,
     445,   445,   445,   445,   445,   445,   445,   445,   448,   445,
     445,   445,   445,   445,   445,   445,   445,   445,   445,   445,
     445,   445,   445,   480,   480,   480,   480,   445,   445,   445,
     449,   449,   449,   449,   445,   445,   445,   445,   445,   445,
     445,   445,   445,   446,   449,   445,   445,   445,   445,   446,
     445,   445,   445,   445,   449,   445,   445,   445,   445,    14,
      20,    14,    14,    20,    20,    20,    14,    14,    14,    20,
      14,    14,    20,    14,    14,    14,    14,    14,    20,    14,
      20,    14,    20,    14,    14,    20,    14,    14,    14,    14,
      20,    14,    14,    14,    14,    20,    20,    14,    20,    14,
      14,    20,    20,    20,    20,    20,    14,    20,    14,    20,
      14,    20,    14,    20,    20,    20,    20,    20,    20,    20,
      22,    14,    22,   445,   445,   445,   445,   445,   445,   445,
     445,   445,   445,   480,   445,   445,   445,   445,   445,   445,
     445,   445,   449,   445,   445,   446,   445,   445,   445,   445,
     449,   445,   445,   445,    14,    20,    20,    20,    20,    20,
      14,    14,    14,    20,    14,    20,    20,    14,    20,    20,
      20,    14,    20,    20,    20,    20,    20,    20,    14,    20,
      14,    20,    20,    20,    20,    14,   445,   445,   445,   445,
     445,   445,   445,   445,   445,   445,   445,   445,   445,   449,
     445,   445,   445,   445,   445,   445,   449,   445,   110,    14,
      14,    20,    14,    14,    14,    14,    20,    14,    20,    14,
      20,    20,    20,    14,    20,    20,    20,    14,    14,    20,
      14,    20,    20,    20,    20,   446,   445,   445,   446,   445,
     445,   445,   446,   445,   445,   445,   446,   445,   445,   445,
      20,    20,    14,    14,    20,    14,    14,    14,    20,    14,
      20,    20,    20,    20,   445,   445,   445,   445,   446,   445,
     445,   449,    20,    14,    14,    20,    14,    14,    20,    20,
     445,   445,   445,   449,    20,    20,    20,    20,   445,   445,
     445,   445,    20,    20,    20,    14,   445,   445,   445,    20,
      20,    20,   445,   445,   445,    14,    20,    20,   445,   445,
      14,    14
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  Parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   631,   632,   633,   634,
     635,   636,   637,   638,   639,   640,   641,   642,   643,   644,
     645,   646,   647,   648,   649,   650,   651,   652,   653,   654,
     655,   656,   657,   658,   659,   660,   661,   662,   663,   664,
     665,   666,   667,   668,   669,   670,   671,   672,   673,   674,
     675,   676,   677,   678
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  Parser::yyr1_[] =
  {
         0,   424,   425,   425,   426,   426,   426,   426,   426,   426,
     426,   426,   426,   426,   426,   426,   426,   426,   426,   426,
     427,   427,   428,   428,   428,   428,   428,   429,   429,   431,
     430,   432,   430,   433,   433,   434,   435,   435,   435,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   437,   437,   438,   438,
     438,   438,   438,   438,   438,   439,   439,   439,   439,   439,
     439,   439,   439,   439,   439,   439,   440,   440,   440,   440,
     440,   440,   440,   441,   442,   443,   444,   444,   444,   444,
     444,   444,   444,   444,   444,   444,   444,   444,   444,   444,
     444,   444,   444,   444,   444,   444,   444,   444,   444,   444,
     444,   444,   444,   444,   444,   444,   444,   444,   444,   444,
     444,   444,   444,   444,   444,   444,   444,   444,   444,   444,
     444,   444,   444,   444,   444,   444,   444,   444,   444,   444,
     444,   444,   444,   444,   444,   445,   446,   447,   448,   448,
     448,   448,   448,   448,   448,   448,   448,   448,   448,   448,
     449,   449,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   451,
     452,   452,   453,   453,   453,   453,   453,   453,   453,   453,
     453,   453,   453,   454,   454,   454,   454,   454,   454,   454,
     454,   455,   455,   455,   455,   455,   455,   455,   455,   455,
     455,   455,   455,   455,   455,   455,   455,   455,   455,   455,
     455,   456,   456,   456,   456,   457,   457,   457,   458,   459,
     459,   459,   459,   459,   460,   460,   460,   461,   461,   462,
     463,   463,   464,   464,   465,   465,   466,   466,   467,   467,
     468,   468,   468,   468,   468,   468,   468,   469,   470,   470,
     470,   470,   471,   471,   471,   472,   472,   472,   472,   472,
     472,   472,   472,   472,   472,   472,   472,   472,   472,   472,
     472,   472,   472,   472,   472,   472,   472,   472,   472,   472,
     472,   472,   472,   472,   472,   472,   472,   472,   472,   473,
     474,   475,   475,   475,   475,   475,   475,   476,   476,   476,
     476,   476,   476,   477,   477,   478,   478,   478,   478,   478,
     479,   479,   480,   480,   480,   480,   480
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Parser::yyr2_[] =
  {
         0,     2,     0,     2,     1,     2,     2,     3,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     2,
       1,     1,     8,    10,     6,     2,     3,     4,     6,     0,
       8,     0,     8,     4,     7,     2,     3,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     6,     4,
       4,     3,     5,     3,     6,     3,     6,     3,     6,     8,
       6,     8,     8,     8,     3,     1,     1,     2,     2,     1,
       1,     2,     8,     4,     4,     1,     2,     2,     2,     8,
      16,     2,     6,     2,     2,     2,     1,     1,     2,     2,
       2,     2,     2,     2,     4,     4,     2,     2,     2,     3,
      10,     6,     3,     6,     6,     8,    28,     8,     8,     3,
       8,    12,     6,     6,    16,     8,    16,    10,     6,    10,
       8,    10,    14,     8,    12,     6,     8,     6,     6,     3,
       3,     2,     6,    10,     6,    10,    10,    12,     6,     6,
       3,     3,     3,     3,     4,     3,     6,     6,     4,    20,
      10,     6,     3,     3,     6,     3,     6,     8,     6,     6,
       8,    16,     6,     3,     6,     8,     3,    12,    12,    12,
      10,     3,     3,     8,     8,    10,     8,    10,    12,     6,
       8,    10,    16,    18,    12,     6,    18,    16,    12,    10,
      10,    10,     6,    10,     6,     6,     6,     8,     4,     4,
       8,     4,    18,     4,     1,     1,     1,     6,     3,     4,
       1,     1,     1,    30,    24,     8,     1,     3,     0,     1,
       3,     2,     4,     1,     3,     0,     2,     2,     2,     2,
       2,     4,     4,     4,     4,     4,     1,     6,     1,     3,
       4,     4,     1,     3,     0,     0,     1,     1,     1,     1,
       6,     8,    10,    10,    10,     8,     6,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     6,
       4,    10,     4,    10,     4,     4,     4,     4,     4,     4,
       7,     7,     7,     9,     7,     6,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     6,    10,     4,     4,
       4,     3,     6,     6,     6,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     4,     1,     2,     4,     4,     1,    10,    12,     8,
       6,     6,     6,     8,     8,     6,     8,     8,    10,    10,
      12,    12,    10,     4,    10,     4,     6,     4,     4,     4,
      12,     4,    12,    12,    16,    20,    10,    12,     4,     6,
       6,     6,     4,     4,     6,     4,     6,     6,     6,    16,
      10,     8,    12,    10,     8,    12,     8,    12,     8,    12,
      12,    14,    12,    12,    16,     4,     8,    10,    12,    10,
      12,    10,    12,    12,    14,    12,     8,    14,     4,     4,
       4,     4,     3,     3,     3,     6,     6,     6,     6,     8,
      14,    12,    14,    12,     6,     8,    10,    10,    12,     6,
       6,     6,     6,     6,     6,     6,     6,     8,    10,     4,
       4,    10,    10,     4,     6,     6,    12,    30,     8,     6,
       4,     6,     4,     6,     4,     4,    18,     8,     6,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       6,     4,     3,     1,     4,     2,     2,     2,     2,     4,
       4,     1,     4,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     3,     3,     3,     1,     3,     3,     1,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     1,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     5,
       1,     3,     3,     3,     3,     3,     3,     1,     1,     3,
       8,     4,     6,     1,     4,     6,     6,     8,     8,     4,
       6,     6,     6,     6,     3,     2,     4,     6,     4,     4,
      10,     6,    16,    18,    10,    20,    14,     4,     6,     8,
       8,    12,    16,    16,    18,    14,    14,    16,    20,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,    11,     7,     7,     3,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const Parser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "LEX_ERROR", "T_EXP", "T_GT",
  "T_LT", "T_MULT", "T_DIV", "T_NOT", "T_ADD", "T_SUB", "T_MOD",
  "T_OP_PAR", "T_CL_PAR", "T_OP_BR", "T_CL_BR", "T_AND", "T_OR", "T_POINT",
  "T_COMMA", "T_QUEST", "T_COLON", "T_SEMICOLON", "T_SetDebugOn",
  "T_SetDebugOff", "T_TraceScanning", "T_TraceParsing",
  "T_NoMessageDialog", "T_SetVerboseOn", "T_SetVerboseOff",
  "T_AddMenuScript", "T_SetProgress", "T_SetStatusText", "T_GetScriptsDir",
  "T_argc", "T_emptyargs", "END_INSTRUCTION", "T_Image", "T_BrowseImage",
  "T_ReadRawImages", "T_Transform", "SHOW", "HELP", "QUIT", "T_HIDE",
  "PRINT", "PRINTN", "T_InfoDialog", "T_boost_format", "T_SPRINT",
  "ASHELL", "LS", "T_SetName", "T_GetName", "T_GetObjectName", "ASTRING",
  "ABLOCK", "NUMBER", "IDENTIFIER", "PROCESSED_VAR", "VAR_IMAGE",
  "VAR_STRING", "VAR_IMAGEDRAW", "VAR_SURFDRAW", "VAR_MATRIX", "VAR_FILE",
  "VAR_C_FUNCTION", "VAR_C_PROCEDURE", "VAR_CLASS_MEMBER",
  "VAR_C_IMAGE_FUNCTION", "VAR_AMI_FUNCTION", "VAR_AMI_CLASS",
  "VAR_AMI_OBJECT", "VAR_GLTRANSFORM", "VAR_ARRAY_IMAGE", "T_del",
  "T_delvars", "T_Comments", "ENDOP", "T_global", "T_local",
  "T_global_new", "T_local_new", "T_wait", "T_schedule", "T_SetComponent",
  "T_GetExtent", "RIGHT_ASSIGN", "LEFT_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN",
  "OR_ASSIGN", "RIGHT_OP", "INC_OP", "DEC_OP", "PTR_OP", "AND_OP", "OR_OP",
  "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "TRANSPOSE_OP", "POINTWISE_MULT",
  "ASSIGN_OP", "T_COUNT", "T_MAX", "T_argmax", "T_MIN", "T_MEDIAN",
  "OpImage", "FILTER", "NormGrad", "T_DiscNormGrad", "T_gradient",
  "SecDerGrad", "SecDerGrad2", "SubImage", "PutImage", "T_AutoCrop",
  "T_DiscSecDerGrad", "T_EDPdilate", "T_EDPerode", "T_EDPopen",
  "T_EDPclose", "AnisoSmoothGS", "T_vtkAnisoGS", "T_DiscMeanCurvature",
  "T_vtkMedian3D", "T_NULL", "T_RestartTime", "T_InitTime", "T_TimeSpent",
  "T_EndTime", "T_vtkFastMarching", "T_vtkFastMarchingTarget",
  "T_FluxDiffusion", "T_AnisoWeickert", "T_AnisoCW", "T_SRAD_qcoeff",
  "T_AnisoSRAD", "T_AnisoSRAD2", "T_AnisoLeeAdd2", "T_AnisoDPAD",
  "T_AnisoDPAD2", "T_AnisoNRAD", "T_AnisoRudinMult", "TInit", "TIterate",
  "TEnd", "TAddGaussNoise", "T_SNR", "T_info", "T_save", "T_normalize",
  "T_OrientField", "T_OrientPositive", "T_2DFlux", "T_OutFlux",
  "T_OutFluxScalar", "T_OrientationRatio", "T_Skeleton", "T_SimplePoints",
  "T_CircleIntegral", "T_CircleIntegralExc", "T_CircleIntSdExc",
  "T_CircleMinIntSdExc", "T_LocalExtrema", "T_NormalField",
  "T_DirConnectivity", "T_eccentricity", "T_rot2D", "T_mean", "T_SUM",
  "T_localmean", "T_localmean2", "T_localSD", "T_localSD2",
  "T_struct_tensor", "T_StructTensorH", "T_HessianMatrix", "T_HessianEVal",
  "T_Derivatives", "T_curvatures", "T_Laplacian", "T_setvoxelsize",
  "T_settranslation", "T_setendianness", "T_Skeleton2lines",
  "T_SmoothLines", "T_ResampleLines", "T_threscross", "T_IsocontourPoints",
  "T_IsosurfDist", "T_vtkIsoContourDist", "T_ShortestPath",
  "T_ShortestPathImage", "T_PathFromDispl", "T_PathFromVectField",
  "T_LineRecons", "T_ReadCTALine", "T_ReadCTALineRadii", "T_SetIsoContour",
  "T_SetIsoContourParam", "T_DrawIsoContour", "T_SetIsoContourColor",
  "T_DrawAllContours", "T_AllContoursParam", "T_GetZmin", "T_GetZmax",
  "T_GetYmin", "T_GetYmax", "T_GetXmin", "T_GetXmax", "T_GetXPos",
  "T_GetYPos", "T_GetZPos", "T_vtkDicomRead", "T_vtkMINCRead",
  "T_Convolve", "T_ConvolveMask", "T_Pad", "T_Eigen2D", "T_Eigen3D",
  "T_ChamferDT", "T_Chamfer2DT", "T_BorgeforsDT", "T_BorgeforsSDT",
  "T_vtkSignedBorgefors", "T_vtkSignedFMDist", "T_PropagationDist",
  "T_PropagationDist2", "T_PropDanielsson", "T_vtkPropDanielsson",
  "T_vtkPropDaniel2", "T_CC", "T_ProcessXEvents", "T_ProcessEvents",
  "T_isoarea2D", "T_posarea", "T_isosurf", "T_isosurf_inv",
  "T_isosurf_ijk", "T_isosurf_ras", "T_vtkDecimate", "T_vtkMarchingCubes",
  "T_vtkSmooth", "T_vtkWindowedSinc", "T_isoline", "T_vtkDist",
  "T_AndreDist", "T_Surface", "T_getimage", "T_GetImageFromX", "T_rotate",
  "T_computeCC", "T_drawCC", "T_addobj", "T_setcurrentobj", "T_writeVRML",
  "T_writeVTK", "T_Paint", "T_SetLight", "T_SetLightPos",
  "T_SetLightAmbient", "T_SetLightDiffuse", "T_SetLightSpecular",
  "T_SetBackground", "T_Normalize", "T_Center", "T_Remove",
  "T_SwapBuffers", "T_SetOpacityImage", "T_GetTransform", "T_SetTransform",
  "T_Interpolate", "T_Matrix", "T_Invert", "T_PrintMatrices", "SET",
  "SETPOS", "SHOWCURSOR", "T_update", "COMPARE", "SETVECTOR",
  "T_lininterp", "T_SetCompareDisplacement", "T_DrawVector",
  "T_DisplayVectors", "T_SetVectParam", "T_SetVectColor", "T_SetVectStyle",
  "T_SetLineThickness", "T_SetZoom", "T_SetWindowSize", "T_SetColormap",
  "T_drawcircle", "T_setGLwin", "T_initvalue", "T_ShowSection",
  "T_HideSection", "T_Xpos", "T_Ypos", "T_Zpos", "T_SpacePos", "T_CHAR",
  "T_UCHAR", "T_SHORT", "T_USHORT", "T_INT", "T_UINT", "T_LONG", "T_FLOAT",
  "T_DOUBLE", "T_RGB", "T_FLOAT_VECTOR", "T_GetFormat", "T_atof",
  "T_gnuplot", "T_histo", "T_cumhisto", "T_DisplayHisto", "T_OPEN",
  "T_CLOSE", "T_scan_float", "T_read", "T_rewind", "T_LineNumber",
  "CONST_PI", "SIN", "COS", "TAN", "ASIN", "ACOS", "ATAN", "SINH", "COSH",
  "EXP", "LN", "LOG", "SQRT", "ABS", "ROUND", "FLOOR", "NORM", "FOR", "TO",
  "STEP", "ENDFOR", "T_IN", "T_REPEAT", "T_UNTIL", "T_WHILE", "T_BREAK",
  "IF", "THEN", "ELSE", "VARIABLES", "FUNCTION", "T_eval", "T_tx", "T_ty",
  "T_tz", "T_trx", "T_try", "T_trz", "T_vx", "T_vy", "T_vz", "T_vdim",
  "T_inc", "T_val", "T_exists", "T_FileExists", "T_slice", "T_GenRead",
  "T_IMAGE", "T_IMAGEDRAW", "T_SURFACE", "T_NUM", "T_STRING",
  "T_TRANSFORM", "T_OBJECT", "T_PROC", "T_Class", "T_public",
  "T_MeanHalfSize", "T_Resize", "T_ReSlice", "T_Flip", "T_SetCompTransf",
  "T_ConvexHull", "T_itk", "T_CannyEdgeDetector", "T_CreateFlatMesh",
  "T_CreateVolume", "T_vtkCreateFlatMesh", "T_Altitude2Position",
  "T_GeoCoordinates", "T_CreateVectors", "T_CreateVectorsFromField",
  "T_Set3DArrowParam", "T_CreateEllipsoids", "T_ComputeAltitudes",
  "T_Temp2Altitudes", "T_ReadFlow", "T_SetFluidNavFile",
  "T_DrawEarthCoord", "T_PaintCallback", "T_SaveStructuredGrid",
  "T_import_vtk", "T_import_wii", "T_import_filters", "T_amiOFCorr2D",
  "T_amiOFVar2D", "SHIFT_THERE", "prefix", "postfix", "$accept", "start",
  "list_commands", "end_instr", "loop_inst", "cond_inst", "proc_decl",
  "$@1", "$@2", "class_decl", "object_decl", "func_inst", "command",
  "exprstringlist", "param_list", "param_list_decl", "primary_expr_string",
  "instr_block", "begin_block", "end_block", "float_variable", "expr",
  "expr_image", "expr_string", "basic_type", "var_image", "image",
  "image_variable", "string_variable", "primary_var", "postfix_var",
  "prefix_var", "multiplicative_var", "additive_var", "shift_var",
  "relational_var", "equality_var", "and_var", "exclusive_or_var",
  "inclusive_or_var", "logical_and_var", "logical_xor_var",
  "logical_or_var", "conditional_var", "assignment_var", "expr_var",
  "gltransform", "matrix_variable", "surface", "identifier",
  "variable_with_assign", "function_variable", "variable_without_assign",
  "unprocessed_variable", "processed_variable", "variable", "image_extent", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Parser::rhs_number_type
  Parser::yyrhs_[] =
  {
       425,     0,    -1,    -1,   426,     0,    -1,   427,    -1,   426,
     427,    -1,   436,   427,    -1,   426,   436,   427,    -1,   428,
      -1,   426,   428,    -1,   429,    -1,   426,   429,    -1,   435,
      -1,   426,   435,    -1,   430,    -1,   426,   430,    -1,   433,
      -1,   426,   433,    -1,   434,    -1,   426,   434,    -1,    37,
      -1,    23,    -1,   351,   473,   110,   445,   352,   445,   441,
     427,    -1,   351,   473,   110,   445,   352,   445,   353,   445,
     441,   427,    -1,   351,   473,   355,   437,   441,   427,    -1,
     356,   441,    -1,   358,   479,   441,    -1,   360,   445,   441,
     427,    -1,   360,   445,   441,   362,   441,   427,    -1,    -1,
     389,   473,   431,    13,   439,    14,   441,   427,    -1,    -1,
     389,    71,   432,    13,   439,    14,   441,   427,    -1,   390,
     473,   441,   427,    -1,   390,   473,    22,   391,    72,   441,
     427,    -1,    72,   473,    -1,   364,   447,   427,    -1,   364,
     427,    -1,   365,   447,    -1,   477,    -1,   469,    -1,    36,
      -1,   359,    -1,    80,    -1,    82,    -1,    83,    -1,    81,
      -1,    84,    13,   445,    14,    -1,    85,    13,   445,    20,
      71,    14,    -1,   473,   110,    17,   477,    -1,   473,   110,
      17,   469,    -1,   473,   110,   469,    -1,   473,   110,   469,
      20,   447,    -1,   473,   110,   476,    -1,   473,   110,    38,
      15,   445,    16,    -1,   473,    89,   446,    -1,    75,    15,
     445,    16,   110,   446,    -1,   473,   110,   470,    -1,   473,
     110,   315,    13,   445,    14,    -1,   473,   110,   315,    13,
     445,    14,    20,   447,    -1,   473,   110,   312,    13,   445,
      14,    -1,   473,   110,   312,    13,   445,    14,    20,   447,
      -1,   473,   110,   328,    13,   447,    20,    56,    14,    -1,
      66,   110,   328,    13,   447,    20,    56,    14,    -1,    66,
      19,   332,    -1,    24,    -1,    25,    -1,    26,   445,    -1,
      27,   445,    -1,    29,    -1,    30,    -1,    28,   445,    -1,
      31,    13,   447,    20,   447,    20,   447,    14,    -1,    32,
      13,   445,    14,    -1,    33,    13,   447,    14,    -1,    44,
      -1,    42,   449,    -1,    45,   449,    -1,    42,    73,    -1,
     449,    19,    86,    13,   445,    20,   469,    14,    -1,   449,
      13,   445,    22,   445,    20,   445,    22,   445,    20,   445,
      22,   445,    14,   110,   446,    -1,    42,   363,    -1,    78,
      13,   479,    20,   447,    14,    -1,    76,   479,    -1,    77,
     447,    -1,    51,   447,    -1,    52,    -1,    43,    -1,    43,
     473,    -1,    43,    70,    -1,    43,    67,    -1,    43,    68,
      -1,    43,    69,    -1,    43,    56,    -1,    66,    19,    46,
     469,    -1,    66,    19,    47,   469,    -1,    46,   469,    -1,
      47,   469,    -1,    48,   447,    -1,    66,    19,   329,    -1,
      63,    19,   286,    13,   445,    20,   445,    20,   445,    14,
      -1,    63,    19,   287,    13,   445,    14,    -1,    63,    19,
     288,    -1,    63,    19,   289,    13,   449,    14,    -1,    63,
      19,   289,    13,    63,    14,    -1,    63,    19,   292,    13,
      63,    20,   449,    14,    -1,    63,    19,   396,    13,   445,
      20,   445,    20,   445,    20,   445,    20,   445,    20,   445,
      20,   445,    20,   445,    20,   445,    20,   445,    20,   445,
      20,   445,    14,    -1,    63,    19,   290,    13,    58,    20,
     449,    14,    -1,    63,    19,   293,    13,   445,    20,   445,
      14,    -1,    63,    19,   294,    -1,    63,    19,   295,    13,
     445,    20,   445,    14,    -1,    63,    19,   296,    13,   445,
      20,   445,    20,   445,    20,   445,    14,    -1,    63,    19,
     297,    13,   445,    14,    -1,    63,    19,   298,    13,   445,
      14,    -1,    63,    19,   299,    13,   445,    20,   445,    20,
     445,    20,   445,    20,   445,    20,   445,    14,    -1,    63,
      19,   300,    13,   445,    20,   445,    14,    -1,    63,    19,
     302,    13,   445,    20,   445,    20,   445,    20,   445,    20,
     445,    20,   445,    14,    -1,    63,    19,   301,    13,   446,
      20,   445,    20,   445,    14,    -1,    63,    19,   303,    13,
      64,    14,    -1,    63,    19,   208,    13,   445,    20,   449,
      20,   445,    14,    -1,    63,    19,   208,    13,   449,    20,
     445,    14,    -1,    63,    19,   209,    13,   445,    20,   445,
      20,   445,    14,    -1,    63,    19,   209,    13,   445,    20,
     445,    20,   445,    20,   445,    20,   445,    14,    -1,    63,
      19,   210,    13,   445,    20,   445,    14,    -1,    63,    19,
     211,    13,   445,    20,   445,    20,   445,    20,   445,    14,
      -1,    63,    19,   212,    13,   445,    14,    -1,    63,    19,
     213,    13,   445,    20,   445,    14,    -1,    63,    19,   414,
      13,    71,    14,    -1,    63,    19,   278,    13,   449,    14,
      -1,   449,    19,   153,    -1,   449,    19,   158,    -1,    73,
     158,    -1,   449,    19,   304,    13,   445,    14,    -1,   449,
      19,   304,    13,   445,    20,   445,    20,   445,    14,    -1,
     449,    19,   285,    13,   445,    14,    -1,   449,    19,   285,
      13,   445,    20,   445,    20,   445,    14,    -1,   449,    19,
     286,    13,   445,    20,   445,    20,   445,    14,    -1,   449,
      19,   124,    13,   449,    20,   445,    20,   445,    20,   445,
      14,    -1,   449,    19,   124,    13,   449,    14,    -1,   449,
      19,    53,    13,   447,    14,    -1,   143,    19,   154,    -1,
     143,    19,   155,    -1,   144,    19,   154,    -1,   144,    19,
     155,    -1,   449,    19,   159,   447,    -1,   449,    19,   160,
      -1,   449,    19,   161,    13,   449,    14,    -1,   449,    19,
     162,    13,   449,    14,    -1,   412,    13,   447,    14,    -1,
     413,    13,    63,    20,   445,    20,   445,    20,   445,    20,
     445,    20,   445,    20,   445,    20,   445,    20,   445,    14,
      -1,    64,    19,   260,    13,   445,    20,   445,    20,   445,
      14,    -1,    64,    19,   263,    13,    73,    14,    -1,    64,
      90,    73,    -1,    64,    91,    73,    -1,    64,    19,   276,
      13,    73,    14,    -1,    64,    19,   277,    -1,    64,    19,
     262,    13,   445,    14,    -1,    64,    19,   262,    13,   445,
      20,   445,    14,    -1,    64,    19,   264,    13,   445,    14,
      -1,    64,    19,   289,    13,    64,    14,    -1,    64,    19,
     290,    13,    58,    20,   449,    14,    -1,    64,    19,   305,
      13,   445,    20,   446,    20,   445,    20,   445,    20,   445,
      20,   445,    14,    -1,    64,    19,   306,    13,   445,    14,
      -1,    64,    19,   284,    -1,    64,    19,   280,    13,   470,
      14,    -1,    64,    19,   280,    13,   470,    20,   445,    14,
      -1,    64,    19,   267,    -1,    64,    19,   270,    13,   445,
      20,   445,    20,   445,    20,   445,    14,    -1,    64,    19,
     271,    13,   445,    20,   445,    20,   445,    20,   445,    14,
      -1,    64,    19,   272,    13,   445,    20,   445,    20,   445,
      20,   445,    14,    -1,    64,    19,   273,    13,   445,    20,
     445,    20,   445,    14,    -1,    64,    19,   274,    -1,    64,
      19,   275,    -1,    64,    19,   300,    13,   445,    20,   445,
      14,    -1,   184,    13,   449,    20,   445,    20,   445,    14,
      -1,   184,    13,   449,    20,   445,    20,   445,    20,   446,
      14,    -1,   185,    13,   449,    20,   445,    20,   445,    14,
      -1,   185,    13,   449,    20,   445,    20,   445,    20,   446,
      14,    -1,   185,    13,   449,    20,   445,    20,   445,    20,
     446,    20,   445,    14,    -1,   186,    13,   449,    20,   445,
      14,    -1,   186,    13,   449,    20,   445,    20,   469,    14,
      -1,   186,    13,   449,    20,   445,    20,   445,    20,   446,
      14,    -1,   188,    13,   449,    20,   445,    20,   445,    20,
     445,    20,   445,    20,   445,    20,   445,    14,    -1,   188,
      13,   449,    20,   445,    20,   445,    20,   445,    20,   445,
      20,   445,    20,   445,    20,   446,    14,    -1,   187,    13,
     449,    20,   445,    20,   445,    20,   446,    20,   445,    14,
      -1,   189,    13,   449,    20,   445,    14,    -1,   229,    13,
      56,    20,   449,    20,   449,    20,   449,    20,   449,    20,
     449,    20,   449,    20,   446,    14,    -1,   229,    13,    56,
      20,   449,    20,   449,    20,   449,    20,   449,    20,   449,
      20,   449,    14,    -1,   228,    13,    56,    20,   449,    20,
     449,    20,   449,    20,   446,    14,    -1,   228,    13,    56,
      20,   449,    20,   449,    20,   449,    14,    -1,   191,    13,
     449,    20,   445,    20,   445,    20,   445,    14,    -1,   449,
      19,   191,    13,   445,    20,   445,    20,   445,    14,    -1,
     449,    19,   191,    13,   449,    14,    -1,   449,    19,   192,
      13,   445,    20,   445,    20,   445,    14,    -1,   449,    19,
     192,    13,   449,    14,    -1,   449,    19,   193,    13,   445,
      14,    -1,   126,    13,   449,    20,   449,    14,    -1,   126,
      13,   449,    20,   449,    20,   449,    14,    -1,   242,    13,
     445,    14,    -1,   243,    13,   445,    14,    -1,   324,    13,
     446,    20,   447,    20,   445,    14,    -1,   327,    13,   449,
      14,    -1,   227,    13,   449,    20,   449,    20,   445,    20,
     445,    20,   445,    20,   445,    20,   445,    20,   445,    14,
      -1,   381,    13,    56,    14,    -1,   136,    -1,   137,    -1,
     139,    -1,   415,    13,   449,    20,   447,    14,    -1,    74,
      19,    46,    -1,    74,    19,   159,   447,    -1,   416,    -1,
     417,    -1,   418,    -1,   419,    13,   449,    20,   449,    20,
     449,    20,   449,    20,   449,    20,   449,    20,   449,    20,
     445,    20,   445,    20,   445,    20,   445,    20,   445,    20,
     445,    20,   445,    14,    -1,   420,    13,   449,    20,   449,
      20,   445,    20,   445,    20,   445,    20,   445,    20,   445,
      20,   445,    20,   449,    20,   449,    20,   445,    14,    -1,
     407,    13,   445,    20,   445,    20,   445,    14,    -1,   447,
      -1,   437,    20,   447,    -1,    -1,   477,    -1,   438,    20,
     477,    -1,    17,   479,    -1,   438,    20,    17,   479,    -1,
     469,    -1,   438,    20,   469,    -1,    -1,   385,    59,    -1,
     388,    59,    -1,   386,    59,    -1,   382,    59,    -1,   383,
      59,    -1,   439,    20,   388,    59,    -1,   439,    20,   385,
      59,    -1,   439,    20,   386,    59,    -1,   439,    20,   382,
      59,    -1,   439,    20,   383,    59,    -1,    56,    -1,    50,
      13,   447,    20,   445,    14,    -1,   138,    -1,   449,    19,
      54,    -1,    54,    13,   479,    14,    -1,    55,    13,   479,
      14,    -1,    34,    -1,   442,    57,   443,    -1,    -1,    -1,
      58,    -1,    35,    -1,   333,    -1,   334,    -1,   449,    13,
     445,    20,   445,    14,    -1,   449,    13,   445,    20,   445,
      20,   445,    14,    -1,   449,    19,   291,    13,   445,    20,
     445,    20,   445,    14,    -1,   449,    13,   445,    20,   445,
      20,   445,    20,   445,    14,    -1,   449,    13,   445,    20,
     445,    20,   445,    23,   445,    14,    -1,   449,    13,   445,
      20,   445,    23,   445,    14,    -1,   449,    13,   445,    23,
     445,    14,    -1,   449,    19,   366,    -1,   449,    19,   367,
      -1,   449,    19,   368,    -1,   449,    19,   369,    -1,   449,
      19,   370,    -1,   449,    19,   371,    -1,   449,    19,   372,
      -1,   449,    19,   373,    -1,   449,    19,   374,    -1,   449,
      19,   375,    -1,   449,    19,   376,    -1,   449,    19,   377,
      -1,   157,    13,   449,    20,   449,    14,    -1,   176,    13,
     449,    14,    -1,   244,    13,   449,    20,   445,    20,   445,
      20,   445,    14,    -1,   245,    13,   449,    14,    -1,   245,
      13,   445,    20,   445,    20,   445,    20,   445,    14,    -1,
     111,    13,   446,    14,    -1,   178,    13,   446,    14,    -1,
     112,    13,   446,    14,    -1,   113,    13,   446,    14,    -1,
     114,    13,   446,    14,    -1,   115,    13,   446,    14,    -1,
     112,    15,   446,    16,    13,   446,    14,    -1,   114,    15,
     446,    16,    13,   449,    14,    -1,   115,    15,   446,    16,
      13,   449,    14,    -1,   115,    15,   446,    16,    13,   449,
      20,   445,    14,    -1,   178,    15,   446,    16,    13,   446,
      14,    -1,   178,    13,   449,    20,   446,    14,    -1,   323,
      13,   447,    14,    -1,    63,    19,   218,    -1,    63,    19,
     219,    -1,    63,    19,   216,    -1,    63,    19,   217,    -1,
      63,    19,   214,    -1,    63,    19,   215,    -1,    63,    19,
     220,    -1,    63,    19,   221,    -1,    63,    19,   222,    -1,
     471,    13,   445,    20,   445,    14,    -1,   471,    19,   285,
      13,   445,    20,   445,    20,   445,    14,    -1,   378,    13,
     473,    14,    -1,   378,    13,   479,    14,    -1,   379,    13,
     447,    14,    -1,   448,    19,   377,    -1,    66,    19,   330,
      13,   447,    14,    -1,    66,    19,   331,    13,    60,    14,
      -1,    66,    19,   331,    13,    62,    14,    -1,   469,    -1,
     469,    -1,   469,    -1,   311,    -1,   312,    -1,   313,    -1,
     314,    -1,   315,    -1,   316,    -1,   317,    -1,   318,    -1,
     319,    -1,   320,    -1,   321,    -1,   449,    19,   322,    -1,
      61,    -1,    75,    15,   445,    16,    -1,   449,    -1,    38,
     447,    -1,   223,    13,   447,    14,    -1,   224,    13,   447,
      14,    -1,    39,    -1,    38,    13,   448,    20,   445,    20,
     445,    20,   445,    14,    -1,    38,    13,   448,    20,   445,
      20,   445,    20,   445,    20,   445,    14,    -1,    38,    13,
     448,    20,   445,    20,   449,    14,    -1,   179,    13,   446,
      20,   445,    14,    -1,   180,    13,   446,    20,   445,    14,
      -1,   181,    13,   446,    20,   445,    14,    -1,   182,    13,
     446,    20,   446,    20,   445,    14,    -1,   183,    13,   446,
      20,   446,    20,   445,    14,    -1,   116,    13,   449,    20,
      56,    14,    -1,   116,    13,   449,    20,    56,    20,   448,
      14,    -1,   116,    13,   449,    20,   449,    20,    56,    14,
      -1,   116,    13,   449,    20,   449,    20,    56,    20,   448,
      14,    -1,   116,    13,   449,    20,   449,    20,   449,    20,
      56,    14,    -1,   116,    13,   449,    20,   449,    20,   449,
      20,    56,    20,   448,    14,    -1,   117,    13,   446,    20,
     445,    20,   445,    20,   445,    20,   445,    14,    -1,   398,
      19,   399,    13,   449,    20,   445,    20,   445,    14,    -1,
     255,    13,   449,    14,    -1,   134,    13,   449,    20,   445,
      20,   445,    20,   445,    14,    -1,   256,    13,   449,    14,
      -1,   163,    13,   446,    20,   445,    14,    -1,   164,    13,
     449,    14,    -1,   165,    13,   449,    14,    -1,   166,    13,
     449,    14,    -1,   167,    13,   449,    20,   449,    20,   445,
      20,   445,    20,   445,    14,    -1,   168,    13,   449,    14,
      -1,   169,    13,   449,    20,   449,    20,   449,    20,   445,
      20,   449,    14,    -1,   170,    13,   449,    20,   449,    20,
     449,    20,   445,    20,   449,    14,    -1,   171,    13,   449,
      20,   449,    20,   449,    20,   445,    20,   449,    20,   445,
      20,   445,    14,    -1,   172,    13,   449,    20,   449,    20,
     449,    20,   445,    20,   449,    20,   445,    20,   445,    20,
     445,    20,   445,    14,    -1,   173,    13,   449,    20,   449,
      20,   449,    20,   449,    14,    -1,   173,    13,   449,    20,
     449,    20,   449,    20,   449,    20,   445,    14,    -1,   174,
      13,   449,    14,    -1,   174,    13,   449,    20,   449,    14,
      -1,   175,    13,   449,    20,   449,    14,    -1,   118,    13,
     446,    20,   445,    14,    -1,   119,    13,   449,    14,    -1,
     133,    13,   449,    14,    -1,   120,    13,   449,    20,   445,
      14,    -1,   190,    13,   449,    14,    -1,   121,    13,   449,
      20,   445,    14,    -1,   122,    13,   449,    20,   445,    14,
      -1,   125,    13,   446,    20,   445,    14,    -1,   123,    13,
     449,    20,   445,    20,   445,    20,   445,    20,   445,    20,
     445,    20,   445,    14,    -1,   127,    13,   449,    20,   445,
      20,   445,    20,   445,    14,    -1,   127,    13,   449,    20,
     445,    20,   445,    14,    -1,   127,    13,   449,    20,   445,
      20,   445,    20,   445,    20,   445,    14,    -1,   128,    13,
     449,    20,   445,    20,   445,    20,   445,    14,    -1,   128,
      13,   449,    20,   445,    20,   445,    14,    -1,   128,    13,
     449,    20,   445,    20,   445,    20,   445,    20,   445,    14,
      -1,   129,    13,   449,    20,   445,    20,   445,    14,    -1,
     129,    13,   449,    20,   445,    20,   445,    20,   445,    20,
     445,    14,    -1,   130,    13,   449,    20,   445,    20,   445,
      14,    -1,   130,    13,   449,    20,   445,    20,   445,    20,
     445,    20,   445,    14,    -1,   142,    13,   449,    20,   449,
      20,   445,    20,   445,    20,   445,    14,    -1,   132,    13,
     449,    20,   445,    20,   445,    20,   445,    20,   445,    20,
     445,    14,    -1,   131,    13,   449,    20,   445,    20,   445,
      20,   445,    20,   445,    14,    -1,   143,    19,   153,    13,
     449,    20,   445,    20,   445,    20,   445,    14,    -1,   144,
      19,   153,    13,   449,    20,   445,    20,   445,    20,   445,
      20,   445,    20,   445,    14,    -1,   145,    13,   449,    14,
      -1,   146,    13,   449,    20,   445,    20,   445,    14,    -1,
     146,    13,   449,    20,   445,    20,   445,    20,   480,    14,
      -1,   146,    13,   449,    20,   445,    20,   445,    20,   445,
      20,   480,    14,    -1,   147,    13,   449,    20,   445,    20,
     445,    20,   480,    14,    -1,   147,    13,   449,    20,   445,
      20,   445,    20,   445,    20,   480,    14,    -1,   148,    13,
     449,    20,   445,    20,   445,    20,   480,    14,    -1,   149,
      13,   449,    20,   445,    20,   445,    20,   445,    20,   480,
      14,    -1,   150,    13,   449,    20,   445,    20,   445,    20,
     445,    20,   480,    14,    -1,   151,    13,   449,    20,   445,
      20,   445,    20,   445,    20,   445,    20,   480,    14,    -1,
     152,    13,   449,    20,   445,    20,   445,    20,   445,    20,
     445,    14,    -1,   156,    13,   449,    20,   445,    20,   445,
      14,    -1,   177,    13,   449,    20,   445,    20,   445,    20,
     445,    20,   445,    20,   445,    14,    -1,   307,    13,   449,
      14,    -1,   308,    13,   449,    14,    -1,   309,    13,   449,
      14,    -1,   310,    13,   449,    14,    -1,    64,    19,   258,
      -1,    64,    19,   259,    -1,    63,    19,   258,    -1,   197,
      13,   449,    20,   445,    14,    -1,   198,    13,   449,    20,
     445,    14,    -1,   199,    13,   449,    20,   445,    14,    -1,
     200,    13,   449,    20,   445,    14,    -1,   140,    13,   446,
      20,   446,    20,   445,    14,    -1,   141,    13,   446,    20,
     446,    20,   445,    20,   445,    20,   445,    20,   445,    14,
      -1,   140,    13,   446,    20,   446,    20,   445,    20,   445,
      20,   445,    14,    -1,   140,    13,   446,    20,   446,    20,
     445,    20,   445,    20,   445,    20,   445,    14,    -1,   140,
      13,   446,    20,   446,    20,   449,    20,   445,    20,   445,
      14,    -1,   225,    13,   449,    20,   449,    14,    -1,   226,
      13,   449,    20,   449,    20,   446,    14,    -1,   230,    13,
     449,    20,   445,    20,   445,    20,   445,    14,    -1,   231,
      13,   449,    20,   445,    20,   445,    20,   445,    14,    -1,
     231,    13,   449,    20,   445,    20,   445,    20,   445,    20,
     445,    14,    -1,   232,    13,   449,    20,   445,    14,    -1,
     233,    13,   449,    20,   445,    14,    -1,   234,    13,   449,
      20,   445,    14,    -1,   235,    13,   449,    20,   445,    14,
      -1,   236,    13,   449,    20,   445,    14,    -1,   237,    13,
     449,    20,   445,    14,    -1,   238,    13,   449,    20,   445,
      14,    -1,   239,    13,   449,    20,   445,    14,    -1,   239,
      13,   449,    20,   445,    20,   445,    14,    -1,   240,    13,
     449,    20,   445,    20,   445,    20,   445,    14,    -1,   241,
      13,   446,    14,    -1,   449,    13,   469,    14,    -1,   325,
      13,   446,    20,   445,    20,   445,    20,   445,    14,    -1,
     326,    13,   446,    20,   445,    20,   445,    20,   445,    14,
      -1,   392,    13,   446,    14,    -1,   392,    13,   446,    20,
     445,    14,    -1,   395,    13,   446,    20,   445,    14,    -1,
     393,    13,   446,    20,   445,    20,   445,    20,   445,    20,
     445,    14,    -1,   394,    13,   449,    20,   449,    20,   445,
      20,   445,    20,   445,    20,   445,    20,   445,    20,   445,
      20,   445,    20,   445,    20,   445,    20,   445,    20,   445,
      20,   445,    14,    -1,   397,    13,   446,    20,   445,    20,
     445,    14,    -1,   403,    13,   446,    20,   445,    14,    -1,
     403,    13,   446,    14,    -1,   404,    13,   446,    20,   445,
      14,    -1,   404,    13,   446,    14,    -1,   409,    13,   446,
      20,   446,    14,    -1,   410,    13,   446,    14,    -1,   411,
      13,   447,    14,    -1,   380,    13,   446,    20,   445,    20,
     445,    20,   445,    20,   445,    20,   445,    20,   445,    20,
     445,    14,    -1,   205,    13,    73,    20,   449,    20,   446,
      14,    -1,   207,    13,    73,    20,   447,    14,    -1,   450,
      -1,    62,    -1,   440,    -1,    73,    -1,    60,    -1,   444,
      -1,   451,    -1,   472,    -1,   452,    -1,   471,    -1,   257,
      15,   445,    16,    -1,   112,    13,   469,    20,   469,    14,
      -1,   475,    13,   438,    14,    -1,    13,   469,    14,    -1,
     453,    -1,   454,    13,   438,    14,    -1,     9,   453,    -1,
     454,    99,    -1,   454,   100,    -1,   454,   108,    -1,   454,
      15,   480,    16,    -1,   454,    15,   453,    16,    -1,   454,
      -1,    13,   448,    14,   455,    -1,    11,   455,    -1,    10,
     455,    -1,    99,   454,    -1,   100,   455,    -1,   335,   455,
      -1,   336,   455,    -1,   346,   455,    -1,   347,   455,    -1,
     348,   455,    -1,   349,   455,    -1,   337,   455,    -1,   338,
     455,    -1,   339,   455,    -1,   340,   455,    -1,   343,   455,
      -1,   345,   455,    -1,   344,   455,    -1,   350,   455,    -1,
     455,    -1,   456,     7,   455,    -1,   456,     8,   455,    -1,
     456,    12,   455,    -1,   456,    -1,   457,    10,   456,    -1,
     457,    11,   456,    -1,   457,    -1,   458,    -1,   459,     6,
     458,    -1,   459,     5,   458,    -1,   459,   104,   458,    -1,
     459,   105,   458,    -1,   459,    -1,   460,   106,   459,    -1,
     460,   107,   459,    -1,   460,    -1,   461,    17,   460,    -1,
     461,    -1,   462,    -1,   463,    18,   462,    -1,   463,    -1,
     464,   102,   463,    -1,   464,    -1,   465,     4,   464,    -1,
     465,    -1,   466,   103,   465,    -1,   466,    -1,   466,    21,
     466,    22,   467,    -1,   467,    -1,   467,   110,   468,    -1,
     467,    89,   468,    -1,   467,    90,   468,    -1,   467,    91,
     468,    -1,   467,    92,   468,    -1,   467,    93,   468,    -1,
     468,    -1,    74,    -1,    64,    19,   279,    -1,   281,    13,
      74,    20,    74,    20,   445,    14,    -1,    41,    13,   447,
      14,    -1,   282,    13,   445,    20,   445,    14,    -1,    65,
      -1,   283,    13,   469,    14,    -1,   246,    13,   446,    20,
     445,    14,    -1,   249,    13,   449,    20,   445,    14,    -1,
     246,    13,   446,    20,   445,    20,   449,    14,    -1,   254,
      13,   446,    20,   445,    20,   446,    14,    -1,   250,    13,
      73,    14,    -1,   250,    13,    73,    20,   445,    14,    -1,
     251,    13,   449,    20,   445,    14,    -1,   252,    13,    73,
      20,   445,    14,    -1,   253,    13,    73,    20,   445,    14,
      -1,   257,    13,    14,    -1,   257,   447,    -1,   206,    13,
     447,    14,    -1,   206,    13,   447,    20,   445,    14,    -1,
     194,    13,   449,    14,    -1,   195,    13,    73,    14,    -1,
     195,    13,    73,    20,   445,    20,   445,    20,   445,    14,
      -1,   196,    13,    73,    20,   445,    14,    -1,   201,    13,
      73,    20,   445,    20,   445,    20,   445,    20,   445,    20,
     445,    20,   445,    14,    -1,   202,    13,   446,    20,   445,
      20,   445,    20,   445,    20,   445,    20,   445,    20,   445,
      20,   445,    14,    -1,   203,    13,   446,    20,   445,    20,
     445,    20,   445,    14,    -1,   204,    13,   446,    20,   445,
      20,   445,    20,   445,    20,   445,    20,   445,    20,   445,
      20,   445,    20,   445,    14,    -1,   204,    13,   446,    20,
     445,    20,   445,    20,   445,    20,   445,    20,   445,    14,
      -1,   400,    13,   446,    14,    -1,   400,    13,   446,    20,
     445,    14,    -1,   400,    13,   446,    20,   445,    20,   445,
      14,    -1,   402,    13,   446,    20,   445,    20,   445,    14,
      -1,   401,    13,   446,    20,   445,    20,   445,    20,   446,
      20,   446,    14,    -1,   401,    13,   446,    20,   445,    20,
     445,    20,   446,    20,   446,    20,   446,    20,   445,    14,
      -1,   405,    13,   446,    20,   446,    20,   446,    20,   445,
      20,   445,    20,   445,    20,   445,    14,    -1,   405,    13,
     446,    20,   446,    20,   446,    20,   445,    20,   445,    20,
     445,    20,   445,    20,   445,    14,    -1,   405,    13,   446,
      20,   446,    20,   446,    20,   445,    20,   445,    20,   445,
      14,    -1,   406,    13,   446,    20,   445,    20,   445,    20,
     445,    20,   445,    20,   445,    14,    -1,   408,    13,   446,
      20,   446,    20,   446,    20,   445,    20,   445,    20,   445,
      20,   445,    14,    -1,   408,    13,   446,    20,   446,    20,
     446,    20,   445,    20,   445,    20,   445,    20,   445,    20,
     446,    20,   446,    14,    -1,    59,    -1,    74,    -1,    67,
      -1,    68,    -1,    70,    -1,    69,    -1,    71,    -1,    73,
      19,   473,    -1,   475,    -1,    63,    -1,    64,    -1,    66,
      -1,    72,    -1,    75,    -1,   474,    -1,   476,    -1,    73,
      -1,    60,    -1,    62,    -1,    65,    -1,   449,    -1,   477,
      -1,   478,    -1,   445,    22,   445,    20,   445,    22,   445,
      20,   445,    22,   445,    -1,   445,    22,   445,    20,   445,
      22,   445,    -1,    22,    20,    22,    20,   445,    22,   445,
      -1,   449,    19,    87,    -1,    63,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  Parser::yyprhs_[] =
  {
         0,     0,     3,     4,     7,     9,    12,    15,    19,    21,
      24,    26,    29,    31,    34,    36,    39,    41,    44,    46,
      49,    51,    53,    62,    73,    80,    83,    87,    92,    99,
     100,   109,   110,   119,   124,   132,   135,   139,   142,   145,
     147,   149,   151,   153,   155,   157,   159,   161,   166,   173,
     178,   183,   187,   193,   197,   204,   208,   215,   219,   226,
     235,   242,   251,   260,   269,   273,   275,   277,   280,   283,
     285,   287,   290,   299,   304,   309,   311,   314,   317,   320,
     329,   346,   349,   356,   359,   362,   365,   367,   369,   372,
     375,   378,   381,   384,   387,   392,   397,   400,   403,   406,
     410,   421,   428,   432,   439,   446,   455,   484,   493,   502,
     506,   515,   528,   535,   542,   559,   568,   585,   596,   603,
     614,   623,   634,   649,   658,   671,   678,   687,   694,   701,
     705,   709,   712,   719,   730,   737,   748,   759,   772,   779,
     786,   790,   794,   798,   802,   807,   811,   818,   825,   830,
     851,   862,   869,   873,   877,   884,   888,   895,   904,   911,
     918,   927,   944,   951,   955,   962,   971,   975,   988,  1001,
    1014,  1025,  1029,  1033,  1042,  1051,  1062,  1071,  1082,  1095,
    1102,  1111,  1122,  1139,  1158,  1171,  1178,  1197,  1214,  1227,
    1238,  1249,  1260,  1267,  1278,  1285,  1292,  1299,  1308,  1313,
    1318,  1327,  1332,  1351,  1356,  1358,  1360,  1362,  1369,  1373,
    1378,  1380,  1382,  1384,  1415,  1440,  1449,  1451,  1455,  1456,
    1458,  1462,  1465,  1470,  1472,  1476,  1477,  1480,  1483,  1486,
    1489,  1492,  1497,  1502,  1507,  1512,  1517,  1519,  1526,  1528,
    1532,  1537,  1542,  1544,  1548,  1549,  1550,  1552,  1554,  1556,
    1558,  1565,  1574,  1585,  1596,  1607,  1616,  1623,  1627,  1631,
    1635,  1639,  1643,  1647,  1651,  1655,  1659,  1663,  1667,  1671,
    1678,  1683,  1694,  1699,  1710,  1715,  1720,  1725,  1730,  1735,
    1740,  1748,  1756,  1764,  1774,  1782,  1789,  1794,  1798,  1802,
    1806,  1810,  1814,  1818,  1822,  1826,  1830,  1837,  1848,  1853,
    1858,  1863,  1867,  1874,  1881,  1888,  1890,  1892,  1894,  1896,
    1898,  1900,  1902,  1904,  1906,  1908,  1910,  1912,  1914,  1916,
    1920,  1922,  1927,  1929,  1932,  1937,  1942,  1944,  1955,  1968,
    1977,  1984,  1991,  1998,  2007,  2016,  2023,  2032,  2041,  2052,
    2063,  2076,  2089,  2100,  2105,  2116,  2121,  2128,  2133,  2138,
    2143,  2156,  2161,  2174,  2187,  2204,  2225,  2236,  2249,  2254,
    2261,  2268,  2275,  2280,  2285,  2292,  2297,  2304,  2311,  2318,
    2335,  2346,  2355,  2368,  2379,  2388,  2401,  2410,  2423,  2432,
    2445,  2458,  2473,  2486,  2499,  2516,  2521,  2530,  2541,  2554,
    2565,  2578,  2589,  2602,  2615,  2630,  2643,  2652,  2667,  2672,
    2677,  2682,  2687,  2691,  2695,  2699,  2706,  2713,  2720,  2727,
    2736,  2751,  2764,  2779,  2792,  2799,  2808,  2819,  2830,  2843,
    2850,  2857,  2864,  2871,  2878,  2885,  2892,  2899,  2908,  2919,
    2924,  2929,  2940,  2951,  2956,  2963,  2970,  2983,  3014,  3023,
    3030,  3035,  3042,  3047,  3054,  3059,  3064,  3083,  3092,  3099,
    3101,  3103,  3105,  3107,  3109,  3111,  3113,  3115,  3117,  3119,
    3124,  3131,  3136,  3140,  3142,  3147,  3150,  3153,  3156,  3159,
    3164,  3169,  3171,  3176,  3179,  3182,  3185,  3188,  3191,  3194,
    3197,  3200,  3203,  3206,  3209,  3212,  3215,  3218,  3221,  3224,
    3227,  3230,  3232,  3236,  3240,  3244,  3246,  3250,  3254,  3256,
    3258,  3262,  3266,  3270,  3274,  3276,  3280,  3284,  3286,  3290,
    3292,  3294,  3298,  3300,  3304,  3306,  3310,  3312,  3316,  3318,
    3324,  3326,  3330,  3334,  3338,  3342,  3346,  3350,  3352,  3354,
    3358,  3367,  3372,  3379,  3381,  3386,  3393,  3400,  3409,  3418,
    3423,  3430,  3437,  3444,  3451,  3455,  3458,  3463,  3470,  3475,
    3480,  3491,  3498,  3515,  3534,  3545,  3566,  3581,  3586,  3593,
    3602,  3611,  3624,  3641,  3658,  3677,  3692,  3707,  3724,  3745,
    3747,  3749,  3751,  3753,  3755,  3757,  3759,  3763,  3765,  3767,
    3769,  3771,  3773,  3775,  3777,  3779,  3781,  3783,  3785,  3787,
    3789,  3791,  3793,  3805,  3813,  3821,  3825
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   835,   835,   836,   840,   840,   841,   842,   843,   843,
     844,   844,   845,   845,   846,   846,   847,   847,   848,   848,
     851,   852,   857,   876,   896,   942,   965,  1014,  1029,  1052,
    1051,  1083,  1082,  1126,  1143,  1165,  1186,  1193,  1228,  1238,
    1271,  1304,  1312,  1322,  1336,  1350,  1364,  1374,  1390,  1408,
    1423,  1438,  1469,  1497,  1570,  1581,  1607,  1646,  1741,  1753,
    1772,  1783,  1870,  1904,  1920,  1926,  1930,  1934,  1938,  1948,
    1953,  1957,  1967,  1982,  1992,  2003,  2006,  2056,  2079,  2129,
    2219,  2245,  2249,  2261,  2275,  2285,  2296,  2304,  2316,  2552,
    2562,  2572,  2582,  2591,  2656,  2670,  2704,  2716,  2757,  2776,
    2803,  2820,  2833,  2844,  2890,  2897,  2916,  2951,  2966,  2974,
    2982,  3001,  3025,  3031,  3037,  3051,  3063,  3073,  3083,  3090,
    3107,  3123,  3141,  3162,  3178,  3197,  3211,  3226,  3236,  3248,
    3270,  3294,  3316,  3328,  3342,  3361,  3383,  3412,  3441,  3473,
    3670,  3675,  3682,  3687,  3927,  3955,  3969,  3976,  3982,  3990,
    4091,  4098,  4106,  4114,  4122,  4133,  4143,  4151,  4159,  4170,
    4177,  4191,  4205,  4214,  4219,  4228,  4237,  4250,  4263,  4276,
    4289,  4296,  4306,  4316,  4330,  4338,  4349,  4372,  4398,  4426,
    4437,  4480,  4502,  4531,  4548,  4563,  4569,  4596,  4622,  4642,
    4659,  4665,  4671,  4682,  4688,  4696,  4711,  4720,  4731,  4748,
    4764,  4802,  4816,  4863,  4869,  4874,  4879,  4885,  4892,  4898,
    4905,  4910,  4915,  4920,  4963,  5017,  5039,  5047,  5064,  5068,
    5084,  5102,  5118,  5133,  5149,  5169,  5174,  5183,  5190,  5197,
    5204,  5220,  5227,  5234,  5241,  5248,  5266,  5271,  5352,  5376,
    5381,  5394,  5413,  5444,  5455,  5456,  5461,  5465,  5473,  5481,
    5490,  5507,  5523,  5540,  5559,  5577,  5593,  5609,  5615,  5621,
    5627,  5633,  5639,  5645,  5651,  5657,  5663,  5669,  5675,  5682,
    5691,  5698,  5729,  5737,  5749,  5769,  5789,  5809,  5829,  5849,
    5869,  5893,  5917,  5941,  5949,  5973,  5996,  6004,  6016,  6028,
    6040,  6052,  6064,  6076,  6092,  6111,  6152,  6162,  6174,  6184,
    6194,  6206,  6214,  6230,  6249,  6279,  6297,  6309,  6330,  6335,
    6339,  6343,  6347,  6351,  6355,  6359,  6363,  6367,  6371,  6375,
    6383,  6385,  6404,  6406,  6414,  6434,  6469,  6500,  6507,  6525,
    6616,  6682,  6689,  6696,  6704,  6712,  6728,  6746,  6764,  6781,
    6798,  6816,  6852,  6865,  6876,  6889,  6913,  6924,  6935,  6945,
    6955,  6988,  6999,  7020,  7040,  7081,  7128,  7148,  7169,  7180,
    7194,  7208,  7221,  7232,  7243,  7256,  7274,  7286,  7298,  7350,
    7391,  7402,  7412,  7424,  7435,  7445,  7470,  7493,  7521,  7535,
    7669,  7703,  7736,  7764,  7778,  7792,  7802,  7821,  7840,  7860,
    7881,  7903,  7922,  7941,  7961,  8001,  8023,  8052,  8074,  8111,
    8148,  8185,  8219,  8225,  8235,  8241,  8248,  8255,  8263,  8270,
    8292,  8320,  8344,  8371,  8403,  8412,  8425,  8432,  8440,  8454,
    8466,  8478,  8488,  8499,  8509,  8519,  8530,  8540,  8551,  8578,
    8626,  8760,  8781,  8821,  8832,  8840,  8848,  8869,  8895,  8906,
    8913,  8919,  8925,  8932,  8957,  8975,  8982,  9015,  9034,  9055,
    9083,  9092,  9106,  9108,  9110,  9112,  9114,  9116,  9118,  9120,
    9141,  9203,  9281,  9284,  9286,  9363,  9371,  9379,  9387,  9397,
    9436,  9448,  9450,  9459,  9465,  9470,  9475,  9480,  9485,  9490,
    9495,  9500,  9505,  9510,  9515,  9520,  9525,  9530,  9535,  9540,
    9545,  9554,  9555,  9561,  9567,  9577,  9578,  9585,  9595,  9599,
    9600,  9606,  9612,  9618,  9627,  9628,  9634,  9660,  9661,  9665,
    9669,  9670,  9674,  9675,  9687,  9688,  9700,  9701,  9713,  9714,
    9727,  9728,  9738,  9745,  9751,  9757,  9763,  9772,  9776,  9786,
    9800,  9811,  9829,  9835,  9844,  9989, 10004, 10016, 10038, 10074,
   10083, 10093, 10102, 10112, 10126, 10133, 10142, 10158, 10177, 10197,
   10227, 10256, 10273, 10299, 10333, 10365, 10412, 10453, 10462, 10484,
   10495, 10506, 10542, 10584, 10630, 10680, 10722, 10753, 10785, 10827,
   10835, 10838, 10839, 10840, 10841, 10842, 10843, 10876, 10877, 10878,
   10879, 10880, 10881, 10886, 10887, 10893, 10895, 10897, 10900, 10902,
   10906, 10908, 10911, 10920, 10928, 10946, 10963
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 11008;
  const int Parser::yynnts_ = 57;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 557;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 424;

  const unsigned int Parser::yyuser_token_number_max_ = 678;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // yyip

/* Line 1054 of lalr1.cc  */
#line 15804 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"


/* Line 1056 of lalr1.cc  */
#line 10985 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"

#include <stdio.h>



int is_space(char c)
{
  return ((c==' ')||(c=='\n')||(c=='\t'));
}




void yyip::Parser::error(const Parser::location_type& l,
          const std::string& m)
{
    driver.error(l, m);
}


//------------------------------------------------------
void CB_update_imagelist( void* imagelist_gui)
//   -------------------
{
  wxEnumerationParameter* imlist = (wxEnumerationParameter*) imagelist_gui;
  boost::shared_ptr<wxArrayString> imagelist;

  imagelist = Vars.SearchVariables(type_image);
  imagelist->Add(_T("BrowseImage"));
  imlist->SetChoices(imagelist);
}


//------------------------------------------------------
void wxScheduleTimer::Notify()
//   -----------------------
{
  //cout << "Notify()" << endl;
  CB_ParamWin( var->Pointer().get() );

  std::list<wxScheduleTimer::ptr>::iterator Iter;
  for (Iter  = schedule_timers.begin();
       Iter != schedule_timers.end()  ; Iter++ )
  {
    if ((*Iter).use_count()) {
      if (Iter->get() == this) {
        Iter = schedule_timers.erase(Iter);
     }
    }
  }
} // wxScheduleTimer::Notify()

InrImage* ReadImage( const char* name)
{
  // look for the image 
  wxFileName inputname(wxString(name, wxConvUTF8));
  wxFileName newname(wxString(name,wxConvUTF8));
  InrImage* res = NULL;

  if (!inputname.IsFileReadable()) 
  // add the current script path
  {
    newname.Assign(
            wxFileName(wxString(GB_driver.GetCurrentFilename().c_str(),wxConvUTF8)).GetPath() +
            inputname.GetPathSeparator()+
            inputname.GetPath(),
            inputname.GetFullName());
  }

  if (newname.IsFileReadable()) {
    try {
      res=new InrImage(newname.GetFullPath().mb_str());
    }
    catch (InrImage::ErreurLecture)
    {
      FILE_ERROR(boost::format("Unable to read image %s") % name);
      //AddImagePointer(NULL);
      return NULL;
    }
  } else {
    FILE_ERROR(boost::format("Invalid image filename '%s'") % name);
    //AddImagePointer(NULL);
  }
  return res;
}




