
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

void CB_ParamWin( void* cd );


//static void ( void* cd, long unsigned int *) {
//  CB_ParamWin(cd);
//}

/*
static void CB_Button(  void* cd) {
  CB_ParamWin(cd);
}
*/

void CB_delete_variable( void* var);


//------------------------------------------------------
void CB_update_imagelist( void* imagelist_gui);


#define GET_VARSTACK_VALUE(type,newvar) \
  boost::shared_ptr<type> newvar( \
    driver.var_stack.GetLastVar<type>()->Pointer());


/*! \def GET_VARSTACK_OBJECT
    \brief Gets the smart pointer to the wrapped object  (of type WrapClass_type) included in an AMIObject variable, taken from the stack of variables.
*/
#define GET_VARSTACK_OBJECT(wtype, type, obj) \
  Variable<AMIObject>::ptr objvar( \
    driver.var_stack.GetLastVar<AMIObject>()); \
  if (!objvar.get()) {  \
    driver.yyiperror(" Expecting an AMIObject variable."); \
    YYABORT; \
  } \
  WrapClassBase::ptr wrap_base( objvar->Pointer()->GetWrappedObject()); \
  WrapClass_##wtype::ptr wobj( boost::dynamic_pointer_cast<WrapClass_##wtype>(wrap_base));\
  if (!wobj.get()) {  \
    driver.yyiperror((boost::format(" Expecting an AMIObject variable of type %1%.")%(#type)).str().c_str()); \
    YYABORT; \
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

#define UNARYOP_EXPR(operator,val,res)           \
  res=operator(val);






/* Line 311 of lalr1.cc  */
#line 314 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"


#include "improcess_bison.tab.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 784 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"


#include "driver.h"
#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex



/* Line 317 of lalr1.cc  */
#line 337 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"

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
#line 406 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
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
#line 777 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 513 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 59: /* "IDENTIFIER" */

/* Line 480 of lalr1.cc  */
#line 778 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 522 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 483: /* "exprstringlist" */

/* Line 480 of lalr1.cc  */
#line 780 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->string_list); };

/* Line 480 of lalr1.cc  */
#line 531 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 486: /* "primary_expr_string" */

/* Line 480 of lalr1.cc  */
#line 777 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 540 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 487: /* "instr_block" */

/* Line 480 of lalr1.cc  */
#line 779 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ablock); };

/* Line 480 of lalr1.cc  */
#line 549 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 494: /* "expr_string" */

/* Line 480 of lalr1.cc  */
#line 777 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 558 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 521: /* "identifier" */

/* Line 480 of lalr1.cc  */
#line 778 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 567 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
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
#line 302 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}

/* Line 553 of lalr1.cc  */
#line 653 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"

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
#line 823 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 842 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 862 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 907 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 930 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 979 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 994 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1016 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GB_driver.procedure_declaration = true;
    }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 1021 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1047 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      // allow overriding current functions
      GB_driver.procedure_declaration = true;
    }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 1053 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1092 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1109 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1130 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1151 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
       //driver.res_print($2);
       driver.parse_script((yysemantic_stack_[(3) - (2)].astring));
       delete [] (yysemantic_stack_[(3) - (2)].astring);
     }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 1158 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1193 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> input((yysemantic_stack_[(2) - (2)].astring));
      string inputstring( input.get());
      driver.parse_string( inputstring,
                          "'eval string' command");
    }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 1203 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1236 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1268 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1276 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1287 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1301 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1315 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1329 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1339 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1355 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1373 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1388 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1403 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
          if (var->GetPtrCounter()==1) {
            //cout << "GetPtrCounter == 1" << endl;
            IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
            Vars.AddVar(ident,var);
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
#line 1431 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1459 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1506 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1517 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1527 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1538 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          InrImage::ptr imptr(driver.im_stack.GetLastImage());
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
#line 1564 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(VarArray, vararray, array);

          InrImage::ptr imptr(driver.im_stack.GetLastImage());
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
#line 1603 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 1633 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(VarArray,vararray,array)

          int  i = (int) (yysemantic_stack_[(6) - (3)].adouble);
          char name[256];

          SurfacePoly::ptr surfptr (driver.surf_stack.GetLastSurf());
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
#line 1655 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
          // TODO: use smart pointers in surf_stack ...
          SurfacePoly::ptr surfptr (driver.surf_stack.GetLastSurf());

          if (surfptr != NULL)
            Vars.AddVar<SurfacePoly>(ident, surfptr);
          else
            driver.err_print("assignment of NULL surface\n");
        }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1667 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(SurfacePoly,var,val)

          SurfacePoly::ptr surfptr( driver.surf_stack.GetLastSurf());

          // instead of deleting and creating,
          // replace the pointer and the information
          if (surfptr.get()) {
            var->Delete();
            var->Init(var->Name().c_str(),
                      surfptr);
          }
          else
            driver.err_print("assignment of NULL surface\n");

        }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1685 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 64:

/* Line 678 of lalr1.cc  */
#line 1705 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 65:

/* Line 678 of lalr1.cc  */
#line 1717 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 66:

/* Line 678 of lalr1.cc  */
#line 1736 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 67:

/* Line 678 of lalr1.cc  */
#line 1747 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 68:

/* Line 678 of lalr1.cc  */
#line 1834 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 69:

/* Line 678 of lalr1.cc  */
#line 1868 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 70:

/* Line 678 of lalr1.cc  */
#line 1884 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<FILE>::ptr varfile(driver.var_stack.GetLastVar<FILE>());
          FILE_ptr file(varfile->Pointer());
          rewind(file.get());
        }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1890 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GB_debug = 1;
        }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1894 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GB_debug = 0;
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1898 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      driver.SetTraceScanning((yysemantic_stack_[(2) - (2)].adouble)>0.5);
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1902 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 75:

/* Line 678 of lalr1.cc  */
#line 1912 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 1;
      verbose = 1;
    }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1917 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 0;
    }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 1921 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 78:

/* Line 678 of lalr1.cc  */
#line 1931 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 79:

/* Line 678 of lalr1.cc  */
#line 1946 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 80:

/* Line 678 of lalr1.cc  */
#line 1956 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 81:

/* Line 678 of lalr1.cc  */
#line 1966 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GB_main_wxFrame->Close(true);
        }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 1970 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 83:

/* Line 678 of lalr1.cc  */
#line 2020 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 84:

/* Line 678 of lalr1.cc  */
#line 2043 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(SurfacePoly,surfvar,surf)
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

  case 85:

/* Line 678 of lalr1.cc  */
#line 2090 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Replacing the previous image by the new one.
        **/
          GET_VARSTACK_VAR_VAL(InrImage, var, i1);
          InrImage::ptr imptr  (driver.im_stack.GetLastImage());
          bool can_skip_allocation = false;

          if (imptr.get()) {
            if (i1.get()!=imptr.get()) {
              can_skip_allocation = (i1->GetFormat()==imptr->GetFormat());
              if (can_skip_allocation) {
                // first try the standard data copy
                can_skip_allocation = ((*i1)=(*imptr));
                if (can_skip_allocation) {
                  // copy additional information here
                  i1->SetTranslation(imptr->TrX(), imptr->TrY(), imptr->TrZ());
                  i1->SetVoxelSize( imptr->VoxSizeX(), 
                                    imptr->VoxSizeY(),
                                    imptr->VoxSizeZ());
                }
              }
              if (!can_skip_allocation) {
                // instead of deleting and creating,
                // replace the pointer and the information
                  var->Delete();
                  // should be OK
                  var->Init( var->Name().c_str(), imptr);
              } // end if (!can_skip_allocation)
            } // end if (i1.get()!=imptr)
          }
          else
            driver.err_print("assignment of NULL image\n");
        }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 2141 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 87:

/* Line 678 of lalr1.cc  */
#line 2231 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
          Description: Pads the image ...
        **/
          GET_VARSTACK_VALUE(InrImage, i1);
          int posx  = (int) (yysemantic_stack_[(16) - (3)].adouble);
          int stepx = (int) (yysemantic_stack_[(16) - (5)].adouble);
          int posy  = (int) (yysemantic_stack_[(16) - (7)].adouble);
          int stepy = (int) (yysemantic_stack_[(16) - (9)].adouble);
          int posz  = (int) (yysemantic_stack_[(16) - (11)].adouble);
          int stepz = (int) (yysemantic_stack_[(16) - (13)].adouble);

          InrImage::ptr i2 (driver.im_stack.GetLastImage());

          Func_Pad(i1.get(),i2.get(),stepx,posx,stepy,posy,stepz,posz);


        }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 2285 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Vars.display();
        }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 2289 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 90:

/* Line 678 of lalr1.cc  */
#line 2301 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 91:

/* Line 678 of lalr1.cc  */
#line 2315 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 92:

/* Line 678 of lalr1.cc  */
#line 2325 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<VarArray>::ptr vararray(driver.var_stack.GetLastVar<VarArray>());
          VarArray::ptr array (vararray->Pointer());
          int  i = (int) (yysemantic_stack_[(5) - (4)].adouble);

          if (array->GetVar(i).get()) {
            array->GetVar(i) = BasicVariable::ptr();
          }
      }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 2335 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 94:

/* Line 678 of lalr1.cc  */
#line 2346 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
        Description:
        Calls system 'ls' command (for unix systems)
      **/
         std::system("ls");
           }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 2354 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 96:

/* Line 678 of lalr1.cc  */
#line 2366 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 97:

/* Line 678 of lalr1.cc  */
#line 2602 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 98:

/* Line 678 of lalr1.cc  */
#line 2612 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 99:

/* Line 678 of lalr1.cc  */
#line 2622 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 100:

/* Line 678 of lalr1.cc  */
#line 2632 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        Displays the documentation relative to the wrapped c++ member.
    **/
      GET_VARSTACK_VALUE(WrapClassMember, m);
      m->ShowHelp();
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 2641 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 102:

/* Line 678 of lalr1.cc  */
#line 2695 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<FILE>::ptr varfile(driver.var_stack.GetLastVar<FILE>());
          FILE_ptr file (varfile->Pointer());
          boost::shared_array<char> text( (yysemantic_stack_[(4) - (4)].astring));

          fprintf(file.get(),"%s",text.get());
          fflush(file.get());
        }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 2704 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<FILE>::ptr varfile(driver.var_stack.GetLastVar<FILE>());
          FILE_ptr file (varfile->Pointer());
          boost::shared_array<char> text( (yysemantic_stack_[(4) - (4)].astring));

          fprintf(file.get(),"%s\n",text.get());
          fflush(file.get());
        }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 2713 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 105:

/* Line 678 of lalr1.cc  */
#line 2725 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 106:

/* Line 678 of lalr1.cc  */
#line 2766 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 107:

/* Line 678 of lalr1.cc  */
#line 2785 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<FILE>::ptr varfile(driver.var_stack.GetLastVar<FILE>());
          FILE_ptr file (varfile->Pointer());

          fprintf(file.get(),"%5.10f",(yysemantic_stack_[(4) - (4)].adouble));
          fflush(file.get());
        }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 2793 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          driver.var_stack.GetLastBasicVar();
          printf("Deprecated: No need to close files explicitly, since we use smart pointers, they will be closed when the variable is deleted. \n");
        }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 2820 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 110:

/* Line 678 of lalr1.cc  */
#line 2837 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 111:

/* Line 678 of lalr1.cc  */
#line 2850 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 112:

/* Line 678 of lalr1.cc  */
#line 2861 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 113:

/* Line 678 of lalr1.cc  */
#line 2907 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(DessinImage, draw2);
          GET_VARSTACK_VALUE(DessinImage, draw1);

          draw1->CreeCompare2Image(draw2);
        }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 2914 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 115:

/* Line 678 of lalr1.cc  */
#line 2937 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 116:

/* Line 678 of lalr1.cc  */
#line 2968 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 117:

/* Line 678 of lalr1.cc  */
#line 2983 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;

          draw = DessinImage::ptr(varimd->Pointer());
          draw->SetVectorVisible( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 2991 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;

          draw = DessinImage::ptr(varimd->Pointer());
          draw->CB_AfficheChampVect(draw.get(),NULL);
        }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 2999 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 120:

/* Line 678 of lalr1.cc  */
#line 3018 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 121:

/* Line 678 of lalr1.cc  */
#line 3042 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw= DessinImage::ptr(varimd->Pointer());
          draw->SetVectType((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 3048 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw= DessinImage::ptr(varimd->Pointer());
          draw->SetLineThickness((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 3054 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 124:

/* Line 678 of lalr1.cc  */
#line 3068 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          int width  = (int) (yysemantic_stack_[(8) - (5)].adouble);
          int height = (int) (yysemantic_stack_[(8) - (7)].adouble);

          DessinImage::ptr draw= DessinImage::ptr(varimd->Pointer());
          draw->SetSize(width,height);
          draw->Update();


        }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 3080 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          ClasseCouleur c;

          draw = DessinImage::ptr(varimd->Pointer());
          c.FixeValeur((int)(yysemantic_stack_[(16) - (11)].adouble),(int)(yysemantic_stack_[(16) - (13)].adouble),(int)(yysemantic_stack_[(16) - (15)].adouble));
          draw->DessineCercle( (int) (yysemantic_stack_[(16) - (5)].adouble), (int) (yysemantic_stack_[(16) - (7)].adouble), (int) (yysemantic_stack_[(16) - (9)].adouble), c);
        }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 3090 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
          Description: Set a user-defined colormap.
         **/
          GET_VARSTACK_VALUE(DessinImage, draw);
          InrImage::ptr colmap(driver.im_stack.GetLastImage());

          draw->SetUserColormap( colmap,  (yysemantic_stack_[(10) - (7)].adouble),  (yysemantic_stack_[(10) - (9)].adouble));
        }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 3100 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,    surfd);
          GET_VARSTACK_VALUE(DessinImage, draw);

          draw->SetGLWindow(surfd);
        }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 3107 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 129:

/* Line 678 of lalr1.cc  */
#line 3124 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 130:

/* Line 678 of lalr1.cc  */
#line 3140 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 131:

/* Line 678 of lalr1.cc  */
#line 3158 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 132:

/* Line 678 of lalr1.cc  */
#line 3179 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 133:

/* Line 678 of lalr1.cc  */
#line 3195 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 134:

/* Line 678 of lalr1.cc  */
#line 3214 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 135:

/* Line 678 of lalr1.cc  */
#line 3228 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 136:

/* Line 678 of lalr1.cc  */
#line 3243 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(AMIFunction, func);
          GET_VARSTACK_VALUE(DessinImage, draw);

          draw->SetPaintCallback( (void*) CB_ParamWin, 
                                  (void*) func.get() );
          // may be a pb to call Paint() here since it will start another interpreter ??? to check
          //draw->Paint();
        }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 3253 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 138:

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

  case 139:

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

  case 140:

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

  case 141:

/* Line 678 of lalr1.cc  */
#line 3333 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(SurfacePoly,var,s);
    
          std::string tmp_string;
          tmp_string = (boost::format(" %s: %d points %d lines %d polygons  \n")
            % var->Name()
            % s->GetNumberOfPoints()
            % s->GetNumberOfLines()
            % s->GetNumberOfPolys ()
            ).str();
          driver.res_print(tmp_string);
          tmp_string = (boost::format(" limits X:[%4.2f %4.2f] Y:[%4.2f %4.2f]  Z:[%4.2f %4.2f]  \n")
            % s->_xmin % s->_xmax
            % s->_ymin % s->_ymax
            % s->_zmin % s->_zmax).str();
          driver.res_print(tmp_string);
        }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 3351 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 143:

/* Line 678 of lalr1.cc  */
#line 3363 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 144:

/* Line 678 of lalr1.cc  */
#line 3377 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 145:

/* Line 678 of lalr1.cc  */
#line 3396 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 146:

/* Line 678 of lalr1.cc  */
#line 3418 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 147:

/* Line 678 of lalr1.cc  */
#line 3449 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 148:

/* Line 678 of lalr1.cc  */
#line 3476 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 149:

/* Line 678 of lalr1.cc  */
#line 3508 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> name((yysemantic_stack_[(6) - (5)].astring));
      GET_VARSTACK_VALUE(InrImage, im);
      im->FixeNom( name.get());
    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 3705 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 3710 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {

      Func_EndWeickert();

    }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 3717 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 3722 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Func_EndWeickert();
    }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 3962 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 155:

/* Line 678 of lalr1.cc  */
#line 3990 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 156:

/* Line 678 of lalr1.cc  */
#line 4004 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im2);
      GET_VARSTACK_VALUE(InrImage, im1);
      Func_OrientField( im1.get() , im2.get() );
    }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 4011 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im2);
      GET_VARSTACK_VALUE(InrImage, im1);
      Func_OrientPositive( im1.get(), im2.get());
    }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 4017 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename((yysemantic_stack_[(4) - (4)].astring));
      GET_VARSTACK_VALUE(SurfacePoly, s);

      s->Write(filename.get());
    }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 4025 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
        (1) input polydata
        (4) filename
    Description:
        Save the first line of the polydata in text format
    **/
      boost::shared_array<char> filename((yysemantic_stack_[(4) - (4)].astring));
      GET_VARSTACK_VALUE(SurfacePoly, surf);
      Func_WriteCTALine(surf.get(),filename.get());

    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 4039 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(SurfacePoly, s);

      s->SetOwnMaterial( (int) (yysemantic_stack_[(6) - (5)].adouble));

    }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 4046 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(SurfacePoly, s);
      s->GetMaterial()._ambient.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 4052 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(SurfacePoly, s);
      s->GetMaterial()._diffuse.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 4059 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(SurfacePoly, s);
      s->GetMaterial()._specular.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 4067 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(SurfacePoly, s);
      s->GetMaterial()._shininess= (yysemantic_stack_[(6) - (5)].adouble);

    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 4075 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(SurfacePoly, s);
      s->GetMaterial()._opacity= (yysemantic_stack_[(6) - (5)].adouble);

    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 4083 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        Sets the object visible or not visible in the scene.
      **/
      GET_VARSTACK_VALUE(SurfacePoly, s);
      s->SetVisible( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 4093 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Enable/Disable colormaterial for the associated surface.
        **/

      GET_VARSTACK_VALUE(SurfacePoly, s);

      s->GetMaterial()._colormaterial = (unsigned char) ((yysemantic_stack_[(6) - (5)].adouble)>0.5);

    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 4106 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
      Parameters:
        (1) surface object
        (5) alpha value
    
      Description:
        to define the transparency to the RGB color
        associated per each vertex (actived with Enable ColorMaterial)
      **/

      GET_VARSTACK_VALUE(SurfacePoly, s);

      s->SetColorOpacity((yysemantic_stack_[(6) - (5)].adouble));

    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 4123 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(SurfacePoly, s);

      int n;
      Pour(n,0,s->NbPoints()-1)
        (*s)[n].SetColor((unsigned char) (yysemantic_stack_[(10) - (5)].adouble),
                 (unsigned char) (yysemantic_stack_[(10) - (7)].adouble),
                 (unsigned char) (yysemantic_stack_[(10) - (9)].adouble));
      FinPour

      s->SetColorMaterial(true);
      s->GLRecomputeList(  );

    }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 4138 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,    im);
      GET_VARSTACK_VALUE(SurfacePoly, s);

      s->SetPointsColors( im.get() );

    }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 4146 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      InrImage::ptr i (driver.im_stack.GetLastImage());
      // TODO: use smart pointer to image in SetColors ...
      s->SetColors( i.get() , (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 4154 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      InrImage::ptr i (driver.im_stack.GetLastImage());
      s->SetColors( i.get() );

    }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 4162 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->Statistics( im.get() );

    }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 4170 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->MergePoints((yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 4176 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->Triangulate();
    }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 4182 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {

      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr surf (surfdraw->Pointer());

      float        depth = (yysemantic_stack_[(6) - (5)].adouble);
      std::string  name;
      int          n;

      // param 1: depth (neighborhood)
      //

      // Create images for the curvatures and their directions
      InrImage::ptr Icmin;
      InrImage::ptr Icmax;
      InrImage::ptr Idmin;
      InrImage::ptr Idmax;

      n = surf->GetNumberOfPoints();

      Icmin = InrImage::ptr(new InrImage(n,1,1,WT_FLOAT,"mincurv.ami.gz"));
      Icmax = InrImage::ptr(new InrImage(n,1,1,WT_FLOAT,"maxcurv.ami.gz"));

      Idmin = InrImage::ptr(new InrImage(n,1,1,3,WT_FLOAT,"mincurvdir.ami.gz"));
      Idmax = InrImage::ptr(new InrImage(n,1,1,3,WT_FLOAT,"maxcurvdir.ami.gz"));

      surf->ComputeCurvatures(Icmin.get(),Icmax.get(),
                              Idmin.get(),Idmax.get(), 
                              (int) depth);

      BasicVariable::ptr var;

      name = (boost::format("%s_cmin") % surfdraw->Name()).str();
      Vars.AddVar<InrImage>(name,Icmin);

      name = (boost::format("%s_cmax") % surfdraw->Name()).str();
      Vars.AddVar<InrImage>(name,Icmax);

      name = (boost::format("%s_dmin") % surfdraw->Name()).str();
      Vars.AddVar<InrImage>(name,Idmin);

      name = (boost::format("%s_dmax") % surfdraw->Name()).str();
      Vars.AddVar<InrImage>(name,Idmax);

    }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 4228 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      InrImage::ptr i (driver.im_stack.GetLastImage());
      s->DisplacePoints( i.get() );
    }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 4236 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      s->Translate( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble) );

    }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 4244 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      s->Scale( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble),0 );

    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 4252 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      int          w = (int) (yysemantic_stack_[(6) - (5)].adouble);

      Si w<1  AlorsFait w=1;
      Si w>10 AlorsFait w=10;

      s->_line_width = w;

    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 4264 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      s->RemoveLine((int)(yysemantic_stack_[(6) - (5)].adouble));
      s->GLRecomputeList();

    }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 4273 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        image expression
      Description:
        Select lines based on an image
        The image is 1D of size the number of lines
        if the value is > 0.5, then select the corresponding line
    **/

      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      InrImage::ptr im (driver.im_stack.GetLastImage());

      s->SelectLines(im.get());
      s->GLRecomputeList();
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 4291 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Remove selected lines
    **/
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      s->RemoveSelection();
      s->GLRecomputeList();
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 4302 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->GLRecomputeList();

    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 4309 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->RecomputeNormals();

    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 4316 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      s->InvertNormals();

    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 4324 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      Func_ApplyvtkSmooth(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 4333 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      Func_vtkWindowedSinc(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 4342 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {

      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      SurfacePoly* surf;

      surf = Func_decimate(s.get());
      Si surf != NULL Alors

        // Non correct: supprimer la variable et la re-creer:
        // car pb si la variable est deja utilisee ...
        //          $1->Init(type_surface,$1->Name(), surf);
        //      delete surf_init;
      Sinon
        fprintf(stderr,"improcess.y: var_surface.T_vtkDecimate \t error \n ");
          FinSi


      }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 4362 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Sets a threshold for drawing connected components
          bigger.
        **/
          Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
          SurfacePoly::ptr s (surfdraw->Pointer());
          GLuint _SURFACE;

          Si Non(s->_cc_calculees) Alors
            s->CalculCC();
          FinSi
          s->GLSurfaceMinThCC( _SURFACE, (int) (yysemantic_stack_[(6) - (5)].adouble));

        }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 4379 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        Draw one connected component only
        **/
          Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
          SurfacePoly::ptr s (surfdraw->Pointer());
          GLuint _SURFACE;

            //          Si _type_surface == SURFACE_POLY Alors
            Si Non(s->_cc_calculees) Alors
              s->CalculCC();
            FinSi
            s->GLSurfaceDrawOnlyCC( _SURFACE, (int) (yysemantic_stack_[(6) - (5)].adouble));
            //          FinSi

        }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 4397 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        Activate/Desactivate Drawing of one connected components
        **/
          Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
          SurfacePoly::ptr s (surfdraw->Pointer());
          GLuint _SURFACE;

      //          Si _type_surface == SURFACE_POLY Alors
            Si Non(s->_cc_calculees) Alors
              s->CalculCC();
            FinSi
            s->GLSurfaceSetDrawCC( _SURFACE, (int) (yysemantic_stack_[(8) - (5)].adouble),(int) (yysemantic_stack_[(8) - (7)].adouble));
        //          FinSi

    }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 4415 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->AddPoint((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 4421 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->NewLine();
    }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 4427 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->LineAddPointNumber( (int) (yysemantic_stack_[(6) - (5)].adouble) );
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 4433 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->EndLine();
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 4439 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      if (strlen((yysemantic_stack_[(4) - (3)].astring))<255) {
        strcpy(AMIFluid::FLUID_NAVIGATION_FILE,(yysemantic_stack_[(4) - (3)].astring));
      } else
        fprintf(stderr,"SetFluidNavFile() \t File too long \n");
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 4448 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 199:

/* Line 678 of lalr1.cc  */
#line 4548 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        ElevateMesh can have different behaviors depending on the type of
        the input image. In any case, it scans all the points of the mesh,
        and uses their 2 first coordinates (x,y) to deduce a position in
        the input image, and interpolate a value.
          - if the image is scalar, the value of the image at position
          (x,y) is used to set the elevation of the mesh (z coordinate).
          - if the image contains 2D vectors, the vectors are used to set
          the (x,y) coordinates of each vertex of the mesh.
          - if the image contains 3D vectors, those vectors are used
          to set new positions (x,y,z) for each vertex of the mesh.

      Parameters:
      (1) input surface
      (5) input image

      Example(s):
        s = CreateFlatMesh(i)
        ipos = Altitude2Postion(i,1)
        s.ElevateMesh(ipos)

      See also:
        CreateFlatMesh, ElevateMesh
        changes the position of the nodes of a 3D mesh

      **/
          GET_VARSTACK_VALUE(SurfacePoly,s);
          InrImage::ptr im ( driver.im_stack.GetLastImage());
          AMIFluid::Func_ElevateMesh(s.get(),im.get());
        }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 4581 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,sdraw);

          sdraw->GetCanvas()->UserRotate((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 4588 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,sdraw);
          SurfacePoly::ptr surf = SurfacePoly::ptr(driver.surf_stack.GetLastSurf());

          sdraw->GetCanvas()->AddSurface(surf);
          sdraw->Paint();
        }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 4596 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(SurfacePoly,surf);
          GET_VARSTACK_VALUE(Viewer3D,   sdraw);

          sdraw->GetCanvas()->AddSurface( surf);
          //sdraw->Paint();
        }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 4604 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(SurfacePoly,surf);
          GET_VARSTACK_VALUE(Viewer3D,   sdraw);

          sdraw->GetCanvas()->RemoveSurface(surf);
          sdraw->Paint();
        }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 4612 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          /**
            Description: Removes the surface without swapping the 3D buffer
          **/
          GET_VARSTACK_VALUE(SurfacePoly,surf);
          GET_VARSTACK_VALUE(Viewer3D,   sdraw);

          sdraw->GetCanvas()->RemoveSurface(surf);
          sdraw->Paint(false);
        }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 4623 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          /**
            Description:  Swaps the 3D buffer
          **/
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw(varsurfd->Pointer());

          sdraw->GetCanvas()->AfficheBuffer();
        }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 4633 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC ( (int) (yysemantic_stack_[(6) - (5)].adouble) );
          sdraw->Paint();
        }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 4641 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
          sdraw->Paint();
        }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 4649 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 209:

/* Line 678 of lalr1.cc  */
#line 4660 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,sdraw2);
          GET_VARSTACK_VALUE(Viewer3D,sdraw1);

          sdraw1->AddCompSurf(sdraw2);
        }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 4667 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 211:

/* Line 678 of lalr1.cc  */
#line 4681 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr draw (varsurfd->Pointer());
          int num = (int) (yysemantic_stack_[(16) - (5)].adouble);
          InrImage::ptr im ( driver.im_stack.GetLastImage());
          int orientation = (int) (yysemantic_stack_[(16) - (9)].adouble);
          int pos = (int) (yysemantic_stack_[(16) - (11)].adouble);
          float Imin = (yysemantic_stack_[(16) - (13)].adouble);
          float Imax = (yysemantic_stack_[(16) - (15)].adouble);

          draw->GetCanvas()->ShowFreeSection(num,im.get(),orientation,pos,Imin,Imax);

        }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 4695 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr draw (varsurfd->Pointer());
          int num = (int) (yysemantic_stack_[(6) - (5)].adouble);
    
          draw->GetCanvas()->HideFreeSection(num);
    
        }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 4704 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,v);
          v->GetCanvas()->PrintMatrices();
        }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 4709 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->GetCanvas()->SetObjectTransform(*tr);
              sdraw->Paint();
          delete tr;
        }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 4718 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->GetCanvas()->SetObjectTransform(*tr);
          if ((yysemantic_stack_[(8) - (7)].adouble)>0.5) sdraw->Paint();
          delete tr;
        }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 4727 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 217:

/* Line 678 of lalr1.cc  */
#line 4740 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 218:

/* Line 678 of lalr1.cc  */
#line 4753 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 219:

/* Line 678 of lalr1.cc  */
#line 4766 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 220:

/* Line 678 of lalr1.cc  */
#line 4779 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->GetCanvas()->SetBG((int)(yysemantic_stack_[(10) - (5)].adouble),(int)(yysemantic_stack_[(10) - (7)].adouble),(int)(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 4786 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 222:

/* Line 678 of lalr1.cc  */
#line 4796 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 223:

/* Line 678 of lalr1.cc  */
#line 4806 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 224:

/* Line 678 of lalr1.cc  */
#line 4820 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          Func_StructureTensor(im.get(),
                   varim->Name().c_str(),
                   (yysemantic_stack_[(8) - (5)].adouble), (yysemantic_stack_[(8) - (7)].adouble), NULL);
        }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 4828 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          InrImage::ptr mask ( driver.im_stack.GetLastImage());

          Func_StructureTensor(
            im.get(),
            varim->Name().c_str(),
            (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), mask.get());
        }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 4839 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 227:

/* Line 678 of lalr1.cc  */
#line 4862 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          InrImage::ptr mask ( driver.im_stack.GetLastImage());

          Func_StructureTensorHessian(
            im.get(),
            varim->Name().c_str(),
            (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), mask.get());
        }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 4888 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          InrImage::ptr mask (driver.im_stack.GetLastImage());
          int save_grad = (int) (yysemantic_stack_[(12) - (11)].adouble);

          Func_StructureTensorHessian(im.get(),
                   varim->Name().c_str(),
                   (yysemantic_stack_[(12) - (5)].adouble), (yysemantic_stack_[(12) - (7)].adouble), mask.get(), save_grad);
        }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 4916 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 230:

/* Line 678 of lalr1.cc  */
#line 4927 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 231:

/* Line 678 of lalr1.cc  */
#line 4970 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          InrImage::ptr mask (driver.im_stack.GetLastImage());

          Func_HessianMatrix(im.get(),
                 varim->Name().c_str(),
                 (yysemantic_stack_[(10) - (5)].adouble),   // sigma
                 (yysemantic_stack_[(10) - (7)].adouble),   // gamma
                 mask.get()  // mask
                 );
        }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 4992 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 233:

/* Line 678 of lalr1.cc  */
#line 5021 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage,varim,im);
          InrImage::ptr mask (driver.im_stack.GetLastImage());

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

  case 234:

/* Line 678 of lalr1.cc  */
#line 5039 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          InrImage::ptr mask (driver.im_stack.GetLastImage());

          Func_HessianVap(im.get(),
              varim->Name().c_str(),
              (yysemantic_stack_[(12) - (5)].adouble),   // sigma
              (yysemantic_stack_[(12) - (7)].adouble),   // gamma
              mask.get(),
              (int) (yysemantic_stack_[(12) - (11)].adouble) // eigenvalue number
              );
        }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 5053 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          Func_Curvatures(im.get(), varim->Name().c_str(), (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 5064 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<InrImage>::ptr  varim6( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim5( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim4( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim3( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim2( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim1( driver.var_stack.GetLastVar<InrImage>());
          InrImage::ptr mask ( driver.im_stack.GetLastImage());

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

  case 237:

/* Line 678 of lalr1.cc  */
#line 5090 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 238:

/* Line 678 of lalr1.cc  */
#line 5116 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<InrImage>::ptr  varim3( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim2( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim1( driver.var_stack.GetLastVar<InrImage>());
      InrImage::ptr mask ( driver.im_stack.GetLastImage());

          Func_Eigen2D(
               (char*) (yysemantic_stack_[(12) - (3)].astring),
               varim1 ->Pointer().get(),
               varim2 ->Pointer().get(),
               varim3 ->Pointer().get(),
               mask.get()  // mask
               );
        }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 5135 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 240:

/* Line 678 of lalr1.cc  */
#line 5149 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      im->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 5155 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      im->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 5161 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 243:

/* Line 678 of lalr1.cc  */
#line 5172 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      im->SetTranslation((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 5178 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2( driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1( driver.var_stack.GetLastVar<InrImage>());
      InrImage::ptr im (varim2->Pointer());
      varim1->Pointer()->SetVoxelSize( im->TrX(), im->TrY(), im->TrZ());
    }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 5186 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 246:

/* Line 678 of lalr1.cc  */
#line 5201 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
      Func_DiscSecDerGrad(
        varim1->Pointer().get(),
        varim2->Pointer().get());
    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 5210 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 248:

/* Line 678 of lalr1.cc  */
#line 5221 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 249:

/* Line 678 of lalr1.cc  */
#line 5238 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 250:

/* Line 678 of lalr1.cc  */
#line 5254 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
      InrImage::ptr   image (driver.im_stack.GetLastImage());
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

  case 251:

/* Line 678 of lalr1.cc  */
#line 5292 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 252:

/* Line 678 of lalr1.cc  */
#line 5310 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 253:

/* Line 678 of lalr1.cc  */
#line 5353 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));
      Func_GenRead(filename.get());
    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 5359 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.InitCumul();
    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 5364 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Debut();
    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 5369 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Fin();
      cout << "time spent = " << driver.IP_time << endl;
    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 5375 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          boost::shared_array<char> filename( (yysemantic_stack_[(6) - (5)].astring));
          GET_VARSTACK_VALUE(InrImage, i);
          Func_VectorImage2StructuredGrid(i.get(),filename.get());
        }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 5382 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(GLTransfMatrix, glmat);
          glmat->Print();
        }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 5388 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          boost::shared_array<char> filename( (yysemantic_stack_[(4) - (4)].astring));
          GET_VARSTACK_VALUE(GLTransfMatrix, glmat);
          Func_SaveTransform(glmat.get(),filename.get());
        }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 5395 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          AddWrapVTK();
        }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 5400 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          AddWrapWII();
        }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 5405 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          AddWrapFilters();
        }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 5416 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 264:

/* Line 678 of lalr1.cc  */
#line 5456 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 265:

/* Line 678 of lalr1.cc  */
#line 5507 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 266:

/* Line 678 of lalr1.cc  */
#line 5529 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = new std::list<std::string>();
            sl->push_back(string((yysemantic_stack_[(1) - (1)].astring)));
            delete [] (yysemantic_stack_[(1) - (1)].astring);
            (yyval.string_list) = sl;
        }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 5537 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = (yysemantic_stack_[(3) - (1)].string_list);
            sl->push_back(string((yysemantic_stack_[(3) - (3)].astring)));
            delete [] (yysemantic_stack_[(3) - (3)].astring);
            (yyval.string_list) = sl;
        }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 5553 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          (yyval.paramlist) = pl;
        }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 5558 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 270:

/* Line 678 of lalr1.cc  */
#line 5574 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 271:

/* Line 678 of lalr1.cc  */
#line 5592 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 272:

/* Line 678 of lalr1.cc  */
#line 5608 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 273:

/* Line 678 of lalr1.cc  */
#line 5623 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 274:

/* Line 678 of lalr1.cc  */
#line 5639 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 275:

/* Line 678 of lalr1.cc  */
#line 5658 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      //      printf("no parameters \n");
      ParamListDecl* pl = new ParamListDecl;
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 5664 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      cout << "param_list_decl: T_NUM IDENTIFIER" << endl;
      cout << ident->GetName().c_str() << endl;
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_float);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 5673 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_ami_object);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 5680 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_string);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 5687 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 5694 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 5701 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 5708 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_ami_object);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 5715 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_float);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 5722 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_string);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 5729 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 5736 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 5743 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 5751 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
    }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 5756 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 290:

/* Line 678 of lalr1.cc  */
#line 5837 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 291:

/* Line 678 of lalr1.cc  */
#line 5860 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      (yyval.astring)=(char*) (im)->GetName();
    }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 5866 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 293:

/* Line 678 of lalr1.cc  */
#line 5878 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 294:

/* Line 678 of lalr1.cc  */
#line 5898 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      char* res = new char[GB_scripts_dir.Len()+1];
      strcpy(res,(const char*)GB_scripts_dir.mb_str(wxConvUTF8));
      (yyval.astring)= res;
    }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 5931 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        (yyval.ablock)=(yysemantic_stack_[(3) - (2)].ablock);
        if (GB_debug)
          cerr << format("ablock : %s")
                  % (yysemantic_stack_[(3) - (2)].ablock)->GetBody()
                << endl;
          }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 5945 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
      Description: adds a reference to the variable in the stack
      **/
      BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
      driver.var_stack.AddVar(var->NewReference());
    }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 5955 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      ADD_VARSTACK_FLOAT((yysemantic_stack_[(1) - (1)].adouble))
    }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 5959 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      returns the number of arguments in the command line
    **/
      ADD_VARSTACK_FLOAT(GB_argc-GB_num_arg_parsed)
    }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 5967 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      Line number in the current script
    **/
      ADD_VARSTACK_FLOAT(driver.yyiplineno)
    }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 5975 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        the constant Pi is set to
         3.14159265358979323846
      **/
      ADD_VARSTACK_FLOAT(3.14159265358979323846)
    }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 5984 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
      Description: adds a reference to the variable in the stack
      **/
      BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
      driver.var_stack.AddVar(var->NewReference());
    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 6012 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 305:

/* Line 678 of lalr1.cc  */
#line 6029 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 306:

/* Line 678 of lalr1.cc  */
#line 6045 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 307:

/* Line 678 of lalr1.cc  */
#line 6062 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 308:

/* Line 678 of lalr1.cc  */
#line 6081 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 309:

/* Line 678 of lalr1.cc  */
#line 6099 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 310:

/* Line 678 of lalr1.cc  */
#line 6115 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 311:

/* Line 678 of lalr1.cc  */
#line 6131 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->DimX();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 6137 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->DimY();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 6143 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->DimZ();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 6149 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->TrX();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 6155 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->TrY();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 6161 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->TrZ();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 6167 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->VoxSizeX();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 6173 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->VoxSizeY();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 6179 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->VoxSizeZ();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 6185 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->GetVDim();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 6191 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->IncBuffer();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 6197 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->ValeurBuffer();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 6204 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(SurfacePoly,s);
      float val = s->GetNumberOfPoints();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 6211 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(SurfacePoly,s);
      float val = s->GetNumberOfPolys();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 6218 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
      float val=Func_SNR(varim1->Pointer().get(),
                  varim2->Pointer().get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 6227 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      float val=Func_eccentricity(im.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 6234 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 328:

/* Line 678 of lalr1.cc  */
#line 6265 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(InrImage, im);
      float val=Func_ComputePositiveArea( im.get() );
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 6273 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 330:

/* Line 678 of lalr1.cc  */
#line 6285 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im  (driver.im_stack.GetLastImage());
      float val=Func_count( im.get() );
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 6305 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im  (driver.im_stack.GetLastImage());
      float val=Func_mean( im.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 6325 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im  (driver.im_stack.GetLastImage());
      float val=Func_max( im.get(),NULL);
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 6345 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im  (driver.im_stack.GetLastImage());
      float val=Func_argmax( im.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 6365 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im  (driver.im_stack.GetLastImage());
      float val=Func_min( im.get(),NULL);
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 6385 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im  (driver.im_stack.GetLastImage());
      float val=Func_med( im.get(),0.5,NULL);
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 6405 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im  (driver.im_stack.GetLastImage());
      InrImage::ptr mask  (driver.im_stack.GetLastImage());
      float val=Func_max( im.get(),mask.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 6429 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
      InrImage::ptr mask  (driver.im_stack.GetLastImage());
      float val=Func_min( im.get(),mask.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 6453 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
      InrImage::ptr mask ( driver.im_stack.GetLastImage());
      float val=Func_med( im.get(),0.5,mask.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 6477 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr mask( driver.im_stack.GetLastImage());
      float val=Func_med( im.get(),(float) (yysemantic_stack_[(9) - (8)].adouble),mask.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 6485 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
      InrImage::ptr input  (driver.im_stack.GetLastImage());
      InrImage::ptr mask  (driver.im_stack.GetLastImage());
      float val=Func_mean( input.get(),mask.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 6509 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr mask (driver.im_stack.GetLastImage());
      float val=Func_mean( im.get(), mask.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 6532 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      setlocale(LC_NUMERIC, "C");
      float val=atof((yysemantic_stack_[(4) - (3)].astring));
      ADD_VARSTACK_FLOAT(val);
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 6540 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 344:

/* Line 678 of lalr1.cc  */
#line 6552 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 345:

/* Line 678 of lalr1.cc  */
#line 6564 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 346:

/* Line 678 of lalr1.cc  */
#line 6576 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 347:

/* Line 678 of lalr1.cc  */
#line 6588 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 348:

/* Line 678 of lalr1.cc  */
#line 6600 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 349:

/* Line 678 of lalr1.cc  */
#line 6612 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 350:

/* Line 678 of lalr1.cc  */
#line 6628 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 351:

/* Line 678 of lalr1.cc  */
#line 6647 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 352:

/* Line 678 of lalr1.cc  */
#line 6688 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 353:

/* Line 678 of lalr1.cc  */
#line 6698 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 354:

/* Line 678 of lalr1.cc  */
#line 6710 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 355:

/* Line 678 of lalr1.cc  */
#line 6720 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 356:

/* Line 678 of lalr1.cc  */
#line 6730 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 357:

/* Line 678 of lalr1.cc  */
#line 6742 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
        Description: returns the value of the pixel format type in float format
      **/
      float val = (int) (yysemantic_stack_[(3) - (1)].aint);
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 6750 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 359:

/* Line 678 of lalr1.cc  */
#line 6766 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 360:

/* Line 678 of lalr1.cc  */
#line 6781 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 361:

/* Line 678 of lalr1.cc  */
#line 6793 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        - input polydata
      Description: 
        Returns the number of lines of the polydata structure
    **/
      GET_VARSTACK_VALUE(SurfacePoly,s);
      float val = s->GetNumberOfLines(  );
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 6823 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 363:

/* Line 678 of lalr1.cc  */
#line 6841 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
          if (var->Type()==type_image)  {
            DYNAMIC_CAST_VARIABLE(InrImage,var,varim) 
            driver.im_stack.AddImage(varim->Pointer());
          } else {
            driver.err_print("Expecting an image variable here ... \n");
            YYABORT;
          }
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 6854 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 365:

/* Line 678 of lalr1.cc  */
#line 6875 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      driver.err_print(" char format is not available: use unsigned char \n");
      (yyval.aint)=WT_UNSIGNED_CHAR;
    }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 6880 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          (yyval.aint)=WT_UNSIGNED_CHAR;
       }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 6884 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_SHORT;
       }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 6888 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_SHORT;
       }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 6892 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_INT;
       }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 6896 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_INT;
       }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 6900 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_LONG;
       }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 6904 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT;
       }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 6908 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_DOUBLE;
       }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 6912 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_RGB;
       }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 6916 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT_VECTOR;
       }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 6920 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
         //        printf("format %d \n",(int) ( *(InrImage::ptr*) $1->Pointer())->GetFormat());
        GET_VARSTACK_VALUE(InrImage, im);
        (yyval.aint) = (int) im->GetFormat();
      }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 6930 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 379:

/* Line 678 of lalr1.cc  */
#line 6949 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        boost::shared_array<char> st( (yysemantic_stack_[(2) - (2)].astring));
        bool res = driver.im_stack.AddFileImage(st.get());
        if (!res) YYABORT;
      }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 7125 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

        driver.im_stack.AddImage(res);
      }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 7145 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

        driver.im_stack.AddImage(res);
      }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 7180 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          int res;
          string name;
          string inc_cmd; // increment the command line string

          res=AskImage(name);
          if (!res) {
            driver.yyiperror(" Need Image \n");
            YYABORT;
          }
          bool res1 = driver.im_stack.AddFileImage((char*)name.c_str());
          if (!res1) YYABORT;

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

  case 383:

/* Line 678 of lalr1.cc  */
#line 7209 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        //printf(" ********** %d %f %f %f\n", $3, $5, $7, $9);
        InrImage::ptr im (new InrImage( (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble), (WORDTYPE) (yysemantic_stack_[(10) - (3)].aint)));
        driver.im_stack.AddImage(im);
      }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 7216 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
    driver.im_stack.AddImage(im);
    }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 7234 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
      driver.im_stack.AddImage(im);
    }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 7259 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
        Description: returning a reference to the image here ...
      **/
      GET_VARSTACK_VAR_VAL(InrImage,var,im);


/*
      // do we need a copy here ???
      // Yes, we need a copy until we know that the operators, methods, etc.. cannot change the value of the variable !!!
      std::string imname = (boost::format("copy_%s") % var->Name().c_str()).str();
      InrImage::ptr imcopy (new InrImage(im->GetFormat(),im->GetVDim(),imname.c_str(),im.get()));
      (*imcopy)=(*im);
      driver.im_stack.AddImage(imcopy);
*/
      // returning reference here since the smart pointers will take care of everything (hopefully :) !!!)
      // and we can't return a copy here otherwise a=b won't work !!!
      driver.im_stack.AddImage(im);
/*
      GET_VARSTACK_VAR_VAL(InrImage,var,varim);
      InrImage::ptr im;
      std::string  imname;

      driver.im_stack.AddImage(im);
      // driver.im_stack.AddImage(varim);
*/
    }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 7354 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
          InrImage::ptr im ( driver.im_stack.GetLastImage());
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
      driver.im_stack.AddImagePointer(res);
    }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 7420 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im ( driver.im_stack.GetLastImage());
      InrImage* res =Func_localmean( im.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      driver.im_stack.AddImagePointer(res);
    }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 7427 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im (driver.im_stack.GetLastImage());
      InrImage* res =Func_localmean2( im.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      driver.im_stack.AddImagePointer(res);
    }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 7434 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr mean    ( driver.im_stack.GetLastImage());
      InrImage::ptr im      ( driver.im_stack.GetLastImage());
      InrImage* res     = Func_localSD( im.get(), mean.get(), (int) (yysemantic_stack_[(8) - (7)].adouble));
      driver.im_stack.AddImagePointer(res);
    }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 7442 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr mean  ( driver.im_stack.GetLastImage());
      InrImage::ptr im    ( driver.im_stack.GetLastImage());
      InrImage::ptr res(Func_localSD2( im.get(), mean.get(), (int) (yysemantic_stack_[(8) - (7)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 7450 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res (Func_OpImage(im.get(),
                NULL,
                NULL,
                (yysemantic_stack_[(6) - (5)].astring)));
      Si (!res.get()) Alors
        driver.err_print("OpImage() erreur ... \n");
      FinSi
  
      driver.im_stack.AddImage(res);

      }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 7466 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

    driver.im_stack.AddImage(res);


      }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 7484 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

    driver.im_stack.AddImage(res);

      }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 7502 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

    driver.im_stack.AddImage(res);

      }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 7519 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

        driver.im_stack.AddImage(res);
      }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 7537 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
        driver.im_stack.AddImage(res);
      }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 7557 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
        InrImage::ptr im (driver.im_stack.GetLastImage());

        InrImage::ptr res( Func_Filter( im.get(),
                  (yysemantic_stack_[(12) - (5)].adouble),
                  (int) (yysemantic_stack_[(12) - (7)].adouble),
                  (int) (yysemantic_stack_[(12) - (9)].adouble),
                  (int) (yysemantic_stack_[(12) - (11)].adouble)));

        Si (!res.get()) Alors
          driver.err_print("Filter() erreur ... \n");
        FinSi
        driver.im_stack.AddImage(res);
      }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 7590 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        float var           = (yysemantic_stack_[(10) - (7)].adouble);
        float lowthreshold  = (yysemantic_stack_[(10) - (9)].adouble);
        //float highthreshold = $11;
        GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_itkCannyEdgeDetector(  im.get(), var, lowthreshold));
        Si (!res.get()) Alors
          driver.err_print("itk.CannyEdgeDetector() error ... \n");
        FinSi
        driver.im_stack.AddImage(res);
      }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 7603 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkDist( im.get()));

        Si (!res.get()) Alors
          driver.err_print("vtkDist() erreur ... \n");
        FinSi
        driver.im_stack.AddImage(res);
      }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 7614 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res (Func_vtkMedianFilter3D(
            im.get(),
            (int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble)));

        Si (!res.get()) Alors
          driver.err_print("vtkMedian3D() erreur ... \n");
        FinSi
        driver.im_stack.AddImage(res);
      }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 7627 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
          driver.im_stack.AddImage(res);
        FinSi
*/
      }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 7651 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr res (Func_2DFlux( driver.im_stack.GetLastImage().get(),(yysemantic_stack_[(6) - (5)].adouble)));

    Si (res.get()) Alors
      driver.err_print("2DFlux() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 7661 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_OutFlux( im.get()));

      Si (!res.get()) Alors
        driver.err_print("OutFlux() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
      }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 7672 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_OutFluxScalar( im.get()));
    Si (!res.get()) Alors
      driver.err_print("OutFluxScalar() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 7682 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_OrientationRatio2D( im.get()));
    Si (!res.get()) Alors
      driver.err_print("OrientationRatio() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 7692 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
    driver.im_stack.AddImage(res);
      }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 7725 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_SimplePoints( im.get() ));

    Si !res.get() Alors
      driver.err_print("SimplePoints() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 7737 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
        driver.im_stack.AddImage(res);
      }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 7758 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
      driver.im_stack.AddImage(res);
      }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 7778 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
        driver.im_stack.AddImage(res);
      }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 7819 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
      driver.im_stack.AddImage(res);
      }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 7865 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

    driver.im_stack.AddImage(res);
      }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 7885 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
    driver.im_stack.AddImage(res);
      }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 7906 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res( Func_NormalSmoothField( im.get() ));

    Si !res.get() Alors
      driver.err_print("NormalField() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 7917 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
    InrImage::ptr res( Func_NormalSmoothField( 
                    varim1->Pointer().get() , 
                    varim2->Pointer().get() ));

    Si !res.get() Alors
      driver.err_print("NormalField() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 7931 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
    InrImage::ptr res( Func_DirConnectivity( 
        varim1->Pointer().get() ,
        varim2->Pointer().get() ));

    Si res.get() Alors
      driver.err_print("DirConnectivity() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 7947 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr input ( driver.im_stack.GetLastImage());

    InrImage::ptr res ( Func_NormGrad( input.get(), (yysemantic_stack_[(6) - (5)].adouble)));
    Si (!res.get()) Alors
      driver.err_print("NormGrad() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 7959 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_DiscNormGrad( im.get()));
    Si !res.get() Alors
      driver.err_print("discnormgrad() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 7970 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_DiscMeanCurvature( im.get()));
    Si !res.get() Alors
      driver.err_print("DiscMeanCurvature() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 7982 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_Gradient( im.get(),
                 (yysemantic_stack_[(6) - (5)].adouble)));
    Si !res.get() Alors
      driver.err_print("Filter() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 7993 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
    driver.im_stack.AddImage(res);
        }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 8013 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage,im);
        InrImage::ptr res (Func_SecDerGrad( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
        Si !res.get() Alors
          fprintf(stderr,"SecDerGrad() erreur ... \n");
        FinSi
        driver.im_stack.AddImage(res);
      }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 8025 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage,im);
        InrImage::ptr res ( Func_SecDerGrad2( im.get(),
                 (yysemantic_stack_[(6) - (5)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SecDerGrad2() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
    }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 8035 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        InrImage::ptr im ( driver.im_stack.GetLastImage());
        InrImage::ptr res ( Func_AutoCrop(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
        driver.im_stack.AddImage(res);
    }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 8090 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
    driver.im_stack.AddImage(res);
      }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 8128 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_EDP_dilate( im.get(),
                   (yysemantic_stack_[(10) - (5)].adouble),  (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 8139 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_EDP_dilate( im.get(), (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 8149 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    float Imin = (yysemantic_stack_[(12) - (9)].adouble);
    float Imax = (yysemantic_stack_[(12) - (11)].adouble);
    InrImage::ptr res ( Func_EDP_dilate( im.get(), (yysemantic_stack_[(12) - (5)].adouble),  (yysemantic_stack_[(12) - (7)].adouble), Imin, Imax));
    Si (!res.get()) Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 8161 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_EDP_erode( im.get(),
                  (yysemantic_stack_[(10) - (5)].adouble),  (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 8172 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_EDP_erode( im.get(), (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 8182 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
    driver.im_stack.AddImage(res);
      }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 8209 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
    driver.im_stack.AddImage(res);
      }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 8232 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
    driver.im_stack.AddImage(res);
      }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 8260 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage,im);
    InrImage::ptr res ( Func_EDP_close( im.get(),
                   (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble)));

    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 8273 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    float Imin = (yysemantic_stack_[(12) - (9)].adouble);
    float Imax = (yysemantic_stack_[(12) - (11)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_EDP_close( im.get(),
                   (yysemantic_stack_[(12) - (5)].adouble),  (yysemantic_stack_[(12) - (7)].adouble), Imin, Imax));

    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 8407 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
      driver.im_stack.AddImage(res);
    }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 8442 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
      driver.im_stack.AddImage(res);

    }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 8475 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
      driver.im_stack.AddImage(res);

    }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 8503 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_InitWeickert( im.get(),
                (yysemantic_stack_[(12) - (7)].adouble),  (yysemantic_stack_[(12) - (9)].adouble), (yysemantic_stack_[(12) - (11)].adouble)));

      Si !res.get() Alors
        fprintf(stderr,"Func_InitWeickert() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
        }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 8517 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_InitWeickertCoherence( im.get(),
                (yysemantic_stack_[(16) - (7)].adouble),  (yysemantic_stack_[(16) - (9)].adouble), (yysemantic_stack_[(16) - (11)].adouble), (yysemantic_stack_[(16) - (13)].adouble), (yysemantic_stack_[(16) - (15)].adouble)));

      Si !res.get() Alors
        fprintf(stderr,"Func_InitWeickert() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
        }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 8529 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_SRAD_qcoeff( im.get()));
      Si !res.get() Alors
        fprintf(stderr,"Func_SRAD_qcoeff() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
        }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 8541 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
      driver.im_stack.AddImage(res);
    }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 8559 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_OBJECT(ImageExtent, ImageExtent<float>, extent)
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
      driver.im_stack.AddImage(res);
    }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 8578 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_OBJECT(ImageExtent, ImageExtent<float>, extent)
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
      driver.im_stack.AddImage(res);
    }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 8598 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_OBJECT(ImageExtent, ImageExtent<float>, extent)
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

      driver.im_stack.AddImage(res);
    }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 8620 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_OBJECT(ImageExtent, ImageExtent<float>, extent)
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

      driver.im_stack.AddImage(res);
    }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 8640 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_OBJECT(ImageExtent, ImageExtent<float>, extent)
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
      driver.im_stack.AddImage(res);
    }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 8659 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_OBJECT(ImageExtent, ImageExtent<float>, extent)
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
      driver.im_stack.AddImage(res);
    }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 8679 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_OBJECT(ImageExtent, ImageExtent<float>, extent)
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
      driver.im_stack.AddImage(res);
    }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 8699 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
      GET_VARSTACK_OBJECT(ImageExtent, ImageExtent<float>, extent)
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
      driver.im_stack.AddImage(res);
    }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 8740 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
      driver.im_stack.AddImage(res);
    }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 8762 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
      driver.im_stack.AddImage(res);

    }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 8790 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

      driver.im_stack.AddImage(res);
        }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 8811 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
        driver.im_stack.AddImage(res);
        }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 8848 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

        driver.im_stack.AddImage(res);
        }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 8885 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

        driver.im_stack.AddImage(res);
        }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 8922 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
        driver.im_stack.AddImage(res);
        }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 8956 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          driver.im_stack.AddImage(InrImage::ptr(( varsurfd->Pointer())->GetCanvas()->GetGLImage()));
        }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 8962 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          driver.yyiperror("Not available in new wxwidgets version of the 3D viewer ! ");
          driver.im_stack.AddImage(InrImage::ptr());
/*
          driver.im_stack.AddImage((*(Viewer3D_ptr*) $1->Pointer())->GetInrImage());
*/
    }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 8972 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(DessinImage, imdraw)
      driver.im_stack.AddImagePointer(imdraw->GetInrImage());
    }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 8978 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_ThresholdCrossing( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
       driver.im_stack.AddImage(res);
    }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 8985 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_IsocontourPoints( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 8992 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_IsosurfDist( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);

    }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 9000 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_vtkIsoContourDist( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 9007 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3) input image
      (5) initialization image
      (7) maximal time
    Description:
      Runs the fast marching algorithm
     **/

        InrImage::ptr    init (driver.im_stack.GetLastImage()); // 2nd param
        InrImage::ptr    input(driver.im_stack.GetLastImage()); // 1st param
        float   maxtime = (float) (yysemantic_stack_[(8) - (7)].adouble);

        InrImage::ptr res ( Func_vtkFastMarching( input.get(), init.get(),  maxtime));
        driver.im_stack.AddImage(res);
    }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 9028 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

      InrImage::ptr init  (driver.im_stack.GetLastImage());
      InrImage::ptr input (driver.im_stack.GetLastImage());
      float   maxtime = (float) (yysemantic_stack_[(14) - (7)].adouble);

      InrImage::ptr res ( Func_vtkFastMarchingTarget( input.get(), init.get(),  maxtime,
              (int) round((yysemantic_stack_[(14) - (9)].adouble)),
              (int) round((yysemantic_stack_[(14) - (11)].adouble)),
              (int) round((yysemantic_stack_[(14) - (13)].adouble))
              ));
      driver.im_stack.AddImage(res);
    }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 9055 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

      InrImage::ptr init  (driver.im_stack.GetLastImage());
      InrImage::ptr input (driver.im_stack.GetLastImage());
      float   mean    = (float) (yysemantic_stack_[(12) - (7)].adouble);
      float   sd      = (float) (yysemantic_stack_[(12) - (9)].adouble);
      float   maxtime = (float) (yysemantic_stack_[(12) - (11)].adouble);

      InrImage::ptr res ( Func_vtkFastMarching( input.get(), init.get(), mean, sd, maxtime));
      driver.im_stack.AddImage(res);
    }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 9079 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

      InrImage::ptr init  (driver.im_stack.GetLastImage());
      InrImage::ptr input (driver.im_stack.GetLastImage());
      float   mean     = (float) (yysemantic_stack_[(14) - (7)].adouble);
      float   sd       = (float) (yysemantic_stack_[(14) - (9)].adouble);
      float   maxtime  = (float) (yysemantic_stack_[(14) - (11)].adouble);
      int     inittype = (int) (yysemantic_stack_[(14) - (13)].adouble);

      InrImage::ptr res ( Func_vtkFastMarching( input.get(), init.get(), mean, sd, maxtime,inittype));
      driver.im_stack.AddImage(res);
    }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 9108 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

      InrImage::ptr init ( driver.im_stack.GetLastImage());
      InrImage::ptr input( driver.im_stack.GetLastImage());
      float   maxtime    = (float) (yysemantic_stack_[(12) - (9)].adouble);
      int     inittype   = (int)   (yysemantic_stack_[(12) - (11)].adouble);
      GET_VARSTACK_VALUE(InrImage, im);

      InrImage::ptr res ( Func_vtkFastMarching(
                  input.get(),
                  init.get(),
                  im.get(),
                  maxtime,inittype));
      driver.im_stack.AddImage(res);
    }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 9137 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
      InrImage::ptr res ( Func_Convolve(
                  varim1->Pointer().get(),
                  varim2->Pointer().get()));
      driver.im_stack.AddImage(res);

      }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 9148 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
        InrImage::ptr mask (driver.im_stack.GetLastImage());

        InrImage::ptr res ( Func_ConvolveMask(varim1->Pointer().get(),
                  varim2->Pointer().get(),
                  mask.get()));
        driver.im_stack.AddImage(res);

      }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 9161 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_Chamfer(im.get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble)));
        driver.im_stack.AddImage(res);
        }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 9168 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
          InrImage::ptr res ( Func_Chamfer2(im.get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble)));
          driver.im_stack.AddImage(res);

        }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 9176 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {

        float a = (yysemantic_stack_[(12) - (5)].adouble);
        float b = (yysemantic_stack_[(12) - (7)].adouble);
        float c = (yysemantic_stack_[(12) - (9)].adouble);
        float dmax = (yysemantic_stack_[(12) - (11)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_Chamfer2(im.get(), a,b,c,dmax));
        driver.im_stack.AddImage(res);

        }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 9190 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr  res ( Func_Chamfer2(im.get(),
                  0.92644, 1.34065, 1.65849,
                  dmax));
        driver.im_stack.AddImage(res);

        }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 9202 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_Chamfer2Signed(im.get(),
                    0.92644, 1.34065, 1.65849,
                    dmax));
        driver.im_stack.AddImage(res);

        }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 9214 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkSignedBorgefors(im.get(),
                    dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 9224 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkSignedFMDist(im.get(),
                     dmax));
        driver.im_stack.AddImage(res);

        }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 9235 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_PropagationDistance(im.get(),
                      dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 9245 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_PropagationDistance2(im.get(),
                      dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 9255 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

        GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_PropagationDanielsson(im.get(),
                       dmax));

        driver.im_stack.AddImage(res);
        }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 9266 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkPropDanielsson(im.get(),
                       -dmax,dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 9276 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        float dmin = (yysemantic_stack_[(8) - (5)].adouble);
        float dmax = (yysemantic_stack_[(8) - (7)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkPropDanielsson(im.get(),
                       dmin,dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 9287 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

        driver.im_stack.AddImage(res);
        }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 9314 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im(driver.im_stack.GetLastImage());
      InrImage::ptr res ( Func_CC(im.get()));
      driver.im_stack.AddImage(res);
    }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 9362 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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


/*
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
*/

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
          InrImage::ptr im2( driver.im_stack.GetLastImage());
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
    
          Variable<InrImage>::ptr new_var(new Variable<InrImage>(res));
          driver.var_stack.AddVar(new_var);

        }
        else {
          driver.err_print("operator image(expr_var), wrong type of parameter \n");
          YYABORT;
        }
      }


    }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 9544 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im( driver.im_stack.GetLastImage());
      float vmin  = (yysemantic_stack_[(10) - (5)].adouble);
      float vmax  = (yysemantic_stack_[(10) - (7)].adouble);
      int   nint = (int) (yysemantic_stack_[(10) - (9)].adouble); // number of intervals

      InrImage::ptr res ( Func_Histogram(im.get(),vmin,vmax,nint));
      driver.im_stack.AddImage(res);
    }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 9565 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im(driver.im_stack.GetLastImage());
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

      driver.im_stack.AddImage(res);
    }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 9605 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im (driver.im_stack.GetLastImage());
      InrImage::ptr res;
      if (im->DimZ()>1)
        res = InrImage::ptr( Func_MeanHalfSize(im.get(),3));
      else
        res = InrImage::ptr( Func_MeanHalfSize(im.get(),2));

      driver.im_stack.AddImage(res);
    }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 9616 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      int dim = (int) (yysemantic_stack_[(6) - (5)].adouble);

      InrImage::ptr im (driver.im_stack.GetLastImage());
      InrImage::ptr res ( Func_MeanHalfSize(im.get(),dim));
      driver.im_stack.AddImage(res);
    }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 9624 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        int axis=(int) (yysemantic_stack_[(6) - (5)].adouble);

        InrImage::ptr im (driver.im_stack.GetLastImage());
        InrImage::ptr res(Func_Flip(im,axis));
        driver.im_stack.AddImage(res);
    }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 9632 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

            InrImage::ptr im (driver.im_stack.GetLastImage());
            InrImage::ptr res ( Func_Resize(im.get(),sx,sy,sz,interpolate));
            driver.im_stack.AddImage(res);
    }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 9653 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
      driver.im_stack.AddImage(res);

    }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 9679 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      int   order = (int) (yysemantic_stack_[(8) - (5)].adouble);
      float resolution = (yysemantic_stack_[(8) - (7)].adouble);
      InrImage::ptr input(driver.im_stack.GetLastImage());

      InrImage::ptr res ( Func_vtkConvexHull(input.get(),
                   order,resolution));

      driver.im_stack.AddImage(res);
    }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 9690 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(SurfacePoly,s);

      InrImage::ptr res ( s->GetImageLinesLength(  ));
      driver.im_stack.AddImage(res);
    }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 9697 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      /**
        Parameters:
          - input polydata
          - line number
        Description:
          Get the points of the given line as a vectorial 1D image of 
          the point positions.
      **/
      InrImage::ptr         res;
      GET_VARSTACK_VAR_VAL(SurfacePoly,var,s);
      int linenumber = (int) (yysemantic_stack_[(6) - (5)].adouble);
      
      if ((linenumber>=0)&&(linenumber<s->GetNumberOfLines())) {
        T_Line line=s->GetLine(linenumber);
        if (line.NbElts()>0) {
          // Create the image
          res = InrImage::ptr(new InrImage(line.NbElts(),1,1,3,WT_FLOAT,
            (boost::format("%1%_line%2%") 
              % var->Name()
              % linenumber
            ).str().c_str()));
          // fill it with the point positions
          for(int n=0;n<line.NbElts();n++) {
            res->BufferPos(n,0,0);
            Point_3D<float>  pt = s->GetPoint(line[n]).pt;
            res->VectFixeValeurs( pt.X(),pt.Y(),pt.Z());
          }
          driver.im_stack.AddImage(res);
        } else
          driver.err_print((boost::format("Line %1% has no point.") % linenumber).str());
      } else {
        driver.err_print("Invalid line number.");
      }

    }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 9734 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        - input polydata containing lines
      Description:
        Returns an image Mx2 where M is the number of lines and 
        containing the point id of the 2 extremities of each 
        line
    **/
      GET_VARSTACK_VALUE(SurfacePoly,s);

      InrImage::ptr res ( s->GetImageLinesExtremities(  ));
      driver.im_stack.AddImage(res);
    }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 9749 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        - input polydata containing lines
      Description:
        Get the number of lines connected to each point.
        The result is given as a 1D image of size the total
        number of points of the polydata
    **/

      GET_VARSTACK_VALUE(SurfacePoly,s);
      InrImage::ptr res ( s->GetImageConnections(  ));
      driver.im_stack.AddImage(res);
    }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 9764 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      GET_VARSTACK_VALUE(SurfacePoly,s);

      InrImage::ptr res ( s->GetIntensities( im.get() ));
      driver.im_stack.AddImage(res);
    }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 9772 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im ( driver.im_stack.GetLastImage());

      InrImage::ptr res ( AMIFluid::Func_Altitude2Position(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 9779 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im (driver.im_stack.GetLastImage());
      InrImage::ptr res ( AMIFluid::Func_Altitude2Position(im.get()));
      driver.im_stack.AddImage(res);
    }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 9785 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im( driver.im_stack.GetLastImage());
      InrImage::ptr res ( AMIFluid::Func_GeoCoordinates(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 9791 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im( driver.im_stack.GetLastImage());
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im.get());
      if (res!=NULL) driver.im_stack.AddImagePointer(res);
    }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 9798 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
      InrImage::ptr coeff (driver.im_stack.GetLastImage());
      InrImage::ptr input (driver.im_stack.GetLastImage());
      InrImage* res;

      res = AMIFluid::Func_ComputeAltitudes(input.get(),coeff.get());
      driver.im_stack.AddImagePointer(res);

    }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 9823 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**

        Description:
        Compute the altitude to the sea level based on the
        temperature channel.

        Parameters:
        (3) image containing the temperature at the top of the clouds
        in Kelvin.

        **/
      InrImage::ptr input (driver.im_stack.GetLastImage());
      InrImage::ptr res ( AMIFluid::Func_Temp2Altitudes(input.get()));
      driver.im_stack.AddImage(res);

    }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 9841 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));
      InrImage::ptr res( AMIFluid::Func_ReadFlow(filename.get()));
      driver.im_stack.AddImage(res);
    }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 9848 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
        InrImage::ptr im (driver.im_stack.GetLastImage());

        if (im->_format==WT_UNSIGNED_CHAR) {
          ImageDraw<unsigned char> imdraw;
          imdraw.SetInput((unsigned char*)im->GetData(),im->DimX(),im->DimY(),im->DimZ());
          imdraw.SetVoxelSize(im->VoxSizeX(),im->VoxSizeY(),im->VoxSizeZ());
          imdraw.SetCursorPosition((int)(yysemantic_stack_[(18) - (9)].adouble),(int)(yysemantic_stack_[(18) - (11)].adouble),(int)(yysemantic_stack_[(18) - (13)].adouble));
          imdraw.Apply((int)(yysemantic_stack_[(18) - (5)].adouble),(int)(yysemantic_stack_[(18) - (7)].adouble),(int)(yysemantic_stack_[(18) - (15)].adouble),(int)(yysemantic_stack_[(18) - (17)].adouble));
          // copy to RGB image
          InrImage::ptr res ( new InrImage(imdraw.RGB_width, imdraw.RGB_height, 1, WT_RGB));
          memcpy(res->GetData(),imdraw.RGB_image,imdraw.RGB_width*imdraw.RGB_height*3);
          driver.im_stack.AddImage(res);
        } else
          fprintf(stderr,"only UCHAR format for now \n");
        }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 9881 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
      GET_VARSTACK_VALUE(InrImage,ref);
      GET_VARSTACK_VALUE(SurfacePoly,surf);
      InrImage::ptr rad = InrImage::ptr(
                                driver.im_stack.GetLastImage());

      InrImage::ptr res ( LineRecons( surf.get(), ref.get(), rad.get()));
      driver.im_stack.AddImage(res);
    }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 9901 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3) input line read with ReadCTALine
      (5) name of the file
    Description:
      Reads the radius information and save it to an image,
      returns this image.
    **/
      GET_VARSTACK_VALUE(SurfacePoly,surf);
      boost::shared_array<char> filename( (yysemantic_stack_[(6) - (5)].astring));

      InrImage::ptr res ( Func_ReadCTALineRadii( surf.get(), filename.get()));
      driver.im_stack.AddImage(res);
    }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 10073 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Description: convert the pointer to an image in im_stack to a pointer to a image variable in var_stack
      TODO: get completely rid of im_stack later ...
    **/
    InrImage::ptr im (driver.im_stack.GetLastImage());
    Variable<InrImage>::ptr new_var(new Variable<InrImage>(im));
    driver.var_stack.AddVar(new_var);
  }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 10086 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
    Description: adds a reference to the variable in the stack
    **/
    BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->NewReference());
  }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 10095 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 522:

/* Line 678 of lalr1.cc  */
#line 10125 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 523:

/* Line 678 of lalr1.cc  */
#line 10187 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 526:

/* Line 678 of lalr1.cc  */
#line 10269 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Logical negation (NOT) operator.
    **/
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(!(*var));
  }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 10277 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Postfix increment operator.
    **/
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar((*var)++);
  }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 10285 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Postfix decrement operator.
    **/
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar((*var)--);
  }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 10294 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Cast operator.
    **/
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->BasicCast( (yysemantic_stack_[(4) - (2)].aint)));

  }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 10303 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Transpose operator, usefull for matrices
    **/
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->Transpose());
  }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 10312 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Array subscript operator.
    **/
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)[var2]);
  }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 10325 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    //cout << "T_SUB  cast_var  " << endl;
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(-(*var));
  }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 10331 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(+(*var));
  }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 10336 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(++(*var));
  }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 10341 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(--(*var));
  }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 10346 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_sin());
  }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 10351 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_cos());
  }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 10356 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_sqrt());
  }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 10361 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_fabs());
  }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 10366 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_round());
  }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 10371 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_floor());
  }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 10376 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_tan());
  }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 10381 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_asin());
  }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 10386 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_acos());
  }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 10391 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_atan());
  }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 10396 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_exp());
  }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 10401 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_log());
  }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 10406 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_ln());
  }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 10411 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var)
    driver.var_stack.AddVar(var->m_norm());
  }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 10421 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)*var2);
  }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 10427 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)/var2);
  }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 10433 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)%var2);
  }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 10444 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    BasicVariable::ptr res(*var1+var2);
    driver.var_stack.AddVar(res);
  }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 10451 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    BasicVariable::ptr res((*var1)-var2);
    driver.var_stack.AddVar(res);
  }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 10466 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)<var2);
  }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 10472 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)>var2);
  }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 10478 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)<=var2);
  }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 10484 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)>=var2);
  }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 10494 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)==var2);
  }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 10500 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)!=var2);
  }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 10541 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Descriptiopn: Logical AND operator
    **/
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)&&var2);
  }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 10554 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Descriptiopn: Logical XOR operator, for vectorial images it defines the pointwise vectorial product.
    **/
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)^var2);
  }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 10567 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Descriptiopn: Logical OR operator
    **/
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)||var2);
  }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 10580 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 581:

/* Line 678 of lalr1.cc  */
#line 10594 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 582:

/* Line 678 of lalr1.cc  */
#line 10604 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)+=var2);
  }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 10610 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)-=var2);
  }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 10616 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)*=var2);
  }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 10622 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    GET_CHECK_VARSTACK(var2)
    GET_CHECK_VARSTACK(var1)
    driver.var_stack.AddVar((*var1)/=var2);
  }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 10634 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
            GET_VARSTACK_VALUE(GLTransfMatrix,glt);
            GLTransfMatrix* newglt;

            newglt = new GLTransfMatrix();
            (*newglt) = (*glt);
            driver.gltransf_stack.AddMatrix(newglt);
    
        }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 10645 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 589:

/* Line 678 of lalr1.cc  */
#line 10659 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(GLTransfMatrix,glt2);
        GET_VARSTACK_VALUE(GLTransfMatrix,glt1);
        GLTransfMatrix* newglt = NULL;
        float coeff = (yysemantic_stack_[(8) - (7)].adouble);

        newglt = Func_InterpolateTransform(glt1.get(),glt2.get(),coeff);
        driver.gltransf_stack.AddMatrix(newglt);
      }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 10670 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 591:

/* Line 678 of lalr1.cc  */
#line 10688 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
         FloatMatrix::ptr m( new FloatMatrix((int)(yysemantic_stack_[(6) - (3)].adouble),(int)(yysemantic_stack_[(6) - (5)].adouble)));
         ADD_VARSTACK_PTR(FloatMatrix,m);
      }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 10694 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Description: adds a reference to the variable in the stack
        **/
        BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
        driver.var_stack.AddVar(var->NewReference());
      }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 10703 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 595:

/* Line 678 of lalr1.cc  */
#line 10826 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 596:

/* Line 678 of lalr1.cc  */
#line 10844 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          InrImage::ptr im (driver.im_stack.GetLastImage());
          surf = Func_isosurf(im,
                  (yysemantic_stack_[(6) - (5)].adouble),
                  NULL);
          if (surf==NULL) driver.err_print("Isosurface failed!");
          driver.surf_stack.AddSurf(surf);
    }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 10855 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
        SurfacePoly* surf;
        surf = Func_isosurf(im,
                (yysemantic_stack_[(6) - (5)].adouble),
                NULL,
                2);
        driver.surf_stack.AddSurf(surf);
    }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 10866 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
        InrImage::ptr im (driver.im_stack.GetLastImage());
        SurfacePoly* surf;
        surf = Func_isosurf(im,
                (yysemantic_stack_[(8) - (5)].adouble),
                mask.get());
        if (surf==NULL) driver.err_print("Isosurface failed!");
        driver.surf_stack.AddSurf(surf);
    }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 10887 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
      InrImage::ptr mask (driver.im_stack.GetLastImage());
      InrImage::ptr im   (driver.im_stack.GetLastImage());
      vtkPolyData* vtklines;
      CreeCrest* crestlines;
      SurfacePoly* lines;

      crestlines = Func_IsoLine(im.get(), (yysemantic_stack_[(8) - (5)].adouble), mask.get());
      printf("running conversion to vtkPolyData ...");
      vtklines = (vtkPolyData*) (*crestlines);

      lines = new SurfacePoly(vtklines);
      if (lines == NULL)
        driver.err_print("IsoLine failed!");
      driver.surf_stack.AddSurf(lines);

      //vtklines->Delete();
      delete crestlines;

    }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 10921 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(SurfacePoly,varsurf);
      SurfacePoly* surf;
      surf = Func_decimate( varsurf.get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 10931 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* newsurf;
      GET_VARSTACK_VALUE(SurfacePoly,surf);

      newsurf = Func_decimate( surf.get(), (yysemantic_stack_[(6) - (5)].adouble) );
      Si newsurf != NULL Alors
        driver.surf_stack.AddSurf(newsurf);
      FinSi
    }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 10942 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
      GET_VARSTACK_VALUE(InrImage, im);
          surf = Func_vtkMarchingCubes(im.get(),(yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 10952 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* newsurf;
      GET_VARSTACK_VALUE(SurfacePoly,surf);

      newsurf = Func_vtkSmooth(surf.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      Si newsurf != NULL Alors
        driver.surf_stack.AddSurf(newsurf);
      FinSi
    }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 10963 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(SurfacePoly, surf);
        SurfacePoly* newsurf;

        newsurf = Func_vtkWindowedSinc( surf.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
        if (newsurf==NULL) driver.err_print("vtkWindowedSinc failed!");
        driver.surf_stack.AddSurf(newsurf);
    }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 10973 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf = new SurfacePoly();
      driver.surf_stack.AddSurf(surf);
    }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 10979 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(2) - (2)].astring));
      driver.surf_stack.AddSurf(filename.get());
    }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 10993 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
          int res;
          string name;
          string inc_cmd; // increment the command line string

          res=AskSurface(name);
          if (!res) {
            driver.yyiperror(" Need Surface \n");
            YYABORT;
          }
          driver.surf_stack.AddSurf((char*)name.c_str());

          wxFileName filename(GetwxStr(name));
          filename.Normalize(wxPATH_NORM_ALL,wxEmptyString,wxPATH_UNIX);
          wxString newname(   filename.GetVolume()+filename.GetVolumeSeparator()+
                              filename.GetPath(wxPATH_GET_VOLUME,wxPATH_UNIX)+
                              filename.GetPathSeparator(wxPATH_UNIX)+
                              filename.GetFullName());


          inc_cmd = str(format(" \"%1%\"  // from browser ") % newname.mb_str());
          if (driver.InConsole())
            GB_main_wxFrame->GetConsole()->IncCommand(inc_cmd);
        }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 11019 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
          driver.surf_stack.AddSurf(surf);
      }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 11034 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
          driver.surf_stack.AddSurf(surf);
      }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 11052 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(SurfacePoly,surf);
        SurfacePoly* newsurf;
  
        newsurf = new SurfacePoly( (*surf) );
        driver.surf_stack.AddSurf(newsurf);
      }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 11061 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Creates lines from a skeleton image
        **/
          SurfacePoly* surf;

      GET_VARSTACK_VALUE(InrImage, im);
      surf = Func_Skeleton2lines( im.get()  );

      Si surf==NULL Alors
        driver.err_print("Skeleton2lines() error ... \n");
      FinSi
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 11080 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
      GET_VARSTACK_VALUE(SurfacePoly, insurf);
      SurfacePoly* surf;

      surf = Func_SmoothLines( insurf.get(),
                      0.1,
                      0.01,
                      10);

      Si surf==NULL Alors
        driver.err_print("SmoothLines() error ... \n");
      FinSi
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 11109 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
      GET_VARSTACK_VALUE(SurfacePoly, insurf);
      SurfacePoly* surf;

      surf = Func_SmoothLines( insurf.get(),
                      (yysemantic_stack_[(10) - (5)].adouble),
                      (yysemantic_stack_[(10) - (7)].adouble),
                      (int) (yysemantic_stack_[(10) - (9)].adouble));

      Si surf==NULL Alors
        driver.err_print("SmoothLines() error ... \n");
      FinSi
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 11137 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(SurfacePoly, insurf);
      SurfacePoly* surf;

      surf = Func_ResampleLines( insurf.get(),
                     (yysemantic_stack_[(6) - (5)].adouble));

      Si surf==NULL Alors
        driver.err_print("ResampleLines() error ... \n");
      FinSi
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 11154 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        - input polydata containing lines
        - point 1: x,y,z
        - point 2: x,y,z 
      Description:
        Finds the shortest path within the lines of the polydata
    **/
      GET_VARSTACK_VALUE(SurfacePoly, insurf);
      SurfacePoly* surf;

      surf = Func_shortestpath( insurf.get(),
                      (yysemantic_stack_[(16) - (5)].adouble), (yysemantic_stack_[(16) - (7)].adouble), (yysemantic_stack_[(16) - (9)].adouble),
                      (yysemantic_stack_[(16) - (11)].adouble),(yysemantic_stack_[(16) - (13)].adouble),(yysemantic_stack_[(16) - (15)].adouble));

      Si surf==NULL Alors
        driver.err_print("Func_shortestpath () error ... \n");
      FinSi
      driver.surf_stack.AddSurf(surf);
    }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 11178 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im (driver.im_stack.GetLastImage());
      SurfacePoly* surf;

      surf = Func_shortestpath_image(  im.get(),(yysemantic_stack_[(18) - (5)].adouble),
                                      (yysemantic_stack_[(18) - (7)].adouble), (yysemantic_stack_[(18) - (9)].adouble), (yysemantic_stack_[(18) - (11)].adouble),
                                      (yysemantic_stack_[(18) - (13)].adouble),(yysemantic_stack_[(18) - (15)].adouble),(yysemantic_stack_[(18) - (17)].adouble));

      Si surf==NULL Alors
        driver.err_print("Func_shortestpath_image () error ... \n");
      FinSi
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 11211 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im (driver.im_stack.GetLastImage());
      SurfacePoly* surf;

      surf = Func_path_from_displ(  im.get(),
          (int) round((yysemantic_stack_[(10) - (5)].adouble)),
          (int) round((yysemantic_stack_[(10) - (7)].adouble)),
          (int) round((yysemantic_stack_[(10) - (9)].adouble))
          );

      Si surf==NULL Alors
        driver.err_print("Func_path_from_displ() error ... \n");
      FinSi
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 11247 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im (driver.im_stack.GetLastImage());
      SurfacePoly* surf;

      double start[3] = {(yysemantic_stack_[(20) - (9)].adouble),(yysemantic_stack_[(20) - (11)].adouble),(yysemantic_stack_[(20) - (13)].adouble)};
      double end[3] = {(yysemantic_stack_[(20) - (15)].adouble),(yysemantic_stack_[(20) - (17)].adouble),(yysemantic_stack_[(20) - (19)].adouble)};
      surf = Func_path_from_vectfield(  im,
                                        start,end,
                                        (yysemantic_stack_[(20) - (5)].adouble), (yysemantic_stack_[(20) - (7)].adouble));

      Si surf==NULL Alors
        driver.err_print("Func_path_from_vectfield() error ... \n");
      FinSi
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 11293 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im (driver.im_stack.GetLastImage());
      SurfacePoly* surf;

      double start[3] = {(yysemantic_stack_[(14) - (9)].adouble),(yysemantic_stack_[(14) - (11)].adouble),(yysemantic_stack_[(14) - (13)].adouble)};
      surf = Func_path_from_vectfield(  im,
                                        start,
                                        (yysemantic_stack_[(14) - (5)].adouble), (yysemantic_stack_[(14) - (7)].adouble));

      Si surf==NULL Alors
        driver.err_print("Func_path_from_vectfield() error ... \n");
      FinSi
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 11331 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (1) input polydata
      (5) maximal distance (square distance between extremities)
      (7) maximal angle (square length of the sum of the
                         normalized extremity vectors)
    Description:
      Connecting close lines
    **/
      GET_VARSTACK_VALUE(SurfacePoly, insurf);
      SurfacePoly* surf;
 
      surf = Func_ConnectLines( insurf.get(),
                      (yysemantic_stack_[(8) - (5)].adouble),
                      (yysemantic_stack_[(8) - (7)].adouble));

      Si surf==NULL Alors
        driver.err_print("ConnectLines() error ... \n");
      FinSi
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 11356 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr im (driver.im_stack.GetLastImage());
      SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 11366 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im (driver.im_stack.GetLastImage());
          SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get(), (int) (yysemantic_stack_[(6) - (5)].adouble) );
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 11389 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im (driver.im_stack.GetLastImage());
      float minth = (yysemantic_stack_[(8) - (5)].adouble);
      float maxth = (yysemantic_stack_[(8) - (7)].adouble);
          SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get(),minth,maxth);
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 11401 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im ( driver.im_stack.GetLastImage());
      SurfacePoly* surf;
      float minth = (yysemantic_stack_[(8) - (5)].adouble);
      float maxth = (yysemantic_stack_[(8) - (7)].adouble);

      surf = AMIFluid::Func_vtkCreateFlatMesh(im.get(),minth,maxth);
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 11413 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
      InrImage::ptr highpos (driver.im_stack.GetLastImage());
      InrImage::ptr lowpos  (driver.im_stack.GetLastImage());
      InrImage::ptr input   (driver.im_stack.GetLastImage());
      SurfacePoly* surf;
      float minth = (yysemantic_stack_[(12) - (5)].adouble);
      float maxth = (yysemantic_stack_[(12) - (7)].adouble);

      surf = AMIFluid::Func_CreateVolume(input.get(), minth, maxth, lowpos.get(), highpos.get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 11450 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
      InrImage::ptr colors  (driver.im_stack.GetLastImage());
      InrImage::ptr highpos (driver.im_stack.GetLastImage());
      InrImage::ptr lowpos  (driver.im_stack.GetLastImage());
      InrImage::ptr input  (driver.im_stack.GetLastImage());
      SurfacePoly* surf;
      float minth = (yysemantic_stack_[(16) - (5)].adouble);
      float maxth = (yysemantic_stack_[(16) - (7)].adouble);
      float alpha = (yysemantic_stack_[(16) - (15)].adouble);

      surf = AMIFluid::Func_CreateVolume(input.get(), minth, maxth, 
                                          lowpos.get(), highpos.get(), colors.get(), alpha);
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 11493 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

      InrImage::ptr alt2  (driver.im_stack.GetLastImage());
      InrImage::ptr displ (driver.im_stack.GetLastImage());
      InrImage::ptr alt1  (driver.im_stack.GetLastImage());
      int stepx   = (int) (yysemantic_stack_[(16) - (9)].adouble);
      int stepy   = (int) (yysemantic_stack_[(16) - (11)].adouble);
      float scale = (yysemantic_stack_[(16) - (13)].adouble);
      int   type  = (int) (yysemantic_stack_[(16) - (15)].adouble);
          SurfacePoly* surf;

      surf = AMIFluid::Func_CreateVectors(alt1.get(),displ.get(),alt2.get(), 
                                          stepx, stepy, scale, type);
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 11541 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

      InrImage::ptr alt2  (driver.im_stack.GetLastImage());
      InrImage::ptr displ (driver.im_stack.GetLastImage());
      InrImage::ptr alt1  (driver.im_stack.GetLastImage());
      int stepx   = (int) (yysemantic_stack_[(18) - (9)].adouble);
      int stepy   = (int) (yysemantic_stack_[(18) - (11)].adouble);
      float scale = (yysemantic_stack_[(18) - (13)].adouble);
      int   type   = (int) (yysemantic_stack_[(18) - (15)].adouble);
      int   style  = (int) (yysemantic_stack_[(18) - (17)].adouble);
          SurfacePoly* surf;

      surf = AMIFluid::Func_CreateVectors(alt1.get(),
          displ.get(),
          alt2.get(), stepx, stepy, scale, type,style);
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 11593 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
      InrImage::ptr alt2  (driver.im_stack.GetLastImage());
      InrImage::ptr displ (driver.im_stack.GetLastImage());
      InrImage::ptr alt1  (driver.im_stack.GetLastImage());
      int stepx   = (int) (yysemantic_stack_[(14) - (9)].adouble);
      int stepy   = (int) (yysemantic_stack_[(14) - (11)].adouble);
      float scale = (yysemantic_stack_[(14) - (13)].adouble);
          SurfacePoly* surf;

      surf = AMIFluid::Func_CreateVectors(alt1.get(),displ.get(),alt2.get(), stepx, stepy, scale);
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 11636 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
      InrImage::ptr displ (driver.im_stack.GetLastImage());
      int stepx   = (int) (yysemantic_stack_[(14) - (5)].adouble);
      int stepy   = (int) (yysemantic_stack_[(14) - (7)].adouble);
      int stepz   = (int) (yysemantic_stack_[(14) - (9)].adouble);
      float scale = (yysemantic_stack_[(14) - (11)].adouble);
      int style = (int) (yysemantic_stack_[(14) - (13)].adouble);
      SurfacePoly* surf;

      stepx = macro_max(stepx,1);
      stepy = macro_max(stepy,1);
      stepz = macro_max(stepz,1);
       surf = AMIFluid::Func_CreateVectors(displ.get(), stepx, stepy, stepz,  scale, style);
       Si surf != NULL Alors
         driver.surf_stack.AddSurf(surf);
       FinSi
    }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 11667 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
      InrImage::ptr v3  (driver.im_stack.GetLastImage());
      InrImage::ptr v2  (driver.im_stack.GetLastImage());
      InrImage::ptr v1  (driver.im_stack.GetLastImage());
      int stepx   = (int) (yysemantic_stack_[(16) - (9)].adouble);
      int stepy   = (int) (yysemantic_stack_[(16) - (11)].adouble);
      int stepz   = (int) (yysemantic_stack_[(16) - (13)].adouble);
      int res     = (int) (yysemantic_stack_[(16) - (15)].adouble);

          SurfacePoly* surf;

      surf = Func_CreateEllipsoids(v1.get(),
              v2.get(),
              v3.get(),
              stepx,stepy,stepz,res);
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 11700 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
      InrImage::ptr mask   (driver.im_stack.GetLastImage());
      InrImage::ptr colors (driver.im_stack.GetLastImage());
      InrImage::ptr v3     (driver.im_stack.GetLastImage());
      InrImage::ptr v2     (driver.im_stack.GetLastImage());
      InrImage::ptr v1     (driver.im_stack.GetLastImage());

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
      if (surf != NULL) {
        driver.surf_stack.AddSurf(surf);
      }
    }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 11761 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 662:

/* Line 678 of lalr1.cc  */
#line 11838 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      ImageExtent<float>* extent=new ImageExtent<float>( (float)(yysemantic_stack_[(11) - (1)].adouble),(float)(yysemantic_stack_[(11) - (3)].adouble),(float)(yysemantic_stack_[(11) - (5)].adouble),
                          (float)(yysemantic_stack_[(11) - (7)].adouble),(float)(yysemantic_stack_[(11) - (9)].adouble),(float)(yysemantic_stack_[(11) - (11)].adouble));
      extent->SetMode(1); // relative
      BasicVariable::ptr res(CreateVar_ImageExtent(extent));
      driver.var_stack.AddVar(res);
    }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 11847 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
    {
      ImageExtent<float>* extent=new ImageExtent<float>((float)(yysemantic_stack_[(7) - (1)].adouble),(float)(yysemantic_stack_[(7) - (3)].adouble),(float)(yysemantic_stack_[(7) - (5)].adouble),(float)(yysemantic_stack_[(7) - (7)].adouble));
      extent->SetMode(1); // relative
      BasicVariable::ptr res(CreateVar_ImageExtent(extent));
      driver.var_stack.AddVar(res);
    }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 11855 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 665:

/* Line 678 of lalr1.cc  */
#line 11873 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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

  case 666:

/* Line 678 of lalr1.cc  */
#line 11890 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"
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
#line 12624 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
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
  const short int Parser::yypact_ninf_ = -2040;
  const short int
  Parser::yypact_[] =
  {
      6617, 13274, 12845, 12845, 11528, -2040, -2040, -2040, 11528, 11528,
   11528, -2040, -2040,    15,    54,    64, -2040, -2040, -2040, -2040,
   11970, -2040,   -23,    33, -2040,     1, 11528, 11528, 11528,    72,
   11528, -2040,   101,   106, -2040, -2040, -2040, -2040,   123,   136,
     140,   149,   188,   210,   227, -2040,    40,    82,     2, -2040,
   -2040, -2040, -2040, -2040,   228,     0,   297,     8,    21,   697,
   11528, -2040, -2040, -2040, -2040,   166,   229, 12845, 12845,   300,
     111,   315,   281,   286,   326,   329,   347,   354,   394,   399,
     433,   444,   457,   464,   471,   475,   477,   487,   500,   505,
     506,   508, -2040, -2040, -2040, -2040,   510,   511,   512,   368,
     507,   527,   529,   531,   532,   533,   534,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   547,   549,   550,   553,
     554,   555,   556,   557,   558,   559,   454,   560,   561,   563,
     564,   565,   568,   569,   571,   572,   573,   575,   579,   580,
     581,   588,   589,   590,   591,   607,   608,   609,   610,   611,
     613,   614,   615,   617,   618,   619,   620,   621,   622,   623,
     625,   626,   627,   629,   632,   633,   634,   637,   638,   640,
     641,   642,   643,   645,   646,   647,   648, -2040, -2040, -2040,
   -2040, -2040, -2040, -2040, -2040, -2040, -2040, -2040,   649,   650,
     651,   652,   653, -2040, -2040, 12845, 12845, 12845, 12845, 12845,
   12845, 12845, 12845, 12845, 12845, 12845, 12845, 12845, 12845,   228,
   -2040,   752, -2040, 11528,  8410, 11528,   654,   655,   656,   681,
      14,   228,   683,   687,   688,   689,   691,   570,   692,   694,
     698,   699,   700,   705,   706,   707,   708, -2040, -2040, -2040,
     709,   710,   424,  6158, -2040, -2040, -2040, -2040, -2040, -2040,
   -2040,    49, -2040, -2040, -2040,   606,    37, -2040, -2040, -2040,
     -18,   695, -2040,   396,    83, -2040,    28,   259,   711, -2040,
     716,   616,   721,     4,   -33, -2040, -2040, -2040,     7,   -47,
   -2040,   713, -2040,   760, -2040,   762, 11528, -2040, -2040, -2040,
   -2040,   763, -2040, -2040,   764,    82,   765,   766,   712,   771,
     768,   769,   114, -2040,   770,   713,   695,   695,    98,   776,
   -2040, -2040, -2040, -2040, 11528, 11528, 11528, 11528, -2040, -2040,
   -2040, -2040, -2040, -2040, -2040, -2040, -2040, -2040, -2040, -2040,
   -2040, -2040, -2040, 11528, -2040,   752,   752,   576,   213,    43,
      43, 11528,   460,   -29,   418, -2040,   228, -2040,   -22, 11528,
     522, 11528, -2040, -2040, -2040, -2040, -2040, -2040, -2040, -2040,
   -2040, -2040, -2040,   766, -2040,   780,   771, -2040, -2040, -2040,
   -2040, -2040, -2040, 11528, 11528,   695,   695, 11528, 11528, 11528,
   11528, 11528, 11528, 11528, 11528,     1, 11528, 11528,     1,     1,
       1,     1,     1, 11528,     1,     1,     1,     1,     1,     1,
       1,     1,     1, 11528, 11528,     1,    35,   321,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1, 11528,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1, 11528, 11528, 11528, 11528, 11528, 11528, 11528,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,    43,    43, 11528, 11528,     1,     1,     1,   740,
     778,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1, 11528, 11528, 11528,     1, 11528,     1,     1, 11528,
   11528,     1,     1,     1,     1, 11528, 11528, 11528, 11528,     1,
     695,   695,   695,   695,   695,   695,   695,   695,   695,   695,
     695,   695,   695,   695,  -106, -2040,   779,   712, -2040, -2040,
   -2040,    49, -2040,   612, 11528, 11528,   781, -2040, -2040,   813,
   11528, 11528,     1, 11528, 11528,   393, 11528, 11528, 11528, 11528,
   11528, 11528, 11528,   774,     1,     1,     1, -2040, -2040, -2040,
   -2040, -2040, -2040, -2040, -2040, -2040,    49, -2040,   417, 11528,
     -39, 11528, -2040, -2040, -2040, 13274, 11528, 11528, 11528, 11528,
   11528, 11528, 11528, 11528, 11528, 11528, 11528, 11528, 11528, 11528,
   11528, 11528, 11528, 11528, 11528, 11528, 11528, 11528,   432,   -37,
    9294,  7076,  7526,   757,   -81,   119,    87, 11528, 11528,   684,
     685, 11528,   115,  -119, 13274, -2040,   822,   831,   832,   204,
     827,   835,   836,   838,   839,   840,   841,   842,   843, -2040,
   -2040, -2040, -2040, -2040, -2040, -2040, -2040, -2040, -2040,   844,
     845,   846, -2040,   847,   848,   849,   850, -2040,   851,   852,
     853,   854,   855,   856,   857,   858,   859,   860,   861, -2040,
   -2040,   862,   863,   864,   866, -2040,   867,   868,   869,   871,
   -2040, -2040,   872, -2040,   873, -2040,   874,   875,   876,   877,
     878, -2040, -2040,   879,   880, 11528, 11528, -2040,   881,   882,
   -2040,   883, -2040, -2040, 11528,   884,   886,   887, 11528,   888,
     885,   890, -2040,   892,   893,   891,   912,   914,   913,   916,
     915,   917,   918,   919,   920,   921,   922,   923,   924,   925,
     926,   927,   928,   929,   930,   931,   932,   939,   934,   935,
     936,   937,   945, -2040, -2040,   946, -2040, -2040,   947,   940,
     942,   943,   944,   948,   949,   951,   952,   953,   955,   962,
     963,   964,   959,   966,   961,   965,   967,   978,   981,   201,
     982,   968,   983,   969,    96,   950,   991,   993,   995,  1004,
    1005,  1006,  1013,  1014,  1015,  1016,  1018,   970,  1019,  1020,
    1021,  1023,  1025,  1026,  1027,   972,  1034,  1029,  1030,  1031,
    1032,  1033,  1035,  1036,  1039,  1045,  1052,  1054,  1055,  1056,
    1057,  1058,  1059,  1040,  1076,  1077,  1072,  1073,   144,  1081,
    1082,  1078,  1083,  1085,  1086,  1087,  1088,  1089,  1091,  1092,
    1099,  1093, 11528, 11528, -2040, -2040,   -15, -2040,  1111,  1112,
    1113,  1108,  1115,   954,  1117,   455,    49,   223,  1125,  1126,
    1127,  1130,  1118,   230,   233,  1131,  1132,  1119,  1140,  1141,
    1136,  1137,  1138,  1139, -2040, -2040,   160,  1146,  1150, -2040,
    1151,  1152, -2040, -2040, 11528, -2040,  1153,  1154,  1155,  1156,
    1157,  1158,  1159,  1161,  1162, -2040, -2040, -2040, -2040, -2040,
   -2040, -2040, -2040, -2040, -2040, -2040, -2040, -2040, -2040,  1090,
   -2040, -2040, -2040,   396,   396, -2040, -2040, -2040, -2040,    28,
      28,   259, -2040,   716,   616,    13,   721, -2040, -2040, -2040,
   -2040, -2040, -2040, -2040, -2040, 11528,  1163,  1164, -2040,  1165,
   11528, -2040,  1166, -2040,  1169,  1172,  1173,  1175,  1178,  1179,
    1180,  1181,  1183,  1184,  1185,  1189,  1190,  1192,  1193,  1194,
    1195,  1203,  1204,  1205, -2040,  1209, -2040,  1216, -2040, -2040,
    1227,  1229,  1230,  1232,  1235, -2040, -2040,  1240,  1242,  1243,
    1244,  1245,  1246,  1247,  1248,  1249,  1250,  1251,  1252,  1253,
    1254,  1255,  1256,  1257, 12412,  1258,  1259,  1260,  1261,  1262,
    1263,  1265, -2040,  1264, -2040,  8852,  9744,  1268,   763,  1269,
     765, -2040, 10194,  1274,  1276,  1277,  1278,  1272, -2040,  1275,
   -2040, -2040,   752,   764,   235, -2040,   770, -2040,  1280,  1116,
    1266,   183, -2040, 11528, -2040, -2040, 11528, 11528, -2040, -2040,
   11528, 11528, 11528, 11528, 11528, 11528,     1, 11528, 11528,    -5,
     907,   833, 11528, 11528, 11528, 11528, 11528, 11528, 11528, 11528,
   11528,   828, 11528,  1202, 11528, 11528,   -37, 11528, 11528, 11528,
   11528, 11528,    43,   -25,  1226,  1047, 11528, 11528, 11528, 11528,
   11528, -2040, -2040, -2040, -2040, 11528,   225, 11528, -2040,   816,
   11528,   817,  1281, -2040,  1220, -2040, -2040, 11528,  1285, -2040,
   -2040,  1287, -2040,  1288,    18, 11528, 11528, -2040, 11528, 11528,
   11528, 11528, 11528,     1, 11528, 11528, 11528, 11528, 11528, 11528,
   -2040, 11528, 11528, 11528,     1,     1,     1, -2040, 11528, 11528,
   11528, 11528, 11528, 11528, 11528, 11528,     1, 11528, -2040, -2040,
   -2040,     1, -2040,     1,     1,     1,     1,     1, -2040,     1,
       1, -2040, 11528, -2040, 11528,  1289, 11528, 11528, 11528, 11528,
   11528, 11528, 11528, 11528, 11528, 11528, 11528, -2040, 11528, 11528,
   11528, 11528, 11528,     1, 11528, -2040, -2040,     1,     1,     1,
       1,     1, 11528, 11528, 11528, 11528, 11528, 11528, 11528, 11528,
   11528, 11528, 11528, -2040, -2040, -2040, 11528, 11528, -2040, -2040,
   -2040, 11528, -2040, -2040, -2040, -2040, -2040, -2040, 11528, 11528,
   11528, -2040,   905,  1284, -2040, -2040, -2040, -2040, -2040, -2040,
   -2040, 11528, -2040,  -230,  -230,  1231, -2040, -2040, 11528, 11528,
       1, 11528, 11528,     1, -2040, 11528, -2040, 11528, 11528, 11528,
   -2040, -2040, -2040, 11528, 11528,     1,     1, 11528, 11528, 11528,
   -2040, 11528, 11528,     1, -2040,     1,     1, 11528, 11528, 11528,
   11528, 11528, 11528, 11528, -2040, 11528, -2040, 11528, 11528, 11528,
   -2040, 11528, 11528, 11528, 11528, 11528, 11528, 11528, 11528, 11528,
   11528, 11528, 11528, 11528, 11528, 11528,     1,     1,  1292,  1293,
    1296, 11528, 11528, 11528, 11528, 11528,     1, 11528, 11528, 11528,
   11528,     1,    43,    43,    43, 11528, 11528, 11528, 11528, 11528,
       1,    43,     1,    43,    43, 11528, 10644, -2040, 11528, 11528,
   11528, 11528, 11528, 11528,   729, 11528, -2040, -2040, 11528, 11528,
    -221, 11528,  1233, 11528, 11528, 11528, 11528,  -136, -2040, -2040,
    7968, 11528, -2040, -2040,  1291,  1294,  1299,  1295,   165,  1297,
    1298,  1300,  1302,  1301,  1305,  1303,  1308,  1313,  1314,  1309,
    1310,  1311,  1312,  1317,  1320,  1324,  1319,  1321,  1322,  1323,
    1326,  1325,  1330,  1327,   237,  1332,  1334,  1329,  1331,  1333,
    1335,  1336,  1337,   240,  1338,  1339,  1340,  1341,  1343,  1344,
    1345,  1349,  1350,  1352,  1347,   -37,  1353, 11528, -2040,  1354,
    1356, 11528,     1,     1,   242,  1351,  1355,  1358,  1359,  1360,
    1362,  1357,  1364,   244,  1361,  1363,  1365,  1366,  1367,  1368,
    1369,  1370,  1371,  1372,  1373,  1374,  1375,  1376,  1377,  1378,
    1379,  1380,  1381,  1382,  1389,  1390,  1385,  1386,  1387,  1388,
    1391,  1392,  1395,  1396,  1393,  1400, 11528,  1401,  1402,  1404,
    1399,  1403,  1405,  1406,   245,  1407,  1408,  1410,  1409,  1416,
    1417,  1418,  1419,  1414,  1421,  1422,  1420,  1423,  1424,  1425,
    1426,  1427,  1428,  1434,  1435,  1436,  1437,  1438,  1439,   247,
    1440,  1441,  1442,  1443,  1444,  1445,  1446, 11528, 11528,    49,
      49,  1447,  1397,  1411,  1412,  1413,  1415,  1429,   249,   252,
   -2040,  1449,  1448,  1453,  1455,  1456,  1457,  1461,  1464,  1459,
    1466,  1462,  1467,  1463,  1465,   120,  1469,  1470,  1472,  1471,
     254,  1473,  1476,  1474,   219,  1475,   222,  1478,   256,  1477,
    1479,   263, -2040,  1482,  1484,  1486,  1487,  1488,   268,  1489,
    1491,  1490,   270,  1492,  1493,  1495,  1496,  1494,  1497,  1498,
    1503,  1504,  1505, -2040, -2040, -2040,  1506,  1507,  1508,  1509,
    1510,  1511,  1512,  1513,  1514,  1517,  1518,   271,  1515,  1516,
    1519,  1520,  1521,   283,  1522,  1523,   290,  1524,  1525,  1526,
    1527, -2040,   292,  1528,  1529,  1530,  1531,  1532,  1480,  1537,
    1538,  1541, -2040,  1542,  1543,  1551,  1553,  1549, -2040,   752,
   -2040, -2040,  1556, 11528, 11528, -2040,     1, 11528, 11528, 11528,
   11528, -2040, 11528, -2040, 11528, -2040, -2040, -2040,     1,     1,
   11528, 11528, 11528, -2040, -2040, 11528, 11528, 11528, 11528, -2040,
   11528, -2040, 11528, -2040, 11528, -2040, -2040, 11528, 11528, 11528,
   11528, -2040,  1095, -2040, 11528, -2040,     1, 11528, 11528, -2040,
   -2040, 11528, -2040, -2040, -2040,  1328, -2040, -2040, -2040, -2040,
   -2040,  1557,  1561,   294, -2040,   -40,    19, 11528, -2040, -2040,
   -2040, -2040, 11528, -2040, -2040,     1, 11528, 11528, 11528, 11528,
   11528, 11528, 11528, 11528, 11528, 11528, 11528, 11528, 11528, 11528,
   11528, 11528, 11528, 11528, 11528, 11528, -2040, -2040, 11528,     1,
       1,     1,     1,     1, -2040, -2040, 11528, -2040,  1562, -2040,
   -2040, -2040, 11528, 11528, 11528, 11528, -2040, 11528, 11528, 11528,
   -2040, 11528, -2040, -2040, -2040, -2040, 11528, -2040, -2040, 11528,
   11528,     1,     1, 11528, 11528, -2040, -2040, -2040, -2040, -2040,
   -2040, -2040, -2040, 11528, 11528, 11528, 11528, -2040, 11528, 11528,
   11528,   980, -2040, -2040, -2040, 11528, -2040, -2040, -2040, -2040,
   -2040, -2040, -2040,  -218, -2040,    49, -2040, 11528, 11528, -2040,
   11528, 11528, -2040, -2040, 11528, -2040, 11528, -2040,     1, 11528,
   -2040, 11528, 11528, 11528, -2040, -2040, 11528, -2040, 11528, -2040,
   -2040, 11528, -2040, 11528, -2040, -2040, -2040, 11528, 11528, 11528,
   -2040, 11528, -2040, -2040, -2040, -2040, -2040, -2040, 11528, -2040,
   -2040, 11528, -2040, 11528, -2040, 11528, 11528, 11528, -2040, -2040,
   -2040, -2040, -2040, -2040, -2040, -2040, -2040, 11528, 11528, -2040,
   -2040, 11528, -2040, -2040, -2040, -2040, 11528, 11528, 11528, 11528,
   11528, 11528, -2040, 11528, 11528, 11528, -2040, 11528, 11528, 11528,
   11528, 11528, -2040, 11528, 11528, 11528, 11528, 11528, 11528, 11528,
   -2040, -2040, -2040, -2040,  1342,  1563,  1565,  1398, -2040, -2040,
    1567,  1568,   226,  1573,  1580,  1575,  1583,  1578,  1586,  1581,
    1588,  1590,  1591,  1592,  1587,  1589,  1594,  1593,  1595,  1596,
    1597,  1598,  1602,  1603,  1605,  1606,  1600,  1604,  1613,  1629,
    1631,  1638, -2040, -2040, -2040, 11528,  1639,  1635,   295,  1636,
    1637,  1640,  1641,   316,   317,   318,   336,  1642,  1643,  1648,
     337,   173,  1652,  1654,  1655,  1656,   338,  1657,  1658,  1659,
    1660,  1661,  1663,  1645,  1664,  1667,  1668,  1669,  1670,  1671,
    1672, -2040,  1647,  1679,   339,   341,  1674,  1685,  1683,  1684,
    1686,  1691,  1694,  1689,  1690,  1692,  1693,  1696,  1697,  1698,
    1701,  1705,  1700,  1707,  1709, 11528,    49,  1710,    49,  1450,
    1468,  1552,  1673,  1677,  1678,    49, -2040,  1718,  1719,  1727,
    1722,  1730,  1726,  1728,  1732,   121,  1733,  1433,  1740,  1735,
    1736,  1737,  1738,  1739,  1741,  1742,  1750,  1746,  1751,  1752,
    1753,  1754,  1755,  1756,  1757,  1758,  1767,  1762,  1764,  1765,
    1766,  1773,   348,  1780,  1784,  1790,  1794,  1796,  1792,   349,
    1793,  1795,  1797,  1798,  1799,  1800,  1801, 11528, 11528,  1802,
   -2040, 11528, -2040, 11528, -2040, 11528, -2040, 11528, -2040, 11528,
   -2040, -2040, -2040, -2040, 11528, 11528, -2040, 11528, 11528, 11528,
   11528, -2040, 11528, 11528, 11528, 11528, -2040, -2040, -2040, 11528,
   11528, -2040,  1808, -2040,   986, -2040,   -40,  1451, 11528, 11528,
   -2040, -2040, 11528, -2040, 11528, -2040, 11528, -2040, 11528, 11528,
   11528, 11528, -2040, 11528, 11528, 11528, 11528, 11528, 11528, -2040,
   11086, 11086, 11086, 11528, 11528, 11528, 11528, -2040, 11528, 11528,
   11528, 11528, 11528,     1, 11528, -2040, -2040, -2040, 11528, -2040,
   11528, 11528, -2040, 11528, 11528, 11528, -2040, -2040, 11528,     1,
       1, 11528, 11528, -2040, 11528, 11528, 11528, -2040, 11528, 11528,
   -2040, -2040, 11528, -2040, -2040, -2040, -2040, -2040, -2040, -2040,
   -2040, 11528, 11528, -2040, 11528, -2040, 11528,     1, 11528, -2040,
   11528, 11528, -2040, 11528, -2040, 11528, 11528, 11528, 11528, 11528,
   11528, 11528, -2040, 11528, 11528, 11528, 11528, 11528, 11528, 11528,
   11528, 11528, -2040, 11528, 11528, 11528, 11528, -2040, -2040,     1,
   -2040, -2040, -2040, -2040, -2040, 11528, -2040, 11528, 11528, 11528,
   11528, 11528, 11528, 11528, 11528, -2040, -2040, -2040,   350,  1809,
     374,  1804,  1811,  1806,  1807,  1814,  1810,  1812,  1815,  1813,
    1816,  1817,  1820,  1818,  1821, -2040,  1825,   375,  1822,  1823,
     376,   385,  1824,  1826,  1827,  1828,  1831,  1829,  1830,  1832,
    1833,  1834,  1835,  1836,   763,   197,   387,  1837,   423,  1844,
    1501,  1845,  1840,  1841,  1842,  1843,  1846,  1847,  1848,  1849,
    1850,   403,  1851,  1858,   405,  1859,  1854,  1855,  1862,  1857,
     406,  1860,  1864,   407,  1865,  1867,  1868,  1869,  1870,    49,
    1866,  1871,  1872,  1873,  1874,  1875,  1876,  1879,  1883,  1878,
    1880,  1885,  1887,  1888,  1889,  1890,  1891,  1892,  1893,  1894,
    1895,  1896,  1897,  1898,  1899,  1900,  1901,  1902,  1903,  1904,
    1905,  1911,  1912,  1907,  1914,  1909,  1910,  1913,  1917,  1918,
   -2040, 11528, -2040, -2040, 11528, 11528, -2040, 11528, 11528, -2040,
   11528, 11528, -2040, 11528, 11528, 11528, -2040, 11528, -2040, -2040,
   -2040,   -40, 11528, 11528, -2040, 11528, -2040, 11528, 11528, 11528,
   11528, 11528, -2040, 11528, 11528, 11528, 11528, 11528, 11528,  1502,
   11086, 11528,    17, -2040, 11086, -2040, -2040, 11086, 11086, 11528,
   11528, 11528,     1,     1,     1,     1, -2040, 11528, 11528, -2040,
   -2040, 11528, -2040, 11528, 11528, -2040, 11528, -2040, 11528,     1,
   -2040, -2040, 11528, -2040, -2040, -2040, -2040, -2040, -2040, 11528,
   11528, 11528, -2040, 11528,     1, 11528, -2040, -2040, 11528, 11528,
   -2040, -2040, -2040, -2040, -2040, -2040, -2040, -2040, -2040, -2040,
   -2040, -2040, -2040, -2040, 11528, 11528, 11528, 11528, 11528, -2040,
   -2040, -2040, 11528, -2040, 11528, 11528, 11528, -2040, -2040,  1920,
    1915,  1922,  1923,  1919,  1921,  1924,  1926,  1928,  1929,  1925,
    1932,  1933,  1930,  1934,  1935,  1937,  1938,  1939,  1936,   408,
    1940,  1941,  1943,  1944,  1942,  1945,  1946,  1947, -2040,  1949,
    1950,  1952,  1948,  1955,  1956,  1957,  1958,  1953,  1954,  1961,
    1959,  1962,  1963,  1960,  1964,  1967,  1966,  1968,  1970,  1974,
    1972,  1973,  1975,  1978,  1535,  1980,  1989,  1988,  1990,  1995,
    1993,  1994,  1996,  1997,  1999, -2040, 11528, -2040, -2040, 11528,
   11528, 11528, -2040, -2040, -2040, 11528, -2040, -2040, 11528, -2040,
   -2040, -2040, -2040, -2040, 11528, -2040, 11528, -2040, 11528, -2040,
   -2040, 11528, 11528, -2040, 11528, -2040, -2040, -2040, 11086, -2040,
   -2040, -2040, -2040, 11528, 11528, -2040, 11528, -2040, -2040, 11528,
   11528, -2040,     1, -2040, 11528, -2040, 11528, 11528,     1, 11528,
   11528, -2040, -2040, 11528, 11528, -2040, 11528, 11528, 11528, 11528,
   11528,  2001,  2002,  2003,  2005,  2007,  2009,  2020,  2027,  2030,
    2035,  1748,  1819,  2043,  2038,  2039,  2046,  2041,  2042,  2044,
    2045,  2048,  2049,  2051,  2052,  2061,  2059,  2062,  2063,   427,
    2065,  2066,  2067, -2040, 11528, 11528, 11528, 11528, 11528, -2040,
   -2040, -2040, 11528, 11528, 11528, -2040, 11528, 11528, -2040, 11528,
   11528,     1, 11528, 11528, 11528,     1, 11528,   820, 11528, 11528,
   11528, -2040, 11528, 11528, 11528, 11528,  2074,  2075,  2070,  2077,
    2078,  2081, -2040,  2079,  2083,  2084,   428,  2086,   430,  2094,
    2104,  2109,  2110,  2111, 11528,  2112,  2113,   439,  2114,   440,
    2087,  2115, -2040, -2040, 11528, -2040, -2040, -2040, 11528, -2040,
   11528, -2040, 11528, 11528, -2040, 11528, 11528, 11528, 11528, 11528,
   11528, -2040, 11528, 11528, -2040, 11528, 11528, -2040, 11528, -2040,
   11528,  2116,  1863,  2117,  2124,  2128,  2130,  2133,  2129,  2131,
    2132,  2134,  2136,  2135,  2137,  2139,   441,   442, 11528, 11528,
   11528, -2040, -2040, -2040, -2040, 11528, 11528, 11528,     1, -2040,
   11528, 11528, -2040, -2040, 11528, -2040, 11528,  2138, -2040,  2142,
    2140,  2145,  2141,  2143,  2148,  2144,  2151,  2146, 11528, -2040,
   11528, -2040, 11528,     1, -2040, 11528, -2040, 11528,  2147,  2149,
    2150,  2152,  2154,  2157, 11528, 11528, 11528, 11528, -2040, -2040,
    2153,  2155,  2156,  2160, 11528, 11528, 11528, -2040,  2158,  2159,
    2161, 11528, 11528, 11528,  2163,  2162,  2164, -2040, 11528, 11528,
    2166,  2169, -2040, -2040
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  Parser::yydefact_[] =
  {
         2,     0,     0,     0,     0,    21,    71,    72,     0,     0,
       0,    75,    76,     0,     0,     0,   294,   300,    41,    20,
       0,   382,     0,    95,    81,     0,     0,     0,     0,     0,
       0,    94,     0,     0,   288,   299,   633,   377,   303,   515,
     516,   512,   643,   514,   298,   594,   645,   592,   646,   636,
     637,   639,   638,   640,   647,   648,   634,   644,   649,     0,
       0,    43,    46,    44,    45,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   254,   255,   290,   256,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,     0,     0,
       0,     0,     0,   301,   302,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     296,     0,    42,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   260,   261,   262,
       0,     0,     0,     0,     4,     8,    10,    14,    16,    18,
      12,     0,   513,   517,   518,     0,   386,   511,   519,   520,
     525,   532,   551,   555,   558,   559,   564,   567,   569,   570,
     572,   574,   576,   578,   580,   586,    40,   521,   635,     0,
     650,   642,   651,    39,   661,     0,     0,   303,   515,   516,
     512,     0,   514,   298,     0,   592,     0,     0,     0,     0,
       0,     0,   386,   526,     0,     0,   534,   533,     0,     0,
      73,   362,    74,    77,     0,     0,     0,     0,   379,   364,
      88,    82,    84,   101,    98,    99,   100,    97,    96,    83,
     104,   105,   106,     0,    93,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    35,     0,   140,     0,     0,
       0,     0,   654,   652,   653,   657,   643,   655,   656,   645,
     658,   646,   647,   648,   634,   644,   649,   659,   635,   642,
     660,    90,    91,     0,     0,   535,   536,     0,     0,     0,
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
     537,   538,   543,   544,   545,   546,   547,   549,   548,   539,
     540,   541,   542,   550,     0,    25,     0,   644,   296,   296,
      37,     0,    38,     0,     0,     0,     0,    31,    29,   296,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     3,     5,
       9,    11,    15,    17,    19,    13,     0,     6,     0,     0,
       0,     0,   527,   528,   530,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   268,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   524,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   347,
     348,   345,   346,   343,   344,   349,   350,   351,   461,     0,
       0,     0,   111,     0,     0,     0,     0,   118,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   459,
     460,     0,     0,     0,     0,   216,     0,     0,     0,     0,
     221,   222,     0,   205,     0,   213,     0,     0,     0,     0,
       0,   202,   203,     0,     0,     0,     0,   108,     0,     0,
      70,     0,   641,   258,     0,     0,     0,     0,     0,     0,
       0,     0,   363,     0,   363,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   150,   151,     0,   152,   153,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   386,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   386,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   297,    26,     0,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,   357,     0,   362,     0,   291,
       0,     0,   138,   139,     0,   155,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   376,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,    85,     0,
     552,   553,   554,   556,   557,   561,   560,   562,   563,   565,
     566,   568,   571,   573,   575,     0,   577,   582,   583,   584,
     585,   581,   141,   323,   324,     0,     0,     0,   361,     0,
       0,   189,     0,   184,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   183,     0,   175,     0,   185,   186,
       0,     0,     0,     0,     0,   194,   196,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   607,     0,     0,     0,     0,     0,
       0,   610,    62,     0,    57,     0,     0,     0,   643,   645,
     646,   587,   607,     0,   366,   369,     0,    51,    59,   610,
      61,    53,     0,   645,     0,   273,   635,   269,     0,     0,
       0,     0,   529,     0,    79,    80,     0,     0,   292,   293,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   107,   102,   362,   103,     0,     0,     0,   259,   595,
       0,   378,     0,    47,     0,   330,   332,     0,     0,   333,
     334,     0,   335,     0,     0,     0,     0,   419,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     420,     0,     0,     0,     0,     0,     0,   442,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   404,   405,
     406,     0,   408,     0,     0,     0,     0,     0,   415,     0,
       0,   326,     0,   331,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   422,     0,     0,
       0,     0,     0,     0,     0,   380,   381,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   486,   248,   249,     0,     0,   328,   400,
     402,     0,   593,   455,   456,   457,   458,   342,     0,     0,
       0,   251,     0,   296,   266,   295,   296,    27,   354,   355,
     356,     0,   253,   275,   275,     0,    33,   490,     0,     0,
       0,     0,     0,     0,   502,     0,   504,     0,     0,     0,
     506,   507,   197,     0,     0,     0,     0,     0,     0,     0,
     487,     0,     0,     0,   154,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   531,     0,   158,     0,     0,     0,
     159,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   606,     0,     0,
       0,     0,     0,     0,     0,     0,    50,    49,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   271,   523,
       0,     0,   595,   378,     0,     0,     0,     0,   386,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,     0,
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
     296,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   386,     0,   386,     0,     0,     0,
       0,     0,   579,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   496,   498,   499,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   605,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   588,     0,     0,     0,     0,     0,    52,     0,
     274,   270,     0,     0,     0,   289,     0,     0,     0,     0,
       0,   134,     0,   137,     0,   110,   113,   112,     0,     0,
       0,     0,     0,   121,   122,     0,     0,     0,     0,   127,
       0,   136,     0,   206,     0,   201,   208,     0,     0,     0,
       0,   204,     0,   214,     0,   209,     0,     0,     0,   212,
     352,     0,   358,   359,   360,     0,    60,    63,    58,    48,
     522,     0,     0,     0,   392,     0,     0,     0,   418,   421,
     423,   424,     0,   425,   246,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   325,   403,     0,     0,
       0,     0,     0,     0,   416,   417,     0,   341,     0,   387,
     388,   389,     0,     0,     0,     0,   229,     0,     0,     0,
     235,     0,   462,   463,   464,   465,     0,   510,   471,     0,
       0,     0,     0,     0,     0,   476,   477,   478,   479,   480,
     481,   482,   483,     0,     0,     0,     0,   591,     0,     0,
       0,   296,   267,    24,    28,     0,   279,   280,   281,   276,
     278,   277,   296,     0,   296,     0,   491,     0,     0,   492,
       0,     0,   501,   503,     0,   505,     0,   257,     0,     0,
     304,     0,     0,     0,   310,   149,     0,   148,     0,   156,
     157,     0,   242,     0,   244,   245,   144,     0,     0,     0,
     142,     0,   176,   181,   497,   187,   188,   191,     0,   190,
     160,     0,   172,     0,   168,     0,     0,     0,   164,   165,
     166,   167,   173,   500,   182,   174,   177,     0,     0,   170,
     180,     0,   195,   199,   611,   612,     0,     0,     0,     0,
       0,     0,   608,     0,     0,     0,   600,     0,     0,     0,
       0,     0,   621,     0,     0,     0,     0,     0,     0,     0,
      55,    56,   590,    54,     0,    66,    64,     0,   272,    89,
       0,     0,   386,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   336,   337,   338,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   386,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   340,     0,     0,     0,     0,     0,   362,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    34,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      78,     0,   385,     0,   129,     0,   132,     0,   135,     0,
     116,   114,   117,   119,     0,     0,   124,     0,     0,     0,
       0,   207,     0,     0,     0,     0,   215,   210,   223,     0,
       0,    69,     0,   393,     0,   394,     0,     0,     0,     0,
     247,   428,     0,   431,     0,   433,     0,   435,     0,     0,
       0,     0,   466,     0,     0,     0,     0,     0,     0,   443,
       0,     0,     0,     0,     0,     0,     0,   453,     0,     0,
       0,     0,     0,     0,     0,   390,   391,   224,     0,   226,
       0,     0,   230,     0,     0,     0,   509,   472,     0,     0,
       0,     0,     0,   484,     0,     0,     0,   250,     0,     0,
     296,    22,     0,    32,   285,   286,   287,   283,   284,   282,
      30,     0,     0,   495,     0,   265,     0,     0,     0,   305,
       0,     0,   309,     0,    86,     0,     0,     0,     0,     0,
       0,     0,   192,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   614,     0,     0,     0,     0,   609,   596,     0,
     597,   601,   602,   603,   604,     0,   622,     0,     0,     0,
       0,     0,     0,     0,     0,    67,    65,    68,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   339,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   666,     0,   386,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     383,     0,   128,   130,     0,     0,   109,     0,     0,   126,
       0,     0,   200,     0,     0,     0,   220,     0,   353,   395,
     396,     0,     0,     0,   427,     0,   430,     0,     0,     0,
       0,     0,   401,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   444,     0,   446,   448,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   413,     0,     0,   225,
     227,     0,   231,     0,     0,   240,     0,   239,     0,     0,
     473,   474,     0,   485,   327,   329,   488,   489,    23,     0,
       0,     0,   399,     0,     0,     0,   307,   308,     0,     0,
     241,   243,   145,   146,   306,   143,   169,   171,   161,   162,
     163,   178,   179,   193,     0,     0,     0,     0,     0,   598,
     599,   623,     0,   624,     0,     0,     0,   620,   589,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   665,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   384,     0,   133,   120,     0,
       0,     0,   217,   218,   219,     0,   397,   398,     0,   429,
     432,   434,   436,   439,     0,   468,     0,   470,     0,   437,
     440,     0,     0,   445,     0,   447,   449,   450,     0,   452,
     407,   409,   410,     0,     0,   414,     0,   228,   234,     0,
       0,   238,     0,   475,     0,   493,     0,     0,     0,     0,
       0,   147,   613,     0,     0,   617,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   131,     0,     0,     0,     0,     0,   438,
     469,   467,     0,     0,     0,   451,     0,     0,   454,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   625,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   664,   663,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   123,   125,     0,   211,   426,   441,     0,   411,
       0,   232,     0,     0,   237,     0,     0,     0,     0,     0,
       0,    87,     0,     0,   619,     0,     0,   629,     0,   630,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   233,   252,   236,   508,     0,     0,     0,     0,   615,
       0,     0,   626,   627,     0,   631,     0,     0,   662,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   412,
       0,   198,     0,     0,   616,     0,   628,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   618,   632,
       0,     0,     0,     0,     0,     0,     0,   264,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   115,     0,     0,
       0,     0,   494,   263
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
     -2040, -2040, -2040,  -211,  1198,  1215,  1571, -2040, -2040,  1621,
    1622,  1646,  1675, -2040, -2040,  -244, -2040,  -470, -2040, -2040,
   -2040, -2040,    -8,  3502,  3066,    23,  3389, -2040, -2040, -2040,
       6,   411,   -46,   -62, -2040,   -68,   -49,   815, -2040,   812,
    1041,   889,   865,  1384,   309,  -101,  2359,   389, -2040,    62,
    -575,   -12, -2040,     9,   956,     5, -2040,   -55, -2039
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,   242,   243,   244,   245,   246,   247,   814,   813,   248,
     249,   250,   251,  1173,   984,  1458,   252,   505,   506,  1175,
     253,   254,  2200,   681,   318,   255,   302,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   311,   978,   277,   304,
     962,   279,   280,   305,   282,   370,   284,   285,  2197
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int Parser::yytable_ninf_ = -661;
  const short int
  Parser::yytable_[] =
  {
       310,   312,   313,   510,   371,   283,   980,   303,     5,   281,
     802,   328,  2199,  2201,   838,   839,   967,   665,   666,   346,
      37,   343,    19,   349,   673,   571,   578,   308,   314,   893,
     894,    45,   539,   561,   562,  1225,   351,    37,   805,   806,
     547,   299,   345,   298,  1342,    45,   893,   894,   580,   816,
     549,   639,   640,   840,   971,    37,   550,   298,   299,   338,
    1317,    37,   278,   573,   574,   575,   576,   315,   369,   581,
    1548,   839,     5,    36,  1364,  1868,   299,   316,    37,    37,
     898,   899,   299,   577,   322,   333,    19,   552,   553,   323,
     517,   841,    36,   559,   560,   341,   554,   898,   899,   299,
     299,   342,   579,   350,  1552,   324,   325,   326,   327,   591,
    2418,    45,   594,   572,   335,   592,  1114,   548,   344,   336,
     842,   368,   572,   298,   378,   843,   379,   591,   844,   845,
     846,   847,   551,   592,  1740,  2109,   339,   340,   563,   564,
    1741,  2110,  -654,  1742,  2111,   674,   609,   610,   611,   612,
     613,   614,   615,   616,   617,  -652,   508,   591,  1158,  -653,
     848,   849,   850,   592,   347,   939,   940,   941,  -657,   839,
     919,   920,   921,   922,   942,   943,   944,   945,   591,   373,
    1207,   946,  1208,  1209,   592,  1567,   591,   919,   920,   921,
     922,   618,   592,  2044,   712,   713,   714,   504,  1452,  1453,
    1454,  1455,  1456,  1207,  1457,   509,  1209,   337,   518,   519,
    1929,  1930,  1931,  1932,  1933,  1108,  1934,  2310,   594,  2311,
     369,  1109,   947,   548,   996,   948,   949,   950,   951,  -655,
     952,   953,   591,  1752,   954,   591,  1754,  1187,   592,   591,
    1992,   592,   374,  1188,  1194,   592,  -656,  1196,   283,  1299,
    1195,  1593,   281,  1197,  1603,  1300,  1624,  1594,  1634,  1676,
    1604,  1702,  1625,  1722,  1635,  1677,  1724,  1703,  1747,  1723,
    1756,  2416,  1723,   368,  1748,  2419,  1757,  1760,  2420,  2421,
     601,   602,  1767,  1761,  1772,  1795,  1352,    36,  1768,  1353,
    1773,  1796,   851,   852,   381,   803,   382,  1802,   853,   383,
     807,   384,   973,  1803,  1806,   278,  1812,   597,  1864,  2025,
    1807,   854,  1813,   377,  1865,  2026,   348,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   380,   855,
    2031,  2033,  2035,   663,   672,   834,  2032,  2034,  2036,   385,
     599,   675,   386,   677,   369,   369,   667,   668,   669,   670,
    2037,  2042,  2049,  2067,   853,  2069,  2038,  2043,  2050,  2068,
     387,  2070,  2138,  2146,  2270,   679,   680,   388,  2139,  2147,
    2271,   565,   566,   856,   857,   858,   859,   860,   861,   862,
     863,   864,   865,   866,   867,   855,   320,   406,  2273,  2290,
    2294,   639,   640,  1176,  2274,  2291,  2295,   368,   368,  2296,
     591,   661,   662,   556,   557,  2297,  2312,   389,   558,   955,
     956,   957,   390,   306,   307,   958,   959,  2326,   960,  2330,
    2337,  2341,  2475,  2327,   537,  2331,  2338,  2342,  2476,   856,
     857,   858,   859,   860,   861,   862,   863,   864,   865,   866,
     867,  2581,  2621,  2314,  2624,  2311,   391,  2582,  2622,  2533,
    2625,  1335,   853,  2634,  2637,  2673,  2675,   392,   809,  2635,
    2638,  2674,  2676,   668,   669,   784,   785,   433,   787,   434,
     393,   791,   887,   888,   889,   890,   891,   394,   375,   376,
     715,   716,   717,   855,   395,   639,   640,   641,   396,   642,
     397,   643,   644,   875,   876,   877,   878,   873,   874,   645,
     398,   808,   646,   647,   648,   649,   650,   651,   652,   653,
     870,   871,   872,   399,   763,   764,   879,   880,   400,   401,
     825,   402,   369,   403,   404,   405,   407,   856,   857,   858,
     859,   860,   861,   862,   863,   864,   865,   866,   867,   654,
     408,   836,   409,   655,   410,   411,   412,   413,   656,   657,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   658,
     423,   869,   424,   425,   659,   660,   426,   427,   428,   429,
     430,   431,   432,   435,   436,   368,   437,   438,   439,   989,
     990,   440,   441,   991,   442,   443,   444,   987,   445,   525,
     281,   281,   446,   447,   448,  1177,   892,   893,   894,   895,
     992,   449,   450,   451,   452,  1186,   490,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     453,   454,   455,   456,   457,   548,   458,   459,   460,   896,
     461,   462,   463,   464,   465,   466,   467,   897,   468,   469,
     470,   961,   471,   979,   986,   472,   473,   474,   898,   899,
     475,   476,   900,   477,   478,   479,   480,  1041,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   513,   514,   515,
    1052,    36,    37,   352,   353,   354,   355,   356,   357,   358,
      45,   359,   360,   361,    49,    50,    51,    52,    53,   362,
     363,   364,   507,   366,   516,   901,   520,   902,   903,   904,
     521,   522,   523,  1449,   524,   526,  1450,   527,   905,   906,
     555,   528,   529,   530,   907,   908,   909,   910,   531,   532,
     533,   534,   535,   536,   569,   570,   582,   587,   567,   911,
     912,   913,   914,   915,   568,   916,   917,   918,   919,   920,
     921,   922,   923,   924,   925,   926,   927,   928,   929,   930,
     931,   932,   933,   934,   935,   936,   937,    37,   352,   353,
     354,   355,   356,   357,   358,    45,   359,   360,   361,    49,
      50,    51,    52,    53,   362,   363,   364,   365,   366,  -660,
    1616,   583,   584,   585,   586,   346,   588,   589,   590,   593,
     595,   664,   671,   676,  1172,   678,   770,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,    37,   352,   353,   354,   355,   356,   357,   358,
      45,   359,   360,   361,    49,    50,    51,    52,    53,   362,
     363,   364,   507,   366,   771,   815,   804,   812,   822,   830,
     835,   988,   993,   712,   715,   994,   995,   997,   618,   998,
     999,  1000,  1001,  1002,  1003,  1004,  1005,  1006,  1007,  1008,
    1009,  1010,  1011,  1012,  1013,  1014,  1015,  1016,  1017,  1018,
    1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,   619,  1027,
    1028,  1029,  1030,   938,  1031,  1032,  1033,  1034,  1035,  1036,
    1037,  1038,  1185,  1040,  1045,  1046,  1047,  1330,  1320,  1039,
    1049,  1050,  1053,  1051,  1055,  1054,  1056,  1058,   620,   621,
     622,   623,   624,  1057,   625,   626,   627,   628,   629,   630,
     631,   632,   633,   634,   635,   636,  1059,  1298,  1060,  1061,
    1062,  1063,  1355,  1357,  1067,  1548,  2604,  1064,  1065,  1066,
    1459,  1068,  1069,  1070,  1071,  1072,  1073,  1074,  1075,  1076,
    1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,
    1088,  1087,  1089,  1090,  1091,  1319,  1115,  1183,  1092,  1093,
    1287,  1094,  1095,  1096,   281,  1097,  1098,  1099,  1100,  1101,
    1102,  1103,  1111,  1113,  1127,  1104,  1135,  1105,  1305,  1306,
    1725,   369,  1307,  1309,  1310,  1311,  1312,  1313,  1106,  1315,
    1316,  1107,  1110,  1112,  1321,  1322,  1323,  1324,  1325,  1326,
    1327,  1116,  1329,  1117,  1331,  1118,  1333,  1334,   637,  1336,
    1337,  1338,  1339,  1340,  1119,  1120,  1121,   986,  1346,  1347,
    1348,  1349,  1350,  1122,  1123,  1124,  1125,   638,  1126,  1128,
    1129,  1130,  1356,  1131,   368,  1132,  1133,  1134,  1136,  1137,
    1138,  1139,  1140,  1141,  1153,  1142,  1143,  1366,  1367,  1144,
    1368,  1369,  1370,  1371,  1372,  1145,  1374,  1375,  1376,  1377,
    1378,  1379,  1146,  1380,  1147,  1148,  1149,  1150,  1151,  1152,
    1386,  1387,  1388,  1389,  1390,  1391,  1392,  1393,   961,  1395,
    1154,  1155,  1156,  1157,  1341,  1159,  1160,  1162,  1161,  1163,
    1164,  1165,  1166,  1167,  1404,  1345,  1224,  1171,  1407,  1408,
    1409,  1168,  1169,  1412,  1413,  1414,  1415,  1416,  1417,  1170,
    1418,  1419,  1420,  1421,  1422,  1178,  1179,  1180,  1181,  1182,
    1184,  1193,  1302,  1200,  1430,  1431,  1432,  1433,  1434,  1435,
    1436,  1437,  1438,  1439,  1440,  1189,  1190,  1191,  1441,  1442,
    1192,  1198,  1199,  1443,  1201,  1202,  1203,  1204,  1205,  1206,
    1210,  1445,  1446,  1211,  1212,  1213,  1215,  1216,  1217,  1218,
    1219,  1220,  1221,  1451,  1222,  1223,  1227,  1228,  1229,  1231,
    1461,  1462,  1232,  1464,  1465,  1233,  1234,  1467,  1235,  1468,
    1469,  1236,  1237,  1238,  1239,  1471,  1240,  1241,  1242,  1475,
    1476,  1477,  1243,  1244,  1479,  1245,  1246,  1247,  1248,  1483,
    1485,  1487,  1488,  1489,  1490,  1491,  1249,  1250,  1251,  1493,
    1494,  1495,  1252,  1496,  1497,  1498,  1499,  1500,  1501,  1253,
    1503,  1504,  1505,  1506,  1507,  1508,  1509,  1510,  1713,  1714,
    1254,  1926,  1255,  1256,  1517,  1257,  1519,  1520,  1258,  1522,
    1523,  1524,  1928,  1259,  1935,  1260,  1261,  1262,  1263,  1264,
    1265,  1266,  1267,  1268,  1269,  1270,  1271,  1272,  1273,  1274,
    1275,  1278,  1279,  1280,  1281,  1282,  1283,  1549,  1332,  1285,
    1550,  1289,  1303,  1553,  1284,  1555,  1556,  1292,  1290,  1293,
    1294,  1295,  1296,  1301,  1297,  1344,  1359,  1358,  1361,   308,
    1362,  1363,  1406,  1447,  1448,  1561,  1513,  1514,  1460,   281,
    1515,  1563,  1554,  1565,  1564,  1566,  1571,  1568,  1569,  1573,
    1570,  1572,  1575,  1574,  1527,  1528,  1529,  1576,  1577,  1578,
    1579,  1580,  1581,  1536,  1583,  1538,  1539,  1582,  1584,  1585,
    1589,  1586,  1587,  1588,  1591,  1590,  1595,  1592,  1596,  1597,
    1601,  1598,  1605,  1599,   855,  1600,  1602,  1609,  1610,  1606,
    1607,  1608,   986,  1612,  1613,  1611,  1614,  1615,  1619,  1617,
    1620,  1626,  1628,  1629,  1630,  1627,  1631,  1632,  1633,  1925,
     882,  1636,   881,  1637,  1861,  1638,  1639,  1640,  1641,  1642,
    1643,  1644,  1645,  1646,  1647,  1648,  1649,  1650,  1651,  1652,
    1653,  1654,  1655,  1656,  1657,  1658,  1659,  1660,  1661,  1664,
    1665,  1662,  1663,  1666,  1667,  1669,  1670,   961,  1671,  1672,
    1552,  1986,  1343,  1673,  1680,  1674,  1675,  1678,  1679,  1681,
    1682,  1683,  1684,  1685,  1686,  1687,  1688,   886,     0,  1711,
    1689,   540,  1695,  1690,  1691,  1692,  1693,  1694,  1696,  1697,
    1698,  1699,  1700,  1701,  1989,  2113,  1716,  1707,   541,   884,
    1704,  1705,  1706,  1726,  1708,  1709,  1710,  1715,  1727,  1729,
    1717,  1718,  1719,  1728,  1720,  1732,  1730,  1731,  1733,  1734,
    1735,  1737,  1736,  1738,  1744,  1739,  1745,  1749,  1721,  1743,
    1750,  1746,  1755,  1819,  1751,  1753,  1762,  1758,  1763,  1759,
    1764,  1765,  1766,  1769,  1828,  1770,  1774,  2177,  1778,  2094,
    1771,  1779,  1780,  1775,  1936,  1776,  1777,  1781,  1782,  1783,
    1784,  1785,  1786,  2311,  2415,  1789,  1790,  2095,  1792,  1787,
    1788,  1793,  1794,  1791,  1492,  1797,  1798,   981,     0,  1799,
    1800,  1801,  1804,  1805,  1808,  1809,  1810,  1811,  1814,  1815,
    1816,  1817,  1818,  1820,  1821,  1822,  1831,  2510,  1823,  1834,
    1835,  1836,  1837,  1824,  1838,  1825,  1839,  1826,   369,  1827,
    1829,  1862,  1842,  1843,  1844,  1863,  1901,  1845,  1846,  1847,
    1848,  1990,  1849,  1987,  1850,  1988,  1851,     0,  1991,  1852,
    1853,  1854,  1855,  1993,  1994,  1995,  1856,  1996,  1997,  1858,
    1998,  1999,  2000,  1860,  2001,  2002,  2003,  2004,  2006,  2005,
     883,  2096,  2011,  2007,  2016,  2008,  2009,  2010,  2017,  1870,
    2229,   368,  2012,  2013,  1871,  2014,  2015,  2018,  1873,  1874,
    1875,  1876,  1877,  1878,  1879,  1880,  1882,  1883,  1884,  1885,
    1886,  1887,  1888,  1889,  1890,  1891,  1892,  1893,  1866,  2019,
    1894,  2020,  2021,  2023,  2024,  2030,  2027,  2028,  1900,  2057,
    2029,  2065,  2039,  2040,  1902,  1903,  1904,  1905,  2041,  1906,
    1908,  1909,  2045,  1910,  2046,  2047,  2048,  2051,  2052,  2053,
    2054,  2055,  1913,  2056,  2058,  1916,  1917,  2059,  2060,  2061,
    2062,  2063,  2064,  2066,  2071,  1918,  1919,  1920,  1921,  2072,
    1922,  1923,  1924,  2073,  2074,  2076,  2075,  1927,  2077,  2078,
    2079,  2083,  2080,  2081,  2087,  2091,  2082,  2093,  2084,  1937,
    1938,  2085,  1939,  1940,  2100,  2086,  1941,  2088,  1942,  2089,
    2092,  1944,  2097,  1945,  1946,  1947,  2098,  2099,  2101,  2102,
    1949,  2103,  2104,  1950,  2105,  1951,  2106,  2112,  2107,  1952,
    1953,  1954,  2108,  1955,  2114,  2115,  2116,  2117,  2118,  2119,
    1956,  2120,  2121,  1957,  2122,  1958,  2123,  1959,  1960,  1961,
    2563,  2124,  2125,  2126,  2127,  2128,  2129,  2130,  2131,  1962,
    1963,  2132,  2133,  1964,  2134,  2135,  2136,  2137,  1965,  1966,
    1967,  1968,  1969,  1970,  2140,  1971,  1972,  1973,  2141,  1974,
    1975,  1976,  1977,  1978,  2142,  1979,  1980,  1981,  2143,  1983,
    2144,  1985,  2145,  2148,   542,  2149,  2157,  2150,  2151,  2152,
    2153,  2154,  2175,  2272,  2275,  2276,  2277,  2278,  2279,  2282,
    2280,     0,  2281,  2283,  2286,  2288,  2284,  2285,  2287,  2289,
       0,  2564,  2292,  2293,  2298,  2302,  2299,  2300,  2301,  2303,
    2304,  2313,  2305,  2306,  2307,  2308,  2309,  2022,  2315,  2316,
    2317,  2318,  2319,  2320,   543,   544,  2321,  2322,  2323,  2324,
    2325,  2328,  2329,  2332,  2333,  2334,  2335,  2336,  2340,  2343,
    2339,  2344,  2345,  2346,  2347,  2659,  2349,  2352,     0,   545,
       0,  2350,  2351,  2356,  2353,  2354,  2355,  2357,  2358,  2360,
    2359,  2361,  2362,  2363,  2364,  2365,  2366,  2367,  2368,  2369,
    2370,  2371,  2372,  2373,     0,     0,     0,  2090,   546,  2379,
    2374,  2375,  2376,  2377,  2378,  2380,  2381,  2382,  2383,  2384,
    2385,  2387,  2388,  2386,  2455,  2456,  2457,  2458,     0,  2459,
    2462,  2460,  2463,  2464,  2461,  2465,  2466,  2467,  2469,  2470,
    2468,  2471,  2472,  2473,  2477,   885,  2474,  2479,  2480,     0,
    2483,  2478,  2481,  2485,  2486,  2482,  2487,  2484,  2488,  2489,
    2490,  2491,  2492,  2493,  2494,  2495,  2497,  2498,     0,  2496,
    2499,  2501,  2503,  2158,  2500,  2159,  2502,  2160,  2505,  2161,
    2504,  2162,  2506,  2507,  2511,  2508,  2163,  2164,  2509,  2165,
    2166,  2167,  2168,  2512,  2169,  2170,  2171,  2172,  2513,  2515,
    2514,  2173,  2174,  2516,  2517,  2553,  2518,  2519,  2348,  2520,
    2178,  2179,  2554,  2555,  2180,  2556,  2181,  2557,  2182,  2558,
    2183,  2184,  2185,  2186,  2559,  2187,  2188,  2189,  2190,  2191,
    2192,  2560,  2195,  2198,  2561,  2202,  2203,  2204,  2205,  2176,
    2206,  2207,  2208,  2209,  2210,  2562,  2212,  2565,  2566,  2567,
    2568,  2569,  2570,     0,  2571,  2572,  2217,  2218,  2573,  2574,
    2219,  2575,  2576,  2222,  2223,  2577,  2224,  2225,  2226,  2578,
    2227,  2228,  2579,  2580,  2230,  2583,  2584,  2585,  2612,  2613,
    2614,  2615,  2616,  2231,  2232,  2617,  2233,  2619,  2234,  2618,
    2236,  2639,  2237,  2238,  2620,  2239,  2623,  2240,  2241,  2242,
    2243,  2244,  2245,  2246,  2626,  2247,  2248,  2249,  2250,  2251,
    2252,  2253,  2254,  2255,  2627,  2256,  2257,  2258,  2259,  2628,
    2629,  2630,  2632,  2633,  2636,  2640,  2658,  2660,  2661,  2262,
    2263,  2264,  2662,  2266,  2663,  2268,  2269,  2664,     0,  2665,
    2669,  2666,  2667,  2672,  2668,  2670,  2689,  2671,  2688,  2691,
    2690,  2692,  2694,  2693,  2695,  2696,  2697,  2704,  2708,  2705,
    2706,  2709,  2707,  2714,  2717,  2715,  2716,  2727,  2721,  2722,
    2732,  2723,  2728,  2733,  2729,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2389,     0,     0,  2390,  2391,     0,  2392,
    2393,     0,  2394,  2395,     0,  2396,  2397,  2398,     0,  2399,
       0,     0,     0,     0,  2401,  2402,     0,  2403,     0,  2404,
    2405,  2406,  2407,  2408,     0,  2409,  2410,  2411,  2412,  2413,
    2414,     0,     0,  2417,     0,     0,     0,     0,     0,     0,
       0,  2422,  2423,  2424,  2400,     0,     0,     0,     0,  2429,
    2430,     0,     0,  2431,     0,  2432,  2433,     0,  2434,     0,
       0,     0,     0,     0,  2437,     0,     0,     0,     0,     0,
       0,  2438,  2439,  2440,     0,  2441,     0,  2443,     0,     0,
    2444,  2445,     0,     0,     0,     0,     0,     0,     0,   276,
       0,     0,     0,   309,     0,     0,  2446,  2447,  2448,  2449,
    2450,     0,     0,     0,     0,     0,  2452,  2453,  2454,   319,
       0,     0,     0,     0,     0,   330,   331,   319,     0,   319,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   319,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2521,     0,
       0,  2522,  2523,  2524,     0,     0,     0,  2525,     0,     0,
    2526,     0,     0,     0,     0,     0,  2527,     0,  2528,     0,
    2529,     0,     0,  2530,  2531,     0,  2532,     0,     0,     0,
       0,     0,     0,     0,     0,  2534,  2535,     0,  2536,     0,
       0,  2537,  2538,     0,     0,     0,  2540,     0,  2541,  2542,
       0,  2544,  2545,     0,     0,  2546,  2547,     0,  2548,     0,
    2550,  2551,  2552,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2586,  2587,  2588,  2589,
    2590,     0,     0,     0,  2591,  2592,  2593,     0,  2594,  2595,
       0,  2596,  2597,     0,  2599,  2600,  2601,     0,  2603,     0,
    2605,  2606,  2607,   319,   319,  2609,  2610,  2611,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   276,     0,     0,     0,  2641,     0,     0,     0,
    2642,     0,  2643,     0,     0,  2645,     0,     0,  2647,  2648,
    2649,  2650,  2651,     0,  2652,  2653,     0,  2654,  2655,     0,
    2656,     0,  2657,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   309,     0,     0,     0,     0,
    2677,  2678,  2679,     0,     0,     0,     0,  2680,  2681,  2682,
       0,     0,  2684,  2685,     0,     0,  2686,     0,     0,     0,
       0,     0,     0,   319,     0,   319,   309,     0,     0,     0,
    2698,     0,  2699,     0,  2700,     0,     0,  2702,     0,     0,
       0,     0,   319,     0,     0,     0,  2710,  2711,  2712,  2713,
       0,     0,     0,     0,     0,     0,  2718,  2719,  2720,     0,
       0,     0,     0,  2724,  2725,  2726,     0,     0,     0,     0,
    2730,  2731,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   682,   684,   682,   682,
     682,   682,   682,   682,     0,   682,   682,     0,     0,     0,
       0,     0,   682,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   682,   682,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   682,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   682,   682,   682,   682,   682,   682,   682,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   319,   319,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   682,     0,     0,     0,     0,     0,     0,     0,   792,
       0,     0,     0,     0,   319,   682,   682,   682,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   319,   682,     0,     0,     0,     0,   682,
     682,     0,   682,   682,     0,   682,   682,     0,   682,   682,
     319,   319,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   837,     0,
     682,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   682,
     977,   985,     0,     0,     0,     0,     0,     0,     0,     0,
     837,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1043,   319,     0,     0,     0,     0,
       0,     0,     0,   319,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   332,     0,   334,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   372,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   319,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   319,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   319,     0,     0,     0,     0,   319,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     511,   512,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   319,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1286,   319,     0,     0,     0,     0,
       0,   319,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   319,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   682,     0,
     596,     0,   598,     0,     0,     0,     0,     0,     0,   256,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   600,
       0,     0,     0,     0,   319,     0,   319,     0,     0,     0,
       0,   321,     0,     0,   329,     0,  1360,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   682,   682,     0,     0,     0,     0,     0,   367,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   682,     0,     0,     0,     0,   682,   682,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   319,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     765,   766,     0,     0,     0,     0,     0,   319,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   797,     0,     0,     0,     0,     0,     0,   682,     0,
       0,     0,     0,   319,     0,     0,     0,     0,     0,     0,
     319,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     810,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   682,   828,   829,     0,
     367,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     682,     0,   682,     0,     0,     0,     0,     0,     0,   682,
       0,     0,     0,     0,   682,   682,   682,   319,   682,     0,
       0,     0,   256,     0,   682,   309,     0,   682,   682,   682,
     682,   682,   682,     0,     0,     0,     0,     0,   319,     0,
       0,     0,     0,     0,   319,   319,     0,     0,     0,  1560,
     319,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   682,     0,     0,     0,
     682,     0,     0,     0,   367,   367,     0,     0,     0,     0,
       0,  1042,  1044,     0,     0,     0,     0,     0,     0,     0,
    1048,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   682,     0,     0,     0,     0,
       0,     0,     0,     0,   691,     0,     0,   694,   695,   696,
     697,   698,     0,   700,   701,   702,   703,   704,   705,   706,
     707,   708,     0,     0,   711,     0,     0,   718,   719,   720,
     721,   722,   723,   724,   725,   726,   727,   319,   729,   730,
     731,   732,   733,   734,   735,   736,   737,   738,   739,   740,
     741,   742,   744,     0,     0,     0,     0,     0,     0,   751,
     752,   753,   754,   755,   756,   757,   758,   759,   760,   761,
     762,     0,     0,     0,     0,   767,   768,   769,     0,     0,
     772,   773,   774,   775,   776,   777,   778,   779,   780,   781,
     782,     0,     0,     0,   786,   788,   789,   790,     0,  1174,
     793,   794,   795,   796,     0,     0,     0,     0,   801,     0,
     683,   685,   686,   687,   688,   689,   690,     0,   692,   693,
       0,     0,     0,     0,     0,   699,     0,     0,     0,     0,
       0,     0,   367,     0,     0,   709,   710,     0,     0,     0,
    1214,   819,     0,     0,     0,     0,     0,     0,     0,     0,
     728,     0,   319,   831,   832,   833,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   743,   745,   746,   747,   748,
     749,   750,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1226,     0,     0,     0,     0,  1230,   682,     0,     0,
       0,     0,     0,     0,   783,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   798,   799,
     800,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   811,     0,     0,
    1277,     0,   817,   818,     0,   820,   821,     0,   823,   824,
       0,   826,   827,     0,     0,     0,  1907,     0,  1277,     0,
       0,     0,     0,     0,     0,   682,     0,     0,   682,     0,
       0,     0,     0,   868,     0,     0,     0,     0,     0,  1304,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   964,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1948,     0,     0,     0,     0,
       0,  1351,     0,  1354,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   682,     0,   682,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1424,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1444,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1472,     0,     0,     0,     0,     0,     0,  1478,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1533,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   319,   319,     0,     0,
       0,     0,     0,     0,     0,  1551,     0,     0,     0,     0,
       0,  1557,  1558,     0,     0,     0,     0,  1562,     0,     0,
       0,   367,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1308,
       0,     0,     0,     0,     0,  1314,     0,     0,  1318,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   682,     0,   682,
     682,     0,   682,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1365,     0,     0,     0,     0,     0,     0,
       0,     0,  1373,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1383,  1384,  1385,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1394,     0,     0,     0,     0,
    1396,     0,  1397,  1398,  1399,  1400,  1401,     0,  1402,  1403,
       0,     0,     0,     0,   682,     0,     0,     0,     0,   682,
       0,   682,     0,     0,  1712,     0,     0,     0,     0,     0,
       0,  1328,  1423,     0,     0,     0,  1425,  1426,  1427,  1428,
    1429,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1463,
       0,     0,  1466,     0,  1381,  1382,     0,     0,     0,     0,
       0,     0,     0,     0,  1473,  1474,     0,     0,     0,     0,
       0,     0,  1480,     0,  1481,  1482,  1484,  1486,     0,     0,
       0,     0,     0,     0,     0,     0,  1405,     0,     0,     0,
       0,  1410,  1411,     0,     0,     0,     0,     0,     0,  1830,
       0,     0,     0,     0,     0,  1511,  1512,     0,     0,     0,
       0,     0,     0,     0,     0,  1521,     0,     0,     0,     0,
    1526,     0,     0,     0,     0,     0,     0,     0,     0,  1535,
       0,  1537,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   682,     0,     0,
       0,  1470,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1502,
       0,   682,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1622,  1623,  1516,     0,  1518,     0,     0,     0,     0,
       0,     0,  1525,     0,     0,     0,     0,  1530,  1531,  1532,
       0,  1534,     0,     0,     0,     0,     0,  1540,     0,     0,
    1542,  1543,  1544,  1545,  1546,  1547,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1618,
       0,     0,     0,  1621,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   682,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1668,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   682,     0,     0,     0,     0,     0,     0,   367,     0,
       0,     0,     0,  1832,     0,  1833,     0,     0,     0,     0,
       0,     0,     0,   682,     0,     0,     0,  1840,  1841,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   682,     0,     0,   682,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1857,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1867,  1869,     0,     0,     0,     0,
       0,     0,     0,     0,  1872,     0,     0,     0,     0,     0,
       0,     0,  1881,     0,     0,   682,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1895,  1896,
    1897,  1898,  1899,  2155,  2156,     0,   682,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1914,  1915,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1859,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1943,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1911,     0,
       0,  1912,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,  1982,     0,
    1984,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1867,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2196,
    2196,  2196,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2211,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2220,  2221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2235,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2260,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2213,     0,  2214,  2215,     0,  2216,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2261,     0,     0,
       0,     0,  2265,     0,  2267,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1867,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2196,
       0,     0,     0,  2196,     0,     0,  2196,  2196,     0,     0,
       0,  2425,  2426,  2427,  2428,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2436,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2442,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2435,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2196,     0,     0,
       0,     0,     0,     0,  2451,     0,     0,     0,     0,     0,
       0,  2539,     0,     0,     0,     0,     0,  2543,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2598,     0,     0,     0,  2602,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2549,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2683,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2701,     0,  2608,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2631,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2644,     0,     0,  2646,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   538,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     2,     3,
       0,     4,     0,     0,     0,     0,     0,     0,  2687,     0,
       0,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,     0,  2703,
      22,    23,    24,    25,    26,    27,    28,     0,    29,    30,
      31,     0,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,     0,     0,    61,    62,    63,    64,    65,    66,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    67,    68,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,     0,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,     0,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,     0,     0,     0,
     109,   110,     0,     0,     0,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,     0,     0,
       0,     0,     0,     0,     0,   140,   141,   142,   143,     0,
       0,     0,     0,   144,     0,     0,     0,   145,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   169,   170,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   171,   172,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,     0,   188,   189,   190,
     191,   192,     0,     0,     0,     0,     0,   193,   194,   195,
     196,   197,   198,   199,   200,     0,     0,   201,   202,   203,
     204,   205,   206,   207,   208,   209,     0,     0,     0,     0,
     210,     0,   211,   212,   213,     0,     0,     0,   214,   215,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   216,   217,   218,   219,     0,     0,     0,     0,
       0,     0,     0,   220,   221,     0,   222,   223,   224,   225,
       0,   226,   227,     0,     0,     0,     0,   228,   229,     0,
       0,     0,   230,     0,   231,   232,   233,   234,   235,     0,
     236,   237,   238,   239,   240,   241,     1,     2,     3,     0,
       4,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     0,     0,    22,
      23,    24,    25,    26,    27,    28,     0,    29,    30,    31,
       0,    32,    33,    34,     0,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,     0,     0,    61,    62,    63,    64,    65,    66,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    67,    68,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,     0,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,     0,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,     0,     0,     0,   109,
     110,     0,     0,     0,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,     0,     0,     0,
       0,     0,     0,     0,   140,   141,   142,   143,     0,     0,
       0,     0,   144,     0,     0,     0,   145,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   169,   170,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   171,   172,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,     0,   188,   189,   190,   191,
     192,     0,     0,     0,     0,     0,   193,   194,   195,   196,
     197,   198,   199,   200,     0,     0,   201,   202,   203,   204,
     205,   206,   207,   208,   209,     0,     0,     0,     0,   210,
       0,   211,   212,   213,     0,     0,     0,   214,   215,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   216,   217,   218,   219,     0,     0,     0,     0,     0,
       0,     0,   220,   221,     0,   222,   223,   224,   225,     0,
     226,   227,     0,     0,     0,     0,   228,   229,     0,     0,
       0,   230,     0,   231,   232,   233,   234,   235,     0,   236,
     237,   238,   239,   240,   241,     1,     2,     3,     0,     4,
       0,     0,     0,   965,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      16,    17,     0,     0,   966,    21,     0,   967,     0,     0,
       0,     0,     0,     0,     0,     0,    29,     0,     0,     0,
      32,    33,    34,     0,    35,     0,    37,   287,   288,   289,
     290,   968,   292,   293,    45,   969,   295,   970,    49,    50,
      51,    52,    53,   362,   363,   971,   507,   366,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    67,    68,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,     0,    82,     0,    84,
      85,    86,    87,    88,    89,    90,    91,     0,     0,     0,
      94,     0,    96,    97,    98,   300,   301,   101,   102,   103,
     104,   105,   106,   107,   108,     0,     0,     0,   109,   110,
       0,     0,     0,     0,     0,     0,     0,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,     0,     0,
       0,     0,     0,     0,   138,     0,     0,     0,   939,   940,
     941,     0,     0,   140,   141,   142,   143,   942,   943,   944,
     945,   144,     0,     0,   946,   145,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   146,   147,   148,   149,     0,     0,     0,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,     0,     0,   167,   168,   947,     0,     0,   948,   949,
     950,   951,     0,   952,   953,   169,   170,   972,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   973,   171,   172,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   173,
     174,   175,   176,   177,   974,   179,   180,   975,   182,   183,
     184,   185,   186,   187,     0,   188,     0,   190,   191,     0,
     976,     0,     0,     0,     0,   193,   194,   195,   196,   197,
     198,   199,   200,     0,     0,   201,   202,   203,   204,   205,
     206,   207,   208,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     216,   217,   218,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   222,   223,   224,   225,     0,   226,
     227,     0,   955,   956,   957,   228,   229,     0,   958,   959,
       0,   960,   231,   232,   233,     1,     2,     3,     0,     4,
       0,     0,     0,   982,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      16,    17,     0,     0,    20,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    29,     0,     0,     0,
      32,    33,    34,     0,    35,     0,    37,   287,   288,   289,
     290,   968,   292,   293,    45,   983,   295,   970,    49,    50,
      51,    52,    53,   362,   363,   364,   507,   366,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    67,    68,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,     0,    82,     0,    84,
      85,    86,    87,    88,    89,    90,    91,     0,     0,     0,
      94,     0,    96,    97,    98,   300,   301,   101,   102,   103,
     104,   105,   106,   107,   108,     0,     0,     0,   109,   110,
       0,     0,     0,     0,     0,     0,     0,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,     0,     0,
       0,     0,     0,     0,   138,     0,     0,     0,     0,     0,
       0,     0,     0,   140,   141,   142,   143,     0,     0,     0,
       0,   144,     0,     0,     0,   145,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   146,   147,   148,   149,     0,     0,     0,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,     0,     0,   167,   168,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   169,   170,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   171,   172,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,     0,   188,     0,   190,   191,     0,
       0,     0,     0,     0,     0,   193,   194,   195,   196,   197,
     198,   199,   200,     0,     0,   201,   202,   203,   204,   205,
     206,   207,   208,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     216,   217,   218,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   222,   223,   224,   225,     0,   226,
     227,     0,     0,     0,     0,   228,   229,     1,     2,     3,
       0,     4,   231,   232,   233,  1559,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    16,    17,     0,     0,    20,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    29,     0,
       0,     0,    32,    33,    34,     0,    35,     0,    37,   287,
     288,   289,   290,   968,   292,   293,    45,   983,   295,   970,
      49,    50,    51,    52,    53,   362,   363,   364,   507,   366,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    67,    68,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,     0,    82,
       0,    84,    85,    86,    87,    88,    89,    90,    91,     0,
       0,     0,    94,     0,    96,    97,    98,   300,   301,   101,
     102,   103,   104,   105,   106,   107,   108,     0,     0,     0,
     109,   110,     0,     0,     0,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
       0,     0,     0,     0,     0,     0,   138,     0,     0,     0,
       0,     0,     0,     0,     0,   140,   141,   142,   143,     0,
       0,     0,     0,   144,     0,     0,     0,   145,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   146,   147,   148,   149,     0,     0,
       0,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,     0,     0,   167,   168,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   169,   170,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   171,   172,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,     0,   188,     0,   190,
     191,     0,     0,     0,     0,     0,     0,   193,   194,   195,
     196,   197,   198,   199,   200,     0,     0,   201,   202,   203,
     204,   205,   206,   207,   208,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   216,   217,   218,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   222,   223,   224,   225,
       0,   226,   227,     0,     0,     0,     0,   228,   229,     1,
       2,     3,     0,     4,   231,   232,   233,     0,     0,     0,
       0,     0,     0,     5,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,    17,     0,    19,    20,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      29,     0,     0,     0,    32,    33,    34,     0,    35,     0,
      37,   287,   288,   289,   290,   291,   292,   293,    45,   294,
     295,   296,    49,    50,    51,    52,    53,     0,   297,     0,
     298,   299,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    67,    68,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
       0,    82,     0,    84,    85,    86,    87,    88,    89,    90,
      91,     0,     0,     0,    94,     0,    96,    97,    98,   300,
     301,   101,   102,   103,   104,   105,   106,   107,   108,     0,
       0,     0,   109,   110,     0,     0,     0,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,     0,     0,     0,     0,     0,     0,   138,     0,
       0,     0,     0,     0,     0,     0,     0,   140,   141,   142,
     143,     0,     0,     0,     0,   144,     0,     0,     0,   145,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   146,   147,   148,   149,
       0,     0,     0,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,     0,     0,   167,   168,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   169,
     170,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   171,   172,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,     0,   188,
       0,   190,   191,     0,     0,     0,     0,     0,     0,   193,
     194,   195,   196,   197,   198,   199,   200,     0,     0,   201,
     202,   203,   204,   205,   206,   207,   208,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   216,   217,   218,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   222,   223,
     224,   225,     0,   226,   227,     0,     0,     0,     0,   228,
     229,     1,     2,     3,     0,     4,   231,   232,   233,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    16,    17,     0,     0,
      20,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    29,     0,     0,     0,    32,    33,    34,     0,
      35,     0,    37,   287,   288,   289,   290,   968,   292,   293,
      45,   983,   295,   970,    49,    50,    51,    52,    53,   362,
     363,   364,   507,   366,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    67,    68,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,     0,    82,     0,    84,    85,    86,    87,    88,
      89,    90,    91,     0,     0,     0,    94,     0,    96,    97,
      98,   300,   301,   101,   102,   103,   104,   105,   106,   107,
     108,     0,     0,     0,   109,   110,     0,     0,     0,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,     0,     0,     0,     0,     0,     0,
     138,     0,     0,     0,     0,     0,     0,     0,     0,   140,
     141,   142,   143,     0,     0,     0,     0,   144,     0,     0,
       0,   145,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   146,   147,
     148,   149,     0,     0,     0,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,     0,     0,   167,
     168,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   169,   170,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     171,   172,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
       0,   188,     0,   190,   191,     0,     0,     0,     0,     0,
       0,   193,   194,   195,   196,   197,   198,   199,   200,     0,
       0,   201,   202,   203,   204,   205,   206,   207,   208,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   216,   217,   218,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     222,   223,   224,   225,     0,   226,   227,     0,     0,     0,
       0,   228,   229,     1,     2,     3,     0,     4,   231,   232,
     233,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    16,    17,
       0,     0,    20,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    29,     0,     0,     0,    32,    33,
      34,     0,    35,     0,    37,   287,   288,   289,   290,   291,
     292,   293,    45,   294,   295,   296,    49,    50,    51,    52,
      53,     0,   297,     0,   298,   299,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    67,
      68,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,     0,    82,     0,    84,    85,    86,
      87,    88,    89,    90,    91,     0,     0,     0,    94,     0,
      96,    97,    98,   300,   301,   101,   102,   103,   104,   105,
     106,   107,   108,     0,     0,     0,   109,   110,     0,     0,
       0,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,     0,     0,     0,     0,
       0,     0,   138,     0,     0,     0,     0,     0,     0,     0,
       0,   140,   141,   142,   143,     0,     0,     0,     0,   144,
       0,     0,     0,   145,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     146,   147,   148,   149,     0,     0,     0,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,     0,
       0,   167,   168,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   169,   170,   963,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   171,   172,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,     0,   188,     0,   190,   191,     0,     0,     0,
       0,     0,     0,   193,   194,   195,   196,   197,   198,   199,
     200,     0,     0,   201,   202,   203,   204,   205,   206,   207,
     208,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   216,   217,
     218,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   222,   223,   224,   225,     0,   226,   227,     0,
       0,     0,     0,   228,   229,     0,     0,     0,     0,     0,
     231,   232,   233,     1,     2,     3,     0,   317,     0,  1288,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    16,    17,
       0,     0,    20,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    29,     0,     0,     0,    32,    33,
      34,     0,    35,     0,    37,   287,   288,   289,   290,   291,
     292,   293,    45,   294,   295,   296,    49,    50,    51,    52,
      53,     0,   297,     0,   298,   299,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    67,
      68,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,     0,    82,     0,    84,    85,    86,
      87,    88,    89,    90,    91,     0,     0,     0,    94,     0,
      96,    97,    98,   300,   301,   101,   102,   103,   104,   105,
     106,   107,   108,     0,     0,     0,   109,   110,     0,     0,
       0,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,     0,     0,     0,     0,
       0,     0,   138,     0,     0,     0,     0,     0,     0,     0,
       0,   140,   141,   142,   143,     0,     0,     0,     0,   144,
       0,     0,     0,   145,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     146,   147,   148,   149,     0,     0,     0,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,     0,
       0,   167,   168,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   169,   170,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   171,   172,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,     0,   188,     0,   190,   191,     0,     0,     0,
       0,     0,     0,   193,   194,   195,   196,   197,   198,   199,
     200,     0,     0,   201,   202,   203,   204,   205,   206,   207,
     208,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   216,   217,
     218,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   222,   223,   224,   225,     0,   226,   227,     0,
       0,     0,     0,   228,   229,     0,     0,     0,     0,     0,
     231,   232,   233,     1,     2,     3,     0,  1276,     0,  1291,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    16,    17,
       0,     0,    20,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    29,     0,     0,     0,    32,    33,
      34,     0,    35,     0,    37,   287,   288,   289,   290,   291,
     292,   293,    45,   294,   295,   296,    49,    50,    51,    52,
      53,     0,   297,     0,   298,   299,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    67,
      68,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,     0,    82,     0,    84,    85,    86,
      87,    88,    89,    90,    91,     0,     0,     0,    94,     0,
      96,    97,    98,   300,   301,   101,   102,   103,   104,   105,
     106,   107,   108,     0,     0,     0,   109,   110,     0,     0,
       0,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,     0,     0,     0,     0,
       0,     0,   138,     0,     0,     0,     0,     0,     0,     0,
       0,   140,   141,   142,   143,     0,     0,     0,     0,   144,
       0,     0,     0,   145,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     146,   147,   148,   149,     0,     0,     0,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,     0,
       0,   167,   168,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   169,   170,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   171,   172,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,     0,   188,     0,   190,   191,     0,     0,     0,
       0,     0,     0,   193,   194,   195,   196,   197,   198,   199,
     200,     0,     0,   201,   202,   203,   204,   205,   206,   207,
     208,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   216,   217,
     218,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   222,   223,   224,   225,     0,   226,   227,     0,
       0,     0,     0,   228,   229,     0,     0,     0,     0,     0,
     231,   232,   233,     1,     2,     3,     0,     4,  1541,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    16,    17,
       0,     0,    20,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    29,     0,     0,     0,    32,    33,
      34,     0,    35,     0,    37,   287,   288,   289,   290,   291,
     292,   293,    45,   294,   295,   296,    49,    50,    51,    52,
      53,     0,   297,     0,   298,   299,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    67,
      68,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,     0,    82,     0,    84,    85,    86,
      87,    88,    89,    90,    91,     0,     0,     0,    94,     0,
      96,    97,    98,   300,   301,   101,   102,   103,   104,   105,
     106,   107,   108,     0,     0,     0,   109,   110,     0,     0,
       0,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,     0,     0,     0,     0,
       0,     0,   138,     0,     0,     0,     0,     0,     0,     0,
       0,   140,   141,   142,   143,     0,     0,     0,     0,   144,
       0,     0,     0,   145,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     146,   147,   148,   149,     0,     0,     0,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,     0,
       0,   167,   168,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   169,   170,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   171,   172,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,     0,   188,     0,   190,   191,     0,     0,     0,
       0,     0,     0,   193,   194,   195,   196,   197,   198,   199,
     200,     0,     0,   201,   202,   203,   204,   205,   206,   207,
     208,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   216,   217,
     218,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   222,   223,   224,   225,     0,   226,   227,     0,
       0,     0,     0,   228,   229,     1,     2,     3,     0,     4,
     231,   232,   233,     0,     0,     0,     0,     0,  2193,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      16,    17,     0,     0,    20,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    29,     0,     0,     0,
      32,    33,    34,     0,    35,     0,    37,   287,   288,   289,
     290,  2194,   292,   293,    45,   294,   295,   296,    49,    50,
      51,    52,    53,     0,   297,     0,   298,   299,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    67,    68,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,     0,    82,     0,    84,
      85,    86,    87,    88,    89,    90,    91,     0,     0,     0,
      94,     0,    96,    97,    98,   300,   301,   101,   102,   103,
     104,   105,   106,   107,   108,     0,     0,     0,   109,   110,
       0,     0,     0,     0,     0,     0,     0,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,     0,     0,
       0,     0,     0,     0,   138,     0,     0,     0,     0,     0,
       0,     0,     0,   140,   141,   142,   143,     0,     0,     0,
       0,   144,     0,     0,     0,   145,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   146,   147,   148,   149,     0,     0,     0,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,     0,     0,   167,   168,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   169,   170,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   171,   172,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,     0,   188,     0,   190,   191,     0,
       0,     0,     0,     0,     0,   193,   194,   195,   196,   197,
     198,   199,   200,     0,     0,   201,   202,   203,   204,   205,
     206,   207,   208,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     216,   217,   218,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   222,   223,   224,   225,     0,   226,
     227,     0,     0,     0,     0,   228,   229,     1,     2,     3,
       0,     4,   231,   232,   233,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    16,    17,     0,     0,    20,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    29,     0,
       0,     0,    32,    33,    34,     0,    35,     0,    37,   287,
     288,   289,   290,   291,   292,   293,    45,   294,   295,   296,
      49,    50,    51,    52,    53,     0,   297,     0,   298,   299,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    67,    68,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,     0,    82,
       0,    84,    85,    86,    87,    88,    89,    90,    91,     0,
       0,     0,    94,     0,    96,    97,    98,   300,   301,   101,
     102,   103,   104,   105,   106,   107,   108,     0,     0,     0,
     109,   110,     0,     0,     0,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
       0,     0,     0,     0,     0,     0,   138,     0,     0,     0,
       0,     0,     0,     0,     0,   140,   141,   142,   143,     0,
       0,     0,     0,   144,     0,     0,     0,   145,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   146,   147,   148,   149,     0,     0,
       0,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,     0,     0,   167,   168,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   169,   170,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   171,   172,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,     0,   188,     0,   190,
     191,     0,     0,     0,     0,     0,     0,   193,   194,   195,
     196,   197,   198,   199,   200,     0,     0,   201,   202,   203,
     204,   205,   206,   207,   208,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   216,   217,   218,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   222,   223,   224,   225,
       0,   226,   227,     0,     0,     0,     0,   228,   229,     1,
       2,     3,     0,   317,   231,   232,   233,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,    17,     0,     0,    20,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      29,     0,     0,     0,    32,    33,    34,     0,    35,     0,
      37,   287,   288,   289,   290,   291,   292,   293,    45,   294,
     295,   296,    49,    50,    51,    52,    53,     0,   297,     0,
     298,   299,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    67,    68,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
       0,    82,     0,    84,    85,    86,    87,    88,    89,    90,
      91,     0,     0,     0,    94,     0,    96,    97,    98,   300,
     301,   101,   102,   103,   104,   105,   106,   107,   108,     0,
       0,     0,   109,   110,     0,     0,     0,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,     0,     0,     0,     0,     0,     0,   138,     0,
       0,     0,     0,     0,     0,     0,     0,   140,   141,   142,
     143,     0,     0,     0,     0,   144,     0,     0,     0,   145,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   146,   147,   148,   149,
       0,     0,     0,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,     0,     0,   167,   168,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   169,
     170,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   171,   172,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,     0,   188,
       0,   190,   191,     0,     0,     0,     0,     0,     0,   193,
     194,   195,   196,   197,   198,   199,   200,     0,     0,   201,
     202,   203,   204,   205,   206,   207,   208,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   216,   217,   218,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   222,   223,
     224,   225,     0,   226,   227,     0,     0,     0,     0,   228,
     229,     1,     2,     3,     0,  1276,   231,   232,   233,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    16,    17,     0,     0,
      20,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    29,     0,     0,     0,    32,    33,    34,     0,
      35,     0,    37,   287,   288,   289,   290,   291,   292,   293,
      45,   294,   295,   296,    49,    50,    51,    52,    53,     0,
     297,     0,   298,   299,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    67,    68,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,     0,    82,     0,    84,    85,    86,    87,    88,
      89,    90,    91,     0,     0,     0,    94,     0,    96,    97,
      98,   300,   301,   101,   102,   103,   104,   105,   106,   107,
     108,     0,     0,     0,   109,   110,     0,     0,     0,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,     0,     0,     0,     0,     0,     0,
     138,     0,     0,     0,     0,     0,     0,     0,     0,   140,
     141,   142,   143,     0,     0,     0,     0,   144,     0,     0,
       0,   145,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   146,   147,
     148,   149,     0,     0,     0,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,     0,     0,   167,
     168,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   169,   170,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     171,   172,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
       0,   188,     0,   190,   191,     0,     0,     0,     0,     0,
       0,   193,   194,   195,   196,   197,   198,   199,   200,     0,
       0,   201,   202,   203,   204,   205,   206,   207,   208,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   216,   217,   218,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     222,   223,   224,   225,     1,   226,   227,     0,     4,     0,
       0,   228,   229,     0,     0,     0,     0,     0,   231,   232,
     233,     0,     0,     0,     0,     0,     0,     0,     0,    16,
      17,     0,     0,    20,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    29,     0,     0,     0,    32,
      33,    34,     0,    35,     0,    37,   287,   288,   289,   290,
     291,   292,   293,    45,   294,   295,   296,    49,    50,    51,
      52,    53,     0,   297,     0,   298,   299,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,     0,    82,     0,    84,    85,
      86,    87,    88,    89,    90,    91,     0,     0,     0,    94,
       0,    96,    97,    98,   300,   301,   101,   102,   103,   104,
     105,   106,   107,   108,     0,     0,     0,   109,   110,     0,
       0,     0,     0,     0,     0,     0,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,     0,     0,     0,
       0,     0,     0,   138,     0,     0,     0,     0,     0,     0,
       0,     0,   140,   141,   142,   143,     0,     0,     0,     0,
     144,     0,     0,     0,   145,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   146,   147,   148,   149,     0,     0,     0,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
       0,     0,   167,   168,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   169,   170,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   171,   172,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,     0,   188,     0,   190,   191,     0,     0,
       0,     0,     0,     0,   193,   194,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   216,
     217,   218,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   222,   223,   224,   225,   286,   226,   227,
       0,     0,     0,     0,   228,   229,     0,     0,     0,     0,
       0,   231,   232,   233,     0,     0,     0,     0,    16,    17,
       0,     0,    20,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    29,     0,     0,     0,    32,    33,
      34,     0,    35,     0,    37,   287,   288,   289,   290,   291,
     292,   293,    45,   294,   295,   296,    49,    50,    51,    52,
      53,     0,   297,     0,   298,   299,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,     0,    82,     0,    84,    85,    86,
      87,    88,    89,    90,    91,     0,     0,     0,    94,     0,
      96,    97,    98,   300,   301,   101,   102,   103,   104,   105,
     106,   107,   108,     0,     0,     0,   109,   110,     0,     0,
       0,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,     0,     0,     0,     0,
       0,     0,   138,     0,     0,     0,     0,     0,     0,     0,
       0,   140,   141,   142,   143,     0,     0,     0,     0,   144,
       0,     0,     0,   145,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     146,   147,   148,   149,     0,     0,     0,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,     0,
       0,   167,   168,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   169,   170,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   171,   172,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,     0,   188,     0,   190,   191,     0,     0,     0,
       0,     0,     0,   193,   194,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   216,   217,
     218,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   222,   223,   224,   225,     0,   226,   227,     0,
       0,     0,     0,   228,   229,     0,     0,     0,     0,     0,
     231,   232,   233
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
         8,     9,    10,   214,    59,     0,   581,     1,    23,     0,
     116,    23,  2051,  2052,    53,    54,    41,    46,    47,    19,
      60,    19,    37,    15,    46,    21,    19,     4,    13,   165,
     166,    68,   243,     5,     6,    22,    15,    60,   508,   509,
     251,    81,    54,    80,    69,    68,   165,   166,    95,   519,
      13,   272,   273,    92,    79,    60,    19,    80,    81,    19,
      65,    60,     0,    96,    97,    98,    99,    13,    59,   116,
     206,    54,    23,    59,    56,    56,    81,    13,    60,    60,
     216,   217,    81,   116,    22,    13,    37,   105,   106,    56,
      76,   130,    59,    10,    11,    13,   114,   216,   217,    81,
      81,    19,    95,    95,   325,    72,    73,    74,    75,    13,
      93,    68,    14,   109,    13,    19,    20,    19,   116,    13,
     159,    59,   109,    80,    13,   164,    15,    13,   167,   168,
     169,   170,    95,    19,    14,    14,    96,    97,   110,   111,
      20,    20,    19,    23,    23,   167,   227,   228,   229,   230,
     231,   232,   233,   234,   235,    19,   211,    13,    14,    19,
     199,   200,   201,    19,   164,   202,   203,   204,    19,    54,
     306,   307,   308,   309,   211,   212,   213,   214,    13,    13,
      20,   218,    22,    23,    19,    20,    13,   306,   307,   308,
     309,   272,    19,    20,   159,   160,   161,   209,   428,   429,
     430,   431,   432,    20,   434,   213,    23,    19,   220,   221,
     428,   429,   430,   431,   432,    14,   434,    20,    14,    22,
     211,    20,   259,    19,    20,   262,   263,   264,   265,    19,
     267,   268,    13,    14,   271,    13,    14,    14,    19,    13,
      14,    19,    13,    20,    14,    19,    19,    14,   243,    14,
      20,    14,   243,    20,    14,    20,    14,    20,    14,    14,
      20,    14,    20,    14,    20,    20,    14,    20,    14,    20,
      14,  2310,    20,   211,    20,  2314,    20,    14,  2317,  2318,
     335,   336,    14,    20,    14,    14,    61,    59,    20,    64,
      20,    20,   331,   332,    13,   401,    15,    14,   337,    13,
     511,    15,   327,    20,    14,   243,    14,   315,    14,    14,
      20,   350,    20,    13,    20,    20,    19,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,    13,   368,
      14,    14,    14,   341,   346,   546,    20,    20,    20,    13,
     317,   349,    13,   351,   335,   336,   375,   376,   377,   378,
      14,    14,    14,    14,   337,    14,    20,    20,    20,    20,
      13,    20,    14,    14,    14,   373,   374,    13,    20,    20,
      20,   112,   113,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   368,   409,    19,    14,    14,
      14,   272,   273,   408,    20,    20,    20,   335,   336,    14,
      13,   339,   340,     7,     8,    20,    19,    13,    12,   446,
     447,   448,    13,     2,     3,   452,   453,    14,   455,    14,
      14,    14,    14,    20,     0,    20,    20,    20,    20,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,    14,    14,    20,    14,    22,    13,    20,    20,  2488,
      20,  1026,   337,    14,    14,    14,    14,    13,   513,    20,
      20,    20,    20,   376,   377,   473,   474,    13,   476,    15,
      13,   479,   573,   574,   575,   576,   577,    13,    67,    68,
     159,   160,   161,   368,    13,   272,   273,   274,    13,   276,
      13,   278,   279,   561,   562,   563,   564,   559,   560,   286,
      13,   513,   289,   290,   291,   292,   293,   294,   295,   296,
     556,   557,   558,    13,   452,   453,   565,   566,    13,    13,
     528,    13,   513,    13,    13,    13,    19,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   326,
      13,   549,    13,   330,    13,    13,    13,    13,   335,   336,
      13,    13,    13,    13,    13,    13,    13,    13,    13,   346,
      13,   555,    13,    13,   351,   352,    13,    13,    13,    13,
      13,    13,    13,    13,    13,   513,    13,    13,    13,   587,
     588,    13,    13,   591,    13,    13,    13,   582,    13,    19,
     581,   582,    13,    13,    13,   806,   164,   165,   166,   167,
     594,    13,    13,    13,    13,   816,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
      13,    13,    13,    13,    13,    19,    13,    13,    13,   197,
      13,    13,    13,    13,    13,    13,    13,   205,    13,    13,
      13,   579,    13,   581,   582,    13,    13,    13,   216,   217,
      13,    13,   220,    13,    13,    13,    13,   665,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
     678,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    13,   263,    13,   265,   266,   267,
      13,    13,    13,  1173,    13,    13,  1176,    13,   276,   277,
      15,    13,    13,    13,   282,   283,   284,   285,    13,    13,
      13,    13,    13,    13,   108,     4,    13,    15,    17,   297,
     298,   299,   300,   301,    18,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    19,
    1355,    19,    19,    19,    19,    19,    15,    19,    19,    19,
      14,   331,   374,   271,   802,    15,    56,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    56,    22,    57,    56,   445,    65,
     423,    84,    20,   159,   159,    14,    14,    20,   272,    14,
      14,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,   302,    13,
      13,    13,    13,   451,    13,    13,    13,    13,    13,    13,
      13,    13,   437,    13,    13,    13,    13,    69,    65,    20,
      16,    15,    14,    16,    14,    20,    14,    16,   332,   333,
     334,   335,   336,    20,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,    14,   982,    14,    16,
      14,    16,   116,   116,    14,   206,   116,    20,    20,    20,
    1184,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    14,    20,    20,    20,    20,    13,    13,
      20,    14,    20,    20,    20,    58,    16,    13,    20,    20,
     965,    20,    20,    20,   965,    20,    14,    14,    14,    20,
      14,    20,    14,    14,    14,    20,    14,    20,   996,   997,
    1460,   982,  1000,  1001,  1002,  1003,  1004,  1005,    20,  1007,
    1008,    20,    20,    20,  1012,  1013,  1014,  1015,  1016,  1017,
    1018,    20,  1020,    20,  1022,    20,  1024,  1025,   442,  1027,
    1028,  1029,  1030,  1031,    20,    20,    20,   965,  1036,  1037,
    1038,  1039,  1040,    20,    20,    20,    20,   461,    20,    20,
      20,    20,  1050,    20,   982,    20,    20,    20,    14,    20,
      20,    20,    20,    20,    14,    20,    20,  1065,  1066,    20,
    1068,  1069,  1070,  1071,  1072,    20,  1074,  1075,  1076,  1077,
    1078,  1079,    20,  1081,    20,    20,    20,    20,    20,    20,
    1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,  1026,  1097,
      14,    14,    20,    20,  1032,    14,    14,    14,    20,    14,
      14,    14,    14,    14,  1112,    58,    16,    14,  1116,  1117,
    1118,    20,    20,  1121,  1122,  1123,  1124,  1125,  1126,    20,
    1128,  1129,  1130,  1131,  1132,    14,    14,    14,    20,    14,
      13,    13,    16,    14,  1142,  1143,  1144,  1145,  1146,  1147,
    1148,  1149,  1150,  1151,  1152,    20,    20,    20,  1156,  1157,
      20,    20,    20,  1161,    14,    14,    20,    20,    20,    20,
      14,  1169,  1170,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,  1181,    13,    13,    13,    13,    13,    13,
    1188,  1189,    13,  1191,  1192,    13,    13,  1195,    13,  1197,
    1198,    13,    13,    13,    13,  1203,    13,    13,    13,  1207,
    1208,  1209,    13,    13,  1212,    13,    13,    13,    13,  1217,
    1218,  1219,  1220,  1221,  1222,  1223,    13,    13,    13,  1227,
    1228,  1229,    13,  1231,  1232,  1233,  1234,  1235,  1236,    13,
    1238,  1239,  1240,  1241,  1242,  1243,  1244,  1245,  1449,  1450,
      13,  1711,    13,    13,  1252,    13,  1254,  1255,    13,  1257,
    1258,  1259,  1722,    13,  1724,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,  1285,    76,    15,
    1288,    13,    16,  1291,    19,  1293,  1294,    13,    19,    13,
      13,    13,    20,    13,    19,    69,    76,    16,    13,  1276,
      13,    13,    13,   398,    20,  1300,    14,    14,    77,  1300,
      14,    20,    79,    14,    20,    20,    14,    20,    20,    14,
      20,    20,    14,    20,  1262,  1263,  1264,    14,    14,    20,
      20,    20,    20,  1271,    14,  1273,  1274,    20,    14,    20,
      14,    20,    20,    20,    14,    20,    14,    20,    14,    20,
      14,    20,    14,    20,   368,    20,    19,    14,    14,    20,
      20,    20,  1300,    14,    14,    20,    14,    20,    14,    16,
      14,    20,    14,    14,    14,    20,    14,    20,    14,   399,
     568,    20,   567,    20,    56,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    14,    14,    20,    20,    20,    20,    14,
      14,    20,    20,    20,    14,    14,    14,  1355,    14,    20,
     325,    79,  1033,    20,    14,    20,    20,    20,    20,    20,
      14,    14,    14,    14,    20,    14,    14,   572,    -1,  1447,
      20,   243,    14,    20,    20,    20,    20,    20,    14,    14,
      14,    14,    14,    14,    56,    22,    59,    14,   243,   570,
      20,    20,    20,    14,    20,    20,    20,    20,    20,    14,
      59,    59,    59,    20,    59,    14,    20,    20,    14,    20,
      14,    14,    20,    20,    14,    20,    14,    14,    59,    20,
      14,    20,    14,    13,    20,    20,    14,    20,    14,    20,
      14,    14,    14,    14,  1559,    14,    14,    56,    14,    59,
      20,    14,    14,    20,  1725,    20,    20,    14,    14,    14,
      14,    14,    14,    22,    22,    14,    14,    59,    14,    20,
      20,    14,    14,    20,  1225,    20,    20,   581,    -1,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    16,    16,    14,  1564,    22,    16,  1567,
    1568,  1569,  1570,    20,  1572,    14,  1574,    14,  1559,    20,
      14,    14,  1580,  1581,  1582,    14,    14,  1585,  1586,  1587,
    1588,    14,  1590,    20,  1592,    20,  1594,    -1,    20,  1597,
    1598,  1599,  1600,    20,    14,    20,  1604,    14,    20,  1607,
      14,    20,    14,  1611,    14,    14,    14,    20,    14,    20,
     569,    59,    14,    20,    14,    20,    20,    20,    14,  1627,
    2090,  1559,    20,    20,  1632,    20,    20,    14,  1636,  1637,
    1638,  1639,  1640,  1641,  1642,  1643,  1644,  1645,  1646,  1647,
    1648,  1649,  1650,  1651,  1652,  1653,  1654,  1655,  1625,    20,
    1658,    20,    14,    14,    19,    14,    20,    20,  1666,    14,
      20,    14,    20,    20,  1672,  1673,  1674,  1675,    20,  1677,
    1678,  1679,    20,  1681,    20,    20,    20,    20,    20,    20,
      20,    20,  1690,    20,    20,  1693,  1694,    20,    20,    20,
      20,    20,    20,    14,    20,  1703,  1704,  1705,  1706,    14,
    1708,  1709,  1710,    20,    20,    14,    20,  1715,    14,    20,
      20,    14,    20,    20,    14,  1926,    20,  1928,    20,  1727,
    1728,    20,  1730,  1731,  1935,    20,  1734,    20,  1736,    20,
      20,  1739,    59,  1741,  1742,  1743,    59,    59,    20,    20,
    1748,    14,    20,  1751,    14,  1753,    20,    14,    20,  1757,
    1758,  1759,    20,  1761,    14,    20,    20,    20,    20,    20,
    1768,    20,    20,  1771,    14,  1773,    20,  1775,  1776,  1777,
      22,    20,    20,    20,    20,    20,    20,    20,    20,  1787,
    1788,    14,    20,  1791,    20,    20,    20,    14,  1796,  1797,
    1798,  1799,  1800,  1801,    14,  1803,  1804,  1805,    14,  1807,
    1808,  1809,  1810,  1811,    14,  1813,  1814,  1815,    14,  1817,
      14,  1819,    20,    20,   243,    20,    14,    20,    20,    20,
      20,    20,    14,    14,    20,    14,    20,    20,    14,    14,
      20,    -1,    20,    20,    14,    14,    20,    20,    20,    14,
      -1,    22,    20,    20,    20,    14,    20,    20,    20,    20,
      20,    14,    20,    20,    20,    20,    20,  1865,    14,    14,
      20,    20,    20,    20,   243,   243,    20,    20,    20,    20,
      20,    20,    14,    14,    20,    20,    14,    20,    14,    14,
      20,    14,    14,    14,    14,    22,    20,    14,    -1,   243,
      -1,    20,    20,    14,    20,    20,    20,    14,    20,    14,
      20,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    -1,    -1,    -1,  1925,   243,    14,
      20,    20,    20,    20,    20,    14,    14,    20,    14,    20,
      20,    14,    14,    20,    14,    20,    14,    14,    -1,    20,
      14,    20,    14,    14,    20,    20,    14,    14,    14,    14,
      20,    14,    14,    14,    14,   571,    20,    14,    14,    -1,
      14,    20,    20,    14,    14,    20,    14,    20,    20,    14,
      14,    14,    14,    20,    20,    14,    14,    14,    -1,    20,
      20,    14,    14,  1991,    20,  1993,    20,  1995,    14,  1997,
      20,  1999,    20,    20,    14,    20,  2004,  2005,    20,  2007,
    2008,  2009,  2010,    14,  2012,  2013,  2014,  2015,    20,    14,
      20,  2019,  2020,    20,    20,    14,    20,    20,  2229,    20,
    2028,  2029,    20,    20,  2032,    20,  2034,    20,  2036,    20,
    2038,  2039,  2040,  2041,    14,  2043,  2044,  2045,  2046,  2047,
    2048,    14,  2050,  2051,    14,  2053,  2054,  2055,  2056,  2026,
    2058,  2059,  2060,  2061,  2062,    20,  2064,    14,    20,    20,
      14,    20,    20,    -1,    20,    20,  2074,  2075,    20,    20,
    2078,    20,    20,  2081,  2082,    14,  2084,  2085,  2086,    20,
    2088,  2089,    20,    20,  2092,    20,    20,    20,    14,    14,
      20,    14,    14,  2101,  2102,    14,  2104,    14,  2106,    20,
    2108,    14,  2110,  2111,    20,  2113,    20,  2115,  2116,  2117,
    2118,  2119,  2120,  2121,    20,  2123,  2124,  2125,  2126,  2127,
    2128,  2129,  2130,  2131,    20,  2133,  2134,  2135,  2136,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    14,  2147,
    2148,  2149,    14,  2151,    14,  2153,  2154,    14,    -1,    20,
      14,    20,    20,    14,    20,    20,    14,    20,    20,    14,
      20,    20,    14,    20,    20,    14,    20,    20,    14,    20,
      20,    14,    20,    20,    14,    20,    20,    14,    20,    20,
      14,    20,    20,    14,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2271,    -1,    -1,  2274,  2275,    -1,  2277,
    2278,    -1,  2280,  2281,    -1,  2283,  2284,  2285,    -1,  2287,
      -1,    -1,    -1,    -1,  2292,  2293,    -1,  2295,    -1,  2297,
    2298,  2299,  2300,  2301,    -1,  2303,  2304,  2305,  2306,  2307,
    2308,    -1,    -1,  2311,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2319,  2320,  2321,  2291,    -1,    -1,    -1,    -1,  2327,
    2328,    -1,    -1,  2331,    -1,  2333,  2334,    -1,  2336,    -1,
      -1,    -1,    -1,    -1,  2342,    -1,    -1,    -1,    -1,    -1,
      -1,  2349,  2350,  2351,    -1,  2353,    -1,  2355,    -1,    -1,
    2358,  2359,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,
      -1,    -1,    -1,     4,    -1,    -1,  2374,  2375,  2376,  2377,
    2378,    -1,    -1,    -1,    -1,    -1,  2384,  2385,  2386,    20,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2456,    -1,
      -1,  2459,  2460,  2461,    -1,    -1,    -1,  2465,    -1,    -1,
    2468,    -1,    -1,    -1,    -1,    -1,  2474,    -1,  2476,    -1,
    2478,    -1,    -1,  2481,  2482,    -1,  2484,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2493,  2494,    -1,  2496,    -1,
      -1,  2499,  2500,    -1,    -1,    -1,  2504,    -1,  2506,  2507,
      -1,  2509,  2510,    -1,    -1,  2513,  2514,    -1,  2516,    -1,
    2518,  2519,  2520,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2554,  2555,  2556,  2557,
    2558,    -1,    -1,    -1,  2562,  2563,  2564,    -1,  2566,  2567,
      -1,  2569,  2570,    -1,  2572,  2573,  2574,    -1,  2576,    -1,
    2578,  2579,  2580,   214,   215,  2583,  2584,  2585,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   243,    -1,    -1,    -1,  2614,    -1,    -1,    -1,
    2618,    -1,  2620,    -1,    -1,  2623,    -1,    -1,  2626,  2627,
    2628,  2629,  2630,    -1,  2632,  2633,    -1,  2635,  2636,    -1,
    2638,    -1,  2640,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   286,    -1,    -1,    -1,    -1,
    2658,  2659,  2660,    -1,    -1,    -1,    -1,  2665,  2666,  2667,
      -1,    -1,  2670,  2671,    -1,    -1,  2674,    -1,    -1,    -1,
      -1,    -1,    -1,   314,    -1,   316,   317,    -1,    -1,    -1,
    2688,    -1,  2690,    -1,  2692,    -1,    -1,  2695,    -1,    -1,
      -1,    -1,   333,    -1,    -1,    -1,  2704,  2705,  2706,  2707,
      -1,    -1,    -1,    -1,    -1,    -1,  2714,  2715,  2716,    -1,
      -1,    -1,    -1,  2721,  2722,  2723,    -1,    -1,    -1,    -1,
    2728,  2729,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   377,   378,   379,   380,
     381,   382,   383,   384,    -1,   386,   387,    -1,    -1,    -1,
      -1,    -1,   393,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   403,   404,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   418,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   433,   434,   435,   436,   437,   438,   439,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   454,   455,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   472,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,
      -1,    -1,    -1,    -1,   485,   486,   487,   488,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   514,   515,    -1,    -1,    -1,    -1,   520,
     521,    -1,   523,   524,    -1,   526,   527,    -1,   529,   530,
     531,   532,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   549,    -1,
     551,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   580,
     581,   582,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     591,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   665,   666,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   674,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   803,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   844,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   895,    -1,    -1,    -1,    -1,   900,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     214,   215,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   954,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   965,   966,    -1,    -1,    -1,    -1,
      -1,   972,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   993,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1019,    -1,
     314,    -1,   316,    -1,    -1,    -1,    -1,    -1,    -1,     0,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   333,
      -1,    -1,    -1,    -1,  1045,    -1,  1047,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    25,    -1,  1057,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1082,  1083,    -1,    -1,    -1,    -1,    -1,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1114,    -1,    -1,    -1,    -1,  1119,  1120,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1134,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     454,   455,    -1,    -1,    -1,    -1,    -1,  1168,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   485,    -1,    -1,    -1,    -1,    -1,    -1,  1199,    -1,
      -1,    -1,    -1,  1204,    -1,    -1,    -1,    -1,    -1,    -1,
    1211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     514,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1237,   531,   532,    -1,
     211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1251,    -1,  1253,    -1,    -1,    -1,    -1,    -1,    -1,  1260,
      -1,    -1,    -1,    -1,  1265,  1266,  1267,  1268,  1269,    -1,
      -1,    -1,   243,    -1,  1275,  1276,    -1,  1278,  1279,  1280,
    1281,  1282,  1283,    -1,    -1,    -1,    -1,    -1,  1289,    -1,
      -1,    -1,    -1,    -1,  1295,  1296,    -1,    -1,    -1,  1300,
    1301,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1357,    -1,    -1,    -1,
    1361,    -1,    -1,    -1,   335,   336,    -1,    -1,    -1,    -1,
      -1,   665,   666,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     674,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1406,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   385,    -1,    -1,   388,   389,   390,
     391,   392,    -1,   394,   395,   396,   397,   398,   399,   400,
     401,   402,    -1,    -1,   405,    -1,    -1,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,  1448,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,    -1,    -1,    -1,    -1,    -1,    -1,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,    -1,    -1,    -1,    -1,   456,   457,   458,    -1,    -1,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,    -1,    -1,    -1,   475,   476,   477,   478,    -1,   803,
     481,   482,   483,   484,    -1,    -1,    -1,    -1,   489,    -1,
     378,   379,   380,   381,   382,   383,   384,    -1,   386,   387,
      -1,    -1,    -1,    -1,    -1,   393,    -1,    -1,    -1,    -1,
      -1,    -1,   513,    -1,    -1,   403,   404,    -1,    -1,    -1,
     844,   522,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     418,    -1,  1563,   534,   535,   536,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   433,   434,   435,   436,   437,
     438,   439,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   895,    -1,    -1,    -1,    -1,   900,  1608,    -1,    -1,
      -1,    -1,    -1,    -1,   472,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   486,   487,
     488,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   515,    -1,    -1,
     954,    -1,   520,   521,    -1,   523,   524,    -1,   526,   527,
      -1,   529,   530,    -1,    -1,    -1,  1677,    -1,   972,    -1,
      -1,    -1,    -1,    -1,    -1,  1686,    -1,    -1,  1689,    -1,
      -1,    -1,    -1,   551,    -1,    -1,    -1,    -1,    -1,   993,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   580,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1746,    -1,    -1,    -1,    -1,
      -1,  1045,    -1,  1047,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1816,    -1,  1818,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1134,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1168,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1204,    -1,    -1,    -1,    -1,    -1,    -1,  1211,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1268,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1987,  1988,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1289,    -1,    -1,    -1,    -1,
      -1,  1295,  1296,    -1,    -1,    -1,    -1,  1301,    -1,    -1,
      -1,   982,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1000,
      -1,    -1,    -1,    -1,    -1,  1006,    -1,    -1,  1009,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2068,    -1,  2070,
    2071,    -1,  2073,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1064,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1073,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1084,  1085,  1086,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1096,    -1,    -1,    -1,    -1,
    1101,    -1,  1103,  1104,  1105,  1106,  1107,    -1,  1109,  1110,
      -1,    -1,    -1,    -1,  2145,    -1,    -1,    -1,    -1,  2150,
      -1,  2152,    -1,    -1,  1448,    -1,    -1,    -1,    -1,    -1,
      -1,  1019,  1133,    -1,    -1,    -1,  1137,  1138,  1139,  1140,
    1141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1190,
      -1,    -1,  1193,    -1,  1082,  1083,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1205,  1206,    -1,    -1,    -1,    -1,
      -1,    -1,  1213,    -1,  1215,  1216,  1217,  1218,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1114,    -1,    -1,    -1,
      -1,  1119,  1120,    -1,    -1,    -1,    -1,    -1,    -1,  1563,
      -1,    -1,    -1,    -1,    -1,  1246,  1247,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1256,    -1,    -1,    -1,    -1,
    1261,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1270,
      -1,  1272,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2338,    -1,    -1,
      -1,  1199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1237,
      -1,  2382,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1362,  1363,  1251,    -1,  1253,    -1,    -1,    -1,    -1,
      -1,    -1,  1260,    -1,    -1,    -1,    -1,  1265,  1266,  1267,
      -1,  1269,    -1,    -1,    -1,    -1,    -1,  1275,    -1,    -1,
    1278,  1279,  1280,  1281,  1282,  1283,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1357,
      -1,    -1,    -1,  1361,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2517,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1406,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2582,    -1,    -1,    -1,    -1,    -1,    -1,  1559,    -1,
      -1,    -1,    -1,  1564,    -1,  1566,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2604,    -1,    -1,    -1,  1578,  1579,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2622,    -1,    -1,  2625,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1606,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1625,  1626,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1635,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1643,    -1,    -1,  2676,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1659,  1660,
    1661,  1662,  1663,  1987,  1988,    -1,  2697,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1691,  1692,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1608,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1738,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1686,    -1,
      -1,  1689,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1816,    -1,
    1818,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2026,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2050,
    2051,  2052,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2063,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2079,  2080,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2107,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2139,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2068,    -1,  2070,  2071,    -1,  2073,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2145,    -1,    -1,
      -1,    -1,  2150,    -1,  2152,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2291,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2310,
      -1,    -1,    -1,  2314,    -1,    -1,  2317,  2318,    -1,    -1,
      -1,  2322,  2323,  2324,  2325,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2339,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2354,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2338,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2488,    -1,    -1,
      -1,    -1,    -1,    -1,  2382,    -1,    -1,    -1,    -1,    -1,
      -1,  2502,    -1,    -1,    -1,    -1,    -1,  2508,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2571,    -1,    -1,    -1,  2575,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2517,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2668,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2693,    -1,  2582,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2604,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2622,    -1,    -1,  2625,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    10,    11,
      -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,  2676,    -1,
      -1,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    -1,  2697,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      52,    -1,    54,    55,    56,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    -1,    -1,    86,    87,    88,    89,    90,    91,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,    -1,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,    -1,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,    -1,    -1,    -1,
     162,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   207,   208,   209,   210,    -1,
      -1,    -1,    -1,   215,    -1,    -1,    -1,   219,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,   270,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   328,   329,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,    -1,   369,   370,   371,
     372,   373,    -1,    -1,    -1,    -1,    -1,   379,   380,   381,
     382,   383,   384,   385,   386,    -1,    -1,   389,   390,   391,
     392,   393,   394,   395,   396,   397,    -1,    -1,    -1,    -1,
     402,    -1,   404,   405,   406,    -1,    -1,    -1,   410,   411,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   424,   425,   426,   427,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   435,   436,    -1,   438,   439,   440,   441,
      -1,   443,   444,    -1,    -1,    -1,    -1,   449,   450,    -1,
      -1,    -1,   454,    -1,   456,   457,   458,   459,   460,    -1,
     462,   463,   464,   465,   466,   467,     9,    10,    11,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    51,    52,
      -1,    54,    55,    56,    -1,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    -1,    -1,    86,    87,    88,    89,    90,    91,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   105,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,    -1,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,    -1,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,    -1,    -1,    -1,   162,
     163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   207,   208,   209,   210,    -1,    -1,
      -1,    -1,   215,    -1,    -1,    -1,   219,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   269,   270,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   328,   329,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,    -1,   369,   370,   371,   372,
     373,    -1,    -1,    -1,    -1,    -1,   379,   380,   381,   382,
     383,   384,   385,   386,    -1,    -1,   389,   390,   391,   392,
     393,   394,   395,   396,   397,    -1,    -1,    -1,    -1,   402,
      -1,   404,   405,   406,    -1,    -1,    -1,   410,   411,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   424,   425,   426,   427,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   435,   436,    -1,   438,   439,   440,   441,    -1,
     443,   444,    -1,    -1,    -1,    -1,   449,   450,    -1,    -1,
      -1,   454,    -1,   456,   457,   458,   459,   460,    -1,   462,
     463,   464,   465,   466,   467,     9,    10,    11,    -1,    13,
      -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,    -1,    38,    39,    -1,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,
      54,    55,    56,    -1,    58,    -1,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   105,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,    -1,   131,    -1,   133,
     134,   135,   136,   137,   138,   139,   140,    -1,    -1,    -1,
     144,    -1,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,    -1,    -1,    -1,   162,   163,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   202,   203,
     204,    -1,    -1,   207,   208,   209,   210,   211,   212,   213,
     214,   215,    -1,    -1,   218,   219,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   236,   237,   238,   239,    -1,    -1,    -1,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,   257,   258,   259,    -1,    -1,   262,   263,
     264,   265,    -1,   267,   268,   269,   270,   271,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   327,   328,   329,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,    -1,   369,    -1,   371,   372,    -1,
     374,    -1,    -1,    -1,    -1,   379,   380,   381,   382,   383,
     384,   385,   386,    -1,    -1,   389,   390,   391,   392,   393,
     394,   395,   396,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     424,   425,   426,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   438,   439,   440,   441,    -1,   443,
     444,    -1,   446,   447,   448,   449,   450,    -1,   452,   453,
      -1,   455,   456,   457,   458,     9,    10,    11,    -1,    13,
      -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,    -1,    38,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,
      54,    55,    56,    -1,    58,    -1,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   105,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,    -1,   131,    -1,   133,
     134,   135,   136,   137,   138,   139,   140,    -1,    -1,    -1,
     144,    -1,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,    -1,    -1,    -1,   162,   163,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   207,   208,   209,   210,    -1,    -1,    -1,
      -1,   215,    -1,    -1,    -1,   219,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   236,   237,   238,   239,    -1,    -1,    -1,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,   257,   258,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   269,   270,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   328,   329,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,    -1,   369,    -1,   371,   372,    -1,
      -1,    -1,    -1,    -1,    -1,   379,   380,   381,   382,   383,
     384,   385,   386,    -1,    -1,   389,   390,   391,   392,   393,
     394,   395,   396,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     424,   425,   426,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   438,   439,   440,   441,    -1,   443,
     444,    -1,    -1,    -1,    -1,   449,   450,     9,    10,    11,
      -1,    13,   456,   457,   458,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    35,    -1,    -1,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,
      -1,    -1,    54,    55,    56,    -1,    58,    -1,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,    -1,   131,
      -1,   133,   134,   135,   136,   137,   138,   139,   140,    -1,
      -1,    -1,   144,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,    -1,    -1,    -1,
     162,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   207,   208,   209,   210,    -1,
      -1,    -1,    -1,   215,    -1,    -1,    -1,   219,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   236,   237,   238,   239,    -1,    -1,
      -1,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,    -1,    -1,   257,   258,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,   270,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   328,   329,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,    -1,   369,    -1,   371,
     372,    -1,    -1,    -1,    -1,    -1,    -1,   379,   380,   381,
     382,   383,   384,   385,   386,    -1,    -1,   389,   390,   391,
     392,   393,   394,   395,   396,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   424,   425,   426,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   438,   439,   440,   441,
      -1,   443,   444,    -1,    -1,    -1,    -1,   449,   450,     9,
      10,    11,    -1,    13,   456,   457,   458,    -1,    -1,    -1,
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
      -1,    -1,   162,   163,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,   208,   209,
     210,    -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,   219,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   236,   237,   238,   239,
      -1,    -1,    -1,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,   257,   258,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,
     270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   328,   329,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,    -1,   369,
      -1,   371,   372,    -1,    -1,    -1,    -1,    -1,    -1,   379,
     380,   381,   382,   383,   384,   385,   386,    -1,    -1,   389,
     390,   391,   392,   393,   394,   395,   396,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   424,   425,   426,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   438,   439,
     440,   441,    -1,   443,   444,    -1,    -1,    -1,    -1,   449,
     450,     9,    10,    11,    -1,    13,   456,   457,   458,    -1,
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
      -1,    -1,    -1,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,
     208,   209,   210,    -1,    -1,    -1,    -1,   215,    -1,    -1,
      -1,   219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,   237,
     238,   239,    -1,    -1,    -1,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,    -1,    -1,   257,
     258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   269,   270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     328,   329,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
      -1,   369,    -1,   371,   372,    -1,    -1,    -1,    -1,    -1,
      -1,   379,   380,   381,   382,   383,   384,   385,   386,    -1,
      -1,   389,   390,   391,   392,   393,   394,   395,   396,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   424,   425,   426,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     438,   439,   440,   441,    -1,   443,   444,    -1,    -1,    -1,
      -1,   449,   450,     9,    10,    11,    -1,    13,   456,   457,
     458,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      -1,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    54,    55,
      56,    -1,    58,    -1,    60,    61,    62,    63,    64,    65,
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
      -1,    -1,    -1,    -1,    -1,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   207,   208,   209,   210,    -1,    -1,    -1,    -1,   215,
      -1,    -1,    -1,   219,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     236,   237,   238,   239,    -1,    -1,    -1,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,    -1,
      -1,   257,   258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   269,   270,   271,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   328,   329,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,    -1,   369,    -1,   371,   372,    -1,    -1,    -1,
      -1,    -1,    -1,   379,   380,   381,   382,   383,   384,   385,
     386,    -1,    -1,   389,   390,   391,   392,   393,   394,   395,
     396,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   424,   425,
     426,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   438,   439,   440,   441,    -1,   443,   444,    -1,
      -1,    -1,    -1,   449,   450,    -1,    -1,    -1,    -1,    -1,
     456,   457,   458,     9,    10,    11,    -1,    13,    -1,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      -1,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    54,    55,
      56,    -1,    58,    -1,    60,    61,    62,    63,    64,    65,
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
      -1,    -1,    -1,    -1,    -1,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   207,   208,   209,   210,    -1,    -1,    -1,    -1,   215,
      -1,    -1,    -1,   219,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     236,   237,   238,   239,    -1,    -1,    -1,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,    -1,
      -1,   257,   258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   269,   270,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   328,   329,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,    -1,   369,    -1,   371,   372,    -1,    -1,    -1,
      -1,    -1,    -1,   379,   380,   381,   382,   383,   384,   385,
     386,    -1,    -1,   389,   390,   391,   392,   393,   394,   395,
     396,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   424,   425,
     426,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   438,   439,   440,   441,    -1,   443,   444,    -1,
      -1,    -1,    -1,   449,   450,    -1,    -1,    -1,    -1,    -1,
     456,   457,   458,     9,    10,    11,    -1,    13,    -1,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      -1,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    54,    55,
      56,    -1,    58,    -1,    60,    61,    62,    63,    64,    65,
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
      -1,    -1,    -1,    -1,    -1,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   207,   208,   209,   210,    -1,    -1,    -1,    -1,   215,
      -1,    -1,    -1,   219,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     236,   237,   238,   239,    -1,    -1,    -1,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,    -1,
      -1,   257,   258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   269,   270,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   328,   329,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,    -1,   369,    -1,   371,   372,    -1,    -1,    -1,
      -1,    -1,    -1,   379,   380,   381,   382,   383,   384,   385,
     386,    -1,    -1,   389,   390,   391,   392,   393,   394,   395,
     396,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   424,   425,
     426,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   438,   439,   440,   441,    -1,   443,   444,    -1,
      -1,    -1,    -1,   449,   450,    -1,    -1,    -1,    -1,    -1,
     456,   457,   458,     9,    10,    11,    -1,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      -1,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    54,    55,
      56,    -1,    58,    -1,    60,    61,    62,    63,    64,    65,
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
      -1,    -1,    -1,    -1,    -1,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   207,   208,   209,   210,    -1,    -1,    -1,    -1,   215,
      -1,    -1,    -1,   219,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     236,   237,   238,   239,    -1,    -1,    -1,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,    -1,
      -1,   257,   258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   269,   270,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   328,   329,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,    -1,   369,    -1,   371,   372,    -1,    -1,    -1,
      -1,    -1,    -1,   379,   380,   381,   382,   383,   384,   385,
     386,    -1,    -1,   389,   390,   391,   392,   393,   394,   395,
     396,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   424,   425,
     426,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   438,   439,   440,   441,    -1,   443,   444,    -1,
      -1,    -1,    -1,   449,   450,     9,    10,    11,    -1,    13,
     456,   457,   458,    -1,    -1,    -1,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,    -1,    38,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,
      54,    55,    56,    -1,    58,    -1,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    78,    -1,    80,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   105,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,    -1,   131,    -1,   133,
     134,   135,   136,   137,   138,   139,   140,    -1,    -1,    -1,
     144,    -1,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,    -1,    -1,    -1,   162,   163,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   207,   208,   209,   210,    -1,    -1,    -1,
      -1,   215,    -1,    -1,    -1,   219,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   236,   237,   238,   239,    -1,    -1,    -1,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,   257,   258,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   269,   270,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   328,   329,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,    -1,   369,    -1,   371,   372,    -1,
      -1,    -1,    -1,    -1,    -1,   379,   380,   381,   382,   383,
     384,   385,   386,    -1,    -1,   389,   390,   391,   392,   393,
     394,   395,   396,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     424,   425,   426,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   438,   439,   440,   441,    -1,   443,
     444,    -1,    -1,    -1,    -1,   449,   450,     9,    10,    11,
      -1,    13,   456,   457,   458,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    35,    -1,    -1,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,
      -1,    -1,    54,    55,    56,    -1,    58,    -1,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    78,    -1,    80,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,    -1,   131,
      -1,   133,   134,   135,   136,   137,   138,   139,   140,    -1,
      -1,    -1,   144,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,    -1,    -1,    -1,
     162,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   207,   208,   209,   210,    -1,
      -1,    -1,    -1,   215,    -1,    -1,    -1,   219,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   236,   237,   238,   239,    -1,    -1,
      -1,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,    -1,    -1,   257,   258,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,   270,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   328,   329,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,    -1,   369,    -1,   371,
     372,    -1,    -1,    -1,    -1,    -1,    -1,   379,   380,   381,
     382,   383,   384,   385,   386,    -1,    -1,   389,   390,   391,
     392,   393,   394,   395,   396,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   424,   425,   426,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   438,   439,   440,   441,
      -1,   443,   444,    -1,    -1,    -1,    -1,   449,   450,     9,
      10,    11,    -1,    13,   456,   457,   458,    -1,    -1,    -1,
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
      -1,    -1,   162,   163,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,   208,   209,
     210,    -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,   219,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   236,   237,   238,   239,
      -1,    -1,    -1,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,   257,   258,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,
     270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   328,   329,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,    -1,   369,
      -1,   371,   372,    -1,    -1,    -1,    -1,    -1,    -1,   379,
     380,   381,   382,   383,   384,   385,   386,    -1,    -1,   389,
     390,   391,   392,   393,   394,   395,   396,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   424,   425,   426,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   438,   439,
     440,   441,    -1,   443,   444,    -1,    -1,    -1,    -1,   449,
     450,     9,    10,    11,    -1,    13,   456,   457,   458,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,
     208,   209,   210,    -1,    -1,    -1,    -1,   215,    -1,    -1,
      -1,   219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,   237,
     238,   239,    -1,    -1,    -1,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,    -1,    -1,   257,
     258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   269,   270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     328,   329,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
      -1,   369,    -1,   371,   372,    -1,    -1,    -1,    -1,    -1,
      -1,   379,   380,   381,   382,   383,   384,   385,   386,    -1,
      -1,   389,   390,   391,   392,   393,   394,   395,   396,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   424,   425,   426,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     438,   439,   440,   441,     9,   443,   444,    -1,    13,    -1,
      -1,   449,   450,    -1,    -1,    -1,    -1,    -1,   456,   457,
     458,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      35,    -1,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    54,
      55,    56,    -1,    58,    -1,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    -1,    78,    -1,    80,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,    -1,   131,    -1,   133,   134,
     135,   136,   137,   138,   139,   140,    -1,    -1,    -1,   144,
      -1,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,    -1,    -1,    -1,   162,   163,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   207,   208,   209,   210,    -1,    -1,    -1,    -1,
     215,    -1,    -1,    -1,   219,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   236,   237,   238,   239,    -1,    -1,    -1,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,   257,   258,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   269,   270,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   328,   329,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,    -1,   369,    -1,   371,   372,    -1,    -1,
      -1,    -1,    -1,    -1,   379,   380,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   424,
     425,   426,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   438,   439,   440,   441,    13,   443,   444,
      -1,    -1,    -1,    -1,   449,   450,    -1,    -1,    -1,    -1,
      -1,   456,   457,   458,    -1,    -1,    -1,    -1,    34,    35,
      -1,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    54,    55,
      56,    -1,    58,    -1,    60,    61,    62,    63,    64,    65,
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
      -1,    -1,    -1,    -1,    -1,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   207,   208,   209,   210,    -1,    -1,    -1,    -1,   215,
      -1,    -1,    -1,   219,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     236,   237,   238,   239,    -1,    -1,    -1,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,    -1,
      -1,   257,   258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   269,   270,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   328,   329,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,    -1,   369,    -1,   371,   372,    -1,    -1,    -1,
      -1,    -1,    -1,   379,   380,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   424,   425,
     426,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   438,   439,   440,   441,    -1,   443,   444,    -1,
      -1,    -1,    -1,   449,   450,    -1,    -1,    -1,    -1,    -1,
     456,   457,   458
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
      83,    86,    87,    88,    89,    90,    91,   105,   106,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   162,
     163,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     207,   208,   209,   210,   215,   219,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   269,
     270,   328,   329,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   369,   370,
     371,   372,   373,   379,   380,   381,   382,   383,   384,   385,
     386,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     402,   404,   405,   406,   410,   411,   424,   425,   426,   427,
     435,   436,   438,   439,   440,   441,   443,   444,   449,   450,
     454,   456,   457,   458,   459,   460,   462,   463,   464,   465,
     466,   467,   471,   472,   473,   474,   475,   476,   479,   480,
     481,   482,   486,   490,   491,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,   505,   506,   507,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   518,   519,   521,
     522,   523,   524,   525,   526,   527,    13,    61,    62,    63,
      64,    65,    66,    67,    69,    70,    71,    78,    80,    81,
     149,   150,   496,   500,   519,   523,   501,   501,   495,   516,
     492,   516,   492,   492,    13,    13,    13,    13,   494,   516,
     409,   496,   519,    56,    72,    73,    74,    75,   521,   496,
     516,   516,   494,    13,   494,    13,    13,    19,    19,    96,
      97,    13,    19,    19,   116,   521,    19,   164,    19,    15,
      95,    15,    61,    62,    63,    64,    65,    66,    67,    69,
      70,    71,    77,    78,    79,    80,    81,   496,   519,   523,
     525,   527,   494,    13,    13,   501,   501,    13,    13,    15,
      13,    13,    15,    13,    15,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    19,    19,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    15,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
     501,   501,   501,   501,   501,   501,   501,   501,   501,   501,
     501,   501,   501,   501,   521,   487,   488,    80,   527,   492,
     473,   494,   494,    13,    13,    13,    13,    76,   521,   521,
      13,    13,    13,    13,    13,    19,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,     0,     0,   473,
     474,   475,   476,   479,   480,   481,   482,   473,    19,    13,
      19,    95,   105,   106,   114,    15,     7,     8,    12,    10,
      11,     5,     6,   110,   111,   112,   113,    17,    18,   108,
       4,    21,   109,    96,    97,    98,    99,   116,    19,    95,
      95,   116,    13,    19,    19,    19,    19,    15,    15,    19,
      19,    13,    19,    19,    14,    14,   494,   492,   494,   495,
     494,   527,   527,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   272,   302,
     332,   333,   334,   335,   336,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   442,   461,   272,
     273,   274,   276,   278,   279,   286,   289,   290,   291,   292,
     293,   294,   295,   296,   326,   330,   335,   336,   346,   351,
     352,   519,   519,   492,   331,    46,    47,   375,   376,   377,
     378,   374,   521,    46,   167,   492,   271,   492,    15,   492,
     492,   493,   516,   493,   516,   493,   493,   493,   493,   493,
     493,   496,   493,   493,   496,   496,   496,   496,   496,   493,
     496,   496,   496,   496,   496,   496,   496,   496,   496,   493,
     493,   496,   159,   160,   161,   159,   160,   161,   496,   496,
     496,   496,   496,   496,   496,   496,   496,   496,   493,   496,
     496,   496,   496,   496,   496,   496,   496,   496,   496,   496,
     496,   496,   496,   493,   496,   493,   493,   493,   493,   493,
     493,   496,   496,   496,   496,   496,   496,   496,   496,   496,
     496,   496,   496,   519,   519,   494,   494,   496,   496,   496,
      56,    56,   496,   496,   496,   496,   496,   496,   496,   496,
     496,   496,   496,   493,   492,   492,   496,   492,   496,   496,
     496,   492,   516,   496,   496,   496,   496,   494,   493,   493,
     493,   496,   116,   401,    57,   487,   487,   473,   521,   527,
     494,   493,    56,   478,   477,    22,   487,   493,   493,   496,
     493,   493,   445,   493,   493,   492,   493,   493,   494,   494,
      65,   496,   496,   496,   473,   423,   492,   516,    53,    54,
      92,   130,   159,   164,   167,   168,   169,   170,   199,   200,
     201,   331,   332,   337,   350,   368,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   493,   500,
     502,   502,   502,   503,   503,   505,   505,   505,   505,   506,
     506,   507,   509,   510,   511,   513,   512,   515,   515,   515,
     515,   515,   164,   165,   166,   167,   197,   205,   216,   217,
     220,   263,   265,   266,   267,   276,   277,   282,   283,   284,
     285,   297,   298,   299,   300,   301,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   451,   202,
     203,   204,   211,   212,   213,   214,   218,   259,   262,   263,
     264,   265,   267,   268,   271,   446,   447,   448,   452,   453,
     455,   519,   520,   271,   493,    17,    38,    41,    65,    69,
      71,    79,   271,   327,   358,   361,   374,   516,   517,   519,
     520,   524,    17,    69,   484,   516,   519,   525,    84,   492,
     492,   492,   500,    20,    14,    14,    20,    20,    14,    14,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    20,
      13,   492,   494,   516,   494,    13,    13,    13,   494,    16,
      15,    16,   492,    14,    20,    14,    14,    20,    16,    14,
      14,    16,    14,    16,    20,    20,    20,    14,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      14,    20,    20,    20,    20,    13,    13,    14,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    14,    14,
      14,    20,    14,    20,    20,    20,    20,    20,    14,    20,
      20,    14,    20,    14,    20,    16,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    14,    20,    20,
      20,    20,    20,    20,    20,    14,    14,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    14,    14,    14,    20,    20,    14,    14,
      14,    20,    14,    14,    14,    14,    14,    14,    20,    20,
      20,    14,   492,   483,   494,   489,   408,   473,    14,    14,
      14,    20,    14,    13,    13,   437,   473,    14,    20,    20,
      20,    20,    20,    13,    14,    20,    14,    20,    20,    20,
      14,    14,    14,    20,    20,    20,    20,    20,    22,    23,
      14,    13,    13,    13,   494,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    16,    22,   494,    13,    13,    13,
     494,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,   494,    13,    13,
      13,    13,    13,    13,    19,    15,   516,   525,    15,    13,
      19,    15,    13,    13,    13,    13,    20,    19,   527,    14,
      20,    13,    16,    16,   494,   492,   492,   492,   496,   492,
     492,   492,   492,   492,   496,   492,   492,    65,   496,    58,
      65,   492,   492,   492,   492,   492,   492,   492,   493,   492,
      69,   492,    76,   492,   492,   520,   492,   492,   492,   492,
     492,   519,    69,   517,    69,    58,   492,   492,   492,   492,
     492,   494,    61,    64,   494,   116,   492,   116,    16,    76,
     516,    13,    13,    13,    56,   496,   492,   492,   492,   492,
     492,   492,   492,   496,   492,   492,   492,   492,   492,   492,
     492,   493,   493,   496,   496,   496,   492,   492,   492,   492,
     492,   492,   492,   492,   496,   492,   496,   496,   496,   496,
     496,   496,   496,   496,   492,   493,    13,   492,   492,   492,
     493,   493,   492,   492,   492,   492,   492,   492,   492,   492,
     492,   492,   492,   496,   494,   496,   496,   496,   496,   496,
     492,   492,   492,   492,   492,   492,   492,   492,   492,   492,
     492,   492,   492,   492,   494,   492,   492,   398,    20,   487,
     487,   492,   428,   429,   430,   431,   432,   434,   485,   485,
      77,   492,   492,   496,   492,   492,   496,   492,   492,   492,
     493,   492,   494,   496,   496,   492,   492,   492,   494,   492,
     496,   496,   496,   492,   496,   492,   496,   492,   492,   492,
     492,   492,   514,   492,   492,   492,   492,   492,   492,   492,
     492,   492,   493,   492,   492,   492,   492,   492,   492,   492,
     492,   496,   496,    14,    14,    14,   493,   492,   493,   492,
     492,   496,   492,   492,   492,   493,   496,   519,   519,   519,
     493,   493,   493,   494,   493,   496,   519,   496,   519,   519,
     493,    14,   493,   493,   493,   493,   493,   493,   206,   492,
     492,   494,   325,   492,    79,   492,   492,   494,   494,    17,
     516,   525,   494,    20,    20,    14,    20,    20,    20,    20,
      20,    14,    20,    14,    20,    14,    14,    14,    20,    20,
      20,    20,    20,    14,    14,    20,    20,    20,    20,    14,
      20,    14,    20,    14,    20,    14,    14,    20,    20,    20,
      20,    14,    19,    14,    20,    14,    20,    20,    20,    14,
      14,    20,    14,    14,    14,    20,   520,    16,   493,    14,
      14,   493,   496,   496,    14,    20,    20,    20,    14,    14,
      14,    14,    20,    14,    14,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    14,    14,    20,    20,
      20,    20,    20,    20,    14,    14,    20,    14,   493,    14,
      14,    14,    20,    20,    20,    20,    14,    20,    20,    20,
      14,    20,    14,    14,    14,    14,    20,    14,    14,    20,
      20,    20,    20,    20,    20,    14,    14,    14,    14,    14,
      14,    14,    14,    20,    20,    20,    20,    14,    20,    20,
      20,   492,   494,   473,   473,    20,    59,    59,    59,    59,
      59,    59,    14,    20,    14,   487,    14,    20,    20,    14,
      20,    20,    14,    14,    20,    14,    20,    14,    20,    20,
      14,    20,    23,    20,    14,    14,    20,    14,    20,    14,
      14,    20,    14,    20,    14,    14,    14,    20,    20,    20,
      14,    20,    14,    14,    14,    14,    14,    14,    20,    14,
      14,    20,    14,    20,    14,    20,    20,    20,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    20,    20,    14,
      14,    20,    14,    14,    14,    14,    20,    20,    20,    20,
      20,    20,    14,    20,    20,    20,    14,    20,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    20,    20,    13,
      16,    16,    14,    16,    20,    14,    14,    20,   527,    14,
     494,   492,   496,   496,   492,   492,   492,   492,   492,   492,
     496,   496,   492,   492,   492,   492,   492,   492,   492,   492,
     492,   492,   492,   492,   492,   492,   492,   496,   492,   493,
     492,    56,    14,    14,    14,    20,   495,   496,    56,   496,
     492,   492,   496,   492,   492,   492,   492,   492,   492,   492,
     492,   496,   492,   492,   492,   492,   492,   492,   492,   492,
     492,   492,   492,   492,   492,   496,   496,   496,   496,   496,
     492,    14,   492,   492,   492,   492,   492,   516,   492,   492,
     492,   493,   493,   492,   496,   496,   492,   492,   492,   492,
     492,   492,   492,   492,   492,   399,   487,   492,   487,   428,
     429,   430,   431,   432,   434,   487,   473,   492,   492,   492,
     492,   492,   492,   496,   492,   492,   492,   492,   516,   492,
     492,   492,   492,   492,   492,   492,   492,   492,   492,   492,
     492,   492,   492,   492,   492,   492,   492,   492,   492,   492,
     492,   492,   492,   492,   492,   492,   492,   492,   492,   492,
     492,   492,   493,   492,   493,   492,    79,    20,    20,    56,
      14,    20,    14,    20,    14,    20,    14,    20,    14,    20,
      14,    14,    14,    14,    20,    20,    14,    20,    20,    20,
      20,    14,    20,    20,    20,    20,    14,    14,    14,    20,
      20,    14,   492,    14,    19,    14,    20,    20,    20,    20,
      14,    14,    20,    14,    20,    14,    20,    14,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    20,    20,    14,
      20,    20,    20,    20,    20,    20,    20,    14,    20,    20,
      20,    20,    20,    20,    20,    14,    14,    14,    20,    14,
      20,    20,    14,    20,    20,    20,    14,    14,    20,    20,
      20,    20,    20,    14,    20,    20,    20,    14,    20,    20,
     492,   473,    20,   473,    59,    59,    59,    59,    59,    59,
     473,    20,    20,    14,    20,    14,    20,    20,    20,    14,
      20,    23,    14,    22,    14,    20,    20,    20,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    14,    14,    20,
      14,    14,    14,    14,    14,    20,    14,    20,    20,    20,
      20,    20,    20,    20,    20,   494,   494,    14,   492,   492,
     492,   492,   492,   492,   492,   492,   492,   492,   492,   492,
     492,   492,   492,   492,   492,    14,   495,    56,   492,   492,
     492,   492,   492,   492,   492,   492,   492,   492,   492,   492,
     492,   492,   492,    22,    65,   492,   496,   528,   492,   528,
     492,   528,   492,   492,   492,   492,   492,   492,   492,   492,
     492,   496,   492,   493,   493,   493,   493,   492,   492,   492,
     496,   496,   492,   492,   492,   492,   492,   492,   492,   487,
     492,   492,   492,   492,   492,   496,   492,   492,   492,   492,
     492,   492,   492,   492,   492,   492,   492,   492,   492,   492,
     492,   492,   492,   492,   492,   492,   492,   492,   492,   492,
     496,   493,   492,   492,   492,   493,   492,   493,   492,   492,
      14,    20,    14,    14,    20,    20,    14,    20,    20,    14,
      20,    20,    14,    20,    20,    20,    14,    20,    14,    14,
      14,    20,    20,    20,    14,    20,    14,    20,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    20,    20,    20,
      20,    22,    19,    14,    20,    14,    14,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    14,    20,    20,    14,
      14,    20,    14,    20,    20,    14,    20,    14,    20,    20,
      14,    14,    20,    14,    14,    14,    14,    14,   473,    20,
      20,    20,    14,    20,    20,    20,    14,    14,    20,    20,
      14,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    20,    20,    20,    20,    20,    14,
      14,    14,    20,    14,    20,    20,    20,    14,    14,   492,
     492,   492,   492,   492,   492,   492,   492,   492,   492,   492,
     495,   492,   492,   492,   492,   492,   492,   492,   492,   492,
     492,   492,   492,   492,   492,    22,   528,   492,    93,   528,
     528,   528,   492,   492,   492,   496,   496,   496,   496,   492,
     492,   492,   492,   492,   492,   493,   496,   492,   492,   492,
     492,   492,   496,   492,   492,   492,   492,   492,   492,   492,
     492,   493,   492,   492,   492,    14,    20,    14,    14,    20,
      20,    20,    14,    14,    14,    20,    14,    14,    20,    14,
      14,    14,    14,    14,    20,    14,    20,    14,    20,    14,
      14,    20,    20,    14,    20,    14,    14,    14,    20,    14,
      14,    14,    14,    20,    20,    14,    20,    14,    14,    20,
      20,    14,    20,    14,    20,    14,    20,    20,    20,    20,
      22,    14,    14,    20,    20,    14,    20,    20,    20,    20,
      20,   492,   492,   492,   492,   492,   492,   492,   492,   492,
     492,   492,   492,   528,   492,   492,   492,   492,   492,   496,
     492,   492,   492,   496,   492,   492,   492,   492,   492,   493,
     492,   492,   492,    14,    20,    20,    20,    20,    20,    14,
      14,    14,    20,    22,    22,    14,    20,    20,    14,    20,
      20,    20,    20,    20,    20,    20,    20,    14,    20,    20,
      20,    14,    20,    20,    20,    20,   492,   492,   492,   492,
     492,   492,   492,   492,   492,   492,   492,   492,   496,   492,
     492,   492,   496,   492,   116,   492,   492,   492,   493,   492,
     492,   492,    14,    14,    20,    14,    14,    14,    20,    14,
      20,    14,    20,    20,    14,    20,    20,    20,    20,    20,
      20,   493,    20,    20,    14,    20,    20,    14,    20,    14,
      20,   492,   492,   492,   493,   492,   493,   492,   492,   492,
     492,   492,   492,   492,   492,   492,   492,   492,    20,    22,
      20,    14,    14,    14,    14,    20,    20,    20,    20,    14,
      20,    20,    14,    14,    20,    14,    20,   492,   492,   492,
     492,   492,   492,   496,   492,   492,   492,   493,    20,    14,
      20,    14,    20,    20,    14,    20,    14,    20,   492,   492,
     492,   496,   492,   493,    20,    20,    20,    20,    14,    14,
     492,   492,   492,   492,    20,    20,    20,    14,   492,   492,
     492,    20,    20,    20,   492,   492,   492,    14,    20,    20,
     492,   492,    14,    14
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
     675,   676,   677,   678,   679,   680,   681,   682,   683,   684,
     685,   686,   687,   688,   689,   690,   691,   692,   693,   694,
     695,   696,   697,   698,   699,   700,   701,   702,   703,   704,
     705,   706,   707,   708,   709,   710,   711,   712,   713,   714,
     715,   716,   717,   718,   719,   720,   721,   722,   723,   724
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  Parser::yyr1_[] =
  {
         0,   470,   471,   471,   472,   472,   472,   472,   472,   472,
     472,   472,   472,   472,   472,   472,   472,   472,   472,   472,
     473,   473,   474,   474,   474,   474,   474,   475,   475,   477,
     476,   478,   476,   479,   479,   480,   481,   481,   481,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   483,   483,   484,   484,
     484,   484,   484,   484,   484,   485,   485,   485,   485,   485,
     485,   485,   485,   485,   485,   485,   485,   485,   486,   486,
     486,   486,   486,   486,   486,   487,   488,   489,   490,   491,
     491,   491,   491,   491,   491,   491,   491,   491,   491,   491,
     491,   491,   491,   491,   491,   491,   491,   491,   491,   491,
     491,   491,   491,   491,   491,   491,   491,   491,   491,   491,
     491,   491,   491,   491,   491,   491,   491,   491,   491,   491,
     491,   491,   491,   491,   491,   491,   491,   491,   491,   491,
     491,   491,   491,   491,   491,   491,   491,   491,   491,   491,
     491,   491,   492,   493,   494,   495,   495,   495,   495,   495,
     495,   495,   495,   495,   495,   495,   495,   496,   496,   497,
     497,   497,   497,   497,   497,   497,   497,   497,   497,   497,
     497,   497,   497,   497,   497,   497,   497,   497,   497,   497,
     497,   497,   497,   497,   497,   497,   497,   497,   497,   497,
     497,   497,   497,   497,   497,   497,   497,   497,   497,   497,
     497,   497,   497,   497,   497,   497,   497,   497,   497,   497,
     497,   497,   497,   497,   497,   497,   497,   497,   497,   497,
     497,   497,   497,   497,   497,   497,   497,   497,   497,   497,
     497,   497,   497,   497,   497,   497,   497,   497,   497,   497,
     497,   497,   497,   497,   497,   497,   497,   497,   497,   497,
     497,   497,   497,   497,   497,   497,   497,   497,   497,   497,
     497,   497,   497,   497,   497,   497,   497,   497,   497,   497,
     497,   497,   497,   497,   497,   497,   497,   497,   497,   497,
     497,   497,   497,   497,   497,   497,   497,   497,   497,   497,
     497,   498,   499,   499,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   501,   501,   501,   501,   501,
     501,   501,   502,   502,   502,   502,   502,   502,   502,   502,
     502,   502,   502,   502,   502,   502,   502,   502,   502,   502,
     502,   503,   503,   503,   503,   504,   504,   504,   505,   506,
     506,   506,   506,   506,   507,   507,   507,   508,   508,   509,
     510,   510,   511,   511,   512,   512,   513,   513,   514,   514,
     515,   515,   515,   515,   515,   515,   516,   517,   517,   517,
     517,   518,   518,   518,   519,   519,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   521,   522,   522,   523,   523,   523,   523,
     523,   523,   524,   524,   524,   524,   524,   524,   524,   524,
     525,   525,   526,   526,   526,   526,   526,   526,   526,   526,
     527,   527,   528,   528,   528,   528,   528
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
       6,     3,     3,     6,     6,     8,     6,     8,     8,     8,
       3,     1,     1,     2,     2,     1,     1,     2,     8,     4,
       4,     1,     2,     2,     2,     3,     8,    16,     2,     6,
       2,     2,     5,     2,     1,     1,     2,     2,     2,     2,
       2,     2,     4,     4,     2,     2,     2,     4,     3,    10,
       6,     3,     6,     6,     8,    28,     8,     8,     3,     8,
      12,     6,     6,    16,     8,    16,    10,     6,    10,     8,
      10,    14,     8,    12,     6,     8,     6,     6,     3,     3,
       2,     3,     6,    10,     6,    10,    10,    12,     6,     6,
       3,     3,     3,     3,     4,     3,     6,     6,     4,     4,
       6,    10,    10,    10,     6,     6,     6,     6,     6,    10,
       6,    10,     6,     6,     6,     3,     6,     6,    10,    10,
       6,     6,     6,     3,     3,     3,     3,     6,     6,     3,
       6,     6,     8,    10,     3,     6,     3,     4,    20,     6,
      10,     6,     3,     3,     6,     3,     6,     8,     6,     6,
       8,    16,     6,     3,     6,     8,     3,    12,    12,    12,
      10,     3,     3,     8,     8,    10,     8,    10,    12,     6,
       8,    10,    16,    18,    12,     6,    18,    16,    12,    10,
      10,    10,     6,    10,     6,     6,     6,     8,     4,     4,
       8,     4,    18,     4,     1,     1,     1,     6,     3,     4,
       1,     1,     1,    30,    24,     8,     1,     3,     0,     1,
       3,     2,     4,     1,     3,     0,     2,     2,     2,     2,
       2,     2,     4,     4,     4,     4,     4,     4,     1,     6,
       1,     3,     4,     4,     1,     3,     0,     0,     1,     1,
       1,     1,     1,     1,     6,     8,    10,    10,    10,     8,
       6,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     6,     4,    10,     4,    10,
       4,     4,     4,     4,     4,     4,     7,     7,     7,     9,
       7,     6,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     6,    10,     4,     4,     4,     3,     6,     6,
       6,     3,     1,     1,     1,     1,     1,     1,     1,     1,
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
       4,     6,     6,    12,    30,     8,     5,     6,     5,     5,
       6,     6,     4,     6,     4,     6,     4,     4,    18,     8,
       6,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     6,     4,     3,     1,     2,     2,     2,     4,
       2,     4,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     3,     3,     3,     1,     3,     3,     1,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     1,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     5,
       1,     3,     3,     3,     3,     3,     1,     1,     3,     8,
       4,     6,     1,     4,     1,     4,     6,     6,     8,     8,
       4,     6,     6,     6,     6,     3,     2,     1,     4,     6,
       1,     4,     4,    10,     6,    16,    18,    10,    20,    14,
       8,     4,     6,     8,     8,    12,    16,    16,    18,    14,
      14,    16,    20,     1,     1,     1,     1,     1,     1,     1,
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
  "T_SNR", "T_info", "T_NbPoints", "T_NbPolys", "T_save", "T_normalize",
  "T_OrientField", "T_OrientPositive", "T_2DFlux", "T_OutFlux",
  "T_OutFluxScalar", "T_OrientationRatio", "T_Skeleton", "T_SimplePoints",
  "T_CircleIntegral", "T_CircleIntegralExc", "T_CircleIntSdExc",
  "T_CircleMinIntSdExc", "T_LocalExtrema", "T_NormalField",
  "T_DirConnectivity", "T_eccentricity", "T_rot2D", "T_mean", "T_SUM",
  "T_localmean", "T_localmean2", "T_localSD", "T_localSD2",
  "T_struct_tensor", "T_StructTensorH", "T_HessianMatrix", "T_HessianEVal",
  "T_Derivatives", "T_curvatures", "T_Laplacian", "T_setvoxelsize",
  "T_settranslation", "T_setendianness", "T_Skeleton2lines",
  "T_SmoothLines", "T_ResampleLines", "T_RemoveLine", "T_ConnectLines",
  "T_threscross", "T_IsocontourPoints", "T_IsosurfDist",
  "T_vtkIsoContourDist", "T_ShortestPath", "T_ShortestPathImage",
  "T_PathFromDispl", "T_PathFromVectField", "T_LineRecons",
  "T_GetNumberOfLines", "T_GetLine", "T_ReadCTALine", "T_ReadCTALineRadii",
  "T_WriteCTALine", "T_SetIsoContour", "T_SetIsoContourParam",
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
  "T_vtkDecimate", "T_vtkMarchingCubes", "T_vtkSmooth", "T_Recompute",
  "T_vtkWindowedSinc", "T_isoline", "T_vtkDist", "T_AndreDist",
  "T_Surface", "T_getimage", "T_GetImageFromX", "T_rotate", "T_computeCC",
  "T_drawCC", "T_setminCC", "T_addobj", "T_setcurrentobj", "T_writeVRML",
  "T_writeVTK", "T_OwnMaterial", "T_SetColor", "T_SetColors",
  "T_SetColorOpacity", "T_Paint", "T_SetLight", "T_SetLightPos",
  "T_SetLightAmbient", "T_SetLightDiffuse", "T_SetLightSpecular",
  "T_SetBackground", "T_Normalize", "T_Center", "T_Remove",
  "T_SwapBuffers", "T_SetAmbient", "T_SetDiffuse", "T_SetSpecular",
  "T_SetShininess", "T_SetOpacity", "T_SetOpacityImage", "T_SetVisible",
  "T_SetColorMaterial", "T_Statistics", "T_GetIntensities",
  "T_GetLinesLength", "T_GetLinesExtremities", "T_GetConnections",
  "T_SelectLines", "T_RemoveSelection", "T_mergepoints", "T_Triangulate",
  "T_Displace", "T_Normals", "T_InvertNormals", "T_Translate", "T_Scale",
  "T_SetPointsColors", "T_SetLineWidth", "T_AddPoint", "T_NewLine",
  "T_EndLine", "T_LineAddPointNumber", "T_GetTransform", "T_SetTransform",
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
  "T_GeoCoordinates", "T_ElevateMesh", "T_CreateVectors",
  "T_CreateVectorsFromField", "T_Set3DArrowParam", "T_CreateEllipsoids",
  "T_ComputeAltitudes", "T_Temp2Altitudes", "T_ReadFlow",
  "T_SetFluidNavFile", "T_DrawEarthCoord", "T_PaintCallback",
  "T_SaveStructuredGrid", "T_import_vtk", "T_import_wii",
  "T_import_filters", "T_amiOFCorr2D", "T_amiOFVar2D", "prefix", "postfix",
  "$accept", "start", "list_commands", "end_instr", "loop_inst",
  "cond_inst", "proc_decl", "$@1", "$@2", "class_decl", "object_decl",
  "func_inst", "command", "exprstringlist", "param_list",
  "param_list_decl", "primary_expr_string", "instr_block", "begin_block",
  "end_block", "double_variable", "float_variable", "expr", "expr_image",
  "expr_string", "basic_type", "var_image", "image", "image_variable",
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
       471,     0,    -1,    -1,   472,     0,    -1,   473,    -1,   472,
     473,    -1,   482,   473,    -1,   472,   482,   473,    -1,   474,
      -1,   472,   474,    -1,   475,    -1,   472,   475,    -1,   481,
      -1,   472,   481,    -1,   476,    -1,   472,   476,    -1,   479,
      -1,   472,   479,    -1,   480,    -1,   472,   480,    -1,    37,
      -1,    23,    -1,   397,   521,   116,   492,   398,   492,   487,
     473,    -1,   397,   521,   116,   492,   398,   492,   399,   492,
     487,   473,    -1,   397,   521,   401,   483,   487,   473,    -1,
     402,   487,    -1,   404,   527,   487,    -1,   406,   492,   487,
     473,    -1,   406,   492,   487,   408,   487,   473,    -1,    -1,
     435,   521,   477,    13,   485,    14,   487,   473,    -1,    -1,
     435,    76,   478,    13,   485,    14,   487,   473,    -1,   436,
     521,   487,   473,    -1,   436,   521,    22,   437,    77,   487,
     473,    -1,    77,   521,    -1,   410,   494,   473,    -1,   410,
     473,    -1,   411,   494,    -1,   525,    -1,   516,    -1,    36,
      -1,   405,    -1,    86,    -1,    88,    -1,    89,    -1,    87,
      -1,    90,    13,   492,    14,    -1,    91,    13,   492,    20,
      76,    14,    -1,   521,   116,    17,   525,    -1,   521,   116,
      17,   516,    -1,   521,   116,   516,    -1,   521,   116,   516,
      20,   494,    -1,   521,   116,   524,    -1,   521,   116,   271,
      15,   492,    16,    -1,   521,    95,   271,    15,   492,    16,
      -1,   521,   116,    38,    15,   492,    16,    -1,   521,    95,
     493,    -1,    81,    15,   492,    16,   116,   493,    -1,   521,
     116,   517,    -1,    80,    15,   492,    16,   116,   520,    -1,
     521,   116,   520,    -1,   519,    95,   520,    -1,    80,    95,
     271,    15,   492,    16,    -1,   521,   116,   361,    13,   492,
      14,    -1,   521,   116,   361,    13,   492,    14,    20,   494,
      -1,   521,   116,   358,    13,   492,    14,    -1,   521,   116,
     358,    13,   492,    14,    20,   494,    -1,   521,   116,   374,
      13,   494,    20,    56,    14,    -1,    71,   116,   374,    13,
     494,    20,    56,    14,    -1,    71,    19,   378,    -1,    24,
      -1,    25,    -1,    26,   492,    -1,    27,   492,    -1,    29,
      -1,    30,    -1,    28,   492,    -1,    31,    13,   494,    20,
     494,    20,   494,    14,    -1,    32,    13,   492,    14,    -1,
      33,    13,   494,    14,    -1,    44,    -1,    42,   496,    -1,
      45,   496,    -1,    42,   519,    -1,   496,    95,   493,    -1,
     496,    19,    92,    13,   492,    20,   516,    14,    -1,   496,
      13,   492,    22,   492,    20,   492,    22,   492,    20,   492,
      22,   492,    14,   116,   493,    -1,    42,   409,    -1,   527,
      19,    84,    13,   494,    14,    -1,    82,   527,    -1,    83,
     494,    -1,    82,    80,    15,   492,    16,    -1,    51,   494,
      -1,    52,    -1,    43,    -1,    43,   521,    -1,    43,    75,
      -1,    43,    72,    -1,    43,    73,    -1,    43,    74,    -1,
      43,    56,    -1,    71,    19,    46,   494,    -1,    71,    19,
      47,   494,    -1,    46,   516,    -1,    47,   516,    -1,    48,
     494,    -1,    71,    19,    46,   492,    -1,    71,    19,   375,
      -1,    65,    19,   332,    13,   492,    20,   492,    20,   492,
      14,    -1,    65,    19,   333,    13,   492,    14,    -1,    65,
      19,   334,    -1,    65,    19,   335,    13,   496,    14,    -1,
      65,    19,   335,    13,    65,    14,    -1,    65,    19,   338,
      13,    65,    20,   496,    14,    -1,    65,    19,   442,    13,
     492,    20,   492,    20,   492,    20,   492,    20,   492,    20,
     492,    20,   492,    20,   492,    20,   492,    20,   492,    20,
     492,    20,   492,    14,    -1,    65,    19,   336,    13,    58,
      20,   496,    14,    -1,    65,    19,   339,    13,   492,    20,
     492,    14,    -1,    65,    19,   340,    -1,    65,    19,   341,
      13,   492,    20,   492,    14,    -1,    65,    19,   342,    13,
     492,    20,   492,    20,   492,    20,   492,    14,    -1,    65,
      19,   343,    13,   492,    14,    -1,    65,    19,   344,    13,
     492,    14,    -1,    65,    19,   345,    13,   492,    20,   492,
      20,   492,    20,   492,    20,   492,    20,   492,    14,    -1,
      65,    19,   346,    13,   492,    20,   492,    14,    -1,    65,
      19,   348,    13,   492,    20,   492,    20,   492,    20,   492,
      20,   492,    20,   492,    14,    -1,    65,    19,   347,    13,
     493,    20,   492,    20,   492,    14,    -1,    65,    19,   349,
      13,    69,    14,    -1,    65,    19,   221,    13,   492,    20,
     496,    20,   492,    14,    -1,    65,    19,   221,    13,   496,
      20,   492,    14,    -1,    65,    19,   222,    13,   492,    20,
     492,    20,   492,    14,    -1,    65,    19,   222,    13,   492,
      20,   492,    20,   492,    20,   492,    20,   492,    14,    -1,
      65,    19,   223,    13,   492,    20,   492,    14,    -1,    65,
      19,   224,    13,   492,    20,   492,    20,   492,    20,   492,
      14,    -1,    65,    19,   225,    13,   492,    14,    -1,    65,
      19,   226,    13,   492,    20,   492,    14,    -1,    65,    19,
     461,    13,    76,    14,    -1,    65,    19,   302,    13,   496,
      14,    -1,   496,    19,   159,    -1,   496,    19,   164,    -1,
      78,   164,    -1,   519,    19,   164,    -1,   496,    19,   350,
      13,   492,    14,    -1,   496,    19,   350,    13,   492,    20,
     492,    20,   492,    14,    -1,   496,    19,   331,    13,   492,
      14,    -1,   496,    19,   331,    13,   492,    20,   492,    20,
     492,    14,    -1,   496,    19,   332,    13,   492,    20,   492,
      20,   492,    14,    -1,   496,    19,   130,    13,   496,    20,
     492,    20,   492,    20,   492,    14,    -1,   496,    19,   130,
      13,   496,    14,    -1,   496,    19,    53,    13,   494,    14,
      -1,   149,    19,   160,    -1,   149,    19,   161,    -1,   150,
      19,   160,    -1,   150,    19,   161,    -1,   496,    19,   167,
     494,    -1,   496,    19,   168,    -1,   496,    19,   169,    13,
     496,    14,    -1,   496,    19,   170,    13,   496,    14,    -1,
     519,    19,   167,   494,    -1,   519,    19,   220,   494,    -1,
     519,    19,   282,    13,   492,    14,    -1,   519,    19,   297,
      13,   492,    20,   492,    20,   492,    14,    -1,   519,    19,
     298,    13,   492,    20,   492,    20,   492,    14,    -1,   519,
      19,   299,    13,   492,    20,   492,    20,   492,    14,    -1,
     519,    19,   300,    13,   492,    14,    -1,   519,    19,   301,
      13,   492,    14,    -1,   519,    19,   303,    13,   492,    14,
      -1,   519,    19,   304,    13,   492,    14,    -1,   519,    19,
     285,    13,   492,    14,    -1,   519,    19,   283,    13,   492,
      20,   492,    20,   492,    14,    -1,   519,    19,   319,    13,
     496,    14,    -1,   519,    19,   284,    13,   493,    20,   492,
      20,   492,    14,    -1,   519,    19,   284,    13,   493,    14,
      -1,   519,    19,   305,    13,   496,    14,    -1,   519,    19,
     312,    13,   492,    14,    -1,   519,    19,   313,    -1,   519,
      19,   197,    13,   492,    14,    -1,   519,    19,   314,    13,
     493,    14,    -1,   519,    19,   317,    13,   492,    20,   492,
      20,   492,    14,    -1,   519,    19,   318,    13,   492,    20,
     492,    20,   492,    14,    -1,   519,    19,   320,    13,   492,
      14,    -1,   519,    19,   205,    13,   492,    14,    -1,   519,
      19,   310,    13,   493,    14,    -1,   519,    19,   311,    -1,
     519,    19,   266,    -1,   519,    19,   315,    -1,   519,    19,
     316,    -1,   519,    19,   265,    13,   492,    14,    -1,   519,
      19,   267,    13,   492,    14,    -1,   519,    19,   263,    -1,
     519,    19,   277,    13,   492,    14,    -1,   519,    19,   276,
      13,   492,    14,    -1,   519,    19,   276,    13,   492,    20,
     492,    14,    -1,   519,    19,   321,    13,   492,    20,   492,
      20,   492,    14,    -1,   519,    19,   322,    -1,   519,    19,
     324,    13,   492,    14,    -1,   519,    19,   323,    -1,   459,
      13,   494,    14,    -1,   460,    13,    65,    20,   492,    20,
     492,    20,   492,    20,   492,    20,   492,    20,   492,    20,
     492,    20,   492,    14,    -1,   519,    19,   451,    13,   493,
      14,    -1,    69,    19,   274,    13,   492,    20,   492,    20,
     492,    14,    -1,    69,    19,   278,    13,   520,    14,    -1,
      69,    96,   519,    -1,    69,    97,   519,    -1,    69,    19,
     295,    13,   519,    14,    -1,    69,    19,   296,    -1,    69,
      19,   276,    13,   492,    14,    -1,    69,    19,   276,    13,
     492,    20,   492,    14,    -1,    69,    19,   279,    13,   492,
      14,    -1,    69,    19,   335,    13,    69,    14,    -1,    69,
      19,   336,    13,    58,    20,   496,    14,    -1,    69,    19,
     351,    13,   492,    20,   493,    20,   492,    20,   492,    20,
     492,    20,   492,    14,    -1,    69,    19,   352,    13,   492,
      14,    -1,    69,    19,   330,    -1,    69,    19,   326,    13,
     517,    14,    -1,    69,    19,   326,    13,   517,    20,   492,
      14,    -1,    69,    19,   286,    -1,    69,    19,   289,    13,
     492,    20,   492,    20,   492,    20,   492,    14,    -1,    69,
      19,   290,    13,   492,    20,   492,    20,   492,    20,   492,
      14,    -1,    69,    19,   291,    13,   492,    20,   492,    20,
     492,    20,   492,    14,    -1,    69,    19,   292,    13,   492,
      20,   492,    20,   492,    14,    -1,    69,    19,   293,    -1,
      69,    19,   294,    -1,    69,    19,   346,    13,   492,    20,
     492,    14,    -1,   192,    13,   496,    20,   492,    20,   492,
      14,    -1,   192,    13,   496,    20,   492,    20,   492,    20,
     493,    14,    -1,   193,    13,   496,    20,   492,    20,   492,
      14,    -1,   193,    13,   496,    20,   492,    20,   492,    20,
     493,    14,    -1,   193,    13,   496,    20,   492,    20,   492,
      20,   493,    20,   492,    14,    -1,   194,    13,   496,    20,
     492,    14,    -1,   194,    13,   496,    20,   492,    20,   516,
      14,    -1,   194,    13,   496,    20,   492,    20,   492,    20,
     493,    14,    -1,   196,    13,   496,    20,   492,    20,   492,
      20,   492,    20,   492,    20,   492,    20,   492,    14,    -1,
     196,    13,   496,    20,   492,    20,   492,    20,   492,    20,
     492,    20,   492,    20,   492,    20,   493,    14,    -1,   195,
      13,   496,    20,   492,    20,   492,    20,   493,    20,   492,
      14,    -1,   197,    13,   496,    20,   492,    14,    -1,   242,
      13,    56,    20,   496,    20,   496,    20,   496,    20,   496,
      20,   496,    20,   496,    20,   493,    14,    -1,   242,    13,
      56,    20,   496,    20,   496,    20,   496,    20,   496,    20,
     496,    20,   496,    14,    -1,   241,    13,    56,    20,   496,
      20,   496,    20,   496,    20,   493,    14,    -1,   241,    13,
      56,    20,   496,    20,   496,    20,   496,    14,    -1,   199,
      13,   496,    20,   492,    20,   492,    20,   492,    14,    -1,
     496,    19,   199,    13,   492,    20,   492,    20,   492,    14,
      -1,   496,    19,   199,    13,   496,    14,    -1,   496,    19,
     200,    13,   492,    20,   492,    20,   492,    14,    -1,   496,
      19,   200,    13,   496,    14,    -1,   496,    19,   201,    13,
     492,    14,    -1,   132,    13,   496,    20,   496,    14,    -1,
     132,    13,   496,    20,   496,    20,   496,    14,    -1,   255,
      13,   492,    14,    -1,   256,    13,   492,    14,    -1,   370,
      13,   493,    20,   494,    20,   492,    14,    -1,   373,    13,
     496,    14,    -1,   240,    13,   496,    20,   496,    20,   492,
      20,   492,    20,   492,    20,   492,    20,   492,    20,   492,
      14,    -1,   427,    13,    56,    14,    -1,   142,    -1,   143,
      -1,   145,    -1,   462,    13,   496,    20,   494,    14,    -1,
      79,    19,    46,    -1,    79,    19,   167,   494,    -1,   463,
      -1,   464,    -1,   465,    -1,   466,    13,   496,    20,   496,
      20,   496,    20,   496,    20,   496,    20,   496,    20,   496,
      20,   492,    20,   492,    20,   492,    20,   492,    20,   492,
      20,   492,    20,   492,    14,    -1,   467,    13,   496,    20,
     496,    20,   492,    20,   492,    20,   492,    20,   492,    20,
     492,    20,   492,    20,   496,    20,   496,    20,   492,    14,
      -1,   454,    13,   492,    20,   492,    20,   492,    14,    -1,
     494,    -1,   483,    20,   494,    -1,    -1,   525,    -1,   484,
      20,   525,    -1,    17,   527,    -1,   484,    20,    17,   527,
      -1,   516,    -1,   484,    20,   516,    -1,    -1,   431,    59,
      -1,   434,    59,    -1,   432,    59,    -1,   428,    59,    -1,
     429,    59,    -1,   430,    59,    -1,   485,    20,   434,    59,
      -1,   485,    20,   431,    59,    -1,   485,    20,   432,    59,
      -1,   485,    20,   428,    59,    -1,   485,    20,   429,    59,
      -1,   485,    20,   430,    59,    -1,    56,    -1,    50,    13,
     494,    20,   492,    14,    -1,   144,    -1,   496,    19,    54,
      -1,    54,    13,   527,    14,    -1,    55,    13,   527,    14,
      -1,    34,    -1,   488,    57,   489,    -1,    -1,    -1,    67,
      -1,    58,    -1,    35,    -1,   379,    -1,   380,    -1,    61,
      -1,   496,    13,   492,    20,   492,    14,    -1,   496,    13,
     492,    20,   492,    20,   492,    14,    -1,   496,    19,   337,
      13,   492,    20,   492,    20,   492,    14,    -1,   496,    13,
     492,    20,   492,    20,   492,    20,   492,    14,    -1,   496,
      13,   492,    20,   492,    20,   492,    23,   492,    14,    -1,
     496,    13,   492,    20,   492,    23,   492,    14,    -1,   496,
      13,   492,    23,   492,    14,    -1,   496,    19,   412,    -1,
     496,    19,   413,    -1,   496,    19,   414,    -1,   496,    19,
     415,    -1,   496,    19,   416,    -1,   496,    19,   417,    -1,
     496,    19,   418,    -1,   496,    19,   419,    -1,   496,    19,
     420,    -1,   496,    19,   421,    -1,   496,    19,   422,    -1,
     496,    19,   423,    -1,   519,    19,   165,    -1,   519,    19,
     166,    -1,   163,    13,   496,    20,   496,    14,    -1,   184,
      13,   496,    14,    -1,   257,    13,   496,    20,   492,    20,
     492,    20,   492,    14,    -1,   258,    13,   496,    14,    -1,
     258,    13,   492,    20,   492,    20,   492,    20,   492,    14,
      -1,   117,    13,   493,    14,    -1,   186,    13,   493,    14,
      -1,   118,    13,   493,    14,    -1,   119,    13,   493,    14,
      -1,   120,    13,   493,    14,    -1,   121,    13,   493,    14,
      -1,   118,    15,   493,    16,    13,   493,    14,    -1,   120,
      15,   493,    16,    13,   496,    14,    -1,   121,    15,   493,
      16,    13,   496,    14,    -1,   121,    15,   493,    16,    13,
     496,    20,   492,    14,    -1,   186,    15,   493,    16,    13,
     493,    14,    -1,   186,    13,   496,    20,   493,    14,    -1,
     369,    13,   494,    14,    -1,    65,    19,   231,    -1,    65,
      19,   232,    -1,    65,    19,   229,    -1,    65,    19,   230,
      -1,    65,    19,   227,    -1,    65,    19,   228,    -1,    65,
      19,   233,    -1,    65,    19,   234,    -1,    65,    19,   235,
      -1,    70,    13,   492,    20,   492,    14,    -1,    70,    19,
     331,    13,   492,    20,   492,    20,   492,    14,    -1,   424,
      13,   521,    14,    -1,   424,    13,   527,    14,    -1,   425,
      13,   494,    14,    -1,   495,    19,   423,    -1,    71,    19,
     376,    13,   494,    14,    -1,    71,    19,   377,    13,    61,
      14,    -1,    71,    19,   377,    13,    64,    14,    -1,   519,
      19,   216,    -1,   516,    -1,   516,    -1,   516,    -1,   357,
      -1,   358,    -1,   359,    -1,   360,    -1,   361,    -1,   362,
      -1,   363,    -1,   364,    -1,   365,    -1,   366,    -1,   367,
      -1,   496,    19,   368,    -1,    60,    -1,    81,    15,   492,
      16,    -1,    38,   494,    -1,   236,    13,   494,    14,    -1,
     237,    13,   494,    14,    -1,    39,    -1,    38,    13,   495,
      20,   492,    20,   492,    20,   492,    14,    -1,    38,    13,
     495,    20,   492,    20,   492,    20,   492,    20,   492,    14,
      -1,    38,    13,   495,    20,   492,    20,   496,    14,    -1,
     496,    -1,   187,    13,   493,    20,   492,    14,    -1,   188,
      13,   493,    20,   492,    14,    -1,   189,    13,   493,    20,
     492,    14,    -1,   190,    13,   493,    20,   493,    20,   492,
      14,    -1,   191,    13,   493,    20,   493,    20,   492,    14,
      -1,   122,    13,   496,    20,    56,    14,    -1,   122,    13,
     496,    20,    56,    20,   495,    14,    -1,   122,    13,   496,
      20,   496,    20,    56,    14,    -1,   122,    13,   496,    20,
     496,    20,    56,    20,   495,    14,    -1,   122,    13,   496,
      20,   496,    20,   496,    20,    56,    14,    -1,   122,    13,
     496,    20,   496,    20,   496,    20,    56,    20,   495,    14,
      -1,   123,    13,   493,    20,   492,    20,   492,    20,   492,
      20,   492,    14,    -1,   444,    19,   445,    13,   496,    20,
     492,    20,   492,    14,    -1,   269,    13,   496,    14,    -1,
     140,    13,   496,    20,   492,    20,   492,    20,   492,    14,
      -1,   270,    13,   496,    14,    -1,   171,    13,   493,    20,
     492,    14,    -1,   172,    13,   496,    14,    -1,   173,    13,
     496,    14,    -1,   174,    13,   496,    14,    -1,   175,    13,
     496,    20,   496,    20,   492,    20,   492,    20,   492,    14,
      -1,   176,    13,   496,    14,    -1,   177,    13,   496,    20,
     496,    20,   496,    20,   492,    20,   496,    14,    -1,   178,
      13,   496,    20,   496,    20,   496,    20,   492,    20,   496,
      14,    -1,   179,    13,   496,    20,   496,    20,   496,    20,
     492,    20,   496,    20,   492,    20,   492,    14,    -1,   180,
      13,   496,    20,   496,    20,   496,    20,   492,    20,   496,
      20,   492,    20,   492,    20,   492,    20,   492,    14,    -1,
     181,    13,   496,    20,   496,    20,   496,    20,   496,    14,
      -1,   181,    13,   496,    20,   496,    20,   496,    20,   496,
      20,   492,    14,    -1,   182,    13,   496,    14,    -1,   182,
      13,   496,    20,   496,    14,    -1,   183,    13,   496,    20,
     496,    14,    -1,   124,    13,   493,    20,   492,    14,    -1,
     125,    13,   496,    14,    -1,   139,    13,   496,    14,    -1,
     126,    13,   496,    20,   492,    14,    -1,   198,    13,   496,
      14,    -1,   127,    13,   496,    20,   492,    14,    -1,   128,
      13,   496,    20,   492,    14,    -1,   131,    13,   493,    20,
     492,    14,    -1,   129,    13,   496,    20,   492,    20,   492,
      20,   492,    20,   492,    20,   492,    20,   492,    14,    -1,
     133,    13,   496,    20,   492,    20,   492,    20,   492,    14,
      -1,   133,    13,   496,    20,   492,    20,   492,    14,    -1,
     133,    13,   496,    20,   492,    20,   492,    20,   492,    20,
     492,    14,    -1,   134,    13,   496,    20,   492,    20,   492,
      20,   492,    14,    -1,   134,    13,   496,    20,   492,    20,
     492,    14,    -1,   134,    13,   496,    20,   492,    20,   492,
      20,   492,    20,   492,    14,    -1,   135,    13,   496,    20,
     492,    20,   492,    14,    -1,   135,    13,   496,    20,   492,
      20,   492,    20,   492,    20,   492,    14,    -1,   136,    13,
     496,    20,   492,    20,   492,    14,    -1,   136,    13,   496,
      20,   492,    20,   492,    20,   492,    20,   492,    14,    -1,
     148,    13,   496,    20,   496,    20,   492,    20,   492,    20,
     492,    14,    -1,   138,    13,   496,    20,   492,    20,   492,
      20,   492,    20,   492,    20,   492,    14,    -1,   137,    13,
     496,    20,   492,    20,   492,    20,   492,    20,   492,    14,
      -1,   149,    19,   159,    13,   496,    20,   492,    20,   492,
      20,   492,    14,    -1,   150,    19,   159,    13,   496,    20,
     492,    20,   492,    20,   492,    20,   492,    20,   492,    14,
      -1,   151,    13,   496,    14,    -1,   152,    13,   496,    20,
     492,    20,   492,    14,    -1,   152,    13,   496,    20,   492,
      20,   492,    20,   528,    14,    -1,   152,    13,   496,    20,
     492,    20,   492,    20,   492,    20,   528,    14,    -1,   153,
      13,   496,    20,   492,    20,   492,    20,   528,    14,    -1,
     153,    13,   496,    20,   492,    20,   492,    20,   492,    20,
     528,    14,    -1,   154,    13,   496,    20,   492,    20,   492,
      20,   528,    14,    -1,   155,    13,   496,    20,   492,    20,
     492,    20,   492,    20,   528,    14,    -1,   156,    13,   496,
      20,   492,    20,   492,    20,   492,    20,   528,    14,    -1,
     157,    13,   496,    20,   492,    20,   492,    20,   492,    20,
     492,    20,   528,    14,    -1,   158,    13,   496,    20,   492,
      20,   492,    20,   492,    20,   492,    14,    -1,   162,    13,
     496,    20,   492,    20,   492,    14,    -1,   185,    13,   496,
      20,   492,    20,   492,    20,   492,    20,   492,    20,   492,
      14,    -1,   353,    13,   496,    14,    -1,   354,    13,   496,
      14,    -1,   355,    13,   496,    14,    -1,   356,    13,   496,
      14,    -1,    69,    19,   272,    -1,    69,    19,   273,    -1,
      65,    19,   272,    -1,   207,    13,   496,    20,   492,    14,
      -1,   208,    13,   496,    20,   492,    14,    -1,   209,    13,
     496,    20,   492,    14,    -1,   210,    13,   496,    20,   492,
      14,    -1,   146,    13,   493,    20,   493,    20,   492,    14,
      -1,   147,    13,   493,    20,   493,    20,   492,    20,   492,
      20,   492,    20,   492,    14,    -1,   146,    13,   493,    20,
     493,    20,   492,    20,   492,    20,   492,    14,    -1,   146,
      13,   493,    20,   493,    20,   492,    20,   492,    20,   492,
      20,   492,    14,    -1,   146,    13,   493,    20,   493,    20,
     496,    20,   492,    20,   492,    14,    -1,   238,    13,   496,
      20,   496,    14,    -1,   239,    13,   496,    20,   496,    20,
     493,    14,    -1,   243,    13,   496,    20,   492,    20,   492,
      20,   492,    14,    -1,   244,    13,   496,    20,   492,    20,
     492,    20,   492,    14,    -1,   244,    13,   496,    20,   492,
      20,   492,    20,   492,    20,   492,    14,    -1,   245,    13,
     496,    20,   492,    14,    -1,   246,    13,   496,    20,   492,
      14,    -1,   247,    13,   496,    20,   492,    14,    -1,   248,
      13,   496,    20,   492,    14,    -1,   249,    13,   496,    20,
     492,    14,    -1,   250,    13,   496,    20,   492,    14,    -1,
     251,    13,   496,    20,   492,    14,    -1,   252,    13,   496,
      20,   492,    14,    -1,   252,    13,   496,    20,   492,    20,
     492,    14,    -1,   253,    13,   496,    20,   492,    20,   492,
      20,   492,    14,    -1,   254,    13,   493,    14,    -1,   496,
      13,   516,    14,    -1,   371,    13,   493,    20,   492,    20,
     492,    20,   492,    14,    -1,   372,    13,   493,    20,   492,
      20,   492,    20,   492,    14,    -1,   438,    13,   493,    14,
      -1,   438,    13,   493,    20,   492,    14,    -1,   441,    13,
     493,    20,   492,    14,    -1,   439,    13,   493,    20,   492,
      20,   492,    20,   492,    20,   492,    14,    -1,   440,    13,
     496,    20,   496,    20,   492,    20,   492,    20,   492,    20,
     492,    20,   492,    20,   492,    20,   492,    20,   492,    20,
     492,    20,   492,    20,   492,    20,   492,    14,    -1,   443,
      13,   493,    20,   492,    20,   492,    14,    -1,   519,    19,
     307,    13,    14,    -1,   519,    19,   217,    13,   492,    14,
      -1,   519,    19,   308,    13,    14,    -1,   519,    19,   309,
      13,    14,    -1,   519,    19,   306,    13,   496,    14,    -1,
     449,    13,   493,    20,   492,    14,    -1,   449,    13,   493,
      14,    -1,   450,    13,   493,    20,   492,    14,    -1,   450,
      13,   493,    14,    -1,   456,    13,   493,    20,   493,    14,
      -1,   457,    13,   493,    14,    -1,   458,    13,   494,    14,
      -1,   426,    13,   493,    20,   492,    20,   492,    20,   492,
      20,   492,    20,   492,    20,   492,    20,   492,    14,    -1,
     215,    13,   519,    20,   496,    20,   493,    14,    -1,   219,
      13,   519,    20,   494,    14,    -1,   497,    -1,    64,    -1,
     486,    -1,    66,    -1,    62,    -1,    63,    -1,   490,    -1,
     491,    -1,   498,    -1,   499,    -1,   518,    -1,   118,    13,
     516,    20,   516,    14,    -1,   523,    13,   484,    14,    -1,
      13,   516,    14,    -1,   500,    -1,     9,   500,    -1,   500,
     105,    -1,   500,   106,    -1,    13,   495,    14,   500,    -1,
     500,   114,    -1,   501,    15,   500,    16,    -1,   501,    -1,
      11,   501,    -1,    10,   501,    -1,   105,   501,    -1,   106,
     501,    -1,   381,   501,    -1,   382,   501,    -1,   392,   501,
      -1,   393,   501,    -1,   394,   501,    -1,   395,   501,    -1,
     383,   501,    -1,   384,   501,    -1,   385,   501,    -1,   386,
     501,    -1,   389,   501,    -1,   391,   501,    -1,   390,   501,
      -1,   396,   501,    -1,   502,    -1,   503,     7,   502,    -1,
     503,     8,   502,    -1,   503,    12,   502,    -1,   503,    -1,
     504,    10,   503,    -1,   504,    11,   503,    -1,   504,    -1,
     505,    -1,   506,     6,   505,    -1,   506,     5,   505,    -1,
     506,   110,   505,    -1,   506,   111,   505,    -1,   506,    -1,
     507,   112,   506,    -1,   507,   113,   506,    -1,   507,    -1,
     508,    17,   507,    -1,   508,    -1,   509,    -1,   510,    18,
     509,    -1,   510,    -1,   511,   108,   510,    -1,   511,    -1,
     512,     4,   511,    -1,   512,    -1,   513,   109,   512,    -1,
     513,    -1,   513,    21,   513,    22,   514,    -1,   514,    -1,
     514,   116,   515,    -1,   514,    96,   515,    -1,   514,    97,
     515,    -1,   514,    98,   515,    -1,   514,    99,   515,    -1,
     515,    -1,    79,    -1,    69,    19,   325,    -1,   327,    13,
      79,    20,    79,    20,   492,    14,    -1,    41,    13,   494,
      14,    -1,   328,    13,   492,    20,   492,    14,    -1,    70,
      -1,   329,    13,   516,    14,    -1,    68,    -1,    80,    15,
     492,    16,    -1,   259,    13,   493,    20,   492,    14,    -1,
     262,    13,   496,    20,   492,    14,    -1,   259,    13,   493,
      20,   492,    20,   496,    14,    -1,   268,    13,   493,    20,
     492,    20,   493,    14,    -1,   263,    13,   519,    14,    -1,
     263,    13,   519,    20,   492,    14,    -1,   264,    13,   496,
      20,   492,    14,    -1,   265,    13,   519,    20,   492,    14,
      -1,   267,    13,   519,    20,   492,    14,    -1,   271,    13,
      14,    -1,   271,   494,    -1,   271,    -1,   218,    13,   494,
      14,    -1,   218,    13,   494,    20,   492,    14,    -1,   519,
      -1,   202,    13,   496,    14,    -1,   203,    13,   519,    14,
      -1,   203,    13,   519,    20,   492,    20,   492,    20,   492,
      14,    -1,   204,    13,   519,    20,   492,    14,    -1,   211,
      13,   519,    20,   492,    20,   492,    20,   492,    20,   492,
      20,   492,    20,   492,    14,    -1,   212,    13,   493,    20,
     492,    20,   492,    20,   492,    20,   492,    20,   492,    20,
     492,    20,   492,    14,    -1,   213,    13,   493,    20,   492,
      20,   492,    20,   492,    14,    -1,   214,    13,   493,    20,
     492,    20,   492,    20,   492,    20,   492,    20,   492,    20,
     492,    20,   492,    20,   492,    14,    -1,   214,    13,   493,
      20,   492,    20,   492,    20,   492,    20,   492,    20,   492,
      14,    -1,   519,    19,   206,    13,   492,    20,   492,    14,
      -1,   446,    13,   493,    14,    -1,   446,    13,   493,    20,
     492,    14,    -1,   446,    13,   493,    20,   492,    20,   492,
      14,    -1,   448,    13,   493,    20,   492,    20,   492,    14,
      -1,   447,    13,   493,    20,   492,    20,   492,    20,   493,
      20,   493,    14,    -1,   447,    13,   493,    20,   492,    20,
     492,    20,   493,    20,   493,    20,   493,    20,   492,    14,
      -1,   452,    13,   493,    20,   493,    20,   493,    20,   492,
      20,   492,    20,   492,    20,   492,    14,    -1,   452,    13,
     493,    20,   493,    20,   493,    20,   492,    20,   492,    20,
     492,    20,   492,    20,   492,    14,    -1,   452,    13,   493,
      20,   493,    20,   493,    20,   492,    20,   492,    20,   492,
      14,    -1,   453,    13,   493,    20,   492,    20,   492,    20,
     492,    20,   492,    20,   492,    14,    -1,   455,    13,   493,
      20,   493,    20,   493,    20,   492,    20,   492,    20,   492,
      20,   492,    14,    -1,   455,    13,   493,    20,   493,    20,
     493,    20,   492,    20,   492,    20,   492,    20,   492,    20,
     493,    20,   493,    14,    -1,    59,    -1,    79,    -1,   519,
      -1,    72,    -1,    73,    -1,    75,    -1,    74,    -1,    76,
      -1,    78,    19,   521,    -1,   523,    -1,    65,    -1,    80,
      -1,    69,    -1,    71,    -1,    77,    -1,    78,    -1,    81,
      -1,   522,    -1,   524,    -1,    62,    -1,    63,    -1,    61,
      -1,    66,    -1,    67,    -1,    64,    -1,    70,    -1,   496,
      -1,   525,    -1,   526,    -1,   492,    22,   492,    20,   492,
      22,   492,    20,   492,    22,   492,    -1,   492,    22,   492,
      20,   492,    22,   492,    -1,    22,    20,    22,    20,   492,
      22,   492,    -1,   496,    19,    93,    -1,    65,    -1
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
     233,   240,   244,   248,   255,   262,   271,   278,   287,   296,
     305,   309,   311,   313,   316,   319,   321,   323,   326,   335,
     340,   345,   347,   350,   353,   356,   360,   369,   386,   389,
     396,   399,   402,   408,   411,   413,   415,   418,   421,   424,
     427,   430,   433,   438,   443,   446,   449,   452,   457,   461,
     472,   479,   483,   490,   497,   506,   535,   544,   553,   557,
     566,   579,   586,   593,   610,   619,   636,   647,   654,   665,
     674,   685,   700,   709,   722,   729,   738,   745,   752,   756,
     760,   763,   767,   774,   785,   792,   803,   814,   827,   834,
     841,   845,   849,   853,   857,   862,   866,   873,   880,   885,
     890,   897,   908,   919,   930,   937,   944,   951,   958,   965,
     976,   983,   994,  1001,  1008,  1015,  1019,  1026,  1033,  1044,
    1055,  1062,  1069,  1076,  1080,  1084,  1088,  1092,  1099,  1106,
    1110,  1117,  1124,  1133,  1144,  1148,  1155,  1159,  1164,  1185,
    1192,  1203,  1210,  1214,  1218,  1225,  1229,  1236,  1245,  1252,
    1259,  1268,  1285,  1292,  1296,  1303,  1312,  1316,  1329,  1342,
    1355,  1366,  1370,  1374,  1383,  1392,  1403,  1412,  1423,  1436,
    1443,  1452,  1463,  1480,  1499,  1512,  1519,  1538,  1555,  1568,
    1579,  1590,  1601,  1608,  1619,  1626,  1633,  1640,  1649,  1654,
    1659,  1668,  1673,  1692,  1697,  1699,  1701,  1703,  1710,  1714,
    1719,  1721,  1723,  1725,  1756,  1781,  1790,  1792,  1796,  1797,
    1799,  1803,  1806,  1811,  1813,  1817,  1818,  1821,  1824,  1827,
    1830,  1833,  1836,  1841,  1846,  1851,  1856,  1861,  1866,  1868,
    1875,  1877,  1881,  1886,  1891,  1893,  1897,  1898,  1899,  1901,
    1903,  1905,  1907,  1909,  1911,  1918,  1927,  1938,  1949,  1960,
    1969,  1976,  1980,  1984,  1988,  1992,  1996,  2000,  2004,  2008,
    2012,  2016,  2020,  2024,  2028,  2032,  2039,  2044,  2055,  2060,
    2071,  2076,  2081,  2086,  2091,  2096,  2101,  2109,  2117,  2125,
    2135,  2143,  2150,  2155,  2159,  2163,  2167,  2171,  2175,  2179,
    2183,  2187,  2191,  2198,  2209,  2214,  2219,  2224,  2228,  2235,
    2242,  2249,  2253,  2255,  2257,  2259,  2261,  2263,  2265,  2267,
    2269,  2271,  2273,  2275,  2277,  2279,  2281,  2285,  2287,  2292,
    2295,  2300,  2305,  2307,  2318,  2331,  2340,  2342,  2349,  2356,
    2363,  2372,  2381,  2388,  2397,  2406,  2417,  2428,  2441,  2454,
    2465,  2470,  2481,  2486,  2493,  2498,  2503,  2508,  2521,  2526,
    2539,  2552,  2569,  2590,  2601,  2614,  2619,  2626,  2633,  2640,
    2645,  2650,  2657,  2662,  2669,  2676,  2683,  2700,  2711,  2720,
    2733,  2744,  2753,  2766,  2775,  2788,  2797,  2810,  2823,  2838,
    2851,  2864,  2881,  2886,  2895,  2906,  2919,  2930,  2943,  2954,
    2967,  2980,  2995,  3008,  3017,  3032,  3037,  3042,  3047,  3052,
    3056,  3060,  3064,  3071,  3078,  3085,  3092,  3101,  3116,  3129,
    3144,  3157,  3164,  3173,  3184,  3195,  3208,  3215,  3222,  3229,
    3236,  3243,  3250,  3257,  3264,  3273,  3284,  3289,  3294,  3305,
    3316,  3321,  3328,  3335,  3348,  3379,  3388,  3394,  3401,  3407,
    3413,  3420,  3427,  3432,  3439,  3444,  3451,  3456,  3461,  3480,
    3489,  3496,  3498,  3500,  3502,  3504,  3506,  3508,  3510,  3512,
    3514,  3516,  3518,  3525,  3530,  3534,  3536,  3539,  3542,  3545,
    3550,  3553,  3558,  3560,  3563,  3566,  3569,  3572,  3575,  3578,
    3581,  3584,  3587,  3590,  3593,  3596,  3599,  3602,  3605,  3608,
    3611,  3614,  3616,  3620,  3624,  3628,  3630,  3634,  3638,  3640,
    3642,  3646,  3650,  3654,  3658,  3660,  3664,  3668,  3670,  3674,
    3676,  3678,  3682,  3684,  3688,  3690,  3694,  3696,  3700,  3702,
    3708,  3710,  3714,  3718,  3722,  3726,  3730,  3732,  3734,  3738,
    3747,  3752,  3759,  3761,  3766,  3768,  3773,  3780,  3787,  3796,
    3805,  3810,  3817,  3824,  3831,  3838,  3842,  3845,  3847,  3852,
    3859,  3861,  3866,  3871,  3882,  3889,  3906,  3925,  3936,  3957,
    3972,  3981,  3986,  3993,  4002,  4011,  4024,  4041,  4058,  4077,
    4092,  4107,  4124,  4145,  4147,  4149,  4151,  4153,  4155,  4157,
    4159,  4161,  4165,  4167,  4169,  4171,  4173,  4175,  4177,  4179,
    4181,  4183,  4185,  4187,  4189,  4191,  4193,  4195,  4197,  4199,
    4201,  4203,  4205,  4217,  4225,  4233,  4237
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   799,   799,   800,   804,   804,   805,   806,   807,   807,
     808,   808,   809,   809,   810,   810,   811,   811,   812,   812,
     815,   816,   821,   840,   860,   906,   929,   978,   993,  1016,
    1015,  1047,  1046,  1090,  1107,  1129,  1150,  1157,  1192,  1202,
    1235,  1268,  1276,  1286,  1300,  1314,  1328,  1338,  1354,  1372,
    1387,  1402,  1430,  1458,  1505,  1516,  1526,  1537,  1563,  1602,
    1632,  1654,  1666,  1684,  1704,  1716,  1735,  1746,  1833,  1867,
    1883,  1889,  1893,  1897,  1901,  1911,  1916,  1920,  1930,  1945,
    1955,  1966,  1969,  2019,  2042,  2089,  2140,  2230,  2284,  2288,
    2300,  2314,  2324,  2334,  2345,  2353,  2365,  2601,  2611,  2621,
    2631,  2640,  2694,  2703,  2712,  2724,  2765,  2784,  2792,  2819,
    2836,  2849,  2860,  2906,  2913,  2932,  2967,  2982,  2990,  2998,
    3017,  3041,  3047,  3053,  3067,  3079,  3089,  3099,  3106,  3123,
    3139,  3157,  3178,  3194,  3213,  3227,  3242,  3252,  3264,  3286,
    3310,  3332,  3350,  3362,  3376,  3395,  3417,  3446,  3475,  3507,
    3704,  3709,  3716,  3721,  3961,  3989,  4003,  4010,  4016,  4024,
    4038,  4045,  4051,  4058,  4066,  4074,  4082,  4092,  4105,  4122,
    4137,  4145,  4153,  4161,  4169,  4175,  4181,  4227,  4235,  4243,
    4251,  4263,  4272,  4290,  4301,  4308,  4315,  4323,  4332,  4341,
    4361,  4378,  4396,  4414,  4420,  4426,  4432,  4438,  4446,  4547,
    4580,  4587,  4595,  4603,  4611,  4622,  4632,  4640,  4648,  4659,
    4666,  4680,  4694,  4703,  4708,  4717,  4726,  4739,  4752,  4765,
    4778,  4785,  4795,  4805,  4819,  4827,  4838,  4861,  4887,  4915,
    4926,  4969,  4991,  5020,  5037,  5052,  5058,  5085,  5111,  5131,
    5148,  5154,  5160,  5171,  5177,  5185,  5200,  5209,  5220,  5237,
    5253,  5291,  5305,  5352,  5358,  5363,  5368,  5374,  5381,  5387,
    5394,  5399,  5404,  5409,  5452,  5506,  5528,  5536,  5553,  5557,
    5573,  5591,  5607,  5622,  5638,  5658,  5663,  5672,  5679,  5686,
    5693,  5700,  5707,  5714,  5721,  5728,  5735,  5742,  5750,  5755,
    5836,  5860,  5865,  5878,  5897,  5928,  5939,  5940,  5944,  5954,
    5958,  5966,  5974,  5983,  6011,  6028,  6044,  6061,  6080,  6098,
    6114,  6130,  6136,  6142,  6148,  6154,  6160,  6166,  6172,  6178,
    6184,  6190,  6196,  6203,  6210,  6217,  6226,  6233,  6264,  6272,
    6284,  6304,  6324,  6344,  6364,  6384,  6404,  6428,  6452,  6476,
    6484,  6508,  6531,  6539,  6551,  6563,  6575,  6587,  6599,  6611,
    6627,  6646,  6687,  6697,  6709,  6719,  6729,  6741,  6749,  6765,
    6780,  6792,  6822,  6840,  6853,  6874,  6879,  6883,  6887,  6891,
    6895,  6899,  6903,  6907,  6911,  6915,  6919,  6927,  6929,  6948,
    7124,  7144,  7179,  7208,  7215,  7233,  7258,  7353,  7419,  7426,
    7433,  7441,  7449,  7465,  7483,  7501,  7518,  7535,  7553,  7589,
    7602,  7613,  7626,  7650,  7660,  7671,  7681,  7691,  7724,  7735,
    7756,  7776,  7817,  7864,  7884,  7905,  7916,  7930,  7944,  7957,
    7968,  7979,  7992,  8010,  8022,  8034,  8086,  8127,  8138,  8148,
    8160,  8171,  8181,  8206,  8229,  8257,  8271,  8405,  8439,  8472,
    8500,  8514,  8528,  8538,  8557,  8576,  8596,  8617,  8639,  8658,
    8677,  8697,  8737,  8759,  8788,  8810,  8847,  8884,  8921,  8955,
    8961,  8971,  8977,  8984,  8991,  8999,  9006,  9025,  9053,  9077,
    9104,  9136,  9147,  9160,  9167,  9175,  9189,  9201,  9213,  9223,
    9234,  9244,  9254,  9265,  9275,  9286,  9313,  9361,  9543,  9564,
    9604,  9615,  9623,  9631,  9652,  9678,  9689,  9696,  9733,  9748,
    9763,  9771,  9778,  9784,  9790,  9797,  9822,  9840,  9847,  9880,
    9900, 10072, 10085, 10094, 10108, 10110, 10112, 10114, 10116, 10118,
   10120, 10122, 10124, 10186, 10264, 10267, 10268, 10276, 10284, 10293,
   10302, 10311, 10323, 10324, 10330, 10335, 10340, 10345, 10350, 10355,
   10360, 10365, 10370, 10375, 10380, 10385, 10390, 10395, 10400, 10405,
   10410, 10419, 10420, 10426, 10432, 10442, 10443, 10450, 10460, 10464,
   10465, 10471, 10477, 10483, 10492, 10493, 10499, 10525, 10526, 10530,
   10534, 10535, 10539, 10540, 10552, 10553, 10565, 10566, 10578, 10579,
   10592, 10593, 10603, 10609, 10615, 10621, 10630, 10634, 10644, 10658,
   10669, 10687, 10693, 10702, 10823, 10825, 10843, 10854, 10865, 10886,
   10920, 10930, 10941, 10951, 10962, 10972, 10978, 10992, 11018, 11033,
   11051, 11060, 11079, 11108, 11136, 11152, 11176, 11210, 11242, 11289,
   11330, 11355, 11365, 11388, 11400, 11412, 11449, 11492, 11540, 11592,
   11635, 11666, 11699, 11742, 11750, 11752, 11755, 11756, 11757, 11758,
   11759, 11760, 11793, 11794, 11795, 11796, 11797, 11798, 11799, 11800,
   11805, 11806, 11812, 11814, 11816, 11818, 11821, 11823, 11826, 11828,
   11832, 11834, 11837, 11846, 11854, 11872, 11889
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
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 13732;
  const int Parser::yynnts_ = 59;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 537;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 470;

  const unsigned int Parser::yyuser_token_number_max_ = 724;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // yyip

/* Line 1054 of lalr1.cc  */
#line 17502 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"


/* Line 1056 of lalr1.cc  */
#line 11911 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"

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


//-------------------------------------------
void CB_ParamWin(void* cd)
 {

  AMIFunction* func_ptr = (AMIFunction*) (cd);

  //cout << "CB_ParamWin pointer is " << func_ptr << endl;

  GB_driver.yyip_call_function(func_ptr);

} // CB_ParamWin( void* cd )

//-----------------------------------------
void CB_delete_variable( void* var)
{
  BasicVariable* vartodelete = (BasicVariable*) var;

  FILE_MESSAGE(boost::format("deleting %1%") % vartodelete->Name());
  if (!Vars.deleteVar(vartodelete))
    FILE_ERROR("Could not delete variable "); 

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





