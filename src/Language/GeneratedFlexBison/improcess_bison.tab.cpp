
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
#include "wrap_DessinImage.h"

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
extern void CB_delete_varlist( void* var);

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
#line 377 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"


#include "improcess_bison.tab.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 823 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"


#include "driver.h"
#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex



/* Line 317 of lalr1.cc  */
#line 400 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"

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
#line 469 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
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
#line 816 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 576 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 59: /* "IDENTIFIER" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 585 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 407: /* "exprstringlist" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->string_list); };

/* Line 480 of lalr1.cc  */
#line 594 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 410: /* "primary_expr_string" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 603 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 411: /* "instr_block" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ablock); };

/* Line 480 of lalr1.cc  */
#line 612 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 417: /* "expr_string" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 621 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 443: /* "identifier" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 630 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
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
#line 365 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}

/* Line 553 of lalr1.cc  */
#line 716 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"

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
#line 862 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 881 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 901 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 946 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 969 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1018 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1033 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1055 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GB_driver.procedure_declaration = true;
    }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 1060 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1086 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      // allow overriding current functions
      GB_driver.procedure_declaration = true;
    }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 1092 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      AmiInstructionBlock::ptr body((yysemantic_stack_[(8) - (7)].ablock));

      GET_VARSTACK_VAR_VAL(AMIFunction, var, func);

      // Why delete and recreate previous variable ???
      // delete previous variable
//      std::string varname = var->Name();
//      int context = Vars.GetContext(boost::static_pointer_cast<BasicVariable>(var));
//      Vars.deleteVar(var);

      FILE_MESSAGE(boost::format("Redefining procedure %1%") % var->Name()); 

//      AMIFunction::ptr amifunc( new AMIFunction);
      AMIFunction::ptr amifunc(func);

//      amifunc->SetName(varname.c_str());
      amifunc->SetFileName(driver.current_file);
      amifunc->SetParamList((yysemantic_stack_[(8) - (5)].paramlistdecl));
      amifunc->SetBody(     body);
      FILE_MESSAGE(boost::format("%1%: body = %2%")
                    % var->Name()  % body->GetBody());

      // add the variable in the same context ...
//      BasicVariable::ptr newvar =
//        Vars.AddVar<AMIFunction>(
//                      varname,
//                     amifunc,
//                      context);
//      if (newvar.get())
//        amifunc->SetContext(newvar->GetContext());

      // desactivate the flag procedure_declaration
      // which allows not to accept variables as identifiers
      GB_driver.procedure_declaration = false;
    }
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 1133 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1150 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1171 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1192 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
       //driver.res_print($2);
       driver.parse_script((yysemantic_stack_[(3) - (2)].astring));
       delete [] (yysemantic_stack_[(3) - (2)].astring);
     }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 1199 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1234 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> input((yysemantic_stack_[(2) - (2)].astring));
      string inputstring( input.get());
      driver.parse_string( inputstring,
                          "'eval string' command");
    }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 1244 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          /**
            Description:
              Empty instruction.
          **/
          BasicVariable::ptr       var(driver.var_stack.GetLastBasicVar());
          if (var.get()) {
            // TODO: only do it from the command line ???
            //cout << "display var info" << endl;
            if (driver.InConsole())
              var->display();
          }

        }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 1260 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1292 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1300 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1311 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1325 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1339 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1353 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1363 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1379 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1397 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1412 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
        if (var.get() && (var->HasPointer())  ) {
          if ((var->GetPtrCounter()==1)&&(var.use_count()==1)) {
            IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (1)].ident));
            Vars.AddVar(ident,var);
          } else {
            BasicVariable::ptr newvar( var->NewReference());
            Vars.AddVar(ident,newvar);
          }
        } else {
          driver.err_print("identifier = &expr_var, no variable value");
          YYABORT;
        }
      }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 1437 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
        if (var.get() && (var->HasPointer())  ) {
          //cout << "GetPtrCounter == " <<  var->GetPtrCounter()<< endl;
          //cout << "use_count() == " <<  var.use_count() << endl;
          // only if both reference counters are equal to 1, we can avoid copy the variable
          if ((var->GetPtrCounter()==1)&&(var.use_count()==1)) {
            IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
            //BasicVariable::ptr ref = var->NewReference();
            // need to run on reference to avoid renaming the own variable !!!
            //Vars.AddVar(ident,ref);
            Vars.AddVar(ident,var);
          } else
          {
            BasicVariable::ptr copy = var->NewCopy();
            if (copy.get()) {
              IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
              Vars.AddVar(ident,copy);
            } else {
              driver.err_print("Copy failed for the variable in rule id = expr_var");
              YYABORT;
            }
          }
        } else {
          driver.err_print("identifier = expr_var, no variable value");
          YYABORT;
        }
      }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 1475 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1503 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1576 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1587 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1613 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1652 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1747 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1759 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1778 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1789 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1876 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1910 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1926 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<FILE>::ptr varfile(driver.var_stack.GetLastVar<FILE>());
          FILE_ptr file(varfile->Pointer());
          rewind(file.get());
        }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1932 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GB_debug = 1;
        }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1936 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GB_debug = 0;
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1940 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      driver.SetTraceScanning((yysemantic_stack_[(2) - (2)].adouble)>0.5);
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1944 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1954 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 1;
      verbose = 1;
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1959 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 0;
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1963 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1973 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1988 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1998 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2008 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GB_main_wxFrame->Close(true);
    }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 2012 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      std::string titre;
      GET_VARSTACK_VAR_VAL(InrImage, imagevar, im);
      BasicVariable::ptr var;
      int var_context = Vars.GetContext(imagevar);
      Variables::ptr context = imagevar->GetContext();

/*
          Variables::ptr previous_ocontext = Vars.GetObjectContext();
          if (var_context==OBJECT_CONTEXT_NUMBER) {
            // set new object context
            Vars.SetObjectContext(imagevar->GetContext());
          }
*/
      
      titre = (boost::format("%s_draw") % imagevar->Name().c_str()).str();
      FILE_MESSAGE(boost::format("SHOW var_image  title %s") % titre);
      //if (Vars.GetCurrentContext()->GetVar(titre,&var)) {
      var = context->GetVar(titre.c_str());
      if (var.get()) {
        GET_WRAPPED_OBJECT(DessinImage, var, di)
        if (di.get()) {
          DessinImageParametres* param;
          param = di->GetParam();
          param->_MAJ.MAJCoupes();
          di->Paint();
          di->Raise();
        } else {
          driver.err_print(
            (boost::format
              ("Unable to convert variable %1% to a wrapped DessinImage") % titre).str().c_str());
          YYABORT;
        }
      }
      else
      {
        // Call constructor from DessinImage constructor function
        ParamList* p = new ParamList();
        p->AddParam(imagevar);
        BasicVariable::ptr newvar = wrap_DessinImage().CallMember(p);
        FILE_MESSAGE(boost::format("SHOW var_image creating title %s ") % titre);
        if (newvar.get()) {
          newvar->Rename(titre.c_str());
          context->AddVar(newvar, context);
        } else {
          driver.err_print("Failed to create image viewer.");
          YYABORT;
        }
      }

/*
          if (var_context==OBJECT_CONTEXT_NUMBER) {
            // Restore the object context
            Vars.SetObjectContext(previous_ocontext);
          }
*/

        }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 2071 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im)
          string title;
          BasicVariable::ptr var;
          Variables::ptr context = varim->GetContext();

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
#line 2095 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2145 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2235 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2261 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Vars.display();
        }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 2265 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2277 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2291 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2301 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2312 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2320 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2332 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2568 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2578 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2588 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2598 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2607 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2672 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2686 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2720 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2732 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2773 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2792 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          driver.var_stack.GetLastBasicVar();
          printf("Deprecated: No need to close files explicitly, since we use smart pointers, they will be closed when the variable is deleted. \n");
        }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 3265 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 101:

/* Line 678 of lalr1.cc  */
#line 3287 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 102:

/* Line 678 of lalr1.cc  */
#line 3311 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 103:

/* Line 678 of lalr1.cc  */
#line 3333 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 104:

/* Line 678 of lalr1.cc  */
#line 3345 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 105:

/* Line 678 of lalr1.cc  */
#line 3359 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 106:

/* Line 678 of lalr1.cc  */
#line 3378 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 107:

/* Line 678 of lalr1.cc  */
#line 3400 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 108:

/* Line 678 of lalr1.cc  */
#line 3431 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 109:

/* Line 678 of lalr1.cc  */
#line 3458 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 110:

/* Line 678 of lalr1.cc  */
#line 3490 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> name((yysemantic_stack_[(6) - (5)].astring));
      GET_VARSTACK_VALUE(InrImage, im);
      im->FixeNom( name.get());
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 3687 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 3692 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {

      Func_EndWeickert();

    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 3699 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 3704 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Func_EndWeickert();
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 3944 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 116:

/* Line 678 of lalr1.cc  */
#line 3972 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 117:

/* Line 678 of lalr1.cc  */
#line 3986 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im2);
      GET_VARSTACK_VALUE(InrImage, im1);
      Func_OrientField( im1.get() , im2.get() );
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 3993 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im2);
      GET_VARSTACK_VALUE(InrImage, im1);
      Func_OrientPositive( im1.get(), im2.get());
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 3999 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      if (strlen((yysemantic_stack_[(4) - (3)].astring))<255) {
        strcpy(AMIFluid::FLUID_NAVIGATION_FILE,(yysemantic_stack_[(4) - (3)].astring));
      } else
        fprintf(stderr,"SetFluidNavFile() \t File too long \n");
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 4008 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 121:

/* Line 678 of lalr1.cc  */
#line 4108 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,sdraw);

          sdraw->GetCanvas()->UserRotate((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 4115 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_OBJECT(SurfacePoly,surf)
          GET_VARSTACK_VALUE(Viewer3D,sdraw);

          sdraw->GetCanvas()->AddSurface(surf);
          sdraw->Paint();
        }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 4123 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_OBJECT(SurfacePoly,surf)
          GET_VARSTACK_VALUE(Viewer3D,   sdraw);

          sdraw->GetCanvas()->AddSurface( surf);
          //sdraw->Paint();
        }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 4131 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_OBJECT(SurfacePoly,surf)
          GET_VARSTACK_VALUE(Viewer3D,   sdraw);

          sdraw->GetCanvas()->RemoveSurface(surf);
          sdraw->Paint();
        }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 4139 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 126:

/* Line 678 of lalr1.cc  */
#line 4150 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          /**
            Description:  Swaps the 3D buffer
          **/
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw(varsurfd->Pointer());

          sdraw->GetCanvas()->AfficheBuffer();
        }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 4160 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC ( (int) (yysemantic_stack_[(6) - (5)].adouble) );
          sdraw->Paint();
        }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 4168 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
          sdraw->Paint();
        }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 4176 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 130:

/* Line 678 of lalr1.cc  */
#line 4187 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,sdraw2);
          GET_VARSTACK_VALUE(Viewer3D,sdraw1);

          sdraw1->AddCompSurf(sdraw2);
        }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 4194 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 132:

/* Line 678 of lalr1.cc  */
#line 4208 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 133:

/* Line 678 of lalr1.cc  */
#line 4222 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr draw (varsurfd->Pointer());
          int num = (int) (yysemantic_stack_[(6) - (5)].adouble);
    
          draw->GetCanvas()->HideFreeSection(num);
    
        }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 4231 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,v);
          v->GetCanvas()->PrintMatrices();
        }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 4236 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->GetCanvas()->SetObjectTransform(*tr);
              sdraw->Paint();
          delete tr;
        }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 4245 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->GetCanvas()->SetObjectTransform(*tr);
          if ((yysemantic_stack_[(8) - (7)].adouble)>0.5) sdraw->Paint();
          delete tr;
        }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 4254 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 138:

/* Line 678 of lalr1.cc  */
#line 4267 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 139:

/* Line 678 of lalr1.cc  */
#line 4280 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 140:

/* Line 678 of lalr1.cc  */
#line 4293 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 141:

/* Line 678 of lalr1.cc  */
#line 4306 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->GetCanvas()->SetBG((int)(yysemantic_stack_[(10) - (5)].adouble),(int)(yysemantic_stack_[(10) - (7)].adouble),(int)(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 4313 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 143:

/* Line 678 of lalr1.cc  */
#line 4323 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 144:

/* Line 678 of lalr1.cc  */
#line 4333 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 145:

/* Line 678 of lalr1.cc  */
#line 4347 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          Func_StructureTensor(im.get(),
                   varim->Name().c_str(),
                   (yysemantic_stack_[(8) - (5)].adouble), (yysemantic_stack_[(8) - (7)].adouble), NULL);
        }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 4355 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage,mask);
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);

          Func_StructureTensor(
            im.get(),
            varim->Name().c_str(),
            (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), mask.get());
        }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 4366 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 148:

/* Line 678 of lalr1.cc  */
#line 4389 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 149:

/* Line 678 of lalr1.cc  */
#line 4415 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 150:

/* Line 678 of lalr1.cc  */
#line 4443 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 151:

/* Line 678 of lalr1.cc  */
#line 4454 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 152:

/* Line 678 of lalr1.cc  */
#line 4497 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 153:

/* Line 678 of lalr1.cc  */
#line 4519 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 154:

/* Line 678 of lalr1.cc  */
#line 4548 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 155:

/* Line 678 of lalr1.cc  */
#line 4566 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 156:

/* Line 678 of lalr1.cc  */
#line 4580 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          Func_Curvatures(im.get(), varim->Name().c_str(), (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 4591 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 158:

/* Line 678 of lalr1.cc  */
#line 4617 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 159:

/* Line 678 of lalr1.cc  */
#line 4643 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 160:

/* Line 678 of lalr1.cc  */
#line 4662 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 161:

/* Line 678 of lalr1.cc  */
#line 4676 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      im->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 4682 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      im->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 4688 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 164:

/* Line 678 of lalr1.cc  */
#line 4699 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      im->SetTranslation((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 4705 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2( driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1( driver.var_stack.GetLastVar<InrImage>());
      InrImage::ptr im (varim2->Pointer());
      varim1->Pointer()->SetVoxelSize( im->TrX(), im->TrY(), im->TrZ());
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 4713 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 167:

/* Line 678 of lalr1.cc  */
#line 4728 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
      Func_DiscSecDerGrad(
        varim1->Pointer().get(),
        varim2->Pointer().get());
    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 4737 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 169:

/* Line 678 of lalr1.cc  */
#line 4748 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 170:

/* Line 678 of lalr1.cc  */
#line 4765 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 171:

/* Line 678 of lalr1.cc  */
#line 4781 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 172:

/* Line 678 of lalr1.cc  */
#line 4819 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 173:

/* Line 678 of lalr1.cc  */
#line 4837 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 174:

/* Line 678 of lalr1.cc  */
#line 4880 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));
      Func_GenRead(filename.get());
    }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 4886 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.InitCumul();
    }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 4891 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Debut();
    }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 4896 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Fin();
      cout << "time spent = " << driver.IP_time << endl;
    }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 4902 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          boost::shared_array<char> filename( (yysemantic_stack_[(6) - (5)].astring));
          GET_VARSTACK_VALUE(InrImage, i);
          Func_VectorImage2StructuredGrid(i.get(),filename.get());
        }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 4909 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(GLTransfMatrix, glmat);
          glmat->Print();
        }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 4915 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          boost::shared_array<char> filename( (yysemantic_stack_[(4) - (4)].astring));
          GET_VARSTACK_VALUE(GLTransfMatrix, glmat);
          Func_SaveTransform(glmat.get(),filename.get());
        }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 4922 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          AddWrapVTK();
        }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 4927 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          AddWrapWII();
        }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 4932 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          AddWrapFilters();
        }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 4943 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 185:

/* Line 678 of lalr1.cc  */
#line 4983 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 186:

/* Line 678 of lalr1.cc  */
#line 5034 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 187:

/* Line 678 of lalr1.cc  */
#line 5056 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = new std::list<std::string>();
            sl->push_back(string((yysemantic_stack_[(1) - (1)].astring)));
            delete [] (yysemantic_stack_[(1) - (1)].astring);
            (yyval.string_list) = sl;
        }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 5064 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = (yysemantic_stack_[(3) - (1)].string_list);
            sl->push_back(string((yysemantic_stack_[(3) - (3)].astring)));
            delete [] (yysemantic_stack_[(3) - (3)].astring);
            (yyval.string_list) = sl;
        }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 5080 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          (yyval.paramlist) = pl;
        }
    break;

  case 190:

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
          ParamList* pl = new ParamList();
          // Creating a new variable that points to the same value, and a slightly different name (with added "_ref"), comments are also copied.
          BasicVariable::ptr newvar(var->NewReference());
          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 5101 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 192:

/* Line 678 of lalr1.cc  */
#line 5119 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 193:

/* Line 678 of lalr1.cc  */
#line 5134 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 194:

/* Line 678 of lalr1.cc  */
#line 5149 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
          if (newvar.get()) {
            newvar->Rename("Param0");
            pl->AddParam(newvar);
            (yyval.paramlist) = pl;
          } else {
            driver.error(boost::format("Could not copy parameter 0 variable expression !").str().c_str());
            YYABORT;
          }
        }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 5170 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
          if (newvar.get()) {
            newvar->Rename(paramname.c_str());
            pl->AddParam(newvar);
            (yyval.paramlist) = pl;
          } else {
            driver.error((boost::format("Could not copy parameter %1% variable expression !") % pl->GetNumParam()).str().c_str());
            YYABORT;
          }
        }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 5194 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      //      printf("no parameters \n");
      ParamListDecl* pl = new ParamListDecl;
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 5200 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      cout << "param_list_decl: T_NUM IDENTIFIER" << endl;
      cout << ident->GetName().c_str() << endl;
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_float);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 5209 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_ami_object);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 5216 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_string);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 5223 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_image);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 5230 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 5246 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_ami_object);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 5253 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_float);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 5260 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_string);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 5267 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_image);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 5274 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 5292 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
    }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 5297 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 209:

/* Line 678 of lalr1.cc  */
#line 5378 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 210:

/* Line 678 of lalr1.cc  */
#line 5401 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      (yyval.astring)=(char*) (im)->GetName();
    }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 5407 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 212:

/* Line 678 of lalr1.cc  */
#line 5419 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 213:

/* Line 678 of lalr1.cc  */
#line 5439 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      char* res = new char[GB_scripts_dir.Len()+1];
      strcpy(res,(const char*)GB_scripts_dir.mb_str(wxConvUTF8));
      (yyval.astring)= res;
    }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 5472 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        (yyval.ablock)=(yysemantic_stack_[(3) - (2)].ablock);
        if (GB_debug)
          cerr << format("ablock : %s")
                  % (yysemantic_stack_[(3) - (2)].ablock)->GetBody()
                << endl;
          }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 5487 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      ADD_VARSTACK_FLOAT((yysemantic_stack_[(1) - (1)].adouble))
    }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 5491 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      returns the number of arguments in the command line
    **/
      ADD_VARSTACK_FLOAT(GB_argc-GB_num_arg_parsed)
    }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 5499 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      Line number in the current script
    **/
      ADD_VARSTACK_FLOAT(driver.yyiplineno)
    }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 5507 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        the constant Pi is set to
         3.14159265358979323846
      **/
      ADD_VARSTACK_FLOAT(3.14159265358979323846)
    }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 5516 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 222:

/* Line 678 of lalr1.cc  */
#line 5533 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 223:

/* Line 678 of lalr1.cc  */
#line 5549 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 224:

/* Line 678 of lalr1.cc  */
#line 5566 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 225:

/* Line 678 of lalr1.cc  */
#line 5585 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 226:

/* Line 678 of lalr1.cc  */
#line 5603 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 227:

/* Line 678 of lalr1.cc  */
#line 5619 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 228:

/* Line 678 of lalr1.cc  */
#line 5635 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->DimX();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 5641 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->DimY();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 5647 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->DimZ();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 5653 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->TrX();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 5659 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->TrY();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 5665 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->TrZ();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 5671 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->VoxSizeX();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 5677 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->VoxSizeY();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 5683 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->VoxSizeZ();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 5689 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->GetVDim();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 5695 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->IncBuffer();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 5701 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->ValeurBuffer();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 5708 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
      float val=Func_SNR(varim1->Pointer().get(),
                  varim2->Pointer().get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 5717 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      float val=Func_eccentricity(im.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 5724 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 243:

/* Line 678 of lalr1.cc  */
#line 5755 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(InrImage, im);
      float val=Func_ComputePositiveArea( im.get() );
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 5763 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 245:

/* Line 678 of lalr1.cc  */
#line 5775 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 246:

/* Line 678 of lalr1.cc  */
#line 5795 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 247:

/* Line 678 of lalr1.cc  */
#line 5815 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 248:

/* Line 678 of lalr1.cc  */
#line 5835 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 249:

/* Line 678 of lalr1.cc  */
#line 5855 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 250:

/* Line 678 of lalr1.cc  */
#line 5875 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 251:

/* Line 678 of lalr1.cc  */
#line 5895 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 252:

/* Line 678 of lalr1.cc  */
#line 5919 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 253:

/* Line 678 of lalr1.cc  */
#line 5943 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 254:

/* Line 678 of lalr1.cc  */
#line 5967 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      GET_VARSTACK_VALUE(InrImage, mask);
      float val=Func_med( im.get(),(float) (yysemantic_stack_[(9) - (8)].adouble),mask.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 5975 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 256:

/* Line 678 of lalr1.cc  */
#line 5999 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 257:

/* Line 678 of lalr1.cc  */
#line 6022 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      setlocale(LC_NUMERIC, "C");
      float val=atof((yysemantic_stack_[(4) - (3)].astring));
      ADD_VARSTACK_FLOAT(val);
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 6179 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 259:

/* Line 678 of lalr1.cc  */
#line 6189 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 260:

/* Line 678 of lalr1.cc  */
#line 6201 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 261:

/* Line 678 of lalr1.cc  */
#line 6211 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 262:

/* Line 678 of lalr1.cc  */
#line 6221 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 263:

/* Line 678 of lalr1.cc  */
#line 6233 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
        Description: returns the value of the pixel format type in float format
      **/
      float val = (int) (yysemantic_stack_[(3) - (1)].aint);
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 6241 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 265:

/* Line 678 of lalr1.cc  */
#line 6257 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 266:

/* Line 678 of lalr1.cc  */
#line 6276 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 267:

/* Line 678 of lalr1.cc  */
#line 6306 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 268:

/* Line 678 of lalr1.cc  */
#line 6324 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 269:

/* Line 678 of lalr1.cc  */
#line 6336 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 270:

/* Line 678 of lalr1.cc  */
#line 6357 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      driver.err_print(" char format is not available: use unsigned char \n");
      (yyval.aint)=WT_UNSIGNED_CHAR;
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 6362 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          (yyval.aint)=WT_UNSIGNED_CHAR;
       }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 6366 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_SHORT;
       }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 6370 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_SHORT;
       }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 6374 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_INT;
       }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 6378 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_INT;
       }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 6382 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_LONG;
       }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 6386 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT;
       }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 6390 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_DOUBLE;
       }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 6394 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_RGB;
       }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 6398 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT_VECTOR;
       }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 6402 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
         //        printf("format %d \n",(int) ( *(InrImage::ptr*) $1->Pointer())->GetFormat());
        GET_VARSTACK_VALUE(InrImage, im);
        (yyval.aint) = (int) im->GetFormat();
      }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 6412 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 285:

/* Line 678 of lalr1.cc  */
#line 6433 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        boost::shared_array<char> st( (yysemantic_stack_[(2) - (2)].astring));
        InrImage* res = ReadImage(st.get());
        if (!res) YYABORT;
        else
          ADD_VARSTACK(InrImage,res);
      }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 6441 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 287:

/* Line 678 of lalr1.cc  */
#line 6461 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 288:

/* Line 678 of lalr1.cc  */
#line 6496 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 289:

/* Line 678 of lalr1.cc  */
#line 6527 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        //printf(" ********** %d %f %f %f\n", $3, $5, $7, $9);
        InrImage::ptr im (new InrImage( (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble), (WORDTYPE) (yysemantic_stack_[(10) - (3)].aint)));
        ADD_VARSTACK_PTR(InrImage,im);
      }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 6534 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 291:

/* Line 678 of lalr1.cc  */
#line 6552 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 292:

/* Line 678 of lalr1.cc  */
#line 6643 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 293:

/* Line 678 of lalr1.cc  */
#line 6709 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      InrImage* res =Func_localmean( im.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      ADD_VARSTACK(InrImage,res);
    }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 6716 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      InrImage* res =Func_localmean2( im.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      ADD_VARSTACK(InrImage,res);
    }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 6723 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, mean);
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage* res     = Func_localSD( im.get(), mean.get(), (int) (yysemantic_stack_[(8) - (7)].adouble));
      ADD_VARSTACK(InrImage,res);
    }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 6731 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, mean);
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res(Func_localSD2( im.get(), mean.get(), (int) (yysemantic_stack_[(8) - (7)].adouble)));
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 6739 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 298:

/* Line 678 of lalr1.cc  */
#line 6755 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 299:

/* Line 678 of lalr1.cc  */
#line 6773 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 300:

/* Line 678 of lalr1.cc  */
#line 6791 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 301:

/* Line 678 of lalr1.cc  */
#line 6808 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 302:

/* Line 678 of lalr1.cc  */
#line 6826 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 303:

/* Line 678 of lalr1.cc  */
#line 6846 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 304:

/* Line 678 of lalr1.cc  */
#line 6879 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 305:

/* Line 678 of lalr1.cc  */
#line 6892 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkDist( im.get()));

        Si (!res.get()) Alors
          driver.err_print("vtkDist() erreur ... \n");
        FinSi
        ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 6903 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 307:

/* Line 678 of lalr1.cc  */
#line 6916 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 308:

/* Line 678 of lalr1.cc  */
#line 6940 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, input);
        InrImage::ptr res (Func_2DFlux(input.get(),(yysemantic_stack_[(6) - (5)].adouble)));

      Si (res.get()) Alors
        driver.err_print("2DFlux() error ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 6951 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_OutFlux( im.get()));

      Si (!res.get()) Alors
        driver.err_print("OutFlux() erreur ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 6962 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_OutFluxScalar( im.get()));
    Si (!res.get()) Alors
      driver.err_print("OutFluxScalar() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 6972 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_OrientationRatio2D( im.get()));
    Si (!res.get()) Alors
      driver.err_print("OrientationRatio() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 6982 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 313:

/* Line 678 of lalr1.cc  */
#line 7015 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_SimplePoints( im.get() ));

    Si !res.get() Alors
      driver.err_print("SimplePoints() error ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 7027 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 315:

/* Line 678 of lalr1.cc  */
#line 7048 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 316:

/* Line 678 of lalr1.cc  */
#line 7068 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 317:

/* Line 678 of lalr1.cc  */
#line 7109 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 318:

/* Line 678 of lalr1.cc  */
#line 7155 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 319:

/* Line 678 of lalr1.cc  */
#line 7175 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 320:

/* Line 678 of lalr1.cc  */
#line 7196 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res( Func_NormalSmoothField( im.get() ));

    Si !res.get() Alors
      driver.err_print("NormalField() error ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 7207 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 322:

/* Line 678 of lalr1.cc  */
#line 7221 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 323:

/* Line 678 of lalr1.cc  */
#line 7237 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, input);
  
      InrImage::ptr res ( Func_NormGrad( input.get(), (yysemantic_stack_[(6) - (5)].adouble)));
      Si (!res.get()) Alors
        driver.err_print("NormGrad() error ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 7249 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_DiscNormGrad( im.get()));
    Si !res.get() Alors
      driver.err_print("discnormgrad() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 7260 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_DiscMeanCurvature( im.get()));
    Si !res.get() Alors
      driver.err_print("DiscMeanCurvature() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 7272 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 327:

/* Line 678 of lalr1.cc  */
#line 7283 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 328:

/* Line 678 of lalr1.cc  */
#line 7303 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage,im);
        InrImage::ptr res (Func_SecDerGrad( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
        Si !res.get() Alors
          fprintf(stderr,"SecDerGrad() erreur ... \n");
        FinSi
        ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 7315 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 330:

/* Line 678 of lalr1.cc  */
#line 7325 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage,im);
        InrImage::ptr res ( Func_AutoCrop(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
        ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 7380 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 332:

/* Line 678 of lalr1.cc  */
#line 7418 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 333:

/* Line 678 of lalr1.cc  */
#line 7429 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_EDP_dilate( im.get(), (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 7439 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 335:

/* Line 678 of lalr1.cc  */
#line 7451 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 336:

/* Line 678 of lalr1.cc  */
#line 7462 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_EDP_erode( im.get(), (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 7472 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 338:

/* Line 678 of lalr1.cc  */
#line 7499 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 339:

/* Line 678 of lalr1.cc  */
#line 7522 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 340:

/* Line 678 of lalr1.cc  */
#line 7550 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 341:

/* Line 678 of lalr1.cc  */
#line 7563 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 342:

/* Line 678 of lalr1.cc  */
#line 7697 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 343:

/* Line 678 of lalr1.cc  */
#line 7732 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 344:

/* Line 678 of lalr1.cc  */
#line 7765 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 345:

/* Line 678 of lalr1.cc  */
#line 7793 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 346:

/* Line 678 of lalr1.cc  */
#line 7807 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 347:

/* Line 678 of lalr1.cc  */
#line 7819 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_SRAD_qcoeff( im.get()));
      Si !res.get() Alors
        fprintf(stderr,"Func_SRAD_qcoeff() erreur ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
        }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 7831 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 349:

/* Line 678 of lalr1.cc  */
#line 7849 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 350:

/* Line 678 of lalr1.cc  */
#line 7868 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 351:

/* Line 678 of lalr1.cc  */
#line 7888 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 352:

/* Line 678 of lalr1.cc  */
#line 7910 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 353:

/* Line 678 of lalr1.cc  */
#line 7930 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 354:

/* Line 678 of lalr1.cc  */
#line 7949 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 355:

/* Line 678 of lalr1.cc  */
#line 7969 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 356:

/* Line 678 of lalr1.cc  */
#line 7989 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 357:

/* Line 678 of lalr1.cc  */
#line 8030 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 358:

/* Line 678 of lalr1.cc  */
#line 8052 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 359:

/* Line 678 of lalr1.cc  */
#line 8080 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 360:

/* Line 678 of lalr1.cc  */
#line 8101 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 361:

/* Line 678 of lalr1.cc  */
#line 8138 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 362:

/* Line 678 of lalr1.cc  */
#line 8175 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 363:

/* Line 678 of lalr1.cc  */
#line 8212 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 364:

/* Line 678 of lalr1.cc  */
#line 8246 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          ADD_VARSTACK(InrImage,InrImage::ptr(( varsurfd->Pointer())->GetCanvas()->GetGLImage()));
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 8252 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          driver.yyiperror("Not available in new wxwidgets version of the 3D viewer ! ");
          YYABORT;
/*
          ADD_VARSTACK(InrImage,(*(Viewer3D_ptr*) $1->Pointer())->GetInrImage());
*/
    }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 8269 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_ThresholdCrossing( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
       ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 8276 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_IsocontourPoints( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 8283 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_IsosurfDist( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
      ADD_VARSTACK_PTR(InrImage,res);

    }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 8291 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_vtkIsoContourDist( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 8298 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 371:

/* Line 678 of lalr1.cc  */
#line 8322 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 372:

/* Line 678 of lalr1.cc  */
#line 8349 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 373:

/* Line 678 of lalr1.cc  */
#line 8373 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 374:

/* Line 678 of lalr1.cc  */
#line 8402 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 375:

/* Line 678 of lalr1.cc  */
#line 8431 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im2);
      GET_VARSTACK_VALUE(InrImage, im1);
      InrImage::ptr res ( Func_Convolve(im1.get(), im2.get()));
      ADD_VARSTACK_PTR(InrImage,res);

      }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 8440 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 377:

/* Line 678 of lalr1.cc  */
#line 8453 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_Chamfer(im.get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble)));
        ADD_VARSTACK_PTR(InrImage,res);
        }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 8460 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
          InrImage::ptr res ( Func_Chamfer2(im.get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble)));
          ADD_VARSTACK_PTR(InrImage,res);

        }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 8468 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 380:

/* Line 678 of lalr1.cc  */
#line 8482 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr  res ( Func_Chamfer2(im.get(),
                  0.92644, 1.34065, 1.65849,
                  dmax));
        ADD_VARSTACK_PTR(InrImage,res);

        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 8494 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_Chamfer2Signed(im.get(),
                    0.92644, 1.34065, 1.65849,
                    dmax));
        ADD_VARSTACK_PTR(InrImage,res);

        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 8506 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkSignedBorgefors(im.get(),
                    dmax));
        ADD_VARSTACK_PTR(InrImage,res);
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 8516 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkSignedFMDist(im.get(),
                     dmax));
        ADD_VARSTACK_PTR(InrImage,res);

        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 8527 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_PropagationDistance(im.get(),
                      dmax));
        ADD_VARSTACK_PTR(InrImage,res);
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 8537 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_PropagationDistance2(im.get(),
                      dmax));
        ADD_VARSTACK_PTR(InrImage,res);
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 8547 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

        GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_PropagationDanielsson(im.get(),
                       dmax));

        ADD_VARSTACK_PTR(InrImage,res);
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 8558 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkPropDanielsson(im.get(),
                       -dmax,dmax));
        ADD_VARSTACK_PTR(InrImage,res);
        }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 8568 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        float dmin = (yysemantic_stack_[(8) - (5)].adouble);
        float dmax = (yysemantic_stack_[(8) - (7)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkPropDanielsson(im.get(),
                       dmin,dmax));
        ADD_VARSTACK_PTR(InrImage,res);
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 8579 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 390:

/* Line 678 of lalr1.cc  */
#line 8606 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 391:

/* Line 678 of lalr1.cc  */
#line 8654 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 392:

/* Line 678 of lalr1.cc  */
#line 8788 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 393:

/* Line 678 of lalr1.cc  */
#line 8809 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 394:

/* Line 678 of lalr1.cc  */
#line 8849 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 395:

/* Line 678 of lalr1.cc  */
#line 8860 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      int dim = (int) (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage,im);
      InrImage::ptr res ( Func_MeanHalfSize(im.get(),dim));
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 8868 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        int axis=(int) (yysemantic_stack_[(6) - (5)].adouble);

        GET_VARSTACK_VALUE(InrImage,im);
        InrImage::ptr res(Func_Flip(im,axis));
        ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 8876 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 398:

/* Line 678 of lalr1.cc  */
#line 8897 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 399:

/* Line 678 of lalr1.cc  */
#line 8923 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      int   order = (int) (yysemantic_stack_[(8) - (5)].adouble);
      float resolution = (yysemantic_stack_[(8) - (7)].adouble);
      GET_VARSTACK_VALUE(InrImage,input);

      InrImage::ptr res ( Func_vtkConvexHull(input.get(),
                   order,resolution));

      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 8934 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);

      InrImage::ptr res ( AMIFluid::Func_Altitude2Position(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 8941 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      InrImage::ptr res ( AMIFluid::Func_Altitude2Position(im.get()));
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 8947 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      InrImage::ptr res ( AMIFluid::Func_GeoCoordinates(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 8953 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im.get());
      ADD_VARSTACK(InrImage,res);
    }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 8960 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 405:

/* Line 678 of lalr1.cc  */
#line 8985 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 406:

/* Line 678 of lalr1.cc  */
#line 9003 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));
      InrImage::ptr res( AMIFluid::Func_ReadFlow(filename.get()));
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 9010 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 408:

/* Line 678 of lalr1.cc  */
#line 9043 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 409:

/* Line 678 of lalr1.cc  */
#line 9062 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 411:

/* Line 678 of lalr1.cc  */
#line 9111 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
    Description: adds a reference to the variable in the stack
    **/
    BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->NewReference());
  }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 9120 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 421:

/* Line 678 of lalr1.cc  */
#line 9150 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 422:

/* Line 678 of lalr1.cc  */
#line 9171 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 426:

/* Line 678 of lalr1.cc  */
#line 9320 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          // todo ... 
          // 1. check if identifier belongs to the object
          // 2. if so return corresponding variable
          Variable<AMIObject>::ptr var(driver.var_stack.GetLastVar<AMIObject>());
          if (!var.get()) {
            driver.err_print("operator . (Element selection) is only available for variables of type AMIObject");
            YYABORT;
          }
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

  case 427:

/* Line 678 of lalr1.cc  */
#line 9355 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 428:

/* Line 678 of lalr1.cc  */
#line 9432 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Logical negation (NOT) operator.
    **/
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(!(*var));
  }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 9440 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Postfix increment operator.
    **/
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar((*var)++);
  }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 9448 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Postfix decrement operator.
    **/
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar((*var)--);
  }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 9456 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Transpose operator, usefull for matrices
    **/
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->Transpose());
  }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 9508 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Array subscript operator.
    **/
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)[var2]);
  }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 9522 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Cast operator.
    **/
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->BasicCast( (yysemantic_stack_[(4) - (2)].aint)));

  }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 9531 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    //cout << "T_SUB  cast_var  " << endl;
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(-(*var));
  }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 9537 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(+(*var));
  }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 9542 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(++(*var));
  }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 9547 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(--(*var));
  }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 9552 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_sin());
  }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 9557 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_cos());
  }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 9562 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_sqrt());
  }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 9567 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_fabs());
  }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 9572 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_round());
  }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 9577 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_floor());
  }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 9582 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_tan());
  }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 9587 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_asin());
  }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 9592 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_acos());
  }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 9597 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_atan());
  }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 9602 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_exp());
  }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 9607 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_log());
  }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 9612 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_ln());
  }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 9617 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_norm());
  }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 9627 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)*var2);
  }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 9633 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)/var2);
  }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 9639 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)%var2);
  }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 9650 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    BasicVariable::ptr res(*var1+var2);
    driver.var_stack.AddVar(res);
  }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 9657 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    BasicVariable::ptr res((*var1)-var2);
    driver.var_stack.AddVar(res);
  }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 9672 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)<var2);
  }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 9678 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)>var2);
  }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 9684 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)<=var2);
  }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 9690 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)>=var2);
  }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 9700 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)==var2);
  }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 9706 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)!=var2);
  }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 9747 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Descriptiopn: Logical AND operator
    **/
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)&&var2);
  }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 9760 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Descriptiopn: Logical XOR operator, for vectorial images it defines the pointwise vectorial product.
    **/
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)^var2);
  }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 9773 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Descriptiopn: Logical OR operator
    **/
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)||var2);
  }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 9786 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 483:

/* Line 678 of lalr1.cc  */
#line 9800 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 484:

/* Line 678 of lalr1.cc  */
#line 9810 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    //cout << "assignment_var" << endl;
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1).left_assign(var2));
  }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 9817 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)+=var2);
  }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 9823 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)-=var2);
  }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 9829 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)*=var2);
  }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 9835 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)/=var2);
  }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 9847 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
            GET_VARSTACK_VALUE(GLTransfMatrix,glt);
            GLTransfMatrix* newglt;

            newglt = new GLTransfMatrix();
            (*newglt) = (*glt);
            driver.gltransf_stack.AddMatrix(newglt);
    
        }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 9858 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 492:

/* Line 678 of lalr1.cc  */
#line 9872 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(GLTransfMatrix,glt2);
        GET_VARSTACK_VALUE(GLTransfMatrix,glt1);
        GLTransfMatrix* newglt = NULL;
        float coeff = (yysemantic_stack_[(8) - (7)].adouble);

        newglt = Func_InterpolateTransform(glt1.get(),glt2.get(),coeff);
        driver.gltransf_stack.AddMatrix(newglt);
      }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 9883 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 494:

/* Line 678 of lalr1.cc  */
#line 9901 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
         FloatMatrix::ptr m( new FloatMatrix((int)(yysemantic_stack_[(6) - (3)].adouble),(int)(yysemantic_stack_[(6) - (5)].adouble)));
         ADD_VARSTACK_PTR(FloatMatrix,m);
      }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 9907 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Description: adds a reference to the variable in the stack
        **/
        BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
        driver.var_stack.AddVar(var->NewReference());
      }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 9916 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 497:

/* Line 678 of lalr1.cc  */
#line 10061 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 498:

/* Line 678 of lalr1.cc  */
#line 10076 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 499:

/* Line 678 of lalr1.cc  */
#line 10088 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 500:

/* Line 678 of lalr1.cc  */
#line 10110 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 501:

/* Line 678 of lalr1.cc  */
#line 10146 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_OBJECT(SurfacePoly,varsurf)
      SurfacePoly* surf;
      surf = Func_decimate( varsurf.get());
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 10155 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* newsurf;
      GET_VARSTACK_OBJECT(SurfacePoly,varsurf)

      newsurf = Func_decimate( varsurf.get(), (yysemantic_stack_[(6) - (5)].adouble) );
      BasicVariable::ptr res(CreateVar_SurfacePoly(newsurf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 10165 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf;
      GET_VARSTACK_VALUE(InrImage, im);
      surf = Func_vtkMarchingCubes(im.get(),(yysemantic_stack_[(6) - (5)].adouble));
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 10174 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* newsurf;
      GET_VARSTACK_OBJECT(SurfacePoly,surf)

      newsurf = Func_vtkSmooth(surf.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      BasicVariable::ptr res(CreateVar_SurfacePoly(newsurf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 10184 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 506:

/* Line 678 of lalr1.cc  */
#line 10198 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf = new SurfacePoly();
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 10205 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(2) - (2)].astring));
      SurfacePoly* surf = new SurfacePoly();
      surf->Read(filename.get());
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 10214 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 509:

/* Line 678 of lalr1.cc  */
#line 10230 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 510:

/* Line 678 of lalr1.cc  */
#line 10249 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 511:

/* Line 678 of lalr1.cc  */
#line 10269 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 512:

/* Line 678 of lalr1.cc  */
#line 10299 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 513:

/* Line 678 of lalr1.cc  */
#line 10328 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 514:

/* Line 678 of lalr1.cc  */
#line 10346 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 515:

/* Line 678 of lalr1.cc  */
#line 10372 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 516:

/* Line 678 of lalr1.cc  */
#line 10405 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 517:

/* Line 678 of lalr1.cc  */
#line 10441 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 518:

/* Line 678 of lalr1.cc  */
#line 10487 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 519:

/* Line 678 of lalr1.cc  */
#line 10525 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_VARSTACK_VALUE(InrImage,im);
      SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get());
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 10534 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 521:

/* Line 678 of lalr1.cc  */
#line 10556 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 522:

/* Line 678 of lalr1.cc  */
#line 10567 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 523:

/* Line 678 of lalr1.cc  */
#line 10578 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 524:

/* Line 678 of lalr1.cc  */
#line 10614 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 525:

/* Line 678 of lalr1.cc  */
#line 10656 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 526:

/* Line 678 of lalr1.cc  */
#line 10702 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 527:

/* Line 678 of lalr1.cc  */
#line 10752 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 528:

/* Line 678 of lalr1.cc  */
#line 10794 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 529:

/* Line 678 of lalr1.cc  */
#line 10825 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 530:

/* Line 678 of lalr1.cc  */
#line 10857 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 552:

/* Line 678 of lalr1.cc  */
#line 10959 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
        Description: creates an image extent based on the limits in voxel coordinates in X,Y and Z
        Parameters: xmin, xmax, ymin, ymax, zmin, zmax
      **/
      GET_VARSTACK_VALUE(float,zmax)
      GET_VARSTACK_VALUE(float,zmin)
      GET_VARSTACK_VALUE(float,ymax)
      GET_VARSTACK_VALUE(float,ymin)
      GET_VARSTACK_VALUE(float,xmax)
      GET_VARSTACK_VALUE(float,xmin)
      ImageExtent<float>* extent=new ImageExtent<float>(  *xmin, *xmax, 
                                                          *ymin, *ymax, 
                                                          *zmin, *zmax);
      extent->SetMode(1); // relative
      BasicVariable::ptr res(CreateVar_ImageExtent(extent));
      driver.var_stack.AddVar(res);
    }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 10979 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
        Description: creates an image extent based on the limits in pixel coordinates in X,Y 
        Parameters: xmin, xmax, ymin, ymax
      **/
      GET_VARSTACK_VALUE(float,ymax)
      GET_VARSTACK_VALUE(float,ymin)
      GET_VARSTACK_VALUE(float,xmax)
      GET_VARSTACK_VALUE(float,xmin)

      ImageExtent<float>* extent=new ImageExtent<float>( *xmin, *xmax, *ymin, *ymax);
      extent->SetMode(1); // relative
      BasicVariable::ptr res(CreateVar_ImageExtent(extent));
      driver.var_stack.AddVar(res);
    }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 10996 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 555:

/* Line 678 of lalr1.cc  */
#line 11014 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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



/* Line 678 of lalr1.cc  */
#line 10772 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
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
  const short int Parser::yypact_ninf_ = -1702;
  const short int
  Parser::yypact_[] =
  {
      4737,  9573,  8111,  8111,  8111,    51, -1702, -1702, -1702,  8111,
    8111,  8111, -1702, -1702,    28,    73,    85, -1702, -1702, -1702,
   -1702,  8485, -1702,   -47,    90, -1702,   -37,  8111,  8111,  8111,
     120,  8111, -1702,   124,   140, -1702, -1702, -1702, -1702, -1702,
   -1702,     2, -1702,   -11, -1702, -1702, -1702, -1702, -1702,     5,
      23,   175,   223,   118,  8111,   237, -1702, -1702, -1702, -1702,
     244,   251,  8859,  8111,   273,   115,   304,   290,   390,   332,
     385,   389,   393,   404,   409,   446,   450,   452,   455,   464,
     465,   466,   468,   470,   471,   472,   473, -1702, -1702, -1702,
   -1702,   474,   475,   476,   399,   477,   478,   479,   480,   481,
     482,   484,   485,   486,   487,   488,   489,   491,   492,   493,
     494,   495,   496,   498,   499,   500,   501,   502,   503,   504,
     505,   443,   506,   507,   508,   509,   510,   511,   512,   513,
     514,   515,   516,   517,   518,   519,   520,   521,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   538,   539,   540,   541,   542,   543,   545,   546,
     547,   548,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   561,   562,   563,   565,   566,   568,   569,
     571,  6989,   572,   573,   574,   575,   577,   581, -1702, -1702,
   -1702, -1702, -1702, -1702, -1702, -1702, -1702, -1702, -1702,   583,
     584,   586,   587,   588, -1702, -1702,  8111,  8111,  8111,  8111,
    8111,  8111,  8111,  8111,  8111,  8111,  8111,  8111,  8111,  8111,
       5, -1702,   118, -1702,  8111,  6241,  8111,   589,   590,   591,
     592,    13,     5,   593,   594,   595,   596,   597,   599,   598,
     600,   601,   602,   603,   606,   607,   608,   609,   610,   611,
     612,   615,   616,   617, -1702, -1702, -1702,   618,   619,   490,
    4355, -1702, -1702, -1702, -1702, -1702, -1702, -1702,    12, -1702,
   -1702,   614,    55, -1702, -1702, -1702,   613,    39, -1702,   196,
      40, -1702,    27,   109,   620, -1702,   621,   544,   630,    -8,
     -45, -1702, -1702,   135, -1702,   -55, -1702, -1702, -1702, -1702,
   -1702,  8111,   622,   623, -1702,   625,   624,   626,   137, -1702,
     153, -1702, -1702,    83,   633,   627, -1702, -1702, -1702, -1702,
    8111,  8111,  8111,  8111, -1702, -1702, -1702, -1702, -1702, -1702,
   -1702, -1702, -1702, -1702, -1702, -1702, -1702, -1702, -1702,  8111,
   -1702,   118,   118,   152,  8111,  8111,   -31,   313, -1702, -1702,
     -39,  8111, -1702, -1702, -1702, -1702, -1702, -1702, -1702, -1702,
     625, -1702, -1702, -1702, -1702, -1702, -1702,   118,  8111,  8111,
   -1702, -1702,  8111,  8111,  8111,  8111,  8111,  8111,  8111,  8111,
     -37,  8111,  8111,   -37,   -37,   -37,   -37,   -37,  8111,   -37,
     -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,  8111,  8111,
     -37,   207,   225,   -37,   -37,   -37,   -37,   -37,   -37,   -37,
     -37,   -37,   -37,  8111,   -37,   -37,   -37,   -37,   -37,   -37,
     -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,  8111,  8111,
    8111,  8111,  8111,  8111,  8111,   -37,   -37,   -37,   -37,   -37,
     -37,   -37,   -37,   -37,   578,   579,   -37,   -37,   -37,   -37,
     580,  8111,  8111,  8111,   582,  8111,   585,  8111,  8111,   -37,
     -37,   -37,   604,   605,   -37,   -37,   -37,   -37,   -37,   -37,
     -37,   -37,   -37,   -37,   -37,  8111,  8111,  8111,   -37,  8111,
    8111,   -37,   628,   -37,   629,   631,  8111,   -37,   -37,  7363,
    8111, -1702,  8111,  8111,  8111,  8111,  8111,  8111,  8111,  8111,
    8111,  8111,   -37, -1702, -1702, -1702, -1702, -1702, -1702, -1702,
   -1702, -1702, -1702, -1702, -1702, -1702, -1702,   -87, -1702,   632,
   -1702, -1702, -1702,    12, -1702,    44,  8111,  8111,   634, -1702,
   -1702,   635,  8111,  8111,   -37,  8111,  8111,   266,  8111,  8111,
    8111,  8111,  8111,  8111,  8111,  8111,  8111,  8111,  8111,  8111,
    8111,   636,   -37,   -37,   -37, -1702, -1702, -1702, -1702, -1702,
   -1702, -1702, -1702, -1702,    12, -1702,   300,  8111,   -17,  9573,
    5493,  8111,     5, -1702, -1702, -1702,  8111,  8111,  8111,  8111,
    8111,  8111,  8111,  8111,  8111,  8111,  8111,  8111,  8111,  8111,
    8111,  8111,  8111,  8111,  8111,  8111,  8111,  8111,  8111,  8111,
     369,  8111,  5119,    91,    11,  8111,   497,   522,  8111,    26,
       9,  8111, -1702,   639,   642,   640,   649,    69,   644,   651,
     652, -1702, -1702,   643,   654,   655,   656, -1702,   657,   658,
     659,   660, -1702, -1702,   661, -1702,   663, -1702,   664,   665,
     666,   667,   668, -1702, -1702,  8111,  8111, -1702,   669,   670,
   -1702,   671, -1702,  8111,   672,   673,   677,   674,   678, -1702,
     681,   676,   682,   683,   686,   687,   691,   690,   688,   689,
     692,   693,   694,   695,   696,   697,   698,   699,   700,   701,
     702,   703,   704,   705,   712,   707,   708,   709,   710,   718,
   -1702, -1702,   719, -1702, -1702,   720,   713,   715,   716,   717,
     721,   722,   723,   724,   725,   726,   733,   734,   735,   730,
     737,   732,   736,   738,   739,   740,   181,   741,   743,   742,
     749,    47,   748,   745,   746,   747,   750,   751,   752,   753,
     754,   755,   756,   757,   764,   759,   766,   193,   761,   762,
     763,   765,   767,   768,   769,   770,   771,   772,   198,   773,
     780,   781,   776,   778,   779,   782,   783,   784,   785,   786,
     787,   788,   789,   790,   791,   792,   793,   794,   801,   802,
     803,   798,   799,   108,   800,   804,   222,   805,   806,   807,
     808,   809,   815, -1702,   814,   811,   818,   819,   820,   821,
     822,   823,   824,   825,   826,   827,  8111,  8111, -1702, -1702,
     -18, -1702,   828,   829,   833,   830,   834,   727,   836,   282,
      12,   229,   831,   832,   835,   837,   840,   231,   838,   839,
     234,   241,   841,   842,   843,   844,   845,   846,   852,   853,
     848,   849,   850,   851, -1702, -1702,   197,   858,   860, -1702,
     861, -1702,   862, -1702, -1702,  8111, -1702,   863,   864,   865,
     866,   867,   868,   869,   870,   871, -1702, -1702, -1702, -1702,
   -1702, -1702, -1702, -1702, -1702, -1702, -1702, -1702, -1702,   872,
    8111,   622,   623,   245, -1702, -1702,   873, -1702, -1702, -1702,
   -1702,   196,   196, -1702, -1702, -1702, -1702,    27,    27,   109,
   -1702,   621,   544,   -12,   630, -1702, -1702, -1702, -1702, -1702,
   -1702,   874,   875, -1702,  6615,  7737,   877,   876, -1702,   878,
     880,   883,   884,   879, -1702, -1702,   882,   132, -1702,  8111,
    8111, -1702, -1702,  8111,  8111, -1702, -1702,  8111,  8111,  8111,
    8111,  8111,  8111,  8111,  8111,  8111,   -21,   646,   653,  8111,
    8111,  8111, -1702, -1702,  8111,   402,  8111, -1702,   576,  8111,
   -1702,   684, -1702, -1702,  8111,   887, -1702, -1702,   888, -1702,
     889,     0,  8111,  8111, -1702,  8111,  8111,  8111,  8111,  8111,
     -37,  8111,  8111,  8111,  8111,  8111,  8111, -1702,  8111,  8111,
    8111,   -37,   -37,   -37, -1702,  8111,  8111,  8111,  8111,  8111,
    8111,  8111,  8111,   -37,  8111, -1702, -1702, -1702,   -37, -1702,
     -37,   -37,   -37,   -37,   -37, -1702,   -37,   -37, -1702,  8111,
   -1702,  8111,   890,  8111,  8111,  8111,  8111,  8111,  8111,  8111,
    8111,  8111,  8111,  8111, -1702,  8111, -1702, -1702,  8111,  8111,
    8111,  8111,  8111,  8111,  8111,  8111,  8111,  8111,   -37, -1702,
    8111,  8111, -1702, -1702,   -37,   -37,   -37,   -37,   -37,  8111,
    8111,  8111,  8111,  8111,  8111,  8111,  8111,  8111,  8111,  8111,
   -1702, -1702, -1702,  8111,  8111, -1702,  8111,  8111, -1702,  8111,
    8111,  8111,  8111,  8111, -1702, -1702, -1702,  8111, -1702, -1702,
   -1702, -1702, -1702, -1702,  8111,  8111,  8111, -1702,   362,   885,
   -1702, -1702, -1702, -1702, -1702, -1702, -1702,  8111, -1702,  -192,
    -192,   641, -1702, -1702,  8111,  8111,   -37,  8111,  8111,   -37,
   -1702,  8111,  8111,  8111, -1702,  8111, -1702,  8111,  8111,  8111,
    8111,  8111,  8111, -1702, -1702, -1702,  8111,  8111,   -37,   -37,
    8111,  8111,  8111, -1702,  8111,  8111,   -37, -1702,   -37,   -37,
    8111,  8111,  8111,  8111,  8111,  8111,  8111,  9573, -1702, -1702,
    5867, -1702,  8111,  8111,  8111, -1702, -1702,  8111,  8111,  -204,
     679,  8111,  8111,  8111,  8111, -1702,   816,   886,   891,   894,
     892,   246,   896,   901,   899,   905,   906,   907,   902,   909,
     248,   918,   913,   914,   915,   922,   923,   924,   925,   920,
    8111,   927,   928,   929,  8111,   -37,   -37,   253,   926,   930,
     931,   933,   934,   935,   940,   937,   260,   947,   949,   950,
     951,   952,   953,   954,   963,   966,   967,   968,   969,   970,
     971,   972,   973,   974,   976,   978,   980,   987,   988,   986,
     994,   996,   997,  1008,  1009,   993,  1017,  1012,  1019,  8111,
    1020,  1021,  1022,  1018,  1030,  1031,  1032,   261,  1035,  1038,
    1023,  1044,  1045,  1052,  1054,  1055,  1056,  1057,  1053,  1058,
    1059,  1060,  1061,  1063,  1068,  1069,  1064,  1065,  1066,  1070,
    1071,  1072,  1074,  1075,  1079,  1082,  1085,  1086,  1090,   263,
    1088,  1091,  1092,   264,  1101,  1103,  1104,  1105,  1109,  1106,
    1110,  1107,  1108,  1117,  8111,  8111,    12,    12,  1118,   680,
     795,   797,   895,  1013,   265,   274, -1702,  1115,  1119,  1120,
    1127,  1122,  1125,   275,  1126,  1128,  1135,  1136,  1134,  1137,
    1138,  1139,  1142,  1140,  1147,  1143,  1144,    59,  1145,  1148,
    1152,  1149,   276,  1153,  1154,  1150,   110,  1151,   121,  1158,
     277,  1155,  1156,   284,   817,  8111, -1702, -1702, -1702,  1159,
    1157,  1162,  1160, -1702,  1161,  1165,  1166,  1163, -1702,  8111,
    8111,  8111, -1702,  8111, -1702,  8111, -1702, -1702,  8111,  8111,
    8111,  8111, -1702,   424, -1702,  8111, -1702,   -37,  8111,  8111,
   -1702, -1702, -1702, -1702,   728, -1702, -1702, -1702, -1702,  1168,
    1170,   286, -1702,   102,     1,  8111, -1702, -1702, -1702, -1702,
    8111, -1702, -1702,   -37,  8111,  8111,  8111,  8111,  8111,  8111,
    8111,  8111,  8111,  8111,  8111,  8111,  8111,  8111,  8111,  8111,
    8111,  8111,  8111,  8111, -1702, -1702,  8111,   -37,   -37,   -37,
     -37,   -37, -1702, -1702,  8111, -1702,  1171, -1702, -1702, -1702,
    8111,  8111,  8111,  8111, -1702,  8111,  8111,  8111, -1702,  8111,
    8111, -1702, -1702, -1702, -1702, -1702,  8111,  8111,  8111,  8111,
    8111, -1702, -1702, -1702,  8111,  8111,   -37,   -37,  8111,  8111,
   -1702, -1702, -1702, -1702, -1702, -1702, -1702, -1702,  8111,  8111,
    8111,  8111, -1702,   -37, -1702, -1702, -1702, -1702, -1702,  8111,
   -1702,  8111,  8111,  8111,   414, -1702, -1702, -1702,  8111, -1702,
   -1702, -1702, -1702, -1702, -1702,  -157, -1702,    12, -1702,  8111,
    8111, -1702,  8111,  8111, -1702,  8111,  8111,  8111, -1702, -1702,
    8111,  8111,  8111,  8111, -1702,  8111, -1702,   -37,  8111, -1702,
    8111,  8111,  8111, -1702, -1702,  8111, -1702,  8111, -1702, -1702,
    8111, -1702,  8111, -1702, -1702, -1702,  8111,  8111,  8111, -1702,
    8111,  9573, -1702, -1702,  8111, -1702, -1702,   812,  1167,  1169,
     744, -1702,  1172,  1173,   192,  1174,  1176,  1175,  1177,  1178,
    1179,  1182,  1186,  1187,  1183,  1188, -1702, -1702, -1702,  8111,
    1190,  1087,   287,  1185,  1189,  1191,  1192,   294,   296,   318,
     319,  1193,  1194,  1195,   322,    81,  1196,  1197,  1198,  1199,
     323,  1200,  1201,  1202,  1203,  1204,  1205,  1212,  1207,  1208,
    1209,  1210,  1211,  1213,  1214, -1702,  1218,  1221,   363,   401,
    1216,  1223,  1219,  1220,  1222,  1224,  1225,  1226,  1227,  1228,
    1229,  1235,  1230,  1231,  1232,  1233,  1234,  1241,  1236,  1237,
    1238,  1245,  1246,  1247,  1242,  1243,  8111,    12,  1244,    12,
    1015,  1129,  1132,  1133,  1206,    12, -1702,  1249,  1250,  1252,
    1251,  1253,  1254,  1258,  1255,  1256,  1259,  1257,  1260,  1261,
    1262,    67,  1264,  1263,  1265,  1266,  1267,  1268,  1269,  1270,
    1271,  1272,  1273,  1274,  1275,  8111,  8111,  1282, -1702,  8111,
   -1702,  8111, -1702,  8111,  8111,  8111,  8111, -1702, -1702, -1702,
    8111, -1702,  1283, -1702,   461, -1702,   102,  1248,  8111,  8111,
   -1702, -1702,  8111, -1702,  8111, -1702,  8111, -1702,  8111,  8111,
    8111,  8111, -1702,  8111,  8111,  8111,  8111,  8111,  8111, -1702,
    8111,  8111,  9224,  8111,  8111,  8111,  8111, -1702,  8111,  8111,
    8111,  8111,  8111,   -37,  8111, -1702, -1702, -1702,  8111, -1702,
    8111,  8111, -1702,  8111,  8111,  8111,  8111,  8111,  8111,  8111,
    8111, -1702, -1702,  8111,   -37,   -37,  8111,  8111, -1702,  8111,
    8111,  8111, -1702, -1702, -1702,  8111,  8111, -1702, -1702,  8111,
   -1702, -1702, -1702, -1702, -1702, -1702, -1702,  8111,  8111, -1702,
    8111, -1702,  8111, -1702,  8111,  8111, -1702,  8111,  8111,   -37,
    8111, -1702,  8111,  8111, -1702,  8111, -1702,  8111,  8111,  8111,
    8111,  8111,  8111,  8111,  9573,  8111,  8111, -1702, -1702, -1702,
     405,  1284,  1279,  1280,  1281,  1288,  1285, -1702,  1289,   413,
    1286,  1287,   416,   417,  1290,  1291,  1292,  1293,  1294,  1295,
    1296,  1297,  1298,  1299,  1300,  1301,  1308,  1303,  1311,   613,
    1312,  1307,  1309,  1310,  1313,  1314,  1315,  1316,  1317,  1318,
     418,  1319,  1326,   420,  1327,  1322,  1323,  1330,  1331,  1328,
    1332,  1333,  1334,  1336,   421,  1337,  1348,   425,  1349,  1350,
    1352,  1353,  1355,    12,  1351,  1354,  1356,  1358,  1357,  1359,
    1360,  1361,  1362,  1363,  1364,  1372,  1373,  1368,  1369,  1377,
    1378,  1379,  1401,  1403,  1404,  1306,  1405,  1406, -1702,  8111,
   -1702,  8111,  8111,  8111, -1702,  8111, -1702, -1702,   102,  8111,
    8111, -1702,  8111, -1702,  8111,  8111,  8111,  8111,  8111, -1702,
    8111,  8111,  8111,  8111,  8111,  8111,  9224, -1702,  9224, -1702,
   -1702,  9224,  9224,  8111,  8111,  8111,   -37,   -37,   -37,   -37,
   -1702,  8111,  8111, -1702, -1702,  8111, -1702,  8111,  8111, -1702,
   -1702,  8111,  8111, -1702,  8111,  8111, -1702,  8111,   -37, -1702,
   -1702,  8111, -1702, -1702, -1702, -1702, -1702, -1702,  8111,  8111,
    8111, -1702,  8111,  8111,  8111,  8111,  8111,   -37,  8111, -1702,
   -1702,  8111,  8111, -1702, -1702, -1702, -1702, -1702, -1702,  9573,
   -1702, -1702,  1407,  1408,  1409,  1411,  1414,  1412,  1413,  1418,
    1415,  1427,  1428,  1429,  1430,  1425,   428,  1436,  1431,  1438,
    1439,  1434,  1442,  1443,  1446,  1447,  1445,  1448,  1449,  1453,
    1459,  1454,  1455,  1462,  1457,  1464,  1465,  1460,  1466,  1467,
    1469,  1470,  1471,  1472,  1477,  1473,  1480,  1475,   429,  1476,
    1478,  1481,  1484,  1488,  1489,  1324,  1483, -1702, -1702, -1702,
   -1702, -1702,  8111, -1702, -1702,  8111, -1702, -1702, -1702, -1702,
   -1702,  8111, -1702,  8111, -1702,  8111, -1702, -1702,  8111, -1702,
   -1702, -1702, -1702,  9224, -1702, -1702, -1702, -1702,  8111,  8111,
   -1702,  8111, -1702, -1702,  8111,  8111,  8111,  8111,  8111, -1702,
     -37, -1702,  8111, -1702,  8111, -1702,  8111,  8111,  8111,  8111,
    8111,   -37,  8111,  8111, -1702,  1490,  1493,  1500,  1502,  1503,
    1499,  1509,  1504,  1505,  1512,  1508,  1511,  1513,   430,  1514,
    1515,  1519,  1521,  1522,   432,  1529,  1525,  1526,  1527,  1528,
    1535,  8111,  8111, -1702, -1702, -1702,  8111, -1702,  8111,  8111,
   -1702,  8111,  8111,  8111, -1702,  8111,  8111,   -37,  8111,  8111,
    8111, -1702,  8111, -1702,  8111,  8111,   -37,  8111,   711,  1536,
    1537,  1538,  1539,  1534,   433,  1541,  1540,  1542,  1543,   437,
    1544,  1545,  1547,   440,   441,  1546,  1548,  1550,  8111, -1702,
   -1702, -1702, -1702,  8111, -1702,  8111, -1702,  8111,  8111,  8111,
   -1702,  8111,  8111,  8111, -1702, -1702,  8111, -1702,  8111,  8111,
    8111,  8111, -1702,  1551,  1553,  1558,  1554,  1559,  1561,  1562,
    1557,  1564,  1560,  1563,  1565,  1566,  8111, -1702, -1702,  8111,
   -1702, -1702, -1702,  8111, -1702,  8111,  8111,  8111,   -37,  1567,
    1568,  1569,  1570,  1573,  1571,  1572, -1702, -1702,  8111, -1702,
   -1702,  8111,   -37,  1574,  1575,  1576,  8111,  8111,  8111,  1577,
    1578,  1579,  8111,  8111, -1702,  1580,  1581,  8111,  8111,  1582,
    1583,  8111,  8111,  1585,  1590, -1702, -1702
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  Parser::yydefact_[] =
  {
         2,     0,     0,     0,     0,     0,    21,    65,    66,     0,
       0,     0,    69,    70,     0,     0,     0,   213,   218,    41,
      20,     0,   288,     0,    87,    75,     0,     0,     0,     0,
       0,     0,    86,     0,     0,   207,   217,   531,   415,   282,
     411,   538,   495,   539,   533,   534,   536,   535,   537,   540,
     414,   532,   541,     0,     0,     0,    43,    46,    44,    45,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   175,   176,   209,
     177,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,     0,
       0,     0,     0,     0,   219,   220,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   215,     0,    42,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   181,   182,   183,     0,     0,     0,
       0,     4,     8,    10,    14,    16,    18,    12,     0,   412,
     416,     0,   284,   410,   417,   419,   424,   433,   453,   457,
     460,   461,   466,   469,   471,   472,   474,   476,   478,   480,
     482,   489,    40,   420,   418,     0,   542,   413,   543,    39,
     425,     0,     0,     0,   414,     0,     0,     0,   284,   428,
     284,   436,   435,     0,     0,     0,    67,   267,    68,    71,
       0,     0,     0,     0,   285,   269,    78,    81,    76,    93,
      90,    91,    92,    89,    88,    77,    96,    97,    98,     0,
      85,     0,     0,     0,     0,     0,     0,     0,    35,   102,
       0,     0,   545,   546,   538,   547,   539,   540,   544,   532,
     541,   548,   551,   549,   550,    83,    84,     0,     0,     0,
     437,   438,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,   507,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   439,   440,   445,   446,   447,   448,   449,
     451,   450,   441,   442,   443,   444,   452,     0,    25,     0,
     215,   215,    37,     0,    38,     0,     0,     0,     0,    31,
      29,   215,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     3,     5,     9,    11,
      15,    17,    19,    13,     0,     6,     0,     0,     0,     0,
     189,     0,     0,   429,   430,   431,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   423,     0,     0,     0,     0,     0,     0,     0,
       0,   364,   365,     0,     0,     0,     0,   137,     0,     0,
       0,     0,   142,   143,     0,   126,     0,   134,     0,     0,
       0,     0,     0,   123,   124,     0,     0,    99,     0,     0,
      64,     0,   179,     0,     0,     0,     0,     0,     0,   268,
       0,   268,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     111,   112,     0,   113,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   284,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   284,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   506,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   216,    26,
       0,    36,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,   263,     0,   267,     0,   210,
       0,   555,     0,   100,   101,     0,   116,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   281,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,     0,
       0,   538,   539,     0,   194,   190,     0,   426,   454,   455,
     456,   458,   459,   463,   462,   464,   465,   467,   468,   470,
     473,   475,   477,     0,   479,   484,   485,   486,   487,   488,
     483,     0,     0,    55,     0,     0,     0,   538,   490,     0,
     271,   274,     0,    51,    57,    53,     0,     0,   434,     0,
       0,    73,    74,     0,     0,   211,   212,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    95,     0,     0,     0,   180,   283,     0,
      47,     0,   245,   247,     0,     0,   248,   249,     0,   250,
       0,     0,     0,     0,   324,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   325,     0,     0,
       0,     0,     0,     0,   347,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   309,   310,   311,     0,   313,
       0,     0,     0,     0,     0,   320,     0,     0,   241,     0,
     246,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   327,     0,   510,   511,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   508,
       0,     0,   286,   287,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     390,   169,   170,     0,     0,   243,     0,     0,   501,     0,
       0,     0,     0,     0,   305,   307,   421,     0,   496,   360,
     361,   362,   363,   257,     0,     0,     0,   172,     0,   215,
     187,   214,   215,    27,   260,   261,   262,     0,   174,   196,
     196,     0,    33,   394,     0,     0,     0,     0,     0,     0,
     519,     0,     0,     0,   401,     0,   403,     0,     0,     0,
       0,     0,     0,   405,   406,   119,     0,     0,     0,     0,
       0,     0,     0,   391,     0,     0,     0,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   192,   427,
       0,   432,     0,     0,     0,    50,    49,     0,     0,     0,
       0,     0,     0,     0,     0,   283,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,   215,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   284,     0,   284,     0,
       0,     0,     0,     0,     0,     0,   195,   191,   481,     0,
       0,     0,     0,   491,     0,     0,     0,     0,    52,     0,
       0,     0,   208,     0,   127,     0,   122,   129,     0,     0,
       0,     0,   125,     0,   135,     0,   130,     0,     0,     0,
     133,   264,   265,   266,     0,    56,    82,    48,   422,     0,
       0,     0,   297,     0,     0,     0,   323,   326,   328,   329,
       0,   330,   167,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   240,   308,     0,     0,     0,     0,
       0,     0,   321,   322,     0,   256,     0,   292,   293,   294,
       0,     0,     0,     0,   150,     0,     0,     0,   156,     0,
       0,   513,   366,   367,   368,   369,     0,     0,     0,     0,
       0,   509,   409,   375,     0,     0,     0,     0,     0,     0,
     380,   381,   382,   383,   384,   385,   386,   387,     0,     0,
       0,     0,   497,     0,   498,   502,   503,   504,   505,     0,
     494,     0,     0,     0,   215,   188,    24,    28,     0,   200,
     201,   197,   199,   198,   215,     0,   215,     0,   395,     0,
       0,   396,     0,     0,   520,     0,     0,     0,   400,   402,
       0,     0,     0,     0,   404,     0,   178,     0,     0,   221,
       0,     0,     0,   227,   110,     0,   109,     0,   117,   118,
       0,   163,     0,   165,   166,   105,     0,     0,     0,   103,
       0,     0,   193,   258,     0,    54,   493,     0,    60,    58,
       0,   554,     0,     0,   284,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   251,   252,   253,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   284,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   255,     0,     0,     0,     0,
       0,   267,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    34,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   553,     0,     0,     0,     0,     0,    72,     0,
     291,     0,   128,     0,     0,     0,     0,   136,   131,   144,
       0,    63,     0,   298,     0,   299,     0,     0,     0,     0,
     168,   333,     0,   336,     0,   338,     0,   340,     0,     0,
       0,     0,   370,     0,     0,     0,     0,     0,     0,   348,
       0,     0,     0,     0,     0,     0,     0,   358,     0,     0,
       0,     0,     0,     0,     0,   295,   296,   145,     0,   147,
       0,     0,   151,     0,     0,     0,     0,     0,     0,     0,
       0,   408,   376,     0,     0,     0,     0,     0,   388,     0,
       0,     0,   499,   500,   171,     0,     0,   215,    22,     0,
      32,   205,   206,   203,   204,   202,    30,     0,     0,   399,
       0,   521,     0,   522,     0,     0,   186,     0,     0,     0,
       0,   222,     0,     0,   226,     0,    79,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    61,    59,    62,
       0,     0,     0,     0,     0,     0,     0,   254,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   425,     0,   425,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   289,     0,
     121,     0,     0,     0,   141,     0,   300,   301,     0,     0,
       0,   332,     0,   335,     0,     0,     0,     0,     0,   306,
       0,     0,     0,     0,     0,     0,     0,   349,     0,   351,
     353,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     318,     0,     0,   146,   148,     0,   152,     0,     0,   161,
     512,     0,     0,   516,     0,     0,   160,     0,     0,   377,
     378,     0,   389,   242,   244,   392,   393,    23,     0,     0,
       0,   304,     0,     0,     0,     0,     0,     0,     0,   224,
     225,     0,     0,   162,   164,   106,   107,   223,   104,     0,
     259,   492,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   552,   290,   138,
     139,   140,     0,   302,   303,     0,   334,   337,   339,   341,
     344,     0,   372,     0,   374,     0,   342,   345,     0,   350,
     352,   354,   355,     0,   357,   312,   314,   315,     0,     0,
     319,     0,   149,   155,     0,     0,     0,     0,     0,   159,
       0,   379,     0,   397,     0,   523,     0,     0,     0,     0,
       0,     0,     0,     0,   108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   343,   373,   371,     0,   356,     0,     0,
     359,     0,     0,     0,   518,     0,     0,     0,     0,     0,
       0,   527,     0,   528,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   132,
     331,   346,   316,     0,   153,     0,   514,     0,     0,     0,
     158,     0,     0,     0,   524,   525,     0,   529,     0,     0,
       0,     0,    80,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   154,   515,     0,
     173,   157,   407,     0,   526,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   317,   517,     0,   530,
     120,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   185,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   398,   184
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
     -1702, -1702, -1702,  -183,   948,   981,  1049, -1702, -1702,  1113,
    1345,  1346,  1347, -1702, -1702,  -332, -1702,  -509, -1702, -1702,
   -1702,   -10,  2071,  2511,    21,  1937, -1702, -1702, -1702,     8,
     760,    15,  -333, -1702,  -413,  -210,   182, -1702,   213,   298,
     250,   293,   353,  -248,  -123,  2255,   271, -1702, -1702,   -22,
   -1702,   -49,   729,     3, -1702,  -216, -1701
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,   259,   260,   261,   262,   263,   264,   808,   807,   265,
     266,   267,   268,  1089,   873,  1304,   269,   518,   519,  1091,
     270,   316,   658,   324,   271,   310,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   317,   914,   293,   294,   295,
     296,   297,   298,   363,   364,   365,   300
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char Parser::yytable_ninf_ = -1;
  const unsigned short int
  Parser::yytable_[] =
  {
       318,   319,   334,   299,   362,     6,   520,   652,   346,   309,
    1152,   799,   800,   591,    39,   645,   646,   311,   312,    20,
     906,   343,   810,   796,    39,   313,   326,   348,   305,  1846,
    1848,  1850,   581,   582,   601,     6,   838,   839,   305,   621,
     622,   320,   522,  1179,   593,   594,   595,   596,   597,    20,
     579,   580,   570,   908,   571,   602,  1197,  1582,   572,  1353,
     608,    39,    39,   839,    37,   598,   610,  1011,   567,   840,
     841,   315,    37,  1529,   568,   305,   305,   557,   371,  1530,
     839,  1801,  1531,   611,   529,   565,   321,  1802,   566,   923,
    1803,   592,   344,   345,   608,   592,   841,   611,   322,   347,
     610,  1724,   566,    37,   352,    39,   353,   842,   354,   355,
     356,    44,    45,    46,    47,    48,   357,   358,   359,   360,
     653,   608,  1065,   608,  1541,   619,   620,   610,   373,   610,
     374,   583,   584,   339,   608,  1543,   843,   341,   573,   574,
     610,   844,   845,   846,   847,   848,   329,   575,   599,    37,
     608,   655,  1130,   342,   600,  1132,   609,   330,   331,   332,
     333,  1299,  1300,    39,  1301,  1302,   608,  1303,   883,   884,
     885,   886,   610,   362,   849,   850,   851,   305,   352,    39,
     353,   349,   354,   355,   356,    44,    45,    46,    47,    48,
     357,   358,   359,   360,   350,  1005,  1650,  1651,   517,  1652,
    1653,  1006,  1654,   576,   577,   608,  1690,  1027,   578,   530,
     531,   610,  1039,  1028,   521,   585,   586,  1130,  1040,  1131,
    1132,   503,   504,   505,   506,   507,   508,   509,   510,   511,
     512,   513,   514,   515,   516,  2022,  1068,  2023,   351,   797,
    2024,  2025,  1069,  1103,   909,  1110,   881,   882,  1114,  1104,
     367,  1111,   852,   853,  1115,  1116,   854,   368,   855,  1149,
    1364,  1117,  1374,   299,   369,  1150,  1365,  1392,  1375,   647,
     648,   649,   650,  1393,  1402,  1444,   856,  1477,  1482,  1504,
    1403,  1445,   854,  1478,  1483,  1505,   372,   327,  1506,  1514,
    1536,  1545,   362,   362,  1505,  1515,  1537,  1546,  1549,   854,
    1578,  1705,   856,   376,  1550,   377,  1579,  1706,  1711,   803,
    1713,   615,   648,   649,  1712,  1092,  1714,   375,   362,   856,
     857,   858,   859,   860,   861,   862,   863,   864,   865,   866,
     867,   868,  1715,  1717,   621,   622,  1722,  1729,  1716,  1718,
     801,   654,  1723,  1730,   617,   380,   857,   858,   859,   860,
     861,   862,   863,   864,   865,   866,   867,   868,   656,   657,
     689,   690,   691,   857,   858,   859,   860,   861,   862,   863,
     864,   865,   866,   867,   868,   887,   888,  1747,   692,   693,
     694,   834,  2121,  1748,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   621,   622,   623,   381,   624,
     625,   626,   382,   378,   627,   379,   383,   628,   629,   630,
     631,   632,   633,   634,   635,  1749,   636,   384,   401,  1908,
     637,  1750,   385,   638,   639,  1909,   640,  1917,   641,   642,
    1921,  1923,  1950,  1918,  1954,  1966,  1922,  1924,  1951,  1970,
    1955,  1967,  2072,  2105,  2154,  1971,  2161,  2194,  2073,  2106,
    2155,  2200,  2162,  2195,  2205,  2207,   428,  2201,   429,   386,
    2206,  2208,  1187,   387,  1188,   388,   769,   770,   389,   772,
     895,   896,   897,   898,   899,   900,   362,   390,   391,   392,
     784,   393,   785,   394,   395,   396,   397,   398,   399,   400,
     555,   403,   404,   405,   406,   407,   402,   408,   409,   410,
     411,   412,   413,   802,   414,   415,   416,   417,   418,   419,
     313,   420,   421,   422,   423,   424,   425,   426,   427,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   824,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     877,   460,   461,   462,   463,   464,   465,   836,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   875,   481,   482,   483,   869,   484,   485,
    1296,   486,   487,  1297,   488,   492,   493,   494,   495,   901,
     496,   878,   879,   880,   497,   916,   498,   499,   917,   500,
     501,   502,   525,   526,   527,   528,   532,   533,   534,   535,
     536,   538,   651,   539,   540,   541,   542,  1093,   537,   543,
     544,   545,   546,   547,   548,   549,   918,  1102,   550,   551,
     552,   553,   554,   566,   590,   569,   816,   587,   902,   588,
     605,   603,   604,   606,  1101,   607,   589,   612,   835,   613,
     689,   737,   738,   743,   921,   747,   927,   809,   749,   919,
     755,   756,   920,   922,   924,   925,   926,   928,   929,   930,
     931,   932,   933,   934,   935,   692,   936,   937,   938,   939,
     940,   941,   944,   945,   946,  1294,  1190,  1353,   948,   798,
     806,   950,   952,   949,   951,   953,   954,   956,   955,   830,
     957,   776,   778,   958,   779,   959,   960,   964,   961,   962,
    1181,  1182,   963,  1306,   965,   966,   967,   968,   969,   970,
     971,   972,   973,   974,   975,   976,   977,   978,   979,   980,
     981,   982,   983,   985,   984,   986,   987,   988,  1646,  1499,
    1099,   989,   990,   991,   992,   993,   994,   995,   996,   997,
     998,   999,  1000,  1354,   856,  1192,  1001,  1008,  1002,  1003,
    1004,  1007,  1009,  1010,  1012,  1013,  1014,  1015,  1305,   889,
    1016,  1017,  1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,
    1026,  1029,  1030,  1031,  1575,  1032,  1088,  1033,  1034,  1035,
    1036,  1037,  1038,  1041,  1042,  1043,  1044,  1507,  1045,  1046,
    1687,   890,  1047,  1048,  1049,  1050,  1051,  1052,  1053,  1054,
    1055,  1056,  1057,  1058,  1059,  1060,  1061,  1062,  1063,  1064,
    1066,  2188,   370,  1074,  1067,  1070,  1071,  1072,  1073,  1075,
    1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1359,  1551,
     892,  1087,  1094,  1095,  1084,  1085,  1086,  1096,  1098,  1100,
    1097,  1105,  1106,  1109,  1500,  1107,  1501,  1108,  1112,  1113,
    1123,  1118,  1119,  1120,  1121,  1122,  1124,  1125,  1126,  1127,
    1128,  1129,  1133,  1134,  1135,  1136,  1138,  1139,  1140,  1141,
    1142,  1143,  1144,  1145,  1146,   894,  1684,   891,  1154,  1151,
    1158,  1160,  1147,  1161,  1153,  1159,  1162,  1163,  1165,  1164,
    1194,  1195,  1196,  1239,  1348,  1295,  1360,  1156,  1362,  1166,
    1366,  1361,  1363,  1168,  1169,  1367,  1372,  1170,  1171,  1368,
    1173,  1174,  1175,  1176,  1177,  1369,  1370,  1371,  1373,  1183,
    1184,  1185,  1376,  1377,  1378,  1379,  1380,  1381,  1382,  1383,
    1384,  1386,  1387,  1388,   893,  1396,  1394,  1397,  1398,  1399,
    1395,  1401,  1199,  1200,  1502,  1201,  1202,  1203,  1204,  1205,
    1400,  1207,  1208,  1209,  1210,  1211,  1212,  1404,  1213,  1405,
    1406,  1407,  1408,  1409,  1410,  1219,  1220,  1221,  1222,  1223,
    1224,  1225,  1226,  1411,  1228,  1647,  1412,  1413,  1414,  1415,
    1416,  1417,  1418,  1419,  1420,  1649,  1421,  1655,  1422,  1237,
    1423,  1424,  1425,  1240,  1241,  1242,  1426,  1432,  1245,  1246,
    1247,  1248,  1249,  1250,  1427,  1251,  1428,  1429,  1252,  1253,
    1254,  1255,  1256,  1257,  1258,  1259,  1260,  1261,  1430,  1431,
    1263,  1433,  1434,  1435,  1437,  1438,  1439,  1448,  1440,  1270,
    1271,  1272,  1273,  1274,  1275,  1276,  1277,  1278,  1279,  1280,
    1441,  1442,  1443,  1281,  1282,  1446,  1283,  1284,  1447,  1285,
    1286,  1287,  1288,  1289,  1449,  1450,  1451,  1290,  1452,  1453,
    1454,  1455,  1503,  1456,  1781,  1292,  1293,  1461,  1457,  1458,
    1459,  1460,  1462,  1463,  1464,  1465,  1466,  1298,  1470,  1471,
    1467,  1468,  1469,  1472,  1307,  1308,  1473,  1310,  1311,  1474,
    1475,  1313,  1314,  1315,  1476,  1316,  1704,  1317,  1479,  1319,
    1320,  1480,  1481,  1496,  1497,  1484,  1323,  1485,  1486,  1487,
    1327,  1328,  1329,  1488,  1490,  1331,  1489,  1491,  1492,  1508,
    1335,  1337,  1339,  1340,  1341,  1342,  1343,  1493,  1498,  1509,
    1510,  1511,  1512,  1349,  1350,  1513,  1516,  1351,  1517,  1518,
    1519,  1355,  1356,  1347,  1520,  1344,  1524,  1521,  1522,  1523,
    1525,  1526,  1533,  1527,  1528,  1532,  1534,  1538,  1539,  1535,
    1540,  1542,  1544,  1553,  1556,  1547,  1548,  1554,  1555,  1558,
    1559,  1557,  1576,  1560,  1577,  1615,  1688,  1685,  1782,  1686,
    1692,  1783,  1784,  1689,  1691,  1693,  1697,  1694,  1695,  1696,
    1698,  1699,  1701,  1700,  1703,  1707,  1710,  1180,   558,  1708,
       0,  1709,     0,  1719,  1720,  1721,  1725,  1726,  1727,  1728,
    1731,  1732,  1733,  1734,  1735,  1736,  1737,  1738,  1739,  1740,
    1741,  1742,  1745,  1743,  1744,  1746,  1751,  1752,     0,  1753,
    1754,   559,  1755,  1761,  1756,  1757,  1758,  1759,  1760,  1762,
    1763,  1764,  1765,  1766,  1767,  1768,  1769,  1770,  1771,  1772,
    1773,  1774,  1775,  1776,  1779,  1785,  1789,  1791,  1883,  1787,
    1788,  1790,  1793,  1796,  1792,  1794,  1795,  1797,  1804,  1806,
    1798,  1799,  1800,     0,  1494,  1805,  1807,  1808,  1809,  1810,
    1811,  1812,  1813,  1814,  1815,  1816,  1819,  1827,  1910,  1911,
    1912,  1913,  1914,  1916,  1829,  1915,  1919,  1920,  1929,   560,
    1925,  1926,  1927,  1928,     0,  1930,  1931,  1932,  1933,  1934,
    1935,  1936,  1937,  1938,  1656,  1939,  1940,  1941,  1999,  1942,
    1943,   915,     0,  1944,  1945,  1946,  1947,  1948,  1949,  1952,
    1953,  1956,  1957,  1958,  1959,  1960,  2113,  1963,  1961,  1561,
       0,  1563,  1962,  1565,  1964,  1566,  1965,  1968,  1567,  1568,
    1569,  1570,  1969,  1972,  1973,  1571,  1974,  1975,  1573,  1976,
       0,  1978,  1981,   561,  1979,     0,  1980,  1982,     0,  1983,
    1984,  1985,  1986,  1987,  1988,  1584,  1989,  1990,  1991,  1992,
    1585,  1993,  1994,  1995,  1587,  1588,  1589,  1590,  1591,  1592,
    1593,  1594,  1596,  1597,  1598,  1599,  1600,  1601,  1602,  1603,
    1604,  1605,  1606,  1607,  1580,  1996,  1608,  1997,  1998,  2000,
    2001,  2058,  2059,  2060,  1614,  2061,  2063,  2064,     0,  2066,
    1616,  1617,  1618,  1619,  2062,  1620,  1622,  1623,  2065,  1624,
    1625,  2067,  2068,  2069,  2070,  2071,  1626,  1627,  1628,  1629,
    2074,  2075,  2076,  2077,  2078,  1632,  2079,  2080,  1635,  1636,
    2081,  2082,  2084,  2085,  1778,  2083,  1780,  2086,  1637,  1638,
    1639,  1640,  1786,  2087,  2088,  2089,  2090,  2091,  2092,  2093,
    2094,  1643,  1644,  1645,     0,  2099,  2095,  2096,  1648,  2097,
    2098,  2101,  2100,  2102,  2103,  2104,  2107,  2114,  2108,  1657,
    1658,  2109,  1659,  1660,  2110,  1661,  1662,  1663,  2111,  2112,
    2141,  1665,  1666,  2142,  2143,  1668,  2144,  2145,  1670,  2146,
    1671,  1672,  1673,  2147,  2148,  2149,  2150,  1675,  2151,     0,
    1676,  2152,  1677,  2153,  2156,  2157,  1678,  1679,  1680,  2158,
    1681,  2159,  2160,  2163,  1683,  2164,  2165,  2166,  2167,  2168,
    2189,  2190,  2191,  2192,  2193,  2196,     0,     0,     0,  1682,
    2197,  2204,  2198,  2199,  2202,  2203,  2209,  2227,  2210,  1702,
    2211,  2226,  2228,  2230,  2229,  2231,  2232,  2233,  2234,     0,
    2235,  2246,  2247,  2236,  2249,  2237,  2238,  2250,     0,  2248,
       0,  2251,  2252,  2264,  2256,  2257,  2258,  2262,  2263,  2275,
    2267,  2268,  2271,  2272,  2276,   562,   563,   564,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1777,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1820,
       0,  1821,     0,  1822,  1823,  1824,  1825,     0,     0,     0,
    1826,     0,     0,     0,     0,     0,     0,     0,  1830,  1831,
    1977,     0,  1832,     0,  1833,     0,  1834,     0,  1835,  1836,
    1837,  1838,     0,  1839,  1840,  1841,  1842,  1843,  1844,     0,
    1845,  1847,     0,  1851,  1852,  1853,  1854,  1828,  1855,  1856,
    1857,  1858,  1859,     0,  1861,     0,     0,     0,     0,     0,
    1849,     0,     0,     0,  1866,  1867,  1868,  1869,  1870,  1871,
    1872,     0,     0,  1873,     0,     0,  1876,  1877,     0,  1878,
    1879,  1880,     0,     0,     0,  1881,  1882,     0,     0,  1884,
       0,     0,     0,     0,     0,     0,     0,  1885,  1886,     0,
    1887,     0,     0,     0,  1889,  1890,     0,  1891,  1892,     0,
    1894,     0,  1895,  1896,     0,  1897,     0,  1898,  1899,  1900,
    1901,  1902,  1903,  1904,     0,  1906,  1907,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1905,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2002,
       0,  2003,  2004,  2005,     0,  2006,     0,     0,     0,  2008,
    2009,     0,  2010,     0,  2011,  2012,  2013,  2014,  2015,     0,
    2016,  2017,  2018,  2019,  2020,  2021,     0,     0,     0,     0,
       0,     0,     0,  2026,  2027,  2028,     0,   272,   308,  2007,
       0,  2033,  2034,     0,  1849,  2035,  1849,  2036,  2037,  1849,
    1849,  2038,  2039,     0,  2040,  2041,     0,     0,     0,     0,
     328,  2044,     0,   335,     0,     0,     0,     0,  2045,  2046,
    2047,     0,     0,  2049,  2050,  2051,  2052,     0,  2054,     0,
       0,  2055,  2056,     0,     0,     0,     0,     0,     0,     0,
     361,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2057,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2115,     0,     0,  2116,     0,     0,     0,     0,
       0,  2117,     0,  2118,     0,  2119,     0,     0,  2120,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2122,  2123,
       0,  2124,     0,     0,  2125,  2126,  2127,  2128,  2129,     0,
       0,  1849,  2131,     0,  2132,     0,     0,  2134,  2135,  2136,
    2137,     0,  2139,  2140,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2169,  2170,     0,     0,     0,  2171,     0,  2172,  2173,
       0,  2174,  2175,  2176,     0,  2177,  2178,     0,  2180,  2181,
    2182,     0,  2183,     0,  2184,  2185,     0,  2187,     0,   361,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2213,     0,     0,     0,  2215,  2216,  2217,
       0,     0,  2219,  2220,     0,     0,  2221,   272,     0,  2223,
    2224,  2225,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2239,     0,     0,  2240,
       0,     0,     0,  2241,     0,     0,  2243,  2244,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2253,     0,
       0,  2254,     0,     0,     0,     0,  2259,  2260,  2261,     0,
       0,     0,  2265,  2266,     0,   292,     0,  2269,  2270,   314,
       0,  2273,  2274,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   325,     0,   361,   361,
       0,     0,   336,   337,   325,     0,   325,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   361,     0,     0,     0,     0,   325,
       0,     0,     0,     0,     0,     0,     0,   668,     0,     0,
     671,   672,   673,   674,   675,     0,   677,   678,   679,   680,
     681,   682,   683,   684,   685,     0,     0,   688,     0,     0,
     695,   696,   697,   698,   699,   700,   701,   702,   703,   704,
       0,   706,   707,   708,   709,   710,   711,   712,   713,   714,
     715,   716,   717,   718,   719,   721,     0,     0,     0,     0,
       0,     0,   728,   729,   730,   731,   732,   733,   734,   735,
     736,     0,     0,   739,   740,   741,   742,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   752,   753,   754,     0,
       0,   757,   758,   759,   760,   761,   762,   763,   764,   765,
     766,   767,     0,     0,     0,   771,   773,     0,   775,     0,
     777,     0,     0,     0,   781,   782,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   325,     0,     0,   795,
       0,     0,     0,     0,   660,   662,   663,   664,   665,   666,
     667,     0,   669,   670,     0,     0,     0,     0,     0,   676,
       0,     0,   361,     0,     0,     0,     0,     0,     0,   686,
     687,   813,     0,     0,     0,     0,     0,     0,     0,     0,
     325,   325,     0,     0,   705,     0,     0,     0,     0,   831,
     832,   833,     0,     0,     0,     0,     0,     0,     0,   720,
     722,   723,   724,   725,   726,   727,   308,     0,     0,     0,
       0,     0,     0,     0,     0,   292,     0,     0,     0,     0,
       0,     0,   744,   745,   746,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     338,     0,   340,     0,     0,     0,   768,     0,     0,     0,
       0,   774,     0,     0,     0,     0,   314,   780,     0,     0,
       0,     0,     0,     0,     0,   366,     0,     0,     0,     0,
     792,   793,   794,     0,     0,   325,     0,   325,   314,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   325,     0,     0,     0,   805,   643,
     644,     0,     0,   811,   812,     0,   814,   815,     0,   817,
     818,   819,   820,   821,   822,   823,     0,   825,   826,   827,
       0,     0,     0,     0,     0,     0,     0,   659,   661,   659,
     659,   659,   659,   659,   659,     0,   659,   659,     0,     0,
       0,     0,     0,   659,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   659,   659,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   659,     0,
       0,     0,   903,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   659,   659,   659,   659,   659,   659,   659,
       0,     0,   491,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   659,   659,   659,     0,
     325,     0,   325,   325,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     659,     0,     0,     0,     0,   659,   523,   524,     0,     0,
       0,   659,     0,     0,   314,     0,     0,     0,   786,   787,
     788,   789,   790,   325,   659,   659,   659,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   325,   659,     0,     0,     0,     0,   659,   659,     0,
     659,   659,     0,   659,   659,   659,   659,   659,   659,   659,
       0,   659,   659,   659,   325,   325,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   837,     0,     0,   874,   876,     0,     0,     0,
       0,   614,     0,   616,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     618,     0,     0,     0,     0,     0,   659,   913,     0,     0,
       0,     0,     0,   837,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1198,     0,
     942,   943,     0,     0,     0,     0,     0,  1206,   325,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1216,  1217,
    1218,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1227,     0,     0,     0,     0,  1229,     0,  1230,  1231,  1232,
    1233,  1234,     0,  1235,  1236,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   748,     0,   750,   751,
       0,     0,     0,     0,     0,  1262,     0,     0,     0,     0,
       0,  1265,  1266,  1267,  1268,  1269,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   791,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   804,     0,     0,
       0,     0,     0,  1309,     0,     0,  1312,     0,     0,     0,
    1214,  1215,   325,     0,     0,     0,     0,     0,     0,     0,
     828,   829,     0,     0,     0,  1325,  1326,     0,     0,     0,
       0,     0,     0,  1332,     0,  1333,  1334,  1336,  1338,     0,
       0,     0,  1238,     0,   308,     0,     0,  1243,  1244,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     325,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1148,     0,     0,     0,     0,
       0,     0,  1390,  1391,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1155,
     325,     0,     0,     0,   947,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   325,     0,     0,     0,     0,
       0,     0,     0,     0,  1172,     0,     0,     0,     0,  1318,
    1178,     0,  1321,  1322,     0,     0,     0,     0,     0,   325,
       0,   325,     0,     0,   325,     0,     0,     0,     0,  1193,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   659,   659,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1385,     0,     0,     0,  1389,   659,     0,     0,     0,
       0,   659,   659,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   325,     0,  1564,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1090,     0,
    1436,     0,     0,     0,  1572,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1581,  1583,     0,     0,     0,     0,     0,     0,     0,   325,
    1586,     0,     0,     0,     0,     0,     0,     0,  1595,     0,
       0,     0,     0,     0,     0,     0,  1137,     0,     0,     0,
       0,     0,     0,     0,  1609,  1610,  1611,  1612,  1613,     0,
       0,     0,     0,   659,     0,     0,   659,   659,     0,     0,
       0,     0,   325,     0,     0,     0,     0,     0,     0,   325,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1633,  1634,  1346,     0,     0,     0,     0,
       0,     0,     0,   325,     0,     0,     0,     0,   325,   325,
    1641,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1167,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   659,     0,     0,     0,   659,
    1574,     0,     0,     0,     0,  1186,     0,  1189,     0,     0,
    1191,     0,     0,     0,  1669,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   308,     0,
       0,     0,     0,     0,   659,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1630,     0,     0,     0,  1631,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     325,     0,  1264,     0,     0,     0,     0,     0,     0,     0,
    1642,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1664,     0,     0,  1667,  1291,     0,     0,     0,     0,
    1552,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   325,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   659,     0,     0,     0,  1324,     0,
       0,     0,     0,  1581,     0,  1330,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1352,
       0,     0,     0,     0,  1357,  1358,     0,     0,     0,     0,
    1860,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1621,  1874,  1875,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   659,     0,     0,     0,   659,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1893,     0,     0,     0,
       0,     0,     0,     0,   659,     0,     0,     0,     0,     0,
       0,   308,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   659,     0,     0,   659,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1674,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1495,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1862,
       0,  1863,  1864,     0,  1865,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1581,     0,     0,     0,     0,
       0,     0,     0,  1888,     0,     0,     0,     0,     0,     0,
       0,  1562,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2029,  2030,  2031,  2032,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2043,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2053,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   308,     0,     0,     0,
     325,   325,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   659,     0,   659,   659,     0,   659,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2130,  2042,     0,
       0,     0,     0,     0,     0,     0,     0,   659,  2138,     0,
       0,     0,     0,  2048,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2179,     0,     0,     0,     0,     0,
       0,     0,     0,  2186,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2245,     0,  2133,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2255,
       0,     0,     0,     0,     0,     0,  1817,  1818,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   659,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   659,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2212,
       0,     0,     0,     0,     0,     0,  2214,     0,     0,     0,
       0,     0,  2218,     0,     0,     0,     0,     0,     0,  2222,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2242,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   556,     0,     0,     0,     0,
       0,   659,     0,     0,     1,     2,     3,     0,     4,     0,
       0,     0,     0,     0,     0,     0,     0,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,     0,     0,    23,    24,    25,
      26,    27,    28,    29,     0,    30,    31,    32,     0,    33,
      34,    35,     0,    36,    37,    38,    39,    40,     0,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,     0,    56,    57,    58,    59,    60,
      61,     0,     0,   659,     0,     0,     0,     0,     0,     0,
     659,     0,     0,     0,    62,    63,   659,     0,     0,     0,
       0,     0,     0,   659,     0,     0,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,     0,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
     659,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,     0,     0,
       0,   104,   105,     0,     0,     0,     0,     0,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,     0,     0,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,     0,     0,   173,
     174,   175,   176,   177,   178,   179,   180,   181,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   182,   183,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,     0,   199,
     200,   201,   202,   203,     0,     0,     0,     0,     0,   204,
     205,   206,   207,   208,   209,   210,   211,     0,     0,   212,
     213,   214,   215,   216,   217,   218,   219,   220,     0,     0,
       0,     0,   221,     0,   222,   223,   224,     0,     0,     0,
     225,   226,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   227,   228,   229,   230,     0,     0,
       0,     0,     0,     0,     0,   231,   232,     0,   233,   234,
     235,   236,     0,   237,   238,     0,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,     1,     2,     3,     0,
       4,     0,     0,     0,     0,     0,     0,     0,     0,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,     0,     0,    23,
      24,    25,    26,    27,    28,    29,     0,    30,    31,    32,
       0,    33,    34,    35,     0,    36,    37,    38,    39,    40,
       0,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,     0,    56,    57,    58,
      59,    60,    61,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    62,    63,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,     0,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,     0,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
       0,     0,     0,   104,   105,     0,     0,     0,     0,     0,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,     0,
       0,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,     0,
       0,   173,   174,   175,   176,   177,   178,   179,   180,   181,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   182,   183,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
       0,   199,   200,   201,   202,   203,     0,     0,     0,     0,
       0,   204,   205,   206,   207,   208,   209,   210,   211,     0,
       0,   212,   213,   214,   215,   216,   217,   218,   219,   220,
       0,     0,     0,     0,   221,     0,   222,   223,   224,     0,
       0,     0,   225,   226,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   227,   228,   229,   230,
       0,     0,     0,     0,     0,     0,     0,   231,   232,     0,
     233,   234,   235,   236,     0,   237,   238,     0,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,     1,     2,
       3,     0,     4,     0,     0,     0,   904,     0,     0,     0,
       0,     5,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    17,    18,     0,     0,   905,    22,     0,
     906,     0,     0,     0,     0,     0,     0,     0,     0,    30,
       0,     0,     0,    33,    34,    35,     0,    36,     0,    38,
      39,    40,     0,   907,    42,   872,    44,    45,    46,    47,
      48,   357,   304,   908,   360,     0,     0,     0,     0,     0,
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
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,     0,     0,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,     0,     0,   170,   171,
     172,     0,     0,   173,   174,   175,   176,   177,   178,   179,
     180,   181,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   909,   182,   183,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   184,   185,   186,
     187,   188,   910,   190,   191,   911,   193,   194,   195,   196,
     197,   198,     0,   199,     0,   201,   202,     0,   912,     0,
       0,     0,     0,   204,   205,   206,   207,   208,   209,   210,
     211,     0,     0,   212,   213,   214,   215,   216,   217,   218,
     219,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   227,   228,
     229,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   233,   234,   235,   236,     0,   237,   238,     0,
     239,   240,   241,   242,   243,   244,   245,     0,   247,   248,
     249,   250,     1,     2,     3,     0,     4,     0,     0,     0,
     870,     0,     0,     0,     0,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    17,    18,     0,
       0,    21,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    30,     0,     0,     0,    33,    34,    35,
       0,    36,     0,    38,    39,    40,     0,   871,    42,   872,
      44,    45,    46,    47,    48,   357,   304,   359,   360,     0,
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
     148,   149,   150,   151,   152,     0,     0,     0,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
       0,     0,   170,   171,   172,     0,     0,   173,   174,   175,
     176,   177,   178,   179,   180,   181,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   182,
     183,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,     0,   199,     0,   201,
     202,     0,     0,     0,     0,     0,     0,   204,   205,   206,
     207,   208,   209,   210,   211,     0,     0,   212,   213,   214,
     215,   216,   217,   218,   219,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   227,   228,   229,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   233,   234,   235,   236,
       0,   237,   238,     0,   239,   240,   241,   242,   243,   244,
     245,     0,   247,   248,   249,   250,     1,     2,     3,     0,
       4,     0,     0,     0,  1345,     0,     0,     0,     0,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    17,    18,     0,     0,    21,    22,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    30,     0,     0,
       0,    33,    34,    35,     0,    36,     0,    38,    39,    40,
       0,   871,    42,   872,    44,    45,    46,    47,    48,   357,
     304,   359,   360,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    62,    63,     0,     0,
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
     144,   145,   146,   147,   148,   149,   150,   151,   152,     0,
       0,     0,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,     0,     0,   170,   171,   172,     0,
       0,   173,   174,   175,   176,   177,   178,   179,   180,   181,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   182,   183,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
       0,   199,     0,   201,   202,     0,     0,     0,     0,     0,
       0,   204,   205,   206,   207,   208,   209,   210,   211,     0,
       0,   212,   213,   214,   215,   216,   217,   218,   219,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   227,   228,   229,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     233,   234,   235,   236,     0,   237,   238,     0,   239,   240,
     241,   242,   243,   244,   245,     0,   247,   248,   249,   250,
       1,     2,     3,     0,     4,     0,     0,     0,     0,     0,
       0,     0,     0,     5,     6,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    17,    18,     0,    20,    21,
      22,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    30,     0,     0,     0,    33,    34,    35,     0,    36,
       0,    38,    39,    40,     0,   302,    42,   303,    44,    45,
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
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,     0,     0,     0,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,     0,     0,
     170,   171,   172,     0,     0,   173,   174,   175,   176,   177,
     178,   179,   180,   181,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   182,   183,     0,
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
       0,     0,     0,     0,     0,     0,     0,     5,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    17,
      18,     0,     0,    21,    22,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    30,     0,     0,     0,    33,
      34,    35,     0,    36,     0,    38,    39,    40,     0,   871,
      42,   872,    44,    45,    46,    47,    48,   357,   304,   359,
     360,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
     146,   147,   148,   149,   150,   151,   152,     0,     0,     0,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,     0,     0,   170,   171,   172,     0,     0,   173,
     174,   175,   176,   177,   178,   179,   180,   181,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   182,   183,     0,     0,     0,     0,     0,     0,     0,
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
       3,     0,   489,     0,   490,     0,     0,     0,     0,     0,
       0,     5,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    17,    18,     0,     0,    21,    22,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    30,
       0,     0,     0,    33,    34,    35,     0,    36,     0,    38,
      39,    40,     0,   302,    42,   303,    44,    45,    46,    47,
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
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,     0,     0,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,     0,     0,   170,   171,
     172,     0,     0,   173,   174,   175,   176,   177,   178,   179,
     180,   181,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   182,   183,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,     0,   199,     0,   201,   202,     0,     0,     0,
       0,     0,     0,   204,   205,   206,   207,   208,   209,   210,
     211,     0,     0,   212,   213,   214,   215,   216,   217,   218,
     219,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   227,   228,
     229,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   233,   234,   235,   236,     0,   237,   238,     0,
     239,   240,   241,   242,   243,   244,   245,     0,   247,   248,
     249,   250,     1,     2,     3,     0,     4,   783,     0,     0,
       0,     0,     0,     0,     0,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    17,    18,     0,
       0,    21,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    30,     0,     0,     0,    33,    34,    35,
       0,    36,     0,    38,    39,    40,     0,   302,    42,   303,
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
     148,   149,   150,   151,   152,     0,     0,     0,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
       0,     0,   170,   171,   172,     0,     0,   173,   174,   175,
     176,   177,   178,   179,   180,   181,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   182,
     183,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,     0,   199,     0,   201,
     202,     0,     0,     0,     0,     0,     0,   204,   205,   206,
     207,   208,   209,   210,   211,     0,     0,   212,   213,   214,
     215,   216,   217,   218,   219,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   227,   228,   229,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   233,   234,   235,   236,
       0,   237,   238,     0,   239,   240,   241,   242,   243,   244,
     245,     0,   247,   248,   249,   250,     1,     2,     3,     0,
     323,     0,  1157,     0,     0,     0,     0,     0,     0,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    17,    18,     0,     0,    21,    22,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    30,     0,     0,
       0,    33,    34,    35,     0,    36,     0,    38,    39,    40,
       0,   302,    42,   303,    44,    45,    46,    47,    48,     0,
     304,     0,   305,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    62,    63,     0,     0,
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
     144,   145,   146,   147,   148,   149,   150,   151,   152,     0,
       0,     0,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,     0,     0,   170,   171,   172,     0,
       0,   173,   174,   175,   176,   177,   178,   179,   180,   181,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   182,   183,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
       0,   199,     0,   201,   202,     0,     0,     0,     0,     0,
       0,   204,   205,   206,   207,   208,   209,   210,   211,     0,
       0,   212,   213,   214,   215,   216,   217,   218,   219,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   227,   228,   229,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     233,   234,   235,   236,     0,   237,   238,     0,   239,   240,
     241,   242,   243,   244,   245,     0,   247,   248,   249,   250,
       1,     2,     3,     0,     4,     0,     0,     0,     0,     0,
       0,     0,     0,     5,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    17,    18,     0,     0,    21,
      22,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    30,     0,     0,     0,    33,    34,    35,     0,    36,
       0,    38,    39,    40,     0,   302,    42,   303,    44,    45,
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
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,     0,     0,     0,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,     0,     0,
     170,   171,   172,     0,     0,   173,   174,   175,   176,   177,
     178,   179,   180,   181,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   182,   183,     0,
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
     247,   248,   249,   250,     1,     2,     3,     0,   323,     0,
       0,     0,     0,     0,     0,     0,     0,     5,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    17,
      18,     0,     0,    21,    22,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    30,     0,     0,     0,    33,
      34,    35,     0,    36,     0,    38,    39,    40,     0,   302,
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
     146,   147,   148,   149,   150,   151,   152,     0,     0,     0,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,     0,     0,   170,   171,   172,     0,     0,   173,
     174,   175,   176,   177,   178,   179,   180,   181,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   182,   183,     0,     0,     0,     0,     0,     0,     0,
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
     243,   244,   245,     0,   247,   248,   249,   250,     1,     0,
       0,     0,   301,     0,     0,     0,     0,     0,     0,     0,
       0,     5,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    17,    18,     0,     0,    21,    22,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    30,
       0,     0,     0,    33,    34,    35,     0,    36,     0,    38,
      39,    40,     0,   302,    42,   303,    44,    45,    46,    47,
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
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,     0,     0,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,     0,     0,   170,   171,
     172,     0,     0,   173,   174,   175,   176,   177,   178,   179,
     180,   181,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   182,   183,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,     0,   199,     0,   201,   202,     0,     0,     0,
       0,     0,     0,   204,   205,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   227,   228,
     229,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   233,   234,   235,   236,     0,   237,   238,     0,
     239,   240,   241,   242,   243,   244,   245,   301,   247,   248,
     249,   250,     0,     0,     0,     0,     5,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    17,    18,
       0,     0,    21,    22,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    30,     0,     0,     0,    33,    34,
      35,     0,    36,     0,    38,    39,    40,     0,   302,    42,
     303,    44,    45,    46,    47,    48,     0,   304,     0,   305,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,     0,    77,
       0,    79,    80,    81,    82,    83,    84,    85,    86,     0,
       0,     0,    89,     0,    91,    92,    93,   306,   307,    96,
      97,    98,    99,   100,   101,   102,   103,     0,     0,     0,
     104,   105,     0,     0,     0,     0,     0,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,     0,     0,
       0,     0,     0,     0,   133,     0,     0,     0,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,     0,     0,     0,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,     0,     0,   170,   171,   172,     0,     0,   173,   174,
     175,   176,   177,   178,   179,   180,   181,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     182,   183,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,     0,   199,     0,
     201,   202,     0,     0,     0,     0,     0,     0,   204,   205,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   227,   228,   229,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   301,   233,   234,   235,
     236,     0,   237,   238,     0,   239,   240,   241,   242,   243,
     244,   245,     0,   247,   248,   249,   250,    17,    18,     0,
       0,    21,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    30,     0,     0,     0,    33,    34,    35,
       0,    36,     0,    38,    39,    40,     0,   302,    42,   303,
      44,    45,    46,    47,    48,     0,   304,     0,   305,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
     148,   149,   150,   151,   152,     0,     0,     0,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
       0,     0,   170,   171,   172,     0,     0,   173,   174,   175,
     176,   177,   178,   179,   180,   181,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   182,
     183,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,     0,   199,     0,   201,
     202,     0,     0,     0,     0,     0,     0,   204,   205,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   227,   228,   229,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   233,   234,   235,   236,
       0,   237,   238,     0,   239,   240,   241,   242,   243,   244,
     245,     0,   247,   248,   249,   250
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
        10,    11,    24,     0,    53,    23,   222,    46,    19,     1,
      22,   520,   521,    21,    61,    46,    47,     2,     3,    37,
      41,    19,   531,   110,    61,     4,    73,    49,    75,  1730,
    1731,  1732,     5,     6,    89,    23,    53,    54,    75,   243,
     244,    13,   225,    64,    89,    90,    91,    92,    93,    37,
      10,    11,    13,    74,    15,   110,    56,    56,    19,   263,
      13,    61,    61,    54,    59,   110,    19,    20,    13,    86,
      87,    20,    59,    14,    19,    75,    75,   260,    63,    20,
      54,    14,    23,    14,    71,   268,    13,    20,    19,    20,
      23,   103,    90,    91,    13,   103,    87,    14,    13,   110,
      19,    20,    19,    59,    60,    61,    62,   124,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
     159,    13,    14,    13,    14,   341,   342,    19,    13,    19,
      15,   104,   105,    13,    13,    14,   153,    13,    99,   100,
      19,   158,   159,   160,   161,   162,    56,   108,    13,    59,
      13,   367,    20,    13,    19,    23,    19,    67,    68,    69,
      70,   353,   354,    61,   356,   357,    13,   359,   581,   582,
     583,   584,    19,   222,   191,   192,   193,    75,    60,    61,
      62,   158,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    19,    14,   353,   354,   220,   356,
     357,    20,   359,     7,     8,    13,    14,    14,    12,   231,
     232,    19,    14,    20,   224,   106,   107,    20,    20,    22,
      23,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,  1936,    14,  1938,    15,   326,
    1941,  1942,    20,    14,   265,    14,   579,   580,    14,    20,
      13,    20,   269,   270,    20,    14,   273,    13,   275,    14,
      14,    20,    14,   260,    13,    20,    20,    14,    20,   300,
     301,   302,   303,    20,    14,    14,   293,    14,    14,    14,
      20,    20,   273,    20,    20,    20,    13,   334,    14,    14,
      14,    14,   341,   342,    20,    20,    20,    20,    14,   273,
      14,    14,   293,    13,    20,    15,    20,    20,    14,   525,
      14,   321,   301,   302,    20,   333,    20,    13,   367,   293,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,    14,    14,   243,   244,    14,    14,    20,    20,
     523,   351,    20,    20,   323,    13,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   368,   369,
     153,   154,   155,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   585,   586,    14,   153,   154,
     155,   564,  2083,    20,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   243,   244,   245,    13,   247,
     248,   249,    13,    13,   252,    15,    13,   255,   256,   257,
     258,   259,   260,   261,   262,    14,   264,    13,    19,    14,
     268,    20,    13,   271,   272,    20,   274,    14,   276,   277,
      14,    14,    14,    20,    14,    14,    20,    20,    20,    14,
      20,    20,    14,    14,    14,    20,    14,    14,    20,    20,
      20,    14,    20,    20,    14,    14,    13,    20,    15,    13,
      20,    20,    60,    13,    62,    13,   476,   477,    13,   479,
     593,   594,   595,   596,   597,   598,   525,    13,    13,    13,
     490,    13,   492,    13,    13,    13,    13,    13,    13,    13,
       0,    13,    13,    13,    13,    13,    19,    13,    13,    13,
      13,    13,    13,   525,    13,    13,    13,    13,    13,    13,
     489,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,   545,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
     572,    13,    13,    13,    13,    13,    13,   567,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,   570,    13,    13,    13,   569,    13,    13,
    1089,    13,    13,  1092,    13,    13,    13,    13,    13,   599,
      13,   576,   577,   578,    13,   605,    13,    13,   608,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,   299,    13,    13,    13,    13,   800,    19,    13,
      13,    13,    13,    13,    13,    13,   611,   810,    13,    13,
      13,    13,    13,    19,     4,    22,   370,    17,   269,    18,
      15,    19,    19,    19,   362,    19,   102,    14,   348,    22,
     153,    73,    73,    73,    14,    73,    13,    22,    73,    20,
      56,    56,    20,    14,    20,    14,    14,    13,    13,    13,
      13,    13,    13,    13,    13,   153,    13,    13,    13,    13,
      13,    13,    13,    13,    13,   323,   110,   263,    16,    57,
      56,    14,    14,    20,    20,    14,    20,    14,    16,    63,
      14,    73,    73,    16,    73,    14,    16,    14,    20,    20,
      64,    58,    20,    72,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    14,    20,    20,    20,
      20,    13,    13,    20,    14,    20,    20,    20,   324,    59,
      13,    20,    20,    20,    20,    20,    20,    14,    14,    14,
      20,    14,    20,    74,   293,    71,    20,    14,    20,    20,
      20,    20,    20,    14,    16,    20,    20,    20,  1100,   587,
      20,    20,    20,    20,    20,    20,    20,    20,    14,    20,
      14,    20,    20,    20,    56,    20,   796,    20,    20,    20,
      20,    20,    20,    20,    14,    14,    20,  1306,    20,    20,
      56,   588,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    14,    14,    14,    20,    20,
      20,   110,    62,    14,    20,    20,    20,    20,    20,    14,
      16,    20,    14,    14,    14,    14,    14,    14,    22,    22,
     590,    14,    14,    14,    20,    20,    20,    14,    14,    13,
      20,    20,    20,    13,    59,    20,    59,    20,    20,    20,
      14,    20,    20,    20,    20,    20,    14,    14,    20,    20,
      20,    20,    14,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,   592,    74,   589,    13,    16,
      13,    13,    20,    13,    20,    19,    13,    13,    16,    20,
      13,    13,    13,    13,  1152,    20,    20,   904,    14,   919,
      14,    20,    20,   923,   924,    14,    14,   927,   928,    20,
     930,   931,   932,   933,   934,    20,    20,    20,    19,   939,
     940,   941,    14,    20,    20,    20,    14,    14,    14,    14,
      20,    14,    14,    14,   591,    14,    20,    14,    14,    14,
      20,    14,   962,   963,    59,   965,   966,   967,   968,   969,
      20,   971,   972,   973,   974,   975,   976,    20,   978,    20,
      20,    20,    20,    20,    20,   985,   986,   987,   988,   989,
     990,   991,   992,    20,   994,  1494,    20,    20,    20,    20,
      20,    20,    20,    20,    20,  1504,    20,  1506,    20,  1009,
      20,    14,    14,  1013,  1014,  1015,    20,    14,  1018,  1019,
    1020,  1021,  1022,  1023,    20,  1025,    20,    20,  1028,  1029,
    1030,  1031,  1032,  1033,  1034,  1035,  1036,  1037,    20,    20,
    1040,    14,    20,    14,    14,    14,    14,    14,    20,  1049,
    1050,  1051,  1052,  1053,  1054,  1055,  1056,  1057,  1058,  1059,
      20,    20,    20,  1063,  1064,    20,  1066,  1067,    20,  1069,
    1070,  1071,  1072,  1073,    20,    20,    14,  1077,    14,    14,
      14,    14,    59,    20,    59,  1085,  1086,    14,    20,    20,
      20,    20,    14,    14,    20,    20,    20,  1097,    14,    14,
      20,    20,    20,    14,  1104,  1105,    14,  1107,  1108,    14,
      14,  1111,  1112,  1113,    14,  1115,    19,  1117,    20,  1119,
    1120,    20,    20,  1296,  1297,    14,  1126,    14,    14,    14,
    1130,  1131,  1132,    14,    14,  1135,    20,    20,    20,    14,
    1140,  1141,  1142,  1143,  1144,  1145,  1146,    20,    20,    20,
      20,    14,    20,  1153,  1154,    20,    20,  1157,    20,    14,
      14,  1161,  1162,  1150,    20,  1147,    14,    20,    20,    20,
      20,    14,    14,    20,    20,    20,    14,    14,    14,    20,
      20,    20,    14,    14,    14,    20,    20,    20,    16,    14,
      14,    20,    14,    20,    14,    14,    14,    20,    59,    20,
      14,    59,    59,    20,    20,    20,    14,    20,    20,    20,
      14,    14,    14,    20,    14,    20,    14,   936,   260,    20,
      -1,    20,    -1,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    14,    20,    20,    20,
      20,    20,    14,    20,    20,    14,    20,    14,    -1,    20,
      20,   260,    20,    14,    20,    20,    20,    20,    20,    14,
      20,    20,    20,    20,    20,    14,    20,    20,    20,    14,
      14,    14,    20,    20,    20,    59,    14,    14,  1777,    20,
      20,    20,    14,    14,    20,    20,    20,    20,    14,    14,
      20,    20,    20,    -1,  1294,    22,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    14,    14,    14,    20,
      20,    20,    14,    14,    56,    20,    20,    20,    14,   260,
      20,    20,    20,    20,    -1,    20,    20,    20,    20,    20,
      20,    20,    14,    20,  1507,    14,    14,    20,    22,    20,
      20,   602,    -1,    20,    20,    20,    20,    20,    20,    20,
      14,    14,    20,    20,    14,    14,    22,    14,    20,  1359,
      -1,  1361,    20,  1363,    20,  1365,    20,    20,  1368,  1369,
    1370,  1371,    14,    14,    14,  1375,    14,    14,  1378,    14,
      -1,    20,    14,   260,    20,    -1,    20,    20,    -1,    20,
      20,    20,    20,    20,    20,  1395,    14,    14,    20,    20,
    1400,    14,    14,    14,  1404,  1405,  1406,  1407,  1408,  1409,
    1410,  1411,  1412,  1413,  1414,  1415,  1416,  1417,  1418,  1419,
    1420,  1421,  1422,  1423,  1393,    14,  1426,    14,    14,    14,
      14,    14,    14,    14,  1434,    14,    14,    14,    -1,    14,
    1440,  1441,  1442,  1443,    20,  1445,  1446,  1447,    20,  1449,
    1450,    14,    14,    14,    14,    20,  1456,  1457,  1458,  1459,
      14,    20,    14,    14,    20,  1465,    14,    14,  1468,  1469,
      14,    14,    14,    14,  1647,    20,  1649,    14,  1478,  1479,
    1480,  1481,  1655,    14,    20,    20,    14,    20,    14,    14,
      20,  1491,  1492,  1493,    -1,    14,    20,    20,  1498,    20,
      20,    14,    20,    20,    14,    20,    20,    14,    20,  1509,
    1510,    20,  1512,  1513,    20,  1515,  1516,  1517,    20,    20,
      20,  1521,  1522,    20,    14,  1525,    14,    14,  1528,    20,
    1530,  1531,  1532,    14,    20,    20,    14,  1537,    20,    -1,
    1540,    20,  1542,    20,    20,    20,  1546,  1547,  1548,    20,
    1550,    20,    20,    14,  1554,    20,    20,    20,    20,    14,
      14,    14,    14,    14,    20,    14,    -1,    -1,    -1,  1551,
      20,    14,    20,    20,    20,    20,    20,    14,    20,  1579,
      20,    20,    14,    14,    20,    14,    14,    20,    14,    -1,
      20,    14,    14,    20,    14,    20,    20,    14,    -1,    20,
      -1,    20,    20,    14,    20,    20,    20,    20,    20,    14,
      20,    20,    20,    20,    14,   260,   260,   260,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1646,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1689,
      -1,  1691,    -1,  1693,  1694,  1695,  1696,    -1,    -1,    -1,
    1700,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1708,  1709,
    1883,    -1,  1712,    -1,  1714,    -1,  1716,    -1,  1718,  1719,
    1720,  1721,    -1,  1723,  1724,  1725,  1726,  1727,  1728,    -1,
    1730,  1731,    -1,  1733,  1734,  1735,  1736,  1706,  1738,  1739,
    1740,  1741,  1742,    -1,  1744,    -1,    -1,    -1,    -1,    -1,
    1732,    -1,    -1,    -1,  1754,  1755,  1756,  1757,  1758,  1759,
    1760,    -1,    -1,  1763,    -1,    -1,  1766,  1767,    -1,  1769,
    1770,  1771,    -1,    -1,    -1,  1775,  1776,    -1,    -1,  1779,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1787,  1788,    -1,
    1790,    -1,    -1,    -1,  1794,  1795,    -1,  1797,  1798,    -1,
    1800,    -1,  1802,  1803,    -1,  1805,    -1,  1807,  1808,  1809,
    1810,  1811,  1812,  1813,    -1,  1815,  1816,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1814,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1909,
      -1,  1911,  1912,  1913,    -1,  1915,    -1,    -1,    -1,  1919,
    1920,    -1,  1922,    -1,  1924,  1925,  1926,  1927,  1928,    -1,
    1930,  1931,  1932,  1933,  1934,  1935,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1943,  1944,  1945,    -1,     0,     1,  1918,
      -1,  1951,  1952,    -1,  1936,  1955,  1938,  1957,  1958,  1941,
    1942,  1961,  1962,    -1,  1964,  1965,    -1,    -1,    -1,    -1,
      23,  1971,    -1,    26,    -1,    -1,    -1,    -1,  1978,  1979,
    1980,    -1,    -1,  1983,  1984,  1985,  1986,    -1,  1988,    -1,
      -1,  1991,  1992,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1999,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2062,    -1,    -1,  2065,    -1,    -1,    -1,    -1,
      -1,  2071,    -1,  2073,    -1,  2075,    -1,    -1,  2078,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2088,  2089,
      -1,  2091,    -1,    -1,  2094,  2095,  2096,  2097,  2098,    -1,
      -1,  2083,  2102,    -1,  2104,    -1,    -1,  2107,  2108,  2109,
    2110,    -1,  2112,  2113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2141,  2142,    -1,    -1,    -1,  2146,    -1,  2148,  2149,
      -1,  2151,  2152,  2153,    -1,  2155,  2156,    -1,  2158,  2159,
    2160,    -1,  2162,    -1,  2164,  2165,    -1,  2167,    -1,   222,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2193,    -1,    -1,    -1,  2197,  2198,  2199,
      -1,    -1,  2202,  2203,    -1,    -1,  2206,   260,    -1,  2209,
    2210,  2211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2226,    -1,    -1,  2229,
      -1,    -1,    -1,  2233,    -1,    -1,  2236,  2237,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2248,    -1,
      -1,  2251,    -1,    -1,    -1,    -1,  2256,  2257,  2258,    -1,
      -1,    -1,  2262,  2263,    -1,     0,    -1,  2267,  2268,     4,
      -1,  2271,  2272,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,   341,   342,
      -1,    -1,    27,    28,    29,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   367,    -1,    -1,    -1,    -1,    54,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   380,    -1,    -1,
     383,   384,   385,   386,   387,    -1,   389,   390,   391,   392,
     393,   394,   395,   396,   397,    -1,    -1,   400,    -1,    -1,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
      -1,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,    -1,    -1,    -1,    -1,
      -1,    -1,   435,   436,   437,   438,   439,   440,   441,   442,
     443,    -1,    -1,   446,   447,   448,   449,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   459,   460,   461,    -1,
      -1,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,    -1,    -1,    -1,   478,   479,    -1,   481,    -1,
     483,    -1,    -1,    -1,   487,   488,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   181,    -1,    -1,   502,
      -1,    -1,    -1,    -1,   373,   374,   375,   376,   377,   378,
     379,    -1,   381,   382,    -1,    -1,    -1,    -1,    -1,   388,
      -1,    -1,   525,    -1,    -1,    -1,    -1,    -1,    -1,   398,
     399,   534,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     225,   226,    -1,    -1,   413,    -1,    -1,    -1,    -1,   552,
     553,   554,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,
     429,   430,   431,   432,   433,   434,   569,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,
      -1,    -1,   451,   452,   453,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    -1,    31,    -1,    -1,    -1,   475,    -1,    -1,    -1,
      -1,   480,    -1,    -1,    -1,    -1,   301,   486,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,
     499,   500,   501,    -1,    -1,   320,    -1,   322,   323,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   339,    -1,    -1,    -1,   527,   344,
     345,    -1,    -1,   532,   533,    -1,   535,   536,    -1,   538,
     539,   540,   541,   542,   543,   544,    -1,   546,   547,   548,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   372,   373,   374,
     375,   376,   377,   378,   379,    -1,   381,   382,    -1,    -1,
      -1,    -1,    -1,   388,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   398,   399,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   413,    -1,
      -1,    -1,   601,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   428,   429,   430,   431,   432,   433,   434,
      -1,    -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   451,   452,   453,    -1,
     455,    -1,   457,   458,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     475,    -1,    -1,    -1,    -1,   480,   225,   226,    -1,    -1,
      -1,   486,    -1,    -1,   489,    -1,    -1,    -1,   493,   494,
     495,   496,   497,   498,   499,   500,   501,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   526,   527,    -1,    -1,    -1,    -1,   532,   533,    -1,
     535,   536,    -1,   538,   539,   540,   541,   542,   543,   544,
      -1,   546,   547,   548,   549,   550,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   567,    -1,    -1,   570,   571,    -1,    -1,    -1,
      -1,   320,    -1,   322,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     339,    -1,    -1,    -1,    -1,    -1,   601,   602,    -1,    -1,
      -1,    -1,    -1,   608,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   961,    -1,
     645,   646,    -1,    -1,    -1,    -1,    -1,   970,   653,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   981,   982,
     983,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     993,    -1,    -1,    -1,    -1,   998,    -1,  1000,  1001,  1002,
    1003,  1004,    -1,  1006,  1007,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   455,    -1,   457,   458,
      -1,    -1,    -1,    -1,    -1,  1038,    -1,    -1,    -1,    -1,
      -1,  1044,  1045,  1046,  1047,  1048,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   498,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   526,    -1,    -1,
      -1,    -1,    -1,  1106,    -1,    -1,  1109,    -1,    -1,    -1,
     979,   980,   797,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     549,   550,    -1,    -1,    -1,  1128,  1129,    -1,    -1,    -1,
      -1,    -1,    -1,  1136,    -1,  1138,  1139,  1140,  1141,    -1,
      -1,    -1,  1011,    -1,  1147,    -1,    -1,  1016,  1017,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     845,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   870,    -1,    -1,    -1,    -1,
      -1,    -1,  1195,  1196,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   904,
     905,    -1,    -1,    -1,   653,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   920,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   929,    -1,    -1,    -1,    -1,  1118,
     935,    -1,  1121,  1122,    -1,    -1,    -1,    -1,    -1,   944,
      -1,   946,    -1,    -1,   949,    -1,    -1,    -1,    -1,   954,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   979,   980,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1190,    -1,    -1,    -1,  1194,  1011,    -1,    -1,    -1,
      -1,  1016,  1017,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1041,    -1,  1361,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   797,    -1,
    1239,    -1,    -1,    -1,  1377,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1393,  1394,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1084,
    1403,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1411,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   845,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1427,  1428,  1429,  1430,  1431,    -1,
      -1,    -1,    -1,  1118,    -1,    -1,  1121,  1122,    -1,    -1,
      -1,    -1,  1127,    -1,    -1,    -1,    -1,    -1,    -1,  1134,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1466,  1467,  1150,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1158,    -1,    -1,    -1,    -1,  1163,  1164,
    1483,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   920,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1190,    -1,    -1,    -1,  1194,
    1379,    -1,    -1,    -1,    -1,   944,    -1,   946,    -1,    -1,
     949,    -1,    -1,    -1,  1527,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1551,    -1,
      -1,    -1,    -1,    -1,  1239,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1460,    -1,    -1,    -1,  1464,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1295,    -1,  1041,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1489,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1520,    -1,    -1,  1523,  1084,    -1,    -1,    -1,    -1,
    1345,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1360,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1379,    -1,    -1,    -1,  1127,    -1,
      -1,    -1,    -1,  1706,    -1,  1134,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1158,
      -1,    -1,    -1,    -1,  1163,  1164,    -1,    -1,    -1,    -1,
    1743,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1445,  1764,  1765,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1460,    -1,    -1,    -1,  1464,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1799,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1489,    -1,    -1,    -1,    -1,    -1,
      -1,  1814,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1520,    -1,    -1,  1523,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1535,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1295,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1748,
      -1,  1750,  1751,    -1,  1753,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1918,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1792,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1360,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1946,  1947,  1948,  1949,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1968,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1987,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1999,    -1,    -1,    -1,
    1685,  1686,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1748,    -1,  1750,  1751,    -1,  1753,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2100,  1967,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1792,  2111,    -1,
      -1,    -1,    -1,  1982,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2157,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2166,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2238,    -1,  2106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2252,
      -1,    -1,    -1,    -1,    -1,    -1,  1685,  1686,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1967,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1982,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2188,
      -1,    -1,    -1,    -1,    -1,    -1,  2195,    -1,    -1,    -1,
      -1,    -1,  2201,    -1,    -1,    -1,    -1,    -1,    -1,  2208,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2235,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     0,    -1,    -1,    -1,    -1,
      -1,  2106,    -1,    -1,     9,    10,    11,    -1,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    -1,    42,    43,    44,
      45,    46,    47,    48,    -1,    50,    51,    52,    -1,    54,
      55,    56,    -1,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    -1,    80,    81,    82,    83,    84,
      85,    -1,    -1,  2188,    -1,    -1,    -1,    -1,    -1,    -1,
    2195,    -1,    -1,    -1,    99,   100,  2201,    -1,    -1,    -1,
      -1,    -1,    -1,  2208,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,    -1,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
    2235,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,    -1,    -1,
      -1,   156,   157,    -1,    -1,    -1,    -1,    -1,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,    -1,    -1,   234,
     235,   236,   237,   238,   239,   240,   241,   242,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   266,   267,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,    -1,   294,
     295,   296,   297,   298,    -1,    -1,    -1,    -1,    -1,   304,
     305,   306,   307,   308,   309,   310,   311,    -1,    -1,   314,
     315,   316,   317,   318,   319,   320,   321,   322,    -1,    -1,
      -1,    -1,   327,    -1,   329,   330,   331,    -1,    -1,    -1,
     335,   336,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   349,   350,   351,   352,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   360,   361,    -1,   363,   364,
     365,   366,    -1,   368,   369,    -1,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,     9,    10,    11,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    51,    52,
      -1,    54,    55,    56,    -1,    58,    59,    60,    61,    62,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    -1,    80,    81,    82,
      83,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,   100,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,    -1,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,    -1,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
      -1,    -1,    -1,   156,   157,    -1,    -1,    -1,    -1,    -1,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
      -1,   234,   235,   236,   237,   238,   239,   240,   241,   242,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   266,   267,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
      -1,   294,   295,   296,   297,   298,    -1,    -1,    -1,    -1,
      -1,   304,   305,   306,   307,   308,   309,   310,   311,    -1,
      -1,   314,   315,   316,   317,   318,   319,   320,   321,   322,
      -1,    -1,    -1,    -1,   327,    -1,   329,   330,   331,    -1,
      -1,    -1,   335,   336,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   349,   350,   351,   352,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   360,   361,    -1,
     363,   364,   365,   366,    -1,   368,   369,    -1,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,     9,    10,
      11,    -1,    13,    -1,    -1,    -1,    17,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    -1,    -1,    38,    39,    -1,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      -1,    -1,    -1,    54,    55,    56,    -1,    58,    -1,    60,
      61,    62,    -1,    64,    65,    66,    67,    68,    69,    70,
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
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,    -1,    -1,    -1,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,    -1,    -1,   229,   230,
     231,    -1,    -1,   234,   235,   236,   237,   238,   239,   240,
     241,   242,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   265,   266,   267,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,    -1,   294,    -1,   296,   297,    -1,   299,    -1,
      -1,    -1,    -1,   304,   305,   306,   307,   308,   309,   310,
     311,    -1,    -1,   314,   315,   316,   317,   318,   319,   320,
     321,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   349,   350,
     351,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   363,   364,   365,   366,    -1,   368,   369,    -1,
     371,   372,   373,   374,   375,   376,   377,    -1,   379,   380,
     381,   382,     9,    10,    11,    -1,    13,    -1,    -1,    -1,
      17,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,
      -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    -1,    -1,    -1,    54,    55,    56,
      -1,    58,    -1,    60,    61,    62,    -1,    64,    65,    66,
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
     207,   208,   209,   210,   211,    -1,    -1,    -1,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
      -1,    -1,   229,   230,   231,    -1,    -1,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   266,
     267,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,    -1,   294,    -1,   296,
     297,    -1,    -1,    -1,    -1,    -1,    -1,   304,   305,   306,
     307,   308,   309,   310,   311,    -1,    -1,   314,   315,   316,
     317,   318,   319,   320,   321,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   349,   350,   351,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   363,   364,   365,   366,
      -1,   368,   369,    -1,   371,   372,   373,   374,   375,   376,
     377,    -1,   379,   380,   381,   382,     9,    10,    11,    -1,
      13,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    35,    -1,    -1,    38,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,
      -1,    54,    55,    56,    -1,    58,    -1,    60,    61,    62,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,   100,    -1,    -1,
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
     203,   204,   205,   206,   207,   208,   209,   210,   211,    -1,
      -1,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,    -1,    -1,   229,   230,   231,    -1,
      -1,   234,   235,   236,   237,   238,   239,   240,   241,   242,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   266,   267,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
      -1,   294,    -1,   296,   297,    -1,    -1,    -1,    -1,    -1,
      -1,   304,   305,   306,   307,   308,   309,   310,   311,    -1,
      -1,   314,   315,   316,   317,   318,   319,   320,   321,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   349,   350,   351,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     363,   364,   365,   366,    -1,   368,   369,    -1,   371,   372,
     373,   374,   375,   376,   377,    -1,   379,   380,   381,   382,
       9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    37,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    -1,    -1,    -1,    54,    55,    56,    -1,    58,
      -1,    60,    61,    62,    -1,    64,    65,    66,    67,    68,
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
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,    -1,    -1,    -1,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,    -1,    -1,
     229,   230,   231,    -1,    -1,   234,   235,   236,   237,   238,
     239,   240,   241,   242,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   266,   267,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,    -1,   294,    -1,   296,   297,    -1,
      -1,    -1,    -1,    -1,    -1,   304,   305,   306,   307,   308,
     309,   310,   311,    -1,    -1,   314,   315,   316,   317,   318,
     319,   320,   321,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     349,   350,   351,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   363,   364,   365,   366,    -1,   368,
     369,    -1,   371,   372,   373,   374,   375,   376,   377,    -1,
     379,   380,   381,   382,     9,    10,    11,    -1,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      35,    -1,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    54,
      55,    56,    -1,    58,    -1,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
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
     205,   206,   207,   208,   209,   210,   211,    -1,    -1,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,    -1,    -1,   229,   230,   231,    -1,    -1,   234,
     235,   236,   237,   238,   239,   240,   241,   242,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   266,   267,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,    -1,   294,
      -1,   296,   297,    -1,    -1,    -1,    -1,    -1,    -1,   304,
     305,   306,   307,   308,   309,   310,   311,    -1,    -1,   314,
     315,   316,   317,   318,   319,   320,   321,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   349,   350,   351,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   363,   364,
     365,   366,    -1,   368,   369,    -1,   371,   372,   373,   374,
     375,   376,   377,    -1,   379,   380,   381,   382,     9,    10,
      11,    -1,    13,    -1,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    -1,    -1,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      -1,    -1,    -1,    54,    55,    56,    -1,    58,    -1,    60,
      61,    62,    -1,    64,    65,    66,    67,    68,    69,    70,
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
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,    -1,    -1,    -1,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,    -1,    -1,   229,   230,
     231,    -1,    -1,   234,   235,   236,   237,   238,   239,   240,
     241,   242,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   266,   267,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,    -1,   294,    -1,   296,   297,    -1,    -1,    -1,
      -1,    -1,    -1,   304,   305,   306,   307,   308,   309,   310,
     311,    -1,    -1,   314,   315,   316,   317,   318,   319,   320,
     321,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   349,   350,
     351,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   363,   364,   365,   366,    -1,   368,   369,    -1,
     371,   372,   373,   374,   375,   376,   377,    -1,   379,   380,
     381,   382,     9,    10,    11,    -1,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,
      -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    -1,    -1,    -1,    54,    55,    56,
      -1,    58,    -1,    60,    61,    62,    -1,    64,    65,    66,
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
     207,   208,   209,   210,   211,    -1,    -1,    -1,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
      -1,    -1,   229,   230,   231,    -1,    -1,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   266,
     267,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,    -1,   294,    -1,   296,
     297,    -1,    -1,    -1,    -1,    -1,    -1,   304,   305,   306,
     307,   308,   309,   310,   311,    -1,    -1,   314,   315,   316,
     317,   318,   319,   320,   321,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   349,   350,   351,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   363,   364,   365,   366,
      -1,   368,   369,    -1,   371,   372,   373,   374,   375,   376,
     377,    -1,   379,   380,   381,   382,     9,    10,    11,    -1,
      13,    -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    35,    -1,    -1,    38,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,
      -1,    54,    55,    56,    -1,    58,    -1,    60,    61,    62,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    -1,
      73,    -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,   100,    -1,    -1,
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
     203,   204,   205,   206,   207,   208,   209,   210,   211,    -1,
      -1,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,    -1,    -1,   229,   230,   231,    -1,
      -1,   234,   235,   236,   237,   238,   239,   240,   241,   242,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   266,   267,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
      -1,   294,    -1,   296,   297,    -1,    -1,    -1,    -1,    -1,
      -1,   304,   305,   306,   307,   308,   309,   310,   311,    -1,
      -1,   314,   315,   316,   317,   318,   319,   320,   321,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   349,   350,   351,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     363,   364,   365,   366,    -1,   368,   369,    -1,   371,   372,
     373,   374,   375,   376,   377,    -1,   379,   380,   381,   382,
       9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    -1,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    -1,    -1,    -1,    54,    55,    56,    -1,    58,
      -1,    60,    61,    62,    -1,    64,    65,    66,    67,    68,
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
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,    -1,    -1,    -1,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,    -1,    -1,
     229,   230,   231,    -1,    -1,   234,   235,   236,   237,   238,
     239,   240,   241,   242,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   266,   267,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,    -1,   294,    -1,   296,   297,    -1,
      -1,    -1,    -1,    -1,    -1,   304,   305,   306,   307,   308,
     309,   310,   311,    -1,    -1,   314,   315,   316,   317,   318,
     319,   320,   321,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     349,   350,   351,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   363,   364,   365,   366,    -1,   368,
     369,    -1,   371,   372,   373,   374,   375,   376,   377,    -1,
     379,   380,   381,   382,     9,    10,    11,    -1,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      35,    -1,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    54,
      55,    56,    -1,    58,    -1,    60,    61,    62,    -1,    64,
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
     205,   206,   207,   208,   209,   210,   211,    -1,    -1,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,    -1,    -1,   229,   230,   231,    -1,    -1,   234,
     235,   236,   237,   238,   239,   240,   241,   242,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   266,   267,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,    -1,   294,
      -1,   296,   297,    -1,    -1,    -1,    -1,    -1,    -1,   304,
     305,   306,   307,   308,   309,   310,   311,    -1,    -1,   314,
     315,   316,   317,   318,   319,   320,   321,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   349,   350,   351,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   363,   364,
     365,   366,    -1,   368,   369,    -1,   371,   372,   373,   374,
     375,   376,   377,    -1,   379,   380,   381,   382,     9,    -1,
      -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    -1,    -1,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      -1,    -1,    -1,    54,    55,    56,    -1,    58,    -1,    60,
      61,    62,    -1,    64,    65,    66,    67,    68,    69,    70,
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
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,    -1,    -1,    -1,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,    -1,    -1,   229,   230,
     231,    -1,    -1,   234,   235,   236,   237,   238,   239,   240,
     241,   242,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   266,   267,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,    -1,   294,    -1,   296,   297,    -1,    -1,    -1,
      -1,    -1,    -1,   304,   305,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   349,   350,
     351,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   363,   364,   365,   366,    -1,   368,   369,    -1,
     371,   372,   373,   374,   375,   376,   377,    13,   379,   380,
     381,   382,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      -1,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    54,    55,
      56,    -1,    58,    -1,    60,    61,    62,    -1,    64,    65,
      66,    67,    68,    69,    70,    71,    -1,    73,    -1,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,    -1,   125,
      -1,   127,   128,   129,   130,   131,   132,   133,   134,    -1,
      -1,    -1,   138,    -1,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,    -1,    -1,    -1,
     156,   157,    -1,    -1,    -1,    -1,    -1,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,    -1,    -1,
      -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,    -1,    -1,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,    -1,    -1,   229,   230,   231,    -1,    -1,   234,   235,
     236,   237,   238,   239,   240,   241,   242,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     266,   267,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,    -1,   294,    -1,
     296,   297,    -1,    -1,    -1,    -1,    -1,    -1,   304,   305,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   349,   350,   351,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    13,   363,   364,   365,
     366,    -1,   368,   369,    -1,   371,   372,   373,   374,   375,
     376,   377,    -1,   379,   380,   381,   382,    34,    35,    -1,
      -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    -1,    -1,    -1,    54,    55,    56,
      -1,    58,    -1,    60,    61,    62,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    -1,    73,    -1,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     207,   208,   209,   210,   211,    -1,    -1,    -1,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
      -1,    -1,   229,   230,   231,    -1,    -1,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   266,
     267,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,    -1,   294,    -1,   296,
     297,    -1,    -1,    -1,    -1,    -1,    -1,   304,   305,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   349,   350,   351,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   363,   364,   365,   366,
      -1,   368,   369,    -1,   371,   372,   373,   374,   375,   376,
     377,    -1,   379,   380,   381,   382
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  Parser::yystos_[] =
  {
         0,     9,    10,    11,    13,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    42,    43,    44,    45,    46,    47,    48,
      50,    51,    52,    54,    55,    56,    58,    59,    60,    61,
      62,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    80,    81,    82,    83,
      84,    85,    99,   100,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   156,   157,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   266,   267,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   294,
     295,   296,   297,   298,   304,   305,   306,   307,   308,   309,
     310,   311,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   327,   329,   330,   331,   335,   336,   349,   350,   351,
     352,   360,   361,   363,   364,   365,   366,   368,   369,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   395,
     396,   397,   398,   399,   400,   403,   404,   405,   406,   410,
     414,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   441,   442,   443,   444,   445,   446,   447,
     450,    13,    64,    66,    73,    75,   143,   144,   419,   423,
     419,   425,   425,   418,   439,    20,   415,   439,   415,   415,
      13,    13,    13,    13,   417,   439,    73,   334,   419,    56,
      67,    68,    69,    70,   443,   419,   439,   439,   417,    13,
     417,    13,    13,    19,    90,    91,    19,   110,   443,   158,
      19,    15,    60,    62,    64,    65,    66,    72,    73,    74,
      75,   419,   445,   447,   448,   449,   417,    13,    13,    13,
     424,   425,    13,    13,    15,    13,    13,    15,    13,    15,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    19,    19,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    15,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      15,   417,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,   425,   425,   425,   425,   425,   425,   425,
     425,   425,   425,   425,   425,   425,   425,   443,   411,   412,
     449,   415,   397,   417,   417,    13,    13,    13,    13,    71,
     443,   443,    13,    13,    13,    13,    13,    19,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,     0,     0,   397,   398,   399,
     400,   403,   404,   405,   406,   397,    19,    13,    19,    22,
      13,    15,    19,    99,   100,   108,     7,     8,    12,    10,
      11,     5,     6,   104,   105,   106,   107,    17,    18,   102,
       4,    21,   103,    89,    90,    91,    92,    93,   110,    13,
      19,    89,   110,    19,    19,    15,    19,    19,    13,    19,
      19,    14,    14,    22,   417,   415,   417,   418,   417,   449,
     449,   243,   244,   245,   247,   248,   249,   252,   255,   256,
     257,   258,   259,   260,   261,   262,   264,   268,   271,   272,
     274,   276,   277,   439,   439,    46,    47,   300,   301,   302,
     303,   299,    46,   159,   415,   449,   415,   415,   416,   439,
     416,   439,   416,   416,   416,   416,   416,   416,   419,   416,
     416,   419,   419,   419,   419,   419,   416,   419,   419,   419,
     419,   419,   419,   419,   419,   419,   416,   416,   419,   153,
     154,   155,   153,   154,   155,   419,   419,   419,   419,   419,
     419,   419,   419,   419,   419,   416,   419,   419,   419,   419,
     419,   419,   419,   419,   419,   419,   419,   419,   419,   419,
     416,   419,   416,   416,   416,   416,   416,   416,   419,   419,
     419,   419,   419,   419,   419,   419,   419,    73,    73,   419,
     419,   419,   419,    73,   416,   416,   416,    73,   417,    73,
     417,   417,   419,   419,   419,    56,    56,   419,   419,   419,
     419,   419,   419,   419,   419,   419,   419,   419,   416,   415,
     415,   419,   415,   419,   416,   419,    73,   419,    73,    73,
     416,   419,   419,    14,   415,   415,   439,   439,   439,   439,
     439,   417,   416,   416,   416,   419,   110,   326,    57,   411,
     411,   397,   443,   449,   417,   416,    56,   402,   401,    22,
     411,   416,   416,   419,   416,   416,   370,   416,   416,   416,
     416,   416,   416,   416,   415,   416,   416,   416,   417,   417,
      63,   419,   419,   419,   397,   348,   415,   439,    53,    54,
      86,    87,   124,   153,   158,   159,   160,   161,   162,   191,
     192,   193,   269,   270,   273,   275,   293,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   423,
      17,    64,    66,   408,   439,   447,   439,   443,   425,   425,
     425,   426,   426,   428,   428,   428,   428,   429,   429,   430,
     432,   433,   434,   436,   435,   438,   438,   438,   438,   438,
     438,   415,   269,   416,    17,    38,    41,    64,    74,   265,
     283,   286,   299,   439,   440,   446,   415,   415,   425,    20,
      20,    14,    14,    20,    20,    14,    14,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,   439,   439,    13,    13,    13,   417,    16,    20,
      14,    20,    14,    14,    20,    16,    14,    14,    16,    14,
      16,    20,    20,    20,    14,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    14,    20,    20,
      20,    20,    13,    13,    14,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    14,    14,    14,    20,    14,
      20,    20,    20,    20,    20,    14,    20,    20,    14,    20,
      14,    20,    16,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    14,    20,    14,    14,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    14,
      20,    20,    14,    14,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      14,    14,    14,    20,    20,    14,    20,    20,    14,    20,
      20,    20,    20,    20,    14,    14,    16,    20,    14,    14,
      14,    14,    14,    14,    20,    20,    20,    14,   415,   407,
     417,   413,   333,   397,    14,    14,    14,    20,    14,    13,
      13,   362,   397,    14,    20,    20,    20,    20,    20,    13,
      14,    20,    20,    20,    14,    20,    14,    20,    20,    20,
      20,    20,    20,    14,    14,    14,    20,    20,    20,    20,
      20,    22,    23,    14,    13,    13,    13,   417,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    20,   439,    14,
      20,    16,    22,    20,    13,   439,   447,    15,    13,    19,
      13,    13,    13,    13,    20,    16,   415,   417,   415,   415,
     415,   415,   439,   415,   415,   415,   415,   415,   439,    64,
     440,    64,    58,   415,   415,   415,   417,    60,    62,   417,
     110,   417,    71,   439,    13,    13,    13,    56,   419,   415,
     415,   415,   415,   415,   415,   415,   419,   415,   415,   415,
     415,   415,   415,   415,   416,   416,   419,   419,   419,   415,
     415,   415,   415,   415,   415,   415,   415,   419,   415,   419,
     419,   419,   419,   419,   419,   419,   419,   415,   416,    13,
     415,   415,   415,   416,   416,   415,   415,   415,   415,   415,
     415,   415,   415,   415,   415,   415,   415,   415,   415,   415,
     415,   415,   419,   415,   417,   419,   419,   419,   419,   419,
     415,   415,   415,   415,   415,   415,   415,   415,   415,   415,
     415,   415,   415,   415,   415,   415,   415,   415,   415,   415,
     415,   417,   415,   415,   323,    20,   411,   411,   415,   353,
     354,   356,   357,   359,   409,   409,    72,   415,   415,   419,
     415,   415,   419,   415,   415,   415,   415,   415,   416,   415,
     415,   416,   416,   415,   417,   419,   419,   415,   415,   415,
     417,   415,   419,   419,   419,   415,   419,   415,   419,   415,
     415,   415,   415,   415,   423,    17,   439,   447,   437,   415,
     415,   415,   417,   263,    74,   415,   415,   417,   417,    22,
      20,    20,    14,    20,    14,    20,    14,    14,    20,    20,
      20,    20,    14,    19,    14,    20,    14,    20,    20,    20,
      14,    14,    14,    14,    20,   416,    14,    14,    14,   416,
     419,   419,    14,    20,    20,    20,    14,    14,    14,    14,
      20,    14,    14,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    14,    14,    20,    20,    20,    20,
      20,    20,    14,    14,    20,    14,   416,    14,    14,    14,
      20,    20,    20,    20,    14,    20,    20,    20,    14,    20,
      20,    14,    14,    14,    14,    14,    20,    20,    20,    20,
      20,    14,    14,    14,    20,    20,    20,    20,    20,    20,
      14,    14,    14,    14,    14,    14,    14,    14,    20,    20,
      20,    20,    14,    20,    14,    14,    14,    14,    14,    20,
      14,    20,    20,    20,   415,   417,   397,   397,    20,    59,
      59,    59,    59,    59,    14,    20,    14,   411,    14,    20,
      20,    14,    20,    20,    14,    20,    20,    20,    14,    14,
      20,    20,    20,    20,    14,    20,    14,    20,    20,    14,
      20,    23,    20,    14,    14,    20,    14,    20,    14,    14,
      20,    14,    20,    14,    14,    14,    20,    20,    20,    14,
      20,    22,   439,    14,    20,    16,    14,    20,    14,    14,
      20,   415,   417,   415,   419,   415,   415,   415,   415,   415,
     415,   415,   419,   415,   416,    56,    14,    14,    14,    20,
     418,   419,    56,   419,   415,   415,   419,   415,   415,   415,
     415,   415,   415,   415,   415,   419,   415,   415,   415,   415,
     415,   415,   415,   415,   415,   415,   415,   415,   415,   419,
     419,   419,   419,   419,   415,    14,   415,   415,   415,   415,
     415,   439,   415,   415,   415,   415,   415,   415,   415,   415,
     416,   416,   415,   419,   419,   415,   415,   415,   415,   415,
     415,   419,   416,   415,   415,   415,   324,   411,   415,   411,
     353,   354,   356,   357,   359,   411,   397,   415,   415,   415,
     415,   415,   415,   415,   416,   415,   415,   416,   415,   419,
     415,   415,   415,   415,   439,   415,   415,   415,   415,   415,
     415,   415,   423,   415,    74,    20,    20,    56,    14,    20,
      14,    20,    14,    20,    20,    20,    20,    14,    14,    14,
      20,    14,   415,    14,    19,    14,    20,    20,    20,    20,
      14,    14,    20,    14,    20,    14,    20,    14,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    20,    20,    14,
      20,    20,    20,    20,    20,    20,    20,    14,    20,    20,
      20,    20,    20,    20,    20,    14,    14,    14,    20,    14,
      20,    20,    14,    20,    20,    20,    20,    20,    20,    20,
      20,    14,    14,    20,    20,    20,    20,    20,    14,    20,
      20,    20,    14,    14,    14,    20,    20,   415,   397,    20,
     397,    59,    59,    59,    59,    59,   397,    20,    20,    14,
      20,    14,    20,    14,    20,    20,    14,    20,    20,    20,
      20,    14,    20,    23,    14,    22,    14,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,   417,   417,    14,
     415,   415,   415,   415,   415,   415,   415,    14,   418,    56,
     415,   415,   415,   415,   415,   415,   415,   415,   415,   415,
     415,   415,   415,   415,   415,   415,   450,   415,   450,   423,
     450,   415,   415,   415,   415,   415,   415,   415,   415,   415,
     419,   415,   416,   416,   416,   416,   415,   415,   415,   415,
     415,   415,   415,   415,   419,   419,   415,   415,   415,   415,
     415,   415,   415,   411,   415,   415,   415,   415,   416,   415,
     415,   415,   415,   419,   415,   415,   415,   415,   415,   415,
     415,   415,   415,   415,   415,   423,   415,   415,    14,    20,
      14,    20,    20,    20,    14,    20,    14,    14,    20,    20,
      20,    14,    20,    14,    20,    20,    20,    20,    20,    14,
      20,    20,    20,    20,    20,    20,    20,    14,    20,    14,
      14,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      14,    20,    20,    14,    14,    20,    14,    20,    20,    14,
      14,    20,    20,    14,    20,    20,    14,    20,    20,    14,
      14,    20,    14,    14,    14,    14,    14,   397,    20,    20,
      20,    14,    20,    20,    20,    20,    20,    20,    20,    14,
      14,    20,    20,    14,    14,    14,    14,    14,    14,    22,
      14,    14,   415,   415,   415,   415,   415,   418,   415,   415,
     415,   415,   415,   415,   415,   415,   415,   415,   415,   415,
     415,   415,   450,   450,   450,   450,   415,   415,   415,   419,
     419,   419,   419,   415,   415,   415,   415,   415,   415,   415,
     415,   415,   416,   419,   415,   415,   415,   415,   416,   415,
     415,   415,   415,   419,   415,   415,   415,   423,    14,    14,
      14,    14,    20,    14,    14,    20,    14,    14,    14,    14,
      14,    20,    14,    20,    14,    20,    14,    14,    20,    14,
      14,    14,    14,    20,    14,    14,    14,    14,    20,    20,
      14,    20,    14,    14,    20,    20,    20,    20,    20,    14,
      20,    14,    20,    14,    20,    14,    20,    20,    20,    20,
      20,    20,    20,    22,    14,   415,   415,   415,   415,   415,
     415,   450,   415,   415,   415,   415,   415,   415,   415,   415,
     419,   415,   415,   416,   415,   415,   415,   415,   419,   415,
     415,    20,    20,    14,    14,    14,    20,    14,    20,    20,
      14,    20,    20,    20,    14,    20,    20,    20,    20,    20,
      20,    14,    20,    14,    20,    20,    20,    20,    14,   415,
     415,   415,   415,   415,   415,   415,   415,   415,   415,   419,
     415,   415,   415,   415,   415,   415,   419,   415,   110,    14,
      14,    14,    14,    20,    14,    20,    14,    20,    20,    20,
      14,    20,    20,    20,    14,    14,    20,    14,    20,    20,
      20,    20,   416,   415,   416,   415,   415,   415,   416,   415,
     415,   415,   416,   415,   415,   415,    20,    14,    14,    20,
      14,    14,    14,    20,    14,    20,    20,    20,    20,   415,
     415,   415,   416,   415,   415,   419,    14,    14,    20,    14,
      14,    20,    20,   415,   415,   419,    20,    20,    20,   415,
     415,   415,    20,    20,    14,   415,   415,    20,    20,   415,
     415,    20,    20,   415,   415,    14,    14
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
     645,   646,   647,   648
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  Parser::yyr1_[] =
  {
         0,   394,   395,   395,   396,   396,   396,   396,   396,   396,
     396,   396,   396,   396,   396,   396,   396,   396,   396,   396,
     397,   397,   398,   398,   398,   398,   398,   399,   399,   401,
     400,   402,   400,   403,   403,   404,   405,   405,   405,   406,
     406,   406,   406,   406,   406,   406,   406,   406,   406,   406,
     406,   406,   406,   406,   406,   406,   406,   406,   406,   406,
     406,   406,   406,   406,   406,   406,   406,   406,   406,   406,
     406,   406,   406,   406,   406,   406,   406,   406,   406,   406,
     406,   406,   406,   406,   406,   406,   406,   406,   406,   406,
     406,   406,   406,   406,   406,   406,   406,   406,   406,   406,
     406,   406,   406,   406,   406,   406,   406,   406,   406,   406,
     406,   406,   406,   406,   406,   406,   406,   406,   406,   406,
     406,   406,   406,   406,   406,   406,   406,   406,   406,   406,
     406,   406,   406,   406,   406,   406,   406,   406,   406,   406,
     406,   406,   406,   406,   406,   406,   406,   406,   406,   406,
     406,   406,   406,   406,   406,   406,   406,   406,   406,   406,
     406,   406,   406,   406,   406,   406,   406,   406,   406,   406,
     406,   406,   406,   406,   406,   406,   406,   406,   406,   406,
     406,   406,   406,   406,   406,   406,   406,   407,   407,   408,
     408,   408,   408,   408,   408,   408,   409,   409,   409,   409,
     409,   409,   409,   409,   409,   409,   409,   410,   410,   410,
     410,   410,   410,   410,   411,   412,   413,   414,   414,   414,
     414,   414,   414,   414,   414,   414,   414,   414,   414,   414,
     414,   414,   414,   414,   414,   414,   414,   414,   414,   414,
     414,   414,   414,   414,   414,   414,   414,   414,   414,   414,
     414,   414,   414,   414,   414,   414,   414,   414,   414,   414,
     414,   414,   414,   414,   414,   414,   414,   415,   416,   417,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   419,   419,   420,   420,   420,   420,   420,   420,
     420,   420,   420,   420,   420,   420,   420,   420,   420,   420,
     420,   420,   420,   420,   420,   420,   420,   420,   420,   420,
     420,   420,   420,   420,   420,   420,   420,   420,   420,   420,
     420,   420,   420,   420,   420,   420,   420,   420,   420,   420,
     420,   420,   420,   420,   420,   420,   420,   420,   420,   420,
     420,   420,   420,   420,   420,   420,   420,   420,   420,   420,
     420,   420,   420,   420,   420,   420,   420,   420,   420,   420,
     420,   420,   420,   420,   420,   420,   420,   420,   420,   420,
     420,   420,   420,   420,   420,   420,   420,   420,   420,   420,
     420,   420,   420,   420,   420,   420,   420,   420,   420,   420,
     420,   420,   420,   420,   420,   420,   420,   420,   420,   420,
     420,   420,   420,   420,   420,   420,   420,   420,   420,   420,
     421,   422,   422,   423,   423,   423,   423,   423,   423,   423,
     423,   423,   423,   423,   424,   424,   424,   424,   424,   424,
     424,   424,   424,   425,   425,   425,   425,   425,   425,   425,
     425,   425,   425,   425,   425,   425,   425,   425,   425,   425,
     425,   425,   425,   426,   426,   426,   426,   427,   427,   427,
     428,   429,   429,   429,   429,   429,   430,   430,   430,   431,
     431,   432,   433,   433,   434,   434,   435,   435,   436,   436,
     437,   437,   438,   438,   438,   438,   438,   438,   438,   439,
     440,   440,   440,   440,   441,   441,   441,   442,   442,   442,
     442,   442,   442,   442,   442,   442,   442,   442,   442,   442,
     442,   442,   442,   442,   442,   442,   442,   442,   442,   442,
     442,   442,   442,   442,   442,   442,   442,   442,   442,   442,
     442,   443,   444,   445,   445,   445,   445,   445,   446,   446,
     446,   446,   447,   447,   448,   448,   448,   448,   448,   449,
     449,   449,   450,   450,   450,   450
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
       3,     3,     2,     6,    10,     6,    10,    10,    12,     6,
       6,     3,     3,     3,     3,     4,     3,     6,     6,     4,
      20,    10,     6,     3,     3,     6,     3,     6,     8,     6,
       6,     8,    16,     6,     3,     6,     8,     3,    12,    12,
      12,    10,     3,     3,     8,     8,    10,     8,    10,    12,
       6,     8,    10,    16,    18,    12,     6,    18,    16,    12,
      10,    10,    10,     6,    10,     6,     6,     6,     8,     4,
       4,     8,     4,    18,     4,     1,     1,     1,     6,     3,
       4,     1,     1,     1,    30,    24,     8,     1,     3,     0,
       1,     3,     2,     4,     1,     3,     0,     2,     2,     2,
       2,     2,     4,     4,     4,     4,     4,     1,     6,     1,
       3,     4,     4,     1,     3,     0,     0,     1,     1,     1,
       1,     6,     8,    10,    10,    10,     8,     6,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       6,     4,    10,     4,    10,     4,     4,     4,     4,     4,
       4,     7,     7,     7,     9,     7,     6,     4,     6,    10,
       4,     4,     4,     3,     6,     6,     6,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     4,     1,     2,     4,     4,     1,    10,
      12,     8,     6,     6,     6,     8,     8,     6,     8,     8,
      10,    10,    12,    12,    10,     4,    10,     4,     6,     4,
       4,     4,    12,     4,    12,    12,    16,    20,    10,    12,
       4,     6,     6,     6,     4,     4,     6,     4,     6,     6,
       6,    16,    10,     8,    12,    10,     8,    12,     8,    12,
       8,    12,    12,    14,    12,    12,    16,     4,     8,    10,
      12,    10,    12,    10,    12,    12,    14,    12,     8,    14,
       4,     4,     4,     4,     3,     3,     6,     6,     6,     6,
       8,    14,    12,    14,    12,     6,     8,    10,    10,    12,
       6,     6,     6,     6,     6,     6,     6,     6,     8,    10,
       4,     4,    10,    10,     4,     6,     6,    12,    30,     8,
       6,     4,     6,     4,     6,     4,     4,    18,     8,     6,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     6,     3,     1,     1,     3,     4,     2,     2,
       2,     2,     4,     1,     4,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     3,     3,     3,     1,     3,     3,
       1,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     5,     1,     3,     3,     3,     3,     3,     3,     1,
       1,     3,     8,     4,     6,     1,     4,     6,     6,     8,
       8,     4,     6,     6,     6,     6,     3,     2,     4,     6,
       4,     4,    10,     6,    16,    18,    10,    20,    14,     4,
       6,     8,     8,    12,    16,    16,    18,    14,    14,    16,
      20,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,    11,     7,     7,     3
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
  "T_LineRecons", "T_ReadCTALine", "T_ReadCTALineRadii", "T_vtkDicomRead",
  "T_vtkMINCRead", "T_Convolve", "T_ConvolveMask", "T_Pad", "T_Eigen2D",
  "T_Eigen3D", "T_ChamferDT", "T_Chamfer2DT", "T_BorgeforsDT",
  "T_BorgeforsSDT", "T_vtkSignedBorgefors", "T_vtkSignedFMDist",
  "T_PropagationDist", "T_PropagationDist2", "T_PropDanielsson",
  "T_vtkPropDanielsson", "T_vtkPropDaniel2", "T_CC", "T_ProcessXEvents",
  "T_ProcessEvents", "T_isoarea2D", "T_posarea", "T_isosurf",
  "T_isosurf_inv", "T_isosurf_ijk", "T_isosurf_ras", "T_vtkDecimate",
  "T_vtkMarchingCubes", "T_vtkSmooth", "T_vtkWindowedSinc", "T_isoline",
  "T_vtkDist", "T_AndreDist", "T_Surface", "T_getimage", "T_GetImageFromX",
  "T_rotate", "T_computeCC", "T_drawCC", "T_addobj", "T_setcurrentobj",
  "T_writeVRML", "T_writeVTK", "T_Paint", "T_SetLight", "T_SetLightPos",
  "T_SetLightAmbient", "T_SetLightDiffuse", "T_SetLightSpecular",
  "T_SetBackground", "T_Normalize", "T_Center", "T_Remove",
  "T_SwapBuffers", "T_GetTransform", "T_SetTransform", "T_Interpolate",
  "T_Matrix", "T_Invert", "T_PrintMatrices", "SET", "SETPOS", "COMPARE",
  "SETVECTOR", "T_lininterp", "T_SetWindowSize", "T_initvalue",
  "T_ShowSection", "T_HideSection", "T_Xpos", "T_Ypos", "T_Zpos",
  "T_SpacePos", "T_CHAR", "T_UCHAR", "T_SHORT", "T_USHORT", "T_INT",
  "T_UINT", "T_LONG", "T_FLOAT", "T_DOUBLE", "T_RGB", "T_FLOAT_VECTOR",
  "T_GetFormat", "T_atof", "T_gnuplot", "T_histo", "T_cumhisto",
  "T_DisplayHisto", "T_OPEN", "T_CLOSE", "T_scan_float", "T_read",
  "T_rewind", "T_LineNumber", "CONST_PI", "SIN", "COS", "TAN", "ASIN",
  "ACOS", "ATAN", "SINH", "COSH", "EXP", "LN", "LOG", "SQRT", "ABS",
  "ROUND", "FLOOR", "NORM", "FOR", "TO", "STEP", "ENDFOR", "T_IN",
  "T_REPEAT", "T_UNTIL", "T_WHILE", "T_BREAK", "IF", "THEN", "ELSE",
  "VARIABLES", "FUNCTION", "T_eval", "T_tx", "T_ty", "T_tz", "T_trx",
  "T_try", "T_trz", "T_vx", "T_vy", "T_vz", "T_vdim", "T_inc", "T_val",
  "T_exists", "T_FileExists", "T_slice", "T_GenRead", "T_IMAGE",
  "T_IMAGEDRAW", "T_SURFACE", "T_NUM", "T_STRING", "T_TRANSFORM",
  "T_OBJECT", "T_PROC", "T_Class", "T_public", "T_MeanHalfSize",
  "T_Resize", "T_ReSlice", "T_Flip", "T_SetCompTransf", "T_ConvexHull",
  "T_itk", "T_CannyEdgeDetector", "T_CreateFlatMesh", "T_CreateVolume",
  "T_vtkCreateFlatMesh", "T_Altitude2Position", "T_GeoCoordinates",
  "T_CreateVectors", "T_CreateVectorsFromField", "T_Set3DArrowParam",
  "T_CreateEllipsoids", "T_ComputeAltitudes", "T_Temp2Altitudes",
  "T_ReadFlow", "T_SetFluidNavFile", "T_DrawEarthCoord",
  "T_SaveStructuredGrid", "T_import_vtk", "T_import_wii",
  "T_import_filters", "T_amiOFCorr2D", "T_amiOFVar2D", "SHIFT_THERE",
  "prefix", "postfix", "$accept", "start", "list_commands", "end_instr",
  "loop_inst", "cond_inst", "proc_decl", "$@1", "$@2", "class_decl",
  "object_decl", "func_inst", "command", "exprstringlist", "param_list",
  "param_list_decl", "primary_expr_string", "instr_block", "begin_block",
  "end_block", "float_variable", "expr", "expr_image", "expr_string",
  "basic_type", "var_image", "image", "image_variable", "string_variable",
  "primary_var", "postfix_var", "prefix_var", "multiplicative_var",
  "additive_var", "shift_var", "relational_var", "equality_var", "and_var",
  "exclusive_or_var", "inclusive_or_var", "logical_and_var",
  "logical_xor_var", "logical_or_var", "conditional_var", "assignment_var",
  "expr_var", "gltransform", "matrix_variable", "surface", "identifier",
  "variable_with_assign", "function_variable", "variable_without_assign",
  "unprocessed_variable", "processed_variable", "variable", "image_extent", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Parser::rhs_number_type
  Parser::yyrhs_[] =
  {
       395,     0,    -1,    -1,   396,     0,    -1,   397,    -1,   396,
     397,    -1,   406,   397,    -1,   396,   406,   397,    -1,   398,
      -1,   396,   398,    -1,   399,    -1,   396,   399,    -1,   405,
      -1,   396,   405,    -1,   400,    -1,   396,   400,    -1,   403,
      -1,   396,   403,    -1,   404,    -1,   396,   404,    -1,    37,
      -1,    23,    -1,   322,   443,   110,   415,   323,   415,   411,
     397,    -1,   322,   443,   110,   415,   323,   415,   324,   415,
     411,   397,    -1,   322,   443,   326,   407,   411,   397,    -1,
     327,   411,    -1,   329,   449,   411,    -1,   331,   415,   411,
     397,    -1,   331,   415,   411,   333,   411,   397,    -1,    -1,
     360,   443,   401,    13,   409,    14,   411,   397,    -1,    -1,
     360,    71,   402,    13,   409,    14,   411,   397,    -1,   361,
     443,   411,   397,    -1,   361,   443,    22,   362,    72,   411,
     397,    -1,    72,   443,    -1,   335,   417,   397,    -1,   335,
     397,    -1,   336,   417,    -1,   447,    -1,   439,    -1,    36,
      -1,   330,    -1,    80,    -1,    82,    -1,    83,    -1,    81,
      -1,    84,    13,   415,    14,    -1,    85,    13,   415,    20,
      71,    14,    -1,   443,   110,    17,   447,    -1,   443,   110,
      17,   439,    -1,   443,   110,   439,    -1,   443,   110,   439,
      20,   417,    -1,   443,   110,   446,    -1,   443,   110,    38,
      15,   415,    16,    -1,   443,    89,   416,    -1,    75,    15,
     415,    16,   110,   416,    -1,   443,   110,   440,    -1,   443,
     110,   286,    13,   415,    14,    -1,   443,   110,   286,    13,
     415,    14,    20,   417,    -1,   443,   110,   283,    13,   415,
      14,    -1,   443,   110,   283,    13,   415,    14,    20,   417,
      -1,   443,   110,   299,    13,   417,    20,    56,    14,    -1,
      66,   110,   299,    13,   417,    20,    56,    14,    -1,    66,
      19,   303,    -1,    24,    -1,    25,    -1,    26,   415,    -1,
      27,   415,    -1,    29,    -1,    30,    -1,    28,   415,    -1,
      31,    13,   417,    20,   417,    20,   417,    14,    -1,    32,
      13,   415,    14,    -1,    33,    13,   417,    14,    -1,    44,
      -1,    42,   419,    -1,    45,   419,    -1,    42,    73,    -1,
     419,    19,    86,    13,   415,    20,   439,    14,    -1,   419,
      13,   415,    22,   415,    20,   415,    22,   415,    20,   415,
      22,   415,    14,   110,   416,    -1,    42,   334,    -1,    78,
      13,   449,    20,   417,    14,    -1,    76,   449,    -1,    77,
     417,    -1,    51,   417,    -1,    52,    -1,    43,    -1,    43,
     443,    -1,    43,    70,    -1,    43,    67,    -1,    43,    68,
      -1,    43,    69,    -1,    43,    56,    -1,    66,    19,    46,
     439,    -1,    66,    19,    47,   439,    -1,    46,   439,    -1,
      47,   439,    -1,    48,   417,    -1,    66,    19,   300,    -1,
     419,    19,   153,    -1,   419,    19,   158,    -1,    73,   158,
      -1,   419,    19,   275,    13,   415,    14,    -1,   419,    19,
     275,    13,   415,    20,   415,    20,   415,    14,    -1,   419,
      19,   269,    13,   415,    14,    -1,   419,    19,   269,    13,
     415,    20,   415,    20,   415,    14,    -1,   419,    19,   270,
      13,   415,    20,   415,    20,   415,    14,    -1,   419,    19,
     124,    13,   419,    20,   415,    20,   415,    20,   415,    14,
      -1,   419,    19,   124,    13,   419,    14,    -1,   419,    19,
      53,    13,   417,    14,    -1,   143,    19,   154,    -1,   143,
      19,   155,    -1,   144,    19,   154,    -1,   144,    19,   155,
      -1,   419,    19,   159,   417,    -1,   419,    19,   160,    -1,
     419,    19,   161,    13,   419,    14,    -1,   419,    19,   162,
      13,   419,    14,    -1,   383,    13,   417,    14,    -1,   384,
      13,    63,    20,   415,    20,   415,    20,   415,    20,   415,
      20,   415,    20,   415,    20,   415,    20,   415,    14,    -1,
      64,    19,   245,    13,   415,    20,   415,    20,   415,    14,
      -1,    64,    19,   248,    13,   439,    14,    -1,    64,    90,
     439,    -1,    64,    91,   439,    -1,    64,    19,   261,    13,
     439,    14,    -1,    64,    19,   262,    -1,    64,    19,   247,
      13,   415,    14,    -1,    64,    19,   247,    13,   415,    20,
     415,    14,    -1,    64,    19,   249,    13,   415,    14,    -1,
      64,    19,   271,    13,    64,    14,    -1,    64,    19,   272,
      13,    58,    20,   419,    14,    -1,    64,    19,   276,    13,
     415,    20,   416,    20,   415,    20,   415,    20,   415,    20,
     415,    14,    -1,    64,    19,   277,    13,   415,    14,    -1,
      64,    19,   268,    -1,    64,    19,   264,    13,   440,    14,
      -1,    64,    19,   264,    13,   440,    20,   415,    14,    -1,
      64,    19,   252,    -1,    64,    19,   255,    13,   415,    20,
     415,    20,   415,    20,   415,    14,    -1,    64,    19,   256,
      13,   415,    20,   415,    20,   415,    20,   415,    14,    -1,
      64,    19,   257,    13,   415,    20,   415,    20,   415,    20,
     415,    14,    -1,    64,    19,   258,    13,   415,    20,   415,
      20,   415,    14,    -1,    64,    19,   259,    -1,    64,    19,
     260,    -1,    64,    19,   274,    13,   415,    20,   415,    14,
      -1,   184,    13,   419,    20,   415,    20,   415,    14,    -1,
     184,    13,   419,    20,   415,    20,   415,    20,   416,    14,
      -1,   185,    13,   419,    20,   415,    20,   415,    14,    -1,
     185,    13,   419,    20,   415,    20,   415,    20,   416,    14,
      -1,   185,    13,   419,    20,   415,    20,   415,    20,   416,
      20,   415,    14,    -1,   186,    13,   419,    20,   415,    14,
      -1,   186,    13,   419,    20,   415,    20,   439,    14,    -1,
     186,    13,   419,    20,   415,    20,   415,    20,   416,    14,
      -1,   188,    13,   419,    20,   415,    20,   415,    20,   415,
      20,   415,    20,   415,    20,   415,    14,    -1,   188,    13,
     419,    20,   415,    20,   415,    20,   415,    20,   415,    20,
     415,    20,   415,    20,   416,    14,    -1,   187,    13,   419,
      20,   415,    20,   415,    20,   416,    20,   415,    14,    -1,
     189,    13,   419,    20,   415,    14,    -1,   214,    13,    56,
      20,   419,    20,   419,    20,   419,    20,   419,    20,   419,
      20,   419,    20,   416,    14,    -1,   214,    13,    56,    20,
     419,    20,   419,    20,   419,    20,   419,    20,   419,    20,
     419,    14,    -1,   213,    13,    56,    20,   419,    20,   419,
      20,   419,    20,   416,    14,    -1,   213,    13,    56,    20,
     419,    20,   419,    20,   419,    14,    -1,   191,    13,   419,
      20,   415,    20,   415,    20,   415,    14,    -1,   419,    19,
     191,    13,   415,    20,   415,    20,   415,    14,    -1,   419,
      19,   191,    13,   419,    14,    -1,   419,    19,   192,    13,
     415,    20,   415,    20,   415,    14,    -1,   419,    19,   192,
      13,   419,    14,    -1,   419,    19,   193,    13,   415,    14,
      -1,   126,    13,   419,    20,   419,    14,    -1,   126,    13,
     419,    20,   419,    20,   419,    14,    -1,   227,    13,   415,
      14,    -1,   228,    13,   415,    14,    -1,   295,    13,   416,
      20,   417,    20,   415,    14,    -1,   298,    13,   419,    14,
      -1,   212,    13,   419,    20,   419,    20,   415,    20,   415,
      20,   415,    20,   415,    20,   415,    20,   415,    14,    -1,
     352,    13,    56,    14,    -1,   136,    -1,   137,    -1,   139,
      -1,   385,    13,   419,    20,   417,    14,    -1,    74,    19,
      46,    -1,    74,    19,   159,   417,    -1,   386,    -1,   387,
      -1,   388,    -1,   389,    13,   419,    20,   419,    20,   419,
      20,   419,    20,   419,    20,   419,    20,   419,    20,   415,
      20,   415,    20,   415,    20,   415,    20,   415,    20,   415,
      20,   415,    14,    -1,   390,    13,   419,    20,   419,    20,
     415,    20,   415,    20,   415,    20,   415,    20,   415,    20,
     415,    20,   419,    20,   419,    20,   415,    14,    -1,   378,
      13,   415,    20,   415,    20,   415,    14,    -1,   417,    -1,
     407,    20,   417,    -1,    -1,   447,    -1,   408,    20,   447,
      -1,    17,   439,    -1,   408,    20,    17,   439,    -1,   439,
      -1,   408,    20,   439,    -1,    -1,   356,    59,    -1,   359,
      59,    -1,   357,    59,    -1,   353,    59,    -1,   354,    59,
      -1,   409,    20,   359,    59,    -1,   409,    20,   356,    59,
      -1,   409,    20,   357,    59,    -1,   409,    20,   353,    59,
      -1,   409,    20,   354,    59,    -1,    56,    -1,    50,    13,
     417,    20,   415,    14,    -1,   138,    -1,   419,    19,    54,
      -1,    54,    13,   449,    14,    -1,    55,    13,   449,    14,
      -1,    34,    -1,   412,    57,   413,    -1,    -1,    -1,    58,
      -1,    35,    -1,   304,    -1,   305,    -1,   419,    13,   415,
      20,   415,    14,    -1,   419,    13,   415,    20,   415,    20,
     415,    14,    -1,   419,    19,   273,    13,   415,    20,   415,
      20,   415,    14,    -1,   419,    13,   415,    20,   415,    20,
     415,    20,   415,    14,    -1,   419,    13,   415,    20,   415,
      20,   415,    23,   415,    14,    -1,   419,    13,   415,    20,
     415,    23,   415,    14,    -1,   419,    13,   415,    23,   415,
      14,    -1,   419,    19,   337,    -1,   419,    19,   338,    -1,
     419,    19,   339,    -1,   419,    19,   340,    -1,   419,    19,
     341,    -1,   419,    19,   342,    -1,   419,    19,   343,    -1,
     419,    19,   344,    -1,   419,    19,   345,    -1,   419,    19,
     346,    -1,   419,    19,   347,    -1,   419,    19,   348,    -1,
     157,    13,   419,    20,   419,    14,    -1,   176,    13,   419,
      14,    -1,   229,    13,   419,    20,   415,    20,   415,    20,
     415,    14,    -1,   230,    13,   419,    14,    -1,   230,    13,
     415,    20,   415,    20,   415,    20,   415,    14,    -1,   111,
      13,   416,    14,    -1,   178,    13,   416,    14,    -1,   112,
      13,   416,    14,    -1,   113,    13,   416,    14,    -1,   114,
      13,   416,    14,    -1,   115,    13,   416,    14,    -1,   112,
      15,   416,    16,    13,   416,    14,    -1,   114,    15,   416,
      16,    13,   419,    14,    -1,   115,    15,   416,    16,    13,
     419,    14,    -1,   115,    15,   416,    16,    13,   419,    20,
     415,    14,    -1,   178,    15,   416,    16,    13,   416,    14,
      -1,   178,    13,   419,    20,   416,    14,    -1,   294,    13,
     417,    14,    -1,   441,    13,   415,    20,   415,    14,    -1,
     441,    19,   269,    13,   415,    20,   415,    20,   415,    14,
      -1,   349,    13,   443,    14,    -1,   349,    13,   449,    14,
      -1,   350,    13,   417,    14,    -1,   418,    19,   348,    -1,
      66,    19,   301,    13,   417,    14,    -1,    66,    19,   302,
      13,    60,    14,    -1,    66,    19,   302,    13,    62,    14,
      -1,   439,    -1,   439,    -1,   439,    -1,   282,    -1,   283,
      -1,   284,    -1,   285,    -1,   286,    -1,   287,    -1,   288,
      -1,   289,    -1,   290,    -1,   291,    -1,   292,    -1,   419,
      19,   293,    -1,    61,    -1,    75,    15,   415,    16,    -1,
     419,    -1,    38,   417,    -1,   208,    13,   417,    14,    -1,
     209,    13,   417,    14,    -1,    39,    -1,    38,    13,   418,
      20,   415,    20,   415,    20,   415,    14,    -1,    38,    13,
     418,    20,   415,    20,   415,    20,   415,    20,   415,    14,
      -1,    38,    13,   418,    20,   415,    20,   419,    14,    -1,
     179,    13,   416,    20,   415,    14,    -1,   180,    13,   416,
      20,   415,    14,    -1,   181,    13,   416,    20,   415,    14,
      -1,   182,    13,   416,    20,   416,    20,   415,    14,    -1,
     183,    13,   416,    20,   416,    20,   415,    14,    -1,   116,
      13,   419,    20,    56,    14,    -1,   116,    13,   419,    20,
      56,    20,   418,    14,    -1,   116,    13,   419,    20,   419,
      20,    56,    14,    -1,   116,    13,   419,    20,   419,    20,
      56,    20,   418,    14,    -1,   116,    13,   419,    20,   419,
      20,   419,    20,    56,    14,    -1,   116,    13,   419,    20,
     419,    20,   419,    20,    56,    20,   418,    14,    -1,   117,
      13,   416,    20,   415,    20,   415,    20,   415,    20,   415,
      14,    -1,   369,    19,   370,    13,   419,    20,   415,    20,
     415,    14,    -1,   240,    13,   419,    14,    -1,   134,    13,
     419,    20,   415,    20,   415,    20,   415,    14,    -1,   241,
      13,   419,    14,    -1,   163,    13,   416,    20,   415,    14,
      -1,   164,    13,   419,    14,    -1,   165,    13,   419,    14,
      -1,   166,    13,   419,    14,    -1,   167,    13,   419,    20,
     419,    20,   415,    20,   415,    20,   415,    14,    -1,   168,
      13,   419,    14,    -1,   169,    13,   419,    20,   419,    20,
     419,    20,   415,    20,   419,    14,    -1,   170,    13,   419,
      20,   419,    20,   419,    20,   415,    20,   419,    14,    -1,
     171,    13,   419,    20,   419,    20,   419,    20,   415,    20,
     419,    20,   415,    20,   415,    14,    -1,   172,    13,   419,
      20,   419,    20,   419,    20,   415,    20,   419,    20,   415,
      20,   415,    20,   415,    20,   415,    14,    -1,   173,    13,
     419,    20,   419,    20,   419,    20,   419,    14,    -1,   173,
      13,   419,    20,   419,    20,   419,    20,   419,    20,   415,
      14,    -1,   174,    13,   419,    14,    -1,   174,    13,   419,
      20,   419,    14,    -1,   175,    13,   419,    20,   419,    14,
      -1,   118,    13,   416,    20,   415,    14,    -1,   119,    13,
     419,    14,    -1,   133,    13,   419,    14,    -1,   120,    13,
     419,    20,   415,    14,    -1,   190,    13,   419,    14,    -1,
     121,    13,   419,    20,   415,    14,    -1,   122,    13,   419,
      20,   415,    14,    -1,   125,    13,   416,    20,   415,    14,
      -1,   123,    13,   419,    20,   415,    20,   415,    20,   415,
      20,   415,    20,   415,    20,   415,    14,    -1,   127,    13,
     419,    20,   415,    20,   415,    20,   415,    14,    -1,   127,
      13,   419,    20,   415,    20,   415,    14,    -1,   127,    13,
     419,    20,   415,    20,   415,    20,   415,    20,   415,    14,
      -1,   128,    13,   419,    20,   415,    20,   415,    20,   415,
      14,    -1,   128,    13,   419,    20,   415,    20,   415,    14,
      -1,   128,    13,   419,    20,   415,    20,   415,    20,   415,
      20,   415,    14,    -1,   129,    13,   419,    20,   415,    20,
     415,    14,    -1,   129,    13,   419,    20,   415,    20,   415,
      20,   415,    20,   415,    14,    -1,   130,    13,   419,    20,
     415,    20,   415,    14,    -1,   130,    13,   419,    20,   415,
      20,   415,    20,   415,    20,   415,    14,    -1,   142,    13,
     419,    20,   419,    20,   415,    20,   415,    20,   415,    14,
      -1,   132,    13,   419,    20,   415,    20,   415,    20,   415,
      20,   415,    20,   415,    14,    -1,   131,    13,   419,    20,
     415,    20,   415,    20,   415,    20,   415,    14,    -1,   143,
      19,   153,    13,   419,    20,   415,    20,   415,    20,   415,
      14,    -1,   144,    19,   153,    13,   419,    20,   415,    20,
     415,    20,   415,    20,   415,    20,   415,    14,    -1,   145,
      13,   419,    14,    -1,   146,    13,   419,    20,   415,    20,
     415,    14,    -1,   146,    13,   419,    20,   415,    20,   415,
      20,   450,    14,    -1,   146,    13,   419,    20,   415,    20,
     415,    20,   415,    20,   450,    14,    -1,   147,    13,   419,
      20,   415,    20,   415,    20,   450,    14,    -1,   147,    13,
     419,    20,   415,    20,   415,    20,   415,    20,   450,    14,
      -1,   148,    13,   419,    20,   415,    20,   415,    20,   450,
      14,    -1,   149,    13,   419,    20,   415,    20,   415,    20,
     415,    20,   450,    14,    -1,   150,    13,   419,    20,   415,
      20,   415,    20,   415,    20,   450,    14,    -1,   151,    13,
     419,    20,   415,    20,   415,    20,   415,    20,   415,    20,
     450,    14,    -1,   152,    13,   419,    20,   415,    20,   415,
      20,   415,    20,   415,    14,    -1,   156,    13,   419,    20,
     415,    20,   415,    14,    -1,   177,    13,   419,    20,   415,
      20,   415,    20,   415,    20,   415,    20,   415,    14,    -1,
     278,    13,   439,    14,    -1,   279,    13,   439,    14,    -1,
     280,    13,   439,    14,    -1,   281,    13,   439,    14,    -1,
      64,    19,   243,    -1,    64,    19,   244,    -1,   197,    13,
     419,    20,   415,    14,    -1,   198,    13,   419,    20,   415,
      14,    -1,   199,    13,   419,    20,   415,    14,    -1,   200,
      13,   419,    20,   415,    14,    -1,   140,    13,   416,    20,
     416,    20,   415,    14,    -1,   141,    13,   416,    20,   416,
      20,   415,    20,   415,    20,   415,    20,   415,    14,    -1,
     140,    13,   416,    20,   416,    20,   415,    20,   415,    20,
     415,    14,    -1,   140,    13,   416,    20,   416,    20,   415,
      20,   415,    20,   415,    20,   415,    14,    -1,   140,    13,
     416,    20,   416,    20,   419,    20,   415,    20,   415,    14,
      -1,   210,    13,   419,    20,   419,    14,    -1,   211,    13,
     419,    20,   419,    20,   416,    14,    -1,   215,    13,   419,
      20,   415,    20,   415,    20,   415,    14,    -1,   216,    13,
     419,    20,   415,    20,   415,    20,   415,    14,    -1,   216,
      13,   419,    20,   415,    20,   415,    20,   415,    20,   415,
      14,    -1,   217,    13,   419,    20,   415,    14,    -1,   218,
      13,   419,    20,   415,    14,    -1,   219,    13,   419,    20,
     415,    14,    -1,   220,    13,   419,    20,   415,    14,    -1,
     221,    13,   419,    20,   415,    14,    -1,   222,    13,   419,
      20,   415,    14,    -1,   223,    13,   419,    20,   415,    14,
      -1,   224,    13,   419,    20,   415,    14,    -1,   224,    13,
     419,    20,   415,    20,   415,    14,    -1,   225,    13,   419,
      20,   415,    20,   415,    20,   415,    14,    -1,   226,    13,
     416,    14,    -1,   419,    13,   439,    14,    -1,   296,    13,
     416,    20,   415,    20,   415,    20,   415,    14,    -1,   297,
      13,   416,    20,   415,    20,   415,    20,   415,    14,    -1,
     363,    13,   416,    14,    -1,   363,    13,   416,    20,   415,
      14,    -1,   366,    13,   416,    20,   415,    14,    -1,   364,
      13,   416,    20,   415,    20,   415,    20,   415,    20,   415,
      14,    -1,   365,    13,   419,    20,   419,    20,   415,    20,
     415,    20,   415,    20,   415,    20,   415,    20,   415,    20,
     415,    20,   415,    20,   415,    20,   415,    20,   415,    20,
     415,    14,    -1,   368,    13,   416,    20,   415,    20,   415,
      14,    -1,   374,    13,   416,    20,   415,    14,    -1,   374,
      13,   416,    14,    -1,   375,    13,   416,    20,   415,    14,
      -1,   375,    13,   416,    14,    -1,   380,    13,   416,    20,
     416,    14,    -1,   381,    13,   416,    14,    -1,   382,    13,
     417,    14,    -1,   351,    13,   416,    20,   415,    20,   415,
      20,   415,    20,   415,    20,   415,    20,   415,    20,   415,
      14,    -1,   205,    13,    73,    20,   419,    20,   416,    14,
      -1,   207,    13,    73,    20,   417,    14,    -1,   420,    -1,
      62,    -1,   410,    -1,   445,    -1,    73,    -1,    60,    -1,
     414,    -1,   421,    -1,   442,    -1,   422,    -1,   441,    -1,
     242,    15,   415,    16,    -1,   112,    13,   439,    20,   439,
      14,    -1,    13,   439,    14,    -1,   423,    -1,   450,    -1,
     424,    19,   443,    -1,   424,    13,   408,    14,    -1,     9,
     423,    -1,   424,    99,    -1,   424,   100,    -1,   424,   108,
      -1,   424,    15,   439,    16,    -1,   424,    -1,    13,   418,
      14,   425,    -1,    11,   425,    -1,    10,   425,    -1,    99,
     424,    -1,   100,   425,    -1,   306,   425,    -1,   307,   425,
      -1,   317,   425,    -1,   318,   425,    -1,   319,   425,    -1,
     320,   425,    -1,   308,   425,    -1,   309,   425,    -1,   310,
     425,    -1,   311,   425,    -1,   314,   425,    -1,   316,   425,
      -1,   315,   425,    -1,   321,   425,    -1,   425,    -1,   426,
       7,   425,    -1,   426,     8,   425,    -1,   426,    12,   425,
      -1,   426,    -1,   427,    10,   426,    -1,   427,    11,   426,
      -1,   427,    -1,   428,    -1,   429,     6,   428,    -1,   429,
       5,   428,    -1,   429,   104,   428,    -1,   429,   105,   428,
      -1,   429,    -1,   430,   106,   429,    -1,   430,   107,   429,
      -1,   430,    -1,   431,    17,   430,    -1,   431,    -1,   432,
      -1,   433,    18,   432,    -1,   433,    -1,   434,   102,   433,
      -1,   434,    -1,   435,     4,   434,    -1,   435,    -1,   436,
     103,   435,    -1,   436,    -1,   436,    21,   436,    22,   437,
      -1,   437,    -1,   437,   110,   438,    -1,   437,    89,   438,
      -1,   437,    90,   438,    -1,   437,    91,   438,    -1,   437,
      92,   438,    -1,   437,    93,   438,    -1,   438,    -1,    74,
      -1,    64,    19,   263,    -1,   265,    13,    74,    20,    74,
      20,   415,    14,    -1,    41,    13,   417,    14,    -1,   266,
      13,   415,    20,   415,    14,    -1,    65,    -1,   267,    13,
     439,    14,    -1,   231,    13,   416,    20,   415,    14,    -1,
     234,    13,   419,    20,   415,    14,    -1,   231,    13,   416,
      20,   415,    20,   419,    14,    -1,   239,    13,   416,    20,
     415,    20,   416,    14,    -1,   235,    13,    73,    14,    -1,
     235,    13,    73,    20,   415,    14,    -1,   236,    13,   419,
      20,   415,    14,    -1,   237,    13,    73,    20,   415,    14,
      -1,   238,    13,    73,    20,   415,    14,    -1,   242,    13,
      14,    -1,   242,   417,    -1,   206,    13,   417,    14,    -1,
     206,    13,   417,    20,   415,    14,    -1,   194,    13,   419,
      14,    -1,   195,    13,    73,    14,    -1,   195,    13,    73,
      20,   415,    20,   415,    20,   415,    14,    -1,   196,    13,
      73,    20,   415,    14,    -1,   201,    13,    73,    20,   415,
      20,   415,    20,   415,    20,   415,    20,   415,    20,   415,
      14,    -1,   202,    13,   416,    20,   415,    20,   415,    20,
     415,    20,   415,    20,   415,    20,   415,    20,   415,    14,
      -1,   203,    13,   416,    20,   415,    20,   415,    20,   415,
      14,    -1,   204,    13,   416,    20,   415,    20,   415,    20,
     415,    20,   415,    20,   415,    20,   415,    20,   415,    20,
     415,    14,    -1,   204,    13,   416,    20,   415,    20,   415,
      20,   415,    20,   415,    20,   415,    14,    -1,   371,    13,
     416,    14,    -1,   371,    13,   416,    20,   415,    14,    -1,
     371,    13,   416,    20,   415,    20,   415,    14,    -1,   373,
      13,   416,    20,   415,    20,   415,    14,    -1,   372,    13,
     416,    20,   415,    20,   415,    20,   416,    20,   416,    14,
      -1,   372,    13,   416,    20,   415,    20,   415,    20,   416,
      20,   416,    20,   416,    20,   415,    14,    -1,   376,    13,
     416,    20,   416,    20,   416,    20,   415,    20,   415,    20,
     415,    20,   415,    14,    -1,   376,    13,   416,    20,   416,
      20,   416,    20,   415,    20,   415,    20,   415,    20,   415,
      20,   415,    14,    -1,   376,    13,   416,    20,   416,    20,
     416,    20,   415,    20,   415,    20,   415,    14,    -1,   377,
      13,   416,    20,   415,    20,   415,    20,   415,    20,   415,
      20,   415,    14,    -1,   379,    13,   416,    20,   416,    20,
     416,    20,   415,    20,   415,    20,   415,    20,   415,    14,
      -1,   379,    13,   416,    20,   416,    20,   416,    20,   415,
      20,   415,    20,   415,    20,   415,    20,   416,    20,   416,
      14,    -1,    59,    -1,    74,    -1,    67,    -1,    68,    -1,
      70,    -1,    69,    -1,    71,    -1,    64,    -1,    66,    -1,
      72,    -1,    75,    -1,   444,    -1,   446,    -1,    73,    -1,
      60,    -1,    62,    -1,    65,    -1,   419,    -1,   447,    -1,
     448,    -1,   445,    -1,   423,    22,   423,    20,   423,    22,
     423,    20,   423,    22,   423,    -1,   423,    22,   423,    20,
     423,    22,   423,    -1,    22,    20,    22,    20,   415,    22,
     415,    -1,   419,    19,    87,    -1
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
     410,   414,   418,   421,   428,   439,   446,   457,   468,   481,
     488,   495,   499,   503,   507,   511,   516,   520,   527,   534,
     539,   560,   571,   578,   582,   586,   593,   597,   604,   613,
     620,   627,   636,   653,   660,   664,   671,   680,   684,   697,
     710,   723,   734,   738,   742,   751,   760,   771,   780,   791,
     804,   811,   820,   831,   848,   867,   880,   887,   906,   923,
     936,   947,   958,   969,   976,   987,   994,  1001,  1008,  1017,
    1022,  1027,  1036,  1041,  1060,  1065,  1067,  1069,  1071,  1078,
    1082,  1087,  1089,  1091,  1093,  1124,  1149,  1158,  1160,  1164,
    1165,  1167,  1171,  1174,  1179,  1181,  1185,  1186,  1189,  1192,
    1195,  1198,  1201,  1206,  1211,  1216,  1221,  1226,  1228,  1235,
    1237,  1241,  1246,  1251,  1253,  1257,  1258,  1259,  1261,  1263,
    1265,  1267,  1274,  1283,  1294,  1305,  1316,  1325,  1332,  1336,
    1340,  1344,  1348,  1352,  1356,  1360,  1364,  1368,  1372,  1376,
    1380,  1387,  1392,  1403,  1408,  1419,  1424,  1429,  1434,  1439,
    1444,  1449,  1457,  1465,  1473,  1483,  1491,  1498,  1503,  1510,
    1521,  1526,  1531,  1536,  1540,  1547,  1554,  1561,  1563,  1565,
    1567,  1569,  1571,  1573,  1575,  1577,  1579,  1581,  1583,  1585,
    1587,  1589,  1593,  1595,  1600,  1602,  1605,  1610,  1615,  1617,
    1628,  1641,  1650,  1657,  1664,  1671,  1680,  1689,  1696,  1705,
    1714,  1725,  1736,  1749,  1762,  1773,  1778,  1789,  1794,  1801,
    1806,  1811,  1816,  1829,  1834,  1847,  1860,  1877,  1898,  1909,
    1922,  1927,  1934,  1941,  1948,  1953,  1958,  1965,  1970,  1977,
    1984,  1991,  2008,  2019,  2028,  2041,  2052,  2061,  2074,  2083,
    2096,  2105,  2118,  2131,  2146,  2159,  2172,  2189,  2194,  2203,
    2214,  2227,  2238,  2251,  2262,  2275,  2288,  2303,  2316,  2325,
    2340,  2345,  2350,  2355,  2360,  2364,  2368,  2375,  2382,  2389,
    2396,  2405,  2420,  2433,  2448,  2461,  2468,  2477,  2488,  2499,
    2512,  2519,  2526,  2533,  2540,  2547,  2554,  2561,  2568,  2577,
    2588,  2593,  2598,  2609,  2620,  2625,  2632,  2639,  2652,  2683,
    2692,  2699,  2704,  2711,  2716,  2723,  2728,  2733,  2752,  2761,
    2768,  2770,  2772,  2774,  2776,  2778,  2780,  2782,  2784,  2786,
    2788,  2790,  2795,  2802,  2806,  2808,  2810,  2814,  2819,  2822,
    2825,  2828,  2831,  2836,  2838,  2843,  2846,  2849,  2852,  2855,
    2858,  2861,  2864,  2867,  2870,  2873,  2876,  2879,  2882,  2885,
    2888,  2891,  2894,  2897,  2899,  2903,  2907,  2911,  2913,  2917,
    2921,  2923,  2925,  2929,  2933,  2937,  2941,  2943,  2947,  2951,
    2953,  2957,  2959,  2961,  2965,  2967,  2971,  2973,  2977,  2979,
    2983,  2985,  2991,  2993,  2997,  3001,  3005,  3009,  3013,  3017,
    3019,  3021,  3025,  3034,  3039,  3046,  3048,  3053,  3060,  3067,
    3076,  3085,  3090,  3097,  3104,  3111,  3118,  3122,  3125,  3130,
    3137,  3142,  3147,  3158,  3165,  3182,  3201,  3212,  3233,  3248,
    3253,  3260,  3269,  3278,  3291,  3308,  3325,  3344,  3359,  3374,
    3391,  3412,  3414,  3416,  3418,  3420,  3422,  3424,  3426,  3428,
    3430,  3432,  3434,  3436,  3438,  3440,  3442,  3444,  3446,  3448,
    3450,  3452,  3454,  3466,  3474,  3482
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   838,   838,   839,   843,   843,   844,   845,   846,   846,
     847,   847,   848,   848,   849,   849,   850,   850,   851,   851,
     854,   855,   860,   879,   899,   945,   968,  1017,  1032,  1055,
    1054,  1086,  1085,  1131,  1148,  1170,  1191,  1198,  1233,  1243,
    1259,  1292,  1300,  1310,  1324,  1338,  1352,  1362,  1378,  1396,
    1411,  1436,  1474,  1502,  1575,  1586,  1612,  1651,  1746,  1758,
    1777,  1788,  1875,  1909,  1925,  1931,  1935,  1939,  1943,  1953,
    1958,  1962,  1972,  1987,  1997,  2008,  2011,  2070,  2094,  2144,
    2234,  2260,  2264,  2276,  2290,  2300,  2311,  2319,  2331,  2567,
    2577,  2587,  2597,  2606,  2671,  2685,  2719,  2731,  2772,  2791,
    3264,  3286,  3310,  3332,  3344,  3358,  3377,  3399,  3428,  3457,
    3489,  3686,  3691,  3698,  3703,  3943,  3971,  3985,  3992,  3998,
    4006,  4107,  4114,  4122,  4130,  4138,  4149,  4159,  4167,  4175,
    4186,  4193,  4207,  4221,  4230,  4235,  4244,  4253,  4266,  4279,
    4292,  4305,  4312,  4322,  4332,  4346,  4354,  4365,  4388,  4414,
    4442,  4453,  4496,  4518,  4547,  4564,  4579,  4585,  4612,  4638,
    4658,  4675,  4681,  4687,  4698,  4704,  4712,  4727,  4736,  4747,
    4764,  4780,  4818,  4832,  4879,  4885,  4890,  4895,  4901,  4908,
    4914,  4921,  4926,  4931,  4936,  4979,  5033,  5055,  5063,  5080,
    5084,  5100,  5118,  5133,  5148,  5169,  5194,  5199,  5208,  5215,
    5222,  5229,  5245,  5252,  5259,  5266,  5273,  5291,  5296,  5377,
    5401,  5406,  5419,  5438,  5469,  5480,  5481,  5486,  5490,  5498,
    5506,  5515,  5532,  5548,  5565,  5584,  5602,  5618,  5634,  5640,
    5646,  5652,  5658,  5664,  5670,  5676,  5682,  5688,  5694,  5700,
    5707,  5716,  5723,  5754,  5762,  5774,  5794,  5814,  5834,  5854,
    5874,  5894,  5918,  5942,  5966,  5974,  5998,  6021,  6178,  6188,
    6200,  6210,  6220,  6232,  6240,  6256,  6275,  6305,  6323,  6335,
    6356,  6361,  6365,  6369,  6373,  6377,  6381,  6385,  6389,  6393,
    6397,  6401,  6409,  6411,  6430,  6432,  6440,  6460,  6495,  6526,
    6533,  6551,  6642,  6708,  6715,  6722,  6730,  6738,  6754,  6772,
    6790,  6807,  6824,  6842,  6878,  6891,  6902,  6915,  6939,  6950,
    6961,  6971,  6981,  7014,  7025,  7046,  7066,  7107,  7154,  7174,
    7195,  7206,  7220,  7234,  7247,  7258,  7269,  7282,  7300,  7312,
    7324,  7376,  7417,  7428,  7438,  7450,  7461,  7471,  7496,  7519,
    7547,  7561,  7695,  7729,  7762,  7790,  7804,  7818,  7828,  7847,
    7866,  7886,  7907,  7929,  7948,  7967,  7987,  8027,  8049,  8078,
    8100,  8137,  8174,  8211,  8245,  8251,  8268,  8275,  8282,  8290,
    8297,  8319,  8347,  8371,  8398,  8430,  8439,  8452,  8459,  8467,
    8481,  8493,  8505,  8515,  8526,  8536,  8546,  8557,  8567,  8578,
    8605,  8653,  8787,  8808,  8848,  8859,  8867,  8875,  8896,  8922,
    8933,  8940,  8946,  8952,  8959,  8984,  9002,  9009,  9042,  9061,
    9082,  9110,  9119,  9133,  9135,  9137,  9139,  9141,  9143,  9145,
    9147,  9149,  9170,  9312,  9315,  9317,  9319,  9354,  9431,  9439,
    9447,  9455,  9507,  9519,  9521,  9530,  9536,  9541,  9546,  9551,
    9556,  9561,  9566,  9571,  9576,  9581,  9586,  9591,  9596,  9601,
    9606,  9611,  9616,  9625,  9626,  9632,  9638,  9648,  9649,  9656,
    9666,  9670,  9671,  9677,  9683,  9689,  9698,  9699,  9705,  9731,
    9732,  9736,  9740,  9741,  9745,  9746,  9758,  9759,  9771,  9772,
    9784,  9785,  9798,  9799,  9809,  9816,  9822,  9828,  9834,  9843,
    9847,  9857,  9871,  9882,  9900,  9906,  9915, 10060, 10075, 10087,
   10109, 10145, 10154, 10164, 10173, 10183, 10197, 10204, 10213, 10229,
   10248, 10268, 10298, 10327, 10344, 10370, 10404, 10436, 10483, 10524,
   10533, 10555, 10566, 10577, 10613, 10655, 10701, 10751, 10793, 10824,
   10856, 10898, 10906, 10909, 10910, 10911, 10912, 10913, 10920, 10921,
   10922, 10923, 10928, 10929, 10935, 10937, 10939, 10942, 10944, 10948,
   10950, 10952, 10956, 10978, 10995, 11013
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
     385,   386,   387,   388,   389,   390,   391,   392,   393
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 9955;
  const int Parser::yynnts_ = 57;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 555;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 394;

  const unsigned int Parser::yyuser_token_number_max_ = 648;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // yyip

/* Line 1054 of lalr1.cc  */
#line 14601 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"


/* Line 1056 of lalr1.cc  */
#line 11054 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"

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




