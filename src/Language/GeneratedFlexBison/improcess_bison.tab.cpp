
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
#line 11 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"

 /*** C/C++ Declarations ***/
  //#include <stdlib.h>
  //#include <stdio.h>

// use NOMINMAX to avoid conflicts between windows.h min,max and std::min std::max ...
#define NOMINMAX

#include "driver.h"
#include "CoutwxString.h"
#include "MainFrame.h"
#include "ParamPanel.hpp"
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
#include "wrap_mainframe.h"
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
//#include "Duree.hpp"

#include "DefineClass.hpp"
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
#include "penguin.h"
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
    wxScheduleTimer( Variable* callback)
    {
      var = callback;
    }

    ~wxScheduleTimer()
    { 
      //cout << "~wxScheduleTimer()" << endl; 
    }

    //Called each time the timer's timeout expires
    void Notify();

  private:
    // variable of type type_ami_function
    Variable* var;
};

// create a array of shared pointers
// to delete the wxScheduleTimer when necessary
static std::list<wxScheduleTimer::ptr> schedule_timers;

static void CB_ParamWin( void* cd ) {

  Variable* v = (Variable*) (cd);

  GB_driver.yyip_call_function(v);

} // CB_ParamWin( void* cd )


//static void ( void* cd, long unsigned int *) {
//  CB_ParamWin(cd);
//}

static void CB_Button(  void* cd) {
  CB_ParamWin(cd);
}

void CB_delete_imagedraw( void* var);

void CB_delete_surfdraw( void* varid);

//------------------------------------------------------
static void CB_update_imagelist( void* imagelist_gui)
//   -------------------
{
  wxEnumerationParameter* imlist = (wxEnumerationParameter*) imagelist_gui;
  boost::shared_ptr<wxArrayString> imagelist;

  imagelist = Vars.SearchVariables(type_image);
  imagelist->Add(_T("Image"));
  imlist->SetChoices(imagelist);
}

#define UNARYOP_EXPR(operator,val,res)           \
  res=operator(val);


#define UNARYOP_IMAGE(operator)           \
  InrImage* im;                           \
  int       i;                            \
  im = driver.im_stack.GetLastImage();           \
  im->InitBuffer();                       \
  Si im->ScalarFormat() Alors             \
    Repeter                                \
     im->FixeValeur( operator(im->ValeurBuffer()) );   \
    JusquA Non(im->IncBuffer()) FinRepeter             \
  Sinon                                                \
    Pour(i,0,im->GetVDim()-1)                 \
      im->InitBuffer();                       \
      Repeter                                 \
       im->VectFixeValeur( i, operator(im->VectValeurBuffer(i)) );   \
      JusquA Non(im->IncBuffer()) FinRepeter  \
    FinPour                                   \
  FinSi                                       \
  driver.im_stack.AddImage(im);

#define IMAGE_OP_EXPR(operator,expr)                     \
  InrImage* im1;                                         \
  int       i;                                           \
  double    val = expr;                                  \
  im1 = driver.im_stack.GetLastImage();                         \
  im1->InitBuffer();                                     \
  Si im1->ScalarFormat() Alors                           \
    Repeter                                              \
      im1->FixeValeur(im1->ValeurBuffer() operator val); \
    JusquA Non(im1->IncBuffer()) FinRepeter              \
  Sinon                                                  \
    Repeter                                              \
      Pour(i,0,im1->GetVDim()-1)                         \
        im1->VectFixeValeur(i,im1->VectValeurBuffer(i) operator val);  \
      FinPour                                            \
    JusquA Non(im1->IncBuffer()) FinRepeter              \
  FinSi                                                  \
  driver.im_stack.AddImage(im1);

#define EXPR_OP_IMAGE(operator,expr)                     \
  InrImage* im1;                                         \
  int       i;                                           \
  double    val = expr;                                  \
  im1 = driver.im_stack.GetLastImage();                         \
  im1->InitBuffer();                                     \
  Si im1->ScalarFormat() Alors                           \
    Repeter                                              \
      im1->FixeValeur(val operator im1->ValeurBuffer() ); \
    JusquA Non(im1->IncBuffer()) FinRepeter              \
  Sinon                                                  \
    Repeter                                              \
      Pour(i,0,im1->GetVDim()-1)                         \
        im1->VectFixeValeur(i, val operator im1->VectValeurBuffer(i));  \
      FinPour                                            \
    JusquA Non(im1->IncBuffer()) FinRepeter              \
  FinSi                                                  \
  driver.im_stack.AddImage(im1);

#define IMAGE_OP_IMAGE(operator)    \
  InrImage* im1;                    \
  InrImage* im2;                    \
  im2 = driver.im_stack.GetLastImage();    \
  im1 = driver.im_stack.GetLastImage();    \
  im1->InitBuffer();                \
  im2->InitBuffer();                \
  Repeter                           \
    im1->FixeValeur(im1->ValeurBuffer() operator im2->ValeurBuffer()); \
    im2->IncBuffer();               \
  JusquA Non(im1->IncBuffer())      \
  FinRepeter                        \
  driver.im_stack.AddImage(im1);           \
  delete im2;

#define IMAGE_OP_IMAGE_2(operator)  \
  InrImage* im1;                    \
  InrImage* im2;                    \
  InrImage* res;                    \
  im2 = driver.im_stack.GetLastImage();    \
  im1 = driver.im_stack.GetLastImage();    \
  res = (*im1) operator (*im2);     \
  Si res == NULL Alors              \
    driver.err_print((boost::format("Error in operation %s \t IMAGE_OP_IMAGE_2 \n") % #operator).str().c_str()); \
  FinSi                             \
  driver.im_stack.AddImage(res);           \
  delete im1;                       \
  delete im2;

#define UNARYOP_MATRIX(operator)           \
  FloatMatrix* mat;                         \
  int       i,j;                            \
  mat = driver.matrix_stack.GetLastMatrix();       \
  for (i=0;i<mat->Rows();i++)               \
  for (j=0;j<mat->Cols();j++) {             \
    (*mat)[i][j]=operator((*mat)[i][j]);               \
  }                                         \
  driver.matrix_stack.AddMatrix(mat);

#define MATRIX_OP_EXPR(operator,expr)        \
  FloatMatrix* mat;                          \
  int       i,j;                             \
  float     val = expr;                      \
  mat = driver.matrix_stack.GetLastMatrix();        \
  for (i=0;i<mat->Rows();i++)               \
  for (j=0;j<mat->Cols();j++) {             \
    (*mat)[i][j]=(*mat)[i][j] operator val;            \
  }                                         \
  driver.matrix_stack.AddMatrix(mat);

#define MATRIX_OP_MATRIX_2(operator)        \
  FloatMatrix* mat1;                          \
  FloatMatrix* mat2;                          \
  FloatMatrix* mat;                          \
  int       i,j;                             \
  mat2 = driver.matrix_stack.GetLastMatrix();        \
  mat1 = driver.matrix_stack.GetLastMatrix();        \
  if ((mat1->Rows()==mat2->Rows())&&(mat1->Cols()==mat2->Cols())) { \
    mat=new FloatMatrix(mat1->Rows(),mat1->Cols()); \
    for (i=0;i<mat1->Rows();i++)               \
    for (j=0;j<mat1->Cols();j++)              \
      (*mat)[i][j]=(*mat1)[i][j] operator (*mat2)[i][j];            \
    driver.matrix_stack.AddMatrix(mat);                 \
    delete mat1;                                    \
    delete mat2;                                    \
  }                                              \
  else {                                         \
    delete mat2;                                    \
    driver.matrix_stack.AddMatrix(mat1);                \
  }




/* Line 311 of lalr1.cc  */
#line 391 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"


#include "improcess_bison.tab.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 946 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"


#include "driver.h"
#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex



/* Line 317 of lalr1.cc  */
#line 414 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"

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
#line 483 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
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
        case 54: /* "ASTRING" */

/* Line 480 of lalr1.cc  */
#line 939 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 590 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 57: /* "IDENTIFIER" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 599 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 547: /* "primary_expr_string" */

/* Line 480 of lalr1.cc  */
#line 939 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 608 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 548: /* "postfix_expr_string" */

/* Line 480 of lalr1.cc  */
#line 939 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 617 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 549: /* "additive_expr_string" */

/* Line 480 of lalr1.cc  */
#line 939 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 626 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 550: /* "expr_string" */

/* Line 480 of lalr1.cc  */
#line 939 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 635 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 551: /* "instr_block" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ablock); };

/* Line 480 of lalr1.cc  */
#line 644 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 614: /* "identifier" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 653 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 616: /* "image_extent" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->imageextent); };

/* Line 480 of lalr1.cc  */
#line 662 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
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
#line 379 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}

/* Line 553 of lalr1.cc  */
#line 748 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"

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
#line 985 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       int  previous_lineno=driver.yyiplineno;
       int* varint;
        AmiInstructionBlock::ptr block((yysemantic_stack_[(8) - (7)].ablock));
        IdentifierInfo::ptr ident((yysemantic_stack_[(8) - (2)].ident));

      varint = new int;
      Vars.AddVar(type_int,ident,(void*)varint);
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
#line 1004 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       int  previous_lineno=driver.yyiplineno;
       float* var;
        AmiInstructionBlock::ptr block((yysemantic_stack_[(10) - (9)].ablock));
        IdentifierInfo::ptr ident((yysemantic_stack_[(10) - (2)].ident));

      var = new float;
      Vars.AddVar(type_float,ident,(void*)var);

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
#line 1027 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      string* tmp = new string();
      Variable* var = Vars.AddVar(type_string,ident,(void*)tmp);

      std::list<std::string>::iterator sl_it;
      for (sl_it=sl->begin(); sl_it!=sl->end(); sl_it++) {

        // assign new value to the variable
        string_ptr newval( new std::string(*sl_it));
        var->SetString(newval);

        driver.yyiplineno = block->GetStartingLine();
        //driver.yyiplineno=previous_lineno;
        driver.parse_block(block);

      }
      Vars.deleteVar(ident->GetName().c_str());
      driver.yyiplineno=previous_lineno;

    }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 1061 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       int  previous_lineno=driver.yyiplineno;
        AmiInstructionBlock::ptr block((yysemantic_stack_[(2) - (2)].ablock));


      //          printf(" block = %s \n",$7);
          int res;
      //driver.yyiplineno = $2->GetStartingLine();

      do {

          //driver.yyiplineno=previous_lineno;
          driver.yyiplineno = block->GetStartingLine();
          res=driver.parse_block(block);

      } while (!res);
      driver.yyiplineno = previous_lineno;
    }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 1083 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int  previous_lineno;
      AmiInstructionBlock::ptr block((yysemantic_stack_[(4) - (3)].ablock));

      // Pb with line numbers
      previous_lineno=driver.yyiplineno;

        if ((yysemantic_stack_[(4) - (2)].adouble)>0.5)
        {
          //driver.yyiplineno=previous_lineno;
          driver.parse_block(block);
          driver.yyiplineno = previous_lineno;
        }
    }
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 1098 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       int  previous_lineno = driver.yyiplineno;

      AmiInstructionBlock::ptr block_if(  (yysemantic_stack_[(6) - (3)].ablock));
      AmiInstructionBlock::ptr block_else((yysemantic_stack_[(6) - (5)].ablock));

      // Pb with line numbers
      previous_lineno=driver.yyiplineno;

      if ((yysemantic_stack_[(6) - (2)].adouble)>0.5)
        driver.parse_block(block_if);
      else
        driver.parse_block(block_else);
      driver.yyiplineno = previous_lineno;

    }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 1118 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_driver.procedure_declaration = true;
    }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 1123 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      AMIFunction* amifunc;
      AmiInstructionBlock::ptr body((yysemantic_stack_[(8) - (7)].ablock));
      IdentifierInfo::ptr ident((yysemantic_stack_[(8) - (2)].ident));

      amifunc = new AMIFunction;

      amifunc->SetName(ident->GetName().c_str());
      amifunc->SetFileName(driver.current_file);
      amifunc->SetParamList((yysemantic_stack_[(8) - (5)].paramlistdecl));
      amifunc->SetBody(     body);
      if (GB_debug)
        cout  << ident->GetName()
              << " body = "
              << body->GetBody()  << endl;

      Vars.AddVar( type_ami_function,ident, (void*) amifunc);

      // desactivate the flag procedure_declaration
      // which allows not to accept variables as identifiers
      GB_driver.procedure_declaration = false;
    }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 1147 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      // allow overriding current functions
      GB_driver.procedure_declaration = true;
    }
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 1153 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      AMIFunction* amifunc;
      AmiInstructionBlock::ptr body((yysemantic_stack_[(8) - (7)].ablock));
      Variable*       var   = (yysemantic_stack_[(8) - (2)].variable);

      // delete previous variable
      std::string varname = var->Name();
      int context = Vars.GetContext(var);
      Vars.deleteVar(var);

      FILE_MESSAGE(boost::format("Redefining procedure %1%") % varname); 

      amifunc = new AMIFunction;

      amifunc->SetName(varname.c_str());
      amifunc->SetFileName(driver.current_file);
      amifunc->SetParamList((yysemantic_stack_[(8) - (5)].paramlistdecl));
      amifunc->SetBody(     body);
      FILE_MESSAGE(boost::format("%1%: body = %2%")
                    % varname  % body->GetBody());

      // add the variable in the same context ...
      Vars.AddVar(  type_ami_function,
                    varname.c_str(),
                    (void*) amifunc,
                    context);

      // desactivate the flag procedure_declaration
      // which allows not to accept variables as identifiers
      GB_driver.procedure_declaration = false;
    }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 1189 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      AMIClass* amiclass;
      AmiInstructionBlock::ptr body((yysemantic_stack_[(4) - (3)].ablock));
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (2)].ident));

      amiclass = new AMIClass;

      amiclass->SetName(ident->GetName());
      amiclass->SetFileName(driver.current_file);
      amiclass->SetBody(     body);
      if (GB_debug) printf("%s body = %s\n", ident->GetName().c_str(),body->GetBody().c_str());

      Vars.AddVar( type_ami_class, ident, (void*) amiclass);

    }
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 1207 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable*       var   = (yysemantic_stack_[(2) - (1)].variable);
      AMIClass::ptr ac = *(AMIClass::ptr*) (var->Pointer());
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));

      //AMIObject::ptr amiobject;
      //amiobject = AMIObject::ptr(new AMIObject);
      AMIObject* amiobject;
      amiobject = new AMIObject;

      amiobject->SetName(ident->GetName());
      amiobject->SetClass(ac);

      // execute the code of the class with the variables of the object
      driver.yyip_instanciate_object(ac,amiobject);

      Vars.AddVar( type_ami_object, ident, (void*) amiobject);

    }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 1229 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       //driver.res_print($2);
       driver.parse_script((yysemantic_stack_[(3) - (2)].astring));
       delete [] (yysemantic_stack_[(3) - (2)].astring);
     }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 1236 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        if (driver.in_console)
          GB_main_wxFrame->GetConsole()
                          ->IncCommand(wxString::FromAscii(inc_cmd.c_str()));
      }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 1271 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      string_ptr inputstring( new std::string((yysemantic_stack_[(2) - (2)].astring)));
      driver.parse_string( *inputstring,
                          "'eval string' command");
     }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 1277 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        Variable*       var   = (yysemantic_stack_[(5) - (1)].variable);
        ParamList::ptr  param((yysemantic_stack_[(5) - (3)].paramlist));

        driver.yyip_call_function(var,param);


        }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 1286 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable*    var   = (yysemantic_stack_[(2) - (1)].variable);

          // Call the function
          driver.yyip_call_function(var);
        }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 1295 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
          Description:
            Sets the number of command line arguments to 1 (name of the program)
          **/
          GB_argc = 1;
         }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 1303 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           YYABORT;
         }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1308 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 42:

/* Line 678 of lalr1.cc  */
#line 1322 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 43:

/* Line 678 of lalr1.cc  */
#line 1336 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 44:

/* Line 678 of lalr1.cc  */
#line 1350 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
         Description:
         Set a local context for variables
         **/
       Vars.SetLastContext();
       Vars.SetGlobalNew(0);
         }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1360 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 46:

/* Line 678 of lalr1.cc  */
#line 1376 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (3) time in ms
            (5) function to schedule
        **/

        // TODO To avoid pbs, make sure that the variable does not disappears
        // by making a copy of it
        int ms = (int) (yysemantic_stack_[(6) - (3)].adouble);
        Variable*    var   = (yysemantic_stack_[(6) - (5)].variable);

        wxScheduleTimer::ptr w = wxScheduleTimer::ptr(new wxScheduleTimer( var ));
        // add to the list of schedule timers
        schedule_timers.push_back(w);
        w->Start(ms,wxTIMER_ONE_SHOT);

      }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1396 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            VarArray* arraysurf;
            IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));

            int size = (int) (yysemantic_stack_[(6) - (5)].adouble);
            if (size<1) size = 1;
            arraysurf = new VarArray();
            arraysurf->Init(type_surface,size);
            Vars.AddVar(type_array,ident,arraysurf);
          }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1408 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            VarArray* arraysurf;
            IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));
            int size = (int) (yysemantic_stack_[(6) - (5)].adouble);
            if (size<1) size = 1;
            arraysurf = new VarArray();
            arraysurf->Init(type_surface,size);
            Vars.AddVar(type_array,ident,arraysurf);
          }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1419 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));
            VarArray* array;
            int size = (int) (yysemantic_stack_[(6) - (5)].adouble);
            if (size<1) size = 1;
            array = new VarArray();
            array->Init(type_image,size);
            Vars.AddVar(type_array,ident,array);
          }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 1430 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          void * imptr;
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));

          imptr = (void*)driver.im_stack.GetLastImage();
          if (imptr != NULL)
            Vars.AddVar(type_image,ident,imptr);
          else
            driver.err_print((boost::format("assignment of NULL image for %1%  \n") % (yysemantic_stack_[(3) - (1)].ident)).str().c_str() );;
        }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 1442 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          void * imptr;
          imptr = (void*)driver.im_stack.GetLastImage();
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));

          if (imptr != NULL)
            Vars.AddVar(type_image,ident,imptr);
          else
            driver.err_print((boost::format("assignment of NULL image for %1%  \n") %(yysemantic_stack_[(3) - (1)].ident)).str().c_str() );;
        }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 1453 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Calls a wrapped function that returns a smart pointer to a variable, requires a new variable name as a result
        **/
          Variable*      var   = (yysemantic_stack_[(6) - (3)].variable);
          ParamList::ptr param((yysemantic_stack_[(6) - (5)].paramlist));
          Variable::ptr  res;
          IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));

          res = ((Variable::ptr (*)(ParamList*)) var->Pointer())(param.get());
          if (!res.use_count()) {
            driver.yyiperror(" function returns NULL \n");
            YYABORT;
          }
          res->Rename(ident->GetName().c_str());
          Vars.AddVar(res,ident->GetCreationContext());
        }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 1473 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          VarArray::ptr array;
          void * imptr = (void*)driver.im_stack.GetLastImage();
          int  i = (int) (yysemantic_stack_[(6) - (3)].adouble);
          char name[256];

          array = *((VarArray::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer()));
          if (imptr != NULL)
            if (array->GetVar(i).Pointer()==NULL) {
              sprintf(name,"%s[%d]",(yysemantic_stack_[(6) - (1)].variable)->Name().c_str(),i);
              array->InitElement(i,imptr,name);
            }
            else
            {
              driver.err_print("array element already assigned\n");
              delete (InrImage*)imptr;
            }
          else
            driver.err_print("assignment of NULL image\n");
        }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 1495 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          void * imptr;
          imptr = (void*) driver.matrix_stack.GetLastMatrix();
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));

          if (imptr != NULL)
        Vars.AddVar(type_matrix,ident,imptr);
          else
        driver.err_print("assignment of NULL matrix\n");
        }
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 1507 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          void * imptr;
          imptr = (void*)driver.gltransf_stack.GetLastMatrix();
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));

          if (imptr != NULL)
            Vars.AddVar(type_gltransform,ident,imptr);
          else
            driver.err_print("assignment of NULL matrix\n");
        }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 1518 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr m1 = *((FloatMatrix::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer()));
          (*m1) = (yysemantic_stack_[(3) - (3)].adouble);
       }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 1523 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr m1 = *((FloatMatrix::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer()));
          FloatMatrix* m2 = driver.matrix_stack.GetLastMatrix();
          (*m1) = m2;
          printf("delete m2\n");
          delete m2;
          printf("delete m2 end\n");
       }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 1533 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          VarArray::ptr array;
          void * surfptr;
          int  i = (int) (yysemantic_stack_[(6) - (3)].adouble);
          char name[256];

          array = *((VarArray::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer()));
          surfptr = (void*)driver.surf_stack.GetLastSurf();
          if (surfptr != NULL)
          if (array->GetVar(i).Pointer()==NULL) {
            sprintf(name,"%s[%d]",(yysemantic_stack_[(6) - (1)].variable)->Name().c_str(),i);
            array->InitElement(i,surfptr,name);
          }
          else
          {
            driver.err_print("array element already assigned\n");
            delete (SurfacePoly*)surfptr;
          }
          else
            driver.err_print("assignment of NULL surface\n");
        }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 1556 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variables* contextptr = new Variables();
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
          contextptr->SetName(ident->GetName());

          Vars.AddVar(type_context,ident,(void*)contextptr);
        }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1565 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          void * surfptr;
          surfptr = (void*)driver.surf_stack.GetLastSurf();
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));

          if (surfptr != NULL)
            Vars.AddVar(type_surface,ident,surfptr);
          else
            driver.err_print("assignment of NULL surface\n");
        }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1577 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable* var = (yysemantic_stack_[(3) - (1)].variable);
          void* surfptr  = (void*) driver.surf_stack.GetLastSurf();

          // instead of deleting and creating,
          // replace the pointer and the information
          if (surfptr != NULL) {
            var->FreeMemory();
            var->Init(type_surface,
                      var->Name().c_str(),
                      surfptr);
          }
          else
            driver.err_print("assignment of NULL surface\n");

        }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1595 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable* var = (yysemantic_stack_[(6) - (1)].variable);
          VarArray* arraysurf;
          int size = (int) (yysemantic_stack_[(6) - (5)].adouble);
          if (size<1) size = 1;
          arraysurf = new VarArray();
          arraysurf->Init(type_surface,size);

          // instead of deleting and creating,
          // replace the pointer and the information
          if (arraysurf != NULL) {
            var->FreeMemory();
            var->Init(type_array,
                      var->Name().c_str(),
                      arraysurf);
          }
          else
            driver.err_print("not able to create surface array !\n");

      }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1617 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description: 
          Creates a variable of type int
      **/
        int* varint;
        IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));

        varint = new int((int)(yysemantic_stack_[(6) - (5)].adouble));
        Vars.AddVar(type_int,ident,(void*)varint);
      }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1630 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Parameters:
        - identifier: name of the new variable
        - expr: value of the new variable
        - expr_string: short description of the new variable
        Description: 
          Creates a variable of type int
      **/
        int* varint;
        IdentifierInfo::ptr ident((yysemantic_stack_[(8) - (1)].ident));

        varint = new int((int)(yysemantic_stack_[(8) - (5)].adouble));
        Variable* var=Vars.AddVar(type_int,ident,(void*)varint);
        string_ptr comments( new std::string((yysemantic_stack_[(8) - (8)].astring)));
        var->SetComments(*comments);
      }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1649 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description: 
          Creates a variable of type unsigned char (used for boolean type too)
      **/
        unsigned char* varuchar;
        IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));

        varuchar = new unsigned char((unsigned char)(yysemantic_stack_[(6) - (5)].adouble));
        Vars.AddVar(type_uchar,ident,(void*)varuchar);
      }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1662 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Parameters:
        - identifier: name of the new variable
        - expr: value of the new variable
        - expr_string: short description of the new variable
      Description: 
        creates a variable of type unsigned char (used for boolean type too)
      **/
        unsigned char* varuchar;
        IdentifierInfo::ptr ident((yysemantic_stack_[(8) - (1)].ident));

        varuchar = new unsigned char((unsigned char)(yysemantic_stack_[(8) - (5)].adouble));
        Variable* var=Vars.AddVar(type_uchar,ident,(void*)varuchar);
        string_ptr comments( new std::string((yysemantic_stack_[(8) - (8)].astring)));
        var->SetComments(*comments);
      }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1681 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description: 
          Creation of a new floating point number variable
      **/
          float* varfloat;
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
          varfloat = new float((yysemantic_stack_[(3) - (3)].adouble));

          Vars.AddVar(type_float,ident,(void*)varfloat);
        }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1694 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Parameters:
          - identifier: name of the new variable
          - expr: value of the new variable
          - expr_string: short description of the new variable
        Description: 
          Creation of a new floating point number variable
      **/
        float* varfloat;
        IdentifierInfo::ptr ident((yysemantic_stack_[(5) - (1)].ident));
        varfloat = new float((yysemantic_stack_[(5) - (3)].adouble));

        Variable* var = Vars.AddVar(type_float,ident,(void*)varfloat);
        string_ptr comments( new std::string((yysemantic_stack_[(5) - (5)].astring)));
        var->SetComments(*comments);
      }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1713 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description: 
          Creation of a new string variable
      **/
          string* varstring;
          varstring = new string((yysemantic_stack_[(3) - (3)].astring));
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));

          Vars.AddVar(type_string,ident,(void*)varstring);
          delete [] (yysemantic_stack_[(3) - (3)].astring);
      }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1727 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Parameters:
          - identifier: name of the new variable
          - expr_string: value of the new variable
          - expr_string: short description of the new variable
        Description: 
          Creation of a new string variable
      **/
        string_ptr value( new std::string((yysemantic_stack_[(5) - (3)].astring)));
        string* varstring;
        varstring = new string(value->c_str());
        IdentifierInfo::ptr ident((yysemantic_stack_[(5) - (1)].ident));

        Variable* var = Vars.AddVar(type_string,ident,(void*)varstring);
        string_ptr comments( new std::string((yysemantic_stack_[(5) - (5)].astring)));
        var->SetComments(*comments);
      }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1747 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FILE* file;
          IdentifierInfo::ptr ident((yysemantic_stack_[(8) - (1)].ident));

          file = fopen((yysemantic_stack_[(8) - (5)].astring),(yysemantic_stack_[(8) - (7)].astring));
          if (file!=NULL) {
            Vars.AddVar(type_file,ident,(void*)file);
          } else {
            fprintf(stderr,"error opening file '%s' in mode '%s'\n",
                      (yysemantic_stack_[(8) - (5)].astring),(yysemantic_stack_[(8) - (7)].astring));
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

  case 72:

/* Line 678 of lalr1.cc  */
#line 1780 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            std::string filename((yysemantic_stack_[(8) - (1)].variable)->Name());
            Variable* var;

            if (Vars.GetVar(filename.c_str(),&var))
                Vars.deleteVar(filename.c_str());

            FILE* file;
            file = fopen((yysemantic_stack_[(8) - (5)].astring),(yysemantic_stack_[(8) - (7)].astring));
            if (file!=NULL) {
                Vars.AddVar(type_file,filename.c_str(),(void*)file);
            } else {
              fprintf(stderr,"error opening file '%s' in mode '%s'\n",
                      (yysemantic_stack_[(8) - (5)].astring),(yysemantic_stack_[(8) - (7)].astring));
            }
        }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1797 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
            rewind(file.get());
        }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1802 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 1;
        }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1806 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 0;
        }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1810 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 1;
      verbose = 1;
    }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 1815 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 0;
    }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 1819 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description:
        Adds a new link to a script from the menus
      Parameters:
        - string expression: category of the script
        - string expression: menu label
        - string expression: script name
   **/
          string_ptr category( new std::string((yysemantic_stack_[(8) - (3)].astring)));
          string_ptr label(    new std::string((yysemantic_stack_[(8) - (5)].astring)));
          string_ptr script(   new std::string((yysemantic_stack_[(8) - (7)].astring)));
          GB_main_wxFrame->AddMenuScript(*category,*label,*script);
    }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 1834 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1844 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameter:
        String: input text
      Description:
        Set the given text in the status bar
    **/
        string_ptr text( new std::string((yysemantic_stack_[(4) - (3)].astring)));
        GB_main_wxFrame->SetStatusText( (*text) );
    }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 1854 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GB_main_wxFrame->Close(true);
        }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 1858 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          std::string titre;
          Variable* imagevar = (yysemantic_stack_[(2) - (2)].variable);
          Variable* var;
          int var_context = Vars.GetContext(imagevar);

          Variables::ptr previous_ocontext = Vars.GetObjectContext();
          if (var_context==OBJECT_CONTEXT_NUMBER) {
            // set new object context
            Vars.SetObjectContext(imagevar->GetContext());
          }

          if ((var_context>=0)||
              (var_context==OBJECT_CONTEXT_NUMBER)) {
            titre = (boost::format("%s_draw") % (yysemantic_stack_[(2) - (2)].variable)->Name().c_str()).str();
            FILE_MESSAGE(boost::format("SHOW var_image  title %s") % titre);
            //if (Vars.GetCurrentContext()->GetVar(titre,&var)) {
            if (Vars.GetVar(titre.c_str(),&var,var_context)) {
              DessinImageParametres* param;
              DessinImage::ptr di;
              di = *((DessinImage::ptr*) var->Pointer());
              param = di->GetParam();
              param->_MAJ.MAJCoupes();
              di->Paint();
            }
            else
            {
              FILE_MESSAGE(boost::format("SHOW var_image creating title %s ") % titre);
              DessinImage* di;

              std::string varname(titre);

              di = CreateIDraw( varname,
                    *((InrImage::ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer()));

              Variable* newvar = Vars.AddVar(type_imagedraw,titre.c_str(), (void*) di,
                          var_context);
              di->SetCloseFunction(
                (void*) CB_delete_imagedraw,
                (void*) (newvar));
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
#line 1908 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          char titre[100];
          Variable* var;

          sprintf(titre,"%s_draw",(yysemantic_stack_[(2) - (2)].variable)->Name().c_str());
          if (Vars.GetVar(titre,&var)) {

        if (var->Type() == type_imagedraw) {
            driver.err_print("Hide window \n");
            (*(DessinImage::ptr*) var->Pointer())->Hide();
        }
        else
          fprintf(stderr,"Variable %s_draw not of type imagedraw \n",
            (yysemantic_stack_[(2) - (2)].variable)->Name().c_str());
          } else
        fprintf(stderr,"Image %s not visible \n",
            (yysemantic_stack_[(2) - (2)].variable)->Name().c_str());

        }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1928 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          string    titre;
          Viewer3D* surfdraw;
          Variable* imagevar = (yysemantic_stack_[(2) - (2)].variable);
          Variable* var;
          int var_context = Vars.GetContext(imagevar);

          Variables::ptr previous_ocontext = Vars.GetObjectContext();
          if (var_context==OBJECT_CONTEXT_NUMBER) {
            // set new object context
            Vars.SetObjectContext(imagevar->GetContext());
          }

          if ((var_context>=0)||
              (var_context==OBJECT_CONTEXT_NUMBER)) {
            titre = str(format("%s_draw") % (yysemantic_stack_[(2) - (2)].variable)->Name());
            if (!Vars.GetVar(titre.c_str(),&var,var_context)) {
              surfdraw = new Viewer3D(  GB_main_wxFrame,
                                        wxString::FromAscii(titre.c_str()));

              Variable* newvar =  Vars.AddVar(type_surfdraw,titre.c_str(),
                          (void*) surfdraw,
                          var_context);
              surfdraw->SetCloseFunction(
                              (void*) CB_delete_surfdraw,
                              (void*) (newvar));

              surfdraw->Show(true);
              // Add the surface to the OpenGL Object
              surfdraw->GetCanvas()->AddSurface(
                                *(SurfacePoly::ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer());
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
#line 1973 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          // Create the main frame window
          PenguinFrame *frame = new PenguinFrame(GB_main_wxFrame, wxT("wxWidgets Penguin Sample"),
              wxDefaultPosition, wxDefaultSize);

          #if wxUSE_ZLIB
            if (wxFileExists(wxT("penguin.dxf.gz")))
              frame->GetCanvas()->LoadDXF(wxT("penguin.dxf.gz"));
          #else
            if (wxFileExists(wxT("penguin.dxf")))
              frame->GetCanvas()->LoadDXF(wxT("penguin.dxf"));
          #endif

          // Show the frame
          frame->Show(true);
        }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1990 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage::ptr i1 = *(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          InrImage::ptr i2 = InrImage::ptr(driver.im_stack.GetLastImage());

          if (i2.get()) {
            // copy option
            if (!((*i1)=(*i2))) driver.err_print(" Error in images assignement\n");
          } else {
            driver.err_print("Error\n");
          }
        }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 2002 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Replacing the previous image by the new one.
        **/
          Variable* var = (yysemantic_stack_[(3) - (1)].variable);
          InrImage::ptr i1 = *(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          InrImage* imptr  = driver.im_stack.GetLastImage();
          bool can_skip_allocation = false;

          if (i1.get()!=imptr) {
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
                // then delete imptr
                delete imptr;
              }
            }
            if (!can_skip_allocation) {
              // instead of deleting and creating,
              // replace the pointer and the information
              if (imptr != NULL) {
                var->FreeMemory();
                var->Init(type_image,
                          var->Name().c_str(),
                          (void*)imptr);
              }
              else
                driver.err_print("assignment of NULL image\n");
            } // end if (!can_skip_allocation)
          } // end if (i1.get()!=imptr)
        }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 2042 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
        (1) image
        (3) expression

        Description:
        Sets the whole image to a constant value given by expression.
        **/
          InrImage::ptr i1 = *(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          i1->InitImage((yysemantic_stack_[(3) - (3)].adouble));
        }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 2055 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
        (1) image: vectorial or RGB input image
        (3) n: component index
        (6) imageval: image expression

        Description:
        assigns imageval to the component 'n' of the input image
        **/
          int comp = (int) (yysemantic_stack_[(6) - (3)].adouble);

          InrImage::ptr i1 = *(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
          InrImage::ptr i2 = InrImage::ptr(
                                driver.im_stack.GetLastImage());

          Si (comp<0) Ou (comp>i1->GetVDim()) Alors
            fprintf(stderr,"image[n]=image error index too high, reset to 0 \n");
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
            driver.yyiperror("image[]=image\t second image has to be scalar \n");
            YYABORT;
          FinSi

        }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 2090 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
        (1) image: vectorial or RGB input image
        (3) n: component index
        (6) val: numerical expression

        Description:
        assigns the value val to every component 'n' of the input image
        **/
          int comp = (int) (yysemantic_stack_[(6) - (3)].adouble);

          Si (comp<0) Ou (comp>2) Alors
        fprintf(stderr,"image[n]=image error \n");
        comp = 0;
          FinSi

         InrImage::ptr i1 = *(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();

          Si i1->VectorialFormat()  Alors

             i1->InitBuffer();
             Repeter
           i1->VectFixeValeur(comp,(yysemantic_stack_[(6) - (6)].adouble));
             JusquA Non(i1->IncBuffer()) FinRepeter

      FinSi

        }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 2120 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description: Pads the image ...
        **/
          int posx  = (int) (yysemantic_stack_[(16) - (3)].adouble);
          int stepx = (int) (yysemantic_stack_[(16) - (5)].adouble);
          int posy  = (int) (yysemantic_stack_[(16) - (7)].adouble);
          int stepy = (int) (yysemantic_stack_[(16) - (9)].adouble);
          int posz  = (int) (yysemantic_stack_[(16) - (11)].adouble);
          int stepz = (int) (yysemantic_stack_[(16) - (13)].adouble);


          InrImage::ptr i1 = *(InrImage::ptr*) (yysemantic_stack_[(16) - (1)].variable)->Pointer();
          InrImage::ptr i2 = InrImage::ptr(driver.im_stack.GetLastImage());

          Func_Pad(i1.get(),i2.get(),stepx,posx,stepy,posy,stepz,posz);


        }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 2140 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(float_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))++;
        }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 2144 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(float_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))--;
        }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 2148 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          *(*(float_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer()) = (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 2152 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(int_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))++;
        }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 2156 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(int_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))--;
        }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 2160 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          *(*(int_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer()) = (int) (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 2164 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           *(*(uchar_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer()) = (unsigned char) (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 2168 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (*(*(uchar_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))++;
        }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 2172 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (*(*(uchar_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))--;
        }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 2176 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          string_ptr newname( new std::string((yysemantic_stack_[(3) - (3)].astring)));
          (yysemantic_stack_[(3) - (1)].variable)->SetString(newname);
        }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 2181 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Vars.display();
        }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 2185 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Parameters:
              variable: input variable
              string expression: comments
          Description: Set comments for a variable
        **/
          string_ptr comments( new std::string((yysemantic_stack_[(6) - (5)].astring)));
          (yysemantic_stack_[(6) - (1)].variable)->SetComments(*comments);
        }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 2196 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description: 
            Delete the given variable
        **/
         /*Variable* var;

         if (Vars.GetVar($2->Name(),&var))
         Vars.deleteVar($2->Name());
         */
         Vars.deleteVar((yysemantic_stack_[(2) - (2)].variable));
        }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 2209 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description: 
            Delete all variables that match the expression, where the expression can contain 
            '*' and '?' characters
        **/
        string_ptr varmatch( new std::string((yysemantic_stack_[(2) - (2)].astring)));
         Vars.deleteVars( *varmatch);
        }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 2219 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          VarArray::ptr array = *(VarArray::ptr*) ((yysemantic_stack_[(5) - (2)].variable)->Pointer());;
          int  i = (int) (yysemantic_stack_[(5) - (4)].adouble);

          if (array->GetVar(i).Pointer()!=NULL) {
            array->GetVar(i).FreeMemory();
          }
      }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 2228 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Parameters:
          - string expression: command to call
        Description:
          calls a command from the system using std::system()
      **/
        string_ptr cmd( new std::string((yysemantic_stack_[(2) - (2)].astring)));
        std::system( cmd->c_str());
      }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 2239 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//         std::ostream streamtest(TC->GetLog());
//        std::cout=streamtest;
         //wxStreamToTextRedirector redirect(TC->GetLog());

         std::system("ls");
           }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 2247 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 110:

/* Line 678 of lalr1.cc  */
#line 2259 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
         driver.res_print("\t\t\t - basic_type are CHAR UCHAR SHORT USHORT FLOAT DOUBLE RGB FLOAT_VECTOR \n");
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


         driver.res_print("\t image = AnisoGS.init( var_image, expr, expr, expr )\n");
         driver.res_print("\t\t  expr 1:    sigma  \n");
         driver.res_print("\t\t  expr 2:    theshold  \n");
         driver.res_print("\t\t  expr 3:    data attachment coeff  \n");
         driver.res_print("\t AnisoGS.setcoeff( expr )\n");
         driver.res_print("\t\t  expr 1:    tangential coeff  \n");
         driver.res_print("\t AnisoGS.setcoeff( expr, expr )\n");
         driver.res_print("\t\t  expr 1:    min curv coeff  \n");
         driver.res_print("\t\t  expr 2:    max curv coeff  \n");
         driver.res_print("\t AnisoGS.iterate\n");
         driver.res_print("\t AnisoGS.end\n");

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

  case 111:

/* Line 678 of lalr1.cc  */
#line 2508 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        Displays the documentation relative to the wrapped image function.
    **/
       Variable*  var   = (yysemantic_stack_[(2) - (2)].variable);
        // call with NULL paramlist pointer to trigger help message
       ((InrImage* (*)(ParamList*)) var->Pointer())(NULL);
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 2518 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        Displays the documentation relative to the wrapped image function.
    **/
       Variable*  var   = (yysemantic_stack_[(2) - (2)].variable);
        // call with NULL paramlist pointer to trigger help message
        ((Variable::ptr (*)(ParamList*)) var->Pointer())(NULL);
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 2528 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        Displays the documentation relative to the wrapped image function.
    **/
       Variable*  var   = (yysemantic_stack_[(2) - (2)].variable);
        // call with NULL paramlist pointer to trigger help message
        ((void (*)(ParamList*)) var->Pointer())(NULL);
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 2538 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 115:

/* Line 678 of lalr1.cc  */
#line 2592 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(4) - (1)].variable)->Pointer());
          string_ptr text( new std::string((yysemantic_stack_[(4) - (4)].astring)));

          fprintf(file.get(),"%s",text->c_str());
          fflush(file.get());
        }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 2600 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(4) - (1)].variable)->Pointer());
          string_ptr text( new std::string((yysemantic_stack_[(4) - (4)].astring)));

          fprintf(file.get(),"%s\n",text->c_str());
          fflush(file.get());
        }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 2608 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
          Description:
            Print a string
          **/
          driver.res_print((yysemantic_stack_[(2) - (2)].astring));
          delete [] (yysemantic_stack_[(2) - (2)].astring);
        }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 2617 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
          Description:
            Print a string and newline
          **/
        driver.res_print((yysemantic_stack_[(2) - (2)].astring));
        driver.res_print("\n");
        delete [] (yysemantic_stack_[(2) - (2)].astring);
      }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 2627 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=driver.matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
      }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 2633 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 121:

/* Line 678 of lalr1.cc  */
#line 2644 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=driver.matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
          }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 2650 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(4) - (1)].variable)->Pointer());

          fprintf(file.get(),"%5.10f",(yysemantic_stack_[(4) - (4)].adouble));
          fflush(file.get());
        }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 2657 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            printf("Files are not close anymore: delete the variable instead \n");
          //FILE_ptr file = *(FILE_ptr*) ($1->Pointer());
          //fclose(file.get());
        }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 2663 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Prints a numerical value.
        **/
          string st;
          st = str(format("%5.10f") % (yysemantic_stack_[(2) - (2)].adouble));
          driver.res_print(st.c_str());
        }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 2673 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Prints a numerical value and a newline.
        **/
          string st;
          st = str(format("%5.10f\n") %(yysemantic_stack_[(2) - (2)].adouble));
          driver.res_print(st.c_str());
        }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 2683 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          DessinImageParametres* param;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(10) - (1)].variable)->Pointer());
          param = draw->GetParam();
          param->_pos._x = (int) (yysemantic_stack_[(10) - (5)].adouble);
          param->_pos._y = (int) (yysemantic_stack_[(10) - (7)].adouble);
          param->_pos._z = (int) (yysemantic_stack_[(10) - (9)].adouble);
          //      param->_pos.Check();
          param->_MAJ.MAJCoupes();

          draw->Paint();

        }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 2699 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          DessinImageParametres* param;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          param = draw->GetParam();
          param->_curseur._visible = (int) ((yysemantic_stack_[(6) - (5)].adouble)>0.5);
          //      param->_MAJ.MAJCoupes();

          draw->Paint();
        }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 2711 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          DessinImageParametres* param;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
          param = draw->GetParam();
          param->_MAJ.MAJCoupes();
          draw->Paint();
        }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 2721 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            DessinImage::ptr draw;
            InrImage::ptr im;
            char title[255];
            Variable* var;

            draw = *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
            im   = *(InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer();

            sprintf(title,"%s_draw",(yysemantic_stack_[(6) - (5)].variable)->Name().c_str());

            if (Vars.GetCurrentContext()->GetVar(title,&var)) {
              DessinImage::ptr di;
              DessinImageParametres* param;
              di = *(DessinImage::ptr*) var->Pointer();
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
              DessinImage* di;
              std::string varname(title);
              di = CreateIDraw( varname, im);

              Variable* newvar = Vars.AddVar(type_imagedraw,title, (void*) di);
              di->SetCloseFunction(
                  (void*) CB_delete_imagedraw,
                  (void*) (newvar));
              // get the pointer to the newly created
              // variable
              Variable* var;
              if (Vars.GetVar(title,&var))
                draw->CreeCompare2Image(*(DessinImage::ptr*)var->Pointer());
              else
                fprintf(stderr,"Image comparison: Variable %s not found !\n",title);
            }

        }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 2769 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        DessinImage::ptr draw1;
        DessinImage::ptr draw2;

          draw1 = *(DessinImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
          draw2 = *(DessinImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer();

/*          std::string* varname = new std::string($5->Name());
          draw2->SetCloseFunction(
                  (void*) CB_delete_imagedraw,
                  (void*) varname);
*/
          draw1->CreeCompare2Image(draw2);
        }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 2784 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          DessinImage::ptr draw;
          DessinImage::ptr draw2;
          InrImage::ptr displ;

          draw  = *(DessinImage::ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
          draw2 = *(DessinImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer();
          displ = *(InrImage::ptr*)    (yysemantic_stack_[(8) - (7)].variable)->Pointer();
          draw->SetCompareDisplacement(draw2,displ);
        }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 2809 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        DessinImage::ptr draw;
        FloatMatrix* mat;

        draw = *(DessinImage::ptr*) ((yysemantic_stack_[(28) - (1)].variable)->Pointer());

        mat = new FloatMatrix(4,4);
        (*mat)[0][0] = (yysemantic_stack_[(28) - (5)].adouble);
        (*mat)[0][1] = (yysemantic_stack_[(28) - (7)].adouble);
        (*mat)[0][2] = (yysemantic_stack_[(28) - (9)].adouble);
        (*mat)[0][3] = (yysemantic_stack_[(28) - (11)].adouble);
        (*mat)[1][0] = (yysemantic_stack_[(28) - (13)].adouble);
        (*mat)[1][1] = (yysemantic_stack_[(28) - (15)].adouble);
        (*mat)[1][2] = (yysemantic_stack_[(28) - (17)].adouble);
        (*mat)[1][3] = (yysemantic_stack_[(28) - (19)].adouble);
        (*mat)[2][0] = (yysemantic_stack_[(28) - (21)].adouble);
        (*mat)[2][1] = (yysemantic_stack_[(28) - (23)].adouble);
        (*mat)[2][2] = (yysemantic_stack_[(28) - (25)].adouble);
        (*mat)[2][3] = (yysemantic_stack_[(28) - (27)].adouble);

            if (draw->GetCompareWindow(0)!=NULL)
          draw->GetCompareWindow(0)->SetTransformationMatrix(mat);
        // PB: the matrix is never freed from memory ...
        // TODO use smart pointer management !!!

        }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 2836 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Parameters:
                (1) Image Drawing window
                (5) Index of the vector field to be drawned (between 1 and 3)
                (7) Vector field image
            Description:
                Assign a vector field to be draw in the given image drawing window.
          **/
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(8) - (1)].variable)->Pointer());
          draw->LoadVectImage( (int) (yysemantic_stack_[(8) - (5)].adouble), (*(InrImage::ptr*) (yysemantic_stack_[(8) - (7)].variable)->Pointer()));
        }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 2851 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(8) - (1)].variable)->Pointer());
          draw->SetVectorVisible( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 2858 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
          draw->CB_AfficheChampVect(draw.get(),NULL);
        }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 2865 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
          Parameters:
            (5) expression: vector size
            (7) expression: vector spacing

          Description:
            Sets the size and spacing of the vector drawing interface in the given
            image drawing window.
          **/
          DessinImage::ptr draw;
          float size    = (yysemantic_stack_[(8) - (5)].adouble);
          int   spacing = (int)(yysemantic_stack_[(8) - (7)].adouble);

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(8) - (1)].variable)->Pointer());
          draw->SetVectParam( size, spacing);
        }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 2883 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          DessinImage::ptr draw;
          int vectid = (int) (yysemantic_stack_[(12) - (5)].adouble);
          unsigned char red   = (unsigned char) (yysemantic_stack_[(12) - (7)].adouble);
          unsigned char green = (unsigned char) (yysemantic_stack_[(12) - (9)].adouble);
          unsigned char blue  = (unsigned char) (yysemantic_stack_[(12) - (11)].adouble);

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(12) - (1)].variable)->Pointer());
          draw->SetVectColor( vectid,red,green,blue);
        }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 2906 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw= *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          draw->SetVectType((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 2911 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw= *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          draw->SetLineThickness((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 2916 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          int xmin = (int)  (yysemantic_stack_[(16) - (5)].adouble);
          int ymin = (int)  (yysemantic_stack_[(16) - (7)].adouble);
          int zmin = (int)  (yysemantic_stack_[(16) - (9)].adouble);
          int xmax = (int) (yysemantic_stack_[(16) - (11)].adouble);
          int ymax = (int) (yysemantic_stack_[(16) - (13)].adouble);
          int zmax = (int) (yysemantic_stack_[(16) - (15)].adouble);

          DessinImage::ptr draw= *(DessinImage::ptr*) ((yysemantic_stack_[(16) - (1)].variable)->Pointer());
          draw->SetZoom(xmin,ymin,zmin,xmax,ymax,zmax);

        }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 2929 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          int width  = (int) (yysemantic_stack_[(8) - (5)].adouble);
          int height = (int) (yysemantic_stack_[(8) - (7)].adouble);

          DessinImage::ptr draw= *(DessinImage::ptr*) ((yysemantic_stack_[(8) - (1)].variable)->Pointer());
          draw->SetSize(width,height);
          draw->Update();


        }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 2940 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          ClasseCouleur c;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(16) - (1)].variable)->Pointer());
          c.FixeValeur((int)(yysemantic_stack_[(16) - (11)].adouble),(int)(yysemantic_stack_[(16) - (13)].adouble),(int)(yysemantic_stack_[(16) - (15)].adouble));
          draw->DessineCercle( (int) (yysemantic_stack_[(16) - (5)].adouble), (int) (yysemantic_stack_[(16) - (7)].adouble), (int) (yysemantic_stack_[(16) - (9)].adouble), c);
        }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 2949 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          // TODO: fix this memory problem ...
          InrImage* colmap=(InrImage*) driver.im_stack.GetLastImage();

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(10) - (1)].variable)->Pointer());
          draw->SetUserColormap( colmap,  (yysemantic_stack_[(10) - (7)].adouble),  (yysemantic_stack_[(10) - (9)].adouble));
          //      delete colmap;
        }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 2959 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          draw->SetGLWindow( *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer()));

        }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 2967 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) isocontour index (0,1 or 2)
                (7) image to use for the isocontour
                (9) intensity value of the isocontour

            Description:
                Sets the image and intensity value of an isocontour in an 'image_draw' window.
            **/
            DessinImage::ptr draw;

            draw = *(DessinImage::ptr*) ((yysemantic_stack_[(10) - (1)].variable)->Pointer());
            draw->InitIsoContour( (*(InrImage::ptr*) (yysemantic_stack_[(10) - (7)].variable)->Pointer()), (yysemantic_stack_[(10) - (9)].adouble) , (int) (yysemantic_stack_[(10) - (5)].adouble) );
            draw->DrawIsoContour( (int) (yysemantic_stack_[(10) - (5)].adouble), true );
        }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 2984 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) image to use for the isocontour
                (7) intensity value of the isocontour

            Description:
                Sets the image and intensity value of the isocontour number 0 in an 'image_draw' window.
            **/
            DessinImage::ptr draw;

            draw = *(DessinImage::ptr*) ((yysemantic_stack_[(8) - (1)].variable)->Pointer());
            draw->InitIsoContour( (*(InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer()), (yysemantic_stack_[(8) - (7)].adouble) , 0 );
            draw->DrawIsoContour( 0, true );
        }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 3000 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
            DessinImage::ptr draw;

            draw = *(DessinImage::ptr*) ((yysemantic_stack_[(10) - (1)].variable)->Pointer());
            draw->SetIsoContourParam( (int)(yysemantic_stack_[(10) - (5)].adouble), (int)(yysemantic_stack_[(10) - (7)].adouble), (int)(yysemantic_stack_[(10) - (9)].adouble) );
        }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 3017 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
            DessinImage::ptr draw;

            draw = *(DessinImage::ptr*) ((yysemantic_stack_[(14) - (1)].variable)->Pointer());
            draw->SetIsoContourParam( (int)(yysemantic_stack_[(14) - (5)].adouble), (int)(yysemantic_stack_[(14) - (7)].adouble), (int)(yysemantic_stack_[(14) - (9)].adouble) );
            draw->SetLineAttributes( (int)(yysemantic_stack_[(14) - (11)].adouble), (int)(yysemantic_stack_[(14) - (13)].adouble));
        }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 3037 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) isocontour index (0,1 or 2)
                (7) visible or not (0 or 1)

            Description:
                Sets the visibility of an isocontour in an 'image_draw' window.
            **/
            DessinImage::ptr draw;

            draw = *(DessinImage::ptr*) ((yysemantic_stack_[(8) - (1)].variable)->Pointer());
            draw->DrawIsoContour( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble) );
        }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 3052 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
            DessinImage::ptr draw;
            draw = *(DessinImage::ptr*) ((yysemantic_stack_[(12) - (1)].variable)->Pointer());
            draw->SetIsoContourColor( (int) (yysemantic_stack_[(12) - (5)].adouble), (unsigned char) (yysemantic_stack_[(12) - (7)].adouble),
                                                (unsigned char) (yysemantic_stack_[(12) - (9)].adouble),
                                                (unsigned char) (yysemantic_stack_[(12) - (11)].adouble));
        }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 3070 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) boolean parameter

            Description:
                Activates or desactivates the drawing of a series of isocontours.
            **/
            DessinImage::ptr draw;
            draw = *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
            draw->SetDrawAllContours( (int) (yysemantic_stack_[(6) - (5)].adouble) );
        }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 3083 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) intensity step between isocontours
                (7) half size of the intensity range where to draw isocontours

            Description:
                Parameters for drawing a series of isocontours around the main isocontour.
            **/
            DessinImage::ptr draw;
            draw = *(DessinImage::ptr*) ((yysemantic_stack_[(8) - (1)].variable)->Pointer());
            draw->AllContoursParam(  (yysemantic_stack_[(8) - (5)].adouble) , (yysemantic_stack_[(8) - (7)].adouble) );
        }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 3097 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            DessinImage::ptr draw;

            draw = *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
            draw->SetPaintCallback( (void*) CB_ParamWin, (void*) (yysemantic_stack_[(6) - (5)].variable));
            // may be a pb to call Paint() here since it will start another interpreter ??? to check
            //draw->Paint();
        }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 3106 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
         Description:
            Setting the opacity image for the volume rendering.
            This image should have unsigned char values.
         **/
          DessinImage::ptr draw;
          InrImage::ptr im;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          im = *(InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer();
          draw->SetVolRenOpacity( im.get());
        }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 3120 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (5) expr:  value to init the image

        Description:
          Set the whole image to the same vector value .
        **/
          (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->InitImage((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 3131 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (5) expr:  X coord of the init vector
          (7) expr:  Y coord of the init vector
          (9) expr:  Z coord of the init vector

        Description:
          Set the whole image to the same value.
        **/
      (*(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->InitImage((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
        }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 3144 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->FixeValeur((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 3162 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      (*(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->VectFixeValeurs((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
        }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 3184 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          Si (*(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->CoordOK( (int) (yysemantic_stack_[(10) - (5)].adouble),(int)(yysemantic_stack_[(10) - (7)].adouble),(int)(yysemantic_stack_[(10) - (9)].adouble))
          Alors
        (*(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->BufferPos((int)(yysemantic_stack_[(10) - (5)].adouble),(int)(yysemantic_stack_[(10) - (7)].adouble),(int)(yysemantic_stack_[(10) - (9)].adouble));
          Sinon
        char tmp_string[255];
        sprintf(tmp_string,"coord = %f %f %f \n",(yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
        driver.err_print(tmp_string);
          FinSi
        }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 3211 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
       InrImage::ptr  i1;
       InrImage::ptr  i2;

       i1 = *(InrImage::ptr*) (yysemantic_stack_[(12) - (1)].variable)->Pointer();
       i2 = *(InrImage::ptr*) (yysemantic_stack_[(12) - (5)].variable)->Pointer();
       Func_PutImage( i1.get(), i2.get(), (int) (yysemantic_stack_[(12) - (7)].adouble), (int) (yysemantic_stack_[(12) - (9)].adouble), (int) (yysemantic_stack_[(12) - (11)].adouble));
        }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 3239 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr  i1;
      InrImage::ptr  i2;
      float tx1,ty1,tz1;
      float tx2,ty2,tz2;

          i1 = *(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
          i2 = *(InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer();
      i1->GetTranslation(tx1,ty1,tz1);
      i2->GetTranslation(tx2,ty2,tz2);
      Func_PutImage( i1.get(), i2.get(),
             (int) round((double)(tx2-tx1)/i1->VoxSizeX()),
             (int) round((double)(ty2-ty1)/i1->VoxSizeY()),
             (int) round((double)(tz2-tz1)/i1->VoxSizeZ()));
    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 3270 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->FixeNom( (yysemantic_stack_[(6) - (5)].astring));
      delete [] (yysemantic_stack_[(6) - (5)].astring);
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 3276 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (5)  var_image: input image
            (7)  expr: sigma, standard deviation of the Gaussian smoothing used
                        to compute the gradient and principal curvature directions
            (9)  expr:  threshold on the magnitude of the gradient
            (11) expr: data attachment coefficient

        Description:
            Sets parameters for the anisotropic diffusion algorithm using
            Gauss-Seidel scheme.
        **/
        Func_InitAnisoGS( ((InrImage::ptr*) (yysemantic_stack_[(12) - (5)].variable)->Pointer())->get(),
                          (yysemantic_stack_[(12) - (7)].adouble),  (yysemantic_stack_[(12) - (9)].adouble), (yysemantic_stack_[(12) - (11)].adouble));
        }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 3294 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_SetCoeffAnisoGS((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 3299 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetDistanceMap((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 3304 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseType((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 3309 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseSD((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 3314 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetMask(((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 3319 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
         Parameters:
            (5) image which defines a region of interest used
                to estimate the noise parameters in the
                Oriented Speckle Reducing Anisotropic Diffusion
         Description:
            Sets the region of interest (region of constant tissue in the image)
            and activates the Oriented Speckle Reducing Anisotropic Diffusion
         **/
          Func_AnisoGS_SetSRAD_ROI(((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 3333 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
         Parameters:
            (5) image which defines a region of interest used
                to estimate the noise parameters in the
                Rician Noise Reducing Anisotropic Diffusion
         Description:
            Sets the region of interest (region of constant tissue in the image)
            and activates the Rician Noise Reducing Anisotropic Diffusion
            used to reduce noise in MRI data.
         **/
          Func_AnisoGS_SetRNRAD_ROI(((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 3348 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
         Parameters:
            (5) image which defines a region of interest used
                to estimate the noise parameters in the
                Rician Noise Reducing Anisotropic Diffusion
         Description:
            Sets the region of interest (region of constant tissue in the image)
            and activates the Rician Noise Reducing Anisotropic Diffusion
            used to reduce noise in MRI data.
            New version of the filter, using local directional mean and variance
            for the diffusion matrix.
         **/
          Func_AnisoGS_SetRNRAD_ROI_NEW(((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 3365 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Parameters:
            (5) expr: determine the local structure description
              0 for smoothed gradient and principal curv. directions
              1 for the local structure tensor

          Description:
            Sets the local structure mode.
         **/
      Func_SetLocalStructureMode((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 3379 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Parameters:
            (5) expr: option for selecting the eigenvalues for the
              diffusion matrix
              0: sums the 3D, 2D and 1D diffusions
                - lambda1 will depend on a coefficient based on a
                    3D neighborhood
                - lambda2 will be the sum of lambda1 + a coeff based
                    on a 2D neighborhood
                - lambda3 = lambda2 + coeff based on a linear neigh.
              1: take the maximum instead of the sum

          Description:
            Choose a way to select the diffusion matrix eigenvalues.
         **/
      Func_SetEigenvaluesMode((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 3399 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setdt((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 3404 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setneighborhood((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 3409 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_SetCoeffAnisoGS3D((yysemantic_stack_[(8) - (5)].adouble),(yysemantic_stack_[(8) - (7)].adouble));

    }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 3416 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float  error;

      error = Func_ItereAnisoGS();

      //driver.res_print("Error in AnisoGS.Iterate ");
    }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 3425 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int res;

      res = Func_EndAnisoGS();

    }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 3433 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 3438 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_EndWeickert();

    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 3445 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 3450 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_EndWeickert();
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 3455 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    //
    // Parameters:
    // 1. number of iterations
    // 2. coefficient of the data attachment
    // 3. curvature coefficient
    // 4. reinitialization frequency for the distance map

    Func_LevelSets_InitParam(
                 0.8,
                 (int) (yysemantic_stack_[(12) - (5)].adouble),
                 (yysemantic_stack_[(12) - (7)].adouble),
                 (yysemantic_stack_[(12) - (9)].adouble),
                 1,
                 (int) (yysemantic_stack_[(12) - (11)].adouble)
                 );

        }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 3476 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    //
    // Parameters:
    // 1. threshold on the cumulative histo of the grad norm for data attachment
    // 2. number of iterations
    // 3. coefficient of the data attachment
    // 4. curvature coefficient
    // 5. evolution step dt
    // 6. reinitialization frequency for the distance map


      Func_LevelSets_InitParam(
                   (yysemantic_stack_[(16) - (5)].adouble),
                   (int) (yysemantic_stack_[(16) - (7)].adouble),
                   (yysemantic_stack_[(16) - (9)].adouble),
                   (yysemantic_stack_[(16) - (11)].adouble),
                   (yysemantic_stack_[(16) - (13)].adouble),
                   (int) (yysemantic_stack_[(16) - (15)].adouble)
                   );

        }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 3499 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetMeanCurv( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 3504 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetAffineCurvature( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 3509 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetBalloonScheme( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 3514 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetDMmethod( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 3519 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetThreads( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 3524 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 3529 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityLowThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 3534 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityHighThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 3539 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbabilityHighThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 3544 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumGaussians( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 3549 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetGaussian( (int) (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 3554 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumInitPoints( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 3559 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetInitPoint( (int) (yysemantic_stack_[(14) - (5)].adouble), (int) (yysemantic_stack_[(14) - (7)].adouble), (int) (yysemantic_stack_[(14) - (9)].adouble), (int) (yysemantic_stack_[(14) - (11)].adouble), (int) (yysemantic_stack_[(14) - (13)].adouble));
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 3564 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSets_SetIsoContourBin( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 3569 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsVelocity(((InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get(),(yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 3574 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsExpansion((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 3579 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /** 
            Parameters:
              - input image: expansion image, expansion force for the level set evolution
            Description:
              Set the expansion to be the given image instead of a combination of Gaussian functions
              The expansion will then be multiplied by the expansion coefficient during the evolution.
              
          **/
          Func_LevelSetsExpansionImage( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 3592 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsBandAndTube((int)(yysemantic_stack_[(8) - (5)].adouble),(int)(yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 3597 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSetCurvWeights( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 3602 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSetAdvectionField(
                ((InrImage::ptr*) (yysemantic_stack_[(10) - (5)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(10) - (7)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(10) - (9)].variable)->Pointer())->get());
        }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 3610 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetCurvatureData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 3615 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetDistanceMap( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 3620 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetAdvectionData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 3625 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetSkeleton( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 3630 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetVelocityData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 3635 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetExpansionData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 3640 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetCurvatureData( NULL );
        }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 3645 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetAdvectionData( NULL);
        }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 3650 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetVelocityData( NULL);
        }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 3655 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsSaveDistMap( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 3660 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsSaveSecDerGrad( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 3665 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.aint) = Func_LevelSets_Iterate();
    }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 3670 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_End();
    }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 3674 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      (*(InrImage::ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())->Sauve((yysemantic_stack_[(4) - (4)].astring));
      delete [] (yysemantic_stack_[(4) - (4)].astring);
        }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 3701 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Normalizes a vector field given by a vectorial image.

        Example(s):
          v1.normalize

        **/
      Func_Normalize((((InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->get()));
        }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 3714 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_OrientField( ((InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->get() , ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );
        }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 3719 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       Func_OrientPositive( ((InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->get() , ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );
    }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 3723 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())->Write((yysemantic_stack_[(4) - (4)].astring));
      delete [] (yysemantic_stack_[(4) - (4)].astring);
    }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 3729 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
        (1) input polydata
        (4) filename
    Description:
        Save the first line of the polydata in text format
    **/
      SurfacePoly::ptr surf = (*(SurfacePoly::ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer());
      Func_WriteCTALine(surf.get(),(yysemantic_stack_[(4) - (4)].astring));
      delete [] (yysemantic_stack_[(4) - (4)].astring);
    }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 3742 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetOwnMaterial( (int) (yysemantic_stack_[(6) - (5)].adouble));

        }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 3748 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->GetMaterial()._ambient.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 3754 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->GetMaterial()._diffuse.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 3760 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->GetMaterial()._specular.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 3767 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->GetMaterial()._shininess= (yysemantic_stack_[(6) - (5)].adouble);

        }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 3774 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->GetMaterial()._opacity= (yysemantic_stack_[(6) - (5)].adouble);

    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 3781 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        Sets the object visible or not visible in the scene.
      **/
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetVisible( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 3790 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Enable/Disable colormaterial for the associated surface.
        **/

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->GetMaterial()._colormaterial = (unsigned char) ((yysemantic_stack_[(6) - (5)].adouble)>0.5);

    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 3801 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Parameters:
        (1) surface object
        (5) alpha value
    
      Description:
        to define the transparency to the RGB color
        associated per each vertex (actived with Enable ColorMaterial)
      **/

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetColorOpacity((yysemantic_stack_[(6) - (5)].adouble));

    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 3816 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int n;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

      Pour(n,0,s->NbPoints()-1)
        (*s)[n].SetColor((unsigned char) (yysemantic_stack_[(10) - (5)].adouble),
                 (unsigned char) (yysemantic_stack_[(10) - (7)].adouble),
                 (unsigned char) (yysemantic_stack_[(10) - (9)].adouble));
      FinPour

          s->SetColorMaterial(true);
          s->GLRecomputeList(  );

    }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 3831 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());


      s->SetPointsColors( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

    }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 3839 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());
      InrImage::ptr i = InrImage::ptr(driver.im_stack.GetLastImage());
      // TODO: use smart pointer to image in SetColors ...
      s->SetColors( i.get() , (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 3846 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      InrImage::ptr i = InrImage::ptr(driver.im_stack.GetLastImage());
      s->SetColors( i.get() );

    }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 3853 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      s->Statistics( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

    }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 3859 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->MergePoints((yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 3863 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->Triangulate();
    }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 3867 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      SurfacePoly::ptr surf = *(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      float        depth = (yysemantic_stack_[(6) - (5)].adouble);
      char         name[100];
      int          n;

      // param 1: depth (neighborhood)
      //

      // Create images for the curvatures and their directions
      InrImage* Icmin;
      InrImage* Icmax;
      InrImage* Idmin;
      InrImage* Idmax;

      n = surf->GetNumberOfPoints();

      Icmin = new InrImage(n,1,1,WT_FLOAT,"mincurv.ami.gz");
      Icmax = new InrImage(n,1,1,WT_FLOAT,"maxcurv.ami.gz");

      Idmin = new InrImage(n,1,1,3,WT_FLOAT,"mincurvdir.ami.gz");
      Idmax = new InrImage(n,1,1,3,WT_FLOAT,"maxcurvdir.ami.gz");

      surf->ComputeCurvatures(Icmin,Icmax,Idmin,Idmax, (int) depth);

      sprintf(name,"%s_cmin",(yysemantic_stack_[(6) - (1)].variable)->Name().c_str());
      Vars.AddVar(type_image,name,Icmin);
      sprintf(name,"%s_cmax",(yysemantic_stack_[(6) - (1)].variable)->Name().c_str());
      Vars.AddVar(type_image,name,Icmax);
      sprintf(name,"%s_dmin",(yysemantic_stack_[(6) - (1)].variable)->Name().c_str());
      Vars.AddVar(type_image,name,Idmin);
      sprintf(name,"%s_dmax",(yysemantic_stack_[(6) - (1)].variable)->Name().c_str());
      Vars.AddVar(type_image,name,Idmax);

    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 3904 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      InrImage::ptr i = InrImage::ptr(driver.im_stack.GetLastImage());
      s->DisplacePoints( i.get() );
    }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 3910 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

      s->Translate( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble) );

    }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 3917 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

      s->Scale( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble),0 );

        }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 3924 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          int          w = (int) (yysemantic_stack_[(6) - (5)].adouble);

          Si w<1  AlorsFait w=1;
          Si w>10 AlorsFait w=10;

          s->_line_width = w;

        }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 3935 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

      s->RemoveLine((int)(yysemantic_stack_[(6) - (5)].adouble));
          s->GLRecomputeList();

    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 3943 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        image expression
      Description:
        Select lines based on an image
        The image is 1D of size the number of lines
        if the value is > 0.5, then select the corresponding line
    **/

      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      InrImage::ptr im = InrImage::ptr(driver.im_stack.GetLastImage());

      s->SelectLines(im.get());
      s->GLRecomputeList();
    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 3960 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Remove selected lines
    **/
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

        s->RemoveSelection();
        s->GLRecomputeList();
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 3970 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GLRecomputeList();

        }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 3975 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

      s->RecomputeNormals();

        }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 3982 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

      s->InvertNormals();

        }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 3989 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          Func_ApplyvtkSmooth(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 3997 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          Func_vtkWindowedSinc(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 4005 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

          SurfacePoly::ptr surf_init = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          SurfacePoly* surf;

          surf = Func_decimate(surf_init.get());
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

  case 254:

/* Line 678 of lalr1.cc  */
#line 4024 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Sets a threshold for drawing connected components
          bigger.
        **/
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          GLuint _SURFACE;

          Si Non(s->_cc_calculees) Alors
            s->CalculCC();
          FinSi
          s->GLSurfaceMinThCC( _SURFACE, (int) (yysemantic_stack_[(6) - (5)].adouble));

        }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 4040 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        Draw one connected component only
        **/
          SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          GLuint _SURFACE;

            //          Si _type_surface == SURFACE_POLY Alors
            Si Non(s->_cc_calculees) Alors
              s->CalculCC();
            FinSi
            s->GLSurfaceDrawOnlyCC( _SURFACE, (int) (yysemantic_stack_[(6) - (5)].adouble));
            //          FinSi

        }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 4057 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        Activate/Desactivate Drawing of one connected components
        **/
          SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer());
          GLuint _SURFACE;

      //          Si _type_surface == SURFACE_POLY Alors
            Si Non(s->_cc_calculees) Alors
              s->CalculCC();
            FinSi
            s->GLSurfaceSetDrawCC( _SURFACE, (int) (yysemantic_stack_[(8) - (5)].adouble),(int) (yysemantic_stack_[(8) - (7)].adouble));
        //          FinSi

        }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 4074 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());
      s->AddPoint((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 4079 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      s->NewLine();
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 4084 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      s->LineAddPointNumber( (int) (yysemantic_stack_[(6) - (5)].adouble) );
    }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 4089 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      s->EndLine();
    }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 4094 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      if (strlen((yysemantic_stack_[(4) - (3)].astring))<255) {
        strcpy(AMIFluid::FLUID_NAVIGATION_FILE,(yysemantic_stack_[(4) - (3)].astring));
      } else
        fprintf(stderr,"SetFluidNavFile() \t File too long \n");
      delete [] (yysemantic_stack_[(4) - (3)].astring);
        }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 4103 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr di = *(DessinImage::ptr*) (yysemantic_stack_[(20) - (3)].variable)->Pointer();
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

  case 263:

/* Line 678 of lalr1.cc  */
#line 4203 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      InrImage* im = (InrImage*) driver.im_stack.GetLastImage();
      AMIFluid::Func_ElevateMesh(s.get(),im);
      delete im;
    }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 4237 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->UserRotate((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 4244 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          SurfacePoly::ptr surf = SurfacePoly::ptr(driver.surf_stack.GetLastSurf());

          sdraw->GetCanvas()->AddSurface(surf);
          sdraw->Paint();
        }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 4252 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());
          sdraw->GetCanvas()->AddSurface(*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (3)].variable)->Pointer());
          //sdraw->Paint();
        }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 4258 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->RemoveSurface(*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (3)].variable)->Pointer());
          sdraw->Paint();
        }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 4265 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description: Removes the surface without swapping the 3D buffer
          **/
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->RemoveSurface(*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer());
          sdraw->Paint(false);
        }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 4275 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:  Swaps the 3D buffer
          **/
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->AfficheBuffer();
        }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 4284 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC ( (int) (yysemantic_stack_[(6) - (5)].adouble) );
          sdraw->Paint();
        }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 4291 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
          sdraw->Paint();
        }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 4298 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          Si sdraw->GetCanvas()->SetCurrentObject( (int) (yysemantic_stack_[(6) - (5)].adouble) ) Alors
            sdraw->Paint();
          Sinon
            fprintf(stderr," Incorrect index \n");
          FinSi
        }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 4308 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw1 = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          Viewer3D_ptr sdraw2 = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer());

          sdraw1->AddCompSurf(sdraw2);
        }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 4315 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Viewer3D_ptr draw;

      draw = *((Viewer3D_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer());
      switch ((int) (yysemantic_stack_[(8) - (5)].adouble)) {
      case 1:
        draw->GetCanvas()->SetVectors1( (*(InrImage::ptr*) (yysemantic_stack_[(8) - (7)].variable)->Pointer()));
        break;
      case 2:
        draw->GetCanvas()->SetVectors2( (*(InrImage::ptr*) (yysemantic_stack_[(8) - (7)].variable)->Pointer()));
        break;
      }
    }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 4329 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Viewer3D_ptr draw = *((Viewer3D_ptr*) (yysemantic_stack_[(16) - (1)].variable)->Pointer());
      int num = (int) (yysemantic_stack_[(16) - (5)].adouble);
          InrImage* im = (InrImage*) driver.im_stack.GetLastImage();
      int orientation = (int) (yysemantic_stack_[(16) - (9)].adouble);
          int pos = (int) (yysemantic_stack_[(16) - (11)].adouble);
          float Imin = (yysemantic_stack_[(16) - (13)].adouble);
          float Imax = (yysemantic_stack_[(16) - (15)].adouble);

      draw->GetCanvas()->ShowFreeSection(num,im,orientation,pos,Imin,Imax);

          delete im;
        }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 4343 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Viewer3D_ptr draw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      int num = (int) (yysemantic_stack_[(6) - (5)].adouble);

      draw->GetCanvas()->HideFreeSection(num);

        }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 4351 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr glclass=*((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());
          glclass->GetCanvas()->PrintMatrices();
        }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 4356 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->SetObjectTransform(*tr);
              sdraw->Paint();
          delete tr;
        }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 4364 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->SetObjectTransform(*tr);
          if ((yysemantic_stack_[(8) - (7)].adouble)>0.5) sdraw->Paint();
          delete tr;
        }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 4372 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          sdraw->Paint();
          sdraw->Update();
          // process all pending events ...
          while (GB_wxApp->Pending()) {
            if (GB_verbose) printf("Dispatching event on GB_wxApp \n");
            GB_wxApp->Dispatch();
          }
        }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 4383 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(12) - (1)].variable)->Pointer();
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

  case 282:

/* Line 678 of lalr1.cc  */
#line 4395 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(12) - (1)].variable)->Pointer();
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

  case 283:

/* Line 678 of lalr1.cc  */
#line 4407 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(12) - (1)].variable)->Pointer();
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

  case 284:

/* Line 678 of lalr1.cc  */
#line 4419 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->SetBG((int)(yysemantic_stack_[(10) - (5)].adouble),(int)(yysemantic_stack_[(10) - (7)].adouble),(int)(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 4425 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Normalizes the 3D view based on the limits in space of the current objects
        **/
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->Normalize();
        }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 4434 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Centers the 3D view based on the limits in space of the current objects
        **/
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->Center();
        }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 4443 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
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

  case 288:

/* Line 678 of lalr1.cc  */
#line 4456 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_StructureTensor(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                   (yysemantic_stack_[(8) - (3)].variable)->Name().c_str(),
                   (yysemantic_stack_[(8) - (5)].adouble), (yysemantic_stack_[(8) - (7)].adouble), NULL);
        }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 4463 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();

          Func_StructureTensor(
            ((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),
            (yysemantic_stack_[(10) - (3)].variable)->Name().c_str(),
            (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), mask);
          delete mask;
        }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 4474 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          Func_StructureTensorHessian(
            ((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
            (yysemantic_stack_[(8) - (3)].variable)->Name().c_str(),
            (yysemantic_stack_[(8) - (5)].adouble), (yysemantic_stack_[(8) - (7)].adouble), NULL);
        }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 4496 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();

          Func_StructureTensorHessian(
            ((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),
            (yysemantic_stack_[(10) - (3)].variable)->Name().c_str(),
            (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), mask);
          delete mask;
        }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 4522 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();
      int save_grad = (int) (yysemantic_stack_[(12) - (11)].adouble);

          Func_StructureTensorHessian(((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get(),
                   (yysemantic_stack_[(12) - (3)].variable)->Name().c_str(),
                   (yysemantic_stack_[(12) - (5)].adouble), (yysemantic_stack_[(12) - (7)].adouble), mask, save_grad);
      delete mask;
        }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 4550 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_HessianMatrix(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(6) - (3)].variable)->Name().c_str(),
                 (yysemantic_stack_[(6) - (5)].adouble),   // sigma
                 0,   // gamma
                 NULL  // mask
                 );
        }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 4560 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();

          Func_HessianMatrix(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(8) - (3)].variable)->Name().c_str(),
                 (yysemantic_stack_[(8) - (5)].adouble),   // sigma
                 0,   // gamma
                 mask  // mask
                 );
      delete mask;
        }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 4573 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_HessianMatrix(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(8) - (3)].variable)->Name().c_str(),
                 (yysemantic_stack_[(8) - (5)].adouble),   // sigma
                 (yysemantic_stack_[(8) - (7)].adouble),   // gamma
                 NULL  // mask
                 );
        }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 4583 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();

          Func_HessianMatrix(((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(10) - (3)].variable)->Name().c_str(),
                 (yysemantic_stack_[(10) - (5)].adouble),   // sigma
                 (yysemantic_stack_[(10) - (7)].adouble),   // gamma
                 mask  // mask
                 );
      delete mask;
        }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 4605 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

          Func_Derivatives(((InrImage::ptr*) (yysemantic_stack_[(16) - (3)].variable)->Pointer())->get(),
               (yysemantic_stack_[(16) - (3)].variable)->Name().c_str(),
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

  case 298:

/* Line 678 of lalr1.cc  */
#line 4634 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();

          Func_Derivatives(((InrImage::ptr*) (yysemantic_stack_[(18) - (3)].variable)->Pointer())->get(),
               (yysemantic_stack_[(18) - (3)].variable)->Name().c_str(),
               (yysemantic_stack_[(18) - (5)].adouble),   // sigma
               (yysemantic_stack_[(18) - (7)].adouble),   // gamma
               mask,  // mask
               (int)(yysemantic_stack_[(18) - (9)].adouble),   // 1st eigenvalue | eigenvector?
               (int)(yysemantic_stack_[(18) - (11)].adouble),   // 2nd eigenvalue | eigenvector?
               (int)(yysemantic_stack_[(18) - (13)].adouble),   // 3rd eigenvalue | eigenvector?
               (int)(yysemantic_stack_[(18) - (15)].adouble)   // Gradient vector?
               );
      delete mask;
        }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 4652 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();

          Func_HessianVap(((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get(),
              (yysemantic_stack_[(12) - (3)].variable)->Name().c_str(),
              (yysemantic_stack_[(12) - (5)].adouble),   // sigma
              (yysemantic_stack_[(12) - (7)].adouble),   // gamma
              mask,
              (int) (yysemantic_stack_[(12) - (11)].adouble) // eigenvalue number
              );
      delete mask;
        }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 4666 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_Curvatures(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
              (yysemantic_stack_[(6) - (3)].variable)->Name().c_str(),
              (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 4678 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();

          Func_Eigen3D(
               (char*) (yysemantic_stack_[(18) - (3)].astring),
               ((InrImage::ptr*) (yysemantic_stack_[(18) - (5)].variable) ->Pointer())->get(),
               ((InrImage::ptr*) (yysemantic_stack_[(18) - (7)].variable) ->Pointer())->get(),
               ((InrImage::ptr*) (yysemantic_stack_[(18) - (9)].variable) ->Pointer())->get(),
               ((InrImage::ptr*) (yysemantic_stack_[(18) - (11)].variable)->Pointer())->get(),
               ((InrImage::ptr*) (yysemantic_stack_[(18) - (13)].variable)->Pointer())->get(),
               ((InrImage::ptr*) (yysemantic_stack_[(18) - (15)].variable)->Pointer())->get(),
               mask  // mask
               );
      delete mask;
        }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 4699 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

          Func_Eigen3D(
               (char*) (yysemantic_stack_[(16) - (3)].astring),
               ((InrImage::ptr*) (yysemantic_stack_[(16) - (5)].variable) ->Pointer())->get(),
               ((InrImage::ptr*) (yysemantic_stack_[(16) - (7)].variable) ->Pointer())->get(),
               ((InrImage::ptr*) (yysemantic_stack_[(16) - (9)].variable) ->Pointer())->get(),
               ((InrImage::ptr*) (yysemantic_stack_[(16) - (11)].variable)->Pointer())->get(),
               ((InrImage::ptr*) (yysemantic_stack_[(16) - (13)].variable)->Pointer())->get(),
               ((InrImage::ptr*) (yysemantic_stack_[(16) - (15)].variable)->Pointer())->get(),
               NULL
               );
        }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 4718 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();

          Func_Eigen2D(
               (char*) (yysemantic_stack_[(12) - (3)].astring),
               ((InrImage::ptr*) (yysemantic_stack_[(12) - (5)].variable) ->Pointer())->get(),
               ((InrImage::ptr*) (yysemantic_stack_[(12) - (7)].variable) ->Pointer())->get(),
               ((InrImage::ptr*) (yysemantic_stack_[(12) - (9)].variable) ->Pointer())->get(),
               mask  // mask
               );
      delete mask;
        }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 4735 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_Eigen2D(
               (char*) (yysemantic_stack_[(10) - (3)].astring),
               ((InrImage::ptr*) (yysemantic_stack_[(10) - (5)].variable) ->Pointer())->get(),
               ((InrImage::ptr*) (yysemantic_stack_[(10) - (7)].variable) ->Pointer())->get(),
               ((InrImage::ptr*) (yysemantic_stack_[(10) - (9)].variable) ->Pointer())->get(),
               NULL
               );
        }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 4746 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get())->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 4751 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 4756 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im = *(InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer();
      (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetVoxelSize(
                                   im->VoxSizeX(),
                                   im->VoxSizeY(),
                                   im->VoxSizeZ());
    }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 4765 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->SetTranslation((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 4770 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im = *(InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer();
      (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetVoxelSize(
                                   im->TrX(),
                                   im->TrY(),
                                   im->TrZ());
    }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 4779 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        (5) boolean, 0 little endianness, 1 big endianness

      Description:
        Forces the endianness of the image, usually before writting it to a file.
        If the endianness is different from the one of the architecture, the bytes
        are swapped before writting, and there are swapped back after.
    **/
      ((amimage*) (*(*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())) )->SetEndianness((AMIENDIANNESS)(int)(yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 4793 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_DiscSecDerGrad(
        ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
        ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 4800 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_DiscSecDerGrad(
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (7)].variable)->Pointer())->get());
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 4806 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.aint)=1;}
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 4809 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 315:

/* Line 678 of lalr1.cc  */
#line 4826 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 316:

/* Line 678 of lalr1.cc  */
#line 4842 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage*   image = (InrImage*) driver.im_stack.GetLastImage();
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
      delete image;
      delete [] (yysemantic_stack_[(8) - (5)].astring);
         }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 4881 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
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

  case 318:

/* Line 678 of lalr1.cc  */
#line 4898 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      Func_Pad(
        ((InrImage::ptr*) (yysemantic_stack_[(18) - (3)].variable)->Pointer())->get(),
        ((InrImage::ptr*) (yysemantic_stack_[(18) - (5)].variable)->Pointer())->get(),
           step_x,step_y,step_z,
           pos_x,pos_y,pos_z);


        }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 4938 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_GenRead((yysemantic_stack_[(4) - (3)].astring));
        }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 4943 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Debut();
        }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 4948 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Fin();
      cout << "time spent = " << driver.IP_time << endl;
        }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 4954 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          void * pwptr;
          IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));

          pwptr = (void*)new ParamPanel(GB_main_wxFrame,  (char*) (yysemantic_stack_[(6) - (5)].astring)  );
//          GB_main_wxFrame->AddParamPage((wxWindow*)pwptr,GetwxStr((char*) $5),
//                                        true // select as current page
//                                        );
          //GB_main_wxFrame->GetAuiManager().Update();
          if (pwptr != NULL)
        Vars.AddVar(type_parampanel,ident,pwptr);
          else
        driver.err_print("assignment of NULL parameter window\n");
              delete [] (yysemantic_stack_[(6) - (5)].astring);
        }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 4971 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description:
        Ends a notebook.
    **/
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndBook();
    }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 4981 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        - num expression: id of the notebook
        - num expression: position of the page
      Description:
        Selects a give page number in a book (notebook)
    **/
      int book_id = (yysemantic_stack_[(8) - (5)].adouble);
      int pagepos = (yysemantic_stack_[(8) - (7)].adouble);
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
      pw->SelectPage(book_id,pagepos);
    }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 4996 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndPanel();
    }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 5002 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndPanel();
      pw->EndBox( );
    }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 5009 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndBox( );
    }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 5015 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->BeginHorizontal( );
    }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 5021 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
        pw->EndHorizontal( );
        }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 5027 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          pw->CreeDialogue( );
        }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 5033 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Displays the given parameter panel, a smart pointer
            copy is stored
        **/
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

          GB_main_wxFrame->AddParamPanelPage(pw,
                                        pw->GetName(),
                                        true // select as current page
                                        );
        }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 5048 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Hides the given parameter panel, the smart pointer copy is released
        **/
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

          GB_main_wxFrame->RemoveParamPanelPage(pw);
        }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 5059 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          pw->ReAfficheParametres();
        }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 5065 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (1) Parameter window
    
        Description:
          update the display of all the parameters
        **/
            ParamPanel_ptr pw  = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
            pw->MAJ();
            GB_main_wxFrame->GetAuiManager().Update();
        }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 5079 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (1) Parameter window
          (5) parameter id
    
        Description:
          update the display of one parameter
        **/
            ParamPanel_ptr pw  = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
            pw->UpdateParameter((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 5093 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (1) Parameter window
          (5) parameter id
          (7) bool: 1/0 for show/hide
        Description:
          Show/hide the slider if there is one.
        **/
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
          int n = (int) (yysemantic_stack_[(8) - (5)].adouble);
          bool show = (bool) (yysemantic_stack_[(8) - (7)].adouble);

          pw->ParamShowSlider(n,show );
        }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 5110 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
          int n = pw->NbParameters();
            pw->ChangedValueCallback(n-1,(void*) CB_ParamWin, (void*) (yysemantic_stack_[(6) - (5)].variable) );
        }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 5120 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        Sets the object position properties of the given widget
      Parameters:
        - proportion property (0: not proportional, 
                               1: standard proportion,
                               -1: keeps previous value)
        - border size ( -1 keeps previous value)
        - flags       ( -1 keeps previous value)
      **/
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer();
      int n = pw->NbParameters();
        pw->SetPositionProperties(
              n-1, (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 5139 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        - index of the parameter for which to set the drag callback
      Description: activate the drag callback
    **/
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      int n = pw->NbParameters();
      int i     = (int) (yysemantic_stack_[(6) - (5)].adouble);
      bool drag = true;
      if ((i>=0)&&(i<n))
        pw->SetDragCallback(i,drag);
      else
        fprintf(stderr,"VAR_PARAMWIN.SetDragCallbackO( %d , .. ) \t bad parameter number \n",i);
    }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 5157 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        - index of the parameter for which to set the drag callback
        - boolean value: activate or desactivate the drag callbacks
      Description: activate the drag callback
    **/
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
      int n = pw->NbParameters();
      int i     = (int) (yysemantic_stack_[(8) - (5)].adouble);
      bool drag = (bool) (yysemantic_stack_[(8) - (7)].adouble);
      if ((i>=0)&&(i<n))
        pw->SetDragCallback(i,drag);
      else
        fprintf(stderr,"VAR_PARAMWIN.SetDragCallbackO( %d , .. ) \t bad parameter number \n",i);
        }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 5175 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description: 
          Enable a parameter
        Parameters:
          - index of the parameter for which to set the drag callback
          - value enable:1 disable:0
      **/
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
      int n = pw->NbParameters();
      int i     = (int) (yysemantic_stack_[(8) - (5)].adouble);
      bool val  = (bool) (yysemantic_stack_[(8) - (7)].adouble);
      if ((i>=0)&&(i<n))
        pw->Enable(i,val);
      else
        driver.err_print(
          (boost::format("VAR_PARAMWIN.Enable( %d , .. ) \t bad parameter number ")%i).str().c_str());
      }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 5195 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description: 
          Enable a static box
        Parameters:
          - index of the box
          - value enable:1 disable:0
      **/
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
      int n = pw->NbBoxes();
      int i     = (int) (yysemantic_stack_[(8) - (5)].adouble);
      bool val  = (bool) (yysemantic_stack_[(8) - (7)].adouble);
      if ((i>=0)&&(i<n))
        pw->EnableBox(i,val);
      else
        driver.err_print(
          (boost::format("VAR_PARAMWIN.EnableBox( %d , .. ) \t bad parameter number ")%i).str().c_str());
      }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 5215 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description: 
          Enable a panel
        Parameters:
          - index of the panel
          - value enable:1 disable:0
      **/
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
      int n = pw->NbPanels();
      int i     = (int) (yysemantic_stack_[(8) - (5)].adouble);
      bool val  = (bool) (yysemantic_stack_[(8) - (7)].adouble);
      if ((i>=0)&&(i<n))
        pw->EnablePanel(i,val);
      else
        driver.err_print(
          (boost::format("VAR_PARAMWIN.EnablePanel( %d , .. ) \t bad parameter number ")%i).str().c_str());
      }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 5235 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage::ptr   i = *(InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer();
          Func_VectorImage2StructuredGrid(i.get(),(yysemantic_stack_[(6) - (5)].astring));
          delete [] (yysemantic_stack_[(6) - (5)].astring);
        }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 5242 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(GLTransfMatrix_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->Print();
        }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 5247 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_SaveTransform(((GLTransfMatrix_ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())->get(),(yysemantic_stack_[(4) - (4)].astring));
          delete [] (yysemantic_stack_[(4) - (4)].astring);
        }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 5253 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapFluid();
        }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 5258 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapVTK();
        }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 5263 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapITK();
        }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 5268 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapWII();
        }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 5273 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapFilters();
        }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 5278 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapSystem();
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 5283 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapMainFrame();
        }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 5294 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage::ptr im1 = *(InrImage::ptr*) (yysemantic_stack_[(30) - (3)].variable)->Pointer();
    InrImage::ptr im2 = *(InrImage::ptr*) (yysemantic_stack_[(30) - (5)].variable)->Pointer();
    InrImage::ptr u = *(InrImage::ptr*) (yysemantic_stack_[(30) - (7)].variable)->Pointer();
    InrImage::ptr v = *(InrImage::ptr*) (yysemantic_stack_[(30) - (9)].variable)->Pointer();
    InrImage::ptr corr = *(InrImage::ptr*) (yysemantic_stack_[(30) - (11)].variable)->Pointer();
    InrImage::ptr conf_x = *(InrImage::ptr*) (yysemantic_stack_[(30) - (13)].variable)->Pointer();
    InrImage::ptr conf_y = *(InrImage::ptr*) (yysemantic_stack_[(30) - (15)].variable)->Pointer();
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

  case 355:

/* Line 678 of lalr1.cc  */
#line 5326 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage::ptr im1 = *(InrImage::ptr*) (yysemantic_stack_[(24) - (3)].variable)->Pointer();
        InrImage::ptr im2 = *(InrImage::ptr*) (yysemantic_stack_[(24) - (5)].variable)->Pointer();
        float     sigma = (yysemantic_stack_[(24) - (7)].adouble);
        float     T     = (yysemantic_stack_[(24) - (9)].adouble);
        float     alpha = (yysemantic_stack_[(24) - (11)].adouble);
        long      dtype = (long) (yysemantic_stack_[(24) - (13)].adouble);      /* type of smoothness term */
        float     quantile = (yysemantic_stack_[(24) - (15)].adouble);          /* isotropy fraction */
        float     ht       = (yysemantic_stack_[(24) - (17)].adouble);          /* time step size */
        InrImage::ptr u =  *(InrImage::ptr*) (yysemantic_stack_[(24) - (19)].variable)->Pointer();  /* x component of optic flow, changed */
        InrImage::ptr v =  *(InrImage::ptr*) (yysemantic_stack_[(24) - (21)].variable)->Pointer();  /* y component of optic flow, changed */
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

  case 356:

/* Line 678 of lalr1.cc  */
#line 5350 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable*  var   = (yysemantic_stack_[(4) - (1)].variable);
          ParamList::ptr param((yysemantic_stack_[(4) - (3)].paramlist));
          ((void (*)(ParamList*)) var->Pointer())(param.get());
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 5357 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 358:

/* Line 678 of lalr1.cc  */
#line 5379 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = new std::list<std::string>();
            sl->push_back(string((yysemantic_stack_[(1) - (1)].astring)));
            delete [] (yysemantic_stack_[(1) - (1)].astring);
            (yyval.string_list) = sl;
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 5387 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = (yysemantic_stack_[(3) - (1)].string_list);
            sl->push_back(string((yysemantic_stack_[(3) - (3)].astring)));
            delete [] (yysemantic_stack_[(3) - (3)].astring);
            (yyval.string_list) = sl;
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 5403 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          (yyval.paramlist) = pl;
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 5408 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl(new ParamList);
          float_ptr* x = new float_ptr(new float((yysemantic_stack_[(1) - (1)].adouble)));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 5415 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);
          float_ptr* x= new float_ptr(new float((yysemantic_stack_[(3) - (3)].adouble)));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 5422 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          string_ptr* x = new string_ptr(new string((yysemantic_stack_[(1) - (1)].astring)));
          delete [] (yysemantic_stack_[(1) - (1)].astring);
          pl->AddParam(type_string, x);
          (yyval.paramlist) = pl;
         }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 5430 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);
          string_ptr* x = new string_ptr(new string((yysemantic_stack_[(3) - (3)].astring)));
          delete [] (yysemantic_stack_[(3) - (3)].astring);
          pl->AddParam(type_string, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 5438 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  new ParamList();
          // creating reference
          float_ptr* x = new float_ptr(*((float_ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer()));

          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 5447 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          float_ptr*   x = new float_ptr(* ((float_ptr*)(yysemantic_stack_[(4) - (4)].variable)->Pointer()));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 5454 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          int_ptr*   x = new int_ptr(*((int_ptr*)(yysemantic_stack_[(2) - (2)].variable)->Pointer()));
          pl->AddParam(type_int, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 5461 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          int_ptr*   x = new int_ptr( *((int_ptr*)(yysemantic_stack_[(4) - (4)].variable)->Pointer()));
          pl->AddParam(type_int, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 5468 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          InrImage::ptr* i = new InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 5475 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(3) - (1)].paramlist);
          InrImage::ptr*   i = new InrImage::ptr( (InrImage*) driver.im_stack.GetLastImage());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 5482 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          InrImage::ptr*  i = new InrImage::ptr(*(InrImage::ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 5489 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          InrImage::ptr* i = new InrImage::ptr(*(InrImage::ptr*) (yysemantic_stack_[(4) - (4)].variable)->Pointer());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 5496 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          SurfacePoly::ptr*  s = new SurfacePoly::ptr(*(SurfacePoly::ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer());
          pl->AddParam(type_surface, s);
          (yyval.paramlist) = pl;
        }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 5503 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          SurfacePoly::ptr*  s = new SurfacePoly::ptr(*(SurfacePoly::ptr*) (yysemantic_stack_[(4) - (4)].variable)->Pointer());
          pl->AddParam(type_surface, s);
          (yyval.paramlist) = pl;
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 5510 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          DessinImage::ptr* i = new DessinImage::ptr(*(DessinImage::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer());
          pl->AddParam(type_imagedraw, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 5517 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(3) - (1)].paramlist);
          DessinImage::ptr*  i = new DessinImage::ptr(*(DessinImage::ptr*) (yysemantic_stack_[(3) - (3)].variable)->Pointer());
          pl->AddParam(type_imagedraw, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 5526 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      //      printf("no parameters \n");
      ParamListDecl* pl = new ParamListDecl;
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 5532 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      cout << "param_list_decl: T_NUM IDENTIFIER" << endl;
      cout << ident->GetName().c_str() << endl;
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_float);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 5541 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_string);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 5548 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 5555 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 5562 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 5569 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_float);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 5576 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_string);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 5583 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 5590 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 5597 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 5605 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 5610 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      //
      // TODO: replace string expression to use std::string !!!
      //
      char* res;

      res = new char[(*(string_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->length()+1];
      strcpy(res,((string_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get()->c_str());
      (yyval.astring)= res;
        }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 5625 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
          //fflush(stdout);
        }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 5631 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 392:

/* Line 678 of lalr1.cc  */
#line 5645 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        Uses the class boost::format to create the result of 
        the format as a string, only one numerical parameter 
        is accepted.
    **/
      boost::format bf((yysemantic_stack_[(6) - (3)].astring));
      delete [] (yysemantic_stack_[(6) - (3)].astring);
      std::string resstr = (bf % (yysemantic_stack_[(6) - (6)].adouble)).str();
      char* res = new char[resstr.length()+1];
      strcpy(res,resstr.c_str());
      (yyval.astring)= res;
    }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 5661 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        Uses the class boost::format to create the result of 
        the format as a string, using a string expression as a parameter.
    **/
      boost::format bf((yysemantic_stack_[(6) - (3)].astring));
      delete [] (yysemantic_stack_[(6) - (3)].astring);
      std::string resstr = (bf % (yysemantic_stack_[(6) - (6)].astring)).str();
      char* res = new char[resstr.length()+1];
      strcpy(res,resstr.c_str());
      (yyval.astring)= res;
      delete [] (yysemantic_stack_[(6) - (6)].astring);
    }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 5677 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      char* res;
      long min,hour,sec;

      driver.IP_time.Fin();
      driver.IP_time.AddCumul();
      driver.IP_time.GetCumul(hour,min,sec);
      res = new char[10];
      sprintf(res,"%03d:%02d:%02d",(int)hour,(int)min,(int)sec);
      (yyval.astring)=res;
    }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 5689 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.astring)=(char*) (*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->Nom();
    }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 5693 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description:
        Returns the name of the variable as a string
    **/
      char* resstr = (char*) (yysemantic_stack_[(4) - (3)].variable)->Name().c_str();
      char* res = new char[strlen(resstr)+1];
      strcpy(res,resstr);
      (yyval.astring)= res;
    }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 5704 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description:
        Returns the name of the object instance to which this variable belongs. If this variable does not belong to an object, returns an empty string.
    **/
      boost::shared_ptr<Variables> context = (yysemantic_stack_[(4) - (3)].variable)->GetContext();
      if (context.get()) {
        char* resstr = (char*) context->GetName().c_str();
        char* res = new char[strlen(resstr)+1];
        strcpy(res,resstr);
        (yyval.astring)= res;
      } else {
        char* empty_string;
        empty_string = new char[1];
        empty_string[0] = '\0';
        (yyval.astring) = empty_string;
      }
    }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 5724 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      char* res = new char[GB_scripts_dir.Len()+1];
      strcpy(res,(const char*)GB_scripts_dir.mb_str(wxConvUTF8));
      (yyval.astring)= res;
    }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 5735 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          char* res;
          res = new char[strlen((yysemantic_stack_[(3) - (1)].astring))+strlen((yysemantic_stack_[(3) - (3)].astring))+1];
          strcpy(res,(yysemantic_stack_[(3) - (1)].astring));
          strcat(res,(yysemantic_stack_[(3) - (3)].astring));
          delete [] (yysemantic_stack_[(3) - (1)].astring);
          delete [] (yysemantic_stack_[(3) - (3)].astring);
          (yyval.astring)=res;
        }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 5745 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          RemoveEndString((yysemantic_stack_[(3) - (1)].astring),(yysemantic_stack_[(3) - (3)].astring));
          (yyval.astring)=(yysemantic_stack_[(3) - (1)].astring);
        }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 5758 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        (yyval.ablock)=(yysemantic_stack_[(3) - (2)].ablock);
        if (GB_debug)
          cerr << format("ablock : %s")
                  % (yysemantic_stack_[(3) - (2)].ablock)->GetBody()
                << endl;
          }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 5772 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      returns the number of arguments in the command line
    **/
      (yyval.adouble)=GB_argc-GB_num_arg_parsed;
    }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 5780 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      Line number in the current script
    **/
      (yyval.adouble)=driver.yyiplineno;
    }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 5788 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        the constant Pi is set to
         3.14159265358979323846
      **/
      (yyval.adouble)= 3.14159265358979323846;
    }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 5797 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=*((float_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get();
    }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 5801 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = (float) *((int_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get();
    }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 5805 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = (float) *((uchar_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get();
    }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 5809 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(3) - (2)].adouble);
      fflush(stdout);
    }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 5818 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
        (1) input_image
        (3) x

        Description:
        returns the image value at pixel (x,y=0,z=0).

        return:
        float value
        **/
      (yyval.adouble)=(**(InrImage::ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())((int) (yysemantic_stack_[(4) - (3)].adouble),0);
    }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 5833 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
        (1) input_image
        (3) x
        (5) y

        Description:
        returns the image value at pixel (x,y,z=0) by default

        return:
        float value
        **/
      (yyval.adouble)=(**(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())((int) (yysemantic_stack_[(6) - (3)].adouble),(int) ( (yysemantic_stack_[(6) - (5)].adouble)));
    }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 5849 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Parameters:
          - input image variable
          - pixel position x,y,z
        Description:
          returns the pixel intensity at the given position
          the position value are rounded to the closest integer
      **/
      (yyval.adouble)=(**(InrImage::ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer())((int) round((yysemantic_stack_[(8) - (3)].adouble)),
          (int) round( (yysemantic_stack_[(8) - (5)].adouble)), 
          (int) round((yysemantic_stack_[(8) - (7)].adouble)));
    }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 5863 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Parameters:
          - input image variable
          - pixel position x,y,z
        Description:
          returns the pixel intensity at the given position
          the position using linear interpolation
      **/
      (yyval.adouble)=(*(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->InterpLinIntensite(
          (yysemantic_stack_[(10) - (5)].adouble),
          (yysemantic_stack_[(10) - (7)].adouble), 
          (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 5878 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        get image component value at a given 3D voxel position.
        same as image(expr,expr,expr;expr)
        **/
        InrImage::ptr im = *(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer();
        Si im->CoordOK((int) (yysemantic_stack_[(10) - (3)].adouble), (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble))
           Et ((int) (yysemantic_stack_[(10) - (9)].adouble) >=0) Et ((int)(yysemantic_stack_[(10) - (9)].adouble) <im->GetVDim()) Alors

        (yyval.adouble)=(**(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())((int) (yysemantic_stack_[(10) - (3)].adouble),(int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble),
                      (int) (yysemantic_stack_[(10) - (9)].adouble) );
      Sinon
        driver.err_print("var_image(expr,expr,expr,expr) \t err coord \n");
          FinSi
    }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 5895 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        get image component value at a given 3D voxel position.
        **/
        InrImage::ptr im = *(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer();
        Si im->CoordOK((int) (yysemantic_stack_[(10) - (3)].adouble), (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble))
           Et ((int) (yysemantic_stack_[(10) - (9)].adouble) >=0) Et ((int)(yysemantic_stack_[(10) - (9)].adouble) <im->GetVDim()) Alors

        (yyval.adouble)=(**(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())((int) (yysemantic_stack_[(10) - (3)].adouble),(int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble),
                      (int) (yysemantic_stack_[(10) - (9)].adouble) );
      Sinon
        driver.err_print("var_image(expr,expr,expr;expr) \t err coord \n");
          FinSi
    }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 5911 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        get image component value at a given 2D  position. ( z component set to 0)
        **/
        InrImage::ptr im = *(InrImage::ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
      Si (im->CoordOK((int) (yysemantic_stack_[(8) - (3)].adouble),   (int (yysemantic_stack_[(8) - (5)].adouble)),   0  )
        Et ((int) (yysemantic_stack_[(8) - (7)].adouble) >=0) Et ((int)(yysemantic_stack_[(8) - (7)].adouble) <im->GetVDim())) Alors
        (yyval.adouble)=(**(InrImage::ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer())((int) (yysemantic_stack_[(8) - (3)].adouble),(int) (yysemantic_stack_[(8) - (5)].adouble),0, (int) (yysemantic_stack_[(8) - (7)].adouble) );
      Sinon
        driver.err_print("var_image(expr,expr;expr) \t err coord \n");
          FinSi
    }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 5925 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        get image component value at a given 1D  position. (y and z components set to 0)
        **/
      Si (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->CoordOK((int) (yysemantic_stack_[(6) - (3)].adouble),   0,   0  )
        Et ((int) (yysemantic_stack_[(6) - (5)].adouble) >=0) Et ((int)(yysemantic_stack_[(6) - (5)].adouble) <3) Alors
        (yyval.adouble)=(**(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())((int) (yysemantic_stack_[(6) - (3)].adouble),0,0, (int) (yysemantic_stack_[(6) - (5)].adouble) );
      Sinon
        driver.err_print("var_image(expr;expr) \t err coord \n");
          FinSi
    }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 5938 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        (*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->InitBuffer();
        }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 5959 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (3)].ident));
      if (strcmp(ident->GetName().c_str(),"tx")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->_tx;
      }
      else
      if (strcmp(ident->GetName().c_str(),"ty")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->_ty;
      }
      else
      if (strcmp(ident->GetName().c_str(),"tz")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->_tz;
      }
      else
      if (strcmp(ident->GetName().c_str(),"trx")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->_translation_x;
      }
      else
      if (strcmp(ident->GetName().c_str(),"vdim")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetVDim();
      }
      else
      if (strcmp(ident->GetName().c_str(),"try")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->_translation_y;
      }
      else
      if (strcmp(ident->GetName().c_str(),"trz")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->_translation_z;
      }
      else
      if (strcmp(ident->GetName().c_str(),"vx")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->_size_x;
      }
      else
      if (strcmp(ident->GetName().c_str(),"vy")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->_size_y;
      }
      else
      if (strcmp(ident->GetName().c_str(),"vz")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->_size_z;
      }
      else
      if (strcmp(ident->GetName().c_str(),"inc")==0) {
        (*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->IncBuffer();
      }
      else
      if (strcmp(ident->GetName().c_str(),"val")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->ValeurBuffer();
      }
      else
        {
          char tmp_string[255];
          sprintf(tmp_string," %s.%s identifier not recognized \n",
              (yysemantic_stack_[(3) - (1)].variable)->Name().c_str(), ident->GetName().c_str());
          strcat(tmp_string," known identifiers {tx, ty, tz, vdim, trx, try, trz, vx, vy, vz, init, inc, val, info} \n");
          driver.err_print(tmp_string);
        }

      }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 6019 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Prints the image information
        **/
        InrImage::ptr im;
        im=*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
        std::string tmp_string;
        tmp_string = (boost::format(" %s: format=%s  dim=(%d,%d,%d)x%d  vox=(%f,%f,%f) \
  translation =(%f,%f,%f) \n")
            % (yysemantic_stack_[(3) - (1)].variable)->Name()
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

  case 426:

/* Line 678 of lalr1.cc  */
#line 6044 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description:
          Prints the object information
      **/
      AMIObject::ptr o = *(AMIObject::ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer();
      
      if (o.get()) {
        cout << "var   name = " << (yysemantic_stack_[(2) - (1)].variable)->Name() <<endl;
        cout << "class name = " << o->GetClass()->GetName() <<endl;
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

  case 427:

/* Line 678 of lalr1.cc  */
#line 6064 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

      std::string tmp_string;
      tmp_string = (boost::format(" %s: %d points %d lines %d polygons  \n")
        % (yysemantic_stack_[(3) - (1)].variable)->Name()
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

  case 428:

/* Line 678 of lalr1.cc  */
#line 6083 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

      (yyval.adouble) = s->GetNumberOfPoints();
    }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 6090 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

      (yyval.adouble) = s->GetNumberOfPolys();

    }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 6098 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_SNR(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 6103 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (yyval.adouble)=Func_eccentricity(((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());
        }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 6108 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

          compute_area = new CalculAireSection( ((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),
                        resolution);
      compute_area->InitImagesSurf((InrImage*) NULL, (InrImage*) NULL,
                       (InrImage*) NULL, (InrImage*) NULL);
      surf_inf[0]  = surf_sup[0] = surf_interp[0] = 0.0;
      v1.Init( 1.0, 0.0, 0.0);
      v2.Init( 0.0, 1.0, 0.0);
      point.Init( cx,cy,0);

      (yyval.adouble)=compute_area->Aire( 0, point, v1, v2,
                  surf_inf, surf_sup, surf_interp);

      delete compute_area;

    }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 6136 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (yyval.adouble)=Func_ComputePositiveArea( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get() );
    }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 6142 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float val[4];

      val[0] = (yysemantic_stack_[(10) - (3)].adouble);
      val[1] = (yysemantic_stack_[(10) - (5)].adouble);
      val[2] = (yysemantic_stack_[(10) - (7)].adouble);
      val[3] = (yysemantic_stack_[(10) - (9)].adouble);
      (yyval.adouble)=Func_PositiveArea(val);
        }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 6153 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im  = InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
      (yyval.adouble)=Func_count( im.get() );
        }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 6172 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im  = InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
      (yyval.adouble)=Func_mean( im.get());
        }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 6191 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im  = InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
      (yyval.adouble)=Func_max( im.get(),NULL);
        }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 6210 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im  = InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
      (yyval.adouble)=Func_argmax( im.get());
      }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 6229 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im  = InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
      (yyval.adouble)=Func_min( im.get(),NULL);
      }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 6248 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im  = InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
      (yyval.adouble)=Func_med( im.get(),0.5,NULL);
        }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 6267 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im  = InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
      InrImage::ptr mask  = InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
          (yyval.adouble)=Func_max( im.get(),mask.get());
        }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 6290 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr mask  = InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
          (yyval.adouble)=Func_min( ((InrImage::ptr*) (yysemantic_stack_[(7) - (6)].variable)->Pointer())->get(),mask.get());
        }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 6312 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();
          (yyval.adouble)=Func_med( ((InrImage::ptr*) (yysemantic_stack_[(7) - (6)].variable)->Pointer())->get(),0.5,mask);
          delete mask;
        }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 6335 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();
          (yyval.adouble)=Func_med( ((InrImage::ptr*) (yysemantic_stack_[(9) - (6)].variable)->Pointer())->get(),(float) (yysemantic_stack_[(9) - (8)].adouble),mask);
          delete mask;
        }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 6342 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr input  = InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
      InrImage::ptr mask  = InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());

          (yyval.adouble)=Func_mean( input.get(),mask.get());
        }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 6366 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();

          (yyval.adouble)=Func_mean( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), mask);
          delete mask;
    }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 6389 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//    setlocale(LC_NUMERIC,"C");
      setlocale(LC_NUMERIC, "C");
      (yyval.adouble)=atof((yysemantic_stack_[(4) - (3)].astring));
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 6397 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._xmin;
        }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 6407 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._xmax;
        }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 6417 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._ymin;
        }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 6427 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._ymax;
        }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 6437 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._zmin;
        }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 6447 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._zmax;
        }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 6457 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          DessinImageParametres* param;
          string comment;
          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
          param = draw->GetParam();
          (yyval.adouble)=param->_pos._x;
          comment = str(format(" //  xpos=%3d") % param->_pos._x);
          if (driver.in_console)
            GB_main_wxFrame->GetConsole()
                           ->IncCommand(wxString::FromAscii(comment.c_str()));
        }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 6471 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;
      string comment;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_pos._y;

      comment = str( format(" //  ypos=%3d") % param->_pos._y);
      if (driver.in_console)
        GB_main_wxFrame->GetConsole()
                       ->IncCommand(wxString::FromAscii(comment.c_str()));

    }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 6488 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;
      string comment;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_pos._z;

      comment = str( format(" //  xpos=%3d") % param->_pos._z);
      if (driver.in_console)
        GB_main_wxFrame->GetConsole()
                        ->IncCommand(wxString::FromAscii(comment.c_str()));
    }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 6504 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_AnisoGS_GetNoiseSD();
    }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 6509 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_AnisoGS_GetDAcoeff();
    }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 6514 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = Func_LevelSets_UpdateResult();
    }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 6518 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr mat = *(FloatMatrix::ptr*)(yysemantic_stack_[(6) - (1)].variable)->Pointer();
          int i = (int)(yysemantic_stack_[(6) - (3)].adouble);
          int j = (int)(yysemantic_stack_[(6) - (5)].adouble);
          (yyval.adouble) = (*mat)[i][j];
    }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 6525 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr mat = *(FloatMatrix::ptr*)(yysemantic_stack_[(8) - (1)].variable)->Pointer();
          int i = (int)(yysemantic_stack_[(8) - (3)].adouble);
          int j = (int)(yysemantic_stack_[(8) - (5)].adouble);
          (yyval.adouble)  =  ((*mat)[i][j] = (yysemantic_stack_[(8) - (8)].adouble));
    }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 6533 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
          Description:
            Adds an interface for a floating point variable to the window of parameters.

          Parameters:
            (1) variable of type window of parameters
            (5) float variable for which we want to create an interface
            (7) minimal value accepted
            (9) maximal value accepted

        Keywords:

        See also:
            ParamWin, AddInt, CreateWin, Display

        Example(s):
          a=1
          w1 = ParamWin("test")
          w1.AddFloat(a,1,100)
          w1.CreateWin
          w1.Display
      **/

      float* var = ((float_ptr*)(yysemantic_stack_[(10) - (5)].variable)->Pointer())->get();
      float min_value = (float)(yysemantic_stack_[(10) - (7)].adouble);
      float max_value = (float)(yysemantic_stack_[(10) - (9)].adouble);

      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer();
      int var_id = pw->AddFloat( var, (yysemantic_stack_[(10) - (5)].variable)->Name().c_str(),2,(yysemantic_stack_[(10) - (5)].variable)->Name());
      pw->FloatConstraints( var_id, min_value, max_value, *var );
      (yyval.adouble) = var_id;
    }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 6568 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
          Description:
            Adds an interface for a floating point variable to the window of parameters.

          Parameters:
            (3) variable of type window of parameters
            (5) string expression: label
            (7) float variable for which we want to create an interface
            (9) minimal value accepted
            (11) maximal value accepted

        Keywords:

        See also:
            ParamWin, AddInt, CreateWin, Display

        Example(s):
          a=1
          w1 = ParamWin("test")
          w1.AddFloat(a,1,100)
          w1.CreateWin
          w1.Display
      **/

      float* var = ((float_ptr*)(yysemantic_stack_[(12) - (5)].variable)->Pointer())->get();
      string_ptr label( new std::string((yysemantic_stack_[(12) - (7)].astring)));
      float min_value = (float)(yysemantic_stack_[(12) - (9)].adouble);
      float max_value = (float)(yysemantic_stack_[(12) - (11)].adouble);

      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(12) - (1)].variable)->Pointer();
      std::string tooltip = (boost::format("%s  (%s)") % (yysemantic_stack_[(12) - (5)].variable)->GetComments() % (yysemantic_stack_[(12) - (5)].variable)->Name()).str();
      int var_id = pw->AddFloat( var, label->c_str(),2,tooltip);
      pw->FloatConstraints( var_id, min_value, max_value, *var );
      (yyval.adouble) = var_id;
    }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 6606 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Parameters:
          - integer variable
          - minimal scale value
          - maximal scale value
        Description:
          Add interface to set an integer value between a minimal and a maximal value.
      **/
      int* var = ((int_ptr*)(yysemantic_stack_[(10) - (5)].variable)->Pointer())->get();
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer();
      int var_id = pw->AddInteger( var, (char*)(yysemantic_stack_[(10) - (5)].variable)->Name().c_str(), (char*)(yysemantic_stack_[(10) - (5)].variable)->Name().c_str());
      pw->IntegerConstraints( var_id, (int)(yysemantic_stack_[(10) - (7)].adouble), (int)(yysemantic_stack_[(10) - (9)].adouble), *var );
      (yyval.adouble) = var_id;
    }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 6623 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Parameters:
          - integer variable
          - string expression: label
          - minimal scale value
          - maximal scale value
        Description:
          Add interface to set an integer value between a minimal and a maximal value.
      **/
      string_ptr label( new std::string((yysemantic_stack_[(12) - (7)].astring)));
      int* var = ((int_ptr*)(yysemantic_stack_[(12) - (5)].variable)->Pointer())->get();
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(12) - (1)].variable)->Pointer();
      std::string tooltip = (boost::format("%s  (%s)") % (yysemantic_stack_[(12) - (5)].variable)->GetComments() % (yysemantic_stack_[(12) - (5)].variable)->Name()).str();
      int var_id = pw->AddInteger( var, label->c_str(), tooltip);
      pw->IntegerConstraints( var_id, (int)(yysemantic_stack_[(12) - (9)].adouble), (int)(yysemantic_stack_[(12) - (11)].adouble), *var );
      (yyval.adouble) = var_id;
    }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 6643 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    int bid;
    ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
    std::string tooltip = (boost::format("%s  (%s)") % (yysemantic_stack_[(8) - (7)].variable)->GetComments() % (yysemantic_stack_[(8) - (7)].variable)->Name()).str();
    pw->AddButton( &bid, (yysemantic_stack_[(8) - (5)].astring),
                (void*) CB_Button,
                (void*) (yysemantic_stack_[(8) - (7)].variable),
                tooltip);
    (yyval.adouble) = bid;
    }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 6655 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (5) Variable of type UCHAR

    Description:
      Adds a boolean variable to the parameter window.
    **/
      unsigned char*   var = ((uchar_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get();
      ParamPanel_ptr pw  = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      int var_id;
      pw->AddBoolean( &var_id, var, (char*)(yysemantic_stack_[(6) - (5)].variable)->Name().c_str());
      pw->BooleanDefault( var_id, *var);
      (yyval.adouble) = var_id;
    }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 6672 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (5) Variable of type UCHAR
      (7) string expression: label

    Description:
      Adds a boolean variable to the parameter window.
    **/
      string_ptr label( new std::string((yysemantic_stack_[(8) - (7)].astring)));
      unsigned char*   var = ((uchar_ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get();
      ParamPanel_ptr pw  = *(ParamPanel_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
      int var_id;
      std::string tooltip = (boost::format("%s  (%s)") % (yysemantic_stack_[(8) - (5)].variable)->GetComments() % (yysemantic_stack_[(8) - (5)].variable)->Name()).str();
      pw->AddBoolean( &var_id, var, label->c_str(),CaractereToggle,tooltip);
      pw->BooleanDefault( var_id, *var);
      (yyval.adouble) = var_id;
    }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 6692 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      - string variable that will contain the name of the
              selected image
      - label: description of the image to select
    Description:
      Allows the user to choose among the current image variables available
    **/
      string_ptr label( new std::string((yysemantic_stack_[(8) - (7)].astring)));
      ParamPanel_ptr pw  = *(ParamPanel_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
      boost::shared_ptr<wxArrayString> imagelist;
      int var_id;

      imagelist = Vars.SearchVariables(type_image);
      imagelist->Add(_T("Image"));

      // Get comments as tooltip
      std::string tooltip = (boost::format("%s  (%s)") % (yysemantic_stack_[(8) - (5)].variable)->GetComments() % (yysemantic_stack_[(8) - (5)].variable)->Name()).str();

      // Get list of image names
      pw->AddListChoice( &var_id,
          (string_ptr*)(yysemantic_stack_[(8) - (5)].variable)->Pointer(),
          label->c_str(),
          imagelist,
          (void*)CB_update_imagelist,
          EnumOptionMenu,
          tooltip);
      //pw->EnumerationDefaut( var_id,  *var);
      (yyval.adouble) = var_id;
    }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 6725 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (5) Variable of type INT
      (7) number of different values of the enumeration

    Description:
      Adds an integer variable as an enumeration to the parameter window.
    **/
      int*   var = ((int_ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get();
      ParamPanel_ptr pw  = *(ParamPanel_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
      int size = (int) (yysemantic_stack_[(8) - (7)].adouble);
      int var_id;
      pw->AddEnumeration( &var_id, size, var, (char*)(yysemantic_stack_[(8) - (5)].variable)->Name().c_str());
      //pw->EnumerationDefaut( var_id,  *var);
      (yyval.adouble) = var_id;
    }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 6744 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (5) Variable of type INT
      (7) expr_string label

    Description:
      Adds an integer variable as an enumeration to the parameter window.
    **/
      string_ptr label( new std::string((yysemantic_stack_[(8) - (7)].astring)));
      int*   var = ((int_ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get();
      ParamPanel_ptr pw  = *(ParamPanel_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
      int var_id;
      std::string tooltip = (boost::format("%s  (%s)") % (yysemantic_stack_[(8) - (5)].variable)->GetComments() % (yysemantic_stack_[(8) - (5)].variable)->Name()).str();
      pw->AddEnumeration( &var_id,  var, label->c_str(),
                          EnumOptionMenu,
                          tooltip);
      //pw->EnumerationDefaut( var_id,  *var);
      (yyval.adouble) = var_id;
    }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 6766 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (5) Variable of type INT

    Description:
      Adds an integer variable as an enumeration to the parameter window.
    **/
      int*   var = ((int_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get();
      ParamPanel_ptr pw  = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      int var_id;
      pw->AddEnumeration( &var_id, var, (char*)(yysemantic_stack_[(6) - (5)].variable)->Name().c_str());
      (yyval.adouble) = var_id;
    }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 6782 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (5) expression:        identificator of the enumeration parameter
      (7) string expression: text associated to this choice

    Description:
      Adds a choice for an enumeration created in the parameter window
    **/
      string_ptr text( new std::string((yysemantic_stack_[(8) - (7)].astring)));
      ParamPanel_ptr pw  = *(ParamPanel_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
      int id = (int) (yysemantic_stack_[(8) - (5)].adouble);
      int var_id;
      pw->AddEnumChoice( id, &var_id, text->c_str());
      (yyval.adouble) = var_id;
    }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 6800 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (1) Parameter window
      (5) String variable to interface
      (7) label

    Description:
      Adds a string in the parameter window
    **/
        string_ptr label( new std::string((yysemantic_stack_[(8) - (7)].astring)));
        ParamPanel_ptr pw  = *(ParamPanel_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
        int var_id;
        std::string tooltip = (boost::format("%s  (%s)") % (yysemantic_stack_[(8) - (5)].variable)->GetComments() % (yysemantic_stack_[(8) - (5)].variable)->Name()).str();
        pw->AjouteChaine( &var_id,
          (string_ptr*)(yysemantic_stack_[(8) - (5)].variable)->Pointer(),
          label->c_str(),
          tooltip);
        pw->ContraintesChaine(var_id,
          (char*) ((string_ptr*)(yysemantic_stack_[(8) - (5)].variable)->Pointer())->get()->c_str());
        (yyval.adouble)=var_id;
    }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 6824 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (1) Parameter window
      (5) label label
      (7) label value

    Description:
      Adds a label in the parameter window
    **/
        ParamPanel_ptr pw  = *(ParamPanel_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
        string_ptr label( new std::string((yysemantic_stack_[(8) - (5)].astring)));
        string_ptr value( new std::string((yysemantic_stack_[(8) - (7)].astring)));
        int var_id;
        pw->AddLabel( &var_id,
                      label->c_str(),
                      value->c_str());
        (yyval.adouble)=var_id;
    }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 6845 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (1) Parameter window
      (5) String variable to interface
      (7) label
      (9) default path
      (11) default mask

    Description:
      Adds a filename in the parameter window
    **/
        ParamPanel_ptr pw  = *(ParamPanel_ptr*) (yysemantic_stack_[(12) - (1)].variable)->Pointer();
        int var_id;
        string_ptr label( new std::string((yysemantic_stack_[(12) - (7)].astring)));
        string_ptr defpath( new std::string((yysemantic_stack_[(12) - (9)].astring)));
        string_ptr defmask( new std::string((yysemantic_stack_[(12) - (11)].astring)));

        // passer AjouteNomFichier a std::string !!!!
        pw->AjouteNomFichier( &var_id, (string_ptr*)(yysemantic_stack_[(12) - (5)].variable)->Pointer(), label->c_str());
        pw->ContraintesNomFichier(var_id,
                                  defpath->c_str(),
                                  (char*)"",
                                  defmask->c_str());
        (yyval.adouble)=var_id;
    }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 6873 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        string expression
      Description:
        Adds a box around the parameters, with the given text as label, and returns the id of the created box.
    **/
      string_ptr label( new std::string((yysemantic_stack_[(6) - (5)].astring)));
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      pw->BeginBox( label->c_str());
      (yyval.adouble)= pw->NbBoxes()-1;
    }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 6887 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    **/
      string_ptr label( new std::string((yysemantic_stack_[(6) - (5)].astring)));
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      int id = pw->AddPage( label->c_str());
      (yyval.adouble)=id;
    }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 6897 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description:
        Adds a new NoteBook, return the corresponding id.
      See also:
        EndBook, AddPage
    **/
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      int id = pw->BeginBook();
      (yyval.adouble) = id;
    }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 6910 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        string expr: label of the new panel
      Description:
        Adds a new panel, return the id of the corresponding panel
    **/
      string_ptr label( new std::string((yysemantic_stack_[(6) - (5)].astring)));
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      int id = pw->BeginPanel( label->c_str());
      (yyval.adouble)=id;
    }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 6924 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        string expr: label of the new panel
      Description:
        Adds a new panel, return the id of the corresponding panel
    **/
      string_ptr label( new std::string((yysemantic_stack_[(6) - (5)].astring)));
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      pw->BeginBox( label->c_str());
      int id = pw->BeginPanel( label->c_str());
      //$$= pw->NbBoxes()-1;
      (yyval.adouble)=id;
    }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 6939 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
    Check for the existence of a variable, returns 0
    **/
          (yyval.adouble)=0;
    }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 6947 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description: 
    Check for the existence of a variable, returns 1
    **/
          (yyval.adouble)=1;
    }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 6955 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      string: input filename
    Description:
      Check for the existence of the given filename
    **/
      string_ptr name( new std::string((yysemantic_stack_[(4) - (3)].astring)));

      (yyval.adouble) = wxFileExists(wxString(name->c_str(),wxConvUTF8));
    }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 6967 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble) = (int) (yysemantic_stack_[(1) - (1)].aint);
    }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 6971 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description:
        Scans a float number in the given file and based on the
        given formatting expression.
    **/
        float res;
        FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
        string_ptr format( new std::string((yysemantic_stack_[(6) - (5)].astring)));

        setlocale(LC_NUMERIC, "C");
        fscanf(file.get(),format->c_str(),&res);
        (yyval.adouble) =  res;
    }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 6986 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       float*  var = ((float_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get();
        FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
        setlocale(LC_NUMERIC, "C");
        (yyval.adouble) = fscanf(file.get(),"%f",var);
    }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 6993 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
      setlocale(LC_NUMERIC, "C");
      // not safe, TODO: use iostream or boost for files here ...
      char res[100];
      (yyval.adouble) = fscanf(file.get(),"%s",res);
      string_ptr var( new std::string(res));
      (yysemantic_stack_[(6) - (5)].variable)->SetString(var);
    }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 7003 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        - input polydata
      Description: 
        Returns the number of lines of the polydata structure
    **/
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

      (yyval.adouble) = s->GetNumberOfLines(  );
    }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 7015 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        - 2 numbers
      Description: 
        Returns the maximal value
    **/
      (yyval.adouble) = macro_max((yysemantic_stack_[(6) - (3)].adouble),(yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 7028 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(2) - (2)].adouble); }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 7029 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(!,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 7030 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(-,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 7031 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(+,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 7032 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(sin,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 7033 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(cos,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 7034 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(sqrt,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 7035 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(fabs,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 7036 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(round,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 7038 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:
                return the closest integer smaller than the given expression value.
           **/
          UNARYOP_EXPR(floor,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble))
        }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 7045 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(tan,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 7046 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(asin,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 7047 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(acos,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 7048 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(atan,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 7050 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { 
        /**
          Parameters:
            - input expression
          Description:
            Returns exponiential of the input (e^input).
          See also:
            ln, log
        **/
          UNARYOP_EXPR(exp,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) 
        }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 7062 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { 
        /**
          Parameters:
            - input expression
          Description:
            Returns logarithm base 10 of the input.
          See also:
            ln, exp
        **/
          UNARYOP_EXPR(1.0/log(10.0)*log,(yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) 
        }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 7074 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { 
        /**
          Parameters:
            - input expression
          Description:
            Returns natural logarithm of the input.
          See also:
            log, exp
        **/
            UNARYOP_EXPR(log,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) 
        }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 7097 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      switch((WORDTYPE) (yysemantic_stack_[(4) - (2)].aint)) {
      case WT_UNSIGNED_CHAR:  (yyval.adouble)=(unsigned char) (yysemantic_stack_[(4) - (4)].adouble); break;
      case WT_SIGNED_SHORT:   (yyval.adouble)=(short) (yysemantic_stack_[(4) - (4)].adouble);  break;
      case WT_UNSIGNED_SHORT: (yyval.adouble)=(unsigned short) (yysemantic_stack_[(4) - (4)].adouble);  break;
      case WT_SIGNED_INT:     (yyval.adouble)=(int) (yysemantic_stack_[(4) - (4)].adouble);  break;
      case WT_UNSIGNED_INT:   (yyval.adouble)=(unsigned int) (yysemantic_stack_[(4) - (4)].adouble);  break;
      case WT_FLOAT:          (yyval.adouble)=(float) (yysemantic_stack_[(4) - (4)].adouble);  break;
      default:
        fprintf(stderr,"Conversion not available\n");
      }
        }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 7113 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)*(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 7114 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)/(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 7115 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)= ((int) round((yysemantic_stack_[(3) - (1)].adouble))) % ((int) round((yysemantic_stack_[(3) - (3)].adouble))); }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 7120 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)+(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 7121 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)-(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 7131 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)<(yysemantic_stack_[(3) - (3)].adouble));  }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 7132 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)>(yysemantic_stack_[(3) - (3)].adouble));  }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 7133 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)<=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 7134 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)>=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 7139 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)==(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 7140 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)!=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 7141 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(strcmp((yysemantic_stack_[(3) - (1)].astring),(yysemantic_stack_[(3) - (3)].astring))==0); }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 7142 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(strcmp((yysemantic_stack_[(3) - (1)].astring),(yysemantic_stack_[(3) - (3)].astring))!=0); }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 7148 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = ((int)(yysemantic_stack_[(3) - (1)].adouble)) & ((int)(yysemantic_stack_[(3) - (3)].adouble));
    }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 7161 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
        }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 7165 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = ((int)(yysemantic_stack_[(3) - (1)].adouble)) | ((int)(yysemantic_stack_[(3) - (3)].adouble));
        }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 7172 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
        }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 7176 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)&&(yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 7183 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
    }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 7187 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)||(yysemantic_stack_[(3) - (3)].adouble);
    }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 7195 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=((yysemantic_stack_[(5) - (1)].adouble)?(yysemantic_stack_[(5) - (3)].adouble):(yysemantic_stack_[(5) - (5)].adouble));
        }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 7212 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.err_print(" char format is not available: use unsigned char \n");
      (yyval.aint)=WT_UNSIGNED_CHAR;
    }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 7217 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.aint)=WT_UNSIGNED_CHAR;
       }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 7221 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_SHORT;
       }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 7225 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_SHORT;
       }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 7229 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_INT;
       }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 7233 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_INT;
       }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 7237 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT;
       }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 7241 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_DOUBLE;
       }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 7245 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_RGB;
       }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 7249 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT_VECTOR;
       }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 7253 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//        printf("format %d \n",(int) ( *(InrImage::ptr*) $1->Pointer())->GetFormat());
        (yyval.aint) = (int) (*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetFormat();
      }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 7261 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yysemantic_stack_[(1) - (1)].variable);
        }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 7266 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          VarArray::ptr array;
          int  i = (int) (yysemantic_stack_[(4) - (3)].adouble);

          array = *(VarArray::ptr*) ((yysemantic_stack_[(4) - (1)].variable)->Pointer());
          if (array->GetVar(i).Pointer()==NULL) {
            // create a small image to avoid problems
            InrImage* im = new InrImage(1,1,1,WT_UNSIGNED_CHAR);
            string name = str(format("%s[%d]") % (yysemantic_stack_[(4) - (1)].variable)->Name() % i);
            array->InitElement(i,im,name.c_str());
          }
          (yyval.variable)=&(array->GetVar(i));
        }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 7283 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     driver.im_stack.AddImage((yysemantic_stack_[(2) - (2)].astring));
     delete [] (yysemantic_stack_[(2) - (2)].astring);
       }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 7289 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     driver.im_stack.AddImage((yysemantic_stack_[(4) - (3)].astring));
     delete [] (yysemantic_stack_[(4) - (3)].astring);
       }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 7296 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       /**
       Parameters:
         (3)  dimension in X
         (5)  dimension in Y
         (7)  image type, one of: CHAR, UCHAR, SHORT,
                                 USHORT, FLOAT, DOUBLE, RGB, FLOAT_VECTOR.
         (9)  endianess: 0 for little, 1 for big.
         (11) filename or file format
         (13) first slice number
         (15) last slice number

       Description:
         Read 2D raw data (or a sequence of 2D raw data) as an image.
         The program can read raw data compressed with gzip:
         if the file is not found, it looks for the same filename with a '.gz' extention. If
         it can find it, it will open the file using the 'popen' (pipe open) command and the 'gunzip' program.

       Example(s):
          i = ReadRawImages(1024,1024,USHORT,0,"AfGG.%d",48,48)
       **/
     InrImage* im  = new InrImage();
     amimage* amim = new amimage();
     int dimx                    = (int)           (yysemantic_stack_[(16) - (3)].adouble);
     int dimy                    = (int)           (yysemantic_stack_[(16) - (5)].adouble);
     WORDTYPE inr_format         = (WORDTYPE)      (yysemantic_stack_[(16) - (7)].aint);
     int endianness              = (int)           (yysemantic_stack_[(16) - (9)].adouble);
     char* file_format           = (char*)         (yysemantic_stack_[(16) - (11)].astring);
     unsigned short first_slice  = (unsigned short)(yysemantic_stack_[(16) - (13)].adouble);
     unsigned short last_slice   = (unsigned short)(yysemantic_stack_[(16) - (15)].adouble);

         amim->SetDim(dimx,dimy,1);
     if (endianness)
       amim->endianness = BIG_END;
     else
       amim->endianness = LITTLE_END;

         im->AMIFromWT(1,inr_format,amim);
     amim->datafile    = AMI_DATAEXT;
     amim->file_format = file_format;
     delete [] file_format;
     amim->first_slice = first_slice;
     amim->last_slice  =  last_slice;

     if (amim->readdata_ext()) {
       im->SetAMImage(amim);
       driver.im_stack.AddImage(im);
     } else {
       // Error message
       driver.err_print("ReadRawImages() failed ... \n");
       driver.im_stack.AddImage((InrImage*)NULL);
       delete amim;
       delete im;
     }
       }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 7354 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       /**
       Parameters:
         (3)  dimension in X
         (5)  dimension in Y
         (7)  dimension in Z
         (9)  image type, one of: CHAR, UCHAR, SHORT,
                                 USHORT, FLOAT, DOUBLE, RGB, FLOAT_VECTOR.
         (11)  endianess: 0 for little, 1 for big.
         (13) filename or file format

       Description:
         Read 3D raw data as an image.
         The program can read raw data compressed with gzip:
         if the file is not found, it looks for the same filename with a '.gz' extention. If
         it can find it, it will open the file using the 'popen' (pipe open) command and the 'gunzip' program.

       Example(s):
          i = ReadRawImages(256,256,256,USHORT,0,"data.raw")
       **/
     InrImage* im  = new InrImage();
     amimage* amim = new amimage();
     int dimx                    = (int)           (yysemantic_stack_[(14) - (3)].adouble);
     int dimy                    = (int)           (yysemantic_stack_[(14) - (5)].adouble);
     int dimz                    = (int)           (yysemantic_stack_[(14) - (7)].adouble);
     WORDTYPE inr_format         = (WORDTYPE)      (yysemantic_stack_[(14) - (9)].aint);
     int endianness              = (int)           (yysemantic_stack_[(14) - (11)].adouble);
     char* file_format           = (char*)         (yysemantic_stack_[(14) - (13)].astring);

         amim->SetDim(dimx,dimy,dimz);
     if (endianness)
       amim->endianness = BIG_END;
     else
       amim->endianness = LITTLE_END;

     im->AMIFromWT(1,inr_format,amim);
     amim->datafile    = AMI_DATAEXT;
     amim->file_format = file_format;
     delete [] file_format;

     if (amim->readdata3D_ext()) {
       im->SetAMImage(amim);
       driver.im_stack.AddImage(im);
     } else {
       // Error message
       driver.err_print("ReadRawImages() failed ... \n");
       driver.im_stack.AddImage((InrImage*)NULL);
       delete amim;
       delete im;
     }
       }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 7408 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       /**
       Parameters:
         (3)  dimension in X
         (5)  dimension in Y
         (7)  dimension in Z
         (9)  image type, one of: CHAR, UCHAR, SHORT,
                                 USHORT, FLOAT, DOUBLE, RGB,
         (11) Vectorial dimension
         (13)  endianess: 0 for little, 1 for big.
         (15) filename or file format

       Description:
         Read 3D raw data as an image.
         The program can read raw data compressed with gzip:
         if the file is not found, it looks for the same filename with a '.gz' extention. If
         it can find it, it will open the file using the 'popen' (pipe open) command and the 'gunzip' program.

       Example(s):
          i = ReadRawImages(256,256,256,FLOAT,3,0,"3dvectorfielddata.raw")
       **/
     InrImage* im  = new InrImage();
     amimage* amim = new amimage();
     int dimx                    = (int)           (yysemantic_stack_[(16) - (3)].adouble);
     int dimy                    = (int)           (yysemantic_stack_[(16) - (5)].adouble);
     int dimz                    = (int)           (yysemantic_stack_[(16) - (7)].adouble);
     WORDTYPE inr_format         = (WORDTYPE)      (yysemantic_stack_[(16) - (9)].aint);
     int vdim                    = (int)           (yysemantic_stack_[(16) - (11)].adouble);
     int endianness              = (int)           (yysemantic_stack_[(16) - (13)].adouble);
     char* file_format           = (char*)         (yysemantic_stack_[(16) - (15)].astring);

     amim->SetDim(dimx,dimy,dimz);
     amim->SetVDim(vdim);
     if (endianness)
       amim->endianness = BIG_END;
     else
       amim->endianness = LITTLE_END;

     im->AMIFromWT(vdim,inr_format,amim);
     amim->datafile    = AMI_DATAEXT;
     amim->file_format = file_format;
     delete [] file_format;

     if (amim->readdata3D_ext()) {
       im->SetAMImage(amim);
       driver.im_stack.AddImage(im);
     } else {
       // Error message
       driver.err_print("ReadRawImages() failed ... \n");
       driver.im_stack.AddImage((InrImage*)NULL);
       delete amim;
       delete im;
     }
       }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 7463 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       /**
       Parameters:
        (3) STRING EXPRESSION: dicom directory

       Description:
         Reads a dicom file using VTK
       **/
            InrImage*  res;

            res = Func_vtkDicomRead( (char*) (yysemantic_stack_[(4) - (3)].astring));

            Si res==NULL Alors
                driver.err_print("vtkDicomRead() error ... \n");
                driver.im_stack.AddImage((InrImage*)NULL);
            FinSi

            driver.im_stack.AddImage(res);
            delete [] (yysemantic_stack_[(4) - (3)].astring);
       }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 7484 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       /**
       Parameters:
        (3) STRING EXPRESSION: filename in minc format

       Description:
         Reads a file in minc format using vtk reader for MINC.
       **/
            InrImage*  res;

            res = Func_vtkMINCRead( (char*) (yysemantic_stack_[(4) - (3)].astring));

            Si res==NULL Alors
                driver.err_print("vtkMINCRead() error ... \n");
                driver.im_stack.AddImage((InrImage*)NULL);
            FinSi

            driver.im_stack.AddImage(res);
            delete [] (yysemantic_stack_[(4) - (3)].astring);
       }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 7505 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       Variable*  var   = (yysemantic_stack_[(4) - (1)].variable);
       ParamList::ptr param((yysemantic_stack_[(4) - (3)].paramlist));
       InrImage*  im;

       im = ((InrImage* (*)(ParamList*)) var->Pointer())(param.get());
       if (!im) {
        driver.yyiperror(" image function returns NULL \n");
        YYABORT;
       }
      driver.im_stack.AddImage(im);
       }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 7519 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          int res;
          string name;
          string inc_cmd; // increment the command line string

          res=AskImage(name);
          if (!res) {
            driver.yyiperror(" Need Image \n");
            YYABORT;
          }
          driver.im_stack.AddImage((char*)name.c_str());


          wxFileName filename(GetwxStr(name));
          filename.Normalize(wxPATH_NORM_ALL,wxEmptyString,wxPATH_UNIX);
          wxString newname(   filename.GetVolume()+filename.GetVolumeSeparator()+
                              filename.GetPath(wxPATH_GET_VOLUME,wxPATH_UNIX)+
                              filename.GetPathSeparator(wxPATH_UNIX)+
                              filename.GetFullName());
          driver.res_print(newname.mb_str());
          driver.res_print("\n");
          inc_cmd = str(format(" \"%1%\" // from browser ") % newname.mb_str());

          if (driver.in_console)
            GB_main_wxFrame->GetConsole()
                            ->IncCommand(wxString::FromAscii(inc_cmd.c_str()));
      }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 7548 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage* im;
        //printf(" ********** %d %f %f %f\n", $3, $5, $7, $9);
        im = new InrImage( (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble), (WORDTYPE) (yysemantic_stack_[(10) - (3)].aint));
        driver.im_stack.AddImage(im);
      }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 7556 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    InrImage* im;
    //printf(" ********** %d %f %f %f\n", $3, $5, $7, $9);
    im = new InrImage( (int) (yysemantic_stack_[(12) - (5)].adouble), (int) (yysemantic_stack_[(12) - (7)].adouble), (int) (yysemantic_stack_[(12) - (9)].adouble), (int) (yysemantic_stack_[(12) - (11)].adouble), (WORDTYPE) (yysemantic_stack_[(12) - (3)].aint));
    driver.im_stack.AddImage(im);
    }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 7575 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage* im;
      WORDTYPE imformat = (WORDTYPE) (yysemantic_stack_[(8) - (3)].aint);
      int vdim   = (int) (yysemantic_stack_[(8) - (5)].adouble);
      InrImage::ptr varim=*(InrImage::ptr*) (yysemantic_stack_[(8) - (7)].variable)->Pointer();
      string  imname;

      imname = str(format("newimagefrom_%s.ami.gz")
                  % (yysemantic_stack_[(8) - (7)].variable)->Name());

      im = new InrImage(imformat,vdim,
                        imname.c_str(),varim.get());
      driver.im_stack.AddImage(im);
    }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 7601 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         InrImage::ptr varim;
         InrImage* im;
         char  imname[200];

         varim=*(InrImage::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();
         sprintf(imname,"copy_%s",(yysemantic_stack_[(1) - (1)].variable)->Name().c_str());
         im = new InrImage(varim->_format,imname,varim.get());
         (*im)=(*varim);
          driver.im_stack.AddImage(im);
       }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 7614 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       /**
        Description:
          Applied on RGB or vectorial images,
          returns one component of the image:
          expr=0 returns Red   if RGB or the X coordinate if vectorial
          expr=1 returns Green if RGB or the Y coordinate if vectorial
          expr=2 returns Blue  if RGB or the Z coordinate if vectorial

        Example(s):
          i = Image "test.jpg"
          ired   = i[0]
          igreen = i[1]
          iblue  = i[2]

          print ired(i.tx/2,i.ty/2); print "\n"
          print i(i.tx/2,i.ty/2,0,0); print "\n"
       **/
         InrImage::ptr im1;
         InrImage* im;
          char  imname[200];
         int i;

         im1=*(InrImage::ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer();

          i = (int) (yysemantic_stack_[(4) - (3)].adouble);
          Si i<0               AlorsFait i = 0;
          Si i>=im1->GetVDim() AlorsFait i = im1->GetVDim()-1;
          sprintf(imname,"C%d_%s",i,(yysemantic_stack_[(4) - (1)].variable)->Name().c_str());

         SelonQue im1->_format Vaut
          Valeur WT_RGB:
          Valeur WT_RGBA:
          Valeur WT_UNSIGNED_CHAR:
             im = new InrImage(WT_UNSIGNED_CHAR,1,imname,im1.get());
          FinValeur

          Valeur WT_UNSIGNED_INT:
             im = new InrImage(WT_UNSIGNED_INT,1,imname,im1.get());
          FinValeur

          Valeur WT_SIGNED_INT:
             im = new InrImage(WT_SIGNED_INT,1,imname,im1.get());
          FinValeur

          Valeur WT_UNSIGNED_SHORT:
             im = new InrImage(WT_UNSIGNED_SHORT,1,imname,im1.get());
          FinValeur

          Valeur WT_SIGNED_SHORT:
             im = new InrImage(WT_SIGNED_SHORT,1,imname,im1.get());
          FinValeur

          Valeur WT_FLOAT_VECTOR:
          Valeur WT_FLOAT:
             im = new InrImage(WT_FLOAT,1,imname,im1.get());
          FinValeur

          Valeur WT_DOUBLE:
             im = new InrImage(WT_DOUBLE,1,imname,im1.get());
          FinValeur

       Defaut:
        driver.yyiperror(" operator [] does not handle this format \n");
        YYABORT;
         FinSelonQue

         im->InitBuffer();
         im1->InitBuffer();
         Repeter
           im->FixeValeur(im1->VectValeurBuffer(i));
               im1->IncBuffer();
         JusquA Non(im->IncBuffer()) FinRepeter
         driver.im_stack.AddImage(im);

       }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 7692 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    InrImage* im = (InrImage*) driver.im_stack.GetLastImage();
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
    }
    } else
    {
      driver.err_print("sum operator only for scalar images ... \n");
    }
        driver.im_stack.AddImage(res);
        delete im;
    }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 7759 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im  = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res =Func_localmean( im, (int) (yysemantic_stack_[(6) - (5)].adouble));
      driver.im_stack.AddImage(res);
      delete im;
    }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 7767 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im  = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res =Func_localmean2( im, (int) (yysemantic_stack_[(6) - (5)].adouble));
      driver.im_stack.AddImage(res);
      delete im;
      }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 7775 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage* mean    = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* im      = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* res     = Func_localSD( im, mean, (int) (yysemantic_stack_[(8) - (7)].adouble));
    driver.im_stack.AddImage(res);
    delete im;
    delete mean;
      }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 7785 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage* mean    = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* im      = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* res     = Func_localSD2( im, mean, (int) (yysemantic_stack_[(8) - (7)].adouble));
    driver.im_stack.AddImage(res);
    delete im;
    delete mean;
      }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 7795 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
      Returns the image corresponding to the pointwise maximum between 2 images.


      See also:
              min, median
        **/
    InrImage* im1;
    InrImage* im2;
        float val1,val2;

    im2 = driver.im_stack.GetLastImage();
    im1 = driver.im_stack.GetLastImage();
    im1->InitBuffer();
    im2->InitBuffer();
    Repeter
          val1 = im1->ValeurBuffer();
      val2 = im2->ValeurBuffer();
      Si val2>val1 AlorsFait im1->FixeValeur(val2);
      im2->IncBuffer();
    JusquA Non(im1->IncBuffer())
    FinRepeter
    driver.im_stack.AddImage(im1);
    delete im2;

      }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 7825 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_OpImage(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
              NULL,
              NULL,
              (yysemantic_stack_[(6) - (5)].astring));
    Si res==NULL Alors
      driver.err_print("OpImage() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
    delete [] (yysemantic_stack_[(6) - (3)].variable);

      }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 7843 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_OpImage(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
              NULL,
              NULL,
              (yysemantic_stack_[(8) - (5)].astring),
              (WORDTYPE) (yysemantic_stack_[(8) - (7)].aint));
    Si res==NULL Alors
      driver.err_print("OpImage() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);

    delete [] (yysemantic_stack_[(8) - (5)].astring);

      }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 7863 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_OpImage(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
              ((InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get(),
              NULL,
              (yysemantic_stack_[(8) - (7)].astring));
    Si res==NULL Alors
      driver.err_print("OpImage() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);

    delete [] (yysemantic_stack_[(8) - (7)].astring);
      }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 7881 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_OpImage(((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),
              ((InrImage::ptr*) (yysemantic_stack_[(10) - (5)].variable)->Pointer())->get(),
              NULL,
              (yysemantic_stack_[(10) - (7)].astring),
              (yysemantic_stack_[(10) - (9)].aint));
    Si res==NULL Alors
      driver.err_print("OpImage() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);

    delete [] (yysemantic_stack_[(10) - (7)].astring);

      }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 7901 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*  res;

        res = Func_OpImage(
            ((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),
            ((InrImage::ptr*) (yysemantic_stack_[(10) - (5)].variable)->Pointer())->get(),
            ((InrImage::ptr*) (yysemantic_stack_[(10) - (7)].variable)->Pointer())->get(),
              (yysemantic_stack_[(10) - (9)].astring));
        Si res==NULL Alors
          driver.err_print("OpImage() erreur ... \n");
          res=((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get();
        FinSi
        driver.im_stack.AddImage(res);

        delete [] (yysemantic_stack_[(10) - (9)].astring);
      }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 7920 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*  res;

        res = Func_OpImage(
            ((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get(),
            ((InrImage::ptr*) (yysemantic_stack_[(12) - (5)].variable)->Pointer())->get(),
            ((InrImage::ptr*) (yysemantic_stack_[(12) - (7)].variable)->Pointer())->get(),
              (yysemantic_stack_[(12) - (9)].astring),
              (yysemantic_stack_[(12) - (11)].aint));
        Si res==NULL Alors
          driver.err_print("OpImage() erreur ... \n");
          res=((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get();
        FinSi
        driver.im_stack.AddImage(res);
        delete [] (yysemantic_stack_[(12) - (9)].astring);
      }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 7941 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        InrImage*  res;
        InrImage* im = (InrImage*) driver.im_stack.GetLastImage();

        res = Func_Filter( im,
                  (yysemantic_stack_[(12) - (5)].adouble),
                  (int) (yysemantic_stack_[(12) - (7)].adouble),
                  (int) (yysemantic_stack_[(12) - (9)].adouble),
                  (int) (yysemantic_stack_[(12) - (11)].adouble));

        Si res==NULL Alors
          driver.err_print("Filter() erreur ... \n");
          res=im;
        Sinon
          delete im;
        FinSi
        driver.im_stack.AddImage(res);
      }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 7978 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage* res;
        float var           = (yysemantic_stack_[(10) - (7)].adouble);
        float lowthreshold  = (yysemantic_stack_[(10) - (9)].adouble);
        //float highthreshold = $11;
            res = Func_itkCannyEdgeDetector(  ((InrImage::ptr*) (yysemantic_stack_[(10) - (5)].variable)->Pointer())->get(), var, lowthreshold);
        Si res==NULL Alors
          driver.err_print("itk.CannyEdgeDetector() error ... \n");
          res=((InrImage::ptr*) (yysemantic_stack_[(10) - (5)].variable)->Pointer())->get();
        FinSi

        driver.im_stack.AddImage(res);
      }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 7993 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*  res;

        res = Func_vtkDist( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());

        Si res==NULL Alors
          driver.err_print("vtkDist() erreur ... \n");
          res=((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get();
        FinSi

        driver.im_stack.AddImage(res);
      }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 8007 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*  res;

        res = Func_vtkMedianFilter3D(
            ((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),
            (int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        Si res==NULL Alors
          driver.err_print("vtkMedian3D() erreur ... \n");
          res=((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get();
        FinSi

        driver.im_stack.AddImage(res);
      }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 8023 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
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

  case 589:

/* Line 678 of lalr1.cc  */
#line 8046 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_2DFlux( driver.im_stack.GetLastImage(),(yysemantic_stack_[(6) - (5)].adouble));

    Si res==NULL Alors
      driver.err_print("2DFlux() error ... \n");
      res=NULL;
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 8060 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_OutFlux( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());

    Si res==NULL Alors
      driver.err_print("OutFlux() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 8074 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_OutFluxScalar( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());

    Si res==NULL Alors
      driver.err_print("OutFluxScalar() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 8088 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_OrientationRatio2D( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());

    Si res==NULL Alors
      driver.err_print("OrientationRatio() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 8102 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    InrImage*  res;

    res = Func_Thinning( ((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get(),
                 ((InrImage::ptr*) (yysemantic_stack_[(12) - (5)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(12) - (7)].adouble),
                 (yysemantic_stack_[(12) - (9)].adouble),
                 (yysemantic_stack_[(12) - (11)].adouble));

    Si res==NULL Alors
      driver.err_print("Skeleton() error ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 8137 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_SimplePoints( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get() );

    Si res==NULL Alors
      driver.err_print("SimplePoints() error ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 8152 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*  res;

        res = Func_CircleIntegration(
          ((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable) ->Pointer())->get(), // gradient
          ((InrImage::ptr*) (yysemantic_stack_[(12) - (5)].variable) ->Pointer())->get(),  // first  vector
          ((InrImage::ptr*) (yysemantic_stack_[(12) - (7)].variable) ->Pointer())->get(),  // second vector
          (float)     (yysemantic_stack_[(12) - (9)].adouble),              // radius
          CIRCLE_RESPONSE_MEAN,          // integration type
          ((InrImage::ptr*) (yysemantic_stack_[(12) - (11)].variable)->Pointer())->get()); // mask

        Si res==NULL Alors
          driver.err_print("CircleInt() error ... \n");
          res=((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get();
        FinSi

        driver.im_stack.AddImage(res);
      }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 8173 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;

      res = Func_CircleIntegration(
        ((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable) ->Pointer())->get(),  // gradient
        ((InrImage::ptr*) (yysemantic_stack_[(12) - (5)].variable) ->Pointer())->get(),  // first  vector
        ((InrImage::ptr*) (yysemantic_stack_[(12) - (7)].variable) ->Pointer())->get(),  // second vector
        (float)     (yysemantic_stack_[(12) - (9)].adouble),              // radius
        CIRCLE_RESPONSE_MEAN,        // integration type
        ((InrImage::ptr*) (yysemantic_stack_[(12) - (11)].variable)->Pointer())->get()); // mask

      Si res==NULL Alors
        driver.err_print("CircleInt() error ... \n");
        res=((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get();
      FinSi

      driver.im_stack.AddImage(res);
      }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 8194 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        InrImage*  res;

        res = Func_CircleIntSdExc(
          ((InrImage::ptr*) (yysemantic_stack_[(16) - (3)].variable) ->Pointer())->get(),  // gradient
          ((InrImage::ptr*) (yysemantic_stack_[(16) - (5)].variable) ->Pointer())->get(),  // first  vector
          ((InrImage::ptr*) (yysemantic_stack_[(16) - (7)].variable) ->Pointer())->get(),  // second vector
          (float)     (yysemantic_stack_[(16) - (9)].adouble),              // radius
          ((InrImage::ptr*) (yysemantic_stack_[(16) - (11)].variable)->Pointer())->get(),
          (float) (yysemantic_stack_[(16) - (13)].adouble),
          (float) (yysemantic_stack_[(16) - (15)].adouble),
          2, // pairs mode MEAN
          100, // keeps all points
          CIRCLE_RESPONSE_MEAN);

        Si res==NULL Alors
          driver.err_print("CircleIntSdExc() error ... \n");
          res=((InrImage::ptr*) (yysemantic_stack_[(16) - (3)].variable)->Pointer())->get();
        FinSi

        driver.im_stack.AddImage(res);
      }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 8235 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage*  res;

      res = Func_CircleIntSdExc(
        ((InrImage::ptr*) (yysemantic_stack_[(20) - (3)].variable) ->Pointer())->get(),  // gradient
        ((InrImage::ptr*) (yysemantic_stack_[(20) - (5)].variable) ->Pointer())->get(),  // first  vector
        ((InrImage::ptr*) (yysemantic_stack_[(20) - (7)].variable) ->Pointer())->get(),  // second vector
        (float)     (yysemantic_stack_[(20) - (9)].adouble),              // radius
        ((InrImage::ptr*) (yysemantic_stack_[(20) - (11)].variable)->Pointer())->get(),
        (float) (yysemantic_stack_[(20) - (13)].adouble),
        (float) (yysemantic_stack_[(20) - (15)].adouble),
        (int) (yysemantic_stack_[(20) - (17)].adouble),
        (int) (yysemantic_stack_[(20) - (19)].adouble),
        CIRCLE_RESPONSE_MEAN);

      Si res==NULL Alors
        driver.err_print("CircleIntSdExc() error ... \n");
        res=((InrImage::ptr*) (yysemantic_stack_[(20) - (3)].variable)->Pointer())->get();
      FinSi

      driver.im_stack.AddImage(res);
      }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 8280 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_LocalExtrema( ((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),  // input image
                 ((InrImage::ptr*) (yysemantic_stack_[(10) - (5)].variable)->Pointer())->get(),  // first  vector
                 ((InrImage::ptr*) (yysemantic_stack_[(10) - (7)].variable)->Pointer())->get(),  // second vector
                 ((InrImage::ptr*) (yysemantic_stack_[(10) - (9)].variable)->Pointer())->get()); // mask

    Si res==NULL Alors
      driver.err_print("LocalExtrema() error ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 8297 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;
    int samples = (int) (yysemantic_stack_[(12) - (11)].adouble);

    res = Func_LocalExtrema( ((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get(),  // input image
                 ((InrImage::ptr*) (yysemantic_stack_[(12) - (5)].variable)->Pointer())->get(),  // first  vector
                 ((InrImage::ptr*) (yysemantic_stack_[(12) - (7)].variable)->Pointer())->get(),  // second vector
                 ((InrImage::ptr*) (yysemantic_stack_[(12) - (9)].variable)->Pointer())->get(),  // mask
                 samples);                   // number of sample points around the circle

    Si res==NULL Alors
      driver.err_print("LocalExtrema() error ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 8316 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_NormalSmoothField( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get() );

    Si res==NULL Alors
      driver.err_print("NormalField() error ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 8330 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_NormalSmoothField( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get() , ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

    Si res==NULL Alors
      driver.err_print("NormalField() error ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 8344 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_DirConnectivity( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get() , ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

    Si res==NULL Alors
      driver.err_print("DirConnectivity() error ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 8360 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;
    InrImage*    input  = (InrImage*) driver.im_stack.GetLastImage();

    res = Func_NormGrad( input, (yysemantic_stack_[(6) - (5)].adouble));

    Si res==NULL Alors
      driver.err_print("Filter() error ... \n");
      res=input;
    Sinon
      delete input;
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 8378 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_DiscNormGrad( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());

    Si res==NULL Alors
      driver.err_print("discnormgrad() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 8393 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_DiscMeanCurvature( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());

    Si res==NULL Alors
      driver.err_print("DiscMeanCurvature() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 8409 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_Gradient( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(6) - (5)].adouble));

    Si res==NULL Alors
      driver.err_print("Filter() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 8424 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
        Parameters:
            (3) input image.

        Description:
        Computes a discrete laplacian (sum of second order derivatives),
        in 2D or 3D depending on the image dimension.
    **/
    InrImage*  res;

    res = Func_Laplacian(((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());
    Si res==NULL Alors
      driver.err_print("Filter() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
        }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 8447 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_SecDerGrad( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(6) - (5)].adouble));

    Si res==NULL Alors
      fprintf(stderr,"SecDerGrad() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 8464 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_SecDerGrad2( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(6) - (5)].adouble));

    Si res==NULL Alors
      fprintf(stderr,"SecDerGrad2() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
    }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 8478 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

          InrImage* res;
          InrImage* im = (InrImage*) driver.im_stack.GetLastImage();

        res = Func_AutoCrop(im,(int)(yysemantic_stack_[(6) - (5)].adouble));

        driver.im_stack.AddImage(res);
        delete im;
    }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 8490 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;
      ImageExtent<float>* extent = (ImageExtent<float>*) (yysemantic_stack_[(4) - (3)].imageextent);
  
      //extent->print();
      extent->SetRelative(((InrImage::ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())->get());
  
      //extent->print();
      //cout << "xmax = " << (int)  extent->Xmax() << endl;
      //cout << "xmax = " << (int)  round((double)extent->Xmax()) << endl;
      res = Func_SubImage( ((InrImage::ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())->get(),
                  (int)  round((double)extent->Xmin()),
                  (int)  round((double)extent->Ymin()),
                  (int)  round((double)extent->Zmin()),
                  (int)  round((double)extent->Xmax()),
                  (int)  round((double)extent->Ymax()),
                  (int)  round((double)extent->Zmax())
                  );
      delete extent;
  
      Si res==NULL Alors
        fprintf(stderr,"SubImage() erreur ... \n");
        res= ((InrImage::ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())->get();
      FinSi
  
      driver.im_stack.AddImage(res);
    }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 8522 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr  im = *(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer();
      InrImage*  res;
  
      res = Func_SubImage( im.get(),
                  0, 0,  (int) round((yysemantic_stack_[(10) - (7)].adouble)),
                  im->DimX()-1,  im->DimY()-1, (int) round((yysemantic_stack_[(10) - (9)].adouble)));
  
      Si res==NULL Alors
        fprintf(stderr,"SubImage() erreur ... \n");
        res=((InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->get();
      FinSi
  
      driver.im_stack.AddImage(res);
      }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 8542 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    InrImage*  res;

    res = Func_SubImage( ((InrImage::ptr*) (yysemantic_stack_[(16) - (3)].variable)->Pointer())->get(),
                 (int) (yysemantic_stack_[(16) - (5)].adouble), (int) (yysemantic_stack_[(16) - (7)].adouble), (int) (yysemantic_stack_[(16) - (9)].adouble),
                 (int) (yysemantic_stack_[(16) - (11)].adouble),(int) (yysemantic_stack_[(16) - (13)].adouble),(int) (yysemantic_stack_[(16) - (15)].adouble));

    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(16) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 8584 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;
    res = Func_EDP_dilate( ((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),
                   (yysemantic_stack_[(10) - (5)].adouble),  (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble));
    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get();
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 8596 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;
    res = Func_EDP_dilate( ((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble));
    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get();
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 8607 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;
    float Imin = (yysemantic_stack_[(12) - (9)].adouble);
    float Imax = (yysemantic_stack_[(12) - (11)].adouble);
    res = Func_EDP_dilate( ((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(12) - (5)].adouble),  (yysemantic_stack_[(12) - (7)].adouble), Imin, Imax);
    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get();
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 8620 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;
    res = Func_EDP_erode( ((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),
                  (yysemantic_stack_[(10) - (5)].adouble),  (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble));
    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get();
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 8632 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;
    res = Func_EDP_erode( ((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble));
    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get();
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 8643 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    InrImage*  res;
    float Imin = (yysemantic_stack_[(12) - (9)].adouble);
    float Imax = (yysemantic_stack_[(12) - (11)].adouble);
    res = Func_EDP_erode( ((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(12) - (5)].adouble),  (yysemantic_stack_[(12) - (7)].adouble), Imin, Imax);
    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get();
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 8671 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    InrImage*  res;

    res = Func_EDP_open( ((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                    (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble));

    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 8698 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    InrImage*  res;
    float Imin = (yysemantic_stack_[(12) - (9)].adouble);
    float Imax = (yysemantic_stack_[(12) - (11)].adouble);

    res = Func_EDP_open( ((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get(),
                    (yysemantic_stack_[(12) - (5)].adouble),  (yysemantic_stack_[(12) - (7)].adouble), Imin, Imax);

    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 8730 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_EDP_close( ((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                   (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble));

    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 8746 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;
    float Imin = (yysemantic_stack_[(12) - (9)].adouble);
    float Imax = (yysemantic_stack_[(12) - (11)].adouble);

    res = Func_EDP_close( ((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get(),
                   (yysemantic_stack_[(12) - (5)].adouble),  (yysemantic_stack_[(12) - (7)].adouble), Imin, Imax);

    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 8763 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_AnisoGS_GetOutput();

    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 8776 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_AnisoGS_GetDiffusionCoeff();

    Si res==NULL Alors
      fprintf(stderr,"GetDiffCoeff() erreur ... \n");
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 8789 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    //
    // Parameters:
    // 1. input image
    // 2. isosurface threshold on the input image

    InrImage*  res;

    res = Func_LevelSets_Init( ((InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get(),
                   (yysemantic_stack_[(8) - (7)].adouble));

    Si res==NULL Alors
      fprintf(stderr,"Func_LevelSets_Init() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 8809 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    //
    // Parameters:
    // 1. input image
    // 2. Initial position of the level set a the zero-crossing of
    //    this image

    InrImage*  res;

    res = Func_LevelSets_Init(
           ((InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get(),
           ((InrImage::ptr*) (yysemantic_stack_[(8) - (7)].variable)->Pointer())->get()
                   );

    Si res==NULL Alors
      fprintf(stderr,"Func_LevelSets_Init() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
    }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 8832 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

    InrImage*  res;

    res = Func_LevelSets_GetCurrentOutput();

    Si res==NULL Alors
      fprintf(stderr,"Func_LevelSets_GetOutput() error ... \n");
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 8846 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

    InrImage*  res;

    res = Func_LevelSets_GetAttachVectors( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());

    Si res==NULL Alors
      fprintf(stderr,"Func_GetAttachVect() erreur ... \n");
      res=((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 8863 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Parameters:
        (1) input image
        (2) sigma: standard deviation of the Gaussian smoothing applied to compute the local structure orientations.
        (3) k: diffusion parameter that controls the diffusion depending on the local gradients.
        (4) beta: data attachment coefficient.
        (5) number of iterations
      Description:
        Runs an anisotropic diffusion filter using Gauss-Seidel numerical scheme, based on the Flux-diffusion algorithm [Krissian,IEEE TMI 2002].
      **/
      int        nb_iter,i;
      float       error;

      Func_InitAnisoGS( ((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get(),
                  (yysemantic_stack_[(12) - (5)].adouble),  (yysemantic_stack_[(12) - (7)].adouble), (yysemantic_stack_[(12) - (9)].adouble));

          nb_iter = (int) (yysemantic_stack_[(12) - (11)].adouble);
      if (nb_iter < 1) nb_iter = 1;

      Pour(i,1,nb_iter)
        error = Func_ItereAnisoGS();
      FinPour

      driver.im_stack.AddImage(Func_AnisoGS_GetOutput());

      Func_EndAnisoGS();


    }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 8896 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      //
      // param 1: input image
      // 2: vector field
      // 3: data attachment coeff
      // 4: diffusion coeff
      // 5: number of iterations
      //
      InrImage*  res;
      int        nb_iter,i;
      float       error;

      Func_InitAnisoGS( ((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get(),
                  1,  1, (yysemantic_stack_[(12) - (7)].adouble));


          nb_iter = (int) (yysemantic_stack_[(12) - (11)].adouble);
      if (nb_iter < 1) nb_iter = 1;

      Pour(i,1,nb_iter)
        error = Func_ItereFlux(((InrImage::ptr*) (yysemantic_stack_[(12) - (5)].variable)->Pointer())->get(),(yysemantic_stack_[(12) - (9)].adouble));
      FinPour

          res = Func_AnisoGS_GetOutput();
      Si res==NULL Alors
        fprintf(stderr,"AnisoGS() erreur ... \n");
        res=((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get();
      FinSi

      Func_EndAnisoGS();

      driver.im_stack.AddImage(res);

    }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 8934 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr  in      = *(InrImage::ptr*) (yysemantic_stack_[(14) - (3)].variable)->Pointer();
      float      sigma   = (yysemantic_stack_[(14) - (5)].adouble);
      float      k       = (yysemantic_stack_[(14) - (7)].adouble);
      float      beta    = (yysemantic_stack_[(14) - (9)].adouble);
      int        nb_iter    = (int) (yysemantic_stack_[(14) - (11)].adouble);
      int        nb_threads = (int) (yysemantic_stack_[(14) - (13)].adouble);

          InrImage*  res = Func_vtkAnisoGS(  in.get(), sigma, k, beta, nb_iter, nb_threads);

      Si res==NULL Alors
        fprintf(stderr,"Func_vtkAnisoGS() erreur ... \n");
      FinSi

          //      printf("5 \n");
      driver.im_stack.AddImage(res);

    }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 8969 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;
      int        nb_iter,i;
      float       error;

      Func_InitAnisoGS( ((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get(),
                  (yysemantic_stack_[(12) - (5)].adouble),  (yysemantic_stack_[(12) - (7)].adouble), (yysemantic_stack_[(12) - (9)].adouble));


          Func_SetSmoothedParam(1);

          nb_iter = (int) (yysemantic_stack_[(12) - (11)].adouble);
      if (nb_iter < 1) nb_iter = 1;

      Pour(i,1,nb_iter)
        error = Func_ItereAnisoGS();
      FinPour

          res = Func_AnisoGS_GetOutput();
      Si res==NULL Alors
        fprintf(stderr,"AnisoGS() erreur ... \n");
        res=((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get();
      FinSi

      Func_EndAnisoGS();

      driver.im_stack.AddImage(res);

    }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 9002 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;

      res = Func_InitWeickert( ((InrImage::ptr*) (yysemantic_stack_[(12) - (5)].variable)->Pointer())->get(),
                (yysemantic_stack_[(12) - (7)].adouble),  (yysemantic_stack_[(12) - (9)].adouble), (yysemantic_stack_[(12) - (11)].adouble));

      Si res==NULL Alors
        fprintf(stderr,"Func_InitWeickert() erreur ... \n");
        res=((InrImage::ptr*) (yysemantic_stack_[(12) - (5)].variable)->Pointer())->get();
      FinSi

      driver.im_stack.AddImage(res);
        }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 9019 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;

      res = Func_InitWeickertCoherence( ((InrImage::ptr*) (yysemantic_stack_[(16) - (5)].variable)->Pointer())->get(),
                (yysemantic_stack_[(16) - (7)].adouble),  (yysemantic_stack_[(16) - (9)].adouble), (yysemantic_stack_[(16) - (11)].adouble), (yysemantic_stack_[(16) - (13)].adouble), (yysemantic_stack_[(16) - (15)].adouble));

      Si res==NULL Alors
        fprintf(stderr,"Func_InitWeickert() erreur ... \n");
        res=((InrImage::ptr*) (yysemantic_stack_[(16) - (5)].variable)->Pointer())->get();
      FinSi

      driver.im_stack.AddImage(res);
        }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 9034 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;

      res = Func_SRAD_qcoeff( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());

      Si res==NULL Alors
        fprintf(stderr,"Func_SRAD_qcoeff() erreur ... \n");
        res=((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get();
      FinSi

      driver.im_stack.AddImage(res);
        }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 9050 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;
      float dt = (float) (yysemantic_stack_[(8) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(8) - (7)].adouble);

      res = Func_SRAD( ((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),dt,numit,
               0, // Lee mode
               0,  // Yu neighborhood
               NULL); // no extent

      Si res==NULL Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
        res=((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get();
      FinSi

      driver.im_stack.AddImage(res);
        }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 9070 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;
      float dt = (float) (yysemantic_stack_[(10) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(10) - (7)].adouble);
      ImageExtent<float>* extent = (ImageExtent<float>*) (yysemantic_stack_[(10) - (9)].imageextent);

      res = Func_SRAD( ((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),dt,numit,
               0, // Lee mode
               0, // Yu neighborhood
               extent);

      delete extent;

      Si res==NULL Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
        res=((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get();
      FinSi

      driver.im_stack.AddImage(res);
        }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 9093 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;
      float dt = (float) (yysemantic_stack_[(12) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(12) - (7)].adouble);
      int neighborhood = (int) (yysemantic_stack_[(12) - (9)].adouble);
      ImageExtent<float>* extent = (ImageExtent<float>*) (yysemantic_stack_[(12) - (11)].imageextent);

      res = Func_SRAD( ((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get(),dt,numit,
               0, // Lee mode
               neighborhood,
               extent);

      delete extent;

      Si res==NULL Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
        res=((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get();
      FinSi

      driver.im_stack.AddImage(res);
        }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 9117 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;
      float dt = (float) (yysemantic_stack_[(10) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(10) - (7)].adouble);
      ImageExtent<float>* extent = (ImageExtent<float>*) (yysemantic_stack_[(10) - (9)].imageextent);


      res = Func_SRAD2( ((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),dt,numit,
                0, // Lee function
                0, // Yu neighborhood
                extent
                );

      delete extent;

      Si res==NULL Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
        res=((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get();
      FinSi

      driver.im_stack.AddImage(res);
        }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 9143 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;
      float dt = (float) (yysemantic_stack_[(12) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(12) - (7)].adouble);
      int neighborhood = (int) (yysemantic_stack_[(12) - (9)].adouble);
      ImageExtent<float>* extent = (ImageExtent<float>*) (yysemantic_stack_[(12) - (11)].imageextent);

      res = Func_SRAD2( ((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get(),dt,numit,
                0, // Lee function
                neighborhood, // neighborhood size
                extent // bounding box
                );
      delete extent;

      Si res==NULL Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
        res=((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get();
      FinSi

      driver.im_stack.AddImage(res);
        }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 9166 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;
      float dt = (float) (yysemantic_stack_[(10) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(10) - (7)].adouble);
      ImageExtent<float>* extent = (ImageExtent<float>*) (yysemantic_stack_[(10) - (9)].imageextent);

      res = Func_SRAD2( ((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),dt,numit,
                2, // Additive mode
                0, // Yu neighborhood
                extent // constant region
                );
      delete extent;

      Si res==NULL Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
        res=((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get();
      FinSi

      driver.im_stack.AddImage(res);
        }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 9188 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;
      float dt         = (float) (yysemantic_stack_[(12) - (5)].adouble);
      int numit        = (int) (yysemantic_stack_[(12) - (7)].adouble);
      int neighborhood = (int) (yysemantic_stack_[(12) - (9)].adouble);
      ImageExtent<float>* extent = (ImageExtent<float>*) (yysemantic_stack_[(12) - (11)].imageextent);

      res = Func_SRAD( ((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get(),dt,numit,
               1, // Kuan's function
               neighborhood, // Yu neighborhood
               extent);
      delete extent;

      Si res==NULL Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
        res=((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get();
      FinSi

      driver.im_stack.AddImage(res);
    }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 9211 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;
      float dt = (float) (yysemantic_stack_[(12) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(12) - (7)].adouble);
      int neighborhood = (int) (yysemantic_stack_[(12) - (9)].adouble);
      ImageExtent<float>* extent = (ImageExtent<float>*) (yysemantic_stack_[(12) - (11)].imageextent);

      res = Func_SRAD2( ((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get(),dt,numit,
                1, // Kuan's function
                neighborhood, // Yu neighborhood
                extent
                );
      delete extent;

      Si res==NULL Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
        res=((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get();
      FinSi

      driver.im_stack.AddImage(res);
    }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 9235 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
            InrImage*  res;
            int mode = (int) (yysemantic_stack_[(14) - (5)].adouble);
            float dt = (float) (yysemantic_stack_[(14) - (7)].adouble);
            int numit = (int) (yysemantic_stack_[(14) - (9)].adouble);
            int neighborhood = (int) (yysemantic_stack_[(14) - (11)].adouble);
            ImageExtent<float>* extent = (ImageExtent<float>*) (yysemantic_stack_[(14) - (13)].imageextent);

            res = Func_SRAD2( ((InrImage::ptr*) (yysemantic_stack_[(14) - (3)].variable)->Pointer())->get(),dt,numit,
                        mode, // fiter mode
                        neighborhood, //  neighborhood size
                        extent
                        );
            delete extent;

            Si res==NULL Alors
                fprintf(stderr,"Func_AnisoNRAD() erreur ... \n");
                res=((InrImage::ptr*) (yysemantic_stack_[(14) - (3)].variable)->Pointer())->get();
            FinSi

            driver.im_stack.AddImage(res);
    }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 9279 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr  initim = *(InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer();
      InrImage*  res;
      float dt = (float) (yysemantic_stack_[(12) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(12) - (7)].adouble);
      int attach = (int) (yysemantic_stack_[(12) - (9)].adouble);
      int scheme = (int) (yysemantic_stack_[(12) - (11)].adouble);

      if (initim->DimZ()==1)
        res = Func_RudinMultiplicative2D( initim.get(),dt,numit,attach, scheme);
      else
        res = Func_RudinMultiplicative3D( initim.get(),dt,numit,attach, scheme);

      Si res==NULL Alors
        fprintf(stderr,"Func_AnisoRudinMult() erreur ... \n");
        res=((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get();
      FinSi

      driver.im_stack.AddImage(res);
    }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 9303 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description:
          Add Gaussian noise with specified mean and variance.
      **/

        AjouteBruit* addnoise;
        InrImage*    res;
        InrImage::ptr    in = *(InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer();
        float mean;
        float sd;
        char  resname[256];

      mean = (yysemantic_stack_[(8) - (5)].adouble);
      sd   = (yysemantic_stack_[(8) - (7)].adouble);

      sprintf(resname,"%s.noise",in->Nom());
      res = new InrImage(WT_FLOAT, resname, in.get());

      (*res)=(*in);

      addnoise = new AjouteBruit();
      addnoise->AjouteBruitGaussien(res,mean,sd);
      delete addnoise;

      driver.im_stack.AddImage(res);

    }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 9334 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

        InrImage*    res;

          res = Func_rot2D( ((InrImage::ptr*) (yysemantic_stack_[(14) - (3)].variable)->Pointer())->get(),
                (yysemantic_stack_[(14) - (5)].adouble), (yysemantic_stack_[(14) - (7)].adouble),   // rotation center
                (yysemantic_stack_[(14) - (9)].adouble),       // angle of rotation
                (yysemantic_stack_[(14) - (11)].adouble), (yysemantic_stack_[(14) - (13)].adouble)  // dimension of the new image
                );

      driver.im_stack.AddImage(res);
        }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 9356 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

          InrImage*    res;
          int x,y,z;

        res = new InrImage(WT_UNSIGNED_SHORT,1,
                   "tmp_X.inr.gz",
                   ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());
        res->InitBuffer();
        Pour(z,0,res->_tz-1)
        Pour(y,0,res->_ty-1)
        Pour(x,0,res->_tx-1)
          res->FixeValeur(x);
          res->IncBuffer();
            FinPour
            FinPour
            FinPour

        driver.im_stack.AddImage(res);
        }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 9393 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

          InrImage*    res;
          int x,y,z;

        res = new InrImage(WT_UNSIGNED_SHORT,1,
                   "tmp_X.inr.gz",
                   ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());
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

  case 652:

/* Line 678 of lalr1.cc  */
#line 9430 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

          InrImage*    res;
          int x,y,z;

        res = new InrImage(WT_UNSIGNED_SHORT,1,
                   "tmp_X.inr.gz",
                   ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());
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

  case 653:

/* Line 678 of lalr1.cc  */
#line 9467 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

          InrImage*    res;
          int x,y,z;

        res = new InrImage(WT_FLOAT,3,
                   "tmp_spacepos.inr.gz",
                   ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());
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

  case 654:

/* Line 678 of lalr1.cc  */
#line 9502 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          driver.im_stack.AddImage((*(Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetCanvas()->GetGLImage());
        }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 9507 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          fprintf(stderr,"not available in new wxwidgets version of the 3D viewer ! \n");
          driver.im_stack.AddImage((InrImage*)NULL);
/*
          driver.im_stack.AddImage((*(Viewer3D_ptr*) $1->Pointer())->GetInrImage());
*/
    }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 9516 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.im_stack.AddImage((*(DessinImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetInrImage());
    }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 9521 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

    InrImage*    res;

      res = Func_ThresholdCrossing( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

          driver.im_stack.AddImage(res);

    }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 9532 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*    res;

      res = Func_IsocontourPoints( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

      driver.im_stack.AddImage(res);

    }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 9542 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*    res;

      res = Func_IsosurfDist( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

          driver.im_stack.AddImage(res);

    }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 9552 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*    res;

      res = Func_vtkIsoContourDist( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

          driver.im_stack.AddImage(res);
    }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 9561 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3) input image
      (5) initialization image
      (7) maximal time
    Description:
      Runs the fast marching algorithm
     **/

        InrImage*    init = (InrImage*) driver.im_stack.GetLastImage(); // 2nd param
        InrImage*    input  = (InrImage*) driver.im_stack.GetLastImage(); // 1st param
        InrImage*    res = NULL;
            float   maxtime = (float) (yysemantic_stack_[(8) - (7)].adouble);

          res = Func_vtkFastMarching( input, init,  maxtime);

          driver.im_stack.AddImage(res);
    }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 9584 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      InrImage::ptr init  = InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
      InrImage::ptr input = InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
      InrImage*     res = NULL;
      float   maxtime = (float) (yysemantic_stack_[(14) - (7)].adouble);

      res = Func_vtkFastMarchingTarget( input.get(), init.get(),  maxtime,
              (int) round((yysemantic_stack_[(14) - (9)].adouble)),
              (int) round((yysemantic_stack_[(14) - (11)].adouble)),
              (int) round((yysemantic_stack_[(14) - (13)].adouble))
              );

      driver.im_stack.AddImage(res);
    }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 9613 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      InrImage::ptr init  = InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
      InrImage::ptr input = InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
      InrImage*    res = NULL;
      float   mean    = (float) (yysemantic_stack_[(12) - (7)].adouble);
      float   sd      = (float) (yysemantic_stack_[(12) - (9)].adouble);
      float   maxtime = (float) (yysemantic_stack_[(12) - (11)].adouble);

      res = Func_vtkFastMarching( input.get(), init.get(), mean, sd, maxtime);

      driver.im_stack.AddImage(res);
    }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 9639 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      InrImage::ptr init  = InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
      InrImage::ptr input = InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
      InrImage*    res = NULL;
      float   mean     = (float) (yysemantic_stack_[(14) - (7)].adouble);
      float   sd       = (float) (yysemantic_stack_[(14) - (9)].adouble);
      float   maxtime  = (float) (yysemantic_stack_[(14) - (11)].adouble);
      int     inittype = (int) (yysemantic_stack_[(14) - (13)].adouble);

      res = Func_vtkFastMarching( input.get(), init.get(), mean, sd, maxtime,inittype);

      driver.im_stack.AddImage(res);
    }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 9670 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      InrImage::ptr init  = InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
      InrImage::ptr input = InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
      InrImage*    res   = NULL;
      float   maxtime    = (float) (yysemantic_stack_[(12) - (9)].adouble);
      int     inittype   = (int)   (yysemantic_stack_[(12) - (11)].adouble);

      res = Func_vtkFastMarching(
                  input.get(),
                  init.get(),
                  ((InrImage::ptr*) (yysemantic_stack_[(12) - (7)].variable)->Pointer())->get(),
                  maxtime,inittype);

      driver.im_stack.AddImage(res);
    }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 9700 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      InrImage* res;
      res = Func_Convolve(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                  ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());

          driver.im_stack.AddImage(res);

        }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 9711 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();
;

      res = Func_ConvolveMask(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                  ((InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get(),
                  mask);

          driver.im_stack.AddImage(res);
      delete mask;

        }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 9727 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
      res = Func_Chamfer(((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));

          driver.im_stack.AddImage(res);

        }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 9737 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
      res = Func_Chamfer2(((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));

          driver.im_stack.AddImage(res);

        }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 9747 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float a = (yysemantic_stack_[(12) - (5)].adouble);
        float b = (yysemantic_stack_[(12) - (7)].adouble);
        float c = (yysemantic_stack_[(12) - (9)].adouble);
        float dmax = (yysemantic_stack_[(12) - (11)].adouble);

          res = Func_Chamfer2(((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get(), a,b,c,dmax);

          driver.im_stack.AddImage(res);

        }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 9762 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_Chamfer2(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                  0.92644, 1.34065, 1.65849,
                  dmax);

          driver.im_stack.AddImage(res);

        }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 9776 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_Chamfer2Signed(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                    0.92644, 1.34065, 1.65849,
                    dmax);

          driver.im_stack.AddImage(res);

        }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 9790 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_vtkSignedBorgefors(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                    dmax);

          driver.im_stack.AddImage(res);

        }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 9803 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_vtkSignedFMDist(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                     dmax);

          driver.im_stack.AddImage(res);

        }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 9816 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_PropagationDistance(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                      dmax);

          driver.im_stack.AddImage(res);
        }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 9828 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_PropagationDistance2(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                      dmax);

          driver.im_stack.AddImage(res);
        }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 9840 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_PropagationDanielsson(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                       dmax);

          driver.im_stack.AddImage(res);
        }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 9852 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_vtkPropDanielsson(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                       -dmax,dmax);
          driver.im_stack.AddImage(res);
        }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 9863 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmin = (yysemantic_stack_[(8) - (5)].adouble);
        float dmax = (yysemantic_stack_[(8) - (7)].adouble);

      res = Func_vtkPropDanielsson(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                       dmin,dmax);

          driver.im_stack.AddImage(res);
        }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 9876 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
            InrImage* res;
        float threshold = (yysemantic_stack_[(10) - (5)].adouble);
        float dmin      = (yysemantic_stack_[(10) - (7)].adouble);
        float dmax      = (yysemantic_stack_[(10) - (9)].adouble);

        printf("threshold = %f \n",threshold);
      res = Func_vtkPropDaniel2(((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),
                    threshold,dmin,dmax);

          driver.im_stack.AddImage(res);
        }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 9903 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
       InrImage* im = (InrImage*) driver.im_stack.GetLastImage();
           InrImage* res;

      res = Func_CC(im);

          driver.im_stack.AddImage(res);
      delete im;
        }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 9936 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     /**
       Parameters:
         (1) image1: image variable
         (3) image2: image expression

       Description:
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
      // image composition
      // Initialy for applying a RGB colormap to an image
      InrImage::ptr im1;
      InrImage* im2 = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;
      int pos;

      im1 = *(InrImage::ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer();

      res = new InrImage(
                          im1->_format,
                          im1->GetVDim(),
                          "ImComp.ami.gz",
                          im2);
 
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

          driver.im_stack.AddImage(res);
      delete im2;
        }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 10052 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage* im = (InrImage*) driver.im_stack.GetLastImage();
      float vmin  = (yysemantic_stack_[(10) - (5)].adouble);
      float vmax  = (yysemantic_stack_[(10) - (7)].adouble);
      int   nint = (int) (yysemantic_stack_[(10) - (9)].adouble); // number of intervals

      InrImage* res;

      res = Func_Histogram(im,vmin,vmax,nint);
      driver.im_stack.AddImage(res);
      delete im;
    }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 10076 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im = (InrImage*) driver.im_stack.GetLastImage();
      float vmin  = (yysemantic_stack_[(10) - (5)].adouble);
      float vmax  = (yysemantic_stack_[(10) - (7)].adouble);
      int   nint = (int) (yysemantic_stack_[(10) - (9)].adouble); // number of intervals

      int* numpts;
      int  n;
      InrImage* res;
      float v;
      double total = 0;

      res = new InrImage(nint,1,1,WT_SIGNED_INT);

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
      delete im;
    }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 10118 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* res;
      InrImage::ptr im = InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());

      if (im->DimZ()>1)
        res = Func_MeanHalfSize(im.get(),3);
      else
        res = Func_MeanHalfSize(im.get(),2);

      if (res!=NULL) driver.im_stack.AddImage(res);
    }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 10130 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* res;
      int dim = (int) (yysemantic_stack_[(6) - (5)].adouble);

      InrImage::ptr im = InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
      res = Func_MeanHalfSize(im.get(),dim);
      if (res!=NULL) driver.im_stack.AddImage(res);
    }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 10139 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage* res;
        int axis=(int) (yysemantic_stack_[(6) - (5)].adouble);

        InrImage::ptr im = InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
        res=Func_Flip(im,axis);
        driver.im_stack.AddImage(res);
    }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 10148 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
            InrImage* res;
            int sx = (int) (yysemantic_stack_[(12) - (5)].adouble);
            int sy = (int) (yysemantic_stack_[(12) - (7)].adouble);
            int sz = (int) (yysemantic_stack_[(12) - (9)].adouble);
            unsigned char interpolate=(unsigned char) (yysemantic_stack_[(12) - (11)].adouble);

            InrImage::ptr im = InrImage::ptr(driver.im_stack.GetLastImage());
            res = Func_Resize(im.get(),sx,sy,sz,interpolate);

            if (res!=NULL) driver.im_stack.AddImage(res);
        }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 10171 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* res;
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

      InrImage::ptr im1 = *(InrImage::ptr*) (yysemantic_stack_[(30) - (3)].variable)->Pointer();
      InrImage::ptr im2 = *(InrImage::ptr*) (yysemantic_stack_[(30) - (5)].variable)->Pointer();

      res = Func_ReSlice(im1.get(),im2.get(),m);

      if (res!=NULL) driver.im_stack.AddImage(res);

    }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 10196 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      int   order = (int) (yysemantic_stack_[(8) - (5)].adouble);
      float resolution = (yysemantic_stack_[(8) - (7)].adouble);
      InrImage* input=(InrImage*) driver.im_stack.GetLastImage();

      res = Func_vtkConvexHull(input,
                   order,resolution);

      if (res!=NULL) driver.im_stack.AddImage(res);
      delete input;
    }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 10209 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(5) - (1)].variable)->Pointer());


      res = s->GetImageLinesLength(  );

      if (res!=NULL) driver.im_stack.AddImage(res);
    }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 10219 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Parameters:
          - input polydata
          - line number
        Description:
          Get the points of the given line as a vectorial 1D image of 
          the point positions.
      **/
      InrImage*         res = NULL;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      int linenumber = (int) (yysemantic_stack_[(6) - (5)].adouble);
      
      if ((linenumber>=0)&&(linenumber<s->GetNumberOfLines())) {
        T_Line line=s->GetLine(linenumber);
        if (line.NbElts()>0) {
          // Create the image
          res = new InrImage(line.NbElts(),1,1,3,WT_FLOAT,
            (boost::format("%1%_line%2%") 
              % (yysemantic_stack_[(6) - (1)].variable)->Name()
              % linenumber
            ).str().c_str());
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

  case 693:

/* Line 678 of lalr1.cc  */
#line 10256 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        - input polydata containing lines
      Description:
        Returns an image Mx2 where M is the number of lines and 
        containing the point id of the 2 extremities of each 
        line
    **/
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(5) - (1)].variable)->Pointer());


      res = s->GetImageLinesExtremities(  );

      if (res!=NULL) driver.im_stack.AddImage(res);
    }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 10274 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        - input polydata containing lines
      Description:
        Get the number of lines connected to each point.
        The result is given as a 1D image of size the total
        number of points of the polydata
    **/
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(5) - (1)].variable)->Pointer());


      res = s->GetImageConnections(  );

      if (res!=NULL) driver.im_stack.AddImage(res);
        }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 10292 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());


      res = s->GetIntensities( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

      if (res!=NULL) driver.im_stack.AddImage(res);
        }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 10302 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;

      res = AMIFluid::Func_Altitude2Position(im,(int)(yysemantic_stack_[(6) - (5)].adouble));
      if (res!=NULL) driver.im_stack.AddImage(res);

      delete im;
    }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 10312 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_Altitude2Position(im);
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
    }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 10320 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im,(int)(yysemantic_stack_[(6) - (5)].adouble));
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
    }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 10328 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im);
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
    }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 10336 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr coeff = InrImage::ptr(driver.im_stack.GetLastImage());
      InrImage::ptr input = InrImage::ptr(driver.im_stack.GetLastImage());
      InrImage* res;

      res = AMIFluid::Func_ComputeAltitudes(input.get(),coeff.get());
      if (res!=NULL) driver.im_stack.AddImage(res);

    }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 10361 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**

        Description:
        Compute the altitude to the sea level based on the
        temperature channel.

        Parameters:
        (3) image containing the temperature at the top of the clouds
        in Kelvin.

        **/
      InrImage::ptr input = InrImage::ptr(driver.im_stack.GetLastImage());
      InrImage* res;

      res = AMIFluid::Func_Temp2Altitudes(input.get());
      if (res!=NULL) driver.im_stack.AddImage(res);

    }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 10381 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* res;
      res= AMIFluid::Func_ReadFlow((char*)(yysemantic_stack_[(4) - (3)].astring));
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 10389 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        InrImage::ptr im = InrImage::ptr(driver.im_stack.GetLastImage());
        InrImage* res;

        if (im->_format==WT_UNSIGNED_CHAR) {
          ImageDraw<unsigned char> imdraw;
          imdraw.SetInput((unsigned char*)im->GetData(),im->DimX(),im->DimY(),im->DimZ());
          imdraw.SetVoxelSize(im->VoxSizeX(),im->VoxSizeY(),im->VoxSizeZ());
          imdraw.SetCursorPosition((int)(yysemantic_stack_[(18) - (9)].adouble),(int)(yysemantic_stack_[(18) - (11)].adouble),(int)(yysemantic_stack_[(18) - (13)].adouble));
          imdraw.Apply((int)(yysemantic_stack_[(18) - (5)].adouble),(int)(yysemantic_stack_[(18) - (7)].adouble),(int)(yysemantic_stack_[(18) - (15)].adouble),(int)(yysemantic_stack_[(18) - (17)].adouble));
          // copy to RGB image
          res = new InrImage(imdraw.RGB_width, imdraw.RGB_height, 1, WT_RGB);
          memcpy(res->GetData(),imdraw.RGB_image,imdraw.RGB_width*imdraw.RGB_height*3);
          driver.im_stack.AddImage(res);
        } else
          fprintf(stderr,"only UCHAR format for now \n");
        }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 10423 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage*         res;

      SurfacePoly::ptr  surf = *(SurfacePoly::ptr*)
                                  (yysemantic_stack_[(8) - (3)].variable)->Pointer();
      InrImage::ptr ref = *(InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer();
      InrImage::ptr rad = InrImage::ptr(
                                driver.im_stack.GetLastImage());

      res = LineRecons( surf.get(), ref.get(), rad.get());
      driver.im_stack.AddImage(res);
    }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 10446 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3) input line read with ReadCTALine
      (5) name of the file
    Description:
      Reads the radius information and save it to an image,
      returns this image.
    **/
      InrImage*         res;

      SurfacePoly::ptr  surf = *(SurfacePoly::ptr*)
                                  (yysemantic_stack_[(6) - (3)].variable)->Pointer();

      res = Func_ReadCTALineRadii( surf.get(), (yysemantic_stack_[(6) - (5)].astring));
      driver.im_stack.AddImage(res);
    }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 10471 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(-)               }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 10473 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sin)             }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 10474 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(cos)             }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 10475 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sqrt)            }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 10476 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(fabs)            }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 10477 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(round)           }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 10478 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(floor)           }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 10479 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(tan)             }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 10480 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(asin)            }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 10481 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(acos)            }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 10482 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(atan)            }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 10483 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(exp)             }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 10484 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(1.0/log(10.0)*log) }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 10485 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(log)             }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 10487 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage* res;

          InrImage::ptr im1 = InrImage::ptr(driver.im_stack.GetLastImage());
          res = Norm(*im1);
          if (res!=NULL)
            driver.im_stack.AddImage(res);
          else
            fprintf(stderr,"Error computing the norm |image| \n");
        }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 10502 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
                  The image conversion is done using the cast operator
                  where basic_type can be one of the basic type accepted,
                  currently:
                  CHAR UCHAR SHORT USHORT FLOAT DOUBLE RGB FLOAT_VECTOR


                Example(s):
                  i = Image(FLOAT,10,10,10)
                  j = (RGB) i
        **/
            InrImage* im;
            InrImage::ptr im1 = InrImage::ptr(driver.im_stack.GetLastImage());
            im  = new InrImage( (WORDTYPE) (yysemantic_stack_[(4) - (2)].aint), "tmp.inr.gz", im1.get());
            (*im) = (*im1);
            driver.im_stack.AddImage(im);
          }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 10524 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(*,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 10530 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(/,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 10532 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  IMAGE_OP_IMAGE_2(*)   }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 10533 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(/)   }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 10534 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(^)   }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 10543 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(+,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 10544 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(-,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 10545 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(+)   }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 10546 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(-)   }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 10554 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<)    }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 10555 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>)    }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 10556 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<=)   }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 10557 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>=)   }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 10558 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<, (yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 10559 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>, (yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 10560 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<=,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 10561 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>=,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 10566 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(==)   }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 10567 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(!=)   }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 10568 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(==,(yysemantic_stack_[(3) - (3)].adouble))   }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 10569 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(!=,(yysemantic_stack_[(3) - (3)].adouble))   }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 10611 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         GLTransfMatrix* newglt;
         GLTransfMatrix_ptr glt = *(GLTransfMatrix_ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

         newglt = new GLTransfMatrix();
         (*newglt) = (*glt);
         driver.gltransf_stack.AddMatrix(newglt);

           }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 10622 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         GLTransfMatrix glt;
         GLTransfMatrix* newglt;

         printf("GetTransform begin \n");
         newglt = new GLTransfMatrix();
             glt = (*(Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetCanvas()->GetObjectTransform();
         (*newglt) = (glt);
         driver.gltransf_stack.AddMatrix(newglt);
         printf("GetTransform \n");
           }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 10635 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         GLTransfMatrix* newglt = NULL;
         GLTransfMatrix_ptr glt1 = *(GLTransfMatrix_ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer();
         GLTransfMatrix_ptr glt2 = *(GLTransfMatrix_ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer();
         float coeff = (yysemantic_stack_[(8) - (7)].adouble);

         newglt = Func_InterpolateTransform(glt1.get(),glt2.get(),coeff);
         driver.gltransf_stack.AddMatrix(newglt);
       }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 10646 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         GLTransfMatrix* newglt;
         newglt = Func_ReadTransform((yysemantic_stack_[(4) - (3)].astring));
         if (newglt!=NULL)
           driver.gltransf_stack.AddMatrix(newglt);
         else {
           fprintf(stderr,"TRANSFORM() Error reading file ...\n");
           driver.err_print("TRANSFORM() Error reading file ...\n");
           driver.gltransf_stack.AddMatrix(NULL);
           //          yyiperror(
           //          YYABORT;
         }
         delete [] (yysemantic_stack_[(4) - (3)].astring);
           }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 10663 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         FloatMatrix* m;
         m = new FloatMatrix((int)(yysemantic_stack_[(6) - (3)].adouble),(int)(yysemantic_stack_[(6) - (5)].adouble));
         driver.matrix_stack.AddMatrix(m);
       }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 10670 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      FloatMatrix* newmat;
      FloatMatrix::ptr mat = *(FloatMatrix::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

      newmat = new FloatMatrix( (*mat));

          driver.matrix_stack.AddMatrix(newmat);
       }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 10680 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
         Inversion of a symmetric matrix
        **/
          FloatMatrix* mat;
          FloatMatrix* res;
          mat=driver.matrix_stack.GetLastMatrix();
          res = mat->Transpose();
          delete mat;
          driver.matrix_stack.AddMatrix(res);
        }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 10700 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(-)               }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 10703 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix* mat;
          FloatMatrix* res;
          mat=driver.matrix_stack.GetLastMatrix();
          res = mat->Transpose();
          delete mat;
          driver.matrix_stack.AddMatrix(res);
        }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 10711 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sin)             }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 10712 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(cos)             }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 10713 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sqrt)            }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 10714 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(fabs)            }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 10715 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(round)           }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 10716 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(floor)           }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 10717 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(tan)             }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 10718 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(asin)            }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 10719 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(acos)            }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 10720 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(atan)            }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 10721 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(exp)             }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 10722 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(1.0/log(10.0)*log) }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 10723 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(log)             }
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 10730 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(*,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 10731 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(*)   }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 10733 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         FloatMatrix* m2 = driver.matrix_stack.GetLastMatrix();
         FloatMatrix* m1 = driver.matrix_stack.GetLastMatrix();
             FloatMatrix* res = Multiply(m1, m2) ;
         driver.matrix_stack.AddMatrix(res);
         delete m1;
         delete m2;
           }
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 10743 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(+,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 10744 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(-,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 10745 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(+)   }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 10746 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(-)   }
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 10795 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yysemantic_stack_[(1) - (1)].variable);
        }
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 10800 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          VarArray::ptr array;
          int  i = (int) (yysemantic_stack_[(4) - (3)].adouble);

          array = *(VarArray::ptr*) ((yysemantic_stack_[(4) - (1)].variable)->Pointer());
          if (array->GetVar(i).Pointer()==NULL) {
            // initialize the surface
            SurfacePoly* surf = new SurfacePoly();
            std::string name = (boost::format("%s[%d]") %(yysemantic_stack_[(4) - (1)].variable)->Name().c_str() %i).str();
            array->InitElement(i,surf,name.c_str());
          }
          (yyval.variable)=&(array->GetVar(i));
        }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 10816 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          InrImage::ptr im = InrImage::ptr(driver.im_stack.GetLastImage());
          surf = Func_isosurf(im,
                  (yysemantic_stack_[(6) - (5)].adouble),
                  NULL);
          if (surf==NULL) driver.err_print("Isosurface failed!");
          driver.surf_stack.AddSurf(surf);
    }
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 10827 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        SurfacePoly* surf;
        surf = Func_isosurf((*(InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer()),
                (yysemantic_stack_[(6) - (5)].adouble),
                NULL,
                2);
        driver.surf_stack.AddSurf(surf);
    }
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 10837 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        InrImage::ptr im = InrImage::ptr(driver.im_stack.GetLastImage());
        SurfacePoly* surf;
        surf = Func_isosurf(im,
                (yysemantic_stack_[(8) - (5)].adouble),
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (7)].variable)->Pointer())->get());
        if (surf==NULL) driver.err_print("Isosurface failed!");
        driver.surf_stack.AddSurf(surf);
    }
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 10857 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr mask = InrImage::ptr(driver.im_stack.GetLastImage());
      InrImage::ptr im   = InrImage::ptr(driver.im_stack.GetLastImage());
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

  case 825:

/* Line 678 of lalr1.cc  */
#line 10891 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_decimate(((SurfacePoly::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 10900 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_decimate(((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble) );
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 10909 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_vtkMarchingCubes(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),(yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 10918 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_vtkSmooth(((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 10927 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        SurfacePoly* surf;
        surf = Func_vtkWindowedSinc(((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
        if (surf==NULL) driver.err_print("vtkWindowedSinc failed!");
        driver.surf_stack.AddSurf(surf);
    }
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 10935 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf = new SurfacePoly();
      driver.surf_stack.AddSurf(surf);
    }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 10941 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.surf_stack.AddSurf((yysemantic_stack_[(2) - (2)].astring));
      delete [] (yysemantic_stack_[(2) - (2)].astring);
    }
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 10947 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.surf_stack.AddSurf((yysemantic_stack_[(4) - (3)].astring));
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 10953 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          if (driver.in_console)
            GB_main_wxFrame->GetConsole()->IncCommand(inc_cmd);
        }
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 10979 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (3): input filename (text file)
        Description:
            Reads a line given described in a text file
            format used in the CTA coronary segmentation challenge
        **/
          SurfacePoly* surf;
          surf = Func_ReadCTALine((yysemantic_stack_[(4) - (3)].astring));
          driver.surf_stack.AddSurf(surf);
      }
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 10993 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          surf = Func_ReadCTALine((yysemantic_stack_[(6) - (3)].astring), (int) (yysemantic_stack_[(6) - (5)].adouble));
          driver.surf_stack.AddSurf(surf);
      }
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 11009 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* newsurf;
      SurfacePoly::ptr surf = *(SurfacePoly::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

      newsurf = new SurfacePoly( (*surf) );

          driver.surf_stack.AddSurf(newsurf);
      }
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 11019 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Creates lines from a skeleton image
        **/
          SurfacePoly* surf;

      surf = Func_Skeleton2lines( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get()  );

      Si surf==NULL Alors
        driver.err_print("Skeleton2lines() error ... \n");
      FinSi
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 11037 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          SurfacePoly* surf;

      surf = Func_SmoothLines( ((SurfacePoly::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get(),
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

  case 839:

/* Line 678 of lalr1.cc  */
#line 11065 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          SurfacePoly* surf;

      surf = Func_SmoothLines( ((SurfacePoly::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),
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

  case 840:

/* Line 678 of lalr1.cc  */
#line 11092 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf;

      surf = Func_ResampleLines( ((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                     (yysemantic_stack_[(6) - (5)].adouble));

      Si surf==NULL Alors
        driver.err_print("ResampleLines() error ... \n");
      FinSi
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 11108 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        - input polydata containing lines
        - point 1: x,y,z
        - point 2: x,y,z 
      Description:
        Finds the shortest path within the lines of the polydata
    **/
      SurfacePoly* surf;

      surf = Func_shortestpath( ((SurfacePoly::ptr*) (yysemantic_stack_[(16) - (3)].variable)->Pointer())->get(),
                      (yysemantic_stack_[(16) - (5)].adouble), (yysemantic_stack_[(16) - (7)].adouble), (yysemantic_stack_[(16) - (9)].adouble),
                      (yysemantic_stack_[(16) - (11)].adouble),(yysemantic_stack_[(16) - (13)].adouble),(yysemantic_stack_[(16) - (15)].adouble));

      Si surf==NULL Alors
        driver.err_print("Func_shortestpath () error ... \n");
      FinSi
      driver.surf_stack.AddSurf(surf);
    }
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 11131 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im = InrImage::ptr(driver.im_stack.GetLastImage());
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

  case 843:

/* Line 678 of lalr1.cc  */
#line 11164 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im = InrImage::ptr(driver.im_stack.GetLastImage());
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

  case 844:

/* Line 678 of lalr1.cc  */
#line 11200 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im = InrImage::ptr(driver.im_stack.GetLastImage());
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

  case 845:

/* Line 678 of lalr1.cc  */
#line 11246 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im = InrImage::ptr(driver.im_stack.GetLastImage());
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

  case 846:

/* Line 678 of lalr1.cc  */
#line 11284 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          SurfacePoly* surf;

      surf = Func_ConnectLines( ((SurfacePoly::ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer())->get(),
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

  case 847:

/* Line 678 of lalr1.cc  */
#line 11308 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr im = InrImage::ptr(driver.im_stack.GetLastImage());
      SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 11318 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im = InrImage::ptr(driver.im_stack.GetLastImage());
          SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get(), (int) (yysemantic_stack_[(6) - (5)].adouble) );
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 11341 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im = InrImage::ptr(driver.im_stack.GetLastImage());
      float minth = (yysemantic_stack_[(8) - (5)].adouble);
      float maxth = (yysemantic_stack_[(8) - (7)].adouble);
          SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get(),minth,maxth);
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 11353 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im = (InrImage*) driver.im_stack.GetLastImage();
          SurfacePoly* surf;
      float minth = (yysemantic_stack_[(8) - (5)].adouble);
      float maxth = (yysemantic_stack_[(8) - (7)].adouble);

      surf = AMIFluid::Func_vtkCreateFlatMesh(im,minth,maxth);
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
     delete im;
        }
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 11366 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr highpos = InrImage::ptr(driver.im_stack.GetLastImage());
      InrImage::ptr lowpos  = InrImage::ptr(driver.im_stack.GetLastImage());
      InrImage::ptr input   = InrImage::ptr(driver.im_stack.GetLastImage());
      SurfacePoly* surf;
      float minth = (yysemantic_stack_[(12) - (5)].adouble);
      float maxth = (yysemantic_stack_[(12) - (7)].adouble);

      surf = AMIFluid::Func_CreateVolume(input.get(), minth, maxth, lowpos.get(), highpos.get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 11403 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr colors  = InrImage::ptr(driver.im_stack.GetLastImage());
      InrImage::ptr highpos = InrImage::ptr(driver.im_stack.GetLastImage());
      InrImage::ptr lowpos  = InrImage::ptr(driver.im_stack.GetLastImage());
      InrImage::ptr input  = InrImage::ptr(driver.im_stack.GetLastImage());
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

  case 853:

/* Line 678 of lalr1.cc  */
#line 11446 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      InrImage::ptr alt2  = InrImage::ptr(driver.im_stack.GetLastImage());
      InrImage::ptr displ = InrImage::ptr(driver.im_stack.GetLastImage());
      InrImage::ptr alt1  = InrImage::ptr(driver.im_stack.GetLastImage());
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

  case 854:

/* Line 678 of lalr1.cc  */
#line 11494 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      InrImage::ptr alt2  = InrImage::ptr(driver.im_stack.GetLastImage());
      InrImage::ptr displ = InrImage::ptr(driver.im_stack.GetLastImage());
      InrImage::ptr alt1  = InrImage::ptr(driver.im_stack.GetLastImage());
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

  case 855:

/* Line 678 of lalr1.cc  */
#line 11546 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr alt2  = InrImage::ptr(driver.im_stack.GetLastImage());
      InrImage::ptr displ = InrImage::ptr(driver.im_stack.GetLastImage());
      InrImage::ptr alt1  = InrImage::ptr(driver.im_stack.GetLastImage());
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

  case 856:

/* Line 678 of lalr1.cc  */
#line 11589 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr displ = InrImage::ptr(driver.im_stack.GetLastImage());
      int stepx   = (int) (yysemantic_stack_[(14) - (5)].adouble);
      int stepy   = (int) (yysemantic_stack_[(14) - (7)].adouble);
      int stepz   = (int) (yysemantic_stack_[(14) - (9)].adouble);
      float scale = (yysemantic_stack_[(14) - (11)].adouble);
      int style = (int) (yysemantic_stack_[(14) - (13)].adouble);
      SurfacePoly* surf;

       surf = AMIFluid::Func_CreateVectors(displ.get(), stepx, stepy, stepz,  scale, style);
       Si surf != NULL Alors
         driver.surf_stack.AddSurf(surf);
       FinSi
    }
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 11617 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr v3  = InrImage::ptr(driver.im_stack.GetLastImage());
      InrImage::ptr v2  = InrImage::ptr(driver.im_stack.GetLastImage());
      InrImage::ptr v1  = InrImage::ptr(driver.im_stack.GetLastImage());
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

  case 858:

/* Line 678 of lalr1.cc  */
#line 11650 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr mask   = InrImage::ptr(driver.im_stack.GetLastImage());
      InrImage::ptr colors = InrImage::ptr(driver.im_stack.GetLastImage());
      InrImage::ptr v3     = InrImage::ptr(driver.im_stack.GetLastImage());
      InrImage::ptr v2     = InrImage::ptr(driver.im_stack.GetLastImage());
      InrImage::ptr v1     = InrImage::ptr(driver.im_stack.GetLastImage());

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

  case 863:

/* Line 678 of lalr1.cc  */
#line 11700 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yysemantic_stack_[(1) - (1)].variable);
        }
    break;

  case 880:

/* Line 678 of lalr1.cc  */
#line 11724 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent<float>* extent=new ImageExtent<float>( (float)(yysemantic_stack_[(11) - (1)].adouble),(float)(yysemantic_stack_[(11) - (3)].adouble),(float)(yysemantic_stack_[(11) - (5)].adouble),
                              (float)(yysemantic_stack_[(11) - (7)].adouble),(float)(yysemantic_stack_[(11) - (9)].adouble),(float)(yysemantic_stack_[(11) - (11)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        }
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 11732 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent<float>* extent=new ImageExtent<float>((float)(yysemantic_stack_[(7) - (1)].adouble),(float)(yysemantic_stack_[(7) - (3)].adouble),(float)(yysemantic_stack_[(7) - (5)].adouble),(float)(yysemantic_stack_[(7) - (7)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        }
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 11739 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage::ptr im = *(InrImage::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

          ImageExtent<float>* extent=new ImageExtent<float>();
          extent->SetMode(0); // absolute
          extent->SetXmin( im->SpacePosX(0));
          extent->SetXmax( im->SpacePosX(im->DimX()-1));
          extent->SetYmin( im->SpacePosY(0));
          extent->SetYmax( im->SpacePosY(im->DimY()-1));
          extent->SetZmin( im->SpacePosZ(0));
          extent->SetZmax( im->SpacePosZ(im->DimZ()-1));
          extent->print();
          (yyval.imageextent)=extent;
       }
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 11755 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        DessinImage::ptr draw = *(DessinImage::ptr*) ((yysemantic_stack_[(1) - (1)].variable)->Pointer());

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
        if (driver.in_console) GB_main_wxFrame->GetConsole()->IncCommand(comment);

        (yyval.imageextent)=extent;
       }
    break;



/* Line 678 of lalr1.cc  */
#line 14793 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
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
  const short int Parser::yypact_ninf_ = -2819;
  const short int
  Parser::yypact_[] =
  {
      3863, -2819,  9341,  9194,  9194,  1636, -2819, -2819, -2819, -2819,
   -2819,    93,   139,   146, -2819, -2819, -2819, -2819,   -30,   314,
   -2819,    71,  1636, 15275,  1563,   164,   218,  1563, -2819,   228,
     231, -2819, -2819, -2819, -2819,   109,   118,   160,    61,   237,
   -2819,    79,    64,    68, -2819,   248, -2819,   278,    14,    39,
     263,   277,    35,   291,  1679,  1563, -2819, -2819, -2819, -2819,
     336,   341,   352,   362,   372,   401,   549,   383,   361, -2819,
   -2819, -2819,   396,   410,   419,   429,   434,   657,   442,   455,
     458,   471,   488,   528,   550,   590,   620,   660,   709,   719,
     730,   733, -2819,   767,   770, -2819, -2819, -2819, -2819, -2819,
   -2819, -2819, -2819, -2819, -2819,   796,   818,   829, -2819, -2819,
    9194,  9194,  9194,  9194,  9194,  9194,  9194,  9194,  9194,  9194,
    9194,  9194,  9194,    14, -2819, -2819, 15275,  1140,  1563,   841,
     847,   865,    82,    14,   883,   916,   918,   925, -2819, -2819,
   -2819, -2819, -2819, -2819, -2819,   926,   927, -2819,   645,  9064,
   -2819, -2819, -2819, -2819, -2819, -2819, -2819,    74, -2819, -2819,
     563,   252, -2819, -2819, -2819,  9194, -2819,   308,   571, -2819,
      52,   377,   760,   656,   794,   805,    48, -2819, -2819, -2819,
   -2819,    57, -2819, -2819, -2819, -2819,   801,    28,   611, -2819,
   -2819, -2819, -2819, -2819, -2819, -2819, -2819, -2819, -2819, -2819,
      69,   -34,   923,  9341,  9341, 15275, -2819, -2819, -2819,   930,
   -2819,   951,   946,    39,   950,   955,   957,   954,   959,  9341,
    9341,  9341,  9341,  9341,  9341,  9341,  9341,  9341,  9341,  9341,
    9341,  9341,  9341, -2819,   399,   962,   951, -2819,   801, -2819,
     801, -2819,   960,   973,   432,   974,  1563, 15275,  1563, -2819,
   -2819, -2819, -2819, -2819, -2819, -2819, -2819, -2819,   252, -2819,
   -2819,   252, -2819, -2819,   964,  1563,  1563, -2819,  1768,  1768,
   -2819, -2819, 15275, -2819, -2819, 15275, -2819, -2819, 15275,  1563,
    1131,  1455,    29,    29, 15275,  1636,     9,   542, 10971, 10971,
   -2819, -2819, -2819,   807,   -32, 15275,   648, 15275, -2819, -2819,
   -2819, -2819, -2819, -2819, -2819, -2819, -2819, -2819, -2819, -2819,
   -2819, -2819, -2819,   961,   957, -2819, -2819, -2819, 15275, 15275,
   14347, 11991, 14347, 14347, 14347, 14347, 14347, 14347,    71,   724,
    2069,   369,   541,    71,    71, 14347, 14347,    71,    71,    71,
      71,    71,    71,    71,    71,   935,   938, 15275, 15275,    71,
   15275, 15275,   120,  1563, 14347,    71, -2819,   801, -2819,   801,
   -2819,   801, -2819,   801, -2819,   801, -2819,   801, -2819,   801,
   -2819,   801, -2819,   801, -2819,   801, -2819,   801, -2819,   801,
   -2819,   801,  -135, -2819,   940, -2819, -2819,    74, -2819,  1456,
    1563,   942, -2819, -2819, -2819, 15275,  1563,   934,    71,    71,
      71, -2819, -2819, -2819, -2819, -2819, -2819, -2819, -2819, -2819,
      74, -2819,  1563,  1563,  1563,  1563, -2819,   801,  9341,  9341,
    9341,  9341,  9341,  9341,  9341,  9341,  9341,  9341,  9341, 15275,
   15275, 15275, 15275, 15275, 15275, 15275, 15275,    25, 14347, 11991,
   -2819,  9194,   120,  9194,  9194,   763,   -28, 13934,  9951,   919,
     251,   370,   631, 15275, 15275,   601,   822, 15275,   -42,  -139,
   -2819, 15771,   -36, -2819,   985,   992,   994,   963,   995,   990,
   -2819,   997,   998, -2819, -2819, -2819, -2819,  1003,  1004,  1005,
    1008,  1009,  1011, -2819, -2819, -2819, -2819, -2819, -2819, -2819,
   -2819, -2819,  1012,  1013,  1015, -2819,  1016,  1017,  1019,  1020,
   -2819,  1022,  1023,  1024,  1025,  1026,  1027,  1028,  1030,  1032,
    1043,  1045,  1053,  1057,  1060,  1069, -2819,  1074,  1075,  1076,
    1078, -2819, -2819,  1082, -2819,  1083, -2819,  1084,  1085,  1086,
    1088,  1093, -2819, -2819,  1087, -2819, -2819, 15275,  1563, -2819,
    1099,  1102, -2819,  1103, 13011, 13011, 11991,   279,   589,  1104,
    1105,  1106,  1110,   729,  1113,  1114,  1115,  1116,  1117,  1118,
    1119,  1120,  1126,  1132,  1133,  1134,  1151,   443,  1152,  1153,
    1154,  1156,  1125,  1157,  1159,  1162,  1158,  1160,  1163,  1165,
    1167,  1168,  1169,  1170,  1174,  1175,  1176,  1179,  1180,  1182,
    1183,  1186,  1187,  1188,  1205,  1206,  1207,  1209,  1212,  1213,
    1214,  1215,  1216,  1217,  1219,  1220,  1221,  1222,  1223,  1224,
    1225,  1226,  1227,  1228,  1229,  1230,  1231,  1232,  1233,  1236,
    1237,  1238,  1239,  1241,  1242,  1243,  1244,  1246,  1249,  1254,
    1255,  1257,  1258,  1259,  1261,  1262,  1263, 13011, 13011, 13011,
   13011, 13011, 13011, 13011, 13011, 13011, 13011, 13011, 13011, 13011,
   14347,  1264,  1265,  1266,  1267,  1268,  1269,  1270,  1271,  1272,
    1273,  1274,  1275,   450,   252, 13011, -2819,   384, -2819, -2819,
   -2819,  1146, -2819,   426, -2819,   830, -2819,    60,   705,  1101,
   -2819,  1279,  1155,    58, -2819, -2819, -2819,  1280,   452, -2819,
    1285, -2819,  1287, -2819, -2819, -2819,  1295,  1297,  1298,  1299,
   -2819, -2819,  1301,  1302,  1303,  1304,  1305,  1321,  1322,  1323,
    1324,  1325,  1333,  1334,  1335, -2819, -2819, -2819, -2819,  1336,
    1337,  1340,  1342, -2819,  1563,  1277,  1341,  1343, 15275,  1344,
    1345, 14347, 14347,  8443,  1338,  1347,   456,  1348, 14347, 14347,
   14347, 14347, 14347, 14347, 14347, 14347, 14347, 14347, 14347, 14347,
   14347, 14347,   812,  1349,  1350,  1105,  1346,  1354,  1355,  1356,
    1359,  1360,  1361,  1362,  1357,  1351,  1366,  1370, -2819, -2819,
    1371,  1372, -2819, -2819,  1373,  1374,  1375,  1383,  1386,  1393,
    1402,  1403, -2819,  1405,  1408,  1412,  1428,  1429,  1430,  1431,
    1432,  1433,  1434,  1435,  1438,  1439,  1441,  1443,  1446,  1447,
    1448,  1449,  1450,  1451,  1452,  1453,  1457,  1458,  1459,  1460,
    1461,  1462, -2819, -2819, -2819, -2819, -2819, -2819,  1475,  1454,
      89,  1465,  1464,  1476,  1477,  1478,  1479,  1480,  1481,  1482,
    1483,  1484,  1485,  1492,  1494,  1489,  1490,   143,  1491,   120,
     120,   120, -2819,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,  1520,  1521,  1516,
    1523, 15275,  1563, -2819,   -18, -2819,  1529,  1542,  1543,  1544,
    1463,  1546,    74,  1540,  1547,  1548,  1549,  1550,  1551, -2819,
   -2819, -2819, -2819, -2819, -2819, -2819, -2819,   308,   308, -2819,
   -2819, -2819, -2819,    52,    52,   377,   760,   656,   794,    37,
     805,   322,  1556,  1553, -2819,  1554, -2819, -2819,  1563, -2819,
    1560,  1564,  1565,  1582,  1583,  1584,  1585,  1586,  1587, -2819,
   -2819, -2819, -2819, -2819, -2819,   801,   801,   308,    28,   308,
      28, -2819, -2819, -2819,  1563,  1588,  1589, -2819,  1563, -2819,
    1590, -2819,  1591,  1592,  1597,  1603,  1605,  1607,  1609,  1611,
    1613,  1614,  1615,  1616,  1617,  1618,  1620,  1621, -2819,  1622,
   -2819,  1626, -2819, -2819,  1628,  1629,  1631,  1635,  1651, -2819,
   -2819,  1653,  1656,  1657,  1658,  1659,  1660,  1661,  1662,  1663,
    1664,  1665,  1666,  1667,  1670,  1671,  1672,  1675,   969,  1676,
    1678,  1680,  1688,  1691,  1555, -2819,  1690, -2819, 12501, 12501,
   10461,   793,  1693,  1557,  1694, -2819, -2819,  1695,   917,  1698,
    1701,  1702,  1703, 12501, 12501, 12501, 12501, 12501, 12501, 12501,
   12501, 12501, 12501, 12501, 12501, 12501,    24, 12501,  1697, -2819,
   -2819, -2819,  1699, -2819,  1706,  1704,  1705,   149, 15275, -2819,
    1563, -2819, -2819,  1710, 15275, -2819, -2819, 15275, 15275, 15275,
   15275, 15275, 15275,    71, 15275, 15275,    78,  1306,  1406, 15275,
   15275, 15275, 15275, 15275, 15275, 15275, 14347, 15275,  1296, 15275,
    1652, 15275, 15275,   -28, 15275, 15275, 15275, 15275, 15275,    29,
       3,  1497,  1507, 15275, 15275, 15275, 15275,   252, -2819, -2819,
    1563,   138,  1563,   389, -2819, -2819, -2819,  1712,  1713, -2819,
   -2819, -2819, -2819,   -13, -2819, 15275,    26,   503, 10971, 11991,
      71, 14347, 14347,    71,    71,    71,    71,    71, 14347,    71,
      71,    71,    71,    71,     1,    71,    71,    71,    71,    -9,
   14347, 14347,    71,  1508,  1509,    71,    71,    71,    71,    71,
      71,    71,    71,    71, 14347,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71, 14347, 14347,
   14347, 14347, 14347,    71,    71,    71,    71,    71,    29,    29,
    1563,  1563,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71, 14347,    71,    71,    71,    71,
      71,    71, 14347, 14347, -2819, -2819, -2819, -2819, -2819, -2819,
   -2819, -2819, -2819, -2819, -2819, -2819, -2819, -2819, 14347, 14347,
   14347,    71, 14347, 14347,  1253, 14347, 14347, 14347, 14347,  1563,
   -2819, 11481, -2819, 11991, 15105, 14347, 14347, 13011, 13011, 13011,
   13011, 13011, 13011, 13011, 13011, 13011, 13011, 14347, 14347, 14347,
   14347, 14347,  -144,    74,  1563,  1563,  1563, 15275,  1673,  1700,
    1563,  1669,  1707, 15275,  1696,  1709,  1711,  1563, 15275,  1692,
   15275, 15275,  1563, 15275, 15275, 15275, 15275, -2819,  1625, 15275,
    1630,  1715, -2819,  1708,  1719,   394,  1389, 14347,   800,   -10,
   14347, -2819,   -59, 15275, -2819,  1746, -2819, -2819,  1749, -2819,
    1751,    71, 15275,    71, 15275, 15275, 15275,    71,    71,    71,
      71, 15275, 15275, 15275, 15275, 15275, 15275, 15275,    71, 15275,
      71,    71,    71,   112,    71,   188,   215,    71,    71, 15275,
   15275, 15275, 15275, 15275, 15275, 15275, 15275, 15275, 15275, 15275,
   15275, 15275, 15275, 15275,    71, -2819, 14347, -2819,  1752, 15275,
   15275, 15275, 15275, 15275, 15275, 15275,    71,    71,    71, -2819,
   -2819, 15275, 15275, -2819, 15275, -2819, -2819,  1563, -2819,  1294,
    1755, -2819, -2819, -2819, -2819, -2819, -2819, -2819, -2819,   382,
     382, -2819, 15275, -2819, 15275,  1563,    71,    71, 15275, -2819,
   15275, 15275, 15275,  1632,  1563,    71, -2819,    71,    71, 15275,
   15275, 15275, 15275, 15275, 15275, 15275, -2819, 15275, 15275, -2819,
   15275, 15275, 15275, 15275, 15275, 15275, 14347, 15275, 15275, 15275,
   15275, 15275, 15275, 15275, 15275,    71, 14347, 15275, 14347, 15275,
   15275,    71, 15275, 15275, 15275, 14347,    71,    29,    29,    29,
   14347, 14347, 14347,  1563, 14347,    71,    29,    71,    29,    29,
   14347,  1561, -2819, 14347, 14347, 14347, 14347, 14347,  1498, 15275,
   15275,  1563,  -262, 10971,  1563, 15275,  1714, 15275, 15275,  1563,
    1563,  1563,  -148,  1563, -2819, -2819,  1757, 15275,  1766,  1767,
     333,  1770,  1771,  1772,  1781,  1776,  1783,  1778,  1785,  1786,
    1788,  1784,  1790,  1792,  1793,  1794,  1802,  1803,  1826,  1827,
    1828,  1829,  1836,  1831,  1838,  1833,   462,  1840,  1841,  1837,
    1839,  1842,  1843,  1844,  1787,   466,  1850,  1847,  1848,  1849,
    1856,  1857,  1864,  1866,  1869,  1868, 13521, -2819,  1870,  1878,
    1881,  1886, -2819, -2819, -2819,   467,   505,  1887,  1888,  1890,
    1875,  1891,  1893,  1894,  1895,  1896,  1897,  1898,  1899,  1900,
    1901, -2819, -2819,  1902,  1904,  1912,  1907, -2819,  1773,  1915,
    1911,  1924,  1926,  1934,  1935,  1936,  1929,  1931,  1932,  1933,
    1943,  1944,  1945,  1946,  1949,  1956,  1957,  1958,  1953,  1960,
    1955,  1961,  1962,  1967,  1968,   506,  1969,  1970,  1971,  1972,
    1984,  1985,  1986,  1966,  1987,  1988,  1989,  1990,  1994,  1997,
    2006,  2007,  2003,  2005,  2008,  2009,  2010,  2011,  2012,  2013,
    2014,  2016,  2017,  2021,  2022,  2029,  2030,  2031,  2035,  2036,
    2037,  2038,  2034,  2040,  2041,   507,  2044,  2058,  2060,  2062,
    2042,   508,   515,  2064,  2043,  2071,   302,  1105,   252, -2819,
   -2819,  2072,  2067,   930,   514,   432,  1885, -2819, -2819, -2819,
   -2819, -2819, -2819,   308,   426,   308,   426, -2819, -2819, -2819,
   -2819, -2819, -2819, -2819, -2819, -2819,    60, -2819,    60,   705,
   -2819,  1279,    51,  1155,  2045,  2075,  2085,  2093,  2094, -2819,
    2095,  2096,  2097,  2088,  2098,  2100,  2103,   518,   519,  2104,
    2106,  2107,  2108,  2111,  2115,  2099,   520,  2118,  2101,  2119,
    2122,  2124,  2102,   -28,  2129, 14347, -2819,  2132, 14760,  1716,
    2127,  2134, 14347,    71,    71,   547,  2135,  2130,   551,  2137,
    2138,  2139,  2140,  2141,  2145,  2147,  2151,  2153,  2154,  2155,
    2157,  2158,  2156,  2160,  2163,  2162,  2164,  2170,  2171,  2172,
    2173,  2174,  2176,  2177,  2179,  2181,  2185,  2180,  2187,  2182,
    2189,  2190,  2191,  2192,  2193,  2195,  2196,  2198,  2200,  2201,
    2202,  2212,  2218, 14347,  2213,  2220,   552,  2221,  2222,  2224,
    2223,  2256,  2257,  2258,  2260,  2261,  2230,  2262, 15275,  1563,
      74,    74,  1999,  2226,  2227,  2228,  2229,   576,   579,  2267,
    2268,  2275,  2270,  2273, -2819,   267,  2274,  2281, 11991,  2282,
     580,  2283,  2284,  2279,   344,  2280,   375,  2287,   581,  2285,
    2286,   604,  2288,  2289,  2290,  2293,   605,  2294,  2295,  2291,
     609,  2296,  2292,  2297,  2298,  2299,  2300,  2301,  2302,  2305,
    2306,  2307,  2308,  2303,  2304,  2311,  2312,  2309,  2313,  2314,
    2316,   612,  2315,  2317,  2318,  2319,  2320,   616,  2321,  2322,
     617,  2323,  2324,  2325,  2326, -2819,  2333,   624,  2328,  2329,
    2330,  2331,  2339,  2337,  2338,  2341, -2819,   632,  2342,  2343,
    2340,  2344,  2347,  2345, -2819, -2819,  2348,  1563,   252, -2819,
   -2819,    71, 15275, 15275, 15275, 15275, -2819, 15275, -2819, 15275,
   -2819, -2819, -2819,    71,    71, 15275, 15275, 15275, -2819, -2819,
   15275, 15275, 15275, 15275, -2819, 15275, -2819, 15275, -2819, 15275,
   -2819, -2819, 15275, 15275, 15275, 15275, -2819,  1627, -2819, 15275,
   -2819,    71, 15275, 14347, -2819,  1882, -2819, -2819, -2819,  2063,
   11991, -2819, -2819, 15275,   -44, 15275, -2819, 14347,    96, 15275,
   15275, -2819, 15275, 15275, 15275, 15275, 15275, 15275, 15275, 15275,
   15275, 15275, 15275, 15275, -2819, 15275,    71,    71, 14347, 14347,
      71,    71,    71, -2819, 15275, 15275, 15275, 15275, 15275, 15275,
   15275, 15275, 15275, -2819, -2819, -2819,    71, -2819,    71,    71,
      71,    71,    71, -2819,    71,    71, 15275, 15275, 15275, 15275,
   14347, 14347, -2819, 15275, 15275, 15275, 15275,    71,  1563, -2819,
   -2819,    71,    71, 15275, 15275, 15275, 15275, 15275, 15275, 15275,
   15275, 15275, 15275, 15275, -2819, -2819, -2819, -2819, -2819, -2819,
   -2819, 15275, 15275, 15275, -2819, 15275, 15275,    71, 15275, 15275,
      71, -2819, 15275, -2819, 15275, 14347, -2819, -2819, -2819, -2819,
   -2819, -2819, -2819,  2310, -2819, 15275, -2819, 14347, 15275,    71,
    2349,  2350,  2352, -2819, -2819, -2819, 15275, 15275, 15275,  2263,
   -2819,  1563, -2819, 15275,  1563,  1563,  1563,  1563,  1563, 15275,
   -2819, -2819, 15275, 15275, -2819, 15275, 15275, 15275, -2819, -2819,
   -2819, -2819, -2819, 14347, -2819,  2353,  2354,   634, -2819,    71,
   -2819, 15275, -2819, 15275, -2819, -2819, -2819, -2819, -2819, -2819,
   -2819, -2819, -2819, -2819, -2819, -2819, -2819, 15275, -2819, -2819,
      71, -2819, -2819, -2819, -2819, -2819, -2819, -2819, -2819, -2819,
   -2819, -2819, 15275, -2819, 15275, -2819, -2819, -2819, -2819, 15275,
   -2819, -2819, -2819, -2819, -2819, 15275, -2819, -2819,  2355, 15275,
   15275, -2819, 11991, 15275, 15275, -2819, 15275, 15275,    71,    71,
   15275, 15275, -2819, 15275,  1858, -2819, -2819, -2819, -2819, -2819,
   -2819, -2819, -2819, -2819,   444, -2819, 15275, 15275, -2819,    71,
   15275, -2819, 15275, 15275, 15275, -2819, -2819, -2819, -2819, -2819,
   15275, -2819, -2819, 15275, -2819, 15275, -2819, -2819, -2819, 15275,
   15275, 15275, -2819, 15275, -2819, -2819, -2819, -2819, -2819, 15275,
   -2819, -2819, 15275, -2819, 15275, -2819, 15275, 15275, 15275, -2819,
   -2819, -2819, -2819, -2819, -2819, -2819, -2819, 15275, 15275, -2819,
   -2819, 15275, -2819, -2819, -2819, -2819, 15275, 15275, 15275, 15275,
   15275, 15275, -2819, 15275, 15275, 15275, -2819, 15275, 15275, 15275,
   15275, 15275, -2819, -2819, 15275, 15275, 15275, 11991, 14347, 15275,
   -2819, -2819, -2819, -2819, -2819, -2819,  2327,  2351,  2356,  2332,
   -2819,  2360,  2357,  2361,  2358,  2366,  2362,  2367,  2363,  2370,
    2371,  2373,  2374,  2369,  2372,  2376,  2375,  2377,  2378,  2379,
    2380,  2381,  2383,  2384,  2385,  2382,  2386,  2392,  2387, 15275,
    2394,  2389,  2390,  2397,   635,  2393,  2395,  2398,  2400,  2402,
    2404,  2399,  2406,  2401,  2403,  2405,  2407,  2408,  2409,  2410,
    2411,  2412,  2413,  2414,  2415,  2416,  2417,  2418,  2419,  2420,
    2421,  2422,  2423,  2424,  2425,  2426,  2433,  2428,  2429,  2430,
    2431,  2432,  2434,  2439,  2441,  2436,  2443,  2444,  2445,  2440,
    2442,  2447,  2449,  2450,  2451,  2446,  2453,  2454,  2452,  2456,
    2458,  2455,  2457,  2459,  2460,  2466,  2468,  2469,   639,  2464,
    2465,  2473,  2478,  2474,  2479,  2480,  2488,  2483,  2486,  2493,
    2494,  2495,  2491,  2492, -2819,  2499,  2500, -2819, -2819, -2819,
    2502,    87,  2505,   114,  2520,  2528,  2529,    41,  2530,  2531,
    2532,  2533,  2535,  2534,  2536,  2537,  2538,  2542,  2543,  2545,
   -2819, -2819, -2819, 15275,  2546,  2541,  2548,  2551,  2547,  2549,
    2552,  2550,  2558, -2819,   642,   643,   644,  2554,  2561,  2564,
    2565,  2570,  2571,  2576,  2577,  2578,  2557, 15275,    74,    74,
    2276,  2334,  2365,  2515,  2544,    74,  2585,  2580,  2582,  2583,
     367,  2590,  2335,  2586,  2588,  2589,  2591,  2592,  2594,  2595,
    2596,  2598,  2601,  2602,  2603,  2604,  2605,  2606,  2607,  2608,
    2618,  2613,  2616,  2617,  2619,  2624,   647,  2626,  2627,  2628,
    2629,  2630,  2625,   651,  2633,  2642,  2652,  2657,  2658,  2659,
    2660,  1563,  1563,  2632, -2819, 15275, -2819, 15275, -2819, 15275,
   -2819, 15275, -2819, -2819, -2819, -2819, 15275, 15275, -2819, 15275,
   15275, 15275, 15275, -2819, 15275, 15275, 15275, 15275, -2819, -2819,
   -2819, 15275, -2819, -2819, 15275, 15275, -2819, -2819,   110,   249,
   15275, -2819, -2819, -2819, -2819, 15275, -2819, 15275, 15275, 15275,
   15275, 15275, 15275, 15275, 15275, -2819, 15275, 15275, 15275, 15275,
   15275, 15275, 15275, 15275, 15275, 15275, 15275, 15275, 15275, 15275,
   -2819, 15275,    71,    71,    71,    71,    71, -2819, -2819, 15275,
   -2819, -2819, -2819, 15275, 15275, -2819, -2819, -2819, -2819, 14347,
   -2819, -2819, 14347, 15275, 15275, -2819, -2819, -2819, -2819, -2819,
   -2819, -2819, -2819, 15275, 15275, 15275, 15275, 15275, -2819, 15275,
   15275, -2819, 15275, 15275, -2819, -2819, -2819, 15275, 15275, -2819,
   -2819, -2819, 15275, 15275, 15275, 15275, -2819, -2819, -2819, -2819,
   -2819, -2819, -2819,  1563, -2819, -2819, -2819, 15275, -2819, -2819,
   -2819,  2634, -2819, 15275, -2819, -2819,    71, 15275, -2819, 15275,
   15275, -2819, 14347, -2819, 14347, -2819, 14347, -2819, 14347, 15275,
   15275, 15275,    71,    71, 15275, 15275, -2819, -2819, -2819, -2819,
   -2819, -2819, -2819, -2819, -2819, -2819, -2819, 15275,    71, 15275,
   -2819, 15275, 15275, -2819, 15275, 15275, 15275, 15275, 15275, 15275,
   15275, 15275, -2819, 15275, 15275, 15275, 15275, 15275, 15275, 15275,
   15275, 15275, -2819, 15275, 15275, 15275, 15275, -2819, -2819,    71,
   -2819, -2819, -2819, -2819, -2819, 14347, -2819, 15275, 15275, 15275,
   15275, 14347, 14347, 15275, 15275, -2819, -2819, -2819,  2636,   654,
    2661,  2668,  2663,  2664,  2671,  2666,  2672,  2677,  2675,  2676,
    2678,  2683,  2679,  2680,   427,  2681,  2682,  2689,  2597,   655,
    2684,  2685,  2686,   675,   676,   677,   678,  2687,  2688,  2690,
    2691,  2695,   430,   679,   354,  2692,  2693,  2694,  2696,   680,
    2697,  2698,  2699,  2700,  2701,  2702,  2709,  2704,  2705,  2706,
    2707,  2708,  2710,  2711,  2715,  2718,  2719,  2720,  2716,  2717,
    2721,  2722,  2723,  2724,  2725,  2726,  2727,  2735,  2730,  2448,
    2729,  2732,  2739,  2734,  2741,  2736,  2743, -2819,  2738,  2745,
    2740,  2747,  2742,  2749,   704,  2750,  2746,  2748,  2751,  2752,
     706,  2753,  2755,  2756,    74,  2754,  2757,  2758,  2761,  2762,
    2759,  2760,  2767,  2768,  2769,  2770,  2771,  2772,  2773,  2774,
    2775,  2776,  2777,  2778,  2779,  2780,  2781,  2782,  2783,  2784,
    2785,  2786,  2792,  2793,  2788,  2795,  2790,  2791,  2794,  2798,
    2799, -2819, -2819, 15275, 15275, -2819, 15275, 15275, -2819, 15275,
   15275, -2819, 15275, 15275, 15275, -2819, 15275, 15275, -2819,   110,
   15275, -2819, -2819,   110,  2498, 15275, 15275, -2819, 15275, -2819,
   15275, -2819, 15275, -2819, 15275, 15275, 15275, 15275, 15275, -2819,
   -2819, -2819, 15275, 15275, 15275, 15275, 15275, 15275, -2819, 15601,
   15601, 15601, 15275, 15275, 15275, 15275, -2819, 15275, 15275, 15275,
   15275, 15275,    71, 15275, -2819, -2819, -2819, -2819, 15275, 15275,
   -2819, 15275, 15275, 15275, 15275, 15275, 15275, -2819, 15275, 15275,
   15275, 15275, -2819, 15275, -2819,  1563, -2819, 15275, -2819, 15275,
   -2819, 15275, -2819, -2819, 15275, -2819, 15275, 15275, -2819, 15275,
   -2819, 14347,    71, -2819, -2819, -2819, 15275,    71, 15275, -2819,
   -2819, 15275, 15275, -2819, -2819, -2819, -2819, -2819, -2819, -2819,
   -2819, -2819, -2819, -2819, -2819, -2819, -2819, 15275, 15275, 15275,
   15275, 15275, -2819, -2819, -2819, 14347, -2819, 15275, 15275, 15275,
   -2819, -2819,  2796,  2801,  2803,  2800,  2802,  2804,  2805,  2807,
    2809,  2806,   727,  2808,  2810,  2811,   747,  2812,  2815,   751,
     752,  2818,  2821,  2825,  2828,  2829,  2813,  2831,  2832,  2833,
    2834,  2837,  2839,   697,  2817,   780,  2847,  2841,  2855,  2850,
    2851,  2858,  2866,  2872,  2874,  2875,  2876,  2877,   754,  2880,
    2893,   759,  2898,  2900,  2901,  2896,  2902,  2903,  2904,  2909,
    2908,  2906,  2917,  2918,  2919,   761,  2915,  2923,  2925,  2920,
    2924,  2929,  2926,  2927,  2928,  2930,  2931,  2935,  2937,  2932,
    2934,  2941,  2936,  2942,  2943,  2944,  2945, 15275, -2819, -2819,
   15275, 15275, 15275, -2819, -2819, -2819, 15275, -2819, 15275, 15275,
    1563, -2819, -2819,   110, 15275, 15275, -2819, 15275, -2819, 15275,
   15275, 15275, 15275, 15275, 15275, -2819, 15275, 15275, 15275, 15275,
   15275, 15275, 15601, -2819, 15601, -2819, -2819, 15601, 15601, 15275,
   15275, 15275,    71,    71,    71,    71, -2819, 15275, 15275, -2819,
   -2819, 15275, -2819, -2819, -2819, 15275, 15275, 15275, -2819, -2819,
   15275, -2819, -2819, -2819, -2819, -2819, 15275, 15275, -2819, -2819,
   15275, 15275, -2819,    71, 15275,    71, 15275, 15275, -2819, -2819,
   15275, 15275, -2819, 15275, 14347, 15275, 15275, 15275,  2952,  2950,
    2951,  2953,  2954,  2958,  2955,  2956,  2963,  2964,  2959,  2966,
    2967,  2968,  2969,  2970,  2971,  2972,   762,  2973,  2974,  2975,
    2976,  2977,  2979,  2981,  2982,  2984,  2980,  2985,  2987,  2988,
    2989,  2986,  2990,  2991,  2992,  2993,  2994,  2995,  2996,  2997,
    2998,  2999,  3000,  3001,  3002,  3003,  3004,  3005,  3012,  3007,
    3008,  3009,   764,  3010,  3011,  3013, -2819, 15275, 15275, 15275,
   15275, -2819, 15275, 15275, -2819, -2819, 15275, -2819, -2819, -2819,
   -2819, -2819, -2819, 15275, -2819, 15275, -2819, 15275, -2819, -2819,
   15275, -2819, -2819, -2819, -2819, 15601, -2819, -2819, -2819, -2819,
   15275, 15275, -2819, 15275, -2819, 15275, -2819, 15275, 15275, 15275,
   -2819, 15275, 15275,    71, 15275,    71, 15275,  2461, 15275, 15275,
   15275, -2819, 14347, 15275, 15275, 15275,  3018,  3020,  3015,  3022,
      53,  3017,  3019,  3021,  3024,  3026,  3028,  3023,  3030,  3025,
    3027,  3032,  3029,  3031, -2819,  3034,   785,  3033,   787,  3035,
    3036,  3038, 14347,  3039,  3043,   790,  3044,  3040,   797,  3045,
   -2819, -2819, 15275, -2819, -2819,  1563, 15275, 15275, -2819, -2819,
   -2819, 15275, -2819, 15275, 15275, -2819, 15275, 15275, -2819, -2819,
   14347, 15275, -2819, 14347, 15275, 15275, 15275, -2819, 15275, 15275,
   -2819, 15275, 15275, -2819, -2819, 15275, 15275,  3047,  3056,  3057,
    3058,  3059,  3062,  3065,  3073,  3075,  3064,  3082,  3088,  3083,
    3084,  3085,  3092,  3089,  3090,  3098,   799,   808, 15275, -2819,
   -2819, -2819, -2819, -2819, 15275, 15275, 15275, -2819, -2819, -2819,
   15275, 15275,    71, -2819, 15275, 15275, -2819, -2819, 15275, -2819,
   14347,  3093,  3094,  3104,  3099,  3107,  3102,  3103,  3110,  3105,
    3114,  3109, 15275, 15275, -2819, 15275, -2819, 15275,    71, -2819,
   15275, -2819, 14347,  3112,  3119,  3115,  3118,  3122,  3125,  3130,
   15275, -2819, 15275, 15275, 15275, -2819, -2819,  3128,  3129,  3131,
    3136, 15275, 15275, 15275, -2819,  3132,  3133,  3135, 15275, 15275,
   15275,  3142,  3137,  3138, -2819, 15275, 15275,  3139,  3146, 15275,
   -2819,  3147, -2819
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  Parser::yydefact_[] =
  {
         2,   509,     0,     0,     0,     0,    21,    74,    75,    76,
      77,     0,     0,     0,   398,   407,    39,    20,     0,   109,
      81,     0,     0,     0,     0,     0,     0,     0,   108,     0,
       0,   388,   406,   859,   556,   410,   411,   412,   389,     0,
     819,     0,   775,     0,   868,   869,   870,   871,   872,   873,
       0,     0,   878,   879,     0,     0,    41,    44,    42,    43,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   320,
     394,   321,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    85,     0,     0,   545,   546,   547,   548,   549,
     550,   551,   552,   553,   554,     0,     0,     0,   408,   409,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   404,    40,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   347,   348,
     349,   350,   351,   352,   353,     0,     0,   510,     0,     0,
       4,     8,    10,    14,    16,    18,    12,     0,   390,   399,
     402,     0,   414,   491,   511,     0,   513,   517,   520,   521,
     526,   531,   533,   535,   537,   539,   541,   543,   544,   313,
     485,     0,   777,   779,   780,   798,   799,   803,   808,   809,
     810,   811,   812,   813,   814,   815,   816,   817,   818,   121,
       0,     0,     0,     0,     0,     0,   410,   411,   412,     0,
     819,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   493,     0,     0,   775,   495,   783,   494,
     782,   389,     0,   485,     0,     0,     0,     0,     0,   102,
      82,    84,   114,   112,   113,   111,   110,    83,   117,   124,
     119,   118,   125,   120,     0,     0,     0,   107,     0,     0,
      92,    93,     0,    95,    96,     0,    99,   100,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   360,   360,
      38,    33,   426,     0,     0,     0,     0,     0,   861,   860,
     862,   874,   864,   865,   866,   875,   867,   869,   871,   872,
     873,   877,   876,   878,   879,   863,   104,   105,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   496,   785,   497,   786,
     502,   791,   503,   792,   504,   793,   505,   794,   506,   795,
     508,   797,   507,   796,   498,   787,   499,   788,   500,   789,
     501,   790,     0,    25,     0,   404,    35,     0,    36,     0,
       0,     0,    30,    28,   404,     0,     0,     0,     0,     0,
       0,     1,     3,     5,     9,    11,    15,    17,    19,    13,
       0,     6,     0,     0,     0,     0,   492,   781,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     784,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     413,     0,     0,   778,     0,     0,     0,     0,     0,     0,
     878,     0,     0,    94,    97,    98,   101,     0,     0,     0,
       0,     0,     0,   452,   453,   450,   451,   448,   449,   454,
     455,   456,     0,     0,     0,   128,     0,     0,     0,     0,
     135,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   280,     0,     0,     0,
       0,   285,   286,     0,   269,     0,   277,     0,     0,     0,
       0,     0,   266,   267,     0,    56,    57,     0,     0,   123,
       0,     0,    73,     0,     0,     0,     0,     0,   566,     0,
     375,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,   363,     0,   361,   570,   706,   708,
     709,   727,   729,   735,   736,   741,   742,   751,   756,   758,
     759,   761,   763,   765,   767,   769,   369,     0,     0,   332,
       0,   325,     0,   326,   479,   323,     0,     0,     0,     0,
     330,   331,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   327,   328,   329,   333,     0,
       0,     0,   334,   345,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   570,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   177,   178,
       0,     0,   457,   458,     0,     0,     0,     0,     0,     0,
       0,     0,   459,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   216,   217,   179,   180,   181,   182,     0,     0,
     570,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   775,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   405,     0,    34,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
     400,   401,   529,   530,   514,   515,   516,   518,   519,   523,
     522,   524,   525,   527,   528,   532,   534,   536,   538,     0,
     540,     0,     0,     0,   395,     0,   423,   425,     0,   219,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   555,
     424,    87,    88,    86,   800,   802,   801,   804,   806,   805,
     807,   427,   428,   429,     0,     0,     0,   489,     0,   253,
       0,   248,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   247,     0,
     239,     0,   249,   250,     0,     0,     0,     0,     0,   258,
     260,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   833,     0,
       0,     0,     0,     0,   836,    61,     0,    51,     0,     0,
       0,   566,     0,     0,     0,   770,    59,     0,   833,     0,
     546,   549,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    69,     0,    67,    50,
      55,    54,   836,    60,     0,     0,     0,     0,     0,   512,
       0,    79,    80,     0,     0,   396,   397,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   115,   122,   116,
       0,     0,     0,   570,   727,   712,   711,   485,     0,   365,
     367,   371,   373,     0,   558,     0,     0,     0,   360,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   713,   714,   719,   720,   721,   722,
     723,   725,   724,   715,   716,   717,   718,   726,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     356,     0,   710,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   346,   820,     0,
     557,     0,    45,     0,     0,   570,     0,     0,     0,     0,
       0,   435,     0,     0,   437,     0,   438,   439,     0,   440,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   431,     0,   436,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   314,
     315,     0,     0,   433,     0,   776,   447,     0,   317,     0,
     404,   358,   403,   404,    26,   482,   483,   484,   319,   377,
     377,    32,     0,   261,     0,     0,     0,     0,     0,   415,
       0,     0,     0,     0,     0,     0,   218,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   222,     0,     0,   223,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   831,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   360,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   820,   557,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   707,     0,     0,
       0,     0,   656,   654,   655,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   625,   626,     0,     0,     0,     0,   629,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   376,   364,   362,
     370,     0,     0,   883,     0,   882,     0,   768,   734,   730,
     732,   731,   733,   737,   739,   738,   740,   748,   744,   747,
     743,   749,   745,   750,   746,   754,   752,   755,   753,   757,
     760,   762,     0,   764,     0,     0,     0,     0,     0,    37,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   106,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   542,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   830,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   771,     0,     0,     0,
       0,     0,     0,     0,    70,    68,     0,     0,   393,   392,
     391,     0,     0,     0,     0,     0,   151,     0,   154,     0,
     127,   130,   129,     0,     0,     0,     0,     0,   138,   139,
       0,     0,     0,     0,   144,     0,   153,     0,   270,     0,
     265,   272,     0,     0,     0,     0,   268,     0,   278,     0,
     273,     0,     0,     0,   276,   460,   486,   487,   488,     0,
       0,   728,   559,     0,     0,     0,   565,     0,     0,     0,
       0,   605,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   606,     0,     0,     0,     0,     0,
       0,     0,     0,   637,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   590,   591,   592,     0,   594,     0,     0,
       0,     0,     0,   601,     0,     0,     0,     0,     0,     0,
       0,     0,   608,     0,     0,     0,     0,     0,     0,   563,
     564,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   681,   586,   588,   650,   651,   652,
     653,     0,     0,     0,   685,     0,     0,     0,     0,     0,
       0,   697,     0,   699,     0,     0,   701,   702,   366,   368,
     372,   374,   682,     0,   571,     0,   612,     0,     0,     0,
       0,     0,     0,   480,   481,   478,     0,     0,     0,     0,
     467,     0,   472,     0,     0,     0,     0,     0,     0,     0,
     337,   339,     0,     0,   477,     0,     0,     0,   335,    58,
      62,    53,    46,     0,   490,     0,     0,     0,   311,     0,
     165,     0,   164,     0,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   185,   186,   187,     0,   200,   201,
       0,   203,   211,   205,   206,   212,   207,   213,   209,   210,
     208,   188,     0,   198,     0,   189,   214,   215,   194,     0,
     190,   191,   192,   193,   196,     0,   430,   446,     0,     0,
       0,   293,     0,     0,     0,   300,     0,     0,     0,     0,
       0,     0,   774,     0,   404,   359,    24,    27,   380,   381,
     382,   378,   379,   404,     0,   404,     0,     0,   344,     0,
       0,   416,     0,     0,     0,   422,    90,    89,   162,   161,
       0,   220,   221,     0,   307,     0,   309,   310,   157,     0,
       0,     0,   155,     0,   240,   245,   251,   252,   255,     0,
     254,   224,     0,   236,     0,   232,     0,     0,     0,   228,
     229,   230,   231,   237,   246,   238,   241,     0,     0,   234,
     244,     0,   259,   263,   837,   838,     0,     0,     0,     0,
       0,     0,   834,     0,     0,     0,   825,     0,     0,     0,
       0,     0,   832,   847,     0,     0,     0,     0,     0,     0,
      48,    49,   773,    52,   322,    47,     0,    65,    63,     0,
     103,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,   766,     0,     0,   691,   693,   694,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     441,   442,   443,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   445,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    78,     0,   146,     0,   149,     0,
     152,     0,   133,   131,   134,   136,     0,     0,   141,     0,
       0,     0,     0,   271,     0,     0,     0,     0,   279,   274,
     287,     0,   461,    72,     0,     0,   577,   578,     0,     0,
       0,   604,   607,   609,   610,     0,   611,     0,     0,     0,
       0,     0,     0,     0,     0,   630,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     589,     0,     0,     0,     0,     0,     0,   602,   603,     0,
     572,   573,   574,     0,     0,   657,   658,   659,   660,     0,
     705,   666,     0,     0,     0,   671,   672,   673,   674,   675,
     676,   677,   678,     0,     0,     0,     0,     0,   686,     0,
       0,   687,     0,     0,   696,   698,   700,     0,     0,   692,
     695,   324,     0,     0,     0,     0,   466,   468,   471,   470,
     473,   469,   474,     0,   475,   336,   340,     0,   341,   342,
     343,     0,   312,     0,   176,   199,     0,     0,   202,     0,
       0,   288,     0,   290,     0,   295,     0,   294,     0,     0,
       0,     0,     0,     0,     0,     0,   316,   404,    22,    31,
     385,   386,   387,   383,   384,    29,   357,     0,     0,     0,
     417,     0,     0,   421,     0,     0,     0,     0,     0,     0,
       0,     0,   256,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   840,     0,     0,     0,     0,   835,   821,     0,
     822,   826,   827,   828,   829,     0,   848,     0,     0,     0,
       0,     0,     0,     0,     0,    66,    64,    71,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   485,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   444,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   145,   147,     0,     0,   126,     0,     0,   143,     0,
       0,   264,     0,     0,     0,   284,     0,     0,   569,     0,
       0,   579,   580,     0,     0,     0,     0,   616,     0,   619,
       0,   621,     0,   623,     0,     0,     0,     0,     0,   627,
     628,   661,     0,     0,     0,     0,     0,     0,   638,     0,
       0,     0,     0,     0,     0,     0,   648,     0,     0,     0,
       0,     0,     0,     0,   575,   576,   704,   667,     0,     0,
     679,     0,     0,     0,     0,     0,     0,   690,     0,     0,
       0,     0,   462,     0,   464,     0,   338,     0,   204,     0,
     195,     0,   289,   291,     0,   296,     0,     0,   305,     0,
     304,     0,     0,   432,   434,    23,     0,     0,     0,   419,
     420,     0,     0,   306,   308,   158,   159,   418,   156,   233,
     235,   225,   226,   227,   242,   243,   257,     0,     0,     0,
       0,     0,   823,   824,   849,     0,   850,     0,     0,     0,
     846,   772,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     881,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   150,   137,
       0,     0,     0,   281,   282,   283,     0,   567,     0,     0,
       0,   581,   582,     0,     0,     0,   615,     0,   618,     0,
       0,     0,     0,     0,     0,   587,     0,     0,     0,     0,
       0,     0,     0,   639,     0,   641,   643,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   599,     0,     0,   668,
     669,     0,   680,   683,   684,     0,     0,     0,   585,   613,
       0,   463,   465,   476,   163,   183,     0,     0,   292,   299,
       0,     0,   303,     0,     0,     0,     0,     0,   160,   839,
       0,     0,   843,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   148,     0,     0,     0,
       0,   568,     0,     0,   583,   584,     0,   617,   620,   622,
     624,   631,   634,     0,   663,     0,   665,     0,   632,   635,
       0,   640,   642,   644,   645,     0,   647,   593,   595,   596,
       0,     0,   600,     0,   670,     0,   688,     0,     0,     0,
     197,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   851,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   880,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     140,   142,     0,   275,   561,     0,     0,     0,   633,   664,
     662,     0,   646,     0,     0,   649,     0,     0,   184,   297,
       0,     0,   302,     0,     0,     0,     0,    91,     0,     0,
     845,     0,     0,   856,   855,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   562,
     560,   614,   636,   597,     0,     0,     0,   298,   318,   301,
       0,     0,     0,   841,     0,     0,   852,   853,     0,   857,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   703,     0,   262,     0,     0,   842,
       0,   854,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   598,     0,     0,     0,   844,   858,     0,     0,     0,
       0,     0,     0,     0,   355,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   132,     0,     0,     0,     0,     0,
     354,     0,   689
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
     -2819, -2819, -2819,   -46,  2566,  2622,  2646, -2819, -2819,  2647,
    2648,  2649,  2650, -2819,  -285,   966, -2819,   454, -2819,  6962,
    -383, -2819, -2819, -2819, -2819,  -448,  4981,   566,  -414, -2819,
    -399,   435,  1941,  2002,  1993,  2513,  2574,  2396,  1363, -2819,
       0,    81,  3416, -2819, -2819, -2819,  -525,  -134,  -361, -2819,
   -2819,  -375,  -359,  1501, -2819,  1502,  1500,  1526,  1578,   949,
    1763,  7043,  1937, -2819, -2819, -2819, -2819,   638,   451, -2819,
   -2819, -2819, -2819, -2819, -2819, -2819, -2819, -2819, -2819, -2819,
      17,  5956,  -445,    12,     2, -2818
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,   148,   149,   150,   151,   152,   153,   871,   870,   154,
     155,   156,   157,  1360,   663,  1777,   158,   159,   160,   161,
     383,   384,  1362,   162,   163,   164,   232,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     242,   180,   244,   668,   669,   670,   671,   672,   673,   674,
     675,   676,   677,   678,   679,   680,   681,   682,   683,   684,
     685,  1098,  1030,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     245,   235,   995,   920,   202,  1636
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int Parser::yytable_ninf_ = -876;
  const short int
  Parser::yytable_[] =
  {
       179,   290,   864,  1033,   688,     6,   904,   887,   888,   861,
     723,   872,   201,  1039,   904,    33,    17,   199,    14,  1094,
    1094,    33,   259,   262,   889,   890,   891,   892,    34,   927,
     929,   256,    25,    26,   210,   441,   210,    29,    30,   260,
    1002,    31,  1547,  1547,  1460,    34,   215,   216,   215,   241,
     295,   537,   538,  1541,  1542,  2598,   316,   423,   424,  1378,
     291,  3004,  3006,  3008,   216,  1231,  1232,  3304,  1504,   433,
     435,    33,   436,  2037,   903,   904,   437,   284,  1005,  1240,
    -874,   386,    33,  -875,  1523,  1524,   243,   286,   445,   447,
     931,   932,   933,   210,   931,   932,   933,     6,   281,   931,
     932,   933,  1280,   403,  1224,   215,   246,  2592,    17,  1336,
     448,   411,  1094,  1094,  1094,  1094,  1094,  1094,  1094,  1094,
    1094,  1094,  1094,  1094,  1094,  1094,   385,     1,  -861,    34,
     839,   840,  1852,   841,  2594,   382,    34,  -860,  1856,    33,
    1094,  1479,   937,  1664,   393,   394,   937,  1664,   216,   179,
    2284,   937,   247,   392,    34,   216,   457,  1353,   296,   248,
      70,   201,   462,  1379,   414,   415,   199,   782,    34,  1380,
      34,   442,  1382,   216,   434,  1548,  1548,   265,   906,  -862,
     438,   414,   415,   905,   906,   434,   842,   216,  1241,   216,
     425,   426,   446,   414,   415,  1241,   907,  1513,  1233,  1234,
    1514,   439,   907,   282,   283,   279,  1094,  1094,   285,   724,
    1549,  1549,   287,  1094,  1094,  1094,  1094,  1094,  1094,  1094,
    1094,  1094,  1094,  1094,  1094,  1094,  1094,   414,   415,   772,
     773,   266,  1664,  1665,  1666,  1667,  1668,  1665,  1666,  1667,
    1668,   268,   270,   271,   269,   906,    34,   465,   973,   974,
     975,   273,   274,   272,   414,   415,   280,   976,   977,   978,
     979,   288,   275,   907,   980,   216,   908,   909,   910,   911,
     471,   472,   473,    34,  3172,   474,  3173,   292,   475,  3174,
    3175,  2161,   293,  1727,   534,   535,   243,  2162,   666,   666,
    2163,   289,   216,   276,   277,   725,   294,   727,   912,   913,
     914,     6,   536,  2719,   278,   981,   297,    34,   982,   983,
     984,   985,    17,   986,   987,   418,   419,   988,   729,   730,
     420,   756,  1665,  1666,  1667,  1668,   216,   483,   484,   485,
     486,   487,   488,   489,   490,   491,  1379,    34,  1099,  1100,
     862,   865,  1380,   210,  1381,  1382,   457,   833,   834,   318,
     836,   838,   462,  1872,   319,   215,   216,   457,  2174,  1730,
      34,  2028,  2029,   462,   879,   320,   210,   457,   252,   857,
     917,    33,  1522,   462,  2873,   321,   917,   322,   215,   216,
     329,  2650,   253,   254,   255,   323,  1732,  2651,   457,  2176,
    2652,   867,   414,   415,   462,   873,   328,  1223,   919,  1224,
     919,   866,  1223,   462,  1224,  1009,   919,  1280,   458,  1224,
    1095,  1096,   457,  1699,   324,   330,   325,  3278,   458,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   331,
    1226,   915,   916,  1227,  1228,   901,   902,   917,   332,   922,
     457,  2848,   333,   457,  2870,   457,   462,   334,  1028,   462,
     918,   462,   249,  1035,  1036,   337,  1123,  1037,   539,   540,
     541,   542,  1124,  1363,  1220,  1031,  1243,   919,   338,  1123,
    1221,   339,  1221,  1094,  1094,  1278,  1898,   989,   990,   991,
    1908,  1926,  1899,   992,   340,   993,  1909,  1221,  1094,  1094,
    1094,  1094,  1094,  1094,  1094,  1094,  1094,  1094,  1094,  1094,
    1094,   341,  1094,  1194,  1195,  1196,  1197,  1198,  1199,  1200,
    1201,  1202,  1203,  1204,  1205,  1206,  1207,   427,   428,  1284,
    1973,  2014,  2021,    93,    94,  1927,  1974,  2015,  2022,  2023,
    2034,  1222,  2050,  2052,  2061,  2024,  2035,  1088,  2051,  2053,
    2062,   342,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   483,   484,   485,   486,   487,   488,   489,   490,
     491,  2078,   326,   343,   327,  2082,  2131,  2079,   233,   237,
     239,  2083,  2132,   412,   413,   843,   844,   845,   846,   847,
     848,   421,   422,   849,   850,   851,   852,   853,   854,   855,
    2153,   814,   815,  2155,  2169,  2178,  2154,  1095,  1096,  2154,
    2170,  2179,  1103,   344,  1194,  1195,  1196,  1197,  1198,  1199,
    1200,  1201,  1202,  1203,  1204,  1205,  1206,  1222,  2182,  2188,
      14,   443,   444,  2193,  2183,  2189,  2215,  1097,  1497,  2194,
    2222,  2226,  2216,   345,    25,    26,  2223,  2227,  2233,    29,
      30,   238,   240,    31,  2234,   401,  2243,    34,  2392,  2507,
     147,   241,  1221,  2572,  2393,  2508,  2621,  2623,  2625,  2573,
     430,  2678,  2622,  2624,  2626,  2686,   216,  2679,  2832,  2852,
     335,  2687,   336,   346,  2833,  2853,   356,   358,   360,   362,
     364,   366,   368,   370,   372,   374,   376,   378,   380,  2857,
    2859,  2861,  2863,  2871,  2878,  2858,  2860,  2862,  2864,  2872,
    2879,  1094,  1094,  1094,  1094,  1094,  1094,  1094,  1094,  1094,
    1094,  1094,  1094,  1094,  1094,  1094,  1094,  3092,  2923,  2035,
    2930,   690,   347,   692,  2924,   694,  2931,   696,  1271,   698,
     699,   416,   348,   702,   703,   704,   705,   706,   707,   708,
     709,  3067,  1109,   349,   322,   714,   350,  3068,   357,   359,
     361,   363,   365,   367,   369,   371,   373,   375,   377,   379,
     381,  3072,    70,   816,   817,  3076,  3078,  3073,  3106,   237,
     239,  3077,  3079,  3110,  3107,  3125,  3224,   429,  3261,  3111,
     351,  3126,  3225,   352,  3262,   356,   358,   360,   362,   364,
     366,   368,   370,   372,   374,   376,   378,   380,   416,  3319,
    3094,  3322,  2035,   417,  3330,  3320,  1103,  3323,  1450,   353,
    3331,  3334,   431,  3377,  1274,  1643,  1645,  3335,  1364,  3378,
     540,   541,  3379,  1525,    14,  1280,  1371,  1224,  3380,   772,
     773,   354,  1647,  1649,  1651,  1653,  1655,  1657,    25,    26,
    1229,  1230,   355,    29,    30,  1235,  1236,    31,   689,  1523,
    1524,    34,  1541,  1542,   389,   241,  1648,  1650,  1652,  1654,
     390,  1359,   893,   894,  1095,  1096,   880,   881,  1644,  1646,
     216,  1772,  1773,  1774,  1775,  1776,  1656,  1658,   391,  1194,
    1195,  1196,  1197,  1198,  1199,  1200,  1201,  1202,  1203,  1204,
    1205,  1206,   765,  1222,   928,   930,   395,   690,   691,   692,
     693,   694,   695,   696,   697,   698,   699,   700,   701,   702,
     703,   704,   705,   706,   707,   708,   709,   710,   711,   712,
     713,   714,   715,   716,   717,   718,   719,   720,   721,   396,
    1441,   397,  1455,  2420,  2421,  2422,  2423,  2424,   398,   399,
     400,   432,   449,   440,   766,   767,   768,   769,    14,   450,
     770,   771,   772,   773,   774,   775,   776,   777,   778,   779,
     780,   781,    25,    26,   284,   451,    70,    29,    30,   452,
     453,    31,   454,   455,   460,    34,   728,  1770,   456,   241,
    1771,   459,  1441,   467,   884,   885,   886,   461,   463,   831,
     543,  1921,   832,   726,   216,   863,   869,   875,   782,  1034,
      14,   931,   932,   933,   934,  1040,  1041,   924,  1042,  1043,
    1044,  1045,  1046,   904,    25,    26,  1047,  1048,  1049,    29,
      30,  1050,  1051,    31,  1052,  1053,  1054,    34,  1055,  1056,
    1057,   241,  1058,  1059,   935,  1060,  1061,  1062,  1063,  1064,
    1065,  1066,   936,  1067,  1468,  1068,   216,  1469,  1471,  1472,
    1473,  1474,  1475,   937,  1477,  1478,  1069,   938,  1070,  1483,
    1484,  1485,  1486,  1487,  1488,  1489,  1071,  1491,  1039,  1493,
    1072,  1495,  1496,  1073,  1498,  1499,  1500,  1501,  1502,   925,
     926,  1097,  1074,  1508,  1509,  1510,  1511,  1075,  1076,  1077,
      70,  1078,  1638,  1640,  1642,  1079,  1080,  1081,  1082,  1083,
     939,  1084,   940,   941,   942,  1521,  1085,  1086,   666,   756,
     237,   239,  1090,   943,   944,  1091,  1092,  1105,  1237,   945,
     946,   947,   948,  1108,  1106,  1107,  1110,  1111,  1112,  1113,
    1114,  1115,  1116,  1117,   949,   950,   951,   952,   953,  1118,
     954,   955,    70,   956,  1129,  1119,  1120,  1121,   957,   958,
     959,   960,   961,   962,   963,   964,   965,   966,   967,   968,
     969,   970,   971,     6,  1122,  1125,  1126,  1127,  1857,  1128,
    1130,    14,  1131,  1921,    17,  1132,  1135,  1133,  1136,  1134,
    1137,  1138,  1139,  1140,  1519,    25,    26,  1141,  1142,  1143,
      29,    30,  1144,  1145,    31,  1146,  1147,  1669,    34,  1148,
    1149,  1150,   241,   356,   358,   360,   362,   364,   366,   368,
     370,   372,   374,   376,   378,   380,   722,   216,  1151,  1152,
    1153,  1629,  1154,  1037,  1634,  1155,  1156,  1157,  1158,  1159,
    1160,   416,  1161,  1162,  1163,  1164,  1165,  1166,  1167,  1168,
    1169,  1170,  1171,  1172,  1173,  1174,  1175,  1673,  2069,  1176,
    1177,  1178,  1179,  1679,  1180,  1181,  1182,  1183,  1684,  1184,
    1686,  1687,  1185,  1689,  1690,  1691,  1692,  1186,  1187,  1694,
    1188,  1189,  1190,   972,  1191,  1192,  1193,  1208,  1209,  1210,
    1211,  1212,  1213,  1701,  1215,  1216,  1217,  1218,  1219,  1214,
    1225,  1239,  1706,  1268,  1708,  1709,  1710,  1238,  1244,  1242,
    1245,  1715,  1716,  1717,  1718,  1719,  1720,  1721,  1246,  1723,
    1247,  1248,  1249,    70,  1250,  1251,  1252,  1253,  1254,  1736,
    1737,  1738,  1739,  1740,  1741,  1742,  1743,  1744,  1745,  1746,
    1747,  1748,  1749,  1750,  1255,  1256,  1257,  1258,  1259,  1754,
    1755,  1756,  1757,  1758,  1759,  1760,  1260,  1261,  1262,  1263,
    1264,  1764,  1765,  1265,  1766,  1266,  1269,  1276,  1272,  1270,
    1277,  1492,  1481,  1281,  1292,  1273,  1283,  1279,  1284,  1282,
    1286,  1285,  1779,  1287,  1780,  1289,  1288,  1291,  1290,  1293,
    1785,  1786,  1787,  1294,  1295,  1296,  1297,  1298,  1299,  1793,
    1795,  1797,  1798,  1799,  1800,  1801,  1300,  1802,  1803,  1301,
    1804,  1805,  1806,  1807,  1808,  1809,  1302,  1811,  1812,  1813,
    1814,  1815,  1816,  1817,  1818,  1303,  1304,  1821,  1305,  1823,
    1824,  1306,  1826,  1827,  1828,  1307,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,  1308,  1309,  1310,  1311,  1312,  1313,  1314,  1315,  1853,
    1854,  1316,  1317,   666,  1318,  1859,  1319,  1861,  1862,  1320,
    1321,  1322,  1323,  1324,  1325,  1326,  1327,  1869,  1335,  1482,
    1328,  1329,  1330,  1331,  1332,  1333,  1369,   238,   240,  1337,
    1338,   357,   359,   361,   363,   365,   367,   369,   371,   373,
     375,   377,   379,   381,   417,  1334,  1339,  1340,  1341,  1342,
    1343,  1344,  1345,  1346,  1347,  1348,  1349,   492,  1350,  1351,
    1352,  1354,  1094,    33,    34,   298,   299,   300,   301,   302,
     303,   304,   305,   306,    44,   307,    46,   308,   309,   310,
     311,   312,   470,   314,  1355,  1356,  1357,  1358,   493,   494,
     495,   496,   497,  1365,   498,   499,   500,   501,   502,   503,
     504,   505,   506,   507,   508,   509,  1366,  1367,  1368,  1370,
    1372,  1373,  1506,  1507,   237,   239,  1384,  1385,  1374,  1375,
    1376,  1377,  1383,  1387,  1448,  1845,  1452,  1388,  1389,   356,
     358,   360,   362,   364,   366,   368,   370,   372,   374,   376,
     378,   380,    14,   416,    14,  1390,  1391,  1392,  1393,  1394,
    1395,  1397,  1398,  1400,  1401,  1402,    25,    26,    25,    26,
    1403,    29,    30,    29,    30,    31,  1404,    31,  1405,    34,
    1406,    34,  1407,   241,  1408,   241,  1409,  1410,  1411,  1412,
    1413,  1414,   510,  1415,  1416,  1417,   238,   240,   216,  1418,
     216,  1419,  1420,     1,  1421,     2,     3,     4,  1422,     5,
     511,   357,   359,   361,   363,   365,   367,   369,   371,   373,
     375,   377,   379,   381,  1423,   417,  1424,    14,    15,  1425,
    1426,  1427,  1428,  1429,  1430,  1431,  1432,  1433,  1434,  1435,
    1436,    25,    26,  1437,  1438,  1439,    29,    30,  1440,  1443,
      31,  1444,    32,  1445,    34,   206,   207,   208,   241,   209,
     210,  1446,   236,   212,  1447,  1449,  1451,  1453,  1454,   213,
     214,  1456,   215,   216,  1457,  1458,  1459,  1461,  1462,  1463,
    1464,  1465,  1467,  1494,  2146,  2147,  1516,  1517,  1553,  1554,
    1677,  1696,  1674,  1698,    70,  1522,    70,    34,   298,   299,
     300,   301,   302,   303,   304,   305,   306,    44,   307,    46,
     308,   309,   310,   311,   312,   313,   314,  1620,  1680,  1702,
    1675,  2418,  1703,  1685,  1704,  1753,  1768,  1678,  2144,  1693,
    2419,  1681,  2425,  1682,  1695,  1769,  1788,  1867,  1852,  1697,
    1870,    62,    63,    64,    65,    66,  1946,  1871,  2166,  1860,
    1873,  1874,  1875,  1639,  1641,  1876,  1877,  1878,  1879,  1880,
    1881,   217,  1882,   512,  1883,   513,  1907,   514,   515,    70,
    1884,   218,  1885,  1886,  1887,   516,  1888,  1889,   517,   518,
     519,   520,   521,   522,   523,   524,    34,   298,   299,   300,
     301,   302,   303,   304,   305,   306,    44,   307,    46,   308,
     309,   310,   311,   312,   470,   314,  1890,  1891,  1892,  1893,
    1894,  1895,  1896,  1897,  1900,  1901,   525,  1902,  1906,  1903,
     526,    75,  1904,  1905,  1910,   527,   528,  1911,  1912,  1913,
    1914,  1915,  2253,  2254,  2255,  2256,   529,  2257,  1916,  2258,
    1917,   530,   531,  1918,  1922,  2261,  2262,  2263,  1919,  1931,
    2264,  2265,  2266,  2267,    76,  2268,    77,  2269,  1923,  2270,
    1924,  2036,  2271,  2272,  2273,  2274,  1925,  1928,  1929,  2275,
    1930,  1932,  2277,  1933,  1934,  1935,  1936,  1937,  1938,  1939,
    1940,  1941,  1942,  2281,  1943,  2282,  1944,  1945,  1947,  2286,
    2287,  1948,  2288,  2289,  2290,  2291,  2292,  2293,  2294,  2295,
    2296,  2297,  2298,  2299,  1949,  2300,  1950,  1951,  1952,  1954,
    1953,  1955,  1956,  1957,  2308,  2309,  2310,  2311,  2312,  2313,
    2314,  2315,  2316,  1958,  1959,  1960,  1961,    90,    91,  1962,
    1963,  1964,  1965,  1966,  1967,  1968,  2325,  2326,  2327,  2328,
    1982,  1969,  1970,  2331,  2332,  2333,  2334,  1971,  1972,  1975,
    1976,  1977,  1978,  2339,  2340,  2341,  2342,  2343,  2344,  2345,
    2346,  2347,  2348,  2349,  1979,  1980,  1981,  1983,  1984,  1985,
    1986,  2350,  2351,  2352,  1987,  2353,  2354,  1988,  2356,  2357,
    1989,  1990,  2359,  1991,  2360,  1992,  2279,  1856,  1993,  1994,
    1995,  1996,  1997,  1998,  1999,  2363,  2000,  2001,  2365,    93,
      94,  2002,  2003,  2004,  2005,  2006,  2370,  2372,  2374,  2007,
    2008,  2009,  2010,  2378,  2011,  2020,  2148,  2026,  2038,  2384,
    2012,  2013,  2385,  2386,  2016,  2387,  2388,  2389,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,  2017,   105,
    2018,  2395,  2019,  2396,  2025,  2027,  2032,  2033,  2039,   108,
     109,   110,   111,   112,   113,   114,   115,  2397,  2040,   116,
     117,   118,   119,   120,   121,   122,  2041,  2042,  2046,  2043,
    2044,  2045,  2399,  2060,  2400,  2064,  2068,  2280,  2047,  2401,
    2048,   129,   130,  2049,  2054,  2402,  2055,  2056,  2057,  2404,
    2405,  2058,  2406,  2408,  2409,  2059,  2410,  2411,  2063,  2065,
    2414,  2415,  2066,  2416,  2067,  2070,  2072,  1927,  2074,  2080,
    2081,  2084,  2085,  2086,  2087,  2088,  2426,  2427,   919,  2089,
    2429,  2090,  2430,  2431,  2432,  2091,   147,  2092,  2093,  2094,
    2433,  2095,  2096,  2434,  2098,  2435,  2097,  2099,  2101,  2436,
    2437,  2438,  2100,  2439,  2102,  2103,  2104,  2105,  2106,  2440,
    2107,  2108,  2441,  2109,  2442,  2110,  2443,  2444,  2445,  2111,
    2112,  2113,  2114,  2115,  2116,  2117,  2118,  2446,  2447,  2120,
    2121,  2448,  2122,  2119,  2123,  2124,  2449,  2450,  2451,  2452,
    2453,  2454,  2125,  2455,  2456,  2457,  2126,  2458,  2459,  2460,
    2461,  2462,  2127,  2129,  2463,  2464,  2465,  2466,  2135,  2469,
    2130,  2133,  2134,  2136,  2142,   782,   783,   784,   785,   786,
     787,   788,   789,   790,  2794,   791,   792,   793,   794,   795,
     796,   797,   798,   799,   800,   801,   802,   803,   804,   805,
     806,   807,   808,   809,   810,   811,  2137,  2138,  2139,  2502,
    2140,  2141,  2143,  2149,  2150,  2151,  2152,  2156,  2157,  2158,
    2159,   812,   813,  2160,  2164,  2165,  2168,  2171,  2172,  2173,
    2175,  2177,  2184,  2185,  2186,  2180,  2181,  2187,  2190,  2191,
    2195,  2192,  2196,  2199,  2200,  2201,  2202,  2197,  2198,  2203,
    2204,  2205,  2206,  2207,  2208,  2209,  2210,  2212,  2213,  2211,
    2214,  2417,  2362,  2640,  2375,  2217,  1778,  2218,  2219,  2220,
    2221,  2224,  2225,  2228,  2229,  2230,  2231,  2232,  2235,  2236,
    2237,  2238,  2239,  2240,  2241,  2242,  2244,  2654,  2247,  2245,
    2246,  2248,  2250,  2367,  2368,  2249,  2369,  2390,  2391,  2403,
     895,  2471,  2638,  2639,  2474,  2476,  2472,  2475,  2477,  2645,
    2478,  2480,  2479,  2481,  2482,  2483,  2473,  2484,  2485,  2486,
    2488,  2641,  2487,  2611,  2493,  2489,  2498,  2490,  2491,  2492,
    2499,  2494,  2470,  2495,  2496,  2497,  2500,  2501,  2503,  2504,
    2505,  2506,  2511,  2509,  2512,  2510,  2513,  2637,  2514,  2515,
    2516,  2517,  2642,  2518,   897,  2519,  2525,  2520,  2521,  2522,
    2523,  2524,   896,  2526,  2527,  2528,  2529,  2530,  2531,  2532,
    2533,  2534,  2535,  2536,  2537,  2538,  2539,  2540,  2541,  2542,
    2543,  2544,  2545,  2547,  2546,  2548,  2549,  2550,  2551,  2552,
    2553,  2555,  2554,  2556,  2557,  2558,  2559,  2560,  2561,  2565,
    2909,  2566,  2562,  2567,  2568,  2698,  2563,  2699,  2564,  2700,
    2569,  2701,  2570,  2571,  2574,  2575,  2702,  2703,  2578,  2704,
    2705,  2706,  2707,  2576,  2708,  2709,  2710,  2711,  2577,  2579,
    2580,  2712,  2581,  2582,  2713,  2715,  2583,  2584,  2585,  2586,
    2721,  2587,  2588,  2589,  2590,  2722,  2591,  2723,  2724,  2725,
    2726,  2727,  2728,  2729,  2730,  2593,  2731,  2733,  2735,  2736,
    2737,  2738,  2739,  2740,  2741,  2742,  2743,  2744,  2745,  2746,
    2595,  2747,  2596,  2597,  2599,  2600,  2601,  2602,  2604,  2753,
    2605,  2606,  2986,  2754,  2755,  2603,  2608,  2609,  2607,  2610,
    2612,  2613,  2614,  2758,  2759,  2615,  2618,  2616,  2627,  2617,
    2619,  2636,  2643,  2760,  2761,  2762,  2763,  2764,  2620,  2765,
    2766,  2628,  2767,  2768,  2629,  2630,  2716,  2769,  2770,  2717,
    2631,  2632,  2771,  2772,  2773,  2774,  2633,  2634,  2635,  2646,
    2647,  2644,  2648,  2649,  2653,  3292,  2655,  2776,  2656,  2657,
    2662,  2658,  2659,  2778,  2660,  2661,  1699,  2780,  2663,  2781,
    2782,  2664,  2665,  2666,  2667,  2668,  2669,  2670,  2671,  2787,
    2788,  2789,  2672,  2673,  2792,  2793,  2674,  2675,  2677,  2676,
    2680,  2681,  2682,  2683,  2684,  2685,  2697,  2795,  2777,  2797,
    2831,  2798,  2799,  2688,  2800,  2801,  2802,  2803,  2804,  2805,
    2806,  2807,  2689,  2808,  2809,  2810,  2811,  2812,  2813,  2814,
    2815,  2816,  2690,  2817,  2818,  2819,  2820,  2691,  2692,  2693,
    2694,  2834,  2835,  2836,  2837,  2838,  2839,  2823,  2824,  2825,
    2826,  2841,  2840,  2829,  2830,  2842,  2843,  2845,  2844,  2846,
    2847,  2849,  2850,  2851,  2854,  2855,  2856,  2865,  2866,  2869,
    2867,  2868,  2874,  2875,  2876,   404,  2877,  2880,  2881,  2882,
    2883,  2884,  2885,  2886,  2887,  2888,  2889,  2890,  2891,  2894,
    2892,  2893,  2895,  2896,  2897,  2900,  2898,  2899,  1659,  1661,
    1660,  1784,  2901,  2902,  2903,  2904,  2905,  2906,  2935,  2907,
    2908,  2910,  2911,  2912,  2913,  2914,  2915,  2916,  2917,  2918,
    2919,  2920,  2921,  2922,  2925,  2928,  2926,  1663,  2927,  2933,
    2934,   405,  2929,  2932,  2936,  2939,  2940,  2937,  2938,  2941,
    2942,  2943,  2944,  2945,  2946,  2947,  2948,  2949,  2950,  2951,
    2952,  2953,  2954,  2955,  2956,   406,   407,   408,   409,   410,
    2962,  2957,  2958,  2959,  2960,  2961,  2963,  2964,  2965,  2966,
    2967,  2968,  2970,  2971,  2969,  3058,  3057,  3059,  1662,  3063,
    3060,  3064,  3061,  3065,  3062,  3071,  3066,  3085,  3069,   899,
    3070,  3093,  3074,  2972,  2973,  3075,  2974,  2975,  3080,  2976,
    2977,  3081,  2978,  2979,  2980,  3082,  2981,  2982,  3083,  3084,
    2984,  3086,  3087,  3088,  3089,  2987,  2988,  3090,  2989,  3091,
    2990,  3095,  2991,  2035,  2992,  2993,  2994,  2995,  2996,  3096,
    3097,  3098,  2997,  2998,  2999,  3000,  3001,  3002,  3099,  3003,
    3005,  3007,  3009,  3010,  3011,  3012,  3100,  3013,  3014,  3015,
    3016,  3017,  3101,  3019,  3102,  3103,  3104,  3105,  3020,  3021,
    3108,  3022,  3023,  3024,  3025,  3026,  3027,  3109,  3028,  3029,
    3030,  3031,  3112,  3032,  3113,  3114,  3115,  3034,  3118,  3035,
    3121,  3036,  3116,  3117,  3037,  3119,  3038,  3039,  3120,  3040,
    2983,  3122,  3123,  3124,  2985,  3127,  3043,  3128,  3045,  3129,
    3130,  3046,  3047,  3132,  3131,   898,  3133,  3134,  3135,  3138,
    3136,  3139,  3140,  3137,  3141,  3142,  3143,  3048,  3049,  3050,
    3051,  3052,  3144,  3145,  3146,  3147,  3206,  3054,  3055,  3056,
    3207,  3208,  3211,  3209,  3210,  3212,  3213,  3214,  3215,  3216,
    3217,  3218,  3219,  3220,  3221,  3222,  2364,  3226,  1637,  3228,
    3229,     0,  3223,  3231,  3227,  3232,  3233,  3230,  3234,  3236,
    3235,  3237,  3238,  3239,     0,  3242,  3240,  3244,   900,  3246,
    3241,     0,  3243,  3250,  3245,     0,  3247,  1505,  3249,  3248,
    3251,  3252,  3253,  3254,  3255,  3256,  3257,  3258,  3259,  3260,
    3263,  3264,  3300,  3265,  3301,  3302,  3303,  3305,  3308,  3306,
    3309,  3307,  3310,  3311,  3312,  3313,  3315,  3314,  3318,  3316,
       0,  3317,     0,  3321,  3333,  3324,  3325,  3148,  3326,  3328,
    3149,  3150,  3151,  3329,  3332,  3336,  3152,  3358,  3153,  3154,
    3359,  3360,  3361,  3362,  3157,  3158,  3363,  3159,  3367,  3160,
    3161,  3162,  3163,  3164,  3165,  3364,  3166,  3167,  3168,  3169,
    3170,  3171,  3007,  3365,  3007,  3366,  3368,  3007,  3007,  3176,
    3177,  3178,  3369,  3370,  3371,  3372,  3373,  3183,  3184,  3374,
    3375,  3185,  3376,  3392,  3393,  3186,  3187,  3188,  3394,  3395,
    3189,  3396,  3397,  3398,  3399,  3400,  3190,  3191,  3401,  3402,
    3192,  3193,  3410,  3411,  3195,  3412,  3197,  3198,  3413,  3415,
    3199,  3200,  3414,  3201,  3416,  3203,  3204,  3205,  3421,  3422,
    3424,  3423,  3428,  3429,  3156,  3430,  3434,  3435,  3436,  3439,
    3440,  3442,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3266,  3267,  3268,
    3269,     0,  3271,  3272,     0,     0,  3273,     0,     0,     0,
       0,     0,     0,  3274,     0,  3275,     0,  3276,     0,     0,
    3277,     0,     0,     0,     0,  3007,     0,     0,     0,     0,
    3279,  3280,     0,  3281,     0,  3282,     0,  3283,  3284,  3285,
       0,  3286,  3287,     0,  3289,     0,  3291,     0,  3293,  3294,
    3295,     0,     0,  3297,  3298,  3299,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3337,     0,     0,     0,  3339,  3340,     0,     0,
       0,  3341,     0,  3342,  3343,     0,  3344,  3345,     0,     0,
       0,  3347,     0,     0,  3349,  3350,  3351,     0,  3352,  3353,
       0,  3354,  3355,     0,     0,  3356,  3357,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3381,     0,
       0,     0,     0,     0,  3382,  3383,  3384,     0,     0,     0,
    3385,  3386,     0,     0,  3388,  3389,     0,     0,  3390,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3403,  3404,     0,  3405,     0,  3406,     0,     0,
    3408,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3417,     0,  3418,  3419,  3420,     0,   181,     0,   234,   234,
     234,  3425,  3426,  3427,     0,     0,     0,     0,  3431,  3432,
    3433,     0,     0,     0,   250,  3437,  3438,   257,     0,  3441,
     264,     0,     0,   264,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     315,   264,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,     0,
       0,     0,     0,   264,   264,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   181,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   234,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   234,
     234,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   264,     0,   264,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   264,   264,     0,   315,   315,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   264,     0,     0,     0,     0,
       0,     0,     0,     0,   667,   667,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   752,   667,   752,   752,
     752,   752,   752,   752,   764,     0,     0,     0,     0,   818,
     819,   820,   752,   823,   824,   825,   826,   827,   828,   829,
     830,     0,     0,     0,     0,   835,   837,     0,     0,   264,
     752,   860,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   315,   264,     0,     0,     0,
       0,     0,   264,     0,   876,   877,   878,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   264,   264,
     264,   264,     0,     0,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   752,   667,     0,   234,     0,   234,
     234,     0,     0,   752,   667,     0,     0,     0,     0,     0,
       1,     0,     2,     3,     4,     0,     5,   234,     0,     0,
       0,     0,     0,     0,     0,     0,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,     0,     0,
       0,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     0,    29,    30,     0,     0,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,     0,     0,    56,    57,    58,    59,     0,
      60,    61,     0,     0,   264,     0,     0,     0,     0,     0,
    1093,  1093,   667,  1101,   264,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    62,    63,
      64,    65,    66,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    67,     0,     0,     0,     0,    68,     0,
       0,     0,     0,     0,     0,    69,    70,    71,    72,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1093,  1093,  1093,  1093,  1093,  1093,  1093,
    1093,  1093,  1093,  1093,  1093,  1093,   752,     0,     0,     0,
       0,     0,     0,    73,    74,     0,     0,     0,     0,     0,
       0,  1093,     0,     0,     0,     0,     0,     0,    75,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    76,     0,    77,     0,     0,     0,     0,     0,    78,
      79,    80,    81,    82,    83,     0,    84,     0,     0,     0,
     264,     0,     0,     0,     0,     0,     0,   752,   752,  1275,
       0,     0,     0,     0,   752,   752,   752,   752,   752,   752,
     752,   752,   752,   752,   752,   752,   752,   752,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    85,    86,    87,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    88,    89,    90,    91,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    93,    94,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   264,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,     0,   105,   106,     0,     0,
     107,     0,     0,     0,     0,     0,   108,   109,   110,   111,
     112,   113,   114,   115,   264,     0,   116,   117,   118,   119,
     120,   121,   122,     0,   123,     0,     0,     0,     0,   124,
       0,   125,   126,     0,     0,     0,   127,   128,   129,   130,
     264,   131,     0,     0,   264,     0,     0,     0,   132,   133,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   134,     0,     0,     0,     0,
     135,   136,     0,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   264,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1093,  1093,   667,   264,     0,     0,
       0,     0,     0,     0,   264,     0,     0,     0,     0,  1093,
    1093,  1093,  1093,  1093,  1093,  1093,  1093,  1093,  1093,  1093,
    1093,  1093,     0,  1093,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   264,     0,     0,     0,
       0,     0,     0,  1470,     0,     0,     0,     0,     0,  1476,
       0,     0,  1480,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   752,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   264,     0,   264,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1520,
       0,     0,     0,     0,   667,   667,  1527,   752,   752,  1530,
    1531,  1532,  1533,  1534,   752,  1536,  1537,  1538,  1539,  1540,
       0,  1543,  1544,  1545,  1546,     0,   752,   752,  1552,     0,
       0,  1555,  1556,  1557,  1558,  1559,  1560,  1561,  1562,  1563,
     752,  1565,  1566,  1567,  1568,  1569,  1570,  1571,  1572,  1573,
    1574,  1575,  1576,  1577,   752,   752,   752,   752,   752,  1583,
    1584,  1585,  1586,  1587,     0,     0,   264,   264,  1592,  1593,
    1594,  1595,  1596,  1597,  1598,  1599,  1600,  1601,  1602,  1603,
    1604,   752,  1606,  1607,  1608,  1609,  1610,  1611,   752,   752,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   752,   752,   752,  1617,   752,   752,
       0,   752,   752,   752,   752,   264,     0,   667,     0,   667,
    1635,   752,   752,  1093,  1093,  1093,  1093,  1093,  1093,  1093,
    1093,  1093,  1093,   752,   752,   752,   752,   752,     0,     0,
     264,   264,   264,     0,     0,     0,   264,     0,     0,     0,
       0,     0,     0,   264,     0,     0,     0,     0,   264,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   752,     0,     0,   752,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1705,     0,  1707,
       0,     0,     0,  1711,  1712,  1713,  1714,     0,     0,     0,
       0,     0,     0,     0,  1722,     0,  1724,  1725,  1726,  1728,
    1729,  1731,  1733,  1734,  1735,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1751,     0,   752,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1761,  1762,  1763,     0,     0,     0,     0,     0,
       0,     0,     0,   264,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   264,  1782,  1783,     0,     0,     0,     0,     0,     0,
     264,  1790,     0,  1791,  1792,  1794,  1796,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   752,     0,     0,     0,     0,     0,     0,     0,
       0,  1819,   752,     0,   752,     0,     0,  1825,     0,     0,
       0,   752,  1830,     0,     0,     0,   752,   752,   752,   264,
     752,  1839,     0,  1841,     0,     0,   752,   264,     0,   752,
     752,   752,   752,   752,     0,     0,     0,   264,     0,   667,
     264,     0,     0,     0,     0,   264,   264,   264,     0,   264,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1093,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   165,     0,     0,   165,   165,   165,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   165,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2030,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,     0,     0,     0,     0,     0,     0,
       0,   752,     0,     0,   752,     0,     0,     0,   752,  2076,
    2077,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     165,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   165,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   752,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   264,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   667,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   165,     0,     0,   665,
     665,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   264,     0,     0,     0,  2252,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2259,
    2260,   751,   665,   751,   751,   751,   751,   751,   751,     0,
       0,     0,     0,     0,     0,     0,   751,   751,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2276,     0,   752,
       0,     0,     0,   856,     0,   751,   667,     0,     0,     0,
       0,     0,     0,   752,  2285,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2301,  2302,   752,   752,  2305,  2306,  2307,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2317,     0,  2318,  2319,  2320,  2321,  2322,     0,
    2323,  2324,     0,     0,     0,     0,   752,   752,     0,     0,
       0,     0,     0,  2335,   264,     0,     0,  2337,  2338,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   751,
     665,     0,   165,   856,   165,   165,     0,     0,   751,  1027,
       0,     0,     0,  2355,     0,     0,  2358,     0,     0,     0,
       0,   752,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   752,     0,  2366,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   264,     0,     0,
     264,   264,   264,   264,   264,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   752,
       0,     0,     0,     0,     0,  2394,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2398,     0,     0,     0,
       0,     0,     0,     0,     0,   665,   665,   665,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   667,     0,
       0,     0,     0,     0,  2412,  2413,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2428,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   665,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   751,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   665,     0,     0,     0,
       0,     0,     0,   667,   752,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   751,   751,   751,     0,     0,     0,     0,   751,
     751,   751,   751,   751,   751,   751,   751,   751,   751,   751,
     751,   751,   751,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     856,   856,   856,     0,   856,   856,   856,   856,   856,   856,
     856,   856,   856,   856,   856,   856,   856,   856,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   264,   264,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2714,     0,     0,     0,  2718,  2720,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2732,  2734,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   200,     0,  2748,  2749,
    2750,  2751,  2752,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   251,   752,     0,     0,   752,  1027,
    1027,  1027,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1027,  1027,  1027,  1027,  1027,  1027,
    1027,  1027,  1027,  1027,  1027,  1027,  1027,     0,  1027,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   264,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2779,     0,     0,     0,     0,     0,   752,     0,
     752,     0,   752,     0,   752,     0,     0,   751,  2790,  2791,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2796,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   665,
     665,     0,   751,   751,     0,  2821,     0,     0,     0,   751,
       0,   752,     0,     0,     0,   200,     0,   752,   752,     0,
       0,   751,   751,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   751,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   751,
     751,   751,   751,   751,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   751,     0,     0,     0,
       0,     0,     0,   751,   751,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   751,
     751,   751,     0,   751,   751,     0,   751,   751,   751,   751,
       0,     0,   665,     0,   665,     0,   751,   751,   665,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   751,   751,
     751,   751,   751,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   532,   533,
       0,     0,     0,     0,   687,   687,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   751,     0,
       0,   751,     0,     0,     0,  2718,     0,     0,     0,  2718,
       0,     0,     0,     0,     0,     0,   754,   687,   754,   754,
     754,   754,   754,   754,     0,     0,     0,     0,     0,     0,
       0,   754,   754,     0,     0,  1635,  1635,  1635,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3018,     0,
     754,     0,     0,     0,     0,     0,     0,   751,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   264,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   752,  3042,     0,
       0,     0,     0,  3044,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   752,     0,     0,     0,     0,     0,   751,     0,     0,
       0,     0,     0,     0,   754,   687,     0,   751,     0,   751,
       0,     0,   994,   754,  1032,     0,   751,     0,     0,     0,
       0,   751,   751,   751,     0,   751,     0,     0,     0,     0,
       0,   751,     0,     0,   751,   751,   751,   751,   751,     0,
       0,     0,     0,     0,   665,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   264,     0,     0,  2718,
       0,     0,     0,     0,     0,     0,     0,   665,     0,     0,
     687,   687,   687,  1102,     0,     0,     0,     0,  1635,     0,
    1635,     0,     0,  1635,  1635,     0,     0,     0,  3179,  3180,
    3181,  3182,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3194,
       0,  3196,     0,     0,     0,     0,     0,     0,     0,     0,
     752,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   687,   687,   687,   687,   687,   687,   687,
     687,   687,   687,   687,   687,   687,   754,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   687,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1635,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3288,
       0,  3290,     0,     0,     0,     0,   751,     0,   752,   751,
       0,     0,     0,   751,     0,     0,     0,   754,   754,   754,
       0,     0,     0,     0,   754,   754,   754,   754,   754,   754,
     754,   754,   754,   754,   754,   754,   754,   754,   752,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   264,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   751,     0,   752,     0,     0,   752,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   665,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3387,     0,
       0,     0,     0,     0,     0,     0,   752,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3407,     0,     0,     0,   752,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   751,     0,     0,     0,     0,     0,
       0,   665,     0,     0,     0,     0,     0,     0,   751,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   751,
     751,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   687,   687,   687,     0,     0,     0,
       0,   751,   751,     0,     0,     0,     0,     0,     0,   687,
     687,   687,   687,   687,   687,   687,   687,   687,   687,   687,
     687,   687,     0,   687,   258,   261,   263,     0,     0,   267,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   751,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   317,   751,     0,
       0,     0,   754,     0,     0,     0,     0,     0,     0,   994,
       0,     0,     0,     0,     0,  1503,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   751,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   687,   687,     0,   754,   754,     0,
       0,     0,     0,     0,   754,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   754,   754,     0,   387,
     388,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     754,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   665,   754,   754,   754,   754,   754,     0,
       0,     0,     0,     0,  1588,  1589,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   754,     0,     0,     0,     0,     0,     0,   754,   754,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   754,   754,   754,     0,   754,   754,
       0,   754,   754,   754,   754,     0,     0,   687,     0,   687,
       0,   754,   754,   687,   687,   687,   687,   687,   687,   687,
     687,   687,   687,   754,   754,   754,   754,   754,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   464,     0,
     466,     0,     0,     0,     0,     0,     0,     0,   665,   751,
       0,     0,     0,     0,     0,     0,     0,   468,   469,     0,
       0,     0,     0,   754,     0,     0,   754,     0,     0,     0,
       0,   476,     0,     0,     0,     0,     0,     0,     0,     0,
     664,   664,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   754,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   858,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   686,   686,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   868,     0,     0,     0,     0,     0,   874,     0,
       0,     0,   754,   753,   757,   758,   759,   760,   761,   762,
     763,     0,   754,     0,   754,     0,   882,   883,   821,   822,
       0,   754,     0,  1831,  1832,  1833,   754,   754,   754,     0,
     754,     0,  1840,     0,  1842,  1843,   754,   859,     0,   754,
     754,   754,   754,   754,     0,     0,     0,     0,     0,   687,
    1026,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   687,     0,     0,     0,     0,     0,     0,     0,
       0,   921,   923,     0,     0,     0,     0,     0,     0,     0,
     997,  1029,     0,     0,     0,     0,     0,     0,     0,  1087,
    1089,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1104,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     751,     0,     0,   751,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2031,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   751,     0,   751,     0,   751,     0,   751,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   994,
       0,   754,     0,     0,   754,     0,     0,     0,   754,     0,
       0,     0,     0,     0,     0,     0,   751,     0,     0,     0,
       0,     0,   751,   751,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1267,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   754,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   687,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1361,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   754,
    1386,     0,     0,     0,     0,     0,   687,     0,     0,     0,
       0,     0,     0,   754,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1396,     0,     0,     0,
    1399,     0,     0,     0,   754,   754,     0,     0,     0,     0,
       0,     0,   751,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   754,   754,     0,     0,
       0,     0,     0,     0,     0,     0,   751,     0,     0,     0,
    1442,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1104,     0,     0,     0,     0,     0,     0,
    1442,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   754,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   754,     0,     0,     0,     0,     0,     0,
       0,     0,  1466,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   754,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1512,     0,  1515,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1518,     0,     0,     0,     0,
     664,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   687,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1490,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   751,     0,     0,     0,     0,
       0,     0,  1590,  1591,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   686,  1526,     0,  1528,  1529,     0,     0,     0,     0,
       0,  1535,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1550,  1551,     0,     0,     0,     0,     0,
       0,  1625,     0,  1628,     0,     0,     0,  1564,     0,     0,
       0,     0,     0,   687,   754,     0,     0,     0,     0,     0,
       0,  1578,  1579,  1580,  1581,  1582,  1670,  1671,  1672,     0,
       0,     0,  1676,     0,     0,     0,     0,     0,     0,  1683,
       0,     0,     0,     0,  1688,     0,     0,     0,  1605,     0,
       0,     0,     0,     0,     0,  1612,  1613,     0,     0,     0,
       0,     0,     0,   751,     0,     0,     0,     0,     0,     0,
       0,  1614,  1615,  1616,     0,  1618,  1619,     0,  1621,  1622,
    1623,  1624,     0,     0,  1630,     0,  1631,     0,     0,     0,
       0,     0,     0,   751,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   751,     0,     0,   751,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1767,
    1700,     0,     0,  1631,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1781,     0,     0,
       0,     0,     0,     0,     0,     0,  1789,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   751,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1752,
       0,     0,     0,   751,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1837,     0,     0,     0,     0,
       0,     0,     0,  1846,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1855,     0,   664,  1858,     0,     0,     0,
       0,  1863,  1864,  1865,     0,  1866,     0,     0,     0,  1868,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1810,
       1,     0,     0,   731,   732,     0,   733,     0,     0,  1820,
       0,  1822,     0,     0,     0,     0,     0,     0,  1829,     0,
       0,     0,     0,  1834,  1835,  1836,     0,  1838,   548,   549,
       0,     0,     0,  1844,     0,     0,  1847,  1848,  1849,  1850,
    1851,     0,     0,     0,     0,     0,   686,     0,     0,     0,
       0,    34,     0,     0,     0,     0,   734,   210,   551,     0,
       0,     0,     0,   552,     0,   754,     0,     0,   754,   215,
     216,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   754,     0,
     754,     0,   754,     0,   754,     0,     0,     0,     0,   735,
       0,     0,     0,   554,   555,   556,   557,   558,   559,   560,
     561,     0,   562,     0,   563,   564,   565,   566,   736,   568,
     569,     0,   570,   571,     0,     0,     0,     0,   737,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   754,     0,     0,     0,     0,     0,   754,   754,     0,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,     0,     0,     0,     0,   586,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,     0,   600,     0,   601,   602,   603,   604,   605,     0,
       0,     0,     0,     0,     0,   606,     0,     0,     0,     0,
       0,     0,     0,     0,   607,   608,   609,   610,     0,     0,
       0,  2145,   611,     0,     0,     0,   612,     0,  2071,     0,
       0,     0,     0,     0,     0,  2075,     0,     0,     0,     0,
       0,     0,     0,   613,   614,   615,   616,     0,     0,     0,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   628,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   629,   630,     0,     0,
       0,     0,     0,     0,     0,     0,  2128,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2251,
       0,  2167,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   631,   632,   633,   634,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,     0,     0,   754,   635,   636,
       0,     0,     0,     0,     0,     0,     0,     0,   738,   739,
     740,   741,   742,   743,     0,     0,   744,   745,   746,   747,
     748,   749,   750,   650,     0,     0,     0,     0,     0,     0,
       0,   754,     0,     0,     0,     0,     0,     0,     0,     0,
     651,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     652,   653,   654,   655,     0,   656,   657,     0,     0,     0,
    2336,   658,   659,     0,     0,     0,  2278,   660,   661,   662,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2283,     0,     0,   147,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2303,  2304,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2371,
    2373,     0,     0,  2376,     0,  2377,  2379,  2380,  2381,  2382,
    2383,     0,     0,  2329,  2330,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   402,     0,     0,     0,  2361,     0,
       0,     1,     0,     2,     3,     4,     0,     5,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,     0,
     754,     0,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,     0,    29,    30,     0,     0,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,     0,     0,    56,    57,    58,    59,
       0,    60,    61,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2407,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     2,     3,     4,     0,     5,     0,    62,
      63,    64,    65,    66,     0,     0,     0,     0,   754,     0,
       0,     0,     0,     0,    67,     0,    15,     0,     0,    68,
       0,     0,     0,     0,     0,     0,    69,    70,    71,    72,
       0,     0,     0,     0,     0,     0,     0,     0,   754,     0,
      32,     0,    34,   206,   207,   208,     0,   209,   210,     0,
     236,   212,     0,     0,     0,     0,     0,   213,   214,     0,
     215,   216,     0,     0,    73,    74,   754,     0,     0,   754,
    2467,  2468,     0,     0,     0,     0,     0,     0,     0,    75,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    76,     0,    77,     0,     0,     0,     0,     0,
      78,    79,    80,    81,    82,    83,   754,    84,     0,    62,
      63,    64,    65,    66,     0,     0,     0,     0,     1,     0,
       2,   203,   204,     0,   205,     0,     0,     0,   754,   217,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   218,
       0,     0,     0,    15,     0,     0,     0,     0,    85,    86,
      87,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    88,    89,    90,    91,    32,     0,    34,
     206,   207,   208,     0,   209,   210,     0,   211,   212,     0,
       0,     0,     0,     0,   213,   214,     0,   215,   216,    75,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2695,  2696,     0,     0,     0,     0,     0,
       0,     0,     0,    92,     0,     0,     0,     0,     0,     0,
       0,     0,    76,     0,    77,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    93,    94,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    62,    63,    64,    65,
      66,     0,     0,     0,     0,     0,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   217,   105,   106,     0,
       0,   107,     0,     0,     0,     0,   218,   108,   109,   110,
     111,   112,   113,   114,   115,    90,    91,   116,   117,   118,
     119,   120,   121,   122,     0,   123,     0,     0,     0,     0,
     124,     0,   125,   126,     0,     0,     0,   127,   128,   129,
     130,     0,   131,     0,     0,     0,     0,     0,     0,   132,
     133,     0,     0,     0,     0,  2775,    75,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   134,     0,     0,     0,
       0,   135,   136,     0,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,     0,     0,    93,    94,    76,
       0,    77,  2756,     0,     0,  2757,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,     0,   105,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,     0,     0,   116,   117,   118,
     119,   120,   121,   122,     0,  2783,     0,  2784,     0,  2785,
       0,  2786,    90,    91,     0,     0,     0,     0,     0,   129,
     130,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   147,     0,     0,     0,  2822,     0,
       0,     0,     0,     0,  2827,  2828,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,     0,   105,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   108,   109,   219,   220,   221,   222,
     223,   224,     0,     0,   225,   226,   227,   228,   229,   230,
     231,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   129,   130,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   147,     0,     0,     0,     0,     0,  3033,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       2,   998,   999,     0,  1000,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3041,     0,     0,     0,     0,     0,
       0,     0,    14,    15,     0,     0,  1001,   549,  1002,     0,
       0,     0,     0,     0,     0,     0,    25,    26,     0,     0,
       0,    29,    30,     0,     0,    31,     0,    32,  3053,    34,
     206,   207,   208,   241,   755,   210,  1003,   236,   212,  1004,
       0,   552,     0,     0,   213,   214,  1005,   215,   216,     0,
       0,     0,  3155,     0,     0,     0,     0,  1006,     0,     0,
    1007,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    62,   553,    64,    65,
      66,   554,   555,   556,   557,   558,   559,   560,   561,     0,
     562,     0,   563,   564,   565,   566,   567,   568,   569,     0,
     570,   571,     0,     0,    70,     0,   572,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,     0,     0,     0,  3270,   586,    75,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3202,     0,     0,
       0,     0,     0,     0,     0,     0,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,    76,
     600,    77,   601,   602,   603,   604,   605,     0,     0,     0,
       0,     0,     0,   606,     0,     0,     0,   973,   974,   975,
       0,     0,   607,   608,   609,   610,   976,   977,   978,   979,
     611,     0,     0,   980,   612,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   613,   614,   615,   616,     0,     0,  3338,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   628,
       0,     0,    90,    91,   981,     0,     0,   982,   983,   984,
     985,     0,   986,   987,   629,   630,  1008,     0,     0,     0,
       0,     0,     0,     0,     0,  3296,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  3327,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1009,    93,    94,     0,     0,     0,     0,
       0,     0,     0,  3346,     0,     0,  3348,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   631,
     632,   633,   634,    95,  1010,    97,    98,  1011,   100,   101,
     102,   103,   104,     0,   105,     0,   635,   636,     0,  1012,
       0,     0,     0,     0,   108,   109,  1013,  1014,  1015,  1016,
    1017,  1018,     0,     0,  1019,  1020,  1021,  1022,  1023,  1024,
    1025,   650,     0,  3391,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   129,   130,   651,     0,
       0,     0,     0,     0,     0,  3409,     0,     0,   652,   653,
     654,   655,     0,   656,   657,     0,   989,   990,   991,   658,
     659,     0,   992,     0,   993,   660,   661,   662,     1,     0,
       2,   998,   999,     0,  1000,     0,     0,     0,     0,     0,
       0,   147,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    14,    15,     0,     0,   548,   549,     0,     0,
       0,     0,     0,     0,     0,     0,    25,    26,     0,     0,
       0,    29,    30,     0,     0,    31,     0,    32,     0,    34,
     206,   207,   208,   241,   755,   210,   551,   236,   212,     0,
       0,   552,     0,     0,   213,   214,     0,   215,   216,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    62,   553,    64,    65,
      66,   554,   555,   556,   557,   558,   559,   560,   561,     0,
     562,     0,   563,   564,   565,   566,   567,   568,   569,     0,
     570,   571,     0,     0,    70,     0,   572,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,     0,     0,     0,     0,   586,    75,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,    76,
     600,    77,   601,   602,   603,   604,   605,     0,     0,     0,
       0,     0,     0,   606,     0,     0,     0,     0,     0,     0,
       0,     0,   607,   608,   609,   610,     0,     0,     0,     0,
     611,     0,     0,     0,   612,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   613,   614,   615,   616,     0,     0,     0,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   628,
       0,     0,    90,    91,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   629,   630,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    93,    94,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   631,
     632,   633,   634,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,     0,   105,     0,   635,   636,     0,     0,
       0,     0,     0,     0,   108,   109,  1013,  1014,  1015,  1016,
    1017,  1018,     0,     0,  1019,  1020,  1021,  1022,  1023,  1024,
    1025,   650,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   129,   130,   651,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   652,   653,
     654,   655,     0,   656,   657,     0,     0,     0,     0,   658,
     659,     0,     0,     0,     0,   660,   661,   662,     1,     0,
       2,   544,   545,     0,   546,     0,     0,     0,   547,     0,
       0,   147,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    14,    15,     0,     0,   548,   549,     0,     0,
       0,     0,     0,     0,     0,     0,    25,    26,     0,     0,
       0,    29,    30,     0,     0,    31,     0,    32,     0,    34,
     206,   207,   208,   241,   550,   210,   551,   211,   212,     0,
       0,   552,     0,     0,   213,   214,     0,   215,   216,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    62,   553,    64,    65,
      66,   554,   555,   556,   557,   558,   559,   560,   561,     0,
     562,     0,   563,   564,   565,   566,   567,   568,   569,     0,
     570,   571,     0,     0,    70,     0,   572,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,     0,     0,     0,     0,   586,    75,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,    76,
     600,    77,   601,   602,   603,   604,   605,     0,     0,     0,
       0,     0,     0,   606,     0,     0,     0,     0,     0,     0,
       0,     0,   607,   608,   609,   610,     0,     0,     0,     0,
     611,     0,     0,     0,   612,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   613,   614,   615,   616,     0,     0,     0,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   628,
       0,     0,    90,    91,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   629,   630,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   631,
     632,   633,   634,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,     0,   105,     0,   635,   636,     0,     0,
       0,     0,     0,     0,   108,   109,   637,   638,   639,   640,
     641,   642,     0,     0,   643,   644,   645,   646,   647,   648,
     649,   650,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   129,   130,   651,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   652,   653,
     654,   655,     0,   656,   657,     0,     0,     0,     0,   658,
     659,     0,     0,     0,     0,   660,   661,   662,     1,     0,
       2,   544,   545,     0,   546,     0,     0,     0,  1626,     0,
       0,   147,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    14,    15,     0,     0,   548,   549,     0,     0,
       0,     0,     0,     0,     0,     0,    25,    26,     0,     0,
       0,    29,    30,     0,     0,    31,     0,    32,     0,    34,
     206,   207,   208,   241,  1627,   210,   551,   211,   212,     0,
       0,   552,     0,     0,   213,   214,     0,   215,   216,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    62,   553,    64,    65,
      66,   554,   555,   556,   557,   558,   559,   560,   561,     0,
     562,     0,   563,   564,   565,   566,   567,   568,   569,     0,
     570,   571,     0,     0,    70,     0,   572,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,     0,     0,     0,     0,   586,    75,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,    76,
     600,    77,   601,   602,   603,   604,   605,     0,     0,     0,
       0,     0,     0,   606,     0,     0,     0,     0,     0,     0,
       0,     0,   607,   608,   609,   610,     0,     0,     0,     0,
     611,     0,     0,     0,   612,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   613,   614,   615,   616,     0,     0,     0,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   628,
       0,     0,    90,    91,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   629,   630,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   631,
     632,   633,   634,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,     0,   105,     0,   635,   636,     0,     0,
       0,     0,     0,     0,   108,   109,   637,   638,   639,   640,
     641,   642,     0,     0,   643,   644,   645,   646,   647,   648,
     649,   650,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   129,   130,   651,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   652,   653,
     654,   655,     0,   656,   657,     0,     0,     0,     0,   658,
     659,     0,     0,     0,     0,   660,   661,   662,     1,     0,
       2,   544,   545,     0,   546,     0,     0,     0,     0,     0,
       0,   147,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    14,    15,     0,     0,   548,   549,     0,     0,
       0,     0,     0,     0,     0,     0,    25,    26,     0,     0,
       0,    29,    30,     0,     0,    31,     0,    32,     0,    34,
     206,   207,   208,   241,   755,   210,   551,   211,   212,     0,
       0,   552,     0,     0,   213,   214,     0,   215,   216,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    62,   553,    64,    65,
      66,   554,   555,   556,   557,   558,   559,   560,   561,     0,
     562,     0,   563,   564,   565,   566,   567,   568,   569,     0,
     570,   571,     0,     0,    70,     0,   572,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,     0,     0,     0,     0,   586,    75,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,    76,
     600,    77,   601,   602,   603,   604,   605,     0,     0,     0,
       0,     0,     0,   606,     0,     0,     0,     0,     0,     0,
       0,     0,   607,   608,   609,   610,     0,     0,     0,     0,
     611,     0,     0,     0,   612,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   613,   614,   615,   616,     0,     0,     0,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   628,
       0,     0,    90,    91,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   629,   630,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   631,
     632,   633,   634,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,     0,   105,     0,   635,   636,     0,     0,
       0,     0,     0,     0,   108,   109,   637,   638,   639,   640,
     641,   642,     0,     0,   643,   644,   645,   646,   647,   648,
     649,   650,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   129,   130,   651,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   652,   653,
     654,   655,     0,   656,   657,     0,     0,     0,     0,   658,
     659,     0,     0,     0,     0,   660,   661,   662,     1,     0,
       2,   998,   999,     0,  1000,     0,     0,     0,     0,     0,
       0,   147,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    15,     0,     0,   548,   549,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    32,     0,    34,
     206,   207,   208,     0,   755,   210,   551,   236,   212,     0,
       0,   552,     0,     0,   213,   214,     0,   215,   216,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    62,   553,    64,    65,
      66,   554,   555,   556,   557,   558,   559,   560,   561,     0,
     562,     0,   563,   564,   565,   566,   567,   568,   569,     0,
     570,   571,     0,     0,     0,     0,   572,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,     0,     0,     0,     0,   586,    75,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,    76,
     600,    77,   601,   602,   603,   604,   605,     0,     0,     0,
       0,     0,     0,   606,     0,     0,     0,     0,     0,     0,
       0,     0,   607,   608,   609,   610,     0,     0,     0,     0,
     611,     0,     0,     0,   612,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   613,   614,   615,   616,     0,     0,     0,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   628,
       0,     0,    90,    91,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   629,   630,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    93,    94,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   631,
     632,   633,   634,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,     0,   105,     0,   635,   636,     0,     0,
       0,     0,     0,     0,   108,   109,  1013,  1014,  1015,  1016,
    1017,  1018,     0,     0,  1019,  1020,  1021,  1022,  1023,  1024,
    1025,   650,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   129,   130,   651,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   652,   653,
     654,   655,     0,   656,   657,     0,     0,     0,     0,   658,
     659,     0,     0,     0,     0,   660,   661,   662,     1,     0,
       2,   544,   545,     0,   546,     0,     0,     0,     0,     0,
       0,   147,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    15,     0,     0,   548,   549,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    32,     0,    34,
     206,   207,   208,     0,   755,   210,   551,   211,   212,     0,
       0,   552,     0,     0,   213,   214,     0,   215,   216,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    62,   553,    64,    65,
      66,   554,   555,   556,   557,   558,   559,   560,   561,     0,
     562,     0,   563,   564,   565,   566,   567,   568,   569,     0,
     570,   571,     0,     0,     0,     0,   572,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,     0,     0,     0,     0,   586,    75,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,    76,
     600,    77,   601,   602,   603,   604,   605,     0,     0,     0,
       0,     0,     0,   606,     0,     0,     0,     0,     0,     0,
       0,     0,   607,   608,   609,   610,     0,     0,     0,     0,
     611,     0,     0,     0,   612,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   613,   614,   615,   616,     0,     0,     0,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   628,
       0,     0,    90,    91,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   629,   630,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   631,
     632,   633,   634,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,     0,   105,     0,   635,   636,     0,     0,
       0,     0,     0,     0,   108,   109,   637,   638,   639,   640,
     641,   642,     0,     0,   643,   644,   645,   646,   647,   648,
     649,   650,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   129,   130,   651,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   652,   653,
     654,   655,     0,   656,   657,     0,     0,     0,     0,   658,
     659,     0,     0,     0,     0,   660,   661,   662,     1,     0,
       2,   544,   545,     0,  1920,     0,     0,     0,     0,     0,
       0,   147,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    15,     0,     0,   548,   549,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    32,     0,    34,
     206,   207,   208,     0,   755,   210,   551,   211,   212,     0,
       0,   552,     0,     0,   213,   214,     0,   215,   216,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    62,   553,    64,    65,
      66,   554,   555,   556,   557,   558,   559,   560,   561,     0,
     562,     0,   563,   564,   565,   566,   567,   568,   569,     0,
     570,   571,     0,     0,     0,     0,   572,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,     0,     0,     0,     0,   586,    75,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,    76,
     600,    77,   601,   602,   603,   604,   605,     0,     0,     0,
       0,     0,     0,   606,     0,     0,     0,     0,     0,     0,
       0,     0,   607,   608,   609,   610,     0,     0,     0,     0,
     611,     0,     0,     0,   612,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   613,   614,   615,   616,     0,     0,     0,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   628,
       0,     0,    90,    91,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   629,   630,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     0,   731,   732,     0,   733,     0,   631,
     632,   633,   634,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,     0,   105,     0,   635,   636,     0,   548,
     549,     0,     0,     0,   108,   109,   637,   638,   639,   640,
     641,   642,     0,     0,   643,   644,   645,   646,   647,   648,
     649,   650,    34,     0,     0,     0,     0,   734,   210,   551,
       0,     0,     0,     0,   552,     0,   129,   130,   651,     0,
     215,   216,     0,     0,     0,     0,     0,     0,   652,   653,
     654,   655,     0,   656,   657,     0,     0,     0,     0,   658,
     659,     0,     0,     0,     0,   660,   661,   662,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   147,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     735,     0,     0,     0,   554,   555,   556,   557,   558,   559,
     560,   561,     0,   562,     0,   563,   564,   565,   566,   736,
     568,   569,     0,   570,   571,     0,     0,     0,     0,   737,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,     0,     0,     0,     0,   586,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,     0,   600,     0,   601,   602,   603,   604,   605,
       0,     0,     0,     0,     0,     0,   606,     0,     0,     0,
       0,     0,     0,     0,     0,   607,   608,   609,   610,     0,
       0,     0,     0,   611,     0,     0,     0,   612,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   613,   614,   615,   616,     0,     0,
       0,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   628,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   629,   630,   996,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     0,     0,   731,   732,     0,
     733,     0,   631,   632,   633,   634,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   635,
     636,     0,   548,   549,     0,     0,     0,     0,     0,   738,
     739,   740,   741,   742,   743,     0,     0,   744,   745,   746,
     747,   748,   749,   750,   650,    34,     0,     0,     0,     0,
     734,   210,   551,     0,     0,     0,     0,   552,     0,     0,
       0,   651,     0,   215,   216,     0,     0,     0,     0,     0,
       0,   652,   653,   654,   655,     0,   656,   657,     0,     0,
       0,     0,   658,   659,     0,     0,     0,     0,   660,   661,
     662,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   147,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   735,     0,     0,     0,   554,   555,   556,
     557,   558,   559,   560,   561,     0,   562,     0,   563,   564,
     565,   566,   736,   568,   569,     0,   570,   571,     0,     0,
       0,     0,   737,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,     0,     0,     0,
       0,   586,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,     0,   600,     0,   601,   602,
     603,   604,   605,     0,     0,     0,     0,     0,     0,   606,
       0,     0,     0,     0,     0,     0,     0,     0,   607,   608,
     609,   610,     0,     0,     0,     0,   611,     0,     0,     0,
     612,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   613,   614,   615,
     616,     0,     0,     0,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   628,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     629,   630,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     0,     0,
     731,   732,     0,  2073,     0,   631,   632,   633,   634,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   635,   636,     0,   548,   549,     0,     0,     0,
       0,     0,   738,   739,   740,   741,   742,   743,     0,     0,
     744,   745,   746,   747,   748,   749,   750,   650,    34,     0,
       0,     0,     0,   734,   210,   551,     0,     0,     0,     0,
     552,     0,     0,     0,   651,     0,   215,   216,     0,     0,
       0,     0,     0,     0,   652,   653,   654,   655,     0,   656,
     657,     0,     0,     0,     0,   658,   659,     0,     0,     0,
       0,   660,   661,   662,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   147,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   735,     0,     0,     0,
     554,   555,   556,   557,   558,   559,   560,   561,     0,   562,
       0,   563,   564,   565,   566,   736,   568,   569,     0,   570,
     571,     0,     0,     0,     0,   737,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
       0,     0,     0,     0,   586,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,     0,   600,
       0,   601,   602,   603,   604,   605,     0,     0,     0,     0,
       0,     0,   606,     0,     0,     0,     0,     0,     0,     0,
       0,   607,   608,   609,   610,     0,     0,     0,     0,   611,
       0,     0,     0,   612,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     613,   614,   615,   616,     0,     0,     0,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   628,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   629,   630,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     2,   203,   204,     0,   205,     0,
       0,     0,     0,     0,     0,     0,     0,  1632,     0,     0,
       0,     0,     0,     0,     0,     0,    14,    15,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      25,    26,     0,     0,     0,    29,    30,     0,     0,    31,
       0,    32,     0,    34,   206,   207,   208,   241,  1633,   210,
       0,   211,   212,     0,     0,     0,     0,     0,   213,   214,
       0,   215,   216,     0,     0,     0,     0,     0,   631,   632,
     633,   634,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   635,   636,     0,     0,     0,
       0,     0,     0,     0,     0,   738,   739,   740,   741,   742,
     743,     0,     0,   744,   745,   746,   747,   748,   749,   750,
     650,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   651,     0,     0,
      62,    63,    64,    65,    66,     0,     0,   652,   653,   654,
     655,     0,   656,   657,     0,     0,     0,     0,   658,   659,
     217,     0,     0,     0,   660,   661,   662,     0,    70,     0,
     218,     0,     1,     0,     2,   203,   204,     0,   205,     0,
     147,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    14,    15,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      25,    26,     0,     0,     0,    29,    30,     0,     0,    31,
      75,    32,     0,    34,   206,   207,   208,   241,   209,   210,
       0,   211,   212,     0,     0,     0,     0,     0,   213,   214,
       0,   215,   216,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    76,     0,    77,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      62,    63,    64,    65,    66,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    90,    91,     0,     0,
     217,     0,     0,     0,     0,     0,     0,     0,    70,     0,
     218,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      75,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    76,     0,    77,     0,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,     0,   105,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   108,   109,
     219,   220,   221,   222,   223,   224,     0,     0,   225,   226,
     227,   228,   229,   230,   231,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     129,   130,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    90,    91,     1,     0,
       2,   203,   204,     0,   205,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    14,    15,     0,   147,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    25,    26,     0,     0,
       0,    29,    30,     0,     0,    31,     0,    32,     0,    34,
     206,   207,   208,   241,  1633,   210,     0,   211,   212,     0,
       0,     0,     0,     0,   213,   214,     0,   215,   216,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,     0,   105,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   108,   109,
     219,   220,   221,   222,   223,   224,     0,     0,   225,   226,
     227,   228,   229,   230,   231,     0,    62,    63,    64,    65,
      66,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     129,   130,     0,     0,     0,     0,   217,     0,     0,     0,
       0,     0,     0,     0,    70,     0,   218,     0,     1,     0,
       2,   203,   204,     0,  1038,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    15,     0,   147,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    75,    32,     0,    34,
     206,   207,   208,     0,   209,   210,     0,   211,   212,     0,
       0,     0,     0,     0,   213,   214,     0,   215,   216,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    76,
       0,    77,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    62,    63,    64,    65,
      66,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    90,    91,     0,     0,   217,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   218,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    75,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    76,
       0,    77,     0,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,     0,   105,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   108,   109,   219,   220,   221,   222,
     223,   224,     0,     0,   225,   226,   227,   228,   229,   230,
     231,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   129,   130,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    90,    91,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   147,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,     0,   105,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   108,   109,   219,   220,   221,   222,
     223,   224,     0,     0,   225,   226,   227,   228,   229,   230,
     231,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   129,   130,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   147
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
         0,    47,   385,   448,   289,    23,    50,   421,   422,   144,
      42,   394,     0,   461,    50,    57,    34,     0,    31,   544,
     545,    57,    22,    23,   423,   424,   425,   426,    58,   443,
     444,    19,    45,    46,    64,     7,    64,    50,    51,    22,
      37,    54,    52,    52,    20,    58,    76,    77,    76,    62,
      15,    42,    43,    52,    53,    14,    54,     5,     6,    22,
      48,  2879,  2880,  2881,    77,     5,     6,    14,    65,    21,
      13,    57,    15,    22,    49,    50,    19,    13,    75,    21,
      19,   127,    57,    19,   346,   347,     5,    19,    19,   123,
     238,   239,   240,    64,   238,   239,   240,    23,    19,   238,
     239,   240,    13,   149,    15,    76,    13,    20,    34,    20,
     144,   157,   637,   638,   639,   640,   641,   642,   643,   644,
     645,   646,   647,   648,   649,   650,   126,     7,    19,    58,
      10,    11,   280,    13,    20,   123,    58,    19,   400,    57,
     665,    63,   290,   291,   132,   133,   290,   291,    77,   149,
      54,   290,    13,    71,    58,    77,    13,    14,   123,    13,
     173,   149,    19,    14,   140,   141,   149,   176,    58,    20,
      58,   143,    23,    77,   137,   185,   185,    13,   220,    19,
     123,   140,   141,   158,   220,   137,    66,    77,   137,    77,
     138,   139,   123,   140,   141,   137,   238,    59,   138,   139,
      62,   144,   238,   124,   125,   144,   731,   732,   144,   241,
     220,   220,   144,   738,   739,   740,   741,   742,   743,   744,
     745,   746,   747,   748,   749,   750,   751,   140,   141,   228,
     229,    13,   291,   381,   382,   383,   384,   381,   382,   383,
     384,    13,   133,   134,    13,   220,    58,   247,   276,   277,
     278,   133,   134,   144,   140,   141,    19,   285,   286,   287,
     288,    13,   144,   238,   292,    77,   241,   242,   243,   244,
     268,   269,   272,    58,  3092,   275,  3094,   238,   278,  3097,
    3098,    14,    19,   171,   284,   285,   205,    20,   288,   289,
      23,    13,    77,   133,   134,   295,    19,   297,   273,   274,
     275,    23,   285,    54,   144,   333,    15,    58,   336,   337,
     338,   339,    34,   341,   342,     7,     8,   345,   318,   319,
      12,   321,   381,   382,   383,   384,    77,   301,   302,   303,
     304,   305,   306,   307,   308,   309,    14,    58,    59,    60,
     475,   387,    20,    64,    22,    23,    13,   347,   348,    13,
     350,   351,    19,    20,    13,    76,    77,    13,    14,   171,
      58,    59,    60,    19,   410,    13,    64,    13,    54,   352,
     412,    57,   346,    19,    20,    13,   412,    15,    76,    77,
      19,    14,    68,    69,    70,    13,   171,    20,    13,    14,
      23,   389,   140,   141,    19,   395,    13,    13,   442,    15,
     442,   389,    13,    19,    15,   402,   442,    13,    19,    15,
     544,   545,    13,    19,    13,    19,    15,  3235,    19,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,    19,
       4,   406,   407,     7,     8,   435,   436,   412,    19,   439,
      13,    14,    13,    13,    14,    13,    19,    13,   448,    19,
     425,    19,   482,   453,   454,    13,    13,   457,   449,   450,
     451,   452,    19,   481,    14,   448,    14,   442,    13,    13,
      20,    13,    20,   998,   999,    19,    14,   505,   506,   507,
      14,    14,    20,   511,    13,   513,    20,    20,  1013,  1014,
    1015,  1016,  1017,  1018,  1019,  1020,  1021,  1022,  1023,  1024,
    1025,    13,  1027,   637,   638,   639,   640,   641,   642,   643,
     644,   645,   646,   647,   648,   649,   650,   140,   141,    14,
      14,    14,    14,   403,   404,    20,    20,    20,    20,    14,
      16,   665,    14,    14,    14,    20,    22,   537,    20,    20,
      20,    13,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   301,   302,   303,   304,   305,   306,   307,   308,
     309,    14,    13,    13,    15,    14,    14,    20,     2,     3,
       4,    20,    20,    10,    11,   455,   456,   457,   458,   459,
     460,    10,    11,   463,   464,   465,   466,   467,   468,   469,
      14,   222,   223,    14,    14,    14,    20,   731,   732,    20,
      20,    20,    13,    13,   738,   739,   740,   741,   742,   743,
     744,   745,   746,   747,   748,   749,   750,   751,    14,    14,
      31,    10,    11,    14,    20,    20,    14,   546,  1073,    20,
      14,    14,    20,    13,    45,    46,    20,    20,    14,    50,
      51,     3,     4,    54,    20,     0,    14,    58,    14,    14,
     530,    62,    20,    14,    20,    20,    14,    14,    14,    20,
       4,    14,    20,    20,    20,    14,    77,    20,    14,    14,
      13,    20,    15,    13,    20,    20,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,    14,
      14,    14,    14,    14,    14,    20,    20,    20,    20,    20,
      20,  1226,  1227,  1228,  1229,  1230,  1231,  1232,  1233,  1234,
    1235,  1236,  1237,  1238,  1239,  1240,  1241,    20,    14,    22,
      14,    90,    13,    92,    20,    94,    20,    96,   728,    98,
      99,   165,    13,   102,   103,   104,   105,   106,   107,   108,
     109,    14,    13,    13,    15,   114,    13,    20,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,    14,   173,   222,   223,    14,    14,    20,    14,   203,
     204,    20,    20,    14,    20,    14,    14,    17,    14,    20,
      13,    20,    20,    13,    20,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    14,
      20,    14,    22,   165,    14,    20,    13,    20,    15,    13,
      20,    14,    18,    14,   733,  1229,  1230,    20,   864,    20,
     450,   451,    14,  1108,    31,    13,   872,    15,    20,   228,
     229,    13,  1231,  1232,  1233,  1234,  1235,  1236,    45,    46,
      10,    11,    13,    50,    51,   140,   141,    54,    41,   346,
     347,    58,    52,    53,    13,    62,  1231,  1232,  1233,  1234,
      13,   861,   427,   428,   998,   999,   412,   413,  1229,  1230,
      77,   489,   490,   491,   492,   493,  1235,  1236,    13,  1013,
    1014,  1015,  1016,  1017,  1018,  1019,  1020,  1021,  1022,  1023,
    1024,  1025,   168,  1027,   443,   444,    13,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    13,
      13,    13,    15,   489,   490,   491,   492,   493,    13,    13,
      13,   136,    19,   142,   220,   221,   222,   223,    31,    19,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,    45,    46,    13,    19,   173,    50,    51,    19,
      15,    54,    15,    19,    14,    58,    15,  1360,    19,    62,
    1363,    19,    13,    19,   418,   419,   420,    14,    14,    54,
     448,  1516,    54,   345,    77,    55,    54,    63,   176,    80,
      31,   238,   239,   240,   241,    20,    14,   441,    14,    14,
      20,    14,    14,    50,    45,    46,    13,    13,    13,    50,
      51,    13,    13,    54,    13,    13,    13,    58,    13,    13,
      13,    62,    13,    13,   271,    13,    13,    13,    13,    13,
      13,    13,   279,    13,  1044,    13,    77,  1047,  1048,  1049,
    1050,  1051,  1052,   290,  1054,  1055,    13,   294,    13,  1059,
    1060,  1061,  1062,  1063,  1064,  1065,    13,  1067,  1516,  1069,
      13,  1071,  1072,    13,  1074,  1075,  1076,  1077,  1078,   441,
     442,  1000,    13,  1083,  1084,  1085,  1086,    13,    13,    13,
     173,    13,  1226,  1227,  1228,    13,    13,    13,    13,    13,
     337,    13,   339,   340,   341,  1105,    13,    20,  1108,  1109,
     544,   545,    13,   350,   351,    13,    13,    13,    17,   356,
     357,   358,   359,    13,    19,    19,    13,    13,    13,    13,
      13,    13,    13,    13,   371,   372,   373,   374,   375,    13,
     377,   378,   173,   380,    19,    13,    13,    13,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,    23,    13,    13,    13,    13,  1453,    13,
      13,    31,    13,  1698,    34,    13,    13,    19,    13,    19,
      13,    13,    13,    13,  1103,    45,    46,    13,    13,    13,
      50,    51,    13,    13,    54,    13,    13,  1243,    58,    13,
      13,    13,    62,   637,   638,   639,   640,   641,   642,   643,
     644,   645,   646,   647,   648,   649,   409,    77,    13,    13,
      13,  1221,    13,  1223,  1224,    13,    13,    13,    13,    13,
      13,   665,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,  1247,  1693,    13,
      13,    13,    13,  1253,    13,    13,    13,    13,  1258,    13,
    1260,  1261,    13,  1263,  1264,  1265,  1266,    13,    13,  1269,
      13,    13,    13,   510,    13,    13,    13,    13,    13,    13,
      13,    13,    13,  1283,    13,    13,    13,    13,    13,    19,
     144,   136,  1292,    16,  1294,  1295,  1296,    18,    13,    19,
      13,  1301,  1302,  1303,  1304,  1305,  1306,  1307,    13,  1309,
      13,    13,    13,   173,    13,    13,    13,    13,    13,  1319,
    1320,  1321,  1322,  1323,  1324,  1325,  1326,  1327,  1328,  1329,
    1330,  1331,  1332,  1333,    13,    13,    13,    13,    13,  1339,
    1340,  1341,  1342,  1343,  1344,  1345,    13,    13,    13,    13,
      13,  1351,  1352,    13,  1354,    13,    15,    19,    14,    16,
      13,    65,    56,    14,    13,    20,    20,    19,    14,    19,
      14,    16,  1372,    14,  1374,    14,    16,    20,    16,    13,
    1380,  1381,  1382,    13,    13,    13,    13,    13,    13,  1389,
    1390,  1391,  1392,  1393,  1394,  1395,    13,  1397,  1398,    13,
    1400,  1401,  1402,  1403,  1404,  1405,    13,  1407,  1408,  1409,
    1410,  1411,  1412,  1413,  1414,    13,    13,  1417,    13,  1419,
    1420,    13,  1422,  1423,  1424,    13,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,    13,    13,    13,    13,    13,    13,    13,    13,  1449,
    1450,    13,    13,  1453,    13,  1455,    13,  1457,  1458,    13,
      13,    13,    13,    13,    13,    13,    13,  1467,    14,    63,
      13,    13,    13,    13,    13,    13,    13,   839,   840,    14,
      16,   843,   844,   845,   846,   847,   848,   849,   850,   851,
     852,   853,   854,   855,   856,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    14,   376,    14,    20,
      20,    20,  2037,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    14,    14,    20,    14,   407,   408,
     409,   410,   411,    14,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,    14,    14,    14,    13,
      20,    14,    65,    56,   998,   999,    13,    13,    20,    20,
      20,    20,    16,    13,    19,    14,    19,    13,    13,  1013,
    1014,  1015,  1016,  1017,  1018,  1019,  1020,  1021,  1022,  1023,
    1024,  1025,    31,  1027,    31,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    45,    46,    45,    46,
      13,    50,    51,    50,    51,    54,    13,    54,    13,    58,
      13,    58,    13,    62,    13,    62,    13,    13,    13,    13,
      13,    13,   501,    13,    13,    13,   998,   999,    77,    13,
      77,    13,    13,     7,    13,     9,    10,    11,    13,    13,
     519,  1013,  1014,  1015,  1016,  1017,  1018,  1019,  1020,  1021,
    1022,  1023,  1024,  1025,    13,  1027,    13,    31,    32,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    45,    46,    13,    13,    13,    50,    51,    13,    13,
      54,    13,    56,    13,    58,    59,    60,    61,    62,    63,
      64,    13,    66,    67,    13,    15,    13,    13,    13,    73,
      74,    13,    76,    77,    13,    13,    13,    20,    19,    13,
      16,    16,    12,    71,  1770,  1771,    14,    14,   220,   220,
      61,    16,    59,    14,   173,   346,   173,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,   504,    62,    13,
      60,  2144,    13,    71,    13,    13,   472,    60,  1768,   144,
    2153,    62,  2155,    62,   144,    20,   144,    20,   280,    71,
      14,   145,   146,   147,   148,   149,    13,    20,  1788,    75,
      20,    20,    20,  1227,  1228,    14,    20,    14,    20,    14,
      14,   165,    14,   348,    20,   350,    19,   352,   353,   173,
      20,   175,    20,    20,    20,   360,    14,    14,   363,   364,
     365,   366,   367,   368,   369,   370,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    20,    20,    20,    20,
      14,    20,    14,    20,    14,    14,   401,    20,    14,    20,
     405,   225,    20,    20,    14,   410,   411,    20,    20,    20,
      14,    14,  1872,  1873,  1874,  1875,   421,  1877,    14,  1879,
      14,   426,   427,    14,    14,  1885,  1886,  1887,    20,    14,
    1890,  1891,  1892,  1893,   258,  1895,   260,  1897,    20,  1899,
      19,    16,  1902,  1903,  1904,  1905,    20,    20,    20,  1909,
      20,    20,  1912,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,  1923,    20,  1925,    14,    20,    13,  1929,
    1930,    20,  1932,  1933,  1934,  1935,  1936,  1937,  1938,  1939,
    1940,  1941,  1942,  1943,    20,  1945,    20,    13,    13,    20,
      14,    20,    20,    20,  1954,  1955,  1956,  1957,  1958,  1959,
    1960,  1961,  1962,    20,    20,    20,    20,   331,   332,    20,
      14,    14,    14,    20,    14,    20,  1976,  1977,  1978,  1979,
      14,    20,    20,  1983,  1984,  1985,  1986,    20,    20,    20,
      20,    20,    20,  1993,  1994,  1995,  1996,  1997,  1998,  1999,
    2000,  2001,  2002,  2003,    20,    20,    20,    20,    20,    20,
      20,  2011,  2012,  2013,    20,  2015,  2016,    20,  2018,  2019,
      14,    14,  2022,    20,  2024,    20,   144,   400,    20,    20,
      20,    20,    20,    20,    20,  2035,    20,    20,  2038,   403,
     404,    20,    20,    14,    14,    14,  2046,  2047,  2048,    14,
      14,    14,    14,  2053,    20,    13,    57,    14,    13,  2059,
      20,    20,  2062,  2063,    20,  2065,  2066,  2067,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,    20,   443,
      20,  2081,    20,  2083,    20,    14,    14,    20,    13,   453,
     454,   455,   456,   457,   458,   459,   460,  2097,    13,   463,
     464,   465,   466,   467,   468,   469,    13,    13,    20,    14,
      14,    14,  2112,    14,  2114,    14,    14,    54,    20,  2119,
      20,   485,   486,    20,    20,  2125,    20,    20,    20,  2129,
    2130,    20,  2132,  2133,  2134,    20,  2136,  2137,    20,    20,
    2140,  2141,    20,  2143,    20,    16,    14,    20,    14,    14,
      20,    14,    14,    14,    14,    14,  2156,  2157,   442,    14,
    2160,    14,  2162,  2163,  2164,    14,   530,    14,    14,    14,
    2170,    14,    14,  2173,    14,  2175,    20,    14,    14,  2179,
    2180,  2181,    20,  2183,    14,    14,    14,    14,    14,  2189,
      14,    14,  2192,    14,  2194,    14,  2196,  2197,  2198,    14,
      20,    14,    20,    14,    14,    14,    14,  2207,  2208,    14,
      14,  2211,    14,    20,    14,    14,  2216,  2217,  2218,  2219,
    2220,  2221,    20,  2223,  2224,  2225,    14,  2227,  2228,  2229,
    2230,  2231,    14,    20,  2234,  2235,  2236,  2237,    14,  2239,
      20,    20,    20,    20,    14,   176,   177,   178,   179,   180,
     181,   182,   183,   184,  2637,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,    20,    20,    20,  2279,
      20,    20,    20,    57,    57,    57,    57,    20,    20,    14,
      20,   222,   223,    20,    20,    14,    14,    14,    14,    20,
      20,    14,    14,    14,    14,    20,    20,    14,    14,    14,
      14,    20,    20,    14,    14,    14,    14,    20,    20,    14,
      14,    14,    14,    20,    20,    14,    14,    14,    14,    20,
      14,   473,    22,    57,    71,    20,  1370,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    14,    20,    20,
      20,    20,    13,    16,    16,    14,    14,    22,    14,    16,
      20,    14,    14,    14,    14,    20,    14,    14,    14,    14,
     429,    20,  2418,  2419,    14,    14,    20,    20,    20,  2425,
      14,    14,    20,    20,    14,    14,    54,    14,    14,    20,
      14,    57,    20,  2393,    14,    20,    14,    20,    20,    20,
      14,    20,    75,    20,    20,    20,    14,    20,    14,    20,
      20,    14,    14,    20,    14,    20,    14,  2417,    14,    20,
      14,    20,    57,    20,   431,    20,    14,    20,    20,    20,
      20,    20,   430,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    14,    20,    20,
      20,    20,    20,    14,    20,    14,    20,    14,    14,    14,
      20,    14,    20,    14,    14,    14,    20,    14,    14,    14,
      22,    14,    20,    14,    14,  2475,    20,  2477,    20,  2479,
      14,  2481,    14,    14,    20,    20,  2486,  2487,    14,  2489,
    2490,  2491,  2492,    20,  2494,  2495,  2496,  2497,    20,    20,
      20,  2501,    14,    20,  2504,  2505,    20,    14,    14,    14,
    2510,    20,    20,    14,    14,  2515,    14,  2517,  2518,  2519,
    2520,  2521,  2522,  2523,  2524,    20,  2526,  2527,  2528,  2529,
    2530,  2531,  2532,  2533,  2534,  2535,  2536,  2537,  2538,  2539,
      20,  2541,    14,    14,    14,    14,    14,    14,    14,  2549,
      14,    14,    54,  2553,  2554,    20,    14,    14,    20,    14,
      14,    20,    14,  2563,  2564,    14,    14,    20,    14,    20,
      20,    14,    57,  2573,  2574,  2575,  2576,  2577,    20,  2579,
    2580,    20,  2582,  2583,    20,    20,  2505,  2587,  2588,  2508,
      20,    20,  2592,  2593,  2594,  2595,    20,    20,    20,    14,
      20,    57,    20,    20,    14,   144,    20,  2607,    20,    20,
      14,    20,    20,  2613,    20,    20,    19,  2617,    20,  2619,
    2620,    20,    20,    20,    20,    20,    20,    20,    20,  2629,
    2630,  2631,    14,    20,  2634,  2635,    20,    20,    14,    20,
      14,    14,    14,    14,    14,    20,    14,  2647,    14,  2649,
      14,  2651,  2652,    20,  2654,  2655,  2656,  2657,  2658,  2659,
    2660,  2661,    20,  2663,  2664,  2665,  2666,  2667,  2668,  2669,
    2670,  2671,    20,  2673,  2674,  2675,  2676,    20,    20,    20,
      20,    20,    14,    20,    20,    14,    20,  2687,  2688,  2689,
    2690,    14,    20,  2693,  2694,    20,    20,    14,    20,    20,
      20,    20,    20,    14,    20,    20,    20,    20,    20,    14,
      20,    20,    20,    20,    20,   149,    20,    20,    20,    20,
      20,    20,    20,    14,    20,    20,    20,    20,    20,    14,
      20,    20,    14,    14,    14,    14,    20,    20,  1237,  1239,
    1238,  1378,    20,    20,    20,    20,    20,    20,  2794,    14,
      20,    22,    20,    14,    20,    14,    20,    14,    20,    14,
      20,    14,    20,    14,    14,    14,    20,  1241,    20,    14,
      14,   149,    20,    20,    20,    14,    14,    20,    20,    20,
      20,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    14,   149,   149,   149,   149,   149,
      14,    20,    20,    20,    20,    20,    14,    14,    20,    14,
      20,    20,    14,    14,    20,    14,    20,    14,  1240,    14,
      20,    14,    20,    14,    20,    14,    20,    14,    20,   433,
      20,    14,    20,  2833,  2834,    20,  2836,  2837,    20,  2839,
    2840,    20,  2842,  2843,  2844,    20,  2846,  2847,    20,    20,
    2850,    20,    20,    20,    20,  2855,  2856,    20,  2858,    20,
    2860,    14,  2862,    22,  2864,  2865,  2866,  2867,  2868,    14,
      20,    20,  2872,  2873,  2874,  2875,  2876,  2877,    20,  2879,
    2880,  2881,  2882,  2883,  2884,  2885,    20,  2887,  2888,  2889,
    2890,  2891,    20,  2893,    20,    20,    20,    20,  2898,  2899,
      20,  2901,  2902,  2903,  2904,  2905,  2906,    14,  2908,  2909,
    2910,  2911,    14,  2913,    14,    14,    20,  2917,    14,  2919,
      14,  2921,    20,    20,  2924,    16,  2926,  2927,    20,  2929,
    2849,    14,    14,    14,  2853,    20,  2936,    14,  2938,    14,
      20,  2941,  2942,    14,    20,   432,    20,    20,    20,    14,
      20,    14,    20,    22,    20,    14,    20,  2957,  2958,  2959,
    2960,  2961,    20,    20,    20,    20,    14,  2967,  2968,  2969,
      20,    20,    14,    20,    20,    20,    20,    14,    14,    20,
      14,    14,    14,    14,    14,    14,  2037,    14,  1225,    14,
      14,    -1,    20,    14,    20,    14,    14,    20,    14,    14,
      20,    14,    14,    14,    -1,    14,    20,    14,   434,    14,
      20,    -1,    20,    14,    20,    -1,    20,  1080,    20,    22,
      20,    20,    20,    20,    20,    20,    14,    20,    20,    20,
      20,    20,    14,    20,    14,    20,    14,    20,    14,    20,
      14,    20,    14,    20,    14,    20,    14,    20,    14,    20,
      -1,    20,    -1,    20,    14,    20,    20,  3057,    20,    20,
    3060,  3061,  3062,    20,    20,    20,  3066,    20,  3068,  3069,
      14,    14,    14,    14,  3074,  3075,    14,  3077,    14,  3079,
    3080,  3081,  3082,  3083,  3084,    20,  3086,  3087,  3088,  3089,
    3090,  3091,  3092,    20,  3094,    20,    14,  3097,  3098,  3099,
    3100,  3101,    14,    20,    20,    20,    14,  3107,  3108,    20,
      20,  3111,    14,    20,    20,  3115,  3116,  3117,    14,    20,
    3120,    14,    20,    20,    14,    20,  3126,  3127,    14,    20,
    3130,  3131,    20,    14,  3134,    20,  3136,  3137,    20,    14,
    3140,  3141,    20,  3143,    14,  3145,  3146,  3147,    20,    20,
      14,    20,    20,    20,  3073,    20,    14,    20,    20,    20,
      14,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3207,  3208,  3209,
    3210,    -1,  3212,  3213,    -1,    -1,  3216,    -1,    -1,    -1,
      -1,    -1,    -1,  3223,    -1,  3225,    -1,  3227,    -1,    -1,
    3230,    -1,    -1,    -1,    -1,  3235,    -1,    -1,    -1,    -1,
    3240,  3241,    -1,  3243,    -1,  3245,    -1,  3247,  3248,  3249,
      -1,  3251,  3252,    -1,  3254,    -1,  3256,    -1,  3258,  3259,
    3260,    -1,    -1,  3263,  3264,  3265,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3302,    -1,    -1,    -1,  3306,  3307,    -1,    -1,
      -1,  3311,    -1,  3313,  3314,    -1,  3316,  3317,    -1,    -1,
      -1,  3321,    -1,    -1,  3324,  3325,  3326,    -1,  3328,  3329,
      -1,  3331,  3332,    -1,    -1,  3335,  3336,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3358,    -1,
      -1,    -1,    -1,    -1,  3364,  3365,  3366,    -1,    -1,    -1,
    3370,  3371,    -1,    -1,  3374,  3375,    -1,    -1,  3378,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3392,  3393,    -1,  3395,    -1,  3397,    -1,    -1,
    3400,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3410,    -1,  3412,  3413,  3414,    -1,     0,    -1,     2,     3,
       4,  3421,  3422,  3423,    -1,    -1,    -1,    -1,  3428,  3429,
    3430,    -1,    -1,    -1,    18,  3435,  3436,    21,    -1,  3439,
      24,    -1,    -1,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,    -1,
      -1,    -1,    -1,   127,   128,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   203,
     204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   246,    -1,   248,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   265,   266,    -1,   268,   269,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   279,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   288,   289,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   320,   321,   322,   323,
     324,   325,   326,   327,   328,    -1,    -1,    -1,    -1,   333,
     334,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,    -1,    -1,    -1,    -1,   349,   350,    -1,    -1,   353,
     354,   355,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   389,   390,    -1,    -1,    -1,
      -1,    -1,   396,    -1,   398,   399,   400,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   412,   413,
     414,   415,    -1,    -1,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   438,   439,    -1,   441,    -1,   443,
     444,    -1,    -1,   447,   448,    -1,    -1,    -1,    -1,    -1,
       7,    -1,     9,    10,    11,    -1,    13,   461,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    50,    51,    -1,    -1,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    -1,    -1,    82,    83,    84,    85,    -1,
      87,    88,    -1,    -1,   538,    -1,    -1,    -1,    -1,    -1,
     544,   545,   546,   547,   548,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,
     147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,   165,    -1,
      -1,    -1,    -1,    -1,    -1,   172,   173,   174,   175,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   637,   638,   639,   640,   641,   642,   643,
     644,   645,   646,   647,   648,   649,   650,    -1,    -1,    -1,
      -1,    -1,    -1,   210,   211,    -1,    -1,    -1,    -1,    -1,
      -1,   665,    -1,    -1,    -1,    -1,    -1,    -1,   225,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   258,    -1,   260,    -1,    -1,    -1,    -1,    -1,   266,
     267,   268,   269,   270,   271,    -1,   273,    -1,    -1,    -1,
     724,    -1,    -1,    -1,    -1,    -1,    -1,   731,   732,   733,
      -1,    -1,    -1,    -1,   738,   739,   740,   741,   742,   743,
     744,   745,   746,   747,   748,   749,   750,   751,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   314,   315,   316,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   329,   330,   331,   332,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   379,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   403,   404,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   862,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,    -1,   443,   444,    -1,    -1,
     447,    -1,    -1,    -1,    -1,    -1,   453,   454,   455,   456,
     457,   458,   459,   460,   908,    -1,   463,   464,   465,   466,
     467,   468,   469,    -1,   471,    -1,    -1,    -1,    -1,   476,
      -1,   478,   479,    -1,    -1,    -1,   483,   484,   485,   486,
     934,   488,    -1,    -1,   938,    -1,    -1,    -1,   495,   496,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   512,    -1,    -1,    -1,    -1,
     517,   518,    -1,   520,   521,   522,   523,   524,   525,   526,
     527,   528,   529,   530,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   988,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   998,   999,  1000,  1001,    -1,    -1,
      -1,    -1,    -1,    -1,  1008,    -1,    -1,    -1,    -1,  1013,
    1014,  1015,  1016,  1017,  1018,  1019,  1020,  1021,  1022,  1023,
    1024,  1025,    -1,  1027,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1040,    -1,    -1,    -1,
      -1,    -1,    -1,  1047,    -1,    -1,    -1,    -1,    -1,  1053,
      -1,    -1,  1056,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1066,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1090,    -1,  1092,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1103,
      -1,    -1,    -1,    -1,  1108,  1109,  1110,  1111,  1112,  1113,
    1114,  1115,  1116,  1117,  1118,  1119,  1120,  1121,  1122,  1123,
      -1,  1125,  1126,  1127,  1128,    -1,  1130,  1131,  1132,    -1,
      -1,  1135,  1136,  1137,  1138,  1139,  1140,  1141,  1142,  1143,
    1144,  1145,  1146,  1147,  1148,  1149,  1150,  1151,  1152,  1153,
    1154,  1155,  1156,  1157,  1158,  1159,  1160,  1161,  1162,  1163,
    1164,  1165,  1166,  1167,    -1,    -1,  1170,  1171,  1172,  1173,
    1174,  1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,
    1184,  1185,  1186,  1187,  1188,  1189,  1190,  1191,  1192,  1193,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1208,  1209,  1210,  1211,  1212,  1213,
      -1,  1215,  1216,  1217,  1218,  1219,    -1,  1221,    -1,  1223,
    1224,  1225,  1226,  1227,  1228,  1229,  1230,  1231,  1232,  1233,
    1234,  1235,  1236,  1237,  1238,  1239,  1240,  1241,    -1,    -1,
    1244,  1245,  1246,    -1,    -1,    -1,  1250,    -1,    -1,    -1,
      -1,    -1,    -1,  1257,    -1,    -1,    -1,    -1,  1262,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1277,    -1,    -1,  1280,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1291,    -1,  1293,
      -1,    -1,    -1,  1297,  1298,  1299,  1300,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1308,    -1,  1310,  1311,  1312,  1313,
    1314,  1315,  1316,  1317,  1318,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1334,    -1,  1336,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1346,  1347,  1348,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1357,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1375,  1376,  1377,    -1,    -1,    -1,    -1,    -1,    -1,
    1384,  1385,    -1,  1387,  1388,  1389,  1390,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1406,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1415,  1416,    -1,  1418,    -1,    -1,  1421,    -1,    -1,
      -1,  1425,  1426,    -1,    -1,    -1,  1430,  1431,  1432,  1433,
    1434,  1435,    -1,  1437,    -1,    -1,  1440,  1441,    -1,  1443,
    1444,  1445,  1446,  1447,    -1,    -1,    -1,  1451,    -1,  1453,
    1454,    -1,    -1,    -1,    -1,  1459,  1460,  1461,    -1,  1463,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1516,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     0,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1626,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1695,    -1,    -1,  1698,    -1,    -1,    -1,  1702,  1703,
    1704,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   165,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1753,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1769,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1788,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   285,    -1,    -1,   288,
     289,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1867,    -1,    -1,    -1,  1871,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1883,
    1884,   320,   321,   322,   323,   324,   325,   326,   327,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   335,   336,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1911,    -1,  1913,
      -1,    -1,    -1,   352,    -1,   354,  1920,    -1,    -1,    -1,
      -1,    -1,    -1,  1927,  1928,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1946,  1947,  1948,  1949,  1950,  1951,  1952,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1966,    -1,  1968,  1969,  1970,  1971,  1972,    -1,
    1974,  1975,    -1,    -1,    -1,    -1,  1980,  1981,    -1,    -1,
      -1,    -1,    -1,  1987,  1988,    -1,    -1,  1991,  1992,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   438,
     439,    -1,   441,   442,   443,   444,    -1,    -1,   447,   448,
      -1,    -1,    -1,  2017,    -1,    -1,  2020,    -1,    -1,    -1,
      -1,  2025,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2037,    -1,  2039,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2051,    -1,    -1,
    2054,  2055,  2056,  2057,  2058,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2073,
      -1,    -1,    -1,    -1,    -1,  2079,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2100,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   544,   545,   546,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2132,    -1,
      -1,    -1,    -1,    -1,  2138,  2139,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2159,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   637,   638,
     639,   640,   641,   642,   643,   644,   645,   646,   647,   648,
     649,   650,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   665,    -1,    -1,    -1,
      -1,    -1,    -1,  2237,  2238,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   731,   732,   733,    -1,    -1,    -1,    -1,   738,
     739,   740,   741,   742,   743,   744,   745,   746,   747,   748,
     749,   750,   751,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     839,   840,   841,    -1,   843,   844,   845,   846,   847,   848,
     849,   850,   851,   852,   853,   854,   855,   856,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2471,  2472,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2504,    -1,    -1,    -1,  2508,  2509,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2526,  2527,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     0,    -1,  2542,  2543,
    2544,  2545,  2546,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,  2559,    -1,    -1,  2562,   998,
     999,  1000,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1013,  1014,  1015,  1016,  1017,  1018,
    1019,  1020,  1021,  1022,  1023,  1024,  1025,    -1,  1027,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2603,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2616,    -1,    -1,    -1,    -1,    -1,  2622,    -1,
    2624,    -1,  2626,    -1,  2628,    -1,    -1,  1066,  2632,  2633,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2648,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1108,
    1109,    -1,  1111,  1112,    -1,  2679,    -1,    -1,    -1,  1118,
      -1,  2685,    -1,    -1,    -1,   149,    -1,  2691,  2692,    -1,
      -1,  1130,  1131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1144,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1158,
    1159,  1160,  1161,  1162,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1185,    -1,    -1,    -1,
      -1,    -1,    -1,  1192,  1193,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1208,
    1209,  1210,    -1,  1212,  1213,    -1,  1215,  1216,  1217,  1218,
      -1,    -1,  1221,    -1,  1223,    -1,  1225,  1226,  1227,  1228,
    1229,  1230,  1231,  1232,  1233,  1234,  1235,  1236,  1237,  1238,
    1239,  1240,  1241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   282,   283,
      -1,    -1,    -1,    -1,   288,   289,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1277,    -1,
      -1,  1280,    -1,    -1,    -1,  2849,    -1,    -1,    -1,  2853,
      -1,    -1,    -1,    -1,    -1,    -1,   320,   321,   322,   323,
     324,   325,   326,   327,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   335,   336,    -1,    -1,  2879,  2880,  2881,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2892,    -1,
     354,    -1,    -1,    -1,    -1,    -1,    -1,  1336,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2915,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2931,  2932,    -1,
      -1,    -1,    -1,  2937,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2965,    -1,    -1,    -1,    -1,    -1,  1406,    -1,    -1,
      -1,    -1,    -1,    -1,   438,   439,    -1,  1416,    -1,  1418,
      -1,    -1,   446,   447,   448,    -1,  1425,    -1,    -1,    -1,
      -1,  1430,  1431,  1432,    -1,  1434,    -1,    -1,    -1,    -1,
      -1,  1440,    -1,    -1,  1443,  1444,  1445,  1446,  1447,    -1,
      -1,    -1,    -1,    -1,  1453,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3070,    -1,    -1,  3073,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1516,    -1,    -1,
     544,   545,   546,   547,    -1,    -1,    -1,    -1,  3092,    -1,
    3094,    -1,    -1,  3097,  3098,    -1,    -1,    -1,  3102,  3103,
    3104,  3105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3133,
      -1,  3135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   637,   638,   639,   640,   641,   642,   643,
     644,   645,   646,   647,   648,   649,   650,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   665,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3253,
      -1,  3255,    -1,    -1,    -1,    -1,  1695,    -1,  3262,  1698,
      -1,    -1,    -1,  1702,    -1,    -1,    -1,   731,   732,   733,
      -1,    -1,    -1,    -1,   738,   739,   740,   741,   742,   743,
     744,   745,   746,   747,   748,   749,   750,   751,  3292,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3305,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1753,    -1,  3320,    -1,    -1,  3323,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1788,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3372,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3380,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3398,    -1,    -1,    -1,  3402,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1913,    -1,    -1,    -1,    -1,    -1,
      -1,  1920,    -1,    -1,    -1,    -1,    -1,    -1,  1927,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1948,
    1949,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   998,   999,  1000,    -1,    -1,    -1,
      -1,  1980,  1981,    -1,    -1,    -1,    -1,    -1,    -1,  1013,
    1014,  1015,  1016,  1017,  1018,  1019,  1020,  1021,  1022,  1023,
    1024,  1025,    -1,  1027,    22,    23,    24,    -1,    -1,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2025,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,  2037,    -1,
      -1,    -1,  1066,    -1,    -1,    -1,    -1,    -1,    -1,  1073,
      -1,    -1,    -1,    -1,    -1,  1079,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2073,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1108,  1109,    -1,  1111,  1112,    -1,
      -1,    -1,    -1,    -1,  1118,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1130,  1131,    -1,   127,
     128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2132,  1158,  1159,  1160,  1161,  1162,    -1,
      -1,    -1,    -1,    -1,  1168,  1169,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1185,    -1,    -1,    -1,    -1,    -1,    -1,  1192,  1193,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1208,  1209,  1210,    -1,  1212,  1213,
      -1,  1215,  1216,  1217,  1218,    -1,    -1,  1221,    -1,  1223,
      -1,  1225,  1226,  1227,  1228,  1229,  1230,  1231,  1232,  1233,
    1234,  1235,  1236,  1237,  1238,  1239,  1240,  1241,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,    -1,
     248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2237,  2238,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   265,   266,    -1,
      -1,    -1,    -1,  1277,    -1,    -1,  1280,    -1,    -1,    -1,
      -1,   279,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     288,   289,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1336,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   353,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   288,   289,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   390,    -1,    -1,    -1,    -1,    -1,   396,    -1,
      -1,    -1,  1406,   320,   321,   322,   323,   324,   325,   326,
     327,    -1,  1416,    -1,  1418,    -1,   414,   415,   335,   336,
      -1,  1425,    -1,  1427,  1428,  1429,  1430,  1431,  1432,    -1,
    1434,    -1,  1436,    -1,  1438,  1439,  1440,   354,    -1,  1443,
    1444,  1445,  1446,  1447,    -1,    -1,    -1,    -1,    -1,  1453,
     448,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1516,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   438,   439,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     447,   448,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   537,
     538,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     548,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2559,    -1,    -1,  2562,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1626,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2622,    -1,  2624,    -1,  2626,    -1,  2628,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1693,
      -1,  1695,    -1,    -1,  1698,    -1,    -1,    -1,  1702,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2685,    -1,    -1,    -1,
      -1,    -1,  2691,  2692,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   724,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1753,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1788,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   862,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1913,
     908,    -1,    -1,    -1,    -1,    -1,  1920,    -1,    -1,    -1,
      -1,    -1,    -1,  1927,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   934,    -1,    -1,    -1,
     938,    -1,    -1,    -1,  1948,  1949,    -1,    -1,    -1,    -1,
      -1,    -1,  2931,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1980,  1981,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2965,    -1,    -1,    -1,
     988,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1001,    -1,    -1,    -1,    -1,    -1,    -1,
    1008,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2025,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2037,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1040,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2073,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1090,    -1,  1092,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1103,    -1,    -1,    -1,    -1,
    1108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2132,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1066,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3144,    -1,    -1,    -1,    -1,
      -1,    -1,  1170,  1171,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1108,  1109,    -1,  1111,  1112,    -1,    -1,    -1,    -1,
      -1,  1118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1130,  1131,    -1,    -1,    -1,    -1,    -1,
      -1,  1219,    -1,  1221,    -1,    -1,    -1,  1144,    -1,    -1,
      -1,    -1,    -1,  2237,  2238,    -1,    -1,    -1,    -1,    -1,
      -1,  1158,  1159,  1160,  1161,  1162,  1244,  1245,  1246,    -1,
      -1,    -1,  1250,    -1,    -1,    -1,    -1,    -1,    -1,  1257,
      -1,    -1,    -1,    -1,  1262,    -1,    -1,    -1,  1185,    -1,
      -1,    -1,    -1,    -1,    -1,  1192,  1193,    -1,    -1,    -1,
      -1,    -1,    -1,  3262,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1208,  1209,  1210,    -1,  1212,  1213,    -1,  1215,  1216,
    1217,  1218,    -1,    -1,  1221,    -1,  1223,    -1,    -1,    -1,
      -1,    -1,    -1,  3292,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3320,    -1,    -1,  3323,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1357,
    1277,    -1,    -1,  1280,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1375,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1384,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3380,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1336,
      -1,    -1,    -1,  3402,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1433,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1441,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1451,    -1,  1453,  1454,    -1,    -1,    -1,
      -1,  1459,  1460,  1461,    -1,  1463,    -1,    -1,    -1,  1467,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1406,
       7,    -1,    -1,    10,    11,    -1,    13,    -1,    -1,  1416,
      -1,  1418,    -1,    -1,    -1,    -1,    -1,    -1,  1425,    -1,
      -1,    -1,    -1,  1430,  1431,  1432,    -1,  1434,    35,    36,
      -1,    -1,    -1,  1440,    -1,    -1,  1443,  1444,  1445,  1446,
    1447,    -1,    -1,    -1,    -1,    -1,  1453,    -1,    -1,    -1,
      -1,    58,    -1,    -1,    -1,    -1,    63,    64,    65,    -1,
      -1,    -1,    -1,    70,    -1,  2559,    -1,    -1,  2562,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2622,    -1,
    2624,    -1,  2626,    -1,  2628,    -1,    -1,    -1,    -1,   146,
      -1,    -1,    -1,   150,   151,   152,   153,   154,   155,   156,
     157,    -1,   159,    -1,   161,   162,   163,   164,   165,   166,
     167,    -1,   169,   170,    -1,    -1,    -1,    -1,   175,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2685,    -1,    -1,    -1,    -1,    -1,  2691,  2692,    -1,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,    -1,    -1,    -1,    -1,   224,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,    -1,   259,    -1,   261,   262,   263,   264,   265,    -1,
      -1,    -1,    -1,    -1,    -1,   272,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   281,   282,   283,   284,    -1,    -1,
      -1,  1769,   289,    -1,    -1,    -1,   293,    -1,  1695,    -1,
      -1,    -1,    -1,    -1,    -1,  1702,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   310,   311,   312,   313,    -1,    -1,    -1,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   343,   344,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1753,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1867,
      -1,  1788,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,    -1,    -1,  2931,   445,   446,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   455,   456,
     457,   458,   459,   460,    -1,    -1,   463,   464,   465,   466,
     467,   468,   469,   470,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2965,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     487,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     497,   498,   499,   500,    -1,   502,   503,    -1,    -1,    -1,
    1988,   508,   509,    -1,    -1,    -1,  1913,   514,   515,   516,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1927,    -1,    -1,   530,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1948,  1949,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2047,
    2048,    -1,    -1,  2051,    -1,  2053,  2054,  2055,  2056,  2057,
    2058,    -1,    -1,  1980,  1981,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     0,    -1,    -1,    -1,  2025,    -1,
      -1,     7,    -1,     9,    10,    11,    -1,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
    3144,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    50,    51,    -1,    -1,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    -1,    -1,    82,    83,    84,    85,
      -1,    87,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2132,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     7,    -1,     9,    10,    11,    -1,    13,    -1,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,  3262,    -1,
      -1,    -1,    -1,    -1,   160,    -1,    32,    -1,    -1,   165,
      -1,    -1,    -1,    -1,    -1,    -1,   172,   173,   174,   175,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3292,    -1,
      56,    -1,    58,    59,    60,    61,    -1,    63,    64,    -1,
      66,    67,    -1,    -1,    -1,    -1,    -1,    73,    74,    -1,
      76,    77,    -1,    -1,   210,   211,  3320,    -1,    -1,  3323,
    2237,  2238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   258,    -1,   260,    -1,    -1,    -1,    -1,    -1,
     266,   267,   268,   269,   270,   271,  3380,   273,    -1,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,     7,    -1,
       9,    10,    11,    -1,    13,    -1,    -1,    -1,  3402,   165,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,   314,   315,
     316,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   329,   330,   331,   332,    56,    -1,    58,
      59,    60,    61,    -1,    63,    64,    -1,    66,    67,    -1,
      -1,    -1,    -1,    -1,    73,    74,    -1,    76,    77,   225,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2471,  2472,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   379,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   258,    -1,   260,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   403,   404,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,    -1,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   165,   443,   444,    -1,
      -1,   447,    -1,    -1,    -1,    -1,   175,   453,   454,   455,
     456,   457,   458,   459,   460,   331,   332,   463,   464,   465,
     466,   467,   468,   469,    -1,   471,    -1,    -1,    -1,    -1,
     476,    -1,   478,   479,    -1,    -1,    -1,   483,   484,   485,
     486,    -1,   488,    -1,    -1,    -1,    -1,    -1,    -1,   495,
     496,    -1,    -1,    -1,    -1,  2603,   225,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   512,    -1,    -1,    -1,
      -1,   517,   518,    -1,   520,   521,   522,   523,   524,   525,
     526,   527,   528,   529,   530,    -1,    -1,   403,   404,   258,
      -1,   260,  2559,    -1,    -1,  2562,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,    -1,   443,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   453,   454,   455,
     456,   457,   458,   459,   460,    -1,    -1,   463,   464,   465,
     466,   467,   468,   469,    -1,  2622,    -1,  2624,    -1,  2626,
      -1,  2628,   331,   332,    -1,    -1,    -1,    -1,    -1,   485,
     486,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   530,    -1,    -1,    -1,  2685,    -1,
      -1,    -1,    -1,    -1,  2691,  2692,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,    -1,   443,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   453,   454,   455,   456,   457,   458,
     459,   460,    -1,    -1,   463,   464,   465,   466,   467,   468,
     469,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   485,   486,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   530,    -1,    -1,    -1,    -1,    -1,  2915,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,
       9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2931,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    -1,    -1,    35,    36,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,
      -1,    50,    51,    -1,    -1,    54,    -1,    56,  2965,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    -1,    -1,    73,    74,    75,    76,    77,    -1,
      -1,    -1,  3070,    -1,    -1,    -1,    -1,    86,    -1,    -1,
      89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,    -1,
     159,    -1,   161,   162,   163,   164,   165,   166,   167,    -1,
     169,   170,    -1,    -1,   173,    -1,   175,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,    -1,    -1,    -1,  3212,   224,   225,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3144,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,    -1,    -1,    -1,
      -1,    -1,    -1,   272,    -1,    -1,    -1,   276,   277,   278,
      -1,    -1,   281,   282,   283,   284,   285,   286,   287,   288,
     289,    -1,    -1,   292,   293,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   310,   311,   312,   313,    -1,    -1,  3305,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
      -1,    -1,   331,   332,   333,    -1,    -1,   336,   337,   338,
     339,    -1,   341,   342,   343,   344,   345,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3262,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3292,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   402,   403,   404,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3320,    -1,    -1,  3323,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,    -1,   443,    -1,   445,   446,    -1,   448,
      -1,    -1,    -1,    -1,   453,   454,   455,   456,   457,   458,
     459,   460,    -1,    -1,   463,   464,   465,   466,   467,   468,
     469,   470,    -1,  3380,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   485,   486,   487,    -1,
      -1,    -1,    -1,    -1,    -1,  3402,    -1,    -1,   497,   498,
     499,   500,    -1,   502,   503,    -1,   505,   506,   507,   508,
     509,    -1,   511,    -1,   513,   514,   515,   516,     7,    -1,
       9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,   530,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    -1,    -1,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,
      -1,    50,    51,    -1,    -1,    54,    -1,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      -1,    70,    -1,    -1,    73,    74,    -1,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,    -1,
     159,    -1,   161,   162,   163,   164,   165,   166,   167,    -1,
     169,   170,    -1,    -1,   173,    -1,   175,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,    -1,    -1,    -1,    -1,   224,   225,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,    -1,    -1,    -1,
      -1,    -1,    -1,   272,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   281,   282,   283,   284,    -1,    -1,    -1,    -1,
     289,    -1,    -1,    -1,   293,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   310,   311,   312,   313,    -1,    -1,    -1,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
      -1,    -1,   331,   332,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   343,   344,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   403,   404,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,    -1,   443,    -1,   445,   446,    -1,    -1,
      -1,    -1,    -1,    -1,   453,   454,   455,   456,   457,   458,
     459,   460,    -1,    -1,   463,   464,   465,   466,   467,   468,
     469,   470,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   485,   486,   487,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   497,   498,
     499,   500,    -1,   502,   503,    -1,    -1,    -1,    -1,   508,
     509,    -1,    -1,    -1,    -1,   514,   515,   516,     7,    -1,
       9,    10,    11,    -1,    13,    -1,    -1,    -1,    17,    -1,
      -1,   530,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    -1,    -1,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,
      -1,    50,    51,    -1,    -1,    54,    -1,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      -1,    70,    -1,    -1,    73,    74,    -1,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,    -1,
     159,    -1,   161,   162,   163,   164,   165,   166,   167,    -1,
     169,   170,    -1,    -1,   173,    -1,   175,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,    -1,    -1,    -1,    -1,   224,   225,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,    -1,    -1,    -1,
      -1,    -1,    -1,   272,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   281,   282,   283,   284,    -1,    -1,    -1,    -1,
     289,    -1,    -1,    -1,   293,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   310,   311,   312,   313,    -1,    -1,    -1,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
      -1,    -1,   331,   332,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   343,   344,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,    -1,   443,    -1,   445,   446,    -1,    -1,
      -1,    -1,    -1,    -1,   453,   454,   455,   456,   457,   458,
     459,   460,    -1,    -1,   463,   464,   465,   466,   467,   468,
     469,   470,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   485,   486,   487,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   497,   498,
     499,   500,    -1,   502,   503,    -1,    -1,    -1,    -1,   508,
     509,    -1,    -1,    -1,    -1,   514,   515,   516,     7,    -1,
       9,    10,    11,    -1,    13,    -1,    -1,    -1,    17,    -1,
      -1,   530,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    -1,    -1,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,
      -1,    50,    51,    -1,    -1,    54,    -1,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      -1,    70,    -1,    -1,    73,    74,    -1,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,    -1,
     159,    -1,   161,   162,   163,   164,   165,   166,   167,    -1,
     169,   170,    -1,    -1,   173,    -1,   175,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,    -1,    -1,    -1,    -1,   224,   225,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,    -1,    -1,    -1,
      -1,    -1,    -1,   272,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   281,   282,   283,   284,    -1,    -1,    -1,    -1,
     289,    -1,    -1,    -1,   293,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   310,   311,   312,   313,    -1,    -1,    -1,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
      -1,    -1,   331,   332,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   343,   344,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,    -1,   443,    -1,   445,   446,    -1,    -1,
      -1,    -1,    -1,    -1,   453,   454,   455,   456,   457,   458,
     459,   460,    -1,    -1,   463,   464,   465,   466,   467,   468,
     469,   470,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   485,   486,   487,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   497,   498,
     499,   500,    -1,   502,   503,    -1,    -1,    -1,    -1,   508,
     509,    -1,    -1,    -1,    -1,   514,   515,   516,     7,    -1,
       9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,   530,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    -1,    -1,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,
      -1,    50,    51,    -1,    -1,    54,    -1,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      -1,    70,    -1,    -1,    73,    74,    -1,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,    -1,
     159,    -1,   161,   162,   163,   164,   165,   166,   167,    -1,
     169,   170,    -1,    -1,   173,    -1,   175,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,    -1,    -1,    -1,    -1,   224,   225,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,    -1,    -1,    -1,
      -1,    -1,    -1,   272,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   281,   282,   283,   284,    -1,    -1,    -1,    -1,
     289,    -1,    -1,    -1,   293,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   310,   311,   312,   313,    -1,    -1,    -1,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
      -1,    -1,   331,   332,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   343,   344,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,    -1,   443,    -1,   445,   446,    -1,    -1,
      -1,    -1,    -1,    -1,   453,   454,   455,   456,   457,   458,
     459,   460,    -1,    -1,   463,   464,   465,   466,   467,   468,
     469,   470,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   485,   486,   487,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   497,   498,
     499,   500,    -1,   502,   503,    -1,    -1,    -1,    -1,   508,
     509,    -1,    -1,    -1,    -1,   514,   515,   516,     7,    -1,
       9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,   530,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    58,
      59,    60,    61,    -1,    63,    64,    65,    66,    67,    -1,
      -1,    70,    -1,    -1,    73,    74,    -1,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,    -1,
     159,    -1,   161,   162,   163,   164,   165,   166,   167,    -1,
     169,   170,    -1,    -1,    -1,    -1,   175,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,    -1,    -1,    -1,    -1,   224,   225,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,    -1,    -1,    -1,
      -1,    -1,    -1,   272,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   281,   282,   283,   284,    -1,    -1,    -1,    -1,
     289,    -1,    -1,    -1,   293,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   310,   311,   312,   313,    -1,    -1,    -1,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
      -1,    -1,   331,   332,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   343,   344,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   403,   404,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,    -1,   443,    -1,   445,   446,    -1,    -1,
      -1,    -1,    -1,    -1,   453,   454,   455,   456,   457,   458,
     459,   460,    -1,    -1,   463,   464,   465,   466,   467,   468,
     469,   470,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   485,   486,   487,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   497,   498,
     499,   500,    -1,   502,   503,    -1,    -1,    -1,    -1,   508,
     509,    -1,    -1,    -1,    -1,   514,   515,   516,     7,    -1,
       9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,   530,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    58,
      59,    60,    61,    -1,    63,    64,    65,    66,    67,    -1,
      -1,    70,    -1,    -1,    73,    74,    -1,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,    -1,
     159,    -1,   161,   162,   163,   164,   165,   166,   167,    -1,
     169,   170,    -1,    -1,    -1,    -1,   175,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,    -1,    -1,    -1,    -1,   224,   225,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,    -1,    -1,    -1,
      -1,    -1,    -1,   272,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   281,   282,   283,   284,    -1,    -1,    -1,    -1,
     289,    -1,    -1,    -1,   293,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   310,   311,   312,   313,    -1,    -1,    -1,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
      -1,    -1,   331,   332,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   343,   344,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,    -1,   443,    -1,   445,   446,    -1,    -1,
      -1,    -1,    -1,    -1,   453,   454,   455,   456,   457,   458,
     459,   460,    -1,    -1,   463,   464,   465,   466,   467,   468,
     469,   470,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   485,   486,   487,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   497,   498,
     499,   500,    -1,   502,   503,    -1,    -1,    -1,    -1,   508,
     509,    -1,    -1,    -1,    -1,   514,   515,   516,     7,    -1,
       9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,   530,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    58,
      59,    60,    61,    -1,    63,    64,    65,    66,    67,    -1,
      -1,    70,    -1,    -1,    73,    74,    -1,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,    -1,
     159,    -1,   161,   162,   163,   164,   165,   166,   167,    -1,
     169,   170,    -1,    -1,    -1,    -1,   175,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,    -1,    -1,    -1,    -1,   224,   225,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,    -1,    -1,    -1,
      -1,    -1,    -1,   272,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   281,   282,   283,   284,    -1,    -1,    -1,    -1,
     289,    -1,    -1,    -1,   293,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   310,   311,   312,   313,    -1,    -1,    -1,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
      -1,    -1,   331,   332,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   343,   344,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     7,    -1,    -1,    10,    11,    -1,    13,    -1,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,    -1,   443,    -1,   445,   446,    -1,    35,
      36,    -1,    -1,    -1,   453,   454,   455,   456,   457,   458,
     459,   460,    -1,    -1,   463,   464,   465,   466,   467,   468,
     469,   470,    58,    -1,    -1,    -1,    -1,    63,    64,    65,
      -1,    -1,    -1,    -1,    70,    -1,   485,   486,   487,    -1,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,   497,   498,
     499,   500,    -1,   502,   503,    -1,    -1,    -1,    -1,   508,
     509,    -1,    -1,    -1,    -1,   514,   515,   516,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   530,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     146,    -1,    -1,    -1,   150,   151,   152,   153,   154,   155,
     156,   157,    -1,   159,    -1,   161,   162,   163,   164,   165,
     166,   167,    -1,   169,   170,    -1,    -1,    -1,    -1,   175,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,    -1,    -1,    -1,    -1,   224,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,   259,    -1,   261,   262,   263,   264,   265,
      -1,    -1,    -1,    -1,    -1,    -1,   272,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   281,   282,   283,   284,    -1,
      -1,    -1,    -1,   289,    -1,    -1,    -1,   293,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   310,   311,   312,   313,    -1,    -1,
      -1,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   343,   344,   345,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     7,    -1,    -1,    10,    11,    -1,
      13,    -1,   428,   429,   430,   431,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   445,
     446,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,   455,
     456,   457,   458,   459,   460,    -1,    -1,   463,   464,   465,
     466,   467,   468,   469,   470,    58,    -1,    -1,    -1,    -1,
      63,    64,    65,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      -1,   487,    -1,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,   497,   498,   499,   500,    -1,   502,   503,    -1,    -1,
      -1,    -1,   508,   509,    -1,    -1,    -1,    -1,   514,   515,
     516,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   530,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   146,    -1,    -1,    -1,   150,   151,   152,
     153,   154,   155,   156,   157,    -1,   159,    -1,   161,   162,
     163,   164,   165,   166,   167,    -1,   169,   170,    -1,    -1,
      -1,    -1,   175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,    -1,    -1,    -1,
      -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,    -1,   261,   262,
     263,   264,   265,    -1,    -1,    -1,    -1,    -1,    -1,   272,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   281,   282,
     283,   284,    -1,    -1,    -1,    -1,   289,    -1,    -1,    -1,
     293,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   310,   311,   312,
     313,    -1,    -1,    -1,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     343,   344,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,    -1,
      10,    11,    -1,    13,    -1,   428,   429,   430,   431,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   445,   446,    -1,    35,    36,    -1,    -1,    -1,
      -1,    -1,   455,   456,   457,   458,   459,   460,    -1,    -1,
     463,   464,   465,   466,   467,   468,   469,   470,    58,    -1,
      -1,    -1,    -1,    63,    64,    65,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,   487,    -1,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,   497,   498,   499,   500,    -1,   502,
     503,    -1,    -1,    -1,    -1,   508,   509,    -1,    -1,    -1,
      -1,   514,   515,   516,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   530,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   146,    -1,    -1,    -1,
     150,   151,   152,   153,   154,   155,   156,   157,    -1,   159,
      -1,   161,   162,   163,   164,   165,   166,   167,    -1,   169,
     170,    -1,    -1,    -1,    -1,   175,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
      -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,    -1,   259,
      -1,   261,   262,   263,   264,   265,    -1,    -1,    -1,    -1,
      -1,    -1,   272,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   281,   282,   283,   284,    -1,    -1,    -1,    -1,   289,
      -1,    -1,    -1,   293,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     310,   311,   312,   313,    -1,    -1,    -1,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   343,   344,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     7,    -1,     9,    10,    11,    -1,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    -1,    -1,    -1,    50,    51,    -1,    -1,    54,
      -1,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    73,    74,
      -1,    76,    77,    -1,    -1,    -1,    -1,    -1,   428,   429,
     430,   431,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   445,   446,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   455,   456,   457,   458,   459,
     460,    -1,    -1,   463,   464,   465,   466,   467,   468,   469,
     470,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   487,    -1,    -1,
     145,   146,   147,   148,   149,    -1,    -1,   497,   498,   499,
     500,    -1,   502,   503,    -1,    -1,    -1,    -1,   508,   509,
     165,    -1,    -1,    -1,   514,   515,   516,    -1,   173,    -1,
     175,    -1,     7,    -1,     9,    10,    11,    -1,    13,    -1,
     530,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    -1,    -1,    -1,    50,    51,    -1,    -1,    54,
     225,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    73,    74,
      -1,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   258,    -1,   260,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   331,   332,    -1,    -1,
     165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   173,    -1,
     175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   258,    -1,   260,    -1,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,    -1,   443,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   453,   454,
     455,   456,   457,   458,   459,   460,    -1,    -1,   463,   464,
     465,   466,   467,   468,   469,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     485,   486,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   331,   332,     7,    -1,
       9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    -1,   530,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,
      -1,    50,    51,    -1,    -1,    54,    -1,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    -1,    66,    67,    -1,
      -1,    -1,    -1,    -1,    73,    74,    -1,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,    -1,   443,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   453,   454,
     455,   456,   457,   458,   459,   460,    -1,    -1,   463,   464,
     465,   466,   467,   468,   469,    -1,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     485,   486,    -1,    -1,    -1,    -1,   165,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   173,    -1,   175,    -1,     7,    -1,
       9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    -1,   530,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   225,    56,    -1,    58,
      59,    60,    61,    -1,    63,    64,    -1,    66,    67,    -1,
      -1,    -1,    -1,    -1,    73,    74,    -1,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   258,
      -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   331,   332,    -1,    -1,   165,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   175,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   258,
      -1,   260,    -1,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,    -1,   443,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   453,   454,   455,   456,   457,   458,
     459,   460,    -1,    -1,   463,   464,   465,   466,   467,   468,
     469,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   485,   486,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   331,   332,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   530,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,    -1,   443,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   453,   454,   455,   456,   457,   458,
     459,   460,    -1,    -1,   463,   464,   465,   466,   467,   468,
     469,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   485,   486,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   530
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  Parser::yystos_[] =
  {
         0,     7,     9,    10,    11,    13,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    50,
      51,    54,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    82,    83,    84,    85,
      87,    88,   145,   146,   147,   148,   149,   160,   165,   172,
     173,   174,   175,   210,   211,   225,   258,   260,   266,   267,
     268,   269,   270,   271,   273,   314,   315,   316,   329,   330,
     331,   332,   379,   403,   404,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   443,   444,   447,   453,   454,
     455,   456,   457,   458,   459,   460,   463,   464,   465,   466,
     467,   468,   469,   471,   476,   478,   479,   483,   484,   485,
     486,   488,   495,   496,   512,   517,   518,   520,   521,   522,
     523,   524,   525,   526,   527,   528,   529,   530,   532,   533,
     534,   535,   536,   537,   540,   541,   542,   543,   547,   548,
     549,   550,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   594,   595,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   614,   615,    10,    11,    13,    59,    60,    61,    63,
      64,    66,    67,    73,    74,    76,    77,   165,   175,   455,
     456,   457,   458,   459,   460,   463,   464,   465,   466,   467,
     468,   469,   557,   558,   573,   612,    66,   558,   598,   558,
     598,    62,   571,   572,   573,   611,    13,    13,    13,   482,
     573,   612,    54,    68,    69,    70,   614,   573,   550,   571,
     611,   550,   571,   550,   573,    13,    13,   550,    13,    13,
     133,   134,   144,   133,   134,   144,   133,   134,   144,   144,
      19,    19,   124,   125,    13,   144,    19,   144,    13,    13,
     534,   614,   238,    19,    19,    15,   123,    15,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    69,    71,    72,
      73,    74,    75,    76,    77,   573,   615,   550,    13,    13,
      13,    13,    15,    13,    13,    15,    13,    15,    13,    19,
      19,    19,    19,    13,    13,    13,    15,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,   558,   598,   558,   598,
     558,   598,   558,   598,   558,   598,   558,   598,   558,   598,
     558,   598,   558,   598,   558,   598,   558,   598,   558,   598,
     558,   598,   614,   551,   552,   571,   534,   550,   550,    13,
      13,    13,    71,   614,   614,    13,    13,    13,    13,    13,
      13,     0,     0,   534,   535,   536,   537,   540,   541,   542,
     543,   534,    10,    11,   140,   141,   558,   598,     7,     8,
      12,    10,    11,     5,     6,   138,   139,   140,   141,    17,
       4,    18,   136,    21,   137,    13,    15,    19,   123,   144,
     142,     7,   143,    10,    11,    19,   123,   123,   144,    19,
      19,    19,    19,    15,    15,    19,    19,    13,    19,    19,
      14,    14,    19,    14,   550,   571,   550,    19,   550,   550,
      76,   615,   615,   571,   571,   571,   550,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   376,   407,   408,   409,   410,   411,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     501,   519,   348,   350,   352,   353,   360,   363,   364,   365,
     366,   367,   368,   369,   370,   401,   405,   410,   411,   421,
     426,   427,   612,   612,   571,   571,   611,    42,    43,   449,
     450,   451,   452,   448,    10,    11,    13,    17,    35,    36,
      63,    65,    70,   146,   150,   151,   152,   153,   154,   155,
     156,   157,   159,   161,   162,   163,   164,   165,   166,   167,
     169,   170,   175,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   224,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     259,   261,   262,   263,   264,   265,   272,   281,   282,   283,
     284,   289,   293,   310,   311,   312,   313,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   343,
     344,   428,   429,   430,   431,   445,   446,   455,   456,   457,
     458,   459,   460,   463,   464,   465,   466,   467,   468,   469,
     470,   487,   497,   498,   499,   500,   502,   503,   508,   509,
     514,   515,   516,   545,   550,   557,   571,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   612,   545,    41,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   409,    42,   241,   571,   345,   571,    15,   571,
     571,    10,    11,    13,    63,   146,   165,   175,   455,   456,
     457,   458,   459,   460,   463,   464,   465,   466,   467,   468,
     469,   557,   573,   592,   612,    63,   571,   592,   592,   592,
     592,   592,   592,   592,   573,   168,   220,   221,   222,   223,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   222,   223,   222,   223,   222,   223,   573,   573,
     573,   592,   592,   573,   573,   573,   573,   573,   573,   573,
     573,    54,    54,   571,   571,   573,   571,   573,   571,    10,
      11,    13,    66,   455,   456,   457,   458,   459,   460,   463,
     464,   465,   466,   467,   468,   469,   557,   611,   550,   592,
     573,   144,   475,    55,   551,   534,   614,   615,   550,    54,
     539,   538,   551,   571,   550,    63,   573,   573,   573,   534,
     548,   548,   550,   550,   558,   558,   558,   559,   559,   561,
     561,   561,   561,   562,   562,   563,   564,   565,   566,   568,
     567,   571,   571,    49,    50,   158,   220,   238,   241,   242,
     243,   244,   273,   274,   275,   406,   407,   412,   425,   442,
     614,   592,   571,   592,   558,   598,   598,   559,   599,   559,
     599,   238,   239,   240,   241,   271,   279,   290,   294,   337,
     339,   340,   341,   350,   351,   356,   357,   358,   359,   371,
     372,   373,   374,   375,   377,   378,   380,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   510,   276,   277,   278,   285,   286,   287,   288,
     292,   333,   336,   337,   338,   339,   341,   342,   345,   505,
     506,   507,   511,   513,   612,   613,   345,   592,    10,    11,
      13,    35,    37,    65,    68,    75,    86,    89,   345,   402,
     433,   436,   448,   455,   456,   457,   458,   459,   460,   463,
     464,   465,   466,   467,   468,   469,   550,   557,   571,   592,
     593,   611,   612,   613,    80,   571,   571,   571,    13,   556,
      20,    14,    14,    14,    20,    14,    14,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    20,   550,   571,   550,
      13,    13,    13,   573,   577,   578,   578,   572,   592,    59,
      60,   573,   612,    13,   550,    13,    19,    19,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    19,    13,    13,    13,    13,    19,
      13,    13,    13,    19,    19,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,   578,   578,   578,   578,   578,   578,
     578,   578,   578,   578,   578,   578,   578,   578,    13,    13,
      13,    13,    13,    13,    19,    13,    13,    13,    13,    13,
      14,    20,   578,    13,    15,   144,     4,     7,     8,    10,
      11,     5,     6,   138,   139,   140,   141,    17,    18,   136,
      21,   137,    19,    14,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,   550,    16,    15,
      16,   571,    14,    20,   572,   573,    19,    13,    19,    19,
      13,    14,    19,    20,    14,    16,    14,    14,    16,    14,
      16,    20,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    20,    14,    20,    14,    16,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    14,
      14,    20,    20,    14,    20,    14,    14,    20,    14,   571,
     544,   550,   553,   481,   534,    14,    14,    14,    14,    13,
      13,   534,    20,    14,    20,    20,    20,    20,    22,    14,
      20,    22,    23,    16,    13,    13,   550,    13,    13,    13,
      13,    13,    13,    13,    13,    13,   550,    13,    13,   550,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,   550,    13,    13,    13,    13,    13,    19,    15,
      15,    13,    19,    13,    13,    15,    13,    13,    13,    13,
      20,    20,    19,    13,    16,    16,   550,    12,   571,   571,
     573,   571,   571,   571,   571,   571,   573,   571,   571,    63,
     573,    56,    63,   571,   571,   571,   571,   571,   571,   571,
     592,   571,    65,   571,    71,   571,   571,   613,   571,   571,
     571,   571,   571,   612,    65,   593,    65,    56,   571,   571,
     571,   571,   550,    59,    62,   550,    14,    14,   550,   572,
     573,   571,   346,   346,   347,   545,   592,   573,   592,   592,
     573,   573,   573,   573,   573,   592,   573,   573,   573,   573,
     573,    52,    53,   573,   573,   573,   573,    52,   185,   220,
     592,   592,   573,   220,   220,   573,   573,   573,   573,   573,
     573,   573,   573,   573,   592,   573,   573,   573,   573,   573,
     573,   573,   573,   573,   573,   573,   573,   573,   592,   592,
     592,   592,   592,   573,   573,   573,   573,   573,   612,   612,
     550,   550,   573,   573,   573,   573,   573,   573,   573,   573,
     573,   573,   573,   573,   573,   592,   573,   573,   573,   573,
     573,   573,   592,   592,   592,   592,   592,   573,   592,   592,
     504,   592,   592,   592,   592,   550,    17,    63,   550,   571,
     592,   592,    22,    63,   571,   573,   616,   591,   578,   558,
     578,   558,   578,   559,   579,   559,   579,   561,   582,   561,
     582,   561,   582,   561,   582,   561,   583,   561,   583,   584,
     586,   587,   589,   588,   291,   381,   382,   383,   384,   534,
     550,   550,   550,   571,    59,    60,   550,    61,    60,   571,
      62,    62,    62,   550,   571,    71,   571,   571,   550,   571,
     571,   571,   571,   144,   571,   144,    16,    71,    14,    19,
     592,   571,    13,    13,    13,   573,   571,   573,   571,   571,
     571,   573,   573,   573,   573,   571,   571,   571,   571,   571,
     571,   571,   573,   571,   573,   573,   573,   171,   573,   573,
     171,   573,   171,   573,   573,   573,   571,   571,   571,   571,
     571,   571,   571,   571,   571,   571,   571,   571,   571,   571,
     571,   573,   592,    13,   571,   571,   571,   571,   571,   571,
     571,   573,   573,   573,   571,   571,   571,   550,   472,    20,
     551,   551,   489,   490,   491,   492,   493,   546,   546,   571,
     571,   550,   573,   573,   569,   571,   571,   571,   144,   550,
     573,   573,   573,   571,   573,   571,   573,   571,   571,   571,
     571,   571,   571,   571,   571,   571,   571,   571,   571,   571,
     592,   571,   571,   571,   571,   571,   571,   571,   571,   573,
     592,   571,   592,   571,   571,   573,   571,   571,   571,   592,
     573,   612,   612,   612,   592,   592,   592,   550,   592,   573,
     612,   573,   612,   612,   592,    14,   550,   592,   592,   592,
     592,   592,   280,   571,   571,   550,   400,   545,   550,   571,
      75,   571,   571,   550,   550,   550,   550,    20,   550,   571,
      14,    20,    20,    20,    20,    20,    14,    20,    14,    20,
      14,    14,    14,    20,    20,    20,    20,    20,    14,    14,
      20,    20,    20,    20,    14,    20,    14,    20,    14,    20,
      14,    14,    20,    20,    20,    20,    14,    19,    14,    20,
      14,    20,    20,    20,    14,    14,    14,    14,    14,    20,
      13,   577,    14,    20,    19,    20,    14,    20,    20,    20,
      20,    14,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    14,    20,    13,    13,    20,    20,
      20,    13,    13,    14,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    14,    14,    14,    20,    14,    20,    20,
      20,    20,    20,    14,    20,    20,    20,    20,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    20,    20,    14,
      14,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    14,    14,    14,    14,    14,    14,
      14,    20,    20,    20,    14,    20,    20,    20,    20,    20,
      13,    14,    20,    14,    20,    20,    14,    14,    59,    60,
     573,   612,    14,    20,    16,    22,    16,    22,    13,    13,
      13,    13,    13,    14,    14,    14,    20,    20,    20,    20,
      14,    20,    14,    20,    20,    20,    20,    20,    20,    20,
      14,    14,    20,    20,    14,    20,    20,    20,    14,   613,
      16,   592,    14,    13,    14,   592,   573,   573,    14,    20,
      14,    20,    14,    20,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    20,    14,    14,
      20,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    14,    20,    14,    20,    14,    14,    14,    14,    20,
      14,    14,    14,    14,    14,    20,    14,    14,   592,    20,
      20,    14,    20,    20,    20,    14,    20,    20,    20,    20,
      20,    20,    14,    20,   571,   550,   534,   534,    57,    57,
      57,    57,    57,    14,    20,    14,    20,    20,    14,    20,
      20,    14,    20,    23,    20,    14,   571,   592,    14,    14,
      20,    14,    14,    20,    14,    20,    14,    14,    14,    20,
      20,    20,    14,    20,    14,    14,    14,    14,    14,    20,
      14,    14,    20,    14,    20,    14,    20,    20,    20,    14,
      14,    14,    14,    14,    14,    14,    14,    20,    20,    14,
      14,    20,    14,    14,    14,    14,    20,    20,    20,    20,
      20,    20,    14,    20,    20,    20,    14,    20,    20,    20,
      20,    20,    14,    14,    20,    20,    20,    20,    20,    13,
      16,    16,    14,    14,    14,    16,    20,    14,    14,    20,
      14,   550,   573,   571,   571,   571,   571,   571,   571,   573,
     573,   571,   571,   571,   571,   571,   571,   571,   571,   571,
     571,   571,   571,   571,   571,   571,   573,   571,   592,   144,
      54,   571,   571,   592,    54,   573,   571,   571,   571,   571,
     571,   571,   571,   571,   571,   571,   571,   571,   571,   571,
     571,   573,   573,   592,   592,   573,   573,   573,   571,   571,
     571,   571,   571,   571,   571,   571,   571,   573,   573,   573,
     573,   573,   573,   573,   573,   571,   571,   571,   571,   592,
     592,   571,   571,   571,   571,   573,   550,   573,   573,   571,
     571,   571,   571,   571,   571,   571,   571,   571,   571,   571,
     571,   571,   571,   571,   571,   573,   571,   571,   573,   571,
     571,   592,    22,   571,   590,   571,   573,    14,    14,    14,
     571,   550,   571,   550,   571,    71,   550,   550,   571,   550,
     550,   550,   550,   550,   571,   571,   571,   571,   571,   571,
      14,    14,    14,    20,   573,   571,   571,   571,   573,   571,
     571,   571,   571,    14,   571,   571,   571,   592,   571,   571,
     571,   571,   573,   573,   571,   571,   571,   473,   551,   551,
     489,   490,   491,   492,   493,   551,   571,   571,   573,   571,
     571,   571,   571,   571,   571,   571,   571,   571,   571,   571,
     571,   571,   571,   571,   571,   571,   571,   571,   571,   571,
     571,   571,   571,   571,   571,   571,   571,   571,   571,   571,
     571,   571,   571,   571,   571,   571,   571,   592,   592,   571,
      75,    20,    20,    54,    14,    20,    14,    20,    14,    20,
      14,    20,    14,    14,    14,    14,    20,    20,    14,    20,
      20,    20,    20,    14,    20,    20,    20,    20,    14,    14,
      14,    20,   571,    14,    20,    20,    14,    14,    20,    20,
      20,    14,    14,    14,    14,    20,    14,    20,    20,    20,
      20,    20,    20,    20,    20,    14,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      14,    20,    20,    20,    20,    20,    20,    14,    14,    20,
      14,    14,    14,    20,    20,    14,    14,    14,    14,    20,
      14,    14,    20,    20,    20,    14,    14,    14,    14,    14,
      14,    14,    14,    20,    20,    20,    20,    20,    14,    20,
      20,    14,    20,    20,    14,    14,    14,    20,    20,    14,
      14,    14,    20,    20,    20,    20,    14,    14,    14,    14,
      14,    14,    14,    20,    14,    14,    14,    20,    14,    14,
      14,   571,    14,    20,    14,    14,    20,    20,    14,    20,
      20,    14,    20,    14,    20,    14,    20,    14,    20,    20,
      20,    20,    20,    20,    20,    20,    14,   571,   534,   534,
      57,    57,    57,    57,    57,   534,    14,    20,    20,    20,
      14,    20,    23,    14,    22,    20,    20,    20,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    14,    14,    20,
      14,    14,    14,    14,    14,    20,    14,    20,    20,    20,
      20,    20,    20,    20,    20,   550,   550,    14,   571,   571,
     571,   571,   571,   571,   571,   571,   571,   571,   571,   571,
     571,   571,   571,   571,   573,   571,   572,   572,   573,    54,
     573,   571,   571,   571,   571,   571,   571,   571,   571,   571,
     571,   571,   573,   571,   573,   571,   571,   571,   571,   571,
     571,   571,   571,   571,   571,   571,   571,   571,   573,   573,
     573,   573,   573,   571,   571,   571,   592,   592,   571,   571,
     571,   571,   571,   571,   571,   571,   571,   571,   571,   571,
     571,   571,   571,   571,   571,   550,   571,    14,   571,   573,
     571,   571,   571,   592,   592,   592,   592,   571,   571,   571,
     573,   573,   571,   571,   551,   571,   573,   571,   571,   571,
     571,   571,   571,   571,   571,   571,   571,   571,   571,   571,
     571,   571,   571,   571,   571,   571,   571,   571,   571,   571,
     571,   573,   592,   571,   571,   571,   571,   592,   592,   571,
     571,    14,    14,    20,    20,    14,    20,    20,    14,    20,
      20,    14,    20,    20,    20,    14,    20,    20,    14,    20,
      20,    14,    14,    20,    20,    20,    20,    14,    20,    14,
      20,    14,    20,    14,    20,    20,    20,    20,    20,    14,
      14,    14,    20,    20,    20,    20,    20,    20,    14,    20,
      20,    20,    20,    20,    20,    20,    14,    20,    20,    20,
      20,    20,    20,    20,    14,    14,    14,    14,    20,    20,
      14,    20,    20,    20,    20,    20,    20,    14,    20,    22,
      22,    20,    14,    20,    14,    20,    14,    20,    14,    20,
      14,    20,    14,    14,    20,    14,    20,    20,    14,    20,
      14,    20,    20,    14,    14,   534,    20,    20,    20,    14,
      14,    20,    20,    14,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    20,    20,    20,
      20,    20,    14,    14,    14,    20,    14,    20,    20,    20,
      14,    14,   571,   571,   571,   571,   571,   571,   571,   571,
     571,   571,   571,   572,   571,   572,    54,   571,   571,   571,
     571,   571,   571,   571,   571,   571,   571,   571,   571,   571,
     571,   571,   571,   571,   616,   571,   616,   571,   616,   571,
     571,   571,   571,   571,   571,   571,   571,   571,   573,   571,
     571,   571,   571,   571,   571,   571,   571,   571,   571,   571,
     571,   571,   571,   550,   571,   571,   571,   571,   571,   571,
     571,   592,   573,   571,   573,   571,   571,   571,   571,   571,
     571,   571,   571,   592,   571,   571,   571,    20,    14,    14,
      20,    20,    20,    14,    14,    14,    20,    14,    20,    20,
      20,    14,    14,    20,    20,    20,    14,    20,    14,    20,
      20,    20,    20,    20,    20,    14,    20,    20,    20,    20,
      20,    20,    20,    14,    20,    14,    14,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    14,    20,    20,    14,
      14,    20,    14,    14,    14,    20,    20,    20,    14,    16,
      20,    14,    14,    14,    14,    14,    20,    20,    14,    14,
      20,    20,    14,    20,    20,    20,    20,    22,    14,    14,
      20,    20,    14,    20,    20,    20,    20,    20,   571,   571,
     571,   571,   571,   571,   571,   550,   572,   571,   571,   571,
     571,   571,   571,   571,   571,   571,   571,   571,   571,   571,
     571,   571,   616,   616,   616,   616,   571,   571,   571,   573,
     573,   573,   573,   571,   571,   571,   571,   571,   571,   571,
     571,   571,   571,   571,   573,   571,   573,   571,   571,   571,
     571,   571,   592,   571,   571,   571,    14,    20,    20,    20,
      20,    14,    20,    20,    14,    14,    20,    14,    14,    14,
      14,    14,    14,    20,    14,    20,    14,    20,    14,    14,
      20,    14,    14,    14,    14,    20,    14,    14,    14,    14,
      20,    20,    14,    20,    14,    20,    14,    20,    22,    20,
      14,    20,    20,    20,    20,    20,    20,    14,    20,    20,
      20,    14,    20,    20,    20,    20,   571,   571,   571,   571,
     550,   571,   571,   571,   571,   571,   571,   571,   616,   571,
     571,   571,   571,   571,   571,   571,   571,   571,   573,   571,
     573,   571,   144,   571,   571,   571,   592,   571,   571,   571,
      14,    14,    20,    14,    14,    20,    20,    20,    14,    14,
      14,    20,    14,    20,    20,    14,    20,    20,    14,    14,
      20,    20,    14,    20,    20,    20,    20,   592,    20,    20,
      14,    20,    20,    14,    14,    20,    20,   571,   550,   571,
     571,   571,   571,   571,   571,   571,   592,   571,   592,   571,
     571,   571,   571,   571,   571,   571,   571,   571,    20,    14,
      14,    14,    14,    14,    20,    20,    20,    14,    14,    14,
      20,    20,    20,    14,    20,    20,    14,    14,    20,    14,
      20,   571,   571,   571,   571,   571,   571,   573,   571,   571,
     571,   592,    20,    20,    14,    20,    14,    20,    20,    14,
      20,    14,    20,   571,   571,   571,   571,   573,   571,   592,
      20,    14,    20,    20,    20,    14,    14,   571,   571,   571,
     571,    20,    20,    20,    14,   571,   571,   571,    20,    20,
      20,   571,   571,   571,    14,    20,    20,   571,   571,    20,
      14,   571,    14
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
     715,   716,   717,   718,   719,   720,   721,   722,   723,   724,
     725,   726,   727,   728,   729,   730,   731,   732,   733,   734,
     735,   736,   737,   738,   739,   740,   741,   742,   743,   744,
     745,   746,   747,   748,   749,   750,   751,   752,   753,   754,
     755,   756,   757,   758,   759,   760,   761,   762,   763,   764,
     765,   766,   767,   768,   769,   770,   771,   772,   773,   774,
     775,   776,   777,   778,   779,   780,   781,   782,   783,   784,
     126
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  Parser::yyr1_[] =
  {
         0,   531,   532,   532,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     534,   534,   535,   535,   535,   535,   536,   536,   538,   537,
     539,   537,   540,   541,   542,   542,   542,   542,   542,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   544,   544,
     545,   545,   545,   545,   545,   545,   545,   545,   545,   545,
     545,   545,   545,   545,   545,   545,   545,   546,   546,   546,
     546,   546,   546,   546,   546,   546,   546,   546,   547,   547,
     548,   548,   548,   548,   548,   548,   548,   548,   548,   549,
     549,   549,   550,   551,   552,   553,   554,   554,   554,   554,
     554,   554,   554,   554,   555,   555,   555,   555,   555,   555,
     555,   555,   555,   555,   555,   555,   555,   555,   555,   555,
     555,   555,   555,   555,   555,   555,   555,   555,   555,   555,
     555,   555,   555,   555,   555,   555,   555,   555,   555,   555,
     555,   555,   555,   555,   555,   555,   555,   555,   555,   555,
     555,   555,   555,   555,   555,   555,   555,   555,   555,   555,
     555,   555,   555,   555,   555,   555,   555,   555,   555,   555,
     555,   555,   555,   555,   555,   555,   555,   555,   555,   555,
     555,   556,   556,   556,   556,   556,   556,   556,   556,   556,
     556,   556,   556,   556,   556,   556,   556,   556,   556,   557,
     557,   558,   558,   559,   559,   559,   559,   560,   560,   560,
     561,   562,   562,   562,   562,   562,   563,   563,   563,   563,
     563,   564,   564,   565,   565,   566,   566,   567,   567,   568,
     568,   569,   569,   570,   571,   572,   572,   572,   572,   572,
     572,   572,   572,   572,   572,   572,   573,   573,   574,   574,
     574,   574,   574,   574,   574,   574,   574,   574,   574,   574,
     574,   574,   574,   574,   574,   574,   574,   574,   574,   574,
     574,   574,   574,   574,   574,   574,   574,   574,   574,   574,
     574,   574,   574,   574,   574,   574,   574,   574,   574,   574,
     574,   574,   574,   574,   574,   574,   574,   574,   574,   574,
     574,   574,   574,   574,   574,   574,   574,   574,   574,   574,
     574,   574,   574,   574,   574,   574,   574,   574,   574,   574,
     574,   574,   574,   574,   574,   574,   574,   574,   574,   574,
     574,   574,   574,   574,   574,   574,   574,   574,   574,   574,
     574,   574,   574,   574,   574,   574,   574,   574,   574,   574,
     574,   574,   574,   574,   574,   574,   574,   574,   574,   574,
     574,   574,   574,   574,   574,   574,   574,   574,   574,   574,
     574,   574,   574,   574,   574,   574,   574,   574,   574,   574,
     574,   574,   574,   574,   574,   574,   574,   574,   574,   574,
     574,   574,   574,   574,   574,   574,   575,   575,   576,   577,
     577,   577,   577,   577,   577,   577,   577,   577,   577,   577,
     577,   577,   577,   577,   577,   577,   577,   578,   578,   579,
     579,   579,   579,   579,   579,   580,   581,   581,   581,   581,
     581,   582,   583,   583,   583,   583,   583,   583,   583,   583,
     583,   584,   584,   584,   584,   584,   585,   585,   586,   587,
     587,   588,   588,   589,   589,   590,   590,   591,   591,   592,
     593,   593,   593,   593,   594,   594,   594,   595,   595,   596,
     597,   597,   597,   597,   597,   597,   597,   597,   597,   597,
     597,   597,   597,   597,   597,   597,   597,   597,   598,   599,
     599,   599,   599,   600,   600,   600,   600,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     612,   613,   613,   613,   613,   613,   613,   613,   613,   613,
     613,   613,   613,   613,   613,   613,   613,   613,   613,   613,
     613,   613,   613,   613,   613,   613,   613,   613,   613,   613,
     613,   613,   613,   613,   613,   613,   613,   613,   613,   614,
     615,   615,   615,   615,   615,   615,   615,   615,   615,   615,
     615,   615,   615,   615,   615,   615,   615,   615,   615,   615,
     616,   616,   616,   616
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Parser::yyr2_[] =
  {
         0,     2,     0,     2,     1,     2,     2,     3,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     2,
       1,     1,     8,    10,     6,     2,     4,     6,     0,     8,
       0,     8,     4,     2,     3,     2,     2,     5,     2,     1,
       1,     1,     1,     1,     1,     4,     6,     6,     6,     6,
       3,     3,     6,     6,     3,     3,     3,     3,     6,     3,
       3,     3,     6,     6,     8,     6,     8,     3,     5,     3,
       5,     8,     8,     3,     1,     1,     1,     1,     8,     4,
       4,     1,     2,     2,     2,     1,     3,     3,     3,     6,
       6,    16,     2,     2,     3,     2,     2,     3,     3,     2,
       2,     3,     2,     6,     2,     2,     5,     2,     1,     1,
       2,     2,     2,     2,     2,     4,     4,     2,     2,     2,
       2,     1,     4,     3,     2,     2,    10,     6,     3,     6,
       6,     8,    28,     8,     8,     3,     8,    12,     6,     6,
      16,     8,    16,    10,     6,    10,     8,    10,    14,     8,
      12,     6,     8,     6,     6,     6,    10,     6,    10,    10,
      12,     6,     6,    12,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     8,     3,     3,     3,
       3,     3,     3,    12,    16,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,    10,     6,    14,     6,     8,
       6,     6,     8,     6,    10,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     3,     3,     4,     3,
       6,     6,     4,     4,     6,    10,    10,    10,     6,     6,
       6,     6,     6,    10,     6,    10,     6,     6,     6,     3,
       6,     6,    10,    10,     6,     6,     6,     3,     3,     3,
       3,     6,     6,     3,     6,     6,     8,    10,     3,     6,
       3,     4,    20,     6,    10,     6,     3,     3,     6,     3,
       6,     8,     6,     6,     8,    16,     6,     3,     6,     8,
       3,    12,    12,    12,    10,     3,     3,     8,     8,    10,
       8,    10,    12,     6,     8,     8,    10,    16,    18,    12,
       6,    18,    16,    12,    10,    10,    10,     6,    10,     6,
       6,     6,     8,     1,     4,     4,     8,     4,    18,     4,
       1,     1,     6,     3,     8,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     6,     8,     6,    10,     6,
       8,     8,     8,     8,     6,     3,     4,     1,     1,     1,
       1,     1,     1,     1,    30,    24,     4,     8,     1,     3,
       0,     1,     3,     1,     3,     2,     4,     2,     4,     1,
       3,     2,     4,     2,     4,     1,     3,     0,     2,     2,
       2,     2,     2,     4,     4,     4,     4,     4,     1,     1,
       1,     6,     6,     6,     1,     3,     4,     4,     1,     1,
       3,     3,     1,     3,     0,     0,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     4,     6,     8,    10,    10,
      10,     8,     6,     3,     3,     3,     2,     3,     3,     3,
       6,     4,    10,     4,    10,     4,     4,     4,     4,     4,
       4,     7,     7,     7,     9,     7,     6,     4,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       6,     8,    10,    12,    10,    12,     8,     6,     8,     8,
       8,     8,     6,     8,     8,     8,    12,     6,     6,     3,
       6,     6,     4,     4,     4,     1,     6,     6,     6,     3,
       6,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       1,     1,     4,     1,     3,     3,     3,     1,     3,     3,
       1,     1,     3,     3,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     4,     2,     4,
      16,    14,    16,     4,     4,     4,     1,    10,    12,     8,
       1,     4,     6,     6,     6,     8,     8,     6,     6,     8,
       8,    10,    10,    12,    12,    10,     4,    10,     4,     6,
       4,     4,     4,    12,     4,    12,    12,    16,    20,    10,
      12,     4,     6,     6,     6,     4,     4,     6,     4,     6,
       6,     6,     4,    10,    16,    10,     8,    12,    10,     8,
      12,     8,    12,     8,    12,     3,     3,     8,     8,     3,
       6,    12,    12,    14,    12,    12,    16,     4,     8,    10,
      12,    10,    12,    10,    12,    12,    14,    12,     8,    14,
       4,     4,     4,     4,     3,     3,     3,     6,     6,     6,
       6,     8,    14,    12,    14,    12,     6,     8,    10,    10,
      12,     6,     6,     6,     6,     6,     6,     6,     6,     8,
      10,     4,     4,    10,    10,     4,     6,     6,    12,    30,
       8,     5,     6,     5,     5,     6,     6,     4,     6,     4,
       6,     4,     4,    18,     8,     6,     1,     3,     1,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     4,     1,
       3,     3,     3,     3,     3,     1,     1,     3,     3,     3,
       3,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     1,     1,
       3,     1,     3,     1,     3,     1,     5,     1,     3,     1,
       1,     3,     8,     4,     6,     1,     4,     1,     3,     1,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       3,     3,     3,     1,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     6,     6,     8,     8,     4,     6,     6,     6,     6,
       3,     2,     4,     1,     4,     6,     1,     4,     4,    10,
       6,    16,    18,    10,    20,    14,     8,     4,     6,     8,
       8,    12,    16,    16,    18,    14,    14,    16,    20,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
      11,     7,     1,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const Parser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "LEX_ERROR", "T_EXP", "T_GT",
  "T_LT", "T_MULT", "T_DIV", "T_FACT", "T_ADD", "T_SUB", "T_MOD",
  "T_OP_PAR", "T_CL_PAR", "T_OP_BR", "T_CL_BR", "T_AND", "T_OR", "T_POINT",
  "T_COMMA", "T_QUEST", "T_COLON", "T_SEMICOLON", "T_SetDebugOn",
  "T_SetDebugOff", "T_SetVerboseOn", "T_SetVerboseOff", "T_AddMenuScript",
  "T_SetProgress", "T_SetStatusText", "T_GetScriptsDir", "T_argc",
  "T_emptyargs", "END_INSTRUCTION", "T_Image", "T_ReadRawImages",
  "T_Transform", "SHOW", "HELP", "QUIT", "T_HIDE", "PRINT", "PRINTN",
  "T_InfoDialog", "T_boost_format", "T_SPRINT", "ASHELL", "LS",
  "T_SetName", "T_GetName", "T_GetObjectName", "T_GetOutput",
  "T_GetDiffCoeff", "ASTRING", "ABLOCK", "NUMBER", "IDENTIFIER",
  "VAR_IMAGE", "VAR_FLOAT", "VAR_INT", "VAR_UCHAR", "VAR_STRING",
  "VAR_IMAGEDRAW", "VAR_SURFACE", "VAR_SURFDRAW", "VAR_MATRIX", "VAR_FILE",
  "VAR_C_FUNCTION", "VAR_C_PROCEDURE", "VAR_C_IMAGE_FUNCTION",
  "VAR_AMI_FUNCTION", "VAR_AMI_CLASS", "VAR_AMI_OBJECT", "VAR_PARAMWIN",
  "VAR_GLTRANSFORM", "VAR_ARRAY_SURFACE", "VAR_ARRAY_IMAGE", "T_del",
  "T_delvars", "T_Comments", "ENDOP", "T_global", "T_local",
  "T_global_new", "T_local_new", "T_context", "T_wait", "T_schedule",
  "T_ParamWin", "T_BeginPanel", "T_EndPanel", "T_BeginBoxPanel",
  "T_EndBoxPanel", "T_BeginBook", "T_EndBook", "T_AddPage", "T_SelectPage",
  "T_AddFloat", "T_AddInt", "T_CreateWin", "T_Display", "T_AddButton",
  "T_AddBoolean", "T_AddEnum", "T_AddEnumChoice", "T_AddImageChoice",
  "T_AddString", "T_AddFilename", "T_AddLabel", "T_ShowSlider",
  "T_SetCallback", "T_SetDragCallback", "T_SetPositionProp", "T_BeginBox",
  "T_EndBox", "T_BeginHorizontal", "T_EndHorizontal", "T_redraw",
  "T_Enable", "T_EnableBox", "T_EnablePanel", "RIGHT_ASSIGN",
  "LEFT_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "RIGHT_OP",
  "INC_OP", "DEC_OP", "PTR_OP", "AND_OP", "OR_OP", "LE_OP", "GE_OP",
  "EQ_OP", "NE_OP", "TRANSPOSE_OP", "POINTWISE_MULT", "ASSIGN_OP",
  "T_COUNT", "T_MAX", "T_argmax", "T_MIN", "T_MEDIAN", "OpImage", "FILTER",
  "NormGrad", "T_DiscNormGrad", "T_gradient", "SecDerGrad", "SecDerGrad2",
  "SubImage", "PutImage", "T_AutoCrop", "T_DiscSecDerGrad", "T_EDPdilate",
  "T_EDPerode", "T_EDPopen", "T_EDPclose", "AnisoGS", "AnisoSmoothGS",
  "T_vtkAnisoGS", "T_SetDistMap", "T_DiscMeanCurvature", "T_vtkMedian3D",
  "T_NULL", "T_InitTime", "T_TimeSpent", "T_EndTime", "T_LevelSetsCURV",
  "T_UpdateResult", "T_SetMeanCurv", "T_SetAffineCurv",
  "T_SetBalloonScheme", "T_SetVelocity", "T_SetExpansion",
  "T_SetExpansionImage", "T_SetAdvectionField", "T_SetCurvWeights",
  "T_GetAttachVect", "T_GetCurvature", "T_GetDistMap", "T_GetAdvection",
  "T_GetVelocity", "T_GetExpansion", "T_GetSkeleton", "T_SetDistMethod",
  "T_SetParam", "T_SetIsoContourBin", "T_SetBandTube", "T_SetThreads",
  "T_SaveDistMap", "T_SaveSecDerGrad", "T_SetNumGaussians",
  "T_SetGaussian", "T_SetProbThreshold", "T_SetILowTh", "T_SetIHighTh",
  "T_SetProbHighTh", "T_SetNumInitPoints", "T_SetInitPoint",
  "T_vtkFastMarching", "T_vtkFastMarchingTarget", "T_FluxDiffusion",
  "T_AnisoWeickert", "T_AnisoCW", "T_SRAD_qcoeff", "T_AnisoSRAD",
  "T_AnisoSRAD2", "T_AnisoLeeAdd2", "T_AnisoDPAD", "T_AnisoDPAD2",
  "T_AnisoNRAD", "T_AnisoRudinMult", "TInit", "TSetCoeff", "TIterate",
  "TEnd", "TAddGaussNoise", "T_SNR", "T_SetNoiseType", "T_SetNoiseSD",
  "T_GetNoiseSD", "T_GetDAcoeff", "T_SetMask", "T_SetSRADROI",
  "T_SetRNRADROI", "T_SetRNRADROI_NEW", "T_SetLocalStruct",
  "T_SetEigenMode", "T_Setdt", "T_Setneighborhood", "T_info", "T_NbPoints",
  "T_NbPolys", "T_save", "T_normalize", "T_OrientField",
  "T_OrientPositive", "T_2DFlux", "T_OutFlux", "T_OutFluxScalar",
  "T_OrientationRatio", "T_Skeleton", "T_SimplePoints", "T_CircleIntegral",
  "T_CircleIntegralExc", "T_CircleIntSdExc", "T_CircleMinIntSdExc",
  "T_LocalExtrema", "T_NormalField", "T_DirConnectivity", "T_eccentricity",
  "T_rot2D", "T_mean", "T_SUM", "T_localmean", "T_localmean2", "T_localSD",
  "T_localSD2", "T_struct_tensor", "T_StructTensorH", "T_HessianMatrix",
  "T_HessianEVal", "T_Derivatives", "T_curvatures", "T_Laplacian",
  "T_setvoxelsize", "T_settranslation", "T_setendianness",
  "T_Skeleton2lines", "T_SmoothLines", "T_ResampleLines", "T_RemoveLine",
  "T_ConnectLines", "T_threscross", "T_IsocontourPoints", "T_IsosurfDist",
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
  "T_SetColorMaterial", "T_penguin", "T_Statistics", "T_GetIntensities",
  "T_GetLinesLength", "T_GetLinesExtremities", "T_GetConnections",
  "T_SelectLines", "T_RemoveSelection", "T_mergepoints", "T_Triangulate",
  "T_Displace", "T_Normals", "T_InvertNormals", "T_Translate", "T_Scale",
  "T_SetPointsColors", "T_SetLineWidth", "T_AddPoint", "T_NewLine",
  "T_EndLine", "T_LineAddPointNumber", "T_GetTransform", "T_SetTransform",
  "T_Interpolate", "T_Matrix", "T_Invert", "T_PrintMatrices", "SET",
  "SETPOS", "SHOWCURSOR", "UPDATE", "COMPARE", "SETVECTOR", "T_lininterp",
  "T_SetCompareDisplacement", "T_DrawVector", "T_DisplayVectors",
  "T_SetVectParam", "T_SetVectColor", "T_SetVectStyle",
  "T_SetLineThickness", "T_SetZoom", "T_SetWindowSize", "T_SetColormap",
  "T_drawcircle", "T_setGLwin", "T_initvalue", "T_ShowSection",
  "T_HideSection", "T_Xpos", "T_Ypos", "T_Zpos", "T_SpacePos", "T_CHAR",
  "T_UCHAR", "T_SHORT", "T_USHORT", "T_INT", "T_UINT", "T_FLOAT",
  "T_DOUBLE", "T_RGB", "T_FLOAT_VECTOR", "T_GetFormat", "T_atof",
  "T_gnuplot", "T_histo", "T_cumhisto", "T_DisplayHisto", "T_OPEN",
  "T_CLOSE", "T_scan_float", "T_read", "T_rewind", "T_LineNumber",
  "CONST_PI", "SIN", "COS", "TAN", "ASIN", "ACOS", "ATAN", "SINH", "COSH",
  "EXP", "LN", "LOG", "SQRT", "ABS", "ROUND", "FLOOR", "NORM", "FOR", "TO",
  "STEP", "ENDFOR", "T_IN", "T_REPEAT", "T_UNTIL", "T_BREAK", "IF", "THEN",
  "ELSE", "VARIABLES", "FUNCTION", "T_eval", "T_exists", "T_FileExists",
  "T_slice", "T_GenRead", "T_IMAGE", "T_IMAGEDRAW", "T_SURFACE", "T_NUM",
  "T_STRING", "T_TRANSFORM", "T_PROC", "T_Class", "T_MeanHalfSize",
  "T_Resize", "T_ReSlice", "T_Flip", "T_SetCompTransf", "T_ConvexHull",
  "T_itk", "T_CannyEdgeDetector", "T_CreateFlatMesh", "T_CreateVolume",
  "T_vtkCreateFlatMesh", "T_Altitude2Position", "T_GeoCoordinates",
  "T_ElevateMesh", "T_CreateVectors", "T_Set3DArrowParam",
  "T_CreateEllipsoids", "T_ComputeAltitudes", "T_Temp2Altitudes",
  "T_ReadFlow", "T_SetFluidNavFile", "T_DrawEarthCoord", "T_PaintCallback",
  "T_SaveStructuredGrid", "T_import_ami", "T_import_vtk", "T_import_itk",
  "T_import_wii", "T_import_filters", "T_import_sys", "T_import_mainframe",
  "T_amiOFCorr2D", "T_amiOFVar2D", "'~'", "$accept", "start",
  "list_commands", "end_instr", "loop_inst", "cond_inst", "proc_decl",
  "$@1", "$@2", "class_decl", "object_decl", "func_inst", "command",
  "exprstringlist", "param_list", "param_list_decl", "primary_expr_string",
  "postfix_expr_string", "additive_expr_string", "expr_string",
  "instr_block", "begin_block", "end_block", "primary_expr",
  "postfix_expr", "unary_expr", "unary_operator", "cast_expr",
  "multiplicative_expr", "additive_expr", "shift_expr", "relational_expr",
  "equality_expr", "and_expr", "exclusive_or_expr", "inclusive_or_expr",
  "logical_and_expr", "logical_or_expr", "conditional_expr",
  "assignment_expr", "expr", "basic_type", "var_image", "image",
  "primary_image", "postfix_image", "unary_image", "cast_image",
  "multiplicative_image", "additive_image2", "additive_image",
  "shift_image", "relational_image", "equality_image", "and_image",
  "exclusive_or_image", "inclusive_or_image", "logical_and_image",
  "logical_or_image", "conditional_image", "assignment_image",
  "expr_image", "gltransform", "matrix", "primary_matrix",
  "postfix_matrix", "unary_matrix", "cast_matrix", "multiplicative_matrix",
  "additive_matrix", "shift_matrix", "relational_matrix",
  "equality_matrix", "and_matrix", "exclusive_or_matrix",
  "inclusive_or_matrix", "logical_and_matrix", "logical_or_matrix",
  "conditional_matrix", "assignment_matrix", "expr_matrix", "var_surface",
  "surface", "identifier", "variable", "image_extent", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Parser::rhs_number_type
  Parser::yyrhs_[] =
  {
       532,     0,    -1,    -1,   533,     0,    -1,   534,    -1,   533,
     534,    -1,   543,   534,    -1,   533,   543,   534,    -1,   535,
      -1,   533,   535,    -1,   536,    -1,   533,   536,    -1,   542,
      -1,   533,   542,    -1,   537,    -1,   533,   537,    -1,   540,
      -1,   533,   540,    -1,   541,    -1,   533,   541,    -1,    34,
      -1,    23,    -1,   471,   614,   144,   571,   472,   571,   551,
     534,    -1,   471,   614,   144,   571,   472,   571,   473,   571,
     551,   534,    -1,   471,   614,   475,   544,   551,   534,    -1,
     476,   551,    -1,   479,   571,   551,   534,    -1,   479,   571,
     551,   481,   551,   534,    -1,    -1,   495,   614,   538,    13,
     546,    14,   551,   534,    -1,    -1,   495,    71,   539,    13,
     546,    14,   551,   534,    -1,   496,   614,   551,   534,    -1,
      72,   614,    -1,   483,   550,   534,    -1,   483,   534,    -1,
     484,   550,    -1,    71,    13,   545,    14,   534,    -1,    71,
     534,    -1,    33,    -1,   478,    -1,    82,    -1,    84,    -1,
      85,    -1,    83,    -1,    87,    13,   571,    14,    -1,    88,
      13,   571,    20,    71,    14,    -1,   614,   144,   345,    15,
     571,    16,    -1,   614,   123,   345,    15,   571,    16,    -1,
     614,   144,    35,    15,   571,    16,    -1,   614,   144,   592,
      -1,   614,   123,   592,    -1,   614,   144,    68,    13,   545,
      14,    -1,    77,    15,   571,    16,   144,   592,    -1,   614,
     144,   611,    -1,   614,   144,   593,    -1,    66,   144,   571,
      -1,    66,   144,   611,    -1,    76,    15,   571,    16,   144,
     613,    -1,   614,   144,    86,    -1,   614,   144,   613,    -1,
     612,   123,   613,    -1,    76,   123,   345,    15,   571,    16,
      -1,   614,   144,   436,    13,   571,    14,    -1,   614,   144,
     436,    13,   571,    14,    20,   550,    -1,   614,   144,   433,
      13,   571,    14,    -1,   614,   144,   433,    13,   571,    14,
      20,   550,    -1,   614,   144,   571,    -1,   614,   144,   571,
      20,   550,    -1,   614,   144,   550,    -1,   614,   144,   550,
      20,   550,    -1,   614,   144,   448,    13,   550,    20,    54,
      14,    -1,    67,   144,   448,    13,   550,    20,    54,    14,
      -1,    67,    19,   452,    -1,    24,    -1,    25,    -1,    26,
      -1,    27,    -1,    28,    13,   550,    20,   550,    20,   550,
      14,    -1,    29,    13,   571,    14,    -1,    30,    13,   550,
      14,    -1,    40,    -1,    38,   573,    -1,    41,   573,    -1,
      38,   612,    -1,   379,    -1,   573,   144,   592,    -1,   573,
     123,   592,    -1,   573,   144,   571,    -1,   573,    15,   571,
      16,   144,   592,    -1,   573,    15,   571,    16,   144,   571,
      -1,   573,    13,   571,    22,   571,    20,   571,    22,   571,
      20,   571,    22,   571,    14,   144,   592,    -1,    59,   133,
      -1,    59,   134,    -1,    59,   144,   571,    -1,    60,   133,
      -1,    60,   134,    -1,    60,   144,   571,    -1,    61,   144,
     571,    -1,    61,   133,    -1,    61,   134,    -1,    62,   144,
     550,    -1,    38,   482,    -1,   615,    19,    80,    13,   550,
      14,    -1,    78,   615,    -1,    79,   550,    -1,    78,    76,
      15,   571,    16,    -1,    47,   550,    -1,    48,    -1,    39,
      -1,    39,   614,    -1,    39,    70,    -1,    39,    68,    -1,
      39,    69,    -1,    39,    54,    -1,    67,    19,    42,   550,
      -1,    67,    19,    43,   550,    -1,    42,   550,    -1,    43,
     550,    -1,    42,   611,    -1,    44,   550,    -1,   611,    -1,
      67,    19,    42,   571,    -1,    67,    19,   449,    -1,    42,
     571,    -1,    43,   571,    -1,    63,    19,   407,    13,   571,
      20,   571,    20,   571,    14,    -1,    63,    19,   408,    13,
     571,    14,    -1,    63,    19,   409,    -1,    63,    19,   410,
      13,   573,    14,    -1,    63,    19,   410,    13,    63,    14,
      -1,    63,    19,   413,    13,    63,    20,   573,    14,    -1,
      63,    19,   501,    13,   571,    20,   571,    20,   571,    20,
     571,    20,   571,    20,   571,    20,   571,    20,   571,    20,
     571,    20,   571,    20,   571,    20,   571,    14,    -1,    63,
      19,   411,    13,    56,    20,   573,    14,    -1,    63,    19,
     414,    13,   571,    20,   571,    14,    -1,    63,    19,   415,
      -1,    63,    19,   416,    13,   571,    20,   571,    14,    -1,
      63,    19,   417,    13,   571,    20,   571,    20,   571,    20,
     571,    14,    -1,    63,    19,   418,    13,   571,    14,    -1,
      63,    19,   419,    13,   571,    14,    -1,    63,    19,   420,
      13,   571,    20,   571,    20,   571,    20,   571,    20,   571,
      20,   571,    14,    -1,    63,    19,   421,    13,   571,    20,
     571,    14,    -1,    63,    19,   423,    13,   571,    20,   571,
      20,   571,    20,   571,    20,   571,    20,   571,    14,    -1,
      63,    19,   422,    13,   592,    20,   571,    20,   571,    14,
      -1,    63,    19,   424,    13,    65,    14,    -1,    63,    19,
     295,    13,   571,    20,   573,    20,   571,    14,    -1,    63,
      19,   295,    13,   573,    20,   571,    14,    -1,    63,    19,
     296,    13,   571,    20,   571,    20,   571,    14,    -1,    63,
      19,   296,    13,   571,    20,   571,    20,   571,    20,   571,
      20,   571,    14,    -1,    63,    19,   297,    13,   571,    20,
     571,    14,    -1,    63,    19,   298,    13,   571,    20,   571,
      20,   571,    20,   571,    14,    -1,    63,    19,   299,    13,
     571,    14,    -1,    63,    19,   300,    13,   571,    20,   571,
      14,    -1,    63,    19,   519,    13,    71,    14,    -1,    63,
      19,   376,    13,   573,    14,    -1,   573,    19,   425,    13,
     571,    14,    -1,   573,    19,   425,    13,   571,    20,   571,
      20,   571,    14,    -1,   573,    19,   406,    13,   571,    14,
      -1,   573,    19,   406,    13,   571,    20,   571,    20,   571,
      14,    -1,   573,    19,   407,    13,   571,    20,   571,    20,
     571,    14,    -1,   573,    19,   158,    13,   573,    20,   571,
      20,   571,    20,   571,    14,    -1,   573,    19,   158,    13,
     573,    14,    -1,   573,    19,    49,    13,   550,    14,    -1,
     165,    19,   220,    13,   573,    20,   571,    20,   571,    20,
     571,    14,    -1,   165,    19,   221,    13,   571,    14,    -1,
     165,    19,   168,    13,   571,    14,    -1,   165,    19,   226,
      13,   571,    14,    -1,   165,    19,   227,    13,   571,    14,
      -1,   165,    19,   230,    13,   573,    14,    -1,   165,    19,
     231,    13,   573,    14,    -1,   165,    19,   232,    13,   573,
      14,    -1,   165,    19,   233,    13,   573,    14,    -1,   165,
      19,   234,    13,   571,    14,    -1,   165,    19,   235,    13,
     571,    14,    -1,   165,    19,   236,    13,   571,    14,    -1,
     165,    19,   237,    13,   571,    14,    -1,   165,    19,   221,
      13,   571,    20,   571,    14,    -1,   165,    19,   222,    -1,
     165,    19,   223,    -1,   210,    19,   222,    -1,   210,    19,
     223,    -1,   211,    19,   222,    -1,   211,    19,   223,    -1,
     175,    19,   193,    13,   571,    20,   571,    20,   571,    20,
     571,    14,    -1,   175,    19,   193,    13,   571,    20,   571,
      20,   571,    20,   571,    20,   571,    20,   571,    14,    -1,
     175,    19,   177,    13,   571,    14,    -1,   175,    19,   178,
      13,   571,    14,    -1,   175,    19,   179,    13,   571,    14,
      -1,   175,    19,   192,    13,   571,    14,    -1,   175,    19,
     196,    13,   571,    14,    -1,   175,    19,   201,    13,   571,
      14,    -1,   175,    19,   202,    13,   571,    14,    -1,   175,
      19,   203,    13,   571,    14,    -1,   175,    19,   204,    13,
     571,    14,    -1,   175,    19,   199,    13,   571,    14,    -1,
     175,    19,   200,    13,   571,    20,   571,    20,   571,    14,
      -1,   175,    19,   205,    13,   571,    14,    -1,   175,    19,
     206,    13,   571,    20,   571,    20,   571,    20,   571,    20,
     571,    14,    -1,   175,    19,   194,    13,   571,    14,    -1,
     175,    19,   180,    13,   573,    20,   571,    14,    -1,   175,
      19,   181,    13,   571,    14,    -1,   175,    19,   182,    13,
     573,    14,    -1,   175,    19,   195,    13,   571,    20,   571,
      14,    -1,   175,    19,   184,    13,   573,    14,    -1,   175,
      19,   183,    13,   573,    20,   573,    20,   573,    14,    -1,
     175,    19,   186,    13,   573,    14,    -1,   175,    19,   187,
      13,   573,    14,    -1,   175,    19,   188,    13,   573,    14,
      -1,   175,    19,   191,    13,   573,    14,    -1,   175,    19,
     189,    13,   573,    14,    -1,   175,    19,   190,    13,   573,
      14,    -1,   175,    19,   186,    13,   171,    14,    -1,   175,
      19,   188,    13,   171,    14,    -1,   175,    19,   189,    13,
     171,    14,    -1,   175,    19,   197,    13,   571,    14,    -1,
     175,    19,   198,    13,   571,    14,    -1,   175,    19,   222,
      -1,   175,    19,   223,    -1,   573,    19,   241,   550,    -1,
     573,    19,   242,    -1,   573,    19,   243,    13,   573,    14,
      -1,   573,    19,   244,    13,   573,    14,    -1,   612,    19,
     241,   550,    -1,   612,    19,   294,   550,    -1,   612,    19,
     356,    13,   571,    14,    -1,   612,    19,   371,    13,   571,
      20,   571,    20,   571,    14,    -1,   612,    19,   372,    13,
     571,    20,   571,    20,   571,    14,    -1,   612,    19,   373,
      13,   571,    20,   571,    20,   571,    14,    -1,   612,    19,
     374,    13,   571,    14,    -1,   612,    19,   375,    13,   571,
      14,    -1,   612,    19,   377,    13,   571,    14,    -1,   612,
      19,   378,    13,   571,    14,    -1,   612,    19,   359,    13,
     571,    14,    -1,   612,    19,   357,    13,   571,    20,   571,
      20,   571,    14,    -1,   612,    19,   394,    13,   573,    14,
      -1,   612,    19,   358,    13,   592,    20,   571,    20,   571,
      14,    -1,   612,    19,   358,    13,   592,    14,    -1,   612,
      19,   380,    13,   573,    14,    -1,   612,    19,   387,    13,
     571,    14,    -1,   612,    19,   388,    -1,   612,    19,   271,
      13,   571,    14,    -1,   612,    19,   389,    13,   592,    14,
      -1,   612,    19,   392,    13,   571,    20,   571,    20,   571,
      14,    -1,   612,    19,   393,    13,   571,    20,   571,    20,
     571,    14,    -1,   612,    19,   395,    13,   571,    14,    -1,
     612,    19,   279,    13,   571,    14,    -1,   612,    19,   385,
      13,   592,    14,    -1,   612,    19,   386,    -1,   612,    19,
     340,    -1,   612,    19,   390,    -1,   612,    19,   391,    -1,
     612,    19,   339,    13,   571,    14,    -1,   612,    19,   341,
      13,   571,    14,    -1,   612,    19,   337,    -1,   612,    19,
     351,    13,   571,    14,    -1,   612,    19,   350,    13,   571,
      14,    -1,   612,    19,   350,    13,   571,    20,   571,    14,
      -1,   612,    19,   396,    13,   571,    20,   571,    20,   571,
      14,    -1,   612,    19,   397,    -1,   612,    19,   399,    13,
     571,    14,    -1,   612,    19,   398,    -1,   517,    13,   550,
      14,    -1,   518,    13,    63,    20,   571,    20,   571,    20,
     571,    20,   571,    20,   571,    20,   571,    20,   571,    20,
     571,    14,    -1,   612,    19,   510,    13,   592,    14,    -1,
      65,    19,   348,    13,   571,    20,   571,    20,   571,    14,
      -1,    65,    19,   352,    13,   613,    14,    -1,    65,   124,
     612,    -1,    65,   125,   612,    -1,    65,    19,   369,    13,
     612,    14,    -1,    65,    19,   370,    -1,    65,    19,   350,
      13,   571,    14,    -1,    65,    19,   350,    13,   571,    20,
     571,    14,    -1,    65,    19,   353,    13,   571,    14,    -1,
      65,    19,   410,    13,    65,    14,    -1,    65,    19,   411,
      13,    56,    20,   573,    14,    -1,    65,    19,   426,    13,
     571,    20,   592,    20,   571,    20,   571,    20,   571,    20,
     571,    14,    -1,    65,    19,   427,    13,   571,    14,    -1,
      65,    19,   405,    -1,    65,    19,   401,    13,   593,    14,
      -1,    65,    19,   401,    13,   593,    20,   571,    14,    -1,
      65,    19,   360,    -1,    65,    19,   363,    13,   571,    20,
     571,    20,   571,    20,   571,    14,    -1,    65,    19,   364,
      13,   571,    20,   571,    20,   571,    20,   571,    14,    -1,
      65,    19,   365,    13,   571,    20,   571,    20,   571,    20,
     571,    14,    -1,    65,    19,   366,    13,   571,    20,   571,
      20,   571,    14,    -1,    65,    19,   367,    -1,    65,    19,
     368,    -1,    65,    19,   421,    13,   571,    20,   571,    14,
      -1,   266,    13,   573,    20,   571,    20,   571,    14,    -1,
     266,    13,   573,    20,   571,    20,   571,    20,   592,    14,
      -1,   267,    13,   573,    20,   571,    20,   571,    14,    -1,
     267,    13,   573,    20,   571,    20,   571,    20,   592,    14,
      -1,   267,    13,   573,    20,   571,    20,   571,    20,   592,
      20,   571,    14,    -1,   268,    13,   573,    20,   571,    14,
      -1,   268,    13,   573,    20,   571,    20,   592,    14,    -1,
     268,    13,   573,    20,   571,    20,   571,    14,    -1,   268,
      13,   573,    20,   571,    20,   571,    20,   592,    14,    -1,
     270,    13,   573,    20,   571,    20,   571,    20,   571,    20,
     571,    20,   571,    20,   571,    14,    -1,   270,    13,   573,
      20,   571,    20,   571,    20,   571,    20,   571,    20,   571,
      20,   571,    20,   592,    14,    -1,   269,    13,   573,    20,
     571,    20,   571,    20,   592,    20,   571,    14,    -1,   271,
      13,   573,    20,   571,    14,    -1,   316,    13,    54,    20,
     573,    20,   573,    20,   573,    20,   573,    20,   573,    20,
     573,    20,   592,    14,    -1,   316,    13,    54,    20,   573,
      20,   573,    20,   573,    20,   573,    20,   573,    20,   573,
      14,    -1,   315,    13,    54,    20,   573,    20,   573,    20,
     573,    20,   592,    14,    -1,   315,    13,    54,    20,   573,
      20,   573,    20,   573,    14,    -1,   273,    13,   573,    20,
     571,    20,   571,    20,   571,    14,    -1,   573,    19,   273,
      13,   571,    20,   571,    20,   571,    14,    -1,   573,    19,
     273,    13,   573,    14,    -1,   573,    19,   274,    13,   571,
      20,   571,    20,   571,    14,    -1,   573,    19,   274,    13,
     573,    14,    -1,   573,    19,   275,    13,   571,    14,    -1,
     160,    13,   573,    20,   573,    14,    -1,   160,    13,   573,
      20,   573,    20,   573,    14,    -1,   571,    -1,   329,    13,
     571,    14,    -1,   330,    13,   571,    14,    -1,   444,    13,
     592,    20,   550,    20,   571,    14,    -1,   447,    13,   573,
      14,    -1,   314,    13,   573,    20,   573,    20,   571,    20,
     571,    20,   571,    20,   571,    20,   571,    20,   571,    14,
      -1,   488,    13,    54,    14,    -1,   172,    -1,   174,    -1,
     614,   144,    89,    13,   550,    14,    -1,    74,    19,    95,
      -1,    74,    19,    97,    13,   571,    20,   571,    14,    -1,
      74,    19,    91,    -1,    74,    19,    93,    -1,    74,    19,
     115,    -1,    74,    19,   116,    -1,    74,    19,   117,    -1,
      74,    19,   100,    -1,    74,    19,   101,    -1,    74,    19,
      41,    -1,    74,    19,   118,    -1,    74,    19,   409,    -1,
      74,    19,   409,    13,   571,    14,    -1,    74,    19,   110,
      13,   571,    20,   571,    14,    -1,    74,    19,   111,    13,
      71,    14,    -1,    74,    19,   113,    13,   571,    20,   571,
      20,   571,    14,    -1,    74,    19,   112,    13,   571,    14,
      -1,    74,    19,   112,    13,   571,    20,   571,    14,    -1,
      74,    19,   119,    13,   571,    20,   571,    14,    -1,    74,
      19,   120,    13,   571,    20,   571,    14,    -1,    74,    19,
     121,    13,   571,    20,   571,    14,    -1,   520,    13,   573,
      20,   550,    14,    -1,    75,    19,    42,    -1,    75,    19,
     241,   550,    -1,   521,    -1,   522,    -1,   523,    -1,   524,
      -1,   525,    -1,   526,    -1,   527,    -1,   528,    13,   573,
      20,   573,    20,   573,    20,   573,    20,   573,    20,   573,
      20,   573,    20,   571,    20,   571,    20,   571,    20,   571,
      20,   571,    20,   571,    20,   571,    14,    -1,   529,    13,
     573,    20,   573,    20,   571,    20,   571,    20,   571,    20,
     571,    20,   571,    20,   571,    20,   573,    20,   573,    20,
     571,    14,    -1,    69,    13,   545,    14,    -1,   512,    13,
     571,    20,   571,    20,   571,    14,    -1,   550,    -1,   544,
      20,   550,    -1,    -1,   571,    -1,   545,    20,   571,    -1,
     550,    -1,   545,    20,   550,    -1,    17,    59,    -1,   545,
      20,    17,    59,    -1,    17,    60,    -1,   545,    20,    17,
      60,    -1,   592,    -1,   545,    20,   592,    -1,    17,   573,
      -1,   545,    20,    17,   573,    -1,    17,   612,    -1,   545,
      20,    17,   612,    -1,    63,    -1,   545,    20,    63,    -1,
      -1,   492,    57,    -1,   493,    57,    -1,   489,    57,    -1,
     490,    57,    -1,   491,    57,    -1,   546,    20,   492,    57,
      -1,   546,    20,   493,    57,    -1,   546,    20,   489,    57,
      -1,   546,    20,   490,    57,    -1,   546,    20,   491,    57,
      -1,    54,    -1,    62,    -1,   547,    -1,    46,    13,   550,
      20,   571,    14,    -1,    45,    13,   550,    14,    12,   571,
      -1,    45,    13,   550,    14,    12,   550,    -1,   173,    -1,
     573,    19,    50,    -1,    50,    13,   615,    14,    -1,    51,
      13,   615,    14,    -1,    31,    -1,   548,    -1,   549,    10,
     548,    -1,   549,    11,   548,    -1,   549,    -1,   552,    55,
     553,    -1,    -1,    -1,    56,    -1,    32,    -1,   453,    -1,
     454,    -1,    59,    -1,    60,    -1,    61,    -1,    13,   571,
      14,    -1,   554,    -1,   573,    13,   571,    14,    -1,   573,
      13,   571,    20,   571,    14,    -1,   573,    13,   571,    20,
     571,    20,   571,    14,    -1,   573,    19,   412,    13,   571,
      20,   571,    20,   571,    14,    -1,   573,    13,   571,    20,
     571,    20,   571,    20,   571,    14,    -1,   573,    13,   571,
      20,   571,    20,   571,    23,   571,    14,    -1,   573,    13,
     571,    20,   571,    23,   571,    14,    -1,   573,    13,   571,
      23,   571,    14,    -1,   573,    19,   220,    -1,   573,    19,
     614,    -1,   573,    19,   238,    -1,    73,   238,    -1,   612,
      19,   238,    -1,   612,    19,   239,    -1,   612,    19,   240,
      -1,   225,    13,   573,    20,   573,    14,    -1,   258,    13,
     573,    14,    -1,   331,    13,   573,    20,   571,    20,   571,
      20,   571,    14,    -1,   332,    13,   573,    14,    -1,   332,
      13,   571,    20,   571,    20,   571,    20,   571,    14,    -1,
     145,    13,   592,    14,    -1,   260,    13,   592,    14,    -1,
     146,    13,   592,    14,    -1,   147,    13,   592,    14,    -1,
     148,    13,   592,    14,    -1,   149,    13,   592,    14,    -1,
     146,    15,   592,    16,    13,   592,    14,    -1,   148,    15,
     592,    16,    13,   573,    14,    -1,   149,    15,   592,    16,
      13,   573,    14,    -1,   149,    15,   592,    16,    13,   573,
      20,   571,    14,    -1,   260,    15,   592,    16,    13,   592,
      14,    -1,   260,    13,   573,    20,   592,    14,    -1,   443,
      13,   550,    14,    -1,    63,    19,   305,    -1,    63,    19,
     306,    -1,    63,    19,   303,    -1,    63,    19,   304,    -1,
      63,    19,   301,    -1,    63,    19,   302,    -1,    63,    19,
     307,    -1,    63,    19,   308,    -1,    63,    19,   309,    -1,
     165,    19,   228,    -1,   165,    19,   229,    -1,   175,    19,
     176,    -1,    66,    13,   571,    20,   571,    14,    -1,    66,
      13,   571,    20,   571,    14,   144,   571,    -1,    74,    19,
      98,    13,    59,    20,   571,    20,   571,    14,    -1,    74,
      19,    98,    13,    59,    20,   550,    20,   571,    20,   571,
      14,    -1,    74,    19,    99,    13,    60,    20,   571,    20,
     571,    14,    -1,    74,    19,    99,    13,    60,    20,   550,
      20,   571,    20,   571,    14,    -1,    74,    19,   102,    13,
     550,    20,    71,    14,    -1,    74,    19,   103,    13,    61,
      14,    -1,    74,    19,   103,    13,    61,    20,   550,    14,
      -1,    74,    19,   106,    13,    62,    20,   550,    14,    -1,
      74,    19,   104,    13,    60,    20,   571,    14,    -1,    74,
      19,   104,    13,    60,    20,   550,    14,    -1,    74,    19,
     104,    13,    60,    14,    -1,    74,    19,   105,    13,   571,
      20,   550,    14,    -1,    74,    19,   107,    13,    62,    20,
     550,    14,    -1,    74,    19,   109,    13,   550,    20,   550,
      14,    -1,    74,    19,   108,    13,    62,    20,   550,    20,
     550,    20,   550,    14,    -1,    74,    19,   114,    13,   550,
      14,    -1,    74,    19,    96,    13,   550,    14,    -1,    74,
      19,    94,    -1,    74,    19,    90,    13,   550,    14,    -1,
      74,    19,    92,    13,   550,    14,    -1,   485,    13,   614,
      14,    -1,   485,    13,   615,    14,    -1,   486,    13,   550,
      14,    -1,   572,    -1,    67,    19,   450,    13,   550,    14,
      -1,    67,    19,   451,    13,    59,    14,    -1,    67,    19,
     451,    13,    62,    14,    -1,   612,    19,   290,    -1,   146,
      13,   571,    20,   571,    14,    -1,   555,    -1,   557,   558,
      -1,     9,   558,    -1,    11,   558,    -1,    10,   558,    -1,
     455,   558,    -1,   456,   558,    -1,   466,   558,    -1,   467,
     558,    -1,   468,   558,    -1,   469,   558,    -1,   457,   558,
      -1,   458,   558,    -1,   459,   558,    -1,   460,   558,    -1,
     463,   558,    -1,   465,   558,    -1,   464,   558,    -1,     7,
      -1,   530,    -1,   556,    -1,    13,   572,    14,   556,    -1,
     558,    -1,   559,     7,   558,    -1,   559,     8,   558,    -1,
     559,    12,   558,    -1,   559,    -1,   560,    10,   559,    -1,
     560,    11,   559,    -1,   560,    -1,   561,    -1,   562,     6,
     561,    -1,   562,     5,   561,    -1,   562,   138,   561,    -1,
     562,   139,   561,    -1,   562,    -1,   563,   140,   562,    -1,
     563,   141,   562,    -1,   550,   140,   550,    -1,   550,   141,
     550,    -1,   563,    -1,   564,    17,   563,    -1,   564,    -1,
     565,     4,   564,    -1,   565,    -1,   566,    18,   565,    -1,
     566,    -1,   567,   136,   566,    -1,   567,    -1,   568,   137,
     567,    -1,   568,    -1,   568,    21,   568,    22,   569,    -1,
     569,    -1,   570,    -1,   432,    -1,   433,    -1,   434,    -1,
     435,    -1,   436,    -1,   437,    -1,   438,    -1,   439,    -1,
     440,    -1,   441,    -1,   573,    19,   442,    -1,    58,    -1,
      77,    15,   571,    16,    -1,    35,   550,    -1,    35,    13,
     550,    14,    -1,    36,    13,   571,    20,   571,    20,   572,
      20,   571,    20,   550,    20,   571,    20,   571,    14,    -1,
      36,    13,   571,    20,   571,    20,   571,    20,   572,    20,
     571,    20,   550,    14,    -1,    36,    13,   571,    20,   571,
      20,   571,    20,   572,    20,   571,    20,   571,    20,   550,
      14,    -1,   310,    13,   550,    14,    -1,   311,    13,   550,
      14,    -1,    70,    13,   545,    14,    -1,    35,    -1,    35,
      13,   572,    20,   571,    20,   571,    20,   571,    14,    -1,
      35,    13,   572,    20,   571,    20,   571,    20,   571,    20,
     571,    14,    -1,    35,    13,   572,    20,   571,    20,   573,
      14,    -1,   573,    -1,   573,    15,   571,    16,    -1,   261,
      13,   592,    20,   571,    14,    -1,   262,    13,   592,    20,
     571,    14,    -1,   263,    13,   592,    20,   571,    14,    -1,
     264,    13,   592,    20,   592,    20,   571,    14,    -1,   265,
      13,   592,    20,   592,    20,   571,    14,    -1,   146,    13,
     592,    20,   592,    14,    -1,   150,    13,   573,    20,    54,
      14,    -1,   150,    13,   573,    20,    54,    20,   572,    14,
      -1,   150,    13,   573,    20,   573,    20,    54,    14,    -1,
     150,    13,   573,    20,   573,    20,    54,    20,   572,    14,
      -1,   150,    13,   573,    20,   573,    20,   573,    20,    54,
      14,    -1,   150,    13,   573,    20,   573,    20,   573,    20,
      54,    20,   572,    14,    -1,   151,    13,   592,    20,   571,
      20,   571,    20,   571,    20,   571,    14,    -1,   503,    19,
     504,    13,   573,    20,   571,    20,   571,    14,    -1,   343,
      13,   573,    14,    -1,   170,    13,   573,    20,   571,    20,
     571,    20,   571,    14,    -1,   344,    13,   573,    14,    -1,
     245,    13,   592,    20,   571,    14,    -1,   246,    13,   573,
      14,    -1,   247,    13,   573,    14,    -1,   248,    13,   573,
      14,    -1,   249,    13,   573,    20,   573,    20,   571,    20,
     571,    20,   571,    14,    -1,   250,    13,   573,    14,    -1,
     251,    13,   573,    20,   573,    20,   573,    20,   571,    20,
     573,    14,    -1,   252,    13,   573,    20,   573,    20,   573,
      20,   571,    20,   573,    14,    -1,   253,    13,   573,    20,
     573,    20,   573,    20,   571,    20,   573,    20,   571,    20,
     571,    14,    -1,   254,    13,   573,    20,   573,    20,   573,
      20,   571,    20,   573,    20,   571,    20,   571,    20,   571,
      20,   571,    14,    -1,   255,    13,   573,    20,   573,    20,
     573,    20,   573,    14,    -1,   255,    13,   573,    20,   573,
      20,   573,    20,   573,    20,   571,    14,    -1,   256,    13,
     573,    14,    -1,   256,    13,   573,    20,   573,    14,    -1,
     257,    13,   573,    20,   573,    14,    -1,   152,    13,   592,
      20,   571,    14,    -1,   153,    13,   573,    14,    -1,   169,
      13,   573,    14,    -1,   154,    13,   573,    20,   571,    14,
      -1,   272,    13,   573,    14,    -1,   155,    13,   573,    20,
     571,    14,    -1,   156,    13,   573,    20,   571,    14,    -1,
     159,    13,   592,    20,   571,    14,    -1,   573,    15,   616,
      16,    -1,   573,    15,    22,    20,    22,    20,   571,    22,
     571,    16,    -1,   157,    13,   573,    20,   571,    20,   571,
      20,   571,    20,   571,    20,   571,    20,   571,    14,    -1,
     161,    13,   573,    20,   571,    20,   571,    20,   571,    14,
      -1,   161,    13,   573,    20,   571,    20,   571,    14,    -1,
     161,    13,   573,    20,   571,    20,   571,    20,   571,    20,
     571,    14,    -1,   162,    13,   573,    20,   571,    20,   571,
      20,   571,    14,    -1,   162,    13,   573,    20,   571,    20,
     571,    14,    -1,   162,    13,   573,    20,   571,    20,   571,
      20,   571,    20,   571,    14,    -1,   163,    13,   573,    20,
     571,    20,   571,    14,    -1,   163,    13,   573,    20,   571,
      20,   571,    20,   571,    20,   571,    14,    -1,   164,    13,
     573,    20,   571,    20,   571,    14,    -1,   164,    13,   573,
      20,   571,    20,   571,    20,   571,    20,   571,    14,    -1,
     165,    19,    52,    -1,   165,    19,    53,    -1,   175,    19,
     220,    13,   573,    20,   571,    14,    -1,   175,    19,   220,
      13,   573,    20,   573,    14,    -1,   175,    19,    52,    -1,
     175,    19,   185,    13,   573,    14,    -1,   165,    13,   573,
      20,   571,    20,   571,    20,   571,    20,   571,    14,    -1,
     209,    13,   573,    20,   573,    20,   571,    20,   571,    20,
     571,    14,    -1,   167,    13,   573,    20,   571,    20,   571,
      20,   571,    20,   571,    20,   571,    14,    -1,   166,    13,
     573,    20,   571,    20,   571,    20,   571,    20,   571,    14,
      -1,   210,    19,   220,    13,   573,    20,   571,    20,   571,
      20,   571,    14,    -1,   211,    19,   220,    13,   573,    20,
     571,    20,   571,    20,   571,    20,   571,    20,   571,    14,
      -1,   212,    13,   573,    14,    -1,   213,    13,   573,    20,
     571,    20,   571,    14,    -1,   213,    13,   573,    20,   571,
      20,   571,    20,   616,    14,    -1,   213,    13,   573,    20,
     571,    20,   571,    20,   571,    20,   616,    14,    -1,   214,
      13,   573,    20,   571,    20,   571,    20,   616,    14,    -1,
     214,    13,   573,    20,   571,    20,   571,    20,   571,    20,
     616,    14,    -1,   215,    13,   573,    20,   571,    20,   571,
      20,   616,    14,    -1,   216,    13,   573,    20,   571,    20,
     571,    20,   571,    20,   616,    14,    -1,   217,    13,   573,
      20,   571,    20,   571,    20,   571,    20,   616,    14,    -1,
     218,    13,   573,    20,   571,    20,   571,    20,   571,    20,
     571,    20,   616,    14,    -1,   219,    13,   573,    20,   571,
      20,   571,    20,   571,    20,   571,    14,    -1,   224,    13,
     573,    20,   571,    20,   571,    14,    -1,   259,    13,   573,
      20,   571,    20,   571,    20,   571,    20,   571,    20,   571,
      14,    -1,   428,    13,   573,    14,    -1,   429,    13,   573,
      14,    -1,   430,    13,   573,    14,    -1,   431,    13,   573,
      14,    -1,    65,    19,   346,    -1,    65,    19,   347,    -1,
      63,    19,   346,    -1,   281,    13,   573,    20,   571,    14,
      -1,   282,    13,   573,    20,   571,    14,    -1,   283,    13,
     573,    20,   571,    14,    -1,   284,    13,   573,    20,   571,
      14,    -1,   207,    13,   592,    20,   592,    20,   571,    14,
      -1,   208,    13,   592,    20,   592,    20,   571,    20,   571,
      20,   571,    20,   571,    14,    -1,   207,    13,   592,    20,
     592,    20,   571,    20,   571,    20,   571,    14,    -1,   207,
      13,   592,    20,   592,    20,   571,    20,   571,    20,   571,
      20,   571,    14,    -1,   207,    13,   592,    20,   592,    20,
     573,    20,   571,    20,   571,    14,    -1,   312,    13,   573,
      20,   573,    14,    -1,   313,    13,   573,    20,   573,    20,
     592,    14,    -1,   317,    13,   573,    20,   571,    20,   571,
      20,   571,    14,    -1,   318,    13,   573,    20,   571,    20,
     571,    20,   571,    14,    -1,   318,    13,   573,    20,   571,
      20,   571,    20,   571,    20,   571,    14,    -1,   319,    13,
     573,    20,   571,    14,    -1,   320,    13,   573,    20,   571,
      14,    -1,   321,    13,   573,    20,   571,    14,    -1,   322,
      13,   573,    20,   571,    14,    -1,   323,    13,   573,    20,
     571,    14,    -1,   324,    13,   573,    20,   571,    14,    -1,
     325,    13,   573,    20,   571,    14,    -1,   326,    13,   573,
      20,   571,    14,    -1,   326,    13,   573,    20,   571,    20,
     571,    14,    -1,   327,    13,   573,    20,   571,    20,   571,
      20,   571,    14,    -1,   328,    13,   592,    14,    -1,   573,
      13,   592,    14,    -1,   445,    13,   592,    20,   571,    20,
     571,    20,   571,    14,    -1,   446,    13,   592,    20,   571,
      20,   571,    20,   571,    14,    -1,   497,    13,   592,    14,
      -1,   497,    13,   592,    20,   571,    14,    -1,   500,    13,
     592,    20,   571,    14,    -1,   498,    13,   592,    20,   571,
      20,   571,    20,   571,    20,   571,    14,    -1,   499,    13,
     573,    20,   573,    20,   571,    20,   571,    20,   571,    20,
     571,    20,   571,    20,   571,    20,   571,    20,   571,    20,
     571,    20,   571,    20,   571,    20,   571,    14,    -1,   502,
      13,   592,    20,   571,    20,   571,    14,    -1,   612,    19,
     382,    13,    14,    -1,   612,    19,   291,    13,   571,    14,
      -1,   612,    19,   383,    13,    14,    -1,   612,    19,   384,
      13,    14,    -1,   612,    19,   381,    13,   573,    14,    -1,
     508,    13,   592,    20,   571,    14,    -1,   508,    13,   592,
      14,    -1,   509,    13,   592,    20,   571,    14,    -1,   509,
      13,   592,    14,    -1,   514,    13,   592,    20,   592,    14,
      -1,   515,    13,   592,    14,    -1,   516,    13,   550,    14,
      -1,   487,    13,   592,    20,   571,    20,   571,    20,   571,
      20,   571,    20,   571,    20,   571,    20,   571,    14,    -1,
     289,    13,   612,    20,   573,    20,   592,    14,    -1,   293,
      13,   612,    20,   550,    14,    -1,   574,    -1,    13,   592,
      14,    -1,   575,    -1,   576,    -1,   557,   578,    -1,    11,
     578,    -1,    10,   578,    -1,   455,   578,    -1,   456,   578,
      -1,   466,   578,    -1,   467,   578,    -1,   468,   578,    -1,
     469,   578,    -1,   457,   578,    -1,   458,   578,    -1,   459,
     578,    -1,   460,   578,    -1,   463,   578,    -1,   465,   578,
      -1,   464,   578,    -1,   470,   578,    -1,   577,    -1,    13,
     572,    14,   577,    -1,   578,    -1,   579,     7,   558,    -1,
     579,     8,   558,    -1,   579,     7,   578,    -1,   579,     8,
     578,    -1,   579,     4,   578,    -1,   579,    -1,   580,    -1,
     581,    10,   559,    -1,   581,    11,   559,    -1,   581,    10,
     579,    -1,   581,    11,   579,    -1,   581,    -1,   582,    -1,
     583,     6,   582,    -1,   583,     5,   582,    -1,   583,   138,
     582,    -1,   583,   139,   582,    -1,   583,     6,   561,    -1,
     583,     5,   561,    -1,   583,   138,   561,    -1,   583,   139,
     561,    -1,   583,    -1,   584,   140,   583,    -1,   584,   141,
     583,    -1,   584,   140,   561,    -1,   584,   141,   561,    -1,
     584,    -1,   585,    17,   584,    -1,   585,    -1,   586,    -1,
     587,    18,   586,    -1,   587,    -1,   588,   136,   587,    -1,
     588,    -1,   589,   137,   588,    -1,   589,    -1,   589,    21,
     589,    22,   590,    -1,   590,    -1,   577,   144,   591,    -1,
     591,    -1,    75,    -1,    65,    19,   400,    -1,   402,    13,
      75,    20,    75,    20,   571,    14,    -1,    37,    13,   550,
      14,    -1,   403,    13,   571,    20,   571,    14,    -1,    66,
      -1,   404,    13,   611,    14,    -1,   594,    -1,    13,   611,
      14,    -1,   595,    -1,   596,    -1,   557,   598,    -1,    11,
     598,    -1,    10,   598,    -1,   598,   142,    -1,   455,   598,
      -1,   456,   598,    -1,   466,   598,    -1,   467,   598,    -1,
     468,   598,    -1,   469,   598,    -1,   457,   598,    -1,   458,
     598,    -1,   459,   598,    -1,   460,   598,    -1,   463,   598,
      -1,   465,   598,    -1,   464,   598,    -1,   597,    -1,   598,
      -1,   599,     7,   558,    -1,   599,   143,   598,    -1,   599,
       7,   598,    -1,   599,    -1,   600,    10,   559,    -1,   600,
      11,   559,    -1,   600,    10,   599,    -1,   600,    11,   599,
      -1,   600,    -1,   601,    -1,   602,    -1,   603,    -1,   604,
      -1,   605,    -1,   606,    -1,   607,    -1,   608,    -1,   609,
      -1,   610,    -1,    64,    -1,    76,    15,   571,    16,    -1,
     333,    13,   592,    20,   571,    14,    -1,   336,    13,   573,
      20,   571,    14,    -1,   333,    13,   592,    20,   571,    20,
     573,    14,    -1,   342,    13,   592,    20,   571,    20,   592,
      14,    -1,   337,    13,   612,    14,    -1,   337,    13,   612,
      20,   571,    14,    -1,   338,    13,   573,    20,   571,    14,
      -1,   339,    13,   612,    20,   571,    14,    -1,   341,    13,
     612,    20,   571,    14,    -1,   345,    13,    14,    -1,   345,
     550,    -1,   345,    13,   550,    14,    -1,   345,    -1,   292,
      13,   550,    14,    -1,   292,    13,   550,    20,   571,    14,
      -1,   612,    -1,   276,    13,   573,    14,    -1,   277,    13,
     612,    14,    -1,   277,    13,   612,    20,   571,    20,   571,
      20,   571,    14,    -1,   278,    13,   612,    20,   571,    14,
      -1,   285,    13,   612,    20,   571,    20,   571,    20,   571,
      20,   571,    20,   571,    20,   571,    14,    -1,   286,    13,
     592,    20,   571,    20,   571,    20,   571,    20,   571,    20,
     571,    20,   571,    20,   571,    14,    -1,   287,    13,   592,
      20,   571,    20,   571,    20,   571,    14,    -1,   288,    13,
     592,    20,   571,    20,   571,    20,   571,    20,   571,    20,
     571,    20,   571,    20,   571,    20,   571,    14,    -1,   288,
      13,   592,    20,   571,    20,   571,    20,   571,    20,   571,
      20,   571,    14,    -1,   612,    19,   280,    13,   571,    20,
     571,    14,    -1,   505,    13,   592,    14,    -1,   505,    13,
     592,    20,   571,    14,    -1,   505,    13,   592,    20,   571,
      20,   571,    14,    -1,   507,    13,   592,    20,   571,    20,
     571,    14,    -1,   506,    13,   592,    20,   571,    20,   571,
      20,   592,    20,   592,    14,    -1,   506,    13,   592,    20,
     571,    20,   571,    20,   592,    20,   592,    20,   592,    20,
     571,    14,    -1,   511,    13,   592,    20,   592,    20,   592,
      20,   571,    20,   571,    20,   571,    20,   571,    14,    -1,
     511,    13,   592,    20,   592,    20,   592,    20,   571,    20,
     571,    20,   571,    20,   571,    20,   571,    14,    -1,   511,
      13,   592,    20,   592,    20,   592,    20,   571,    20,   571,
      20,   571,    14,    -1,   511,    13,   592,    20,   571,    20,
     571,    20,   571,    20,   571,    20,   571,    14,    -1,   513,
      13,   592,    20,   592,    20,   592,    20,   571,    20,   571,
      20,   571,    20,   571,    14,    -1,   513,    13,   592,    20,
     592,    20,   592,    20,   571,    20,   571,    20,   571,    20,
     571,    20,   592,    20,   592,    14,    -1,    57,    -1,    60,
      -1,    59,    -1,    61,    -1,   573,    -1,    63,    -1,    64,
      -1,    65,    -1,    67,    -1,    68,    -1,    69,    -1,    70,
      -1,    71,    -1,    72,    -1,    73,    -1,    62,    -1,    66,
      -1,    75,    -1,    74,    -1,    76,    -1,    77,    -1,   571,
      22,   571,    20,   571,    22,   571,    20,   571,    22,   571,
      -1,   571,    22,   571,    20,   571,    22,   571,    -1,   573,
      -1,    63,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  Parser::yyprhs_[] =
  {
         0,     0,     3,     4,     7,     9,    12,    15,    19,    21,
      24,    26,    29,    31,    34,    36,    39,    41,    44,    46,
      49,    51,    53,    62,    73,    80,    83,    88,    95,    96,
     105,   106,   115,   120,   123,   127,   130,   133,   139,   142,
     144,   146,   148,   150,   152,   154,   159,   166,   173,   180,
     187,   191,   195,   202,   209,   213,   217,   221,   225,   232,
     236,   240,   244,   251,   258,   267,   274,   283,   287,   293,
     297,   303,   312,   321,   325,   327,   329,   331,   333,   342,
     347,   352,   354,   357,   360,   363,   365,   369,   373,   377,
     384,   391,   408,   411,   414,   418,   421,   424,   428,   432,
     435,   438,   442,   445,   452,   455,   458,   464,   467,   469,
     471,   474,   477,   480,   483,   486,   491,   496,   499,   502,
     505,   508,   510,   515,   519,   522,   525,   536,   543,   547,
     554,   561,   570,   599,   608,   617,   621,   630,   643,   650,
     657,   674,   683,   700,   711,   718,   729,   738,   749,   764,
     773,   786,   793,   802,   809,   816,   823,   834,   841,   852,
     863,   876,   883,   890,   903,   910,   917,   924,   931,   938,
     945,   952,   959,   966,   973,   980,   987,   996,  1000,  1004,
    1008,  1012,  1016,  1020,  1033,  1050,  1057,  1064,  1071,  1078,
    1085,  1092,  1099,  1106,  1113,  1120,  1131,  1138,  1153,  1160,
    1169,  1176,  1183,  1192,  1199,  1210,  1217,  1224,  1231,  1238,
    1245,  1252,  1259,  1266,  1273,  1280,  1287,  1291,  1295,  1300,
    1304,  1311,  1318,  1323,  1328,  1335,  1346,  1357,  1368,  1375,
    1382,  1389,  1396,  1403,  1414,  1421,  1432,  1439,  1446,  1453,
    1457,  1464,  1471,  1482,  1493,  1500,  1507,  1514,  1518,  1522,
    1526,  1530,  1537,  1544,  1548,  1555,  1562,  1571,  1582,  1586,
    1593,  1597,  1602,  1623,  1630,  1641,  1648,  1652,  1656,  1663,
    1667,  1674,  1683,  1690,  1697,  1706,  1723,  1730,  1734,  1741,
    1750,  1754,  1767,  1780,  1793,  1804,  1808,  1812,  1821,  1830,
    1841,  1850,  1861,  1874,  1881,  1890,  1899,  1910,  1927,  1946,
    1959,  1966,  1985,  2002,  2015,  2026,  2037,  2048,  2055,  2066,
    2073,  2080,  2087,  2096,  2098,  2103,  2108,  2117,  2122,  2141,
    2146,  2148,  2150,  2157,  2161,  2170,  2174,  2178,  2182,  2186,
    2190,  2194,  2198,  2202,  2206,  2210,  2217,  2226,  2233,  2244,
    2251,  2260,  2269,  2278,  2287,  2294,  2298,  2303,  2305,  2307,
    2309,  2311,  2313,  2315,  2317,  2348,  2373,  2378,  2387,  2389,
    2393,  2394,  2396,  2400,  2402,  2406,  2409,  2414,  2417,  2422,
    2424,  2428,  2431,  2436,  2439,  2444,  2446,  2450,  2451,  2454,
    2457,  2460,  2463,  2466,  2471,  2476,  2481,  2486,  2491,  2493,
    2495,  2497,  2504,  2511,  2518,  2520,  2524,  2529,  2534,  2536,
    2538,  2542,  2546,  2548,  2552,  2553,  2554,  2556,  2558,  2560,
    2562,  2564,  2566,  2568,  2572,  2574,  2579,  2586,  2595,  2606,
    2617,  2628,  2637,  2644,  2648,  2652,  2656,  2659,  2663,  2667,
    2671,  2678,  2683,  2694,  2699,  2710,  2715,  2720,  2725,  2730,
    2735,  2740,  2748,  2756,  2764,  2774,  2782,  2789,  2794,  2798,
    2802,  2806,  2810,  2814,  2818,  2822,  2826,  2830,  2834,  2838,
    2842,  2849,  2858,  2869,  2882,  2893,  2906,  2915,  2922,  2931,
    2940,  2949,  2958,  2965,  2974,  2983,  2992,  3005,  3012,  3019,
    3023,  3030,  3037,  3042,  3047,  3052,  3054,  3061,  3068,  3075,
    3079,  3086,  3088,  3091,  3094,  3097,  3100,  3103,  3106,  3109,
    3112,  3115,  3118,  3121,  3124,  3127,  3130,  3133,  3136,  3139,
    3141,  3143,  3145,  3150,  3152,  3156,  3160,  3164,  3166,  3170,
    3174,  3176,  3178,  3182,  3186,  3190,  3194,  3196,  3200,  3204,
    3208,  3212,  3214,  3218,  3220,  3224,  3226,  3230,  3232,  3236,
    3238,  3242,  3244,  3250,  3252,  3254,  3256,  3258,  3260,  3262,
    3264,  3266,  3268,  3270,  3272,  3274,  3278,  3280,  3285,  3288,
    3293,  3310,  3325,  3342,  3347,  3352,  3357,  3359,  3370,  3383,
    3392,  3394,  3399,  3406,  3413,  3420,  3429,  3438,  3445,  3452,
    3461,  3470,  3481,  3492,  3505,  3518,  3529,  3534,  3545,  3550,
    3557,  3562,  3567,  3572,  3585,  3590,  3603,  3616,  3633,  3654,
    3665,  3678,  3683,  3690,  3697,  3704,  3709,  3714,  3721,  3726,
    3733,  3740,  3747,  3752,  3763,  3780,  3791,  3800,  3813,  3824,
    3833,  3846,  3855,  3868,  3877,  3890,  3894,  3898,  3907,  3916,
    3920,  3927,  3940,  3953,  3968,  3981,  3994,  4011,  4016,  4025,
    4036,  4049,  4060,  4073,  4084,  4097,  4110,  4125,  4138,  4147,
    4162,  4167,  4172,  4177,  4182,  4186,  4190,  4194,  4201,  4208,
    4215,  4222,  4231,  4246,  4259,  4274,  4287,  4294,  4303,  4314,
    4325,  4338,  4345,  4352,  4359,  4366,  4373,  4380,  4387,  4394,
    4403,  4414,  4419,  4424,  4435,  4446,  4451,  4458,  4465,  4478,
    4509,  4518,  4524,  4531,  4537,  4543,  4550,  4557,  4562,  4569,
    4574,  4581,  4586,  4591,  4610,  4619,  4626,  4628,  4632,  4634,
    4636,  4639,  4642,  4645,  4648,  4651,  4654,  4657,  4660,  4663,
    4666,  4669,  4672,  4675,  4678,  4681,  4684,  4687,  4689,  4694,
    4696,  4700,  4704,  4708,  4712,  4716,  4718,  4720,  4724,  4728,
    4732,  4736,  4738,  4740,  4744,  4748,  4752,  4756,  4760,  4764,
    4768,  4772,  4774,  4778,  4782,  4786,  4790,  4792,  4796,  4798,
    4800,  4804,  4806,  4810,  4812,  4816,  4818,  4824,  4826,  4830,
    4832,  4834,  4838,  4847,  4852,  4859,  4861,  4866,  4868,  4872,
    4874,  4876,  4879,  4882,  4885,  4888,  4891,  4894,  4897,  4900,
    4903,  4906,  4909,  4912,  4915,  4918,  4921,  4924,  4927,  4929,
    4931,  4935,  4939,  4943,  4945,  4949,  4953,  4957,  4961,  4963,
    4965,  4967,  4969,  4971,  4973,  4975,  4977,  4979,  4981,  4983,
    4985,  4990,  4997,  5004,  5013,  5022,  5027,  5034,  5041,  5048,
    5055,  5059,  5062,  5067,  5069,  5074,  5081,  5083,  5088,  5093,
    5104,  5111,  5128,  5147,  5158,  5179,  5194,  5203,  5208,  5215,
    5224,  5233,  5246,  5263,  5280,  5299,  5314,  5329,  5346,  5367,
    5369,  5371,  5373,  5375,  5377,  5379,  5381,  5383,  5385,  5387,
    5389,  5391,  5393,  5395,  5397,  5399,  5401,  5403,  5405,  5407,
    5409,  5421,  5429,  5431
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   961,   961,   962,   966,   966,   967,   968,   969,   969,
     970,   970,   971,   971,   972,   972,   973,   973,   974,   974,
     977,   978,   983,  1002,  1025,  1060,  1082,  1097,  1118,  1117,
    1147,  1146,  1187,  1206,  1228,  1235,  1270,  1276,  1285,  1295,
    1303,  1307,  1321,  1335,  1349,  1359,  1375,  1395,  1407,  1418,
    1429,  1441,  1452,  1472,  1494,  1506,  1517,  1522,  1532,  1555,
    1564,  1576,  1594,  1616,  1629,  1648,  1661,  1680,  1693,  1712,
    1726,  1746,  1779,  1796,  1801,  1805,  1809,  1814,  1818,  1833,
    1843,  1854,  1857,  1907,  1927,  1972,  1989,  2001,  2041,  2054,
    2089,  2119,  2139,  2143,  2147,  2151,  2155,  2159,  2163,  2167,
    2171,  2175,  2180,  2184,  2195,  2208,  2218,  2227,  2238,  2246,
    2258,  2507,  2517,  2527,  2537,  2591,  2599,  2607,  2616,  2626,
    2632,  2643,  2649,  2656,  2662,  2672,  2682,  2698,  2710,  2720,
    2768,  2783,  2804,  2835,  2850,  2857,  2864,  2882,  2905,  2910,
    2915,  2928,  2939,  2948,  2958,  2966,  2983,  2999,  3016,  3036,
    3051,  3069,  3082,  3096,  3105,  3119,  3130,  3143,  3161,  3183,
    3208,  3238,  3270,  3275,  3293,  3298,  3303,  3308,  3313,  3318,
    3332,  3347,  3364,  3378,  3398,  3403,  3408,  3415,  3424,  3432,
    3437,  3444,  3449,  3454,  3474,  3498,  3503,  3508,  3513,  3518,
    3523,  3528,  3533,  3538,  3543,  3548,  3553,  3558,  3563,  3568,
    3573,  3578,  3591,  3596,  3601,  3609,  3614,  3619,  3624,  3629,
    3634,  3639,  3644,  3649,  3654,  3659,  3664,  3669,  3673,  3700,
    3713,  3718,  3722,  3728,  3741,  3747,  3753,  3759,  3766,  3773,
    3780,  3789,  3800,  3815,  3830,  3838,  3845,  3852,  3858,  3862,
    3866,  3903,  3909,  3916,  3923,  3934,  3942,  3959,  3969,  3974,
    3981,  3988,  3996,  4004,  4023,  4039,  4056,  4073,  4078,  4083,
    4088,  4093,  4101,  4202,  4236,  4243,  4251,  4257,  4264,  4274,
    4283,  4290,  4297,  4307,  4314,  4328,  4342,  4350,  4355,  4363,
    4371,  4382,  4394,  4406,  4418,  4424,  4433,  4442,  4455,  4462,
    4473,  4495,  4521,  4549,  4559,  4572,  4582,  4604,  4633,  4650,
    4665,  4672,  4694,  4713,  4731,  4745,  4750,  4755,  4764,  4769,
    4778,  4792,  4799,  4806,  4808,  4825,  4841,  4880,  4893,  4937,
    4942,  4947,  4953,  4970,  4980,  4995,  5001,  5008,  5014,  5020,
    5026,  5032,  5047,  5058,  5064,  5078,  5092,  5109,  5116,  5137,
    5155,  5174,  5194,  5214,  5234,  5241,  5246,  5252,  5257,  5262,
    5267,  5272,  5277,  5282,  5287,  5322,  5349,  5356,  5378,  5386,
    5403,  5407,  5414,  5421,  5429,  5437,  5446,  5453,  5460,  5467,
    5474,  5481,  5488,  5495,  5502,  5509,  5516,  5526,  5531,  5540,
    5547,  5554,  5561,  5568,  5575,  5582,  5589,  5596,  5604,  5609,
    5624,  5630,  5644,  5660,  5676,  5689,  5693,  5704,  5723,  5733,
    5734,  5744,  5752,  5755,  5766,  5767,  5770,  5771,  5779,  5787,
    5796,  5800,  5804,  5808,  5816,  5817,  5832,  5848,  5862,  5877,
    5894,  5910,  5924,  5937,  5958,  6018,  6043,  6063,  6082,  6089,
    6097,  6102,  6107,  6135,  6141,  6152,  6171,  6190,  6209,  6228,
    6247,  6266,  6289,  6311,  6334,  6341,  6365,  6388,  6396,  6406,
    6416,  6426,  6436,  6446,  6456,  6470,  6487,  6503,  6508,  6513,
    6517,  6524,  6532,  6567,  6605,  6622,  6642,  6654,  6671,  6691,
    6724,  6743,  6765,  6781,  6799,  6823,  6844,  6872,  6886,  6896,
    6909,  6923,  6938,  6946,  6954,  6966,  6970,  6985,  6992,  7002,
    7014,  7027,  7028,  7029,  7030,  7031,  7032,  7033,  7034,  7035,
    7036,  7037,  7045,  7046,  7047,  7048,  7049,  7061,  7073,  7089,
    7090,  7094,  7096,  7112,  7113,  7114,  7115,  7119,  7120,  7121,
    7125,  7130,  7131,  7132,  7133,  7134,  7138,  7139,  7140,  7141,
    7142,  7146,  7147,  7155,  7156,  7160,  7164,  7171,  7175,  7182,
    7186,  7193,  7194,  7201,  7205,  7211,  7216,  7220,  7224,  7228,
    7232,  7236,  7240,  7244,  7248,  7252,  7260,  7265,  7282,  7288,
    7294,  7352,  7406,  7462,  7483,  7504,  7518,  7547,  7555,  7574,
    7600,  7613,  7691,  7758,  7766,  7774,  7784,  7794,  7824,  7842,
    7862,  7880,  7900,  7918,  7937,  7977,  7992,  8006,  8022,  8045,
    8059,  8073,  8087,  8101,  8136,  8150,  8171,  8192,  8233,  8279,
    8296,  8315,  8329,  8343,  8357,  8376,  8391,  8406,  8423,  8444,
    8461,  8477,  8489,  8518,  8538,  8583,  8595,  8606,  8619,  8631,
    8642,  8668,  8695,  8727,  8744,  8762,  8775,  8788,  8808,  8831,
    8845,  8860,  8894,  8931,  8966,  8999,  9016,  9033,  9047,  9068,
    9091,  9115,  9140,  9165,  9187,  9209,  9233,  9276,  9300,  9332,
    9355,  9392,  9429,  9466,  9501,  9506,  9515,  9520,  9531,  9541,
    9551,  9560,  9581,  9611,  9637,  9666,  9699,  9710,  9726,  9736,
    9746,  9761,  9775,  9789,  9802,  9815,  9827,  9839,  9851,  9862,
    9875,  9902,  9935, 10051, 10075, 10117, 10129, 10138, 10147, 10170,
   10195, 10208, 10218, 10255, 10273, 10291, 10301, 10311, 10319, 10327,
   10335, 10360, 10380, 10388, 10422, 10445, 10465, 10465, 10467, 10469,
   10470, 10471, 10472, 10473, 10474, 10475, 10476, 10477, 10478, 10479,
   10480, 10481, 10482, 10483, 10484, 10485, 10486, 10500, 10501, 10523,
   10524, 10530, 10532, 10533, 10534, 10537, 10542, 10543, 10544, 10545,
   10546, 10549, 10553, 10554, 10555, 10556, 10557, 10558, 10559, 10560,
   10561, 10565, 10566, 10567, 10568, 10569, 10573, 10574, 10579, 10583,
   10584, 10588, 10589, 10593, 10594, 10598, 10599, 10603, 10604, 10607,
   10611, 10621, 10634, 10645, 10662, 10669, 10679, 10694, 10694, 10696,
   10698, 10699, 10700, 10701, 10702, 10711, 10712, 10713, 10714, 10715,
   10716, 10717, 10718, 10719, 10720, 10721, 10722, 10723, 10727, 10729,
   10730, 10731, 10732, 10742, 10743, 10744, 10745, 10746, 10749, 10753,
   10757, 10761, 10766, 10770, 10774, 10778, 10782, 10786, 10789, 10794,
   10799, 10815, 10826, 10836, 10856, 10890, 10899, 10908, 10917, 10926,
   10934, 10940, 10946, 10952, 10978, 10992, 11008, 11018, 11036, 11064,
   11091, 11106, 11129, 11163, 11195, 11242, 11283, 11307, 11317, 11340,
   11352, 11365, 11402, 11445, 11493, 11545, 11588, 11616, 11649, 11692,
   11696, 11697, 11698, 11699, 11703, 11704, 11705, 11706, 11707, 11708,
   11709, 11710, 11711, 11712, 11713, 11714, 11715, 11716, 11717, 11718,
   11723, 11731, 11738, 11754
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
       2,     2,     2,     2,     2,     2,   530,     2,     2,     2,
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
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 16301;
  const int Parser::yynnts_ = 86;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 401;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 531;

  const unsigned int Parser::yyuser_token_number_max_ = 784;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // yyip

/* Line 1054 of lalr1.cc  */
#line 20649 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"


/* Line 1056 of lalr1.cc  */
#line 11774 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"

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

void CB_delete_imagedraw( void* var)
{
  Variable* vartodelete = (Variable*) var;

  FILE_MESSAGE(boost::format("deleting %1%") % vartodelete->Name());
  if (Vars.deleteVar(vartodelete)==0)
    FILE_ERROR("Could not delete variable "); 

// deleting is risky, use smart pointers instead ...
//  delete name;
}

void CB_delete_surfdraw( void* varid)
{
  fprintf(stderr," CB_delete_surfdraw begin \n");
  Variable* v = (Variable*) varid;
  fprintf(stderr," Delete var %s \n", v->Name().c_str());
  if (Vars.deleteVar( v->Name().c_str())==0)
    fprintf(stderr,"CB_delete_surfdraw() could not delete variable '%s' !!! \n",v->Name().c_str());
  fprintf(stderr," CB_delete_surfdraw end \n");
}


//------------------------------------------------------
void wxScheduleTimer::Notify()
//   -----------------------
{
  //cout << "Notify()" << endl;
  CB_ParamWin(var);

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





