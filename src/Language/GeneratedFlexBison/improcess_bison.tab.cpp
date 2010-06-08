
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
#line 11 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"

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
  boost::shared_ptr<type > obj(wobj->_obj);

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
#line 372 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"


#include "improcess_bison.tab.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 817 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"


#include "driver.h"
#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex



/* Line 317 of lalr1.cc  */
#line 395 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"

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
#line 464 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
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
#line 810 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 571 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 59: /* "IDENTIFIER" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 580 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 412: /* "exprstringlist" */

/* Line 480 of lalr1.cc  */
#line 813 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->string_list); };

/* Line 480 of lalr1.cc  */
#line 589 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 415: /* "primary_expr_string" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 598 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 416: /* "instr_block" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ablock); };

/* Line 480 of lalr1.cc  */
#line 607 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 422: /* "expr_string" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 616 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 450: /* "identifier" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 625 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
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
#line 360 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}

/* Line 553 of lalr1.cc  */
#line 711 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"

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
#line 856 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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
#line 875 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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
#line 895 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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
#line 940 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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
#line 963 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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
#line 1012 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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
#line 1027 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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
#line 1049 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GB_driver.procedure_declaration = true;
    }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 1054 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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
#line 1080 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      // allow overriding current functions
      GB_driver.procedure_declaration = true;
    }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 1086 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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
#line 1125 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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
#line 1142 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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
#line 1163 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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
#line 1184 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
       //driver.res_print($2);
       driver.parse_script((yysemantic_stack_[(3) - (2)].astring));
       delete [] (yysemantic_stack_[(3) - (2)].astring);
     }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 1191 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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
#line 1226 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> input((yysemantic_stack_[(2) - (2)].astring));
      string inputstring( input.get());
      driver.parse_string( inputstring,
                          "'eval string' command");
    }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 1236 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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
#line 1269 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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
#line 1301 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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
#line 1309 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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
#line 1320 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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
#line 1334 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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
#line 1348 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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
#line 1362 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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
#line 1372 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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
#line 1388 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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
#line 1406 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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
#line 1421 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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
#line 1436 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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
#line 1467 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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
#line 1495 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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
#line 1542 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
        IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));

        int size = (int) (yysemantic_stack_[(6) - (5)].adouble);
        if (size<1) size = 1;
        VarArray::ptr arraysurf(new VarArray());
        arraysurf->Init(type_surface,size);
        Vars.AddVar<VarArray>(ident,arraysurf);
      }
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 1553 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
        IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));
        int size = (int) (yysemantic_stack_[(6) - (5)].adouble);
        if (size<1) size = 1;
        VarArray::ptr arraysurf( new VarArray());
        arraysurf->Init(type_surface,size);
        Vars.AddVar<VarArray>(ident,arraysurf);
      }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 1563 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
            IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));
            int size = (int) (yysemantic_stack_[(6) - (5)].adouble);
            if (size<1) size = 1;
            VarArray::ptr array(new VarArray());
            array->Init(type_image,size);
            Vars.AddVar<VarArray>(ident,array);
          }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 1574 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 58:

/* Line 678 of lalr1.cc  */
#line 1600 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 59:

/* Line 678 of lalr1.cc  */
#line 1639 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 60:

/* Line 678 of lalr1.cc  */
#line 1669 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_OBJECT(SurfacePoly,surfptr)
          GET_VARSTACK_VAR_VAL(VarArray,vararray,array)

          int  i = (int) (yysemantic_stack_[(6) - (3)].adouble);
          char name[256];

          if (surfptr.get()) {
            if (!array->GetVar(i).get()) {
              sprintf(name,"%s[%d]",vararray->Name().c_str(),i);
              array->InitElement<SurfacePoly>(i,surfptr,name);
            }
            else
            {
              driver.err_print("array element already assigned\n");
            }
          }
          else
            driver.err_print("assignment of NULL surface\n");
        }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1710 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(VarArray,var,array)
          int size = (int) (yysemantic_stack_[(6) - (5)].adouble);
          if (size<1) size = 1;
          VarArray::ptr arraysurf( new VarArray());
          arraysurf->Init(type_surface,size);

          // instead of deleting and creating,
          // replace the pointer and the information
          if (arraysurf != NULL) {
            var->Delete();
            var->Init(var->Name().c_str(),
                      arraysurf);
          }
          else
            driver.err_print("not able to create surface array !\n");

      }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1730 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 63:

/* Line 678 of lalr1.cc  */
#line 1742 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 64:

/* Line 678 of lalr1.cc  */
#line 1761 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 65:

/* Line 678 of lalr1.cc  */
#line 1772 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 66:

/* Line 678 of lalr1.cc  */
#line 1859 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 67:

/* Line 678 of lalr1.cc  */
#line 1893 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 68:

/* Line 678 of lalr1.cc  */
#line 1909 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
          Variable<FILE>::ptr varfile(driver.var_stack.GetLastVar<FILE>());
          FILE_ptr file(varfile->Pointer());
          rewind(file.get());
        }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1915 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GB_debug = 1;
        }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1919 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GB_debug = 0;
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1923 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      driver.SetTraceScanning((yysemantic_stack_[(2) - (2)].adouble)>0.5);
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1927 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 73:

/* Line 678 of lalr1.cc  */
#line 1937 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 1;
      verbose = 1;
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1942 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 0;
    }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1946 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 76:

/* Line 678 of lalr1.cc  */
#line 1956 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 77:

/* Line 678 of lalr1.cc  */
#line 1971 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 78:

/* Line 678 of lalr1.cc  */
#line 1981 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 79:

/* Line 678 of lalr1.cc  */
#line 1991 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
          GB_main_wxFrame->Close(true);
        }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 1995 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 81:

/* Line 678 of lalr1.cc  */
#line 2045 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 82:

/* Line 678 of lalr1.cc  */
#line 2068 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 83:

/* Line 678 of lalr1.cc  */
#line 2118 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 84:

/* Line 678 of lalr1.cc  */
#line 2208 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 85:

/* Line 678 of lalr1.cc  */
#line 2260 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
          Vars.display();
        }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 2264 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 87:

/* Line 678 of lalr1.cc  */
#line 2276 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 88:

/* Line 678 of lalr1.cc  */
#line 2290 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 89:

/* Line 678 of lalr1.cc  */
#line 2300 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
          Variable<VarArray>::ptr vararray(driver.var_stack.GetLastVar<VarArray>());
          VarArray::ptr array (vararray->Pointer());
          int  i = (int) (yysemantic_stack_[(5) - (4)].adouble);

          if (array->GetVar(i).get()) {
            array->GetVar(i) = BasicVariable::ptr();
          }
      }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 2310 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 91:

/* Line 678 of lalr1.cc  */
#line 2321 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      /**
        Description:
        Calls system 'ls' command (for unix systems)
      **/
         std::system("ls");
           }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 2329 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 93:

/* Line 678 of lalr1.cc  */
#line 2341 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 94:

/* Line 678 of lalr1.cc  */
#line 2577 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 95:

/* Line 678 of lalr1.cc  */
#line 2587 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 96:

/* Line 678 of lalr1.cc  */
#line 2597 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 97:

/* Line 678 of lalr1.cc  */
#line 2607 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        Displays the documentation relative to the wrapped c++ member.
    **/
      GET_VARSTACK_VALUE(WrapClassMember, m);
      m->ShowHelp();
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 2616 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 99:

/* Line 678 of lalr1.cc  */
#line 2681 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 100:

/* Line 678 of lalr1.cc  */
#line 2695 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 101:

/* Line 678 of lalr1.cc  */
#line 2729 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 102:

/* Line 678 of lalr1.cc  */
#line 2741 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 103:

/* Line 678 of lalr1.cc  */
#line 2782 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 104:

/* Line 678 of lalr1.cc  */
#line 2801 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
          driver.var_stack.GetLastBasicVar();
          printf("Deprecated: No need to close files explicitly, since we use smart pointers, they will be closed when the variable is deleted. \n");
        }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 3274 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 106:

/* Line 678 of lalr1.cc  */
#line 3296 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 107:

/* Line 678 of lalr1.cc  */
#line 3320 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 108:

/* Line 678 of lalr1.cc  */
#line 3342 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 109:

/* Line 678 of lalr1.cc  */
#line 3354 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 110:

/* Line 678 of lalr1.cc  */
#line 3368 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 111:

/* Line 678 of lalr1.cc  */
#line 3387 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 112:

/* Line 678 of lalr1.cc  */
#line 3409 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 113:

/* Line 678 of lalr1.cc  */
#line 3440 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 114:

/* Line 678 of lalr1.cc  */
#line 3467 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 115:

/* Line 678 of lalr1.cc  */
#line 3499 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> name((yysemantic_stack_[(6) - (5)].astring));
      GET_VARSTACK_VALUE(InrImage, im);
      im->FixeNom( name.get());
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 3696 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 3701 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {

      Func_EndWeickert();

    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 3708 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 3713 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      Func_EndWeickert();
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 3953 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 121:

/* Line 678 of lalr1.cc  */
#line 3981 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 122:

/* Line 678 of lalr1.cc  */
#line 3995 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im2);
      GET_VARSTACK_VALUE(InrImage, im1);
      Func_OrientField( im1.get() , im2.get() );
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 4002 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im2);
      GET_VARSTACK_VALUE(InrImage, im1);
      Func_OrientPositive( im1.get(), im2.get());
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 4008 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      if (strlen((yysemantic_stack_[(4) - (3)].astring))<255) {
        strcpy(AMIFluid::FLUID_NAVIGATION_FILE,(yysemantic_stack_[(4) - (3)].astring));
      } else
        fprintf(stderr,"SetFluidNavFile() \t File too long \n");
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 4017 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 126:

/* Line 678 of lalr1.cc  */
#line 4117 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,sdraw);

          sdraw->GetCanvas()->UserRotate((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 4124 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_OBJECT(SurfacePoly,surf)
          GET_VARSTACK_VALUE(Viewer3D,sdraw);

          sdraw->GetCanvas()->AddSurface(surf);
          sdraw->Paint();
        }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 4132 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_OBJECT(SurfacePoly,surf)
          GET_VARSTACK_VALUE(Viewer3D,   sdraw);

          sdraw->GetCanvas()->AddSurface( surf);
          //sdraw->Paint();
        }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 4140 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_OBJECT(SurfacePoly,surf)
          GET_VARSTACK_VALUE(Viewer3D,   sdraw);

          sdraw->GetCanvas()->RemoveSurface(surf);
          sdraw->Paint();
        }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 4148 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 131:

/* Line 678 of lalr1.cc  */
#line 4159 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
          /**
            Description:  Swaps the 3D buffer
          **/
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw(varsurfd->Pointer());

          sdraw->GetCanvas()->AfficheBuffer();
        }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 4169 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC ( (int) (yysemantic_stack_[(6) - (5)].adouble) );
          sdraw->Paint();
        }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 4177 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
          sdraw->Paint();
        }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 4185 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 135:

/* Line 678 of lalr1.cc  */
#line 4196 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,sdraw2);
          GET_VARSTACK_VALUE(Viewer3D,sdraw1);

          sdraw1->AddCompSurf(sdraw2);
        }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 4203 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 137:

/* Line 678 of lalr1.cc  */
#line 4217 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 138:

/* Line 678 of lalr1.cc  */
#line 4231 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr draw (varsurfd->Pointer());
          int num = (int) (yysemantic_stack_[(6) - (5)].adouble);
    
          draw->GetCanvas()->HideFreeSection(num);
    
        }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 4240 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,v);
          v->GetCanvas()->PrintMatrices();
        }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 4245 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->GetCanvas()->SetObjectTransform(*tr);
              sdraw->Paint();
          delete tr;
        }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 4254 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->GetCanvas()->SetObjectTransform(*tr);
          if ((yysemantic_stack_[(8) - (7)].adouble)>0.5) sdraw->Paint();
          delete tr;
        }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 4263 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 143:

/* Line 678 of lalr1.cc  */
#line 4276 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 144:

/* Line 678 of lalr1.cc  */
#line 4289 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 145:

/* Line 678 of lalr1.cc  */
#line 4302 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 146:

/* Line 678 of lalr1.cc  */
#line 4315 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->GetCanvas()->SetBG((int)(yysemantic_stack_[(10) - (5)].adouble),(int)(yysemantic_stack_[(10) - (7)].adouble),(int)(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 4322 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 148:

/* Line 678 of lalr1.cc  */
#line 4332 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 149:

/* Line 678 of lalr1.cc  */
#line 4342 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 150:

/* Line 678 of lalr1.cc  */
#line 4356 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          Func_StructureTensor(im.get(),
                   varim->Name().c_str(),
                   (yysemantic_stack_[(8) - (5)].adouble), (yysemantic_stack_[(8) - (7)].adouble), NULL);
        }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 4364 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage,mask);
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);

          Func_StructureTensor(
            im.get(),
            varim->Name().c_str(),
            (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), mask.get());
        }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 4375 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 153:

/* Line 678 of lalr1.cc  */
#line 4398 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 154:

/* Line 678 of lalr1.cc  */
#line 4424 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 155:

/* Line 678 of lalr1.cc  */
#line 4452 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 156:

/* Line 678 of lalr1.cc  */
#line 4463 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 157:

/* Line 678 of lalr1.cc  */
#line 4506 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 158:

/* Line 678 of lalr1.cc  */
#line 4528 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 159:

/* Line 678 of lalr1.cc  */
#line 4557 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 160:

/* Line 678 of lalr1.cc  */
#line 4575 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 161:

/* Line 678 of lalr1.cc  */
#line 4589 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          Func_Curvatures(im.get(), varim->Name().c_str(), (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 4600 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 163:

/* Line 678 of lalr1.cc  */
#line 4626 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 164:

/* Line 678 of lalr1.cc  */
#line 4652 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 165:

/* Line 678 of lalr1.cc  */
#line 4671 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 166:

/* Line 678 of lalr1.cc  */
#line 4685 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      im->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 4691 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      im->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 4697 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 169:

/* Line 678 of lalr1.cc  */
#line 4708 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      im->SetTranslation((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 4714 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2( driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1( driver.var_stack.GetLastVar<InrImage>());
      InrImage::ptr im (varim2->Pointer());
      varim1->Pointer()->SetVoxelSize( im->TrX(), im->TrY(), im->TrZ());
    }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 4722 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 172:

/* Line 678 of lalr1.cc  */
#line 4737 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
      Func_DiscSecDerGrad(
        varim1->Pointer().get(),
        varim2->Pointer().get());
    }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 4746 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 174:

/* Line 678 of lalr1.cc  */
#line 4757 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 175:

/* Line 678 of lalr1.cc  */
#line 4774 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 176:

/* Line 678 of lalr1.cc  */
#line 4790 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 177:

/* Line 678 of lalr1.cc  */
#line 4828 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 178:

/* Line 678 of lalr1.cc  */
#line 4846 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 179:

/* Line 678 of lalr1.cc  */
#line 4889 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));
      Func_GenRead(filename.get());
    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 4895 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.InitCumul();
    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 4900 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Debut();
    }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 4905 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Fin();
      cout << "time spent = " << driver.IP_time << endl;
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 4911 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
          boost::shared_array<char> filename( (yysemantic_stack_[(6) - (5)].astring));
          GET_VARSTACK_VALUE(InrImage, i);
          Func_VectorImage2StructuredGrid(i.get(),filename.get());
        }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 4918 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(GLTransfMatrix, glmat);
          glmat->Print();
        }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 4924 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
          boost::shared_array<char> filename( (yysemantic_stack_[(4) - (4)].astring));
          GET_VARSTACK_VALUE(GLTransfMatrix, glmat);
          Func_SaveTransform(glmat.get(),filename.get());
        }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 4931 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
          AddWrapVTK();
        }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 4936 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
          AddWrapWII();
        }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 4941 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
          AddWrapFilters();
        }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 4952 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 190:

/* Line 678 of lalr1.cc  */
#line 4992 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 191:

/* Line 678 of lalr1.cc  */
#line 5043 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 192:

/* Line 678 of lalr1.cc  */
#line 5065 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = new std::list<std::string>();
            sl->push_back(string((yysemantic_stack_[(1) - (1)].astring)));
            delete [] (yysemantic_stack_[(1) - (1)].astring);
            (yyval.string_list) = sl;
        }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 5073 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = (yysemantic_stack_[(3) - (1)].string_list);
            sl->push_back(string((yysemantic_stack_[(3) - (3)].astring)));
            delete [] (yysemantic_stack_[(3) - (3)].astring);
            (yyval.string_list) = sl;
        }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 5089 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          (yyval.paramlist) = pl;
        }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 5094 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 196:

/* Line 678 of lalr1.cc  */
#line 5110 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 197:

/* Line 678 of lalr1.cc  */
#line 5128 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 198:

/* Line 678 of lalr1.cc  */
#line 5144 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 199:

/* Line 678 of lalr1.cc  */
#line 5159 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 200:

/* Line 678 of lalr1.cc  */
#line 5175 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 201:

/* Line 678 of lalr1.cc  */
#line 5194 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      //      printf("no parameters \n");
      ParamListDecl* pl = new ParamListDecl;
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 5200 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      cout << "param_list_decl: T_NUM IDENTIFIER" << endl;
      cout << ident->GetName().c_str() << endl;
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_float);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 5209 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_ami_object);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 5216 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_string);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 5223 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 5230 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 5237 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 5244 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_ami_object);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 5251 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_float);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 5258 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_string);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 5265 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 5272 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 5279 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 5287 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
    }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 5292 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 216:

/* Line 678 of lalr1.cc  */
#line 5373 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 217:

/* Line 678 of lalr1.cc  */
#line 5396 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      (yyval.astring)=(char*) (im)->GetName();
    }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 5402 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 219:

/* Line 678 of lalr1.cc  */
#line 5414 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 220:

/* Line 678 of lalr1.cc  */
#line 5434 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      char* res = new char[GB_scripts_dir.Len()+1];
      strcpy(res,(const char*)GB_scripts_dir.mb_str(wxConvUTF8));
      (yyval.astring)= res;
    }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 5467 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
        (yyval.ablock)=(yysemantic_stack_[(3) - (2)].ablock);
        if (GB_debug)
          cerr << format("ablock : %s")
                  % (yysemantic_stack_[(3) - (2)].ablock)->GetBody()
                << endl;
          }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 5482 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      ADD_VARSTACK_FLOAT((yysemantic_stack_[(1) - (1)].adouble))
    }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 5486 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      returns the number of arguments in the command line
    **/
      ADD_VARSTACK_FLOAT(GB_argc-GB_num_arg_parsed)
    }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 5494 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      Line number in the current script
    **/
      ADD_VARSTACK_FLOAT(driver.yyiplineno)
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 5502 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        the constant Pi is set to
         3.14159265358979323846
      **/
      ADD_VARSTACK_FLOAT(3.14159265358979323846)
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 5531 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 229:

/* Line 678 of lalr1.cc  */
#line 5548 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 230:

/* Line 678 of lalr1.cc  */
#line 5564 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 231:

/* Line 678 of lalr1.cc  */
#line 5581 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 232:

/* Line 678 of lalr1.cc  */
#line 5600 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 233:

/* Line 678 of lalr1.cc  */
#line 5618 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 234:

/* Line 678 of lalr1.cc  */
#line 5634 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 235:

/* Line 678 of lalr1.cc  */
#line 5650 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->DimX();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 5656 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->DimY();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 5662 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->DimZ();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 5668 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->TrX();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 5674 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->TrY();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 5680 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->TrZ();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 5686 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->VoxSizeX();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 5692 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->VoxSizeY();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 5698 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->VoxSizeZ();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 5704 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->GetVDim();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 5710 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->IncBuffer();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 5716 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->ValeurBuffer();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 5723 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
      float val=Func_SNR(varim1->Pointer().get(),
                  varim2->Pointer().get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 5732 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      float val=Func_eccentricity(im.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 5739 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 250:

/* Line 678 of lalr1.cc  */
#line 5770 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(InrImage, im);
      float val=Func_ComputePositiveArea( im.get() );
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 5778 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 252:

/* Line 678 of lalr1.cc  */
#line 5790 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 253:

/* Line 678 of lalr1.cc  */
#line 5810 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 254:

/* Line 678 of lalr1.cc  */
#line 5830 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 255:

/* Line 678 of lalr1.cc  */
#line 5850 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 256:

/* Line 678 of lalr1.cc  */
#line 5870 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 257:

/* Line 678 of lalr1.cc  */
#line 5890 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 258:

/* Line 678 of lalr1.cc  */
#line 5910 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 259:

/* Line 678 of lalr1.cc  */
#line 5934 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 260:

/* Line 678 of lalr1.cc  */
#line 5958 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 261:

/* Line 678 of lalr1.cc  */
#line 5982 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      GET_VARSTACK_VALUE(InrImage, mask);
      float val=Func_med( im.get(),(float) (yysemantic_stack_[(9) - (8)].adouble),mask.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 5990 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 263:

/* Line 678 of lalr1.cc  */
#line 6014 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 264:

/* Line 678 of lalr1.cc  */
#line 6037 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      setlocale(LC_NUMERIC, "C");
      float val=atof((yysemantic_stack_[(4) - (3)].astring));
      ADD_VARSTACK_FLOAT(val);
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 6193 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 267:

/* Line 678 of lalr1.cc  */
#line 6203 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 268:

/* Line 678 of lalr1.cc  */
#line 6215 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 269:

/* Line 678 of lalr1.cc  */
#line 6225 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 270:

/* Line 678 of lalr1.cc  */
#line 6235 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 271:

/* Line 678 of lalr1.cc  */
#line 6247 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      /**
        Description: returns the value of the pixel format type in float format
      **/
      float val = (int) (yysemantic_stack_[(3) - (1)].aint);
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 6255 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 273:

/* Line 678 of lalr1.cc  */
#line 6271 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(float,val_ptr);
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

  case 274:

/* Line 678 of lalr1.cc  */
#line 6286 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 275:

/* Line 678 of lalr1.cc  */
#line 6316 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 276:

/* Line 678 of lalr1.cc  */
#line 6334 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 277:

/* Line 678 of lalr1.cc  */
#line 6346 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 278:

/* Line 678 of lalr1.cc  */
#line 6367 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      driver.err_print(" char format is not available: use unsigned char \n");
      (yyval.aint)=WT_UNSIGNED_CHAR;
    }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 6372 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
          (yyval.aint)=WT_UNSIGNED_CHAR;
       }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 6376 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_SHORT;
       }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 6380 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_SHORT;
       }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 6384 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_INT;
       }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 6388 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_INT;
       }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 6392 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_LONG;
       }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 6396 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT;
       }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 6400 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_DOUBLE;
       }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 6404 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_RGB;
       }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 6408 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT_VECTOR;
       }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 6412 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
         //        printf("format %d \n",(int) ( *(InrImage::ptr*) $1->Pointer())->GetFormat());
        GET_VARSTACK_VALUE(InrImage, im);
        (yyval.aint) = (int) im->GetFormat();
      }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 6422 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 292:

/* Line 678 of lalr1.cc  */
#line 6441 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
        boost::shared_array<char> st( (yysemantic_stack_[(2) - (2)].astring));
        InrImage* res = ReadImage(st.get());
        if (!res) YYABORT;
        else
          ADD_VARSTACK(InrImage,res);
      }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 6449 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 294:

/* Line 678 of lalr1.cc  */
#line 6469 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 295:

/* Line 678 of lalr1.cc  */
#line 6504 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 296:

/* Line 678 of lalr1.cc  */
#line 6535 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
        //printf(" ********** %d %f %f %f\n", $3, $5, $7, $9);
        InrImage::ptr im (new InrImage( (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble), (WORDTYPE) (yysemantic_stack_[(10) - (3)].aint)));
        ADD_VARSTACK_PTR(InrImage,im);
      }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 6542 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 298:

/* Line 678 of lalr1.cc  */
#line 6560 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 300:

/* Line 678 of lalr1.cc  */
#line 6653 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 301:

/* Line 678 of lalr1.cc  */
#line 6719 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      InrImage* res =Func_localmean( im.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      ADD_VARSTACK(InrImage,res);
    }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 6726 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      InrImage* res =Func_localmean2( im.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      ADD_VARSTACK(InrImage,res);
    }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 6733 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, mean);
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage* res     = Func_localSD( im.get(), mean.get(), (int) (yysemantic_stack_[(8) - (7)].adouble));
      ADD_VARSTACK(InrImage,res);
    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 6741 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, mean);
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res(Func_localSD2( im.get(), mean.get(), (int) (yysemantic_stack_[(8) - (7)].adouble)));
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 6749 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 306:

/* Line 678 of lalr1.cc  */
#line 6765 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 307:

/* Line 678 of lalr1.cc  */
#line 6783 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 308:

/* Line 678 of lalr1.cc  */
#line 6801 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 309:

/* Line 678 of lalr1.cc  */
#line 6818 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 310:

/* Line 678 of lalr1.cc  */
#line 6836 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 311:

/* Line 678 of lalr1.cc  */
#line 6856 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 312:

/* Line 678 of lalr1.cc  */
#line 6889 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 313:

/* Line 678 of lalr1.cc  */
#line 6902 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkDist( im.get()));

        Si (!res.get()) Alors
          driver.err_print("vtkDist() erreur ... \n");
        FinSi
        ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 6913 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 315:

/* Line 678 of lalr1.cc  */
#line 6926 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 316:

/* Line 678 of lalr1.cc  */
#line 6950 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, input);
        InrImage::ptr res (Func_2DFlux(input.get(),(yysemantic_stack_[(6) - (5)].adouble)));

      Si (res.get()) Alors
        driver.err_print("2DFlux() error ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 6961 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_OutFlux( im.get()));

      Si (!res.get()) Alors
        driver.err_print("OutFlux() erreur ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 6972 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_OutFluxScalar( im.get()));
    Si (!res.get()) Alors
      driver.err_print("OutFluxScalar() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 6982 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_OrientationRatio2D( im.get()));
    Si (!res.get()) Alors
      driver.err_print("OrientationRatio() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 6992 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 321:

/* Line 678 of lalr1.cc  */
#line 7025 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_SimplePoints( im.get() ));

    Si !res.get() Alors
      driver.err_print("SimplePoints() error ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 7037 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 323:

/* Line 678 of lalr1.cc  */
#line 7058 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 324:

/* Line 678 of lalr1.cc  */
#line 7078 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 325:

/* Line 678 of lalr1.cc  */
#line 7119 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 326:

/* Line 678 of lalr1.cc  */
#line 7165 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 327:

/* Line 678 of lalr1.cc  */
#line 7185 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 328:

/* Line 678 of lalr1.cc  */
#line 7206 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res( Func_NormalSmoothField( im.get() ));

    Si !res.get() Alors
      driver.err_print("NormalField() error ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 7217 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 330:

/* Line 678 of lalr1.cc  */
#line 7231 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 331:

/* Line 678 of lalr1.cc  */
#line 7247 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, input);
  
      InrImage::ptr res ( Func_NormGrad( input.get(), (yysemantic_stack_[(6) - (5)].adouble)));
      Si (!res.get()) Alors
        driver.err_print("NormGrad() error ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 7259 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_DiscNormGrad( im.get()));
    Si !res.get() Alors
      driver.err_print("discnormgrad() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 7270 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_DiscMeanCurvature( im.get()));
    Si !res.get() Alors
      driver.err_print("DiscMeanCurvature() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 7282 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 335:

/* Line 678 of lalr1.cc  */
#line 7293 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 336:

/* Line 678 of lalr1.cc  */
#line 7313 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage,im);
        InrImage::ptr res (Func_SecDerGrad( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
        Si !res.get() Alors
          fprintf(stderr,"SecDerGrad() erreur ... \n");
        FinSi
        ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 7325 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 338:

/* Line 678 of lalr1.cc  */
#line 7335 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage,im);
        InrImage::ptr res ( Func_AutoCrop(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
        ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 7390 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 340:

/* Line 678 of lalr1.cc  */
#line 7428 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 341:

/* Line 678 of lalr1.cc  */
#line 7439 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_EDP_dilate( im.get(), (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 7449 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 343:

/* Line 678 of lalr1.cc  */
#line 7461 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 344:

/* Line 678 of lalr1.cc  */
#line 7472 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_EDP_erode( im.get(), (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 7482 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 346:

/* Line 678 of lalr1.cc  */
#line 7509 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 347:

/* Line 678 of lalr1.cc  */
#line 7532 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 348:

/* Line 678 of lalr1.cc  */
#line 7560 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 349:

/* Line 678 of lalr1.cc  */
#line 7573 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 350:

/* Line 678 of lalr1.cc  */
#line 7707 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 351:

/* Line 678 of lalr1.cc  */
#line 7742 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 352:

/* Line 678 of lalr1.cc  */
#line 7775 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 353:

/* Line 678 of lalr1.cc  */
#line 7803 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 354:

/* Line 678 of lalr1.cc  */
#line 7817 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 355:

/* Line 678 of lalr1.cc  */
#line 7829 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_SRAD_qcoeff( im.get()));
      Si !res.get() Alors
        fprintf(stderr,"Func_SRAD_qcoeff() erreur ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
        }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 7841 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 357:

/* Line 678 of lalr1.cc  */
#line 7859 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 358:

/* Line 678 of lalr1.cc  */
#line 7878 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 359:

/* Line 678 of lalr1.cc  */
#line 7898 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 360:

/* Line 678 of lalr1.cc  */
#line 7920 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 361:

/* Line 678 of lalr1.cc  */
#line 7940 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 362:

/* Line 678 of lalr1.cc  */
#line 7959 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 363:

/* Line 678 of lalr1.cc  */
#line 7979 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 364:

/* Line 678 of lalr1.cc  */
#line 7999 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 365:

/* Line 678 of lalr1.cc  */
#line 8040 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 366:

/* Line 678 of lalr1.cc  */
#line 8062 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 367:

/* Line 678 of lalr1.cc  */
#line 8090 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 368:

/* Line 678 of lalr1.cc  */
#line 8111 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 369:

/* Line 678 of lalr1.cc  */
#line 8148 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 370:

/* Line 678 of lalr1.cc  */
#line 8185 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 371:

/* Line 678 of lalr1.cc  */
#line 8222 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 372:

/* Line 678 of lalr1.cc  */
#line 8256 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          ADD_VARSTACK(InrImage,InrImage::ptr(( varsurfd->Pointer())->GetCanvas()->GetGLImage()));
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 8262 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          driver.yyiperror("Not available in new wxwidgets version of the 3D viewer ! ");
          YYABORT;
/*
          ADD_VARSTACK(InrImage,(*(Viewer3D_ptr*) $1->Pointer())->GetInrImage());
*/
    }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 8279 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_ThresholdCrossing( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
       ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 8286 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_IsocontourPoints( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 8293 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_IsosurfDist( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
      ADD_VARSTACK_PTR(InrImage,res);

    }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 8301 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_vtkIsoContourDist( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 8308 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 379:

/* Line 678 of lalr1.cc  */
#line 8332 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 380:

/* Line 678 of lalr1.cc  */
#line 8359 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 381:

/* Line 678 of lalr1.cc  */
#line 8383 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 382:

/* Line 678 of lalr1.cc  */
#line 8412 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 383:

/* Line 678 of lalr1.cc  */
#line 8441 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im2);
      GET_VARSTACK_VALUE(InrImage, im1);
      InrImage::ptr res ( Func_Convolve(im1.get(), im2.get()));
      ADD_VARSTACK_PTR(InrImage,res);

      }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 8450 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 385:

/* Line 678 of lalr1.cc  */
#line 8463 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_Chamfer(im.get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble)));
        ADD_VARSTACK_PTR(InrImage,res);
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 8470 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
          InrImage::ptr res ( Func_Chamfer2(im.get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble)));
          ADD_VARSTACK_PTR(InrImage,res);

        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 8478 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 388:

/* Line 678 of lalr1.cc  */
#line 8492 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr  res ( Func_Chamfer2(im.get(),
                  0.92644, 1.34065, 1.65849,
                  dmax));
        ADD_VARSTACK_PTR(InrImage,res);

        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 8504 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_Chamfer2Signed(im.get(),
                    0.92644, 1.34065, 1.65849,
                    dmax));
        ADD_VARSTACK_PTR(InrImage,res);

        }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 8516 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkSignedBorgefors(im.get(),
                    dmax));
        ADD_VARSTACK_PTR(InrImage,res);
        }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 8526 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkSignedFMDist(im.get(),
                     dmax));
        ADD_VARSTACK_PTR(InrImage,res);

        }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 8537 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_PropagationDistance(im.get(),
                      dmax));
        ADD_VARSTACK_PTR(InrImage,res);
        }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 8547 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_PropagationDistance2(im.get(),
                      dmax));
        ADD_VARSTACK_PTR(InrImage,res);
        }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 8557 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

        GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_PropagationDanielsson(im.get(),
                       dmax));

        ADD_VARSTACK_PTR(InrImage,res);
        }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 8568 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkPropDanielsson(im.get(),
                       -dmax,dmax));
        ADD_VARSTACK_PTR(InrImage,res);
        }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 8578 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
        float dmin = (yysemantic_stack_[(8) - (5)].adouble);
        float dmax = (yysemantic_stack_[(8) - (7)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkPropDanielsson(im.get(),
                       dmin,dmax));
        ADD_VARSTACK_PTR(InrImage,res);
        }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 8589 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 398:

/* Line 678 of lalr1.cc  */
#line 8616 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 399:

/* Line 678 of lalr1.cc  */
#line 8664 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 400:

/* Line 678 of lalr1.cc  */
#line 8798 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 401:

/* Line 678 of lalr1.cc  */
#line 8819 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 402:

/* Line 678 of lalr1.cc  */
#line 8859 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 403:

/* Line 678 of lalr1.cc  */
#line 8870 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      int dim = (int) (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage,im);
      InrImage::ptr res ( Func_MeanHalfSize(im.get(),dim));
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 8878 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
        int axis=(int) (yysemantic_stack_[(6) - (5)].adouble);

        GET_VARSTACK_VALUE(InrImage,im);
        InrImage::ptr res(Func_Flip(im,axis));
        ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 8886 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 406:

/* Line 678 of lalr1.cc  */
#line 8907 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 407:

/* Line 678 of lalr1.cc  */
#line 8933 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      int   order = (int) (yysemantic_stack_[(8) - (5)].adouble);
      float resolution = (yysemantic_stack_[(8) - (7)].adouble);
      GET_VARSTACK_VALUE(InrImage,input);

      InrImage::ptr res ( Func_vtkConvexHull(input.get(),
                   order,resolution));

      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 8944 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);

      InrImage::ptr res ( AMIFluid::Func_Altitude2Position(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 8951 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      InrImage::ptr res ( AMIFluid::Func_Altitude2Position(im.get()));
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 8957 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      InrImage::ptr res ( AMIFluid::Func_GeoCoordinates(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 8963 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im.get());
      ADD_VARSTACK(InrImage,res);
    }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 8970 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 413:

/* Line 678 of lalr1.cc  */
#line 8995 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 414:

/* Line 678 of lalr1.cc  */
#line 9013 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));
      InrImage::ptr res( AMIFluid::Func_ReadFlow(filename.get()));
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 9020 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 416:

/* Line 678 of lalr1.cc  */
#line 9053 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 417:

/* Line 678 of lalr1.cc  */
#line 9072 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 419:

/* Line 678 of lalr1.cc  */
#line 9108 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    /**
      Description:
    **/
    // IT IS IMPORTANT TO KEEP CREATING A NEW VARIABLE HERE, TO INCREASE THE SMT PTR COUNTER FOR ASSIGNMENT RULE !!!
    BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->NewReference());
  }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 9119 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    /**
    Description: adds a reference to the variable in the stack
    **/
    BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->NewReference());
  }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 9128 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 433:

/* Line 678 of lalr1.cc  */
#line 9164 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 434:

/* Line 678 of lalr1.cc  */
#line 9226 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 437:

/* Line 678 of lalr1.cc  */
#line 9308 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Logical negation (NOT) operator.
    **/
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(!(*var));
  }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 9316 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Postfix increment operator.
    **/
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar((*var)++);
  }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 9324 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Postfix decrement operator.
    **/
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar((*var)--);
  }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 9332 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Transpose operator, usefull for matrices
    **/
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->Transpose());
  }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 9342 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 442:

/* Line 678 of lalr1.cc  */
#line 9381 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Array subscript operator.
    **/
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)[var2]);
  }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 9395 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Cast operator.
    **/
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->BasicCast( (yysemantic_stack_[(4) - (2)].aint)));

  }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 9404 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    //cout << "T_SUB  cast_var  " << endl;
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(-(*var));
  }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 9410 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(+(*var));
  }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 9415 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(++(*var));
  }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 9420 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(--(*var));
  }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 9425 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_sin());
  }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 9430 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_cos());
  }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 9435 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_sqrt());
  }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 9440 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_fabs());
  }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 9445 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_round());
  }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 9450 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_floor());
  }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 9455 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_tan());
  }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 9460 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_asin());
  }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 9465 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_acos());
  }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 9470 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_atan());
  }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 9475 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_exp());
  }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 9480 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_log());
  }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 9485 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_ln());
  }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 9490 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_norm());
  }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 9500 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)*var2);
  }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 9506 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)/var2);
  }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 9512 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)%var2);
  }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 9523 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    BasicVariable::ptr res(*var1+var2);
    driver.var_stack.AddVar(res);
  }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 9530 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    BasicVariable::ptr res((*var1)-var2);
    driver.var_stack.AddVar(res);
  }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 9545 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)<var2);
  }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 9551 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)>var2);
  }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 9557 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)<=var2);
  }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 9563 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)>=var2);
  }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 9573 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)==var2);
  }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 9579 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)!=var2);
  }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 9620 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    /**
      Descriptiopn: Logical AND operator
    **/
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)&&var2);
  }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 9633 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    /**
      Descriptiopn: Logical XOR operator, for vectorial images it defines the pointwise vectorial product.
    **/
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)^var2);
  }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 9646 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    /**
      Descriptiopn: Logical OR operator
    **/
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)||var2);
  }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 9659 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 493:

/* Line 678 of lalr1.cc  */
#line 9673 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 494:

/* Line 678 of lalr1.cc  */
#line 9683 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    //cout << "assignment_var" << endl;
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1).left_assign(var2));
  }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 9690 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)+=var2);
  }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 9696 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)-=var2);
  }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 9702 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)*=var2);
  }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 9708 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)/=var2);
  }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 9720 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
            GET_VARSTACK_VALUE(GLTransfMatrix,glt);
            GLTransfMatrix* newglt;

            newglt = new GLTransfMatrix();
            (*newglt) = (*glt);
            driver.gltransf_stack.AddMatrix(newglt);
    
        }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 9731 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 502:

/* Line 678 of lalr1.cc  */
#line 9745 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(GLTransfMatrix,glt2);
        GET_VARSTACK_VALUE(GLTransfMatrix,glt1);
        GLTransfMatrix* newglt = NULL;
        float coeff = (yysemantic_stack_[(8) - (7)].adouble);

        newglt = Func_InterpolateTransform(glt1.get(),glt2.get(),coeff);
        driver.gltransf_stack.AddMatrix(newglt);
      }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 9756 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 504:

/* Line 678 of lalr1.cc  */
#line 9774 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
         FloatMatrix::ptr m( new FloatMatrix((int)(yysemantic_stack_[(6) - (3)].adouble),(int)(yysemantic_stack_[(6) - (5)].adouble)));
         ADD_VARSTACK_PTR(FloatMatrix,m);
      }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 9780 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
        /**
        Description: adds a reference to the variable in the stack
        **/
        BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
        driver.var_stack.AddVar(var->NewReference());
      }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 9789 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 508:

/* Line 678 of lalr1.cc  */
#line 9912 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(VarArray,var,array);
          int  i = (int) (yysemantic_stack_[(4) - (3)].adouble);

          BasicVariable::ptr arrayvar = array->GetVar(i);
          if (!arrayvar.get()) {
            // initialize the surface
            SurfacePoly::ptr surf( new SurfacePoly());
            std::string name = (boost::format("%s[%d]") % var->Name().c_str() %i).str();
            array->InitElement(i,surf,name.c_str());
          }

          driver.var_stack.AddVar(array->GetVar(i));
        }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 9933 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 511:

/* Line 678 of lalr1.cc  */
#line 9948 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 512:

/* Line 678 of lalr1.cc  */
#line 9960 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 513:

/* Line 678 of lalr1.cc  */
#line 9982 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 514:

/* Line 678 of lalr1.cc  */
#line 10018 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_OBJECT(SurfacePoly,varsurf)
      SurfacePoly* surf;
      surf = Func_decimate( varsurf.get());
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 10027 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* newsurf;
      GET_VARSTACK_OBJECT(SurfacePoly,varsurf)

      newsurf = Func_decimate( varsurf.get(), (yysemantic_stack_[(6) - (5)].adouble) );
      BasicVariable::ptr res(CreateVar_SurfacePoly(newsurf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 10037 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf;
      GET_VARSTACK_VALUE(InrImage, im);
      surf = Func_vtkMarchingCubes(im.get(),(yysemantic_stack_[(6) - (5)].adouble));
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 10046 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* newsurf;
      GET_VARSTACK_OBJECT(SurfacePoly,surf)

      newsurf = Func_vtkSmooth(surf.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      BasicVariable::ptr res(CreateVar_SurfacePoly(newsurf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 10056 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 519:

/* Line 678 of lalr1.cc  */
#line 10070 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf = new SurfacePoly();
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 10077 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(2) - (2)].astring));
      SurfacePoly* surf = new SurfacePoly();
      surf->Read(filename.get());
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 10086 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 522:

/* Line 678 of lalr1.cc  */
#line 10102 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 523:

/* Line 678 of lalr1.cc  */
#line 10121 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 524:

/* Line 678 of lalr1.cc  */
#line 10141 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 525:

/* Line 678 of lalr1.cc  */
#line 10171 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 526:

/* Line 678 of lalr1.cc  */
#line 10200 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 527:

/* Line 678 of lalr1.cc  */
#line 10218 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 528:

/* Line 678 of lalr1.cc  */
#line 10244 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 529:

/* Line 678 of lalr1.cc  */
#line 10277 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 530:

/* Line 678 of lalr1.cc  */
#line 10313 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 531:

/* Line 678 of lalr1.cc  */
#line 10359 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 532:

/* Line 678 of lalr1.cc  */
#line 10397 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
    GET_VARSTACK_VALUE(InrImage,im);
      SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get());
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 10406 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 534:

/* Line 678 of lalr1.cc  */
#line 10428 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 535:

/* Line 678 of lalr1.cc  */
#line 10439 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 536:

/* Line 678 of lalr1.cc  */
#line 10450 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 537:

/* Line 678 of lalr1.cc  */
#line 10486 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 538:

/* Line 678 of lalr1.cc  */
#line 10528 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 539:

/* Line 678 of lalr1.cc  */
#line 10574 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 540:

/* Line 678 of lalr1.cc  */
#line 10624 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 541:

/* Line 678 of lalr1.cc  */
#line 10666 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 542:

/* Line 678 of lalr1.cc  */
#line 10697 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 543:

/* Line 678 of lalr1.cc  */
#line 10729 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 551:

/* Line 678 of lalr1.cc  */
#line 10787 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 572:

/* Line 678 of lalr1.cc  */
#line 10867 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      ImageExtent<float>* extent=new ImageExtent<float>( (float)(yysemantic_stack_[(11) - (1)].adouble),(float)(yysemantic_stack_[(11) - (3)].adouble),(float)(yysemantic_stack_[(11) - (5)].adouble),
                          (float)(yysemantic_stack_[(11) - (7)].adouble),(float)(yysemantic_stack_[(11) - (9)].adouble),(float)(yysemantic_stack_[(11) - (11)].adouble));
      extent->SetMode(1); // relative
      BasicVariable::ptr res(CreateVar_ImageExtent(extent));
      driver.var_stack.AddVar(res);
    }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 10876 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
    {
      ImageExtent<float>* extent=new ImageExtent<float>((float)(yysemantic_stack_[(7) - (1)].adouble),(float)(yysemantic_stack_[(7) - (3)].adouble),(float)(yysemantic_stack_[(7) - (5)].adouble),(float)(yysemantic_stack_[(7) - (7)].adouble));
      extent->SetMode(1); // relative
      BasicVariable::ptr res(CreateVar_ImageExtent(extent));
      driver.var_stack.AddVar(res);
    }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 10884 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 575:

/* Line 678 of lalr1.cc  */
#line 10902 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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

  case 576:

/* Line 678 of lalr1.cc  */
#line 10919 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"
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
#line 10915 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
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
  const short int Parser::yypact_ninf_ = -1743;
  const short int
  Parser::yypact_[] =
  {
      5004, 10934, 10579, 10579,  9159, -1743, -1743, -1743,  9159,  9159,
    9159, -1743, -1743,    82,   113,   122, -1743, -1743, -1743, -1743,
    9514, -1743,   -44,    80, -1743,   -24,  9159,  9159,  9159,   148,
    9159, -1743,   155,   160, -1743, -1743, -1743, -1743, -1743, -1743,
   -1743, -1743, -1743, -1743, -1743,    37,    53,    13, -1743, -1743,
   -1743, -1743, -1743,    90,    -7,    43,    20,   167,   489,  9159,
     197, -1743, -1743, -1743, -1743,   207,   223, 10579, 10579,   237,
      67,   254,   393,   495,   257,   264,   394,   430,   438,   468,
     485,   488,   492,   531,   532,   533,   534,   535,   558,   559,
     560,   561, -1743, -1743, -1743, -1743,   562,   564,   565,   327,
     338,   566,   567,   569,   572,   573,   574,   575,   579,   580,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   599,   600,   602,   603,   526,   604,   605,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     620,   621,   622,   623,   624,   625,   626,   627,   628,   629,
     630,   631,   632,   633,   634,   635,   636,   637,   638,   639,
     640,   641,   644,   645,   646,   647,   648,   649,   652,   653,
     654,   671,   672,   673,   674,   675,   679,   680,   681,   682,
     687,   692,   694,   695,   700,   702,  9869,   703,   704,   705,
     706,   707,   708, -1743, -1743, -1743, -1743, -1743, -1743, -1743,
   -1743, -1743, -1743, -1743,   709,   710,   711,   712,   714, -1743,
   -1743, 10579, 10579, 10579, 10579, 10579, 10579, 10579, 10579, 10579,
   10579, 10579, 10579, 10579, 10579,    90, -1743,  1842, -1743,  9159,
    6549,  9159,   715,   722,   723,   725,    24,    90,   727,   728,
     735,   738,   739,   447,   740,   741,   742,   743,   744,   745,
     747,   748,   749,   750,   751,   752,   753,   754,   755, -1743,
   -1743, -1743,   757,   758,   774,  5401, -1743, -1743, -1743, -1743,
   -1743, -1743, -1743,    27, -1743, -1743,   756,   129, -1743, -1743,
   -1743, -1743,   -13,   761, -1743,   163,   184, -1743,    40,   200,
     760, -1743,   213,   670,   775,    19,   -28, -1743, -1743, -1743,
   -1743, -1743,   -35, -1743,   767, -1743, -1743,  9159,   762,   763,
     764,   769,   770,   768,   771,   177, -1743,   767,   761,   761,
      92,   772, -1743, -1743, -1743, -1743,  9159,  9159,  9159,  9159,
   -1743, -1743, -1743, -1743, -1743, -1743, -1743, -1743, -1743, -1743,
   -1743, -1743, -1743, -1743, -1743,  9159, -1743,  1842,  1842,   229,
     713,   716,  9159,   513,     1,   484, -1743,    90, -1743,   -33,
    9159,   544,  9159, -1743, -1743, -1743, -1743, -1743, -1743, -1743,
   -1743, -1743, -1743,   764, -1743,   778,   770, -1743, -1743, -1743,
   -1743, -1743, -1743, -1743,  1842,  9159,  9159,   761,   761,  9159,
    9159,  9159,  9159,  9159,  9159,  9159,  9159,   -24,  9159,  9159,
     -24,   -24,   -24,   -24,   -24,  9159,   -24,   -24,   -24,   -24,
     -24,   -24,   -24,   -24,   -24,  9159,  9159,   -24,    93,   141,
     -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,
    9159,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,
     -24,   -24,   -24,   -24,   -24,  9159,  9159,  9159,  9159,  9159,
    9159,  9159,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,
     -24,   717,   718,   -24,   -24,   -24,   -24,   719,  9159,  9159,
    9159,   720,  9159,   721,  9159,  9159,   -24,   -24,   -24,   746,
     759,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,
     -24,   -24,  9159,  9159,  9159,   -24,  9159,  9159,   -24,   726,
     -24,   730,   731,  9159,   -24,   -24,  7664, -1743,  9159,  9159,
     -24,   -24,   -24,   -24,  9159,  9159,  9159,  9159,   -24,   761,
     761,   761,   761,   761,   761,   761,   761,   761,   761,   761,
     761,   761,   761,  -106, -1743,   765,   769, -1743, -1743, -1743,
      27, -1743,   212,  9159,  9159,   773, -1743, -1743,   779,  9159,
    9159,   -24,  9159,  9159,   434,  9159,  9159,  9159,  9159,  9159,
    9159,  9159,  9159,  9159,  9159,  9159,  9159,  9159,   766,   -24,
     -24,   -24, -1743, -1743, -1743, -1743, -1743, -1743, -1743, -1743,
   -1743,    27, -1743,   446,  9159,    49, -1743, -1743, -1743,  6929,
    9159,  9159,  9159,  9159,  9159,  9159,  9159,  9159,  9159,  9159,
    9159,  9159,  9159,  9159,  9159,  9159,  9159,  9159,  9159,  9159,
    9159,  9159,  9159, 10224,  4294,  5789,    88,    64,  9159,  9159,
     655,   657,  9159,   171,  9159, -1743,   783,   792,   797,   102,
     793,   798,   803, -1743, -1743,   805,   806,   807,   808, -1743,
     810,   811,   812,   813, -1743, -1743,   814, -1743,   815, -1743,
     817,   819,   820,   821,   822, -1743, -1743,   816,   824,  9159,
    9159, -1743,   825,   826, -1743,   827, -1743, -1743,  9159,   828,
     830,   831,  9159,   823,   832,   829,   836, -1743,   837,   834,
     839,   838,   842,   841,   844,   843,   840,   845,   849,   847,
     850,   853,   855,   856,   858,   862,   863,   866,   868,   869,
     870,   871,   848,   872,   873,   874,   875,   851, -1743, -1743,
     883, -1743, -1743,   885,   877,   880,   881,   882,   884,   886,
     887,   888,   889,   890,   891,   897,   898,   893,   900,   895,
     896,   899,   901,   902,   189,   903,   904,   905,   910,    99,
     911,   906,   908,   909,   912,   913,   916,   917,   920,   926,
     927,   928,   935,   936,   941,   218,   938,   939,   940,   943,
     944,   945,   946,   947,   948,   949,   220,   950,   958,   959,
     954,   955,   956,   957,   960,   966,   973,   975,   976,   977,
     978,   979,   989,   992,   994,   995,  1002,  1003,  1004,   999,
    1000,   193,  1001,  1006,   231,  1007,  1008,  1012,  1013,  1009,
    1010, -1743,  1022,  1029,  1040,  1041,  1043,  1044,  1045,  1042,
    1056,  1057,  1046,  9159,  9159, -1743, -1743,   -12, -1743,  1047,
    1049,  1050,  1058,  1067,   918,  1071,   473,    27,   235,  1070,
    1073,  1074,  1075,  1078,   283,  1076,  1077,   284,   285,  1079,
    1082,  1083,  1084,  1085,  1092,  1093,  1094,  1089,  1090,  1091,
    1095, -1743, -1743,   136,  1099,  1101, -1743,  1103,  1104, -1743,
   -1743,  9159, -1743,  1105,  1108,  1111,  1118,  1120,  1123,  1124,
    1125,  1126, -1743, -1743, -1743, -1743, -1743, -1743, -1743, -1743,
   -1743, -1743, -1743, -1743, -1743,  1122, -1743,  1121,   298,    -1,
     914, -1743, -1743, -1743,   163,   163, -1743, -1743, -1743, -1743,
      40,    40,   200, -1743,   213,   670,    29,   775, -1743, -1743,
   -1743, -1743, -1743, -1743,  8044, -1743,  7284,  8424,  1127,   942,
     763, -1743,  8804,  1131,  1135,  1136,  1138,  1132, -1743, -1743,
    1842,   762,   300, -1743, -1743,  1137,  1146,    87, -1743,  9159,
   -1743, -1743,  9159,  9159, -1743, -1743,  9159,  9159,   785,  9159,
    9159,  9159,  9159,  9159,  1020,   -27,   953,   784,  9159,  9159,
    9159,  9159,  9159, -1743, -1743,  9159,    66,  9159, -1743,   787,
    9159,   801,  1148,  9159, -1743,  1096, -1743, -1743,  9159,  1152,
   -1743, -1743,  1154, -1743,  1156,     3,  9159,  9159, -1743,  9159,
    9159,  9159,  9159,  9159,   -24,  9159,  9159,  9159,  9159,  9159,
    9159, -1743,  9159,  9159,  9159,   -24,   -24,   -24, -1743,  9159,
    9159,  9159,  9159,  9159,  9159,  9159,  9159,   -24,  9159, -1743,
   -1743, -1743,   -24, -1743,   -24,   -24,   -24,   -24,   -24, -1743,
     -24,   -24, -1743,  9159, -1743,  9159,  1157,  9159,  9159,  9159,
    9159,  9159,  9159,  9159,  9159,  9159,  9159,  9159, -1743,  9159,
   -1743, -1743,  9159,  9159,  9159,  9159,  9159,  9159,  9159,  9159,
    9159,  9159,   -24, -1743,  9159,  9159, -1743, -1743,   -24,   -24,
     -24,   -24,   -24,  9159,  9159,  9159,  9159,  9159,  9159,  9159,
    9159,  9159,  9159,  9159, -1743, -1743, -1743,  9159,  9159, -1743,
    9159,  9159, -1743,  9159,  9159,  9159,  9159,  9159, -1743, -1743,
    9159, -1743, -1743, -1743, -1743, -1743, -1743,  9159,  9159,  9159,
   -1743,   846,  1153, -1743, -1743, -1743, -1743, -1743, -1743, -1743,
    9159, -1743,  -196,  -196,  1102, -1743, -1743,  9159,  9159,   -24,
    9159,  9159,   -24, -1743,  9159,  9159,  9159, -1743,  9159, -1743,
    9159,  9159,  9159,  9159,  9159,  9159, -1743, -1743, -1743,  9159,
    9159,   -24,   -24,  9159,  9159,  9159, -1743,  9159,  9159,   -24,
   -1743,   -24,   -24,  9159,  9159,  9159,  9159,  9159,  9159,  9159,
    1158,  9159,    83, -1743, -1743,  9159,  9159, -1743, -1743,  9159,
    9159,  -160,  9159,  1106,  9159,  9159,  9159,  9159, -1743, -1743,
    6169, -1743, -1743,  1161,  1162,  1164,  1163,   301,  1170,  1173,
    1168,  1171,  1172,  1175,  1176,  1174,   302,  1182,  1177,  1178,
    1179,  1186,  1187,  1183,  1188,  1190,  1191,  1189,   502,  1192,
    9159, -1743,  1193,  1196,  1197,  9159,   -24,   -24,   309,  1194,
    1195,  1198,  1199,  1202,  1203,  1200,  1204,   312,  1201,  1205,
    1206,  1207,  1208,  1209,  1210,  1212,  1213,  1214,  1215,  1216,
    1217,  1218,  1219,  1220,  1221,  1222,  1223,  1224,  1231,  1232,
    1227,  1228,  1229,  1230,  1233,  1234,  1237,  1238,  1235,  1242,
    9159,  1243,  1244,  1247,  1245,  1246,  1248,  1249,   319,  1250,
    1251,  1253,  1252,  1254,  1259,  1261,  1262,  1263,  1264,  1260,
    1265,  1266,  1268,  1269,  1267,  1270,  1276,  1271,  1272,  1273,
    1274,  1275,  1277,  1282,  1284,  1285,  1286,  1287,  1288,  1289,
     320,  1290,  1291,  1292,   321,  1293,  1294,  1295,  1299,  1300,
    1296,  1301,  1298,  1302,  1303,  9159,  9159,    27,    27,  1304,
    1147,  1160,  1165,  1279,  1280,  1281,   322,   331, -1743,  1305,
    1306,  1307,  1311,  1308,  1309,   333,  1310,  1312,  1317,  1319,
    1314,  1315,  1316,  1321,  1328,  1323,  1330,  1325,  1326,    71,
    1327,  1334,  1335,  1331,   335,  1336,  1338,  1333,   205,  1337,
     214,  1340,   336,  1339,  1341,   344,  1342,  1343, -1743, -1743,
    1344,  1348,  1351, -1743,  1350,  1347,  1354,  1355,  1352, -1743,
    1842, -1743, -1743,  9159,  9159, -1743,  9159, -1743,  9159, -1743,
   -1743,  9159,  9159,  9159,  9159, -1743,   993, -1743,  9159, -1743,
     -24,  9159,  9159, -1743, -1743,  9159, -1743, -1743, -1743,  1166,
   -1743, -1743, -1743, -1743, -1743, -1743,  1356,  1357,   345, -1743,
     -32,     5,  9159, -1743, -1743, -1743, -1743,  9159, -1743, -1743,
     -24,  9159,  9159,  9159,  9159,  9159,  9159,  9159,  9159,  9159,
    9159,  9159,  9159,  9159,  9159,  9159,  9159,  9159,  9159,  9159,
    9159, -1743, -1743,  9159,   -24,   -24,   -24,   -24,   -24, -1743,
   -1743,  9159, -1743,  1359, -1743, -1743, -1743,  9159,  9159,  9159,
    9159, -1743,  9159,  9159,  9159, -1743,  9159,  9159, -1743, -1743,
   -1743, -1743, -1743,  9159,  9159,  9159,  9159,  9159, -1743, -1743,
   -1743,  9159,  9159,   -24,   -24,  9159,  9159, -1743, -1743, -1743,
   -1743, -1743, -1743, -1743, -1743,  9159,  9159,  9159,  9159, -1743,
     -24, -1743, -1743, -1743, -1743, -1743,  9159, -1743,  9159,  9159,
    9159,   933, -1743, -1743, -1743,  9159, -1743, -1743, -1743, -1743,
   -1743, -1743, -1743,  -161, -1743,    27, -1743,  9159,  9159, -1743,
    9159,  9159, -1743,  9159,  9159,  9159, -1743, -1743,  9159,  9159,
    9159,  9159, -1743,  9159, -1743,   -24,  9159, -1743,  9159,  9159,
    9159, -1743, -1743,  9159, -1743,  9159, -1743, -1743,  9159, -1743,
    9159, -1743, -1743, -1743,  9159,  9159,  9159, -1743,  9159,  9159,
    9159, -1743, -1743, -1743, -1743,  1144,  1358,  1360,  1226, -1743,
    1361,  1362,   216,  1363,  1365,  1364,  1367,  1369,  1371,  1378,
    1383,  1384,  1379,  1381,  1388, -1743, -1743, -1743,  9159,  1390,
    1366,   346,  1385,  1386,  1389,  1394,   347,   354,   355,   356,
    1391,  1392,  1393,   359,   127,  1395,  1396,  1398,  1401,   366,
    1403,  1405,  1406,  1407,  1408,  1410,  1400,  1412,  1433,  1434,
    1436,  1437,  1438,  1439, -1743,  1446,  1447,   367,   370,  1445,
    1452,  1448,  1453,  1460,  1461,  1462,  1463,  1464,  1469,  1476,
    1477,  1472,  1473,  1475,  1479,  1480,  1482,  1481,  1483,  1484,
    1488,  1491,  1492,  1493,  1494,  9159,    27,  1495,    27,  1297,
    1318,  1322,  1457,  1458,  1459,    27, -1743,  1499,  1503,  1497,
    1504,  1498,  1505,  1512,  1508,  1509,  1516,  1511,  1513,  1514,
    1515,    94,  1518,  1257,  1522,  1517,  1521,  1524,  1528,  1529,
    1530,  1533,  1283,  1532,  1536,  9159,  9159,  1543, -1743,  9159,
   -1743,  9159, -1743,  9159,  9159,  9159,  9159, -1743, -1743, -1743,
    9159,  9159, -1743,  1545, -1743,   965, -1743,   -32,  1320,  9159,
    9159, -1743, -1743,  9159, -1743,  9159, -1743,  9159, -1743,  9159,
    9159,  9159,  9159, -1743,  9159,  9159,  9159,  9159,  9159,  9159,
   -1743,  6929,  6929,  6929,  9159,  9159,  9159,  9159, -1743,  9159,
    9159,  9159,  9159,  9159,   -24,  9159, -1743, -1743, -1743,  9159,
   -1743,  9159,  9159, -1743,  9159,  9159,  9159,  9159,  9159,  9159,
    9159,  9159, -1743, -1743,  9159,   -24,   -24,  9159,  9159, -1743,
    9159,  9159,  9159, -1743, -1743, -1743,  9159,  9159, -1743, -1743,
    9159, -1743, -1743, -1743, -1743, -1743, -1743, -1743, -1743,  9159,
    9159, -1743,  9159, -1743,  9159, -1743,  9159,  9159, -1743,  9159,
    9159,   -24,  9159, -1743,  9159,  9159, -1743,  9159, -1743,  9159,
    9159,  9159,  9159,  9159,  9159,  9159,  9159,  9159,  9159, -1743,
   -1743, -1743,   371,  1549,  1544,  1546,  1548,  1551,  1553,  1555,
   -1743,  1557,   390,  1554,  1559,   391,   395,  1563,  1564,  1565,
    1566,  1561,  1567,  1568,  1569,  1570,  1571,  1572,   396,  1579,
     482,  1580,  1581,  1576,  1577,  1578,  1582,  1583,  1584,  1585,
    1586,  1587,   403,  1588,  1595,   424,  1597,  1592,  1593,  1600,
    1601,  1596,  1599,  1603,  1602,  1604,   425,  1605,  1607,   426,
    1609,  1612,  1614,  1615,  1616,    27,  1611,  1613,  1617,  1618,
    1619,  1620,  1621,  1622,  1623,  1624,  1625,  1632,  1633,  1628,
    1629,  1636,  1637,  1638,  1640,  1641,  1642, -1743,  1639,  1643,
   -1743,  9159, -1743,  9159,  9159,  9159, -1743,  9159, -1743, -1743,
   -1743,   -32,  9159,  9159, -1743,  9159, -1743,  9159,  9159,  9159,
    9159,  9159, -1743,  9159,  9159,  9159,  9159,  9159,  9159,  6929,
   -1743,  6929, -1743, -1743,  6929,  6929,  9159,  9159,  9159,   -24,
     -24,   -24,   -24, -1743,  9159,  9159, -1743, -1743,  9159, -1743,
    9159,  9159, -1743, -1743,  9159,  9159, -1743,  9159,  9159, -1743,
    9159,   -24, -1743, -1743,  9159, -1743, -1743, -1743, -1743, -1743,
   -1743,  9159,  9159,  9159, -1743,  9159,  9159,  9159,  9159,  9159,
     -24,  9159, -1743, -1743,  9159,  9159, -1743, -1743, -1743, -1743,
   -1743, -1743,  9159, -1743,  1644,  1646,  1647,  1648,  1645,  1649,
    1650,  1651,  1652,  1653,  1654,  1655,  1656,  1658,   427,  1659,
    1660,  1661,  1662,  1663,  1665,  1667,  1668,  1670,  1666,  1671,
    1673,  1674,  1675,  1672,  1676,  1677,  1678,  1679,  1680,  1681,
    1682,  1683,  1684,  1685,  1686,  1687,  1692,  1688,  1695,  1690,
     428,  1691,  1693,  1694,  1696,  1697,  1698,  1700,  1701,  1702,
   -1743, -1743, -1743, -1743,  9159, -1743, -1743,  9159, -1743, -1743,
   -1743, -1743, -1743,  9159, -1743,  9159, -1743,  9159, -1743, -1743,
    9159, -1743, -1743, -1743, -1743,  6929, -1743, -1743, -1743, -1743,
    9159,  9159, -1743,  9159, -1743, -1743,  9159,  9159,  9159,  9159,
    9159, -1743,   -24, -1743,  9159, -1743,  9159, -1743,  9159,  9159,
    9159,  9159,  9159,   -24,  9159,  9159, -1743,  9159,  1699,  1709,
    1706,  1716,  1717,  1714,  1721,  1718,  1719,  1722,  1720,  1723,
    1724,   444,  1726,  1728,  1730,  1735,  1742,   445,  1751,  1750,
    1758,  1759,  1760,  1768, -1743,  9159,  9159, -1743, -1743, -1743,
    9159, -1743,  9159,  9159, -1743,  9159,  9159,  9159, -1743,  9159,
    9159,   -24,  9159,  9159,  9159, -1743,  9159, -1743,  9159,  9159,
     -24,  9159,  1167,  1769,  1770,  1771,  1772,  1774,   449,  1781,
    1777,  1778,  1785,   453,  1786,  1787,  1796,   454,   457,  1791,
    1793,  1794,  9159, -1743, -1743, -1743, -1743,  9159, -1743,  9159,
   -1743,  9159,  9159,  9159, -1743,  9159,  9159,  9159, -1743, -1743,
    9159, -1743,  9159,  9159,  9159,  9159, -1743,  1795,  1802,  1803,
    1798,  1805,  1806,  1809,  1807,  1811,  1810,  1813,  1815,  1818,
    9159, -1743, -1743,  9159, -1743, -1743, -1743,  9159, -1743,  9159,
    9159,  9159,   -24,  1812,  1826,  1831,  1838,  1839,  1834,  1835,
   -1743, -1743,  9159, -1743, -1743,  9159,   -24,  1836,  1841,  1843,
    9159,  9159,  9159,  1844,  1845,  1848,  9159,  9159, -1743,  1846,
    1849,  9159,  9159,  1850,  1851,  9159,  9159,  1854,  1858, -1743,
   -1743
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  Parser::yydefact_[] =
  {
       265,   265,   265,   265,   265,    21,    69,    70,   265,   265,
     265,    73,    74,     0,     0,     0,   220,   225,    41,    20,
     265,   295,     0,    92,    79,     0,   265,   265,   265,     0,
     265,    91,     0,     0,   214,   224,   544,   290,   427,   424,
     425,   420,   423,   426,   507,   554,   505,   555,   546,   547,
     549,   548,   550,   556,   422,   545,   553,   557,     0,   265,
       0,    43,    46,    44,    45,     0,     0,   265,   265,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   180,   181,   216,   182,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   265,     0,     0,     0,
       0,     0,     0,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,     0,     0,     0,     0,     0,   226,
     227,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,     0,   222,     0,    42,   265,
     265,   265,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   186,
     187,   188,     0,     0,     0,   265,     4,     8,    10,    14,
      16,    18,    12,     0,   421,   428,     0,   299,   418,   429,
     430,   431,   436,   443,   463,   467,   470,   471,   476,   479,
     481,   482,   484,   486,   488,   490,   492,   499,    40,   432,
     419,   509,     0,   558,   552,   559,    39,   265,     0,     0,
     422,     0,     0,     0,     0,   299,   437,     0,   446,   445,
       0,     0,    71,   275,    72,    75,   265,   265,   265,   265,
     292,   277,    82,    85,    80,    98,    95,    96,    97,    94,
      93,    81,   101,   102,   103,   265,    90,     0,     0,     0,
       0,     0,   265,     0,     0,     0,    35,     0,   107,     0,
     265,     0,   265,   564,   562,   563,   567,   565,   566,   554,
     568,   555,   556,   561,   545,   553,   557,   569,   560,   552,
     570,   571,    87,    88,     0,   265,   265,   447,   448,   265,
     265,   265,   265,   265,   265,   265,   265,     0,   265,   265,
       0,     0,     0,     0,     0,   265,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   265,   265,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     265,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   265,   265,   265,   265,   265,
     265,   265,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   265,   265,
     265,     0,   265,     0,   265,   265,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   265,   265,   265,     0,   265,   265,     0,     0,
       0,     0,     0,   265,     0,     0,   265,   520,   265,   265,
       0,     0,     0,     0,   265,   265,   265,   265,     0,   449,
     450,   455,   456,   457,   458,   459,   461,   460,   451,   452,
     453,   454,   462,     0,    25,     0,   553,   222,   222,    37,
       0,    38,     0,   265,   265,     0,    31,    29,   222,   265,
     265,     0,   265,   265,     0,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,     0,     0,
       0,     0,     1,     3,     5,     9,    11,    15,    17,    19,
      13,     0,     6,     0,   265,     0,   438,   439,   440,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,     0,     0,   265,   265,
       0,     0,   265,     0,   265,   435,     0,     0,     0,     0,
       0,     0,     0,   372,   373,     0,     0,     0,     0,   142,
       0,     0,     0,     0,   147,   148,     0,   131,     0,   139,
       0,     0,     0,     0,     0,   128,   129,     0,     0,   265,
     265,   104,     0,     0,    68,     0,   551,   184,   265,     0,
       0,     0,   265,     0,     0,     0,     0,   276,     0,   276,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   116,   117,
       0,   118,   119,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   299,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   299,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   519,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   265,   265,   223,    26,     0,    36,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,   271,     0,   275,     0,   217,     0,     0,   105,
     106,   265,   121,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   289,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,     0,   576,     0,   299,   436,
       0,   464,   465,   466,   468,   469,   473,   472,   474,   475,
     477,   478,   480,   483,   485,   487,     0,   489,   494,   495,
     496,   497,   498,   493,   265,    57,   265,   265,     0,   554,
     555,   500,   265,     0,   279,   282,     0,    51,    59,    53,
       0,   554,     0,   199,   195,     0,     0,     0,   444,   265,
      77,    78,   265,   265,   218,   219,   265,   265,     0,   265,
     265,   265,   265,   265,     0,     0,     0,     0,   265,   265,
     265,   265,   265,    99,   100,   265,     0,   265,   185,   508,
     265,   291,     0,   265,    47,     0,   252,   254,   265,     0,
     255,   256,     0,   257,     0,     0,   265,   265,   332,   265,
     265,   265,   265,   265,     0,   265,   265,   265,   265,   265,
     265,   333,   265,   265,   265,     0,     0,     0,   355,   265,
     265,   265,   265,   265,   265,   265,   265,     0,   265,   317,
     318,   319,     0,   321,     0,     0,     0,     0,     0,   328,
       0,     0,   248,   265,   253,   265,     0,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   335,   265,
     523,   524,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,     0,   521,   265,   265,   293,   294,     0,     0,
       0,     0,     0,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   398,   174,   175,   265,   265,   250,
     265,   265,   514,   265,   265,   265,   265,   265,   313,   315,
     265,   506,   368,   369,   370,   371,   264,   265,   265,   265,
     177,     0,   222,   192,   221,   222,    27,   268,   269,   270,
     265,   179,   201,   201,     0,    33,   402,   265,   265,     0,
     265,   265,     0,   532,   265,   265,   265,   409,   265,   411,
     265,   265,   265,   265,   265,   265,   413,   414,   124,   265,
     265,     0,     0,   265,   265,   265,   399,   265,   265,     0,
     120,     0,     0,   265,   265,   265,   265,   265,   265,   265,
       0,   265,     0,   442,   441,   265,   265,    50,    49,   265,
     265,     0,   265,     0,   265,   265,   265,   265,   197,   434,
     265,   508,   291,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     265,    89,     0,     0,     0,   265,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     265,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   265,   265,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   222,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   299,     0,
     299,     0,     0,     0,     0,     0,     0,     0,   575,   491,
       0,     0,     0,   501,     0,     0,     0,     0,     0,    52,
       0,   200,   196,   265,   265,   215,   265,   132,   265,   127,
     134,   265,   265,   265,   265,   130,     0,   140,   265,   135,
       0,   265,   265,   138,   266,   265,   272,   273,   274,     0,
      60,    61,    58,    86,    48,   433,     0,     0,     0,   305,
       0,     0,   265,   331,   334,   336,   337,   265,   338,   172,
       0,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   247,   316,   265,     0,     0,     0,     0,     0,   329,
     330,   265,   263,     0,   300,   301,   302,   265,   265,   265,
     265,   155,   265,   265,   265,   161,   265,   265,   526,   374,
     375,   376,   377,   265,   265,   265,   265,   265,   522,   417,
     383,   265,   265,     0,     0,   265,   265,   388,   389,   390,
     391,   392,   393,   394,   395,   265,   265,   265,   265,   510,
       0,   511,   515,   516,   517,   518,   265,   504,   265,   265,
     265,   222,   193,    24,    28,   265,   205,   206,   207,   202,
     204,   203,   222,     0,   222,     0,   403,   265,   265,   404,
     265,   265,   533,   265,   265,   265,   408,   410,   265,   265,
     265,   265,   412,   265,   183,     0,   265,   228,   265,   265,
     265,   234,   115,   265,   114,   265,   122,   123,   265,   168,
     265,   170,   171,   110,   265,   265,   265,   108,   265,   265,
     265,    55,    56,   503,    54,     0,    64,    62,     0,   198,
       0,     0,   299,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   258,   259,   260,   265,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   299,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   262,     0,     0,     0,     0,     0,
     275,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   265,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    34,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   265,   265,     0,    76,   265,
     298,   265,   133,   265,   265,   265,   265,   141,   136,   149,
     265,   265,    67,     0,   306,     0,   307,     0,     0,   265,
     265,   173,   341,   265,   344,   265,   346,   265,   348,   265,
     265,   265,   265,   378,   265,   265,   265,   265,   265,   265,
     356,   265,   265,   265,   265,   265,   265,   265,   366,   265,
     265,   265,   265,   265,     0,   265,   303,   304,   150,   265,
     152,   265,   265,   156,   265,   265,   265,   265,   265,   265,
     265,   265,   416,   384,   265,     0,     0,   265,   265,   396,
     265,   265,   265,   512,   513,   176,   265,   265,   222,    22,
     265,    32,   211,   212,   213,   209,   210,   208,    30,   265,
     265,   407,   265,   534,   265,   535,   265,   265,   191,   265,
     265,     0,   265,   229,   265,   265,   233,   265,    83,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,    65,
      63,    66,     0,     0,     0,     0,     0,     0,     0,     0,
     261,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   574,   573,     0,
     296,   265,   126,   265,   265,   265,   146,   265,   267,   308,
     309,     0,   265,   265,   340,   265,   343,   265,   265,   265,
     265,   265,   314,   265,   265,   265,   265,   265,   265,   265,
     357,   265,   359,   361,   265,   265,   265,   265,   265,     0,
       0,     0,     0,   326,   265,   265,   151,   153,   265,   157,
     265,   265,   166,   525,   265,   265,   529,   265,   265,   165,
     265,     0,   385,   386,   265,   397,   249,   251,   400,   401,
      23,   265,   265,   265,   312,   265,   265,   265,   265,   265,
       0,   265,   231,   232,   265,   265,   167,   169,   111,   112,
     230,   109,   265,   502,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     297,   143,   144,   145,   265,   310,   311,   265,   342,   345,
     347,   349,   352,   265,   380,   265,   382,   265,   350,   353,
     265,   358,   360,   362,   363,   265,   365,   320,   322,   323,
     265,   265,   327,   265,   154,   160,   265,   265,   265,   265,
     265,   164,     0,   387,   265,   405,   265,   536,   265,   265,
     265,   265,   265,     0,   265,   265,   113,   265,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   572,   265,   265,   351,   381,   379,
     265,   364,   265,   265,   367,   265,   265,   265,   531,   265,
     265,     0,   265,   265,   265,   540,   265,   541,   265,   265,
       0,   265,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   265,   137,   339,   354,   324,   265,   158,   265,
     527,   265,   265,   265,   163,   265,   265,   265,   537,   538,
     265,   542,   265,   265,   265,   265,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     265,   159,   528,   265,   178,   162,   415,   265,   539,   265,
     265,   265,     0,     0,     0,     0,     0,     0,     0,     0,
     325,   530,   265,   543,   125,   265,     0,     0,     0,     0,
     265,   265,   265,     0,     0,     0,   265,   265,   190,     0,
       0,   265,   265,     0,     0,   265,   265,     0,     0,   406,
     189
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
     -1743, -1743, -1743,   -68,  1039,  1055,  1109, -1743, -1743,  1145,
    1370,  1409,  1425, -1743, -1743,   183, -1743,  -531, -1743, -1743,
   -1743,    -8,  -372,  2255,    34,  1983, -1743, -1743, -1743, -1743,
       7,   459,  -537,  -118, -1743,   -60,   -57,   937, -1743,   865,
     996,   997,  1028,  1031,   146,   -78,  2766,   400, -1743,   -53,
     140,   -14, -1743,    41,   986,     4, -1743,  -224, -1742
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,   264,   265,   266,   267,   268,   269,   825,   824,   270,
     271,   272,   273,  1112,   932,  1336,   274,   534,   535,  1114,
     275,   887,   676,   507,   276,   315,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   323,   928,   299,   300,
     301,   302,   303,   317,   305,   380,   381,   382,   890
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int Parser::yytable_ninf_ = -195;
  const short int
  Parser::yytable_[] =
  {
       322,   324,   325,   537,   306,   378,   816,   817,   316,   340,
     813,     5,   357,   667,   918,  1173,    37,   827,   678,   680,
     681,   682,   683,   684,   685,    19,   687,   688,    37,  1889,
    1891,  1892,   354,   694,   332,   360,    37,   312,   320,   356,
     605,   304,  1205,   704,   705,   595,   596,   659,   660,   312,
       5,  1175,   921,   891,   892,   893,   349,   312,   723,  1228,
     613,  1621,   359,    37,    19,    37,   352,   607,   608,   609,
     610,   611,   353,   738,   740,   741,   742,   743,   744,   745,
     390,   614,   391,    36,   312,  1567,   312,   938,   612,   633,
     634,  1568,   586,   587,  1569,   326,   762,   763,   764,   379,
     546,   588,   855,   856,   586,   587,   624,  1153,  1843,  1383,
    1155,   583,   622,   588,  1844,   361,   624,  1845,   623,  1035,
     786,   583,   942,   631,   632,   792,   327,  1215,   606,   355,
    1216,   798,   668,   350,   351,   328,   335,   856,   606,    36,
     622,   857,   584,   809,   810,   811,   623,  1765,   585,    36,
     597,   598,   336,   337,   338,   339,  1153,   358,  1154,  1155,
     673,   345,   539,  1330,  1331,  1332,  1333,  1334,   347,  1335,
     590,   591,   822,   348,   378,   592,  1378,   828,   829,   858,
     831,   832,   362,   834,   835,   836,   837,   838,   839,   840,
     622,   842,   843,   844,   593,   594,   623,   574,  1689,  1690,
    1691,  1692,  1693,  1029,  1694,   582,   622,  1089,   859,  1030,
     384,   533,   623,   860,   861,   862,   863,   864,   622,  1579,
     385,   538,   547,   548,   623,   856,   814,   622,  1581,   622,
    1730,   602,  1051,   623,  1063,   623,   386,  2064,  1052,  2065,
    1064,   915,  2066,  2067,   923,  1092,   865,   866,   867,  1126,
     389,  1093,   707,   708,   709,  1127,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   392,   379,   306,
     397,    36,    37,   363,   364,   365,   366,   398,   367,   368,
      44,   369,   370,   371,    48,    49,    50,    51,    52,   372,
     373,   374,   536,   376,   378,   378,   333,  1133,  1137,  1139,
     710,   711,   712,  1134,  1138,  1140,   304,   661,   662,   663,
     664,   622,   599,   600,  1189,  1397,  1407,  1172,   820,   627,
    1190,  1398,  1408,  1429,   868,   869,  1439,  1115,   870,  1430,
     871,   378,  1440,  1481,  1514,  1519,  1542,   633,   634,  1482,
    1515,  1520,  1543,   666,   657,  1544,   418,  1552,   872,  1574,
    1583,  1543,   669,  1553,   671,  1575,  1584,   419,  1587,  1617,
    1746,  1752,   870,   629,  1588,  1618,  1747,  1753,  1754,  1756,
    1758,   662,   663,  1763,  1755,  1757,  1759,   674,   675,  1764,
    1770,  1788,   872,  2164,  1790,  1950,  1771,  1789,   379,   379,
    1791,  1951,   873,   874,   875,   876,   877,   878,   879,   880,
     881,   882,   883,   884,  1960,  1964,   393,   399,   394,  1966,
    1961,  1965,   140,   141,   142,  1967,  1979,  1993,  1171,   147,
     148,   149,   150,  1994,   152,   379,   873,   874,   875,   876,
     877,   878,   879,   880,   881,   882,   883,   884,  1997,  2009,
    2013,  2114,  2147,   400,  1998,  2010,  2014,  2115,  2148,   177,
     870,   401,   178,   179,   180,   181,   182,   183,  2198,  2205,
     186,   318,   319,  2238,  2199,  2206,   554,  2244,  2249,  2239,
     872,  2251,   818,  2245,  2250,   894,   895,  2252,   633,   634,
     635,   402,   636,   637,   638,   787,   788,   639,   790,   378,
     640,   641,   642,   643,   644,   645,   646,   647,   403,   648,
     802,   404,  1981,   649,  1171,   405,   650,   651,   395,   652,
     396,   653,   654,   851,   873,   874,   875,   876,   877,   878,
     879,   880,   881,   882,   883,   884,   387,   388,   819,   908,
     909,   910,   911,   912,   913,   896,   897,   898,   899,   445,
     320,   446,   900,   901,   406,   407,   408,   409,   410,    37,
     363,   364,   365,   366,   841,   367,   368,    44,   369,   370,
     371,    48,    49,    50,    51,    52,   372,   373,   374,   375,
     376,   411,   412,   413,   414,   415,   853,   416,   417,   420,
     421,  1327,   422,   379,  1328,   423,   424,   425,   426,   244,
     245,   246,   427,   428,   249,   250,   889,   252,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     935,   936,   441,   442,   937,   443,   444,   447,   448,   934,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,  1245,  1246,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   304,   304,   482,   483,   484,
     485,   486,   487,  1269,   972,   488,   489,   490,  1274,  1275,
     519,   520,   521,   522,   523,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   491,   492,   493,   494,   495,   140,
     141,   142,   496,   497,   498,   499,   147,   148,   149,   150,
     500,   152,   140,   141,   142,   501,  1188,   502,   503,   147,
     148,   149,   150,   504,   152,   505,   508,   509,   510,   511,
     512,   513,   514,   515,   516,   517,   177,   518,   542,   178,
     179,   180,   181,   182,   183,   543,   544,   186,   545,   177,
     549,   550,   178,   179,   180,   181,   182,   183,   551,  1116,
     186,   552,   553,   555,   556,   557,   558,   559,   560,  1125,
     561,   562,   563,   564,   565,   566,   567,   568,   569,  1350,
     570,   571,  1353,  1354,   572,   583,   589,   601,   603,   604,
     615,   616,   617,   357,   618,   619,   625,   620,   658,   665,
     621,   655,   670,   672,   656,   755,   756,   761,   765,   767,
     852,   826,   773,   939,   794,  1111,   940,  1545,   796,   797,
     833,   941,   944,   943,   707,   774,   710,   945,   946,   947,
     948,   949,   815,   950,   951,   952,   953,   954,   955,   823,
     956,   847,   957,   958,   959,   960,   961,   962,   965,   966,
     967,  1124,  1208,   973,   969,   970,   974,   971,  1422,   975,
     976,   977,   980,  1426,   978,   979,   981,   982,   983,   984,
     985,   988,  1001,  1198,  1006,   986,   244,   245,   246,   987,
     989,   249,   250,   990,   252,   991,   992,   378,   993,   244,
     245,   246,   994,   995,   249,   250,   996,   252,   997,   998,
     999,  1000,  1002,  1003,  1004,  1005,  1007,  1009,  1473,  1008,
    1010,  1011,  1012,  1218,  1013,  1019,  1014,  1015,  1016,  1017,
    1018,  1020,  1021,  1022,  1023,  1024,  1025,  1220,  1032,  1026,
    1178,  1027,  1028,  1031,  1034,  1033,  1037,  1036,  1038,  1039,
    1174,  1122,  1040,  1041,  1194,  1195,  1042,  1043,  1196,  1197,
    1044,  1199,  1200,  1201,  1202,  1203,  1045,  1046,  1047,  1048,
    1209,  1210,  1211,  1212,  1213,  1050,  1049,   304,  1053,  1054,
    1055,  1181,  1219,  1056,  1057,  1058,  1059,  1060,  1061,  1062,
    1065,   379,  1066,  1067,  1068,  1069,  1070,  1071,  1230,  1231,
    1072,  1232,  1233,  1234,  1235,  1236,  1073,  1238,  1239,  1240,
    1241,  1242,  1243,  1074,  1244,  1075,  1076,  1077,  1078,  1079,
    1686,  1250,  1251,  1252,  1253,  1254,  1255,  1256,  1257,  1080,
    1259,  1688,  1081,  1695,  1082,  1083,  1084,  1085,  1086,  1087,
    1088,  1090,  1207,  1098,  1099,  1268,  1091,  1094,  1095,  1271,
    1272,  1273,  1096,  1097,  1276,  1277,  1278,  1279,  1280,  1281,
    1612,  1282,  1100,  1101,  1283,  1284,  1285,  1286,  1287,  1288,
    1289,  1290,  1291,  1292,  1102,  1103,  1294,  1104,  1105,  1106,
    1110,  1117,  1107,  1118,  1119,  1301,  1302,  1303,  1304,  1305,
    1306,  1307,  1308,  1309,  1310,  1311,  1108,  1109,  1120,  1312,
    1313,  1121,  1314,  1315,  1123,  1316,  1317,  1318,  1319,  1320,
    1128,  1132,  1321,  1129,  1130,  1131,  1135,  1136,  1204,  1141,
    1323,  1324,  1142,  1143,  1144,  1145,  1146,  1147,  1148,  1149,
    1150,  1151,  1329,  1156,  1157,  1152,  1158,  1159,  1161,  1339,
    1340,  1162,  1342,  1343,  1163,  1669,  1345,  1346,  1347,  1670,
    1348,  1164,  1349,  1165,  1351,  1352,  1166,  1167,  1168,  1169,
    1180,  1355,  1170,  1171,  1183,  1359,  1360,  1361,  1184,  1185,
    1363,  1186,  1187,  1191,  1681,  1367,  1369,  1371,  1372,  1373,
    1374,  1375,  1192,  1377,  1221,  1225,  1599,  1226,  1380,  1227,
    1270,  1381,  1223,  1326,  1384,  1325,  1386,  1387,  1395,  1338,
    1376,  1393,  1394,  1396,  1399,  1385,  1704,  1400,  1401,  1707,
    1405,  1402,  1403,  1406,  1392,  1404,  1409,  1410,  1411,  1412,
    1413,  1414,  1416,  1415,  1417,  1418,  1536,  1423,  1421,  1419,
    1424,  1425,  1433,  1434,  1431,  1432,  1435,  1436,  1438,  1537,
    1437,  1441,  1614,  1724,  1538,  1442,  1443,  1444,  1445,  1446,
    1447,   304,  1448,  1449,  1450,  1451,  1452,  1453,  1454,  1455,
    1456,  1457,  1458,  1459,  1460,  1461,  1462,  1463,  1464,  1465,
    1466,  1469,  1470,  1467,  1468,  1471,  1472,  1474,  1475,  1533,
    1534,  1476,  1383,  1685,   872,  1477,  1478,  1485,  1479,  1480,
    1483,  1484,  1486,  1488,  1487,  1489,  1490,  1491,  1492,  1847,
    1493,  1498,  1727,  2232,  1499,  1494,  1495,  1925,  1496,  1497,
    1500,  1501,  1502,  1503,  1504,  1505,  1507,  1506,  1508,  1509,
    1510,  1511,  1512,  1513,   575,  1856,  1337,  1521,  1522,  1523,
    1516,  1517,  1518,  1524,  1525,  1527,  1526,  1531,  1528,  1546,
     576,  1379,  1529,  1530,  1535,  1549,  1547,  1548,  1550,  1551,
    1554,  1556,  1555,  1557,  1558,  1559,  1560,   378,  1539,  1540,
    1541,  1561,  1562,  1563,  1564,  1565,  1566,  1570,  1571,  1572,
    1576,  1573,  1577,  1578,  1582,  1206,  1822,  1580,  1420,  1585,
    1591,  1586,  1589,  1590,  1592,  1593,  1594,  1595,  1596,  1597,
    1615,  1616,  1598,  1654,   577,  1728,  1872,  1823,  1725,  1732,
    1726,  1824,  1729,  1731,  1733,  1745,  1601,  1734,  1603,  1735,
    1604,  1736,  1737,  1605,  1606,  1607,  1608,  1738,  1739,  1740,
    1609,  1741,  1742,  1611,  1744,  1748,  1749,  1613,  1751,  1750,
     578,  1760,  1761,  1762,  1778,  1766,  1767,  1904,  1768,  1905,
    1906,  1769,  1907,  1772,  1623,  1773,  1774,  1775,  1776,  1624,
    1777,   379,  1779,  1626,  1627,  1628,  1629,  1630,  1631,  1632,
    1633,  1635,  1636,  1637,  1638,  1639,  1640,  1641,  1642,  1643,
    1644,  1645,  1646,  1780,  1781,  1647,  1782,  1783,  1784,  1785,
    1786,  1787,  1930,  1653,  1619,  1792,  1793,   903,  1794,  1655,
    1656,  1657,  1658,  1795,  1659,  1661,  1662,  1696,  1663,  1664,
    1796,  1797,  1798,  1799,  1800,  1665,  1666,  1667,  1668,  1801,
    1802,  1803,  1804,  1805,  1671,  1806,  1809,  1674,  1675,  1807,
    1808,  1810,  1813,  1811,  1812,  1814,  1815,  1676,  1677,  1678,
    1679,  1831,  1833,  1816,  1817,  1820,  1825,  1826,  1827,  1829,
    1682,  1683,  1684,  1830,  1832,  1834,  1835,  1687,  1836,  1837,
    1838,  1839,  1846,  1840,  1841,  1842,  1848,  1849,   902,  1697,
    1698,  1850,  1699,  1700,  1851,  1701,  1702,  1703,  1852,  1853,
    1854,  1705,  1706,  1855,  1857,  1708,  1858,  1861,  1710,  1870,
    1711,  1712,  1713,  1952,  1953,  1956,  1954,  1715,  1955,  1958,
    1716,  1959,  1717,  1957,  1962,  1972,  1718,  1719,  1720,  1963,
    1721,  1722,  1723,  1968,  1969,  1970,  1971,  1973,  1974,  1975,
    1976,  1977,  1978,  1980,  1982,  1983,  1984,  1985,  1986,   904,
     929,   905,  1987,  1988,  1989,  1990,  1991,  1992,  1995,  1996,
    1743,  1999,  2000,  2001,  2002,  2003,  2004,  2006,  1819,  2005,
    1821,  2012,  2007,  2015,  2008,  2011,  2016,  1828,  2017,  2018,
    2019,  2021,  2024,  2022,   907,   579,   906,  2023,  2084,  2025,
    2026,  2027,  2028,  2029,  2030,  2031,  2032,  2033,  2034,  2035,
    2036,  2037,  2038,  2090,  2039,  2040,  2041,  2043,  2100,  2042,
    2101,  2102,  2103,  2105,  2106,  2104,  2108,  2109,  2110,  2111,
    2112,  2107,     0,  2116,   580,  2118,  2119,  1818,  2113,  2121,
    2117,  2122,  2123,  2120,  2124,  2126,  2125,  2127,  2128,  2129,
     581,  2132,  2130,  2134,  2135,     0,  2131,     0,  2133,     0,
    2141,  2136,  2137,  2138,  2139,  2140,  2143,  2142,  2144,  2145,
    2146,  2149,     0,  2150,  2151,  2156,  2152,  2153,  2154,  2185,
    2187,  1862,  2155,  1863,  2157,  1864,  1865,  1866,  1867,  2186,
    2188,  2189,  1868,  1869,  2190,  2191,  2194,     0,  2192,  2193,
    2195,  1873,  1874,  2196,  2197,  1875,  2200,  1876,  2201,  1877,
    2202,  1878,  1879,  1880,  1881,  2203,  1882,  1883,  1884,  1885,
    1886,  1887,  2204,  1888,  1890,  2207,  1893,  1894,  1895,  1896,
    2208,  1897,  1898,  1899,  1900,  1901,  2176,  1903,  2209,  2210,
    2211,  1871,  2212,  2233,  2234,  2235,  2236,  1908,  1909,  1910,
    1911,  1912,  1913,  1914,  2237,  2240,  1915,  2241,  2242,  1918,
    1919,     0,  1920,  1921,  1922,  2243,  2246,  2247,  1923,  1924,
    2248,  2253,  1926,  2254,  2255,  2270,  2271,  2272,  2273,  2274,
    2275,  1927,  1928,  2276,  1929,  2278,  2290,  2277,  1931,  1932,
    2279,  1933,  1934,  2280,  1936,  2281,  1937,  1938,  2282,  1939,
    2291,  1940,  1941,  1942,  1943,  1944,  1945,  1946,  1947,  1948,
    1949,  2292,  2293,  2294,  2295,  2296,  2300,  2020,     0,     0,
    2256,  2301,  2308,  2302,  2306,  2307,  2311,  2258,  2319,  2312,
    2315,  2316,  2320,  2262,     0,     0,     0,     0,     0,     0,
    2266,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    37,   363,   364,   365,   366,  2286,   367,   368,
      44,   369,   370,   371,    48,    49,    50,    51,    52,   372,
     373,   374,   536,   376,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2044,     0,  2045,  2046,  2047,     0,  2048,
       0,     0,     0,     0,  2050,  2051,     0,  2052,     0,  2053,
    2054,  2055,  2056,  2057,     0,  2058,  2059,  2060,  2061,  2062,
    2063,     0,     0,     0,     0,     0,     0,     0,  2068,  2069,
    2070,     0,     0,   277,     0,     0,  2075,  2076,     0,     0,
    2077,     0,  2078,  2079,     0,  2049,  2080,  2081,     0,  2082,
    2083,     0,     0,     0,     0,   334,  2086,     0,   341,     0,
       0,     0,     0,  2087,  2088,  2089,     0,     0,  2091,  2092,
    2093,  2094,     0,  2096,     0,     0,  2097,  2098,     0,     0,
       0,     0,     0,     0,  2099,     0,     0,     0,     0,     0,
       0,   377,   140,   141,   142,     0,     0,     0,     0,   147,
     148,   149,   150,     0,   152,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   177,
       0,     0,   178,   179,   180,   181,   182,   183,     0,     0,
     186,     0,     0,     0,     0,     0,  2158,     0,     0,  2159,
       0,     0,     0,     0,     0,  2160,     0,  2161,     0,  2162,
       0,     0,  2163,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2165,  2166,     0,  2167,     0,     0,  2168,  2169,
    2170,  2171,  2172,     0,     0,     0,  2174,     0,  2175,     0,
       0,  2177,  2178,  2179,  2180,     0,  2182,  2183,     0,  2184,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2213,  2214,     0,
       0,     0,  2215,     0,  2216,  2217,     0,  2218,  2219,  2220,
       0,  2221,  2222,     0,  2224,  2225,  2226,     0,  2227,     0,
    2228,  2229,     0,  2231,     0,     0,     0,     0,     0,     0,
     377,     0,     0,     0,     0,     0,     0,     0,     0,   244,
     245,   246,     0,     0,   249,   250,     0,   252,     0,  2257,
       0,     0,     0,  2259,  2260,  2261,     0,     0,  2263,  2264,
       0,     0,  2265,     0,     0,  2267,  2268,  2269,   277,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2283,     0,     0,  2284,     0,     0,     0,  2285,
       0,     0,  2287,  2288,     0,   330,     0,     0,     0,     0,
       0,     0,     0,   344,  2297,   346,     0,  2298,     0,     0,
       0,     0,  2303,  2304,  2305,     0,     0,     0,  2309,  2310,
       0,     0,     0,  2313,  2314,     0,     0,  2317,  2318,     0,
       0,     0,     0,     0,   383,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     377,   377,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   377,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     686,     0,     0,   689,   690,   691,   692,   693,     0,   695,
     696,   697,   698,   699,   700,   701,   702,   703,     0,     0,
     706,     0,     0,   713,   714,   715,   716,   717,   718,   719,
     720,   721,   722,     0,   724,   725,   726,   727,   728,   729,
     730,   731,   732,   733,   734,   735,   736,   737,   739,     0,
       0,     0,     0,     0,     0,   746,   747,   748,   749,   750,
     751,   752,   753,   754,     0,     0,   757,   758,   759,   760,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   770,
     771,   772,     0,     0,   775,   776,   777,   778,   779,   780,
     781,   782,   783,   784,   785,     0,     0,     0,   789,   791,
       0,   793,     0,   795,     0,   540,   541,   799,   800,     0,
       0,     0,     0,   804,   805,   806,   807,     0,     0,     0,
       0,   812,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   377,     0,     0,     0,     0,
       0,     0,     0,     0,   830,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   848,   849,   850,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   888,     0,     0,     0,     0,     0,     0,     0,
       0,   626,     0,   628,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     630,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,   766,     0,   768,
     769,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   298,     0,     0,   808,
     321,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   331,     0,     0,     0,
       0,     0,   342,   343,   331,     0,   331,     0,   821,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   845,   846,     0,     0,   331,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   377,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   968,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   331,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1229,     0,
       0,     0,     0,     0,     0,     0,     0,  1237,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1247,  1248,
    1249,     0,     0,     0,     0,     0,   331,   331,     0,     0,
    1258,     0,     0,     0,     0,  1260,     0,  1261,  1262,  1263,
    1264,  1265,     0,  1266,  1267,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   298,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1293,     0,     0,     0,     0,
       0,  1296,  1297,  1298,  1299,  1300,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1113,
       0,     0,     0,   321,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   331,     0,   331,   321,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   331,  1341,     0,     0,  1344,  1160,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1357,  1358,     0,     0,     0,     0,
       0,     0,  1364,     0,  1365,  1366,  1368,  1370,     0,     0,
       0,     0,     0,     0,     0,   677,   679,   677,   677,   677,
     677,   677,   677,     0,   677,   677,     0,     0,     0,     0,
       0,   677,   330,     0,     0,     0,     0,     0,     0,     0,
       0,   677,   677,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1193,     0,   677,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1427,
    1428,   677,   677,   677,   677,   677,   677,   677,     0,     0,
    1214,     0,  1217,     0,     0,     0,     0,     0,  1222,     0,
       0,     0,     0,     0,   677,   677,   677,     0,   331,     0,
     331,   331,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   677,     0,
       0,     0,     0,   677,     0,     0,     0,     0,     0,   677,
       0,     0,   321,     0,     0,   803,     0,     0,     0,     0,
     331,   677,   677,   677,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   331,
     677,     0,     0,     0,     0,   677,   677,     0,   677,   677,
    1295,   677,   677,   677,   677,   677,   677,   677,     0,   677,
     677,   677,   331,   331,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     854,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1322,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   377,     0,     0,     0,  1602,     0,   677,
     927,   933,     0,     0,     0,     0,     0,     0,   854,     0,
       0,     0,     0,  1610,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1356,     0,     0,     0,     0,
       0,     0,  1362,  1620,  1622,     0,     0,     0,     0,     0,
       0,     0,     0,  1625,     0,   963,   964,     0,     0,     0,
       0,  1634,     0,     0,   331,  1382,     0,     0,     0,     0,
       0,  1388,  1389,     0,     0,     0,     0,  1648,  1649,  1650,
    1651,  1652,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1672,  1673,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1680,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1709,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     331,  1532,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   331,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1600,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     331,     0,  1177,   331,     0,     0,     0,     0,   331,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   331,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1620,   331,     0,   331,     0,     0,     0,     0,     0,   331,
       0,     0,     0,     0,  1224,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   888,   888,   888,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1902,     0,   677,
     677,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1916,  1917,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   677,     0,     0,     0,     0,   677,   677,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1935,     0,     0,     0,     0,     0,
       0,   331,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   331,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   677,     0,     0,
     677,   677,     0,     0,     0,     0,   331,     0,     0,     0,
       0,     0,     0,   331,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1620,     0,   331,     0,     0,     0,
       0,     0,   331,   331,     0,     0,  1391,     0,     0,     0,
       0,     0,   888,     0,   888,     0,     0,   888,   888,     0,
       0,     0,  2071,  2072,  2073,  2074,     0,     0,     0,     0,
    1859,  1860,     0,     0,     0,     0,   677,     0,     0,     0,
       0,   677,     0,     0,  2085,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2095,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   677,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   331,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   888,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2173,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2181,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   331,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   677,     0,
       0,     0,     0,     0,  2223,     0,     0,     0,     0,     0,
       0,     0,     0,  2230,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1660,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   677,     0,  2289,     0,   677,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2299,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   677,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     2,     3,     0,     4,     0,     0,
       0,   916,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   677,     0,     0,   677,    16,    17,
       0,     0,   917,    21,     0,   918,     0,     0,     0,  1714,
       0,     0,     0,     0,    29,     0,     0,     0,    32,    33,
      34,     0,    35,     0,    37,    38,    39,    40,    41,     0,
      42,    43,    44,   919,    46,   920,    48,    49,    50,    51,
      52,   372,   310,   921,   536,   376,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    67,
      68,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,     0,    82,     0,    84,    85,    86,
      87,    88,    89,    90,    91,     0,     0,     0,    94,     0,
      96,    97,    98,   313,   314,   101,   102,   103,   104,   105,
     106,   107,   108,     0,     0,     0,   109,   110,     0,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,     0,     0,     0,     0,     0,     0,
     138,   331,   331,     0,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,     0,     0,     0,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,     0,     0,   175,
     176,   177,     0,     0,   178,   179,   180,   181,   182,   183,
     184,   185,   922,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   677,     0,   677,   677,     0,
     677,     0,     0,     0,     0,   923,   187,   188,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   189,   190,
     191,   192,   193,   924,   195,   196,   925,   198,   199,   200,
     201,   202,   203,     0,   204,     0,   206,   207,     0,   926,
     677,     0,     0,     0,   209,   210,   211,   212,   213,   214,
     215,   216,     0,     0,   217,   218,   219,   220,   221,   222,
     223,   224,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   232,
     233,   234,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   238,   239,   240,   241,     0,   242,   243,
       0,   244,   245,   246,   247,   248,   249,   250,     0,   252,
     253,   254,   255,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   677,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   677,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,   677,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   677,     0,
       0,     0,     0,     0,    -2,   677,     0,     0,     0,     0,
       0,   677,     0,     1,     2,     3,     0,     4,   677,     0,
       0,     0,     0,     0,     0,     0,     0,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     0,   677,    22,    23,    24,    25,
      26,    27,    28,     0,    29,    30,    31,     0,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,     0,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,     0,
      61,    62,    63,    64,    65,    66,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    67,
      68,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,     0,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,     0,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,     0,     0,     0,   109,   110,     0,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,     0,     0,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,     0,     0,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   187,   188,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,     0,   204,   205,   206,   207,   208,     0,
       0,     0,     0,     0,   209,   210,   211,   212,   213,   214,
     215,   216,     0,     0,   217,   218,   219,   220,   221,   222,
     223,   224,   225,     0,     0,     0,     0,   226,     0,   227,
     228,   229,     0,     0,     0,   230,   231,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   232,
     233,   234,   235,     0,     0,     0,     0,     0,     0,     0,
     236,   237,     0,   238,   239,   240,   241,     0,   242,   243,
       0,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   573,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     2,     3,     0,     4,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     0,     0,    22,    23,    24,    25,    26,    27,    28,
       0,    29,    30,    31,     0,    32,    33,    34,     0,    35,
      36,    37,    38,    39,    40,    41,     0,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,     0,    61,    62,    63,
      64,    65,    66,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    67,    68,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,     0,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,     0,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
       0,     0,     0,   109,   110,     0,     0,     0,     0,     0,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,     0,
       0,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,     0,
       0,   178,   179,   180,   181,   182,   183,   184,   185,   186,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   187,   188,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
       0,   204,   205,   206,   207,   208,     0,     0,     0,     0,
       0,   209,   210,   211,   212,   213,   214,   215,   216,     0,
       0,   217,   218,   219,   220,   221,   222,   223,   224,   225,
       0,     0,     0,     0,   226,     0,   227,   228,   229,     0,
       0,     0,   230,   231,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   232,   233,   234,   235,
       0,     0,     0,     0,     0,     0,     0,   236,   237,     0,
     238,   239,   240,   241,     0,   242,   243,     0,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,     1,     2,
       3,     0,     4,  -194,     0,     0,   930,     0,     0,  -194,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    16,    17,     0,     0,    20,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    29,
       0,     0,     0,    32,    33,    34,     0,    35,     0,    37,
      38,    39,    40,    41,     0,    42,    43,    44,   931,    46,
     920,    48,    49,    50,    51,    52,   372,   310,   374,   536,
     376,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    67,    68,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,     0,
      82,     0,    84,    85,    86,    87,    88,    89,    90,    91,
       0,     0,     0,    94,     0,    96,    97,    98,   313,   314,
     101,   102,   103,   104,   105,   106,   107,   108,     0,     0,
       0,   109,   110,     0,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,     0,
       0,     0,     0,     0,     0,   138,     0,     0,     0,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,     0,     0,     0,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,     0,     0,   175,   176,   177,     0,     0,   178,
     179,   180,   181,   182,   183,   184,   185,   186,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   187,   188,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,     0,   204,
       0,   206,   207,     0,     0,     0,     0,     0,     0,   209,
     210,   211,   212,   213,   214,   215,   216,     0,     0,   217,
     218,   219,   220,   221,   222,   223,   224,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   232,   233,   234,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   238,   239,
     240,   241,     0,   242,   243,     0,   244,   245,   246,   247,
     248,   249,   250,     0,   252,   253,   254,   255,     1,     2,
       3,     0,     4,     0,     0,     0,  1390,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    16,    17,     0,     0,    20,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    29,
       0,     0,     0,    32,    33,    34,     0,    35,     0,    37,
      38,    39,    40,    41,     0,    42,    43,    44,   931,    46,
     920,    48,    49,    50,    51,    52,   372,   310,   374,   536,
     376,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    67,    68,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,     0,
      82,     0,    84,    85,    86,    87,    88,    89,    90,    91,
       0,     0,     0,    94,     0,    96,    97,    98,   313,   314,
     101,   102,   103,   104,   105,   106,   107,   108,     0,     0,
       0,   109,   110,     0,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,     0,
       0,     0,     0,     0,     0,   138,     0,     0,     0,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,     0,     0,     0,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,     0,     0,   175,   176,   177,     0,     0,   178,
     179,   180,   181,   182,   183,   184,   185,   186,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   187,   188,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,     0,   204,
       0,   206,   207,     0,     0,     0,     0,     0,     0,   209,
     210,   211,   212,   213,   214,   215,   216,     0,     0,   217,
     218,   219,   220,   221,   222,   223,   224,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   232,   233,   234,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   238,   239,
     240,   241,     0,   242,   243,     0,   244,   245,   246,   247,
     248,   249,   250,     0,   252,   253,   254,   255,     1,     2,
       3,     0,     4,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     5,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    16,    17,     0,    19,    20,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    29,
       0,     0,     0,    32,    33,    34,     0,    35,     0,    37,
      38,    39,    40,    41,     0,    42,    43,    44,   308,    46,
     309,    48,    49,    50,    51,    52,     0,   310,     0,   311,
     312,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    67,    68,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,     0,
      82,     0,    84,    85,    86,    87,    88,    89,    90,    91,
       0,     0,     0,    94,     0,    96,    97,    98,   313,   314,
     101,   102,   103,   104,   105,   106,   107,   108,     0,     0,
       0,   109,   110,     0,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,     0,
       0,     0,     0,     0,     0,   138,     0,     0,     0,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,     0,     0,     0,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,     0,     0,   175,   176,   177,     0,     0,   178,
     179,   180,   181,   182,   183,   184,   185,   186,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   187,   188,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,     0,   204,
       0,   206,   207,     0,     0,     0,     0,     0,     0,   209,
     210,   211,   212,   213,   214,   215,   216,     0,     0,   217,
     218,   219,   220,   221,   222,   223,   224,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   232,   233,   234,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   238,   239,
     240,   241,     0,   242,   243,     0,   244,   245,   246,   247,
     248,   249,   250,     0,   252,   253,   254,   255,     1,     2,
       3,     0,     4,     0,     0,     0,     0,     0,     0,     0,
       0,   885,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    16,    17,     0,     0,    20,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    29,
       0,     0,     0,    32,    33,    34,     0,    35,     0,    37,
      38,    39,    40,    41,   886,    42,    43,    44,   308,    46,
     309,    48,    49,    50,    51,    52,     0,   310,     0,   311,
     312,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    67,    68,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,     0,
      82,     0,    84,    85,    86,    87,    88,    89,    90,    91,
       0,     0,     0,    94,     0,    96,    97,    98,   313,   314,
     101,   102,   103,   104,   105,   106,   107,   108,     0,     0,
       0,   109,   110,     0,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,     0,
       0,     0,     0,     0,     0,   138,     0,     0,     0,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,     0,     0,     0,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,     0,     0,   175,   176,   177,     0,     0,   178,
     179,   180,   181,   182,   183,   184,   185,   186,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   187,   188,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,     0,   204,
       0,   206,   207,     0,     0,     0,     0,     0,     0,   209,
     210,   211,   212,   213,   214,   215,   216,     0,     0,   217,
     218,   219,   220,   221,   222,   223,   224,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   232,   233,   234,     0,     0,     0,
       0,     0,     0,     1,     2,     3,     0,     4,   238,   239,
     240,   241,     0,   242,   243,     0,   244,   245,   246,   247,
     248,   249,   250,     0,   252,   253,   254,   255,    16,    17,
       0,     0,    20,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    29,     0,     0,     0,    32,    33,
      34,     0,    35,     0,    37,    38,    39,    40,    41,     0,
      42,    43,    44,   931,    46,   920,    48,    49,    50,    51,
      52,   372,   310,   374,   536,   376,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    67,
      68,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,     0,    82,     0,    84,    85,    86,
      87,    88,    89,    90,    91,     0,     0,     0,    94,     0,
      96,    97,    98,   313,   314,   101,   102,   103,   104,   105,
     106,   107,   108,     0,     0,     0,   109,   110,     0,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,     0,     0,     0,     0,     0,     0,
     138,     0,     0,     0,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,     0,     0,     0,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,     0,     0,   175,
     176,   177,     0,     0,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   187,   188,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,     0,   204,     0,   206,   207,     0,     0,
       0,     0,     0,     0,   209,   210,   211,   212,   213,   214,
     215,   216,     0,     0,   217,   218,   219,   220,   221,   222,
     223,   224,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   232,
     233,   234,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   238,   239,   240,   241,     0,   242,   243,
       0,   244,   245,   246,   247,   248,   249,   250,     0,   252,
     253,   254,   255,     1,     2,     3,     0,     4,   801,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    16,    17,
       0,     0,    20,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    29,     0,     0,     0,    32,    33,
      34,     0,    35,     0,    37,    38,    39,    40,    41,     0,
      42,    43,    44,   308,    46,   309,    48,    49,    50,    51,
      52,     0,   310,     0,   311,   312,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    67,
      68,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,     0,    82,     0,    84,    85,    86,
      87,    88,    89,    90,    91,     0,     0,     0,    94,     0,
      96,    97,    98,   313,   314,   101,   102,   103,   104,   105,
     106,   107,   108,     0,     0,     0,   109,   110,     0,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,     0,     0,     0,     0,     0,     0,
     138,     0,     0,     0,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,     0,     0,     0,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,     0,     0,   175,
     176,   177,     0,     0,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   187,   188,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,     0,   204,     0,   206,   207,     0,     0,
       0,     0,     0,     0,   209,   210,   211,   212,   213,   214,
     215,   216,     0,     0,   217,   218,   219,   220,   221,   222,
     223,   224,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   232,
     233,   234,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   238,   239,   240,   241,     0,   242,   243,
       0,   244,   245,   246,   247,   248,   249,   250,     0,   252,
     253,   254,   255,     1,     2,     3,     0,   506,     0,  1176,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    16,    17,
       0,     0,    20,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    29,     0,     0,     0,    32,    33,
      34,     0,    35,     0,    37,    38,    39,    40,    41,     0,
      42,    43,    44,   308,    46,   309,    48,    49,    50,    51,
      52,     0,   310,     0,   311,   312,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    67,
      68,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,     0,    82,     0,    84,    85,    86,
      87,    88,    89,    90,    91,     0,     0,     0,    94,     0,
      96,    97,    98,   313,   314,   101,   102,   103,   104,   105,
     106,   107,   108,     0,     0,     0,   109,   110,     0,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,     0,     0,     0,     0,     0,     0,
     138,     0,     0,     0,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,     0,     0,     0,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,     0,     0,   175,
     176,   177,     0,     0,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   187,   188,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,     0,   204,     0,   206,   207,     0,     0,
       0,     0,     0,     0,   209,   210,   211,   212,   213,   214,
     215,   216,     0,     0,   217,   218,   219,   220,   221,   222,
     223,   224,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   232,
     233,   234,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   238,   239,   240,   241,     0,   242,   243,
       0,   244,   245,   246,   247,   248,   249,   250,     0,   252,
     253,   254,   255,     1,     2,     3,     0,   329,     0,  1179,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    16,    17,
       0,     0,    20,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    29,     0,     0,     0,    32,    33,
      34,     0,    35,     0,    37,    38,    39,    40,    41,     0,
      42,    43,    44,   308,    46,   309,    48,    49,    50,    51,
      52,     0,   310,     0,   311,   312,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    67,
      68,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,     0,    82,     0,    84,    85,    86,
      87,    88,    89,    90,    91,     0,     0,     0,    94,     0,
      96,    97,    98,   313,   314,   101,   102,   103,   104,   105,
     106,   107,   108,     0,     0,     0,   109,   110,     0,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,     0,     0,     0,     0,     0,     0,
     138,     0,     0,     0,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,     0,     0,     0,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,     0,     0,   175,
     176,   177,     0,     0,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   187,   188,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,     0,   204,     0,   206,   207,     0,     0,
       0,     0,     0,     0,   209,   210,   211,   212,   213,   214,
     215,   216,     0,     0,   217,   218,   219,   220,   221,   222,
     223,   224,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   232,
     233,   234,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   238,   239,   240,   241,     0,   242,   243,
       0,   244,   245,   246,   247,   248,   249,   250,     0,   252,
     253,   254,   255,     1,     2,     3,     0,   506,     0,  1182,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    16,    17,
       0,     0,    20,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    29,     0,     0,     0,    32,    33,
      34,     0,    35,     0,    37,    38,    39,    40,    41,     0,
      42,    43,    44,   308,    46,   309,    48,    49,    50,    51,
      52,     0,   310,     0,   311,   312,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    67,
      68,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,     0,    82,     0,    84,    85,    86,
      87,    88,    89,    90,    91,     0,     0,     0,    94,     0,
      96,    97,    98,   313,   314,   101,   102,   103,   104,   105,
     106,   107,   108,     0,     0,     0,   109,   110,     0,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,     0,     0,     0,     0,     0,     0,
     138,     0,     0,     0,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,     0,     0,     0,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,     0,     0,   175,
     176,   177,     0,     0,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   187,   188,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,     0,   204,     0,   206,   207,     0,     0,
       0,     0,     0,     0,   209,   210,   211,   212,   213,   214,
     215,   216,     0,     0,   217,   218,   219,   220,   221,   222,
     223,   224,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   232,
     233,   234,     0,     0,     0,     0,     0,     0,     1,     2,
       3,     0,     4,   238,   239,   240,   241,     0,   242,   243,
       0,   244,   245,   246,   247,   248,   249,   250,     0,   252,
     253,   254,   255,    16,    17,     0,     0,    20,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    29,
       0,     0,     0,    32,    33,    34,     0,    35,     0,    37,
      38,    39,    40,    41,     0,    42,    43,    44,   308,    46,
     309,    48,    49,    50,    51,    52,     0,   310,     0,   311,
     312,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    67,    68,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,     0,
      82,     0,    84,    85,    86,    87,    88,    89,    90,    91,
       0,     0,     0,    94,     0,    96,    97,    98,   313,   314,
     101,   102,   103,   104,   105,   106,   107,   108,     0,     0,
       0,   109,   110,     0,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,     0,
       0,     0,     0,     0,     0,   138,     0,     0,     0,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,     0,     0,     0,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,     0,     0,   175,   176,   177,     0,     0,   178,
     179,   180,   181,   182,   183,   184,   185,   186,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   187,   188,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,     0,   204,
       0,   206,   207,     0,     0,     0,     0,     0,     0,   209,
     210,   211,   212,   213,   214,   215,   216,     0,     0,   217,
     218,   219,   220,   221,   222,   223,   224,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   232,   233,   234,     0,     0,     0,
       0,     0,     0,     1,     2,     3,     0,   329,   238,   239,
     240,   241,     0,   242,   243,     0,   244,   245,   246,   247,
     248,   249,   250,     0,   252,   253,   254,   255,    16,    17,
       0,     0,    20,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    29,     0,     0,     0,    32,    33,
      34,     0,    35,     0,    37,    38,    39,    40,    41,     0,
      42,    43,    44,   308,    46,   309,    48,    49,    50,    51,
      52,     0,   310,     0,   311,   312,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    67,
      68,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,     0,    82,     0,    84,    85,    86,
      87,    88,    89,    90,    91,     0,     0,     0,    94,     0,
      96,    97,    98,   313,   314,   101,   102,   103,   104,   105,
     106,   107,   108,     0,     0,     0,   109,   110,     0,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,     0,     0,     0,     0,     0,     0,
     138,     0,     0,     0,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,     0,     0,     0,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,     0,     0,   175,
     176,   177,     0,     0,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   187,   188,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,     0,   204,     0,   206,   207,     0,     0,
       0,     0,     0,     0,   209,   210,   211,   212,   213,   214,
     215,   216,     0,     0,   217,   218,   219,   220,   221,   222,
     223,   224,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   232,
     233,   234,     0,     0,     0,     0,     0,     0,     1,     2,
       3,     0,   506,   238,   239,   240,   241,     0,   242,   243,
       0,   244,   245,   246,   247,   248,   249,   250,     0,   252,
     253,   254,   255,    16,    17,     0,     0,    20,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    29,
       0,     0,     0,    32,    33,    34,     0,    35,     0,    37,
      38,    39,    40,    41,     0,    42,    43,    44,   308,    46,
     309,    48,    49,    50,    51,    52,     0,   310,     0,   311,
     312,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    67,    68,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,     0,
      82,     0,    84,    85,    86,    87,    88,    89,    90,    91,
       0,     0,     0,    94,     0,    96,    97,    98,   313,   314,
     101,   102,   103,   104,   105,   106,   107,   108,     0,     0,
       0,   109,   110,     0,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,     0,
       0,     0,     0,     0,     0,   138,     0,     0,     0,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,     0,     0,     0,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,     0,     0,   175,   176,   177,     0,     0,   178,
     179,   180,   181,   182,   183,   184,   185,   186,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   187,   188,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,     0,   204,
       0,   206,   207,     0,     0,     0,     0,     0,     0,   209,
     210,   211,   212,   213,   214,   215,   216,     0,     0,   217,
     218,   219,   220,   221,   222,   223,   224,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   232,   233,   234,     0,     0,     0,
       0,     0,     0,     1,     2,     3,     0,     4,   238,   239,
     240,   241,     0,   242,   243,     0,   244,   245,   246,   247,
     248,   249,   250,     0,   252,   253,   254,   255,    16,    17,
       0,     0,    20,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    29,     0,     0,     0,    32,    33,
      34,     0,    35,     0,    37,    38,    39,    40,    41,     0,
      42,    43,    44,   308,    46,   309,    48,    49,    50,    51,
      52,     0,   310,     0,   311,   312,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    67,
      68,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,     0,    82,     0,    84,    85,    86,
      87,    88,    89,    90,    91,     0,     0,     0,    94,     0,
      96,    97,    98,   313,   314,   101,   102,   103,   104,   105,
     106,   107,   108,     0,     0,     0,   109,   110,     0,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,     0,     0,     0,     0,     0,     0,
     138,     0,     0,     0,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,     0,     0,     0,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,     0,     0,   175,
     176,   177,     0,     0,   178,   179,   180,   181,   182,   183,
     184,   185,   914,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   187,   188,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,     0,   204,     0,   206,   207,     0,     0,
       0,     0,     0,     0,   209,   210,   211,   212,   213,   214,
     215,   216,     0,     0,   217,   218,   219,   220,   221,   222,
     223,   224,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   232,
     233,   234,     0,     0,     0,     0,     0,     0,     1,     0,
       0,     0,   307,   238,   239,   240,   241,     0,   242,   243,
       0,   244,   245,   246,   247,   248,   249,   250,     0,   252,
     253,   254,   255,    16,    17,     0,     0,    20,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    29,
       0,     0,     0,    32,    33,    34,     0,    35,     0,    37,
      38,    39,    40,    41,     0,    42,    43,    44,   308,    46,
     309,    48,    49,    50,    51,    52,     0,   310,     0,   311,
     312,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,     0,
      82,     0,    84,    85,    86,    87,    88,    89,    90,    91,
       0,     0,     0,    94,     0,    96,    97,    98,   313,   314,
     101,   102,   103,   104,   105,   106,   107,   108,     0,     0,
       0,   109,   110,     0,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,     0,
       0,     0,     0,     0,     0,   138,     0,     0,     0,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,     0,     0,     0,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,     0,     0,   175,   176,   177,     0,     0,   178,
     179,   180,   181,   182,   183,   184,   185,   186,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   187,   188,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,     0,   204,
       0,   206,   207,     0,     0,     0,     0,     0,     0,   209,
     210,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   232,   233,   234,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   307,   238,   239,
     240,   241,     0,   242,   243,     0,   244,   245,   246,   247,
     248,   249,   250,     0,   252,   253,   254,   255,    16,    17,
       0,     0,    20,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    29,     0,     0,     0,    32,    33,
      34,     0,    35,     0,    37,    38,    39,    40,    41,     0,
      42,    43,    44,   308,    46,   309,    48,    49,    50,    51,
      52,     0,   310,     0,   311,   312,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,     0,    82,     0,    84,    85,    86,
      87,    88,    89,    90,    91,     0,     0,     0,    94,     0,
      96,    97,    98,   313,   314,   101,   102,   103,   104,   105,
     106,   107,   108,     0,     0,     0,   109,   110,     0,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,     0,     0,     0,     0,     0,     0,
     138,     0,     0,     0,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,     0,     0,     0,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,     0,     0,   175,
     176,   177,     0,     0,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   187,   188,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,     0,   204,     0,   206,   207,     0,     0,
       0,     0,     0,     0,   209,   210,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   232,
     233,   234,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   238,   239,   240,   241,     0,   242,   243,
       0,   244,   245,   246,   247,   248,   249,   250,     0,   252,
     253,   254,   255
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
         8,     9,    10,   227,     0,    58,   537,   538,     1,    23,
     116,    23,    19,    46,    41,    16,    60,   548,   390,   391,
     392,   393,   394,   395,   396,    37,   398,   399,    60,  1771,
    1772,  1773,    19,   405,    78,    15,    60,    81,     4,    53,
      21,     0,    69,   415,   416,     5,     6,    46,    47,    81,
      23,    22,    79,   590,   591,   592,    19,    81,   430,    56,
      95,    56,    19,    60,    37,    60,    13,    95,    96,    97,
      98,    99,    19,   445,   446,   447,   448,   449,   450,   451,
      13,   116,    15,    59,    81,    14,    81,   624,   116,   249,
     250,    20,   105,   106,    23,    13,   468,   469,   470,    58,
      76,   114,    53,    54,   105,   106,    14,    20,    14,   269,
      23,    19,    13,   114,    20,    95,    14,    23,    19,    20,
     492,    19,    20,   347,   348,   497,    13,    61,   109,   116,
      64,   503,   165,    96,    97,    13,    56,    54,   109,    59,
      13,    92,    13,   515,   516,   517,    19,    20,    19,    59,
     110,   111,    72,    73,    74,    75,    20,   164,    22,    23,
     384,    13,   230,   359,   360,   361,   362,   363,    13,   365,
       7,     8,   544,    13,   227,    12,    93,   549,   550,   130,
     552,   553,    15,   555,   556,   557,   558,   559,   560,   561,
      13,   563,   564,   565,    10,    11,    19,   265,   359,   360,
     361,   362,   363,    14,   365,   273,    13,    14,   159,    20,
      13,   225,    19,   164,   165,   166,   167,   168,    13,    14,
      13,   229,   236,   237,    19,    54,   332,    13,    14,    13,
      14,    18,    14,    19,    14,    19,    13,  1979,    20,  1981,
      20,   613,  1984,  1985,   271,    14,   197,   198,   199,    14,
      13,    20,   159,   160,   161,    20,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,    13,   227,   265,
      13,    59,    60,    61,    62,    63,    64,    13,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,   347,   348,   340,    14,    14,    14,
     159,   160,   161,    20,    20,    20,   265,   306,   307,   308,
     309,    13,   112,   113,    14,    14,    14,    19,   542,   327,
      20,    20,    20,    14,   275,   276,    14,   339,   279,    20,
     281,   384,    20,    14,    14,    14,    14,   249,   250,    20,
      20,    20,    20,   357,   352,    14,    19,    14,   299,    14,
      14,    20,   360,    20,   362,    20,    20,    19,    14,    14,
      14,    14,   279,   329,    20,    20,    20,    20,    14,    14,
      14,   307,   308,    14,    20,    20,    20,   385,   386,    20,
      14,    14,   299,  2125,    14,    14,    20,    20,   347,   348,
      20,    20,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,    14,    14,    13,    13,    15,    14,
      20,    20,   200,   201,   202,    20,    20,    14,    22,   207,
     208,   209,   210,    20,   212,   384,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,    14,    14,
      14,    14,    14,    13,    20,    20,    20,    20,    20,   237,
     279,    13,   240,   241,   242,   243,   244,   245,    14,    14,
     248,     2,     3,    14,    20,    20,    19,    14,    14,    20,
     299,    14,   540,    20,    20,   593,   594,    20,   249,   250,
     251,    13,   253,   254,   255,   493,   494,   258,   496,   542,
     261,   262,   263,   264,   265,   266,   267,   268,    13,   270,
     508,    13,    20,   274,    22,    13,   277,   278,    13,   280,
      15,   282,   283,   581,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,    67,    68,   542,   607,
     608,   609,   610,   611,   612,   595,   596,   597,   598,    13,
     506,    15,   599,   600,    13,    13,    13,    13,    13,    60,
      61,    62,    63,    64,   562,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    13,    13,    13,    13,    13,   584,    13,    13,    13,
      13,  1112,    13,   542,  1115,    13,    13,    13,    13,   377,
     378,   379,    13,    13,   382,   383,   589,   385,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
     618,   619,    13,    13,   622,    13,    13,    13,    13,   615,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,  1003,  1004,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,   614,   615,    13,    13,    13,
      13,    13,    13,  1035,   672,    13,    13,    13,  1040,  1041,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    13,    13,    13,    13,    13,   200,
     201,   202,    13,    13,    13,    13,   207,   208,   209,   210,
      13,   212,   200,   201,   202,    13,   930,    13,    13,   207,
     208,   209,   210,    13,   212,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,   237,    13,    13,   240,
     241,   242,   243,   244,   245,    13,    13,   248,    13,   237,
      13,    13,   240,   241,   242,   243,   244,   245,    13,   817,
     248,    13,    13,    13,    13,    13,    13,    13,    13,   827,
      13,    13,    13,    13,    13,    13,    13,    13,    13,  1141,
      13,    13,  1144,  1145,     0,    19,    15,    17,   108,     4,
      13,    19,    19,    19,    15,    15,    14,    19,   275,   305,
      19,    78,   248,    15,    78,    78,    78,    78,    78,    78,
     354,    22,    56,    20,    78,   813,    14,  1338,    78,    78,
     376,    14,    14,    20,   159,    56,   159,    14,    13,    13,
      13,    13,    57,    13,    13,    13,    13,    13,    13,    56,
      13,    65,    13,    13,    13,    13,    20,    13,    13,    13,
      13,   368,    58,    20,    16,    15,    14,    16,  1220,    20,
      14,    14,    14,  1225,    20,    16,    14,    16,    14,    16,
      20,    14,    14,    78,    13,    20,   377,   378,   379,    20,
      20,   382,   383,    20,   385,    20,    20,   930,    20,   377,
     378,   379,    20,    20,   382,   383,    20,   385,    20,    20,
      20,    20,    20,    20,    20,    20,    13,    20,  1270,    14,
      20,    20,    20,   116,    20,    14,    20,    20,    20,    20,
      20,    14,    14,    20,    14,    20,    20,   116,    14,    20,
     916,    20,    20,    20,    14,    20,    20,    16,    20,    20,
      16,    13,    20,    20,   942,   943,    20,    20,   946,   947,
      20,   949,   950,   951,   952,   953,    20,    20,    20,    14,
     958,   959,   960,   961,   962,    14,    20,   916,    20,    20,
      20,    19,   970,    20,    20,    20,    20,    20,    20,    20,
      20,   930,    14,    14,    20,    20,    20,    20,   986,   987,
      20,   989,   990,   991,   992,   993,    20,   995,   996,   997,
     998,   999,  1000,    20,  1002,    20,    20,    20,    20,    20,
    1531,  1009,  1010,  1011,  1012,  1013,  1014,  1015,  1016,    20,
    1018,  1542,    20,  1544,    20,    20,    14,    14,    14,    20,
      20,    20,    69,    14,    14,  1033,    20,    20,    20,  1037,
    1038,  1039,    20,    20,  1042,  1043,  1044,  1045,  1046,  1047,
    1412,  1049,    20,    14,  1052,  1053,  1054,  1055,  1056,  1057,
    1058,  1059,  1060,  1061,    14,    14,  1064,    14,    14,    14,
      14,    14,    20,    14,    14,  1073,  1074,  1075,  1076,  1077,
    1078,  1079,  1080,  1081,  1082,  1083,    20,    20,    20,  1087,
    1088,    14,  1090,  1091,    13,  1093,  1094,  1095,  1096,  1097,
      20,    13,  1100,    20,    20,    20,    20,    20,    78,    20,
    1108,  1109,    20,    20,    20,    20,    14,    14,    14,    20,
      20,    20,  1120,    14,    13,    20,    13,    13,    13,  1127,
    1128,    13,  1130,  1131,    13,  1497,  1134,  1135,  1136,  1501,
    1138,    13,  1140,    13,  1142,  1143,    13,    13,    13,    13,
      13,  1149,    20,    22,    13,  1153,  1154,  1155,    13,    13,
    1158,    13,    20,    16,  1526,  1163,  1164,  1165,  1166,  1167,
    1168,  1169,    16,  1171,    16,    13,  1390,    13,  1176,    13,
      13,  1179,    76,    20,  1182,   329,  1184,  1185,    14,    77,
      22,    20,    20,    20,    14,    79,  1558,    14,    20,  1561,
      14,    20,    20,    19,  1190,    20,    14,    20,    20,    20,
      14,    14,    14,    20,    14,    14,    59,    14,    16,    20,
      14,    14,    14,    14,    20,    20,    14,    14,    14,    59,
      20,    20,    56,    79,    59,    20,    20,    20,    20,    20,
      20,  1190,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    14,    14,    20,    20,    20,
      20,    14,    14,    20,    20,    20,    14,    14,    14,  1327,
    1328,    14,   269,   330,   299,    20,    20,    14,    20,    20,
      20,    20,    20,    14,    20,    14,    14,    14,    14,    22,
      20,    14,    56,   116,    14,    20,    20,  1818,    20,    20,
      14,    20,    20,    20,    20,    20,    14,    20,    14,    14,
      14,    14,    14,    14,   265,    22,  1123,    14,    14,    14,
      20,    20,    20,    14,    14,    14,    20,  1325,    20,    14,
     265,  1175,    20,    20,    20,    14,    20,    20,    20,    20,
      20,    14,    20,    14,    20,    20,    20,  1390,    59,    59,
      59,    20,    14,    20,    14,    20,    20,    20,    14,    14,
      14,    20,    14,    20,    14,   955,    59,    20,  1218,    20,
      16,    20,    20,    20,    16,    14,    16,    20,    14,    14,
      14,    14,    20,    14,   265,    14,    56,    59,    20,    14,
      20,    59,    20,    20,    20,    19,  1394,    20,  1396,    20,
    1398,    20,    14,  1401,  1402,  1403,  1404,    14,    14,    20,
    1408,    20,    14,  1411,    14,    20,    20,  1415,    14,    20,
     265,    20,    20,    20,    14,    20,    20,  1789,    20,  1791,
    1792,    20,  1794,    20,  1432,    20,    20,    20,    20,  1437,
      20,  1390,    20,  1441,  1442,  1443,  1444,  1445,  1446,  1447,
    1448,  1449,  1450,  1451,  1452,  1453,  1454,  1455,  1456,  1457,
    1458,  1459,  1460,    20,    20,  1463,    20,    20,    20,    20,
      14,    14,  1834,  1471,  1430,    20,    14,   602,    20,  1477,
    1478,  1479,  1480,    20,  1482,  1483,  1484,  1545,  1486,  1487,
      20,    20,    20,    20,    20,  1493,  1494,  1495,  1496,    20,
      14,    14,    20,    20,  1502,    20,    14,  1505,  1506,    20,
      20,    20,    14,    20,    20,    14,    14,  1515,  1516,  1517,
    1518,    14,    14,    20,    20,    20,    59,    59,    59,    20,
    1528,  1529,  1530,    20,    20,    20,    14,  1535,    20,    20,
      14,    20,    14,    20,    20,    20,    14,    20,   601,  1547,
    1548,    20,  1550,  1551,    20,  1553,  1554,  1555,    20,    20,
      20,  1559,  1560,    20,    22,  1563,    20,    14,  1566,    14,
    1568,  1569,  1570,    14,    20,    14,    20,  1575,    20,    14,
    1578,    14,  1580,    20,    20,    14,  1584,  1585,  1586,    20,
    1588,  1589,  1590,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    14,    14,    14,    20,    20,    20,   603,
     614,   604,    20,    20,    20,    20,    20,    20,    20,    14,
    1618,    14,    20,    20,    14,    14,    20,    14,  1686,    20,
    1688,    14,    20,    14,    20,    20,    14,  1695,    14,    14,
      14,    20,    14,    20,   606,   265,   605,    20,  2010,    20,
      20,    20,    20,    20,    20,    20,    14,    14,    20,    20,
      14,    14,    14,  2025,    14,    14,    14,    14,    14,    20,
      14,    14,    14,    14,    14,    20,    14,    14,    14,    14,
      14,    20,    -1,    14,   265,    14,    14,  1685,    20,    14,
      20,    14,    14,    20,    14,    14,    20,    14,    14,    14,
     265,    14,    20,    14,    14,    -1,    20,    -1,    20,    -1,
      14,    20,    20,    20,    20,    20,    14,    20,    20,    14,
      20,    20,    -1,    20,    20,    14,    20,    20,    20,    20,
      14,  1729,    22,  1731,    22,  1733,  1734,  1735,  1736,    20,
      14,    14,  1740,  1741,    20,    14,    14,    -1,    20,    20,
      20,  1749,  1750,    20,    20,  1753,    20,  1755,    20,  1757,
      20,  1759,  1760,  1761,  1762,    20,  1764,  1765,  1766,  1767,
    1768,  1769,    20,  1771,  1772,    14,  1774,  1775,  1776,  1777,
      20,  1779,  1780,  1781,  1782,  1783,  2148,  1785,    20,    20,
      20,  1747,    14,    14,    14,    14,    14,  1795,  1796,  1797,
    1798,  1799,  1800,  1801,    20,    14,  1804,    20,    20,  1807,
    1808,    -1,  1810,  1811,  1812,    20,    20,    20,  1816,  1817,
      14,    20,  1820,    20,    20,    20,    14,    14,    20,    14,
      14,  1829,  1830,    14,  1832,    14,    14,    20,  1836,  1837,
      20,  1839,  1840,    20,  1842,    20,  1844,  1845,    20,  1847,
      14,  1849,  1850,  1851,  1852,  1853,  1854,  1855,  1856,  1857,
    1858,    20,    14,    14,    20,    20,    20,  1925,    -1,    -1,
    2232,    20,    14,    20,    20,    20,    20,  2239,    14,    20,
      20,    20,    14,  2245,    -1,    -1,    -1,    -1,    -1,    -1,
    2252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    61,    62,    63,    64,  2279,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1951,    -1,  1953,  1954,  1955,    -1,  1957,
      -1,    -1,    -1,    -1,  1962,  1963,    -1,  1965,    -1,  1967,
    1968,  1969,  1970,  1971,    -1,  1973,  1974,  1975,  1976,  1977,
    1978,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1986,  1987,
    1988,    -1,    -1,     0,    -1,    -1,  1994,  1995,    -1,    -1,
    1998,    -1,  2000,  2001,    -1,  1961,  2004,  2005,    -1,  2007,
    2008,    -1,    -1,    -1,    -1,    22,  2014,    -1,    25,    -1,
      -1,    -1,    -1,  2021,  2022,  2023,    -1,    -1,  2026,  2027,
    2028,  2029,    -1,  2031,    -1,    -1,  2034,  2035,    -1,    -1,
      -1,    -1,    -1,    -1,  2042,    -1,    -1,    -1,    -1,    -1,
      -1,    58,   200,   201,   202,    -1,    -1,    -1,    -1,   207,
     208,   209,   210,    -1,   212,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,
      -1,    -1,   240,   241,   242,   243,   244,   245,    -1,    -1,
     248,    -1,    -1,    -1,    -1,    -1,  2104,    -1,    -1,  2107,
      -1,    -1,    -1,    -1,    -1,  2113,    -1,  2115,    -1,  2117,
      -1,    -1,  2120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2130,  2131,    -1,  2133,    -1,    -1,  2136,  2137,
    2138,  2139,  2140,    -1,    -1,    -1,  2144,    -1,  2146,    -1,
      -1,  2149,  2150,  2151,  2152,    -1,  2154,  2155,    -1,  2157,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2185,  2186,    -1,
      -1,    -1,  2190,    -1,  2192,  2193,    -1,  2195,  2196,  2197,
      -1,  2199,  2200,    -1,  2202,  2203,  2204,    -1,  2206,    -1,
    2208,  2209,    -1,  2211,    -1,    -1,    -1,    -1,    -1,    -1,
     227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   377,
     378,   379,    -1,    -1,   382,   383,    -1,   385,    -1,  2237,
      -1,    -1,    -1,  2241,  2242,  2243,    -1,    -1,  2246,  2247,
      -1,    -1,  2250,    -1,    -1,  2253,  2254,  2255,   265,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2270,    -1,    -1,  2273,    -1,    -1,    -1,  2277,
      -1,    -1,  2280,  2281,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,  2292,    30,    -1,  2295,    -1,    -1,
      -1,    -1,  2300,  2301,  2302,    -1,    -1,    -1,  2306,  2307,
      -1,    -1,    -1,  2311,  2312,    -1,    -1,  2315,  2316,    -1,
      -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     347,   348,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   384,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     397,    -1,    -1,   400,   401,   402,   403,   404,    -1,   406,
     407,   408,   409,   410,   411,   412,   413,   414,    -1,    -1,
     417,    -1,    -1,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,    -1,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,    -1,
      -1,    -1,    -1,    -1,    -1,   452,   453,   454,   455,   456,
     457,   458,   459,   460,    -1,    -1,   463,   464,   465,   466,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   476,
     477,   478,    -1,    -1,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,    -1,    -1,    -1,   495,   496,
      -1,   498,    -1,   500,    -1,   230,   231,   504,   505,    -1,
      -1,    -1,    -1,   510,   511,   512,   513,    -1,    -1,    -1,
      -1,   518,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   542,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   551,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   569,   570,   571,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   589,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   326,    -1,   328,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     345,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   472,    -1,   474,
     475,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     0,    -1,    -1,   514,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    -1,    30,    -1,   543,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   566,   567,    -1,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   930,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   668,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   985,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   994,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1005,  1006,
    1007,    -1,    -1,    -1,    -1,    -1,   230,   231,    -1,    -1,
    1017,    -1,    -1,    -1,    -1,  1022,    -1,  1024,  1025,  1026,
    1027,  1028,    -1,  1030,  1031,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1062,    -1,    -1,    -1,    -1,
      -1,  1068,  1069,  1070,  1071,  1072,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   814,
      -1,    -1,    -1,   307,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   326,    -1,   328,   329,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   345,  1129,    -1,    -1,  1132,   861,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1151,  1152,    -1,    -1,    -1,    -1,
      -1,    -1,  1159,    -1,  1161,  1162,  1163,  1164,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   389,   390,   391,   392,   393,
     394,   395,   396,    -1,   398,   399,    -1,    -1,    -1,    -1,
      -1,   405,   917,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   415,   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   939,    -1,   430,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1226,
    1227,   445,   446,   447,   448,   449,   450,   451,    -1,    -1,
     965,    -1,   967,    -1,    -1,    -1,    -1,    -1,   973,    -1,
      -1,    -1,    -1,    -1,   468,   469,   470,    -1,   472,    -1,
     474,   475,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   492,    -1,
      -1,    -1,    -1,   497,    -1,    -1,    -1,    -1,    -1,   503,
      -1,    -1,   506,    -1,    -1,   509,    -1,    -1,    -1,    -1,
     514,   515,   516,   517,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   543,
     544,    -1,    -1,    -1,    -1,   549,   550,    -1,   552,   553,
    1065,   555,   556,   557,   558,   559,   560,   561,    -1,   563,
     564,   565,   566,   567,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     584,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1390,    -1,    -1,    -1,  1394,    -1,   613,
     614,   615,    -1,    -1,    -1,    -1,    -1,    -1,   622,    -1,
      -1,    -1,    -1,  1410,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1150,    -1,    -1,    -1,    -1,
      -1,    -1,  1157,  1430,  1431,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1440,    -1,   659,   660,    -1,    -1,    -1,
      -1,  1448,    -1,    -1,   668,  1180,    -1,    -1,    -1,    -1,
      -1,  1186,  1187,    -1,    -1,    -1,    -1,  1464,  1465,  1466,
    1467,  1468,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1503,  1504,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1520,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1565,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     814,  1326,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   861,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1393,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     914,    -1,   916,   917,    -1,    -1,    -1,    -1,   922,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   939,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1747,   965,    -1,   967,    -1,    -1,    -1,    -1,    -1,   973,
      -1,    -1,    -1,    -1,   978,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1771,  1772,  1773,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1784,    -1,  1003,
    1004,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1805,  1806,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1035,    -1,    -1,    -1,    -1,  1040,  1041,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1841,    -1,    -1,    -1,    -1,    -1,
      -1,  1065,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1107,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1141,    -1,    -1,
    1144,  1145,    -1,    -1,    -1,    -1,  1150,    -1,    -1,    -1,
      -1,    -1,    -1,  1157,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1961,    -1,  1180,    -1,    -1,    -1,
      -1,    -1,  1186,  1187,    -1,    -1,  1190,    -1,    -1,    -1,
      -1,    -1,  1979,    -1,  1981,    -1,    -1,  1984,  1985,    -1,
      -1,    -1,  1989,  1990,  1991,  1992,    -1,    -1,    -1,    -1,
    1725,  1726,    -1,    -1,    -1,    -1,  1220,    -1,    -1,    -1,
      -1,  1225,    -1,    -1,  2011,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2030,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1270,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1326,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2125,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2142,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2153,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1393,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1412,    -1,
      -1,    -1,    -1,    -1,  2201,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2210,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1482,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1497,    -1,  2282,    -1,  1501,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2296,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1526,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     9,    10,    11,    -1,    13,    -1,    -1,
      -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1558,    -1,    -1,  1561,    34,    35,
      -1,    -1,    38,    39,    -1,    41,    -1,    -1,    -1,  1573,
      -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    54,    55,
      56,    -1,    58,    -1,    60,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,    -1,   131,    -1,   133,   134,   135,
     136,   137,   138,   139,   140,    -1,    -1,    -1,   144,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,    -1,    -1,    -1,   162,   163,    -1,    -1,
      -1,    -1,    -1,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,    -1,    -1,    -1,    -1,    -1,    -1,
     196,  1725,  1726,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,    -1,    -1,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,   235,
     236,   237,    -1,    -1,   240,   241,   242,   243,   244,   245,
     246,   247,   248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1789,    -1,  1791,  1792,    -1,
    1794,    -1,    -1,    -1,    -1,   271,   272,   273,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,    -1,   300,    -1,   302,   303,    -1,   305,
    1834,    -1,    -1,    -1,   310,   311,   312,   313,   314,   315,
     316,   317,    -1,    -1,   320,   321,   322,   323,   324,   325,
     326,   327,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   355,
     356,   357,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   369,   370,   371,   372,    -1,   374,   375,
      -1,   377,   378,   379,   380,   381,   382,   383,    -1,   385,
     386,   387,   388,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2010,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2025,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,  2148,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2232,    -1,
      -1,    -1,    -1,    -1,     0,  2239,    -1,    -1,    -1,    -1,
      -1,  2245,    -1,     9,    10,    11,    -1,    13,  2252,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,  2279,    42,    43,    44,    45,
      46,    47,    48,    -1,    50,    51,    52,    -1,    54,    55,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    -1,
      86,    87,    88,    89,    90,    91,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,    -1,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,    -1,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,    -1,    -1,    -1,   162,   163,    -1,    -1,
      -1,    -1,    -1,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,    -1,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,    -1,    -1,   240,   241,   242,   243,   244,   245,
     246,   247,   248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   272,   273,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,    -1,   300,   301,   302,   303,   304,    -1,
      -1,    -1,    -1,    -1,   310,   311,   312,   313,   314,   315,
     316,   317,    -1,    -1,   320,   321,   322,   323,   324,   325,
     326,   327,   328,    -1,    -1,    -1,    -1,   333,    -1,   335,
     336,   337,    -1,    -1,    -1,   341,   342,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   355,
     356,   357,   358,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     366,   367,    -1,   369,   370,   371,   372,    -1,   374,   375,
      -1,   377,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,     0,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    -1,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    51,    52,    -1,    54,    55,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    -1,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    -1,    86,    87,    88,
      89,    90,    91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   105,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,    -1,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,    -1,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
      -1,    -1,    -1,   162,   163,    -1,    -1,    -1,    -1,    -1,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,    -1,
      -1,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,    -1,
      -1,   240,   241,   242,   243,   244,   245,   246,   247,   248,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   272,   273,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
      -1,   300,   301,   302,   303,   304,    -1,    -1,    -1,    -1,
      -1,   310,   311,   312,   313,   314,   315,   316,   317,    -1,
      -1,   320,   321,   322,   323,   324,   325,   326,   327,   328,
      -1,    -1,    -1,    -1,   333,    -1,   335,   336,   337,    -1,
      -1,    -1,   341,   342,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   355,   356,   357,   358,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   366,   367,    -1,
     369,   370,   371,   372,    -1,   374,   375,    -1,   377,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,     9,    10,
      11,    -1,    13,    14,    -1,    -1,    17,    -1,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    -1,    -1,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      -1,    -1,    -1,    54,    55,    56,    -1,    58,    -1,    60,
      61,    62,    63,    64,    -1,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,    -1,
     131,    -1,   133,   134,   135,   136,   137,   138,   139,   140,
      -1,    -1,    -1,   144,    -1,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,    -1,    -1,
      -1,   162,   163,    -1,    -1,    -1,    -1,    -1,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,    -1,
      -1,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,    -1,    -1,    -1,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,   235,   236,   237,    -1,    -1,   240,
     241,   242,   243,   244,   245,   246,   247,   248,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   272,   273,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,    -1,   300,
      -1,   302,   303,    -1,    -1,    -1,    -1,    -1,    -1,   310,
     311,   312,   313,   314,   315,   316,   317,    -1,    -1,   320,
     321,   322,   323,   324,   325,   326,   327,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   355,   356,   357,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   369,   370,
     371,   372,    -1,   374,   375,    -1,   377,   378,   379,   380,
     381,   382,   383,    -1,   385,   386,   387,   388,     9,    10,
      11,    -1,    13,    -1,    -1,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    -1,    -1,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      -1,    -1,    -1,    54,    55,    56,    -1,    58,    -1,    60,
      61,    62,    63,    64,    -1,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,    -1,
     131,    -1,   133,   134,   135,   136,   137,   138,   139,   140,
      -1,    -1,    -1,   144,    -1,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,    -1,    -1,
      -1,   162,   163,    -1,    -1,    -1,    -1,    -1,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,    -1,
      -1,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,    -1,    -1,    -1,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,   235,   236,   237,    -1,    -1,   240,
     241,   242,   243,   244,   245,   246,   247,   248,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   272,   273,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,    -1,   300,
      -1,   302,   303,    -1,    -1,    -1,    -1,    -1,    -1,   310,
     311,   312,   313,   314,   315,   316,   317,    -1,    -1,   320,
     321,   322,   323,   324,   325,   326,   327,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   355,   356,   357,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   369,   370,
     371,   372,    -1,   374,   375,    -1,   377,   378,   379,   380,
     381,   382,   383,    -1,   385,   386,   387,   388,     9,    10,
      11,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      -1,    -1,    -1,    54,    55,    56,    -1,    58,    -1,    60,
      61,    62,    63,    64,    -1,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    -1,    78,    -1,    80,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,    -1,
     131,    -1,   133,   134,   135,   136,   137,   138,   139,   140,
      -1,    -1,    -1,   144,    -1,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,    -1,    -1,
      -1,   162,   163,    -1,    -1,    -1,    -1,    -1,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,    -1,
      -1,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,    -1,    -1,    -1,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,   235,   236,   237,    -1,    -1,   240,
     241,   242,   243,   244,   245,   246,   247,   248,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   272,   273,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,    -1,   300,
      -1,   302,   303,    -1,    -1,    -1,    -1,    -1,    -1,   310,
     311,   312,   313,   314,   315,   316,   317,    -1,    -1,   320,
     321,   322,   323,   324,   325,   326,   327,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   355,   356,   357,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   369,   370,
     371,   372,    -1,   374,   375,    -1,   377,   378,   379,   380,
     381,   382,   383,    -1,   385,   386,   387,   388,     9,    10,
      11,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    -1,    -1,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      -1,    -1,    -1,    54,    55,    56,    -1,    58,    -1,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    -1,    78,    -1,    80,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,    -1,
     131,    -1,   133,   134,   135,   136,   137,   138,   139,   140,
      -1,    -1,    -1,   144,    -1,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,    -1,    -1,
      -1,   162,   163,    -1,    -1,    -1,    -1,    -1,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,    -1,
      -1,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,    -1,    -1,    -1,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,   235,   236,   237,    -1,    -1,   240,
     241,   242,   243,   244,   245,   246,   247,   248,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   272,   273,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,    -1,   300,
      -1,   302,   303,    -1,    -1,    -1,    -1,    -1,    -1,   310,
     311,   312,   313,   314,   315,   316,   317,    -1,    -1,   320,
     321,   322,   323,   324,   325,   326,   327,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   355,   356,   357,    -1,    -1,    -1,
      -1,    -1,    -1,     9,    10,    11,    -1,    13,   369,   370,
     371,   372,    -1,   374,   375,    -1,   377,   378,   379,   380,
     381,   382,   383,    -1,   385,   386,   387,   388,    34,    35,
      -1,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    54,    55,
      56,    -1,    58,    -1,    60,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,    -1,   131,    -1,   133,   134,   135,
     136,   137,   138,   139,   140,    -1,    -1,    -1,   144,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,    -1,    -1,    -1,   162,   163,    -1,    -1,
      -1,    -1,    -1,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,    -1,    -1,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,    -1,    -1,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,   235,
     236,   237,    -1,    -1,   240,   241,   242,   243,   244,   245,
     246,   247,   248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   272,   273,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,    -1,   300,    -1,   302,   303,    -1,    -1,
      -1,    -1,    -1,    -1,   310,   311,   312,   313,   314,   315,
     316,   317,    -1,    -1,   320,   321,   322,   323,   324,   325,
     326,   327,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   355,
     356,   357,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   369,   370,   371,   372,    -1,   374,   375,
      -1,   377,   378,   379,   380,   381,   382,   383,    -1,   385,
     386,   387,   388,     9,    10,    11,    -1,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      -1,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    54,    55,
      56,    -1,    58,    -1,    60,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    -1,    78,    -1,    80,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,    -1,   131,    -1,   133,   134,   135,
     136,   137,   138,   139,   140,    -1,    -1,    -1,   144,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,    -1,    -1,    -1,   162,   163,    -1,    -1,
      -1,    -1,    -1,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,    -1,    -1,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,    -1,    -1,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,   235,
     236,   237,    -1,    -1,   240,   241,   242,   243,   244,   245,
     246,   247,   248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   272,   273,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,    -1,   300,    -1,   302,   303,    -1,    -1,
      -1,    -1,    -1,    -1,   310,   311,   312,   313,   314,   315,
     316,   317,    -1,    -1,   320,   321,   322,   323,   324,   325,
     326,   327,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   355,
     356,   357,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   369,   370,   371,   372,    -1,   374,   375,
      -1,   377,   378,   379,   380,   381,   382,   383,    -1,   385,
     386,   387,   388,     9,    10,    11,    -1,    13,    -1,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      -1,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    54,    55,
      56,    -1,    58,    -1,    60,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    -1,    78,    -1,    80,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,    -1,   131,    -1,   133,   134,   135,
     136,   137,   138,   139,   140,    -1,    -1,    -1,   144,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,    -1,    -1,    -1,   162,   163,    -1,    -1,
      -1,    -1,    -1,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,    -1,    -1,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,    -1,    -1,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,   235,
     236,   237,    -1,    -1,   240,   241,   242,   243,   244,   245,
     246,   247,   248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   272,   273,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,    -1,   300,    -1,   302,   303,    -1,    -1,
      -1,    -1,    -1,    -1,   310,   311,   312,   313,   314,   315,
     316,   317,    -1,    -1,   320,   321,   322,   323,   324,   325,
     326,   327,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   355,
     356,   357,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   369,   370,   371,   372,    -1,   374,   375,
      -1,   377,   378,   379,   380,   381,   382,   383,    -1,   385,
     386,   387,   388,     9,    10,    11,    -1,    13,    -1,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      -1,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    54,    55,
      56,    -1,    58,    -1,    60,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    -1,    78,    -1,    80,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,    -1,   131,    -1,   133,   134,   135,
     136,   137,   138,   139,   140,    -1,    -1,    -1,   144,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,    -1,    -1,    -1,   162,   163,    -1,    -1,
      -1,    -1,    -1,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,    -1,    -1,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,    -1,    -1,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,   235,
     236,   237,    -1,    -1,   240,   241,   242,   243,   244,   245,
     246,   247,   248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   272,   273,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,    -1,   300,    -1,   302,   303,    -1,    -1,
      -1,    -1,    -1,    -1,   310,   311,   312,   313,   314,   315,
     316,   317,    -1,    -1,   320,   321,   322,   323,   324,   325,
     326,   327,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   355,
     356,   357,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   369,   370,   371,   372,    -1,   374,   375,
      -1,   377,   378,   379,   380,   381,   382,   383,    -1,   385,
     386,   387,   388,     9,    10,    11,    -1,    13,    -1,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      -1,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    54,    55,
      56,    -1,    58,    -1,    60,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    -1,    78,    -1,    80,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,    -1,   131,    -1,   133,   134,   135,
     136,   137,   138,   139,   140,    -1,    -1,    -1,   144,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,    -1,    -1,    -1,   162,   163,    -1,    -1,
      -1,    -1,    -1,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,    -1,    -1,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,    -1,    -1,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,   235,
     236,   237,    -1,    -1,   240,   241,   242,   243,   244,   245,
     246,   247,   248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   272,   273,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,    -1,   300,    -1,   302,   303,    -1,    -1,
      -1,    -1,    -1,    -1,   310,   311,   312,   313,   314,   315,
     316,   317,    -1,    -1,   320,   321,   322,   323,   324,   325,
     326,   327,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   355,
     356,   357,    -1,    -1,    -1,    -1,    -1,    -1,     9,    10,
      11,    -1,    13,   369,   370,   371,   372,    -1,   374,   375,
      -1,   377,   378,   379,   380,   381,   382,   383,    -1,   385,
     386,   387,   388,    34,    35,    -1,    -1,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      -1,    -1,    -1,    54,    55,    56,    -1,    58,    -1,    60,
      61,    62,    63,    64,    -1,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    -1,    78,    -1,    80,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,    -1,
     131,    -1,   133,   134,   135,   136,   137,   138,   139,   140,
      -1,    -1,    -1,   144,    -1,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,    -1,    -1,
      -1,   162,   163,    -1,    -1,    -1,    -1,    -1,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,    -1,
      -1,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,    -1,    -1,    -1,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,   235,   236,   237,    -1,    -1,   240,
     241,   242,   243,   244,   245,   246,   247,   248,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   272,   273,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,    -1,   300,
      -1,   302,   303,    -1,    -1,    -1,    -1,    -1,    -1,   310,
     311,   312,   313,   314,   315,   316,   317,    -1,    -1,   320,
     321,   322,   323,   324,   325,   326,   327,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   355,   356,   357,    -1,    -1,    -1,
      -1,    -1,    -1,     9,    10,    11,    -1,    13,   369,   370,
     371,   372,    -1,   374,   375,    -1,   377,   378,   379,   380,
     381,   382,   383,    -1,   385,   386,   387,   388,    34,    35,
      -1,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    54,    55,
      56,    -1,    58,    -1,    60,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    -1,    78,    -1,    80,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,    -1,   131,    -1,   133,   134,   135,
     136,   137,   138,   139,   140,    -1,    -1,    -1,   144,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,    -1,    -1,    -1,   162,   163,    -1,    -1,
      -1,    -1,    -1,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,    -1,    -1,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,    -1,    -1,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,   235,
     236,   237,    -1,    -1,   240,   241,   242,   243,   244,   245,
     246,   247,   248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   272,   273,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,    -1,   300,    -1,   302,   303,    -1,    -1,
      -1,    -1,    -1,    -1,   310,   311,   312,   313,   314,   315,
     316,   317,    -1,    -1,   320,   321,   322,   323,   324,   325,
     326,   327,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   355,
     356,   357,    -1,    -1,    -1,    -1,    -1,    -1,     9,    10,
      11,    -1,    13,   369,   370,   371,   372,    -1,   374,   375,
      -1,   377,   378,   379,   380,   381,   382,   383,    -1,   385,
     386,   387,   388,    34,    35,    -1,    -1,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      -1,    -1,    -1,    54,    55,    56,    -1,    58,    -1,    60,
      61,    62,    63,    64,    -1,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    -1,    78,    -1,    80,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,    -1,
     131,    -1,   133,   134,   135,   136,   137,   138,   139,   140,
      -1,    -1,    -1,   144,    -1,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,    -1,    -1,
      -1,   162,   163,    -1,    -1,    -1,    -1,    -1,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,    -1,
      -1,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,    -1,    -1,    -1,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,   235,   236,   237,    -1,    -1,   240,
     241,   242,   243,   244,   245,   246,   247,   248,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   272,   273,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,    -1,   300,
      -1,   302,   303,    -1,    -1,    -1,    -1,    -1,    -1,   310,
     311,   312,   313,   314,   315,   316,   317,    -1,    -1,   320,
     321,   322,   323,   324,   325,   326,   327,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   355,   356,   357,    -1,    -1,    -1,
      -1,    -1,    -1,     9,    10,    11,    -1,    13,   369,   370,
     371,   372,    -1,   374,   375,    -1,   377,   378,   379,   380,
     381,   382,   383,    -1,   385,   386,   387,   388,    34,    35,
      -1,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    54,    55,
      56,    -1,    58,    -1,    60,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    -1,    78,    -1,    80,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,    -1,   131,    -1,   133,   134,   135,
     136,   137,   138,   139,   140,    -1,    -1,    -1,   144,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,    -1,    -1,    -1,   162,   163,    -1,    -1,
      -1,    -1,    -1,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,    -1,    -1,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,    -1,    -1,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,   235,
     236,   237,    -1,    -1,   240,   241,   242,   243,   244,   245,
     246,   247,   248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   272,   273,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,    -1,   300,    -1,   302,   303,    -1,    -1,
      -1,    -1,    -1,    -1,   310,   311,   312,   313,   314,   315,
     316,   317,    -1,    -1,   320,   321,   322,   323,   324,   325,
     326,   327,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   355,
     356,   357,    -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,
      -1,    -1,    13,   369,   370,   371,   372,    -1,   374,   375,
      -1,   377,   378,   379,   380,   381,   382,   383,    -1,   385,
     386,   387,   388,    34,    35,    -1,    -1,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      -1,    -1,    -1,    54,    55,    56,    -1,    58,    -1,    60,
      61,    62,    63,    64,    -1,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    -1,    78,    -1,    80,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,    -1,
     131,    -1,   133,   134,   135,   136,   137,   138,   139,   140,
      -1,    -1,    -1,   144,    -1,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,    -1,    -1,
      -1,   162,   163,    -1,    -1,    -1,    -1,    -1,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,    -1,
      -1,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,    -1,    -1,    -1,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,   235,   236,   237,    -1,    -1,   240,
     241,   242,   243,   244,   245,   246,   247,   248,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   272,   273,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,    -1,   300,
      -1,   302,   303,    -1,    -1,    -1,    -1,    -1,    -1,   310,
     311,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   355,   356,   357,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,   369,   370,
     371,   372,    -1,   374,   375,    -1,   377,   378,   379,   380,
     381,   382,   383,    -1,   385,   386,   387,   388,    34,    35,
      -1,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    54,    55,
      56,    -1,    58,    -1,    60,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    -1,    78,    -1,    80,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,    -1,   131,    -1,   133,   134,   135,
     136,   137,   138,   139,   140,    -1,    -1,    -1,   144,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,    -1,    -1,    -1,   162,   163,    -1,    -1,
      -1,    -1,    -1,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,    -1,    -1,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,    -1,    -1,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,   235,
     236,   237,    -1,    -1,   240,   241,   242,   243,   244,   245,
     246,   247,   248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   272,   273,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,    -1,   300,    -1,   302,   303,    -1,    -1,
      -1,    -1,    -1,    -1,   310,   311,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   355,
     356,   357,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   369,   370,   371,   372,    -1,   374,   375,
      -1,   377,   378,   379,   380,   381,   382,   383,    -1,   385,
     386,   387,   388
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
      63,    64,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    86,    87,    88,    89,    90,    91,   105,   106,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   162,
     163,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   272,   273,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   300,   301,   302,   303,   304,   310,
     311,   312,   313,   314,   315,   316,   317,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   333,   335,   336,   337,
     341,   342,   355,   356,   357,   358,   366,   367,   369,   370,
     371,   372,   374,   375,   377,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   400,   401,   402,   403,   404,   405,
     408,   409,   410,   411,   415,   419,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   447,
     448,   449,   450,   451,   452,   453,   454,    13,    69,    71,
      78,    80,    81,   149,   150,   424,   429,   452,   430,   430,
     423,   445,   420,   445,   420,   420,    13,    13,    13,    13,
     422,   445,    78,   340,   424,    56,    72,    73,    74,    75,
     450,   424,   445,   445,   422,    13,   422,    13,    13,    19,
      96,    97,    13,    19,    19,   116,   450,    19,   164,    19,
      15,    95,    15,    61,    62,    63,    64,    66,    67,    69,
      70,    71,    77,    78,    79,    80,    81,   424,   448,   452,
     454,   455,   456,   422,    13,    13,    13,   430,   430,    13,
      13,    15,    13,    13,    15,    13,    15,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    19,    19,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    15,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,   422,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,   430,
     430,   430,   430,   430,   430,   430,   430,   430,   430,   430,
     430,   430,   430,   450,   416,   417,    80,   456,   420,   402,
     422,   422,    13,    13,    13,    13,    76,   450,   450,    13,
      13,    13,    13,    13,    19,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,     0,     0,   402,   403,   404,   405,   408,   409,
     410,   411,   402,    19,    13,    19,   105,   106,   114,    15,
       7,     8,    12,    10,    11,     5,     6,   110,   111,   112,
     113,    17,    18,   108,     4,    21,   109,    95,    96,    97,
      98,    99,   116,    95,   116,    13,    19,    19,    15,    15,
      19,    19,    13,    19,    14,    14,   422,   420,   422,   423,
     422,   456,   456,   249,   250,   251,   253,   254,   255,   258,
     261,   262,   263,   264,   265,   266,   267,   268,   270,   274,
     277,   278,   280,   282,   283,    78,    78,   420,   275,    46,
      47,   306,   307,   308,   309,   305,   450,    46,   165,   420,
     248,   420,    15,   456,   420,   420,   421,   445,   421,   445,
     421,   421,   421,   421,   421,   421,   424,   421,   421,   424,
     424,   424,   424,   424,   421,   424,   424,   424,   424,   424,
     424,   424,   424,   424,   421,   421,   424,   159,   160,   161,
     159,   160,   161,   424,   424,   424,   424,   424,   424,   424,
     424,   424,   424,   421,   424,   424,   424,   424,   424,   424,
     424,   424,   424,   424,   424,   424,   424,   424,   421,   424,
     421,   421,   421,   421,   421,   421,   424,   424,   424,   424,
     424,   424,   424,   424,   424,    78,    78,   424,   424,   424,
     424,    78,   421,   421,   421,    78,   422,    78,   422,   422,
     424,   424,   424,    56,    56,   424,   424,   424,   424,   424,
     424,   424,   424,   424,   424,   424,   421,   420,   420,   424,
     420,   424,   421,   424,    78,   424,    78,    78,   421,   424,
     424,    14,   420,   445,   424,   424,   424,   424,   422,   421,
     421,   421,   424,   116,   332,    57,   416,   416,   402,   450,
     456,   422,   421,    56,   407,   406,    22,   416,   421,   421,
     424,   421,   421,   376,   421,   421,   421,   421,   421,   421,
     421,   420,   421,   421,   421,   422,   422,    65,   424,   424,
     424,   402,   354,   420,   445,    53,    54,    92,   130,   159,
     164,   165,   166,   167,   168,   197,   198,   199,   275,   276,
     279,   281,   299,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,    22,    65,   420,   424,   429,
     457,   431,   431,   431,   432,   432,   434,   434,   434,   434,
     435,   435,   436,   438,   439,   440,   442,   441,   444,   444,
     444,   444,   444,   444,   248,   421,    17,    38,    41,    69,
      71,    79,   248,   271,   289,   292,   305,   445,   446,   453,
      17,    69,   413,   445,   454,   420,   420,   420,   431,    20,
      14,    14,    20,    20,    14,    14,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    20,    13,   445,   445,    13,    13,    13,   422,    16,
      15,    16,   420,    20,    14,    20,    14,    14,    20,    16,
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
      20,    14,    14,    14,    14,    14,    14,    20,    20,    20,
      14,   420,   412,   422,   418,   339,   402,    14,    14,    14,
      20,    14,    13,    13,   368,   402,    14,    20,    20,    20,
      20,    20,    13,    14,    20,    20,    20,    14,    20,    14,
      20,    20,    20,    20,    20,    20,    14,    14,    14,    20,
      20,    20,    20,    20,    22,    23,    14,    13,    13,    13,
     422,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      20,    22,    19,    16,    16,    22,    15,   445,   454,    15,
      13,    19,    15,    13,    13,    13,    13,    20,   456,    14,
      20,    16,    16,   422,   420,   420,   420,   420,    78,   420,
     420,   420,   420,   420,    78,    69,   446,    69,    58,   420,
     420,   420,   420,   420,   422,    61,    64,   422,   116,   420,
     116,    16,   422,    76,   445,    13,    13,    13,    56,   424,
     420,   420,   420,   420,   420,   420,   420,   424,   420,   420,
     420,   420,   420,   420,   420,   421,   421,   424,   424,   424,
     420,   420,   420,   420,   420,   420,   420,   420,   424,   420,
     424,   424,   424,   424,   424,   424,   424,   424,   420,   421,
      13,   420,   420,   420,   421,   421,   420,   420,   420,   420,
     420,   420,   420,   420,   420,   420,   420,   420,   420,   420,
     420,   420,   420,   424,   420,   422,   424,   424,   424,   424,
     424,   420,   420,   420,   420,   420,   420,   420,   420,   420,
     420,   420,   420,   420,   420,   420,   420,   420,   420,   420,
     420,   420,   422,   420,   420,   329,    20,   416,   416,   420,
     359,   360,   361,   362,   363,   365,   414,   414,    77,   420,
     420,   424,   420,   420,   424,   420,   420,   420,   420,   420,
     421,   420,   420,   421,   421,   420,   422,   424,   424,   420,
     420,   420,   422,   420,   424,   424,   424,   420,   424,   420,
     424,   420,   420,   420,   420,   420,    22,   420,    93,   443,
     420,   420,   422,   269,   420,    79,   420,   420,   422,   422,
      17,   445,   454,    20,    20,    14,    20,    14,    20,    14,
      14,    20,    20,    20,    20,    14,    19,    14,    20,    14,
      20,    20,    20,    14,    14,    20,    14,    14,    14,    20,
     449,    16,   421,    14,    14,    14,   421,   424,   424,    14,
      20,    20,    20,    14,    14,    14,    14,    20,    14,    14,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    14,    14,    20,    20,    20,    20,    20,    20,    14,
      14,    20,    14,   421,    14,    14,    14,    20,    20,    20,
      20,    14,    20,    20,    20,    14,    20,    20,    14,    14,
      14,    14,    14,    20,    20,    20,    20,    20,    14,    14,
      14,    20,    20,    20,    20,    20,    20,    14,    14,    14,
      14,    14,    14,    14,    14,    20,    20,    20,    20,    14,
      20,    14,    14,    14,    14,    14,    20,    14,    20,    20,
      20,   420,   422,   402,   402,    20,    59,    59,    59,    59,
      59,    59,    14,    20,    14,   416,    14,    20,    20,    14,
      20,    20,    14,    20,    20,    20,    14,    14,    20,    20,
      20,    20,    14,    20,    14,    20,    20,    14,    20,    23,
      20,    14,    14,    20,    14,    20,    14,    14,    20,    14,
      20,    14,    14,    14,    20,    20,    20,    14,    20,    20,
      20,    16,    16,    14,    16,    20,    14,    14,    20,   456,
     422,   420,   424,   420,   420,   420,   420,   420,   420,   420,
     424,   420,   421,   420,    56,    14,    14,    14,    20,   423,
     424,    56,   424,   420,   420,   424,   420,   420,   420,   420,
     420,   420,   420,   420,   424,   420,   420,   420,   420,   420,
     420,   420,   420,   420,   420,   420,   420,   420,   424,   424,
     424,   424,   424,   420,    14,   420,   420,   420,   420,   420,
     445,   420,   420,   420,   420,   420,   420,   420,   420,   421,
     421,   420,   424,   424,   420,   420,   420,   420,   420,   420,
     424,   421,   420,   420,   420,   330,   416,   420,   416,   359,
     360,   361,   362,   363,   365,   416,   402,   420,   420,   420,
     420,   420,   420,   420,   421,   420,   420,   421,   420,   424,
     420,   420,   420,   420,   445,   420,   420,   420,   420,   420,
     420,   420,   420,   420,    79,    20,    20,    56,    14,    20,
      14,    20,    14,    20,    20,    20,    20,    14,    14,    14,
      20,    20,    14,   420,    14,    19,    14,    20,    20,    20,
      20,    14,    14,    20,    14,    20,    14,    20,    14,    20,
      20,    20,    20,    14,    20,    20,    20,    20,    20,    20,
      14,    20,    20,    20,    20,    20,    20,    20,    14,    20,
      20,    20,    20,    20,    20,    20,    14,    14,    14,    20,
      14,    20,    20,    14,    20,    20,    20,    20,    20,    20,
      20,    20,    14,    14,    20,    20,    20,    20,    20,    14,
      20,    20,    20,    14,    14,    14,    20,    20,   420,   402,
      20,   402,    59,    59,    59,    59,    59,    59,   402,    20,
      20,    14,    20,    14,    20,    14,    20,    20,    14,    20,
      20,    20,    20,    14,    20,    23,    14,    22,    14,    20,
      20,    20,    20,    20,    20,    20,    22,    22,    20,   422,
     422,    14,   420,   420,   420,   420,   420,   420,   420,   420,
      14,   423,    56,   420,   420,   420,   420,   420,   420,   420,
     420,   420,   420,   420,   420,   420,   420,   420,   420,   457,
     420,   457,   457,   420,   420,   420,   420,   420,   420,   420,
     420,   420,   424,   420,   421,   421,   421,   421,   420,   420,
     420,   420,   420,   420,   420,   420,   424,   424,   420,   420,
     420,   420,   420,   420,   420,   416,   420,   420,   420,   420,
     421,   420,   420,   420,   420,   424,   420,   420,   420,   420,
     420,   420,   420,   420,   420,   420,   420,   420,   420,   420,
      14,    20,    14,    20,    20,    20,    14,    20,    14,    14,
      14,    20,    20,    20,    14,    20,    14,    20,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    20,    20,    20,
      14,    20,    14,    14,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    14,    20,    20,    14,    14,    20,    14,
      20,    20,    14,    14,    20,    20,    14,    20,    20,    14,
      20,    20,    14,    14,    20,    14,    14,    14,    14,    14,
     402,    20,    20,    20,    14,    20,    20,    20,    20,    20,
      20,    20,    14,    14,    20,    20,    14,    14,    14,    14,
      14,    14,    20,    14,   420,   420,   420,   420,   420,   423,
     420,   420,   420,   420,   420,   420,   420,   420,   420,   420,
     420,   420,   420,   420,   457,   457,   457,   457,   420,   420,
     420,   424,   424,   424,   424,   420,   420,   420,   420,   420,
     420,   420,   420,   420,   421,   424,   420,   420,   420,   420,
     421,   420,   420,   420,   420,   424,   420,   420,   420,   420,
      14,    14,    14,    14,    20,    14,    14,    20,    14,    14,
      14,    14,    14,    20,    14,    20,    14,    20,    14,    14,
      20,    14,    14,    14,    14,    20,    14,    14,    14,    14,
      20,    20,    14,    20,    14,    14,    20,    20,    20,    20,
      20,    14,    20,    14,    20,    14,    20,    14,    20,    20,
      20,    20,    20,    20,    20,    22,    14,    22,   420,   420,
     420,   420,   420,   420,   457,   420,   420,   420,   420,   420,
     420,   420,   420,   424,   420,   420,   421,   420,   420,   420,
     420,   424,   420,   420,   420,    20,    20,    14,    14,    14,
      20,    14,    20,    20,    14,    20,    20,    20,    14,    20,
      20,    20,    20,    20,    20,    14,    20,    14,    20,    20,
      20,    20,    14,   420,   420,   420,   420,   420,   420,   420,
     420,   420,   420,   424,   420,   420,   420,   420,   420,   420,
     424,   420,   116,    14,    14,    14,    14,    20,    14,    20,
      14,    20,    20,    20,    14,    20,    20,    20,    14,    14,
      20,    14,    20,    20,    20,    20,   421,   420,   421,   420,
     420,   420,   421,   420,   420,   420,   421,   420,   420,   420,
      20,    14,    14,    20,    14,    14,    14,    20,    14,    20,
      20,    20,    20,   420,   420,   420,   421,   420,   420,   424,
      14,    14,    20,    14,    14,    20,    20,   420,   420,   424,
      20,    20,    20,   420,   420,   420,    20,    20,    14,   420,
     420,    20,    20,   420,   420,    20,    20,   420,   420,    14,
      14
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
     645,   646,   647,   648,   649,   650,   651,   652,   653
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  Parser::yyr1_[] =
  {
         0,   399,   400,   400,   401,   401,   401,   401,   401,   401,
     401,   401,   401,   401,   401,   401,   401,   401,   401,   401,
     402,   402,   403,   403,   403,   403,   403,   404,   404,   406,
     405,   407,   405,   408,   408,   409,   410,   410,   410,   411,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   412,   412,   413,   413,   413,   413,   413,   413,
     413,   414,   414,   414,   414,   414,   414,   414,   414,   414,
     414,   414,   414,   414,   415,   415,   415,   415,   415,   415,
     415,   416,   417,   418,   419,   419,   419,   419,   419,   419,
     419,   419,   419,   419,   419,   419,   419,   419,   419,   419,
     419,   419,   419,   419,   419,   419,   419,   419,   419,   419,
     419,   419,   419,   419,   419,   419,   419,   419,   419,   419,
     419,   419,   419,   419,   419,   419,   419,   419,   419,   419,
     419,   419,   419,   419,   419,   420,   421,   422,   423,   423,
     423,   423,   423,   423,   423,   423,   423,   423,   423,   423,
     424,   424,   425,   425,   425,   425,   425,   425,   425,   425,
     425,   425,   425,   425,   425,   425,   425,   425,   425,   425,
     425,   425,   425,   425,   425,   425,   425,   425,   425,   425,
     425,   425,   425,   425,   425,   425,   425,   425,   425,   425,
     425,   425,   425,   425,   425,   425,   425,   425,   425,   425,
     425,   425,   425,   425,   425,   425,   425,   425,   425,   425,
     425,   425,   425,   425,   425,   425,   425,   425,   425,   425,
     425,   425,   425,   425,   425,   425,   425,   425,   425,   425,
     425,   425,   425,   425,   425,   425,   425,   425,   425,   425,
     425,   425,   425,   425,   425,   425,   425,   425,   425,   425,
     425,   425,   425,   425,   425,   425,   425,   425,   425,   425,
     425,   425,   425,   425,   425,   425,   425,   425,   425,   425,
     425,   425,   425,   425,   425,   425,   425,   425,   426,   427,
     428,   428,   429,   429,   429,   429,   429,   429,   429,   429,
     429,   429,   429,   429,   429,   429,   430,   430,   430,   430,
     430,   430,   430,   431,   431,   431,   431,   431,   431,   431,
     431,   431,   431,   431,   431,   431,   431,   431,   431,   431,
     431,   431,   431,   432,   432,   432,   432,   433,   433,   433,
     434,   435,   435,   435,   435,   435,   436,   436,   436,   437,
     437,   438,   439,   439,   440,   440,   441,   441,   442,   442,
     443,   443,   444,   444,   444,   444,   444,   444,   444,   445,
     446,   446,   446,   446,   447,   447,   447,   448,   448,   448,
     449,   449,   449,   449,   449,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   449,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   449,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   450,   451,   452,   452,   452,   452,
     452,   452,   453,   453,   453,   453,   453,   453,   454,   454,
     455,   455,   455,   455,   455,   455,   455,   455,   455,   455,
     456,   456,   457,   457,   457,   457,   457
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
       4,     3,     5,     3,     6,     6,     6,     3,     6,     3,
       6,     6,     6,     8,     6,     8,     8,     8,     3,     1,
       1,     2,     2,     1,     1,     2,     8,     4,     4,     1,
       2,     2,     2,     8,    16,     2,     6,     2,     2,     5,
       2,     1,     1,     2,     2,     2,     2,     2,     2,     4,
       4,     2,     2,     2,     3,     3,     3,     2,     6,    10,
       6,    10,    10,    12,     6,     6,     3,     3,     3,     3,
       4,     3,     6,     6,     4,    20,    10,     6,     3,     3,
       6,     3,     6,     8,     6,     6,     8,    16,     6,     3,
       6,     8,     3,    12,    12,    12,    10,     3,     3,     8,
       8,    10,     8,    10,    12,     6,     8,    10,    16,    18,
      12,     6,    18,    16,    12,    10,    10,    10,     6,    10,
       6,     6,     6,     8,     4,     4,     8,     4,    18,     4,
       1,     1,     1,     6,     3,     4,     1,     1,     1,    30,
      24,     8,     1,     3,     0,     1,     3,     2,     4,     1,
       3,     0,     2,     2,     2,     2,     2,     2,     4,     4,
       4,     4,     4,     4,     1,     6,     1,     3,     4,     4,
       1,     3,     0,     0,     1,     1,     1,     1,     6,     8,
      10,    10,    10,     8,     6,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     6,     4,    10,
       4,    10,     4,     4,     4,     4,     4,     4,     7,     7,
       7,     9,     7,     6,     4,     0,     6,    10,     4,     4,
       4,     3,     6,     6,     6,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     4,     2,     4,     4,     1,    10,    12,     8,     1,
       6,     6,     6,     8,     8,     6,     8,     8,    10,    10,
      12,    12,    10,     4,    10,     4,     6,     4,     4,     4,
      12,     4,    12,    12,    16,    20,    10,    12,     4,     6,
       6,     6,     4,     4,     6,     4,     6,     6,     6,    16,
      10,     8,    12,    10,     8,    12,     8,    12,     8,    12,
      12,    14,    12,    12,    16,     4,     8,    10,    12,    10,
      12,    10,    12,    12,    14,    12,     8,    14,     4,     4,
       4,     4,     3,     3,     6,     6,     6,     6,     8,    14,
      12,    14,    12,     6,     8,    10,    10,    12,     6,     6,
       6,     6,     6,     6,     6,     6,     8,    10,     4,     4,
      10,    10,     4,     6,     6,    12,    30,     8,     6,     4,
       6,     4,     6,     4,     4,    18,     8,     6,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     6,     4,     3,     1,     2,     2,     2,
       2,     4,     4,     1,     4,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     3,     3,     3,     1,     3,     3,
       1,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     5,     1,     3,     3,     3,     3,     3,     3,     1,
       1,     3,     8,     4,     6,     1,     4,     1,     4,     1,
       6,     6,     8,     8,     4,     6,     6,     6,     6,     3,
       2,     4,     6,     4,     4,    10,     6,    16,    18,    10,
      20,    14,     4,     6,     8,     8,    12,    16,    16,    18,
      14,    14,    16,    20,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
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
  "ABLOCK", "NUMBER", "IDENTIFIER", "VAR_IMAGE", "VAR_FLOAT", "VAR_INT",
  "VAR_UCHAR", "VAR_STRING", "VAR_IMAGEDRAW", "VAR_LONG", "VAR_DOUBLE",
  "VAR_SURFACE", "VAR_SURFDRAW", "VAR_MATRIX", "VAR_FILE",
  "VAR_C_FUNCTION", "VAR_C_PROCEDURE", "VAR_CLASS_MEMBER",
  "VAR_C_IMAGE_FUNCTION", "VAR_AMI_FUNCTION", "VAR_AMI_CLASS",
  "VAR_AMI_OBJECT", "VAR_GLTRANSFORM", "VAR_ARRAY_SURFACE",
  "VAR_ARRAY_IMAGE", "T_del", "T_delvars", "T_Comments", "ENDOP",
  "T_global", "T_local", "T_global_new", "T_local_new", "T_wait",
  "T_schedule", "T_SetComponent", "T_GetExtent", "RIGHT_ASSIGN",
  "LEFT_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "RIGHT_OP",
  "INC_OP", "DEC_OP", "PTR_OP", "AND_OP", "OR_OP", "LE_OP", "GE_OP",
  "EQ_OP", "NE_OP", "TRANSPOSE_OP", "POINTWISE_MULT", "ASSIGN_OP",
  "T_COUNT", "T_MAX", "T_argmax", "T_MIN", "T_MEDIAN", "OpImage", "FILTER",
  "NormGrad", "T_DiscNormGrad", "T_gradient", "SecDerGrad", "SecDerGrad2",
  "SubImage", "PutImage", "T_AutoCrop", "T_DiscSecDerGrad", "T_EDPdilate",
  "T_EDPerode", "T_EDPopen", "T_EDPclose", "AnisoSmoothGS", "T_vtkAnisoGS",
  "T_DiscMeanCurvature", "T_vtkMedian3D", "T_NULL", "T_RestartTime",
  "T_InitTime", "T_TimeSpent", "T_EndTime", "T_vtkFastMarching",
  "T_vtkFastMarchingTarget", "T_FluxDiffusion", "T_AnisoWeickert",
  "T_AnisoCW", "T_SRAD_qcoeff", "T_AnisoSRAD", "T_AnisoSRAD2",
  "T_AnisoLeeAdd2", "T_AnisoDPAD", "T_AnisoDPAD2", "T_AnisoNRAD",
  "T_AnisoRudinMult", "TInit", "TIterate", "TEnd", "TAddGaussNoise",
  "T_SNR", "T_info", "T_save", "T_normalize", "T_OrientField",
  "T_OrientPositive", "T_2DFlux", "T_OutFlux", "T_OutFluxScalar",
  "T_OrientationRatio", "T_Skeleton", "T_SimplePoints", "T_CircleIntegral",
  "T_CircleIntegralExc", "T_CircleIntSdExc", "T_CircleMinIntSdExc",
  "T_LocalExtrema", "T_NormalField", "T_DirConnectivity", "T_eccentricity",
  "T_rot2D", "T_mean", "T_SUM", "T_localmean", "T_localmean2", "T_localSD",
  "T_localSD2", "T_struct_tensor", "T_StructTensorH", "T_HessianMatrix",
  "T_HessianEVal", "T_Derivatives", "T_curvatures", "T_Laplacian",
  "T_setvoxelsize", "T_settranslation", "T_setendianness",
  "T_Skeleton2lines", "T_SmoothLines", "T_ResampleLines", "T_threscross",
  "T_IsocontourPoints", "T_IsosurfDist", "T_vtkIsoContourDist",
  "T_ShortestPath", "T_ShortestPathImage", "T_PathFromDispl",
  "T_PathFromVectField", "T_LineRecons", "T_ReadCTALine",
  "T_ReadCTALineRadii", "T_vtkDicomRead", "T_vtkMINCRead", "T_Convolve",
  "T_ConvolveMask", "T_Pad", "T_Eigen2D", "T_Eigen3D", "T_ChamferDT",
  "T_Chamfer2DT", "T_BorgeforsDT", "T_BorgeforsSDT",
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
  "T_import_filters", "T_amiOFCorr2D", "T_amiOFVar2D", "prefix", "postfix",
  "$accept", "start", "list_commands", "end_instr", "loop_inst",
  "cond_inst", "proc_decl", "$@1", "$@2", "class_decl", "object_decl",
  "func_inst", "command", "exprstringlist", "param_list",
  "param_list_decl", "primary_expr_string", "instr_block", "begin_block",
  "end_block", "float_variable", "expr", "expr_image", "expr_string",
  "basic_type", "var_image", "image", "image_variable", "surface_variable",
  "string_variable", "primary_var", "postfix_var", "prefix_var",
  "multiplicative_var", "additive_var", "shift_var", "relational_var",
  "equality_var", "and_var", "exclusive_or_var", "inclusive_or_var",
  "logical_and_var", "logical_xor_var", "logical_or_var",
  "conditional_var", "assignment_var", "expr_var", "gltransform",
  "matrix_variable", "var_surface", "surface", "identifier",
  "variable_with_assign", "function_variable", "variable_without_assign",
  "unprocessed_variable", "processed_variable", "variable", "image_extent", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Parser::rhs_number_type
  Parser::yyrhs_[] =
  {
       400,     0,    -1,    -1,   401,     0,    -1,   402,    -1,   401,
     402,    -1,   411,   402,    -1,   401,   411,   402,    -1,   403,
      -1,   401,   403,    -1,   404,    -1,   401,   404,    -1,   410,
      -1,   401,   410,    -1,   405,    -1,   401,   405,    -1,   408,
      -1,   401,   408,    -1,   409,    -1,   401,   409,    -1,    37,
      -1,    23,    -1,   328,   450,   116,   420,   329,   420,   416,
     402,    -1,   328,   450,   116,   420,   329,   420,   330,   420,
     416,   402,    -1,   328,   450,   332,   412,   416,   402,    -1,
     333,   416,    -1,   335,   456,   416,    -1,   337,   420,   416,
     402,    -1,   337,   420,   416,   339,   416,   402,    -1,    -1,
     366,   450,   406,    13,   414,    14,   416,   402,    -1,    -1,
     366,    76,   407,    13,   414,    14,   416,   402,    -1,   367,
     450,   416,   402,    -1,   367,   450,    22,   368,    77,   416,
     402,    -1,    77,   450,    -1,   341,   422,   402,    -1,   341,
     402,    -1,   342,   422,    -1,   454,    -1,   445,    -1,    36,
      -1,   336,    -1,    86,    -1,    88,    -1,    89,    -1,    87,
      -1,    90,    13,   420,    14,    -1,    91,    13,   420,    20,
      76,    14,    -1,   450,   116,    17,   454,    -1,   450,   116,
      17,   445,    -1,   450,   116,   445,    -1,   450,   116,   445,
      20,   422,    -1,   450,   116,   453,    -1,   450,   116,   248,
      15,   420,    16,    -1,   450,    95,   248,    15,   420,    16,
      -1,   450,   116,    38,    15,   420,    16,    -1,   450,    95,
     421,    -1,    81,    15,   420,    16,   116,   421,    -1,   450,
     116,   446,    -1,    80,    15,   420,    16,   116,   449,    -1,
      80,    95,   248,    15,   420,    16,    -1,   450,   116,   292,
      13,   420,    14,    -1,   450,   116,   292,    13,   420,    14,
      20,   422,    -1,   450,   116,   289,    13,   420,    14,    -1,
     450,   116,   289,    13,   420,    14,    20,   422,    -1,   450,
     116,   305,    13,   422,    20,    56,    14,    -1,    71,   116,
     305,    13,   422,    20,    56,    14,    -1,    71,    19,   309,
      -1,    24,    -1,    25,    -1,    26,   420,    -1,    27,   420,
      -1,    29,    -1,    30,    -1,    28,   420,    -1,    31,    13,
     422,    20,   422,    20,   422,    14,    -1,    32,    13,   420,
      14,    -1,    33,    13,   422,    14,    -1,    44,    -1,    42,
     424,    -1,    45,   424,    -1,    42,    78,    -1,   424,    19,
      92,    13,   420,    20,   445,    14,    -1,   424,    13,   420,
      22,   420,    20,   420,    22,   420,    20,   420,    22,   420,
      14,   116,   421,    -1,    42,   340,    -1,    84,    13,   456,
      20,   422,    14,    -1,    82,   456,    -1,    83,   422,    -1,
      82,    80,    15,   420,    16,    -1,    51,   422,    -1,    52,
      -1,    43,    -1,    43,   450,    -1,    43,    75,    -1,    43,
      72,    -1,    43,    73,    -1,    43,    74,    -1,    43,    56,
      -1,    71,    19,    46,   445,    -1,    71,    19,    47,   445,
      -1,    46,   445,    -1,    47,   445,    -1,    48,   422,    -1,
      71,    19,   306,    -1,   424,    19,   159,    -1,   424,    19,
     164,    -1,    78,   164,    -1,   424,    19,   281,    13,   420,
      14,    -1,   424,    19,   281,    13,   420,    20,   420,    20,
     420,    14,    -1,   424,    19,   275,    13,   420,    14,    -1,
     424,    19,   275,    13,   420,    20,   420,    20,   420,    14,
      -1,   424,    19,   276,    13,   420,    20,   420,    20,   420,
      14,    -1,   424,    19,   130,    13,   424,    20,   420,    20,
     420,    20,   420,    14,    -1,   424,    19,   130,    13,   424,
      14,    -1,   424,    19,    53,    13,   422,    14,    -1,   149,
      19,   160,    -1,   149,    19,   161,    -1,   150,    19,   160,
      -1,   150,    19,   161,    -1,   424,    19,   165,   422,    -1,
     424,    19,   166,    -1,   424,    19,   167,    13,   424,    14,
      -1,   424,    19,   168,    13,   424,    14,    -1,   389,    13,
     422,    14,    -1,   390,    13,    65,    20,   420,    20,   420,
      20,   420,    20,   420,    20,   420,    20,   420,    20,   420,
      20,   420,    14,    -1,    69,    19,   251,    13,   420,    20,
     420,    20,   420,    14,    -1,    69,    19,   254,    13,    78,
      14,    -1,    69,    96,    78,    -1,    69,    97,    78,    -1,
      69,    19,   267,    13,    78,    14,    -1,    69,    19,   268,
      -1,    69,    19,   253,    13,   420,    14,    -1,    69,    19,
     253,    13,   420,    20,   420,    14,    -1,    69,    19,   255,
      13,   420,    14,    -1,    69,    19,   277,    13,    69,    14,
      -1,    69,    19,   278,    13,    58,    20,   424,    14,    -1,
      69,    19,   282,    13,   420,    20,   421,    20,   420,    20,
     420,    20,   420,    20,   420,    14,    -1,    69,    19,   283,
      13,   420,    14,    -1,    69,    19,   274,    -1,    69,    19,
     270,    13,   446,    14,    -1,    69,    19,   270,    13,   446,
      20,   420,    14,    -1,    69,    19,   258,    -1,    69,    19,
     261,    13,   420,    20,   420,    20,   420,    20,   420,    14,
      -1,    69,    19,   262,    13,   420,    20,   420,    20,   420,
      20,   420,    14,    -1,    69,    19,   263,    13,   420,    20,
     420,    20,   420,    20,   420,    14,    -1,    69,    19,   264,
      13,   420,    20,   420,    20,   420,    14,    -1,    69,    19,
     265,    -1,    69,    19,   266,    -1,    69,    19,   280,    13,
     420,    20,   420,    14,    -1,   190,    13,   424,    20,   420,
      20,   420,    14,    -1,   190,    13,   424,    20,   420,    20,
     420,    20,   421,    14,    -1,   191,    13,   424,    20,   420,
      20,   420,    14,    -1,   191,    13,   424,    20,   420,    20,
     420,    20,   421,    14,    -1,   191,    13,   424,    20,   420,
      20,   420,    20,   421,    20,   420,    14,    -1,   192,    13,
     424,    20,   420,    14,    -1,   192,    13,   424,    20,   420,
      20,   445,    14,    -1,   192,    13,   424,    20,   420,    20,
     420,    20,   421,    14,    -1,   194,    13,   424,    20,   420,
      20,   420,    20,   420,    20,   420,    20,   420,    20,   420,
      14,    -1,   194,    13,   424,    20,   420,    20,   420,    20,
     420,    20,   420,    20,   420,    20,   420,    20,   421,    14,
      -1,   193,    13,   424,    20,   420,    20,   420,    20,   421,
      20,   420,    14,    -1,   195,    13,   424,    20,   420,    14,
      -1,   220,    13,    56,    20,   424,    20,   424,    20,   424,
      20,   424,    20,   424,    20,   424,    20,   421,    14,    -1,
     220,    13,    56,    20,   424,    20,   424,    20,   424,    20,
     424,    20,   424,    20,   424,    14,    -1,   219,    13,    56,
      20,   424,    20,   424,    20,   424,    20,   421,    14,    -1,
     219,    13,    56,    20,   424,    20,   424,    20,   424,    14,
      -1,   197,    13,   424,    20,   420,    20,   420,    20,   420,
      14,    -1,   424,    19,   197,    13,   420,    20,   420,    20,
     420,    14,    -1,   424,    19,   197,    13,   424,    14,    -1,
     424,    19,   198,    13,   420,    20,   420,    20,   420,    14,
      -1,   424,    19,   198,    13,   424,    14,    -1,   424,    19,
     199,    13,   420,    14,    -1,   132,    13,   424,    20,   424,
      14,    -1,   132,    13,   424,    20,   424,    20,   424,    14,
      -1,   233,    13,   420,    14,    -1,   234,    13,   420,    14,
      -1,   301,    13,   421,    20,   422,    20,   420,    14,    -1,
     304,    13,   424,    14,    -1,   218,    13,   424,    20,   424,
      20,   420,    20,   420,    20,   420,    20,   420,    20,   420,
      20,   420,    14,    -1,   358,    13,    56,    14,    -1,   142,
      -1,   143,    -1,   145,    -1,   391,    13,   424,    20,   422,
      14,    -1,    79,    19,    46,    -1,    79,    19,   165,   422,
      -1,   392,    -1,   393,    -1,   394,    -1,   395,    13,   424,
      20,   424,    20,   424,    20,   424,    20,   424,    20,   424,
      20,   424,    20,   420,    20,   420,    20,   420,    20,   420,
      20,   420,    20,   420,    20,   420,    14,    -1,   396,    13,
     424,    20,   424,    20,   420,    20,   420,    20,   420,    20,
     420,    20,   420,    20,   420,    20,   424,    20,   424,    20,
     420,    14,    -1,   384,    13,   420,    20,   420,    20,   420,
      14,    -1,   422,    -1,   412,    20,   422,    -1,    -1,   454,
      -1,   413,    20,   454,    -1,    17,   456,    -1,   413,    20,
      17,   456,    -1,   445,    -1,   413,    20,   445,    -1,    -1,
     362,    59,    -1,   365,    59,    -1,   363,    59,    -1,   359,
      59,    -1,   360,    59,    -1,   361,    59,    -1,   414,    20,
     365,    59,    -1,   414,    20,   362,    59,    -1,   414,    20,
     363,    59,    -1,   414,    20,   359,    59,    -1,   414,    20,
     360,    59,    -1,   414,    20,   361,    59,    -1,    56,    -1,
      50,    13,   422,    20,   420,    14,    -1,   144,    -1,   424,
      19,    54,    -1,    54,    13,   456,    14,    -1,    55,    13,
     456,    14,    -1,    34,    -1,   417,    57,   418,    -1,    -1,
      -1,    58,    -1,    35,    -1,   310,    -1,   311,    -1,   424,
      13,   420,    20,   420,    14,    -1,   424,    13,   420,    20,
     420,    20,   420,    14,    -1,   424,    19,   279,    13,   420,
      20,   420,    20,   420,    14,    -1,   424,    13,   420,    20,
     420,    20,   420,    20,   420,    14,    -1,   424,    13,   420,
      20,   420,    20,   420,    23,   420,    14,    -1,   424,    13,
     420,    20,   420,    23,   420,    14,    -1,   424,    13,   420,
      23,   420,    14,    -1,   424,    19,   343,    -1,   424,    19,
     344,    -1,   424,    19,   345,    -1,   424,    19,   346,    -1,
     424,    19,   347,    -1,   424,    19,   348,    -1,   424,    19,
     349,    -1,   424,    19,   350,    -1,   424,    19,   351,    -1,
     424,    19,   352,    -1,   424,    19,   353,    -1,   424,    19,
     354,    -1,   163,    13,   424,    20,   424,    14,    -1,   182,
      13,   424,    14,    -1,   235,    13,   424,    20,   420,    20,
     420,    20,   420,    14,    -1,   236,    13,   424,    14,    -1,
     236,    13,   420,    20,   420,    20,   420,    20,   420,    14,
      -1,   117,    13,   421,    14,    -1,   184,    13,   421,    14,
      -1,   118,    13,   421,    14,    -1,   119,    13,   421,    14,
      -1,   120,    13,   421,    14,    -1,   121,    13,   421,    14,
      -1,   118,    15,   421,    16,    13,   421,    14,    -1,   120,
      15,   421,    16,    13,   424,    14,    -1,   121,    15,   421,
      16,    13,   424,    14,    -1,   121,    15,   421,    16,    13,
     424,    20,   420,    14,    -1,   184,    15,   421,    16,    13,
     421,    14,    -1,   184,    13,   424,    20,   421,    14,    -1,
     300,    13,   422,    14,    -1,    -1,    70,    13,   420,    20,
     420,    14,    -1,    70,    19,   275,    13,   420,    20,   420,
      20,   420,    14,    -1,   355,    13,   450,    14,    -1,   355,
      13,   456,    14,    -1,   356,    13,   422,    14,    -1,   423,
      19,   354,    -1,    71,    19,   307,    13,   422,    14,    -1,
      71,    19,   308,    13,    61,    14,    -1,    71,    19,   308,
      13,    64,    14,    -1,   445,    -1,   445,    -1,   445,    -1,
     288,    -1,   289,    -1,   290,    -1,   291,    -1,   292,    -1,
     293,    -1,   294,    -1,   295,    -1,   296,    -1,   297,    -1,
     298,    -1,   424,    19,   299,    -1,    60,    -1,    81,    15,
     420,    16,    -1,    38,   422,    -1,   214,    13,   422,    14,
      -1,   215,    13,   422,    14,    -1,    39,    -1,    38,    13,
     423,    20,   420,    20,   420,    20,   420,    14,    -1,    38,
      13,   423,    20,   420,    20,   420,    20,   420,    20,   420,
      14,    -1,    38,    13,   423,    20,   420,    20,   424,    14,
      -1,   424,    -1,   185,    13,   421,    20,   420,    14,    -1,
     186,    13,   421,    20,   420,    14,    -1,   187,    13,   421,
      20,   420,    14,    -1,   188,    13,   421,    20,   421,    20,
     420,    14,    -1,   189,    13,   421,    20,   421,    20,   420,
      14,    -1,   122,    13,   424,    20,    56,    14,    -1,   122,
      13,   424,    20,    56,    20,   423,    14,    -1,   122,    13,
     424,    20,   424,    20,    56,    14,    -1,   122,    13,   424,
      20,   424,    20,    56,    20,   423,    14,    -1,   122,    13,
     424,    20,   424,    20,   424,    20,    56,    14,    -1,   122,
      13,   424,    20,   424,    20,   424,    20,    56,    20,   423,
      14,    -1,   123,    13,   421,    20,   420,    20,   420,    20,
     420,    20,   420,    14,    -1,   375,    19,   376,    13,   424,
      20,   420,    20,   420,    14,    -1,   246,    13,   424,    14,
      -1,   140,    13,   424,    20,   420,    20,   420,    20,   420,
      14,    -1,   247,    13,   424,    14,    -1,   169,    13,   421,
      20,   420,    14,    -1,   170,    13,   424,    14,    -1,   171,
      13,   424,    14,    -1,   172,    13,   424,    14,    -1,   173,
      13,   424,    20,   424,    20,   420,    20,   420,    20,   420,
      14,    -1,   174,    13,   424,    14,    -1,   175,    13,   424,
      20,   424,    20,   424,    20,   420,    20,   424,    14,    -1,
     176,    13,   424,    20,   424,    20,   424,    20,   420,    20,
     424,    14,    -1,   177,    13,   424,    20,   424,    20,   424,
      20,   420,    20,   424,    20,   420,    20,   420,    14,    -1,
     178,    13,   424,    20,   424,    20,   424,    20,   420,    20,
     424,    20,   420,    20,   420,    20,   420,    20,   420,    14,
      -1,   179,    13,   424,    20,   424,    20,   424,    20,   424,
      14,    -1,   179,    13,   424,    20,   424,    20,   424,    20,
     424,    20,   420,    14,    -1,   180,    13,   424,    14,    -1,
     180,    13,   424,    20,   424,    14,    -1,   181,    13,   424,
      20,   424,    14,    -1,   124,    13,   421,    20,   420,    14,
      -1,   125,    13,   424,    14,    -1,   139,    13,   424,    14,
      -1,   126,    13,   424,    20,   420,    14,    -1,   196,    13,
     424,    14,    -1,   127,    13,   424,    20,   420,    14,    -1,
     128,    13,   424,    20,   420,    14,    -1,   131,    13,   421,
      20,   420,    14,    -1,   129,    13,   424,    20,   420,    20,
     420,    20,   420,    20,   420,    20,   420,    20,   420,    14,
      -1,   133,    13,   424,    20,   420,    20,   420,    20,   420,
      14,    -1,   133,    13,   424,    20,   420,    20,   420,    14,
      -1,   133,    13,   424,    20,   420,    20,   420,    20,   420,
      20,   420,    14,    -1,   134,    13,   424,    20,   420,    20,
     420,    20,   420,    14,    -1,   134,    13,   424,    20,   420,
      20,   420,    14,    -1,   134,    13,   424,    20,   420,    20,
     420,    20,   420,    20,   420,    14,    -1,   135,    13,   424,
      20,   420,    20,   420,    14,    -1,   135,    13,   424,    20,
     420,    20,   420,    20,   420,    20,   420,    14,    -1,   136,
      13,   424,    20,   420,    20,   420,    14,    -1,   136,    13,
     424,    20,   420,    20,   420,    20,   420,    20,   420,    14,
      -1,   148,    13,   424,    20,   424,    20,   420,    20,   420,
      20,   420,    14,    -1,   138,    13,   424,    20,   420,    20,
     420,    20,   420,    20,   420,    20,   420,    14,    -1,   137,
      13,   424,    20,   420,    20,   420,    20,   420,    20,   420,
      14,    -1,   149,    19,   159,    13,   424,    20,   420,    20,
     420,    20,   420,    14,    -1,   150,    19,   159,    13,   424,
      20,   420,    20,   420,    20,   420,    20,   420,    20,   420,
      14,    -1,   151,    13,   424,    14,    -1,   152,    13,   424,
      20,   420,    20,   420,    14,    -1,   152,    13,   424,    20,
     420,    20,   420,    20,   457,    14,    -1,   152,    13,   424,
      20,   420,    20,   420,    20,   420,    20,   457,    14,    -1,
     153,    13,   424,    20,   420,    20,   420,    20,   457,    14,
      -1,   153,    13,   424,    20,   420,    20,   420,    20,   420,
      20,   457,    14,    -1,   154,    13,   424,    20,   420,    20,
     420,    20,   457,    14,    -1,   155,    13,   424,    20,   420,
      20,   420,    20,   420,    20,   457,    14,    -1,   156,    13,
     424,    20,   420,    20,   420,    20,   420,    20,   457,    14,
      -1,   157,    13,   424,    20,   420,    20,   420,    20,   420,
      20,   420,    20,   457,    14,    -1,   158,    13,   424,    20,
     420,    20,   420,    20,   420,    20,   420,    14,    -1,   162,
      13,   424,    20,   420,    20,   420,    14,    -1,   183,    13,
     424,    20,   420,    20,   420,    20,   420,    20,   420,    20,
     420,    14,    -1,   284,    13,   424,    14,    -1,   285,    13,
     424,    14,    -1,   286,    13,   424,    14,    -1,   287,    13,
     424,    14,    -1,    69,    19,   249,    -1,    69,    19,   250,
      -1,   203,    13,   424,    20,   420,    14,    -1,   204,    13,
     424,    20,   420,    14,    -1,   205,    13,   424,    20,   420,
      14,    -1,   206,    13,   424,    20,   420,    14,    -1,   146,
      13,   421,    20,   421,    20,   420,    14,    -1,   147,    13,
     421,    20,   421,    20,   420,    20,   420,    20,   420,    20,
     420,    14,    -1,   146,    13,   421,    20,   421,    20,   420,
      20,   420,    20,   420,    14,    -1,   146,    13,   421,    20,
     421,    20,   420,    20,   420,    20,   420,    20,   420,    14,
      -1,   146,    13,   421,    20,   421,    20,   424,    20,   420,
      20,   420,    14,    -1,   216,    13,   424,    20,   424,    14,
      -1,   217,    13,   424,    20,   424,    20,   421,    14,    -1,
     221,    13,   424,    20,   420,    20,   420,    20,   420,    14,
      -1,   222,    13,   424,    20,   420,    20,   420,    20,   420,
      14,    -1,   222,    13,   424,    20,   420,    20,   420,    20,
     420,    20,   420,    14,    -1,   223,    13,   424,    20,   420,
      14,    -1,   224,    13,   424,    20,   420,    14,    -1,   225,
      13,   424,    20,   420,    14,    -1,   226,    13,   424,    20,
     420,    14,    -1,   227,    13,   424,    20,   420,    14,    -1,
     228,    13,   424,    20,   420,    14,    -1,   229,    13,   424,
      20,   420,    14,    -1,   230,    13,   424,    20,   420,    14,
      -1,   230,    13,   424,    20,   420,    20,   420,    14,    -1,
     231,    13,   424,    20,   420,    20,   420,    20,   420,    14,
      -1,   232,    13,   421,    14,    -1,   424,    13,   445,    14,
      -1,   302,    13,   421,    20,   420,    20,   420,    20,   420,
      14,    -1,   303,    13,   421,    20,   420,    20,   420,    20,
     420,    14,    -1,   369,    13,   421,    14,    -1,   369,    13,
     421,    20,   420,    14,    -1,   372,    13,   421,    20,   420,
      14,    -1,   370,    13,   421,    20,   420,    20,   420,    20,
     420,    20,   420,    14,    -1,   371,    13,   424,    20,   424,
      20,   420,    20,   420,    20,   420,    20,   420,    20,   420,
      20,   420,    20,   420,    20,   420,    20,   420,    20,   420,
      20,   420,    20,   420,    14,    -1,   374,    13,   421,    20,
     420,    20,   420,    14,    -1,   380,    13,   421,    20,   420,
      14,    -1,   380,    13,   421,    14,    -1,   381,    13,   421,
      20,   420,    14,    -1,   381,    13,   421,    14,    -1,   386,
      13,   421,    20,   421,    14,    -1,   387,    13,   421,    14,
      -1,   388,    13,   422,    14,    -1,   357,    13,   421,    20,
     420,    20,   420,    20,   420,    20,   420,    20,   420,    20,
     420,    20,   420,    14,    -1,   211,    13,    78,    20,   424,
      20,   421,    14,    -1,   213,    13,    78,    20,   422,    14,
      -1,   425,    -1,   448,    -1,    64,    -1,   415,    -1,    78,
      -1,    66,    -1,    62,    -1,    63,    -1,    67,    -1,    61,
      -1,   419,    -1,   426,    -1,   427,    -1,   428,    -1,   447,
      -1,   118,    13,   445,    20,   445,    14,    -1,   452,    13,
     413,    14,    -1,    13,   445,    14,    -1,   429,    -1,     9,
     429,    -1,   429,   105,    -1,   429,   106,    -1,   429,   114,
      -1,   430,    15,   457,    16,    -1,   430,    15,   429,    16,
      -1,   430,    -1,    13,   423,    14,   431,    -1,    11,   430,
      -1,    10,   430,    -1,   105,   430,    -1,   106,   430,    -1,
     312,   430,    -1,   313,   430,    -1,   323,   430,    -1,   324,
     430,    -1,   325,   430,    -1,   326,   430,    -1,   314,   430,
      -1,   315,   430,    -1,   316,   430,    -1,   317,   430,    -1,
     320,   430,    -1,   322,   430,    -1,   321,   430,    -1,   327,
     430,    -1,   431,    -1,   432,     7,   431,    -1,   432,     8,
     431,    -1,   432,    12,   431,    -1,   432,    -1,   433,    10,
     432,    -1,   433,    11,   432,    -1,   433,    -1,   434,    -1,
     435,     6,   434,    -1,   435,     5,   434,    -1,   435,   110,
     434,    -1,   435,   111,   434,    -1,   435,    -1,   436,   112,
     435,    -1,   436,   113,   435,    -1,   436,    -1,   437,    17,
     436,    -1,   437,    -1,   438,    -1,   439,    18,   438,    -1,
     439,    -1,   440,   108,   439,    -1,   440,    -1,   441,     4,
     440,    -1,   441,    -1,   442,   109,   441,    -1,   442,    -1,
     442,    21,   442,    22,   443,    -1,   443,    -1,   443,   116,
     444,    -1,   443,    95,   444,    -1,   443,    96,   444,    -1,
     443,    97,   444,    -1,   443,    98,   444,    -1,   443,    99,
     444,    -1,   444,    -1,    79,    -1,    69,    19,   269,    -1,
     271,    13,    79,    20,    79,    20,   420,    14,    -1,    41,
      13,   422,    14,    -1,   272,    13,   420,    20,   420,    14,
      -1,    70,    -1,   273,    13,   445,    14,    -1,    68,    -1,
      80,    15,   420,    16,    -1,   449,    -1,   237,    13,   421,
      20,   420,    14,    -1,   240,    13,   424,    20,   420,    14,
      -1,   237,    13,   421,    20,   420,    20,   424,    14,    -1,
     245,    13,   421,    20,   420,    20,   421,    14,    -1,   241,
      13,    78,    14,    -1,   241,    13,    78,    20,   420,    14,
      -1,   242,    13,   424,    20,   420,    14,    -1,   243,    13,
      78,    20,   420,    14,    -1,   244,    13,    78,    20,   420,
      14,    -1,   248,    13,    14,    -1,   248,   422,    -1,   212,
      13,   422,    14,    -1,   212,    13,   422,    20,   420,    14,
      -1,   200,    13,   424,    14,    -1,   201,    13,    78,    14,
      -1,   201,    13,    78,    20,   420,    20,   420,    20,   420,
      14,    -1,   202,    13,    78,    20,   420,    14,    -1,   207,
      13,    78,    20,   420,    20,   420,    20,   420,    20,   420,
      20,   420,    20,   420,    14,    -1,   208,    13,   421,    20,
     420,    20,   420,    20,   420,    20,   420,    20,   420,    20,
     420,    20,   420,    14,    -1,   209,    13,   421,    20,   420,
      20,   420,    20,   420,    14,    -1,   210,    13,   421,    20,
     420,    20,   420,    20,   420,    20,   420,    20,   420,    20,
     420,    20,   420,    20,   420,    14,    -1,   210,    13,   421,
      20,   420,    20,   420,    20,   420,    20,   420,    20,   420,
      14,    -1,   377,    13,   421,    14,    -1,   377,    13,   421,
      20,   420,    14,    -1,   377,    13,   421,    20,   420,    20,
     420,    14,    -1,   379,    13,   421,    20,   420,    20,   420,
      14,    -1,   378,    13,   421,    20,   420,    20,   420,    20,
     421,    20,   421,    14,    -1,   378,    13,   421,    20,   420,
      20,   420,    20,   421,    20,   421,    20,   421,    20,   420,
      14,    -1,   382,    13,   421,    20,   421,    20,   421,    20,
     420,    20,   420,    20,   420,    20,   420,    14,    -1,   382,
      13,   421,    20,   421,    20,   421,    20,   420,    20,   420,
      20,   420,    20,   420,    20,   420,    14,    -1,   382,    13,
     421,    20,   421,    20,   421,    20,   420,    20,   420,    20,
     420,    14,    -1,   383,    13,   421,    20,   420,    20,   420,
      20,   420,    20,   420,    20,   420,    14,    -1,   385,    13,
     421,    20,   421,    20,   421,    20,   420,    20,   420,    20,
     420,    20,   420,    14,    -1,   385,    13,   421,    20,   421,
      20,   421,    20,   420,    20,   420,    20,   420,    20,   420,
      20,   421,    20,   421,    14,    -1,    59,    -1,    79,    -1,
      72,    -1,    73,    -1,    75,    -1,    74,    -1,    76,    -1,
      78,    19,   450,    -1,   452,    -1,    80,    -1,    69,    -1,
      71,    -1,    77,    -1,    81,    -1,   451,    -1,   453,    -1,
     448,    -1,    78,    -1,    62,    -1,    63,    -1,    61,    -1,
      66,    -1,    67,    -1,    64,    -1,    70,    -1,   424,    -1,
     454,    -1,   455,    -1,   420,    22,   420,    20,   420,    22,
     420,    20,   420,    22,   420,    -1,   420,    22,   420,    20,
     420,    22,   420,    -1,    22,    20,    22,    20,   420,    22,
     420,    -1,   424,    19,    93,    -1,    65,    -1
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
     178,   183,   187,   193,   197,   204,   211,   218,   222,   229,
     233,   240,   247,   254,   263,   270,   279,   288,   297,   301,
     303,   305,   308,   311,   313,   315,   318,   327,   332,   337,
     339,   342,   345,   348,   357,   374,   377,   384,   387,   390,
     396,   399,   401,   403,   406,   409,   412,   415,   418,   421,
     426,   431,   434,   437,   440,   444,   448,   452,   455,   462,
     473,   480,   491,   502,   515,   522,   529,   533,   537,   541,
     545,   550,   554,   561,   568,   573,   594,   605,   612,   616,
     620,   627,   631,   638,   647,   654,   661,   670,   687,   694,
     698,   705,   714,   718,   731,   744,   757,   768,   772,   776,
     785,   794,   805,   814,   825,   838,   845,   854,   865,   882,
     901,   914,   921,   940,   957,   970,   981,   992,  1003,  1010,
    1021,  1028,  1035,  1042,  1051,  1056,  1061,  1070,  1075,  1094,
    1099,  1101,  1103,  1105,  1112,  1116,  1121,  1123,  1125,  1127,
    1158,  1183,  1192,  1194,  1198,  1199,  1201,  1205,  1208,  1213,
    1215,  1219,  1220,  1223,  1226,  1229,  1232,  1235,  1238,  1243,
    1248,  1253,  1258,  1263,  1268,  1270,  1277,  1279,  1283,  1288,
    1293,  1295,  1299,  1300,  1301,  1303,  1305,  1307,  1309,  1316,
    1325,  1336,  1347,  1358,  1367,  1374,  1378,  1382,  1386,  1390,
    1394,  1398,  1402,  1406,  1410,  1414,  1418,  1422,  1429,  1434,
    1445,  1450,  1461,  1466,  1471,  1476,  1481,  1486,  1491,  1499,
    1507,  1515,  1525,  1533,  1540,  1545,  1546,  1553,  1564,  1569,
    1574,  1579,  1583,  1590,  1597,  1604,  1606,  1608,  1610,  1612,
    1614,  1616,  1618,  1620,  1622,  1624,  1626,  1628,  1630,  1632,
    1636,  1638,  1643,  1646,  1651,  1656,  1658,  1669,  1682,  1691,
    1693,  1700,  1707,  1714,  1723,  1732,  1739,  1748,  1757,  1768,
    1779,  1792,  1805,  1816,  1821,  1832,  1837,  1844,  1849,  1854,
    1859,  1872,  1877,  1890,  1903,  1920,  1941,  1952,  1965,  1970,
    1977,  1984,  1991,  1996,  2001,  2008,  2013,  2020,  2027,  2034,
    2051,  2062,  2071,  2084,  2095,  2104,  2117,  2126,  2139,  2148,
    2161,  2174,  2189,  2202,  2215,  2232,  2237,  2246,  2257,  2270,
    2281,  2294,  2305,  2318,  2331,  2346,  2359,  2368,  2383,  2388,
    2393,  2398,  2403,  2407,  2411,  2418,  2425,  2432,  2439,  2448,
    2463,  2476,  2491,  2504,  2511,  2520,  2531,  2542,  2555,  2562,
    2569,  2576,  2583,  2590,  2597,  2604,  2611,  2620,  2631,  2636,
    2641,  2652,  2663,  2668,  2675,  2682,  2695,  2726,  2735,  2742,
    2747,  2754,  2759,  2766,  2771,  2776,  2795,  2804,  2811,  2813,
    2815,  2817,  2819,  2821,  2823,  2825,  2827,  2829,  2831,  2833,
    2835,  2837,  2839,  2841,  2848,  2853,  2857,  2859,  2862,  2865,
    2868,  2871,  2876,  2881,  2883,  2888,  2891,  2894,  2897,  2900,
    2903,  2906,  2909,  2912,  2915,  2918,  2921,  2924,  2927,  2930,
    2933,  2936,  2939,  2942,  2944,  2948,  2952,  2956,  2958,  2962,
    2966,  2968,  2970,  2974,  2978,  2982,  2986,  2988,  2992,  2996,
    2998,  3002,  3004,  3006,  3010,  3012,  3016,  3018,  3022,  3024,
    3028,  3030,  3036,  3038,  3042,  3046,  3050,  3054,  3058,  3062,
    3064,  3066,  3070,  3079,  3084,  3091,  3093,  3098,  3100,  3105,
    3107,  3114,  3121,  3130,  3139,  3144,  3151,  3158,  3165,  3172,
    3176,  3179,  3184,  3191,  3196,  3201,  3212,  3219,  3236,  3255,
    3266,  3287,  3302,  3307,  3314,  3323,  3332,  3345,  3362,  3379,
    3398,  3413,  3428,  3445,  3466,  3468,  3470,  3472,  3474,  3476,
    3478,  3480,  3484,  3486,  3488,  3490,  3492,  3494,  3496,  3498,
    3500,  3502,  3504,  3506,  3508,  3510,  3512,  3514,  3516,  3518,
    3520,  3522,  3524,  3536,  3544,  3552,  3556
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   832,   832,   833,   837,   837,   838,   839,   840,   840,
     841,   841,   842,   842,   843,   843,   844,   844,   845,   845,
     848,   849,   854,   873,   893,   939,   962,  1011,  1026,  1049,
    1048,  1080,  1079,  1123,  1140,  1162,  1183,  1190,  1225,  1235,
    1268,  1301,  1309,  1319,  1333,  1347,  1361,  1371,  1387,  1405,
    1420,  1435,  1466,  1494,  1541,  1552,  1562,  1573,  1599,  1638,
    1668,  1709,  1729,  1741,  1760,  1771,  1858,  1892,  1908,  1914,
    1918,  1922,  1926,  1936,  1941,  1945,  1955,  1970,  1980,  1991,
    1994,  2044,  2067,  2117,  2207,  2259,  2263,  2275,  2289,  2299,
    2309,  2320,  2328,  2340,  2576,  2586,  2596,  2606,  2615,  2680,
    2694,  2728,  2740,  2781,  2800,  3273,  3295,  3319,  3341,  3353,
    3367,  3386,  3408,  3437,  3466,  3498,  3695,  3700,  3707,  3712,
    3952,  3980,  3994,  4001,  4007,  4015,  4116,  4123,  4131,  4139,
    4147,  4158,  4168,  4176,  4184,  4195,  4202,  4216,  4230,  4239,
    4244,  4253,  4262,  4275,  4288,  4301,  4314,  4321,  4331,  4341,
    4355,  4363,  4374,  4397,  4423,  4451,  4462,  4505,  4527,  4556,
    4573,  4588,  4594,  4621,  4647,  4667,  4684,  4690,  4696,  4707,
    4713,  4721,  4736,  4745,  4756,  4773,  4789,  4827,  4841,  4888,
    4894,  4899,  4904,  4910,  4917,  4923,  4930,  4935,  4940,  4945,
    4988,  5042,  5064,  5072,  5089,  5093,  5109,  5127,  5143,  5158,
    5174,  5194,  5199,  5208,  5215,  5222,  5229,  5236,  5243,  5250,
    5257,  5264,  5271,  5278,  5286,  5291,  5372,  5396,  5401,  5414,
    5433,  5464,  5475,  5476,  5481,  5485,  5493,  5501,  5530,  5547,
    5563,  5580,  5599,  5617,  5633,  5649,  5655,  5661,  5667,  5673,
    5679,  5685,  5691,  5697,  5703,  5709,  5715,  5722,  5731,  5738,
    5769,  5777,  5789,  5809,  5829,  5849,  5869,  5889,  5909,  5933,
    5957,  5981,  5989,  6013,  6036,  6043,  6192,  6202,  6214,  6224,
    6234,  6246,  6254,  6270,  6285,  6315,  6333,  6345,  6366,  6371,
    6375,  6379,  6383,  6387,  6391,  6395,  6399,  6403,  6407,  6411,
    6419,  6421,  6440,  6448,  6468,  6503,  6534,  6541,  6559,  6584,
    6652,  6718,  6725,  6732,  6740,  6748,  6764,  6782,  6800,  6817,
    6834,  6852,  6888,  6901,  6912,  6925,  6949,  6960,  6971,  6981,
    6991,  7024,  7035,  7056,  7076,  7117,  7164,  7184,  7205,  7216,
    7230,  7244,  7257,  7268,  7279,  7292,  7310,  7322,  7334,  7386,
    7427,  7438,  7448,  7460,  7471,  7481,  7506,  7529,  7557,  7571,
    7705,  7739,  7772,  7800,  7814,  7828,  7838,  7857,  7876,  7896,
    7917,  7939,  7958,  7977,  7997,  8037,  8059,  8088,  8110,  8147,
    8184,  8221,  8255,  8261,  8278,  8285,  8292,  8300,  8307,  8329,
    8357,  8381,  8408,  8440,  8449,  8462,  8469,  8477,  8491,  8503,
    8515,  8525,  8536,  8546,  8556,  8567,  8577,  8588,  8615,  8663,
    8797,  8818,  8858,  8869,  8877,  8885,  8906,  8932,  8943,  8950,
    8956,  8962,  8969,  8994,  9012,  9019,  9052,  9071,  9092,  9107,
    9118,  9127,  9141,  9143,  9145,  9147,  9149,  9151,  9153,  9155,
    9157,  9159,  9161,  9163,  9225,  9303,  9306,  9307,  9315,  9323,
    9331,  9341,  9380,  9392,  9394,  9403,  9409,  9414,  9419,  9424,
    9429,  9434,  9439,  9444,  9449,  9454,  9459,  9464,  9469,  9474,
    9479,  9484,  9489,  9498,  9499,  9505,  9511,  9521,  9522,  9529,
    9539,  9543,  9544,  9550,  9556,  9562,  9571,  9572,  9578,  9604,
    9605,  9609,  9613,  9614,  9618,  9619,  9631,  9632,  9644,  9645,
    9657,  9658,  9671,  9672,  9682,  9689,  9695,  9701,  9707,  9716,
    9720,  9730,  9744,  9755,  9773,  9779,  9788,  9909,  9911,  9927,
    9932,  9947,  9959,  9981, 10017, 10026, 10036, 10045, 10055, 10069,
   10076, 10085, 10101, 10120, 10140, 10170, 10199, 10216, 10242, 10276,
   10308, 10355, 10396, 10405, 10427, 10438, 10449, 10485, 10527, 10573,
   10623, 10665, 10696, 10728, 10770, 10778, 10781, 10782, 10783, 10784,
   10785, 10786, 10819, 10821, 10822, 10823, 10824, 10825, 10830, 10831,
   10837, 10839, 10841, 10843, 10845, 10847, 10850, 10852, 10855, 10857,
   10861, 10863, 10866, 10875, 10883, 10901, 10918
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
     395,   396,   397,   398
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 11322;
  const int Parser::yynnts_ = 59;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 572;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 399;

  const unsigned int Parser::yyuser_token_number_max_ = 653;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // yyip

/* Line 1054 of lalr1.cc  */
#line 15052 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"


/* Line 1056 of lalr1.cc  */
#line 10940 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"

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




