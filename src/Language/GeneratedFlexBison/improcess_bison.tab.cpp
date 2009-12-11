
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
#line 947 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"


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
#line 940 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 590 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 57: /* "IDENTIFIER" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 599 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 548: /* "primary_expr_string" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 608 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 549: /* "postfix_expr_string" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 617 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 550: /* "additive_expr_string" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 626 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 551: /* "expr_string" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 635 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 552: /* "instr_block" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ablock); };

/* Line 480 of lalr1.cc  */
#line 644 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 615: /* "identifier" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 653 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 617: /* "image_extent" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 986 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1005 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1028 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1062 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1084 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1099 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1119 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_driver.procedure_declaration = true;
    }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 1124 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1148 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      // allow overriding current functions
      GB_driver.procedure_declaration = true;
    }
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 1154 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1190 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1208 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1230 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       //driver.res_print($2);
       driver.parse_script((yysemantic_stack_[(3) - (2)].astring));
       delete [] (yysemantic_stack_[(3) - (2)].astring);
     }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 1237 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1272 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      string_ptr inputstring( new std::string((yysemantic_stack_[(2) - (2)].astring)));
      driver.parse_string( *inputstring,
                          "'eval string' command");
     }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 1278 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        Variable*       var   = (yysemantic_stack_[(5) - (1)].variable);
        ParamList::ptr  param((yysemantic_stack_[(5) - (3)].paramlist));

        driver.yyip_call_function(var,param);


        }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 1287 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable*    var   = (yysemantic_stack_[(2) - (1)].variable);

          // Call the function
          driver.yyip_call_function(var);
        }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 1296 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1304 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           YYABORT;
         }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1309 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1323 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1337 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1351 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1361 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1377 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1397 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1409 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1420 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1431 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1443 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1454 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1474 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1496 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1508 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1519 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr m1 = *((FloatMatrix::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer()));
          (*m1) = (yysemantic_stack_[(3) - (3)].adouble);
       }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 1524 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1534 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1557 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variables* contextptr = new Variables();
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
          contextptr->SetName(ident->GetName());

          Vars.AddVar(type_context,ident,(void*)contextptr);
        }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1566 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1578 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1596 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1618 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1631 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1650 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1663 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1682 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1695 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1714 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1728 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1748 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1781 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1798 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
            rewind(file.get());
        }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1803 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 1;
        }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1807 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 0;
        }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1811 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 1;
      verbose = 1;
    }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 1816 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 0;
    }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 1820 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1835 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1845 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1855 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GB_main_wxFrame->Close(true);
        }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 1859 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1909 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1929 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1974 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1991 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2003 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2043 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2056 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2091 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2121 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2141 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(float_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))++;
        }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 2145 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(float_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))--;
        }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 2149 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          *(*(float_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer()) = (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 2153 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(int_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))++;
        }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 2157 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(int_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))--;
        }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 2161 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          *(*(int_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer()) = (int) (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 2165 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           *(*(uchar_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer()) = (unsigned char) (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 2169 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (*(*(uchar_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))++;
        }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 2173 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (*(*(uchar_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))--;
        }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 2177 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          string_ptr newname( new std::string((yysemantic_stack_[(3) - (3)].astring)));
          (yysemantic_stack_[(3) - (1)].variable)->SetString(newname);
        }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 2182 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Vars.display();
        }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 2186 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2197 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2210 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2220 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2229 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2240 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//         std::ostream streamtest(TC->GetLog());
//        std::cout=streamtest;
         //wxStreamToTextRedirector redirect(TC->GetLog());

         std::system("ls");
           }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 2248 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2260 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2509 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2519 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2529 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2539 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2593 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(4) - (1)].variable)->Pointer());
          string_ptr text( new std::string((yysemantic_stack_[(4) - (4)].astring)));

          fprintf(file.get(),"%s",text->c_str());
          fflush(file.get());
        }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 2601 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(4) - (1)].variable)->Pointer());
          string_ptr text( new std::string((yysemantic_stack_[(4) - (4)].astring)));

          fprintf(file.get(),"%s\n",text->c_str());
          fflush(file.get());
        }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 2609 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2618 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2628 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=driver.matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
      }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 2634 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2645 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=driver.matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
          }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 2651 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(4) - (1)].variable)->Pointer());

          fprintf(file.get(),"%5.10f",(yysemantic_stack_[(4) - (4)].adouble));
          fflush(file.get());
        }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 2658 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            printf("Files are not close anymore: delete the variable instead \n");
          //FILE_ptr file = *(FILE_ptr*) ($1->Pointer());
          //fclose(file.get());
        }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 2664 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2674 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2684 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2700 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2712 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2722 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2770 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2785 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2810 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2837 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2852 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(8) - (1)].variable)->Pointer());
          draw->SetVectorVisible( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 2859 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
          draw->CB_AfficheChampVect(draw.get(),NULL);
        }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 2866 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2884 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2907 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw= *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          draw->SetVectType((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 2912 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw= *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          draw->SetLineThickness((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 2917 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2930 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2941 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2950 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2960 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          draw->SetGLWindow( *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer()));

        }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 2968 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2985 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3001 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3018 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3038 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3053 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3071 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3084 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3098 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3107 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3121 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3132 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3145 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3163 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3185 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        int x = (int) round((double)(yysemantic_stack_[(10) - (5)].adouble));
        int y = (int) round((double)(yysemantic_stack_[(10) - (7)].adouble));
        int z = (int) round((double)(yysemantic_stack_[(10) - (9)].adouble));
        Si (*(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->CoordOK( x,y,z)
        Alors
          (*(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->BufferPos(x,y,z);
        Sinon
          std::string tmp_string;
          tmp_string = (boost::format("setpos \t coord = (%1% %2% %3%) from (%4% %5% %6%) \n")%x%y%z % (yysemantic_stack_[(10) - (5)].adouble) % (yysemantic_stack_[(10) - (7)].adouble) % (yysemantic_stack_[(10) - (9)].adouble)).str();
         driver.err_print(tmp_string);
        FinSi
        }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 3215 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3243 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3274 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->FixeNom( (yysemantic_stack_[(6) - (5)].astring));
      delete [] (yysemantic_stack_[(6) - (5)].astring);
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 3280 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3298 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_SetCoeffAnisoGS((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 3303 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetDistanceMap((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 3308 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseType((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 3313 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseSD((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 3318 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetMask(((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 3323 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3337 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3352 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3369 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3383 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3403 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setdt((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 3408 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setneighborhood((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 3413 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_SetCoeffAnisoGS3D((yysemantic_stack_[(8) - (5)].adouble),(yysemantic_stack_[(8) - (7)].adouble));

    }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 3420 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float  error;

      error = Func_ItereAnisoGS();

      //driver.res_print("Error in AnisoGS.Iterate ");
    }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 3429 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int res;

      res = Func_EndAnisoGS();

    }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 3437 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 3442 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_EndWeickert();

    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 3449 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 3454 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_EndWeickert();
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 3459 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3480 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3503 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetMeanCurv( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 3508 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetAffineCurvature( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 3513 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetBalloonScheme( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 3518 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetDMmethod( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 3523 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetThreads( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 3528 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 3533 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityLowThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 3538 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityHighThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 3543 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbabilityHighThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 3548 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumGaussians( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 3553 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetGaussian( (int) (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 3558 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumInitPoints( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 3563 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetInitPoint( (int) (yysemantic_stack_[(14) - (5)].adouble), (int) (yysemantic_stack_[(14) - (7)].adouble), (int) (yysemantic_stack_[(14) - (9)].adouble), (int) (yysemantic_stack_[(14) - (11)].adouble), (int) (yysemantic_stack_[(14) - (13)].adouble));
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 3568 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSets_SetIsoContourBin( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 3573 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsVelocity(((InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get(),(yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 3578 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsExpansion((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 3583 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3596 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsBandAndTube((int)(yysemantic_stack_[(8) - (5)].adouble),(int)(yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 3601 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSetCurvWeights( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 3606 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSetAdvectionField(
                ((InrImage::ptr*) (yysemantic_stack_[(10) - (5)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(10) - (7)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(10) - (9)].variable)->Pointer())->get());
        }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 3614 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetCurvatureData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 3619 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetDistanceMap( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 3624 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetAdvectionData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 3629 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetSkeleton( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 3634 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetVelocityData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 3639 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetExpansionData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 3644 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetCurvatureData( NULL );
        }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 3649 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetAdvectionData( NULL);
        }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 3654 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetVelocityData( NULL);
        }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 3659 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsSaveDistMap( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 3664 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsSaveSecDerGrad( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 3669 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.aint) = Func_LevelSets_Iterate();
    }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 3674 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_End();
    }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 3678 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3705 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3718 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_OrientField( ((InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->get() , ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );
        }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 3723 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       Func_OrientPositive( ((InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->get() , ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );
    }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 3727 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())->Write((yysemantic_stack_[(4) - (4)].astring));
      delete [] (yysemantic_stack_[(4) - (4)].astring);
    }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 3733 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3746 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetOwnMaterial( (int) (yysemantic_stack_[(6) - (5)].adouble));

        }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 3752 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->GetMaterial()._ambient.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 3758 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->GetMaterial()._diffuse.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 3764 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->GetMaterial()._specular.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 3771 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->GetMaterial()._shininess= (yysemantic_stack_[(6) - (5)].adouble);

        }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 3778 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->GetMaterial()._opacity= (yysemantic_stack_[(6) - (5)].adouble);

    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 3785 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3794 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3805 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3820 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3835 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());


      s->SetPointsColors( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

    }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 3843 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());
      InrImage::ptr i = InrImage::ptr(driver.im_stack.GetLastImage());
      // TODO: use smart pointer to image in SetColors ...
      s->SetColors( i.get() , (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 3850 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      InrImage::ptr i = InrImage::ptr(driver.im_stack.GetLastImage());
      s->SetColors( i.get() );

    }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 3857 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      s->Statistics( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

    }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 3863 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->MergePoints((yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 3867 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->Triangulate();
    }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 3871 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3908 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      InrImage::ptr i = InrImage::ptr(driver.im_stack.GetLastImage());
      s->DisplacePoints( i.get() );
    }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 3914 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

      s->Translate( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble) );

    }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 3921 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

      s->Scale( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble),0 );

        }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 3928 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3939 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

      s->RemoveLine((int)(yysemantic_stack_[(6) - (5)].adouble));
          s->GLRecomputeList();

    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 3947 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3964 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3974 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GLRecomputeList();

        }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 3979 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

      s->RecomputeNormals();

        }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 3986 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

      s->InvertNormals();

        }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 3993 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          Func_ApplyvtkSmooth(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 4001 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          Func_vtkWindowedSinc(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 4009 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4028 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4044 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4061 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4078 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());
      s->AddPoint((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 4083 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      s->NewLine();
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 4088 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      s->LineAddPointNumber( (int) (yysemantic_stack_[(6) - (5)].adouble) );
    }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 4093 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      s->EndLine();
    }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 4098 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4107 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4207 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4241 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->UserRotate((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 4248 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          SurfacePoly::ptr surf = SurfacePoly::ptr(driver.surf_stack.GetLastSurf());

          sdraw->GetCanvas()->AddSurface(surf);
          sdraw->Paint();
        }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 4256 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());
          sdraw->GetCanvas()->AddSurface(*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (3)].variable)->Pointer());
          //sdraw->Paint();
        }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 4262 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->RemoveSurface(*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (3)].variable)->Pointer());
          sdraw->Paint();
        }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 4269 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4279 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4288 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC ( (int) (yysemantic_stack_[(6) - (5)].adouble) );
          sdraw->Paint();
        }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 4295 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
          sdraw->Paint();
        }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 4302 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4312 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw1 = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          Viewer3D_ptr sdraw2 = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer());

          sdraw1->AddCompSurf(sdraw2);
        }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 4319 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4333 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4347 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Viewer3D_ptr draw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      int num = (int) (yysemantic_stack_[(6) - (5)].adouble);

      draw->GetCanvas()->HideFreeSection(num);

        }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 4355 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr glclass=*((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());
          glclass->GetCanvas()->PrintMatrices();
        }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 4360 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4368 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4376 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4387 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4399 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4411 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4423 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->SetBG((int)(yysemantic_stack_[(10) - (5)].adouble),(int)(yysemantic_stack_[(10) - (7)].adouble),(int)(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 4429 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4438 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4447 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4460 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_StructureTensor(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                   (yysemantic_stack_[(8) - (3)].variable)->Name().c_str(),
                   (yysemantic_stack_[(8) - (5)].adouble), (yysemantic_stack_[(8) - (7)].adouble), NULL);
        }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 4467 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4478 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4500 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4526 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4554 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4564 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4577 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4587 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4609 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4638 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4656 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4670 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_Curvatures(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
              (yysemantic_stack_[(6) - (3)].variable)->Name().c_str(),
              (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 4682 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4703 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4722 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4739 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4750 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get())->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 4755 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 4760 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4769 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->SetTranslation((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 4774 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4783 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4797 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_DiscSecDerGrad(
        ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
        ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 4804 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_DiscSecDerGrad(
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (7)].variable)->Pointer())->get());
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 4810 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.aint)=1;}
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 4813 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4830 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4846 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4885 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4902 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4942 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_GenRead((yysemantic_stack_[(4) - (3)].astring));
        }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 4947 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.InitCumul();
        }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 4952 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Debut();
        }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 4957 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Fin();
      cout << "time spent = " << driver.IP_time << endl;
        }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 4963 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 324:

/* Line 678 of lalr1.cc  */
#line 4980 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description:
        Ends a notebook.
    **/
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndBook();
    }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 4990 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 326:

/* Line 678 of lalr1.cc  */
#line 5005 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndPanel();
    }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 5011 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndPanel();
      pw->EndBox( );
    }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 5018 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndBox( );
    }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 5024 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->BeginHorizontal( );
    }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 5030 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
        pw->EndHorizontal( );
        }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 5036 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          pw->CreeDialogue( );
        }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 5042 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 333:

/* Line 678 of lalr1.cc  */
#line 5057 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Hides the given parameter panel, the smart pointer copy is released
        **/
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

          GB_main_wxFrame->RemoveParamPanelPage(pw);
        }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 5068 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          pw->ReAfficheParametres();
        }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 5074 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 336:

/* Line 678 of lalr1.cc  */
#line 5088 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 337:

/* Line 678 of lalr1.cc  */
#line 5102 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 338:

/* Line 678 of lalr1.cc  */
#line 5119 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
          int n = pw->NbParameters();
            pw->ChangedValueCallback(n-1,(void*) CB_ParamWin, (void*) (yysemantic_stack_[(6) - (5)].variable) );
        }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 5129 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 340:

/* Line 678 of lalr1.cc  */
#line 5148 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 341:

/* Line 678 of lalr1.cc  */
#line 5166 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 342:

/* Line 678 of lalr1.cc  */
#line 5184 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 343:

/* Line 678 of lalr1.cc  */
#line 5204 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 344:

/* Line 678 of lalr1.cc  */
#line 5224 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 345:

/* Line 678 of lalr1.cc  */
#line 5244 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage::ptr   i = *(InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer();
          Func_VectorImage2StructuredGrid(i.get(),(yysemantic_stack_[(6) - (5)].astring));
          delete [] (yysemantic_stack_[(6) - (5)].astring);
        }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 5251 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(GLTransfMatrix_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->Print();
        }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 5256 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_SaveTransform(((GLTransfMatrix_ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())->get(),(yysemantic_stack_[(4) - (4)].astring));
          delete [] (yysemantic_stack_[(4) - (4)].astring);
        }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 5262 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapFluid();
        }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 5267 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapVTK();
        }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 5272 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapITK();
        }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 5277 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapWII();
        }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 5282 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapFilters();
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 5287 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapSystem();
        }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 5292 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapMainFrame();
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 5303 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 356:

/* Line 678 of lalr1.cc  */
#line 5335 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 357:

/* Line 678 of lalr1.cc  */
#line 5359 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable*  var   = (yysemantic_stack_[(4) - (1)].variable);
          ParamList::ptr param((yysemantic_stack_[(4) - (3)].paramlist));
          ((void (*)(ParamList*)) var->Pointer())(param.get());
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 5366 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 359:

/* Line 678 of lalr1.cc  */
#line 5388 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = new std::list<std::string>();
            sl->push_back(string((yysemantic_stack_[(1) - (1)].astring)));
            delete [] (yysemantic_stack_[(1) - (1)].astring);
            (yyval.string_list) = sl;
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 5396 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = (yysemantic_stack_[(3) - (1)].string_list);
            sl->push_back(string((yysemantic_stack_[(3) - (3)].astring)));
            delete [] (yysemantic_stack_[(3) - (3)].astring);
            (yyval.string_list) = sl;
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 5412 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          (yyval.paramlist) = pl;
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 5417 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl(new ParamList);
          float_ptr* x = new float_ptr(new float((yysemantic_stack_[(1) - (1)].adouble)));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 5424 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);
          float_ptr* x= new float_ptr(new float((yysemantic_stack_[(3) - (3)].adouble)));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 5431 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          string_ptr* x = new string_ptr(new string((yysemantic_stack_[(1) - (1)].astring)));
          delete [] (yysemantic_stack_[(1) - (1)].astring);
          pl->AddParam(type_string, x);
          (yyval.paramlist) = pl;
         }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 5439 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);
          string_ptr* x = new string_ptr(new string((yysemantic_stack_[(3) - (3)].astring)));
          delete [] (yysemantic_stack_[(3) - (3)].astring);
          pl->AddParam(type_string, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 5447 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  new ParamList();
          // creating reference
          float_ptr* x = new float_ptr(*((float_ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer()));

          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 5456 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          float_ptr*   x = new float_ptr(* ((float_ptr*)(yysemantic_stack_[(4) - (4)].variable)->Pointer()));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 5463 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          int_ptr*   x = new int_ptr(*((int_ptr*)(yysemantic_stack_[(2) - (2)].variable)->Pointer()));
          pl->AddParam(type_int, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 5470 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          int_ptr*   x = new int_ptr( *((int_ptr*)(yysemantic_stack_[(4) - (4)].variable)->Pointer()));
          pl->AddParam(type_int, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 5477 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          InrImage::ptr* i = new InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 5484 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(3) - (1)].paramlist);
          InrImage::ptr*   i = new InrImage::ptr( (InrImage*) driver.im_stack.GetLastImage());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 5491 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          InrImage::ptr*  i = new InrImage::ptr(*(InrImage::ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 5498 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          InrImage::ptr* i = new InrImage::ptr(*(InrImage::ptr*) (yysemantic_stack_[(4) - (4)].variable)->Pointer());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 5505 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          SurfacePoly::ptr*  s = new SurfacePoly::ptr(*(SurfacePoly::ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer());
          pl->AddParam(type_surface, s);
          (yyval.paramlist) = pl;
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 5512 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          SurfacePoly::ptr*  s = new SurfacePoly::ptr(*(SurfacePoly::ptr*) (yysemantic_stack_[(4) - (4)].variable)->Pointer());
          pl->AddParam(type_surface, s);
          (yyval.paramlist) = pl;
        }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 5519 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          DessinImage::ptr* i = new DessinImage::ptr(*(DessinImage::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer());
          pl->AddParam(type_imagedraw, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 5526 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(3) - (1)].paramlist);
          DessinImage::ptr*  i = new DessinImage::ptr(*(DessinImage::ptr*) (yysemantic_stack_[(3) - (3)].variable)->Pointer());
          pl->AddParam(type_imagedraw, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 5535 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      //      printf("no parameters \n");
      ParamListDecl* pl = new ParamListDecl;
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 5541 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      cout << "param_list_decl: T_NUM IDENTIFIER" << endl;
      cout << ident->GetName().c_str() << endl;
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_float);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 5550 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_string);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 5557 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 5564 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 5571 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 5578 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_float);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 5585 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_string);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 5592 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 5599 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 5606 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 5614 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
        }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 5619 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 391:

/* Line 678 of lalr1.cc  */
#line 5634 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
          //fflush(stdout);
        }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 5640 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 393:

/* Line 678 of lalr1.cc  */
#line 5654 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 394:

/* Line 678 of lalr1.cc  */
#line 5670 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 395:

/* Line 678 of lalr1.cc  */
#line 5686 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 396:

/* Line 678 of lalr1.cc  */
#line 5709 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.astring)=(char*) (*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->Nom();
    }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 5713 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 398:

/* Line 678 of lalr1.cc  */
#line 5724 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 399:

/* Line 678 of lalr1.cc  */
#line 5744 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      char* res = new char[GB_scripts_dir.Len()+1];
      strcpy(res,(const char*)GB_scripts_dir.mb_str(wxConvUTF8));
      (yyval.astring)= res;
    }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 5755 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 402:

/* Line 678 of lalr1.cc  */
#line 5765 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          RemoveEndString((yysemantic_stack_[(3) - (1)].astring),(yysemantic_stack_[(3) - (3)].astring));
          (yyval.astring)=(yysemantic_stack_[(3) - (1)].astring);
        }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 5778 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        (yyval.ablock)=(yysemantic_stack_[(3) - (2)].ablock);
        if (GB_debug)
          cerr << format("ablock : %s")
                  % (yysemantic_stack_[(3) - (2)].ablock)->GetBody()
                << endl;
          }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 5792 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      returns the number of arguments in the command line
    **/
      (yyval.adouble)=GB_argc-GB_num_arg_parsed;
    }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 5800 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      Line number in the current script
    **/
      (yyval.adouble)=driver.yyiplineno;
    }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 5808 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        the constant Pi is set to
         3.14159265358979323846
      **/
      (yyval.adouble)= 3.14159265358979323846;
    }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 5817 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=*((float_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get();
    }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 5821 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = (float) *((int_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get();
    }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 5825 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = (float) *((uchar_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get();
    }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 5829 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(3) - (2)].adouble);
      fflush(stdout);
    }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 5838 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 417:

/* Line 678 of lalr1.cc  */
#line 5853 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 418:

/* Line 678 of lalr1.cc  */
#line 5869 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 419:

/* Line 678 of lalr1.cc  */
#line 5883 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 420:

/* Line 678 of lalr1.cc  */
#line 5898 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 421:

/* Line 678 of lalr1.cc  */
#line 5915 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 422:

/* Line 678 of lalr1.cc  */
#line 5931 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 423:

/* Line 678 of lalr1.cc  */
#line 5945 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 424:

/* Line 678 of lalr1.cc  */
#line 5958 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 425:

/* Line 678 of lalr1.cc  */
#line 5979 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 426:

/* Line 678 of lalr1.cc  */
#line 6039 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 427:

/* Line 678 of lalr1.cc  */
#line 6064 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 428:

/* Line 678 of lalr1.cc  */
#line 6084 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 429:

/* Line 678 of lalr1.cc  */
#line 6103 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

      (yyval.adouble) = s->GetNumberOfPoints();
    }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 6110 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

      (yyval.adouble) = s->GetNumberOfPolys();

    }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 6118 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_SNR(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 6123 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (yyval.adouble)=Func_eccentricity(((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());
        }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 6128 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 434:

/* Line 678 of lalr1.cc  */
#line 6156 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (yyval.adouble)=Func_ComputePositiveArea( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get() );
    }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 6162 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float val[4];

      val[0] = (yysemantic_stack_[(10) - (3)].adouble);
      val[1] = (yysemantic_stack_[(10) - (5)].adouble);
      val[2] = (yysemantic_stack_[(10) - (7)].adouble);
      val[3] = (yysemantic_stack_[(10) - (9)].adouble);
      (yyval.adouble)=Func_PositiveArea(val);
        }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 6173 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 437:

/* Line 678 of lalr1.cc  */
#line 6192 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 438:

/* Line 678 of lalr1.cc  */
#line 6211 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 439:

/* Line 678 of lalr1.cc  */
#line 6230 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 440:

/* Line 678 of lalr1.cc  */
#line 6249 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 441:

/* Line 678 of lalr1.cc  */
#line 6268 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 442:

/* Line 678 of lalr1.cc  */
#line 6287 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 443:

/* Line 678 of lalr1.cc  */
#line 6310 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 444:

/* Line 678 of lalr1.cc  */
#line 6332 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 445:

/* Line 678 of lalr1.cc  */
#line 6355 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();
          (yyval.adouble)=Func_med( ((InrImage::ptr*) (yysemantic_stack_[(9) - (6)].variable)->Pointer())->get(),(float) (yysemantic_stack_[(9) - (8)].adouble),mask);
          delete mask;
        }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 6362 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 447:

/* Line 678 of lalr1.cc  */
#line 6386 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 448:

/* Line 678 of lalr1.cc  */
#line 6409 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//    setlocale(LC_NUMERIC,"C");
      setlocale(LC_NUMERIC, "C");
      (yyval.adouble)=atof((yysemantic_stack_[(4) - (3)].astring));
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 6417 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._xmin;
        }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 6427 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._xmax;
        }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 6437 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._ymin;
        }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 6447 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._ymax;
        }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 6457 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._zmin;
        }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 6467 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._zmax;
        }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 6477 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 456:

/* Line 678 of lalr1.cc  */
#line 6491 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 457:

/* Line 678 of lalr1.cc  */
#line 6508 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 458:

/* Line 678 of lalr1.cc  */
#line 6524 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_AnisoGS_GetNoiseSD();
    }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 6529 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_AnisoGS_GetDAcoeff();
    }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 6534 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = Func_LevelSets_UpdateResult();
    }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 6538 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr mat = *(FloatMatrix::ptr*)(yysemantic_stack_[(6) - (1)].variable)->Pointer();
          int i = (int)(yysemantic_stack_[(6) - (3)].adouble);
          int j = (int)(yysemantic_stack_[(6) - (5)].adouble);
          (yyval.adouble) = (*mat)[i][j];
    }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 6545 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr mat = *(FloatMatrix::ptr*)(yysemantic_stack_[(8) - (1)].variable)->Pointer();
          int i = (int)(yysemantic_stack_[(8) - (3)].adouble);
          int j = (int)(yysemantic_stack_[(8) - (5)].adouble);
          (yyval.adouble)  =  ((*mat)[i][j] = (yysemantic_stack_[(8) - (8)].adouble));
    }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 6553 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 464:

/* Line 678 of lalr1.cc  */
#line 6588 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 465:

/* Line 678 of lalr1.cc  */
#line 6626 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 466:

/* Line 678 of lalr1.cc  */
#line 6643 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 467:

/* Line 678 of lalr1.cc  */
#line 6663 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 468:

/* Line 678 of lalr1.cc  */
#line 6675 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 469:

/* Line 678 of lalr1.cc  */
#line 6692 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 470:

/* Line 678 of lalr1.cc  */
#line 6712 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 471:

/* Line 678 of lalr1.cc  */
#line 6745 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 472:

/* Line 678 of lalr1.cc  */
#line 6764 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 473:

/* Line 678 of lalr1.cc  */
#line 6786 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 474:

/* Line 678 of lalr1.cc  */
#line 6802 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 475:

/* Line 678 of lalr1.cc  */
#line 6820 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 476:

/* Line 678 of lalr1.cc  */
#line 6844 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 477:

/* Line 678 of lalr1.cc  */
#line 6865 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 478:

/* Line 678 of lalr1.cc  */
#line 6893 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 479:

/* Line 678 of lalr1.cc  */
#line 6907 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    **/
      string_ptr label( new std::string((yysemantic_stack_[(6) - (5)].astring)));
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      int id = pw->AddPage( label->c_str());
      (yyval.adouble)=id;
    }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 6917 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 481:

/* Line 678 of lalr1.cc  */
#line 6930 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 482:

/* Line 678 of lalr1.cc  */
#line 6944 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 483:

/* Line 678 of lalr1.cc  */
#line 6959 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
    Check for the existence of a variable, returns 0
    **/
          (yyval.adouble)=0;
    }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 6967 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description: 
    Check for the existence of a variable, returns 1
    **/
          (yyval.adouble)=1;
    }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 6975 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 486:

/* Line 678 of lalr1.cc  */
#line 6987 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble) = (int) (yysemantic_stack_[(1) - (1)].aint);
    }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 6991 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 488:

/* Line 678 of lalr1.cc  */
#line 7006 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       float*  var = ((float_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get();
        FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
        setlocale(LC_NUMERIC, "C");
        (yyval.adouble) = fscanf(file.get(),"%f",var);
    }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 7013 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 490:

/* Line 678 of lalr1.cc  */
#line 7023 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 491:

/* Line 678 of lalr1.cc  */
#line 7035 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 493:

/* Line 678 of lalr1.cc  */
#line 7048 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(2) - (2)].adouble); }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 7049 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(!,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 7050 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(-,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 7051 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(+,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 7052 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(sin,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 7053 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(cos,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 7054 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(sqrt,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 7055 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(fabs,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 7056 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(round,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 7058 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:
                return the closest integer smaller than the given expression value.
           **/
          UNARYOP_EXPR(floor,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble))
        }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 7065 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(tan,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 7066 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(asin,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 7067 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(acos,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 7068 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(atan,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 7070 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 508:

/* Line 678 of lalr1.cc  */
#line 7082 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 509:

/* Line 678 of lalr1.cc  */
#line 7094 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 513:

/* Line 678 of lalr1.cc  */
#line 7117 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 515:

/* Line 678 of lalr1.cc  */
#line 7133 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)*(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 7134 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)/(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 7135 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)= ((int) round((yysemantic_stack_[(3) - (1)].adouble))) % ((int) round((yysemantic_stack_[(3) - (3)].adouble))); }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 7140 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)+(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 7141 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)-(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 7151 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)<(yysemantic_stack_[(3) - (3)].adouble));  }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 7152 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)>(yysemantic_stack_[(3) - (3)].adouble));  }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 7153 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)<=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 7154 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)>=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 7159 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)==(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 7160 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)!=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 7161 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(strcmp((yysemantic_stack_[(3) - (1)].astring),(yysemantic_stack_[(3) - (3)].astring))==0); }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 7162 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(strcmp((yysemantic_stack_[(3) - (1)].astring),(yysemantic_stack_[(3) - (3)].astring))!=0); }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 7168 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = ((int)(yysemantic_stack_[(3) - (1)].adouble)) & ((int)(yysemantic_stack_[(3) - (3)].adouble));
    }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 7181 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
        }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 7185 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = ((int)(yysemantic_stack_[(3) - (1)].adouble)) | ((int)(yysemantic_stack_[(3) - (3)].adouble));
        }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 7192 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
        }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 7196 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)&&(yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 7203 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
    }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 7207 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)||(yysemantic_stack_[(3) - (3)].adouble);
    }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 7215 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=((yysemantic_stack_[(5) - (1)].adouble)?(yysemantic_stack_[(5) - (3)].adouble):(yysemantic_stack_[(5) - (5)].adouble));
        }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 7232 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.err_print(" char format is not available: use unsigned char \n");
      (yyval.aint)=WT_UNSIGNED_CHAR;
    }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 7237 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.aint)=WT_UNSIGNED_CHAR;
       }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 7241 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_SHORT;
       }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 7245 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_SHORT;
       }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 7249 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_INT;
       }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 7253 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_INT;
       }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 7257 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT;
       }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 7261 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_DOUBLE;
       }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 7265 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_RGB;
       }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 7269 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT_VECTOR;
       }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 7273 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//        printf("format %d \n",(int) ( *(InrImage::ptr*) $1->Pointer())->GetFormat());
        (yyval.aint) = (int) (*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetFormat();
      }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 7281 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yysemantic_stack_[(1) - (1)].variable);
        }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 7286 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 559:

/* Line 678 of lalr1.cc  */
#line 7303 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     driver.im_stack.AddImage((yysemantic_stack_[(2) - (2)].astring));
     delete [] (yysemantic_stack_[(2) - (2)].astring);
       }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 7309 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     driver.im_stack.AddImage((yysemantic_stack_[(4) - (3)].astring));
     delete [] (yysemantic_stack_[(4) - (3)].astring);
       }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 7316 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 562:

/* Line 678 of lalr1.cc  */
#line 7374 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 563:

/* Line 678 of lalr1.cc  */
#line 7428 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 564:

/* Line 678 of lalr1.cc  */
#line 7483 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 565:

/* Line 678 of lalr1.cc  */
#line 7504 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 566:

/* Line 678 of lalr1.cc  */
#line 7525 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 567:

/* Line 678 of lalr1.cc  */
#line 7539 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 568:

/* Line 678 of lalr1.cc  */
#line 7568 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage* im;
        //printf(" ********** %d %f %f %f\n", $3, $5, $7, $9);
        im = new InrImage( (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble), (WORDTYPE) (yysemantic_stack_[(10) - (3)].aint));
        driver.im_stack.AddImage(im);
      }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 7576 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 570:

/* Line 678 of lalr1.cc  */
#line 7595 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 571:

/* Line 678 of lalr1.cc  */
#line 7621 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 572:

/* Line 678 of lalr1.cc  */
#line 7634 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 573:

/* Line 678 of lalr1.cc  */
#line 7712 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 574:

/* Line 678 of lalr1.cc  */
#line 7779 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im  = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res =Func_localmean( im, (int) (yysemantic_stack_[(6) - (5)].adouble));
      driver.im_stack.AddImage(res);
      delete im;
    }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 7787 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im  = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res =Func_localmean2( im, (int) (yysemantic_stack_[(6) - (5)].adouble));
      driver.im_stack.AddImage(res);
      delete im;
      }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 7795 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage* mean    = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* im      = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* res     = Func_localSD( im, mean, (int) (yysemantic_stack_[(8) - (7)].adouble));
    driver.im_stack.AddImage(res);
    delete im;
    delete mean;
      }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 7805 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage* mean    = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* im      = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* res     = Func_localSD2( im, mean, (int) (yysemantic_stack_[(8) - (7)].adouble));
    driver.im_stack.AddImage(res);
    delete im;
    delete mean;
      }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 7815 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 579:

/* Line 678 of lalr1.cc  */
#line 7845 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 580:

/* Line 678 of lalr1.cc  */
#line 7863 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 581:

/* Line 678 of lalr1.cc  */
#line 7883 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 582:

/* Line 678 of lalr1.cc  */
#line 7901 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 583:

/* Line 678 of lalr1.cc  */
#line 7921 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 584:

/* Line 678 of lalr1.cc  */
#line 7940 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 585:

/* Line 678 of lalr1.cc  */
#line 7961 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 586:

/* Line 678 of lalr1.cc  */
#line 7998 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 587:

/* Line 678 of lalr1.cc  */
#line 8013 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 588:

/* Line 678 of lalr1.cc  */
#line 8027 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 589:

/* Line 678 of lalr1.cc  */
#line 8043 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 590:

/* Line 678 of lalr1.cc  */
#line 8066 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 591:

/* Line 678 of lalr1.cc  */
#line 8080 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 592:

/* Line 678 of lalr1.cc  */
#line 8094 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 593:

/* Line 678 of lalr1.cc  */
#line 8108 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 594:

/* Line 678 of lalr1.cc  */
#line 8122 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 595:

/* Line 678 of lalr1.cc  */
#line 8157 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 596:

/* Line 678 of lalr1.cc  */
#line 8172 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 597:

/* Line 678 of lalr1.cc  */
#line 8193 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 598:

/* Line 678 of lalr1.cc  */
#line 8214 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 599:

/* Line 678 of lalr1.cc  */
#line 8255 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 600:

/* Line 678 of lalr1.cc  */
#line 8300 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 601:

/* Line 678 of lalr1.cc  */
#line 8317 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 602:

/* Line 678 of lalr1.cc  */
#line 8336 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 603:

/* Line 678 of lalr1.cc  */
#line 8350 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 604:

/* Line 678 of lalr1.cc  */
#line 8364 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 605:

/* Line 678 of lalr1.cc  */
#line 8380 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 606:

/* Line 678 of lalr1.cc  */
#line 8398 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 607:

/* Line 678 of lalr1.cc  */
#line 8413 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 608:

/* Line 678 of lalr1.cc  */
#line 8429 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 609:

/* Line 678 of lalr1.cc  */
#line 8444 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 610:

/* Line 678 of lalr1.cc  */
#line 8467 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 611:

/* Line 678 of lalr1.cc  */
#line 8484 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 612:

/* Line 678 of lalr1.cc  */
#line 8498 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

          InrImage* res;
          InrImage* im = (InrImage*) driver.im_stack.GetLastImage();

        res = Func_AutoCrop(im,(int)(yysemantic_stack_[(6) - (5)].adouble));

        driver.im_stack.AddImage(res);
        delete im;
    }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 8510 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 614:

/* Line 678 of lalr1.cc  */
#line 8542 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 615:

/* Line 678 of lalr1.cc  */
#line 8562 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 616:

/* Line 678 of lalr1.cc  */
#line 8604 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 617:

/* Line 678 of lalr1.cc  */
#line 8616 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 618:

/* Line 678 of lalr1.cc  */
#line 8627 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 619:

/* Line 678 of lalr1.cc  */
#line 8640 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 620:

/* Line 678 of lalr1.cc  */
#line 8652 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 621:

/* Line 678 of lalr1.cc  */
#line 8663 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 622:

/* Line 678 of lalr1.cc  */
#line 8691 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 623:

/* Line 678 of lalr1.cc  */
#line 8718 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 624:

/* Line 678 of lalr1.cc  */
#line 8750 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 625:

/* Line 678 of lalr1.cc  */
#line 8766 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 626:

/* Line 678 of lalr1.cc  */
#line 8783 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_AnisoGS_GetOutput();

    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 8796 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_AnisoGS_GetDiffusionCoeff();

    Si res==NULL Alors
      fprintf(stderr,"GetDiffCoeff() erreur ... \n");
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

  case 629:

/* Line 678 of lalr1.cc  */
#line 8829 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 630:

/* Line 678 of lalr1.cc  */
#line 8852 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

    InrImage*  res;

    res = Func_LevelSets_GetCurrentOutput();

    Si res==NULL Alors
      fprintf(stderr,"Func_LevelSets_GetOutput() error ... \n");
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 8866 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 632:

/* Line 678 of lalr1.cc  */
#line 8883 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 633:

/* Line 678 of lalr1.cc  */
#line 8916 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 634:

/* Line 678 of lalr1.cc  */
#line 8954 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 635:

/* Line 678 of lalr1.cc  */
#line 8989 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 636:

/* Line 678 of lalr1.cc  */
#line 9022 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 637:

/* Line 678 of lalr1.cc  */
#line 9039 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 638:

/* Line 678 of lalr1.cc  */
#line 9054 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 639:

/* Line 678 of lalr1.cc  */
#line 9070 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 640:

/* Line 678 of lalr1.cc  */
#line 9090 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 641:

/* Line 678 of lalr1.cc  */
#line 9113 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 642:

/* Line 678 of lalr1.cc  */
#line 9137 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 643:

/* Line 678 of lalr1.cc  */
#line 9163 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 644:

/* Line 678 of lalr1.cc  */
#line 9186 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 645:

/* Line 678 of lalr1.cc  */
#line 9208 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 646:

/* Line 678 of lalr1.cc  */
#line 9231 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 647:

/* Line 678 of lalr1.cc  */
#line 9255 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 648:

/* Line 678 of lalr1.cc  */
#line 9299 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 649:

/* Line 678 of lalr1.cc  */
#line 9323 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 650:

/* Line 678 of lalr1.cc  */
#line 9354 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 651:

/* Line 678 of lalr1.cc  */
#line 9376 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 652:

/* Line 678 of lalr1.cc  */
#line 9413 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 653:

/* Line 678 of lalr1.cc  */
#line 9450 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 654:

/* Line 678 of lalr1.cc  */
#line 9487 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 655:

/* Line 678 of lalr1.cc  */
#line 9522 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          driver.im_stack.AddImage((*(Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetCanvas()->GetGLImage());
        }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 9527 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          fprintf(stderr,"not available in new wxwidgets version of the 3D viewer ! \n");
          driver.im_stack.AddImage((InrImage*)NULL);
/*
          driver.im_stack.AddImage((*(Viewer3D_ptr*) $1->Pointer())->GetInrImage());
*/
    }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 9536 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.im_stack.AddImage((*(DessinImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetInrImage());
    }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 9541 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

    InrImage*    res;

      res = Func_ThresholdCrossing( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

          driver.im_stack.AddImage(res);

    }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 9552 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*    res;

      res = Func_IsocontourPoints( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

      driver.im_stack.AddImage(res);

    }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 9562 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*    res;

      res = Func_IsosurfDist( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

          driver.im_stack.AddImage(res);

    }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 9572 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*    res;

      res = Func_vtkIsoContourDist( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

          driver.im_stack.AddImage(res);
    }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 9581 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 663:

/* Line 678 of lalr1.cc  */
#line 9604 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 664:

/* Line 678 of lalr1.cc  */
#line 9633 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 665:

/* Line 678 of lalr1.cc  */
#line 9659 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 666:

/* Line 678 of lalr1.cc  */
#line 9690 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 667:

/* Line 678 of lalr1.cc  */
#line 9720 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      InrImage* res;
      res = Func_Convolve(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                  ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());

          driver.im_stack.AddImage(res);

        }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 9731 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 669:

/* Line 678 of lalr1.cc  */
#line 9747 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
      res = Func_Chamfer(((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));

          driver.im_stack.AddImage(res);

        }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 9757 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
      res = Func_Chamfer2(((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));

          driver.im_stack.AddImage(res);

        }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 9767 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 672:

/* Line 678 of lalr1.cc  */
#line 9782 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_Chamfer2(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                  0.92644, 1.34065, 1.65849,
                  dmax);

          driver.im_stack.AddImage(res);

        }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 9796 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_Chamfer2Signed(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                    0.92644, 1.34065, 1.65849,
                    dmax);

          driver.im_stack.AddImage(res);

        }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 9810 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_vtkSignedBorgefors(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                    dmax);

          driver.im_stack.AddImage(res);

        }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 9823 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_vtkSignedFMDist(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                     dmax);

          driver.im_stack.AddImage(res);

        }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 9836 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_PropagationDistance(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                      dmax);

          driver.im_stack.AddImage(res);
        }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 9848 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_PropagationDistance2(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                      dmax);

          driver.im_stack.AddImage(res);
        }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 9860 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_PropagationDanielsson(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                       dmax);

          driver.im_stack.AddImage(res);
        }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 9872 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_vtkPropDanielsson(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                       -dmax,dmax);
          driver.im_stack.AddImage(res);
        }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 9883 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmin = (yysemantic_stack_[(8) - (5)].adouble);
        float dmax = (yysemantic_stack_[(8) - (7)].adouble);

      res = Func_vtkPropDanielsson(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                       dmin,dmax);

          driver.im_stack.AddImage(res);
        }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 9896 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 682:

/* Line 678 of lalr1.cc  */
#line 9923 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 683:

/* Line 678 of lalr1.cc  */
#line 9956 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 684:

/* Line 678 of lalr1.cc  */
#line 10072 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 685:

/* Line 678 of lalr1.cc  */
#line 10096 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 686:

/* Line 678 of lalr1.cc  */
#line 10138 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 687:

/* Line 678 of lalr1.cc  */
#line 10150 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* res;
      int dim = (int) (yysemantic_stack_[(6) - (5)].adouble);

      InrImage::ptr im = InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
      res = Func_MeanHalfSize(im.get(),dim);
      if (res!=NULL) driver.im_stack.AddImage(res);
    }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 10159 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage* res;
        int axis=(int) (yysemantic_stack_[(6) - (5)].adouble);

        InrImage::ptr im = InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
        res=Func_Flip(im,axis);
        driver.im_stack.AddImage(res);
    }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 10168 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 690:

/* Line 678 of lalr1.cc  */
#line 10191 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 691:

/* Line 678 of lalr1.cc  */
#line 10216 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 692:

/* Line 678 of lalr1.cc  */
#line 10229 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(5) - (1)].variable)->Pointer());


      res = s->GetImageLinesLength(  );

      if (res!=NULL) driver.im_stack.AddImage(res);
    }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 10239 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 694:

/* Line 678 of lalr1.cc  */
#line 10276 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 695:

/* Line 678 of lalr1.cc  */
#line 10294 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 696:

/* Line 678 of lalr1.cc  */
#line 10312 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());


      res = s->GetIntensities( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

      if (res!=NULL) driver.im_stack.AddImage(res);
        }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 10322 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;

      res = AMIFluid::Func_Altitude2Position(im,(int)(yysemantic_stack_[(6) - (5)].adouble));
      if (res!=NULL) driver.im_stack.AddImage(res);

      delete im;
    }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 10332 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_Altitude2Position(im);
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
    }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 10340 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im,(int)(yysemantic_stack_[(6) - (5)].adouble));
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
    }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 10348 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im);
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
    }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 10356 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 702:

/* Line 678 of lalr1.cc  */
#line 10381 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 703:

/* Line 678 of lalr1.cc  */
#line 10401 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* res;
      res= AMIFluid::Func_ReadFlow((char*)(yysemantic_stack_[(4) - (3)].astring));
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 10409 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 705:

/* Line 678 of lalr1.cc  */
#line 10443 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 706:

/* Line 678 of lalr1.cc  */
#line 10466 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 712:

/* Line 678 of lalr1.cc  */
#line 10491 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(-)               }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 10493 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sin)             }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 10494 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(cos)             }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 10495 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sqrt)            }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 10496 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(fabs)            }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 10497 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(round)           }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 10498 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(floor)           }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 10499 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(tan)             }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 10500 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(asin)            }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 10501 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(acos)            }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 10502 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(atan)            }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 10503 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(exp)             }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 10504 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(1.0/log(10.0)*log) }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 10505 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(log)             }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 10507 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 729:

/* Line 678 of lalr1.cc  */
#line 10522 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 731:

/* Line 678 of lalr1.cc  */
#line 10544 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(*,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 10550 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(/,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 10552 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  IMAGE_OP_IMAGE_2(*)   }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 10553 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(/)   }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 10554 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(^)   }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 10563 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(+,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 10564 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(-,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 10565 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(+)   }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 10566 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(-)   }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 10574 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<)    }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 10575 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>)    }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 10576 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<=)   }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 10577 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>=)   }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 10578 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<, (yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 10579 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>, (yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 10580 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<=,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 10581 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>=,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 10586 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(==)   }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 10587 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(!=)   }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 10588 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(==,(yysemantic_stack_[(3) - (3)].adouble))   }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 10589 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(!=,(yysemantic_stack_[(3) - (3)].adouble))   }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 10631 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         GLTransfMatrix* newglt;
         GLTransfMatrix_ptr glt = *(GLTransfMatrix_ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

         newglt = new GLTransfMatrix();
         (*newglt) = (*glt);
         driver.gltransf_stack.AddMatrix(newglt);

           }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 10642 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 773:

/* Line 678 of lalr1.cc  */
#line 10655 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         GLTransfMatrix* newglt = NULL;
         GLTransfMatrix_ptr glt1 = *(GLTransfMatrix_ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer();
         GLTransfMatrix_ptr glt2 = *(GLTransfMatrix_ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer();
         float coeff = (yysemantic_stack_[(8) - (7)].adouble);

         newglt = Func_InterpolateTransform(glt1.get(),glt2.get(),coeff);
         driver.gltransf_stack.AddMatrix(newglt);
       }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 10666 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 775:

/* Line 678 of lalr1.cc  */
#line 10683 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         FloatMatrix* m;
         m = new FloatMatrix((int)(yysemantic_stack_[(6) - (3)].adouble),(int)(yysemantic_stack_[(6) - (5)].adouble));
         driver.matrix_stack.AddMatrix(m);
       }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 10690 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      FloatMatrix* newmat;
      FloatMatrix::ptr mat = *(FloatMatrix::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

      newmat = new FloatMatrix( (*mat));

          driver.matrix_stack.AddMatrix(newmat);
       }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 10700 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 783:

/* Line 678 of lalr1.cc  */
#line 10720 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(-)               }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 10723 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix* mat;
          FloatMatrix* res;
          mat=driver.matrix_stack.GetLastMatrix();
          res = mat->Transpose();
          delete mat;
          driver.matrix_stack.AddMatrix(res);
        }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 10731 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sin)             }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 10732 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(cos)             }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 10733 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sqrt)            }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 10734 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(fabs)            }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 10735 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(round)           }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 10736 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(floor)           }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 10737 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(tan)             }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 10738 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(asin)            }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 10739 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(acos)            }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 10740 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(atan)            }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 10741 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(exp)             }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 10742 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(1.0/log(10.0)*log) }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 10743 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(log)             }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 10750 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(*,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 10751 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(*)   }
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 10753 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         FloatMatrix* m2 = driver.matrix_stack.GetLastMatrix();
         FloatMatrix* m1 = driver.matrix_stack.GetLastMatrix();
             FloatMatrix* res = Multiply(m1, m2) ;
         driver.matrix_stack.AddMatrix(res);
         delete m1;
         delete m2;
           }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 10763 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(+,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 10764 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(-,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 10765 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(+)   }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 10766 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(-)   }
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 10815 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yysemantic_stack_[(1) - (1)].variable);
        }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 10820 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 822:

/* Line 678 of lalr1.cc  */
#line 10836 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 823:

/* Line 678 of lalr1.cc  */
#line 10847 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        SurfacePoly* surf;
        surf = Func_isosurf((*(InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer()),
                (yysemantic_stack_[(6) - (5)].adouble),
                NULL,
                2);
        driver.surf_stack.AddSurf(surf);
    }
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 10857 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 825:

/* Line 678 of lalr1.cc  */
#line 10877 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 826:

/* Line 678 of lalr1.cc  */
#line 10911 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_decimate(((SurfacePoly::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 10920 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_decimate(((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble) );
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 10929 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_vtkMarchingCubes(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),(yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 10938 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_vtkSmooth(((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 10947 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        SurfacePoly* surf;
        surf = Func_vtkWindowedSinc(((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
        if (surf==NULL) driver.err_print("vtkWindowedSinc failed!");
        driver.surf_stack.AddSurf(surf);
    }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 10955 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf = new SurfacePoly();
      driver.surf_stack.AddSurf(surf);
    }
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 10961 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.surf_stack.AddSurf((yysemantic_stack_[(2) - (2)].astring));
      delete [] (yysemantic_stack_[(2) - (2)].astring);
    }
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 10967 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.surf_stack.AddSurf((yysemantic_stack_[(4) - (3)].astring));
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 10973 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 835:

/* Line 678 of lalr1.cc  */
#line 10999 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 836:

/* Line 678 of lalr1.cc  */
#line 11013 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 837:

/* Line 678 of lalr1.cc  */
#line 11029 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* newsurf;
      SurfacePoly::ptr surf = *(SurfacePoly::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

      newsurf = new SurfacePoly( (*surf) );

          driver.surf_stack.AddSurf(newsurf);
      }
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 11039 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 839:

/* Line 678 of lalr1.cc  */
#line 11057 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 840:

/* Line 678 of lalr1.cc  */
#line 11085 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 841:

/* Line 678 of lalr1.cc  */
#line 11112 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 842:

/* Line 678 of lalr1.cc  */
#line 11128 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 843:

/* Line 678 of lalr1.cc  */
#line 11151 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 844:

/* Line 678 of lalr1.cc  */
#line 11184 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 845:

/* Line 678 of lalr1.cc  */
#line 11220 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 846:

/* Line 678 of lalr1.cc  */
#line 11266 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 847:

/* Line 678 of lalr1.cc  */
#line 11304 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 848:

/* Line 678 of lalr1.cc  */
#line 11328 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr im = InrImage::ptr(driver.im_stack.GetLastImage());
      SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 11338 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 850:

/* Line 678 of lalr1.cc  */
#line 11361 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 851:

/* Line 678 of lalr1.cc  */
#line 11373 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 852:

/* Line 678 of lalr1.cc  */
#line 11386 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 853:

/* Line 678 of lalr1.cc  */
#line 11423 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 854:

/* Line 678 of lalr1.cc  */
#line 11466 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 855:

/* Line 678 of lalr1.cc  */
#line 11514 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 856:

/* Line 678 of lalr1.cc  */
#line 11566 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 857:

/* Line 678 of lalr1.cc  */
#line 11609 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 858:

/* Line 678 of lalr1.cc  */
#line 11637 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 859:

/* Line 678 of lalr1.cc  */
#line 11670 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 864:

/* Line 678 of lalr1.cc  */
#line 11720 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yysemantic_stack_[(1) - (1)].variable);
        }
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 11744 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent<float>* extent=new ImageExtent<float>( (float)(yysemantic_stack_[(11) - (1)].adouble),(float)(yysemantic_stack_[(11) - (3)].adouble),(float)(yysemantic_stack_[(11) - (5)].adouble),
                              (float)(yysemantic_stack_[(11) - (7)].adouble),(float)(yysemantic_stack_[(11) - (9)].adouble),(float)(yysemantic_stack_[(11) - (11)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        }
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 11752 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent<float>* extent=new ImageExtent<float>((float)(yysemantic_stack_[(7) - (1)].adouble),(float)(yysemantic_stack_[(7) - (3)].adouble),(float)(yysemantic_stack_[(7) - (5)].adouble),(float)(yysemantic_stack_[(7) - (7)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        }
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 11759 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 884:

/* Line 678 of lalr1.cc  */
#line 11775 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 14816 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
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
  const short int Parser::yypact_ninf_ = -2697;
  const short int
  Parser::yypact_[] =
  {
     13268, -2697,  6009, 15279, 15279,  1636, -2697, -2697, -2697, -2697,
   -2697,    52,    75,    83, -2697, -2697, -2697, -2697,   -30,   307,
   -2697,    20,  1636,  8043,   897,    90,   121,   897, -2697,   130,
     135, -2697, -2697, -2697, -2697,    31,   109,   113,    62,    56,
   -2697,   120,    61,    88, -2697,   147, -2697,   268,   111,   -56,
     222,   233,    48,   260,  1755,   897, -2697, -2697, -2697, -2697,
     255,   282,   292,   279,   304,   580,   623,   345,   317, -2697,
   -2697, -2697, -2697,   347,   362,   381,   365,   396,   652,   405,
     422,   425,   453,   472,   475,   489,   520,   555,   563,   567,
     579,   587,   620, -2697,   632,   641, -2697, -2697, -2697, -2697,
   -2697, -2697, -2697, -2697, -2697, -2697,   656,   659,   687, -2697,
   -2697, 15279, 15279, 15279, 15279, 15279, 15279, 15279, 15279, 15279,
   15279, 15279, 15279, 15279,   111, -2697, -2697,  8043,  1474,   897,
     710,   768,   797,    16,   111,   800,   832,   851,   863, -2697,
   -2697, -2697, -2697, -2697, -2697, -2697,   880,   919, -2697,   821,
    3864, -2697, -2697, -2697, -2697, -2697, -2697, -2697,   110, -2697,
   -2697,   420,   482, -2697, -2697, -2697, 15279, -2697,   296,   766,
   -2697,    49,   700,   526,   568,   831,   804,    45, -2697, -2697,
   -2697, -2697,    87, -2697, -2697, -2697, -2697,   792,    46,   928,
   -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697,
   -2697,    73,   -55,   927,  6009,  6009,  8043, -2697, -2697, -2697,
     935, -2697,   945,   947,   -56,   968,   969,   973,   972,   974,
    6009,  6009,  6009,  6009,  6009,  6009,  6009,  6009,  6009,  6009,
    6009,  6009,  6009,  6009, -2697,   139,   975,   945, -2697,   792,
   -2697,   792, -2697,   981,   982,   355,   983,   897,  8043,   897,
   -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697,   482,
   -2697, -2697,   482, -2697, -2697,   979,   897,   897, -2697,  1775,
    1775, -2697, -2697,  8043, -2697, -2697,  8043, -2697, -2697,  8043,
     897,   711,  1203,     8,     8,  8043,  1636,    68,   550, 10202,
   10202, -2697, -2697, -2697,   805,    -2,  8043,   654,  8043, -2697,
   -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697,
   -2697, -2697, -2697, -2697,   986,   973, -2697, -2697, -2697,  8043,
    8043, 14536, 11224, 14536, 14536, 14536, 14536, 14536, 14536,    20,
     503,  1550,   726,   729,    20,    20, 14536, 14536,    20,    20,
      20,    20,    20,    20,    20,    20,   948,   949,  8043,  8043,
      20,  8043,  8043,     3,   897, 14536,    20, -2697,   792, -2697,
     792, -2697,   792, -2697,   792, -2697,   792, -2697,   792, -2697,
     792, -2697,   792, -2697,   792, -2697,   792, -2697,   792, -2697,
     792, -2697,   792,  -109, -2697,   950, -2697, -2697,   110, -2697,
     965,   897,   989, -2697, -2697, -2697,  8043,   897,   943,    20,
      20,    20, -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697,
   -2697,   110, -2697,   897,   897,   897,   897, -2697,   792,  6009,
    6009,  6009,  6009,  6009,  6009,  6009,  6009,  6009,  6009,  6009,
    8043,  8043,  8043,  8043,  8043,  8043,  8043,  8043,   141, 14536,
   11224, -2697, 15279,     3, 15279, 15279,  1911,   -28, 14122,  9167,
     964,    85,   505,   554,  8043,  8043,   731,   869,  8043,   -42,
      30, -2697, 15426,    33, -2697,  1027,  1040,  1043,  1008,  1045,
    1049, -2697,  1060,  1069, -2697, -2697, -2697, -2697,  1076,  1077,
    1078,  1079,  1083,  1084, -2697, -2697, -2697, -2697, -2697, -2697,
   -2697, -2697, -2697,  1085,  1086,  1087, -2697,  1088,  1089,  1090,
    1091, -2697,  1092,  1098,  1099,  1100,  1101,  1102,  1103,  1104,
    1105,  1124,  1125,  1126,  1127,  1128,  1130, -2697,  1131,  1132,
    1133,  1134, -2697, -2697,  1135, -2697,  1136, -2697,  1137,  1138,
    1139,  1140,  1141, -2697, -2697,  1143, -2697, -2697,  8043,   897,
   -2697,  1142,  1145, -2697,  1146, 12246, 12246, 11224,   224,   793,
    1147,  1149,  1151,  1153,   686,  1158,  1159,  1162,  1163,  1164,
    1165,  1166,  1167,  1168,  1169,  1170,  1171,  1173,   429,  1174,
    1176,  1177,  1178,  1175,  1179,  1180,  1182,  1195,  1197,  1183,
    1184,  1186,  1204,  1205,  1206,  1207,  1208,  1210,  1213,  1214,
    1216,  1217,  1219,  1220,  1221,  1222,  1223,  1224,  1225,  1226,
    1227,  1228,  1229,  1230,  1231,  1232,  1233,  1234,  1237,  1238,
    1239,  1240,  1242,  1243,  1244,  1245,  1247,  1250,  1255,  1256,
    1258,  1259,  1260,  1261,  1262,  1263,  1264,  1265,  1266,  1267,
    1268,  1269,  1270,  1273,  1274,  1275,  1276,  1277, 12246, 12246,
   12246, 12246, 12246, 12246, 12246, 12246, 12246, 12246, 12246, 12246,
   12246, 14536,  1278,  1279,  1281,  1285,  1286,  1287,  1282,  1296,
    1298,  1299,  1300,  1301,   463,   482, 12246, -2697,    86, -2697,
   -2697, -2697,  1020, -2697,   937, -2697,   952, -2697,    65,   824,
    1302, -2697,  1297,  1181,    55, -2697, -2697, -2697,  1316,   521,
   -2697,  1303, -2697,  1305, -2697, -2697, -2697,  1323,  1324,  1325,
    1326, -2697, -2697,  1334,  1335,  1336,  1337,  1338,  1341,  1343,
    1344,  1345,  1346,  1347,  1348,  1349, -2697, -2697, -2697, -2697,
    1350,  1351,  1352,  1353, -2697,   897,  1354,  1356,  1358,  8043,
    1355,  1357, 14536, 14536, 13708,  1359,  1363,   523,  1360, 14536,
   14536, 14536, 14536, 14536, 14536, 14536, 14536, 14536, 14536, 14536,
   14536, 14536, 14536,   796,  1366,  1365,  1149,  1367,  1371,  1370,
    1374,  1375,  1381,  1393,  1400,  1399,  1409,  1413,  1414, -2697,
   -2697,  1415,  1416, -2697, -2697,  1417,  1420,  1421,  1422,  1425,
    1426,  1428,  1429, -2697,  1430,  1432,  1433,  1434,  1436,  1439,
    1440,  1442,  1444,  1447,  1448,  1449,  1451,  1452,  1453,  1454,
    1456,  1457,  1458,  1459,  1460,  1461,  1462,  1463,  1464,  1467,
    1468,  1483,  1485, -2697, -2697, -2697, -2697, -2697, -2697,  1479,
    1486,   419,  1487,  1488,  1482,  1489,  1490,  1491,  1492,  1494,
    1495,  1496,  1497,  1498,  1493,  1507,  1502,  1503,   340,  1506,
       3,     3,     3, -2697,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,  1513,  1515,
    1510,  1517,  8043,   897, -2697,   -17, -2697,  1519,  1520,  1521,
    1523,  1525,  1526,   110,  1522,  1527,  1524,  1528,  1529,  1530,
   -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697,   296,   296,
   -2697, -2697, -2697, -2697,    49,    49,   700,   526,   568,   831,
      37,   804,   323,  1531,  1532, -2697,  1533, -2697, -2697,   897,
   -2697,  1540,  1542,  1545,  1546,  1552,  1553,  1562,  1576,  1578,
   -2697, -2697, -2697, -2697, -2697, -2697,   792,   792,   296,    46,
     296,    46, -2697, -2697, -2697,   897,  1579,  1580, -2697,   897,
   -2697,  1581, -2697,  1582,  1583,  1584,  1585,  1586,  1587,  1588,
    1589,  1590,  1591,  1593,  1594,  1595,  1597,  1598,  1599, -2697,
    1600, -2697,  1603, -2697, -2697,  1604,  1605,  1606,  1607,  1608,
   -2697, -2697,  1609,  1610,  1611,  1613,  1614,  1615,  1616,  1619,
    1620,  1621,  1622,  1623,  1626,  1627,  1628,  1629,  1631,  1111,
    1637,  1638,  1652,  1656,  1657,  1484, -2697,  1548, -2697, 11735,
   11735,  9683,   524,  1658,  1653,  1660, -2697, -2697,  1661,   589,
    1662,  1663,  1664,  1665, 11735, 11735, 11735, 11735, 11735, 11735,
   11735, 11735, 11735, 11735, 11735, 11735, 11735,    22, 11735,  1659,
   -2697, -2697, -2697,  1666, -2697,  1667,  1668,  1672,   293,  8043,
   -2697,   897, -2697, -2697,  1671,  8043, -2697, -2697,  8043,  8043,
    8043,  8043,  8043,  8043,    20,  8043,  8043,    72,  1311,  1309,
    8043,  8043,  8043,  8043,  8043,  8043,  8043, 14536,  8043,  1441,
    8043,  1469,  8043,  8043,   -28,  8043,  8043,  8043,  8043,  8043,
       8,     2,  1478,  1312,  8043,  8043,  8043,  8043,   482, -2697,
   -2697,   897,   218,   897,   391, -2697, -2697, -2697,  1675,  1677,
   -2697, -2697, -2697, -2697,   -13, -2697,  8043,    25,   621, 10202,
   11224,    20, 14536, 14536,    20,    20,    20,    20,    20, 14536,
      20,    20,    20,    20,    20,    -1,    20,    20,    20,    20,
      -8, 14536, 14536,    20,  1472,  1480,    20,    20,    20,    20,
      20,    20,    20,    20,    20, 14536,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20, 14536,
   14536, 14536, 14536, 14536,    20,    20,    20,    20,    20,     8,
       8,   897,   897,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20, 14536,    20,    20,    20,
      20,    20,    20, 14536, 14536, -2697, -2697, -2697, -2697, -2697,
   -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697, 14536,
   14536, 14536,    20, 14536, 14536,  1199, 14536, 14536, 14536, 14536,
     897, -2697, 10713, -2697, 11224,  7261, 14536, 14536, 12246, 12246,
   12246, 12246, 12246, 12246, 12246, 12246, 12246, 12246, 14536, 14536,
   14536, 14536, 14536,  -146,   110,   897,   897,   897,  8043,  1646,
    1647,   897,  1645,  1648,  8043,  1649,  1654,  1655,   897,  8043,
    1643,  8043,  8043,   897,  8043,  8043,  8043,  8043, -2697,  1571,
    8043,  1574,  1703, -2697,  1650,  1706,   428,  1376, 14536,   918,
       9, 14536, -2697,   -59,  8043, -2697,  1709, -2697, -2697,  1711,
   -2697,  1723,    20,  8043,    20,  8043,  8043,  8043,    20,    20,
      20,    20,  8043,  8043,  8043,  8043,  8043,  8043,  8043,    20,
    8043,    20,    20,    20,    93,    20,    95,    96,    20,    20,
    8043,  8043,  8043,  8043,  8043,  8043,  8043,  8043,  8043,  8043,
    8043,  8043,  8043,  8043,  8043,    20, -2697, 14536, -2697,  1745,
    8043,  8043,  8043,  8043,  8043,  8043,  8043,    20,    20,    20,
   -2697, -2697,  8043,  8043, -2697,  8043, -2697, -2697,   897, -2697,
    1289,  1739, -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697,
     228,   228, -2697,  8043, -2697,  8043,   897,    20,    20,  8043,
   -2697,  8043,  8043,  8043,  1624,   897,    20, -2697,    20,    20,
    8043,  8043,  8043,  8043,  8043,  8043,  8043, -2697,  8043,  8043,
   -2697,  8043,  8043,  8043,  8043,  8043,  8043, 14536,  8043,  8043,
    8043,  8043,  8043,  8043,  8043,  8043,    20, 14536,  8043, 14536,
    8043,  8043,    20,  8043,  8043,  8043, 14536,    20,     8,     8,
       8, 14536, 14536, 14536,   897, 14536,    20,     8,    20,     8,
       8, 14536,  1386, -2697, 14536, 14536, 14536, 14536, 14536,  1499,
    8043,  8043,   897,  -192, 10202,   897,  8043,  1685,  8043,  8043,
     897,   897,   897,  -183,   897, -2697, -2697,  1743,  8043,  1750,
    1746,   118,  1747,  1751,  1756,  1761,  1757,  1764,  1759,  1772,
    1773,  1774,  1776,  1777,  1778,  1779,  1780,  1781,  1788,  1783,
    1784,  1785,  1786,  1793,  1789,  1794,  1791,   530,  1839,  1840,
    1835,  1836,  1837,  1838,  1845,  1841,   531,  1847,  1843,  1844,
    1846,  1851,  1853,  1854,  1855,  1856,  1852, 12757, -2697,  1857,
    1859,  1858,  1861, -2697, -2697, -2697,   532,   533,  1862,  1863,
    1864,  1871,  1869,  1870,  1879,  1881,  1882,  1887,  1888,  1889,
    1891,  1892, -2697, -2697,  1894,  1895,  1902,  1897, -2697,  1752,
    1905,  1899,  1900,  1901,  1909,  1910,  1913,  1908,  1912,  1925,
    1927,  1928,  1929,  1930,  1931,  1932,  1915,  1939,  1940,  1944,
    1951,  1946,  1947,  1950,  1952,  1953,   542,  1954,  1955,  1956,
    1961,  1962,  1963,  1968,  1957,  1969,  1970,  1971,  1972,  1973,
    1985,  1992,  1993,  1988,  1989,  1990,  1991,  1995,  1998,  2001,
    2002,  2004,  2006,  2007,  2008,  2009,  2016,  2017,  2018,  2019,
    2020,  2021,  2023,  2022,  2024,  2025,   543,  2026,  2030,  2031,
    2032,  2040,   557,   559,  2035,  2029,  2042,   280,  1149,   482,
   -2697, -2697,  2043,  2038,   935,   565,   355,  2045, -2697, -2697,
   -2697, -2697, -2697, -2697,   296,   937,   296,   937, -2697, -2697,
   -2697, -2697, -2697, -2697, -2697, -2697, -2697,    65, -2697,    65,
     824, -2697,  1297,    57,  1181,  2046,  2049,  2052,  2066,  2068,
   -2697,  2069,  2071,  2072,  2067,  2079,  2087,  2088,   569,   571,
    2089,  2090,  2091,  2092,  2094,  2096,  2074,   574,  2097,  2075,
    2098,  2099,  2101,  2110,   -28,  2109, 14536, -2697,  2113, 14950,
    1686,  2108,  2118, 14536,    20,    20,   576,  2122,  2119,   583,
    2126,  2129,  2131,  2132,  2133,  2134,  2135,  2140,  2141,  2142,
    2145,  2146,  2148,  2149,  2152,  2154,  2150,  2158,  2159,  2161,
    2163,  2164,  2165,  2171,  2172,  2173,  2174,  2175,  2176,  2178,
    2180,  2187,  2189,  2190,  2191,  2193,  2196,  2197,  2200,  2201,
    2202,  2203,  2213,  2219, 14536,  2214,  2221,   605,  2222,  2223,
    2225,  2224,  2226,  2227,  2228,  2230,  2235,  2231,  2236,  8043,
     897,   110,   110,  1735,  1736,  1737,  1868,  1981,   607,   610,
    2237,  2238,  2245,  2240,  2241, -2697,   327,  2244,  2251, 11224,
    2252,   612,  2253,  2258,  2254,   400,  2255,   431,  2259,   617,
    2256,  2257,   635,  2264,  2265,  2267,  2268,   650,  2274,  2277,
    2273,   672,  2280,  2275,  2276,  2292,  2299,  2300,  2301,  2302,
    2303,  2304,  2305,  2306,  2307,  2308,  2309,  2310,  2311,  2312,
    2315,  2316,   673,  2313,  2314,  2317,  2318,  2319,   674,  2320,
    2321,   675,  2322,  2323,  2324,  2325, -2697,  2332,   676,  2327,
    2328,  2329,  2330,  2181,  2335,  2336,  2339, -2697,   677,  2340,
    2341,  2338,  2342,  2345,  2343, -2697, -2697,  2346,   897,   482,
   -2697, -2697,    20,  8043,  8043,  8043,  8043, -2697,  8043, -2697,
    8043, -2697, -2697, -2697,    20,    20,  8043,  8043,  8043, -2697,
   -2697,  8043,  8043,  8043,  8043, -2697,  8043, -2697,  8043, -2697,
    8043, -2697, -2697,  8043,  8043,  8043,  8043, -2697,  1806, -2697,
    8043, -2697,    20,  8043, 14536, -2697,  2177, -2697, -2697, -2697,
    2271, 11224, -2697, -2697,  8043,   -45,  8043, -2697, 14536,    82,
    8043,  8043, -2697,  8043,  8043,  8043,  8043,  8043,  8043,  8043,
    8043,  8043,  8043,  8043,  8043, -2697,  8043,    20,    20, 14536,
   14536,    20,    20,    20, -2697,  8043,  8043,  8043,  8043,  8043,
    8043,  8043,  8043,  8043, -2697, -2697, -2697,    20, -2697,    20,
      20,    20,    20,    20, -2697,    20,    20,  8043,  8043,  8043,
    8043, 14536, 14536, -2697,  8043,  8043,  8043,  8043,    20,   897,
   -2697, -2697,    20,    20,  8043,  8043,  8043,  8043,  8043,  8043,
    8043,  8043,  8043,  8043,  8043, -2697, -2697, -2697, -2697, -2697,
   -2697, -2697,  8043,  8043,  8043, -2697,  8043,  8043,    20,  8043,
    8043,    20, -2697,  8043, -2697,  8043, 14536, -2697, -2697, -2697,
   -2697, -2697, -2697, -2697,  2333, -2697,  8043, -2697, 14536,  8043,
      20,  2347,  2348,  2350, -2697, -2697, -2697,  8043,  8043,  8043,
    2261, -2697,   897, -2697,  8043,   897,   897,   897,   897,   897,
    8043, -2697, -2697,  8043,  8043, -2697,  8043,  8043,  8043, -2697,
   -2697, -2697, -2697, -2697, 14536, -2697,  2351,  2352,   728, -2697,
      20, -2697,  8043, -2697,  8043, -2697, -2697, -2697, -2697, -2697,
   -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697,  8043, -2697,
   -2697,    20, -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697,
   -2697, -2697, -2697,  8043, -2697,  8043, -2697, -2697, -2697, -2697,
    8043, -2697, -2697, -2697, -2697, -2697,  8043, -2697, -2697,  2353,
    8043,  8043, -2697, 11224,  8043,  8043, -2697,  8043,  8043,    20,
      20,  8043,  8043, -2697,  8043,  1848, -2697, -2697, -2697, -2697,
   -2697, -2697, -2697, -2697, -2697,   253, -2697,  8043,  8043, -2697,
      20,  8043, -2697,  8043,  8043,  8043, -2697, -2697, -2697, -2697,
   -2697,  8043, -2697, -2697,  8043, -2697,  8043, -2697, -2697, -2697,
    8043,  8043,  8043, -2697,  8043, -2697, -2697, -2697, -2697, -2697,
    8043, -2697, -2697,  8043, -2697,  8043, -2697,  8043,  8043,  8043,
   -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697,  8043,  8043,
   -2697, -2697,  8043, -2697, -2697, -2697, -2697,  8043,  8043,  8043,
    8043,  8043,  8043, -2697,  8043,  8043,  8043, -2697,  8043,  8043,
    8043,  8043,  8043, -2697, -2697,  8043,  8043,  8043, 11224, 14536,
    8043, -2697, -2697, -2697, -2697, -2697, -2697,  2260,  2349,  2355,
    2282, -2697,  2354,  2356,  2357,  2358,  2363,  2359,  2367,  2362,
    2369,  2370,  2371,  2372,  2368,  2373,  2375,  2376,  2377,  2378,
    2379,  2381,  2380,  2382,  2383,  2384,  2387,  2391,  2392,  2388,
    8043,  2393,  2389,  2390,  2397,   748,  2394,  2395,  2398,  2399,
    2402,  2403,  2400,  2405,  2401,  2404,  2406,  2407,  2408,  2409,
    2410,  2411,  2418,  2413,  2414,  2415,  2416,  2417,  2419,  2420,
    2421,  2422,  2423,  2424,  2425,  2426,  2427,  2434,  2429,  2430,
    2431,  2432,  2433,  2435,  2440,  2442,  2437,  2444,  2445,  2446,
    2441,  2443,  2448,  2450,  2451,  2452,  2447,  2454,  2455,  2453,
    2457,  2459,  2456,  2458,  2460,  2461,  2467,  2469,  2470,   750,
    2465,  2466,  2474,  2479,  2475,  2480,  2481,  2489,  2484,  2487,
    2494,  2495,  2496,  2492,  2493, -2697,  2500,  2501, -2697, -2697,
   -2697,  2503,    40,  2506,   122,  2521,  2529,  2530,    71,  2531,
    2532,  2533,  2534,  2536,  2535,  2537,  2538,  2539,  2543,  2544,
    2546, -2697, -2697, -2697,  8043,  2547,  2542,  2549,  2552,  2548,
    2550,  2553,  2551,  2559, -2697,   751,   755,   758,  2555,  2562,
    2565,  2566,  2571,  2572,  2577,  2578,  2579,  2558,  8043,   110,
     110,  2334,  2366,  2516,  2545,  2554,   110,  2586,  2581,  2583,
    2584,   359,  2591,  2365,  2587,  2589,  2590,  2592,  2593,  2595,
    2596,  2603,  2599,  2602,  2604,  2605,  2606,  2607,  2608,  2609,
    2613,  2620,  2617,  2618,  2619,  2621,  2626,   759,  2628,  2629,
    2630,  2631,  2632,  2627,   760,  2634,  2643,  2653,  2658,  2659,
    2660,  2661,   897,   897,  2635, -2697,  8043, -2697,  8043, -2697,
    8043, -2697,  8043, -2697, -2697, -2697, -2697,  8043,  8043, -2697,
    8043,  8043,  8043,  8043, -2697,  8043,  8043,  8043,  8043, -2697,
   -2697, -2697,  8043, -2697, -2697,  8043,  8043, -2697, -2697,    89,
     220,  8043, -2697, -2697, -2697, -2697,  8043, -2697,  8043,  8043,
    8043,  8043,  8043,  8043,  8043,  8043, -2697,  8043,  8043,  8043,
    8043,  8043,  8043,  8043,  8043,  8043,  8043,  8043,  8043,  8043,
    8043, -2697,  8043,    20,    20,    20,    20,    20, -2697, -2697,
    8043, -2697, -2697, -2697,  8043,  8043, -2697, -2697, -2697, -2697,
   14536, -2697, -2697, 14536,  8043,  8043, -2697, -2697, -2697, -2697,
   -2697, -2697, -2697, -2697,  8043,  8043,  8043,  8043,  8043, -2697,
    8043,  8043, -2697,  8043,  8043, -2697, -2697, -2697,  8043,  8043,
   -2697, -2697, -2697,  8043,  8043,  8043,  8043, -2697, -2697, -2697,
   -2697, -2697, -2697, -2697,   897, -2697, -2697, -2697,  8043, -2697,
   -2697, -2697,  2637, -2697,  8043, -2697, -2697,    20,  8043, -2697,
    8043,  8043, -2697, 14536, -2697, 14536, -2697, 14536, -2697, 14536,
    8043,  8043,  8043,    20,    20,  8043,  8043, -2697, -2697, -2697,
   -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697,  8043,    20,
    8043, -2697,  8043,  8043, -2697,  8043,  8043,  8043,  8043,  8043,
    8043,  8043,  8043, -2697,  8043,  8043,  8043,  8043,  8043,  8043,
    8043,  8043,  8043, -2697,  8043,  8043,  8043,  8043, -2697, -2697,
      20, -2697, -2697, -2697, -2697, -2697, 14536, -2697,  8043,  8043,
    8043,  8043, 14536, 14536,  8043,  8043, -2697, -2697, -2697,  2668,
     782,  2663,  2670,  2665,  2666,  2673,  2672,  2676,  2679,  2677,
    2678,  2680,  2685,  2681,  2682,   438,  2683,  2684,  2691,  2687,
     783,  2688,  2689,  2690,   785,   787,   794,   798,  2692,  2693,
    2694,  2695,  2697,   468,   806,   350,  2696,  2698,  2699,  2700,
     809,  2701,  2702,  2703,  2704,  2705,  2706,  2713,  2708,  2709,
    2710,  2711,  2712,  2714,  2715,  2719,  2722,  2723,  2724,  2720,
    2721,  2725,  2726,  2727,  2728,  2730,  2731,  2732,  2729,  2733,
    2449,  2601,  2734,  2741,  2736,  2743,  2738,  2745, -2697,  2740,
    2747,  2742,  2749,  2744,  2751,   811,  2752,  2748,  2750,  2753,
    2754,   828,  2755,  2757,  2758,   110,  2756,  2759,  2760,  2763,
    2764,  2761,  2762,  2769,  2770,  2771,  2772,  2773,  2774,  2775,
    2776,  2777,  2778,  2779,  2780,  2781,  2782,  2783,  2784,  2785,
    2786,  2787,  2788,  2794,  2795,  2790,  2797,  2792,  2793,  2796,
    2800,  2801, -2697, -2697,  8043,  8043, -2697,  8043,  8043, -2697,
    8043,  8043, -2697,  8043,  8043,  8043, -2697,  8043,  8043, -2697,
      89,  8043, -2697, -2697,    89,  2499,  8043,  8043, -2697,  8043,
   -2697,  8043, -2697,  8043, -2697,  8043,  8043,  8043,  8043,  8043,
   -2697, -2697, -2697,  8043,  8043,  8043,  8043,  8043,  8043, -2697,
    8614,  8614,  8614,  8043,  8043,  8043,  8043, -2697,  8043,  8043,
    8043,  8043,  8043,    20,  8043, -2697, -2697, -2697, -2697,  8043,
    8043, -2697,  8043,  8043,  8043,  8043,  8043,  8043, -2697,  8043,
    8043,  8043,  8043, -2697,  8043, -2697,   897, -2697,  8043, -2697,
    8043, -2697,  8043, -2697, -2697,  8043, -2697,  8043,  8043, -2697,
    8043, -2697, 14536,    20, -2697, -2697, -2697,  8043,    20,  8043,
   -2697, -2697,  8043,  8043, -2697, -2697, -2697, -2697, -2697, -2697,
   -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697,  8043,  8043,
    8043,  8043,  8043, -2697, -2697, -2697, 14536, -2697,  8043,  8043,
    8043, -2697, -2697,  2798,  2803,  2805,  2802,  2804,  2806,  2807,
    2809,  2811,  2808,   836,  2810,  2812,  2813,   838,  2816,  2819,
     839,   840,  2822,  2826,  2829,  2830,  2832,  2815,  2833,  2834,
    2835,  2838,  2840,  2842,   778,  2817,   808,  2850,  2848,  2857,
    2852,  2859,  2867,  2873,  2875,  2876,  2877,  2878,  2881,   843,
    2888,  2899,   847,  2901,  2902,  2903,  2904,  2906,  2909,  2905,
    2374,  2912,  2907,  2919,  2920,  2922,   854,  2918,  2926,  2927,
    2924,  2925,  2932,  2928,  2929,  2930,  2931,  2933,  2938,  2939,
    2934,  2936,  2943,  2944,  2945,  2946,  2947,  2951,  8043, -2697,
   -2697,  8043,  8043,  8043, -2697, -2697, -2697,  8043, -2697,  8043,
    8043,   897, -2697, -2697,    89,  8043,  8043, -2697,  8043, -2697,
    8043,  8043,  8043,  8043,  8043,  8043, -2697,  8043,  8043,  8043,
    8043,  8043,  8043,  8614, -2697,  8614, -2697, -2697,  8614,  8614,
    8043,  8043,  8043,    20,    20,    20,    20, -2697,  8043,  8043,
   -2697, -2697,  8043, -2697, -2697, -2697,  8043,  8043,  8043, -2697,
   -2697,  8043, -2697, -2697, -2697, -2697, -2697,  8043,  8043, -2697,
   -2697,  8043,  8043, -2697,    20,  8043,    20,  8043,  8043, -2697,
   -2697,  8043,  8043, -2697,  8043, 14536,  8043,  8043,  8043,  2949,
    2952,  2953,  2954,  2955,  2962,  2957,  2958,  2965,  2966,  2961,
    2968,  2969,  2970,  2971,  2972,  2973,  2974,   855,  2975,  2976,
    2977,  2978,  2979,  2981,  2983,  2984,  2986,  2982,  2987,  2989,
    2990,  2991,  2988,  2992,  2993,  2994,  2995,  2996,  2997,  2998,
    2999,  3000,  3001,  3002,  3003,  3004,  3005,  3006,  3007,  3014,
    3009,  3010,  3011,   857,  3012,  3013,  3015, -2697,  8043,  8043,
    8043,  8043, -2697,  8043,  8043, -2697, -2697,  8043, -2697, -2697,
   -2697, -2697, -2697, -2697,  8043, -2697,  8043, -2697,  8043, -2697,
   -2697,  8043, -2697, -2697, -2697, -2697,  8614, -2697, -2697, -2697,
   -2697,  8043,  8043, -2697,  8043, -2697,  8043, -2697,  8043,  8043,
    8043, -2697,  8043,  8043,    20,  8043,    20,  8043,  2248,  8043,
    8043,  8043, -2697, 14536,  8043,  8043,  8043,  3020,  3022,  3017,
    3024,   115,  3019,  3021,  3023,  3026,  3028,  3030,  3025,  3032,
    3027,  3029,  3034,  3031,  3033, -2697,  3036,   858,  3035,   859,
    3037,  3039,  3040, 14536,  3044,  3045,   913,  3046,  3038,   915,
    3048, -2697, -2697,  8043, -2697, -2697,   897,  8043,  8043, -2697,
   -2697, -2697,  8043, -2697,  8043,  8043, -2697,  8043,  8043, -2697,
   -2697, 14536,  8043, -2697, 14536,  8043,  8043,  8043, -2697,  8043,
    8043, -2697,  8043,  8043, -2697, -2697,  8043,  8043,  3051,  3042,
    3058,  3059,  3060,  3063,  3066,  3074,  3076,  3065,  3083,  3089,
    3084,  3085,  3086,  3093,  3090,  3091,  3099,   916,   917,  8043,
   -2697, -2697, -2697, -2697, -2697,  8043,  8043,  8043, -2697, -2697,
   -2697,  8043,  8043,    20, -2697,  8043,  8043, -2697, -2697,  8043,
   -2697, 14536,  3094,  3095,  3105,  3100,  3108,  3103,  3104,  3111,
    3106,  3115,  3110,  8043,  8043, -2697,  8043, -2697,  8043,    20,
   -2697,  8043, -2697, 14536,  3113,  3120,  3116,  3119,  3123,  3126,
    3131,  8043, -2697,  8043,  8043,  8043, -2697, -2697,  3129,  3130,
    3132,  3137,  8043,  8043,  8043, -2697,  3133,  3134,  3136,  8043,
    8043,  8043,  3143,  3138,  3139, -2697,  8043,  8043,  3140,  3147,
    8043, -2697,  3148, -2697
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  Parser::yydefact_[] =
  {
         2,   510,     0,     0,     0,     0,    21,    74,    75,    76,
      77,     0,     0,     0,   399,   408,    39,    20,     0,   109,
      81,     0,     0,     0,     0,     0,     0,     0,   108,     0,
       0,   389,   407,   860,   557,   411,   412,   413,   390,     0,
     820,     0,   776,     0,   869,   870,   871,   872,   873,   874,
       0,     0,   879,   880,     0,     0,    41,    44,    42,    43,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   320,
     321,   395,   322,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    85,     0,     0,   546,   547,   548,   549,
     550,   551,   552,   553,   554,   555,     0,     0,     0,   409,
     410,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   405,    40,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   348,
     349,   350,   351,   352,   353,   354,     0,     0,   511,     0,
       0,     4,     8,    10,    14,    16,    18,    12,     0,   391,
     400,   403,     0,   415,   492,   512,     0,   514,   518,   521,
     522,   527,   532,   534,   536,   538,   540,   542,   544,   545,
     313,   486,     0,   778,   780,   781,   799,   800,   804,   809,
     810,   811,   812,   813,   814,   815,   816,   817,   818,   819,
     121,     0,     0,     0,     0,     0,     0,   411,   412,   413,
       0,   820,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   494,     0,     0,   776,   496,   784,
     495,   783,   390,     0,   486,     0,     0,     0,     0,     0,
     102,    82,    84,   114,   112,   113,   111,   110,    83,   117,
     124,   119,   118,   125,   120,     0,     0,     0,   107,     0,
       0,    92,    93,     0,    95,    96,     0,    99,   100,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   361,
     361,    38,    33,   427,     0,     0,     0,     0,     0,   862,
     861,   863,   875,   865,   866,   867,   876,   868,   870,   872,
     873,   874,   878,   877,   879,   880,   864,   104,   105,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   497,   786,   498,
     787,   503,   792,   504,   793,   505,   794,   506,   795,   507,
     796,   509,   798,   508,   797,   499,   788,   500,   789,   501,
     790,   502,   791,     0,    25,     0,   405,    35,     0,    36,
       0,     0,     0,    30,    28,   405,     0,     0,     0,     0,
       0,     0,     1,     3,     5,     9,    11,    15,    17,    19,
      13,     0,     6,     0,     0,     0,     0,   493,   782,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   785,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   414,     0,     0,   779,     0,     0,     0,     0,     0,
       0,   879,     0,     0,    94,    97,    98,   101,     0,     0,
       0,     0,     0,     0,   453,   454,   451,   452,   449,   450,
     455,   456,   457,     0,     0,     0,   128,     0,     0,     0,
       0,   135,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   280,     0,     0,
       0,     0,   285,   286,     0,   269,     0,   277,     0,     0,
       0,     0,     0,   266,   267,     0,    56,    57,     0,     0,
     123,     0,     0,    73,     0,     0,     0,     0,     0,   567,
       0,   376,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,   364,     0,   362,   571,   707,
     709,   710,   728,   730,   736,   737,   742,   743,   752,   757,
     759,   760,   762,   764,   766,   768,   770,   370,     0,     0,
     333,     0,   326,     0,   327,   480,   324,     0,     0,     0,
       0,   331,   332,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   328,   329,   330,   334,
       0,     0,     0,   335,   346,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   571,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   177,
     178,     0,     0,   458,   459,     0,     0,     0,     0,     0,
       0,     0,     0,   460,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   216,   217,   179,   180,   181,   182,     0,
       0,   571,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   776,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   406,     0,    34,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,   401,   402,   530,   531,   515,   516,   517,   519,   520,
     524,   523,   525,   526,   528,   529,   533,   535,   537,   539,
       0,   541,     0,     0,     0,   396,     0,   424,   426,     0,
     219,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     556,   425,    87,    88,    86,   801,   803,   802,   805,   807,
     806,   808,   428,   429,   430,     0,     0,     0,   490,     0,
     253,     0,   248,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   247,
       0,   239,     0,   249,   250,     0,     0,     0,     0,     0,
     258,   260,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   834,
       0,     0,     0,     0,     0,   837,    61,     0,    51,     0,
       0,     0,   567,     0,     0,     0,   771,    59,     0,   834,
       0,   547,   550,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    69,     0,    67,
      50,    55,    54,   837,    60,     0,     0,     0,     0,     0,
     513,     0,    79,    80,     0,     0,   397,   398,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   115,   122,
     116,     0,     0,     0,   571,   728,   713,   712,   486,     0,
     366,   368,   372,   374,     0,   559,     0,     0,     0,   361,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   714,   715,   720,   721,   722,
     723,   724,   726,   725,   716,   717,   718,   719,   727,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   357,     0,   711,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   347,   821,
       0,   558,     0,    45,     0,     0,   571,     0,     0,     0,
       0,     0,   436,     0,     0,   438,     0,   439,   440,     0,
     441,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   432,     0,   437,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     314,   315,     0,     0,   434,     0,   777,   448,     0,   317,
       0,   405,   359,   404,   405,    26,   483,   484,   485,   319,
     378,   378,    32,     0,   261,     0,     0,     0,     0,     0,
     416,     0,     0,     0,     0,     0,     0,   218,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   222,     0,     0,
     223,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   832,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   361,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   821,   558,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   708,     0,
       0,     0,     0,   657,   655,   656,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   626,   627,     0,     0,     0,     0,   630,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   377,   365,
     363,   371,     0,     0,   884,     0,   883,     0,   769,   735,
     731,   733,   732,   734,   738,   740,   739,   741,   749,   745,
     748,   744,   750,   746,   751,   747,   755,   753,   756,   754,
     758,   761,   763,     0,   765,     0,     0,     0,     0,     0,
      37,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   106,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   543,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   831,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   772,     0,     0,
       0,     0,     0,     0,     0,    70,    68,     0,     0,   394,
     393,   392,     0,     0,     0,     0,     0,   151,     0,   154,
       0,   127,   130,   129,     0,     0,     0,     0,     0,   138,
     139,     0,     0,     0,     0,   144,     0,   153,     0,   270,
       0,   265,   272,     0,     0,     0,     0,   268,     0,   278,
       0,   273,     0,     0,     0,   276,   461,   487,   488,   489,
       0,     0,   729,   560,     0,     0,     0,   566,     0,     0,
       0,     0,   606,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   607,     0,     0,     0,     0,
       0,     0,     0,     0,   638,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   591,   592,   593,     0,   595,     0,
       0,     0,     0,     0,   602,     0,     0,     0,     0,     0,
       0,     0,     0,   609,     0,     0,     0,     0,     0,     0,
     564,   565,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   682,   587,   589,   651,   652,
     653,   654,     0,     0,     0,   686,     0,     0,     0,     0,
       0,     0,   698,     0,   700,     0,     0,   702,   703,   367,
     369,   373,   375,   683,     0,   572,     0,   613,     0,     0,
       0,     0,     0,     0,   481,   482,   479,     0,     0,     0,
       0,   468,     0,   473,     0,     0,     0,     0,     0,     0,
       0,   338,   340,     0,     0,   478,     0,     0,     0,   336,
      58,    62,    53,    46,     0,   491,     0,     0,     0,   311,
       0,   165,     0,   164,     0,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   185,   186,   187,     0,   200,
     201,     0,   203,   211,   205,   206,   212,   207,   213,   209,
     210,   208,   188,     0,   198,     0,   189,   214,   215,   194,
       0,   190,   191,   192,   193,   196,     0,   431,   447,     0,
       0,     0,   293,     0,     0,     0,   300,     0,     0,     0,
       0,     0,     0,   775,     0,   405,   360,    24,    27,   381,
     382,   383,   379,   380,   405,     0,   405,     0,     0,   345,
       0,     0,   417,     0,     0,     0,   423,    90,    89,   162,
     161,     0,   220,   221,     0,   307,     0,   309,   310,   157,
       0,     0,     0,   155,     0,   240,   245,   251,   252,   255,
       0,   254,   224,     0,   236,     0,   232,     0,     0,     0,
     228,   229,   230,   231,   237,   246,   238,   241,     0,     0,
     234,   244,     0,   259,   263,   838,   839,     0,     0,     0,
       0,     0,     0,   835,     0,     0,     0,   826,     0,     0,
       0,     0,     0,   833,   848,     0,     0,     0,     0,     0,
       0,    48,    49,   774,    52,   323,    47,     0,    65,    63,
       0,   103,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,   767,     0,     0,   692,   694,
     695,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   442,   443,   444,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   446,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,     0,   146,     0,   149,
       0,   152,     0,   133,   131,   134,   136,     0,     0,   141,
       0,     0,     0,     0,   271,     0,     0,     0,     0,   279,
     274,   287,     0,   462,    72,     0,     0,   578,   579,     0,
       0,     0,   605,   608,   610,   611,     0,   612,     0,     0,
       0,     0,     0,     0,     0,     0,   631,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   590,     0,     0,     0,     0,     0,     0,   603,   604,
       0,   573,   574,   575,     0,     0,   658,   659,   660,   661,
       0,   706,   667,     0,     0,     0,   672,   673,   674,   675,
     676,   677,   678,   679,     0,     0,     0,     0,     0,   687,
       0,     0,   688,     0,     0,   697,   699,   701,     0,     0,
     693,   696,   325,     0,     0,     0,     0,   467,   469,   472,
     471,   474,   470,   475,     0,   476,   337,   341,     0,   342,
     343,   344,     0,   312,     0,   176,   199,     0,     0,   202,
       0,     0,   288,     0,   290,     0,   295,     0,   294,     0,
       0,     0,     0,     0,     0,     0,     0,   316,   405,    22,
      31,   386,   387,   388,   384,   385,    29,   358,     0,     0,
       0,   418,     0,     0,   422,     0,     0,     0,     0,     0,
       0,     0,     0,   256,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   841,     0,     0,     0,     0,   836,   822,
       0,   823,   827,   828,   829,   830,     0,   849,     0,     0,
       0,     0,     0,     0,     0,     0,    66,    64,    71,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   486,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   445,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   145,   147,     0,     0,   126,     0,     0,   143,
       0,     0,   264,     0,     0,     0,   284,     0,     0,   570,
       0,     0,   580,   581,     0,     0,     0,     0,   617,     0,
     620,     0,   622,     0,   624,     0,     0,     0,     0,     0,
     628,   629,   662,     0,     0,     0,     0,     0,     0,   639,
       0,     0,     0,     0,     0,     0,     0,   649,     0,     0,
       0,     0,     0,     0,     0,   576,   577,   705,   668,     0,
       0,   680,     0,     0,     0,     0,     0,     0,   691,     0,
       0,     0,     0,   463,     0,   465,     0,   339,     0,   204,
       0,   195,     0,   289,   291,     0,   296,     0,     0,   305,
       0,   304,     0,     0,   433,   435,    23,     0,     0,     0,
     420,   421,     0,     0,   306,   308,   158,   159,   419,   156,
     233,   235,   225,   226,   227,   242,   243,   257,     0,     0,
       0,     0,     0,   824,   825,   850,     0,   851,     0,     0,
       0,   847,   773,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   882,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   150,
     137,     0,     0,     0,   281,   282,   283,     0,   568,     0,
       0,     0,   582,   583,     0,     0,     0,   616,     0,   619,
       0,     0,     0,     0,     0,     0,   588,     0,     0,     0,
       0,     0,     0,     0,   640,     0,   642,   644,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   600,     0,     0,
     669,   670,     0,   681,   684,   685,     0,     0,     0,   586,
     614,     0,   464,   466,   477,   163,   183,     0,     0,   292,
     299,     0,     0,   303,     0,     0,     0,     0,     0,   160,
     840,     0,     0,   844,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   148,     0,     0,
       0,     0,   569,     0,     0,   584,   585,     0,   618,   621,
     623,   625,   632,   635,     0,   664,     0,   666,     0,   633,
     636,     0,   641,   643,   645,   646,     0,   648,   594,   596,
     597,     0,     0,   601,     0,   671,     0,   689,     0,     0,
       0,   197,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   852,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   881,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   140,   142,     0,   275,   562,     0,     0,     0,   634,
     665,   663,     0,   647,     0,     0,   650,     0,     0,   184,
     297,     0,     0,   302,     0,     0,     0,     0,    91,     0,
       0,   846,     0,     0,   857,   856,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     563,   561,   615,   637,   598,     0,     0,     0,   298,   318,
     301,     0,     0,     0,   842,     0,     0,   853,   854,     0,
     858,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   704,     0,   262,     0,     0,
     843,     0,   855,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   599,     0,     0,     0,   845,   859,     0,     0,
       0,     0,     0,     0,     0,   356,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   132,     0,     0,     0,     0,
       0,   355,     0,   690
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
     -2697, -2697, -2697,   -46,  2220,  2288,  2557, -2697, -2697,  2567,
    2594,  2623,  2647, -2697,  -287,  1001, -2697,   572, -2697,  6964,
    -384, -2697, -2697, -2697, -2697,  -450,  4982,   562,  -414, -2697,
    -400,   544,  2517,  1994,  2337,  2490,  2364,  2386,  1419, -2697,
       0,    81,  3417, -2697, -2697, -2697,  -525,  -134,  -255, -2697,
   -2697,  -674,  -258,  1368, -2697,  1561,  1505,  1500,  1560,   795,
    1762,  7020,  1936, -2697, -2697, -2697, -2697,   638,   545, -2697,
   -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697,
       7,  5957,  -445,    43,   -35, -2696
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,   149,   150,   151,   152,   153,   154,   872,   871,   155,
     156,   157,   158,  1361,   664,  1778,   159,   160,   161,   162,
     384,   385,  1363,   163,   164,   165,   233,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     243,   181,   245,   669,   670,   671,   672,   673,   674,   675,
     676,   677,   678,   679,   680,   681,   682,   683,   684,   685,
     686,  1099,  1031,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     246,   236,   996,   921,   203,  1637
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int Parser::yytable_ninf_ = -877;
  const short int
  Parser::yytable_[] =
  {
       180,   291,   865,   689,  1034,   905,     6,   200,   888,   889,
       1,   873,  1040,   840,   841,    33,   842,    17,    14,   317,
    1095,  1095,   260,   263,   890,   891,   892,   893,    34,   261,
     928,   930,    25,    26,   211,   862,   211,    29,    30,  1003,
     724,    31,  1461,   202,  1548,    34,   216,   217,   216,   242,
    -862,  1542,  1543,   442,   424,   425,   932,   933,   934,  1379,
    2593,  1548,   257,   296,   217,   247,   434,  1505,   448,   843,
    1232,  1233,   211,    33,   285,   281,  1241,  1006,    34,  2038,
    -876,  -875,   387,   905,   216,  2599,   244,   393,   248,   449,
      33,   292,   446,   932,   933,   934,   249,   217,  1853,  1224,
     436,  1225,   437,   266,   404,   463,   438,   287,   938,  1665,
     538,   539,   412,  1095,  1095,  1095,  1095,  1095,  1095,  1095,
    1095,  1095,  1095,  1095,  1095,  1095,  1095,   386,  -861,  3305,
      34,   458,  -863,     6,   267,  1480,  2285,   463,  1873,   282,
      34,  1095,  2595,   269,    17,   938,  1665,    34,   270,   217,
     180,    34,   458,    34,    34,  1524,  1525,   200,   459,   217,
     289,    71,   415,   416,   271,   272,   217,   383,    33,   783,
     217,   297,   217,   217,   435,   273,   394,   395,  1549,   907,
     415,   416,   435,   293,  3005,  3007,  3009,   426,   427,   443,
     904,   905,  1242,   202,  1242,  1549,   447,   908,    33,  1666,
    1667,  1668,  1669,  1234,  1235,   286,   280,  1095,  1095,  1857,
     439,   415,   416,  1550,  1095,  1095,  1095,  1095,  1095,  1095,
    1095,  1095,  1095,  1095,  1095,  1095,  1095,  1095,   773,   774,
    1550,   440,   288,  1665,   472,   473,  1666,  1667,  1668,  1669,
     725,   294,   274,   275,   283,   284,   277,   278,   466,   974,
     975,   976,   295,   276,   907,   415,   416,   279,   977,   978,
     979,   980,   415,   416,  1728,   981,  1731,  1733,   319,   932,
     933,   934,   908,   474,  2720,   298,   475,  1514,    34,   476,
    1515,   290,    34,  1100,  1101,   535,   536,   244,   211,   667,
     667,     6,   322,   537,   323,   320,   726,   217,   728,   906,
     216,   217,    17,   419,   420,   321,   982,  1380,   421,   983,
     984,   985,   986,  1381,   987,   988,  1383,   324,   989,   730,
     731,   938,   757,  1666,  1667,  1668,  1669,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   330,  1380,    34,  2029,
    2030,  2162,   866,  1381,   211,  1382,  1383,  2163,   834,   835,
    2164,   837,   839,   458,  1354,   868,   216,   217,   329,   463,
     858,   253,   907,   458,    33,   880,   331,   863,   458,   463,
    2874,   918,  1523,  2651,   463,   254,   255,   256,   334,  2652,
     908,   332,  2653,   909,   910,   911,   912,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   874,  3173,   920,  3174,
     333,   920,  3175,  3176,  1224,  1010,  1225,    94,    95,   335,
     459,  1096,  1097,   458,  2175,   913,   914,   915,   338,   463,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     413,   414,  1281,   867,  1225,   339,   902,   903,   340,  1337,
     923,  1281,  1124,  1225,   458,  2177,   918,  1700,  1125,  1029,
     463,   458,  2849,   250,  1036,  1037,  1032,   463,  1038,   844,
     845,   846,   847,   848,   849,  1364,   341,   850,   851,   852,
     853,   854,   855,   856,  1095,  1095,   920,  1221,   990,   991,
     992,   458,  2871,  1222,   993,   342,   994,   463,   343,  1095,
    1095,  1095,  1095,  1095,  1095,  1095,  1095,  1095,  1095,  1095,
    1095,  1095,   344,  1095,  1195,  1196,  1197,  1198,  1199,  1200,
    1201,  1202,  1203,  1204,  1205,  1206,  1207,  1208,   540,   541,
     542,   543,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,  1223,   345,   148,  1244,  1124,  1104,  1089,  1451,
    3279,  1222,  1279,   430,  1899,  1909,  1927,  1285,   916,   917,
    1900,  1910,  1222,  1928,   918,    14,  1974,  2015,  1649,  1651,
    1653,  1655,  1975,  2016,   234,   238,   240,   919,   346,    25,
      26,  2022,   431,  2024,    29,    30,   347,  2023,    31,  2025,
     348,  2035,    34,  2051,   920,  2053,   242,  2036,  2062,  2052,
    2079,  2054,   349,   325,  2063,   326,  2080,  2083,  1096,  1097,
     350,   217,  1442,  2084,  1456,  1195,  1196,  1197,  1198,  1199,
    1200,  1201,  1202,  1203,  1204,  1205,  1206,  1207,  1223,  2132,
      14,  2154,   415,   416,  2156,  2133,  2170,  2155,  1098,  1498,
    2155,  2179,  2171,   351,    25,    26,   327,  2180,   328,    29,
      30,   239,   241,    31,   691,   352,   693,    34,   695,  2183,
     697,   242,   699,   700,   353,  2184,   703,   704,   705,   706,
     707,   708,   709,   710,  2189,   336,   217,   337,   715,   354,
    2190,   766,   355,   357,   359,   361,   363,   365,   367,   369,
     371,   373,   375,   377,   379,   381,  2194,  2216,  2223,  2227,
    2234,  2244,  2195,  2217,  2224,  2228,  2235,  1222,    71,  1110,
     356,   323,  1095,  1095,  1095,  1095,  1095,  1095,  1095,  1095,
    1095,  1095,  1095,  1095,  1095,  1095,  1095,  1095,  1773,  1774,
    1775,  1776,  1777,   390,   767,   768,   769,   770,   417,  1272,
     771,   772,   773,   774,   775,   776,   777,   778,   779,   780,
     781,   782,  2393,  2421,  2422,  2423,  2424,  2425,  2394,   358,
     360,   362,   364,   366,   368,   370,   372,   374,   376,   378,
     380,   382,  2508,    71,  2573,  2622,   238,   240,  2509,  2624,
    2574,  2623,  2626,  2679,  2687,  2625,   422,   423,  2627,  2680,
    2688,   391,   357,   359,   361,   363,   365,   367,   369,   371,
     373,   375,   377,   379,   381,   417,  2833,  2853,  3093,  2858,
    2036,  2860,  2834,  2854,   418,  2859,  1104,  2861,  2862,  1281,
     392,  1225,  2864,   396,  2863,  1275,  1644,  1646,  2865,  1365,
    2872,   402,  1526,  2879,    14,  2924,  2873,  1372,  3095,  2880,
    2036,  2925,  1648,  1650,  1652,  1654,  1656,  1658,    25,    26,
     428,   429,  2931,    29,    30,   397,   690,    31,  2932,   432,
    3068,    34,  3073,  3077,  3079,   242,  3069,  3107,  3074,  3078,
    3080,  3111,  1360,  3108,   398,  1096,  1097,  3112,  3126,  3225,
     217,  3262,  3320,  3323,  3127,  3226,   399,  3263,  3321,  3324,
    1195,  1196,  1197,  1198,  1199,  1200,  1201,  1202,  1203,  1204,
    1205,  1206,  1207,   400,  1223,   691,   692,   693,   694,   695,
     696,   697,   698,   699,   700,   701,   702,   703,   704,   705,
     706,   707,   708,   709,   710,   711,   712,   713,   714,   715,
     716,   717,   718,   719,   720,   721,   722,  3331,    14,  3335,
    3378,  3380,   401,  3332,   441,  3336,  3379,  3381,   444,   445,
     433,  1227,    25,    26,  1228,  1229,   450,    29,    30,   815,
     816,    31,   817,   818,   451,    34,   541,   542,   285,   242,
     773,   774,  1230,  1231,  1236,  1237,   452,    71,  1524,  1525,
    1542,  1543,   894,   895,   217,  1645,  1647,  1771,  1657,  1659,
    1772,   885,   886,   887,   454,   881,   882,   453,   455,   929,
     931,   456,  1922,   457,   460,   461,   462,   464,   468,   544,
     727,   729,   832,   833,   925,   864,   876,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,    33,    34,   299,   300,   301,   302,   303,   304,
     305,   306,   307,    44,   308,    46,   309,   310,   311,   312,
     313,   471,   315,   870,  1035,  1469,   783,  1041,  1470,  1472,
    1473,  1474,  1475,  1476,  1042,  1478,  1479,  1043,   905,  1044,
    1484,  1485,  1486,  1487,  1488,  1489,  1490,  1040,  1492,  1045,
    1494,    71,  1496,  1497,  1046,  1499,  1500,  1501,  1502,  1503,
     926,   927,  1098,  1047,  1509,  1510,  1511,  1512,   493,  1048,
    1049,  1050,  1051,  1639,  1641,  1643,  1052,  1053,  1054,  1055,
    1056,  1057,  1058,  1059,  1060,  1061,  1522,   238,   240,   667,
     757,  1062,  1063,  1064,  1065,  1066,  1067,  1068,  1069,   494,
     495,   496,   497,   498,  1442,   499,   500,   501,   502,   503,
     504,   505,   506,   507,   508,   509,   510,  1070,  1071,  1072,
    1073,  1074,    14,  1075,  1076,  1077,  1078,  1079,  1080,  1081,
    1082,  1083,  1084,  1085,  1086,  1091,    25,    26,  1092,  1093,
    1106,    29,    30,  1087,  1226,    31,  1109,  1858,  1107,    34,
    1108,  1111,  1112,   242,  1922,  1113,  1114,  1115,  1116,  1117,
    1118,  1119,  1120,  1121,  1122,  1520,  1123,  1126,   217,  1127,
    1128,  1129,  1131,  1132,  1130,  1133,  1136,  1137,  1670,  1138,
     357,   359,   361,   363,   365,   367,   369,   371,   373,   375,
     377,   379,   381,   511,  1134,   723,  1135,  1139,  1140,  1141,
    1142,  1143,  1630,  1144,  1038,  1635,  1145,  1146,   417,  1147,
    1148,   512,  1149,  1150,  1151,  1152,  1153,  1154,  1155,  1156,
    1157,  1158,  1159,  1160,  1161,  1162,  1163,  1164,  1674,  2070,
    1165,  1166,  1167,  1168,  1680,  1169,  1170,  1171,  1172,  1685,
    1173,  1687,  1688,  1174,  1690,  1691,  1692,  1693,  1175,  1176,
    1695,  1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,  1185,
    1186,  1187,  1188,  1189,  1702,    71,  1190,  1191,  1192,  1193,
    1194,  1209,  1210,  1707,  1211,  1709,  1710,  1711,  1212,  1213,
    1214,  1215,  1716,  1717,  1718,  1719,  1720,  1721,  1722,  1216,
    1724,  1217,  1218,  1219,  1220,  1239,  1245,  1240,  1246,  1238,
    1737,  1738,  1739,  1740,  1741,  1742,  1743,  1744,  1745,  1746,
    1747,  1748,  1749,  1750,  1751,  1243,  1247,  1248,  1249,  1250,
    1755,  1756,  1757,  1758,  1759,  1760,  1761,  1251,  1252,  1253,
    1254,  1255,  1765,  1766,  1256,  1767,  1257,  1258,  1259,  1260,
    1261,  1262,  1263,  1264,  1265,  1266,  1267,  1482,  1508,  1273,
    1269,  1270,  1483,  1780,  1271,  1781,  1278,  1274,  1277,  1280,
    1282,  1786,  1787,  1788,  1283,  1285,  1286,  1284,  1287,  1288,
    1794,  1796,  1798,  1799,  1800,  1801,  1802,  1289,  1803,  1804,
    1846,  1805,  1806,  1807,  1808,  1809,  1810,  1290,  1812,  1813,
    1814,  1815,  1816,  1817,  1818,  1819,  1291,    14,  1822,  1292,
    1824,  1825,  1293,  1827,  1828,  1829,  1294,  1295,  1296,  1297,
    1298,    25,    26,  1299,  1300,  1301,    29,    30,  1302,  1303,
      31,  1304,  1305,  1306,    34,  1307,  1308,  1309,   242,  1310,
    1854,  1855,  1311,  1312,   667,  1313,  1860,  1314,  1862,  1863,
    1315,  1316,  1317,   217,  1318,  1319,  1320,  1321,  1870,  1322,
    1323,  1324,  1325,  1326,  1327,  1328,  1329,  1330,   239,   241,
    1331,  1332,   358,   360,   362,   364,   366,   368,   370,   372,
     374,   376,   378,   380,   382,   418,  1333,     6,  1334,  1335,
    1336,  1338,  1340,  1449,  1339,    14,  1493,  1350,    17,  1341,
    1342,  1343,  1344,  1095,  1345,  1346,  1347,  1348,  1349,    25,
      26,  1351,  1352,  1353,    29,    30,  1355,  1356,    31,  1357,
    1358,  1359,    34,  1366,  1367,  1368,   242,  1369,  1370,  1371,
    1495,  1374,  1373,  1507,  1375,  1385,  1386,  1384,  1376,  1377,
    1378,   217,   513,  1388,   514,  1389,   515,   516,  1390,  1391,
      71,   238,   240,  1450,   517,  1392,  1393,   518,   519,   520,
     521,   522,   523,   524,   525,  1394,   357,   359,   361,   363,
     365,   367,   369,   371,   373,   375,   377,   379,   381,  1395,
     417,  1396,  1398,  1399,  1401,  1402,  1403,  1404,  1405,  1406,
    1407,  1408,  1409,  1410,  1411,   526,  1412,  1413,  1414,   527,
    1415,  1416,  1417,  1418,   528,   529,  1419,  1420,  1421,  1422,
    1423,  1424,  1425,  1426,  1427,   530,  1428,  1429,  1430,  1431,
     531,   532,  1432,  1433,  1434,  1435,  1436,   239,   241,  1437,
    1438,  1439,  1440,     1,  1441,     2,     3,     4,    71,     5,
    1444,  1445,   358,   360,   362,   364,   366,   368,   370,   372,
     374,   376,   378,   380,   382,  1446,   418,    14,    15,  1447,
    1448,  1452,  1453,  1454,  1455,  1457,  1458,  1459,  1460,  1462,
    1464,    25,    26,  1468,  1465,  1463,    29,    30,  1466,  1517,
      31,  1518,    32,  1554,    34,   207,   208,   209,   242,   210,
     211,  1555,   237,   213,  1621,  1675,  1678,  1676,  1679,   214,
     215,  1681,   216,   217,  1686,  1694,  1682,  1683,  1696,  1697,
    1699,  1698,  1703,  1523,  1704,  2147,  2148,   783,   784,   785,
     786,   787,   788,   789,   790,   791,  1705,   792,   793,   794,
     795,   796,   797,   798,   799,   800,   801,   802,   803,   804,
     805,   806,   807,   808,   809,   810,   811,   812,  1754,  1770,
    1861,  2419,  1769,  1868,  1871,  1947,  1872,  1874,  1789,  2145,
    2420,  1875,  2426,   813,   814,  1877,  1876,  1878,  1879,  1880,
    1853,    62,    63,    64,    65,    66,  1881,  1882,  1883,  2167,
    1640,  1642,  2149,  2150,  2151,  1889,  1884,  1885,  1886,  1887,
    1888,   218,  1890,  1891,  1892,  1893,  1894,  1895,  1897,  1896,
      71,  1898,   219,    34,   299,   300,   301,   302,   303,   304,
     305,   306,   307,    44,   308,    46,   309,   310,   311,   312,
     313,   314,   315,    34,   299,   300,   301,   302,   303,   304,
     305,   306,   307,    44,   308,    46,   309,   310,   311,   312,
     313,   471,   315,  1901,  1902,  1903,  1904,  1905,  1906,  1907,
    1908,  1911,    76,  1912,  1913,  1915,  1914,  1916,  1917,  1918,
    1919,  1923,  1920,  2254,  2255,  2256,  2257,  1925,  2258,  1924,
    2259,  1926,  1929,  1930,  1931,  1932,  2262,  2263,  2264,  1933,
    1934,  2265,  2266,  2267,  2268,    77,  2269,    78,  2270,  1935,
    2271,  1936,  1937,  2272,  2273,  2274,  2275,  1938,  1939,  1940,
    2276,  1941,  1942,  2278,  1943,  1944,  1945,  1946,  1948,  1949,
    1950,  1951,  1952,  1953,  2282,  2152,  2283,  1954,  1955,  1964,
    2287,  2288,  1956,  2289,  2290,  2291,  2292,  2293,  2294,  2295,
    2296,  2297,  2298,  2299,  2300,  1957,  2301,  1958,  1959,  1960,
    1961,  1962,  1963,  1965,  1966,  2309,  2310,  2311,  2312,  2313,
    2314,  2315,  2316,  2317,  1967,  1968,  1969,  1970,    91,    92,
    1971,  1983,  1972,  1973,  1976,  1977,  1978,  2326,  2327,  2328,
    2329,  1979,  1980,  1981,  2332,  2333,  2334,  2335,  1982,  1984,
    1985,  1986,  1987,  1988,  2340,  2341,  2342,  2343,  2344,  2345,
    2346,  2347,  2348,  2349,  2350,  1989,  1990,  1991,  1992,  1993,
    1994,  1995,  2351,  2352,  2353,  1996,  2354,  2355,  1997,  2357,
    2358,  1998,  1999,  2360,  2000,  2361,  2001,  2002,  2003,  2004,
    2005,  2006,  2007,  2008,  2009,  2010,  2364,  2011,  2153,  2366,
      94,    95,  2012,  2027,  2013,  2014,  2017,  2371,  2373,  2375,
    2018,  2019,  2020,  2021,  2379,  2026,  2028,  2033,  2034,  2039,
    2385,  2037,  2040,  2386,  2387,  2041,  2388,  2389,  2390,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,  2042,
     106,  2043,  2396,  2044,  2397,  2045,  2046,  2047,  2061,  2065,
     109,   110,   111,   112,   113,   114,   115,   116,  2398,  2048,
     117,   118,   119,   120,   121,   122,   123,  2049,  2050,  2055,
    2056,  2057,  2058,  2400,  2059,  2401,  2060,  2064,  2066,  2067,
    2402,  2068,   130,   131,  2069,  2071,  2403,  2073,  1928,   920,
    2405,  2406,  2075,  2407,  2409,  2410,  2081,  2411,  2412,  2082,
    2085,  2415,  2416,  2086,  2417,  2087,  2088,  2089,  2090,  2091,
     932,   933,   934,   935,  2092,  2093,  2094,  2427,  2428,  2095,
    2096,  2430,  2097,  2431,  2432,  2433,  2099,   148,  2100,  2098,
    2101,  2434,  2102,  2103,  2435,  2104,  2436,  2105,  2106,  2107,
    2437,  2438,  2439,   936,  2440,  2108,  2109,  2110,  2111,  2112,
    2441,   937,  2114,  2442,  2240,  2443,  2113,  2444,  2445,  2446,
    2115,  2116,   938,  2117,  2118,  2119,   939,  1857,  2447,  2448,
    2121,  2122,  2449,  2120,  2123,  2124,  2125,  2450,  2451,  2452,
    2453,  2454,  2455,  2126,  2456,  2457,  2458,  2127,  2459,  2460,
    2461,  2462,  2463,  2128,  2130,  2464,  2465,  2466,  2467,  2136,
    2470,  2131,  2134,  2135,  2137,  2143,  2138,  2139,  2140,   940,
    2141,   941,   942,   943,  2795,  2142,  2144,  2157,  2158,  2159,
    2160,  2161,   944,   945,  2165,  2166,  2169,  2172,   946,   947,
     948,   949,  2173,  2178,  2174,  2176,  2181,  2182,  2185,  2186,
    2503,  2187,  2188,   950,   951,   952,   953,   954,  2191,   955,
     956,  2192,   957,  2193,  2196,  2197,  2198,   958,   959,   960,
     961,   962,   963,   964,   965,   966,   967,   968,   969,   970,
     971,   972,  2199,  2200,  2201,  2202,  2203,  2204,  2205,  2206,
    2207,  2280,  2418,  2210,  2211,  2281,  2213,  2208,  2209,  2214,
    2215,  2212,  2376,  2218,  2219,  2471,  2474,  2220,  2221,  2222,
    2225,  2226,  2229,  2230,  2231,  2232,  2233,  2236,  2237,  2238,
    2239,  2241,  2242,  2243,  2245,  2363,  2248,  2246,  2247,  2249,
    2251,  2368,  2369,  2250,  2370,  2391,  2392,  2404,  2475,  2472,
     405,  2477,  1779,  2639,  2640,  2473,  2476,  2479,  2478,  2480,
    2646,  2481,  2482,  2483,  2484,  2485,  2486,  2655,  2487,  2489,
    3120,  2641,  3293,  2488,  2612,  2494,  2490,  2491,  2492,  2493,
    2495,  2499,  2496,  2497,  2498,  2500,  2501,  2504,  2502,  2505,
    2506,  2507,  2512,  2513,  2510,  2511,  2514,  2515,  2638,  2517,
    2516,  2518,   973,  2642,  2519,   897,  2520,  2521,  2522,  2523,
    2524,  2525,  2526,  2527,  2528,  2529,  2530,  2531,   406,  2532,
    2533,  2534,  2535,  2536,  2537,  2538,  2539,  2540,  2541,  2542,
    2543,  2544,  2545,  2546,  2548,  2547,  2549,  2550,  2551,  2552,
    2553,  2554,  2556,  2555,  2557,  2558,  2559,  2560,  2561,  2562,
    2566,  2910,  2567,  2563,  2568,  2569,  2699,  2564,  2700,  2565,
    2701,  2570,  2702,  2571,  2572,  2575,  2576,  2703,  2704,  2579,
    2705,  2706,  2707,  2708,  2577,  2709,  2710,  2711,  2712,  2578,
    2580,  2581,  2713,  2582,  2583,  2714,  2716,  2584,  2585,  2586,
    2587,  2722,  2588,  2589,  2590,  2591,  2723,  2592,  2724,  2725,
    2726,  2727,  2728,  2729,  2730,  2731,  2594,  2732,  2734,  2736,
    2737,  2738,  2739,  2740,  2741,  2742,  2743,  2744,  2745,  2746,
    2747,  2596,  2748,  2597,  2598,  2600,  2601,  2602,  2603,  2605,
    2754,  2606,  2607,  2987,  2755,  2756,  2604,  2609,  2610,  2608,
    2611,  2613,  2614,  2615,  2759,  2760,  2616,  2619,  2617,  2628,
    2618,  2620,  2637,  2643,  2761,  2762,  2763,  2764,  2765,  2621,
    2766,  2767,  2629,  2768,  2769,  2630,  2631,  2717,  2770,  2771,
    2718,  2632,  2633,  2772,  2773,  2774,  2775,  2634,  2635,  2636,
    2647,  2648,  2644,  2649,  2650,  2654,  1660,  2656,  2777,  2657,
    2658,  2645,  2659,  2660,  2779,  2661,  2662,  2663,  2781,  2664,
    2782,  2783,  2665,  2911,  2666,  2667,  2668,  2669,  2670,  2671,
    2788,  2789,  2790,  2672,  2673,  2793,  2794,  2674,  2675,  2676,
    2678,  2677,  2681,  2682,  2683,  2684,  2685,  2686,  2796,  2698,
    2798,  2778,  2799,  2800,  2689,  2801,  2802,  2803,  2804,  2805,
    2806,  2807,  2808,  2690,  2809,  2810,  2811,  2812,  2813,  2814,
    2815,  2816,  2817,  2691,  2818,  2819,  2820,  2821,  2692,  2693,
    2694,  2695,  2832,  2835,  2836,  2837,  2838,  2839,  2824,  2825,
    2826,  2827,  2840,  2842,  2830,  2831,  2841,  2843,  2844,  2846,
    2845,  2847,  2848,  2850,  2851,  2852,  1700,   407,  2855,  2856,
    2857,  2870,  2866,  2867,  2868,  2869,  2875,   408,  2876,  2877,
    2878,  2881,  2882,  2883,  2884,  2885,  2886,  2887,  2888,  2889,
    2890,  2891,  2892,  2895,  2893,  2894,  2896,  2897,  2898,  2901,
    2899,  2900,  1664,  2908,   409,  1662,  2902,  2903,  2904,  2936,
    2905,  2906,  2907,  2909,  2912,  2913,  2914,  2915,  2916,  2917,
    2918,  2919,  2920,  2921,  2922,  2923,  2926,  2929,  2927,   898,
    2928,  2934,  2935,   410,  2930,  2933,  2937,  2940,  2941,  2938,
    2939,  2942,  2943,  2944,  2945,  2946,  2947,  2948,  2949,  2950,
    2951,  2952,  2953,  2954,  2955,  2956,  2957,   411,  1785,   901,
    1661,  1663,  2963,  2958,  2959,  2960,  2961,  2962,  2964,  2965,
    2966,  2967,  2968,  2969,  2971,  2972,  2970,  3059,  3058,  3060,
     900,  3064,  3061,  3065,  3062,  3066,  3063,  3072,  3067,  3086,
    3070,  3094,  3071,  2365,  2973,  2974,  3075,  2975,  2976,  3076,
    2977,  2978,  3081,  2979,  2980,  2981,  3082,  2982,  2983,  3083,
    3084,  2985,  3085,  3087,  3088,  3089,  2988,  2989,  3090,  2990,
    3091,  2991,  3092,  2992,  3096,  2993,  2994,  2995,  2996,  2997,
    2036,  3097,  3098,  2998,  2999,  3000,  3001,  3002,  3003,  3099,
    3004,  3006,  3008,  3010,  3011,  3012,  3013,  3100,  3014,  3015,
    3016,  3017,  3018,  3101,  3020,  3102,  3103,  3104,  3105,  3021,
    3022,  3106,  3023,  3024,  3025,  3026,  3027,  3028,  3109,  3029,
    3030,  3031,  3032,  3110,  3033,  3113,  3114,  3115,  3035,  3119,
    3036,  3122,  3037,   899,  3116,  3038,  3117,  3039,  3040,  3118,
    3041,  2984,  3121,  3123,  3124,  2986,  3125,  3044,  3128,  3046,
    3129,  3130,  3047,  3048,  3131,  3132,  3133,   896,  3134,  3135,
    3136,  3137,  3139,  3140,  3141,  3138,  3142,  3143,  3049,  3050,
    3051,  3052,  3053,  3207,  3144,  3145,  3146,  3147,  3055,  3056,
    3057,  3148,  3208,  3209,  3210,  3211,  3212,  3213,  3214,  3215,
    3216,  3217,  3218,  3219,  3220,  3221,  3222,  3223,  1638,  3227,
       0,  3229,  3230,     0,  3224,  3232,  3228,  3233,  3234,  3231,
    3235,  3237,  3236,  3238,  3239,  3240,     0,  3243,  3241,  3245,
       0,  3247,  3242,     0,  3244,  3251,  3246,  1506,  3248,     0,
    3250,  3249,  3252,  3253,  3254,  3255,  3256,  3257,  3258,  3259,
    3260,  3261,  3264,  3265,  3301,  3266,  3302,  3303,  3304,  3306,
    3309,  3307,  3310,  3308,  3311,  3312,  3313,  3314,  3316,  3315,
    3319,  3317,  3334,  3318,     0,  3322,  3360,  3325,  3149,  3326,
    3327,  3150,  3151,  3152,  3329,  3330,  3333,  3153,  3337,  3154,
    3155,  3359,  3361,  3362,  3363,  3158,  3159,  3364,  3160,  3368,
    3161,  3162,  3163,  3164,  3165,  3166,  3365,  3167,  3168,  3169,
    3170,  3171,  3172,  3008,  3366,  3008,  3367,  3369,  3008,  3008,
    3177,  3178,  3179,  3370,  3371,  3372,  3373,  3374,  3184,  3185,
    3375,  3376,  3186,  3377,  3393,  3394,  3187,  3188,  3189,  3395,
    3396,  3190,  3397,  3398,  3399,  3400,  3401,  3191,  3192,  3402,
    3403,  3193,  3194,  3411,  3412,  3196,  3413,  3198,  3199,  3414,
    3416,  3200,  3201,  3415,  3202,  3417,  3204,  3205,  3206,  3422,
    3423,  3425,  3424,  3429,  3430,  3157,  3431,  3435,  3436,  3437,
    3440,  3441,  3443,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3267,  3268,
    3269,  3270,     0,  3272,  3273,     0,     0,  3274,     0,     0,
       0,     0,     0,     0,  3275,     0,  3276,     0,  3277,     0,
       0,  3278,     0,     0,     0,     0,  3008,     0,     0,     0,
       0,  3280,  3281,     0,  3282,     0,  3283,     0,  3284,  3285,
    3286,     0,  3287,  3288,     0,  3290,     0,  3292,     0,  3294,
    3295,  3296,     0,     0,  3298,  3299,  3300,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3338,     0,     0,     0,  3340,  3341,     0,
       0,     0,  3342,     0,  3343,  3344,     0,  3345,  3346,     0,
       0,     0,  3348,     0,     0,  3350,  3351,  3352,     0,  3353,
    3354,     0,  3355,  3356,     0,     0,  3357,  3358,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3382,
       0,     0,     0,     0,     0,  3383,  3384,  3385,     0,     0,
       0,  3386,  3387,     0,     0,  3389,  3390,     0,     0,  3391,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3404,  3405,     0,  3406,     0,  3407,     0,
       0,  3409,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3418,     0,  3419,  3420,  3421,     0,   182,     0,   235,
     235,   235,  3426,  3427,  3428,     0,     0,     0,     0,  3432,
    3433,  3434,     0,     0,     0,   251,  3438,  3439,   258,     0,
    3442,   265,     0,     0,   265,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   316,   265,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,     0,     0,     0,     0,   265,   265,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   182,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   235,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   235,   235,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   265,     0,   265,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   265,   265,     0,   316,   316,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   265,     0,     0,
       0,     0,     0,     0,     0,     0,   668,   668,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   753,   668,
     753,   753,   753,   753,   753,   753,   765,     0,     0,     0,
       0,   819,   820,   821,   753,   824,   825,   826,   827,   828,
     829,   830,   831,     0,     0,     0,     0,   836,   838,     0,
       0,   265,   753,   861,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   316,   265,     0,
       0,     0,     0,     0,   265,     0,   877,   878,   879,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     265,   265,   265,   265,     0,     0,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   753,   668,     0,   235,
       0,   235,   235,     0,   403,   753,   668,     0,     0,     0,
       0,     1,     0,     2,     3,     4,     0,     5,     0,   235,
       0,     0,     0,     0,     0,     0,     0,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,     0,
       0,     0,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,     0,    29,    30,     0,     0,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,     0,     0,    56,    57,    58,    59,
       0,    60,    61,     0,     0,     0,   265,     0,     0,     0,
       0,     0,  1094,  1094,   668,  1102,   265,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    62,
      63,    64,    65,    66,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    67,     0,     0,     0,     0,    68,
       0,     0,     0,     0,     0,     0,    69,    70,    71,    72,
      73,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1094,  1094,  1094,  1094,  1094,
    1094,  1094,  1094,  1094,  1094,  1094,  1094,  1094,   753,     0,
       0,     0,     0,     0,     0,    74,    75,     0,     0,     0,
       0,     0,     0,  1094,     0,     0,     0,     0,     0,     0,
      76,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    77,     0,    78,     0,     0,     0,     0,
       0,    79,    80,    81,    82,    83,    84,     0,    85,     0,
       0,     0,   265,     0,     0,     0,     0,     0,     0,   753,
     753,  1276,     0,     0,     0,     0,   753,   753,   753,   753,
     753,   753,   753,   753,   753,   753,   753,   753,   753,   753,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
      87,    88,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    89,    90,    91,    92,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    93,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     265,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,     0,   106,   107,
       0,     0,   108,     0,     0,     0,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   265,     0,   117,   118,
     119,   120,   121,   122,   123,     0,   124,     0,     0,     0,
       0,   125,     0,   126,   127,     0,     0,     0,   128,   129,
     130,   131,   265,   132,     0,     0,   265,     0,     0,     0,
     133,   134,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   135,     0,     0,
       0,     0,   136,   137,     0,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   265,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1094,  1094,   668,   265,
       0,     0,     0,     0,     0,     0,   265,     0,     0,     0,
       0,  1094,  1094,  1094,  1094,  1094,  1094,  1094,  1094,  1094,
    1094,  1094,  1094,  1094,     0,  1094,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   265,     0,
       0,     0,     0,     0,     0,  1471,     0,     0,     0,     0,
       0,  1477,     0,     0,  1481,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   753,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   265,     0,
     265,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1521,     0,     0,     0,     0,   668,   668,  1528,   753,
     753,  1531,  1532,  1533,  1534,  1535,   753,  1537,  1538,  1539,
    1540,  1541,     0,  1544,  1545,  1546,  1547,     0,   753,   753,
    1553,     0,     0,  1556,  1557,  1558,  1559,  1560,  1561,  1562,
    1563,  1564,   753,  1566,  1567,  1568,  1569,  1570,  1571,  1572,
    1573,  1574,  1575,  1576,  1577,  1578,   753,   753,   753,   753,
     753,  1584,  1585,  1586,  1587,  1588,     0,     0,   265,   265,
    1593,  1594,  1595,  1596,  1597,  1598,  1599,  1600,  1601,  1602,
    1603,  1604,  1605,   753,  1607,  1608,  1609,  1610,  1611,  1612,
     753,   753,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   753,   753,   753,  1618,
     753,   753,     0,   753,   753,   753,   753,   265,     0,   668,
       0,   668,  1636,   753,   753,  1094,  1094,  1094,  1094,  1094,
    1094,  1094,  1094,  1094,  1094,   753,   753,   753,   753,   753,
       0,     0,   265,   265,   265,     0,     0,     0,   265,     0,
       0,     0,     0,     0,     0,   265,     0,     0,     0,     0,
     265,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   753,     0,     0,   753,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1706,
       0,  1708,     0,     0,     0,  1712,  1713,  1714,  1715,     0,
       0,     0,     0,     0,     0,     0,  1723,     0,  1725,  1726,
    1727,  1729,  1730,  1732,  1734,  1735,  1736,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1752,     0,   753,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1762,  1763,  1764,     0,     0,     0,
       0,     0,     0,     0,     0,   265,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   265,  1783,  1784,     0,     0,     0,     0,
       0,     0,   265,  1791,     0,  1792,  1793,  1795,  1797,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   753,     0,     0,     0,     0,     0,
       0,     0,     0,  1820,   753,     0,   753,     0,     0,  1826,
       0,     0,     0,   753,  1831,     0,     0,     0,   753,   753,
     753,   265,   753,  1840,     0,  1842,     0,     0,   753,   265,
       0,   753,   753,   753,   753,   753,     0,     0,     0,   265,
       0,   668,   265,     0,     0,     0,     0,   265,   265,   265,
       0,   265,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1094,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   166,     0,     0,   166,   166,   166,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   166,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2031,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,     0,     0,     0,     0,
       0,     0,     0,   753,     0,     0,   753,     0,     0,     0,
     753,  2077,  2078,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   166,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   166,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   753,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   265,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   668,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   166,     0,
       0,   666,   666,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   265,     0,     0,     0,  2253,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2260,  2261,   752,   666,   752,   752,   752,   752,   752,
     752,     0,     0,     0,     0,     0,     0,     0,   752,   752,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2277,
       0,   753,     0,     0,     0,   857,     0,   752,   668,     0,
       0,     0,     0,     0,     0,   753,  2286,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2302,  2303,   753,   753,  2306,  2307,
    2308,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2318,     0,  2319,  2320,  2321,  2322,
    2323,     0,  2324,  2325,     0,     0,     0,     0,   753,   753,
       0,     0,     0,     0,     0,  2336,   265,     0,     0,  2338,
    2339,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   752,   666,     0,   166,   857,   166,   166,     0,     0,
     752,  1028,     0,     0,     0,  2356,     0,     0,  2359,     0,
       0,     0,     0,   753,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   753,     0,  2367,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   265,
       0,     0,   265,   265,   265,   265,   265,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   753,     0,     0,     0,     0,     0,  2395,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2399,     0,
       0,     0,     0,     0,     0,     0,     0,   666,   666,   666,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     668,     0,     0,     0,     0,     0,  2413,  2414,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2429,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     666,   666,   666,   666,   666,   666,   666,   666,   666,   666,
     666,   666,   666,   752,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   666,     0,
       0,     0,     0,     0,     0,   668,   753,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   752,   752,   752,     0,     0,     0,
       0,   752,   752,   752,   752,   752,   752,   752,   752,   752,
     752,   752,   752,   752,   752,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   857,   857,   857,     0,   857,   857,   857,   857,
     857,   857,   857,   857,   857,   857,   857,   857,   857,   857,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   265,
     265,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2715,     0,     0,     0,  2719,  2721,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2733,  2735,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   201,     0,     0,
    2749,  2750,  2751,  2752,  2753,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   252,     0,   753,     0,     0,
     753,  1028,  1028,  1028,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1028,  1028,  1028,  1028,
    1028,  1028,  1028,  1028,  1028,  1028,  1028,  1028,  1028,     0,
    1028,     0,     0,     0,     0,     0,     1,     0,     2,   204,
     205,   265,   206,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2780,     0,     0,     0,     0,     0,
     753,    15,   753,     0,   753,     0,   753,     0,     0,   752,
    2791,  2792,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    32,  2797,    34,   207,   208,
     209,     0,   210,   211,     0,   212,   213,     0,     0,     0,
       0,     0,   214,   215,     0,   216,   217,     0,     0,     0,
       0,   666,   666,     0,   752,   752,     0,  2822,     0,     0,
       0,   752,     0,   753,     0,     0,     0,   201,     0,   753,
     753,     0,     0,   752,   752,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   752,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   752,   752,   752,   752,   752,     0,     0,     0,     0,
       0,     0,     0,     0,    62,    63,    64,    65,    66,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   752,     0,
       0,     0,     0,     0,   218,   752,   752,     0,     0,     0,
       0,     0,     0,     0,     0,   219,     0,     0,     0,     0,
       0,   752,   752,   752,     0,   752,   752,     0,   752,   752,
     752,   752,     0,     0,   666,     0,   666,     0,   752,   752,
     666,   666,   666,   666,   666,   666,   666,   666,   666,   666,
     752,   752,   752,   752,   752,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    76,     0,     0,     0,     0,
     533,   534,     0,     0,     0,     0,   688,   688,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     752,     0,     0,   752,     0,     0,     0,  2719,    77,     0,
      78,  2719,     0,     0,     0,     0,     0,     0,   755,   688,
     755,   755,   755,   755,   755,   755,     0,     0,     0,     0,
       0,     0,     0,   755,   755,     0,     0,  1636,  1636,  1636,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3019,     0,   755,     0,     0,     0,     0,     0,     0,   752,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   265,     0,     0,     0,     0,     0,     0,
       0,    91,    92,     0,     0,     0,     0,     0,     0,   753,
    3043,     0,     0,     0,     0,  3045,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   753,     0,     0,     0,     0,     0,   752,
       0,     0,     0,     0,     0,     0,   755,   688,     0,   752,
       0,   752,     0,     0,   995,   755,  1033,     0,   752,     0,
       0,     0,     0,   752,   752,   752,     0,   752,     0,     0,
       0,     0,     0,   752,     0,     0,   752,   752,   752,   752,
     752,     0,     0,     0,     0,     0,   666,     0,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,     0,   106,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   109,   110,   220,   221,   222,   223,   224,
     225,     0,     0,   226,   227,   228,   229,   230,   231,   232,
       0,     0,     0,     0,     0,     0,     0,     0,   265,     0,
       0,  2719,     0,     0,     0,   130,   131,     0,     0,   666,
       0,     0,   688,   688,   688,  1103,     0,     0,     0,     0,
    1636,     0,  1636,     0,     0,  1636,  1636,     0,     0,     0,
    3180,  3181,  3182,  3183,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     148,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3195,     0,  3197,     0,     0,     0,     0,     0,     0,
       0,     0,   753,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   688,   688,   688,   688,   688,
     688,   688,   688,   688,   688,   688,   688,   688,   755,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   688,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1636,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3289,     0,  3291,     0,     0,     0,     0,   752,     0,
     753,   752,     0,     0,     0,   752,     0,     0,     0,   755,
     755,   755,     0,     0,     0,     0,   755,   755,   755,   755,
     755,   755,   755,   755,   755,   755,   755,   755,   755,   755,
     753,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   265,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   752,     0,   753,     0,
       0,   753,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   666,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3388,     0,     0,     0,     0,     0,     0,     0,   753,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3408,     0,     0,     0,
     753,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   752,     0,     0,     0,
       0,     0,     0,   666,     0,     0,     0,     0,     0,     0,
     752,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   752,   752,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   688,   688,   688,     0,
       0,     0,     0,   752,   752,     0,     0,     0,     0,     0,
       0,   688,   688,   688,   688,   688,   688,   688,   688,   688,
     688,   688,   688,   688,     0,   688,   259,   262,   264,     0,
       0,   268,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   752,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   318,
     752,     0,     0,     0,   755,     0,     0,     0,     0,     0,
       0,   995,     0,     0,     0,     0,     0,  1504,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   752,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   688,   688,     0,   755,
     755,     0,     0,     0,     0,     0,   755,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   755,   755,
       0,     0,   388,   389,     0,     0,     0,     0,     0,     0,
       0,     0,   755,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   666,   755,   755,   755,   755,
     755,     0,     0,     0,     0,     0,  1589,  1590,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   755,     0,     0,     0,     0,     0,     0,
     755,   755,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   755,   755,   755,     0,
     755,   755,     0,   755,   755,   755,   755,     0,     0,   688,
       0,   688,     0,   755,   755,   688,   688,   688,   688,   688,
     688,   688,   688,   688,   688,   755,   755,   755,   755,   755,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   465,     0,   467,     0,     0,     0,     0,     0,     0,
     666,   752,     0,     0,     0,     0,     0,     0,     0,     0,
     469,   470,     0,     0,     0,   755,     0,     0,   755,     0,
       0,     0,     0,     0,   477,     0,     0,     0,     0,     0,
       0,     0,     0,   665,   665,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       2,   204,   205,     0,   206,     0,     0,     0,     0,     0,
       0,     0,     0,  1633,     0,     0,     0,     0,     0,     0,
       0,     0,    14,    15,   755,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    25,    26,     0,   687,
     687,    29,    30,     0,     0,    31,     0,    32,   859,    34,
     207,   208,   209,   242,  1634,   211,     0,   212,   213,     0,
       0,     0,     0,     0,   214,   215,     0,   216,   217,     0,
       0,   754,   758,   759,   760,   761,   762,   763,   764,     0,
       0,     0,     0,     0,     0,   869,   822,   823,     0,     0,
       0,   875,     0,     0,   755,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   755,   860,   755,     0,     0,   883,
     884,     0,     0,   755,     0,  1832,  1833,  1834,   755,   755,
     755,     0,   755,     0,  1841,     0,  1843,  1844,   755,     0,
       0,   755,   755,   755,   755,   755,    62,    63,    64,    65,
      66,   688,     0,  1027,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   218,     0,     0,     0,
       0,     0,     0,     0,     0,    71,     0,   219,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   922,
     924,     0,     0,     0,     0,     0,     0,     0,   998,  1030,
       0,     0,     0,     0,   688,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    76,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1088,  1090,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1105,     0,     0,     0,     0,     0,     0,
      77,     0,    78,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   752,     0,     0,   752,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2032,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   752,     0,   752,     0,   752,
       0,   752,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   995,     0,   755,     0,     0,   755,     0,     0,     0,
     755,     0,     0,     0,     0,     0,     0,     0,   752,     0,
       0,     0,     0,     0,   752,   752,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1268,
       0,     0,     0,     0,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,     0,   106,     0,     0,     0,     0,
       0,   755,     0,     0,     0,   109,   110,   220,   221,   222,
     223,   224,   225,     0,     0,   226,   227,   228,   229,   230,
     231,   232,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   688,   130,   131,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   148,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1362,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   755,     0,  1387,     0,     0,     0,     0,   688,     0,
       0,     0,     0,     0,     0,   755,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1397,
       0,     0,     0,  1400,     0,     0,   755,   755,     0,     0,
       0,     0,     0,     0,   752,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   755,   755,
       0,     0,     0,     0,     0,     0,     0,     0,   752,     0,
       0,     0,     0,  1443,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1105,     0,     0,     0,
       0,     0,     0,  1443,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   755,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   755,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1467,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   755,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     2,   204,   205,  1513,   206,  1516,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1519,     0,
       0,     0,     0,   665,    14,    15,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1491,    25,    26,
     688,     0,     0,    29,    30,     0,     0,    31,     0,    32,
       0,    34,   207,   208,   209,   242,   210,   211,     0,   212,
     213,     0,     0,     0,     0,     0,   214,   215,     0,   216,
     217,     0,     0,     0,     0,     0,     0,   752,     0,   687,
    1527,     0,  1529,  1530,     0,  1591,  1592,     0,     0,  1536,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1551,  1552,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1565,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1579,
    1580,  1581,  1582,  1583,  1626,     0,  1629,     0,    62,    63,
      64,    65,    66,     0,     0,   688,   755,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1606,     0,   218,  1671,
    1672,  1673,     0,  1613,  1614,  1677,     0,    71,     0,   219,
       0,     0,  1684,     0,     0,     0,     0,  1689,     0,  1615,
    1616,  1617,     0,  1619,  1620,     0,  1622,  1623,  1624,  1625,
       0,     0,  1631,     0,  1632,   752,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    76,
       0,     0,     0,     0,     0,   752,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1701,     0,
       0,  1632,    77,   752,    78,     0,   752,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1768,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1782,     0,     0,     0,     0,     0,     0,     0,     0,  1790,
       0,     0,     0,     0,     0,     0,     0,  1753,     0,     0,
       0,     0,     0,   752,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,     0,     0,     0,
       0,     0,     0,     0,     0,   752,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1838,     0,
       0,     0,     0,     0,     0,     0,  1847,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1856,     0,   665,  1859,
       0,     0,     0,     0,  1864,  1865,  1866,  1811,  1867,     0,
       0,     0,  1869,     0,     0,     0,     0,  1821,     0,  1823,
       0,     0,     0,     0,     0,     0,  1830,     0,     0,     0,
       0,  1835,  1836,  1837,     0,  1839,     0,     0,     0,     0,
       0,  1845,     0,     0,  1848,  1849,  1850,  1851,  1852,     0,
       0,     0,     0,     0,   687,     0,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,     0,   106,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   109,   110,   220,
     221,   222,   223,   224,   225,     0,     0,   226,   227,   228,
     229,   230,   231,   232,     0,     0,     0,   755,     0,     0,
     755,     0,     0,     0,     0,     0,     0,     0,     0,   130,
     131,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   148,     0,     0,     0,     0,     0,
     755,     0,   755,     0,   755,     0,   755,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     2,   204,   205,     0,   206,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   755,     0,    14,    15,     0,     0,   755,
     755,     0,     0,     0,     0,     0,     0,     0,     0,    25,
      26,     0,     0,     0,    29,    30,     0,     0,    31,     0,
      32,     0,    34,   207,   208,   209,   242,  1634,   211,     0,
     212,   213,     0,     0,     0,     0,     0,   214,   215,     0,
     216,   217,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2072,     0,     0,     0,
       0,     0,     0,  2076,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2146,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    62,
      63,    64,    65,    66,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2129,     0,     0,     0,     0,   218,
       0,     0,     0,     0,     0,     0,     0,     0,    71,     0,
     219,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2168,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2252,     0,     0,     0,     0,     0,     0,     0,
      76,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    77,     0,    78,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   755,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   755,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2279,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    92,  2284,     0,
       0,     0,     0,  2337,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2304,
    2305,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2330,  2331,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2372,  2374,     0,     0,  2377,     0,  2378,  2380,
    2381,  2382,  2383,  2384,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2362,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,     0,   106,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   109,   110,
     220,   221,   222,   223,   224,   225,     0,     0,   226,   227,
     228,   229,   230,   231,   232,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     130,   131,   755,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   148,     0,     0,     0,     0,
       0,     0,     0,  2408,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     0,     2,   999,  1000,     0,
    1001,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    14,    15,
       0,     0,  1002,   550,  1003,     0,     0,     0,     0,     0,
       0,     0,    25,    26,     0,     0,     0,    29,    30,     0,
     755,    31,     0,    32,     0,    34,   207,   208,   209,   242,
     756,   211,  1004,   237,   213,  1005,     0,   553,     0,     0,
     214,   215,  1006,   216,   217,     0,     0,     0,     0,     0,
     755,     0,     0,  1007,     0,     0,  1008,     0,  2468,  2469,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   755,     0,
       0,   755,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    62,   554,    64,    65,    66,   555,   556,   557,
     558,   559,   560,   561,   562,     0,   563,     0,   564,   565,
     566,   567,   568,   569,   570,     0,   571,   572,   755,     0,
       0,    71,     0,   573,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     755,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,     0,     0,
       0,     0,   587,    76,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,    77,   601,    78,   602,
     603,   604,   605,   606,     0,     0,  2696,  2697,     0,     0,
     607,     0,     0,     0,   974,   975,   976,     0,     0,   608,
     609,   610,   611,   977,   978,   979,   980,   612,     0,     0,
     981,   613,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   614,   615,
     616,   617,     0,     0,     0,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   628,   629,     0,     0,    91,
      92,   982,     0,     0,   983,   984,   985,   986,     0,   987,
     988,   630,   631,  1009,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2776,     0,
    1010,    94,    95,     0,     0,     0,     0,     0,     0,     0,
    2757,     0,     0,  2758,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   632,   633,   634,   635,
      96,  1011,    98,    99,  1012,   101,   102,   103,   104,   105,
       0,   106,     0,   636,   637,     0,  1013,     0,     0,     0,
       0,   109,   110,  1014,  1015,  1016,  1017,  1018,  1019,     0,
       0,  1020,  1021,  1022,  1023,  1024,  1025,  1026,   651,     0,
       0,     0,     0,  2784,     0,  2785,     0,  2786,     0,  2787,
       0,     0,     0,   130,   131,   652,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   653,   654,   655,   656,     0,
     657,   658,     0,   990,   991,   992,   659,   660,     0,   993,
       0,   994,   661,   662,   663,     0,     0,     0,     0,     0,
       1,     0,     2,   999,  1000,     0,  1001,     0,   148,     0,
       0,     0,     0,     0,     0,     0,  2823,     0,     0,     0,
       0,     0,  2828,  2829,    14,    15,     0,     0,   549,   550,
       0,     0,     0,     0,     0,     0,     0,     0,    25,    26,
       0,     0,     0,    29,    30,     0,     0,    31,     0,    32,
       0,    34,   207,   208,   209,   242,   756,   211,   552,   237,
     213,     0,     0,   553,     0,     0,   214,   215,     0,   216,
     217,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    62,   554,
      64,    65,    66,   555,   556,   557,   558,   559,   560,   561,
     562,     0,   563,     0,   564,   565,   566,   567,   568,   569,
     570,     0,   571,   572,     0,     0,     0,    71,     0,   573,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3034,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,     0,     0,     0,     0,   587,    76,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   600,    77,   601,    78,   602,   603,   604,   605,   606,
       0,     0,  3042,     0,     0,     0,   607,     0,     0,     0,
       0,     0,     0,     0,     0,   608,   609,   610,   611,     0,
       0,     0,     0,   612,     0,     0,     0,   613,     0,     0,
       0,     0,     0,     0,     0,     0,  3054,     0,     0,     0,
       0,     0,     0,     0,   614,   615,   616,   617,     0,     0,
       0,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   628,   629,     0,     0,    91,    92,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   630,   631,     0,
       0,     0,     0,     0,     0,  3156,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   632,   633,   634,   635,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,     0,   106,     0,   636,
     637,     0,     0,     0,     0,     0,     0,   109,   110,  1014,
    1015,  1016,  1017,  1018,  1019,     0,     0,  1020,  1021,  1022,
    1023,  1024,  1025,  1026,   651,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  3203,     0,     0,     0,   130,
     131,   652,     0,     0,     0,     0,     0,  3271,     0,     0,
       0,   653,   654,   655,   656,     0,   657,   658,     0,     0,
       0,     0,   659,   660,     0,     0,     0,     0,   661,   662,
     663,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       0,     2,   545,   546,   148,   547,     0,     0,     0,   548,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    14,    15,     0,     0,   549,   550,     0,
       0,     0,     0,     0,     0,     0,     0,    25,    26,     0,
       0,     0,    29,    30,     0,     0,    31,     0,    32,     0,
      34,   207,   208,   209,   242,   551,   211,   552,   212,   213,
    3339,     0,   553,     0,     0,   214,   215,     0,   216,   217,
       0,     0,     0,  3297,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3328,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3347,     0,     0,  3349,     0,     0,    62,   554,    64,
      65,    66,   555,   556,   557,   558,   559,   560,   561,   562,
       0,   563,     0,   564,   565,   566,   567,   568,   569,   570,
       0,   571,   572,     0,     0,     0,    71,     0,   573,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3392,     0,     0,     0,     0,     0,     0,     0,     0,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,  3410,     0,     0,     0,   587,    76,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     600,    77,   601,    78,   602,   603,   604,   605,   606,     0,
       0,     0,     0,     0,     0,   607,     0,     0,     0,     0,
       0,     0,     0,     0,   608,   609,   610,   611,     0,     0,
       0,     0,   612,     0,     0,     0,   613,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   614,   615,   616,   617,     0,     0,     0,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     628,   629,     0,     0,    91,    92,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   630,   631,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   632,   633,   634,   635,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,     0,   106,     0,   636,   637,
       0,     0,     0,     0,     0,     0,   109,   110,   638,   639,
     640,   641,   642,   643,     0,     0,   644,   645,   646,   647,
     648,   649,   650,   651,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   130,   131,
     652,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     653,   654,   655,   656,     0,   657,   658,     0,     0,     0,
       0,   659,   660,     0,     0,     0,     0,   661,   662,   663,
       1,     0,     2,   545,   546,     0,   547,     0,     0,     0,
    1627,     0,     0,   148,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    14,    15,     0,     0,   549,   550,
       0,     0,     0,     0,     0,     0,     0,     0,    25,    26,
       0,     0,     0,    29,    30,     0,     0,    31,     0,    32,
       0,    34,   207,   208,   209,   242,  1628,   211,   552,   212,
     213,     0,     0,   553,     0,     0,   214,   215,     0,   216,
     217,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    62,   554,
      64,    65,    66,   555,   556,   557,   558,   559,   560,   561,
     562,     0,   563,     0,   564,   565,   566,   567,   568,   569,
     570,     0,   571,   572,     0,     0,     0,    71,     0,   573,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,     0,     0,     0,     0,   587,    76,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   600,    77,   601,    78,   602,   603,   604,   605,   606,
       0,     0,     0,     0,     0,     0,   607,     0,     0,     0,
       0,     0,     0,     0,     0,   608,   609,   610,   611,     0,
       0,     0,     0,   612,     0,     0,     0,   613,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   614,   615,   616,   617,     0,     0,
       0,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   628,   629,     0,     0,    91,    92,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   630,   631,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   632,   633,   634,   635,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,     0,   106,     0,   636,
     637,     0,     0,     0,     0,     0,     0,   109,   110,   638,
     639,   640,   641,   642,   643,     0,     0,   644,   645,   646,
     647,   648,   649,   650,   651,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   130,
     131,   652,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   653,   654,   655,   656,     0,   657,   658,     0,     0,
       0,     0,   659,   660,     0,     0,     0,     0,   661,   662,
     663,     1,     0,     2,   545,   546,     0,   547,     0,     0,
       0,     0,     0,     0,   148,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    14,    15,     0,     0,   549,
     550,     0,     0,     0,     0,     0,     0,     0,     0,    25,
      26,     0,     0,     0,    29,    30,     0,     0,    31,     0,
      32,     0,    34,   207,   208,   209,   242,   756,   211,   552,
     212,   213,     0,     0,   553,     0,     0,   214,   215,     0,
     216,   217,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    62,
     554,    64,    65,    66,   555,   556,   557,   558,   559,   560,
     561,   562,     0,   563,     0,   564,   565,   566,   567,   568,
     569,   570,     0,   571,   572,     0,     0,     0,    71,     0,
     573,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,     0,     0,     0,     0,   587,
      76,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   600,    77,   601,    78,   602,   603,   604,   605,
     606,     0,     0,     0,     0,     0,     0,   607,     0,     0,
       0,     0,     0,     0,     0,     0,   608,   609,   610,   611,
       0,     0,     0,     0,   612,     0,     0,     0,   613,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   614,   615,   616,   617,     0,
       0,     0,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   628,   629,     0,     0,    91,    92,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   630,   631,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   632,   633,   634,   635,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,     0,   106,     0,
     636,   637,     0,     0,     0,     0,     0,     0,   109,   110,
     638,   639,   640,   641,   642,   643,     0,     0,   644,   645,
     646,   647,   648,   649,   650,   651,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     130,   131,   652,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   653,   654,   655,   656,     0,   657,   658,     0,
       0,     0,     0,   659,   660,     0,     0,     0,     0,   661,
     662,   663,     1,     0,     2,   999,  1000,     0,  1001,     0,
       0,     0,     0,     0,     0,   148,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    15,     0,     0,
     549,   550,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    32,     0,    34,   207,   208,   209,     0,   756,   211,
     552,   237,   213,     0,     0,   553,     0,     0,   214,   215,
       0,   216,   217,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      62,   554,    64,    65,    66,   555,   556,   557,   558,   559,
     560,   561,   562,     0,   563,     0,   564,   565,   566,   567,
     568,   569,   570,     0,   571,   572,     0,     0,     0,     0,
       0,   573,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,     0,     0,     0,     0,
     587,    76,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599,   600,    77,   601,    78,   602,   603,   604,
     605,   606,     0,     0,     0,     0,     0,     0,   607,     0,
       0,     0,     0,     0,     0,     0,     0,   608,   609,   610,
     611,     0,     0,     0,     0,   612,     0,     0,     0,   613,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   614,   615,   616,   617,
       0,     0,     0,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,     0,     0,    91,    92,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   630,
     631,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    94,
      95,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   632,   633,   634,   635,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,     0,   106,
       0,   636,   637,     0,     0,     0,     0,     0,     0,   109,
     110,  1014,  1015,  1016,  1017,  1018,  1019,     0,     0,  1020,
    1021,  1022,  1023,  1024,  1025,  1026,   651,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   130,   131,   652,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   653,   654,   655,   656,     0,   657,   658,
       0,     0,     0,     0,   659,   660,     0,     0,     0,     0,
     661,   662,   663,     1,     0,     2,   545,   546,     0,   547,
       0,     0,     0,     0,     0,     0,   148,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    15,     0,
       0,   549,   550,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    32,     0,    34,   207,   208,   209,     0,   756,
     211,   552,   212,   213,     0,     0,   553,     0,     0,   214,
     215,     0,   216,   217,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    62,   554,    64,    65,    66,   555,   556,   557,   558,
     559,   560,   561,   562,     0,   563,     0,   564,   565,   566,
     567,   568,   569,   570,     0,   571,   572,     0,     0,     0,
       0,     0,   573,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,     0,     0,     0,
       0,   587,    76,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,    77,   601,    78,   602,   603,
     604,   605,   606,     0,     0,     0,     0,     0,     0,   607,
       0,     0,     0,     0,     0,     0,     0,     0,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,     0,     0,
     613,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   614,   615,   616,
     617,     0,     0,     0,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   628,   629,     0,     0,    91,    92,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     630,   631,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   632,   633,   634,   635,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,     0,
     106,     0,   636,   637,     0,     0,     0,     0,     0,     0,
     109,   110,   638,   639,   640,   641,   642,   643,     0,     0,
     644,   645,   646,   647,   648,   649,   650,   651,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   130,   131,   652,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   653,   654,   655,   656,     0,   657,
     658,     0,     0,     0,     0,   659,   660,     0,     0,     0,
       0,   661,   662,   663,     1,     0,     2,   545,   546,     0,
    1921,     0,     0,     0,     0,     0,     0,   148,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    15,
       0,     0,   549,   550,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    32,     0,    34,   207,   208,   209,     0,
     756,   211,   552,   212,   213,     0,     0,   553,     0,     0,
     214,   215,     0,   216,   217,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    62,   554,    64,    65,    66,   555,   556,   557,
     558,   559,   560,   561,   562,     0,   563,     0,   564,   565,
     566,   567,   568,   569,   570,     0,   571,   572,     0,     0,
       0,     0,     0,   573,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,     0,     0,
       0,     0,   587,    76,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,    77,   601,    78,   602,
     603,   604,   605,   606,     0,     0,     0,     0,     0,     0,
     607,     0,     0,     0,     0,     0,     0,     0,     0,   608,
     609,   610,   611,     0,     0,     0,     0,   612,     0,     0,
       0,   613,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   614,   615,
     616,   617,     0,     0,     0,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   628,   629,     0,     0,    91,
      92,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   630,   631,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   632,   633,   634,   635,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
       0,   106,     0,   636,   637,     0,     0,     0,     0,     0,
       0,   109,   110,   638,   639,   640,   641,   642,   643,     0,
       0,   644,   645,   646,   647,   648,   649,   650,   651,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   130,   131,   652,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   653,   654,   655,   656,     0,
     657,   658,     0,     0,     0,     0,   659,   660,     0,     0,
       0,     0,   661,   662,   663,     1,     0,     2,     3,     4,
       0,     5,     0,     0,     0,     0,     0,     0,   148,     0,
       0,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,     0,     0,     0,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,     0,    29,    30,
       0,     0,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,     0,     0,
      56,    57,    58,    59,     0,    60,    61,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    62,    63,    64,    65,    66,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    67,     0,
       0,     0,     0,    68,     0,     0,     0,     0,     0,     0,
      69,    70,    71,    72,    73,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    74,
      75,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    76,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    77,     0,    78,
       0,     0,     0,     0,     0,    79,    80,    81,    82,    83,
      84,     0,    85,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    86,    87,    88,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    89,    90,
      91,    92,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    93,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    95,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,     0,   106,   107,     0,     1,   108,     0,   732,   733,
       0,   734,   109,   110,   111,   112,   113,   114,   115,   116,
       0,     0,   117,   118,   119,   120,   121,   122,   123,     0,
     124,     0,     0,   549,   550,   125,     0,   126,   127,     0,
       0,     0,   128,   129,   130,   131,     0,   132,     0,     0,
       0,     0,     0,     0,   133,   134,    34,     0,     0,     0,
       0,   735,   211,   552,     0,     0,     0,     0,   553,     0,
       0,   135,     0,     0,   216,   217,   136,   137,     0,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   736,     0,     0,     0,   555,   556,
     557,   558,   559,   560,   561,   562,     0,   563,     0,   564,
     565,   566,   567,   737,   569,   570,     0,   571,   572,     0,
       0,     0,     0,     0,   738,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,     0,
       0,     0,     0,   587,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   598,   599,   600,     0,   601,     0,
     602,   603,   604,   605,   606,     0,     0,     0,     0,     0,
       0,   607,     0,     0,     0,     0,     0,     0,     0,     0,
     608,   609,   610,   611,     0,     0,     0,     0,   612,     0,
       0,     0,   613,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   614,
     615,   616,   617,     0,     0,     0,   618,   619,   620,   621,
     622,   623,   624,   625,   626,   627,   628,   629,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   630,   631,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       0,     0,   732,   733,     0,   734,     0,   632,   633,   634,
     635,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,     0,     0,     0,   636,   637,     0,   549,   550,     0,
       0,     0,     0,     0,   739,   740,   741,   742,   743,   744,
       0,     0,   745,   746,   747,   748,   749,   750,   751,   651,
      34,     0,     0,     0,     0,   735,   211,   552,     0,     0,
       0,     0,   553,     0,     0,     0,   652,     0,   216,   217,
       0,     0,     0,     0,     0,     0,   653,   654,   655,   656,
       0,   657,   658,     0,     0,     0,     0,   659,   660,     0,
       0,     0,     0,   661,   662,   663,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   148,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   736,     0,
       0,     0,   555,   556,   557,   558,   559,   560,   561,   562,
       0,   563,     0,   564,   565,   566,   567,   737,   569,   570,
       0,   571,   572,     0,     0,     0,     0,     0,   738,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,     0,     0,     0,     0,   587,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     600,     0,   601,     0,   602,   603,   604,   605,   606,     0,
       0,     0,     0,     0,     0,   607,     0,     0,     0,     0,
       0,     0,     0,     0,   608,   609,   610,   611,     0,     0,
       0,     0,   612,     0,     0,     0,   613,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   614,   615,   616,   617,     0,     0,     0,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     628,   629,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   630,   631,   997,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,     0,   732,   733,     0,   734,
       0,   632,   633,   634,   635,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   636,   637,
       0,   549,   550,     0,     0,     0,     0,     0,   739,   740,
     741,   742,   743,   744,     0,     0,   745,   746,   747,   748,
     749,   750,   751,   651,    34,     0,     0,     0,     0,   735,
     211,   552,     0,     0,     0,     0,   553,     0,     0,     0,
     652,     0,   216,   217,     0,     0,     0,     0,     0,     0,
     653,   654,   655,   656,     0,   657,   658,     0,     0,     0,
       0,   659,   660,     0,     0,     0,     0,   661,   662,   663,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   148,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   736,     0,     0,     0,   555,   556,   557,   558,
     559,   560,   561,   562,     0,   563,     0,   564,   565,   566,
     567,   737,   569,   570,     0,   571,   572,     0,     0,     0,
       0,     0,   738,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,     0,   601,     0,   602,   603,
     604,   605,   606,     0,     0,     0,     0,     0,     0,   607,
       0,     0,     0,     0,     0,     0,     0,     0,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,     0,     0,
     613,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   614,   615,   616,
     617,     0,     0,     0,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   628,   629,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     630,   631,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     0,     0,
     732,   733,     0,  2074,     0,   632,   633,   634,   635,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   636,   637,     0,   549,   550,     0,     0,     0,
       0,     0,   739,   740,   741,   742,   743,   744,     0,     0,
     745,   746,   747,   748,   749,   750,   751,   651,    34,     0,
       0,     0,     0,   735,   211,   552,     0,     0,     0,     0,
     553,     0,     0,     0,   652,     0,   216,   217,     0,     0,
       0,     0,     0,     0,   653,   654,   655,   656,     0,   657,
     658,     0,     0,     0,     0,   659,   660,     0,     0,     0,
       0,   661,   662,   663,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   148,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   736,     0,     0,     0,
     555,   556,   557,   558,   559,   560,   561,   562,     0,   563,
       0,   564,   565,   566,   567,   737,   569,   570,     0,   571,
     572,     0,     0,     0,     0,     0,   738,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   600,     0,
     601,     0,   602,   603,   604,   605,   606,     0,     0,     0,
       0,     0,     0,   607,     0,     0,     0,     0,     0,     0,
       0,     0,   608,   609,   610,   611,     0,     0,     0,     0,
     612,     0,     0,     0,   613,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   614,   615,   616,   617,     0,     0,     0,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   628,   629,
       0,     0,     0,     0,     0,     0,     1,     0,     2,     3,
       4,     0,     5,     0,   630,   631,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    32,     0,    34,   207,   208,
     209,     0,   210,   211,     0,   237,   213,     0,     0,     0,
       0,     0,   214,   215,     0,   216,   217,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   632,
     633,   634,   635,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   636,   637,     0,     0,
       0,     0,     0,     0,     0,     0,   739,   740,   741,   742,
     743,   744,     0,     0,   745,   746,   747,   748,   749,   750,
     751,   651,     0,     0,    62,    63,    64,    65,    66,     0,
       0,     0,     0,     1,     0,     2,   204,   205,   652,  1039,
       0,     0,     0,     0,   218,     0,     0,     0,   653,   654,
     655,   656,     0,   657,   658,   219,     0,     0,    15,   659,
     660,     0,     0,     0,     0,   661,   662,   663,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   148,    32,     0,    34,   207,   208,   209,     0,   210,
     211,     0,   212,   213,     0,     0,     0,     0,     0,   214,
     215,     0,   216,   217,     0,    76,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    77,     0,
      78,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    62,    63,    64,    65,    66,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   218,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   219,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    92,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    76,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    95,    77,     0,    78,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,     0,   106,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   109,   110,   111,   112,   113,   114,   115,
     116,     0,     0,   117,   118,   119,   120,   121,   122,   123,
       0,     0,     0,     0,     0,     0,     0,     0,    91,    92,
       0,     0,     0,     0,     0,   130,   131,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     148,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,     0,
     106,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     109,   110,   220,   221,   222,   223,   224,   225,     0,     0,
     226,   227,   228,   229,   230,   231,   232,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   130,   131,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   148
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
         0,    47,   386,   290,   449,    50,    23,     0,   422,   423,
       7,   395,   462,    10,    11,    57,    13,    34,    31,    54,
     545,   546,    22,    23,   424,   425,   426,   427,    58,    22,
     444,   445,    45,    46,    64,   144,    64,    50,    51,    37,
      42,    54,    20,     0,    52,    58,    76,    77,    76,    62,
      19,    52,    53,     7,     5,     6,   239,   240,   241,    22,
      20,    52,    19,    15,    77,    13,    21,    65,   123,    66,
       5,     6,    64,    57,    13,    19,    21,    75,    58,    22,
      19,    19,   128,    50,    76,    14,     5,    71,    13,   144,
      57,    48,    19,   239,   240,   241,    13,    77,   281,    13,
      13,    15,    15,    13,   150,    19,    19,    19,   291,   292,
      42,    43,   158,   638,   639,   640,   641,   642,   643,   644,
     645,   646,   647,   648,   649,   650,   651,   127,    19,    14,
      58,    13,    19,    23,    13,    63,    54,    19,    20,    19,
      58,   666,    20,    13,    34,   291,   292,    58,    13,    77,
     150,    58,    13,    58,    58,   347,   348,   150,    19,    77,
      13,   174,   140,   141,   133,   134,    77,   124,    57,   177,
      77,   123,    77,    77,   137,   144,   133,   134,   186,   221,
     140,   141,   137,   239,  2880,  2881,  2882,   138,   139,   143,
      49,    50,   137,   150,   137,   186,   123,   239,    57,   382,
     383,   384,   385,   138,   139,   144,   144,   732,   733,   401,
     123,   140,   141,   221,   739,   740,   741,   742,   743,   744,
     745,   746,   747,   748,   749,   750,   751,   752,   229,   230,
     221,   144,   144,   292,   269,   270,   382,   383,   384,   385,
     242,    19,   133,   134,   124,   125,   133,   134,   248,   277,
     278,   279,    19,   144,   221,   140,   141,   144,   286,   287,
     288,   289,   140,   141,   171,   293,   171,   171,    13,   239,
     240,   241,   239,   273,    54,    15,   276,    59,    58,   279,
      62,    13,    58,    59,    60,   285,   286,   206,    64,   289,
     290,    23,    13,   286,    15,    13,   296,    77,   298,   158,
      76,    77,    34,     7,     8,    13,   334,    14,    12,   337,
     338,   339,   340,    20,   342,   343,    23,    13,   346,   319,
     320,   291,   322,   382,   383,   384,   385,   302,   303,   304,
     305,   306,   307,   308,   309,   310,    19,    14,    58,    59,
      60,    14,   388,    20,    64,    22,    23,    20,   348,   349,
      23,   351,   352,    13,    14,   390,    76,    77,    13,    19,
     353,    54,   221,    13,    57,   411,    19,   476,    13,    19,
      20,   413,   347,    14,    19,    68,    69,    70,    13,    20,
     239,    19,    23,   242,   243,   244,   245,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   396,  3093,   443,  3095,
      19,   443,  3098,  3099,    13,   403,    15,   404,   405,    13,
      19,   545,   546,    13,    14,   274,   275,   276,    13,    19,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
      10,    11,    13,   390,    15,    13,   436,   437,    13,    20,
     440,    13,    13,    15,    13,    14,   413,    19,    19,   449,
      19,    13,    14,   483,   454,   455,   449,    19,   458,   456,
     457,   458,   459,   460,   461,   482,    13,   464,   465,   466,
     467,   468,   469,   470,   999,  1000,   443,    14,   506,   507,
     508,    13,    14,    20,   512,    13,   514,    19,    13,  1014,
    1015,  1016,  1017,  1018,  1019,  1020,  1021,  1022,  1023,  1024,
    1025,  1026,    13,  1028,   638,   639,   640,   641,   642,   643,
     644,   645,   646,   647,   648,   649,   650,   651,   450,   451,
     452,   453,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   666,    13,   531,    14,    13,    13,   538,    15,
    3236,    20,    19,    17,    14,    14,    14,    14,   407,   408,
      20,    20,    20,    20,   413,    31,    14,    14,  1232,  1233,
    1234,  1235,    20,    20,     2,     3,     4,   426,    13,    45,
      46,    14,     4,    14,    50,    51,    13,    20,    54,    20,
      13,    16,    58,    14,   443,    14,    62,    22,    14,    20,
      14,    20,    13,    13,    20,    15,    20,    14,   732,   733,
      13,    77,    13,    20,    15,   739,   740,   741,   742,   743,
     744,   745,   746,   747,   748,   749,   750,   751,   752,    14,
      31,    14,   140,   141,    14,    20,    14,    20,   547,  1074,
      20,    14,    20,    13,    45,    46,    13,    20,    15,    50,
      51,     3,     4,    54,    90,    13,    92,    58,    94,    14,
      96,    62,    98,    99,    13,    20,   102,   103,   104,   105,
     106,   107,   108,   109,    14,    13,    77,    15,   114,    13,
      20,   168,    13,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,    14,    14,    14,    14,
      14,    14,    20,    20,    20,    20,    20,    20,   174,    13,
      13,    15,  1227,  1228,  1229,  1230,  1231,  1232,  1233,  1234,
    1235,  1236,  1237,  1238,  1239,  1240,  1241,  1242,   490,   491,
     492,   493,   494,    13,   221,   222,   223,   224,   166,   729,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,    14,   490,   491,   492,   493,   494,    20,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,    14,   174,    14,    14,   204,   205,    20,    14,
      20,    20,    14,    14,    14,    20,    10,    11,    20,    20,
      20,    13,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,    14,    14,    20,    14,
      22,    14,    20,    20,   166,    20,    13,    20,    14,    13,
      13,    15,    14,    13,    20,   734,  1230,  1231,    20,   865,
      14,     0,  1109,    14,    31,    14,    20,   873,    20,    20,
      22,    20,  1232,  1233,  1234,  1235,  1236,  1237,    45,    46,
     140,   141,    14,    50,    51,    13,    41,    54,    20,    18,
      14,    58,    14,    14,    14,    62,    20,    14,    20,    20,
      20,    14,   862,    20,    13,   999,  1000,    20,    14,    14,
      77,    14,    14,    14,    20,    20,    13,    20,    20,    20,
    1014,  1015,  1016,  1017,  1018,  1019,  1020,  1021,  1022,  1023,
    1024,  1025,  1026,    13,  1028,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,    14,    31,    14,
      14,    14,    13,    20,   142,    20,    20,    20,    10,    11,
     136,     4,    45,    46,     7,     8,    19,    50,    51,   223,
     224,    54,   223,   224,    19,    58,   451,   452,    13,    62,
     229,   230,    10,    11,   140,   141,    19,   174,   347,   348,
      52,    53,   428,   429,    77,  1230,  1231,  1361,  1236,  1237,
    1364,   419,   420,   421,    15,   413,   414,    19,    15,   444,
     445,    19,  1517,    19,    19,    14,    14,    14,    19,   449,
     346,    15,    54,    54,   442,    55,    63,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    54,    80,  1045,   177,    20,  1048,  1049,
    1050,  1051,  1052,  1053,    14,  1055,  1056,    14,    50,    14,
    1060,  1061,  1062,  1063,  1064,  1065,  1066,  1517,  1068,    20,
    1070,   174,  1072,  1073,    14,  1075,  1076,  1077,  1078,  1079,
     442,   443,  1001,    14,  1084,  1085,  1086,  1087,   377,    13,
      13,    13,    13,  1227,  1228,  1229,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,  1106,   545,   546,  1109,
    1110,    13,    13,    13,    13,    13,    13,    13,    13,   408,
     409,   410,   411,   412,    13,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,    13,    13,    13,
      13,    13,    31,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    45,    46,    13,    13,
      13,    50,    51,    20,   144,    54,    13,  1454,    19,    58,
      19,    13,    13,    62,  1699,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,  1104,    13,    13,    77,    13,
      13,    13,    13,    13,    19,    13,    13,    13,  1244,    13,
     638,   639,   640,   641,   642,   643,   644,   645,   646,   647,
     648,   649,   650,   502,    19,   410,    19,    13,    13,    13,
      13,    13,  1222,    13,  1224,  1225,    13,    13,   666,    13,
      13,   520,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,  1248,  1694,
      13,    13,    13,    13,  1254,    13,    13,    13,    13,  1259,
      13,  1261,  1262,    13,  1264,  1265,  1266,  1267,    13,    13,
    1270,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,  1284,   174,    13,    13,    13,    13,
      13,    13,    13,  1293,    13,  1295,  1296,  1297,    13,    13,
      13,    19,  1302,  1303,  1304,  1305,  1306,  1307,  1308,    13,
    1310,    13,    13,    13,    13,    18,    13,   136,    13,    17,
    1320,  1321,  1322,  1323,  1324,  1325,  1326,  1327,  1328,  1329,
    1330,  1331,  1332,  1333,  1334,    19,    13,    13,    13,    13,
    1340,  1341,  1342,  1343,  1344,  1345,  1346,    13,    13,    13,
      13,    13,  1352,  1353,    13,  1355,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    56,    56,    14,
      16,    15,    63,  1373,    16,  1375,    13,    20,    19,    19,
      14,  1381,  1382,  1383,    19,    14,    16,    20,    14,    14,
    1390,  1391,  1392,  1393,  1394,  1395,  1396,    16,  1398,  1399,
      14,  1401,  1402,  1403,  1404,  1405,  1406,    14,  1408,  1409,
    1410,  1411,  1412,  1413,  1414,  1415,    16,    31,  1418,    20,
    1420,  1421,    13,  1423,  1424,  1425,    13,    13,    13,    13,
      13,    45,    46,    13,    13,    13,    50,    51,    13,    13,
      54,    13,    13,    13,    58,    13,    13,    13,    62,    13,
    1450,  1451,    13,    13,  1454,    13,  1456,    13,  1458,  1459,
      13,    13,    13,    77,    13,    13,    13,    13,  1468,    13,
      13,    13,    13,    13,    13,    13,    13,    13,   840,   841,
      13,    13,   844,   845,   846,   847,   848,   849,   850,   851,
     852,   853,   854,   855,   856,   857,    13,    23,    13,    20,
      14,    14,    20,    19,    16,    31,    65,    14,    34,    20,
      20,    20,    20,  2038,    20,    20,    20,    20,    20,    45,
      46,    14,    20,    20,    50,    51,    20,    14,    54,    14,
      20,    14,    58,    14,    14,    14,    62,    14,    13,    13,
      71,    14,    20,    65,    20,    13,    13,    16,    20,    20,
      20,    77,   349,    13,   351,    13,   353,   354,    13,    13,
     174,   999,  1000,    15,   361,    13,    13,   364,   365,   366,
     367,   368,   369,   370,   371,    13,  1014,  1015,  1016,  1017,
    1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,    13,
    1028,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,   402,    13,    13,    13,   406,
      13,    13,    13,    13,   411,   412,    13,    13,    13,    13,
      13,    13,    13,    13,    13,   422,    13,    13,    13,    13,
     427,   428,    13,    13,    13,    13,    13,   999,  1000,    13,
      13,    13,    13,     7,    13,     9,    10,    11,   174,    13,
      13,    13,  1014,  1015,  1016,  1017,  1018,  1019,  1020,  1021,
    1022,  1023,  1024,  1025,  1026,    13,  1028,    31,    32,    13,
      13,    13,    19,    13,    13,    13,    13,    13,    13,    20,
      13,    45,    46,    12,    16,    19,    50,    51,    16,    14,
      54,    14,    56,   221,    58,    59,    60,    61,    62,    63,
      64,   221,    66,    67,   505,    59,    61,    60,    60,    73,
      74,    62,    76,    77,    71,   144,    62,    62,   144,    16,
      14,    71,    13,   347,    13,  1771,  1772,   177,   178,   179,
     180,   181,   182,   183,   184,   185,    13,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,    13,    20,
      75,  2145,   473,    20,    14,    13,    20,    20,   144,  1769,
    2154,    20,  2156,   223,   224,    14,    20,    20,    14,    20,
     281,   145,   146,   147,   148,   149,    14,    14,    14,  1789,
    1228,  1229,    57,    57,    57,    14,    20,    20,    20,    20,
      20,   165,    14,    20,    20,    20,    20,    14,    14,    20,
     174,    20,   176,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    14,    14,    20,    20,    20,    20,    14,
      19,    14,   226,    20,    20,    14,    20,    14,    14,    14,
      14,    14,    20,  1873,  1874,  1875,  1876,    19,  1878,    20,
    1880,    20,    20,    20,    20,    14,  1886,  1887,  1888,    20,
      20,  1891,  1892,  1893,  1894,   259,  1896,   261,  1898,    20,
    1900,    20,    20,  1903,  1904,  1905,  1906,    20,    20,    20,
    1910,    20,    20,  1913,    20,    20,    14,    20,    13,    20,
      20,    20,    13,    13,  1924,    57,  1926,    14,    20,    14,
    1930,  1931,    20,  1933,  1934,  1935,  1936,  1937,  1938,  1939,
    1940,  1941,  1942,  1943,  1944,    20,  1946,    20,    20,    20,
      20,    20,    20,    14,    14,  1955,  1956,  1957,  1958,  1959,
    1960,  1961,  1962,  1963,    20,    14,    20,    20,   332,   333,
      20,    14,    20,    20,    20,    20,    20,  1977,  1978,  1979,
    1980,    20,    20,    20,  1984,  1985,  1986,  1987,    20,    20,
      20,    20,    20,    20,  1994,  1995,  1996,  1997,  1998,  1999,
    2000,  2001,  2002,  2003,  2004,    20,    14,    14,    20,    20,
      20,    20,  2012,  2013,  2014,    20,  2016,  2017,    20,  2019,
    2020,    20,    20,  2023,    20,  2025,    20,    20,    20,    20,
      14,    14,    14,    14,    14,    14,  2036,    14,    57,  2039,
     404,   405,    20,    14,    20,    20,    20,  2047,  2048,  2049,
      20,    20,    20,    13,  2054,    20,    14,    14,    20,    13,
    2060,    16,    13,  2063,  2064,    13,  2066,  2067,  2068,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,    13,
     444,    13,  2082,    14,  2084,    14,    14,    20,    14,    14,
     454,   455,   456,   457,   458,   459,   460,   461,  2098,    20,
     464,   465,   466,   467,   468,   469,   470,    20,    20,    20,
      20,    20,    20,  2113,    20,  2115,    20,    20,    20,    20,
    2120,    20,   486,   487,    14,    16,  2126,    14,    20,   443,
    2130,  2131,    14,  2133,  2134,  2135,    14,  2137,  2138,    20,
      14,  2141,  2142,    14,  2144,    14,    14,    14,    14,    14,
     239,   240,   241,   242,    14,    14,    14,  2157,  2158,    14,
      14,  2161,    14,  2163,  2164,  2165,    14,   531,    14,    20,
      20,  2171,    14,    14,  2174,    14,  2176,    14,    14,    14,
    2180,  2181,  2182,   272,  2184,    14,    14,    14,    14,    14,
    2190,   280,    14,  2193,    13,  2195,    20,  2197,  2198,  2199,
      20,    14,   291,    14,    14,    14,   295,   401,  2208,  2209,
      14,    14,  2212,    20,    14,    14,    14,  2217,  2218,  2219,
    2220,  2221,  2222,    20,  2224,  2225,  2226,    14,  2228,  2229,
    2230,  2231,  2232,    14,    20,  2235,  2236,  2237,  2238,    14,
    2240,    20,    20,    20,    20,    14,    20,    20,    20,   338,
      20,   340,   341,   342,  2638,    20,    20,    20,    20,    14,
      20,    20,   351,   352,    20,    14,    14,    14,   357,   358,
     359,   360,    14,    14,    20,    20,    20,    20,    14,    14,
    2280,    14,    14,   372,   373,   374,   375,   376,    14,   378,
     379,    14,   381,    20,    14,    20,    20,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,    20,    14,    14,    14,    14,    14,    14,    14,
      14,   144,   474,    14,    14,    54,    14,    20,    20,    14,
      14,    20,    71,    20,    20,    75,    54,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    14,    20,    20,    20,
      20,    16,    16,    14,    14,    22,    14,    16,    20,    14,
      14,    14,    14,    20,    14,    14,    14,    14,    14,    20,
     150,    14,  1371,  2419,  2420,    20,    20,    14,    20,    20,
    2426,    14,    20,    14,    14,    14,    14,    22,    20,    14,
      16,    57,   144,    20,  2394,    14,    20,    20,    20,    20,
      20,    14,    20,    20,    20,    14,    14,    14,    20,    20,
      20,    14,    14,    14,    20,    20,    14,    14,  2418,    14,
      20,    20,   511,    57,    20,   431,    20,    20,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    20,   150,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    14,    20,
      20,    20,    20,    20,    14,    20,    14,    20,    14,    14,
      14,    20,    14,    20,    14,    14,    14,    20,    14,    14,
      14,    22,    14,    20,    14,    14,  2476,    20,  2478,    20,
    2480,    14,  2482,    14,    14,    20,    20,  2487,  2488,    14,
    2490,  2491,  2492,  2493,    20,  2495,  2496,  2497,  2498,    20,
      20,    20,  2502,    14,    20,  2505,  2506,    20,    14,    14,
      14,  2511,    20,    20,    14,    14,  2516,    14,  2518,  2519,
    2520,  2521,  2522,  2523,  2524,  2525,    20,  2527,  2528,  2529,
    2530,  2531,  2532,  2533,  2534,  2535,  2536,  2537,  2538,  2539,
    2540,    20,  2542,    14,    14,    14,    14,    14,    14,    14,
    2550,    14,    14,    54,  2554,  2555,    20,    14,    14,    20,
      14,    14,    20,    14,  2564,  2565,    14,    14,    20,    14,
      20,    20,    14,    57,  2574,  2575,  2576,  2577,  2578,    20,
    2580,  2581,    20,  2583,  2584,    20,    20,  2506,  2588,  2589,
    2509,    20,    20,  2593,  2594,  2595,  2596,    20,    20,    20,
      14,    20,    57,    20,    20,    14,  1238,    20,  2608,    20,
      20,    57,    20,    20,  2614,    20,    20,    14,  2618,    20,
    2620,  2621,    20,    22,    20,    20,    20,    20,    20,    20,
    2630,  2631,  2632,    20,    14,  2635,  2636,    20,    20,    20,
      14,    20,    14,    14,    14,    14,    14,    20,  2648,    14,
    2650,    14,  2652,  2653,    20,  2655,  2656,  2657,  2658,  2659,
    2660,  2661,  2662,    20,  2664,  2665,  2666,  2667,  2668,  2669,
    2670,  2671,  2672,    20,  2674,  2675,  2676,  2677,    20,    20,
      20,    20,    14,    20,    14,    20,    20,    14,  2688,  2689,
    2690,  2691,    20,    14,  2694,  2695,    20,    20,    20,    14,
      20,    20,    20,    20,    20,    14,    19,   150,    20,    20,
      20,    14,    20,    20,    20,    20,    20,   150,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    14,    20,    20,
      20,    20,    20,    14,    20,    20,    14,    14,    14,    14,
      20,    20,  1242,    14,   150,  1240,    20,    20,    20,  2795,
      20,    20,    20,    20,    20,    14,    20,    14,    20,    14,
      20,    14,    20,    14,    20,    14,    14,    14,    20,   432,
      20,    14,    14,   150,    20,    20,    20,    14,    14,    20,
      20,    20,    20,    14,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    14,   150,  1379,   435,
    1239,  1241,    14,    20,    20,    20,    20,    20,    14,    14,
      20,    14,    20,    20,    14,    14,    20,    14,    20,    14,
     434,    14,    20,    14,    20,    14,    20,    14,    20,    14,
      20,    14,    20,  2038,  2834,  2835,    20,  2837,  2838,    20,
    2840,  2841,    20,  2843,  2844,  2845,    20,  2847,  2848,    20,
      20,  2851,    20,    20,    20,    20,  2856,  2857,    20,  2859,
      20,  2861,    20,  2863,    14,  2865,  2866,  2867,  2868,  2869,
      22,    14,    20,  2873,  2874,  2875,  2876,  2877,  2878,    20,
    2880,  2881,  2882,  2883,  2884,  2885,  2886,    20,  2888,  2889,
    2890,  2891,  2892,    20,  2894,    20,    20,    20,    20,  2899,
    2900,    20,  2902,  2903,  2904,  2905,  2906,  2907,    20,  2909,
    2910,  2911,  2912,    14,  2914,    14,    14,    14,  2918,    14,
    2920,    14,  2922,   433,    20,  2925,    20,  2927,  2928,    20,
    2930,  2850,    20,    14,    14,  2854,    14,  2937,    20,  2939,
      14,    14,  2942,  2943,    20,    20,    14,   430,    20,    20,
      20,    20,    14,    14,    20,    22,    20,    14,  2958,  2959,
    2960,  2961,  2962,    14,    20,    20,    20,    20,  2968,  2969,
    2970,    20,    20,    20,    20,    20,    14,    20,    20,    14,
      14,    20,    14,    14,    14,    14,    14,    14,  1226,    14,
      -1,    14,    14,    -1,    20,    14,    20,    14,    14,    20,
      14,    14,    20,    14,    14,    14,    -1,    14,    20,    14,
      -1,    14,    20,    -1,    20,    14,    20,  1081,    20,    -1,
      20,    22,    20,    20,    20,    20,    20,    20,    14,    20,
      20,    20,    20,    20,    14,    20,    14,    20,    14,    20,
      14,    20,    14,    20,    14,    20,    14,    20,    14,    20,
      14,    20,    14,    20,    -1,    20,    14,    20,  3058,    20,
      20,  3061,  3062,  3063,    20,    20,    20,  3067,    20,  3069,
    3070,    20,    14,    14,    14,  3075,  3076,    14,  3078,    14,
    3080,  3081,  3082,  3083,  3084,  3085,    20,  3087,  3088,  3089,
    3090,  3091,  3092,  3093,    20,  3095,    20,    14,  3098,  3099,
    3100,  3101,  3102,    14,    20,    20,    20,    14,  3108,  3109,
      20,    20,  3112,    14,    20,    20,  3116,  3117,  3118,    14,
      20,  3121,    14,    20,    20,    14,    20,  3127,  3128,    14,
      20,  3131,  3132,    20,    14,  3135,    20,  3137,  3138,    20,
      14,  3141,  3142,    20,  3144,    14,  3146,  3147,  3148,    20,
      20,    14,    20,    20,    20,  3074,    20,    14,    20,    20,
      20,    14,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3208,  3209,
    3210,  3211,    -1,  3213,  3214,    -1,    -1,  3217,    -1,    -1,
      -1,    -1,    -1,    -1,  3224,    -1,  3226,    -1,  3228,    -1,
      -1,  3231,    -1,    -1,    -1,    -1,  3236,    -1,    -1,    -1,
      -1,  3241,  3242,    -1,  3244,    -1,  3246,    -1,  3248,  3249,
    3250,    -1,  3252,  3253,    -1,  3255,    -1,  3257,    -1,  3259,
    3260,  3261,    -1,    -1,  3264,  3265,  3266,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3303,    -1,    -1,    -1,  3307,  3308,    -1,
      -1,    -1,  3312,    -1,  3314,  3315,    -1,  3317,  3318,    -1,
      -1,    -1,  3322,    -1,    -1,  3325,  3326,  3327,    -1,  3329,
    3330,    -1,  3332,  3333,    -1,    -1,  3336,  3337,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3359,
      -1,    -1,    -1,    -1,    -1,  3365,  3366,  3367,    -1,    -1,
      -1,  3371,  3372,    -1,    -1,  3375,  3376,    -1,    -1,  3379,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3393,  3394,    -1,  3396,    -1,  3398,    -1,
      -1,  3401,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3411,    -1,  3413,  3414,  3415,    -1,     0,    -1,     2,
       3,     4,  3422,  3423,  3424,    -1,    -1,    -1,    -1,  3429,
    3430,  3431,    -1,    -1,    -1,    18,  3436,  3437,    21,    -1,
    3440,    24,    -1,    -1,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,    -1,    -1,    -1,    -1,   128,   129,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   150,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   204,   205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   247,    -1,   249,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   266,   267,    -1,   269,   270,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   280,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   289,   290,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   321,   322,
     323,   324,   325,   326,   327,   328,   329,    -1,    -1,    -1,
      -1,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,    -1,    -1,    -1,    -1,   350,   351,    -1,
      -1,   354,   355,   356,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   390,   391,    -1,
      -1,    -1,    -1,    -1,   397,    -1,   399,   400,   401,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     413,   414,   415,   416,    -1,    -1,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   439,   440,    -1,   442,
      -1,   444,   445,    -1,     0,   448,   449,    -1,    -1,    -1,
      -1,     7,    -1,     9,    10,    11,    -1,    13,    -1,   462,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    50,    51,    -1,    -1,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    -1,    -1,    82,    83,    84,    85,
      -1,    87,    88,    -1,    -1,    -1,   539,    -1,    -1,    -1,
      -1,    -1,   545,   546,   547,   548,   549,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,   165,
      -1,    -1,    -1,    -1,    -1,    -1,   172,   173,   174,   175,
     176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   638,   639,   640,   641,   642,
     643,   644,   645,   646,   647,   648,   649,   650,   651,    -1,
      -1,    -1,    -1,    -1,    -1,   211,   212,    -1,    -1,    -1,
      -1,    -1,    -1,   666,    -1,    -1,    -1,    -1,    -1,    -1,
     226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   259,    -1,   261,    -1,    -1,    -1,    -1,
      -1,   267,   268,   269,   270,   271,   272,    -1,   274,    -1,
      -1,    -1,   725,    -1,    -1,    -1,    -1,    -1,    -1,   732,
     733,   734,    -1,    -1,    -1,    -1,   739,   740,   741,   742,
     743,   744,   745,   746,   747,   748,   749,   750,   751,   752,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   315,
     316,   317,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   330,   331,   332,   333,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   380,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   404,   405,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     863,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,    -1,   444,   445,
      -1,    -1,   448,    -1,    -1,    -1,    -1,    -1,   454,   455,
     456,   457,   458,   459,   460,   461,   909,    -1,   464,   465,
     466,   467,   468,   469,   470,    -1,   472,    -1,    -1,    -1,
      -1,   477,    -1,   479,   480,    -1,    -1,    -1,   484,   485,
     486,   487,   935,   489,    -1,    -1,   939,    -1,    -1,    -1,
     496,   497,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   513,    -1,    -1,
      -1,    -1,   518,   519,    -1,   521,   522,   523,   524,   525,
     526,   527,   528,   529,   530,   531,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   989,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   999,  1000,  1001,  1002,
      -1,    -1,    -1,    -1,    -1,    -1,  1009,    -1,    -1,    -1,
      -1,  1014,  1015,  1016,  1017,  1018,  1019,  1020,  1021,  1022,
    1023,  1024,  1025,  1026,    -1,  1028,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1041,    -1,
      -1,    -1,    -1,    -1,    -1,  1048,    -1,    -1,    -1,    -1,
      -1,  1054,    -1,    -1,  1057,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1067,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1091,    -1,
    1093,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1104,    -1,    -1,    -1,    -1,  1109,  1110,  1111,  1112,
    1113,  1114,  1115,  1116,  1117,  1118,  1119,  1120,  1121,  1122,
    1123,  1124,    -1,  1126,  1127,  1128,  1129,    -1,  1131,  1132,
    1133,    -1,    -1,  1136,  1137,  1138,  1139,  1140,  1141,  1142,
    1143,  1144,  1145,  1146,  1147,  1148,  1149,  1150,  1151,  1152,
    1153,  1154,  1155,  1156,  1157,  1158,  1159,  1160,  1161,  1162,
    1163,  1164,  1165,  1166,  1167,  1168,    -1,    -1,  1171,  1172,
    1173,  1174,  1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,
    1183,  1184,  1185,  1186,  1187,  1188,  1189,  1190,  1191,  1192,
    1193,  1194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1209,  1210,  1211,  1212,
    1213,  1214,    -1,  1216,  1217,  1218,  1219,  1220,    -1,  1222,
      -1,  1224,  1225,  1226,  1227,  1228,  1229,  1230,  1231,  1232,
    1233,  1234,  1235,  1236,  1237,  1238,  1239,  1240,  1241,  1242,
      -1,    -1,  1245,  1246,  1247,    -1,    -1,    -1,  1251,    -1,
      -1,    -1,    -1,    -1,    -1,  1258,    -1,    -1,    -1,    -1,
    1263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1278,    -1,    -1,  1281,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1292,
      -1,  1294,    -1,    -1,    -1,  1298,  1299,  1300,  1301,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1309,    -1,  1311,  1312,
    1313,  1314,  1315,  1316,  1317,  1318,  1319,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1335,    -1,  1337,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1347,  1348,  1349,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1358,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1376,  1377,  1378,    -1,    -1,    -1,    -1,
      -1,    -1,  1385,  1386,    -1,  1388,  1389,  1390,  1391,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1407,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1416,  1417,    -1,  1419,    -1,    -1,  1422,
      -1,    -1,    -1,  1426,  1427,    -1,    -1,    -1,  1431,  1432,
    1433,  1434,  1435,  1436,    -1,  1438,    -1,    -1,  1441,  1442,
      -1,  1444,  1445,  1446,  1447,  1448,    -1,    -1,    -1,  1452,
      -1,  1454,  1455,    -1,    -1,    -1,    -1,  1460,  1461,  1462,
      -1,  1464,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1517,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     0,    -1,    -1,     3,     4,     5,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1627,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1696,    -1,    -1,  1699,    -1,    -1,    -1,
    1703,  1704,  1705,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1754,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1770,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1789,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   286,    -1,
      -1,   289,   290,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1868,    -1,    -1,    -1,  1872,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1884,  1885,   321,   322,   323,   324,   325,   326,   327,
     328,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   336,   337,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1912,
      -1,  1914,    -1,    -1,    -1,   353,    -1,   355,  1921,    -1,
      -1,    -1,    -1,    -1,    -1,  1928,  1929,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1947,  1948,  1949,  1950,  1951,  1952,
    1953,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1967,    -1,  1969,  1970,  1971,  1972,
    1973,    -1,  1975,  1976,    -1,    -1,    -1,    -1,  1981,  1982,
      -1,    -1,    -1,    -1,    -1,  1988,  1989,    -1,    -1,  1992,
    1993,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   439,   440,    -1,   442,   443,   444,   445,    -1,    -1,
     448,   449,    -1,    -1,    -1,  2018,    -1,    -1,  2021,    -1,
      -1,    -1,    -1,  2026,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2038,    -1,  2040,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2052,
      -1,    -1,  2055,  2056,  2057,  2058,  2059,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2074,    -1,    -1,    -1,    -1,    -1,  2080,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2101,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   545,   546,   547,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2133,    -1,    -1,    -1,    -1,    -1,  2139,  2140,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2160,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     638,   639,   640,   641,   642,   643,   644,   645,   646,   647,
     648,   649,   650,   651,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   666,    -1,
      -1,    -1,    -1,    -1,    -1,  2238,  2239,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   732,   733,   734,    -1,    -1,    -1,
      -1,   739,   740,   741,   742,   743,   744,   745,   746,   747,
     748,   749,   750,   751,   752,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   840,   841,   842,    -1,   844,   845,   846,   847,
     848,   849,   850,   851,   852,   853,   854,   855,   856,   857,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2472,
    2473,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2505,    -1,    -1,    -1,  2509,  2510,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2527,  2528,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,    -1,    -1,
    2543,  2544,  2545,  2546,  2547,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    -1,  2560,    -1,    -1,
    2563,   999,  1000,  1001,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1014,  1015,  1016,  1017,
    1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,    -1,
    1028,    -1,    -1,    -1,    -1,    -1,     7,    -1,     9,    10,
      11,  2604,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2617,    -1,    -1,    -1,    -1,    -1,
    2623,    32,  2625,    -1,  2627,    -1,  2629,    -1,    -1,  1067,
    2633,  2634,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,  2649,    58,    59,    60,
      61,    -1,    63,    64,    -1,    66,    67,    -1,    -1,    -1,
      -1,    -1,    73,    74,    -1,    76,    77,    -1,    -1,    -1,
      -1,  1109,  1110,    -1,  1112,  1113,    -1,  2680,    -1,    -1,
      -1,  1119,    -1,  2686,    -1,    -1,    -1,   150,    -1,  2692,
    2693,    -1,    -1,  1131,  1132,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1145,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1159,  1160,  1161,  1162,  1163,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   145,   146,   147,   148,   149,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1186,    -1,
      -1,    -1,    -1,    -1,   165,  1193,  1194,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   176,    -1,    -1,    -1,    -1,
      -1,  1209,  1210,  1211,    -1,  1213,  1214,    -1,  1216,  1217,
    1218,  1219,    -1,    -1,  1222,    -1,  1224,    -1,  1226,  1227,
    1228,  1229,  1230,  1231,  1232,  1233,  1234,  1235,  1236,  1237,
    1238,  1239,  1240,  1241,  1242,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,
     283,   284,    -1,    -1,    -1,    -1,   289,   290,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1278,    -1,    -1,  1281,    -1,    -1,    -1,  2850,   259,    -1,
     261,  2854,    -1,    -1,    -1,    -1,    -1,    -1,   321,   322,
     323,   324,   325,   326,   327,   328,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   336,   337,    -1,    -1,  2880,  2881,  2882,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2893,    -1,   355,    -1,    -1,    -1,    -1,    -1,    -1,  1337,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2916,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   332,   333,    -1,    -1,    -1,    -1,    -1,    -1,  2932,
    2933,    -1,    -1,    -1,    -1,  2938,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2966,    -1,    -1,    -1,    -1,    -1,  1407,
      -1,    -1,    -1,    -1,    -1,    -1,   439,   440,    -1,  1417,
      -1,  1419,    -1,    -1,   447,   448,   449,    -1,  1426,    -1,
      -1,    -1,    -1,  1431,  1432,  1433,    -1,  1435,    -1,    -1,
      -1,    -1,    -1,  1441,    -1,    -1,  1444,  1445,  1446,  1447,
    1448,    -1,    -1,    -1,    -1,    -1,  1454,    -1,    -1,    -1,
      -1,    -1,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,    -1,   444,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   454,   455,   456,   457,   458,   459,   460,
     461,    -1,    -1,   464,   465,   466,   467,   468,   469,   470,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3071,    -1,
      -1,  3074,    -1,    -1,    -1,   486,   487,    -1,    -1,  1517,
      -1,    -1,   545,   546,   547,   548,    -1,    -1,    -1,    -1,
    3093,    -1,  3095,    -1,    -1,  3098,  3099,    -1,    -1,    -1,
    3103,  3104,  3105,  3106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     531,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3134,    -1,  3136,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   638,   639,   640,   641,   642,
     643,   644,   645,   646,   647,   648,   649,   650,   651,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   666,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3236,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3254,    -1,  3256,    -1,    -1,    -1,    -1,  1696,    -1,
    3263,  1699,    -1,    -1,    -1,  1703,    -1,    -1,    -1,   732,
     733,   734,    -1,    -1,    -1,    -1,   739,   740,   741,   742,
     743,   744,   745,   746,   747,   748,   749,   750,   751,   752,
    3293,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3306,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1754,    -1,  3321,    -1,
      -1,  3324,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1789,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3373,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3381,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3399,    -1,    -1,    -1,
    3403,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1914,    -1,    -1,    -1,
      -1,    -1,    -1,  1921,    -1,    -1,    -1,    -1,    -1,    -1,
    1928,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1949,  1950,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   999,  1000,  1001,    -1,
      -1,    -1,    -1,  1981,  1982,    -1,    -1,    -1,    -1,    -1,
      -1,  1014,  1015,  1016,  1017,  1018,  1019,  1020,  1021,  1022,
    1023,  1024,  1025,  1026,    -1,  1028,    22,    23,    24,    -1,
      -1,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2026,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
    2038,    -1,    -1,    -1,  1067,    -1,    -1,    -1,    -1,    -1,
      -1,  1074,    -1,    -1,    -1,    -1,    -1,  1080,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2074,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1109,  1110,    -1,  1112,
    1113,    -1,    -1,    -1,    -1,    -1,  1119,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1131,  1132,
      -1,    -1,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2133,  1159,  1160,  1161,  1162,
    1163,    -1,    -1,    -1,    -1,    -1,  1169,  1170,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1186,    -1,    -1,    -1,    -1,    -1,    -1,
    1193,  1194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1209,  1210,  1211,    -1,
    1213,  1214,    -1,  1216,  1217,  1218,  1219,    -1,    -1,  1222,
      -1,  1224,    -1,  1226,  1227,  1228,  1229,  1230,  1231,  1232,
    1233,  1234,  1235,  1236,  1237,  1238,  1239,  1240,  1241,  1242,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   247,    -1,   249,    -1,    -1,    -1,    -1,    -1,    -1,
    2238,  2239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     266,   267,    -1,    -1,    -1,  1278,    -1,    -1,  1281,    -1,
      -1,    -1,    -1,    -1,   280,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   289,   290,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,
       9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,  1337,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,   289,
     290,    50,    51,    -1,    -1,    54,    -1,    56,   354,    58,
      59,    60,    61,    62,    63,    64,    -1,    66,    67,    -1,
      -1,    -1,    -1,    -1,    73,    74,    -1,    76,    77,    -1,
      -1,   321,   322,   323,   324,   325,   326,   327,   328,    -1,
      -1,    -1,    -1,    -1,    -1,   391,   336,   337,    -1,    -1,
      -1,   397,    -1,    -1,  1407,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1417,   355,  1419,    -1,    -1,   415,
     416,    -1,    -1,  1426,    -1,  1428,  1429,  1430,  1431,  1432,
    1433,    -1,  1435,    -1,  1437,    -1,  1439,  1440,  1441,    -1,
      -1,  1444,  1445,  1446,  1447,  1448,   145,   146,   147,   148,
     149,  1454,    -1,   449,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   165,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   174,    -1,   176,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   439,
     440,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   448,   449,
      -1,    -1,    -1,    -1,  1517,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   538,   539,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   549,    -1,    -1,    -1,    -1,    -1,    -1,
     259,    -1,   261,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2560,    -1,    -1,  2563,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1627,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   332,   333,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2623,    -1,  2625,    -1,  2627,
      -1,  2629,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1694,    -1,  1696,    -1,    -1,  1699,    -1,    -1,    -1,
    1703,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2686,    -1,
      -1,    -1,    -1,    -1,  2692,  2693,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   725,
      -1,    -1,    -1,    -1,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,    -1,   444,    -1,    -1,    -1,    -1,
      -1,  1754,    -1,    -1,    -1,   454,   455,   456,   457,   458,
     459,   460,   461,    -1,    -1,   464,   465,   466,   467,   468,
     469,   470,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1789,   486,   487,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   531,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   863,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1914,    -1,   909,    -1,    -1,    -1,    -1,  1921,    -1,
      -1,    -1,    -1,    -1,    -1,  1928,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   935,
      -1,    -1,    -1,   939,    -1,    -1,  1949,  1950,    -1,    -1,
      -1,    -1,    -1,    -1,  2932,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1981,  1982,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2966,    -1,
      -1,    -1,    -1,   989,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1002,    -1,    -1,    -1,
      -1,    -1,    -1,  1009,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2026,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2038,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1041,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2074,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       7,    -1,     9,    10,    11,  1091,    13,  1093,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1104,    -1,
      -1,    -1,    -1,  1109,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1067,    45,    46,
    2133,    -1,    -1,    50,    51,    -1,    -1,    54,    -1,    56,
      -1,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    -1,    -1,    -1,    -1,    -1,    73,    74,    -1,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,  3145,    -1,  1109,
    1110,    -1,  1112,  1113,    -1,  1171,  1172,    -1,    -1,  1119,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1131,  1132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1145,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1159,
    1160,  1161,  1162,  1163,  1220,    -1,  1222,    -1,   145,   146,
     147,   148,   149,    -1,    -1,  2238,  2239,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1186,    -1,   165,  1245,
    1246,  1247,    -1,  1193,  1194,  1251,    -1,   174,    -1,   176,
      -1,    -1,  1258,    -1,    -1,    -1,    -1,  1263,    -1,  1209,
    1210,  1211,    -1,  1213,  1214,    -1,  1216,  1217,  1218,  1219,
      -1,    -1,  1222,    -1,  1224,  3263,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,
      -1,    -1,    -1,    -1,    -1,  3293,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1278,    -1,
      -1,  1281,   259,  3321,   261,    -1,  3324,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1358,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1376,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1385,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1337,    -1,    -1,
      -1,    -1,    -1,  3381,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   332,   333,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3403,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1434,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1442,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1452,    -1,  1454,  1455,
      -1,    -1,    -1,    -1,  1460,  1461,  1462,  1407,  1464,    -1,
      -1,    -1,  1468,    -1,    -1,    -1,    -1,  1417,    -1,  1419,
      -1,    -1,    -1,    -1,    -1,    -1,  1426,    -1,    -1,    -1,
      -1,  1431,  1432,  1433,    -1,  1435,    -1,    -1,    -1,    -1,
      -1,  1441,    -1,    -1,  1444,  1445,  1446,  1447,  1448,    -1,
      -1,    -1,    -1,    -1,  1454,    -1,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,    -1,   444,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   454,   455,   456,
     457,   458,   459,   460,   461,    -1,    -1,   464,   465,   466,
     467,   468,   469,   470,    -1,    -1,    -1,  2560,    -1,    -1,
    2563,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   486,
     487,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   531,    -1,    -1,    -1,    -1,    -1,
    2623,    -1,  2625,    -1,  2627,    -1,  2629,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     7,    -1,     9,    10,    11,    -1,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2686,    -1,    31,    32,    -1,    -1,  2692,
    2693,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    -1,    -1,    -1,    50,    51,    -1,    -1,    54,    -1,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    -1,
      66,    67,    -1,    -1,    -1,    -1,    -1,    73,    74,    -1,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1696,    -1,    -1,    -1,
      -1,    -1,    -1,  1703,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1770,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1754,    -1,    -1,    -1,    -1,   165,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,    -1,
     176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1789,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1868,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   259,    -1,   261,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2932,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2966,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1914,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   332,   333,  1928,    -1,
      -1,    -1,    -1,  1989,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1949,
    1950,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1981,  1982,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2048,  2049,    -1,    -1,  2052,    -1,  2054,  2055,
    2056,  2057,  2058,  2059,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2026,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,    -1,   444,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   454,   455,
     456,   457,   458,   459,   460,   461,    -1,    -1,   464,   465,
     466,   467,   468,   469,   470,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     486,   487,  3145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   531,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2133,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     7,    -1,     9,    10,    11,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
      -1,    -1,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    -1,    -1,    -1,    50,    51,    -1,
    3263,    54,    -1,    56,    -1,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    -1,    -1,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
    3293,    -1,    -1,    86,    -1,    -1,    89,    -1,  2238,  2239,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3321,    -1,
      -1,  3324,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,    -1,   159,    -1,   161,   162,
     163,   164,   165,   166,   167,    -1,   169,   170,  3381,    -1,
      -1,   174,    -1,   176,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3403,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,    -1,    -1,
      -1,    -1,   225,   226,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,    -1,    -1,  2472,  2473,    -1,    -1,
     273,    -1,    -1,    -1,   277,   278,   279,    -1,    -1,   282,
     283,   284,   285,   286,   287,   288,   289,   290,    -1,    -1,
     293,   294,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   311,   312,
     313,   314,    -1,    -1,    -1,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,    -1,    -1,   332,
     333,   334,    -1,    -1,   337,   338,   339,   340,    -1,   342,
     343,   344,   345,   346,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2604,    -1,
     403,   404,   405,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2560,    -1,    -1,  2563,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
      -1,   444,    -1,   446,   447,    -1,   449,    -1,    -1,    -1,
      -1,   454,   455,   456,   457,   458,   459,   460,   461,    -1,
      -1,   464,   465,   466,   467,   468,   469,   470,   471,    -1,
      -1,    -1,    -1,  2623,    -1,  2625,    -1,  2627,    -1,  2629,
      -1,    -1,    -1,   486,   487,   488,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   498,   499,   500,   501,    -1,
     503,   504,    -1,   506,   507,   508,   509,   510,    -1,   512,
      -1,   514,   515,   516,   517,    -1,    -1,    -1,    -1,    -1,
       7,    -1,     9,    10,    11,    -1,    13,    -1,   531,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2686,    -1,    -1,    -1,
      -1,    -1,  2692,  2693,    31,    32,    -1,    -1,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      -1,    -1,    -1,    50,    51,    -1,    -1,    54,    -1,    56,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    -1,    70,    -1,    -1,    73,    74,    -1,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,    -1,   159,    -1,   161,   162,   163,   164,   165,   166,
     167,    -1,   169,   170,    -1,    -1,    -1,   174,    -1,   176,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2916,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,    -1,    -1,    -1,    -1,   225,   226,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
      -1,    -1,  2932,    -1,    -1,    -1,   273,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   282,   283,   284,   285,    -1,
      -1,    -1,    -1,   290,    -1,    -1,    -1,   294,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2966,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   311,   312,   313,   314,    -1,    -1,
      -1,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,    -1,    -1,   332,   333,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   344,   345,    -1,
      -1,    -1,    -1,    -1,    -1,  3071,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   404,   405,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,    -1,   444,    -1,   446,
     447,    -1,    -1,    -1,    -1,    -1,    -1,   454,   455,   456,
     457,   458,   459,   460,   461,    -1,    -1,   464,   465,   466,
     467,   468,   469,   470,   471,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3145,    -1,    -1,    -1,   486,
     487,   488,    -1,    -1,    -1,    -1,    -1,  3213,    -1,    -1,
      -1,   498,   499,   500,   501,    -1,   503,   504,    -1,    -1,
      -1,    -1,   509,   510,    -1,    -1,    -1,    -1,   515,   516,
     517,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,
      -1,     9,    10,    11,   531,    13,    -1,    -1,    -1,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    -1,    -1,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,
      -1,    -1,    50,    51,    -1,    -1,    54,    -1,    56,    -1,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
    3306,    -1,    70,    -1,    -1,    73,    74,    -1,    76,    77,
      -1,    -1,    -1,  3263,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3293,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3321,    -1,    -1,  3324,    -1,    -1,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
      -1,   159,    -1,   161,   162,   163,   164,   165,   166,   167,
      -1,   169,   170,    -1,    -1,    -1,   174,    -1,   176,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3381,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,  3403,    -1,    -1,    -1,   225,   226,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,    -1,
      -1,    -1,    -1,    -1,    -1,   273,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   282,   283,   284,   285,    -1,    -1,
      -1,    -1,   290,    -1,    -1,    -1,   294,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   311,   312,   313,   314,    -1,    -1,    -1,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,    -1,    -1,   332,   333,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   344,   345,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,    -1,   444,    -1,   446,   447,
      -1,    -1,    -1,    -1,    -1,    -1,   454,   455,   456,   457,
     458,   459,   460,   461,    -1,    -1,   464,   465,   466,   467,
     468,   469,   470,   471,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   486,   487,
     488,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     498,   499,   500,   501,    -1,   503,   504,    -1,    -1,    -1,
      -1,   509,   510,    -1,    -1,    -1,    -1,   515,   516,   517,
       7,    -1,     9,    10,    11,    -1,    13,    -1,    -1,    -1,
      17,    -1,    -1,   531,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      -1,    -1,    -1,    50,    51,    -1,    -1,    54,    -1,    56,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    -1,    70,    -1,    -1,    73,    74,    -1,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,    -1,   159,    -1,   161,   162,   163,   164,   165,   166,
     167,    -1,   169,   170,    -1,    -1,    -1,   174,    -1,   176,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,    -1,    -1,    -1,    -1,   225,   226,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
      -1,    -1,    -1,    -1,    -1,    -1,   273,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   282,   283,   284,   285,    -1,
      -1,    -1,    -1,   290,    -1,    -1,    -1,   294,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   311,   312,   313,   314,    -1,    -1,
      -1,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,    -1,    -1,   332,   333,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   344,   345,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,    -1,   444,    -1,   446,
     447,    -1,    -1,    -1,    -1,    -1,    -1,   454,   455,   456,
     457,   458,   459,   460,   461,    -1,    -1,   464,   465,   466,
     467,   468,   469,   470,   471,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   486,
     487,   488,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   498,   499,   500,   501,    -1,   503,   504,    -1,    -1,
      -1,    -1,   509,   510,    -1,    -1,    -1,    -1,   515,   516,
     517,     7,    -1,     9,    10,    11,    -1,    13,    -1,    -1,
      -1,    -1,    -1,    -1,   531,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    -1,    -1,    -1,    50,    51,    -1,    -1,    54,    -1,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    -1,    70,    -1,    -1,    73,    74,    -1,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,    -1,   159,    -1,   161,   162,   163,   164,   165,
     166,   167,    -1,   169,   170,    -1,    -1,    -1,   174,    -1,
     176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,    -1,    -1,    -1,    -1,   225,
     226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,    -1,    -1,    -1,    -1,    -1,    -1,   273,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   282,   283,   284,   285,
      -1,    -1,    -1,    -1,   290,    -1,    -1,    -1,   294,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   311,   312,   313,   314,    -1,
      -1,    -1,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,    -1,    -1,   332,   333,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   344,   345,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,    -1,   444,    -1,
     446,   447,    -1,    -1,    -1,    -1,    -1,    -1,   454,   455,
     456,   457,   458,   459,   460,   461,    -1,    -1,   464,   465,
     466,   467,   468,   469,   470,   471,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     486,   487,   488,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   498,   499,   500,   501,    -1,   503,   504,    -1,
      -1,    -1,    -1,   509,   510,    -1,    -1,    -1,    -1,   515,
     516,   517,     7,    -1,     9,    10,    11,    -1,    13,    -1,
      -1,    -1,    -1,    -1,    -1,   531,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    58,    59,    60,    61,    -1,    63,    64,
      65,    66,    67,    -1,    -1,    70,    -1,    -1,    73,    74,
      -1,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,    -1,   159,    -1,   161,   162,   163,   164,
     165,   166,   167,    -1,   169,   170,    -1,    -1,    -1,    -1,
      -1,   176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,    -1,    -1,    -1,    -1,
     225,   226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,    -1,    -1,    -1,    -1,    -1,    -1,   273,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   282,   283,   284,
     285,    -1,    -1,    -1,    -1,   290,    -1,    -1,    -1,   294,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   311,   312,   313,   314,
      -1,    -1,    -1,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,    -1,    -1,   332,   333,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   344,
     345,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   404,
     405,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,    -1,   444,
      -1,   446,   447,    -1,    -1,    -1,    -1,    -1,    -1,   454,
     455,   456,   457,   458,   459,   460,   461,    -1,    -1,   464,
     465,   466,   467,   468,   469,   470,   471,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   486,   487,   488,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   498,   499,   500,   501,    -1,   503,   504,
      -1,    -1,    -1,    -1,   509,   510,    -1,    -1,    -1,    -1,
     515,   516,   517,     7,    -1,     9,    10,    11,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,   531,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,
      -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    -1,    58,    59,    60,    61,    -1,    63,
      64,    65,    66,    67,    -1,    -1,    70,    -1,    -1,    73,
      74,    -1,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,    -1,   159,    -1,   161,   162,   163,
     164,   165,   166,   167,    -1,   169,   170,    -1,    -1,    -1,
      -1,    -1,   176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,    -1,    -1,    -1,
      -1,   225,   226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,    -1,    -1,    -1,    -1,    -1,    -1,   273,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   282,   283,
     284,   285,    -1,    -1,    -1,    -1,   290,    -1,    -1,    -1,
     294,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   311,   312,   313,
     314,    -1,    -1,    -1,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,    -1,    -1,   332,   333,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     344,   345,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,    -1,
     444,    -1,   446,   447,    -1,    -1,    -1,    -1,    -1,    -1,
     454,   455,   456,   457,   458,   459,   460,   461,    -1,    -1,
     464,   465,   466,   467,   468,   469,   470,   471,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   486,   487,   488,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   498,   499,   500,   501,    -1,   503,
     504,    -1,    -1,    -1,    -1,   509,   510,    -1,    -1,    -1,
      -1,   515,   516,   517,     7,    -1,     9,    10,    11,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,   531,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    -1,    58,    59,    60,    61,    -1,
      63,    64,    65,    66,    67,    -1,    -1,    70,    -1,    -1,
      73,    74,    -1,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,    -1,   159,    -1,   161,   162,
     163,   164,   165,   166,   167,    -1,   169,   170,    -1,    -1,
      -1,    -1,    -1,   176,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,    -1,    -1,
      -1,    -1,   225,   226,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,    -1,    -1,    -1,    -1,    -1,    -1,
     273,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   282,
     283,   284,   285,    -1,    -1,    -1,    -1,   290,    -1,    -1,
      -1,   294,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   311,   312,
     313,   314,    -1,    -1,    -1,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,    -1,    -1,   332,
     333,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   344,   345,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
      -1,   444,    -1,   446,   447,    -1,    -1,    -1,    -1,    -1,
      -1,   454,   455,   456,   457,   458,   459,   460,   461,    -1,
      -1,   464,   465,   466,   467,   468,   469,   470,   471,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   486,   487,   488,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   498,   499,   500,   501,    -1,
     503,   504,    -1,    -1,    -1,    -1,   509,   510,    -1,    -1,
      -1,    -1,   515,   516,   517,     7,    -1,     9,    10,    11,
      -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,   531,    -1,
      -1,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      -1,    -1,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    -1,    -1,
      82,    83,    84,    85,    -1,    87,    88,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,    -1,
      -1,    -1,    -1,   165,    -1,    -1,    -1,    -1,    -1,    -1,
     172,   173,   174,   175,   176,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   211,
     212,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   259,    -1,   261,
      -1,    -1,    -1,    -1,    -1,   267,   268,   269,   270,   271,
     272,    -1,   274,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   315,   316,   317,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   330,   331,
     332,   333,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   380,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   404,   405,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,    -1,   444,   445,    -1,     7,   448,    -1,    10,    11,
      -1,    13,   454,   455,   456,   457,   458,   459,   460,   461,
      -1,    -1,   464,   465,   466,   467,   468,   469,   470,    -1,
     472,    -1,    -1,    35,    36,   477,    -1,   479,   480,    -1,
      -1,    -1,   484,   485,   486,   487,    -1,   489,    -1,    -1,
      -1,    -1,    -1,    -1,   496,   497,    58,    -1,    -1,    -1,
      -1,    63,    64,    65,    -1,    -1,    -1,    -1,    70,    -1,
      -1,   513,    -1,    -1,    76,    77,   518,   519,    -1,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   146,    -1,    -1,    -1,   150,   151,
     152,   153,   154,   155,   156,   157,    -1,   159,    -1,   161,
     162,   163,   164,   165,   166,   167,    -1,   169,   170,    -1,
      -1,    -1,    -1,    -1,   176,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,    -1,
      -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,   260,    -1,
     262,   263,   264,   265,   266,    -1,    -1,    -1,    -1,    -1,
      -1,   273,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     282,   283,   284,   285,    -1,    -1,    -1,    -1,   290,    -1,
      -1,    -1,   294,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   311,
     312,   313,   314,    -1,    -1,    -1,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   344,   345,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,
      -1,    -1,    10,    11,    -1,    13,    -1,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,    -1,    -1,    -1,   446,   447,    -1,    35,    36,    -1,
      -1,    -1,    -1,    -1,   456,   457,   458,   459,   460,   461,
      -1,    -1,   464,   465,   466,   467,   468,   469,   470,   471,
      58,    -1,    -1,    -1,    -1,    63,    64,    65,    -1,    -1,
      -1,    -1,    70,    -1,    -1,    -1,   488,    -1,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,   498,   499,   500,   501,
      -1,   503,   504,    -1,    -1,    -1,    -1,   509,   510,    -1,
      -1,    -1,    -1,   515,   516,   517,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   531,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,    -1,
      -1,    -1,   150,   151,   152,   153,   154,   155,   156,   157,
      -1,   159,    -1,   161,   162,   163,   164,   165,   166,   167,
      -1,   169,   170,    -1,    -1,    -1,    -1,    -1,   176,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,    -1,    -1,    -1,    -1,   225,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,    -1,   260,    -1,   262,   263,   264,   265,   266,    -1,
      -1,    -1,    -1,    -1,    -1,   273,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   282,   283,   284,   285,    -1,    -1,
      -1,    -1,   290,    -1,    -1,    -1,   294,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   311,   312,   313,   314,    -1,    -1,    -1,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   344,   345,   346,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     7,    -1,    -1,    10,    11,    -1,    13,
      -1,   429,   430,   431,   432,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   446,   447,
      -1,    35,    36,    -1,    -1,    -1,    -1,    -1,   456,   457,
     458,   459,   460,   461,    -1,    -1,   464,   465,   466,   467,
     468,   469,   470,   471,    58,    -1,    -1,    -1,    -1,    63,
      64,    65,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,
     488,    -1,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
     498,   499,   500,   501,    -1,   503,   504,    -1,    -1,    -1,
      -1,   509,   510,    -1,    -1,    -1,    -1,   515,   516,   517,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   531,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   146,    -1,    -1,    -1,   150,   151,   152,   153,
     154,   155,   156,   157,    -1,   159,    -1,   161,   162,   163,
     164,   165,   166,   167,    -1,   169,   170,    -1,    -1,    -1,
      -1,    -1,   176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,    -1,    -1,    -1,
      -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,    -1,   260,    -1,   262,   263,
     264,   265,   266,    -1,    -1,    -1,    -1,    -1,    -1,   273,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   282,   283,
     284,   285,    -1,    -1,    -1,    -1,   290,    -1,    -1,    -1,
     294,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   311,   312,   313,
     314,    -1,    -1,    -1,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     344,   345,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,    -1,
      10,    11,    -1,    13,    -1,   429,   430,   431,   432,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   446,   447,    -1,    35,    36,    -1,    -1,    -1,
      -1,    -1,   456,   457,   458,   459,   460,   461,    -1,    -1,
     464,   465,   466,   467,   468,   469,   470,   471,    58,    -1,
      -1,    -1,    -1,    63,    64,    65,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,   488,    -1,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,   498,   499,   500,   501,    -1,   503,
     504,    -1,    -1,    -1,    -1,   509,   510,    -1,    -1,    -1,
      -1,   515,   516,   517,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   531,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   146,    -1,    -1,    -1,
     150,   151,   152,   153,   154,   155,   156,   157,    -1,   159,
      -1,   161,   162,   163,   164,   165,   166,   167,    -1,   169,
     170,    -1,    -1,    -1,    -1,    -1,   176,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,    -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,    -1,
     260,    -1,   262,   263,   264,   265,   266,    -1,    -1,    -1,
      -1,    -1,    -1,   273,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   282,   283,   284,   285,    -1,    -1,    -1,    -1,
     290,    -1,    -1,    -1,   294,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   311,   312,   313,   314,    -1,    -1,    -1,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
      -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,     9,    10,
      11,    -1,    13,    -1,   344,   345,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    -1,    58,    59,    60,
      61,    -1,    63,    64,    -1,    66,    67,    -1,    -1,    -1,
      -1,    -1,    73,    74,    -1,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   429,
     430,   431,   432,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   446,   447,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   456,   457,   458,   459,
     460,   461,    -1,    -1,   464,   465,   466,   467,   468,   469,
     470,   471,    -1,    -1,   145,   146,   147,   148,   149,    -1,
      -1,    -1,    -1,     7,    -1,     9,    10,    11,   488,    13,
      -1,    -1,    -1,    -1,   165,    -1,    -1,    -1,   498,   499,
     500,   501,    -1,   503,   504,   176,    -1,    -1,    32,   509,
     510,    -1,    -1,    -1,    -1,   515,   516,   517,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   531,    56,    -1,    58,    59,    60,    61,    -1,    63,
      64,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    73,
      74,    -1,    76,    77,    -1,   226,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   259,    -1,
     261,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   332,   333,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   404,   405,   259,    -1,   261,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,    -1,   444,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   454,   455,   456,   457,   458,   459,   460,
     461,    -1,    -1,   464,   465,   466,   467,   468,   469,   470,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   332,   333,
      -1,    -1,    -1,    -1,    -1,   486,   487,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     531,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,    -1,
     444,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     454,   455,   456,   457,   458,   459,   460,   461,    -1,    -1,
     464,   465,   466,   467,   468,   469,   470,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   486,   487,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   531
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
     173,   174,   175,   176,   211,   212,   226,   259,   261,   267,
     268,   269,   270,   271,   272,   274,   315,   316,   317,   330,
     331,   332,   333,   380,   404,   405,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   444,   445,   448,   454,
     455,   456,   457,   458,   459,   460,   461,   464,   465,   466,
     467,   468,   469,   470,   472,   477,   479,   480,   484,   485,
     486,   487,   489,   496,   497,   513,   518,   519,   521,   522,
     523,   524,   525,   526,   527,   528,   529,   530,   531,   533,
     534,   535,   536,   537,   538,   541,   542,   543,   544,   548,
     549,   550,   551,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   595,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   615,   616,    10,    11,    13,    59,    60,    61,
      63,    64,    66,    67,    73,    74,    76,    77,   165,   176,
     456,   457,   458,   459,   460,   461,   464,   465,   466,   467,
     468,   469,   470,   558,   559,   574,   613,    66,   559,   599,
     559,   599,    62,   572,   573,   574,   612,    13,    13,    13,
     483,   574,   613,    54,    68,    69,    70,   615,   574,   551,
     572,   612,   551,   572,   551,   574,    13,    13,   551,    13,
      13,   133,   134,   144,   133,   134,   144,   133,   134,   144,
     144,    19,    19,   124,   125,    13,   144,    19,   144,    13,
      13,   535,   615,   239,    19,    19,    15,   123,    15,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    69,    71,
      72,    73,    74,    75,    76,    77,   574,   616,   551,    13,
      13,    13,    13,    15,    13,    13,    15,    13,    15,    13,
      19,    19,    19,    19,    13,    13,    13,    15,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,   559,   599,   559,
     599,   559,   599,   559,   599,   559,   599,   559,   599,   559,
     599,   559,   599,   559,   599,   559,   599,   559,   599,   559,
     599,   559,   599,   615,   552,   553,   572,   535,   551,   551,
      13,    13,    13,    71,   615,   615,    13,    13,    13,    13,
      13,    13,     0,     0,   535,   536,   537,   538,   541,   542,
     543,   544,   535,    10,    11,   140,   141,   559,   599,     7,
       8,    12,    10,    11,     5,     6,   138,   139,   140,   141,
      17,     4,    18,   136,    21,   137,    13,    15,    19,   123,
     144,   142,     7,   143,    10,    11,    19,   123,   123,   144,
      19,    19,    19,    19,    15,    15,    19,    19,    13,    19,
      19,    14,    14,    19,    14,   551,   572,   551,    19,   551,
     551,    76,   616,   616,   572,   572,   572,   551,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   377,   408,   409,   410,   411,   412,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   502,   520,   349,   351,   353,   354,   361,   364,   365,
     366,   367,   368,   369,   370,   371,   402,   406,   411,   412,
     422,   427,   428,   613,   613,   572,   572,   612,    42,    43,
     450,   451,   452,   453,   449,    10,    11,    13,    17,    35,
      36,    63,    65,    70,   146,   150,   151,   152,   153,   154,
     155,   156,   157,   159,   161,   162,   163,   164,   165,   166,
     167,   169,   170,   176,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   225,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   260,   262,   263,   264,   265,   266,   273,   282,   283,
     284,   285,   290,   294,   311,   312,   313,   314,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     344,   345,   429,   430,   431,   432,   446,   447,   456,   457,
     458,   459,   460,   461,   464,   465,   466,   467,   468,   469,
     470,   471,   488,   498,   499,   500,   501,   503,   504,   509,
     510,   515,   516,   517,   546,   551,   558,   572,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   613,   546,
      41,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   410,    42,   242,   572,   346,   572,    15,
     572,   572,    10,    11,    13,    63,   146,   165,   176,   456,
     457,   458,   459,   460,   461,   464,   465,   466,   467,   468,
     469,   470,   558,   574,   593,   613,    63,   572,   593,   593,
     593,   593,   593,   593,   593,   574,   168,   221,   222,   223,
     224,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   223,   224,   223,   224,   223,   224,   574,
     574,   574,   593,   593,   574,   574,   574,   574,   574,   574,
     574,   574,    54,    54,   572,   572,   574,   572,   574,   572,
      10,    11,    13,    66,   456,   457,   458,   459,   460,   461,
     464,   465,   466,   467,   468,   469,   470,   558,   612,   551,
     593,   574,   144,   476,    55,   552,   535,   615,   616,   551,
      54,   540,   539,   552,   572,   551,    63,   574,   574,   574,
     535,   549,   549,   551,   551,   559,   559,   559,   560,   560,
     562,   562,   562,   562,   563,   563,   564,   565,   566,   567,
     569,   568,   572,   572,    49,    50,   158,   221,   239,   242,
     243,   244,   245,   274,   275,   276,   407,   408,   413,   426,
     443,   615,   593,   572,   593,   559,   599,   599,   560,   600,
     560,   600,   239,   240,   241,   242,   272,   280,   291,   295,
     338,   340,   341,   342,   351,   352,   357,   358,   359,   360,
     372,   373,   374,   375,   376,   378,   379,   381,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   511,   277,   278,   279,   286,   287,   288,
     289,   293,   334,   337,   338,   339,   340,   342,   343,   346,
     506,   507,   508,   512,   514,   613,   614,   346,   593,    10,
      11,    13,    35,    37,    65,    68,    75,    86,    89,   346,
     403,   434,   437,   449,   456,   457,   458,   459,   460,   461,
     464,   465,   466,   467,   468,   469,   470,   551,   558,   572,
     593,   594,   612,   613,   614,    80,   572,   572,   572,    13,
     557,    20,    14,    14,    14,    20,    14,    14,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    20,   551,   572,
     551,    13,    13,    13,   574,   578,   579,   579,   573,   593,
      59,    60,   574,   613,    13,   551,    13,    19,    19,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    19,    13,    13,    13,    13,
      19,    13,    13,    13,    19,    19,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,   579,   579,   579,   579,   579,
     579,   579,   579,   579,   579,   579,   579,   579,   579,    13,
      13,    13,    13,    13,    13,    19,    13,    13,    13,    13,
      13,    14,    20,   579,    13,    15,   144,     4,     7,     8,
      10,    11,     5,     6,   138,   139,   140,   141,    17,    18,
     136,    21,   137,    19,    14,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,   551,    16,
      15,    16,   572,    14,    20,   573,   574,    19,    13,    19,
      19,    13,    14,    19,    20,    14,    16,    14,    14,    16,
      14,    16,    20,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    20,    14,    20,    14,    16,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      14,    14,    20,    20,    14,    20,    14,    14,    20,    14,
     572,   545,   551,   554,   482,   535,    14,    14,    14,    14,
      13,    13,   535,    20,    14,    20,    20,    20,    20,    22,
      14,    20,    22,    23,    16,    13,    13,   551,    13,    13,
      13,    13,    13,    13,    13,    13,    13,   551,    13,    13,
     551,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,   551,    13,    13,    13,    13,    13,    19,
      15,    15,    13,    19,    13,    13,    15,    13,    13,    13,
      13,    20,    20,    19,    13,    16,    16,   551,    12,   572,
     572,   574,   572,   572,   572,   572,   572,   574,   572,   572,
      63,   574,    56,    63,   572,   572,   572,   572,   572,   572,
     572,   593,   572,    65,   572,    71,   572,   572,   614,   572,
     572,   572,   572,   572,   613,    65,   594,    65,    56,   572,
     572,   572,   572,   551,    59,    62,   551,    14,    14,   551,
     573,   574,   572,   347,   347,   348,   546,   593,   574,   593,
     593,   574,   574,   574,   574,   574,   593,   574,   574,   574,
     574,   574,    52,    53,   574,   574,   574,   574,    52,   186,
     221,   593,   593,   574,   221,   221,   574,   574,   574,   574,
     574,   574,   574,   574,   574,   593,   574,   574,   574,   574,
     574,   574,   574,   574,   574,   574,   574,   574,   574,   593,
     593,   593,   593,   593,   574,   574,   574,   574,   574,   613,
     613,   551,   551,   574,   574,   574,   574,   574,   574,   574,
     574,   574,   574,   574,   574,   574,   593,   574,   574,   574,
     574,   574,   574,   593,   593,   593,   593,   593,   574,   593,
     593,   505,   593,   593,   593,   593,   551,    17,    63,   551,
     572,   593,   593,    22,    63,   572,   574,   617,   592,   579,
     559,   579,   559,   579,   560,   580,   560,   580,   562,   583,
     562,   583,   562,   583,   562,   583,   562,   584,   562,   584,
     585,   587,   588,   590,   589,   292,   382,   383,   384,   385,
     535,   551,   551,   551,   572,    59,    60,   551,    61,    60,
     572,    62,    62,    62,   551,   572,    71,   572,   572,   551,
     572,   572,   572,   572,   144,   572,   144,    16,    71,    14,
      19,   593,   572,    13,    13,    13,   574,   572,   574,   572,
     572,   572,   574,   574,   574,   574,   572,   572,   572,   572,
     572,   572,   572,   574,   572,   574,   574,   574,   171,   574,
     574,   171,   574,   171,   574,   574,   574,   572,   572,   572,
     572,   572,   572,   572,   572,   572,   572,   572,   572,   572,
     572,   572,   574,   593,    13,   572,   572,   572,   572,   572,
     572,   572,   574,   574,   574,   572,   572,   572,   551,   473,
      20,   552,   552,   490,   491,   492,   493,   494,   547,   547,
     572,   572,   551,   574,   574,   570,   572,   572,   572,   144,
     551,   574,   574,   574,   572,   574,   572,   574,   572,   572,
     572,   572,   572,   572,   572,   572,   572,   572,   572,   572,
     572,   593,   572,   572,   572,   572,   572,   572,   572,   572,
     574,   593,   572,   593,   572,   572,   574,   572,   572,   572,
     593,   574,   613,   613,   613,   593,   593,   593,   551,   593,
     574,   613,   574,   613,   613,   593,    14,   551,   593,   593,
     593,   593,   593,   281,   572,   572,   551,   401,   546,   551,
     572,    75,   572,   572,   551,   551,   551,   551,    20,   551,
     572,    14,    20,    20,    20,    20,    20,    14,    20,    14,
      20,    14,    14,    14,    20,    20,    20,    20,    20,    14,
      14,    20,    20,    20,    20,    14,    20,    14,    20,    14,
      20,    14,    14,    20,    20,    20,    20,    14,    19,    14,
      20,    14,    20,    20,    20,    14,    14,    14,    14,    14,
      20,    13,   578,    14,    20,    19,    20,    14,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    14,    20,    13,    13,    20,
      20,    20,    13,    13,    14,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    14,    14,    14,    20,    14,    20,
      20,    20,    20,    20,    14,    20,    20,    20,    20,    20,
      20,    20,    20,    14,    20,    20,    20,    20,    20,    20,
      14,    14,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    14,    14,    14,    14,    14,
      14,    14,    20,    20,    20,    14,    20,    20,    20,    20,
      20,    13,    14,    20,    14,    20,    20,    14,    14,    59,
      60,   574,   613,    14,    20,    16,    22,    16,    22,    13,
      13,    13,    13,    13,    14,    14,    14,    20,    20,    20,
      20,    14,    20,    14,    20,    20,    20,    20,    20,    20,
      20,    14,    14,    20,    20,    14,    20,    20,    20,    14,
     614,    16,   593,    14,    13,    14,   593,   574,   574,    14,
      20,    14,    20,    14,    20,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    20,    14,
      14,    20,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    20,    14,    20,    14,    14,    14,    14,
      20,    14,    14,    14,    14,    14,    20,    14,    14,   593,
      20,    20,    14,    20,    20,    20,    14,    20,    20,    20,
      20,    20,    20,    14,    20,   572,   551,   535,   535,    57,
      57,    57,    57,    57,    14,    20,    14,    20,    20,    14,
      20,    20,    14,    20,    23,    20,    14,   572,   593,    14,
      14,    20,    14,    14,    20,    14,    20,    14,    14,    14,
      20,    20,    20,    14,    20,    14,    14,    14,    14,    14,
      20,    14,    14,    20,    14,    20,    14,    20,    20,    20,
      14,    14,    14,    14,    14,    14,    14,    14,    20,    20,
      14,    14,    20,    14,    14,    14,    14,    20,    20,    20,
      20,    20,    20,    14,    20,    20,    20,    14,    20,    20,
      20,    20,    20,    14,    14,    20,    20,    20,    20,    20,
      13,    16,    16,    14,    14,    14,    16,    20,    14,    14,
      20,    14,   551,   574,   572,   572,   572,   572,   572,   572,
     574,   574,   572,   572,   572,   572,   572,   572,   572,   572,
     572,   572,   572,   572,   572,   572,   572,   574,   572,   593,
     144,    54,   572,   572,   593,    54,   574,   572,   572,   572,
     572,   572,   572,   572,   572,   572,   572,   572,   572,   572,
     572,   572,   574,   574,   593,   593,   574,   574,   574,   572,
     572,   572,   572,   572,   572,   572,   572,   572,   574,   574,
     574,   574,   574,   574,   574,   574,   572,   572,   572,   572,
     593,   593,   572,   572,   572,   572,   574,   551,   574,   574,
     572,   572,   572,   572,   572,   572,   572,   572,   572,   572,
     572,   572,   572,   572,   572,   572,   574,   572,   572,   574,
     572,   572,   593,    22,   572,   591,   572,   574,    14,    14,
      14,   572,   551,   572,   551,   572,    71,   551,   551,   572,
     551,   551,   551,   551,   551,   572,   572,   572,   572,   572,
     572,    14,    14,    14,    20,   574,   572,   572,   572,   574,
     572,   572,   572,   572,    14,   572,   572,   572,   593,   572,
     572,   572,   572,   574,   574,   572,   572,   572,   474,   552,
     552,   490,   491,   492,   493,   494,   552,   572,   572,   574,
     572,   572,   572,   572,   572,   572,   572,   572,   572,   572,
     572,   572,   572,   572,   572,   572,   572,   572,   572,   572,
     572,   572,   572,   572,   572,   572,   572,   572,   572,   572,
     572,   572,   572,   572,   572,   572,   572,   572,   593,   593,
     572,    75,    20,    20,    54,    14,    20,    14,    20,    14,
      20,    14,    20,    14,    14,    14,    14,    20,    20,    14,
      20,    20,    20,    20,    14,    20,    20,    20,    20,    14,
      14,    14,    20,   572,    14,    20,    20,    14,    14,    20,
      20,    20,    14,    14,    14,    14,    20,    14,    20,    20,
      20,    20,    20,    20,    20,    20,    14,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    14,    20,    20,    20,    20,    20,    20,    14,    14,
      20,    14,    14,    14,    20,    20,    14,    14,    14,    14,
      20,    14,    14,    20,    20,    20,    14,    14,    14,    14,
      14,    14,    14,    14,    20,    20,    20,    20,    20,    14,
      20,    20,    14,    20,    20,    14,    14,    14,    20,    20,
      14,    14,    14,    20,    20,    20,    20,    14,    14,    14,
      14,    14,    14,    14,    20,    14,    14,    14,    20,    14,
      14,    14,   572,    14,    20,    14,    14,    20,    20,    14,
      20,    20,    14,    20,    14,    20,    14,    20,    14,    20,
      20,    20,    20,    20,    20,    20,    20,    14,   572,   535,
     535,    57,    57,    57,    57,    57,   535,    14,    20,    20,
      20,    14,    20,    23,    14,    22,    20,    20,    20,    20,
      20,    20,    20,    14,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    14,    20,    20,    20,    20,    14,    14,
      20,    14,    14,    14,    14,    14,    20,    14,    20,    20,
      20,    20,    20,    20,    20,    20,   551,   551,    14,   572,
     572,   572,   572,   572,   572,   572,   572,   572,   572,   572,
     572,   572,   572,   572,   572,   574,   572,   573,   573,   574,
      54,   574,   572,   572,   572,   572,   572,   572,   572,   572,
     572,   572,   572,   574,   572,   574,   572,   572,   572,   572,
     572,   572,   572,   572,   572,   572,   572,   572,   572,   574,
     574,   574,   574,   574,   572,   572,   572,   593,   593,   572,
     572,   572,   572,   572,   572,   572,   572,   572,   572,   572,
     572,   572,   572,   572,   572,   572,   551,   572,    14,   572,
     574,   572,   572,   572,   593,   593,   593,   593,   572,   572,
     572,   574,   574,   572,   572,   552,   572,   574,   572,   572,
     572,   572,   572,   572,   572,   572,   572,   572,   572,   572,
     572,   572,   572,   572,   572,   572,   572,   572,   572,   572,
     572,   572,   574,   593,   572,   572,   572,   572,   593,   593,
     572,   572,    14,    14,    20,    20,    14,    20,    20,    14,
      20,    20,    14,    20,    20,    20,    14,    20,    20,    14,
      20,    20,    14,    14,    20,    20,    20,    20,    14,    20,
      14,    20,    14,    20,    14,    20,    20,    20,    20,    20,
      14,    14,    14,    20,    20,    20,    20,    20,    20,    14,
      20,    20,    20,    20,    20,    20,    20,    14,    20,    20,
      20,    20,    20,    20,    20,    14,    14,    14,    14,    20,
      20,    14,    20,    20,    20,    20,    20,    20,    14,    20,
      22,    22,    20,    14,    20,    14,    20,    14,    20,    14,
      20,    14,    20,    14,    14,    20,    14,    20,    20,    14,
      20,    14,    20,    20,    14,    14,   535,    20,    20,    20,
      14,    14,    20,    20,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    20,    20,
      20,    20,    20,    14,    14,    14,    20,    14,    20,    20,
      20,    14,    14,   572,   572,   572,   572,   572,   572,   572,
     572,   572,   572,   572,   573,   572,   573,    54,   572,   572,
     572,   572,   572,   572,   572,   572,   572,   572,   572,   572,
     572,   572,   572,   572,   572,   617,   572,   617,   572,   617,
     572,   572,   572,   572,   572,   572,   572,   572,   572,   574,
     572,   572,   572,   572,   572,   572,   572,   572,   572,   572,
     572,   572,   572,   572,   551,   572,   572,   572,   572,   572,
     572,   572,   593,   574,   572,   574,   572,   572,   572,   572,
     572,   572,   572,   572,   593,   572,   572,   572,    20,    14,
      14,    20,    20,    20,    14,    14,    14,    20,    14,    20,
      20,    20,    14,    14,    20,    20,    20,    14,    20,    14,
      20,    20,    20,    20,    20,    20,    14,    20,    20,    20,
      20,    20,    20,    20,    14,    20,    14,    14,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    14,    20,    20,
      14,    14,    20,    14,    14,    14,    20,    20,    20,    14,
      16,    20,    14,    14,    14,    14,    14,    20,    20,    14,
      14,    20,    20,    14,    20,    20,    20,    20,    22,    14,
      14,    20,    20,    14,    20,    20,    20,    20,    20,   572,
     572,   572,   572,   572,   572,   572,   551,   573,   572,   572,
     572,   572,   572,   572,   572,   572,   572,   572,   572,   572,
     572,   572,   572,   617,   617,   617,   617,   572,   572,   572,
     574,   574,   574,   574,   572,   572,   572,   572,   572,   572,
     572,   572,   572,   572,   572,   574,   572,   574,   572,   572,
     572,   572,   572,   593,   572,   572,   572,    14,    20,    20,
      20,    20,    14,    20,    20,    14,    14,    20,    14,    14,
      14,    14,    14,    14,    20,    14,    20,    14,    20,    14,
      14,    20,    14,    14,    14,    14,    20,    14,    14,    14,
      14,    20,    20,    14,    20,    14,    20,    14,    20,    22,
      20,    14,    20,    20,    20,    20,    20,    20,    14,    20,
      20,    20,    14,    20,    20,    20,    20,   572,   572,   572,
     572,   551,   572,   572,   572,   572,   572,   572,   572,   617,
     572,   572,   572,   572,   572,   572,   572,   572,   572,   574,
     572,   574,   572,   144,   572,   572,   572,   593,   572,   572,
     572,    14,    14,    20,    14,    14,    20,    20,    20,    14,
      14,    14,    20,    14,    20,    20,    14,    20,    20,    14,
      14,    20,    20,    14,    20,    20,    20,    20,   593,    20,
      20,    14,    20,    20,    14,    14,    20,    20,   572,   551,
     572,   572,   572,   572,   572,   572,   572,   593,   572,   593,
     572,   572,   572,   572,   572,   572,   572,   572,   572,    20,
      14,    14,    14,    14,    14,    20,    20,    20,    14,    14,
      14,    20,    20,    20,    14,    20,    20,    14,    14,    20,
      14,    20,   572,   572,   572,   572,   572,   572,   574,   572,
     572,   572,   593,    20,    20,    14,    20,    14,    20,    20,
      14,    20,    14,    20,   572,   572,   572,   572,   574,   572,
     593,    20,    14,    20,    20,    20,    14,    14,   572,   572,
     572,   572,    20,    20,    20,    14,   572,   572,   572,    20,
      20,    20,   572,   572,   572,    14,    20,    20,   572,   572,
      20,    14,   572,    14
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
     785,   126
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  Parser::yyr1_[] =
  {
         0,   532,   533,   533,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     535,   535,   536,   536,   536,   536,   537,   537,   539,   538,
     540,   538,   541,   542,   543,   543,   543,   543,   543,   544,
     544,   544,   544,   544,   544,   544,   544,   544,   544,   544,
     544,   544,   544,   544,   544,   544,   544,   544,   544,   544,
     544,   544,   544,   544,   544,   544,   544,   544,   544,   544,
     544,   544,   544,   544,   544,   544,   544,   544,   544,   544,
     544,   544,   544,   544,   544,   544,   544,   544,   544,   544,
     544,   544,   544,   544,   544,   544,   544,   544,   544,   544,
     544,   544,   544,   544,   544,   544,   544,   544,   544,   544,
     544,   544,   544,   544,   544,   544,   544,   544,   544,   544,
     544,   544,   544,   544,   544,   544,   544,   544,   544,   544,
     544,   544,   544,   544,   544,   544,   544,   544,   544,   544,
     544,   544,   544,   544,   544,   544,   544,   544,   544,   544,
     544,   544,   544,   544,   544,   544,   544,   544,   544,   544,
     544,   544,   544,   544,   544,   544,   544,   544,   544,   544,
     544,   544,   544,   544,   544,   544,   544,   544,   544,   544,
     544,   544,   544,   544,   544,   544,   544,   544,   544,   544,
     544,   544,   544,   544,   544,   544,   544,   544,   544,   544,
     544,   544,   544,   544,   544,   544,   544,   544,   544,   544,
     544,   544,   544,   544,   544,   544,   544,   544,   544,   544,
     544,   544,   544,   544,   544,   544,   544,   544,   544,   544,
     544,   544,   544,   544,   544,   544,   544,   544,   544,   544,
     544,   544,   544,   544,   544,   544,   544,   544,   544,   544,
     544,   544,   544,   544,   544,   544,   544,   544,   544,   544,
     544,   544,   544,   544,   544,   544,   544,   544,   544,   544,
     544,   544,   544,   544,   544,   544,   544,   544,   544,   544,
     544,   544,   544,   544,   544,   544,   544,   544,   544,   544,
     544,   544,   544,   544,   544,   544,   544,   544,   544,   544,
     544,   544,   544,   544,   544,   544,   544,   544,   544,   544,
     544,   544,   544,   544,   544,   544,   544,   544,   544,   544,
     544,   544,   544,   544,   544,   544,   544,   544,   544,   544,
     544,   544,   544,   544,   544,   544,   544,   544,   544,   544,
     544,   544,   544,   544,   544,   544,   544,   544,   544,   544,
     544,   544,   544,   544,   544,   544,   544,   544,   544,   545,
     545,   546,   546,   546,   546,   546,   546,   546,   546,   546,
     546,   546,   546,   546,   546,   546,   546,   546,   547,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   547,   548,
     548,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     550,   550,   550,   551,   552,   553,   554,   555,   555,   555,
     555,   555,   555,   555,   555,   556,   556,   556,   556,   556,
     556,   556,   556,   556,   556,   556,   556,   556,   556,   556,
     556,   556,   556,   556,   556,   556,   556,   556,   556,   556,
     556,   556,   556,   556,   556,   556,   556,   556,   556,   556,
     556,   556,   556,   556,   556,   556,   556,   556,   556,   556,
     556,   556,   556,   556,   556,   556,   556,   556,   556,   556,
     556,   556,   556,   556,   556,   556,   556,   556,   556,   556,
     556,   556,   556,   556,   556,   556,   556,   556,   556,   556,
     556,   556,   557,   557,   557,   557,   557,   557,   557,   557,
     557,   557,   557,   557,   557,   557,   557,   557,   557,   557,
     558,   558,   559,   559,   560,   560,   560,   560,   561,   561,
     561,   562,   563,   563,   563,   563,   563,   564,   564,   564,
     564,   564,   565,   565,   566,   566,   567,   567,   568,   568,
     569,   569,   570,   570,   571,   572,   573,   573,   573,   573,
     573,   573,   573,   573,   573,   573,   573,   574,   574,   575,
     575,   575,   575,   575,   575,   575,   575,   575,   575,   575,
     575,   575,   575,   575,   575,   575,   575,   575,   575,   575,
     575,   575,   575,   575,   575,   575,   575,   575,   575,   575,
     575,   575,   575,   575,   575,   575,   575,   575,   575,   575,
     575,   575,   575,   575,   575,   575,   575,   575,   575,   575,
     575,   575,   575,   575,   575,   575,   575,   575,   575,   575,
     575,   575,   575,   575,   575,   575,   575,   575,   575,   575,
     575,   575,   575,   575,   575,   575,   575,   575,   575,   575,
     575,   575,   575,   575,   575,   575,   575,   575,   575,   575,
     575,   575,   575,   575,   575,   575,   575,   575,   575,   575,
     575,   575,   575,   575,   575,   575,   575,   575,   575,   575,
     575,   575,   575,   575,   575,   575,   575,   575,   575,   575,
     575,   575,   575,   575,   575,   575,   575,   575,   575,   575,
     575,   575,   575,   575,   575,   575,   575,   575,   575,   575,
     575,   575,   575,   575,   575,   575,   575,   576,   576,   577,
     578,   578,   578,   578,   578,   578,   578,   578,   578,   578,
     578,   578,   578,   578,   578,   578,   578,   578,   579,   579,
     580,   580,   580,   580,   580,   580,   581,   582,   582,   582,
     582,   582,   583,   584,   584,   584,   584,   584,   584,   584,
     584,   584,   585,   585,   585,   585,   585,   586,   586,   587,
     588,   588,   589,   589,   590,   590,   591,   591,   592,   592,
     593,   594,   594,   594,   594,   595,   595,   595,   596,   596,
     597,   598,   598,   598,   598,   598,   598,   598,   598,   598,
     598,   598,   598,   598,   598,   598,   598,   598,   598,   599,
     600,   600,   600,   600,   601,   601,   601,   601,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   613,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     615,   616,   616,   616,   616,   616,   616,   616,   616,   616,
     616,   616,   616,   616,   616,   616,   616,   616,   616,   616,
     616,   617,   617,   617,   617
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
       1,     1,     1,     6,     3,     8,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     6,     8,     6,    10,
       6,     8,     8,     8,     8,     6,     3,     4,     1,     1,
       1,     1,     1,     1,     1,    30,    24,     4,     8,     1,
       3,     0,     1,     3,     1,     3,     2,     4,     2,     4,
       1,     3,     2,     4,     2,     4,     1,     3,     0,     2,
       2,     2,     2,     2,     4,     4,     4,     4,     4,     1,
       1,     1,     6,     6,     6,     1,     3,     4,     4,     1,
       1,     3,     3,     1,     3,     0,     0,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     4,     6,     8,    10,
      10,    10,     8,     6,     3,     3,     3,     2,     3,     3,
       3,     6,     4,    10,     4,    10,     4,     4,     4,     4,
       4,     4,     7,     7,     7,     9,     7,     6,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     6,     8,    10,    12,    10,    12,     8,     6,     8,
       8,     8,     8,     6,     8,     8,     8,    12,     6,     6,
       3,     6,     6,     4,     4,     4,     1,     6,     6,     6,
       3,     6,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     1,     1,     4,     1,     3,     3,     3,     1,     3,
       3,     1,     1,     3,     3,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     4,     2,
       4,    16,    14,    16,     4,     4,     4,     1,    10,    12,
       8,     1,     4,     6,     6,     6,     8,     8,     6,     6,
       8,     8,    10,    10,    12,    12,    10,     4,    10,     4,
       6,     4,     4,     4,    12,     4,    12,    12,    16,    20,
      10,    12,     4,     6,     6,     6,     4,     4,     6,     4,
       6,     6,     6,     4,    10,    16,    10,     8,    12,    10,
       8,    12,     8,    12,     8,    12,     3,     3,     8,     8,
       3,     6,    12,    12,    14,    12,    12,    16,     4,     8,
      10,    12,    10,    12,    10,    12,    12,    14,    12,     8,
      14,     4,     4,     4,     4,     3,     3,     3,     6,     6,
       6,     6,     8,    14,    12,    14,    12,     6,     8,    10,
      10,    12,     6,     6,     6,     6,     6,     6,     6,     6,
       8,    10,     4,     4,    10,    10,     4,     6,     6,    12,
      30,     8,     5,     6,     5,     5,     6,     6,     4,     6,
       4,     6,     4,     4,    18,     8,     6,     1,     3,     1,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     4,
       1,     3,     3,     3,     3,     3,     1,     1,     3,     3,
       3,     3,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     1,
       1,     3,     1,     3,     1,     3,     1,     5,     1,     3,
       1,     1,     3,     8,     4,     6,     1,     4,     1,     3,
       1,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       1,     3,     3,     3,     1,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     6,     6,     8,     8,     4,     6,     6,     6,
       6,     3,     2,     4,     1,     4,     6,     1,     4,     4,
      10,     6,    16,    18,    10,    20,    14,     8,     4,     6,
       8,     8,    12,    16,    16,    18,    14,    14,    16,    20,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,    11,     7,     1,     1
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
  "T_NULL", "T_RestartTime", "T_InitTime", "T_TimeSpent", "T_EndTime",
  "T_LevelSetsCURV", "T_UpdateResult", "T_SetMeanCurv", "T_SetAffineCurv",
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
       533,     0,    -1,    -1,   534,     0,    -1,   535,    -1,   534,
     535,    -1,   544,   535,    -1,   534,   544,   535,    -1,   536,
      -1,   534,   536,    -1,   537,    -1,   534,   537,    -1,   543,
      -1,   534,   543,    -1,   538,    -1,   534,   538,    -1,   541,
      -1,   534,   541,    -1,   542,    -1,   534,   542,    -1,    34,
      -1,    23,    -1,   472,   615,   144,   572,   473,   572,   552,
     535,    -1,   472,   615,   144,   572,   473,   572,   474,   572,
     552,   535,    -1,   472,   615,   476,   545,   552,   535,    -1,
     477,   552,    -1,   480,   572,   552,   535,    -1,   480,   572,
     552,   482,   552,   535,    -1,    -1,   496,   615,   539,    13,
     547,    14,   552,   535,    -1,    -1,   496,    71,   540,    13,
     547,    14,   552,   535,    -1,   497,   615,   552,   535,    -1,
      72,   615,    -1,   484,   551,   535,    -1,   484,   535,    -1,
     485,   551,    -1,    71,    13,   546,    14,   535,    -1,    71,
     535,    -1,    33,    -1,   479,    -1,    82,    -1,    84,    -1,
      85,    -1,    83,    -1,    87,    13,   572,    14,    -1,    88,
      13,   572,    20,    71,    14,    -1,   615,   144,   346,    15,
     572,    16,    -1,   615,   123,   346,    15,   572,    16,    -1,
     615,   144,    35,    15,   572,    16,    -1,   615,   144,   593,
      -1,   615,   123,   593,    -1,   615,   144,    68,    13,   546,
      14,    -1,    77,    15,   572,    16,   144,   593,    -1,   615,
     144,   612,    -1,   615,   144,   594,    -1,    66,   144,   572,
      -1,    66,   144,   612,    -1,    76,    15,   572,    16,   144,
     614,    -1,   615,   144,    86,    -1,   615,   144,   614,    -1,
     613,   123,   614,    -1,    76,   123,   346,    15,   572,    16,
      -1,   615,   144,   437,    13,   572,    14,    -1,   615,   144,
     437,    13,   572,    14,    20,   551,    -1,   615,   144,   434,
      13,   572,    14,    -1,   615,   144,   434,    13,   572,    14,
      20,   551,    -1,   615,   144,   572,    -1,   615,   144,   572,
      20,   551,    -1,   615,   144,   551,    -1,   615,   144,   551,
      20,   551,    -1,   615,   144,   449,    13,   551,    20,    54,
      14,    -1,    67,   144,   449,    13,   551,    20,    54,    14,
      -1,    67,    19,   453,    -1,    24,    -1,    25,    -1,    26,
      -1,    27,    -1,    28,    13,   551,    20,   551,    20,   551,
      14,    -1,    29,    13,   572,    14,    -1,    30,    13,   551,
      14,    -1,    40,    -1,    38,   574,    -1,    41,   574,    -1,
      38,   613,    -1,   380,    -1,   574,   144,   593,    -1,   574,
     123,   593,    -1,   574,   144,   572,    -1,   574,    15,   572,
      16,   144,   593,    -1,   574,    15,   572,    16,   144,   572,
      -1,   574,    13,   572,    22,   572,    20,   572,    22,   572,
      20,   572,    22,   572,    14,   144,   593,    -1,    59,   133,
      -1,    59,   134,    -1,    59,   144,   572,    -1,    60,   133,
      -1,    60,   134,    -1,    60,   144,   572,    -1,    61,   144,
     572,    -1,    61,   133,    -1,    61,   134,    -1,    62,   144,
     551,    -1,    38,   483,    -1,   616,    19,    80,    13,   551,
      14,    -1,    78,   616,    -1,    79,   551,    -1,    78,    76,
      15,   572,    16,    -1,    47,   551,    -1,    48,    -1,    39,
      -1,    39,   615,    -1,    39,    70,    -1,    39,    68,    -1,
      39,    69,    -1,    39,    54,    -1,    67,    19,    42,   551,
      -1,    67,    19,    43,   551,    -1,    42,   551,    -1,    43,
     551,    -1,    42,   612,    -1,    44,   551,    -1,   612,    -1,
      67,    19,    42,   572,    -1,    67,    19,   450,    -1,    42,
     572,    -1,    43,   572,    -1,    63,    19,   408,    13,   572,
      20,   572,    20,   572,    14,    -1,    63,    19,   409,    13,
     572,    14,    -1,    63,    19,   410,    -1,    63,    19,   411,
      13,   574,    14,    -1,    63,    19,   411,    13,    63,    14,
      -1,    63,    19,   414,    13,    63,    20,   574,    14,    -1,
      63,    19,   502,    13,   572,    20,   572,    20,   572,    20,
     572,    20,   572,    20,   572,    20,   572,    20,   572,    20,
     572,    20,   572,    20,   572,    20,   572,    14,    -1,    63,
      19,   412,    13,    56,    20,   574,    14,    -1,    63,    19,
     415,    13,   572,    20,   572,    14,    -1,    63,    19,   416,
      -1,    63,    19,   417,    13,   572,    20,   572,    14,    -1,
      63,    19,   418,    13,   572,    20,   572,    20,   572,    20,
     572,    14,    -1,    63,    19,   419,    13,   572,    14,    -1,
      63,    19,   420,    13,   572,    14,    -1,    63,    19,   421,
      13,   572,    20,   572,    20,   572,    20,   572,    20,   572,
      20,   572,    14,    -1,    63,    19,   422,    13,   572,    20,
     572,    14,    -1,    63,    19,   424,    13,   572,    20,   572,
      20,   572,    20,   572,    20,   572,    20,   572,    14,    -1,
      63,    19,   423,    13,   593,    20,   572,    20,   572,    14,
      -1,    63,    19,   425,    13,    65,    14,    -1,    63,    19,
     296,    13,   572,    20,   574,    20,   572,    14,    -1,    63,
      19,   296,    13,   574,    20,   572,    14,    -1,    63,    19,
     297,    13,   572,    20,   572,    20,   572,    14,    -1,    63,
      19,   297,    13,   572,    20,   572,    20,   572,    20,   572,
      20,   572,    14,    -1,    63,    19,   298,    13,   572,    20,
     572,    14,    -1,    63,    19,   299,    13,   572,    20,   572,
      20,   572,    20,   572,    14,    -1,    63,    19,   300,    13,
     572,    14,    -1,    63,    19,   301,    13,   572,    20,   572,
      14,    -1,    63,    19,   520,    13,    71,    14,    -1,    63,
      19,   377,    13,   574,    14,    -1,   574,    19,   426,    13,
     572,    14,    -1,   574,    19,   426,    13,   572,    20,   572,
      20,   572,    14,    -1,   574,    19,   407,    13,   572,    14,
      -1,   574,    19,   407,    13,   572,    20,   572,    20,   572,
      14,    -1,   574,    19,   408,    13,   572,    20,   572,    20,
     572,    14,    -1,   574,    19,   158,    13,   574,    20,   572,
      20,   572,    20,   572,    14,    -1,   574,    19,   158,    13,
     574,    14,    -1,   574,    19,    49,    13,   551,    14,    -1,
     165,    19,   221,    13,   574,    20,   572,    20,   572,    20,
     572,    14,    -1,   165,    19,   222,    13,   572,    14,    -1,
     165,    19,   168,    13,   572,    14,    -1,   165,    19,   227,
      13,   572,    14,    -1,   165,    19,   228,    13,   572,    14,
      -1,   165,    19,   231,    13,   574,    14,    -1,   165,    19,
     232,    13,   574,    14,    -1,   165,    19,   233,    13,   574,
      14,    -1,   165,    19,   234,    13,   574,    14,    -1,   165,
      19,   235,    13,   572,    14,    -1,   165,    19,   236,    13,
     572,    14,    -1,   165,    19,   237,    13,   572,    14,    -1,
     165,    19,   238,    13,   572,    14,    -1,   165,    19,   222,
      13,   572,    20,   572,    14,    -1,   165,    19,   223,    -1,
     165,    19,   224,    -1,   211,    19,   223,    -1,   211,    19,
     224,    -1,   212,    19,   223,    -1,   212,    19,   224,    -1,
     176,    19,   194,    13,   572,    20,   572,    20,   572,    20,
     572,    14,    -1,   176,    19,   194,    13,   572,    20,   572,
      20,   572,    20,   572,    20,   572,    20,   572,    14,    -1,
     176,    19,   178,    13,   572,    14,    -1,   176,    19,   179,
      13,   572,    14,    -1,   176,    19,   180,    13,   572,    14,
      -1,   176,    19,   193,    13,   572,    14,    -1,   176,    19,
     197,    13,   572,    14,    -1,   176,    19,   202,    13,   572,
      14,    -1,   176,    19,   203,    13,   572,    14,    -1,   176,
      19,   204,    13,   572,    14,    -1,   176,    19,   205,    13,
     572,    14,    -1,   176,    19,   200,    13,   572,    14,    -1,
     176,    19,   201,    13,   572,    20,   572,    20,   572,    14,
      -1,   176,    19,   206,    13,   572,    14,    -1,   176,    19,
     207,    13,   572,    20,   572,    20,   572,    20,   572,    20,
     572,    14,    -1,   176,    19,   195,    13,   572,    14,    -1,
     176,    19,   181,    13,   574,    20,   572,    14,    -1,   176,
      19,   182,    13,   572,    14,    -1,   176,    19,   183,    13,
     574,    14,    -1,   176,    19,   196,    13,   572,    20,   572,
      14,    -1,   176,    19,   185,    13,   574,    14,    -1,   176,
      19,   184,    13,   574,    20,   574,    20,   574,    14,    -1,
     176,    19,   187,    13,   574,    14,    -1,   176,    19,   188,
      13,   574,    14,    -1,   176,    19,   189,    13,   574,    14,
      -1,   176,    19,   192,    13,   574,    14,    -1,   176,    19,
     190,    13,   574,    14,    -1,   176,    19,   191,    13,   574,
      14,    -1,   176,    19,   187,    13,   171,    14,    -1,   176,
      19,   189,    13,   171,    14,    -1,   176,    19,   190,    13,
     171,    14,    -1,   176,    19,   198,    13,   572,    14,    -1,
     176,    19,   199,    13,   572,    14,    -1,   176,    19,   223,
      -1,   176,    19,   224,    -1,   574,    19,   242,   551,    -1,
     574,    19,   243,    -1,   574,    19,   244,    13,   574,    14,
      -1,   574,    19,   245,    13,   574,    14,    -1,   613,    19,
     242,   551,    -1,   613,    19,   295,   551,    -1,   613,    19,
     357,    13,   572,    14,    -1,   613,    19,   372,    13,   572,
      20,   572,    20,   572,    14,    -1,   613,    19,   373,    13,
     572,    20,   572,    20,   572,    14,    -1,   613,    19,   374,
      13,   572,    20,   572,    20,   572,    14,    -1,   613,    19,
     375,    13,   572,    14,    -1,   613,    19,   376,    13,   572,
      14,    -1,   613,    19,   378,    13,   572,    14,    -1,   613,
      19,   379,    13,   572,    14,    -1,   613,    19,   360,    13,
     572,    14,    -1,   613,    19,   358,    13,   572,    20,   572,
      20,   572,    14,    -1,   613,    19,   395,    13,   574,    14,
      -1,   613,    19,   359,    13,   593,    20,   572,    20,   572,
      14,    -1,   613,    19,   359,    13,   593,    14,    -1,   613,
      19,   381,    13,   574,    14,    -1,   613,    19,   388,    13,
     572,    14,    -1,   613,    19,   389,    -1,   613,    19,   272,
      13,   572,    14,    -1,   613,    19,   390,    13,   593,    14,
      -1,   613,    19,   393,    13,   572,    20,   572,    20,   572,
      14,    -1,   613,    19,   394,    13,   572,    20,   572,    20,
     572,    14,    -1,   613,    19,   396,    13,   572,    14,    -1,
     613,    19,   280,    13,   572,    14,    -1,   613,    19,   386,
      13,   593,    14,    -1,   613,    19,   387,    -1,   613,    19,
     341,    -1,   613,    19,   391,    -1,   613,    19,   392,    -1,
     613,    19,   340,    13,   572,    14,    -1,   613,    19,   342,
      13,   572,    14,    -1,   613,    19,   338,    -1,   613,    19,
     352,    13,   572,    14,    -1,   613,    19,   351,    13,   572,
      14,    -1,   613,    19,   351,    13,   572,    20,   572,    14,
      -1,   613,    19,   397,    13,   572,    20,   572,    20,   572,
      14,    -1,   613,    19,   398,    -1,   613,    19,   400,    13,
     572,    14,    -1,   613,    19,   399,    -1,   518,    13,   551,
      14,    -1,   519,    13,    63,    20,   572,    20,   572,    20,
     572,    20,   572,    20,   572,    20,   572,    20,   572,    20,
     572,    14,    -1,   613,    19,   511,    13,   593,    14,    -1,
      65,    19,   349,    13,   572,    20,   572,    20,   572,    14,
      -1,    65,    19,   353,    13,   614,    14,    -1,    65,   124,
     613,    -1,    65,   125,   613,    -1,    65,    19,   370,    13,
     613,    14,    -1,    65,    19,   371,    -1,    65,    19,   351,
      13,   572,    14,    -1,    65,    19,   351,    13,   572,    20,
     572,    14,    -1,    65,    19,   354,    13,   572,    14,    -1,
      65,    19,   411,    13,    65,    14,    -1,    65,    19,   412,
      13,    56,    20,   574,    14,    -1,    65,    19,   427,    13,
     572,    20,   593,    20,   572,    20,   572,    20,   572,    20,
     572,    14,    -1,    65,    19,   428,    13,   572,    14,    -1,
      65,    19,   406,    -1,    65,    19,   402,    13,   594,    14,
      -1,    65,    19,   402,    13,   594,    20,   572,    14,    -1,
      65,    19,   361,    -1,    65,    19,   364,    13,   572,    20,
     572,    20,   572,    20,   572,    14,    -1,    65,    19,   365,
      13,   572,    20,   572,    20,   572,    20,   572,    14,    -1,
      65,    19,   366,    13,   572,    20,   572,    20,   572,    20,
     572,    14,    -1,    65,    19,   367,    13,   572,    20,   572,
      20,   572,    14,    -1,    65,    19,   368,    -1,    65,    19,
     369,    -1,    65,    19,   422,    13,   572,    20,   572,    14,
      -1,   267,    13,   574,    20,   572,    20,   572,    14,    -1,
     267,    13,   574,    20,   572,    20,   572,    20,   593,    14,
      -1,   268,    13,   574,    20,   572,    20,   572,    14,    -1,
     268,    13,   574,    20,   572,    20,   572,    20,   593,    14,
      -1,   268,    13,   574,    20,   572,    20,   572,    20,   593,
      20,   572,    14,    -1,   269,    13,   574,    20,   572,    14,
      -1,   269,    13,   574,    20,   572,    20,   593,    14,    -1,
     269,    13,   574,    20,   572,    20,   572,    14,    -1,   269,
      13,   574,    20,   572,    20,   572,    20,   593,    14,    -1,
     271,    13,   574,    20,   572,    20,   572,    20,   572,    20,
     572,    20,   572,    20,   572,    14,    -1,   271,    13,   574,
      20,   572,    20,   572,    20,   572,    20,   572,    20,   572,
      20,   572,    20,   593,    14,    -1,   270,    13,   574,    20,
     572,    20,   572,    20,   593,    20,   572,    14,    -1,   272,
      13,   574,    20,   572,    14,    -1,   317,    13,    54,    20,
     574,    20,   574,    20,   574,    20,   574,    20,   574,    20,
     574,    20,   593,    14,    -1,   317,    13,    54,    20,   574,
      20,   574,    20,   574,    20,   574,    20,   574,    20,   574,
      14,    -1,   316,    13,    54,    20,   574,    20,   574,    20,
     574,    20,   593,    14,    -1,   316,    13,    54,    20,   574,
      20,   574,    20,   574,    14,    -1,   274,    13,   574,    20,
     572,    20,   572,    20,   572,    14,    -1,   574,    19,   274,
      13,   572,    20,   572,    20,   572,    14,    -1,   574,    19,
     274,    13,   574,    14,    -1,   574,    19,   275,    13,   572,
      20,   572,    20,   572,    14,    -1,   574,    19,   275,    13,
     574,    14,    -1,   574,    19,   276,    13,   572,    14,    -1,
     160,    13,   574,    20,   574,    14,    -1,   160,    13,   574,
      20,   574,    20,   574,    14,    -1,   572,    -1,   330,    13,
     572,    14,    -1,   331,    13,   572,    14,    -1,   445,    13,
     593,    20,   551,    20,   572,    14,    -1,   448,    13,   574,
      14,    -1,   315,    13,   574,    20,   574,    20,   572,    20,
     572,    20,   572,    20,   572,    20,   572,    20,   572,    14,
      -1,   489,    13,    54,    14,    -1,   172,    -1,   173,    -1,
     175,    -1,   615,   144,    89,    13,   551,    14,    -1,    74,
      19,    95,    -1,    74,    19,    97,    13,   572,    20,   572,
      14,    -1,    74,    19,    91,    -1,    74,    19,    93,    -1,
      74,    19,   115,    -1,    74,    19,   116,    -1,    74,    19,
     117,    -1,    74,    19,   100,    -1,    74,    19,   101,    -1,
      74,    19,    41,    -1,    74,    19,   118,    -1,    74,    19,
     410,    -1,    74,    19,   410,    13,   572,    14,    -1,    74,
      19,   110,    13,   572,    20,   572,    14,    -1,    74,    19,
     111,    13,    71,    14,    -1,    74,    19,   113,    13,   572,
      20,   572,    20,   572,    14,    -1,    74,    19,   112,    13,
     572,    14,    -1,    74,    19,   112,    13,   572,    20,   572,
      14,    -1,    74,    19,   119,    13,   572,    20,   572,    14,
      -1,    74,    19,   120,    13,   572,    20,   572,    14,    -1,
      74,    19,   121,    13,   572,    20,   572,    14,    -1,   521,
      13,   574,    20,   551,    14,    -1,    75,    19,    42,    -1,
      75,    19,   242,   551,    -1,   522,    -1,   523,    -1,   524,
      -1,   525,    -1,   526,    -1,   527,    -1,   528,    -1,   529,
      13,   574,    20,   574,    20,   574,    20,   574,    20,   574,
      20,   574,    20,   574,    20,   572,    20,   572,    20,   572,
      20,   572,    20,   572,    20,   572,    20,   572,    14,    -1,
     530,    13,   574,    20,   574,    20,   572,    20,   572,    20,
     572,    20,   572,    20,   572,    20,   572,    20,   574,    20,
     574,    20,   572,    14,    -1,    69,    13,   546,    14,    -1,
     513,    13,   572,    20,   572,    20,   572,    14,    -1,   551,
      -1,   545,    20,   551,    -1,    -1,   572,    -1,   546,    20,
     572,    -1,   551,    -1,   546,    20,   551,    -1,    17,    59,
      -1,   546,    20,    17,    59,    -1,    17,    60,    -1,   546,
      20,    17,    60,    -1,   593,    -1,   546,    20,   593,    -1,
      17,   574,    -1,   546,    20,    17,   574,    -1,    17,   613,
      -1,   546,    20,    17,   613,    -1,    63,    -1,   546,    20,
      63,    -1,    -1,   493,    57,    -1,   494,    57,    -1,   490,
      57,    -1,   491,    57,    -1,   492,    57,    -1,   547,    20,
     493,    57,    -1,   547,    20,   494,    57,    -1,   547,    20,
     490,    57,    -1,   547,    20,   491,    57,    -1,   547,    20,
     492,    57,    -1,    54,    -1,    62,    -1,   548,    -1,    46,
      13,   551,    20,   572,    14,    -1,    45,    13,   551,    14,
      12,   572,    -1,    45,    13,   551,    14,    12,   551,    -1,
     174,    -1,   574,    19,    50,    -1,    50,    13,   616,    14,
      -1,    51,    13,   616,    14,    -1,    31,    -1,   549,    -1,
     550,    10,   549,    -1,   550,    11,   549,    -1,   550,    -1,
     553,    55,   554,    -1,    -1,    -1,    56,    -1,    32,    -1,
     454,    -1,   455,    -1,    59,    -1,    60,    -1,    61,    -1,
      13,   572,    14,    -1,   555,    -1,   574,    13,   572,    14,
      -1,   574,    13,   572,    20,   572,    14,    -1,   574,    13,
     572,    20,   572,    20,   572,    14,    -1,   574,    19,   413,
      13,   572,    20,   572,    20,   572,    14,    -1,   574,    13,
     572,    20,   572,    20,   572,    20,   572,    14,    -1,   574,
      13,   572,    20,   572,    20,   572,    23,   572,    14,    -1,
     574,    13,   572,    20,   572,    23,   572,    14,    -1,   574,
      13,   572,    23,   572,    14,    -1,   574,    19,   221,    -1,
     574,    19,   615,    -1,   574,    19,   239,    -1,    73,   239,
      -1,   613,    19,   239,    -1,   613,    19,   240,    -1,   613,
      19,   241,    -1,   226,    13,   574,    20,   574,    14,    -1,
     259,    13,   574,    14,    -1,   332,    13,   574,    20,   572,
      20,   572,    20,   572,    14,    -1,   333,    13,   574,    14,
      -1,   333,    13,   572,    20,   572,    20,   572,    20,   572,
      14,    -1,   145,    13,   593,    14,    -1,   261,    13,   593,
      14,    -1,   146,    13,   593,    14,    -1,   147,    13,   593,
      14,    -1,   148,    13,   593,    14,    -1,   149,    13,   593,
      14,    -1,   146,    15,   593,    16,    13,   593,    14,    -1,
     148,    15,   593,    16,    13,   574,    14,    -1,   149,    15,
     593,    16,    13,   574,    14,    -1,   149,    15,   593,    16,
      13,   574,    20,   572,    14,    -1,   261,    15,   593,    16,
      13,   593,    14,    -1,   261,    13,   574,    20,   593,    14,
      -1,   444,    13,   551,    14,    -1,    63,    19,   306,    -1,
      63,    19,   307,    -1,    63,    19,   304,    -1,    63,    19,
     305,    -1,    63,    19,   302,    -1,    63,    19,   303,    -1,
      63,    19,   308,    -1,    63,    19,   309,    -1,    63,    19,
     310,    -1,   165,    19,   229,    -1,   165,    19,   230,    -1,
     176,    19,   177,    -1,    66,    13,   572,    20,   572,    14,
      -1,    66,    13,   572,    20,   572,    14,   144,   572,    -1,
      74,    19,    98,    13,    59,    20,   572,    20,   572,    14,
      -1,    74,    19,    98,    13,    59,    20,   551,    20,   572,
      20,   572,    14,    -1,    74,    19,    99,    13,    60,    20,
     572,    20,   572,    14,    -1,    74,    19,    99,    13,    60,
      20,   551,    20,   572,    20,   572,    14,    -1,    74,    19,
     102,    13,   551,    20,    71,    14,    -1,    74,    19,   103,
      13,    61,    14,    -1,    74,    19,   103,    13,    61,    20,
     551,    14,    -1,    74,    19,   106,    13,    62,    20,   551,
      14,    -1,    74,    19,   104,    13,    60,    20,   572,    14,
      -1,    74,    19,   104,    13,    60,    20,   551,    14,    -1,
      74,    19,   104,    13,    60,    14,    -1,    74,    19,   105,
      13,   572,    20,   551,    14,    -1,    74,    19,   107,    13,
      62,    20,   551,    14,    -1,    74,    19,   109,    13,   551,
      20,   551,    14,    -1,    74,    19,   108,    13,    62,    20,
     551,    20,   551,    20,   551,    14,    -1,    74,    19,   114,
      13,   551,    14,    -1,    74,    19,    96,    13,   551,    14,
      -1,    74,    19,    94,    -1,    74,    19,    90,    13,   551,
      14,    -1,    74,    19,    92,    13,   551,    14,    -1,   486,
      13,   615,    14,    -1,   486,    13,   616,    14,    -1,   487,
      13,   551,    14,    -1,   573,    -1,    67,    19,   451,    13,
     551,    14,    -1,    67,    19,   452,    13,    59,    14,    -1,
      67,    19,   452,    13,    62,    14,    -1,   613,    19,   291,
      -1,   146,    13,   572,    20,   572,    14,    -1,   556,    -1,
     558,   559,    -1,     9,   559,    -1,    11,   559,    -1,    10,
     559,    -1,   456,   559,    -1,   457,   559,    -1,   467,   559,
      -1,   468,   559,    -1,   469,   559,    -1,   470,   559,    -1,
     458,   559,    -1,   459,   559,    -1,   460,   559,    -1,   461,
     559,    -1,   464,   559,    -1,   466,   559,    -1,   465,   559,
      -1,     7,    -1,   531,    -1,   557,    -1,    13,   573,    14,
     557,    -1,   559,    -1,   560,     7,   559,    -1,   560,     8,
     559,    -1,   560,    12,   559,    -1,   560,    -1,   561,    10,
     560,    -1,   561,    11,   560,    -1,   561,    -1,   562,    -1,
     563,     6,   562,    -1,   563,     5,   562,    -1,   563,   138,
     562,    -1,   563,   139,   562,    -1,   563,    -1,   564,   140,
     563,    -1,   564,   141,   563,    -1,   551,   140,   551,    -1,
     551,   141,   551,    -1,   564,    -1,   565,    17,   564,    -1,
     565,    -1,   566,     4,   565,    -1,   566,    -1,   567,    18,
     566,    -1,   567,    -1,   568,   136,   567,    -1,   568,    -1,
     569,   137,   568,    -1,   569,    -1,   569,    21,   569,    22,
     570,    -1,   570,    -1,   571,    -1,   433,    -1,   434,    -1,
     435,    -1,   436,    -1,   437,    -1,   438,    -1,   439,    -1,
     440,    -1,   441,    -1,   442,    -1,   574,    19,   443,    -1,
      58,    -1,    77,    15,   572,    16,    -1,    35,   551,    -1,
      35,    13,   551,    14,    -1,    36,    13,   572,    20,   572,
      20,   573,    20,   572,    20,   551,    20,   572,    20,   572,
      14,    -1,    36,    13,   572,    20,   572,    20,   572,    20,
     573,    20,   572,    20,   551,    14,    -1,    36,    13,   572,
      20,   572,    20,   572,    20,   573,    20,   572,    20,   572,
      20,   551,    14,    -1,   311,    13,   551,    14,    -1,   312,
      13,   551,    14,    -1,    70,    13,   546,    14,    -1,    35,
      -1,    35,    13,   573,    20,   572,    20,   572,    20,   572,
      14,    -1,    35,    13,   573,    20,   572,    20,   572,    20,
     572,    20,   572,    14,    -1,    35,    13,   573,    20,   572,
      20,   574,    14,    -1,   574,    -1,   574,    15,   572,    16,
      -1,   262,    13,   593,    20,   572,    14,    -1,   263,    13,
     593,    20,   572,    14,    -1,   264,    13,   593,    20,   572,
      14,    -1,   265,    13,   593,    20,   593,    20,   572,    14,
      -1,   266,    13,   593,    20,   593,    20,   572,    14,    -1,
     146,    13,   593,    20,   593,    14,    -1,   150,    13,   574,
      20,    54,    14,    -1,   150,    13,   574,    20,    54,    20,
     573,    14,    -1,   150,    13,   574,    20,   574,    20,    54,
      14,    -1,   150,    13,   574,    20,   574,    20,    54,    20,
     573,    14,    -1,   150,    13,   574,    20,   574,    20,   574,
      20,    54,    14,    -1,   150,    13,   574,    20,   574,    20,
     574,    20,    54,    20,   573,    14,    -1,   151,    13,   593,
      20,   572,    20,   572,    20,   572,    20,   572,    14,    -1,
     504,    19,   505,    13,   574,    20,   572,    20,   572,    14,
      -1,   344,    13,   574,    14,    -1,   170,    13,   574,    20,
     572,    20,   572,    20,   572,    14,    -1,   345,    13,   574,
      14,    -1,   246,    13,   593,    20,   572,    14,    -1,   247,
      13,   574,    14,    -1,   248,    13,   574,    14,    -1,   249,
      13,   574,    14,    -1,   250,    13,   574,    20,   574,    20,
     572,    20,   572,    20,   572,    14,    -1,   251,    13,   574,
      14,    -1,   252,    13,   574,    20,   574,    20,   574,    20,
     572,    20,   574,    14,    -1,   253,    13,   574,    20,   574,
      20,   574,    20,   572,    20,   574,    14,    -1,   254,    13,
     574,    20,   574,    20,   574,    20,   572,    20,   574,    20,
     572,    20,   572,    14,    -1,   255,    13,   574,    20,   574,
      20,   574,    20,   572,    20,   574,    20,   572,    20,   572,
      20,   572,    20,   572,    14,    -1,   256,    13,   574,    20,
     574,    20,   574,    20,   574,    14,    -1,   256,    13,   574,
      20,   574,    20,   574,    20,   574,    20,   572,    14,    -1,
     257,    13,   574,    14,    -1,   257,    13,   574,    20,   574,
      14,    -1,   258,    13,   574,    20,   574,    14,    -1,   152,
      13,   593,    20,   572,    14,    -1,   153,    13,   574,    14,
      -1,   169,    13,   574,    14,    -1,   154,    13,   574,    20,
     572,    14,    -1,   273,    13,   574,    14,    -1,   155,    13,
     574,    20,   572,    14,    -1,   156,    13,   574,    20,   572,
      14,    -1,   159,    13,   593,    20,   572,    14,    -1,   574,
      15,   617,    16,    -1,   574,    15,    22,    20,    22,    20,
     572,    22,   572,    16,    -1,   157,    13,   574,    20,   572,
      20,   572,    20,   572,    20,   572,    20,   572,    20,   572,
      14,    -1,   161,    13,   574,    20,   572,    20,   572,    20,
     572,    14,    -1,   161,    13,   574,    20,   572,    20,   572,
      14,    -1,   161,    13,   574,    20,   572,    20,   572,    20,
     572,    20,   572,    14,    -1,   162,    13,   574,    20,   572,
      20,   572,    20,   572,    14,    -1,   162,    13,   574,    20,
     572,    20,   572,    14,    -1,   162,    13,   574,    20,   572,
      20,   572,    20,   572,    20,   572,    14,    -1,   163,    13,
     574,    20,   572,    20,   572,    14,    -1,   163,    13,   574,
      20,   572,    20,   572,    20,   572,    20,   572,    14,    -1,
     164,    13,   574,    20,   572,    20,   572,    14,    -1,   164,
      13,   574,    20,   572,    20,   572,    20,   572,    20,   572,
      14,    -1,   165,    19,    52,    -1,   165,    19,    53,    -1,
     176,    19,   221,    13,   574,    20,   572,    14,    -1,   176,
      19,   221,    13,   574,    20,   574,    14,    -1,   176,    19,
      52,    -1,   176,    19,   186,    13,   574,    14,    -1,   165,
      13,   574,    20,   572,    20,   572,    20,   572,    20,   572,
      14,    -1,   210,    13,   574,    20,   574,    20,   572,    20,
     572,    20,   572,    14,    -1,   167,    13,   574,    20,   572,
      20,   572,    20,   572,    20,   572,    20,   572,    14,    -1,
     166,    13,   574,    20,   572,    20,   572,    20,   572,    20,
     572,    14,    -1,   211,    19,   221,    13,   574,    20,   572,
      20,   572,    20,   572,    14,    -1,   212,    19,   221,    13,
     574,    20,   572,    20,   572,    20,   572,    20,   572,    20,
     572,    14,    -1,   213,    13,   574,    14,    -1,   214,    13,
     574,    20,   572,    20,   572,    14,    -1,   214,    13,   574,
      20,   572,    20,   572,    20,   617,    14,    -1,   214,    13,
     574,    20,   572,    20,   572,    20,   572,    20,   617,    14,
      -1,   215,    13,   574,    20,   572,    20,   572,    20,   617,
      14,    -1,   215,    13,   574,    20,   572,    20,   572,    20,
     572,    20,   617,    14,    -1,   216,    13,   574,    20,   572,
      20,   572,    20,   617,    14,    -1,   217,    13,   574,    20,
     572,    20,   572,    20,   572,    20,   617,    14,    -1,   218,
      13,   574,    20,   572,    20,   572,    20,   572,    20,   617,
      14,    -1,   219,    13,   574,    20,   572,    20,   572,    20,
     572,    20,   572,    20,   617,    14,    -1,   220,    13,   574,
      20,   572,    20,   572,    20,   572,    20,   572,    14,    -1,
     225,    13,   574,    20,   572,    20,   572,    14,    -1,   260,
      13,   574,    20,   572,    20,   572,    20,   572,    20,   572,
      20,   572,    14,    -1,   429,    13,   574,    14,    -1,   430,
      13,   574,    14,    -1,   431,    13,   574,    14,    -1,   432,
      13,   574,    14,    -1,    65,    19,   347,    -1,    65,    19,
     348,    -1,    63,    19,   347,    -1,   282,    13,   574,    20,
     572,    14,    -1,   283,    13,   574,    20,   572,    14,    -1,
     284,    13,   574,    20,   572,    14,    -1,   285,    13,   574,
      20,   572,    14,    -1,   208,    13,   593,    20,   593,    20,
     572,    14,    -1,   209,    13,   593,    20,   593,    20,   572,
      20,   572,    20,   572,    20,   572,    14,    -1,   208,    13,
     593,    20,   593,    20,   572,    20,   572,    20,   572,    14,
      -1,   208,    13,   593,    20,   593,    20,   572,    20,   572,
      20,   572,    20,   572,    14,    -1,   208,    13,   593,    20,
     593,    20,   574,    20,   572,    20,   572,    14,    -1,   313,
      13,   574,    20,   574,    14,    -1,   314,    13,   574,    20,
     574,    20,   593,    14,    -1,   318,    13,   574,    20,   572,
      20,   572,    20,   572,    14,    -1,   319,    13,   574,    20,
     572,    20,   572,    20,   572,    14,    -1,   319,    13,   574,
      20,   572,    20,   572,    20,   572,    20,   572,    14,    -1,
     320,    13,   574,    20,   572,    14,    -1,   321,    13,   574,
      20,   572,    14,    -1,   322,    13,   574,    20,   572,    14,
      -1,   323,    13,   574,    20,   572,    14,    -1,   324,    13,
     574,    20,   572,    14,    -1,   325,    13,   574,    20,   572,
      14,    -1,   326,    13,   574,    20,   572,    14,    -1,   327,
      13,   574,    20,   572,    14,    -1,   327,    13,   574,    20,
     572,    20,   572,    14,    -1,   328,    13,   574,    20,   572,
      20,   572,    20,   572,    14,    -1,   329,    13,   593,    14,
      -1,   574,    13,   593,    14,    -1,   446,    13,   593,    20,
     572,    20,   572,    20,   572,    14,    -1,   447,    13,   593,
      20,   572,    20,   572,    20,   572,    14,    -1,   498,    13,
     593,    14,    -1,   498,    13,   593,    20,   572,    14,    -1,
     501,    13,   593,    20,   572,    14,    -1,   499,    13,   593,
      20,   572,    20,   572,    20,   572,    20,   572,    14,    -1,
     500,    13,   574,    20,   574,    20,   572,    20,   572,    20,
     572,    20,   572,    20,   572,    20,   572,    20,   572,    20,
     572,    20,   572,    20,   572,    20,   572,    20,   572,    14,
      -1,   503,    13,   593,    20,   572,    20,   572,    14,    -1,
     613,    19,   383,    13,    14,    -1,   613,    19,   292,    13,
     572,    14,    -1,   613,    19,   384,    13,    14,    -1,   613,
      19,   385,    13,    14,    -1,   613,    19,   382,    13,   574,
      14,    -1,   509,    13,   593,    20,   572,    14,    -1,   509,
      13,   593,    14,    -1,   510,    13,   593,    20,   572,    14,
      -1,   510,    13,   593,    14,    -1,   515,    13,   593,    20,
     593,    14,    -1,   516,    13,   593,    14,    -1,   517,    13,
     551,    14,    -1,   488,    13,   593,    20,   572,    20,   572,
      20,   572,    20,   572,    20,   572,    20,   572,    20,   572,
      14,    -1,   290,    13,   613,    20,   574,    20,   593,    14,
      -1,   294,    13,   613,    20,   551,    14,    -1,   575,    -1,
      13,   593,    14,    -1,   576,    -1,   577,    -1,   558,   579,
      -1,    11,   579,    -1,    10,   579,    -1,   456,   579,    -1,
     457,   579,    -1,   467,   579,    -1,   468,   579,    -1,   469,
     579,    -1,   470,   579,    -1,   458,   579,    -1,   459,   579,
      -1,   460,   579,    -1,   461,   579,    -1,   464,   579,    -1,
     466,   579,    -1,   465,   579,    -1,   471,   579,    -1,   578,
      -1,    13,   573,    14,   578,    -1,   579,    -1,   580,     7,
     559,    -1,   580,     8,   559,    -1,   580,     7,   579,    -1,
     580,     8,   579,    -1,   580,     4,   579,    -1,   580,    -1,
     581,    -1,   582,    10,   560,    -1,   582,    11,   560,    -1,
     582,    10,   580,    -1,   582,    11,   580,    -1,   582,    -1,
     583,    -1,   584,     6,   583,    -1,   584,     5,   583,    -1,
     584,   138,   583,    -1,   584,   139,   583,    -1,   584,     6,
     562,    -1,   584,     5,   562,    -1,   584,   138,   562,    -1,
     584,   139,   562,    -1,   584,    -1,   585,   140,   584,    -1,
     585,   141,   584,    -1,   585,   140,   562,    -1,   585,   141,
     562,    -1,   585,    -1,   586,    17,   585,    -1,   586,    -1,
     587,    -1,   588,    18,   587,    -1,   588,    -1,   589,   136,
     588,    -1,   589,    -1,   590,   137,   589,    -1,   590,    -1,
     590,    21,   590,    22,   591,    -1,   591,    -1,   578,   144,
     592,    -1,   592,    -1,    75,    -1,    65,    19,   401,    -1,
     403,    13,    75,    20,    75,    20,   572,    14,    -1,    37,
      13,   551,    14,    -1,   404,    13,   572,    20,   572,    14,
      -1,    66,    -1,   405,    13,   612,    14,    -1,   595,    -1,
      13,   612,    14,    -1,   596,    -1,   597,    -1,   558,   599,
      -1,    11,   599,    -1,    10,   599,    -1,   599,   142,    -1,
     456,   599,    -1,   457,   599,    -1,   467,   599,    -1,   468,
     599,    -1,   469,   599,    -1,   470,   599,    -1,   458,   599,
      -1,   459,   599,    -1,   460,   599,    -1,   461,   599,    -1,
     464,   599,    -1,   466,   599,    -1,   465,   599,    -1,   598,
      -1,   599,    -1,   600,     7,   559,    -1,   600,   143,   599,
      -1,   600,     7,   599,    -1,   600,    -1,   601,    10,   560,
      -1,   601,    11,   560,    -1,   601,    10,   600,    -1,   601,
      11,   600,    -1,   601,    -1,   602,    -1,   603,    -1,   604,
      -1,   605,    -1,   606,    -1,   607,    -1,   608,    -1,   609,
      -1,   610,    -1,   611,    -1,    64,    -1,    76,    15,   572,
      16,    -1,   334,    13,   593,    20,   572,    14,    -1,   337,
      13,   574,    20,   572,    14,    -1,   334,    13,   593,    20,
     572,    20,   574,    14,    -1,   343,    13,   593,    20,   572,
      20,   593,    14,    -1,   338,    13,   613,    14,    -1,   338,
      13,   613,    20,   572,    14,    -1,   339,    13,   574,    20,
     572,    14,    -1,   340,    13,   613,    20,   572,    14,    -1,
     342,    13,   613,    20,   572,    14,    -1,   346,    13,    14,
      -1,   346,   551,    -1,   346,    13,   551,    14,    -1,   346,
      -1,   293,    13,   551,    14,    -1,   293,    13,   551,    20,
     572,    14,    -1,   613,    -1,   277,    13,   574,    14,    -1,
     278,    13,   613,    14,    -1,   278,    13,   613,    20,   572,
      20,   572,    20,   572,    14,    -1,   279,    13,   613,    20,
     572,    14,    -1,   286,    13,   613,    20,   572,    20,   572,
      20,   572,    20,   572,    20,   572,    20,   572,    14,    -1,
     287,    13,   593,    20,   572,    20,   572,    20,   572,    20,
     572,    20,   572,    20,   572,    20,   572,    14,    -1,   288,
      13,   593,    20,   572,    20,   572,    20,   572,    14,    -1,
     289,    13,   593,    20,   572,    20,   572,    20,   572,    20,
     572,    20,   572,    20,   572,    20,   572,    20,   572,    14,
      -1,   289,    13,   593,    20,   572,    20,   572,    20,   572,
      20,   572,    20,   572,    14,    -1,   613,    19,   281,    13,
     572,    20,   572,    14,    -1,   506,    13,   593,    14,    -1,
     506,    13,   593,    20,   572,    14,    -1,   506,    13,   593,
      20,   572,    20,   572,    14,    -1,   508,    13,   593,    20,
     572,    20,   572,    14,    -1,   507,    13,   593,    20,   572,
      20,   572,    20,   593,    20,   593,    14,    -1,   507,    13,
     593,    20,   572,    20,   572,    20,   593,    20,   593,    20,
     593,    20,   572,    14,    -1,   512,    13,   593,    20,   593,
      20,   593,    20,   572,    20,   572,    20,   572,    20,   572,
      14,    -1,   512,    13,   593,    20,   593,    20,   593,    20,
     572,    20,   572,    20,   572,    20,   572,    20,   572,    14,
      -1,   512,    13,   593,    20,   593,    20,   593,    20,   572,
      20,   572,    20,   572,    14,    -1,   512,    13,   593,    20,
     572,    20,   572,    20,   572,    20,   572,    20,   572,    14,
      -1,   514,    13,   593,    20,   593,    20,   593,    20,   572,
      20,   572,    20,   572,    20,   572,    14,    -1,   514,    13,
     593,    20,   593,    20,   593,    20,   572,    20,   572,    20,
     572,    20,   572,    20,   593,    20,   593,    14,    -1,    57,
      -1,    60,    -1,    59,    -1,    61,    -1,   574,    -1,    63,
      -1,    64,    -1,    65,    -1,    67,    -1,    68,    -1,    69,
      -1,    70,    -1,    71,    -1,    72,    -1,    73,    -1,    62,
      -1,    66,    -1,    75,    -1,    74,    -1,    76,    -1,    77,
      -1,   572,    22,   572,    20,   572,    22,   572,    20,   572,
      22,   572,    -1,   572,    22,   572,    20,   572,    22,   572,
      -1,   574,    -1,    63,    -1
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
    2146,  2148,  2150,  2152,  2159,  2163,  2172,  2176,  2180,  2184,
    2188,  2192,  2196,  2200,  2204,  2208,  2212,  2219,  2228,  2235,
    2246,  2253,  2262,  2271,  2280,  2289,  2296,  2300,  2305,  2307,
    2309,  2311,  2313,  2315,  2317,  2319,  2350,  2375,  2380,  2389,
    2391,  2395,  2396,  2398,  2402,  2404,  2408,  2411,  2416,  2419,
    2424,  2426,  2430,  2433,  2438,  2441,  2446,  2448,  2452,  2453,
    2456,  2459,  2462,  2465,  2468,  2473,  2478,  2483,  2488,  2493,
    2495,  2497,  2499,  2506,  2513,  2520,  2522,  2526,  2531,  2536,
    2538,  2540,  2544,  2548,  2550,  2554,  2555,  2556,  2558,  2560,
    2562,  2564,  2566,  2568,  2570,  2574,  2576,  2581,  2588,  2597,
    2608,  2619,  2630,  2639,  2646,  2650,  2654,  2658,  2661,  2665,
    2669,  2673,  2680,  2685,  2696,  2701,  2712,  2717,  2722,  2727,
    2732,  2737,  2742,  2750,  2758,  2766,  2776,  2784,  2791,  2796,
    2800,  2804,  2808,  2812,  2816,  2820,  2824,  2828,  2832,  2836,
    2840,  2844,  2851,  2860,  2871,  2884,  2895,  2908,  2917,  2924,
    2933,  2942,  2951,  2960,  2967,  2976,  2985,  2994,  3007,  3014,
    3021,  3025,  3032,  3039,  3044,  3049,  3054,  3056,  3063,  3070,
    3077,  3081,  3088,  3090,  3093,  3096,  3099,  3102,  3105,  3108,
    3111,  3114,  3117,  3120,  3123,  3126,  3129,  3132,  3135,  3138,
    3141,  3143,  3145,  3147,  3152,  3154,  3158,  3162,  3166,  3168,
    3172,  3176,  3178,  3180,  3184,  3188,  3192,  3196,  3198,  3202,
    3206,  3210,  3214,  3216,  3220,  3222,  3226,  3228,  3232,  3234,
    3238,  3240,  3244,  3246,  3252,  3254,  3256,  3258,  3260,  3262,
    3264,  3266,  3268,  3270,  3272,  3274,  3276,  3280,  3282,  3287,
    3290,  3295,  3312,  3327,  3344,  3349,  3354,  3359,  3361,  3372,
    3385,  3394,  3396,  3401,  3408,  3415,  3422,  3431,  3440,  3447,
    3454,  3463,  3472,  3483,  3494,  3507,  3520,  3531,  3536,  3547,
    3552,  3559,  3564,  3569,  3574,  3587,  3592,  3605,  3618,  3635,
    3656,  3667,  3680,  3685,  3692,  3699,  3706,  3711,  3716,  3723,
    3728,  3735,  3742,  3749,  3754,  3765,  3782,  3793,  3802,  3815,
    3826,  3835,  3848,  3857,  3870,  3879,  3892,  3896,  3900,  3909,
    3918,  3922,  3929,  3942,  3955,  3970,  3983,  3996,  4013,  4018,
    4027,  4038,  4051,  4062,  4075,  4086,  4099,  4112,  4127,  4140,
    4149,  4164,  4169,  4174,  4179,  4184,  4188,  4192,  4196,  4203,
    4210,  4217,  4224,  4233,  4248,  4261,  4276,  4289,  4296,  4305,
    4316,  4327,  4340,  4347,  4354,  4361,  4368,  4375,  4382,  4389,
    4396,  4405,  4416,  4421,  4426,  4437,  4448,  4453,  4460,  4467,
    4480,  4511,  4520,  4526,  4533,  4539,  4545,  4552,  4559,  4564,
    4571,  4576,  4583,  4588,  4593,  4612,  4621,  4628,  4630,  4634,
    4636,  4638,  4641,  4644,  4647,  4650,  4653,  4656,  4659,  4662,
    4665,  4668,  4671,  4674,  4677,  4680,  4683,  4686,  4689,  4691,
    4696,  4698,  4702,  4706,  4710,  4714,  4718,  4720,  4722,  4726,
    4730,  4734,  4738,  4740,  4742,  4746,  4750,  4754,  4758,  4762,
    4766,  4770,  4774,  4776,  4780,  4784,  4788,  4792,  4794,  4798,
    4800,  4802,  4806,  4808,  4812,  4814,  4818,  4820,  4826,  4828,
    4832,  4834,  4836,  4840,  4849,  4854,  4861,  4863,  4868,  4870,
    4874,  4876,  4878,  4881,  4884,  4887,  4890,  4893,  4896,  4899,
    4902,  4905,  4908,  4911,  4914,  4917,  4920,  4923,  4926,  4929,
    4931,  4933,  4937,  4941,  4945,  4947,  4951,  4955,  4959,  4963,
    4965,  4967,  4969,  4971,  4973,  4975,  4977,  4979,  4981,  4983,
    4985,  4987,  4992,  4999,  5006,  5015,  5024,  5029,  5036,  5043,
    5050,  5057,  5061,  5064,  5069,  5071,  5076,  5083,  5085,  5090,
    5095,  5106,  5113,  5130,  5149,  5160,  5181,  5196,  5205,  5210,
    5217,  5226,  5235,  5248,  5265,  5282,  5301,  5316,  5331,  5348,
    5369,  5371,  5373,  5375,  5377,  5379,  5381,  5383,  5385,  5387,
    5389,  5391,  5393,  5395,  5397,  5399,  5401,  5403,  5405,  5407,
    5409,  5411,  5423,  5431,  5433
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   962,   962,   963,   967,   967,   968,   969,   970,   970,
     971,   971,   972,   972,   973,   973,   974,   974,   975,   975,
     978,   979,   984,  1003,  1026,  1061,  1083,  1098,  1119,  1118,
    1148,  1147,  1188,  1207,  1229,  1236,  1271,  1277,  1286,  1296,
    1304,  1308,  1322,  1336,  1350,  1360,  1376,  1396,  1408,  1419,
    1430,  1442,  1453,  1473,  1495,  1507,  1518,  1523,  1533,  1556,
    1565,  1577,  1595,  1617,  1630,  1649,  1662,  1681,  1694,  1713,
    1727,  1747,  1780,  1797,  1802,  1806,  1810,  1815,  1819,  1834,
    1844,  1855,  1858,  1908,  1928,  1973,  1990,  2002,  2042,  2055,
    2090,  2120,  2140,  2144,  2148,  2152,  2156,  2160,  2164,  2168,
    2172,  2176,  2181,  2185,  2196,  2209,  2219,  2228,  2239,  2247,
    2259,  2508,  2518,  2528,  2538,  2592,  2600,  2608,  2617,  2627,
    2633,  2644,  2650,  2657,  2663,  2673,  2683,  2699,  2711,  2721,
    2769,  2784,  2805,  2836,  2851,  2858,  2865,  2883,  2906,  2911,
    2916,  2929,  2940,  2949,  2959,  2967,  2984,  3000,  3017,  3037,
    3052,  3070,  3083,  3097,  3106,  3120,  3131,  3144,  3162,  3184,
    3212,  3242,  3274,  3279,  3297,  3302,  3307,  3312,  3317,  3322,
    3336,  3351,  3368,  3382,  3402,  3407,  3412,  3419,  3428,  3436,
    3441,  3448,  3453,  3458,  3478,  3502,  3507,  3512,  3517,  3522,
    3527,  3532,  3537,  3542,  3547,  3552,  3557,  3562,  3567,  3572,
    3577,  3582,  3595,  3600,  3605,  3613,  3618,  3623,  3628,  3633,
    3638,  3643,  3648,  3653,  3658,  3663,  3668,  3673,  3677,  3704,
    3717,  3722,  3726,  3732,  3745,  3751,  3757,  3763,  3770,  3777,
    3784,  3793,  3804,  3819,  3834,  3842,  3849,  3856,  3862,  3866,
    3870,  3907,  3913,  3920,  3927,  3938,  3946,  3963,  3973,  3978,
    3985,  3992,  4000,  4008,  4027,  4043,  4060,  4077,  4082,  4087,
    4092,  4097,  4105,  4206,  4240,  4247,  4255,  4261,  4268,  4278,
    4287,  4294,  4301,  4311,  4318,  4332,  4346,  4354,  4359,  4367,
    4375,  4386,  4398,  4410,  4422,  4428,  4437,  4446,  4459,  4466,
    4477,  4499,  4525,  4553,  4563,  4576,  4586,  4608,  4637,  4654,
    4669,  4676,  4698,  4717,  4735,  4749,  4754,  4759,  4768,  4773,
    4782,  4796,  4803,  4810,  4812,  4829,  4845,  4884,  4897,  4941,
    4946,  4951,  4956,  4962,  4979,  4989,  5004,  5010,  5017,  5023,
    5029,  5035,  5041,  5056,  5067,  5073,  5087,  5101,  5118,  5125,
    5146,  5164,  5183,  5203,  5223,  5243,  5250,  5255,  5261,  5266,
    5271,  5276,  5281,  5286,  5291,  5296,  5331,  5358,  5365,  5387,
    5395,  5412,  5416,  5423,  5430,  5438,  5446,  5455,  5462,  5469,
    5476,  5483,  5490,  5497,  5504,  5511,  5518,  5525,  5535,  5540,
    5549,  5556,  5563,  5570,  5577,  5584,  5591,  5598,  5605,  5613,
    5618,  5633,  5639,  5653,  5669,  5685,  5709,  5713,  5724,  5743,
    5753,  5754,  5764,  5772,  5775,  5786,  5787,  5790,  5791,  5799,
    5807,  5816,  5820,  5824,  5828,  5836,  5837,  5852,  5868,  5882,
    5897,  5914,  5930,  5944,  5957,  5978,  6038,  6063,  6083,  6102,
    6109,  6117,  6122,  6127,  6155,  6161,  6172,  6191,  6210,  6229,
    6248,  6267,  6286,  6309,  6331,  6354,  6361,  6385,  6408,  6416,
    6426,  6436,  6446,  6456,  6466,  6476,  6490,  6507,  6523,  6528,
    6533,  6537,  6544,  6552,  6587,  6625,  6642,  6662,  6674,  6691,
    6711,  6744,  6763,  6785,  6801,  6819,  6843,  6864,  6892,  6906,
    6916,  6929,  6943,  6958,  6966,  6974,  6986,  6990,  7005,  7012,
    7022,  7034,  7047,  7048,  7049,  7050,  7051,  7052,  7053,  7054,
    7055,  7056,  7057,  7065,  7066,  7067,  7068,  7069,  7081,  7093,
    7109,  7110,  7114,  7116,  7132,  7133,  7134,  7135,  7139,  7140,
    7141,  7145,  7150,  7151,  7152,  7153,  7154,  7158,  7159,  7160,
    7161,  7162,  7166,  7167,  7175,  7176,  7180,  7184,  7191,  7195,
    7202,  7206,  7213,  7214,  7221,  7225,  7231,  7236,  7240,  7244,
    7248,  7252,  7256,  7260,  7264,  7268,  7272,  7280,  7285,  7302,
    7308,  7314,  7372,  7426,  7482,  7503,  7524,  7538,  7567,  7575,
    7594,  7620,  7633,  7711,  7778,  7786,  7794,  7804,  7814,  7844,
    7862,  7882,  7900,  7920,  7938,  7957,  7997,  8012,  8026,  8042,
    8065,  8079,  8093,  8107,  8121,  8156,  8170,  8191,  8212,  8253,
    8299,  8316,  8335,  8349,  8363,  8377,  8396,  8411,  8426,  8443,
    8464,  8481,  8497,  8509,  8538,  8558,  8603,  8615,  8626,  8639,
    8651,  8662,  8688,  8715,  8747,  8764,  8782,  8795,  8808,  8828,
    8851,  8865,  8880,  8914,  8951,  8986,  9019,  9036,  9053,  9067,
    9088,  9111,  9135,  9160,  9185,  9207,  9229,  9253,  9296,  9320,
    9352,  9375,  9412,  9449,  9486,  9521,  9526,  9535,  9540,  9551,
    9561,  9571,  9580,  9601,  9631,  9657,  9686,  9719,  9730,  9746,
    9756,  9766,  9781,  9795,  9809,  9822,  9835,  9847,  9859,  9871,
    9882,  9895,  9922,  9955, 10071, 10095, 10137, 10149, 10158, 10167,
   10190, 10215, 10228, 10238, 10275, 10293, 10311, 10321, 10331, 10339,
   10347, 10355, 10380, 10400, 10408, 10442, 10465, 10485, 10485, 10487,
   10489, 10490, 10491, 10492, 10493, 10494, 10495, 10496, 10497, 10498,
   10499, 10500, 10501, 10502, 10503, 10504, 10505, 10506, 10520, 10521,
   10543, 10544, 10550, 10552, 10553, 10554, 10557, 10562, 10563, 10564,
   10565, 10566, 10569, 10573, 10574, 10575, 10576, 10577, 10578, 10579,
   10580, 10581, 10585, 10586, 10587, 10588, 10589, 10593, 10594, 10599,
   10603, 10604, 10608, 10609, 10613, 10614, 10618, 10619, 10623, 10624,
   10627, 10631, 10641, 10654, 10665, 10682, 10689, 10699, 10714, 10714,
   10716, 10718, 10719, 10720, 10721, 10722, 10731, 10732, 10733, 10734,
   10735, 10736, 10737, 10738, 10739, 10740, 10741, 10742, 10743, 10747,
   10749, 10750, 10751, 10752, 10762, 10763, 10764, 10765, 10766, 10769,
   10773, 10777, 10781, 10786, 10790, 10794, 10798, 10802, 10806, 10809,
   10814, 10819, 10835, 10846, 10856, 10876, 10910, 10919, 10928, 10937,
   10946, 10954, 10960, 10966, 10972, 10998, 11012, 11028, 11038, 11056,
   11084, 11111, 11126, 11149, 11183, 11215, 11262, 11303, 11327, 11337,
   11360, 11372, 11385, 11422, 11465, 11513, 11565, 11608, 11636, 11669,
   11712, 11716, 11717, 11718, 11719, 11723, 11724, 11725, 11726, 11727,
   11728, 11729, 11730, 11731, 11732, 11733, 11734, 11735, 11736, 11737,
   11738, 11743, 11751, 11758, 11774
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
       2,     2,     2,     2,     2,     2,   531,     2,     2,     2,
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
     525,   526,   527,   528,   529,   530
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 15957;
  const int Parser::yynnts_ = 86;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 402;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 532;

  const unsigned int Parser::yyuser_token_number_max_ = 785;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // yyip

/* Line 1054 of lalr1.cc  */
#line 20602 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"


/* Line 1056 of lalr1.cc  */
#line 11794 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"

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





