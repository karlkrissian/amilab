
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
#line 11 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"

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
#line 372 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"


#include "improcess_bison.tab.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 815 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"


#include "driver.h"
#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex



/* Line 317 of lalr1.cc  */
#line 395 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"

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
#line 464 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
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
#line 808 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 571 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 59: /* "IDENTIFIER" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 580 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 442: /* "exprstringlist" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->string_list); };

/* Line 480 of lalr1.cc  */
#line 589 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 445: /* "primary_expr_string" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 598 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 446: /* "instr_block" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ablock); };

/* Line 480 of lalr1.cc  */
#line 607 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 452: /* "expr_string" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 616 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 480: /* "identifier" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 625 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
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
#line 360 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}

/* Line 553 of lalr1.cc  */
#line 711 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"

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
#line 854 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 873 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 893 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 938 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 961 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1010 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1025 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1047 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GB_driver.procedure_declaration = true;
    }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 1052 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1078 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      // allow overriding current functions
      GB_driver.procedure_declaration = true;
    }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 1084 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1123 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1140 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1161 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1182 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
       //driver.res_print($2);
       driver.parse_script((yysemantic_stack_[(3) - (2)].astring));
       delete [] (yysemantic_stack_[(3) - (2)].astring);
     }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 1189 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1224 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> input((yysemantic_stack_[(2) - (2)].astring));
      string inputstring( input.get());
      driver.parse_string( inputstring,
                          "'eval string' command");
    }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 1234 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1267 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1299 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1307 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1318 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1332 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1346 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1360 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1370 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1386 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1404 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1419 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1434 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1465 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1493 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1540 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1551 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1561 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1572 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1598 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1637 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1667 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1708 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1728 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1740 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1759 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1770 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1857 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1891 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1907 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<FILE>::ptr varfile(driver.var_stack.GetLastVar<FILE>());
          FILE_ptr file(varfile->Pointer());
          rewind(file.get());
        }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1913 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GB_debug = 1;
        }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1917 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GB_debug = 0;
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1921 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      driver.SetTraceScanning((yysemantic_stack_[(2) - (2)].adouble)>0.5);
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1925 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1935 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 1;
      verbose = 1;
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1940 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 0;
    }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1944 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1954 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1969 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1979 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1989 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GB_main_wxFrame->Close(true);
        }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 1993 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2043 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2066 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2116 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2206 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2258 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Vars.display();
        }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 2262 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2274 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2288 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2298 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2308 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2319 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2327 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2339 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2575 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2585 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2595 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2605 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2614 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2679 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2693 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2727 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2739 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2780 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 2799 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          driver.var_stack.GetLastBasicVar();
          printf("Deprecated: No need to close files explicitly, since we use smart pointers, they will be closed when the variable is deleted. \n");
        }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 2826 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 106:

/* Line 678 of lalr1.cc  */
#line 2843 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 107:

/* Line 678 of lalr1.cc  */
#line 2856 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 108:

/* Line 678 of lalr1.cc  */
#line 2867 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 109:

/* Line 678 of lalr1.cc  */
#line 2913 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(DessinImage, draw2);
          GET_VARSTACK_VALUE(DessinImage, draw1);

          draw1->CreeCompare2Image(draw2);
        }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 2920 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 111:

/* Line 678 of lalr1.cc  */
#line 2943 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 112:

/* Line 678 of lalr1.cc  */
#line 2974 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 113:

/* Line 678 of lalr1.cc  */
#line 2989 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;

          draw = DessinImage::ptr(varimd->Pointer());
          draw->SetVectorVisible( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 2997 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;

          draw = DessinImage::ptr(varimd->Pointer());
          draw->CB_AfficheChampVect(draw.get(),NULL);
        }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 3005 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 116:

/* Line 678 of lalr1.cc  */
#line 3024 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 117:

/* Line 678 of lalr1.cc  */
#line 3048 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw= DessinImage::ptr(varimd->Pointer());
          draw->SetVectType((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 3054 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw= DessinImage::ptr(varimd->Pointer());
          draw->SetLineThickness((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 3060 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 120:

/* Line 678 of lalr1.cc  */
#line 3074 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          int width  = (int) (yysemantic_stack_[(8) - (5)].adouble);
          int height = (int) (yysemantic_stack_[(8) - (7)].adouble);

          DessinImage::ptr draw= DessinImage::ptr(varimd->Pointer());
          draw->SetSize(width,height);
          draw->Update();


        }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 3086 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          ClasseCouleur c;

          draw = DessinImage::ptr(varimd->Pointer());
          c.FixeValeur((int)(yysemantic_stack_[(16) - (11)].adouble),(int)(yysemantic_stack_[(16) - (13)].adouble),(int)(yysemantic_stack_[(16) - (15)].adouble));
          draw->DessineCercle( (int) (yysemantic_stack_[(16) - (5)].adouble), (int) (yysemantic_stack_[(16) - (7)].adouble), (int) (yysemantic_stack_[(16) - (9)].adouble), c);
        }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 3096 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
          Description: Set a user-defined colormap.
         **/
          GET_VARSTACK_VALUE(InrImage, colmap);
          GET_VARSTACK_VALUE(DessinImage, draw);

          draw->SetUserColormap( colmap,  (yysemantic_stack_[(10) - (7)].adouble),  (yysemantic_stack_[(10) - (9)].adouble));
        }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 3106 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,    surfd);
          GET_VARSTACK_VALUE(DessinImage, draw);

          draw->SetGLWindow(surfd);
        }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 3113 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 125:

/* Line 678 of lalr1.cc  */
#line 3130 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 126:

/* Line 678 of lalr1.cc  */
#line 3146 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 127:

/* Line 678 of lalr1.cc  */
#line 3164 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 128:

/* Line 678 of lalr1.cc  */
#line 3185 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 129:

/* Line 678 of lalr1.cc  */
#line 3201 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 130:

/* Line 678 of lalr1.cc  */
#line 3220 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 131:

/* Line 678 of lalr1.cc  */
#line 3234 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 132:

/* Line 678 of lalr1.cc  */
#line 3249 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(AMIFunction, func);
          GET_VARSTACK_VALUE(DessinImage, draw);

          draw->SetPaintCallback( (void*) CB_ParamWin, 
                                  (void*) func.get() );
          // may be a pb to call Paint() here since it will start another interpreter ??? to check
          //draw->Paint();
        }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 3259 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 134:

/* Line 678 of lalr1.cc  */
#line 3271 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 135:

/* Line 678 of lalr1.cc  */
#line 3293 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 136:

/* Line 678 of lalr1.cc  */
#line 3317 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 137:

/* Line 678 of lalr1.cc  */
#line 3339 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 138:

/* Line 678 of lalr1.cc  */
#line 3351 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 139:

/* Line 678 of lalr1.cc  */
#line 3365 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 140:

/* Line 678 of lalr1.cc  */
#line 3384 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 141:

/* Line 678 of lalr1.cc  */
#line 3406 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 142:

/* Line 678 of lalr1.cc  */
#line 3437 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 143:

/* Line 678 of lalr1.cc  */
#line 3464 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 144:

/* Line 678 of lalr1.cc  */
#line 3496 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> name((yysemantic_stack_[(6) - (5)].astring));
      GET_VARSTACK_VALUE(InrImage, im);
      im->FixeNom( name.get());
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 3693 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 3698 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {

      Func_EndWeickert();

    }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 3705 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 3710 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Func_EndWeickert();
    }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 3950 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 150:

/* Line 678 of lalr1.cc  */
#line 3978 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 151:

/* Line 678 of lalr1.cc  */
#line 3992 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im2);
      GET_VARSTACK_VALUE(InrImage, im1);
      Func_OrientField( im1.get() , im2.get() );
    }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 3999 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im2);
      GET_VARSTACK_VALUE(InrImage, im1);
      Func_OrientPositive( im1.get(), im2.get());
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 4005 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      if (strlen((yysemantic_stack_[(4) - (3)].astring))<255) {
        strcpy(AMIFluid::FLUID_NAVIGATION_FILE,(yysemantic_stack_[(4) - (3)].astring));
      } else
        fprintf(stderr,"SetFluidNavFile() \t File too long \n");
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 4014 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 155:

/* Line 678 of lalr1.cc  */
#line 4114 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,sdraw);

          sdraw->GetCanvas()->UserRotate((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 4121 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_OBJECT(SurfacePoly,surf)
          GET_VARSTACK_VALUE(Viewer3D,sdraw);

          sdraw->GetCanvas()->AddSurface(surf);
          sdraw->Paint();
        }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 4129 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_OBJECT(SurfacePoly,surf)
          GET_VARSTACK_VALUE(Viewer3D,   sdraw);

          sdraw->GetCanvas()->AddSurface( surf);
          //sdraw->Paint();
        }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 4137 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_OBJECT(SurfacePoly,surf)
          GET_VARSTACK_VALUE(Viewer3D,   sdraw);

          sdraw->GetCanvas()->RemoveSurface(surf);
          sdraw->Paint();
        }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 4145 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 160:

/* Line 678 of lalr1.cc  */
#line 4156 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          /**
            Description:  Swaps the 3D buffer
          **/
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw(varsurfd->Pointer());

          sdraw->GetCanvas()->AfficheBuffer();
        }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 4166 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC ( (int) (yysemantic_stack_[(6) - (5)].adouble) );
          sdraw->Paint();
        }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 4174 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
          sdraw->Paint();
        }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 4182 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 164:

/* Line 678 of lalr1.cc  */
#line 4193 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,sdraw2);
          GET_VARSTACK_VALUE(Viewer3D,sdraw1);

          sdraw1->AddCompSurf(sdraw2);
        }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 4200 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 166:

/* Line 678 of lalr1.cc  */
#line 4214 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 167:

/* Line 678 of lalr1.cc  */
#line 4228 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr draw (varsurfd->Pointer());
          int num = (int) (yysemantic_stack_[(6) - (5)].adouble);
    
          draw->GetCanvas()->HideFreeSection(num);
    
        }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 4237 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,v);
          v->GetCanvas()->PrintMatrices();
        }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 4242 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->GetCanvas()->SetObjectTransform(*tr);
              sdraw->Paint();
          delete tr;
        }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 4251 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->GetCanvas()->SetObjectTransform(*tr);
          if ((yysemantic_stack_[(8) - (7)].adouble)>0.5) sdraw->Paint();
          delete tr;
        }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 4260 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 172:

/* Line 678 of lalr1.cc  */
#line 4273 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 173:

/* Line 678 of lalr1.cc  */
#line 4286 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 174:

/* Line 678 of lalr1.cc  */
#line 4299 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 175:

/* Line 678 of lalr1.cc  */
#line 4312 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->GetCanvas()->SetBG((int)(yysemantic_stack_[(10) - (5)].adouble),(int)(yysemantic_stack_[(10) - (7)].adouble),(int)(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 4319 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 177:

/* Line 678 of lalr1.cc  */
#line 4329 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 178:

/* Line 678 of lalr1.cc  */
#line 4339 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 179:

/* Line 678 of lalr1.cc  */
#line 4353 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          Func_StructureTensor(im.get(),
                   varim->Name().c_str(),
                   (yysemantic_stack_[(8) - (5)].adouble), (yysemantic_stack_[(8) - (7)].adouble), NULL);
        }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 4361 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage,mask);
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);

          Func_StructureTensor(
            im.get(),
            varim->Name().c_str(),
            (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), mask.get());
        }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 4372 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 182:

/* Line 678 of lalr1.cc  */
#line 4395 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 183:

/* Line 678 of lalr1.cc  */
#line 4421 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 184:

/* Line 678 of lalr1.cc  */
#line 4449 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 185:

/* Line 678 of lalr1.cc  */
#line 4460 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 186:

/* Line 678 of lalr1.cc  */
#line 4503 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 187:

/* Line 678 of lalr1.cc  */
#line 4525 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 188:

/* Line 678 of lalr1.cc  */
#line 4554 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 189:

/* Line 678 of lalr1.cc  */
#line 4572 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 190:

/* Line 678 of lalr1.cc  */
#line 4586 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          Func_Curvatures(im.get(), varim->Name().c_str(), (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 4597 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 192:

/* Line 678 of lalr1.cc  */
#line 4623 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 193:

/* Line 678 of lalr1.cc  */
#line 4649 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 194:

/* Line 678 of lalr1.cc  */
#line 4668 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 195:

/* Line 678 of lalr1.cc  */
#line 4682 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      im->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 4688 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      im->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 4694 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 198:

/* Line 678 of lalr1.cc  */
#line 4705 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      im->SetTranslation((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 4711 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2( driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1( driver.var_stack.GetLastVar<InrImage>());
      InrImage::ptr im (varim2->Pointer());
      varim1->Pointer()->SetVoxelSize( im->TrX(), im->TrY(), im->TrZ());
    }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 4719 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 201:

/* Line 678 of lalr1.cc  */
#line 4734 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
      Func_DiscSecDerGrad(
        varim1->Pointer().get(),
        varim2->Pointer().get());
    }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 4743 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 203:

/* Line 678 of lalr1.cc  */
#line 4754 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 204:

/* Line 678 of lalr1.cc  */
#line 4771 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 205:

/* Line 678 of lalr1.cc  */
#line 4787 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 206:

/* Line 678 of lalr1.cc  */
#line 4825 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 207:

/* Line 678 of lalr1.cc  */
#line 4843 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 208:

/* Line 678 of lalr1.cc  */
#line 4886 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));
      Func_GenRead(filename.get());
    }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 4892 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.InitCumul();
    }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 4897 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Debut();
    }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 4902 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Fin();
      cout << "time spent = " << driver.IP_time << endl;
    }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 4908 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          boost::shared_array<char> filename( (yysemantic_stack_[(6) - (5)].astring));
          GET_VARSTACK_VALUE(InrImage, i);
          Func_VectorImage2StructuredGrid(i.get(),filename.get());
        }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 4915 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(GLTransfMatrix, glmat);
          glmat->Print();
        }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 4921 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          boost::shared_array<char> filename( (yysemantic_stack_[(4) - (4)].astring));
          GET_VARSTACK_VALUE(GLTransfMatrix, glmat);
          Func_SaveTransform(glmat.get(),filename.get());
        }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 4928 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          AddWrapVTK();
        }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 4933 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          AddWrapWII();
        }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 4938 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          AddWrapFilters();
        }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 4949 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 219:

/* Line 678 of lalr1.cc  */
#line 4989 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 220:

/* Line 678 of lalr1.cc  */
#line 5040 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 221:

/* Line 678 of lalr1.cc  */
#line 5062 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = new std::list<std::string>();
            sl->push_back(string((yysemantic_stack_[(1) - (1)].astring)));
            delete [] (yysemantic_stack_[(1) - (1)].astring);
            (yyval.string_list) = sl;
        }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 5070 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = (yysemantic_stack_[(3) - (1)].string_list);
            sl->push_back(string((yysemantic_stack_[(3) - (3)].astring)));
            delete [] (yysemantic_stack_[(3) - (3)].astring);
            (yyval.string_list) = sl;
        }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 5086 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          (yyval.paramlist) = pl;
        }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 5091 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 225:

/* Line 678 of lalr1.cc  */
#line 5107 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 226:

/* Line 678 of lalr1.cc  */
#line 5125 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 227:

/* Line 678 of lalr1.cc  */
#line 5141 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 228:

/* Line 678 of lalr1.cc  */
#line 5156 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 229:

/* Line 678 of lalr1.cc  */
#line 5172 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 230:

/* Line 678 of lalr1.cc  */
#line 5191 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      //      printf("no parameters \n");
      ParamListDecl* pl = new ParamListDecl;
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 5197 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      cout << "param_list_decl: T_NUM IDENTIFIER" << endl;
      cout << ident->GetName().c_str() << endl;
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_float);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 5206 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_ami_object);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 5213 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_string);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 5220 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 5227 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 5234 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 5241 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_ami_object);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 5248 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_float);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 5255 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_string);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 5262 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 5269 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 5276 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 5284 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
    }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 5289 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 245:

/* Line 678 of lalr1.cc  */
#line 5370 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 246:

/* Line 678 of lalr1.cc  */
#line 5393 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      (yyval.astring)=(char*) (im)->GetName();
    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 5399 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 248:

/* Line 678 of lalr1.cc  */
#line 5411 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 249:

/* Line 678 of lalr1.cc  */
#line 5431 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      char* res = new char[GB_scripts_dir.Len()+1];
      strcpy(res,(const char*)GB_scripts_dir.mb_str(wxConvUTF8));
      (yyval.astring)= res;
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 5464 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        (yyval.ablock)=(yysemantic_stack_[(3) - (2)].ablock);
        if (GB_debug)
          cerr << format("ablock : %s")
                  % (yysemantic_stack_[(3) - (2)].ablock)->GetBody()
                << endl;
          }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 5479 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      ADD_VARSTACK_FLOAT((yysemantic_stack_[(1) - (1)].adouble))
    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 5483 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      returns the number of arguments in the command line
    **/
      ADD_VARSTACK_FLOAT(GB_argc-GB_num_arg_parsed)
    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 5491 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      Line number in the current script
    **/
      ADD_VARSTACK_FLOAT(driver.yyiplineno)
    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 5499 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        the constant Pi is set to
         3.14159265358979323846
      **/
      ADD_VARSTACK_FLOAT(3.14159265358979323846)
    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 5528 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 258:

/* Line 678 of lalr1.cc  */
#line 5545 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 259:

/* Line 678 of lalr1.cc  */
#line 5561 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 260:

/* Line 678 of lalr1.cc  */
#line 5578 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 261:

/* Line 678 of lalr1.cc  */
#line 5597 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 262:

/* Line 678 of lalr1.cc  */
#line 5615 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 263:

/* Line 678 of lalr1.cc  */
#line 5631 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 264:

/* Line 678 of lalr1.cc  */
#line 5647 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->DimX();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 5653 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->DimY();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 5659 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->DimZ();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 5665 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->TrX();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 5671 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->TrY();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 5677 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->TrZ();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 5683 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->VoxSizeX();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 5689 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->VoxSizeY();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 5695 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->VoxSizeZ();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 5701 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->GetVDim();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 5707 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->IncBuffer();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 5713 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->ValeurBuffer();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 5720 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
      float val=Func_SNR(varim1->Pointer().get(),
                  varim2->Pointer().get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 5729 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      float val=Func_eccentricity(im.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 5736 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 279:

/* Line 678 of lalr1.cc  */
#line 5767 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(InrImage, im);
      float val=Func_ComputePositiveArea( im.get() );
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 5775 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 281:

/* Line 678 of lalr1.cc  */
#line 5787 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 282:

/* Line 678 of lalr1.cc  */
#line 5807 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 283:

/* Line 678 of lalr1.cc  */
#line 5827 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 284:

/* Line 678 of lalr1.cc  */
#line 5847 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 285:

/* Line 678 of lalr1.cc  */
#line 5867 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 286:

/* Line 678 of lalr1.cc  */
#line 5887 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 287:

/* Line 678 of lalr1.cc  */
#line 5907 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 288:

/* Line 678 of lalr1.cc  */
#line 5931 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 289:

/* Line 678 of lalr1.cc  */
#line 5955 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 290:

/* Line 678 of lalr1.cc  */
#line 5979 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      GET_VARSTACK_VALUE(InrImage, mask);
      float val=Func_med( im.get(),(float) (yysemantic_stack_[(9) - (8)].adouble),mask.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 5987 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 292:

/* Line 678 of lalr1.cc  */
#line 6011 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 293:

/* Line 678 of lalr1.cc  */
#line 6034 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      setlocale(LC_NUMERIC, "C");
      float val=atof((yysemantic_stack_[(4) - (3)].astring));
      ADD_VARSTACK_FLOAT(val);
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 6042 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 295:

/* Line 678 of lalr1.cc  */
#line 6054 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 296:

/* Line 678 of lalr1.cc  */
#line 6066 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 297:

/* Line 678 of lalr1.cc  */
#line 6078 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 298:

/* Line 678 of lalr1.cc  */
#line 6090 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 299:

/* Line 678 of lalr1.cc  */
#line 6102 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 300:

/* Line 678 of lalr1.cc  */
#line 6114 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 301:

/* Line 678 of lalr1.cc  */
#line 6130 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 302:

/* Line 678 of lalr1.cc  */
#line 6149 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 303:

/* Line 678 of lalr1.cc  */
#line 6190 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 304:

/* Line 678 of lalr1.cc  */
#line 6200 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 305:

/* Line 678 of lalr1.cc  */
#line 6212 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 306:

/* Line 678 of lalr1.cc  */
#line 6222 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 307:

/* Line 678 of lalr1.cc  */
#line 6232 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 308:

/* Line 678 of lalr1.cc  */
#line 6244 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
        Description: returns the value of the pixel format type in float format
      **/
      float val = (int) (yysemantic_stack_[(3) - (1)].aint);
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 6252 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 310:

/* Line 678 of lalr1.cc  */
#line 6268 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 311:

/* Line 678 of lalr1.cc  */
#line 6283 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 312:

/* Line 678 of lalr1.cc  */
#line 6313 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 313:

/* Line 678 of lalr1.cc  */
#line 6331 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 314:

/* Line 678 of lalr1.cc  */
#line 6343 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 315:

/* Line 678 of lalr1.cc  */
#line 6364 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      driver.err_print(" char format is not available: use unsigned char \n");
      (yyval.aint)=WT_UNSIGNED_CHAR;
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 6369 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          (yyval.aint)=WT_UNSIGNED_CHAR;
       }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 6373 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_SHORT;
       }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 6377 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_SHORT;
       }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 6381 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_INT;
       }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 6385 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_INT;
       }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 6389 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_LONG;
       }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 6393 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT;
       }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 6397 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_DOUBLE;
       }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 6401 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_RGB;
       }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 6405 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT_VECTOR;
       }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 6409 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
         //        printf("format %d \n",(int) ( *(InrImage::ptr*) $1->Pointer())->GetFormat());
        GET_VARSTACK_VALUE(InrImage, im);
        (yyval.aint) = (int) im->GetFormat();
      }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 6419 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 329:

/* Line 678 of lalr1.cc  */
#line 6438 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        boost::shared_array<char> st( (yysemantic_stack_[(2) - (2)].astring));
        InrImage* res = ReadImage(st.get());
        if (!res) YYABORT;
        else
          ADD_VARSTACK(InrImage,res);
      }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 6446 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 331:

/* Line 678 of lalr1.cc  */
#line 6466 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 332:

/* Line 678 of lalr1.cc  */
#line 6501 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 333:

/* Line 678 of lalr1.cc  */
#line 6532 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        //printf(" ********** %d %f %f %f\n", $3, $5, $7, $9);
        InrImage::ptr im (new InrImage( (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble), (WORDTYPE) (yysemantic_stack_[(10) - (3)].aint)));
        ADD_VARSTACK_PTR(InrImage,im);
      }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 6539 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 335:

/* Line 678 of lalr1.cc  */
#line 6557 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 337:

/* Line 678 of lalr1.cc  */
#line 6650 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 338:

/* Line 678 of lalr1.cc  */
#line 6716 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      InrImage* res =Func_localmean( im.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      ADD_VARSTACK(InrImage,res);
    }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 6723 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      InrImage* res =Func_localmean2( im.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      ADD_VARSTACK(InrImage,res);
    }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 6730 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, mean);
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage* res     = Func_localSD( im.get(), mean.get(), (int) (yysemantic_stack_[(8) - (7)].adouble));
      ADD_VARSTACK(InrImage,res);
    }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 6738 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, mean);
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res(Func_localSD2( im.get(), mean.get(), (int) (yysemantic_stack_[(8) - (7)].adouble)));
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 6746 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 343:

/* Line 678 of lalr1.cc  */
#line 6762 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 344:

/* Line 678 of lalr1.cc  */
#line 6780 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 345:

/* Line 678 of lalr1.cc  */
#line 6798 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 346:

/* Line 678 of lalr1.cc  */
#line 6815 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 347:

/* Line 678 of lalr1.cc  */
#line 6833 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 348:

/* Line 678 of lalr1.cc  */
#line 6853 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 349:

/* Line 678 of lalr1.cc  */
#line 6886 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 350:

/* Line 678 of lalr1.cc  */
#line 6899 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkDist( im.get()));

        Si (!res.get()) Alors
          driver.err_print("vtkDist() erreur ... \n");
        FinSi
        ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 6910 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 352:

/* Line 678 of lalr1.cc  */
#line 6923 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 353:

/* Line 678 of lalr1.cc  */
#line 6947 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, input);
        InrImage::ptr res (Func_2DFlux(input.get(),(yysemantic_stack_[(6) - (5)].adouble)));

      Si (res.get()) Alors
        driver.err_print("2DFlux() error ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 6958 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_OutFlux( im.get()));

      Si (!res.get()) Alors
        driver.err_print("OutFlux() erreur ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 6969 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_OutFluxScalar( im.get()));
    Si (!res.get()) Alors
      driver.err_print("OutFluxScalar() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 6979 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_OrientationRatio2D( im.get()));
    Si (!res.get()) Alors
      driver.err_print("OrientationRatio() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 6989 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 358:

/* Line 678 of lalr1.cc  */
#line 7022 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_SimplePoints( im.get() ));

    Si !res.get() Alors
      driver.err_print("SimplePoints() error ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 7034 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 360:

/* Line 678 of lalr1.cc  */
#line 7055 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 361:

/* Line 678 of lalr1.cc  */
#line 7075 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 362:

/* Line 678 of lalr1.cc  */
#line 7116 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 363:

/* Line 678 of lalr1.cc  */
#line 7162 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 364:

/* Line 678 of lalr1.cc  */
#line 7182 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 365:

/* Line 678 of lalr1.cc  */
#line 7203 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res( Func_NormalSmoothField( im.get() ));

    Si !res.get() Alors
      driver.err_print("NormalField() error ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 7214 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 367:

/* Line 678 of lalr1.cc  */
#line 7228 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 368:

/* Line 678 of lalr1.cc  */
#line 7244 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, input);
  
      InrImage::ptr res ( Func_NormGrad( input.get(), (yysemantic_stack_[(6) - (5)].adouble)));
      Si (!res.get()) Alors
        driver.err_print("NormGrad() error ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 7256 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_DiscNormGrad( im.get()));
    Si !res.get() Alors
      driver.err_print("discnormgrad() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 7267 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_DiscMeanCurvature( im.get()));
    Si !res.get() Alors
      driver.err_print("DiscMeanCurvature() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 7279 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 372:

/* Line 678 of lalr1.cc  */
#line 7290 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 373:

/* Line 678 of lalr1.cc  */
#line 7310 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage,im);
        InrImage::ptr res (Func_SecDerGrad( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
        Si !res.get() Alors
          fprintf(stderr,"SecDerGrad() erreur ... \n");
        FinSi
        ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 7322 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 375:

/* Line 678 of lalr1.cc  */
#line 7332 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage,im);
        InrImage::ptr res ( Func_AutoCrop(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
        ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 7387 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 377:

/* Line 678 of lalr1.cc  */
#line 7425 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 378:

/* Line 678 of lalr1.cc  */
#line 7436 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_EDP_dilate( im.get(), (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 7446 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 380:

/* Line 678 of lalr1.cc  */
#line 7458 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 381:

/* Line 678 of lalr1.cc  */
#line 7469 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_EDP_erode( im.get(), (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    ADD_VARSTACK_PTR(InrImage,res);
      }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 7479 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 383:

/* Line 678 of lalr1.cc  */
#line 7506 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 384:

/* Line 678 of lalr1.cc  */
#line 7529 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 385:

/* Line 678 of lalr1.cc  */
#line 7557 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 386:

/* Line 678 of lalr1.cc  */
#line 7570 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 387:

/* Line 678 of lalr1.cc  */
#line 7704 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 388:

/* Line 678 of lalr1.cc  */
#line 7739 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 389:

/* Line 678 of lalr1.cc  */
#line 7772 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 390:

/* Line 678 of lalr1.cc  */
#line 7800 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 391:

/* Line 678 of lalr1.cc  */
#line 7814 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 392:

/* Line 678 of lalr1.cc  */
#line 7826 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_SRAD_qcoeff( im.get()));
      Si !res.get() Alors
        fprintf(stderr,"Func_SRAD_qcoeff() erreur ... \n");
      FinSi
      ADD_VARSTACK_PTR(InrImage,res);
        }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 7838 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 394:

/* Line 678 of lalr1.cc  */
#line 7856 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 395:

/* Line 678 of lalr1.cc  */
#line 7875 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 396:

/* Line 678 of lalr1.cc  */
#line 7895 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 397:

/* Line 678 of lalr1.cc  */
#line 7917 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 398:

/* Line 678 of lalr1.cc  */
#line 7937 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 399:

/* Line 678 of lalr1.cc  */
#line 7956 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 400:

/* Line 678 of lalr1.cc  */
#line 7976 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 401:

/* Line 678 of lalr1.cc  */
#line 7996 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 402:

/* Line 678 of lalr1.cc  */
#line 8037 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 403:

/* Line 678 of lalr1.cc  */
#line 8059 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 404:

/* Line 678 of lalr1.cc  */
#line 8087 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 405:

/* Line 678 of lalr1.cc  */
#line 8108 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 406:

/* Line 678 of lalr1.cc  */
#line 8145 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 407:

/* Line 678 of lalr1.cc  */
#line 8182 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 408:

/* Line 678 of lalr1.cc  */
#line 8219 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 409:

/* Line 678 of lalr1.cc  */
#line 8253 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          ADD_VARSTACK(InrImage,InrImage::ptr(( varsurfd->Pointer())->GetCanvas()->GetGLImage()));
        }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 8259 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          driver.yyiperror("Not available in new wxwidgets version of the 3D viewer ! ");
          YYABORT;
/*
          ADD_VARSTACK(InrImage,(*(Viewer3D_ptr*) $1->Pointer())->GetInrImage());
*/
    }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 8269 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(DessinImage, imdraw)
      ADD_VARSTACK(InrImage, imdraw->GetInrImage());
    }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 8275 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_ThresholdCrossing( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
       ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 8282 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_IsocontourPoints( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 8289 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_IsosurfDist( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
      ADD_VARSTACK_PTR(InrImage,res);

    }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 8297 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_vtkIsoContourDist( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 8304 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 417:

/* Line 678 of lalr1.cc  */
#line 8328 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 418:

/* Line 678 of lalr1.cc  */
#line 8355 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 419:

/* Line 678 of lalr1.cc  */
#line 8379 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 420:

/* Line 678 of lalr1.cc  */
#line 8408 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 421:

/* Line 678 of lalr1.cc  */
#line 8437 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im2);
      GET_VARSTACK_VALUE(InrImage, im1);
      InrImage::ptr res ( Func_Convolve(im1.get(), im2.get()));
      ADD_VARSTACK_PTR(InrImage,res);

      }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 8446 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 423:

/* Line 678 of lalr1.cc  */
#line 8459 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_Chamfer(im.get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble)));
        ADD_VARSTACK_PTR(InrImage,res);
        }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 8466 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
          InrImage::ptr res ( Func_Chamfer2(im.get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble)));
          ADD_VARSTACK_PTR(InrImage,res);

        }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 8474 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 426:

/* Line 678 of lalr1.cc  */
#line 8488 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr  res ( Func_Chamfer2(im.get(),
                  0.92644, 1.34065, 1.65849,
                  dmax));
        ADD_VARSTACK_PTR(InrImage,res);

        }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 8500 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_Chamfer2Signed(im.get(),
                    0.92644, 1.34065, 1.65849,
                    dmax));
        ADD_VARSTACK_PTR(InrImage,res);

        }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 8512 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkSignedBorgefors(im.get(),
                    dmax));
        ADD_VARSTACK_PTR(InrImage,res);
        }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 8522 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkSignedFMDist(im.get(),
                     dmax));
        ADD_VARSTACK_PTR(InrImage,res);

        }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 8533 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_PropagationDistance(im.get(),
                      dmax));
        ADD_VARSTACK_PTR(InrImage,res);
        }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 8543 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_PropagationDistance2(im.get(),
                      dmax));
        ADD_VARSTACK_PTR(InrImage,res);
        }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 8553 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

        GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_PropagationDanielsson(im.get(),
                       dmax));

        ADD_VARSTACK_PTR(InrImage,res);
        }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 8564 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkPropDanielsson(im.get(),
                       -dmax,dmax));
        ADD_VARSTACK_PTR(InrImage,res);
        }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 8574 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        float dmin = (yysemantic_stack_[(8) - (5)].adouble);
        float dmax = (yysemantic_stack_[(8) - (7)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkPropDanielsson(im.get(),
                       dmin,dmax));
        ADD_VARSTACK_PTR(InrImage,res);
        }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 8585 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 436:

/* Line 678 of lalr1.cc  */
#line 8612 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 437:

/* Line 678 of lalr1.cc  */
#line 8660 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 438:

/* Line 678 of lalr1.cc  */
#line 8794 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 439:

/* Line 678 of lalr1.cc  */
#line 8815 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 440:

/* Line 678 of lalr1.cc  */
#line 8855 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 441:

/* Line 678 of lalr1.cc  */
#line 8866 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      int dim = (int) (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage,im);
      InrImage::ptr res ( Func_MeanHalfSize(im.get(),dim));
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 8874 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        int axis=(int) (yysemantic_stack_[(6) - (5)].adouble);

        GET_VARSTACK_VALUE(InrImage,im);
        InrImage::ptr res(Func_Flip(im,axis));
        ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 8882 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 444:

/* Line 678 of lalr1.cc  */
#line 8903 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 445:

/* Line 678 of lalr1.cc  */
#line 8929 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      int   order = (int) (yysemantic_stack_[(8) - (5)].adouble);
      float resolution = (yysemantic_stack_[(8) - (7)].adouble);
      GET_VARSTACK_VALUE(InrImage,input);

      InrImage::ptr res ( Func_vtkConvexHull(input.get(),
                   order,resolution));

      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 8940 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);

      InrImage::ptr res ( AMIFluid::Func_Altitude2Position(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 8947 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      InrImage::ptr res ( AMIFluid::Func_Altitude2Position(im.get()));
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 8953 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      InrImage::ptr res ( AMIFluid::Func_GeoCoordinates(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 8959 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im.get());
      ADD_VARSTACK(InrImage,res);
    }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 8966 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 451:

/* Line 678 of lalr1.cc  */
#line 8991 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 452:

/* Line 678 of lalr1.cc  */
#line 9009 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));
      InrImage::ptr res( AMIFluid::Func_ReadFlow(filename.get()));
      ADD_VARSTACK_PTR(InrImage,res);
    }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 9016 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 454:

/* Line 678 of lalr1.cc  */
#line 9049 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 455:

/* Line 678 of lalr1.cc  */
#line 9068 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 457:

/* Line 678 of lalr1.cc  */
#line 9104 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Description:
    **/
    // IT IS IMPORTANT TO KEEP CREATING A NEW VARIABLE HERE, TO INCREASE THE SMT PTR COUNTER FOR ASSIGNMENT RULE !!!
    BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->NewReference());
  }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 9115 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
    Description: adds a reference to the variable in the stack
    **/
    BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->NewReference());
  }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 9124 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 471:

/* Line 678 of lalr1.cc  */
#line 9160 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 472:

/* Line 678 of lalr1.cc  */
#line 9222 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 475:

/* Line 678 of lalr1.cc  */
#line 9304 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Logical negation (NOT) operator.
    **/
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(!(*var));
  }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 9312 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Postfix increment operator.
    **/
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar((*var)++);
  }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 9320 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Postfix decrement operator.
    **/
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar((*var)--);
  }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 9328 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Transpose operator, usefull for matrices
    **/
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->Transpose());
  }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 9338 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 480:

/* Line 678 of lalr1.cc  */
#line 9377 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Array subscript operator.
    **/
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)[var2]);
  }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 9391 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Cast operator.
    **/
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->BasicCast( (yysemantic_stack_[(4) - (2)].aint)));

  }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 9400 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    //cout << "T_SUB  cast_var  " << endl;
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(-(*var));
  }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 9406 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(+(*var));
  }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 9411 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(++(*var));
  }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 9416 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(--(*var));
  }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 9421 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_sin());
  }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 9426 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_cos());
  }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 9431 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_sqrt());
  }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 9436 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_fabs());
  }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 9441 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_round());
  }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 9446 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_floor());
  }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 9451 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_tan());
  }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 9456 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_asin());
  }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 9461 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_acos());
  }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 9466 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_atan());
  }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 9471 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_exp());
  }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 9476 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_log());
  }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 9481 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_ln());
  }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 9486 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_norm());
  }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 9496 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)*var2);
  }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 9502 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)/var2);
  }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 9508 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)%var2);
  }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 9519 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    BasicVariable::ptr res(*var1+var2);
    driver.var_stack.AddVar(res);
  }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 9526 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    BasicVariable::ptr res((*var1)-var2);
    driver.var_stack.AddVar(res);
  }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 9541 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)<var2);
  }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 9547 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)>var2);
  }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 9553 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)<=var2);
  }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 9559 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)>=var2);
  }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 9569 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)==var2);
  }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 9575 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)!=var2);
  }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 9616 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Descriptiopn: Logical AND operator
    **/
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)&&var2);
  }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 9629 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Descriptiopn: Logical XOR operator, for vectorial images it defines the pointwise vectorial product.
    **/
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)^var2);
  }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 9642 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Descriptiopn: Logical OR operator
    **/
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)||var2);
  }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 9655 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 531:

/* Line 678 of lalr1.cc  */
#line 9669 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 532:

/* Line 678 of lalr1.cc  */
#line 9679 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    //cout << "assignment_var" << endl;
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1).left_assign(var2));
  }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 9686 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)+=var2);
  }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 9692 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)-=var2);
  }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 9698 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)*=var2);
  }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 9704 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)/=var2);
  }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 9716 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
            GET_VARSTACK_VALUE(GLTransfMatrix,glt);
            GLTransfMatrix* newglt;

            newglt = new GLTransfMatrix();
            (*newglt) = (*glt);
            driver.gltransf_stack.AddMatrix(newglt);
    
        }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 9727 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 540:

/* Line 678 of lalr1.cc  */
#line 9741 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(GLTransfMatrix,glt2);
        GET_VARSTACK_VALUE(GLTransfMatrix,glt1);
        GLTransfMatrix* newglt = NULL;
        float coeff = (yysemantic_stack_[(8) - (7)].adouble);

        newglt = Func_InterpolateTransform(glt1.get(),glt2.get(),coeff);
        driver.gltransf_stack.AddMatrix(newglt);
      }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 9752 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 542:

/* Line 678 of lalr1.cc  */
#line 9770 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
         FloatMatrix::ptr m( new FloatMatrix((int)(yysemantic_stack_[(6) - (3)].adouble),(int)(yysemantic_stack_[(6) - (5)].adouble)));
         ADD_VARSTACK_PTR(FloatMatrix,m);
      }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 9776 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Description: adds a reference to the variable in the stack
        **/
        BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
        driver.var_stack.AddVar(var->NewReference());
      }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 9785 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 546:

/* Line 678 of lalr1.cc  */
#line 9908 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 548:

/* Line 678 of lalr1.cc  */
#line 9929 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 549:

/* Line 678 of lalr1.cc  */
#line 9944 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 550:

/* Line 678 of lalr1.cc  */
#line 9956 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 551:

/* Line 678 of lalr1.cc  */
#line 9978 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 552:

/* Line 678 of lalr1.cc  */
#line 10014 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_OBJECT(SurfacePoly,varsurf)
      SurfacePoly* surf;
      surf = Func_decimate( varsurf.get());
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 10023 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* newsurf;
      GET_VARSTACK_OBJECT(SurfacePoly,varsurf)

      newsurf = Func_decimate( varsurf.get(), (yysemantic_stack_[(6) - (5)].adouble) );
      BasicVariable::ptr res(CreateVar_SurfacePoly(newsurf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 10033 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf;
      GET_VARSTACK_VALUE(InrImage, im);
      surf = Func_vtkMarchingCubes(im.get(),(yysemantic_stack_[(6) - (5)].adouble));
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 10042 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* newsurf;
      GET_VARSTACK_OBJECT(SurfacePoly,surf)

      newsurf = Func_vtkSmooth(surf.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      BasicVariable::ptr res(CreateVar_SurfacePoly(newsurf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 10052 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 557:

/* Line 678 of lalr1.cc  */
#line 10066 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf = new SurfacePoly();
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 10073 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(2) - (2)].astring));
      SurfacePoly* surf = new SurfacePoly();
      surf->Read(filename.get());
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 10082 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 560:

/* Line 678 of lalr1.cc  */
#line 10098 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 561:

/* Line 678 of lalr1.cc  */
#line 10117 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 562:

/* Line 678 of lalr1.cc  */
#line 10137 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 563:

/* Line 678 of lalr1.cc  */
#line 10167 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 564:

/* Line 678 of lalr1.cc  */
#line 10196 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 565:

/* Line 678 of lalr1.cc  */
#line 10214 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 566:

/* Line 678 of lalr1.cc  */
#line 10240 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 567:

/* Line 678 of lalr1.cc  */
#line 10273 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 568:

/* Line 678 of lalr1.cc  */
#line 10309 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 569:

/* Line 678 of lalr1.cc  */
#line 10355 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 570:

/* Line 678 of lalr1.cc  */
#line 10393 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_VARSTACK_VALUE(InrImage,im);
      SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get());
      BasicVariable::ptr res(CreateVar_SurfacePoly(surf));
      driver.var_stack.AddVar(res);
    }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 10402 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 572:

/* Line 678 of lalr1.cc  */
#line 10424 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 573:

/* Line 678 of lalr1.cc  */
#line 10435 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 574:

/* Line 678 of lalr1.cc  */
#line 10446 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 575:

/* Line 678 of lalr1.cc  */
#line 10482 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 576:

/* Line 678 of lalr1.cc  */
#line 10524 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 577:

/* Line 678 of lalr1.cc  */
#line 10570 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 578:

/* Line 678 of lalr1.cc  */
#line 10620 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 579:

/* Line 678 of lalr1.cc  */
#line 10662 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 580:

/* Line 678 of lalr1.cc  */
#line 10693 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 581:

/* Line 678 of lalr1.cc  */
#line 10725 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 589:

/* Line 678 of lalr1.cc  */
#line 10783 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 611:

/* Line 678 of lalr1.cc  */
#line 10863 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      ImageExtent<float>* extent=new ImageExtent<float>( (float)(yysemantic_stack_[(11) - (1)].adouble),(float)(yysemantic_stack_[(11) - (3)].adouble),(float)(yysemantic_stack_[(11) - (5)].adouble),
                          (float)(yysemantic_stack_[(11) - (7)].adouble),(float)(yysemantic_stack_[(11) - (9)].adouble),(float)(yysemantic_stack_[(11) - (11)].adouble));
      extent->SetMode(1); // relative
      BasicVariable::ptr res(CreateVar_ImageExtent(extent));
      driver.var_stack.AddVar(res);
    }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 10872 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      ImageExtent<float>* extent=new ImageExtent<float>((float)(yysemantic_stack_[(7) - (1)].adouble),(float)(yysemantic_stack_[(7) - (3)].adouble),(float)(yysemantic_stack_[(7) - (5)].adouble),(float)(yysemantic_stack_[(7) - (7)].adouble));
      extent->SetMode(1); // relative
      BasicVariable::ptr res(CreateVar_ImageExtent(extent));
      driver.var_stack.AddVar(res);
    }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 10880 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 614:

/* Line 678 of lalr1.cc  */
#line 10898 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 615:

/* Line 678 of lalr1.cc  */
#line 10915 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 11672 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
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
  const short int Parser::yypact_ninf_ = -1912;
  const short int
  Parser::yypact_[] =
  {
      5824, 11793, 11409, 11409,  9873, -1912, -1912, -1912,  9873,  9873,
    9873, -1912, -1912,    48,    85,   104, -1912, -1912, -1912, -1912,
   10257, -1912,   -52,    73, -1912,    49,  9873,  9873,  9873,   125,
    9873, -1912,   172,   189, -1912, -1912, -1912, -1912, -1912, -1912,
   -1912, -1912,    38, -1912, -1912, -1912,    15,    46,     4, -1912,
   -1912, -1912, -1912, -1912,   166,    -2,   238,    13,   203,  1999,
    9873,   224, -1912, -1912, -1912, -1912,   283,   314, 11409, 11409,
     337,   154,   338,   245,   315,   399,   419,   472,   475,   493,
     494,   495,   496,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518, -1912, -1912, -1912, -1912,   521,   522,   523,
     296,   357,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   537,   539,   544,   546,   547,   552,
     554,   555,   556,   558,   559,   560,   561,   471,   562,   563,
     564,   565,   566,   583,   584,   585,   587,   588,   589,   590,
     591,   592,   594,   595,   605,   607,   610,   612,   613,   614,
     615,   616,   617,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   628,   629,   630,   631,   632,   633,   634,   636,
     637,   639,   640,   641,   642,   643,   644,   651,   664,   665,
     667,   668,   670,   671,   672,   673,   674, 10641,   675,   676,
     677,   678,   679,   680, -1912, -1912, -1912, -1912, -1912, -1912,
   -1912, -1912, -1912, -1912, -1912,   681,   682,   683,   684,   685,
   -1912, -1912, 11409, 11409, 11409, 11409, 11409, 11409, 11409, 11409,
   11409, 11409, 11409, 11409, 11409, 11409,   166, -1912,  2619, -1912,
    9873,  7060,  9873,   687,   690,   691,   696,   -13,   166,   700,
     701,   703,   704,   713,   405,   714,   716,   717,   718,   720,
     721,   722,   723,   726,   727,   729,   730,   731,   732,   733,
   -1912, -1912, -1912,   734,   736,   386,  5406, -1912, -1912, -1912,
   -1912, -1912, -1912, -1912,    18, -1912, -1912,   430,   102, -1912,
   -1912, -1912, -1912,    44,   445, -1912,   144,    39, -1912,    25,
      -7,   735, -1912,   737,   648,   747,     1,    45, -1912, -1912,
   -1912, -1912, -1912,    21, -1912,   744, -1912, -1912,  9873,   739,
     740,   745,   748,   756,   757,   754,   755,   146, -1912,   744,
     445,   445,    33,   749, -1912, -1912, -1912, -1912,  9873,  9873,
    9873,  9873, -1912, -1912, -1912, -1912, -1912, -1912, -1912, -1912,
   -1912, -1912, -1912, -1912, -1912, -1912, -1912,  9873, -1912,  2619,
    2619,   367,   442,   697,   698,  9873,   486,   -28,   444, -1912,
     166, -1912,   -26,  9873,   519,  9873, -1912, -1912, -1912, -1912,
   -1912, -1912, -1912, -1912, -1912, -1912, -1912,   748, -1912,   764,
     757, -1912, -1912, -1912, -1912, -1912, -1912, -1912,  2619,  9873,
    9873,   445,   445,  9873,  9873,  9873,  9873,  9873,  9873,  9873,
    9873,    49,  9873,  9873,    49,    49,    49,    49,    49,  9873,
      49,    49,    49,    49,    49,    49,    49,    49,    49,  9873,
    9873,    49,   199,   341,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,  9873,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,  9873,
    9873,  9873,  9873,  9873,  9873,  9873,    49,    49,    49,    49,
      49,    49,    49,    49,    49,   702,   705,    49,    49,    49,
      49,   706,  9873,  9873,  9873,   707,  9873,   708,  9873,  9873,
      49,    49,    49,   725,   741,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,  9873,  9873,  9873,    49,
    9873,  9873,    49,   710,    49,   711,   712,  9873,    49,    49,
    7853, -1912,  9873,  9873,    49,    49,    49,    49,  9873,  9873,
    9873,  9873,    49,   445,   445,   445,   445,   445,   445,   445,
     445,   445,   445,   445,   445,   445,   445,  -100, -1912,   738,
     756, -1912, -1912, -1912,    18, -1912,     7,  9873,  9873,   742,
   -1912, -1912,   769,  9873,  9873,    49,  9873,  9873,   387,  9873,
    9873,  9873,  9873,  9873,  9873,  9873,  9873,  9873,  9873,  9873,
    9873,  9873,   743,    49,    49,    49, -1912, -1912, -1912, -1912,
   -1912, -1912, -1912, -1912, -1912,    18, -1912,   416,  9873,   138,
   -1912, -1912, -1912,  8262,  9873,  9873,  9873,  9873,  9873,  9873,
    9873,  9873,  9873,  9873,  9873,  9873,  9873,  9873,  9873,  9873,
    9873,  9873,  9873,  9873,  9873,  9873,  9873, 11025,  4932,  6242,
    -131,   -88,   -48,  9873,  9873,   645,   646,  9873,   -10,  9873,
   -1912,   776,   786,   787,   184,   782,   789,   792,   794,   796,
     797,   798,   799,   800, -1912, -1912, -1912, -1912, -1912, -1912,
   -1912, -1912, -1912, -1912,   801,   802,   803, -1912,   804,   805,
     806,   807, -1912,   808,   809,   810,   811,   812,   813,   814,
     815,   816,   817,   818, -1912, -1912,   819,   820,   821,   822,
   -1912,   823,   824,   825,   826, -1912, -1912,   827, -1912,   828,
   -1912,   829,   830,   831,   832,   834, -1912, -1912,   833,   835,
    9873,  9873, -1912,   836,   837, -1912,   838, -1912, -1912,  9873,
     839,   841,   842,  9873,   840,   843,   844,   845, -1912,   847,
     846,   849,   848,   853,   852,   855,   854,   851,   856,   857,
     858,   859,   860,   861,   862,   863,   864,   865,   866,   867,
     868,   869,   870,   877,   872,   873,   874,   875,   850, -1912,
   -1912,   883, -1912, -1912,   884,   879,   880,   881,   882,   885,
     886,   887,   888,   889,   890,   897,   898,   899,   894,   901,
     896,   900,   902,   903,   904,   191,   905,   907,   906,   913,
     151,   912,   909,   910,   914,   915,   916,   917,   918,   919,
     920,   921,   922,   929,   924,   931,   215,   926,   927,   928,
     930,   932,   933,   934,   935,   936,   937,   218,   938,   945,
     947,   943,   944,   946,   948,   949,   950,   951,   952,   953,
     954,   958,   959,   966,   969,   970,   971,   985,   987,   989,
     986,   992,   112,   993,   994,   220,   995,  1001,  1002,  1003,
    1010,  1011, -1912,  1006,  1013,  1015,  1016,  1017,  1018,  1019,
    1014,  1020,  1021,  1022,  9873,  9873, -1912, -1912,   -12, -1912,
    1023,  1024,  1025,  1026,  1028,   891,  1030,   455,    18,   222,
    1032,  1039,  1041,  1042,  1050,   232,  1044,  1045,   270,   271,
    1046,  1055,  1057,  1059,  1060,  1067,  1068,  1069,  1064,  1065,
    1066,  1070, -1912, -1912,   278,  1073,  1075, -1912,  1076,  1079,
   -1912, -1912,  9873, -1912,  1080,  1081,  1085,  1086,  1093,  1095,
    1096,  1107,  1108, -1912, -1912, -1912, -1912, -1912, -1912, -1912,
   -1912, -1912, -1912, -1912, -1912, -1912,  1103,   739,   911,   273,
       8,  1110, -1912, -1912, -1912,   144,   144, -1912, -1912, -1912,
   -1912,    25,    25,    -7, -1912,   737,   648,    10,   747, -1912,
   -1912, -1912, -1912, -1912, -1912,  8671, -1912,  7444,  9080,  1111,
     739,   878,   745, -1912,  9489,  1114,  1115,  1116,  1117,  1122,
   -1912, -1912,  2619,   740,   279, -1912, -1912,  1127,  1128,   167,
   -1912,  9873, -1912, -1912,  9873,  9873, -1912, -1912,  9873,  9873,
    9873,  9873,  9873,  9873,    49,  9873,  9873,    42,   893,  1082,
    9873,  9873,  9873,  9873,  9873,  9873,  9873,  9873,  9873,   785,
    9873,  1083,  9873,  9873,   795,  9873,  9873,  9873,  9873,  9873,
     871,   -31,  1087,   977,  9873,  9873,  9873,  9873,  9873, -1912,
   -1912,  9873,   149,  9873, -1912,   758,  9873,   759,  1141,  9873,
   -1912,  1084, -1912, -1912,  9873,  1149, -1912, -1912,  1151, -1912,
    1152,   -23,  9873,  9873, -1912,  9873,  9873,  9873,  9873,  9873,
      49,  9873,  9873,  9873,  9873,  9873,  9873, -1912,  9873,  9873,
    9873,    49,    49,    49, -1912,  9873,  9873,  9873,  9873,  9873,
    9873,  9873,  9873,    49,  9873, -1912, -1912, -1912,    49, -1912,
      49,    49,    49,    49,    49, -1912,    49,    49, -1912,  9873,
   -1912,  9873,  1155,  9873,  9873,  9873,  9873,  9873,  9873,  9873,
    9873,  9873,  9873,  9873, -1912,  9873, -1912, -1912,  9873,  9873,
    9873,  9873,  9873,  9873,  9873,  9873,  9873,  9873,    49, -1912,
    9873,  9873, -1912, -1912,    49,    49,    49,    49,    49,  9873,
    9873,  9873,  9873,  9873,  9873,  9873,  9873,  9873,  9873,  9873,
   -1912, -1912, -1912,  9873,  9873, -1912,  9873,  9873, -1912,  9873,
    9873,  9873,  9873,  9873, -1912, -1912,  9873, -1912, -1912, -1912,
   -1912, -1912, -1912,  9873,  9873,  9873, -1912,   520,  1150, -1912,
   -1912, -1912, -1912, -1912, -1912, -1912,  9873, -1912,  -208,  -208,
    1092, -1912, -1912,  9873,  9873,    49,  9873,  9873,    49, -1912,
    9873,  9873,  9873, -1912,  9873, -1912,  9873,  9873,  9873,  9873,
    9873,  9873, -1912, -1912, -1912,  9873,  9873,    49,    49,  9873,
    9873,  9873, -1912,  9873,  9873,    49, -1912,    49,    49,  9873,
    9873,  9873,  9873,  9873,  9873,  9873,  1153,  9873,    64, -1912,
   -1912,  9873,  9873, -1912, -1912,  9873,  9873,  -161,  9873,  1094,
    9873,  9873,  9873,  9873, -1912, -1912,  6651, -1912, -1912,  1154,
    1156,  1157,  1159,   155,  1160,  1162,  1163,  1158,  1164,  1173,
    1170,  1177,  1181,  1183,  1179,  1182,  1185,  1186,  1188,  1189,
    1200,  1195,  1197,  1198,  1199,  1206,  1208,  1216,  1211,   299,
    1218,  1219,  1215,  1221,  1224,  1225,  1222,  1220,   300,  1232,
    1227,  1228,  1229,  1236,  1237,  1233,  1238,  1241,  1243,  1244,
     354,  1161,  9873, -1912,  1249,  1251,  1252,  9873,    49,    49,
     302,  1247,  1248,  1255,  1256,  1257,  1258,  1253,  1260,   309,
    1259,  1261,  1262,  1263,  1264,  1265,  1266,  1267,  1268,  1269,
    1270,  1271,  1272,  1273,  1274,  1275,  1276,  1277,  1278,  1279,
    1286,  1287,  1282,  1283,  1284,  1285,  1288,  1289,  1292,  1293,
    1290,  1297,  9873,  1298,  1299,  1300,  1295,  1296,  1301,  1302,
     311,  1303,  1304,  1305,  1306,  1307,  1311,  1314,  1315,  1316,
    1317,  1312,  1313,  1318,  1319,  1320,  1321,  1322,  1323,  1324,
    1325,  1326,  1327,  1328,  1329,  1336,  1337,  1338,  1339,  1341,
    1342,  1343,   312,  1340,  1344,  1345,   324,  1347,  1348,  1349,
    1352,  1353,  1350,  1354,  1351,  1355,  1356,  9873,  9873,    18,
      18,  1357,   908,  1217,  1310,  1330,  1331,  1332,   325,   328,
   -1912,  1358,  1359,  1360,  1364,  1361,  1362,   329,  1363,  1365,
    1370,  1372,  1367,  1368,  1373,  1374,  1378,  1375,  1383,  1379,
    1380,    31,  1381,  1384,  1388,  1385,   360,  1389,  1390,  1386,
     187,  1387,   207,  1394,   363,  1391,  1392,   364,  1393,  1395,
   -1912, -1912,  1242,  1398,  1396, -1912,  1400,  1397,  1404,  1405,
    1401, -1912,  2619, -1912, -1912,  9873,  9873, -1912,    49,  9873,
    9873,  9873,  9873, -1912,  9873, -1912,  9873, -1912, -1912, -1912,
      49,    49,  9873,  9873,  9873, -1912, -1912,  9873,  9873,  9873,
    9873, -1912,  9873, -1912,  9873, -1912,  9873, -1912, -1912,  9873,
    9873,  9873,  9873, -1912,   618, -1912,  9873, -1912,    49,  9873,
    9873, -1912, -1912,  9873, -1912, -1912, -1912,  1366, -1912, -1912,
   -1912, -1912, -1912, -1912,  1406,  1409,   365, -1912,   -45,   -21,
    9873, -1912, -1912, -1912, -1912,  9873, -1912, -1912,    49,  9873,
    9873,  9873,  9873,  9873,  9873,  9873,  9873,  9873,  9873,  9873,
    9873,  9873,  9873,  9873,  9873,  9873,  9873,  9873,  9873, -1912,
   -1912,  9873,    49,    49,    49,    49,    49, -1912, -1912,  9873,
   -1912,  1410, -1912, -1912, -1912,  9873,  9873,  9873,  9873, -1912,
    9873,  9873,  9873, -1912,  9873,  9873, -1912, -1912, -1912, -1912,
   -1912,  9873,  9873,  9873,  9873,  9873, -1912, -1912, -1912,  9873,
    9873,    49,    49,  9873,  9873, -1912, -1912, -1912, -1912, -1912,
   -1912, -1912, -1912,  9873,  9873,  9873,  9873, -1912,    49, -1912,
   -1912, -1912, -1912, -1912,  9873, -1912,  9873,  9873,  9873,   606,
   -1912, -1912, -1912,  9873, -1912, -1912, -1912, -1912, -1912, -1912,
   -1912,  -195, -1912,    18, -1912,  9873,  9873, -1912,  9873,  9873,
   -1912,  9873,  9873,  9873, -1912, -1912,  9873,  9873,  9873,  9873,
   -1912,  9873, -1912,    49,  9873, -1912,  9873,  9873,  9873, -1912,
   -1912,  9873, -1912,  9873, -1912, -1912,  9873, -1912,  9873, -1912,
   -1912, -1912,  9873,  9873,  9873, -1912,  9873,  9873,  9873, -1912,
   -1912, -1912, -1912,  1196,  1408,  1411,  1369, -1912,  1412,  1413,
     214,  1414,  1415,  1416,  1418,  1417,  1421,  1420,  1424,  1427,
    1428,  1429,  1425,  1430,  1433,  1431,  1432,  1434,  1435,  1442,
    1437,  1438,  1439,  1440,  1447,  1448,  1449,  1444,  1445,  1452,
   -1912, -1912, -1912,  9873,  1453,  1451,   373,  1454,  1457,  1459,
    1458,   374,   375,   376,   402,  1460,  1467,  1469,   403,   159,
    1470,  1471,  1472,  1473,   406,  1477,  1478,  1483,  1485,  1487,
    1489,  1496,  1495,  1497,  1499,  1500,  1502,  1503,  1504, -1912,
    1512,  1513,   411,   413,  1508,  1515,  1510,  1511,  1514,  1516,
    1517,  1518,  1519,  1520,  1521,  1527,  1523,  1524,  1525,  1526,
    1528,  1535,  1530,  1552,  1554,  1561,  1562,  1563,  1558,  1559,
    9873,    18,  1560,    18,  1371,  1474,  1532,  1536,  1539,  1540,
      18, -1912,  1564,  1565,  1568,  1566,  1569,  1580,  1587,  1582,
    1588,  1593,  1589,  1590,  1594,  1597,   140,  1604,  1422,  1605,
    1601,  1602,  1603,  1609,  1610,  1611,  1612,  1426,  1446,  1613,
    9873,  9873,  1620, -1912,  9873, -1912,  9873, -1912,  9873, -1912,
    9873, -1912,  9873, -1912, -1912, -1912, -1912,  9873,  9873, -1912,
    9873,  9873,  9873,  9873, -1912,  9873,  9873,  9873,  9873, -1912,
   -1912, -1912,  9873,  9873, -1912,  1621, -1912,   990, -1912,   -45,
    1476,  9873,  9873, -1912, -1912,  9873, -1912,  9873, -1912,  9873,
   -1912,  9873,  9873,  9873,  9873, -1912,  9873,  9873,  9873,  9873,
    9873,  9873, -1912,  8262,  8262,  8262,  9873,  9873,  9873,  9873,
   -1912,  9873,  9873,  9873,  9873,  9873,    49,  9873, -1912, -1912,
   -1912,  9873, -1912,  9873,  9873, -1912,  9873,  9873,  9873,  9873,
    9873,  9873,  9873,  9873, -1912, -1912,  9873,    49,    49,  9873,
    9873, -1912,  9873,  9873,  9873, -1912, -1912, -1912,  9873,  9873,
   -1912, -1912,  9873, -1912, -1912, -1912, -1912, -1912, -1912, -1912,
   -1912,  9873,  9873, -1912,  9873, -1912,  9873, -1912,  9873,  9873,
   -1912,  9873,  9873,    49,  9873, -1912,  9873,  9873, -1912,  9873,
   -1912,  9873,  9873,  9873,  9873,  9873,  9873,  9873,  9873,  9873,
    9873, -1912, -1912, -1912,   414,  1622,   436,  1617,  1628,  1623,
    1624,  1632,  1627,  1629,  1634,  1630,  1631,  1633,  1638,  1635,
    1640, -1912,  1642,   437,  1639,  1646,   438,   439,  1647,  1648,
    1651,  1652,  1660,  1655,  1657,  1661,  1662,  1663,  1664,   133,
    1672,   483,  1673,  1675,  1671,  1677,  1681,  1682,  1683,  1684,
    1685,  1686,  1687,   447,  1689,  1678,   448,  1679,  1690,  1691,
    1698,  1699,  1694,  1695,  1702,  1697,  1700,   449,  1701,  1704,
     450,  1705,  1708,  1709,  1710,  1711,    18,  1706,  1707,  1712,
    1714,  1713,  1715,  1716,  1717,  1718,  1719,  1720,  1727,  1728,
    1723,  1724,  1732,  1733,  1734,  1735,  1736,  1737, -1912,  1738,
    1739, -1912,  9873, -1912, -1912,  9873,  9873, -1912,  9873,  9873,
   -1912,  9873,  9873, -1912,  9873,  9873,  9873, -1912,  9873, -1912,
   -1912, -1912,   -45,  9873,  9873, -1912,  9873, -1912,  9873,  9873,
    9873,  9873,  9873, -1912,  9873,  9873,  9873,  9873,  9873,  9873,
    8262, -1912,  8262, -1912, -1912,  8262,  8262,  9873,  9873,  9873,
      49,    49,    49,    49, -1912,  9873,  9873, -1912, -1912,  9873,
   -1912,  9873,  9873, -1912, -1912,  9873,  9873, -1912,  9873,  9873,
   -1912,  9873,    49, -1912, -1912,  9873, -1912, -1912, -1912, -1912,
   -1912, -1912,  9873,  9873,  9873, -1912,  9873,  9873,  9873,  9873,
    9873,    49,  9873, -1912, -1912,  9873,  9873, -1912, -1912, -1912,
   -1912, -1912, -1912,  9873, -1912,  1740,  1741,  1742,  1743,  1744,
    1745,  1746,  1748,  1749,  1753,  1750,  1754,  1755,  1751,  1758,
    1759,  1760,  1761,  1762,  1757,   451,  1764,  1763,  1765,  1766,
    1767,  1768,  1770,  1771,  1772,  1769,  1774,  1776,  1777,  1778,
    1773,  1775,  1780,  1779,  1782,  1783,  1781,  1784,  1785,  1786,
    1787,  1788,  1789,  1794,  1790,  1797,  1793,   458,  1795,  1796,
    1798,  1799,  1800,  1801,  1494,  1803,  1730, -1912,  9873, -1912,
   -1912,  9873,  9873,  9873, -1912, -1912, -1912,  9873, -1912, -1912,
    9873, -1912, -1912, -1912, -1912, -1912,  9873, -1912,  9873, -1912,
    9873, -1912, -1912,  9873, -1912, -1912, -1912, -1912,  8262, -1912,
   -1912, -1912, -1912,  9873,  9873, -1912,  9873, -1912, -1912,  9873,
    9873,  9873,  9873,  9873, -1912,    49, -1912,  9873, -1912,  9873,
   -1912,  9873,  9873,  9873,  9873,  9873,    49,  9873,  9873, -1912,
    9873,  1808,  1804,  1805,  1806,  1807,  1809,  1814,  1816,  1817,
    1812,  1819,  1815,  1818,  1820,  1821,  1822,  1823,   459,  1824,
    1825,  1826,  1827,  1828,   460,  1835,  1830,  1831,  1832,  1833,
    1840, -1912, -1912,  9873,  9873,  9873,  9873,  9873, -1912, -1912,
   -1912,  9873, -1912,  9873,  9873, -1912,  9873,  9873,  9873, -1912,
    9873,  9873,    49,  9873,  9873,  9873, -1912,  9873, -1912,  9873,
    9873,    49,  9873,  1201,  1841,  1843,  1839,  1847,  1849,  1851,
    1852,  1848,   461,  1853,  1861,  1862,  1863,   462,  1866,  1867,
    1857,   463,   473,  1868,  1869,  1870,  9873, -1912, -1912,  9873,
   -1912, -1912, -1912, -1912,  9873, -1912,  9873, -1912,  9873,  9873,
    9873, -1912,  9873,  9873,  9873, -1912, -1912,  9873, -1912,  9873,
    9873,  9873,  9873, -1912,  1871,  1872,  1881,  1882,  1878,  1886,
    1888,  1893,  1894,  1903,  1908,  1910,  1911,  1912,  9873,  9873,
   -1912, -1912,  9873, -1912, -1912, -1912,  9873, -1912,  9873,  9873,
    9873,    49,  1913,  1920,  1921,  1916,  1923,  1924,  1926,  1927,
    9873, -1912, -1912,  9873, -1912, -1912,  9873,    49,  1929,  1930,
    1933,  1937,  9873,  9873,  9873,  9873,  1938,  1939,  1942,  1949,
    9873,  9873,  9873, -1912,  1945,  1946,  1947,  9873,  9873,  9873,
    1954,  1950,  1951, -1912,  9873,  9873,  1955,  1958, -1912, -1912
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  Parser::yydefact_[] =
  {
         2,     0,     0,     0,     0,    21,    69,    70,     0,     0,
       0,    73,    74,     0,     0,     0,   249,   254,    41,    20,
       0,   332,     0,    92,    79,     0,     0,     0,     0,     0,
       0,    91,     0,     0,   243,   253,   582,   327,   465,   462,
     463,   458,   591,   461,   464,   545,   593,   543,   594,   584,
     585,   587,   586,   588,   595,   460,   583,   592,   596,     0,
       0,     0,    43,    46,    44,    45,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   209,   210,   245,   211,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,     0,     0,     0,     0,     0,
     255,   256,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   251,     0,    42,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     215,   216,   217,     0,     0,     0,     0,     4,     8,    10,
      14,    16,    18,    12,     0,   459,   466,     0,   336,   456,
     467,   468,   469,   474,   481,   501,   505,   508,   509,   514,
     517,   519,   520,   522,   524,   526,   528,   530,   537,    40,
     470,   457,   547,     0,   597,   590,   598,    39,     0,     0,
       0,     0,   460,     0,     0,     0,     0,   336,   475,     0,
     484,   483,     0,     0,    71,   312,    72,    75,     0,     0,
       0,     0,   329,   314,    82,    85,    80,    98,    95,    96,
      97,    94,    93,    81,   101,   102,   103,     0,    90,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    35,
       0,   136,     0,     0,     0,     0,   603,   601,   602,   606,
     591,   604,   605,   593,   607,   594,   595,   600,   583,   592,
     596,   608,   599,   590,   609,   610,    87,    88,     0,     0,
       0,   485,   486,     0,     0,     0,     0,     0,     0,     0,
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
       0,   558,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   487,   488,   493,   494,   495,   496,   497,
     499,   498,   489,   490,   491,   492,   500,     0,    25,     0,
     592,   251,   251,    37,     0,    38,     0,     0,     0,     0,
      31,    29,   251,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     3,     5,     9,
      11,    15,    17,    19,    13,     0,     6,     0,     0,     0,
     476,   477,   478,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   223,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     473,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   298,   299,   296,   297,   294,   295,
     300,   301,   302,   411,     0,     0,     0,   107,     0,     0,
       0,     0,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   409,   410,     0,     0,     0,     0,
     171,     0,     0,     0,     0,   176,   177,     0,   160,     0,
     168,     0,     0,     0,     0,     0,   157,   158,     0,     0,
       0,     0,   104,     0,     0,    68,     0,   589,   213,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   313,     0,
     313,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   145,
     146,     0,   147,   148,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     336,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   336,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   557,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   252,    26,     0,    36,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,   308,     0,   312,     0,   246,     0,     0,
     134,   135,     0,   150,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   326,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,     0,   615,     0,   336,
     474,     0,   502,   503,   504,   506,   507,   511,   510,   512,
     513,   515,   516,   518,   521,   523,   525,     0,   527,   532,
     533,   534,   535,   536,   531,     0,    57,     0,     0,     0,
     591,   593,   594,   538,     0,     0,   316,   319,     0,    51,
      59,    53,     0,   593,     0,   228,   224,     0,     0,     0,
     482,     0,    77,    78,     0,     0,   247,   248,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    99,
     100,     0,     0,     0,   214,   546,     0,   328,     0,     0,
      47,     0,   281,   283,     0,     0,   284,   285,     0,   286,
       0,     0,     0,     0,   369,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   370,     0,     0,
       0,     0,     0,     0,   392,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   354,   355,   356,     0,   358,
       0,     0,     0,     0,     0,   365,     0,     0,   277,     0,
     282,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   372,     0,   561,   562,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   559,
       0,     0,   330,   331,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     436,   203,   204,     0,     0,   279,     0,     0,   552,     0,
       0,     0,     0,     0,   350,   352,     0,   544,   405,   406,
     407,   408,   293,     0,     0,     0,   206,     0,   251,   221,
     250,   251,    27,   305,   306,   307,     0,   208,   230,   230,
       0,    33,   440,     0,     0,     0,     0,     0,     0,   570,
       0,     0,     0,   447,     0,   449,     0,     0,     0,     0,
       0,     0,   451,   452,   153,     0,     0,     0,     0,     0,
       0,     0,   437,     0,     0,     0,   149,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   480,
     479,     0,     0,    50,    49,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   226,   472,     0,   546,   328,     0,
       0,     0,     0,   336,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    89,     0,     0,     0,     0,     0,     0,
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
     251,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     336,     0,   336,     0,     0,     0,     0,     0,     0,     0,
     614,   529,     0,     0,     0,   539,     0,     0,     0,     0,
       0,    52,     0,   229,   225,     0,     0,   244,     0,     0,
       0,     0,     0,   130,     0,   133,     0,   106,   109,   108,
       0,     0,     0,     0,     0,   117,   118,     0,     0,     0,
       0,   123,     0,   132,     0,   161,     0,   156,   163,     0,
       0,     0,     0,   159,     0,   169,     0,   164,     0,     0,
       0,   167,   303,     0,   309,   310,   311,     0,    60,    61,
      58,    86,    48,   471,     0,     0,     0,   342,     0,     0,
       0,   368,   371,   373,   374,     0,   375,   201,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   276,
     353,     0,     0,     0,     0,     0,     0,   366,   367,     0,
     292,     0,   337,   338,   339,     0,     0,     0,     0,   184,
       0,     0,     0,   190,     0,     0,   564,   412,   413,   414,
     415,     0,     0,     0,     0,     0,   560,   455,   421,     0,
       0,     0,     0,     0,     0,   426,   427,   428,   429,   430,
     431,   432,   433,     0,     0,     0,     0,   548,     0,   549,
     553,   554,   555,   556,     0,   542,     0,     0,     0,   251,
     222,    24,    28,     0,   234,   235,   236,   231,   233,   232,
     251,     0,   251,     0,   441,     0,     0,   442,     0,     0,
     571,     0,     0,     0,   446,   448,     0,     0,     0,     0,
     450,     0,   212,     0,     0,   257,     0,     0,     0,   263,
     144,     0,   143,     0,   151,   152,     0,   197,     0,   199,
     200,   139,     0,     0,     0,   137,     0,     0,     0,    55,
      56,   541,    54,     0,    64,    62,     0,   227,     0,     0,
     336,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     287,   288,   289,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   336,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   291,
       0,     0,     0,     0,     0,   312,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    34,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    76,     0,   335,     0,   125,     0,   128,
       0,   131,     0,   112,   110,   113,   115,     0,     0,   120,
       0,     0,     0,     0,   162,     0,     0,     0,     0,   170,
     165,   178,     0,     0,    67,     0,   343,     0,   344,     0,
       0,     0,     0,   202,   378,     0,   381,     0,   383,     0,
     385,     0,     0,     0,     0,   416,     0,     0,     0,     0,
       0,     0,   393,     0,     0,     0,     0,     0,     0,     0,
     403,     0,     0,     0,     0,     0,     0,     0,   340,   341,
     179,     0,   181,     0,     0,   185,     0,     0,     0,     0,
       0,     0,     0,     0,   454,   422,     0,     0,     0,     0,
       0,   434,     0,     0,     0,   550,   551,   205,     0,     0,
     251,    22,     0,    32,   240,   241,   242,   238,   239,   237,
      30,     0,     0,   445,     0,   572,     0,   573,     0,     0,
     220,     0,     0,     0,     0,   258,     0,     0,   262,     0,
      83,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    65,    63,    66,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   290,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   613,   612,
       0,   333,     0,   124,   126,     0,     0,   105,     0,     0,
     122,     0,     0,   155,     0,     0,     0,   175,     0,   304,
     345,   346,     0,     0,     0,   377,     0,   380,     0,     0,
       0,     0,     0,   351,     0,     0,     0,     0,     0,     0,
       0,   394,     0,   396,   398,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   363,     0,     0,   180,   182,     0,
     186,     0,     0,   195,   563,     0,     0,   567,     0,     0,
     194,     0,     0,   423,   424,     0,   435,   278,   280,   438,
     439,    23,     0,     0,     0,   349,     0,     0,     0,     0,
       0,     0,     0,   260,   261,     0,     0,   196,   198,   140,
     141,   259,   138,     0,   540,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   334,     0,   129,
     116,     0,     0,     0,   172,   173,   174,     0,   347,   348,
       0,   379,   382,   384,   386,   389,     0,   418,     0,   420,
       0,   387,   390,     0,   395,   397,   399,   400,     0,   402,
     357,   359,   360,     0,     0,   364,     0,   183,   189,     0,
       0,     0,     0,     0,   193,     0,   425,     0,   443,     0,
     574,     0,     0,     0,     0,     0,     0,     0,     0,   142,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   611,   127,     0,     0,     0,     0,     0,   388,   419,
     417,     0,   401,     0,     0,   404,     0,     0,     0,   569,
       0,     0,     0,     0,     0,     0,   578,     0,   579,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   119,   121,     0,
     166,   376,   391,   361,     0,   187,     0,   565,     0,     0,
       0,   192,     0,     0,     0,   575,   576,     0,   580,     0,
       0,     0,     0,    84,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     188,   566,     0,   207,   191,   453,     0,   577,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   362,   568,     0,   581,   154,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   219,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   111,     0,     0,     0,     0,   444,   218
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
     -1912, -1912, -1912,  -210,   652,   653,   972, -1912, -1912,  1012,
    1054,  1077,  1207, -1912, -1912,    88, -1912,  -499, -1912, -1912,
   -1912,    -8,  2491,   223,    23,  2156, -1912, -1912, -1912, -1912,
       6,   186,  -495,  -286, -1912,  -352,  -263,   753, -1912,   728,
     752,   765,  1052,  1120,   100,  -117,  2969,   259, -1912,   -55,
      32,   -14, -1912,     3,  1112,     5, -1912,  -222, -1911
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,   265,   266,   267,   268,   269,   270,   866,   865,   271,
     272,   273,   274,  1178,   974,  1428,   275,   538,   539,  1180,
     276,   928,   717,   511,   277,   317,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   325,   970,   300,   301,
     302,   303,   304,   319,   306,   384,   385,   386,   931
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char Parser::yytable_ninf_ = -1;
  const unsigned short int
  Parser::yytable_[] =
  {
       324,   326,   327,   305,   382,   307,   541,   318,    37,   342,
     959,     5,  2050,  2052,  2053,    37,   854,   360,   700,   701,
     708,   543,   609,   357,  1239,    19,   334,   322,   363,   314,
     599,   600,  1241,  1320,   352,  1756,   314,    37,  1297,    37,
     359,     5,   857,   858,   897,  1685,    36,   629,   963,   597,
     598,  1686,   587,   868,  1687,    19,   578,   351,   314,   355,
     314,   328,   383,   550,   586,   356,    36,    37,   366,   367,
     368,   369,   370,   371,   372,    45,   373,   374,   375,    49,
      50,    51,    52,    53,   376,   377,   378,   540,   380,   644,
     645,   646,   647,   648,   649,   650,   651,   652,   329,   932,
     933,   934,    37,   674,   675,   603,   604,  1272,   364,    37,
     610,   353,   354,   590,   591,   588,   617,   330,   897,   610,
     358,   589,   592,   314,  1475,   627,  1155,   636,   637,   337,
     314,   628,    36,   653,   980,   601,   602,   618,   347,   709,
     611,   612,   613,   614,   615,   338,   339,   340,   341,   590,
     591,   594,   595,  2150,  1995,  1237,   596,  1470,   592,   627,
    1996,   616,   361,  1997,   627,   628,   714,   394,   627,   395,
     628,  1101,   627,   382,   628,  1489,   674,   675,   628,  1917,
    1422,  1423,  1424,  1425,  1426,   349,  1427,  1219,   320,   321,
    1221,   896,   897,  1824,  1825,  1826,  1827,  1828,   629,  1829,
     627,  1697,   350,   587,   984,  1095,   628,   141,   142,   143,
    1307,  1096,   537,  1308,   148,   149,   150,   151,   365,   153,
     627,  1699,   542,   551,   552,    36,   628,   627,  1865,  1117,
     898,   383,  1129,   628,  1158,  1118,  1192,   388,  1130,  2241,
    1159,  2242,  1193,   332,  2243,  2244,  1199,   937,   938,   939,
     940,   346,  1200,   348,   391,   392,   965,   362,   397,   178,
     398,   855,   179,   180,   181,   182,   183,   184,   899,   305,
     187,   307,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   387,  1203,  1205,   627,   911,   703,   704,
    1204,  1206,  1238,  1255,   382,   382,   389,   900,  1219,  1256,
    1220,  1221,   901,   902,   903,   904,   905,   702,   703,   704,
     705,   935,   936,  1515,  1525,   422,  1547,   335,   913,  1516,
    1526,   632,  1548,  1557,   861,  1599,  1632,   390,   399,  1558,
     400,  1600,  1633,   382,   859,   906,   907,   908,  1637,  1660,
     941,   942,  1662,  1670,  1638,  1661,   707,   698,  1661,  1671,
     393,   396,   383,   383,   634,   710,  1181,   712,   748,   749,
     750,   911,   914,   915,   916,   917,   918,   919,   920,   921,
     922,   923,   924,   925,  1692,   892,   423,  1701,  1705,  1752,
    1693,   715,   716,  1702,  1706,  1753,   576,  1898,  1904,  1906,
    1908,   383,   913,  1899,  1905,  1907,  1909,  2351,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   401,   245,   246,   247,  1910,  1915,   250,   251,
    1922,   253,  1911,  1916,   558,  1940,  1923,  1942,  2111,   909,
     910,  1941,   402,  1943,  2112,   911,   914,   915,   916,   917,
     918,   919,   920,   921,   922,   923,   924,   925,   912,   587,
    2114,  2131,  2135,  2137,   544,   545,  2115,  2132,  2136,  2138,
     593,  2164,  2168,  2180,  2184,  2297,   913,  2165,  2169,  2181,
    2185,  2298,  2330,  2389,  2396,  2435,  2441,  2446,  2331,  2390,
    2397,  2436,  2442,  2447,   449,   403,   450,  2448,   404,   828,
     829,   382,   831,  2449,   949,   950,   951,   952,   953,   954,
     751,   752,   753,  2152,   843,  1237,   405,   406,   407,   408,
     914,   915,   916,   917,   918,   919,   920,   921,   922,   923,
     924,   925,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   860,   322,   419,   420,   421,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   383,
     436,   631,   437,   633,   141,   142,   143,   438,   882,   439,
     440,   148,   149,   150,   151,   441,   153,   442,   443,   444,
     635,   445,   446,   447,   448,   451,   452,   453,   454,   455,
     894,   638,   639,   640,   641,   642,   643,   644,   645,   646,
     647,   648,   649,   650,   651,   652,   456,   457,   458,   930,
     459,   460,   461,   462,   463,   464,   178,   465,   466,   179,
     180,   181,   182,   183,   184,   977,   978,   187,   467,   979,
     468,   305,   305,   469,   976,   470,   471,   472,   473,   474,
     475,   653,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,  1182,   492,
     493,   654,   494,   495,   496,   497,   498,   499,  1191,   655,
     656,   657,   658,   659,   500,   660,   661,   662,   663,   664,
     665,   666,   667,   668,   669,   670,   671,   501,   502,  1419,
     503,   504,  1420,   505,   506,   507,   508,   509,   512,   513,
     514,   515,   516,   517,   518,   519,   520,   521,   522,   807,
     546,   809,   810,   547,   548,  1038,   674,   675,   676,   549,
     677,   678,   679,   553,   554,   680,   555,   556,   681,   682,
     683,   684,   685,   686,   687,   688,   557,   559,   689,   560,
     561,   562,   690,   563,   564,   565,   566,   691,   692,   567,
     568,   849,   569,   570,   571,   572,   573,   574,   693,   575,
    1254,   608,   605,   694,   695,   606,   607,   619,   620,   621,
     245,   246,   247,   630,   622,   250,   251,   360,   253,   672,
     862,   623,   624,   625,   626,   696,   697,   699,   706,   713,
     796,   814,   711,   797,   802,   806,   808,   673,   835,   837,
     838,   867,   874,   886,   887,   856,   981,   815,   864,   893,
     982,   983,   985,   986,   748,   751,   987,   988,   888,   989,
     990,   991,   992,   993,   994,   995,   996,   997,   998,   999,
    1000,  1001,  1002,  1003,  1004,  1005,  1006,  1007,  1008,  1009,
    1010,  1011,  1012,  1013,  1014,  1015,  1016,  1017,  1018,  1019,
    1020,  1021,  1022,  1023,  1024,  1025,  1177,  1026,  1028,  1031,
    1032,  1033,  1190,  1027,  1285,  1035,  1036,  1040,  1037,  1042,
    1039,  1043,  1046,  1072,  1041,  1045,  1044,  1047,  1048,  1049,
    1050,  1051,  1054,  1290,  1310,  1312,  1052,  1053,  1417,  1055,
    1056,  1057,  1058,  1059,  1060,  1061,  1062,  1063,  1064,  1065,
    1066,  1067,  1068,  1069,  1070,  1071,  1073,  1247,  1074,  1075,
    1076,  1077,  1078,  1475,  1188,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,   382,   579,   580,
    1091,  1098,  1092,  1093,  1094,  1097,  1099,  1100,  1102,  1103,
    1104,  1663,  1034,  1237,  1105,  1106,  1107,  1108,  1109,  1110,
    1111,  1112,  1113,  1114,  1115,  1116,  1119,  1120,  1121,  1296,
    1122,  1274,  1123,  1124,  1125,  1126,  1127,  1128,  1131,  1132,
     305,  1133,  1244,  1134,  1135,  1820,  1136,  1654,  1137,  1138,
    1139,  1140,  1141,  1142,  1143,   383,  1260,  1261,  1144,  1145,
    1262,  1264,  1265,  1266,  1267,  1268,  1146,  1270,  1271,  1147,
    1148,  1149,  1276,  1277,  1278,  1279,  1280,  1281,  1282,  1150,
    1284,  1151,  1286,  1152,  1288,  1289,  1153,  1291,  1292,  1293,
    1294,  1295,  1154,  1156,  1157,  1160,  1301,  1302,  1303,  1304,
    1305,  1161,  1162,  1163,  1164,  1165,  1166,  1167,  1311,  1168,
    1169,  1170,  1171,  1172,  1173,  1300,  1176,  1183,  1184,  1185,
    1174,  1175,  1187,  1189,  1322,  1323,  1186,  1324,  1325,  1326,
    1327,  1328,  1194,  1330,  1331,  1332,  1333,  1334,  1335,  1195,
    1336,  1196,  1197,  1198,  1201,  1202,  1207,  1342,  1343,  1344,
    1345,  1346,  1347,  1348,  1349,  1208,  1351,  1209,  1179,  1210,
    1211,  1212,  1213,  1214,  1215,  1216,  1217,  1222,  1223,  1224,
    1218,  1360,  1225,  1227,  1228,  1363,  1364,  1365,  1229,  1230,
    1368,  1369,  1370,  1371,  1372,  1373,  1231,  1374,  1232,  1233,
    1375,  1376,  1377,  1378,  1379,  1380,  1381,  1382,  1383,  1384,
    1234,  1235,  1386,  1236,  1246,  1226,  1240,  1249,  1250,  1251,
    1252,  1393,  1394,  1395,  1396,  1397,  1398,  1399,  1400,  1401,
    1402,  1403,  1253,  1257,  1258,  1404,  1405,  1275,  1406,  1407,
    1821,  1408,  1409,  1410,  1411,  1412,  1299,  1313,  1413,  1287,
    1315,  1823,  1317,  1830,  1318,  1319,  1415,  1416,  1362,  1430,
    1418,  1487,  1493,  1477,  1485,  1468,  1486,  1539,  1421,  1488,
    1490,   332,  1491,  1492,  1494,  1431,  1432,  1495,  1434,  1435,
    1496,  1497,  1437,  1438,  1439,  1498,  1440,  1499,  1441,  1500,
    1443,  1444,  1501,  1505,  1259,  1502,  1503,  1447,  1504,  1651,
    1652,  1451,  1452,  1453,  1506,  1507,  1455,  1508,  1509,  1510,
    1511,  1459,  1461,  1463,  1464,  1465,  1466,  1467,  1512,  1469,
    1513,  1514,  1517,  1518,  1472,  1519,  1523,  1473,   581,  1524,
    1476,  1520,  1478,  1479,  1521,  1522,  1527,  1528,  1529,  1530,
    1531,  1532,  1534,  1533,  1306,  1535,  1309,  1536,  1709,   305,
    1717,  1484,  1314,  1541,  1537,  1542,  1543,  1549,  1550,  1551,
    1552,  1553,  1554,  1555,  1556,  1859,  1655,  1429,   582,  1559,
    1298,  1560,  1561,  1562,  1563,  1564,  1565,  1566,  1567,  1568,
    1569,  1570,  1571,  1572,  1573,  1574,  1575,  1576,  1577,  1578,
    1579,  1580,  1581,  1582,  1583,  1584,  1587,  1588,  1585,  1586,
    1589,  1590,  1592,  1593,  1594,  1595,  1596,  2426,   913,  1603,
     583,  1597,  1598,  1601,  1602,  1606,  1604,  1605,  1607,  1608,
    1609,  1610,  1611,  1612,   944,  1616,  1617,  1618,  1613,  1614,
    1615,  1471,  1538,   584,  1619,  1620,  1621,  1622,  1623,  1624,
    1625,  1626,  1627,  1628,  1387,  1629,  1630,  1631,   943,   945,
    1634,  1639,  1640,  1641,  1635,  1636,  1642,  1643,  1645,  1656,
    1644,  1646,  1664,   946,     0,  1647,  1648,  1653,  1667,  1665,
    1666,  1668,  1669,  1672,  1674,  1673,  1675,  1676,  1677,  1657,
    1658,  1659,  1680,  1678,  1679,  1681,  1414,  1682,  1689,  1683,
    1684,  1688,  1690,  1694,  1695,  1691,  1696,  1698,  1700,  1649,
    1711,  1703,  1704,  1707,  1710,  1708,  1712,  1713,  1714,  1715,
    1750,  1716,  1749,  1751,  1789,  1862,  1863,   382,  1860,  1867,
    1974,  1861,  1869,  1864,  1866,  1871,  1868,  1870,  1873,  1448,
    1872,  1874,  1875,  1876,  1999,  1877,  1454,  1879,  2008,     0,
    1878,  1880,  1881,  1831,  1882,  1883,  1884,  1885,  1886,  1887,
    1888,  1889,  1890,  1891,  1892,  1893,  1894,  1896,  2009,  1474,
    1897,  2086,  1903,   585,  1900,  1480,  1481,  1901,  1719,  1902,
    1912,  1722,  1723,  1724,  1725,   383,  1726,  1913,  1727,  1914,
    1918,  1919,  1920,  1921,  1730,  1731,  1732,  1924,  1925,  1733,
    1734,  1735,  1736,  1926,  1737,  1927,  1738,  1928,  1739,  1929,
    1930,  1740,  1741,  1742,  1743,  1931,  2338,  1932,  1744,  1933,
    1934,  1746,  1935,  1936,  1937,  1748,  1938,  1939,  1944,  1945,
    1946,  1947,  2033,  1975,  1948,  1954,  1949,  1950,  1951,  1952,
    1953,  1955,  1758,  1956,  1957,  1958,  1959,  1759,  1960,  1961,
    1962,  1761,  1762,  1763,  1764,  1765,  1766,  1767,  1768,  1770,
    1771,  1772,  1773,  1774,  1775,  1776,  1777,  1778,  1779,  1780,
    1781,  1754,  1963,  1782,  1964,  1965,  1966,  1967,  1968,  1969,
    1972,  1788,  1983,  1985,  1981,  1982,  1984,  1790,  1791,  1792,
    1793,  1976,  1794,  1796,  1797,  1977,  1798,  1799,  1978,  1979,
    1986,  1987,  1988,  1800,  1801,  1802,  1803,  1990,  1989,  1991,
    1992,  1971,  1806,  1973,  1993,  1809,  1810,  1994,  1998,  2000,
    1980,  2001,  2002,  2003,     0,  1811,  1812,  1813,  1814,  2004,
    2005,  2006,  2007,  2010,  2013,  2031,  2113,  2116,  1817,  1818,
    1819,  1650,  2117,  2118,  2119,  1822,  2120,  2121,  2123,  2122,
    2124,  2125,  2127,  2126,  2129,  2128,  2130,  1832,  1833,  2133,
    1834,  1835,   948,  1836,  1837,  1838,  2134,  2139,  2140,  1840,
    1841,  2141,  2142,  1843,  2143,  2144,  1845,  2145,  1846,  1847,
    1848,  2146,  2147,  2148,  2149,  1850,  2151,  2153,  1851,  2154,
    1852,  2155,  2167,  2170,  1853,  1854,  1855,  2156,  1856,  1857,
    1858,  2157,  2158,  2159,  2160,  2161,  2162,  2163,  1718,  2166,
    2171,  2172,  2173,  2174,  2175,  2176,  2177,  2178,  2183,  2186,
    2179,  2182,  2187,  2188,  2189,  2190,  2192,  2193,  2195,   947,
     971,     0,  2194,  2196,     0,  2197,  2198,  2199,  2200,  2201,
    2202,  2203,  2204,  2205,  2206,  1895,  2207,  2208,  2209,  2210,
    2211,  2212,  2340,  2214,  2277,     0,  2279,  2280,  2213,     0,
       0,  2278,  2284,  2285,  2281,  2282,  2283,  2286,  2288,  2289,
    2287,  2290,  2291,  2292,  2293,  2294,  2295,  2296,  2299,  2301,
    2302,     0,  2304,  2300,  2305,  2306,  2307,  2303,  2309,  2308,
    2310,  2311,  2312,  2313,  2315,  2314,  2317,  2318,     0,  2316,
       0,  2319,  2324,     0,  2320,  2321,  2322,  2323,  2326,  2325,
    2327,  2328,  1970,  2329,     0,  2332,  2333,  2339,  2334,  2335,
    2336,  2337,  2372,     0,  2373,  2374,  2375,  2376,  2378,  2377,
    2379,  2380,  2381,  2382,  2385,  2383,     0,     0,  2384,     0,
       0,  2386,  2387,  2388,  2391,  2392,  2393,  2394,  2395,  2398,
    2399,  2400,  2401,  2402,  2403,  2427,  2014,  2428,  2015,  2429,
    2016,  2430,  2017,  2431,  2018,  2432,  2433,  2437,  2434,  2019,
    2020,  2445,  2021,  2022,  2023,  2024,  2191,  2025,  2026,  2027,
    2028,  2438,  2439,  2440,  2029,  2030,  2443,  2444,  2450,  2451,
    2452,  2468,  2469,  2034,  2035,  2470,  2471,  2036,  2472,  2037,
    2473,  2038,  2474,  2039,  2040,  2041,  2042,  2475,  2043,  2044,
    2045,  2046,  2047,  2048,  2476,  2049,  2051,  2477,  2054,  2055,
    2056,  2057,  2032,  2058,  2059,  2060,  2061,  2062,  2478,  2064,
    2479,  2480,  2481,  2490,  2491,  2492,  2493,  2494,  2495,  2069,
    2070,  2071,  2072,  2073,  2074,  2075,  2496,  2497,  2076,  2502,
    2503,  2079,  2080,  2504,  2081,  2082,  2083,  2505,  2510,  2511,
    2084,  2085,  2512,  2513,  2087,  2517,  2518,  2519,  2523,  2528,
    2524,  2525,  2529,  2088,  2089,     0,  2090,     0,     0,     0,
    2092,  2093,     0,  2094,  2095,     0,  2097,     0,  2098,  2099,
       0,  2100,     0,  2101,  2102,  2103,  2104,  2105,  2106,  2107,
    2108,  2109,  2110,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    37,
     366,   367,   368,   369,   370,   371,   372,    45,   373,   374,
     375,    49,    50,    51,    52,    53,   376,   377,   378,   379,
     380,     0,     0,  2011,  2012,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2215,     0,     0,  2216,  2217,     0,
    2218,  2219,     0,  2220,  2221,     0,  2222,  2223,  2224,     0,
    2225,     0,     0,     0,     0,  2227,  2228,     0,  2229,     0,
    2230,  2231,  2232,  2233,  2234,     0,  2235,  2236,  2237,  2238,
    2239,  2240,     0,     0,     0,     0,     0,     0,     0,  2245,
    2246,  2247,     0,     0,     0,  2226,   278,  2252,  2253,     0,
       0,  2254,     0,  2255,  2256,     0,     0,  2257,  2258,     0,
    2259,  2260,     0,     0,     0,     0,     0,  2263,   336,     0,
       0,   343,     0,     0,  2264,  2265,  2266,     0,     0,  2268,
    2269,  2270,  2271,     0,  2273,     0,     0,  2274,  2275,   141,
     142,   143,     0,     0,     0,  2276,   148,   149,   150,   151,
       0,   153,     0,     0,     0,   381,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   178,     0,     0,   179,   180,   181,   182,   183,   184,
       0,     0,   187,     0,     0,     0,     0,     0,     0,     0,
    2341,     0,     0,  2342,  2343,  2344,     0,     0,     0,  2345,
       0,     0,  2346,     0,     0,     0,     0,     0,  2347,     0,
    2348,     0,  2349,     0,     0,  2350,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2352,  2353,     0,  2354,     0,
       0,  2355,  2356,  2357,  2358,  2359,     0,     0,     0,  2361,
       0,  2362,     0,     0,  2364,  2365,  2366,  2367,     0,  2369,
    2370,     0,  2371,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2404,  2405,  2406,  2407,  2408,
       0,     0,     0,  2409,     0,  2410,  2411,     0,  2412,  2413,
    2414,     0,  2415,  2416,   381,  2418,  2419,  2420,     0,  2421,
       0,  2422,  2423,     0,  2425,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   245,   246,   247,     0,     0,
     250,   251,     0,   253,     0,     0,     0,     0,     0,     0,
       0,  2454,   278,     0,     0,     0,  2455,     0,     0,     0,
    2457,  2458,  2459,     0,     0,  2461,  2462,     0,     0,  2463,
       0,     0,  2465,  2466,  2467,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2482,  2483,     0,     0,  2484,     0,     0,     0,  2485,     0,
       0,  2487,  2488,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2498,     0,     0,  2499,     0,     0,  2500,     0,
       0,     0,     0,     0,  2506,  2507,  2508,  2509,     0,     0,
       0,     0,  2514,  2515,  2516,   381,   381,     0,     0,  2520,
    2521,  2522,     0,     0,     0,     0,  2526,  2527,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   381,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   727,     0,     0,
     730,   731,   732,   733,   734,     0,   736,   737,   738,   739,
     740,   741,   742,   743,   744,     0,     0,   747,     0,     0,
     754,   755,   756,   757,   758,   759,   760,   761,   762,   763,
       0,   765,   766,   767,   768,   769,   770,   771,   772,   773,
     774,   775,   776,   777,   778,   780,     0,     0,     0,     0,
       0,     0,   787,   788,   789,   790,   791,   792,   793,   794,
     795,     0,     0,   798,   799,   800,   801,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   811,   812,   813,     0,
       0,   816,   817,   818,   819,   820,   821,   822,   823,   824,
     825,   826,     0,     0,     0,   830,   832,     0,   834,     0,
     836,     0,     0,     0,   840,   841,     0,     0,     0,     0,
     845,   846,   847,   848,     0,     0,     0,     0,   853,    37,
     366,   367,   368,   369,   370,   371,   372,    45,   373,   374,
     375,    49,    50,    51,    52,    53,   376,   377,   378,   540,
     380,     0,   381,     0,     0,     0,     0,     0,     0,     0,
       0,   871,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   889,
     890,   891,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   929,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   141,
     142,   143,     0,     0,     0,     0,   148,   149,   150,   151,
       0,   153,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   178,     0,     0,   179,   180,   181,   182,   183,   184,
       0,     0,   187,     0,     0,   719,   721,   722,   723,   724,
     725,   726,     0,   728,   729,     0,     0,     0,     0,     0,
     735,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     745,   746,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   764,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     779,   781,   782,   783,   784,   785,   786,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   803,   804,   805,     0,     0,     0,   299,
       0,     0,     0,   323,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   827,     0,   333,
       0,     0,   833,     0,     0,   344,   345,   333,   839,   333,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     850,   851,   852,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   245,   246,   247,     0,   333,
     250,   251,     0,   253,     0,     0,     0,     0,     0,   863,
       0,     0,     0,     0,   869,   870,     0,   872,   873,     0,
     875,   876,   877,   878,   879,   880,   881,     0,   883,   884,
     885,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   956,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   381,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1263,     0,     0,     0,     0,     0,
    1269,     0,     0,  1273,     0,     0,   333,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     333,   333,     0,     0,     0,     0,     0,  1321,     0,     0,
       0,     0,     0,     0,     0,     0,  1329,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1339,  1340,  1341,
       0,     0,     0,     0,     0,   299,     0,     0,     0,  1350,
       0,     0,     0,     0,  1352,     0,  1353,  1354,  1355,  1356,
    1357,     0,  1358,  1359,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   323,     0,     0,
       0,     0,     0,     0,  1385,     0,     0,     0,     0,     0,
    1388,  1389,  1390,  1391,  1392,     0,     0,   333,     0,   333,
     323,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   333,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1433,     0,     0,  1436,     0,     0,     0,     0,     0,
       0,     0,   718,   720,   718,   718,   718,   718,   718,   718,
       0,   718,   718,  1449,  1450,     0,     0,     0,   718,     0,
       0,  1456,     0,  1457,  1458,  1460,  1462,     0,   718,   718,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   718,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   718,   718,
     718,   718,   718,   718,   718,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   718,   718,   718,     0,   333,     0,   333,   333,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   718,     0,     0,     0,     0,
     718,     0,     0,     0,  1545,  1546,   718,     0,     0,   323,
       0,     0,   844,     0,     0,     0,     0,   333,   718,   718,
     718,     0,     0,     0,     0,     0,     0,     0,  1283,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   333,   718,     0,     0,
       0,     0,   718,   718,     0,   718,   718,     0,   718,   718,
     718,   718,   718,   718,   718,     0,   718,   718,   718,   333,
     333,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   895,     0,     0,
    1337,  1338,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   718,   969,   975,     0,
       0,     0,  1361,     0,     0,     0,   895,  1366,  1367,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   381,     0,
       0,     0,  1720,     0,  1721,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1728,  1729,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1029,
    1030,     0,     0,     0,     0,     0,     0,     0,   333,     0,
       0,     0,     0,     0,  1745,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1442,     0,
       0,  1445,  1446,     0,  1755,  1757,     0,     0,     0,     0,
       0,     0,     0,     0,  1760,     0,     0,     0,     0,     0,
       0,     0,  1769,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1783,  1784,
    1785,  1786,  1787,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1807,  1808,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1815,     0,     0,     0,     0,     0,
       0,     0,     0,  1540,     0,     0,     0,     0,  1544,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   333,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1844,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1591,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   333,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   333,     0,  1243,   333,     0,     0,
       0,     0,     0,   333,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     333,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   718,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     333,     0,   333,     0,     0,     0,     0,     0,   333,     0,
       0,     0,     0,  1316,     0,     0,     0,     0,     0,     0,
       0,  1747,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   718,   718,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1755,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     718,     0,     0,     0,     0,   718,   718,     0,     0,   929,
     929,   929,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2063,     0,     0,     0,     0,     0,     0,     0,
     333,     0,     0,     0,     0,     0,  1804,     0,     0,     0,
    1805,     0,     0,  2077,  2078,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1816,     0,     0,     0,     0,
       0,     0,   333,     0,     0,     0,     0,     0,     0,  2096,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1839,     0,     0,
    1842,     0,     0,     0,     0,     0,   718,     0,     0,   718,
     718,     0,     0,     0,     0,   333,     0,     0,     0,     0,
       0,     0,   333,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   333,     0,     0,     0,     0,
       0,   333,   333,     0,     0,  1483,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   718,     0,     0,     0,     0,   718,     0,  1755,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   929,     0,   929,     0,
       0,   929,   929,     0,     0,     0,  2248,  2249,  2250,  2251,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   718,     0,     0,     0,     0,     0,     0,  2262,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2272,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   333,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2065,     0,  2066,  2067,     0,  2068,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   333,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   929,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2091,     0,     0,
       0,  2360,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2368,     0,     0,     0,     0,     0,     0,   718,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2417,     0,
       0,     0,     0,     0,     0,     0,     0,  2424,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1795,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   718,     0,     0,     0,   718,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   718,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2489,     0,     0,
       0,     0,     0,     0,     0,   718,     0,     0,   718,     0,
       0,     0,     0,  2501,     0,     0,     0,     0,     0,     0,
    1849,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2261,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2267,     0,     0,
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
       0,     0,  2363,     0,     0,     0,     0,     0,     0,   333,
     333,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     718,     0,   718,   718,     0,   718,     0,  2453,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2456,     0,     0,
       0,     0,     0,  2460,     0,     0,     0,     0,     0,     0,
    2464,     1,     2,     3,     0,     4,     0,     0,     0,   957,
       0,     0,     0,     0,     0,   718,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    16,    17,     0,  2486,
     958,    21,     0,   959,     0,     0,     0,     0,     0,     0,
       0,     0,    29,     0,     0,     0,    32,    33,    34,     0,
      35,     0,    37,    38,    39,    40,    41,   960,    43,    44,
      45,   961,    47,   962,    49,    50,    51,    52,    53,   376,
     312,   963,   540,   380,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    68,    69,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,     0,    83,     0,    85,    86,    87,    88,    89,
      90,    91,    92,     0,     0,     0,    95,     0,    97,    98,
      99,   315,   316,   102,   103,   104,   105,   106,   107,   108,
     109,     0,     0,     0,   110,   111,     0,     0,     0,     0,
       0,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,     0,     0,     0,     0,     0,     0,   139,     0,
       0,     0,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,     0,     0,     0,     0,
     718,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   155,   156,   157,   158,   718,     0,     0,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
       0,     0,   176,   177,   178,     0,     0,   179,   180,   181,
     182,   183,   184,   185,   186,   964,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   965,
     188,   189,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   190,   191,   192,   193,   194,
     966,   196,   197,   967,   199,   200,   201,   202,   203,   204,
       0,   205,     0,   207,   208,     0,   968,     0,     0,     0,
       0,   210,   211,   212,   213,   214,   215,   216,   217,     0,
       0,   218,   219,   220,   221,   222,   223,   224,   225,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     718,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   233,   234,   235,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     239,   240,   241,   242,     0,   243,   244,     0,   245,   246,
     247,   248,   249,   250,   251,     0,   253,   254,   255,   256,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   718,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   718,   577,     0,     0,     0,
       0,   718,     0,     0,     0,     1,     2,     3,   718,     4,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     0,   718,    22,    23,
      24,    25,    26,    27,    28,     0,    29,    30,    31,     0,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,     0,    62,    63,    64,    65,    66,    67,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    68,    69,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,     0,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,     0,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,     0,     0,     0,   110,   111,
       0,     0,     0,     0,     0,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,     0,
       0,   179,   180,   181,   182,   183,   184,   185,   186,   187,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   188,   189,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,     0,   205,   206,   207,   208,   209,
       0,     0,     0,     0,     0,   210,   211,   212,   213,   214,
     215,   216,   217,     0,     0,   218,   219,   220,   221,   222,
     223,   224,   225,   226,     0,     0,     0,     0,   227,     0,
     228,   229,   230,     0,     0,     0,   231,   232,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     233,   234,   235,   236,     0,     0,     0,     0,     0,     0,
       0,   237,   238,     0,   239,   240,   241,   242,     0,   243,
     244,     0,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,     0,   259,   260,   261,
     262,   263,   264,     1,     2,     3,     0,     4,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     0,     0,    22,    23,    24,    25,
      26,    27,    28,     0,    29,    30,    31,     0,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,     0,
      62,    63,    64,    65,    66,    67,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    68,
      69,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,     0,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,     0,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,     0,     0,     0,   110,   111,     0,     0,
       0,     0,     0,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,     0,     0,   179,
     180,   181,   182,   183,   184,   185,   186,   187,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   188,   189,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,     0,   205,   206,   207,   208,   209,     0,     0,
       0,     0,     0,   210,   211,   212,   213,   214,   215,   216,
     217,     0,     0,   218,   219,   220,   221,   222,   223,   224,
     225,   226,     0,     0,     0,     0,   227,     0,   228,   229,
     230,     0,     0,     0,   231,   232,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   233,   234,
     235,   236,     0,     0,     0,     0,     0,     0,     0,   237,
     238,     0,   239,   240,   241,   242,     0,   243,   244,     0,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,     0,   259,   260,   261,   262,   263,
     264,     1,     2,     3,     0,     4,     0,     0,     0,   972,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    16,    17,     0,     0,
      20,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    29,     0,     0,     0,    32,    33,    34,     0,
      35,     0,    37,    38,    39,    40,    41,   960,    43,    44,
      45,   973,    47,   962,    49,    50,    51,    52,    53,   376,
     312,   378,   540,   380,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    68,    69,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,     0,    83,     0,    85,    86,    87,    88,    89,
      90,    91,    92,     0,     0,     0,    95,     0,    97,    98,
      99,   315,   316,   102,   103,   104,   105,   106,   107,   108,
     109,     0,     0,     0,   110,   111,     0,     0,     0,     0,
       0,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,     0,     0,     0,     0,     0,     0,   139,     0,
       0,     0,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   155,   156,   157,   158,     0,     0,     0,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
       0,     0,   176,   177,   178,     0,     0,   179,   180,   181,
     182,   183,   184,   185,   186,   187,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     188,   189,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
       0,   205,     0,   207,   208,     0,     0,     0,     0,     0,
       0,   210,   211,   212,   213,   214,   215,   216,   217,     0,
       0,   218,   219,   220,   221,   222,   223,   224,   225,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   233,   234,   235,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     239,   240,   241,   242,     0,   243,   244,     0,   245,   246,
     247,   248,   249,   250,   251,     0,   253,   254,   255,   256,
       1,     2,     3,     0,     4,     0,     0,     0,  1482,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    16,    17,     0,     0,    20,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    29,     0,     0,     0,    32,    33,    34,     0,    35,
       0,    37,    38,    39,    40,    41,   960,    43,    44,    45,
     973,    47,   962,    49,    50,    51,    52,    53,   376,   312,
     378,   540,   380,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    68,    69,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,     0,    83,     0,    85,    86,    87,    88,    89,    90,
      91,    92,     0,     0,     0,    95,     0,    97,    98,    99,
     315,   316,   102,   103,   104,   105,   106,   107,   108,   109,
       0,     0,     0,   110,   111,     0,     0,     0,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,     0,     0,     0,     0,     0,     0,   139,     0,     0,
       0,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     155,   156,   157,   158,     0,     0,     0,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,     0,
       0,   176,   177,   178,     0,     0,   179,   180,   181,   182,
     183,   184,   185,   186,   187,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   188,
     189,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,     0,
     205,     0,   207,   208,     0,     0,     0,     0,     0,     0,
     210,   211,   212,   213,   214,   215,   216,   217,     0,     0,
     218,   219,   220,   221,   222,   223,   224,   225,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   233,   234,   235,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   239,
     240,   241,   242,     0,   243,   244,     0,   245,   246,   247,
     248,   249,   250,   251,     0,   253,   254,   255,   256,     1,
       2,     3,     0,     4,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     5,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,    17,     0,    19,    20,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      29,     0,     0,     0,    32,    33,    34,     0,    35,     0,
      37,    38,    39,    40,    41,   309,    43,    44,    45,   310,
      47,   311,    49,    50,    51,    52,    53,     0,   312,     0,
     313,   314,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    68,    69,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
       0,    83,     0,    85,    86,    87,    88,    89,    90,    91,
      92,     0,     0,     0,    95,     0,    97,    98,    99,   315,
     316,   102,   103,   104,   105,   106,   107,   108,   109,     0,
       0,     0,   110,   111,     0,     0,     0,     0,     0,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
       0,     0,     0,     0,     0,     0,   139,     0,     0,     0,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   155,
     156,   157,   158,     0,     0,     0,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,     0,     0,
     176,   177,   178,     0,     0,   179,   180,   181,   182,   183,
     184,   185,   186,   187,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   188,   189,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,     0,   205,
       0,   207,   208,     0,     0,     0,     0,     0,     0,   210,
     211,   212,   213,   214,   215,   216,   217,     0,     0,   218,
     219,   220,   221,   222,   223,   224,   225,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   233,   234,   235,     0,     0,     0,
       0,     0,     0,     1,     2,     3,     0,     4,   239,   240,
     241,   242,     0,   243,   244,     0,   245,   246,   247,   248,
     249,   250,   251,     0,   253,   254,   255,   256,    16,    17,
       0,     0,    20,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    29,     0,     0,     0,    32,    33,
      34,     0,    35,     0,    37,    38,    39,    40,    41,   960,
      43,    44,    45,   973,    47,   962,    49,    50,    51,    52,
      53,   376,   312,   378,   540,   380,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    68,
      69,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,     0,    83,     0,    85,    86,    87,
      88,    89,    90,    91,    92,     0,     0,     0,    95,     0,
      97,    98,    99,   315,   316,   102,   103,   104,   105,   106,
     107,   108,   109,     0,     0,     0,   110,   111,     0,     0,
       0,     0,     0,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,     0,     0,     0,     0,     0,     0,
     139,     0,     0,     0,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   155,   156,   157,   158,     0,     0,     0,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,     0,     0,   176,   177,   178,     0,     0,   179,
     180,   181,   182,   183,   184,   185,   186,   187,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   188,   189,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,     0,   205,     0,   207,   208,     0,     0,     0,
       0,     0,     0,   210,   211,   212,   213,   214,   215,   216,
     217,     0,     0,   218,   219,   220,   221,   222,   223,   224,
     225,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   233,   234,
     235,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   239,   240,   241,   242,     0,   243,   244,     0,
     245,   246,   247,   248,   249,   250,   251,     0,   253,   254,
     255,   256,     1,     2,     3,     0,     4,   842,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    16,    17,     0,
       0,    20,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29,     0,     0,     0,    32,    33,    34,
       0,    35,     0,    37,    38,    39,    40,    41,   309,    43,
      44,    45,   310,    47,   311,    49,    50,    51,    52,    53,
       0,   312,     0,   313,   314,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    68,    69,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,     0,    83,     0,    85,    86,    87,    88,
      89,    90,    91,    92,     0,     0,     0,    95,     0,    97,
      98,    99,   315,   316,   102,   103,   104,   105,   106,   107,
     108,   109,     0,     0,     0,   110,   111,     0,     0,     0,
       0,     0,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,     0,     0,     0,     0,     0,     0,   139,
       0,     0,     0,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   155,   156,   157,   158,     0,     0,     0,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,     0,     0,   176,   177,   178,     0,     0,   179,   180,
     181,   182,   183,   184,   185,   186,   187,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   188,   189,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,     0,   205,     0,   207,   208,     0,     0,     0,     0,
       0,     0,   210,   211,   212,   213,   214,   215,   216,   217,
       0,     0,   218,   219,   220,   221,   222,   223,   224,   225,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   233,   234,   235,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   239,   240,   241,   242,     0,   243,   244,     0,   245,
     246,   247,   248,   249,   250,   251,     0,   253,   254,   255,
     256,     1,     2,     3,     0,     4,     0,     0,     0,     0,
       0,     0,     0,     0,   926,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    16,    17,     0,     0,
      20,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    29,     0,     0,     0,    32,    33,    34,     0,
      35,     0,    37,    38,    39,    40,    41,   927,    43,    44,
      45,   310,    47,   311,    49,    50,    51,    52,    53,     0,
     312,     0,   313,   314,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    68,    69,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,     0,    83,     0,    85,    86,    87,    88,    89,
      90,    91,    92,     0,     0,     0,    95,     0,    97,    98,
      99,   315,   316,   102,   103,   104,   105,   106,   107,   108,
     109,     0,     0,     0,   110,   111,     0,     0,     0,     0,
       0,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,     0,     0,     0,     0,     0,     0,   139,     0,
       0,     0,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   155,   156,   157,   158,     0,     0,     0,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
       0,     0,   176,   177,   178,     0,     0,   179,   180,   181,
     182,   183,   184,   185,   186,   187,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     188,   189,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
       0,   205,     0,   207,   208,     0,     0,     0,     0,     0,
       0,   210,   211,   212,   213,   214,   215,   216,   217,     0,
       0,   218,   219,   220,   221,   222,   223,   224,   225,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   233,   234,   235,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     239,   240,   241,   242,     0,   243,   244,     0,   245,   246,
     247,   248,   249,   250,   251,     0,   253,   254,   255,   256,
       1,     2,     3,     0,   510,     0,  1242,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    16,    17,     0,     0,    20,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    29,     0,     0,     0,    32,    33,    34,     0,    35,
       0,    37,    38,    39,    40,    41,   309,    43,    44,    45,
     310,    47,   311,    49,    50,    51,    52,    53,     0,   312,
       0,   313,   314,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    68,    69,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,     0,    83,     0,    85,    86,    87,    88,    89,    90,
      91,    92,     0,     0,     0,    95,     0,    97,    98,    99,
     315,   316,   102,   103,   104,   105,   106,   107,   108,   109,
       0,     0,     0,   110,   111,     0,     0,     0,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,     0,     0,     0,     0,     0,     0,   139,     0,     0,
       0,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     155,   156,   157,   158,     0,     0,     0,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,     0,
       0,   176,   177,   178,     0,     0,   179,   180,   181,   182,
     183,   184,   185,   186,   187,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   188,
     189,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,     0,
     205,     0,   207,   208,     0,     0,     0,     0,     0,     0,
     210,   211,   212,   213,   214,   215,   216,   217,     0,     0,
     218,   219,   220,   221,   222,   223,   224,   225,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   233,   234,   235,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   239,
     240,   241,   242,     0,   243,   244,     0,   245,   246,   247,
     248,   249,   250,   251,     0,   253,   254,   255,   256,     1,
       2,     3,     0,   331,     0,  1245,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,    17,     0,     0,    20,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      29,     0,     0,     0,    32,    33,    34,     0,    35,     0,
      37,    38,    39,    40,    41,   309,    43,    44,    45,   310,
      47,   311,    49,    50,    51,    52,    53,     0,   312,     0,
     313,   314,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    68,    69,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
       0,    83,     0,    85,    86,    87,    88,    89,    90,    91,
      92,     0,     0,     0,    95,     0,    97,    98,    99,   315,
     316,   102,   103,   104,   105,   106,   107,   108,   109,     0,
       0,     0,   110,   111,     0,     0,     0,     0,     0,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
       0,     0,     0,     0,     0,     0,   139,     0,     0,     0,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   155,
     156,   157,   158,     0,     0,     0,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,     0,     0,
     176,   177,   178,     0,     0,   179,   180,   181,   182,   183,
     184,   185,   186,   187,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   188,   189,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,     0,   205,
       0,   207,   208,     0,     0,     0,     0,     0,     0,   210,
     211,   212,   213,   214,   215,   216,   217,     0,     0,   218,
     219,   220,   221,   222,   223,   224,   225,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   233,   234,   235,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   239,   240,
     241,   242,     0,   243,   244,     0,   245,   246,   247,   248,
     249,   250,   251,     0,   253,   254,   255,   256,     1,     2,
       3,     0,   510,     0,  1248,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    16,    17,     0,     0,    20,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    29,
       0,     0,     0,    32,    33,    34,     0,    35,     0,    37,
      38,    39,    40,    41,   309,    43,    44,    45,   310,    47,
     311,    49,    50,    51,    52,    53,     0,   312,     0,   313,
     314,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    68,    69,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,     0,
      83,     0,    85,    86,    87,    88,    89,    90,    91,    92,
       0,     0,     0,    95,     0,    97,    98,    99,   315,   316,
     102,   103,   104,   105,   106,   107,   108,   109,     0,     0,
       0,   110,   111,     0,     0,     0,     0,     0,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,     0,
       0,     0,     0,     0,     0,   139,     0,     0,     0,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   155,   156,
     157,   158,     0,     0,     0,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,     0,     0,   176,
     177,   178,     0,     0,   179,   180,   181,   182,   183,   184,
     185,   186,   187,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   188,   189,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,     0,   205,     0,
     207,   208,     0,     0,     0,     0,     0,     0,   210,   211,
     212,   213,   214,   215,   216,   217,     0,     0,   218,   219,
     220,   221,   222,   223,   224,   225,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   233,   234,   235,     0,     0,     0,     0,
       0,     0,     1,     2,     3,     0,     4,   239,   240,   241,
     242,     0,   243,   244,     0,   245,   246,   247,   248,   249,
     250,   251,     0,   253,   254,   255,   256,    16,    17,     0,
       0,    20,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29,     0,     0,     0,    32,    33,    34,
       0,    35,     0,    37,    38,    39,    40,    41,   309,    43,
      44,    45,   310,    47,   311,    49,    50,    51,    52,    53,
       0,   312,     0,   313,   314,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    68,    69,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,     0,    83,     0,    85,    86,    87,    88,
      89,    90,    91,    92,     0,     0,     0,    95,     0,    97,
      98,    99,   315,   316,   102,   103,   104,   105,   106,   107,
     108,   109,     0,     0,     0,   110,   111,     0,     0,     0,
       0,     0,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,     0,     0,     0,     0,     0,     0,   139,
       0,     0,     0,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   155,   156,   157,   158,     0,     0,     0,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,     0,     0,   176,   177,   178,     0,     0,   179,   180,
     181,   182,   183,   184,   185,   186,   187,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   188,   189,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,     0,   205,     0,   207,   208,     0,     0,     0,     0,
       0,     0,   210,   211,   212,   213,   214,   215,   216,   217,
       0,     0,   218,   219,   220,   221,   222,   223,   224,   225,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   233,   234,   235,
       0,     0,     0,     0,     0,     0,     1,     2,     3,     0,
     331,   239,   240,   241,   242,     0,   243,   244,     0,   245,
     246,   247,   248,   249,   250,   251,     0,   253,   254,   255,
     256,    16,    17,     0,     0,    20,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    29,     0,     0,
       0,    32,    33,    34,     0,    35,     0,    37,    38,    39,
      40,    41,   309,    43,    44,    45,   310,    47,   311,    49,
      50,    51,    52,    53,     0,   312,     0,   313,   314,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    68,    69,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,     0,    83,     0,
      85,    86,    87,    88,    89,    90,    91,    92,     0,     0,
       0,    95,     0,    97,    98,    99,   315,   316,   102,   103,
     104,   105,   106,   107,   108,   109,     0,     0,     0,   110,
     111,     0,     0,     0,     0,     0,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,     0,     0,     0,
       0,     0,     0,   139,     0,     0,     0,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   155,   156,   157,   158,
       0,     0,     0,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,     0,     0,   176,   177,   178,
       0,     0,   179,   180,   181,   182,   183,   184,   185,   186,
     187,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   188,   189,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,     0,   205,     0,   207,   208,
       0,     0,     0,     0,     0,     0,   210,   211,   212,   213,
     214,   215,   216,   217,     0,     0,   218,   219,   220,   221,
     222,   223,   224,   225,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   233,   234,   235,     0,     0,     0,     0,     0,     0,
       1,     2,     3,     0,   510,   239,   240,   241,   242,     0,
     243,   244,     0,   245,   246,   247,   248,   249,   250,   251,
       0,   253,   254,   255,   256,    16,    17,     0,     0,    20,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    29,     0,     0,     0,    32,    33,    34,     0,    35,
       0,    37,    38,    39,    40,    41,   309,    43,    44,    45,
     310,    47,   311,    49,    50,    51,    52,    53,     0,   312,
       0,   313,   314,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    68,    69,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,     0,    83,     0,    85,    86,    87,    88,    89,    90,
      91,    92,     0,     0,     0,    95,     0,    97,    98,    99,
     315,   316,   102,   103,   104,   105,   106,   107,   108,   109,
       0,     0,     0,   110,   111,     0,     0,     0,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,     0,     0,     0,     0,     0,     0,   139,     0,     0,
       0,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     155,   156,   157,   158,     0,     0,     0,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,     0,
       0,   176,   177,   178,     0,     0,   179,   180,   181,   182,
     183,   184,   185,   186,   187,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   188,
     189,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,     0,
     205,     0,   207,   208,     0,     0,     0,     0,     0,     0,
     210,   211,   212,   213,   214,   215,   216,   217,     0,     0,
     218,   219,   220,   221,   222,   223,   224,   225,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   233,   234,   235,     0,     0,
       0,     0,     0,     0,     1,     2,     3,     0,     4,   239,
     240,   241,   242,     0,   243,   244,     0,   245,   246,   247,
     248,   249,   250,   251,     0,   253,   254,   255,   256,    16,
      17,     0,     0,    20,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    29,     0,     0,     0,    32,
      33,    34,     0,    35,     0,    37,    38,    39,    40,    41,
     309,    43,    44,    45,   310,    47,   311,    49,    50,    51,
      52,    53,     0,   312,     0,   313,   314,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      68,    69,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,     0,    83,     0,    85,    86,
      87,    88,    89,    90,    91,    92,     0,     0,     0,    95,
       0,    97,    98,    99,   315,   316,   102,   103,   104,   105,
     106,   107,   108,   109,     0,     0,     0,   110,   111,     0,
       0,     0,     0,     0,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,     0,     0,     0,     0,     0,
       0,   139,     0,     0,     0,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   155,   156,   157,   158,     0,     0,
       0,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,     0,     0,   176,   177,   178,     0,     0,
     179,   180,   181,   182,   183,   184,   185,   186,   955,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   188,   189,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,     0,   205,     0,   207,   208,     0,     0,
       0,     0,     0,     0,   210,   211,   212,   213,   214,   215,
     216,   217,     0,     0,   218,   219,   220,   221,   222,   223,
     224,   225,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   233,
     234,   235,     0,     0,     0,     0,     0,     0,     1,     0,
       0,     0,   308,   239,   240,   241,   242,     0,   243,   244,
       0,   245,   246,   247,   248,   249,   250,   251,     0,   253,
     254,   255,   256,    16,    17,     0,     0,    20,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    29,
       0,     0,     0,    32,    33,    34,     0,    35,     0,    37,
      38,    39,    40,    41,   309,    43,    44,    45,   310,    47,
     311,    49,    50,    51,    52,    53,     0,   312,     0,   313,
     314,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,     0,
      83,     0,    85,    86,    87,    88,    89,    90,    91,    92,
       0,     0,     0,    95,     0,    97,    98,    99,   315,   316,
     102,   103,   104,   105,   106,   107,   108,   109,     0,     0,
       0,   110,   111,     0,     0,     0,     0,     0,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,     0,
       0,     0,     0,     0,     0,   139,     0,     0,     0,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   155,   156,
     157,   158,     0,     0,     0,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,     0,     0,   176,
     177,   178,     0,     0,   179,   180,   181,   182,   183,   184,
     185,   186,   187,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   188,   189,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,     0,   205,     0,
     207,   208,     0,     0,     0,     0,     0,     0,   210,   211,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   233,   234,   235,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   308,   239,   240,   241,
     242,     0,   243,   244,     0,   245,   246,   247,   248,   249,
     250,   251,     0,   253,   254,   255,   256,    16,    17,     0,
       0,    20,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29,     0,     0,     0,    32,    33,    34,
       0,    35,     0,    37,    38,    39,    40,    41,   309,    43,
      44,    45,   310,    47,   311,    49,    50,    51,    52,    53,
       0,   312,     0,   313,   314,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,     0,    83,     0,    85,    86,    87,    88,
      89,    90,    91,    92,     0,     0,     0,    95,     0,    97,
      98,    99,   315,   316,   102,   103,   104,   105,   106,   107,
     108,   109,     0,     0,     0,   110,   111,     0,     0,     0,
       0,     0,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,     0,     0,     0,     0,     0,     0,   139,
       0,     0,     0,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   155,   156,   157,   158,     0,     0,     0,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,     0,     0,   176,   177,   178,     0,     0,   179,   180,
     181,   182,   183,   184,   185,   186,   187,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   188,   189,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,     0,   205,     0,   207,   208,     0,     0,     0,     0,
       0,     0,   210,   211,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   233,   234,   235,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   239,   240,   241,   242,     0,   243,   244,     0,   245,
     246,   247,   248,   249,   250,   251,     0,   253,   254,   255,
     256
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
         8,     9,    10,     0,    59,     0,   228,     1,    60,    23,
      41,    23,  1923,  1924,  1925,    60,   116,    19,    46,    47,
      46,   231,    21,    19,    16,    37,    78,     4,    15,    81,
       5,     6,    22,    56,    19,    56,    81,    60,    69,    60,
      54,    23,   541,   542,    54,    14,    59,    14,    79,    10,
      11,    20,    19,   552,    23,    37,   266,    19,    81,    13,
      81,    13,    59,    76,   274,    19,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,   220,
     221,   222,   223,   224,   225,   226,   227,   228,    13,   594,
     595,   596,    60,   264,   265,   112,   113,    65,    95,    60,
     109,    96,    97,   105,   106,    13,    95,    13,    54,   109,
     116,    19,   114,    81,   285,    13,    14,   349,   350,    56,
      81,    19,    59,   264,   629,   110,   111,   116,    13,   165,
      95,    96,    97,    98,    99,    72,    73,    74,    75,   105,
     106,     7,     8,    20,    14,    22,    12,    93,   114,    13,
      20,   116,   164,    23,    13,    19,   388,    13,    13,    15,
      19,    20,    13,   228,    19,    20,   264,   265,    19,    20,
     388,   389,   390,   391,   392,    13,   394,    20,     2,     3,
      23,    53,    54,   388,   389,   390,   391,   392,    14,   394,
      13,    14,    13,    19,    20,    14,    19,   200,   201,   202,
      61,    20,   226,    64,   207,   208,   209,   210,    15,   212,
      13,    14,   230,   237,   238,    59,    19,    13,    14,    14,
      92,   228,    14,    19,    14,    20,    14,    13,    20,  2150,
      20,  2152,    20,    20,  2155,  2156,    14,   599,   600,   601,
     602,    28,    20,    30,    68,    69,   287,    19,    13,   252,
      15,   361,   255,   256,   257,   258,   259,   260,   130,   266,
     263,   266,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,    60,    14,    14,    13,   297,   336,   337,
      20,    20,    19,    14,   349,   350,    13,   159,    20,    20,
      22,    23,   164,   165,   166,   167,   168,   335,   336,   337,
     338,   597,   598,    14,    14,    19,    14,   369,   328,    20,
      20,   329,    20,    14,   546,    14,    14,    13,    13,    20,
      15,    20,    20,   388,   544,   197,   198,   199,    14,    14,
     603,   604,    14,    14,    20,    20,   360,   355,    20,    20,
      13,    13,   349,   350,   331,   363,   368,   365,   159,   160,
     161,   297,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,    14,   585,    19,    14,    14,    14,
      20,   389,   390,    20,    20,    20,     0,    14,    14,    14,
      14,   388,   328,    20,    20,    20,    20,  2308,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    13,   406,   407,   408,    14,    14,   411,   412,
      14,   414,    20,    20,    19,    14,    20,    14,    14,   291,
     292,    20,    13,    20,    20,   297,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   310,    19,
      14,    14,    14,    14,   231,   232,    20,    20,    20,    20,
      15,    14,    14,    14,    14,    14,   328,    20,    20,    20,
      20,    20,    14,    14,    14,    14,    14,    14,    20,    20,
      20,    20,    20,    20,    13,    13,    15,    14,    13,   497,
     498,   546,   500,    20,   611,   612,   613,   614,   615,   616,
     159,   160,   161,    20,   512,    22,    13,    13,    13,    13,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,   546,   510,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,   546,
      13,   328,    13,   330,   200,   201,   202,    13,   566,    13,
      13,   207,   208,   209,   210,    13,   212,    13,    13,    13,
     347,    13,    13,    13,    13,    13,    13,    13,    13,    13,
     588,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,    13,    13,    13,   593,
      13,    13,    13,    13,    13,    13,   252,    13,    13,   255,
     256,   257,   258,   259,   260,   623,   624,   263,    13,   627,
      13,   618,   619,    13,   619,    13,    13,    13,    13,    13,
      13,   264,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,   858,    13,
      13,   284,    13,    13,    13,    13,    13,    13,   868,   292,
     293,   294,   295,   296,    13,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,    13,    13,  1178,
      13,    13,  1181,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,   476,
      13,   478,   479,    13,    13,   713,   264,   265,   266,    13,
     268,   269,   270,    13,    13,   273,    13,    13,   276,   277,
     278,   279,   280,   281,   282,   283,    13,    13,   286,    13,
      13,    13,   290,    13,    13,    13,    13,   295,   296,    13,
      13,   518,    13,    13,    13,    13,    13,    13,   306,    13,
     972,     4,    17,   311,   312,    18,   108,    13,    19,    19,
     406,   407,   408,    14,    19,   411,   412,    19,   414,   402,
     547,    15,    15,    19,    19,    78,    78,   291,   334,    15,
      78,    56,   263,    78,    78,    78,    78,   420,    78,    78,
      78,    22,   405,   570,   571,    57,    20,    56,    56,   383,
      14,    14,    20,    14,   159,   159,    14,    13,    65,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,   854,    13,    13,    13,
      13,    13,   397,    20,    69,    16,    15,    14,    16,    14,
      20,    14,    14,    13,    20,    16,    20,    14,    16,    14,
      16,    20,    14,    78,   116,   116,    20,    20,   358,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    14,    20,    20,    20,    20,    13,    19,    14,    20,
      20,    20,    20,   285,    13,    20,    20,    20,    20,    20,
      20,    14,    14,    14,    20,    14,    20,   972,   266,   266,
      20,    14,    20,    20,    20,    20,    20,    14,    16,    20,
      20,  1430,   709,    22,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    14,    20,    14,    20,    20,    20,    78,
      20,    58,    20,    20,    20,    20,    20,    20,    20,    14,
     957,    14,   957,    20,    20,   359,    20,    59,    20,    20,
      20,    20,    20,    20,    20,   972,   984,   985,    20,    20,
     988,   989,   990,   991,   992,   993,    20,   995,   996,    20,
      20,    20,  1000,  1001,  1002,  1003,  1004,  1005,  1006,    14,
    1008,    14,  1010,    14,  1012,  1013,    20,  1015,  1016,  1017,
    1018,  1019,    20,    20,    20,    20,  1024,  1025,  1026,  1027,
    1028,    20,    20,    20,    14,    14,    20,    14,  1036,    14,
      14,    14,    14,    14,    20,    58,    14,    14,    14,    14,
      20,    20,    14,    13,  1052,  1053,    20,  1055,  1056,  1057,
    1058,  1059,    20,  1061,  1062,  1063,  1064,  1065,  1066,    20,
    1068,    20,    20,    13,    20,    20,    20,  1075,  1076,  1077,
    1078,  1079,  1080,  1081,  1082,    20,  1084,    20,   855,    20,
      20,    14,    14,    14,    20,    20,    20,    14,    13,    13,
      20,  1099,    13,    13,    13,  1103,  1104,  1105,    13,    13,
    1108,  1109,  1110,  1111,  1112,  1113,    13,  1115,    13,    13,
    1118,  1119,  1120,  1121,  1122,  1123,  1124,  1125,  1126,  1127,
      13,    13,  1130,    20,    13,   902,    16,    13,    13,    13,
      13,  1139,  1140,  1141,  1142,  1143,  1144,  1145,  1146,  1147,
    1148,  1149,    20,    16,    16,  1153,  1154,    65,  1156,  1157,
    1649,  1159,  1160,  1161,  1162,  1163,    69,    16,  1166,    76,
      76,  1660,    13,  1662,    13,    13,  1174,  1175,    13,    77,
      20,    14,    14,    79,    20,    22,    20,    16,  1186,    20,
      20,   958,    20,    20,    20,  1193,  1194,    14,  1196,  1197,
      20,    14,  1200,  1201,  1202,    14,  1204,    14,  1206,    20,
    1208,  1209,    20,    14,   981,    20,    20,  1215,    20,  1419,
    1420,  1219,  1220,  1221,    14,    20,  1224,    20,    20,    20,
      14,  1229,  1230,  1231,  1232,  1233,  1234,  1235,    20,  1237,
      14,    20,    14,    14,  1242,    20,    14,  1245,   266,    19,
    1248,    20,  1250,  1251,    20,    20,    14,    20,    20,    20,
      14,    14,    14,    20,  1031,    14,  1033,    14,    16,  1256,
    1482,  1256,  1039,    14,    20,    14,    14,    20,    20,    14,
      14,    14,    14,    20,    14,    79,    59,  1189,   266,    20,
    1021,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      14,    14,    20,    20,    20,    20,    14,    14,    20,    20,
      20,    14,    14,    14,    14,    20,    20,   116,   328,    14,
     266,    20,    20,    20,    20,    14,    20,    20,    14,    14,
      14,    14,    20,    20,   606,    14,    14,    14,    20,    20,
      20,  1241,  1310,   266,    20,    20,    20,    20,    20,    20,
      14,    14,    14,    14,  1131,    14,    14,    14,   605,   607,
      20,    14,    14,    14,    20,    20,    14,    14,    14,    59,
      20,    20,    14,   608,    -1,    20,    20,    20,    14,    20,
      20,    20,    20,    20,    14,    20,    14,    20,    20,    59,
      59,    59,    14,    20,    20,    20,  1173,    14,    14,    20,
      20,    20,    14,    14,    14,    20,    20,    20,    14,  1417,
      14,    20,    20,    20,    16,    20,    16,    20,    14,    14,
      14,    20,    56,    14,    14,    56,    14,  1482,    20,    14,
      59,    20,    14,    20,    20,    14,    20,    20,    14,  1216,
      20,    14,    14,    14,    22,    20,  1223,    14,    22,    -1,
      20,    20,    20,  1663,    20,    20,    14,    20,    20,    20,
      20,    14,    14,    14,    20,    20,    14,    14,    22,  1246,
      19,  1970,    14,   266,    20,  1252,  1253,    20,  1486,    20,
      20,  1489,  1490,  1491,  1492,  1482,  1494,    20,  1496,    20,
      20,    20,    20,    20,  1502,  1503,  1504,    20,    20,  1507,
    1508,  1509,  1510,    20,  1512,    20,  1514,    20,  1516,    20,
      14,  1519,  1520,  1521,  1522,    20,    22,    20,  1526,    20,
      20,  1529,    20,    20,    20,  1533,    14,    14,    20,    14,
      20,    20,    56,    59,    20,    14,    20,    20,    20,    20,
      20,    14,  1550,    20,    20,    20,    20,  1555,    20,    14,
      20,  1559,  1560,  1561,  1562,  1563,  1564,  1565,  1566,  1567,
    1568,  1569,  1570,  1571,  1572,  1573,  1574,  1575,  1576,  1577,
    1578,  1548,    20,  1581,    20,    14,    14,    14,    20,    20,
      20,  1589,    14,    14,    20,    20,    20,  1595,  1596,  1597,
    1598,    59,  1600,  1601,  1602,    59,  1604,  1605,    59,    59,
      20,    14,    20,  1611,  1612,  1613,  1614,    14,    20,    20,
      20,  1821,  1620,  1823,    20,  1623,  1624,    20,    14,    14,
    1830,    20,    20,    20,    -1,  1633,  1634,  1635,  1636,    20,
      20,    20,    20,    20,    14,    14,    14,    20,  1646,  1647,
    1648,  1418,    14,    20,    20,  1653,    14,    20,    14,    20,
      20,    20,    14,    20,    14,    20,    14,  1665,  1666,    20,
    1668,  1669,   610,  1671,  1672,  1673,    20,    20,    20,  1677,
    1678,    20,    20,  1681,    14,    20,  1684,    20,  1686,  1687,
    1688,    20,    20,    20,    20,  1693,    14,    14,  1696,    14,
    1698,    20,    14,    14,  1702,  1703,  1704,    20,  1706,  1707,
    1708,    20,    20,    20,    20,    20,    20,    20,  1485,    20,
      20,    20,    14,    14,    20,    20,    14,    20,    14,    14,
      20,    20,    14,    14,    14,    14,    20,    20,    14,   609,
     618,    -1,    20,    20,    -1,    20,    20,    20,    20,    20,
      20,    14,    14,    20,    20,  1753,    14,    14,    14,    14,
      14,    14,    22,    14,    14,    -1,    14,    14,    20,    -1,
      -1,    20,    14,    14,    20,    20,    20,    14,    14,    14,
      20,    20,    14,    14,    14,    14,    14,    20,    14,    14,
      14,    -1,    14,    20,    14,    14,    14,    20,    14,    20,
      14,    14,    14,    20,    14,    20,    14,    14,    -1,    20,
      -1,    20,    14,    -1,    20,    20,    20,    20,    14,    20,
      20,    14,  1820,    20,    -1,    20,    20,    14,    20,    20,
      20,    20,    14,    -1,    20,    20,    20,    20,    14,    20,
      14,    14,    20,    14,    14,    20,    -1,    -1,    20,    -1,
      -1,    20,    20,    20,    20,    20,    20,    20,    20,    14,
      20,    20,    20,    20,    14,    14,  1864,    14,  1866,    20,
    1868,    14,  1870,    14,  1872,    14,    14,    14,    20,  1877,
    1878,    14,  1880,  1881,  1882,  1883,  2086,  1885,  1886,  1887,
    1888,    20,    20,    20,  1892,  1893,    20,    20,    20,    20,
      20,    20,    20,  1901,  1902,    14,    14,  1905,    20,  1907,
      14,  1909,    14,  1911,  1912,  1913,  1914,    14,  1916,  1917,
    1918,  1919,  1920,  1921,    20,  1923,  1924,    14,  1926,  1927,
    1928,  1929,  1899,  1931,  1932,  1933,  1934,  1935,    20,  1937,
      20,    20,    20,    20,    14,    14,    20,    14,    14,  1947,
    1948,  1949,  1950,  1951,  1952,  1953,    20,    20,  1956,    20,
      20,  1959,  1960,    20,  1962,  1963,  1964,    20,    20,    20,
    1968,  1969,    20,    14,  1972,    20,    20,    20,    14,    14,
      20,    20,    14,  1981,  1982,    -1,  1984,    -1,    -1,    -1,
    1988,  1989,    -1,  1991,  1992,    -1,  1994,    -1,  1996,  1997,
      -1,  1999,    -1,  2001,  2002,  2003,  2004,  2005,  2006,  2007,
    2008,  2009,  2010,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    -1,    -1,  1860,  1861,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2112,    -1,    -1,  2115,  2116,    -1,
    2118,  2119,    -1,  2121,  2122,    -1,  2124,  2125,  2126,    -1,
    2128,    -1,    -1,    -1,    -1,  2133,  2134,    -1,  2136,    -1,
    2138,  2139,  2140,  2141,  2142,    -1,  2144,  2145,  2146,  2147,
    2148,  2149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2157,
    2158,  2159,    -1,    -1,    -1,  2132,     0,  2165,  2166,    -1,
      -1,  2169,    -1,  2171,  2172,    -1,    -1,  2175,  2176,    -1,
    2178,  2179,    -1,    -1,    -1,    -1,    -1,  2185,    22,    -1,
      -1,    25,    -1,    -1,  2192,  2193,  2194,    -1,    -1,  2197,
    2198,  2199,  2200,    -1,  2202,    -1,    -1,  2205,  2206,   200,
     201,   202,    -1,    -1,    -1,  2213,   207,   208,   209,   210,
      -1,   212,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   252,    -1,    -1,   255,   256,   257,   258,   259,   260,
      -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2278,    -1,    -1,  2281,  2282,  2283,    -1,    -1,    -1,  2287,
      -1,    -1,  2290,    -1,    -1,    -1,    -1,    -1,  2296,    -1,
    2298,    -1,  2300,    -1,    -1,  2303,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2313,  2314,    -1,  2316,    -1,
      -1,  2319,  2320,  2321,  2322,  2323,    -1,    -1,    -1,  2327,
      -1,  2329,    -1,    -1,  2332,  2333,  2334,  2335,    -1,  2337,
    2338,    -1,  2340,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2373,  2374,  2375,  2376,  2377,
      -1,    -1,    -1,  2381,    -1,  2383,  2384,    -1,  2386,  2387,
    2388,    -1,  2390,  2391,   228,  2393,  2394,  2395,    -1,  2397,
      -1,  2399,  2400,    -1,  2402,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   406,   407,   408,    -1,    -1,
     411,   412,    -1,   414,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2429,   266,    -1,    -1,    -1,  2434,    -1,    -1,    -1,
    2438,  2439,  2440,    -1,    -1,  2443,  2444,    -1,    -1,  2447,
      -1,    -1,  2450,  2451,  2452,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2468,  2469,    -1,    -1,  2472,    -1,    -1,    -1,  2476,    -1,
      -1,  2479,  2480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2490,    -1,    -1,  2493,    -1,    -1,  2496,    -1,
      -1,    -1,    -1,    -1,  2502,  2503,  2504,  2505,    -1,    -1,
      -1,    -1,  2510,  2511,  2512,   349,   350,    -1,    -1,  2517,
    2518,  2519,    -1,    -1,    -1,    -1,  2524,  2525,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   388,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   401,    -1,    -1,
     404,   405,   406,   407,   408,    -1,   410,   411,   412,   413,
     414,   415,   416,   417,   418,    -1,    -1,   421,    -1,    -1,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
      -1,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,    -1,    -1,    -1,    -1,
      -1,    -1,   456,   457,   458,   459,   460,   461,   462,   463,
     464,    -1,    -1,   467,   468,   469,   470,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   480,   481,   482,    -1,
      -1,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,    -1,    -1,    -1,   499,   500,    -1,   502,    -1,
     504,    -1,    -1,    -1,   508,   509,    -1,    -1,    -1,    -1,
     514,   515,   516,   517,    -1,    -1,    -1,    -1,   522,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    -1,   546,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   555,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   573,
     574,   575,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   593,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,
     201,   202,    -1,    -1,    -1,    -1,   207,   208,   209,   210,
      -1,   212,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   252,    -1,    -1,   255,   256,   257,   258,   259,   260,
      -1,    -1,   263,    -1,    -1,   394,   395,   396,   397,   398,
     399,   400,    -1,   402,   403,    -1,    -1,    -1,    -1,    -1,
     409,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     419,   420,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   434,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     449,   450,   451,   452,   453,   454,   455,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   472,   473,   474,    -1,    -1,    -1,     0,
      -1,    -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   496,    -1,    20,
      -1,    -1,   501,    -1,    -1,    26,    27,    28,   507,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     519,   520,   521,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   406,   407,   408,    -1,    60,
     411,   412,    -1,   414,    -1,    -1,    -1,    -1,    -1,   548,
      -1,    -1,    -1,    -1,   553,   554,    -1,   556,   557,    -1,
     559,   560,   561,   562,   563,   564,   565,    -1,   567,   568,
     569,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   617,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   972,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   988,    -1,    -1,    -1,    -1,    -1,
     994,    -1,    -1,   997,    -1,    -1,   187,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     231,   232,    -1,    -1,    -1,    -1,    -1,  1051,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1060,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1071,  1072,  1073,
      -1,    -1,    -1,    -1,    -1,   266,    -1,    -1,    -1,  1083,
      -1,    -1,    -1,    -1,  1088,    -1,  1090,  1091,  1092,  1093,
    1094,    -1,  1096,  1097,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   308,    -1,    -1,
      -1,    -1,    -1,    -1,  1128,    -1,    -1,    -1,    -1,    -1,
    1134,  1135,  1136,  1137,  1138,    -1,    -1,   328,    -1,   330,
     331,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   347,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1195,    -1,    -1,  1198,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   393,   394,   395,   396,   397,   398,   399,   400,
      -1,   402,   403,  1217,  1218,    -1,    -1,    -1,   409,    -1,
      -1,  1225,    -1,  1227,  1228,  1229,  1230,    -1,   419,   420,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   434,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   449,   450,
     451,   452,   453,   454,   455,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   472,   473,   474,    -1,   476,    -1,   478,   479,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   496,    -1,    -1,    -1,    -1,
     501,    -1,    -1,    -1,  1318,  1319,   507,    -1,    -1,   510,
      -1,    -1,   513,    -1,    -1,    -1,    -1,   518,   519,   520,
     521,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1007,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   547,   548,    -1,    -1,
      -1,    -1,   553,   554,    -1,   556,   557,    -1,   559,   560,
     561,   562,   563,   564,   565,    -1,   567,   568,   569,   570,
     571,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   588,    -1,    -1,
    1069,  1070,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   617,   618,   619,    -1,
      -1,    -1,  1101,    -1,    -1,    -1,   627,  1106,  1107,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1482,    -1,
      -1,    -1,  1486,    -1,  1488,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1500,  1501,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   700,
     701,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   709,    -1,
      -1,    -1,    -1,    -1,  1528,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1207,    -1,
      -1,  1210,  1211,    -1,  1548,  1549,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1558,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1566,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1582,  1583,
    1584,  1585,  1586,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1621,  1622,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1638,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1312,    -1,    -1,    -1,    -1,  1317,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   855,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1683,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1362,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   902,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   955,    -1,   957,   958,    -1,    -1,
      -1,    -1,    -1,   964,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     981,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1007,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1031,    -1,  1033,    -1,    -1,    -1,    -1,    -1,  1039,    -1,
      -1,    -1,    -1,  1044,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1530,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1069,  1070,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1899,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1101,    -1,    -1,    -1,    -1,  1106,  1107,    -1,    -1,  1923,
    1924,  1925,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1936,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1131,    -1,    -1,    -1,    -1,    -1,  1615,    -1,    -1,    -1,
    1619,    -1,    -1,  1957,  1958,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1644,    -1,    -1,    -1,    -1,
      -1,    -1,  1173,    -1,    -1,    -1,    -1,    -1,    -1,  1993,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1676,    -1,    -1,
    1679,    -1,    -1,    -1,    -1,    -1,  1207,    -1,    -1,  1210,
    1211,    -1,    -1,    -1,    -1,  1216,    -1,    -1,    -1,    -1,
      -1,    -1,  1223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1246,    -1,    -1,    -1,    -1,
      -1,  1252,  1253,    -1,    -1,  1256,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1312,    -1,    -1,    -1,    -1,  1317,    -1,  2132,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2150,    -1,  2152,    -1,
      -1,  2155,  2156,    -1,    -1,    -1,  2160,  2161,  2162,  2163,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1362,    -1,    -1,    -1,    -1,    -1,    -1,  2182,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2201,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1418,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1941,    -1,  1943,  1944,    -1,  1946,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1485,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2308,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1986,    -1,    -1,
      -1,  2325,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2336,    -1,    -1,    -1,    -1,    -1,    -1,  1530,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2392,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2401,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1600,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1615,    -1,    -1,    -1,  1619,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1644,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2481,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1676,    -1,    -1,  1679,    -1,
      -1,    -1,    -1,  2497,    -1,    -1,    -1,    -1,    -1,    -1,
    1691,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2181,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2196,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2331,    -1,    -1,    -1,    -1,    -1,    -1,  1860,
    1861,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1941,    -1,  1943,  1944,    -1,  1946,    -1,  2426,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2436,    -1,    -1,
      -1,    -1,    -1,  2442,    -1,    -1,    -1,    -1,    -1,    -1,
    2449,     9,    10,    11,    -1,    13,    -1,    -1,    -1,    17,
      -1,    -1,    -1,    -1,    -1,  1986,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,  2478,
      38,    39,    -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    -1,    -1,    -1,    54,    55,    56,    -1,
      58,    -1,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,    -1,   131,    -1,   133,   134,   135,   136,   137,
     138,   139,   140,    -1,    -1,    -1,   144,    -1,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,    -1,    -1,    -1,   162,   163,    -1,    -1,    -1,    -1,
      -1,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,    -1,    -1,    -1,    -1,
    2181,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   229,   230,   231,   232,  2196,    -1,    -1,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
      -1,    -1,   250,   251,   252,    -1,    -1,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   287,
     288,   289,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
      -1,   329,    -1,   331,   332,    -1,   334,    -1,    -1,    -1,
      -1,   339,   340,   341,   342,   343,   344,   345,   346,    -1,
      -1,   349,   350,   351,   352,   353,   354,   355,   356,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2331,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   384,   385,   386,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     398,   399,   400,   401,    -1,   403,   404,    -1,   406,   407,
     408,   409,   410,   411,   412,    -1,   414,   415,   416,   417,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2426,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2436,     0,    -1,    -1,    -1,
      -1,  2442,    -1,    -1,    -1,     9,    10,    11,  2449,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,  2478,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    51,    52,    -1,
      54,    55,    56,    -1,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    -1,    86,    87,    88,    89,    90,    91,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   105,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,    -1,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,    -1,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,    -1,    -1,    -1,   162,   163,
      -1,    -1,    -1,    -1,    -1,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,    -1,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,    -1,
      -1,   255,   256,   257,   258,   259,   260,   261,   262,   263,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   288,   289,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,    -1,   329,   330,   331,   332,   333,
      -1,    -1,    -1,    -1,    -1,   339,   340,   341,   342,   343,
     344,   345,   346,    -1,    -1,   349,   350,   351,   352,   353,
     354,   355,   356,   357,    -1,    -1,    -1,    -1,   362,    -1,
     364,   365,   366,    -1,    -1,    -1,   370,   371,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     384,   385,   386,   387,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   395,   396,    -1,   398,   399,   400,   401,    -1,   403,
     404,    -1,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,    -1,   421,   422,   423,
     424,   425,   426,     9,    10,    11,    -1,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    -1,    42,    43,    44,    45,
      46,    47,    48,    -1,    50,    51,    52,    -1,    54,    55,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
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
     206,   207,   208,   209,   210,   211,   212,   213,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,    -1,    -1,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   288,   289,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,    -1,   329,   330,   331,   332,   333,    -1,    -1,
      -1,    -1,    -1,   339,   340,   341,   342,   343,   344,   345,
     346,    -1,    -1,   349,   350,   351,   352,   353,   354,   355,
     356,   357,    -1,    -1,    -1,    -1,   362,    -1,   364,   365,
     366,    -1,    -1,    -1,   370,   371,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   384,   385,
     386,   387,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   395,
     396,    -1,   398,   399,   400,   401,    -1,   403,   404,    -1,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,    -1,   421,   422,   423,   424,   425,
     426,     9,    10,    11,    -1,    13,    -1,    -1,    -1,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    -1,
      38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    -1,    -1,    -1,    54,    55,    56,    -1,
      58,    -1,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,    -1,   131,    -1,   133,   134,   135,   136,   137,
     138,   139,   140,    -1,    -1,    -1,   144,    -1,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,    -1,    -1,    -1,   162,   163,    -1,    -1,    -1,    -1,
      -1,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   229,   230,   231,   232,    -1,    -1,    -1,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
      -1,    -1,   250,   251,   252,    -1,    -1,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     288,   289,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
      -1,   329,    -1,   331,   332,    -1,    -1,    -1,    -1,    -1,
      -1,   339,   340,   341,   342,   343,   344,   345,   346,    -1,
      -1,   349,   350,   351,   352,   353,   354,   355,   356,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   384,   385,   386,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     398,   399,   400,   401,    -1,   403,   404,    -1,   406,   407,
     408,   409,   410,   411,   412,    -1,   414,   415,   416,   417,
       9,    10,    11,    -1,    13,    -1,    -1,    -1,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    -1,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    -1,    -1,    -1,    54,    55,    56,    -1,    58,
      -1,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   105,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,    -1,   131,    -1,   133,   134,   135,   136,   137,   138,
     139,   140,    -1,    -1,    -1,   144,    -1,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
      -1,    -1,    -1,   162,   163,    -1,    -1,    -1,    -1,    -1,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     229,   230,   231,   232,    -1,    -1,    -1,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,    -1,
      -1,   250,   251,   252,    -1,    -1,   255,   256,   257,   258,
     259,   260,   261,   262,   263,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   288,
     289,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,    -1,
     329,    -1,   331,   332,    -1,    -1,    -1,    -1,    -1,    -1,
     339,   340,   341,   342,   343,   344,   345,   346,    -1,    -1,
     349,   350,   351,   352,   353,   354,   355,   356,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   384,   385,   386,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   398,
     399,   400,   401,    -1,   403,   404,    -1,   406,   407,   408,
     409,   410,   411,   412,    -1,   414,   415,   416,   417,     9,
      10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    -1,    -1,    -1,    54,    55,    56,    -1,    58,    -1,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    -1,    78,    -1,
      80,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   105,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
      -1,   131,    -1,   133,   134,   135,   136,   137,   138,   139,
     140,    -1,    -1,    -1,   144,    -1,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,    -1,
      -1,    -1,   162,   163,    -1,    -1,    -1,    -1,    -1,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
      -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,
     230,   231,   232,    -1,    -1,    -1,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,    -1,    -1,
     250,   251,   252,    -1,    -1,   255,   256,   257,   258,   259,
     260,   261,   262,   263,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   288,   289,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,    -1,   329,
      -1,   331,   332,    -1,    -1,    -1,    -1,    -1,    -1,   339,
     340,   341,   342,   343,   344,   345,   346,    -1,    -1,   349,
     350,   351,   352,   353,   354,   355,   356,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   384,   385,   386,    -1,    -1,    -1,
      -1,    -1,    -1,     9,    10,    11,    -1,    13,   398,   399,
     400,   401,    -1,   403,   404,    -1,   406,   407,   408,   409,
     410,   411,   412,    -1,   414,   415,   416,   417,    34,    35,
      -1,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    54,    55,
      56,    -1,    58,    -1,    60,    61,    62,    63,    64,    65,
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
     206,   207,   208,   209,   210,   211,   212,   213,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   229,   230,   231,   232,    -1,    -1,    -1,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,   250,   251,   252,    -1,    -1,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   288,   289,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,    -1,   329,    -1,   331,   332,    -1,    -1,    -1,
      -1,    -1,    -1,   339,   340,   341,   342,   343,   344,   345,
     346,    -1,    -1,   349,   350,   351,   352,   353,   354,   355,
     356,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   384,   385,
     386,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   398,   399,   400,   401,    -1,   403,   404,    -1,
     406,   407,   408,   409,   410,   411,   412,    -1,   414,   415,
     416,   417,     9,    10,    11,    -1,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,
      -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    -1,    -1,    -1,    54,    55,    56,
      -1,    58,    -1,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      -1,    78,    -1,    80,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,    -1,   131,    -1,   133,   134,   135,   136,
     137,   138,   139,   140,    -1,    -1,    -1,   144,    -1,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,    -1,    -1,    -1,   162,   163,    -1,    -1,    -1,
      -1,    -1,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,    -1,    -1,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   229,   230,   231,   232,    -1,    -1,    -1,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,   250,   251,   252,    -1,    -1,   255,   256,
     257,   258,   259,   260,   261,   262,   263,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   288,   289,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,    -1,   329,    -1,   331,   332,    -1,    -1,    -1,    -1,
      -1,    -1,   339,   340,   341,   342,   343,   344,   345,   346,
      -1,    -1,   349,   350,   351,   352,   353,   354,   355,   356,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   384,   385,   386,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   398,   399,   400,   401,    -1,   403,   404,    -1,   406,
     407,   408,   409,   410,   411,   412,    -1,   414,   415,   416,
     417,     9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    -1,
      38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    -1,    -1,    -1,    54,    55,    56,    -1,
      58,    -1,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    -1,
      78,    -1,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,    -1,   131,    -1,   133,   134,   135,   136,   137,
     138,   139,   140,    -1,    -1,    -1,   144,    -1,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,    -1,    -1,    -1,   162,   163,    -1,    -1,    -1,    -1,
      -1,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   229,   230,   231,   232,    -1,    -1,    -1,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
      -1,    -1,   250,   251,   252,    -1,    -1,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     288,   289,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
      -1,   329,    -1,   331,   332,    -1,    -1,    -1,    -1,    -1,
      -1,   339,   340,   341,   342,   343,   344,   345,   346,    -1,
      -1,   349,   350,   351,   352,   353,   354,   355,   356,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   384,   385,   386,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     398,   399,   400,   401,    -1,   403,   404,    -1,   406,   407,
     408,   409,   410,   411,   412,    -1,   414,   415,   416,   417,
       9,    10,    11,    -1,    13,    -1,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    -1,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    -1,    -1,    -1,    54,    55,    56,    -1,    58,
      -1,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    -1,    78,
      -1,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   105,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,    -1,   131,    -1,   133,   134,   135,   136,   137,   138,
     139,   140,    -1,    -1,    -1,   144,    -1,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
      -1,    -1,    -1,   162,   163,    -1,    -1,    -1,    -1,    -1,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     229,   230,   231,   232,    -1,    -1,    -1,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,    -1,
      -1,   250,   251,   252,    -1,    -1,   255,   256,   257,   258,
     259,   260,   261,   262,   263,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   288,
     289,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,    -1,
     329,    -1,   331,   332,    -1,    -1,    -1,    -1,    -1,    -1,
     339,   340,   341,   342,   343,   344,   345,   346,    -1,    -1,
     349,   350,   351,   352,   353,   354,   355,   356,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   384,   385,   386,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   398,
     399,   400,   401,    -1,   403,   404,    -1,   406,   407,   408,
     409,   410,   411,   412,    -1,   414,   415,   416,   417,     9,
      10,    11,    -1,    13,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,    -1,    -1,    38,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    -1,    -1,    -1,    54,    55,    56,    -1,    58,    -1,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    -1,    78,    -1,
      80,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   105,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
      -1,   131,    -1,   133,   134,   135,   136,   137,   138,   139,
     140,    -1,    -1,    -1,   144,    -1,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,    -1,
      -1,    -1,   162,   163,    -1,    -1,    -1,    -1,    -1,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
      -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,
     230,   231,   232,    -1,    -1,    -1,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,    -1,    -1,
     250,   251,   252,    -1,    -1,   255,   256,   257,   258,   259,
     260,   261,   262,   263,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   288,   289,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,    -1,   329,
      -1,   331,   332,    -1,    -1,    -1,    -1,    -1,    -1,   339,
     340,   341,   342,   343,   344,   345,   346,    -1,    -1,   349,
     350,   351,   352,   353,   354,   355,   356,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   384,   385,   386,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   398,   399,
     400,   401,    -1,   403,   404,    -1,   406,   407,   408,   409,
     410,   411,   412,    -1,   414,   415,   416,   417,     9,    10,
      11,    -1,    13,    -1,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     211,   212,   213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,   230,
     231,   232,    -1,    -1,    -1,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,   250,
     251,   252,    -1,    -1,   255,   256,   257,   258,   259,   260,
     261,   262,   263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   288,   289,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,    -1,   329,    -1,
     331,   332,    -1,    -1,    -1,    -1,    -1,    -1,   339,   340,
     341,   342,   343,   344,   345,   346,    -1,    -1,   349,   350,
     351,   352,   353,   354,   355,   356,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   384,   385,   386,    -1,    -1,    -1,    -1,
      -1,    -1,     9,    10,    11,    -1,    13,   398,   399,   400,
     401,    -1,   403,   404,    -1,   406,   407,   408,   409,   410,
     411,   412,    -1,   414,   415,   416,   417,    34,    35,    -1,
      -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    -1,    -1,    -1,    54,    55,    56,
      -1,    58,    -1,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      -1,    78,    -1,    80,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,    -1,   131,    -1,   133,   134,   135,   136,
     137,   138,   139,   140,    -1,    -1,    -1,   144,    -1,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,    -1,    -1,    -1,   162,   163,    -1,    -1,    -1,
      -1,    -1,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,    -1,    -1,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   229,   230,   231,   232,    -1,    -1,    -1,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,   250,   251,   252,    -1,    -1,   255,   256,
     257,   258,   259,   260,   261,   262,   263,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   288,   289,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,    -1,   329,    -1,   331,   332,    -1,    -1,    -1,    -1,
      -1,    -1,   339,   340,   341,   342,   343,   344,   345,   346,
      -1,    -1,   349,   350,   351,   352,   353,   354,   355,   356,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   384,   385,   386,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,
      13,   398,   399,   400,   401,    -1,   403,   404,    -1,   406,
     407,   408,   409,   410,   411,   412,    -1,   414,   415,   416,
     417,    34,    35,    -1,    -1,    38,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,
      -1,    54,    55,    56,    -1,    58,    -1,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    78,    -1,    80,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   105,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,    -1,   131,    -1,
     133,   134,   135,   136,   137,   138,   139,   140,    -1,    -1,
      -1,   144,    -1,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,    -1,    -1,    -1,   162,
     163,    -1,    -1,    -1,    -1,    -1,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,    -1,    -1,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   229,   230,   231,   232,
      -1,    -1,    -1,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,    -1,    -1,   250,   251,   252,
      -1,    -1,   255,   256,   257,   258,   259,   260,   261,   262,
     263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   288,   289,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,    -1,   329,    -1,   331,   332,
      -1,    -1,    -1,    -1,    -1,    -1,   339,   340,   341,   342,
     343,   344,   345,   346,    -1,    -1,   349,   350,   351,   352,
     353,   354,   355,   356,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   384,   385,   386,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    10,    11,    -1,    13,   398,   399,   400,   401,    -1,
     403,   404,    -1,   406,   407,   408,   409,   410,   411,   412,
      -1,   414,   415,   416,   417,    34,    35,    -1,    -1,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    -1,    -1,    -1,    54,    55,    56,    -1,    58,
      -1,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    -1,    78,
      -1,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   105,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,    -1,   131,    -1,   133,   134,   135,   136,   137,   138,
     139,   140,    -1,    -1,    -1,   144,    -1,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
      -1,    -1,    -1,   162,   163,    -1,    -1,    -1,    -1,    -1,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     229,   230,   231,   232,    -1,    -1,    -1,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,    -1,
      -1,   250,   251,   252,    -1,    -1,   255,   256,   257,   258,
     259,   260,   261,   262,   263,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   288,
     289,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,    -1,
     329,    -1,   331,   332,    -1,    -1,    -1,    -1,    -1,    -1,
     339,   340,   341,   342,   343,   344,   345,   346,    -1,    -1,
     349,   350,   351,   352,   353,   354,   355,   356,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   384,   385,   386,    -1,    -1,
      -1,    -1,    -1,    -1,     9,    10,    11,    -1,    13,   398,
     399,   400,   401,    -1,   403,   404,    -1,   406,   407,   408,
     409,   410,   411,   412,    -1,   414,   415,   416,   417,    34,
      35,    -1,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    54,
      55,    56,    -1,    58,    -1,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    -1,    78,    -1,    80,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     105,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,    -1,   131,    -1,   133,   134,
     135,   136,   137,   138,   139,   140,    -1,    -1,    -1,   144,
      -1,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,    -1,    -1,    -1,   162,   163,    -1,
      -1,    -1,    -1,    -1,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,    -1,    -1,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   229,   230,   231,   232,    -1,    -1,
      -1,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,    -1,    -1,   250,   251,   252,    -1,    -1,
     255,   256,   257,   258,   259,   260,   261,   262,   263,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   288,   289,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,    -1,   329,    -1,   331,   332,    -1,    -1,
      -1,    -1,    -1,    -1,   339,   340,   341,   342,   343,   344,
     345,   346,    -1,    -1,   349,   350,   351,   352,   353,   354,
     355,   356,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   384,
     385,   386,    -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,
      -1,    -1,    13,   398,   399,   400,   401,    -1,   403,   404,
      -1,   406,   407,   408,   409,   410,   411,   412,    -1,   414,
     415,   416,   417,    34,    35,    -1,    -1,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      -1,    -1,    -1,    54,    55,    56,    -1,    58,    -1,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
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
     211,   212,   213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,   230,
     231,   232,    -1,    -1,    -1,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,   250,
     251,   252,    -1,    -1,   255,   256,   257,   258,   259,   260,
     261,   262,   263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   288,   289,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,    -1,   329,    -1,
     331,   332,    -1,    -1,    -1,    -1,    -1,    -1,   339,   340,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   384,   385,   386,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    13,   398,   399,   400,
     401,    -1,   403,   404,    -1,   406,   407,   408,   409,   410,
     411,   412,    -1,   414,   415,   416,   417,    34,    35,    -1,
      -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    -1,    -1,    -1,    54,    55,    56,
      -1,    58,    -1,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      -1,    78,    -1,    80,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,    -1,   131,    -1,   133,   134,   135,   136,
     137,   138,   139,   140,    -1,    -1,    -1,   144,    -1,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,    -1,    -1,    -1,   162,   163,    -1,    -1,    -1,
      -1,    -1,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,    -1,    -1,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   229,   230,   231,   232,    -1,    -1,    -1,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,   250,   251,   252,    -1,    -1,   255,   256,
     257,   258,   259,   260,   261,   262,   263,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   288,   289,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,    -1,   329,    -1,   331,   332,    -1,    -1,    -1,    -1,
      -1,    -1,   339,   340,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   384,   385,   386,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   398,   399,   400,   401,    -1,   403,   404,    -1,   406,
     407,   408,   409,   410,   411,   412,    -1,   414,   415,   416,
     417
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
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    86,    87,    88,    89,    90,    91,   105,   106,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     162,   163,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   288,   289,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   329,   330,   331,   332,   333,
     339,   340,   341,   342,   343,   344,   345,   346,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   362,   364,   365,
     366,   370,   371,   384,   385,   386,   387,   395,   396,   398,
     399,   400,   401,   403,   404,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   421,
     422,   423,   424,   425,   426,   430,   431,   432,   433,   434,
     435,   438,   439,   440,   441,   445,   449,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     477,   478,   479,   480,   481,   482,   483,   484,    13,    65,
      69,    71,    78,    80,    81,   149,   150,   454,   459,   482,
     460,   460,   453,   475,   450,   475,   450,   450,    13,    13,
      13,    13,   452,   475,    78,   369,   454,    56,    72,    73,
      74,    75,   480,   454,   475,   475,   452,    13,   452,    13,
      13,    19,    19,    96,    97,    13,    19,    19,   116,   480,
      19,   164,    19,    15,    95,    15,    61,    62,    63,    64,
      65,    66,    67,    69,    70,    71,    77,    78,    79,    80,
      81,   454,   478,   482,   484,   485,   486,   452,    13,    13,
      13,   460,   460,    13,    13,    15,    13,    13,    15,    13,
      15,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    19,    19,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      15,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,   452,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,   460,   460,   460,   460,   460,   460,   460,
     460,   460,   460,   460,   460,   460,   460,   480,   446,   447,
      80,   486,   450,   432,   452,   452,    13,    13,    13,    13,
      76,   480,   480,    13,    13,    13,    13,    13,    19,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,     0,     0,   432,   433,
     434,   435,   438,   439,   440,   441,   432,    19,    13,    19,
     105,   106,   114,    15,     7,     8,    12,    10,    11,     5,
       6,   110,   111,   112,   113,    17,    18,   108,     4,    21,
     109,    95,    96,    97,    98,    99,   116,    95,   116,    13,
      19,    19,    19,    15,    15,    19,    19,    13,    19,    14,
      14,   452,   450,   452,   453,   452,   486,   486,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   264,   284,   292,   293,   294,   295,   296,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   402,   420,   264,   265,   266,   268,   269,   270,
     273,   276,   277,   278,   279,   280,   281,   282,   283,   286,
     290,   295,   296,   306,   311,   312,    78,    78,   450,   291,
      46,    47,   335,   336,   337,   338,   334,   480,    46,   165,
     450,   263,   450,    15,   486,   450,   450,   451,   475,   451,
     475,   451,   451,   451,   451,   451,   451,   454,   451,   451,
     454,   454,   454,   454,   454,   451,   454,   454,   454,   454,
     454,   454,   454,   454,   454,   451,   451,   454,   159,   160,
     161,   159,   160,   161,   454,   454,   454,   454,   454,   454,
     454,   454,   454,   454,   451,   454,   454,   454,   454,   454,
     454,   454,   454,   454,   454,   454,   454,   454,   454,   451,
     454,   451,   451,   451,   451,   451,   451,   454,   454,   454,
     454,   454,   454,   454,   454,   454,    78,    78,   454,   454,
     454,   454,    78,   451,   451,   451,    78,   452,    78,   452,
     452,   454,   454,   454,    56,    56,   454,   454,   454,   454,
     454,   454,   454,   454,   454,   454,   454,   451,   450,   450,
     454,   450,   454,   451,   454,    78,   454,    78,    78,   451,
     454,   454,    14,   450,   475,   454,   454,   454,   454,   452,
     451,   451,   451,   454,   116,   361,    57,   446,   446,   432,
     480,   486,   452,   451,    56,   437,   436,    22,   446,   451,
     451,   454,   451,   451,   405,   451,   451,   451,   451,   451,
     451,   451,   450,   451,   451,   451,   452,   452,    65,   454,
     454,   454,   432,   383,   450,   475,    53,    54,    92,   130,
     159,   164,   165,   166,   167,   168,   197,   198,   199,   291,
     292,   297,   310,   328,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,    22,    65,   450,   454,
     459,   487,   461,   461,   461,   462,   462,   464,   464,   464,
     464,   465,   465,   466,   468,   469,   470,   472,   471,   474,
     474,   474,   474,   474,   474,   263,   451,    17,    38,    41,
      65,    69,    71,    79,   263,   287,   318,   321,   334,   475,
     476,   483,    17,    69,   443,   475,   484,   450,   450,   450,
     461,    20,    14,    14,    20,    20,    14,    14,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    20,    13,   475,
     475,    13,    13,    13,   452,    16,    15,    16,   450,    20,
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
      20,    20,    20,    20,    14,    14,    20,    14,    14,    14,
      14,    14,    14,    20,    20,    20,    14,   450,   442,   452,
     448,   368,   432,    14,    14,    14,    20,    14,    13,    13,
     397,   432,    14,    20,    20,    20,    20,    20,    13,    14,
      20,    20,    20,    14,    20,    14,    20,    20,    20,    20,
      20,    20,    14,    14,    14,    20,    20,    20,    20,    20,
      22,    23,    14,    13,    13,    13,   452,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    20,    22,    19,    16,
      16,    22,    15,   475,   484,    15,    13,    19,    15,    13,
      13,    13,    13,    20,   486,    14,    20,    16,    16,   452,
     450,   450,   450,   454,   450,   450,   450,   450,   450,   454,
     450,   450,    65,   454,    58,    65,   450,   450,   450,   450,
     450,   450,   450,   451,   450,    69,   450,    76,   450,   450,
      78,   450,   450,   450,   450,   450,    78,    69,   476,    69,
      58,   450,   450,   450,   450,   450,   452,    61,    64,   452,
     116,   450,   116,    16,   452,    76,   475,    13,    13,    13,
      56,   454,   450,   450,   450,   450,   450,   450,   450,   454,
     450,   450,   450,   450,   450,   450,   450,   451,   451,   454,
     454,   454,   450,   450,   450,   450,   450,   450,   450,   450,
     454,   450,   454,   454,   454,   454,   454,   454,   454,   454,
     450,   451,    13,   450,   450,   450,   451,   451,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   454,   450,   452,   454,   454,
     454,   454,   454,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   452,   450,   450,   358,    20,   446,
     446,   450,   388,   389,   390,   391,   392,   394,   444,   444,
      77,   450,   450,   454,   450,   450,   454,   450,   450,   450,
     450,   450,   451,   450,   450,   451,   451,   450,   452,   454,
     454,   450,   450,   450,   452,   450,   454,   454,   454,   450,
     454,   450,   454,   450,   450,   450,   450,   450,    22,   450,
      93,   473,   450,   450,   452,   285,   450,    79,   450,   450,
     452,   452,    17,   475,   484,    20,    20,    14,    20,    20,
      20,    20,    20,    14,    20,    14,    20,    14,    14,    14,
      20,    20,    20,    20,    20,    14,    14,    20,    20,    20,
      20,    14,    20,    14,    20,    14,    20,    14,    14,    20,
      20,    20,    20,    14,    19,    14,    20,    14,    20,    20,
      20,    14,    14,    20,    14,    14,    14,    20,   479,    16,
     451,    14,    14,    14,   451,   454,   454,    14,    20,    20,
      20,    14,    14,    14,    14,    20,    14,    14,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    14,
      14,    20,    20,    20,    20,    20,    20,    14,    14,    20,
      14,   451,    14,    14,    14,    20,    20,    20,    20,    14,
      20,    20,    20,    14,    20,    20,    14,    14,    14,    14,
      14,    20,    20,    20,    20,    20,    14,    14,    14,    20,
      20,    20,    20,    20,    20,    14,    14,    14,    14,    14,
      14,    14,    14,    20,    20,    20,    20,    14,    20,    14,
      14,    14,    14,    14,    20,    14,    20,    20,    20,   450,
     452,   432,   432,    20,    59,    59,    59,    59,    59,    59,
      14,    20,    14,   446,    14,    20,    20,    14,    20,    20,
      14,    20,    20,    20,    14,    14,    20,    20,    20,    20,
      14,    20,    14,    20,    20,    14,    20,    23,    20,    14,
      14,    20,    14,    20,    14,    14,    20,    14,    20,    14,
      14,    14,    20,    20,    20,    14,    20,    20,    20,    16,
      16,    14,    16,    20,    14,    14,    20,   486,   452,   450,
     454,   454,   450,   450,   450,   450,   450,   450,   454,   454,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   454,   450,   451,   450,    56,
      14,    14,    14,    20,   453,   454,    56,   454,   450,   450,
     454,   450,   450,   450,   450,   450,   450,   450,   450,   454,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   454,   454,   454,   454,   454,   450,    14,
     450,   450,   450,   450,   450,   475,   450,   450,   450,   450,
     450,   450,   450,   450,   451,   451,   450,   454,   454,   450,
     450,   450,   450,   450,   450,   454,   451,   450,   450,   450,
     359,   446,   450,   446,   388,   389,   390,   391,   392,   394,
     446,   432,   450,   450,   450,   450,   450,   450,   450,   451,
     450,   450,   451,   450,   454,   450,   450,   450,   450,   475,
     450,   450,   450,   450,   450,   450,   450,   450,   450,    79,
      20,    20,    56,    14,    20,    14,    20,    14,    20,    14,
      20,    14,    20,    14,    14,    14,    14,    20,    20,    14,
      20,    20,    20,    20,    14,    20,    20,    20,    20,    14,
      14,    14,    20,    20,    14,   450,    14,    19,    14,    20,
      20,    20,    20,    14,    14,    20,    14,    20,    14,    20,
      14,    20,    20,    20,    20,    14,    20,    20,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    20,    20,    20,
      14,    20,    20,    20,    20,    20,    20,    20,    14,    14,
      14,    20,    14,    20,    20,    14,    20,    20,    20,    20,
      20,    20,    20,    20,    14,    14,    20,    20,    20,    20,
      20,    14,    20,    20,    20,    14,    14,    14,    20,    20,
     450,   432,    20,   432,    59,    59,    59,    59,    59,    59,
     432,    20,    20,    14,    20,    14,    20,    14,    20,    20,
      14,    20,    20,    20,    20,    14,    20,    23,    14,    22,
      14,    20,    20,    20,    20,    20,    20,    20,    22,    22,
      20,   452,   452,    14,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,    14,   453,    56,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     487,   450,   487,   487,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   454,   450,   451,   451,   451,   451,   450,
     450,   450,   450,   450,   450,   450,   450,   454,   454,   450,
     450,   450,   450,   450,   450,   450,   446,   450,   450,   450,
     450,   451,   450,   450,   450,   450,   454,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,    14,    20,    14,    14,    20,    20,    14,    20,    20,
      14,    20,    20,    14,    20,    20,    20,    14,    20,    14,
      14,    14,    20,    20,    20,    14,    20,    14,    20,    20,
      20,    20,    20,    14,    20,    20,    20,    20,    20,    20,
      20,    14,    20,    14,    14,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    14,    20,    20,    14,    14,    20,
      14,    20,    20,    14,    14,    20,    20,    14,    20,    20,
      14,    20,    20,    14,    14,    20,    14,    14,    14,    14,
      14,   432,    20,    20,    20,    14,    20,    20,    20,    20,
      20,    20,    20,    14,    14,    20,    20,    14,    14,    14,
      14,    14,    14,    20,    14,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   453,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   487,   487,   487,   487,   450,   450,   450,   454,   454,
     454,   454,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   451,   454,   450,   450,   450,   450,   451,   450,   450,
     450,   450,   454,   450,   450,   450,   450,    14,    20,    14,
      14,    20,    20,    20,    14,    14,    14,    20,    14,    14,
      20,    14,    14,    14,    14,    14,    20,    14,    20,    14,
      20,    14,    14,    20,    14,    14,    14,    14,    20,    14,
      14,    14,    14,    20,    20,    14,    20,    14,    14,    20,
      20,    20,    20,    20,    14,    20,    14,    20,    14,    20,
      14,    20,    20,    20,    20,    20,    20,    20,    22,    14,
      22,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   487,   450,   450,   450,   450,   450,   450,   450,   450,
     454,   450,   450,   451,   450,   450,   450,   450,   454,   450,
     450,   450,    14,    20,    20,    20,    20,    20,    14,    14,
      14,    20,    14,    20,    20,    14,    20,    20,    20,    14,
      20,    20,    20,    20,    20,    20,    14,    20,    14,    20,
      20,    20,    20,    14,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   454,   450,   450,
     450,   450,   450,   450,   454,   450,   116,    14,    14,    20,
      14,    14,    14,    14,    20,    14,    20,    14,    20,    20,
      20,    14,    20,    20,    20,    14,    14,    20,    14,    20,
      20,    20,    20,   451,   450,   450,   451,   450,   450,   450,
     451,   450,   450,   450,   451,   450,   450,   450,    20,    20,
      14,    14,    20,    14,    14,    14,    20,    14,    20,    20,
      20,    20,   450,   450,   450,   450,   451,   450,   450,   454,
      20,    14,    14,    20,    14,    14,    20,    20,   450,   450,
     450,   454,    20,    20,    20,    20,   450,   450,   450,   450,
      20,    20,    20,    14,   450,   450,   450,    20,    20,    20,
     450,   450,   450,    14,    20,    20,   450,   450,    14,    14
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
     675,   676,   677,   678,   679,   680,   681,   682,   683
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  Parser::yyr1_[] =
  {
         0,   429,   430,   430,   431,   431,   431,   431,   431,   431,
     431,   431,   431,   431,   431,   431,   431,   431,   431,   431,
     432,   432,   433,   433,   433,   433,   433,   434,   434,   436,
     435,   437,   435,   438,   438,   439,   440,   440,   440,   441,
     441,   441,   441,   441,   441,   441,   441,   441,   441,   441,
     441,   441,   441,   441,   441,   441,   441,   441,   441,   441,
     441,   441,   441,   441,   441,   441,   441,   441,   441,   441,
     441,   441,   441,   441,   441,   441,   441,   441,   441,   441,
     441,   441,   441,   441,   441,   441,   441,   441,   441,   441,
     441,   441,   441,   441,   441,   441,   441,   441,   441,   441,
     441,   441,   441,   441,   441,   441,   441,   441,   441,   441,
     441,   441,   441,   441,   441,   441,   441,   441,   441,   441,
     441,   441,   441,   441,   441,   441,   441,   441,   441,   441,
     441,   441,   441,   441,   441,   441,   441,   441,   441,   441,
     441,   441,   441,   441,   441,   441,   441,   441,   441,   441,
     441,   441,   441,   441,   441,   441,   441,   441,   441,   441,
     441,   441,   441,   441,   441,   441,   441,   441,   441,   441,
     441,   441,   441,   441,   441,   441,   441,   441,   441,   441,
     441,   441,   441,   441,   441,   441,   441,   441,   441,   441,
     441,   441,   441,   441,   441,   441,   441,   441,   441,   441,
     441,   441,   441,   441,   441,   441,   441,   441,   441,   441,
     441,   441,   441,   441,   441,   441,   441,   441,   441,   441,
     441,   442,   442,   443,   443,   443,   443,   443,   443,   443,
     444,   444,   444,   444,   444,   444,   444,   444,   444,   444,
     444,   444,   444,   445,   445,   445,   445,   445,   445,   445,
     446,   447,   448,   449,   449,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   449,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   449,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   449,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   449,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   449,   449,   449,   449,   449,   449,
     449,   449,   450,   451,   452,   453,   453,   453,   453,   453,
     453,   453,   453,   453,   453,   453,   453,   454,   454,   455,
     455,   455,   455,   455,   455,   455,   455,   455,   455,   455,
     455,   455,   455,   455,   455,   455,   455,   455,   455,   455,
     455,   455,   455,   455,   455,   455,   455,   455,   455,   455,
     455,   455,   455,   455,   455,   455,   455,   455,   455,   455,
     455,   455,   455,   455,   455,   455,   455,   455,   455,   455,
     455,   455,   455,   455,   455,   455,   455,   455,   455,   455,
     455,   455,   455,   455,   455,   455,   455,   455,   455,   455,
     455,   455,   455,   455,   455,   455,   455,   455,   455,   455,
     455,   455,   455,   455,   455,   455,   455,   455,   455,   455,
     455,   455,   455,   455,   455,   455,   455,   455,   455,   455,
     455,   455,   455,   455,   455,   455,   455,   455,   455,   455,
     455,   455,   455,   455,   455,   455,   455,   455,   455,   455,
     455,   455,   455,   455,   455,   455,   456,   457,   458,   458,
     459,   459,   459,   459,   459,   459,   459,   459,   459,   459,
     459,   459,   459,   459,   460,   460,   460,   460,   460,   460,
     460,   461,   461,   461,   461,   461,   461,   461,   461,   461,
     461,   461,   461,   461,   461,   461,   461,   461,   461,   461,
     461,   462,   462,   462,   462,   463,   463,   463,   464,   465,
     465,   465,   465,   465,   466,   466,   466,   467,   467,   468,
     469,   469,   470,   470,   471,   471,   472,   472,   473,   473,
     474,   474,   474,   474,   474,   474,   474,   475,   476,   476,
     476,   476,   477,   477,   477,   478,   478,   478,   479,   479,
     479,   479,   479,   479,   479,   479,   479,   479,   479,   479,
     479,   479,   479,   479,   479,   479,   479,   479,   479,   479,
     479,   479,   479,   479,   479,   479,   479,   479,   479,   479,
     479,   479,   480,   481,   482,   482,   482,   482,   482,   482,
     483,   483,   483,   483,   483,   483,   483,   484,   484,   485,
     485,   485,   485,   485,   485,   485,   485,   485,   485,   486,
     486,   487,   487,   487,   487,   487
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
       4,     2,     2,     2,     3,    10,     6,     3,     6,     6,
       8,    28,     8,     8,     3,     8,    12,     6,     6,    16,
       8,    16,    10,     6,    10,     8,    10,    14,     8,    12,
       6,     8,     6,     6,     3,     3,     2,     6,    10,     6,
      10,    10,    12,     6,     6,     3,     3,     3,     3,     4,
       3,     6,     6,     4,    20,    10,     6,     3,     3,     6,
       3,     6,     8,     6,     6,     8,    16,     6,     3,     6,
       8,     3,    12,    12,    12,    10,     3,     3,     8,     8,
      10,     8,    10,    12,     6,     8,    10,    16,    18,    12,
       6,    18,    16,    12,    10,    10,    10,     6,    10,     6,
       6,     6,     8,     4,     4,     8,     4,    18,     4,     1,
       1,     1,     6,     3,     4,     1,     1,     1,    30,    24,
       8,     1,     3,     0,     1,     3,     2,     4,     1,     3,
       0,     2,     2,     2,     2,     2,     2,     4,     4,     4,
       4,     4,     4,     1,     6,     1,     3,     4,     4,     1,
       3,     0,     0,     1,     1,     1,     1,     6,     8,    10,
      10,    10,     8,     6,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     6,     4,    10,     4,
      10,     4,     4,     4,     4,     4,     4,     7,     7,     7,
       9,     7,     6,     4,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     6,    10,     4,     4,     4,     3,     6,
       6,     6,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     4,     2,
       4,     4,     1,    10,    12,     8,     1,     6,     6,     6,
       8,     8,     6,     8,     8,    10,    10,    12,    12,    10,
       4,    10,     4,     6,     4,     4,     4,    12,     4,    12,
      12,    16,    20,    10,    12,     4,     6,     6,     6,     4,
       4,     6,     4,     6,     6,     6,    16,    10,     8,    12,
      10,     8,    12,     8,    12,     8,    12,    12,    14,    12,
      12,    16,     4,     8,    10,    12,    10,    12,    10,    12,
      12,    14,    12,     8,    14,     4,     4,     4,     4,     3,
       3,     3,     6,     6,     6,     6,     8,    14,    12,    14,
      12,     6,     8,    10,    10,    12,     6,     6,     6,     6,
       6,     6,     6,     6,     8,    10,     4,     4,    10,    10,
       4,     6,     6,    12,    30,     8,     6,     4,     6,     4,
       6,     4,     4,    18,     8,     6,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     6,     4,     3,     1,     2,     2,     2,     2,     4,
       4,     1,     4,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     3,     3,     3,     1,     3,     3,     1,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     1,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     5,
       1,     3,     3,     3,     3,     3,     3,     1,     1,     3,
       8,     4,     6,     1,     4,     1,     4,     1,     6,     6,
       8,     8,     4,     6,     6,     6,     6,     3,     2,     4,
       6,     4,     4,    10,     6,    16,    18,    10,    20,    14,
       4,     6,     8,     8,    12,    16,    16,    18,    14,    14,
      16,    20,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,    11,     7,     7,     3,     1
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
  "T_ReadCTALineRadii", "T_SetIsoContour", "T_SetIsoContourParam",
  "T_DrawIsoContour", "T_SetIsoContourColor", "T_DrawAllContours",
  "T_AllContoursParam", "T_GetZmin", "T_GetZmax", "T_GetYmin", "T_GetYmax",
  "T_GetXmin", "T_GetXmax", "T_GetXPos", "T_GetYPos", "T_GetZPos",
  "T_vtkDicomRead", "T_vtkMINCRead", "T_Convolve", "T_ConvolveMask",
  "T_Pad", "T_Eigen2D", "T_Eigen3D", "T_ChamferDT", "T_Chamfer2DT",
  "T_BorgeforsDT", "T_BorgeforsSDT", "T_vtkSignedBorgefors",
  "T_vtkSignedFMDist", "T_PropagationDist", "T_PropagationDist2",
  "T_PropDanielsson", "T_vtkPropDanielsson", "T_vtkPropDaniel2", "T_CC",
  "T_ProcessXEvents", "T_ProcessEvents", "T_isoarea2D", "T_posarea",
  "T_isosurf", "T_isosurf_inv", "T_isosurf_ijk", "T_isosurf_ras",
  "T_vtkDecimate", "T_vtkMarchingCubes", "T_vtkSmooth",
  "T_vtkWindowedSinc", "T_isoline", "T_vtkDist", "T_AndreDist",
  "T_Surface", "T_getimage", "T_GetImageFromX", "T_rotate", "T_computeCC",
  "T_drawCC", "T_addobj", "T_setcurrentobj", "T_writeVRML", "T_writeVTK",
  "T_Paint", "T_SetLight", "T_SetLightPos", "T_SetLightAmbient",
  "T_SetLightDiffuse", "T_SetLightSpecular", "T_SetBackground",
  "T_Normalize", "T_Center", "T_Remove", "T_SwapBuffers",
  "T_SetOpacityImage", "T_GetTransform", "T_SetTransform", "T_Interpolate",
  "T_Matrix", "T_Invert", "T_PrintMatrices", "SET", "SETPOS", "SHOWCURSOR",
  "T_update", "COMPARE", "SETVECTOR", "T_lininterp",
  "T_SetCompareDisplacement", "T_DrawVector", "T_DisplayVectors",
  "T_SetVectParam", "T_SetVectColor", "T_SetVectStyle",
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
  "T_amiOFVar2D", "prefix", "postfix", "$accept", "start", "list_commands",
  "end_instr", "loop_inst", "cond_inst", "proc_decl", "$@1", "$@2",
  "class_decl", "object_decl", "func_inst", "command", "exprstringlist",
  "param_list", "param_list_decl", "primary_expr_string", "instr_block",
  "begin_block", "end_block", "float_variable", "expr", "expr_image",
  "expr_string", "basic_type", "var_image", "image", "image_variable",
  "surface_variable", "string_variable", "primary_var", "postfix_var",
  "prefix_var", "multiplicative_var", "additive_var", "shift_var",
  "relational_var", "equality_var", "and_var", "exclusive_or_var",
  "inclusive_or_var", "logical_and_var", "logical_xor_var",
  "logical_or_var", "conditional_var", "assignment_var", "expr_var",
  "gltransform", "matrix_variable", "var_surface", "surface", "identifier",
  "variable_with_assign", "function_variable", "variable_without_assign",
  "unprocessed_variable", "processed_variable", "variable", "image_extent", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Parser::rhs_number_type
  Parser::yyrhs_[] =
  {
       430,     0,    -1,    -1,   431,     0,    -1,   432,    -1,   431,
     432,    -1,   441,   432,    -1,   431,   441,   432,    -1,   433,
      -1,   431,   433,    -1,   434,    -1,   431,   434,    -1,   440,
      -1,   431,   440,    -1,   435,    -1,   431,   435,    -1,   438,
      -1,   431,   438,    -1,   439,    -1,   431,   439,    -1,    37,
      -1,    23,    -1,   357,   480,   116,   450,   358,   450,   446,
     432,    -1,   357,   480,   116,   450,   358,   450,   359,   450,
     446,   432,    -1,   357,   480,   361,   442,   446,   432,    -1,
     362,   446,    -1,   364,   486,   446,    -1,   366,   450,   446,
     432,    -1,   366,   450,   446,   368,   446,   432,    -1,    -1,
     395,   480,   436,    13,   444,    14,   446,   432,    -1,    -1,
     395,    76,   437,    13,   444,    14,   446,   432,    -1,   396,
     480,   446,   432,    -1,   396,   480,    22,   397,    77,   446,
     432,    -1,    77,   480,    -1,   370,   452,   432,    -1,   370,
     432,    -1,   371,   452,    -1,   484,    -1,   475,    -1,    36,
      -1,   365,    -1,    86,    -1,    88,    -1,    89,    -1,    87,
      -1,    90,    13,   450,    14,    -1,    91,    13,   450,    20,
      76,    14,    -1,   480,   116,    17,   484,    -1,   480,   116,
      17,   475,    -1,   480,   116,   475,    -1,   480,   116,   475,
      20,   452,    -1,   480,   116,   483,    -1,   480,   116,   263,
      15,   450,    16,    -1,   480,    95,   263,    15,   450,    16,
      -1,   480,   116,    38,    15,   450,    16,    -1,   480,    95,
     451,    -1,    81,    15,   450,    16,   116,   451,    -1,   480,
     116,   476,    -1,    80,    15,   450,    16,   116,   479,    -1,
      80,    95,   263,    15,   450,    16,    -1,   480,   116,   321,
      13,   450,    14,    -1,   480,   116,   321,    13,   450,    14,
      20,   452,    -1,   480,   116,   318,    13,   450,    14,    -1,
     480,   116,   318,    13,   450,    14,    20,   452,    -1,   480,
     116,   334,    13,   452,    20,    56,    14,    -1,    71,   116,
     334,    13,   452,    20,    56,    14,    -1,    71,    19,   338,
      -1,    24,    -1,    25,    -1,    26,   450,    -1,    27,   450,
      -1,    29,    -1,    30,    -1,    28,   450,    -1,    31,    13,
     452,    20,   452,    20,   452,    14,    -1,    32,    13,   450,
      14,    -1,    33,    13,   452,    14,    -1,    44,    -1,    42,
     454,    -1,    45,   454,    -1,    42,    78,    -1,   454,    19,
      92,    13,   450,    20,   475,    14,    -1,   454,    13,   450,
      22,   450,    20,   450,    22,   450,    20,   450,    22,   450,
      14,   116,   451,    -1,    42,   369,    -1,    84,    13,   486,
      20,   452,    14,    -1,    82,   486,    -1,    83,   452,    -1,
      82,    80,    15,   450,    16,    -1,    51,   452,    -1,    52,
      -1,    43,    -1,    43,   480,    -1,    43,    75,    -1,    43,
      72,    -1,    43,    73,    -1,    43,    74,    -1,    43,    56,
      -1,    71,    19,    46,   475,    -1,    71,    19,    47,   475,
      -1,    46,   475,    -1,    47,   475,    -1,    48,   452,    -1,
      71,    19,   335,    -1,    65,    19,   292,    13,   450,    20,
     450,    20,   450,    14,    -1,    65,    19,   293,    13,   450,
      14,    -1,    65,    19,   294,    -1,    65,    19,   295,    13,
     454,    14,    -1,    65,    19,   295,    13,    65,    14,    -1,
      65,    19,   298,    13,    65,    20,   454,    14,    -1,    65,
      19,   402,    13,   450,    20,   450,    20,   450,    20,   450,
      20,   450,    20,   450,    20,   450,    20,   450,    20,   450,
      20,   450,    20,   450,    20,   450,    14,    -1,    65,    19,
     296,    13,    58,    20,   454,    14,    -1,    65,    19,   299,
      13,   450,    20,   450,    14,    -1,    65,    19,   300,    -1,
      65,    19,   301,    13,   450,    20,   450,    14,    -1,    65,
      19,   302,    13,   450,    20,   450,    20,   450,    20,   450,
      14,    -1,    65,    19,   303,    13,   450,    14,    -1,    65,
      19,   304,    13,   450,    14,    -1,    65,    19,   305,    13,
     450,    20,   450,    20,   450,    20,   450,    20,   450,    20,
     450,    14,    -1,    65,    19,   306,    13,   450,    20,   450,
      14,    -1,    65,    19,   308,    13,   450,    20,   450,    20,
     450,    20,   450,    20,   450,    20,   450,    14,    -1,    65,
      19,   307,    13,   451,    20,   450,    20,   450,    14,    -1,
      65,    19,   309,    13,    69,    14,    -1,    65,    19,   214,
      13,   450,    20,   454,    20,   450,    14,    -1,    65,    19,
     214,    13,   454,    20,   450,    14,    -1,    65,    19,   215,
      13,   450,    20,   450,    20,   450,    14,    -1,    65,    19,
     215,    13,   450,    20,   450,    20,   450,    20,   450,    20,
     450,    14,    -1,    65,    19,   216,    13,   450,    20,   450,
      14,    -1,    65,    19,   217,    13,   450,    20,   450,    20,
     450,    20,   450,    14,    -1,    65,    19,   218,    13,   450,
      14,    -1,    65,    19,   219,    13,   450,    20,   450,    14,
      -1,    65,    19,   420,    13,    76,    14,    -1,    65,    19,
     284,    13,   454,    14,    -1,   454,    19,   159,    -1,   454,
      19,   164,    -1,    78,   164,    -1,   454,    19,   310,    13,
     450,    14,    -1,   454,    19,   310,    13,   450,    20,   450,
      20,   450,    14,    -1,   454,    19,   291,    13,   450,    14,
      -1,   454,    19,   291,    13,   450,    20,   450,    20,   450,
      14,    -1,   454,    19,   292,    13,   450,    20,   450,    20,
     450,    14,    -1,   454,    19,   130,    13,   454,    20,   450,
      20,   450,    20,   450,    14,    -1,   454,    19,   130,    13,
     454,    14,    -1,   454,    19,    53,    13,   452,    14,    -1,
     149,    19,   160,    -1,   149,    19,   161,    -1,   150,    19,
     160,    -1,   150,    19,   161,    -1,   454,    19,   165,   452,
      -1,   454,    19,   166,    -1,   454,    19,   167,    13,   454,
      14,    -1,   454,    19,   168,    13,   454,    14,    -1,   418,
      13,   452,    14,    -1,   419,    13,    65,    20,   450,    20,
     450,    20,   450,    20,   450,    20,   450,    20,   450,    20,
     450,    20,   450,    14,    -1,    69,    19,   266,    13,   450,
      20,   450,    20,   450,    14,    -1,    69,    19,   269,    13,
      78,    14,    -1,    69,    96,    78,    -1,    69,    97,    78,
      -1,    69,    19,   282,    13,    78,    14,    -1,    69,    19,
     283,    -1,    69,    19,   268,    13,   450,    14,    -1,    69,
      19,   268,    13,   450,    20,   450,    14,    -1,    69,    19,
     270,    13,   450,    14,    -1,    69,    19,   295,    13,    69,
      14,    -1,    69,    19,   296,    13,    58,    20,   454,    14,
      -1,    69,    19,   311,    13,   450,    20,   451,    20,   450,
      20,   450,    20,   450,    20,   450,    14,    -1,    69,    19,
     312,    13,   450,    14,    -1,    69,    19,   290,    -1,    69,
      19,   286,    13,   476,    14,    -1,    69,    19,   286,    13,
     476,    20,   450,    14,    -1,    69,    19,   273,    -1,    69,
      19,   276,    13,   450,    20,   450,    20,   450,    20,   450,
      14,    -1,    69,    19,   277,    13,   450,    20,   450,    20,
     450,    20,   450,    14,    -1,    69,    19,   278,    13,   450,
      20,   450,    20,   450,    20,   450,    14,    -1,    69,    19,
     279,    13,   450,    20,   450,    20,   450,    14,    -1,    69,
      19,   280,    -1,    69,    19,   281,    -1,    69,    19,   306,
      13,   450,    20,   450,    14,    -1,   190,    13,   454,    20,
     450,    20,   450,    14,    -1,   190,    13,   454,    20,   450,
      20,   450,    20,   451,    14,    -1,   191,    13,   454,    20,
     450,    20,   450,    14,    -1,   191,    13,   454,    20,   450,
      20,   450,    20,   451,    14,    -1,   191,    13,   454,    20,
     450,    20,   450,    20,   451,    20,   450,    14,    -1,   192,
      13,   454,    20,   450,    14,    -1,   192,    13,   454,    20,
     450,    20,   475,    14,    -1,   192,    13,   454,    20,   450,
      20,   450,    20,   451,    14,    -1,   194,    13,   454,    20,
     450,    20,   450,    20,   450,    20,   450,    20,   450,    20,
     450,    14,    -1,   194,    13,   454,    20,   450,    20,   450,
      20,   450,    20,   450,    20,   450,    20,   450,    20,   451,
      14,    -1,   193,    13,   454,    20,   450,    20,   450,    20,
     451,    20,   450,    14,    -1,   195,    13,   454,    20,   450,
      14,    -1,   235,    13,    56,    20,   454,    20,   454,    20,
     454,    20,   454,    20,   454,    20,   454,    20,   451,    14,
      -1,   235,    13,    56,    20,   454,    20,   454,    20,   454,
      20,   454,    20,   454,    20,   454,    14,    -1,   234,    13,
      56,    20,   454,    20,   454,    20,   454,    20,   451,    14,
      -1,   234,    13,    56,    20,   454,    20,   454,    20,   454,
      14,    -1,   197,    13,   454,    20,   450,    20,   450,    20,
     450,    14,    -1,   454,    19,   197,    13,   450,    20,   450,
      20,   450,    14,    -1,   454,    19,   197,    13,   454,    14,
      -1,   454,    19,   198,    13,   450,    20,   450,    20,   450,
      14,    -1,   454,    19,   198,    13,   454,    14,    -1,   454,
      19,   199,    13,   450,    14,    -1,   132,    13,   454,    20,
     454,    14,    -1,   132,    13,   454,    20,   454,    20,   454,
      14,    -1,   248,    13,   450,    14,    -1,   249,    13,   450,
      14,    -1,   330,    13,   451,    20,   452,    20,   450,    14,
      -1,   333,    13,   454,    14,    -1,   233,    13,   454,    20,
     454,    20,   450,    20,   450,    20,   450,    20,   450,    20,
     450,    20,   450,    14,    -1,   387,    13,    56,    14,    -1,
     142,    -1,   143,    -1,   145,    -1,   421,    13,   454,    20,
     452,    14,    -1,    79,    19,    46,    -1,    79,    19,   165,
     452,    -1,   422,    -1,   423,    -1,   424,    -1,   425,    13,
     454,    20,   454,    20,   454,    20,   454,    20,   454,    20,
     454,    20,   454,    20,   450,    20,   450,    20,   450,    20,
     450,    20,   450,    20,   450,    20,   450,    14,    -1,   426,
      13,   454,    20,   454,    20,   450,    20,   450,    20,   450,
      20,   450,    20,   450,    20,   450,    20,   454,    20,   454,
      20,   450,    14,    -1,   413,    13,   450,    20,   450,    20,
     450,    14,    -1,   452,    -1,   442,    20,   452,    -1,    -1,
     484,    -1,   443,    20,   484,    -1,    17,   486,    -1,   443,
      20,    17,   486,    -1,   475,    -1,   443,    20,   475,    -1,
      -1,   391,    59,    -1,   394,    59,    -1,   392,    59,    -1,
     388,    59,    -1,   389,    59,    -1,   390,    59,    -1,   444,
      20,   394,    59,    -1,   444,    20,   391,    59,    -1,   444,
      20,   392,    59,    -1,   444,    20,   388,    59,    -1,   444,
      20,   389,    59,    -1,   444,    20,   390,    59,    -1,    56,
      -1,    50,    13,   452,    20,   450,    14,    -1,   144,    -1,
     454,    19,    54,    -1,    54,    13,   486,    14,    -1,    55,
      13,   486,    14,    -1,    34,    -1,   447,    57,   448,    -1,
      -1,    -1,    58,    -1,    35,    -1,   339,    -1,   340,    -1,
     454,    13,   450,    20,   450,    14,    -1,   454,    13,   450,
      20,   450,    20,   450,    14,    -1,   454,    19,   297,    13,
     450,    20,   450,    20,   450,    14,    -1,   454,    13,   450,
      20,   450,    20,   450,    20,   450,    14,    -1,   454,    13,
     450,    20,   450,    20,   450,    23,   450,    14,    -1,   454,
      13,   450,    20,   450,    23,   450,    14,    -1,   454,    13,
     450,    23,   450,    14,    -1,   454,    19,   372,    -1,   454,
      19,   373,    -1,   454,    19,   374,    -1,   454,    19,   375,
      -1,   454,    19,   376,    -1,   454,    19,   377,    -1,   454,
      19,   378,    -1,   454,    19,   379,    -1,   454,    19,   380,
      -1,   454,    19,   381,    -1,   454,    19,   382,    -1,   454,
      19,   383,    -1,   163,    13,   454,    20,   454,    14,    -1,
     182,    13,   454,    14,    -1,   250,    13,   454,    20,   450,
      20,   450,    20,   450,    14,    -1,   251,    13,   454,    14,
      -1,   251,    13,   450,    20,   450,    20,   450,    20,   450,
      14,    -1,   117,    13,   451,    14,    -1,   184,    13,   451,
      14,    -1,   118,    13,   451,    14,    -1,   119,    13,   451,
      14,    -1,   120,    13,   451,    14,    -1,   121,    13,   451,
      14,    -1,   118,    15,   451,    16,    13,   451,    14,    -1,
     120,    15,   451,    16,    13,   454,    14,    -1,   121,    15,
     451,    16,    13,   454,    14,    -1,   121,    15,   451,    16,
      13,   454,    20,   450,    14,    -1,   184,    15,   451,    16,
      13,   451,    14,    -1,   184,    13,   454,    20,   451,    14,
      -1,   329,    13,   452,    14,    -1,    65,    19,   224,    -1,
      65,    19,   225,    -1,    65,    19,   222,    -1,    65,    19,
     223,    -1,    65,    19,   220,    -1,    65,    19,   221,    -1,
      65,    19,   226,    -1,    65,    19,   227,    -1,    65,    19,
     228,    -1,    70,    13,   450,    20,   450,    14,    -1,    70,
      19,   291,    13,   450,    20,   450,    20,   450,    14,    -1,
     384,    13,   480,    14,    -1,   384,    13,   486,    14,    -1,
     385,    13,   452,    14,    -1,   453,    19,   383,    -1,    71,
      19,   336,    13,   452,    14,    -1,    71,    19,   337,    13,
      61,    14,    -1,    71,    19,   337,    13,    64,    14,    -1,
     475,    -1,   475,    -1,   475,    -1,   317,    -1,   318,    -1,
     319,    -1,   320,    -1,   321,    -1,   322,    -1,   323,    -1,
     324,    -1,   325,    -1,   326,    -1,   327,    -1,   454,    19,
     328,    -1,    60,    -1,    81,    15,   450,    16,    -1,    38,
     452,    -1,   229,    13,   452,    14,    -1,   230,    13,   452,
      14,    -1,    39,    -1,    38,    13,   453,    20,   450,    20,
     450,    20,   450,    14,    -1,    38,    13,   453,    20,   450,
      20,   450,    20,   450,    20,   450,    14,    -1,    38,    13,
     453,    20,   450,    20,   454,    14,    -1,   454,    -1,   185,
      13,   451,    20,   450,    14,    -1,   186,    13,   451,    20,
     450,    14,    -1,   187,    13,   451,    20,   450,    14,    -1,
     188,    13,   451,    20,   451,    20,   450,    14,    -1,   189,
      13,   451,    20,   451,    20,   450,    14,    -1,   122,    13,
     454,    20,    56,    14,    -1,   122,    13,   454,    20,    56,
      20,   453,    14,    -1,   122,    13,   454,    20,   454,    20,
      56,    14,    -1,   122,    13,   454,    20,   454,    20,    56,
      20,   453,    14,    -1,   122,    13,   454,    20,   454,    20,
     454,    20,    56,    14,    -1,   122,    13,   454,    20,   454,
      20,   454,    20,    56,    20,   453,    14,    -1,   123,    13,
     451,    20,   450,    20,   450,    20,   450,    20,   450,    14,
      -1,   404,    19,   405,    13,   454,    20,   450,    20,   450,
      14,    -1,   261,    13,   454,    14,    -1,   140,    13,   454,
      20,   450,    20,   450,    20,   450,    14,    -1,   262,    13,
     454,    14,    -1,   169,    13,   451,    20,   450,    14,    -1,
     170,    13,   454,    14,    -1,   171,    13,   454,    14,    -1,
     172,    13,   454,    14,    -1,   173,    13,   454,    20,   454,
      20,   450,    20,   450,    20,   450,    14,    -1,   174,    13,
     454,    14,    -1,   175,    13,   454,    20,   454,    20,   454,
      20,   450,    20,   454,    14,    -1,   176,    13,   454,    20,
     454,    20,   454,    20,   450,    20,   454,    14,    -1,   177,
      13,   454,    20,   454,    20,   454,    20,   450,    20,   454,
      20,   450,    20,   450,    14,    -1,   178,    13,   454,    20,
     454,    20,   454,    20,   450,    20,   454,    20,   450,    20,
     450,    20,   450,    20,   450,    14,    -1,   179,    13,   454,
      20,   454,    20,   454,    20,   454,    14,    -1,   179,    13,
     454,    20,   454,    20,   454,    20,   454,    20,   450,    14,
      -1,   180,    13,   454,    14,    -1,   180,    13,   454,    20,
     454,    14,    -1,   181,    13,   454,    20,   454,    14,    -1,
     124,    13,   451,    20,   450,    14,    -1,   125,    13,   454,
      14,    -1,   139,    13,   454,    14,    -1,   126,    13,   454,
      20,   450,    14,    -1,   196,    13,   454,    14,    -1,   127,
      13,   454,    20,   450,    14,    -1,   128,    13,   454,    20,
     450,    14,    -1,   131,    13,   451,    20,   450,    14,    -1,
     129,    13,   454,    20,   450,    20,   450,    20,   450,    20,
     450,    20,   450,    20,   450,    14,    -1,   133,    13,   454,
      20,   450,    20,   450,    20,   450,    14,    -1,   133,    13,
     454,    20,   450,    20,   450,    14,    -1,   133,    13,   454,
      20,   450,    20,   450,    20,   450,    20,   450,    14,    -1,
     134,    13,   454,    20,   450,    20,   450,    20,   450,    14,
      -1,   134,    13,   454,    20,   450,    20,   450,    14,    -1,
     134,    13,   454,    20,   450,    20,   450,    20,   450,    20,
     450,    14,    -1,   135,    13,   454,    20,   450,    20,   450,
      14,    -1,   135,    13,   454,    20,   450,    20,   450,    20,
     450,    20,   450,    14,    -1,   136,    13,   454,    20,   450,
      20,   450,    14,    -1,   136,    13,   454,    20,   450,    20,
     450,    20,   450,    20,   450,    14,    -1,   148,    13,   454,
      20,   454,    20,   450,    20,   450,    20,   450,    14,    -1,
     138,    13,   454,    20,   450,    20,   450,    20,   450,    20,
     450,    20,   450,    14,    -1,   137,    13,   454,    20,   450,
      20,   450,    20,   450,    20,   450,    14,    -1,   149,    19,
     159,    13,   454,    20,   450,    20,   450,    20,   450,    14,
      -1,   150,    19,   159,    13,   454,    20,   450,    20,   450,
      20,   450,    20,   450,    20,   450,    14,    -1,   151,    13,
     454,    14,    -1,   152,    13,   454,    20,   450,    20,   450,
      14,    -1,   152,    13,   454,    20,   450,    20,   450,    20,
     487,    14,    -1,   152,    13,   454,    20,   450,    20,   450,
      20,   450,    20,   487,    14,    -1,   153,    13,   454,    20,
     450,    20,   450,    20,   487,    14,    -1,   153,    13,   454,
      20,   450,    20,   450,    20,   450,    20,   487,    14,    -1,
     154,    13,   454,    20,   450,    20,   450,    20,   487,    14,
      -1,   155,    13,   454,    20,   450,    20,   450,    20,   450,
      20,   487,    14,    -1,   156,    13,   454,    20,   450,    20,
     450,    20,   450,    20,   487,    14,    -1,   157,    13,   454,
      20,   450,    20,   450,    20,   450,    20,   450,    20,   487,
      14,    -1,   158,    13,   454,    20,   450,    20,   450,    20,
     450,    20,   450,    14,    -1,   162,    13,   454,    20,   450,
      20,   450,    14,    -1,   183,    13,   454,    20,   450,    20,
     450,    20,   450,    20,   450,    20,   450,    14,    -1,   313,
      13,   454,    14,    -1,   314,    13,   454,    14,    -1,   315,
      13,   454,    14,    -1,   316,    13,   454,    14,    -1,    69,
      19,   264,    -1,    69,    19,   265,    -1,    65,    19,   264,
      -1,   203,    13,   454,    20,   450,    14,    -1,   204,    13,
     454,    20,   450,    14,    -1,   205,    13,   454,    20,   450,
      14,    -1,   206,    13,   454,    20,   450,    14,    -1,   146,
      13,   451,    20,   451,    20,   450,    14,    -1,   147,    13,
     451,    20,   451,    20,   450,    20,   450,    20,   450,    20,
     450,    14,    -1,   146,    13,   451,    20,   451,    20,   450,
      20,   450,    20,   450,    14,    -1,   146,    13,   451,    20,
     451,    20,   450,    20,   450,    20,   450,    20,   450,    14,
      -1,   146,    13,   451,    20,   451,    20,   454,    20,   450,
      20,   450,    14,    -1,   231,    13,   454,    20,   454,    14,
      -1,   232,    13,   454,    20,   454,    20,   451,    14,    -1,
     236,    13,   454,    20,   450,    20,   450,    20,   450,    14,
      -1,   237,    13,   454,    20,   450,    20,   450,    20,   450,
      14,    -1,   237,    13,   454,    20,   450,    20,   450,    20,
     450,    20,   450,    14,    -1,   238,    13,   454,    20,   450,
      14,    -1,   239,    13,   454,    20,   450,    14,    -1,   240,
      13,   454,    20,   450,    14,    -1,   241,    13,   454,    20,
     450,    14,    -1,   242,    13,   454,    20,   450,    14,    -1,
     243,    13,   454,    20,   450,    14,    -1,   244,    13,   454,
      20,   450,    14,    -1,   245,    13,   454,    20,   450,    14,
      -1,   245,    13,   454,    20,   450,    20,   450,    14,    -1,
     246,    13,   454,    20,   450,    20,   450,    20,   450,    14,
      -1,   247,    13,   451,    14,    -1,   454,    13,   475,    14,
      -1,   331,    13,   451,    20,   450,    20,   450,    20,   450,
      14,    -1,   332,    13,   451,    20,   450,    20,   450,    20,
     450,    14,    -1,   398,    13,   451,    14,    -1,   398,    13,
     451,    20,   450,    14,    -1,   401,    13,   451,    20,   450,
      14,    -1,   399,    13,   451,    20,   450,    20,   450,    20,
     450,    20,   450,    14,    -1,   400,    13,   454,    20,   454,
      20,   450,    20,   450,    20,   450,    20,   450,    20,   450,
      20,   450,    20,   450,    20,   450,    20,   450,    20,   450,
      20,   450,    20,   450,    14,    -1,   403,    13,   451,    20,
     450,    20,   450,    14,    -1,   409,    13,   451,    20,   450,
      14,    -1,   409,    13,   451,    14,    -1,   410,    13,   451,
      20,   450,    14,    -1,   410,    13,   451,    14,    -1,   415,
      13,   451,    20,   451,    14,    -1,   416,    13,   451,    14,
      -1,   417,    13,   452,    14,    -1,   386,    13,   451,    20,
     450,    20,   450,    20,   450,    20,   450,    20,   450,    20,
     450,    20,   450,    14,    -1,   211,    13,    78,    20,   454,
      20,   451,    14,    -1,   213,    13,    78,    20,   452,    14,
      -1,   455,    -1,   478,    -1,    64,    -1,   445,    -1,    78,
      -1,    66,    -1,    62,    -1,    63,    -1,    67,    -1,    61,
      -1,   449,    -1,   456,    -1,   457,    -1,   458,    -1,   477,
      -1,   118,    13,   475,    20,   475,    14,    -1,   482,    13,
     443,    14,    -1,    13,   475,    14,    -1,   459,    -1,     9,
     459,    -1,   459,   105,    -1,   459,   106,    -1,   459,   114,
      -1,   460,    15,   487,    16,    -1,   460,    15,   459,    16,
      -1,   460,    -1,    13,   453,    14,   461,    -1,    11,   460,
      -1,    10,   460,    -1,   105,   460,    -1,   106,   460,    -1,
     341,   460,    -1,   342,   460,    -1,   352,   460,    -1,   353,
     460,    -1,   354,   460,    -1,   355,   460,    -1,   343,   460,
      -1,   344,   460,    -1,   345,   460,    -1,   346,   460,    -1,
     349,   460,    -1,   351,   460,    -1,   350,   460,    -1,   356,
     460,    -1,   461,    -1,   462,     7,   461,    -1,   462,     8,
     461,    -1,   462,    12,   461,    -1,   462,    -1,   463,    10,
     462,    -1,   463,    11,   462,    -1,   463,    -1,   464,    -1,
     465,     6,   464,    -1,   465,     5,   464,    -1,   465,   110,
     464,    -1,   465,   111,   464,    -1,   465,    -1,   466,   112,
     465,    -1,   466,   113,   465,    -1,   466,    -1,   467,    17,
     466,    -1,   467,    -1,   468,    -1,   469,    18,   468,    -1,
     469,    -1,   470,   108,   469,    -1,   470,    -1,   471,     4,
     470,    -1,   471,    -1,   472,   109,   471,    -1,   472,    -1,
     472,    21,   472,    22,   473,    -1,   473,    -1,   473,   116,
     474,    -1,   473,    95,   474,    -1,   473,    96,   474,    -1,
     473,    97,   474,    -1,   473,    98,   474,    -1,   473,    99,
     474,    -1,   474,    -1,    79,    -1,    69,    19,   285,    -1,
     287,    13,    79,    20,    79,    20,   450,    14,    -1,    41,
      13,   452,    14,    -1,   288,    13,   450,    20,   450,    14,
      -1,    70,    -1,   289,    13,   475,    14,    -1,    68,    -1,
      80,    15,   450,    16,    -1,   479,    -1,   252,    13,   451,
      20,   450,    14,    -1,   255,    13,   454,    20,   450,    14,
      -1,   252,    13,   451,    20,   450,    20,   454,    14,    -1,
     260,    13,   451,    20,   450,    20,   451,    14,    -1,   256,
      13,    78,    14,    -1,   256,    13,    78,    20,   450,    14,
      -1,   257,    13,   454,    20,   450,    14,    -1,   258,    13,
      78,    20,   450,    14,    -1,   259,    13,    78,    20,   450,
      14,    -1,   263,    13,    14,    -1,   263,   452,    -1,   212,
      13,   452,    14,    -1,   212,    13,   452,    20,   450,    14,
      -1,   200,    13,   454,    14,    -1,   201,    13,    78,    14,
      -1,   201,    13,    78,    20,   450,    20,   450,    20,   450,
      14,    -1,   202,    13,    78,    20,   450,    14,    -1,   207,
      13,    78,    20,   450,    20,   450,    20,   450,    20,   450,
      20,   450,    20,   450,    14,    -1,   208,    13,   451,    20,
     450,    20,   450,    20,   450,    20,   450,    20,   450,    20,
     450,    20,   450,    14,    -1,   209,    13,   451,    20,   450,
      20,   450,    20,   450,    14,    -1,   210,    13,   451,    20,
     450,    20,   450,    20,   450,    20,   450,    20,   450,    20,
     450,    20,   450,    20,   450,    14,    -1,   210,    13,   451,
      20,   450,    20,   450,    20,   450,    20,   450,    20,   450,
      14,    -1,   406,    13,   451,    14,    -1,   406,    13,   451,
      20,   450,    14,    -1,   406,    13,   451,    20,   450,    20,
     450,    14,    -1,   408,    13,   451,    20,   450,    20,   450,
      14,    -1,   407,    13,   451,    20,   450,    20,   450,    20,
     451,    20,   451,    14,    -1,   407,    13,   451,    20,   450,
      20,   450,    20,   451,    20,   451,    20,   451,    20,   450,
      14,    -1,   411,    13,   451,    20,   451,    20,   451,    20,
     450,    20,   450,    20,   450,    20,   450,    14,    -1,   411,
      13,   451,    20,   451,    20,   451,    20,   450,    20,   450,
      20,   450,    20,   450,    20,   450,    14,    -1,   411,    13,
     451,    20,   451,    20,   451,    20,   450,    20,   450,    20,
     450,    14,    -1,   412,    13,   451,    20,   450,    20,   450,
      20,   450,    20,   450,    20,   450,    14,    -1,   414,    13,
     451,    20,   451,    20,   451,    20,   450,    20,   450,    20,
     450,    20,   450,    14,    -1,   414,    13,   451,    20,   451,
      20,   451,    20,   450,    20,   450,    20,   450,    20,   450,
      20,   451,    20,   451,    14,    -1,    59,    -1,    79,    -1,
      72,    -1,    73,    -1,    75,    -1,    74,    -1,    76,    -1,
      78,    19,   480,    -1,   482,    -1,    65,    -1,    80,    -1,
      69,    -1,    71,    -1,    77,    -1,    81,    -1,   481,    -1,
     483,    -1,   478,    -1,    78,    -1,    62,    -1,    63,    -1,
      61,    -1,    66,    -1,    67,    -1,    64,    -1,    70,    -1,
     454,    -1,   484,    -1,   485,    -1,   450,    22,   450,    20,
     450,    22,   450,    20,   450,    22,   450,    -1,   450,    22,
     450,    20,   450,    22,   450,    -1,    22,    20,    22,    20,
     450,    22,   450,    -1,   454,    19,    93,    -1,    65,    -1
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
     426,   431,   434,   437,   440,   444,   455,   462,   466,   473,
     480,   489,   518,   527,   536,   540,   549,   562,   569,   576,
     593,   602,   619,   630,   637,   648,   657,   668,   683,   692,
     705,   712,   721,   728,   735,   739,   743,   746,   753,   764,
     771,   782,   793,   806,   813,   820,   824,   828,   832,   836,
     841,   845,   852,   859,   864,   885,   896,   903,   907,   911,
     918,   922,   929,   938,   945,   952,   961,   978,   985,   989,
     996,  1005,  1009,  1022,  1035,  1048,  1059,  1063,  1067,  1076,
    1085,  1096,  1105,  1116,  1129,  1136,  1145,  1156,  1173,  1192,
    1205,  1212,  1231,  1248,  1261,  1272,  1283,  1294,  1301,  1312,
    1319,  1326,  1333,  1342,  1347,  1352,  1361,  1366,  1385,  1390,
    1392,  1394,  1396,  1403,  1407,  1412,  1414,  1416,  1418,  1449,
    1474,  1483,  1485,  1489,  1490,  1492,  1496,  1499,  1504,  1506,
    1510,  1511,  1514,  1517,  1520,  1523,  1526,  1529,  1534,  1539,
    1544,  1549,  1554,  1559,  1561,  1568,  1570,  1574,  1579,  1584,
    1586,  1590,  1591,  1592,  1594,  1596,  1598,  1600,  1607,  1616,
    1627,  1638,  1649,  1658,  1665,  1669,  1673,  1677,  1681,  1685,
    1689,  1693,  1697,  1701,  1705,  1709,  1713,  1720,  1725,  1736,
    1741,  1752,  1757,  1762,  1767,  1772,  1777,  1782,  1790,  1798,
    1806,  1816,  1824,  1831,  1836,  1840,  1844,  1848,  1852,  1856,
    1860,  1864,  1868,  1872,  1879,  1890,  1895,  1900,  1905,  1909,
    1916,  1923,  1930,  1932,  1934,  1936,  1938,  1940,  1942,  1944,
    1946,  1948,  1950,  1952,  1954,  1956,  1958,  1962,  1964,  1969,
    1972,  1977,  1982,  1984,  1995,  2008,  2017,  2019,  2026,  2033,
    2040,  2049,  2058,  2065,  2074,  2083,  2094,  2105,  2118,  2131,
    2142,  2147,  2158,  2163,  2170,  2175,  2180,  2185,  2198,  2203,
    2216,  2229,  2246,  2267,  2278,  2291,  2296,  2303,  2310,  2317,
    2322,  2327,  2334,  2339,  2346,  2353,  2360,  2377,  2388,  2397,
    2410,  2421,  2430,  2443,  2452,  2465,  2474,  2487,  2500,  2515,
    2528,  2541,  2558,  2563,  2572,  2583,  2596,  2607,  2620,  2631,
    2644,  2657,  2672,  2685,  2694,  2709,  2714,  2719,  2724,  2729,
    2733,  2737,  2741,  2748,  2755,  2762,  2769,  2778,  2793,  2806,
    2821,  2834,  2841,  2850,  2861,  2872,  2885,  2892,  2899,  2906,
    2913,  2920,  2927,  2934,  2941,  2950,  2961,  2966,  2971,  2982,
    2993,  2998,  3005,  3012,  3025,  3056,  3065,  3072,  3077,  3084,
    3089,  3096,  3101,  3106,  3125,  3134,  3141,  3143,  3145,  3147,
    3149,  3151,  3153,  3155,  3157,  3159,  3161,  3163,  3165,  3167,
    3169,  3171,  3178,  3183,  3187,  3189,  3192,  3195,  3198,  3201,
    3206,  3211,  3213,  3218,  3221,  3224,  3227,  3230,  3233,  3236,
    3239,  3242,  3245,  3248,  3251,  3254,  3257,  3260,  3263,  3266,
    3269,  3272,  3274,  3278,  3282,  3286,  3288,  3292,  3296,  3298,
    3300,  3304,  3308,  3312,  3316,  3318,  3322,  3326,  3328,  3332,
    3334,  3336,  3340,  3342,  3346,  3348,  3352,  3354,  3358,  3360,
    3366,  3368,  3372,  3376,  3380,  3384,  3388,  3392,  3394,  3396,
    3400,  3409,  3414,  3421,  3423,  3428,  3430,  3435,  3437,  3444,
    3451,  3460,  3469,  3474,  3481,  3488,  3495,  3502,  3506,  3509,
    3514,  3521,  3526,  3531,  3542,  3549,  3566,  3585,  3596,  3617,
    3632,  3637,  3644,  3653,  3662,  3675,  3692,  3709,  3728,  3743,
    3758,  3775,  3796,  3798,  3800,  3802,  3804,  3806,  3808,  3810,
    3814,  3816,  3818,  3820,  3822,  3824,  3826,  3828,  3830,  3832,
    3834,  3836,  3838,  3840,  3842,  3844,  3846,  3848,  3850,  3852,
    3854,  3856,  3868,  3876,  3884,  3888
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   830,   830,   831,   835,   835,   836,   837,   838,   838,
     839,   839,   840,   840,   841,   841,   842,   842,   843,   843,
     846,   847,   852,   871,   891,   937,   960,  1009,  1024,  1047,
    1046,  1078,  1077,  1121,  1138,  1160,  1181,  1188,  1223,  1233,
    1266,  1299,  1307,  1317,  1331,  1345,  1359,  1369,  1385,  1403,
    1418,  1433,  1464,  1492,  1539,  1550,  1560,  1571,  1597,  1636,
    1666,  1707,  1727,  1739,  1758,  1769,  1856,  1890,  1906,  1912,
    1916,  1920,  1924,  1934,  1939,  1943,  1953,  1968,  1978,  1989,
    1992,  2042,  2065,  2115,  2205,  2257,  2261,  2273,  2287,  2297,
    2307,  2318,  2326,  2338,  2574,  2584,  2594,  2604,  2613,  2678,
    2692,  2726,  2738,  2779,  2798,  2825,  2842,  2855,  2866,  2912,
    2919,  2938,  2973,  2988,  2996,  3004,  3023,  3047,  3053,  3059,
    3073,  3085,  3095,  3105,  3112,  3129,  3145,  3163,  3184,  3200,
    3219,  3233,  3248,  3258,  3270,  3292,  3316,  3338,  3350,  3364,
    3383,  3405,  3434,  3463,  3495,  3692,  3697,  3704,  3709,  3949,
    3977,  3991,  3998,  4004,  4012,  4113,  4120,  4128,  4136,  4144,
    4155,  4165,  4173,  4181,  4192,  4199,  4213,  4227,  4236,  4241,
    4250,  4259,  4272,  4285,  4298,  4311,  4318,  4328,  4338,  4352,
    4360,  4371,  4394,  4420,  4448,  4459,  4502,  4524,  4553,  4570,
    4585,  4591,  4618,  4644,  4664,  4681,  4687,  4693,  4704,  4710,
    4718,  4733,  4742,  4753,  4770,  4786,  4824,  4838,  4885,  4891,
    4896,  4901,  4907,  4914,  4920,  4927,  4932,  4937,  4942,  4985,
    5039,  5061,  5069,  5086,  5090,  5106,  5124,  5140,  5155,  5171,
    5191,  5196,  5205,  5212,  5219,  5226,  5233,  5240,  5247,  5254,
    5261,  5268,  5275,  5283,  5288,  5369,  5393,  5398,  5411,  5430,
    5461,  5472,  5473,  5478,  5482,  5490,  5498,  5527,  5544,  5560,
    5577,  5596,  5614,  5630,  5646,  5652,  5658,  5664,  5670,  5676,
    5682,  5688,  5694,  5700,  5706,  5712,  5719,  5728,  5735,  5766,
    5774,  5786,  5806,  5826,  5846,  5866,  5886,  5906,  5930,  5954,
    5978,  5986,  6010,  6033,  6041,  6053,  6065,  6077,  6089,  6101,
    6113,  6129,  6148,  6189,  6199,  6211,  6221,  6231,  6243,  6251,
    6267,  6282,  6312,  6330,  6342,  6363,  6368,  6372,  6376,  6380,
    6384,  6388,  6392,  6396,  6400,  6404,  6408,  6416,  6418,  6437,
    6445,  6465,  6500,  6531,  6538,  6556,  6581,  6649,  6715,  6722,
    6729,  6737,  6745,  6761,  6779,  6797,  6814,  6831,  6849,  6885,
    6898,  6909,  6922,  6946,  6957,  6968,  6978,  6988,  7021,  7032,
    7053,  7073,  7114,  7161,  7181,  7202,  7213,  7227,  7241,  7254,
    7265,  7276,  7289,  7307,  7319,  7331,  7383,  7424,  7435,  7445,
    7457,  7468,  7478,  7503,  7526,  7554,  7568,  7702,  7736,  7769,
    7797,  7811,  7825,  7835,  7854,  7873,  7893,  7914,  7936,  7955,
    7974,  7994,  8034,  8056,  8085,  8107,  8144,  8181,  8218,  8252,
    8258,  8268,  8274,  8281,  8288,  8296,  8303,  8325,  8353,  8377,
    8404,  8436,  8445,  8458,  8465,  8473,  8487,  8499,  8511,  8521,
    8532,  8542,  8552,  8563,  8573,  8584,  8611,  8659,  8793,  8814,
    8854,  8865,  8873,  8881,  8902,  8928,  8939,  8946,  8952,  8958,
    8965,  8990,  9008,  9015,  9048,  9067,  9088,  9103,  9114,  9123,
    9137,  9139,  9141,  9143,  9145,  9147,  9149,  9151,  9153,  9155,
    9157,  9159,  9221,  9299,  9302,  9303,  9311,  9319,  9327,  9337,
    9376,  9388,  9390,  9399,  9405,  9410,  9415,  9420,  9425,  9430,
    9435,  9440,  9445,  9450,  9455,  9460,  9465,  9470,  9475,  9480,
    9485,  9494,  9495,  9501,  9507,  9517,  9518,  9525,  9535,  9539,
    9540,  9546,  9552,  9558,  9567,  9568,  9574,  9600,  9601,  9605,
    9609,  9610,  9614,  9615,  9627,  9628,  9640,  9641,  9653,  9654,
    9667,  9668,  9678,  9685,  9691,  9697,  9703,  9712,  9716,  9726,
    9740,  9751,  9769,  9775,  9784,  9905,  9907,  9923,  9928,  9943,
    9955,  9977, 10013, 10022, 10032, 10041, 10051, 10065, 10072, 10081,
   10097, 10116, 10136, 10166, 10195, 10212, 10238, 10272, 10304, 10351,
   10392, 10401, 10423, 10434, 10445, 10481, 10523, 10569, 10619, 10661,
   10692, 10724, 10766, 10774, 10777, 10778, 10779, 10780, 10781, 10782,
   10815, 10816, 10817, 10818, 10819, 10820, 10821, 10826, 10827, 10833,
   10835, 10837, 10839, 10841, 10843, 10846, 10848, 10851, 10853, 10857,
   10859, 10862, 10871, 10879, 10897, 10914
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
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 12210;
  const int Parser::yynnts_ = 59;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 576;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 429;

  const unsigned int Parser::yyuser_token_number_max_ = 683;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // yyip

/* Line 1054 of lalr1.cc  */
#line 16109 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"


/* Line 1056 of lalr1.cc  */
#line 10936 "/home/fsantana/proyectos/amilab/Karl_Grammar/src/Language/improcess_bison.ypp"

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




