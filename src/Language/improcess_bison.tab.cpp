
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
#line 11 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"

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
    wxScheduleTimer( AMIFunction::ptr& callback)
    {
      f = callback;
    }

    ~wxScheduleTimer()
    { 
      //cout << "~wxScheduleTimer()" << endl; 
    }

    //Called each time the timer's timeout expires
    void Notify();

  private:
    AMIFunction::ptr f;
};

// create a array of shared pointers
// to delete the wxScheduleTimer when necessary
static std::list<wxScheduleTimer::ptr> schedule_timers;

static void CB_ParamWin( void* cd ) {

  AMIFunction::ptr f;
  f = *(AMIFunction::ptr*) (cd);

  GB_driver.yyip_call_function(f);

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
#line 390 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.tab.cpp"


#include "improcess_bison.tab.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 942 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"


#include "driver.h"
#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex



/* Line 317 of lalr1.cc  */
#line 413 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.tab.cpp"

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
#line 482 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.tab.cpp"
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
        case 53: /* "ASTRING" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 589 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.tab.cpp"
	break;
      case 56: /* "IDENTIFIER" */

/* Line 480 of lalr1.cc  */
#line 936 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 598 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.tab.cpp"
	break;
      case 544: /* "primary_expr_string" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 607 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.tab.cpp"
	break;
      case 545: /* "postfix_expr_string" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 616 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.tab.cpp"
	break;
      case 546: /* "additive_expr_string" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 625 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.tab.cpp"
	break;
      case 547: /* "expr_string" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 634 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.tab.cpp"
	break;
      case 548: /* "instr_block" */

/* Line 480 of lalr1.cc  */
#line 937 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ablock); };

/* Line 480 of lalr1.cc  */
#line 643 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.tab.cpp"
	break;
      case 611: /* "identifier" */

/* Line 480 of lalr1.cc  */
#line 936 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 652 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.tab.cpp"
	break;
      case 613: /* "image_extent" */

/* Line 480 of lalr1.cc  */
#line 938 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->imageextent); };

/* Line 480 of lalr1.cc  */
#line 661 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.tab.cpp"
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
#line 378 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}

/* Line 553 of lalr1.cc  */
#line 747 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.tab.cpp"

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
#line 981 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1000 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1023 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1057 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1079 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1094 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1114 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      GB_driver.procedure_declaration = true;
    }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 1119 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1143 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      // allow overriding current functions
      GB_driver.procedure_declaration = true;
    }
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 1149 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1185 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1203 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      Variable*       var   = (yysemantic_stack_[(2) - (1)].variable);
      AMIClass::ptr ac = *(AMIClass::ptr*) (var->Pointer());
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));

      AMIObject* amiobject;

      amiobject = new AMIObject;

      amiobject->SetName(ident->GetName());
      amiobject->SetClass(ac);

      Vars.AddVar( type_ami_object, ident, (void*) amiobject);

    }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 1221 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
       driver.res_print((yysemantic_stack_[(3) - (2)].astring));
       driver.parse_script((yysemantic_stack_[(3) - (2)].astring));
       delete [] (yysemantic_stack_[(3) - (2)].astring);
     }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 1228 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1263 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      string_ptr inputstring( new std::string((yysemantic_stack_[(2) - (2)].astring)));
      driver.parse_string( *inputstring,
                          "'eval string' command");
     }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 1269 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          Variable*       var   = (yysemantic_stack_[(5) - (1)].variable);
          ParamList::ptr  param((yysemantic_stack_[(5) - (3)].paramlist));
          AMIFunction::ptr f;

          f = *(AMIFunction::ptr*) (var->Pointer());

        driver.yyip_call_function(f,param);

        if (GB_debug)
          cerr  << "End function body = "
                << f->GetString()
                << endl;

        }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 1285 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          Variable*    var   = (yysemantic_stack_[(2) - (1)].variable);
          AMIFunction::ptr f;

          f = *(AMIFunction::ptr*) (var->Pointer());

          // Call the function
          driver.yyip_call_function(f);
        }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 1297 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1305 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
           YYABORT;
         }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1310 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1324 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1338 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1352 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1362 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1378 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

        wxScheduleTimer::ptr w = wxScheduleTimer::ptr(new wxScheduleTimer(  *(AMIFunction::ptr*) (var->Pointer()) ));
        // add to the list of schedule timers
        schedule_timers.push_back(w);
        w->Start(ms,wxTIMER_ONE_SHOT);

      }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1398 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1410 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1421 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1432 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1444 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1455 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
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
#line 1471 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1493 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1505 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1516 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr m1 = *((FloatMatrix::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer()));
          (*m1) = (yysemantic_stack_[(3) - (3)].adouble);
       }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 1521 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1531 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1554 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          Variables* contextptr = new Variables();
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
          contextptr->SetName(ident->GetName());

          Vars.AddVar(type_context,ident,(void*)contextptr);
        }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1563 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1575 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1593 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1615 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1628 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1647 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1660 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1679 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1692 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1711 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1725 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1745 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1778 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1795 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
            FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
            rewind(file.get());
        }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1800 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      GB_debug = 1;
        }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1804 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      GB_debug = 0;
        }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1808 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 1;
      verbose = 1;
    }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 1813 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 0;
    }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 1817 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1832 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1842 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1852 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          GB_main_wxFrame->Close(true);
        }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 1856 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          char titre[100];
          Variable* var;
          int var_context = Vars.GetContext((yysemantic_stack_[(2) - (2)].variable));

          if (var_context>=0) {
            sprintf(titre,"%s_draw",(yysemantic_stack_[(2) - (2)].variable)->Name().c_str());
            if (GB_debug) fprintf(stderr,
                      "SHOW var_image  title %s \n",
                      titre);
            //if (Vars.GetCurrentContext()->GetVar(titre,&var)) {
            if (Vars.GetVar(titre,&var,var_context)) {
              DessinImageParametres* param;
              DessinImage::ptr di;
              di = *((DessinImage::ptr*) var->Pointer());
              param = di->GetParam();
              param->_MAJ.MAJCoupes();
              di->Paint();
            }
            else
            {
              if (GB_debug) fprintf(stderr,"SHOW var_image creating title %s \n",titre);
              DessinImage* di;

              std::string varname(titre);

              di = CreateIDraw( varname,
                    *((InrImage::ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer()));

              Variable* newvar = Vars.AddVar(type_imagedraw,titre, (void*) di,
                          var_context);
              di->SetCloseFunction(
                (void*) CB_delete_imagedraw,
                (void*) (newvar));
            }
          } // var_context >=0
        }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1894 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1914 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          string    titre;
          Viewer3D* surfdraw;
          Variable* var;
          int var_context = Vars.GetContext((yysemantic_stack_[(2) - (2)].variable));

          if (var_context>=0) {
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
        }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1945 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1962 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 1974 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 2014 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 2027 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 2062 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 2092 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 2112 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          (*(*(float_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))++;
        }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 2116 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          (*(*(float_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))--;
        }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 2120 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          *(*(float_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer()) = (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 2124 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          (*(*(int_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))++;
        }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 2128 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          (*(*(int_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))--;
        }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 2132 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          *(*(int_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer()) = (int) (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 2136 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
           *(*(uchar_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer()) = (unsigned char) (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 2140 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
           (*(*(uchar_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))++;
        }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 2144 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
           (*(*(uchar_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))--;
        }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 2148 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          string_ptr newname( new std::string((yysemantic_stack_[(3) - (3)].astring)));
          (yysemantic_stack_[(3) - (1)].variable)->SetString(newname);
        }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 2153 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          Vars.display();
        }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 2157 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 2168 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 2181 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 2191 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 2200 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 2211 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
//         std::ostream streamtest(TC->GetLog());
//        std::cout=streamtest;
         //wxStreamToTextRedirector redirect(TC->GetLog());

         std::system("ls");
           }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 2219 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 2231 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 2480 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 112:

/* Line 678 of lalr1.cc  */
#line 2534 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(4) - (1)].variable)->Pointer());
          string_ptr text( new std::string((yysemantic_stack_[(4) - (4)].astring)));

          fprintf(file.get(),"%s",text->c_str());
          fflush(file.get());
        }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 2542 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(4) - (1)].variable)->Pointer());
          string_ptr text( new std::string((yysemantic_stack_[(4) - (4)].astring)));

          fprintf(file.get(),"%s\n",text->c_str());
          fflush(file.get());
        }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 2550 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
         /**
          Description:
            Print a string
          **/
          driver.res_print((yysemantic_stack_[(2) - (2)].astring));
          delete [] (yysemantic_stack_[(2) - (2)].astring);
        }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 2559 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 116:

/* Line 678 of lalr1.cc  */
#line 2569 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=driver.matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
      }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 2575 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 118:

/* Line 678 of lalr1.cc  */
#line 2586 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=driver.matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
          }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 2592 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
            FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(4) - (1)].variable)->Pointer());

          fprintf(file.get(),"%5.10f",(yysemantic_stack_[(4) - (4)].adouble));
          fflush(file.get());
        }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 2599 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
            printf("Files are not close anymore: delete the variable instead \n");
          //FILE_ptr file = *(FILE_ptr*) ($1->Pointer());
          //fclose(file.get());
        }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 2605 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 122:

/* Line 678 of lalr1.cc  */
#line 2615 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 123:

/* Line 678 of lalr1.cc  */
#line 2625 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 124:

/* Line 678 of lalr1.cc  */
#line 2641 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 125:

/* Line 678 of lalr1.cc  */
#line 2653 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          DessinImageParametres* param;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
          param = draw->GetParam();
          param->_MAJ.MAJCoupes();
          draw->Paint();
        }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 2663 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 127:

/* Line 678 of lalr1.cc  */
#line 2711 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 128:

/* Line 678 of lalr1.cc  */
#line 2726 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 129:

/* Line 678 of lalr1.cc  */
#line 2751 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 130:

/* Line 678 of lalr1.cc  */
#line 2778 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 131:

/* Line 678 of lalr1.cc  */
#line 2793 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(8) - (1)].variable)->Pointer());
          draw->SetVectorVisible( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 2800 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
          draw->CB_AfficheChampVect(draw.get(),NULL);
        }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 2807 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 134:

/* Line 678 of lalr1.cc  */
#line 2825 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 135:

/* Line 678 of lalr1.cc  */
#line 2848 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw= *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          draw->SetVectType((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 2853 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw= *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          draw->SetLineThickness((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 2858 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 138:

/* Line 678 of lalr1.cc  */
#line 2871 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          int width  = (int) (yysemantic_stack_[(8) - (5)].adouble);
          int height = (int) (yysemantic_stack_[(8) - (7)].adouble);

          DessinImage::ptr draw= *(DessinImage::ptr*) ((yysemantic_stack_[(8) - (1)].variable)->Pointer());
          draw->SetSize(width,height);
          draw->Update();


        }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 2882 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          ClasseCouleur c;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(16) - (1)].variable)->Pointer());
          c.FixeValeur((int)(yysemantic_stack_[(16) - (11)].adouble),(int)(yysemantic_stack_[(16) - (13)].adouble),(int)(yysemantic_stack_[(16) - (15)].adouble));
          draw->DessineCercle( (int) (yysemantic_stack_[(16) - (5)].adouble), (int) (yysemantic_stack_[(16) - (7)].adouble), (int) (yysemantic_stack_[(16) - (9)].adouble), c);
        }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 2891 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          // TODO: fix this memory problem ...
          InrImage* colmap=(InrImage*) driver.im_stack.GetLastImage();

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(10) - (1)].variable)->Pointer());
          draw->SetUserColormap( colmap,  (yysemantic_stack_[(10) - (7)].adouble),  (yysemantic_stack_[(10) - (9)].adouble));
          //      delete colmap;
        }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 2901 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          draw->SetGLWindow( *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer()));

        }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 2909 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 143:

/* Line 678 of lalr1.cc  */
#line 2926 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 144:

/* Line 678 of lalr1.cc  */
#line 2942 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 145:

/* Line 678 of lalr1.cc  */
#line 2959 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 146:

/* Line 678 of lalr1.cc  */
#line 2979 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 147:

/* Line 678 of lalr1.cc  */
#line 2994 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 148:

/* Line 678 of lalr1.cc  */
#line 3012 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 149:

/* Line 678 of lalr1.cc  */
#line 3025 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 150:

/* Line 678 of lalr1.cc  */
#line 3039 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
            DessinImage::ptr draw;

            draw = *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
            draw->SetPaintCallback( (void*) CB_ParamWin, (void*) (yysemantic_stack_[(6) - (5)].variable)->Pointer());
            // may be a pb to call Paint() here since it will start another interpreter ??? to check
            //draw->Paint();
        }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 3048 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 152:

/* Line 678 of lalr1.cc  */
#line 3062 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 153:

/* Line 678 of lalr1.cc  */
#line 3073 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 154:

/* Line 678 of lalr1.cc  */
#line 3086 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 155:

/* Line 678 of lalr1.cc  */
#line 3104 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 156:

/* Line 678 of lalr1.cc  */
#line 3126 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (5) expr:  X position
          (7) expr:  Y position
          (9) expr:  Z position

        Description:
          Set the current voxel (or pixel) of the image
          to the specified position.

        See Also:
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

  case 157:

/* Line 678 of lalr1.cc  */
#line 3153 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 158:

/* Line 678 of lalr1.cc  */
#line 3181 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 159:

/* Line 678 of lalr1.cc  */
#line 3212 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->FixeNom( (yysemantic_stack_[(6) - (5)].astring));
      delete [] (yysemantic_stack_[(6) - (5)].astring);
    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 3218 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 161:

/* Line 678 of lalr1.cc  */
#line 3236 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          Func_SetCoeffAnisoGS((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 3241 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetDistanceMap((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 3246 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseType((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 3251 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseSD((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 3256 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetMask(((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 3261 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 167:

/* Line 678 of lalr1.cc  */
#line 3275 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 168:

/* Line 678 of lalr1.cc  */
#line 3290 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 169:

/* Line 678 of lalr1.cc  */
#line 3307 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 170:

/* Line 678 of lalr1.cc  */
#line 3321 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 171:

/* Line 678 of lalr1.cc  */
#line 3341 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setdt((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 3346 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setneighborhood((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 3351 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {

      Func_SetCoeffAnisoGS3D((yysemantic_stack_[(8) - (5)].adouble),(yysemantic_stack_[(8) - (7)].adouble));

    }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 3358 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      float  error;

      error = Func_ItereAnisoGS();

      //driver.res_print("Error in AnisoGS.Iterate ");
    }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 3367 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      int res;

      res = Func_EndAnisoGS();

    }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 3375 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 3380 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {

      Func_EndWeickert();

    }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 3387 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 3392 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      Func_EndWeickert();
    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 3397 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 181:

/* Line 678 of lalr1.cc  */
#line 3418 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 182:

/* Line 678 of lalr1.cc  */
#line 3441 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetMeanCurv( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 3446 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetAffineCurvature( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 3451 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetBalloonScheme( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 3456 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetDMmethod( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 3461 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetThreads( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 3466 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 3471 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityLowThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 3476 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityHighThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 3481 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbabilityHighThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 3486 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumGaussians( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 3491 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetGaussian( (int) (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 3496 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumInitPoints( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 3501 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetInitPoint( (int) (yysemantic_stack_[(14) - (5)].adouble), (int) (yysemantic_stack_[(14) - (7)].adouble), (int) (yysemantic_stack_[(14) - (9)].adouble), (int) (yysemantic_stack_[(14) - (11)].adouble), (int) (yysemantic_stack_[(14) - (13)].adouble));
    }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 3506 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          Func_LevelSets_SetIsoContourBin( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 3511 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsVelocity(((InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get(),(yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 3516 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsExpansion((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 3521 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 199:

/* Line 678 of lalr1.cc  */
#line 3534 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsBandAndTube((int)(yysemantic_stack_[(8) - (5)].adouble),(int)(yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 3539 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSetCurvWeights( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 3544 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSetAdvectionField(
                ((InrImage::ptr*) (yysemantic_stack_[(10) - (5)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(10) - (7)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(10) - (9)].variable)->Pointer())->get());
        }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 3552 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetCurvatureData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 3557 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetDistanceMap( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 3562 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetAdvectionData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 3567 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetSkeleton( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 3572 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetVelocityData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 3577 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetExpansionData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 3582 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetCurvatureData( NULL );
        }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 3587 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetAdvectionData( NULL);
        }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 3592 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetVelocityData( NULL);
        }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 3597 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsSaveDistMap( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 3602 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsSaveSecDerGrad( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 3607 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      (yyval.aint) = Func_LevelSets_Iterate();
    }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 3612 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_End();
    }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 3616 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 216:

/* Line 678 of lalr1.cc  */
#line 3643 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 217:

/* Line 678 of lalr1.cc  */
#line 3656 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          Func_OrientField( ((InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->get() , ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );
        }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 3661 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
       Func_OrientPositive( ((InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->get() , ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );
    }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 3665 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())->Write((yysemantic_stack_[(4) - (4)].astring));
      delete [] (yysemantic_stack_[(4) - (4)].astring);
    }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 3671 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 221:

/* Line 678 of lalr1.cc  */
#line 3684 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetOwnMaterial( (int) (yysemantic_stack_[(6) - (5)].adouble));

        }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 3690 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->GetMaterial()._ambient.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 3696 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->GetMaterial()._diffuse.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 3702 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->GetMaterial()._specular.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 3709 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->GetMaterial()._shininess= (yysemantic_stack_[(6) - (5)].adouble);

        }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 3716 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->GetMaterial()._opacity= (yysemantic_stack_[(6) - (5)].adouble);

    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 3723 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        Sets the object visible or not visible in the scene.
      **/
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetVisible( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 3732 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Enable/Disable colormaterial for the associated surface.
        **/

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->GetMaterial()._colormaterial = (unsigned char) ((yysemantic_stack_[(6) - (5)].adouble)>0.5);

    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 3743 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 230:

/* Line 678 of lalr1.cc  */
#line 3758 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 231:

/* Line 678 of lalr1.cc  */
#line 3773 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());


      s->SetPointsColors( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 3781 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());
      InrImage::ptr i = InrImage::ptr(driver.im_stack.GetLastImage());
      // TODO: use smart pointer to image in SetColors ...
      s->SetColors( i.get() , (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 3788 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      InrImage::ptr i = InrImage::ptr(driver.im_stack.GetLastImage());
      s->SetColors( i.get() );

    }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 3795 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      s->Statistics( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

    }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 3801 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->MergePoints((yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 3805 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->Triangulate();
    }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 3809 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 238:

/* Line 678 of lalr1.cc  */
#line 3846 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      InrImage::ptr i = InrImage::ptr(driver.im_stack.GetLastImage());
      s->DisplacePoints( i.get() );
    }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 3852 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

      s->Translate( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble) );

    }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 3859 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

      s->Scale( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble),0 );

        }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 3866 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          int          w = (int) (yysemantic_stack_[(6) - (5)].adouble);

          Si w<1  AlorsFait w=1;
          Si w>10 AlorsFait w=10;

          s->_line_width = w;

        }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 3877 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

      s->RemoveLine((int)(yysemantic_stack_[(6) - (5)].adouble));
          s->GLRecomputeList();

    }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 3885 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 244:

/* Line 678 of lalr1.cc  */
#line 3902 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Remove selected lines
    **/
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

        s->RemoveSelection();
        s->GLRecomputeList();
    }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 3912 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
    (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GLRecomputeList();

        }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 3917 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

      s->RecomputeNormals();

        }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 3924 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

      s->InvertNormals();

        }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 3931 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          Func_ApplyvtkSmooth(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 3939 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          Func_vtkWindowedSinc(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 3947 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 251:

/* Line 678 of lalr1.cc  */
#line 3966 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 252:

/* Line 678 of lalr1.cc  */
#line 3982 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 253:

/* Line 678 of lalr1.cc  */
#line 3999 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 254:

/* Line 678 of lalr1.cc  */
#line 4016 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());
      s->AddPoint((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 4021 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      s->NewLine();
    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 4026 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      s->LineAddPointNumber( (int) (yysemantic_stack_[(6) - (5)].adouble) );
    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 4031 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      s->EndLine();
    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 4036 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      if (strlen((yysemantic_stack_[(4) - (3)].astring))<255) {
        strcpy(AMIFluid::FLUID_NAVIGATION_FILE,(yysemantic_stack_[(4) - (3)].astring));
      } else
        fprintf(stderr,"SetFluidNavFile() \t File too long \n");
      delete [] (yysemantic_stack_[(4) - (3)].astring);
        }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 4045 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 260:

/* Line 678 of lalr1.cc  */
#line 4145 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 261:

/* Line 678 of lalr1.cc  */
#line 4179 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->UserRotate((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 4186 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          SurfacePoly::ptr surf = SurfacePoly::ptr(driver.surf_stack.GetLastSurf());

          sdraw->GetCanvas()->AddSurface(surf);
          sdraw->Paint();
        }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 4194 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());
          sdraw->GetCanvas()->AddSurface(*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (3)].variable)->Pointer());
          //sdraw->Paint();
        }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 4200 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->RemoveSurface(*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (3)].variable)->Pointer());
          sdraw->Paint();
        }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 4207 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          /**
            Description: Removes the surface without swapping the 3D buffer
          **/
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->RemoveSurface(*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer());
          sdraw->Paint(false);
        }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 4217 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          /**
            Description:  Swaps the 3D buffer
          **/
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->AfficheBuffer();
        }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 4226 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC ( (int) (yysemantic_stack_[(6) - (5)].adouble) );
          sdraw->Paint();
        }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 4233 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
          sdraw->Paint();
        }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 4240 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          Si sdraw->GetCanvas()->SetCurrentObject( (int) (yysemantic_stack_[(6) - (5)].adouble) ) Alors
            sdraw->Paint();
          Sinon
            fprintf(stderr," Incorrect index \n");
          FinSi
        }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 4250 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw1 = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          Viewer3D_ptr sdraw2 = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer());

          sdraw1->AddCompSurf(sdraw2);
        }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 4257 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 272:

/* Line 678 of lalr1.cc  */
#line 4271 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 273:

/* Line 678 of lalr1.cc  */
#line 4285 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      Viewer3D_ptr draw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      int num = (int) (yysemantic_stack_[(6) - (5)].adouble);

      draw->GetCanvas()->HideFreeSection(num);

        }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 4293 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr glclass=*((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());
          glclass->GetCanvas()->PrintMatrices();
        }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 4298 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->SetObjectTransform(*tr);
              sdraw->Paint();
          delete tr;
        }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 4306 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->SetObjectTransform(*tr);
          if ((yysemantic_stack_[(8) - (7)].adouble)>0.5) sdraw->Paint();
          delete tr;
        }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 4314 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 278:

/* Line 678 of lalr1.cc  */
#line 4325 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 279:

/* Line 678 of lalr1.cc  */
#line 4337 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 280:

/* Line 678 of lalr1.cc  */
#line 4349 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 281:

/* Line 678 of lalr1.cc  */
#line 4361 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->SetBG((int)(yysemantic_stack_[(10) - (5)].adouble),(int)(yysemantic_stack_[(10) - (7)].adouble),(int)(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 4367 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Normalizes the 3D view based on the limits in space of the current objects
        **/
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->Normalize();
        }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 4376 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Centers the 3D view based on the limits in space of the current objects
        **/
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->Center();
        }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 4385 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 285:

/* Line 678 of lalr1.cc  */
#line 4398 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          Func_StructureTensor(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                   (yysemantic_stack_[(8) - (3)].variable)->Name().c_str(),
                   (yysemantic_stack_[(8) - (5)].adouble), (yysemantic_stack_[(8) - (7)].adouble), NULL);
        }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 4405 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();

          Func_StructureTensor(
            ((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),
            (yysemantic_stack_[(10) - (3)].variable)->Name().c_str(),
            (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), mask);
          delete mask;
        }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 4416 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 288:

/* Line 678 of lalr1.cc  */
#line 4438 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 289:

/* Line 678 of lalr1.cc  */
#line 4464 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 290:

/* Line 678 of lalr1.cc  */
#line 4492 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          Func_HessianMatrix(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(6) - (3)].variable)->Name().c_str(),
                 (yysemantic_stack_[(6) - (5)].adouble),   // sigma
                 0,   // gamma
                 NULL  // mask
                 );
        }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 4502 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 292:

/* Line 678 of lalr1.cc  */
#line 4515 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          Func_HessianMatrix(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(8) - (3)].variable)->Name().c_str(),
                 (yysemantic_stack_[(8) - (5)].adouble),   // sigma
                 (yysemantic_stack_[(8) - (7)].adouble),   // gamma
                 NULL  // mask
                 );
        }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 4525 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 294:

/* Line 678 of lalr1.cc  */
#line 4547 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 295:

/* Line 678 of lalr1.cc  */
#line 4576 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 296:

/* Line 678 of lalr1.cc  */
#line 4594 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 297:

/* Line 678 of lalr1.cc  */
#line 4608 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          Func_Curvatures(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
              (yysemantic_stack_[(6) - (3)].variable)->Name().c_str(),
              (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 4620 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 299:

/* Line 678 of lalr1.cc  */
#line 4641 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 300:

/* Line 678 of lalr1.cc  */
#line 4660 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 301:

/* Line 678 of lalr1.cc  */
#line 4677 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 302:

/* Line 678 of lalr1.cc  */
#line 4688 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      (((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get())->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 4693 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 4698 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im = *(InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer();
      (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetVoxelSize(
                                   im->VoxSizeX(),
                                   im->VoxSizeY(),
                                   im->VoxSizeZ());
    }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 4707 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->SetTranslation((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 4712 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im = *(InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer();
      (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetVoxelSize(
                                   im->TrX(),
                                   im->TrY(),
                                   im->TrZ());
    }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 4721 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 308:

/* Line 678 of lalr1.cc  */
#line 4735 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      Func_DiscSecDerGrad(
        ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
        ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 4742 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      Func_DiscSecDerGrad(
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (7)].variable)->Pointer())->get());
    }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 4748 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { (yyval.aint)=1;}
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 4751 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 312:

/* Line 678 of lalr1.cc  */
#line 4768 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 313:

/* Line 678 of lalr1.cc  */
#line 4784 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (3) IMAGE: 1D image to plot, where the voxel size in X is used
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
      char name[200];

          tabx = new float[image->_tx];
          taby = new float[image->_tx];

      Pour(x,0,image->_tx-1)
        tabx[x] = image->SpacePosX(x);
        taby[x] = (*image)(x,0,0);
      FinPour

          num_courbe = gnuplot.AddCourbe( image->_tx, tabx, taby, (yysemantic_stack_[(8) - (5)].astring));
      sprintf(name,"%s.gnuplot",(yysemantic_stack_[(8) - (5)].astring));
      gnuplot.XPlot(name,(int)(yysemantic_stack_[(8) - (7)].adouble));

      delete [] tabx;
      delete [] taby;
      delete image;
      delete [] (yysemantic_stack_[(8) - (5)].astring);
         }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 4818 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 315:

/* Line 678 of lalr1.cc  */
#line 4835 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 316:

/* Line 678 of lalr1.cc  */
#line 4875 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      Func_GenRead((yysemantic_stack_[(4) - (3)].astring));
        }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 4880 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Debut();
        }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 4885 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Fin();
      cout << "time spent = " << driver.IP_time << endl;
        }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 4891 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 320:

/* Line 678 of lalr1.cc  */
#line 4908 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->BeginBook();
    }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 4914 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndBook();
    }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 4920 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndPanel();
    }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 4926 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndPanel();
      pw->EndBox( );
    }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 4933 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndBox( );
    }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 4939 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->BeginHorizontal( );
    }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 4945 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
            ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
        pw->EndHorizontal( );
        }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 4951 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          pw->CreeDialogue( );
        }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 4957 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 329:

/* Line 678 of lalr1.cc  */
#line 4972 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Hides the given parameter panel, the smart pointer copy is released
        **/
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

          GB_main_wxFrame->RemoveParamPanelPage(pw);
        }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 4983 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          pw->ReAfficheParametres();
        }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 4989 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 332:

/* Line 678 of lalr1.cc  */
#line 5003 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 333:

/* Line 678 of lalr1.cc  */
#line 5017 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 334:

/* Line 678 of lalr1.cc  */
#line 5034 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
          int n = pw->NbParameters();
            pw->ChangedValueCallback(n-1,(void*) CB_ParamWin, (void*) (yysemantic_stack_[(6) - (5)].variable)->Pointer() );
        }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 5044 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 336:

/* Line 678 of lalr1.cc  */
#line 5063 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 337:

/* Line 678 of lalr1.cc  */
#line 5081 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 338:

/* Line 678 of lalr1.cc  */
#line 5099 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 339:

/* Line 678 of lalr1.cc  */
#line 5119 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 340:

/* Line 678 of lalr1.cc  */
#line 5139 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 341:

/* Line 678 of lalr1.cc  */
#line 5159 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          InrImage::ptr   i = *(InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer();
          Func_VectorImage2StructuredGrid(i.get(),(yysemantic_stack_[(6) - (5)].astring));
          delete [] (yysemantic_stack_[(6) - (5)].astring);
        }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 5166 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          (*(GLTransfMatrix_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->Print();
        }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 5171 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          Func_SaveTransform(((GLTransfMatrix_ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())->get(),(yysemantic_stack_[(4) - (4)].astring));
          delete [] (yysemantic_stack_[(4) - (4)].astring);
        }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 5177 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          AddWrapFluid();
        }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 5182 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          AddWrapVTK();
        }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 5187 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          AddWrapITK();
        }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 5192 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          AddWrapWII();
        }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 5197 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          AddWrapFilters();
        }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 5202 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          AddWrapSystem();
        }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 5213 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 351:

/* Line 678 of lalr1.cc  */
#line 5245 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 352:

/* Line 678 of lalr1.cc  */
#line 5269 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          Variable*  var   = (yysemantic_stack_[(4) - (1)].variable);
          ParamList::ptr param((yysemantic_stack_[(4) - (3)].paramlist));
          ((void (*)(ParamList*)) var->Pointer())(param.get());
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 5276 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 354:

/* Line 678 of lalr1.cc  */
#line 5298 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = new std::list<std::string>();
            sl->push_back(string((yysemantic_stack_[(1) - (1)].astring)));
            delete [] (yysemantic_stack_[(1) - (1)].astring);
            (yyval.string_list) = sl;
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 5306 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = (yysemantic_stack_[(3) - (1)].string_list);
            sl->push_back(string((yysemantic_stack_[(3) - (3)].astring)));
            delete [] (yysemantic_stack_[(3) - (3)].astring);
            (yyval.string_list) = sl;
        }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 5322 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          (yyval.paramlist) = pl;
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 5327 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          ParamList* pl(new ParamList);
          float_ptr* x = new float_ptr(new float((yysemantic_stack_[(1) - (1)].adouble)));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 5334 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);
          float_ptr* x= new float_ptr(new float((yysemantic_stack_[(3) - (3)].adouble)));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 5341 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          string_ptr* x = new string_ptr(new string((yysemantic_stack_[(1) - (1)].astring)));
          delete [] (yysemantic_stack_[(1) - (1)].astring);
          pl->AddParam(type_string, x);
          (yyval.paramlist) = pl;
         }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 5349 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);
          string_ptr* x = new string_ptr(new string((yysemantic_stack_[(3) - (3)].astring)));
          delete [] (yysemantic_stack_[(3) - (3)].astring);
          pl->AddParam(type_string, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 5357 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  new ParamList();
          // creating reference
          float_ptr* x = new float_ptr(*((float_ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer()));

          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 5366 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          float_ptr*   x = new float_ptr(* ((float_ptr*)(yysemantic_stack_[(4) - (4)].variable)->Pointer()));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 5373 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          int_ptr*   x = new int_ptr(*((int_ptr*)(yysemantic_stack_[(2) - (2)].variable)->Pointer()));
          pl->AddParam(type_int, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 5380 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          int_ptr*   x = new int_ptr( *((int_ptr*)(yysemantic_stack_[(4) - (4)].variable)->Pointer()));
          pl->AddParam(type_int, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 5387 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          InrImage::ptr* i = new InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 5394 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(3) - (1)].paramlist);
          InrImage::ptr*   i = new InrImage::ptr( (InrImage*) driver.im_stack.GetLastImage());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 5401 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          InrImage::ptr*  i = new InrImage::ptr(*(InrImage::ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 5408 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          InrImage::ptr* i = new InrImage::ptr(*(InrImage::ptr*) (yysemantic_stack_[(4) - (4)].variable)->Pointer());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 5415 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          SurfacePoly::ptr*  s = new SurfacePoly::ptr(*(SurfacePoly::ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer());
          pl->AddParam(type_surface, s);
          (yyval.paramlist) = pl;
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 5422 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          SurfacePoly::ptr*  s = new SurfacePoly::ptr(*(SurfacePoly::ptr*) (yysemantic_stack_[(4) - (4)].variable)->Pointer());
          pl->AddParam(type_surface, s);
          (yyval.paramlist) = pl;
        }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 5429 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          DessinImage::ptr* i = new DessinImage::ptr(*(DessinImage::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer());
          pl->AddParam(type_imagedraw, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 5436 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(3) - (1)].paramlist);
          DessinImage::ptr*  i = new DessinImage::ptr(*(DessinImage::ptr*) (yysemantic_stack_[(3) - (3)].variable)->Pointer());
          pl->AddParam(type_imagedraw, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 5445 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      //      printf("no parameters \n");
      ParamListDecl* pl = new ParamListDecl;
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 5451 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      cout << "param_list_decl: T_NUM IDENTIFIER" << endl;
      cout << ident->GetName().c_str() << endl;
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_float);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 5460 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_string);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 5467 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 5474 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 5481 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 5488 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_float);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 5495 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_string);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 5502 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 5509 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 5516 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 5524 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
        (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 5529 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 386:

/* Line 678 of lalr1.cc  */
#line 5544 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
          //fflush(stdout);
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 5550 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 388:

/* Line 678 of lalr1.cc  */
#line 5564 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 389:

/* Line 678 of lalr1.cc  */
#line 5580 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 390:

/* Line 678 of lalr1.cc  */
#line 5596 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 391:

/* Line 678 of lalr1.cc  */
#line 5608 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      (yyval.astring)=(char*) (*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->Nom();
    }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 5613 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      char* res = new char[GB_scripts_dir.Len()+1];
      strcpy(res,(const char*)GB_scripts_dir.mb_str(wxConvUTF8));
      (yyval.astring)= res;
    }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 5624 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 395:

/* Line 678 of lalr1.cc  */
#line 5634 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          RemoveEndString((yysemantic_stack_[(3) - (1)].astring),(yysemantic_stack_[(3) - (3)].astring));
          (yyval.astring)=(yysemantic_stack_[(3) - (1)].astring);
        }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 5647 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
        (yyval.ablock)=(yysemantic_stack_[(3) - (2)].ablock);
        if (GB_debug)
          cerr << format("ablock : %s")
                  % (yysemantic_stack_[(3) - (2)].ablock)->GetBody()
                << endl;
          }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 5661 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      returns the number of arguments in the command line
    **/
      (yyval.adouble)=GB_argc-GB_num_arg_parsed;
    }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 5669 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      Line number in the current script
    **/
      (yyval.adouble)=driver.yyiplineno;
    }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 5677 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        the constant Pi is set to
         3.14159265358979323846
      **/
      (yyval.adouble)= 3.14159265358979323846;
    }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 5686 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=*((float_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get();
    }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 5690 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = (float) *((int_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get();
    }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 5694 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = (float) *((uchar_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get();
    }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 5698 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(3) - (2)].adouble);
      fflush(stdout);
    }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 5707 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 410:

/* Line 678 of lalr1.cc  */
#line 5722 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 411:

/* Line 678 of lalr1.cc  */
#line 5738 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 412:

/* Line 678 of lalr1.cc  */
#line 5752 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 413:

/* Line 678 of lalr1.cc  */
#line 5767 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 414:

/* Line 678 of lalr1.cc  */
#line 5784 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 415:

/* Line 678 of lalr1.cc  */
#line 5800 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 416:

/* Line 678 of lalr1.cc  */
#line 5814 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 417:

/* Line 678 of lalr1.cc  */
#line 5827 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        Init the image buffer to the first voxel or pixel:
        at coordinates (0,0,0).

        See Also:
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

  case 418:

/* Line 678 of lalr1.cc  */
#line 5848 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 419:

/* Line 678 of lalr1.cc  */
#line 5908 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
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

  case 420:

/* Line 678 of lalr1.cc  */
#line 5929 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 421:

/* Line 678 of lalr1.cc  */
#line 5948 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

      (yyval.adouble) = s->GetNumberOfPoints();
    }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 5955 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

      (yyval.adouble) = s->GetNumberOfPolys();

    }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 5963 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_SNR(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 5968 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
           (yyval.adouble)=Func_eccentricity(((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());
        }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 5973 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 426:

/* Line 678 of lalr1.cc  */
#line 6001 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {

      (yyval.adouble)=Func_ComputePositiveArea( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get() );
    }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 6007 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      float val[4];

      val[0] = (yysemantic_stack_[(10) - (3)].adouble);
      val[1] = (yysemantic_stack_[(10) - (5)].adouble);
      val[2] = (yysemantic_stack_[(10) - (7)].adouble);
      val[3] = (yysemantic_stack_[(10) - (9)].adouble);
      (yyval.adouble)=Func_PositiveArea(val);
        }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 6018 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 429:

/* Line 678 of lalr1.cc  */
#line 6037 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 430:

/* Line 678 of lalr1.cc  */
#line 6056 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 431:

/* Line 678 of lalr1.cc  */
#line 6075 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
        /**
             Description:
             returns the position of the maximal value of an image

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

  case 432:

/* Line 678 of lalr1.cc  */
#line 6094 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 433:

/* Line 678 of lalr1.cc  */
#line 6113 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 434:

/* Line 678 of lalr1.cc  */
#line 6132 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 435:

/* Line 678 of lalr1.cc  */
#line 6155 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 436:

/* Line 678 of lalr1.cc  */
#line 6177 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 437:

/* Line 678 of lalr1.cc  */
#line 6200 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();
          (yyval.adouble)=Func_med( ((InrImage::ptr*) (yysemantic_stack_[(9) - (6)].variable)->Pointer())->get(),(float) (yysemantic_stack_[(9) - (8)].adouble),mask);
          delete mask;
        }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 6207 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 439:

/* Line 678 of lalr1.cc  */
#line 6231 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 440:

/* Line 678 of lalr1.cc  */
#line 6254 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
//    setlocale(LC_NUMERIC,"C");
      setlocale(LC_NUMERIC, "C");
      (yyval.adouble)=atof((yysemantic_stack_[(4) - (3)].astring));
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 6262 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._xmin;
        }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 6272 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._xmax;
        }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 6282 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._ymin;
        }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 6292 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._ymax;
        }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 6302 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._zmin;
        }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 6312 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._zmax;
        }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 6322 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 448:

/* Line 678 of lalr1.cc  */
#line 6336 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 449:

/* Line 678 of lalr1.cc  */
#line 6353 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 450:

/* Line 678 of lalr1.cc  */
#line 6369 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_AnisoGS_GetNoiseSD();
    }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 6374 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_AnisoGS_GetDAcoeff();
    }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 6379 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = Func_LevelSets_UpdateResult();
    }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 6383 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr mat = *(FloatMatrix::ptr*)(yysemantic_stack_[(6) - (1)].variable)->Pointer();
          int i = (int)(yysemantic_stack_[(6) - (3)].adouble);
          int j = (int)(yysemantic_stack_[(6) - (5)].adouble);
          (yyval.adouble) = (*mat)[i][j];
    }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 6390 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr mat = *(FloatMatrix::ptr*)(yysemantic_stack_[(8) - (1)].variable)->Pointer();
          int i = (int)(yysemantic_stack_[(8) - (3)].adouble);
          int j = (int)(yysemantic_stack_[(8) - (5)].adouble);
          (yyval.adouble)  =  ((*mat)[i][j] = (yysemantic_stack_[(8) - (8)].adouble));
    }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 6398 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 456:

/* Line 678 of lalr1.cc  */
#line 6433 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 457:

/* Line 678 of lalr1.cc  */
#line 6471 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 458:

/* Line 678 of lalr1.cc  */
#line 6488 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 459:

/* Line 678 of lalr1.cc  */
#line 6508 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
    int bid;
    ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
    std::string tooltip = (boost::format("%s  (%s)") % (yysemantic_stack_[(8) - (7)].variable)->GetComments() % (yysemantic_stack_[(8) - (7)].variable)->Name()).str();
    pw->AddButton( &bid, (yysemantic_stack_[(8) - (5)].astring),
                (void*) CB_Button,
                (void*) (yysemantic_stack_[(8) - (7)].variable)->Pointer(),
                tooltip);
    (yyval.adouble) = bid;
    }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 6520 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 461:

/* Line 678 of lalr1.cc  */
#line 6537 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 462:

/* Line 678 of lalr1.cc  */
#line 6557 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 463:

/* Line 678 of lalr1.cc  */
#line 6590 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 464:

/* Line 678 of lalr1.cc  */
#line 6609 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 465:

/* Line 678 of lalr1.cc  */
#line 6631 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 466:

/* Line 678 of lalr1.cc  */
#line 6647 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 467:

/* Line 678 of lalr1.cc  */
#line 6665 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 468:

/* Line 678 of lalr1.cc  */
#line 6689 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 469:

/* Line 678 of lalr1.cc  */
#line 6710 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 470:

/* Line 678 of lalr1.cc  */
#line 6738 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 471:

/* Line 678 of lalr1.cc  */
#line 6752 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
    /**
    **/
      string_ptr label( new std::string((yysemantic_stack_[(6) - (5)].astring)));
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      int id = pw->AddPage( label->c_str());
      (yyval.adouble)=id;
    }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 6762 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 473:

/* Line 678 of lalr1.cc  */
#line 6776 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 474:

/* Line 678 of lalr1.cc  */
#line 6791 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
    Check for the existence of a variable, returns 0
    **/
          (yyval.adouble)=0;
    }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 6799 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
    /**
    Description: 
    Check for the existence of a variable, returns 1
    **/
          (yyval.adouble)=1;
    }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 6807 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 477:

/* Line 678 of lalr1.cc  */
#line 6819 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble) = (int) (yysemantic_stack_[(1) - (1)].aint);
    }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 6823 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 479:

/* Line 678 of lalr1.cc  */
#line 6838 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
       float*  var = ((float_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get();
        FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
        setlocale(LC_NUMERIC, "C");
        (yyval.adouble) = fscanf(file.get(),"%f",var);
    }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 6845 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 481:

/* Line 678 of lalr1.cc  */
#line 6855 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 482:

/* Line 678 of lalr1.cc  */
#line 6867 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 484:

/* Line 678 of lalr1.cc  */
#line 6880 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(2) - (2)].adouble); }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 6881 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(!,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 6882 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(-,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 6883 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(+,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 6884 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(sin,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 6885 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(cos,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 6886 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(sqrt,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 6887 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(fabs,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 6888 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(round,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 6890 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          /**
            Description:
                return the closest integer smaller than the given expression value.
           **/
          UNARYOP_EXPR(floor,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble))
        }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 6897 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(tan,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 6898 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(asin,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 6899 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(acos,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 6900 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(atan,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 6901 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(exp,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 6902 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(1.0/log(10.0)*log,(yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 6903 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(log,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 6916 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 506:

/* Line 678 of lalr1.cc  */
#line 6932 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)*(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 6933 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)/(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 6934 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { (yyval.adouble)= ((int) round((yysemantic_stack_[(3) - (1)].adouble))) % ((int) round((yysemantic_stack_[(3) - (3)].adouble))); }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 6939 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)+(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 6940 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)-(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 6950 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)<(yysemantic_stack_[(3) - (3)].adouble));  }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 6951 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)>(yysemantic_stack_[(3) - (3)].adouble));  }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 6952 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)<=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 6953 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)>=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 6958 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)==(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 6959 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)!=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 6960 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(strcmp((yysemantic_stack_[(3) - (1)].astring),(yysemantic_stack_[(3) - (3)].astring))==0); }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 6961 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(strcmp((yysemantic_stack_[(3) - (1)].astring),(yysemantic_stack_[(3) - (3)].astring))!=0); }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 6967 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = ((int)(yysemantic_stack_[(3) - (1)].adouble)) & ((int)(yysemantic_stack_[(3) - (3)].adouble));
    }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 6980 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
        }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 6984 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = ((int)(yysemantic_stack_[(3) - (1)].adouble)) | ((int)(yysemantic_stack_[(3) - (3)].adouble));
        }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 6991 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
           (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
        }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 6995 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)&&(yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 7002 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
    }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 7006 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)||(yysemantic_stack_[(3) - (3)].adouble);
    }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 7014 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=((yysemantic_stack_[(5) - (1)].adouble)?(yysemantic_stack_[(5) - (3)].adouble):(yysemantic_stack_[(5) - (5)].adouble));
        }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 7031 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      driver.err_print(" char format is not available: use unsigned char \n");
      (yyval.aint)=WT_UNSIGNED_CHAR;
    }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 7036 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          (yyval.aint)=WT_UNSIGNED_CHAR;
       }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 7040 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_SHORT;
       }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 7044 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_SHORT;
       }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 7048 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_INT;
       }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 7052 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_INT;
       }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 7056 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT;
       }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 7060 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_DOUBLE;
       }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 7064 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_RGB;
       }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 7068 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT_VECTOR;
       }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 7072 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
//        printf("format %d \n",(int) ( *(InrImage::ptr*) $1->Pointer())->GetFormat());
        (yyval.aint) = (int) (*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetFormat();
      }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 7080 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yysemantic_stack_[(1) - (1)].variable);
        }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 7085 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 550:

/* Line 678 of lalr1.cc  */
#line 7102 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
     driver.im_stack.AddImage((yysemantic_stack_[(2) - (2)].astring));
     delete [] (yysemantic_stack_[(2) - (2)].astring);
       }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 7108 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
     driver.im_stack.AddImage((yysemantic_stack_[(4) - (3)].astring));
     delete [] (yysemantic_stack_[(4) - (3)].astring);
       }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 7115 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 553:

/* Line 678 of lalr1.cc  */
#line 7173 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 554:

/* Line 678 of lalr1.cc  */
#line 7227 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 555:

/* Line 678 of lalr1.cc  */
#line 7282 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 556:

/* Line 678 of lalr1.cc  */
#line 7303 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 557:

/* Line 678 of lalr1.cc  */
#line 7324 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 558:

/* Line 678 of lalr1.cc  */
#line 7338 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 559:

/* Line 678 of lalr1.cc  */
#line 7367 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
        InrImage* im;
        printf(" ********** %d %f %f %f\n", (yysemantic_stack_[(10) - (3)].aint), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
        im = new InrImage( (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble), (WORDTYPE) (yysemantic_stack_[(10) - (3)].aint));
        driver.im_stack.AddImage(im);
      }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 7375 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
    printf(" ********** %d %f %f %f\n", (yysemantic_stack_[(12) - (3)].aint), (yysemantic_stack_[(12) - (5)].adouble), (yysemantic_stack_[(12) - (7)].adouble), (yysemantic_stack_[(12) - (9)].adouble));
    im = new InrImage( (int) (yysemantic_stack_[(12) - (5)].adouble), (int) (yysemantic_stack_[(12) - (7)].adouble), (int) (yysemantic_stack_[(12) - (9)].adouble), (int) (yysemantic_stack_[(12) - (11)].adouble), (WORDTYPE) (yysemantic_stack_[(12) - (3)].aint));
    driver.im_stack.AddImage(im);
    }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 7394 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 562:

/* Line 678 of lalr1.cc  */
#line 7420 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 563:

/* Line 678 of lalr1.cc  */
#line 7433 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 564:

/* Line 678 of lalr1.cc  */
#line 7511 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 565:

/* Line 678 of lalr1.cc  */
#line 7578 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      InrImage* im  = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res =Func_localmean( im, (int) (yysemantic_stack_[(6) - (5)].adouble));
      driver.im_stack.AddImage(res);
      delete im;
    }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 7586 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      InrImage* im  = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res =Func_localmean2( im, (int) (yysemantic_stack_[(6) - (5)].adouble));
      driver.im_stack.AddImage(res);
      delete im;
      }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 7594 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
    InrImage* mean    = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* im      = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* res     = Func_localSD( im, mean, (int) (yysemantic_stack_[(8) - (7)].adouble));
    driver.im_stack.AddImage(res);
    delete im;
    delete mean;
      }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 7604 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
    InrImage* mean    = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* im      = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* res     = Func_localSD2( im, mean, (int) (yysemantic_stack_[(8) - (7)].adouble));
    driver.im_stack.AddImage(res);
    delete im;
    delete mean;
      }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 7614 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
      Returns the image corresponding to the pointwise maximum between 2 images.


      See Also:
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

  case 570:

/* Line 678 of lalr1.cc  */
#line 7644 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 571:

/* Line 678 of lalr1.cc  */
#line 7662 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 572:

/* Line 678 of lalr1.cc  */
#line 7682 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 573:

/* Line 678 of lalr1.cc  */
#line 7700 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 574:

/* Line 678 of lalr1.cc  */
#line 7720 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 575:

/* Line 678 of lalr1.cc  */
#line 7739 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 576:

/* Line 678 of lalr1.cc  */
#line 7760 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 577:

/* Line 678 of lalr1.cc  */
#line 7797 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 578:

/* Line 678 of lalr1.cc  */
#line 7812 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 579:

/* Line 678 of lalr1.cc  */
#line 7826 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 580:

/* Line 678 of lalr1.cc  */
#line 7842 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 581:

/* Line 678 of lalr1.cc  */
#line 7865 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 582:

/* Line 678 of lalr1.cc  */
#line 7879 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 583:

/* Line 678 of lalr1.cc  */
#line 7893 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 584:

/* Line 678 of lalr1.cc  */
#line 7907 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 585:

/* Line 678 of lalr1.cc  */
#line 7921 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 586:

/* Line 678 of lalr1.cc  */
#line 7956 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 587:

/* Line 678 of lalr1.cc  */
#line 7971 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 588:

/* Line 678 of lalr1.cc  */
#line 7992 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 589:

/* Line 678 of lalr1.cc  */
#line 8013 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 590:

/* Line 678 of lalr1.cc  */
#line 8054 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 591:

/* Line 678 of lalr1.cc  */
#line 8099 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 592:

/* Line 678 of lalr1.cc  */
#line 8116 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 593:

/* Line 678 of lalr1.cc  */
#line 8135 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 594:

/* Line 678 of lalr1.cc  */
#line 8149 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 595:

/* Line 678 of lalr1.cc  */
#line 8163 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 596:

/* Line 678 of lalr1.cc  */
#line 8179 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 597:

/* Line 678 of lalr1.cc  */
#line 8197 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 598:

/* Line 678 of lalr1.cc  */
#line 8212 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 599:

/* Line 678 of lalr1.cc  */
#line 8228 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 600:

/* Line 678 of lalr1.cc  */
#line 8243 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 601:

/* Line 678 of lalr1.cc  */
#line 8266 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 602:

/* Line 678 of lalr1.cc  */
#line 8283 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 603:

/* Line 678 of lalr1.cc  */
#line 8297 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {

          InrImage* res;
          InrImage* im = (InrImage*) driver.im_stack.GetLastImage();

        res = Func_AutoCrop(im,(int)(yysemantic_stack_[(6) - (5)].adouble));

        driver.im_stack.AddImage(res);
        delete im;
    }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 8309 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      InrImage*  res;
      ImageExtent<float>* extent = (ImageExtent<float>*) (yysemantic_stack_[(4) - (3)].imageextent);
  
      extent->print();
      extent->SetRelative(((InrImage::ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())->get());
  
      extent->print();
      cout << "xmax = " << (int)  extent->Xmax() << endl;
      cout << "xmax = " << (int)  round((double)extent->Xmax()) << endl;
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

  case 605:

/* Line 678 of lalr1.cc  */
#line 8341 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 606:

/* Line 678 of lalr1.cc  */
#line 8361 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 607:

/* Line 678 of lalr1.cc  */
#line 8403 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 608:

/* Line 678 of lalr1.cc  */
#line 8415 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 609:

/* Line 678 of lalr1.cc  */
#line 8426 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 610:

/* Line 678 of lalr1.cc  */
#line 8439 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 611:

/* Line 678 of lalr1.cc  */
#line 8451 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 612:

/* Line 678 of lalr1.cc  */
#line 8462 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 613:

/* Line 678 of lalr1.cc  */
#line 8490 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 614:

/* Line 678 of lalr1.cc  */
#line 8517 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 615:

/* Line 678 of lalr1.cc  */
#line 8549 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 616:

/* Line 678 of lalr1.cc  */
#line 8565 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 617:

/* Line 678 of lalr1.cc  */
#line 8582 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_AnisoGS_GetOutput();

    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 8595 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_AnisoGS_GetDiffusionCoeff();

    Si res==NULL Alors
      fprintf(stderr,"GetDiffCoeff() erreur ... \n");
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 8608 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 620:

/* Line 678 of lalr1.cc  */
#line 8628 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 621:

/* Line 678 of lalr1.cc  */
#line 8651 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {

    InrImage*  res;

    res = Func_LevelSets_GetCurrentOutput();

    Si res==NULL Alors
      fprintf(stderr,"Func_LevelSets_GetOutput() error ... \n");
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 8665 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 623:

/* Line 678 of lalr1.cc  */
#line 8682 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 624:

/* Line 678 of lalr1.cc  */
#line 8715 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 625:

/* Line 678 of lalr1.cc  */
#line 8753 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 626:

/* Line 678 of lalr1.cc  */
#line 8788 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 627:

/* Line 678 of lalr1.cc  */
#line 8821 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 628:

/* Line 678 of lalr1.cc  */
#line 8838 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 629:

/* Line 678 of lalr1.cc  */
#line 8853 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 630:

/* Line 678 of lalr1.cc  */
#line 8869 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 631:

/* Line 678 of lalr1.cc  */
#line 8889 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 632:

/* Line 678 of lalr1.cc  */
#line 8912 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 633:

/* Line 678 of lalr1.cc  */
#line 8936 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 634:

/* Line 678 of lalr1.cc  */
#line 8962 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 635:

/* Line 678 of lalr1.cc  */
#line 8985 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 636:

/* Line 678 of lalr1.cc  */
#line 9007 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 637:

/* Line 678 of lalr1.cc  */
#line 9030 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 638:

/* Line 678 of lalr1.cc  */
#line 9054 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 639:

/* Line 678 of lalr1.cc  */
#line 9098 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 640:

/* Line 678 of lalr1.cc  */
#line 9122 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 641:

/* Line 678 of lalr1.cc  */
#line 9153 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {

        InrImage*    res;

          res = Func_rot2D( ((InrImage::ptr*) (yysemantic_stack_[(14) - (3)].variable)->Pointer())->get(),
                (yysemantic_stack_[(14) - (5)].adouble), (yysemantic_stack_[(14) - (7)].adouble),   // rotation center
                (yysemantic_stack_[(14) - (9)].adouble),       // angle of rotation
                (yysemantic_stack_[(14) - (11)].adouble), (yysemantic_stack_[(14) - (13)].adouble)  // dimension of the new image
                );

      driver.im_stack.AddImage(res);
        }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 9166 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 643:

/* Line 678 of lalr1.cc  */
#line 9203 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 644:

/* Line 678 of lalr1.cc  */
#line 9240 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 645:

/* Line 678 of lalr1.cc  */
#line 9277 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 646:

/* Line 678 of lalr1.cc  */
#line 9312 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          driver.im_stack.AddImage((*(Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetCanvas()->GetGLImage());
        }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 9317 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          fprintf(stderr,"not available in new wxwidgets version of the 3D viewer ! \n");
          driver.im_stack.AddImage((InrImage*)NULL);
/*
          driver.im_stack.AddImage((*(Viewer3D_ptr*) $1->Pointer())->GetInrImage());
*/
    }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 9326 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      driver.im_stack.AddImage((*(DessinImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetInrImage());
    }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 9331 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {

    InrImage*    res;

      res = Func_ThresholdCrossing( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

          driver.im_stack.AddImage(res);

    }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 9342 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      InrImage*    res;

      res = Func_IsocontourPoints( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

      driver.im_stack.AddImage(res);

    }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 9352 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
        InrImage*    res;

      res = Func_IsosurfDist( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

          driver.im_stack.AddImage(res);

    }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 9362 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
        InrImage*    res;

      res = Func_vtkIsoContourDist( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

          driver.im_stack.AddImage(res);
    }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 9371 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 654:

/* Line 678 of lalr1.cc  */
#line 9394 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 655:

/* Line 678 of lalr1.cc  */
#line 9423 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 656:

/* Line 678 of lalr1.cc  */
#line 9449 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 657:

/* Line 678 of lalr1.cc  */
#line 9480 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 658:

/* Line 678 of lalr1.cc  */
#line 9510 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {

      InrImage* res;
      res = Func_Convolve(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                  ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());

          driver.im_stack.AddImage(res);

        }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 9521 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 660:

/* Line 678 of lalr1.cc  */
#line 9537 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
      res = Func_Chamfer(((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));

          driver.im_stack.AddImage(res);

        }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 9547 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
      res = Func_Chamfer2(((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));

          driver.im_stack.AddImage(res);

        }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 9557 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 663:

/* Line 678 of lalr1.cc  */
#line 9572 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_Chamfer2(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                  0.92644, 1.34065, 1.65849,
                  dmax);

          driver.im_stack.AddImage(res);

        }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 9586 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_Chamfer2Signed(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                    0.92644, 1.34065, 1.65849,
                    dmax);

          driver.im_stack.AddImage(res);

        }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 9600 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_vtkSignedBorgefors(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                    dmax);

          driver.im_stack.AddImage(res);

        }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 9613 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_vtkSignedFMDist(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                     dmax);

          driver.im_stack.AddImage(res);

        }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 9626 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_PropagationDistance(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                      dmax);

          driver.im_stack.AddImage(res);
        }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 9638 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_PropagationDistance2(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                      dmax);

          driver.im_stack.AddImage(res);
        }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 9650 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_PropagationDanielsson(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                       dmax);

          driver.im_stack.AddImage(res);
        }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 9662 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_vtkPropDanielsson(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                       -dmax,dmax);
          driver.im_stack.AddImage(res);
        }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 9673 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmin = (yysemantic_stack_[(8) - (5)].adouble);
        float dmax = (yysemantic_stack_[(8) - (7)].adouble);

      res = Func_vtkPropDanielsson(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                       dmin,dmax);

          driver.im_stack.AddImage(res);
        }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 9686 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 673:

/* Line 678 of lalr1.cc  */
#line 9713 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 674:

/* Line 678 of lalr1.cc  */
#line 9746 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
          pos = (int) im2->ValeurBuffer();
          Si (pos<0) AlorsFait pos = 0;
          Si (pos>=im1->DimX()) AlorsFait pos = im1->DimX()-1;
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

  case 675:

/* Line 678 of lalr1.cc  */
#line 9858 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 676:

/* Line 678 of lalr1.cc  */
#line 9882 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 677:

/* Line 678 of lalr1.cc  */
#line 9924 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 678:

/* Line 678 of lalr1.cc  */
#line 9936 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      InrImage* res;
      int dim = (int) (yysemantic_stack_[(6) - (5)].adouble);

      InrImage::ptr im = InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
      res = Func_MeanHalfSize(im.get(),dim);
      if (res!=NULL) driver.im_stack.AddImage(res);
    }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 9945 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
        InrImage* res;
        int axis=(int) (yysemantic_stack_[(6) - (5)].adouble);

        InrImage::ptr im = InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
        res=Func_Flip(im,axis);
        driver.im_stack.AddImage(res);
    }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 9954 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 681:

/* Line 678 of lalr1.cc  */
#line 9977 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 682:

/* Line 678 of lalr1.cc  */
#line 10002 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 683:

/* Line 678 of lalr1.cc  */
#line 10015 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(5) - (1)].variable)->Pointer());


      res = s->GetImageLinesLength(  );

      if (res!=NULL) driver.im_stack.AddImage(res);
    }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 10025 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 685:

/* Line 678 of lalr1.cc  */
#line 10062 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 686:

/* Line 678 of lalr1.cc  */
#line 10080 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 687:

/* Line 678 of lalr1.cc  */
#line 10098 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());


      res = s->GetIntensities( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

      if (res!=NULL) driver.im_stack.AddImage(res);
        }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 10108 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;

      res = AMIFluid::Func_Altitude2Position(im,(int)(yysemantic_stack_[(6) - (5)].adouble));
      if (res!=NULL) driver.im_stack.AddImage(res);

      delete im;
    }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 10118 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_Altitude2Position(im);
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
    }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 10126 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im,(int)(yysemantic_stack_[(6) - (5)].adouble));
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
    }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 10134 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im);
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
    }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 10142 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 693:

/* Line 678 of lalr1.cc  */
#line 10167 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 694:

/* Line 678 of lalr1.cc  */
#line 10187 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      InrImage* res;
      res= AMIFluid::Func_ReadFlow((char*)(yysemantic_stack_[(4) - (3)].astring));
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 10195 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 696:

/* Line 678 of lalr1.cc  */
#line 10229 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 697:

/* Line 678 of lalr1.cc  */
#line 10252 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 703:

/* Line 678 of lalr1.cc  */
#line 10277 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(-)               }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 10279 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sin)             }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 10280 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(cos)             }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 10281 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sqrt)            }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 10282 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(fabs)            }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 10283 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(round)           }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 10284 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(floor)           }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 10285 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(tan)             }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 10286 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(asin)            }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 10287 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(acos)            }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 10288 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(atan)            }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 10289 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(exp)             }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 10290 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(1.0/log(10.0)*log) }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 10291 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(log)             }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 10293 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 720:

/* Line 678 of lalr1.cc  */
#line 10308 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 722:

/* Line 678 of lalr1.cc  */
#line 10330 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(*,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 10336 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(/,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 10338 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {  IMAGE_OP_IMAGE_2(*)   }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 10339 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(/)   }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 10340 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(^)   }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 10349 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(+,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 10350 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(-,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 10351 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(+)   }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 10352 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(-)   }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 10360 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<)    }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 10361 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>)    }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 10362 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<=)   }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 10363 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>=)   }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 10364 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<, (yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 10365 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>, (yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 10366 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<=,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 10367 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>=,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 10372 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(==)   }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 10373 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(!=)   }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 10374 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(==,(yysemantic_stack_[(3) - (3)].adouble))   }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 10375 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(!=,(yysemantic_stack_[(3) - (3)].adouble))   }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 10417 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
         GLTransfMatrix* newglt;
         GLTransfMatrix_ptr glt = *(GLTransfMatrix_ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

         newglt = new GLTransfMatrix();
         (*newglt) = (*glt);
         driver.gltransf_stack.AddMatrix(newglt);

           }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 10428 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 764:

/* Line 678 of lalr1.cc  */
#line 10441 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
         GLTransfMatrix* newglt = NULL;
         GLTransfMatrix_ptr glt1 = *(GLTransfMatrix_ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer();
         GLTransfMatrix_ptr glt2 = *(GLTransfMatrix_ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer();
         float coeff = (yysemantic_stack_[(8) - (7)].adouble);

         newglt = Func_InterpolateTransform(glt1.get(),glt2.get(),coeff);
         driver.gltransf_stack.AddMatrix(newglt);
       }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 10452 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 766:

/* Line 678 of lalr1.cc  */
#line 10469 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
         FloatMatrix* m;
         m = new FloatMatrix((int)(yysemantic_stack_[(6) - (3)].adouble),(int)(yysemantic_stack_[(6) - (5)].adouble));
         driver.matrix_stack.AddMatrix(m);
       }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 10476 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      FloatMatrix* newmat;
      FloatMatrix::ptr mat = *(FloatMatrix::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

      newmat = new FloatMatrix( (*mat));

          driver.matrix_stack.AddMatrix(newmat);
       }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 10486 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 774:

/* Line 678 of lalr1.cc  */
#line 10506 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(-)               }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 10509 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          FloatMatrix* mat;
          FloatMatrix* res;
          mat=driver.matrix_stack.GetLastMatrix();
          res = mat->Transpose();
          delete mat;
          driver.matrix_stack.AddMatrix(res);
        }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 10517 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sin)             }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 10518 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(cos)             }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 10519 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sqrt)            }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 10520 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(fabs)            }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 10521 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(round)           }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 10522 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(floor)           }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 10523 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(tan)             }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 10524 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(asin)            }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 10525 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(acos)            }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 10526 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(atan)            }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 10527 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(exp)             }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 10528 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(1.0/log(10.0)*log) }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 10529 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(log)             }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 10536 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(*,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 10537 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(*)   }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 10539 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
         FloatMatrix* m2 = driver.matrix_stack.GetLastMatrix();
         FloatMatrix* m1 = driver.matrix_stack.GetLastMatrix();
             FloatMatrix* res = Multiply(m1, m2) ;
         driver.matrix_stack.AddMatrix(res);
         delete m1;
         delete m2;
           }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 10549 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(+,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 10550 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(-,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 10551 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(+)   }
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 10552 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(-)   }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 10601 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yysemantic_stack_[(1) - (1)].variable);
        }
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 10606 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          VarArray::ptr array;
          int  i = (int) (yysemantic_stack_[(4) - (3)].adouble);

          array = *(VarArray::ptr*) ((yysemantic_stack_[(4) - (1)].variable)->Pointer());
          if (array->GetVar(i).Pointer()==NULL) {
            // initialize the surface
            SurfacePoly* surf = new SurfacePoly();
            char name[256];
            sprintf(name,"%s[%d]",(yysemantic_stack_[(4) - (1)].variable)->Name().c_str(),i);
            array->InitElement(i,surf,name);
          }
          (yyval.variable)=&(array->GetVar(i));
        }
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 10623 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 814:

/* Line 678 of lalr1.cc  */
#line 10634 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
        SurfacePoly* surf;
        surf = Func_isosurf((*(InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer()),
                (yysemantic_stack_[(6) - (5)].adouble),
                NULL,
                2);
        driver.surf_stack.AddSurf(surf);
    }
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 10644 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 816:

/* Line 678 of lalr1.cc  */
#line 10664 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 817:

/* Line 678 of lalr1.cc  */
#line 10698 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_decimate(((SurfacePoly::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 10707 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_decimate(((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble) );
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 10716 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_vtkMarchingCubes(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),(yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 10725 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_vtkSmooth(((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 10734 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
        SurfacePoly* surf;
        surf = Func_vtkWindowedSinc(((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
        if (surf==NULL) driver.err_print("vtkWindowedSinc failed!");
        driver.surf_stack.AddSurf(surf);
    }
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 10742 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf = new SurfacePoly();
      driver.surf_stack.AddSurf(surf);
    }
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 10748 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      driver.surf_stack.AddSurf((yysemantic_stack_[(2) - (2)].astring));
      delete [] (yysemantic_stack_[(2) - (2)].astring);
    }
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 10754 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      driver.surf_stack.AddSurf((yysemantic_stack_[(4) - (3)].astring));
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 10760 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 826:

/* Line 678 of lalr1.cc  */
#line 10786 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 827:

/* Line 678 of lalr1.cc  */
#line 10800 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 828:

/* Line 678 of lalr1.cc  */
#line 10816 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* newsurf;
      SurfacePoly::ptr surf = *(SurfacePoly::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

      newsurf = new SurfacePoly( (*surf) );

          driver.surf_stack.AddSurf(newsurf);
      }
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 10826 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 830:

/* Line 678 of lalr1.cc  */
#line 10844 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 831:

/* Line 678 of lalr1.cc  */
#line 10872 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 832:

/* Line 678 of lalr1.cc  */
#line 10899 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 833:

/* Line 678 of lalr1.cc  */
#line 10915 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 834:

/* Line 678 of lalr1.cc  */
#line 10938 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 835:

/* Line 678 of lalr1.cc  */
#line 10971 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 836:

/* Line 678 of lalr1.cc  */
#line 11007 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 837:

/* Line 678 of lalr1.cc  */
#line 11053 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 838:

/* Line 678 of lalr1.cc  */
#line 11091 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 839:

/* Line 678 of lalr1.cc  */
#line 11115 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr im = InrImage::ptr(driver.im_stack.GetLastImage());
      SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 11125 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 841:

/* Line 678 of lalr1.cc  */
#line 11148 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 842:

/* Line 678 of lalr1.cc  */
#line 11160 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 843:

/* Line 678 of lalr1.cc  */
#line 11173 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 844:

/* Line 678 of lalr1.cc  */
#line 11210 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 845:

/* Line 678 of lalr1.cc  */
#line 11253 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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


        See Also:
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

  case 846:

/* Line 678 of lalr1.cc  */
#line 11301 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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


        See Also:
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

  case 847:

/* Line 678 of lalr1.cc  */
#line 11353 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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


        See Also:
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

  case 848:

/* Line 678 of lalr1.cc  */
#line 11396 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 849:

/* Line 678 of lalr1.cc  */
#line 11424 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 850:

/* Line 678 of lalr1.cc  */
#line 11457 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 855:

/* Line 678 of lalr1.cc  */
#line 11507 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yysemantic_stack_[(1) - (1)].variable);
        }
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 11531 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          ImageExtent<float>* extent=new ImageExtent<float>( (float)(yysemantic_stack_[(11) - (1)].adouble),(float)(yysemantic_stack_[(11) - (3)].adouble),(float)(yysemantic_stack_[(11) - (5)].adouble),
                              (float)(yysemantic_stack_[(11) - (7)].adouble),(float)(yysemantic_stack_[(11) - (9)].adouble),(float)(yysemantic_stack_[(11) - (11)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        }
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 11539 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
    {
          ImageExtent<float>* extent=new ImageExtent<float>((float)(yysemantic_stack_[(7) - (1)].adouble),(float)(yysemantic_stack_[(7) - (3)].adouble),(float)(yysemantic_stack_[(7) - (5)].adouble),(float)(yysemantic_stack_[(7) - (7)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        }
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 11546 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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

  case 875:

/* Line 678 of lalr1.cc  */
#line 11562 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"
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
#line 14568 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.tab.cpp"
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
  const short int Parser::yypact_ninf_ = -2780;
  const short int
  Parser::yypact_[] =
  {
      9445, -2780, 15712, 15561, 15561,  5102, -2780, -2780, -2780, -2780,
   -2780,    79,   102,   127, -2780, -2780, -2780, -2780,   -32,   352,
   -2780,   229,  5102,  7589,    30,   135,   148,    30, -2780, -2780,
   -2780, -2780, -2780,    31,   136,   139,    23,    48, -2780,   206,
      43,    26, -2780,   174, -2780,    86,    -7, -2780,   178,   189,
      89,   203,  1445,    30, -2780, -2780, -2780, -2780,   251,   264,
     281,   455,   288,   484,   528,   296,   324, -2780, -2780, -2780,
     359,   396,   419,   397,   454,   595,   529,   537,   541,   552,
     555,   586,   602,   606,   639,   647,   729,   732,   744,   747,
   -2780,   775,   799, -2780, -2780, -2780, -2780, -2780, -2780, -2780,
   -2780, -2780, -2780,   801,   826,   828, -2780, -2780, 15561, 15561,
   15561, 15561, 15561, 15561, 15561, 15561, 15561, 15561, 15561, 15561,
   15561,    -7, -2780, -2780,  7589,    30,    30,   881,   903,   928,
      55,    -7,   929,   936,   944,   966, -2780, -2780, -2780, -2780,
   -2780, -2780,   967,   995, -2780,   558,  3792, -2780, -2780, -2780,
   -2780, -2780, -2780, -2780,   161, -2780, -2780,   231,   134, -2780,
   -2780, -2780, 15561, -2780,   100,   279, -2780,    63,   235,   782,
     885,   873,   819,    68, -2780, -2780, -2780, -2780,    75, -2780,
   -2780, -2780, -2780,   856,    34,   375, -2780, -2780, -2780, -2780,
   -2780, -2780, -2780, -2780, -2780, -2780, -2780,    53,   -21,   945,
   15712, 15712,  7589, -2780, -2780, -2780,   979, -2780,   996,   981,
    1004,  1009,  1010,  1007,  1017, 15712, 15712, 15712, 15712, 15712,
   15712, 15712, 15712, 15712, 15712, 15712, 15712, 15712, 15712, -2780,
     293,  1020,   996, -2780,   856, -2780,   856, -2780,  1014,  1026,
     314,  1027,    30,  7589,    30, -2780, -2780, -2780, -2780, -2780,
   -2780,   134, -2780, -2780,   134, -2780, -2780,  1030,    30,    30,
   -2780, -2780, -2780,  7589, -2780, -2780,  7589, -2780, -2780,  7589,
      30,   688,   386,   199,   199,  7589,  5102,   -31,   605, 11047,
   11047, -2780, -2780,   757,   -18,  7589,   720,  7589, -2780, -2780,
   -2780, -2780, -2780, -2780, -2780, -2780, -2780, -2780, -2780, -2780,
   -2780, -2780,  1064,  1010, -2780, -2780, -2780,  7589,  7589, 14823,
   12063, 14823, 14823, 14823, 14823, 14823, 14823,   229,   448,  1280,
     280,   299,   229,   229, 14823, 14823,   229,   229,   229,   229,
     229,   229,   229,   229,  1024,  1028,  7589,  7589,   229,  7589,
    7589,    19,    30, 14823,   229, -2780,   856, -2780,   856, -2780,
     856, -2780,   856, -2780,   856, -2780,   856, -2780,   856, -2780,
     856, -2780,   856, -2780,   856, -2780,   856, -2780,   856, -2780,
     856,  -122, -2780,  1035, -2780,   161, -2780,  1152,    30,  1037,
   -2780, -2780, -2780,  7589,    30,  1036,   229,   229,   229, -2780,
   -2780, -2780, -2780, -2780, -2780, -2780, -2780, -2780,   161, -2780,
      30,    30,    30,    30, -2780,   856, 15712, 15712, 15712, 15712,
   15712, 15712, 15712, 15712, 15712, 15712, 15712,  7589,  7589,  7589,
    7589,  7589,  7589,  7589,  7589,   157, 14823, 12063, -2780, 15561,
      19, 15561, 15561,  1260,   319, 14411, 10016,  1038,   477,    -2,
     915,  7589,  7589,   355,   941,  7589,   -38,    82, -2780, 15750,
       4, -2780,  1094,  1102,  1104,  1069,  1106,  1101, -2780, -2780,
   -2780, -2780,  1109,  1110,  1113,  1114,  1115,  1116, -2780, -2780,
   -2780, -2780, -2780, -2780, -2780, -2780, -2780,  1117,  1118,  1119,
   -2780,  1120,  1121,  1122,  1123, -2780,  1124,  1125,  1139,  1141,
    1142,  1143,  1144,  1145,  1147,  1148,  1149,  1150,  1153,  1154,
    1155, -2780,  1156,  1157,  1158,  1159, -2780, -2780,  1160, -2780,
    1161, -2780,  1162,  1164,  1165,  1166,  1167, -2780, -2780,  1168,
   -2780, -2780,  7589,    30, -2780,  1171,  1172, -2780,  1173, 13079,
   13079, 12063,   403,    40,  1176,  1146,  1174,  1177,   607,  1178,
    1179,  1181,  1182,  1183,  1184,  1185,  1186,  1187,  1188,  1189,
    1190,  1216,   334,  1217,  1218,  1219,  1220,  1215,  1223,  1224,
    1225,  1230,  1231,  1226,  1239,  1240,  1241,  1242,  1243,  1244,
    1245,  1246,  1247,  1248,  1249,  1250,  1251,  1253,  1254,  1255,
    1256,  1257,  1258,  1259,  1262,  1266,  1267,  1268,  1269,  1277,
    1279,  1281,  1282,  1283,  1284,  1285,  1286,  1287,  1303,  1304,
    1305,  1306,  1307,  1315,  1316,  1317,  1318,  1319,  1322,  1324,
    1325,  1326,  1327,  1328,  1329,  1330,  1331,  1332,  1333,  1334,
    1335,  1336, 13079, 13079, 13079, 13079, 13079, 13079, 13079, 13079,
   13079, 13079, 13079, 13079, 13079, 14823,  1337,  1340,  1342,  1344,
    1345,  1346,  1274,  1347,  1348,  1352,  1353,  1354,   318,   134,
   13079, -2780,   420, -2780, -2780, -2780,  1039, -2780,   418, -2780,
     601, -2780,   108,   510,  1227, -2780,  1350,  1235,    77, -2780,
   -2780, -2780,  1351,   429, -2780,  1365, -2780,  1368, -2780, -2780,
   -2780,  1375,  1384,  1385, -2780, -2780,  1387,  1390,  1396,  1397,
    1412,  1413,  1414,  1415,  1416,  1417,  1420,  1421,  1423, -2780,
   -2780, -2780, -2780,  1425,  1428,  1429,  1430, -2780,    30,  1431,
    1433,  1434,  7589,  1432,  1424, 14823, 14823, 13999,  1426,  1438,
     502,  1444, 14823, 14823, 14823, 14823, 14823, 14823, 14823, 14823,
   14823, 14823, 14823, 14823, 14823, 14823,   648,  1439,  1466,  1146,
    1467,  1472,  1436,  1474,  1475,  1476,  1477,  1478,  1470,  1480,
    1482,  1510, -2780, -2780,  1511,  1512, -2780, -2780,  1513,  1514,
    1515,  1517,  1518,  1519,  1520,  1521, -2780,  1522,  1523,  1525,
    1526,  1527,  1528,  1529,  1530,  1531,  1532,  1533,  1534,  1536,
    1537,  1538,  1540,  1541,  1542,  1543,  1544,  1545,  1546,  1547,
    1548,  1549,  1550,  1551,  1552,  1553, -2780, -2780, -2780, -2780,
   -2780, -2780,  1554,  1555,   391,  1556,  1557,  1558,  1559,  1560,
    1561,  1580,  1581,  1582,  1583,  1584,  1585,  1562,  1563,  1586,
    1587,   504,  1590,    19,    19,    19, -2780,    19,    19,    19,
      19,    19,    19,    19,    19,    19,    19,    19,    19,    19,
      19,  1597,  1598,  1593,  1604,  7589,    30, -2780,   -15, -2780,
   -2780,  1605,  1606,  1607,  1608,  1610,  1611,   161,  1614,  1612,
    1617,  1619,  1620,  1621, -2780, -2780, -2780, -2780, -2780, -2780,
   -2780, -2780,   100,   100, -2780, -2780, -2780, -2780,    63,    63,
     235,   782,   885,   873,    24,   819,   357,  1609,  1615, -2780,
    1629, -2780, -2780,    30, -2780,  1645,  1646,  1647,  1648,  1649,
    1650,  1651,  1652,  1653, -2780, -2780, -2780, -2780, -2780, -2780,
     856,   856,   100,    34,   100,    34, -2780, -2780, -2780,    30,
    1654,  1655, -2780,    30, -2780,  1656, -2780,  1657,  1658,  1659,
    1660,  1661,  1662,  1663,  1664,  1665,  1666,  1667,  1668,  1669,
    1670,  1671,  1672, -2780,  1673, -2780,  1674, -2780, -2780,  1675,
    1676,  1677,  1678,  1679, -2780, -2780,  1680,  1681,  1682,  1683,
    1684,  1685,  1686,  1687,  1688,  1689,  1690,  1691,  1692,  1693,
    1696,  1697,  1698,   269,  1699,  1700,  1701,  1702,  1703,  1704,
   -2780,  1705, -2780, 12571, 12571, 10539,   882,  1706,  1707,  1708,
   -2780, -2780,  1709,   902,  1711,  1712,  1714,  1715, 12571, 12571,
   12571, 12571, 12571, 12571, 12571, 12571, 12571, 12571, 12571, 12571,
   12571,    50, 12571,  1710, -2780, -2780, -2780,  1713, -2780,  1716,
    1717,  1718,   332,  7589, -2780,    30, -2780, -2780,  1261,  7589,
    7589,  7589,  7589,  7589,  7589,  7589,   229,  7589,  7589,   259,
    1516,  1565,  7589,  7589,  7589,  7589,  7589,  7589,  7589, 14823,
    7589,  1508,  7589,  1505,  7589,  7589,   319,  7589,  7589,  7589,
    7589,  7589,   199,   -16,  1694,  1695,  7589,  7589,  7589,  7589,
     134, -2780, -2780,    30,    95,    30,   450, -2780, -2780, -2780,
    1721,  1722, -2780, -2780, -2780, -2780,    20, -2780,  7589,   272,
     320, 11047, 12063,   229, 14823, 14823,   229,   229,   229,   229,
     229, 14823,   229,   229,   229,   229,   229,   -12,   229,   229,
     229,   229,   -14, 14823, 14823,   229,  1499,  1500,   229,   229,
     229,   229,   229,   229,   229,   229,   229, 14823,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229, 14823, 14823, 14823, 14823, 14823,   229,   229,   229,   229,
     229,   199,   199,    30,    30,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229, 14823,   229,
     229,   229,   229,   229,   229, 14823, 14823, -2780, -2780, -2780,
   -2780, -2780, -2780, -2780, -2780, -2780, -2780, -2780, -2780, -2780,
   -2780, 14823, 14823, 14823,   229, 14823, 14823,  1229, 14823, 14823,
   14823, 14823,    30, -2780, 11555, -2780, 12063,  5671, 14823, 14823,
   13079, 13079, 13079, 13079, 13079, 13079, 13079, 13079, 13079, 13079,
   14823, 14823, 14823, 14823, 14823,   112,   161,    30,    30,    30,
    1719,  1720,    30,  1723,  1725,  7589,  1724,  1726,  1727,    30,
    7589,  1728,  7589,  7589,    30,  7589,  7589,  7589,  7589, -2780,
    1595,  7589,  1596,  1729, -2780,  1730,  1732,   540,  1395, 14823,
     679,   -13, 14823, -2780,  -230,  7589, -2780,  1731, -2780, -2780,
    1734, -2780,  1735,   229,  7589,   229,  7589,  7589,  7589,   229,
     229,   229,   229,  7589,  7589,  7589,  7589,  7589,  7589,  7589,
     229,  7589,   229,   229,   229,   126,   229,   226,   268,   229,
     229,  7589,  7589,  7589,  7589,  7589,  7589,  7589,  7589,  7589,
    7589,  7589,  7589,  7589,  7589,  7589,   229, -2780, 14823, -2780,
    1738,  7589,  7589,  7589,  7589,  7589,  7589,  7589,   229,   229,
     229, -2780, -2780,  7589,  7589, -2780,  7589, -2780, -2780,    30,
   -2780,  1270,  1733, -2780, -2780, -2780, -2780, -2780, -2780, -2780,
   -2780,   219,   219, -2780,  7589, -2780,  7589,    30,   229,   229,
    7589, -2780,  7589,  7589,  7589,  1599,    30,   229, -2780,   229,
     229,  7589,  7589,  7589,  7589,  7589,  7589,  7589, -2780,  7589,
    7589, -2780,  7589,  7589,  7589,  7589,  7589,  7589, 14823,  7589,
    7589,  7589,  7589,  7589,  7589,  7589,  7589,   229, 14823,  7589,
   14823,  7589,  7589,   229,  7589,  7589,  7589, 14823,   229,   199,
     199,   199, 14823, 14823, 14823,    30, 14823,   229,   199,   229,
     199,   199, 14823,   133, -2780, 14823, 14823, 14823, 14823, 14823,
    1464,  7589,  7589,    30,  -281, 11047,    30,  7589,  1736,  7589,
    7589,    30,    30,    30,    10,    30, -2780, -2780,  1737,  7589,
    1740,  1739,   304,  1742,  1744,  1745,  1741,  1746,  1753,  1750,
    1757,  1758,  1759,  1754,  1755,  1756,  1760,  1761,  1764,  1768,
    1766,  1769,  1770,  1771,  1778,  1773,  1780,  1775,   476,  1782,
    1783,  1779,  1781,  1784,  1785,  1788,  1787,   531,  1789,  1791,
    1792,  1793,  1794,  1795,  1800,  1801,  1802,  1797, 13587, -2780,
    1804,  1799,  1803,  1805, -2780, -2780, -2780,   546,   576,  1806,
    1807,  1808,  1809,  1810,  1811,  1812,  1813,  1814,  1815,  1816,
    1817,  1818,  1819, -2780, -2780,  1820,  1821,  1828,  1823, -2780,
    1743,  1747,  1824,  1825,  1826,  1834,  1835,  1836,  1829,  1831,
    1832,  1837,  1839,  1841,  1842,  1843,  1844,  1851,  1855,  1856,
    1857,  1861,  1859,  1862,  1867,  1868,  1869,   578,  1871,  1872,
    1874,  1875,  1876,  1877,  1878,  1885,  1880,  1881,  1882,  1883,
    1887,  1888,  1891,  1895,  1892,  1905,  1907,  1908,  1909,  1910,
    1911,  1912,  1913,  1914,  1924,  1925,  1926,  1933,  1934,  1935,
    1936,  1937,  1938,  1939,  1941,  1942,  1943,   593,  1948,  1949,
    1950,  1951,  1959,   637,   670,  1953,  1940,  1971,   481,  1146,
     134, -2780, -2780,  1972,  1967,   979,   669,   314,  1865, -2780,
   -2780, -2780, -2780, -2780, -2780,   100,   418,   100,   418, -2780,
   -2780, -2780, -2780, -2780, -2780, -2780, -2780, -2780,   108, -2780,
     108,   510, -2780,  1350,    81,  1235,  1975,  1976,  1977,  1978,
    1982, -2780,  1984,  1987,  1988,  1986,  1989,  1990,   691,   715,
    1991,  1992,  1993,  1994,  1995,  1997,  2004,   719,  2000,  2007,
    2002,  2003,  2005,  2010,   319,  2013, 14823, -2780,  2012, 15235,
    1367,  2011,  2016, 14823,   229,   229,   741,  2018,  2014,   742,
    2021,  2022,  2023,  2024,  2026,  2027,  2030,  2034,  2035,  2036,
    2037,  2038,  2039,  2040,  2041,  2042,  2044,  2043,  2045,  2048,
    2051,  2052,  2053,  2054,  2055,  2056,  2057,  2058,  2059,  2060,
    2061,  2062,  2064,  2066,  2068,  2063,  2070,  2071,  2072,  2073,
    2074,  2069,  2076,  2077, 14823,  2075,  2078,   772,  2080,  2081,
    2079,  2082,  2083,  2084,  2086,  2087,  2088,  2097,  2095,  7589,
      30,   161,   161,  1765,  1899,  1900,  1952,  1998,   773,   776,
    2098,  2099,  2108,  2104,  2105, -2780,   389,  2106,  2113, 12063,
    2114,   783,  2115,  2116,  2111,   550,  2112,   570,  2119,   786,
    2118,  2121,   811,  2120,  2125,  2131,  2132,   812,  2133,  2134,
    2129,   813,  2137,  2136,  2138,  2142,  2140,  2143,  2150,  2151,
    2152,  2153,  2154,  2156,  2155,  2159,  2157,  2166,  2161,  2168,
    2169,  2170,   815,  2165,  2172,  2173,  2174,  2175,   820,  2182,
    2186,   822,  2192,  2193,  2198,  2200, -2780,  2176,   823,  2201,
    2202,  2203,  2204,  2122,  2209,  2210,  2213, -2780,   824,  2214,
    2215,  2212,  2216,  2219,  2217, -2780, -2780,  2220,    30,   134,
   -2780, -2780,   229,  7589,  7589,  7589,  7589, -2780,  7589, -2780,
    7589, -2780, -2780, -2780,   229,   229,  7589,  7589,  7589, -2780,
   -2780,  7589,  7589,  7589,  7589, -2780,  7589, -2780,  7589, -2780,
    7589, -2780, -2780,  7589,  7589,  7589,  7589, -2780,  1422, -2780,
    7589, -2780,   229,  7589, 14823, -2780,  1601, -2780, -2780, -2780,
    1776, 12063, -2780, -2780,  7589,   -33,  7589, -2780, 14823,    65,
    7589,  7589, -2780,  7589,  7589,  7589,  7589,  7589,  7589,  7589,
    7589,  7589,  7589,  7589,  7589, -2780,  7589,   229,   229, 14823,
   14823,   229,   229,   229, -2780,  7589,  7589,  7589,  7589,  7589,
    7589,  7589,  7589,  7589, -2780, -2780, -2780,   229, -2780,   229,
     229,   229,   229,   229, -2780,   229,   229,  7589,  7589,  7589,
    7589, 14823, 14823, -2780,  7589,  7589,  7589,  7589,   229,    30,
   -2780, -2780,   229,   229,  7589,  7589,  7589,  7589,  7589,  7589,
    7589,  7589,  7589,  7589,  7589, -2780, -2780, -2780, -2780, -2780,
   -2780, -2780,  7589,  7589,  7589, -2780,  7589,  7589,   229,  7589,
    7589,   229, -2780,  7589, -2780,  7589, 14823, -2780, -2780, -2780,
   -2780, -2780, -2780, -2780,  1985, -2780,  7589, -2780, 14823,  7589,
     229,  2221,  2222,  2224, -2780, -2780, -2780,  7589,  7589,  2103,
   -2780,    30, -2780,  7589,    30,    30,    30,    30,    30,  7589,
   -2780, -2780,  7589,  7589, -2780,  7589,  7589,  7589, -2780, -2780,
   -2780, -2780, -2780, 14823, -2780,  2225,  2226,   863, -2780,   229,
   -2780,  7589, -2780,  7589, -2780, -2780, -2780, -2780, -2780, -2780,
   -2780, -2780, -2780, -2780, -2780, -2780, -2780,  7589, -2780, -2780,
     229, -2780, -2780, -2780, -2780, -2780, -2780, -2780, -2780, -2780,
   -2780, -2780,  7589, -2780,  7589, -2780, -2780, -2780, -2780,  7589,
   -2780, -2780, -2780, -2780, -2780,  7589, -2780, -2780,  2227,  7589,
    7589, -2780, 12063,  7589,  7589, -2780,  7589,  7589,   229,   229,
    7589,  7589, -2780,  7589,  1602, -2780, -2780, -2780, -2780, -2780,
   -2780, -2780, -2780, -2780,   596, -2780,  7589,  7589, -2780,   229,
    7589, -2780,  7589,  7589,  7589, -2780, -2780, -2780, -2780, -2780,
    7589, -2780, -2780,  7589, -2780,  7589, -2780, -2780, -2780,  7589,
    7589,  7589, -2780,  7589, -2780, -2780, -2780, -2780, -2780,  7589,
   -2780, -2780,  7589, -2780,  7589, -2780,  7589,  7589,  7589, -2780,
   -2780, -2780, -2780, -2780, -2780, -2780, -2780,  7589,  7589, -2780,
   -2780,  7589, -2780, -2780, -2780, -2780,  7589,  7589,  7589,  7589,
    7589,  7589, -2780,  7589,  7589,  7589, -2780,  7589,  7589,  7589,
    7589,  7589, -2780, -2780,  7589,  7589,  7589, 12063, 14823,  7589,
   -2780, -2780, -2780, -2780, -2780, -2780,  1930,  2228,  2229,  2189,
   -2780,  2230,  2231,  2232,  2233,  2236,  2234,  2238,  2235,  2242,
    2243,  2244,  2246,  2241,  2245,  2248,  2247,  2249,  2250,  2251,
    2252,  2253,  2254,  2255,  2256,  2258,  2263,  2264,  2259,  7589,
    2266,  2261,  2262,  2269,   864,  2265,  2267,  2270,  2272,  2274,
    2275,  2271,  2276,  2273,  2277,  2278,  2279,  2280,  2281,  2282,
    2283,  2290,  2285,  2286,  2287,  2288,  2289,  2291,  2292,  2293,
    2294,  2295,  2296,  2297,  2298,  2299,  2306,  2301,  2302,  2303,
    2304,  2305,  2307,  2312,  2314,  2309,  2316,  2317,  2318,  2313,
    2315,  2320,  2322,  2323,  2324,  2319,  2326,  2327,  2325,  2328,
    2329,  2330,  2332,  2333,  2336,  2337,  2338,  2341,   867,  2339,
    2342,  2343,  2344,  2347,  2345,  2346,  2353,  2348,  2349,  2356,
    2357,  2359,  2354,  2355, -2780,  2362,  2363, -2780, -2780, -2780,
      54,  2358,    85,  2360,  2365,  2367,    33,  2368,  2369,  2370,
    2371,  2366,  2373,  2374,  2375,  2372,  2376,  2377,  2379, -2780,
   -2780, -2780,  7589,  2380,  2378,  2381,  2383,  2382,  2384,  2385,
    2386,  2387, -2780,   868,   876,   878,  2389,  2388,  2390,  2391,
    2392,  2393,  2394,  2395,  2396,  2403,  7589,   161,   161,  2019,
    2096,  2130,  2191,  2207,   161,  2404,  2399,  2400,  2401,   475,
    2408,  2167,  2405,  2406,  2407,  2409,  2410,  2411,  2412,  2414,
    2413,  2415,  2416,  2417,  2418,  2419,  2420,  2421,  2422,  2429,
    2424,  2425,  2426,  2427,  2434,   879,  2435,  2436,  2437,  2438,
    2439,  2441,   904,  2442,  2443,  2444,  2447,  2452,  2457,  2458,
      30,    30,  2445, -2780,  7589, -2780,  7589, -2780,  7589, -2780,
    7589, -2780, -2780, -2780, -2780,  7589,  7589, -2780,  7589,  7589,
    7589,  7589, -2780,  7589,  7589,  7589,  7589, -2780, -2780, -2780,
    7589, -2780, -2780,  7589,  7589, -2780, -2780,   208,    66,  7589,
   -2780, -2780, -2780, -2780,  7589, -2780,  7589,  7589,  7589,  7589,
    7589,  7589,  7589,  7589, -2780,  7589,  7589,  7589,  7589,  7589,
    7589,  7589,  7589,  7589,  7589,  7589,  7589,  7589,  7589, -2780,
    7589,   229,   229,   229,   229,   229, -2780, -2780,  7589, -2780,
   -2780, -2780,  7589,  7589, -2780, -2780, -2780, -2780, 14823, -2780,
   -2780, 14823,  7589,  7589, -2780, -2780, -2780, -2780, -2780, -2780,
   -2780, -2780,  7589,  7589,  7589,  7589,  7589, -2780,  7589,  7589,
   -2780,  7589,  7589, -2780, -2780, -2780,  7589,  7589, -2780, -2780,
    7589,  7589,  7589,  7589, -2780, -2780, -2780, -2780, -2780, -2780,
   -2780,    30, -2780, -2780, -2780,  7589, -2780, -2780, -2780,  2465,
   -2780,  7589, -2780, -2780,   229,  7589, -2780,  7589,  7589, -2780,
   14823, -2780, 14823, -2780, 14823, -2780, 14823,  7589,  7589,  7589,
     229,   229,  7589,  7589, -2780, -2780, -2780, -2780, -2780, -2780,
   -2780, -2780, -2780, -2780, -2780,  7589,   229,  7589, -2780,  7589,
    7589, -2780,  7589,  7589,  7589,  7589,  7589,  7589,  7589,  7589,
   -2780,  7589,  7589,  7589,  7589,  7589,  7589,  7589,  7589,  7589,
   -2780,  7589,  7589,  7589,  7589, -2780, -2780,   229, -2780, -2780,
   -2780, -2780, -2780, 14823, -2780,  7589,  7589,  7589,  7589, 14823,
   14823,  7589,  7589, -2780, -2780, -2780,  2467,   905,  2462,  2471,
    2466,  2468,  2473,  2470,  2472,  2477,  2475,  2484,  2499,  2479,
    2501,  2502,   572,  2503,  2504,  2511,  2507,   906,  2509,  2510,
    2514,   909,   916,   917,   918,  2515,  2516,  2517,  2518,  2513,
     587,   920,   368,  2519,  2520,  2521,  2524,   930,  2525,  2526,
    2527,  2528,  2529,  2530,  2537,  2540,  2543,  2544,  2545,  2548,
    2549,  2555,  2562,  2564,  2565,  2566,  2561,  2563,  2568,  2567,
    2569,  2570,  2572,  2573,  2574,  2582,  2579,  2223,  2321,  2580,
    2587,  2583,  2588,  2584,  2591, -2780,  2586,  2596,  2594,  2597,
    2595,  2602,   931,  2603,  2598,  2599,  2606,  2601,   932,  2604,
    2608,  2609,   161,  2611,  2620,  2630,  2612,  2614,  2635,  2636,
    2643,  2644,  2645,  2646,  2647,  2648,  2649,  2650,  2655,  2656,
    2659,  2660,  2661,  2662,  2657,  2658,  2663,  2664,  2665,  2666,
    2667,  2668,  2669,  2672,  2670,  2671,  2673,  2674,  2678, -2780,
   -2780,  7589,  7589, -2780,  7589,  7589, -2780,  7589,  7589, -2780,
    7589,  7589,  7589, -2780,  7589,  7589, -2780,   208,  7589, -2780,
   -2780,   208,  2211,  7589,  7589, -2780,  7589, -2780,  7589, -2780,
    7589, -2780,  7589,  7589,  7589,  7589,  7589, -2780, -2780, -2780,
    7589,  7589,  7589,  7589,  7589,  7589, -2780,  8492,  8492,  8492,
    7589,  7589,  7589,  7589, -2780,  7589,  7589,  7589,  7589,  7589,
     229,  7589, -2780, -2780, -2780, -2780,  7589,  7589, -2780,  7589,
    7589,  7589,  7589,  7589,  7589, -2780,  7589,  7589,  7589,  7589,
   -2780,  7589, -2780,    30, -2780,  7589, -2780,  7589, -2780,  7589,
   -2780, -2780,  7589, -2780,  7589,  7589, -2780,  7589, -2780, 14823,
     229, -2780, -2780, -2780,  7589,   229,  7589, -2780, -2780,  7589,
    7589, -2780, -2780, -2780, -2780, -2780, -2780, -2780, -2780, -2780,
   -2780, -2780, -2780, -2780, -2780,  7589,  7589,  7589,  7589,  7589,
   -2780, -2780, -2780, 14823, -2780,  7589,  7589,  7589, -2780, -2780,
    2675,  2680,  2682,  2677,  2679,  2681,  2684,  2686,  2688,  2683,
     940,  2685,  2687,  2690,   942,  2689,  2691,   947,   951,  2692,
    2693,  2694,  2695,  2696,  2703,  2698,  2699,  2700,  2701,  2702,
    2704,   718,  2709,   721,  2711,  2334,  2712,  2707,  2710,  2713,
    2714,  2715,  2716,  2717,  2718,  2719,   952,  2720,  2727,   954,
    2728,  2729,  2730,  2725,  2726,  2731,  2733,  2541,  2732,  2734,
    2735,  2736,  2739,   955,  2737,  2740,  2741,  2738,  2742,  2745,
    2743,  2744,  2746,  2747,  2335,  2751,  2754,  2749,  2750,  2757,
    2752,  2753,  2755,  2756,  2758,  7589, -2780, -2780,  7589,  7589,
    7589, -2780, -2780, -2780,  7589, -2780,  7589,  7589,    30, -2780,
   -2780,   208,  7589,  7589, -2780,  7589, -2780,  7589,  7589,  7589,
    7589,  7589,  7589, -2780,  7589,  7589,  7589,  7589,  7589,  7589,
    8492, -2780,  8492, -2780, -2780,  8492,  8492,  7589,  7589,  7589,
     229,   229,   229,   229, -2780,  7589,  7589, -2780, -2780,  7589,
   -2780, -2780, -2780,  7589,  7589,  7589, -2780, -2780,  7589, -2780,
   -2780, -2780, -2780, -2780,  7589,  7589, -2780, -2780,  7589,  7589,
   -2780,   229,  7589,   229,  7589,  7589, -2780, -2780,  7589,  7589,
   -2780,  7589, 14823,  7589,  7589,  7589,  2760,  2759,  2761,  2762,
    2763,  2766,  2764,  2765,  2772,  2773,  2768,  2775,  2776,  2777,
    2778,  2779,  2780,  2781,   983,  2782,  2783,  2784,  2785,  2786,
    2788,  2790,  2791,  2793,  2789,  2794,  2796,  2799,  2802,  2803,
    2806,  2805,  2807,  2815,  2810,  2817,  2812,  2402,  2819,  2821,
    2827,  2828,  2829,  2836,  2844,  2850,  2823,  2852,  2853,  2854,
     985,  2855,  2858,  2865, -2780,  7589,  7589,  7589,  7589, -2780,
    7589,  7589, -2780, -2780,  7589, -2780, -2780, -2780, -2780, -2780,
   -2780,  7589, -2780,  7589, -2780,  7589, -2780, -2780,  7589, -2780,
   -2780, -2780, -2780,  8492, -2780, -2780, -2780, -2780,  7589,  7589,
   -2780,  7589, -2780,  7589, -2780,  7589,  7589,  7589, -2780,  7589,
    7589,   229,  7589,   229,  7589,  1916,  7589,  7589,  7589, -2780,
   14823,  7589,  7589,  7589,  2876,  2878,  2873,  2880,    38,  2881,
    2883,  2886,  2882,  2884,  2894,  2889,  2896,  2891,  2892,  2899,
    2895,  2898, -2780,  2908,   987,  2903,  1050,  2904,  2905,  2906,
   14823,  2907,  2909,  1051,  2910,  2914,  1058,  2911, -2780, -2780,
    7589, -2780, -2780,    30,  7589,  7589, -2780, -2780, -2780,  7589,
   -2780,  7589,  7589, -2780,  7589,  7589, -2780, -2780, 14823,  7589,
   -2780, 14823,  7589,  7589,  7589, -2780,  7589,  7589, -2780,  7589,
    7589, -2780, -2780,  7589,  7589,  2912,  2919,  2920,  2926,  2927,
    2928,  2923,  2924,  2929,  2934,  2936,  2937,  2932,  2933,  2935,
    2940,  2938,  2939,  2942,  1060,  1062,  7589, -2780, -2780, -2780,
   -2780, -2780,  7589,  7589,  7589, -2780, -2780, -2780,  7589,  7589,
     229, -2780,  7589,  7589, -2780, -2780,  7589, -2780, 14823,  2941,
    2943,  2946,  2944,  2948,  2945,  2947,  2952,  2949,  2954,  2950,
    7589,  7589, -2780,  7589, -2780,  7589,   229, -2780,  7589, -2780,
   14823,  2951,  2958,  2953,  2955,  2956,  2960,  2963,  7589, -2780,
    7589,  7589,  7589, -2780, -2780,  2959,  2961,  2962,  2964,  7589,
    7589,  7589, -2780,  2965,  2966,  2967,  7589,  7589,  7589,  2969,
    2968,  2970, -2780,  7589,  7589,  2971,  2975,  7589, -2780,  2978,
   -2780
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  Parser::yydefact_[] =
  {
         2,   501,     0,     0,     0,     0,    21,    74,    75,    76,
      77,     0,     0,     0,   392,   401,    39,    20,     0,   109,
      81,     0,     0,     0,     0,     0,     0,     0,   108,   384,
     400,   851,   548,   404,   405,   406,   385,     0,   811,     0,
     767,     0,   860,   861,   862,   863,   864,   865,     0,     0,
     870,   871,     0,     0,    41,    44,    42,    43,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   317,   390,   318,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      85,     0,     0,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,     0,     0,     0,   402,   403,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   398,    40,     0,    35,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   344,   345,   346,   347,
     348,   349,     0,     0,   502,     0,     0,     4,     8,    10,
      14,    16,    18,    12,     0,   386,   393,   396,     0,   408,
     483,   503,     0,   505,   509,   512,   513,   518,   523,   525,
     527,   529,   531,   533,   535,   536,   310,   477,     0,   769,
     771,   772,   790,   791,   795,   800,   801,   802,   803,   804,
     805,   806,   807,   808,   809,   810,   118,     0,     0,     0,
       0,     0,     0,   404,   405,   406,     0,   811,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   485,
       0,     0,   767,   487,   775,   486,   774,   385,     0,   477,
       0,     0,     0,     0,     0,   102,    82,    84,   111,   110,
      83,   114,   121,   116,   115,   122,   117,     0,     0,     0,
     107,    92,    93,     0,    95,    96,     0,    99,   100,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   356,
     356,    38,    33,     0,     0,     0,     0,     0,   853,   852,
     854,   866,   856,   857,   858,   867,   859,   861,   863,   864,
     869,   868,   870,   871,   855,   104,   105,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   488,   777,   489,   778,   494,
     783,   495,   784,   496,   785,   497,   786,   498,   787,   500,
     789,   499,   788,   490,   779,   491,   780,   492,   781,   493,
     782,     0,    25,     0,   398,     0,    36,     0,     0,     0,
      30,    28,   398,     0,     0,     0,     0,     0,     0,     1,
       3,     5,     9,    11,    15,    17,    19,    13,     0,     6,
       0,     0,     0,     0,   484,   773,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   776,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   407,     0,
       0,   770,     0,     0,     0,     0,     0,     0,    94,    97,
      98,   101,     0,     0,     0,     0,     0,     0,   445,   446,
     443,   444,   441,   442,   447,   448,   449,     0,     0,     0,
     125,     0,     0,     0,     0,   132,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   277,     0,     0,     0,     0,   282,   283,     0,   266,
       0,   274,     0,     0,     0,     0,     0,   263,   264,     0,
      56,    57,     0,     0,   120,     0,     0,    73,     0,     0,
       0,     0,     0,   558,     0,   371,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,   359,
       0,   357,   562,   698,   700,   701,   719,   721,   727,   728,
     733,   734,   743,   748,   750,   751,   753,   755,   757,   759,
     761,   365,     0,     0,   329,     0,   322,     0,   323,   320,
     321,     0,     0,     0,   327,   328,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   324,
     325,   326,   330,     0,     0,     0,   331,   342,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   562,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   174,   175,     0,     0,   450,   451,     0,     0,
       0,     0,     0,     0,     0,     0,   452,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   213,   214,   176,   177,
     178,   179,     0,     0,   562,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   767,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   399,     0,    34,
     870,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,   394,   395,   521,   522,   506,
     507,   508,   510,   511,   515,   514,   516,   517,   519,   520,
     524,   526,   528,   530,     0,   532,     0,     0,     0,   391,
       0,   417,   419,     0,   216,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   547,   418,    87,    88,    86,   792,
     794,   793,   796,   798,   797,   799,   420,   421,   422,     0,
       0,     0,   481,     0,   250,     0,   245,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   244,     0,   236,     0,   246,   247,     0,
       0,     0,     0,     0,   255,   257,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   825,     0,     0,     0,     0,     0,   828,
      61,     0,    51,     0,     0,     0,   558,     0,     0,     0,
     762,    59,     0,   825,     0,   538,   541,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    69,     0,    67,    50,    55,    54,   828,    60,     0,
       0,     0,     0,     0,   504,     0,    79,    80,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     112,   119,   113,     0,     0,     0,   562,   719,   704,   703,
     477,     0,   361,   363,   367,   369,     0,   550,     0,     0,
       0,   356,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   705,   706,   711,
     712,   713,   714,   715,   717,   716,   707,   708,   709,   710,
     718,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   352,     0,   702,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   343,
     812,     0,   549,     0,    45,     0,     0,   562,     0,     0,
       0,     0,     0,   428,     0,     0,   430,     0,   431,   432,
       0,   433,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   424,     0,   429,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   311,   312,     0,     0,   426,     0,   768,   440,     0,
     314,     0,   398,   354,   397,   398,    26,   474,   475,   476,
     316,   373,   373,    32,     0,   258,     0,     0,     0,     0,
       0,   409,     0,     0,     0,     0,     0,     0,   215,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   219,     0,
       0,   220,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   823,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   356,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   812,   549,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   699,
       0,     0,     0,     0,   648,   646,   647,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   617,   618,     0,     0,     0,     0,   621,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   372,
     360,   358,   366,     0,     0,   875,     0,   874,     0,   760,
     726,   722,   724,   723,   725,   729,   731,   730,   732,   740,
     736,   739,   735,   741,   737,   742,   738,   746,   744,   747,
     745,   749,   752,   754,     0,   756,     0,     0,     0,     0,
       0,    37,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,   534,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   822,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   763,     0,     0,
       0,     0,     0,     0,     0,    70,    68,     0,     0,   389,
     388,   387,     0,     0,     0,     0,     0,   148,     0,   151,
       0,   124,   127,   126,     0,     0,     0,     0,     0,   135,
     136,     0,     0,     0,     0,   141,     0,   150,     0,   267,
       0,   262,   269,     0,     0,     0,     0,   265,     0,   275,
       0,   270,     0,     0,     0,   273,   453,   478,   479,   480,
       0,     0,   720,   551,     0,     0,     0,   557,     0,     0,
       0,     0,   597,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   598,     0,     0,     0,     0,
       0,     0,     0,     0,   629,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   582,   583,   584,     0,   586,     0,
       0,     0,     0,     0,   593,     0,     0,     0,     0,     0,
       0,     0,     0,   600,     0,     0,     0,     0,     0,     0,
     555,   556,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   673,   578,   580,   642,   643,
     644,   645,     0,     0,     0,   677,     0,     0,     0,     0,
       0,     0,   689,     0,   691,     0,     0,   693,   694,   362,
     364,   368,   370,   674,     0,   563,     0,   604,     0,     0,
       0,     0,     0,     0,   472,   473,   471,     0,     0,     0,
     460,     0,   465,     0,     0,     0,     0,     0,     0,     0,
     334,   336,     0,     0,   470,     0,     0,     0,   332,    58,
      62,    53,    46,     0,   482,     0,     0,     0,   308,     0,
     162,     0,   161,     0,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   182,   183,   184,     0,   197,   198,
       0,   200,   208,   202,   203,   209,   204,   210,   206,   207,
     205,   185,     0,   195,     0,   186,   211,   212,   191,     0,
     187,   188,   189,   190,   193,     0,   423,   439,     0,     0,
       0,   290,     0,     0,     0,   297,     0,     0,     0,     0,
       0,     0,   766,     0,   398,   355,    24,    27,   376,   377,
     378,   374,   375,   398,     0,   398,     0,     0,   341,     0,
       0,   410,     0,     0,     0,   416,    90,    89,   159,   158,
       0,   217,   218,     0,   304,     0,   306,   307,   154,     0,
       0,     0,   152,     0,   237,   242,   248,   249,   252,     0,
     251,   221,     0,   233,     0,   229,     0,     0,     0,   225,
     226,   227,   228,   234,   243,   235,   238,     0,     0,   231,
     241,     0,   256,   260,   829,   830,     0,     0,     0,     0,
       0,     0,   826,     0,     0,     0,   817,     0,     0,     0,
       0,     0,   824,   839,     0,     0,     0,     0,     0,     0,
      48,    49,   765,    52,   319,    47,     0,    65,    63,     0,
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
       0,     0,     0,     0,   758,     0,     0,   683,   685,   686,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   434,
     435,   436,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   438,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78,     0,   143,     0,   146,     0,   149,
       0,   130,   128,   131,   133,     0,     0,   138,     0,     0,
       0,     0,   268,     0,     0,     0,     0,   276,   271,   284,
       0,   454,    72,     0,     0,   569,   570,     0,     0,     0,
     596,   599,   601,   602,     0,   603,     0,     0,     0,     0,
       0,     0,     0,     0,   622,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   581,
       0,     0,     0,     0,     0,     0,   594,   595,     0,   564,
     565,   566,     0,     0,   649,   650,   651,   652,     0,   697,
     658,     0,     0,     0,   663,   664,   665,   666,   667,   668,
     669,   670,     0,     0,     0,     0,     0,   678,     0,     0,
     679,     0,     0,   688,   690,   692,     0,     0,   684,   687,
       0,     0,     0,     0,   459,   461,   464,   463,   466,   462,
     467,     0,   468,   333,   337,     0,   338,   339,   340,     0,
     309,     0,   173,   196,     0,     0,   199,     0,     0,   285,
       0,   287,     0,   292,     0,   291,     0,     0,     0,     0,
       0,     0,     0,     0,   313,   398,    22,    31,   381,   382,
     383,   379,   380,    29,   353,     0,     0,     0,   411,     0,
       0,   415,     0,     0,     0,     0,     0,     0,     0,     0,
     253,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     832,     0,     0,     0,     0,   827,   813,     0,   814,   818,
     819,   820,   821,     0,   840,     0,     0,     0,     0,     0,
       0,     0,     0,    66,    64,    71,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   477,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   437,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   142,
     144,     0,     0,   123,     0,     0,   140,     0,     0,   261,
       0,     0,     0,   281,     0,     0,   561,     0,     0,   571,
     572,     0,     0,     0,     0,   608,     0,   611,     0,   613,
       0,   615,     0,     0,     0,     0,     0,   619,   620,   653,
       0,     0,     0,     0,     0,     0,   630,     0,     0,     0,
       0,     0,     0,     0,   640,     0,     0,     0,     0,     0,
       0,     0,   567,   568,   696,   659,     0,     0,   671,     0,
       0,     0,     0,     0,     0,   682,     0,     0,     0,     0,
     455,     0,   457,     0,   335,     0,   201,     0,   192,     0,
     286,   288,     0,   293,     0,     0,   302,     0,   301,     0,
       0,   425,   427,    23,     0,     0,     0,   413,   414,     0,
       0,   303,   305,   155,   156,   412,   153,   230,   232,   222,
     223,   224,   239,   240,   254,     0,     0,     0,     0,     0,
     815,   816,   841,     0,   842,     0,     0,     0,   838,   764,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   873,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   147,   134,     0,     0,
       0,   278,   279,   280,     0,   559,     0,     0,     0,   573,
     574,     0,     0,     0,   607,     0,   610,     0,     0,     0,
       0,     0,     0,   579,     0,     0,     0,     0,     0,     0,
       0,   631,     0,   633,   635,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   591,     0,     0,   660,   661,     0,
     672,   675,   676,     0,     0,     0,   577,   605,     0,   456,
     458,   469,   160,   180,     0,     0,   289,   296,     0,     0,
     300,     0,     0,     0,     0,     0,   157,   831,     0,     0,
     835,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   145,     0,     0,     0,     0,   560,
       0,     0,   575,   576,     0,   609,   612,   614,   616,   623,
     626,     0,   655,     0,   657,     0,   624,   627,     0,   632,
     634,   636,   637,     0,   639,   585,   587,   588,     0,     0,
     592,     0,   662,     0,   680,     0,     0,     0,   194,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   843,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   872,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   137,   139,
       0,   272,   553,     0,     0,     0,   625,   656,   654,     0,
     638,     0,     0,   641,     0,     0,   181,   294,     0,     0,
     299,     0,     0,     0,     0,    91,     0,     0,   837,     0,
       0,   848,   847,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   554,   552,   606,
     628,   589,     0,     0,     0,   295,   315,   298,     0,     0,
       0,   833,     0,     0,   844,   845,     0,   849,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   695,     0,   259,     0,     0,   834,     0,   846,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   590,
       0,     0,     0,   836,   850,     0,     0,     0,     0,     0,
       0,     0,   351,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   129,     0,     0,     0,     0,     0,   350,     0,
     681
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
     -2780, -2780, -2780,   -44,  2146,  2148,  2149, -2780, -2780,  2164,
    2196,  2311,  2440, -2780,  -276,   472, -2780,   358, -2780,  7235,
    -372, -2780, -2780, -2780, -2780,  -442,  5664,   141,  -404, -2780,
    -398,   464,  1879,  1850,  1981,  2340,  1979,  2110,   736, -2780,
       0,    90,  3358, -2780, -2780, -2780,  -496,   -98,  -411, -2780,
   -2780,  -528,  -297,   877, -2780,  1008,  1136,  1199,  1211,   387,
    1201,  7652,  1392, -2780, -2780, -2780, -2780,   584,   545, -2780,
   -2780, -2780, -2780, -2780, -2780, -2780, -2780, -2780, -2780, -2780,
      35,  6692,  -433,    36,   -43, -2779
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,   145,   146,   147,   148,   149,   150,   856,   855,   151,
     152,   153,   154,  1342,   648,  1758,   155,   156,   157,   158,
     372,   373,  1344,   159,   160,   161,   228,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     238,   177,   240,   653,   654,   655,   656,   657,   658,   659,
     660,   661,   662,   663,   664,   665,   666,   667,   668,   669,
     670,  1081,  1015,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     241,   231,   980,   905,   199,  1618
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int Parser::yytable_ninf_ = -868;
  const short int
  Parser::yytable_[] =
  {
       176,   281,   848,  1018,   673,   872,   873,  1024,     6,   305,
     857,   522,   523,   874,   875,   876,   877,   889,    31,    17,
     845,   987,   252,   255,   707,    32,     1,   912,   914,   823,
     824,   207,   825,  1077,  1077,   196,   198,  1529,  1529,  1523,
    1524,   429,  -866,   211,   212,   277,  1360,  2576,  1486,    31,
    -853,    14,  3282,  1086,   889,   249,   275,   253,   990,  1646,
      31,    14,  -867,  1505,  1506,    25,    26,   271,   411,   412,
    1442,    14,   433,    29,  2570,    25,    26,    32,  2982,  2984,
    2986,   237,   282,    29,   826,    25,    26,    32,   423,   421,
     424,   237,   242,    29,   425,   239,   212,    32,  1223,   280,
     435,   237,   391,  2018,   285,  2572,   212,   406,   407,     6,
     399,    31,   408,  1214,  1215,   243,   212,  1837,  2264,  2697,
      17,   436,    32,    32,   374,   380,  1077,  1077,  1077,  1077,
    1077,  1077,  1077,  1077,  1077,  1077,  1077,  1077,  1077,  1077,
     244,   212,   212,   229,   233,   235,   176,  1826,   258,  1647,
    1648,  1649,  1650,  1495,  1077,  -852,  1496,   371,  -854,   422,
     766,   259,   261,   262,    14,   270,   381,   382,   278,  1530,
    1530,   402,   403,   263,   434,   430,   402,   403,    25,    26,
     891,   196,   198,    32,     6,   276,    29,   279,   402,   403,
      32,    68,   402,   403,   237,    17,   426,   283,   892,   413,
     414,    68,   212,   422,  1531,  1531,   888,   889,   284,   212,
     286,    68,  1224,    31,   756,   757,  1224,   427,   287,  1077,
    1077,   708,   891,   402,   403,   272,  1077,  1077,  1077,  1077,
    1077,  1077,  1077,  1077,  1077,  1077,  1077,  1077,  1077,  1077,
     892,   400,   401,   453,  1216,  1217,   916,   917,   918,   345,
     347,   349,   351,   353,   355,   357,   359,   361,   363,   365,
     367,   369,   207,   458,   307,    32,   459,   264,   265,   460,
     267,   268,   402,   403,   211,   519,   520,   308,   266,   651,
     651,   269,  1423,    32,   212,   709,    32,   711,  1833,   409,
     410,  3150,   239,  3151,   309,  1708,  3152,  3153,   922,  1646,
      14,   312,   212,   404,    68,   212,   445,   713,   714,   317,
     740,   521,   446,   890,    25,    26,    32,   445,   916,   917,
     918,  1461,    29,   450,  1853,    32,    32,   445,   273,   274,
     237,   849,  1203,   450,   852,   212,   817,   818,  1204,   820,
     822,   233,   235,   318,   212,   212,  1361,  1106,   916,   917,
     918,   846,  1362,  1107,   864,  1364,   345,   347,   349,   351,
     353,   355,   357,   359,   361,   363,   365,   367,   369,   404,
     922,  1361,   902,   415,   416,   891,   841,  1362,   319,  1363,
    1364,   445,   207,   858,   994,   431,   432,   450,  2851,  1647,
    1648,  1649,  1650,   892,   211,  1711,   893,   894,   895,   896,
     922,  1646,   904,  2141,  1262,   248,  1207,   904,    31,  2142,
     322,  1318,  2143,   851,   902,   320,   524,   525,   526,   527,
      91,    92,  1209,   886,   887,  1210,  1211,   907,   897,   898,
     899,  1078,  1079,  1206,  3256,  1207,  1013,  1713,   321,   450,
      68,  1020,  1021,  1226,   904,  1022,   525,   526,   245,  1204,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
      32,  1082,  1083,  1206,  1345,  1207,   207,   323,   310,   446,
     311,  1016,   827,   828,   829,   830,   831,   832,   211,   212,
     833,   834,   835,   836,   837,   838,   839,  1077,  1077,  2628,
    1879,  1647,  1648,  1649,  1650,  2629,  1880,   313,  2630,   314,
     798,   799,  1077,  1077,  1077,  1077,  1077,  1077,  1077,  1077,
    1077,  1077,  1077,  1077,  1077,  1106,  1077,   445,  1335,   800,
     801,  1260,  1071,   450,  1177,  1178,  1179,  1180,  1181,  1182,
    1183,  1184,  1185,  1186,  1187,  1188,  1189,  1190,    32,  2009,
    2010,   315,   326,   316,   207,  1889,   144,   869,   870,   871,
     327,  1890,  1205,  1262,   328,  1207,   211,   212,   389,  1680,
    1907,   900,   901,   445,  2154,   329,  1204,   902,   330,   450,
     909,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     903,   756,   757,   445,  2156,   445,  2826,   234,   236,   450,
    1266,   450,  1954,   958,   959,   960,  1908,   904,  1955,   331,
     445,  2848,   961,   962,   963,   964,   450,  1995,   324,   965,
     325,  1212,  1213,  1996,   749,   332,  1504,  1078,  1079,   333,
    1092,  1080,   311,  1479,  1177,  1178,  1179,  1180,  1181,  1182,
    1183,  1184,  1185,  1186,  1187,  1188,  1189,  1205,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,  1218,  1219,
     966,  2002,   334,   967,   968,   969,   970,  2003,   971,   972,
     335,  1262,   973,  1207,  1505,  1506,   750,   751,   752,   753,
     233,   235,   754,   755,   756,   757,   758,   759,   760,   761,
     762,   763,   764,   765,  2004,  2015,  1630,  1632,  1634,  1636,
    2005,  2016,   346,   348,   350,   352,   354,   356,   358,   360,
     362,   364,   366,   368,   370,  2030,  1753,  1754,  1755,  1756,
    1757,  2031,  1253,  1077,  1077,  1077,  1077,  1077,  1077,  1077,
    1077,  1077,  1077,  1077,  1077,  1077,  1077,  1077,  1077,  2032,
    1523,  1524,   497,  2041,   498,  2033,   499,   500,  3070,  2042,
    2016,  3072,   336,  2016,   501,   337,   405,   502,   503,   504,
     505,   506,   507,   508,   509,  2058,  2062,   338,   865,   866,
     339,  2059,  2063,   345,   347,   349,   351,   353,   355,   357,
     359,   361,   363,   365,   367,   369,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   510,  2111,  2133,   340,   511,
    2135,   404,  2112,  2134,   512,   513,  2134,  2149,   674,   417,
    2158,  1626,  1628,  2150,  1346,   514,  2159,  1256,  1625,  1627,
     515,   516,   341,  1353,   342,  1507,  1629,  1631,  1633,  1635,
    1637,  1639,   974,   975,   976,  2162,  2168,  2173,   977,  2195,
     978,  2163,  2169,  2174,  2202,  2196,  2206,  2213,  2223,   343,
    2203,   344,  2207,  2214,  1204,  1341,   675,   676,   677,   678,
     679,   680,   681,   682,   683,   684,   685,   686,   687,   688,
     689,   690,   691,   692,   693,   694,   695,   696,   697,   698,
     699,   700,   701,   702,   703,   704,   705,  2371,  2486,   878,
     879,  2551,  2599,  2372,  2487,  1078,  1079,  2552,  2600,   418,
    2601,   419,  2603,  2656,   377,  1086,  2602,  1432,  2604,  2657,
    1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,  1185,  1186,
    1187,  1188,  1189,    14,  1205,  1423,   378,  1437,  2664,  2810,
    2830,  1638,  1640,  2835,  2665,  2811,  2831,    25,    26,  2836,
    2837,  2839,  2841,    14,  2849,    29,  2838,  2840,  2842,    32,
    2850,   379,   383,   237,  2856,  2901,  2908,    25,    26,   384,
    2857,  2902,  2909,   420,  3045,    29,  3050,   385,   212,    32,
    3046,  3054,  3051,   237,   437,  3056,  3084,  3055,  3088,  3103,
    1751,  3057,  3085,  1752,  3089,  3104,   913,   915,   212,   386,
     387,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   428,  3202,   438,  3239,
     439,  3297,  1902,  3203,   675,  3240,   677,  3298,   388,   275,
     681,   682,   683,   910,   911,   686,   687,   688,   689,   690,
     691,   692,   693,   440,   441,   442,   443,   698,   448,  1450,
    1451,  1453,  1454,  1455,  1456,  1457,   444,  1459,  1460,   447,
     449,   451,  1465,  1466,  1467,  1468,  1469,  1470,  1471,   455,
    1473,   528,  1475,    68,  1477,  1478,  1024,  1480,  1481,  1482,
    1483,  1484,   477,   710,  3300,  3308,  1490,  1491,  1492,  1493,
    3301,  3309,  3312,    68,  3355,  1080,  3357,   815,  3313,   712,
    3356,   816,  3358,  2399,  2400,  2401,  2402,  2403,  1503,   847,
     854,   651,   740,   478,   479,   480,   481,   482,   860,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,  1620,  1622,  1624,  1025,   766,  1026,  1019,  1027,   889,
    1028,  1029,  1030,  1031,   233,   235,  1032,  1033,  1034,  1035,
    1036,  1037,  1038,  1039,  1040,  1041,  1042,  1043,  1044,   345,
     347,   349,   351,   353,   355,   357,   359,   361,   363,   365,
     367,   369,  1045,   404,  1046,  1047,  1048,  1049,  1050,  1838,
    1051,  1052,  1053,  1054,   706,  1089,  1055,  1056,  1057,  1058,
    1059,  1060,  1061,  1062,  1063,  1064,  1501,  1065,  1066,  1067,
    1068,  1208,  1651,  1902,  1073,  1074,  1075,   495,  1069,  1088,
    1091,  1093,  1094,  1090,  1095,  1096,  1097,  1098,  1099,  1100,
    1101,  1102,  1103,  1104,  1611,   496,  1022,  1616,    31,    32,
     288,   289,   290,   291,   292,   293,   294,   295,   296,    42,
     297,    44,   298,   299,    47,   300,   301,   850,   303,  1105,
    1108,  1109,  1110,  1111,  1112,  1660,  1113,  1114,  1115,  1118,
    1665,  2049,  1667,  1668,  1220,  1670,  1671,  1672,  1673,  1116,
    1117,  1675,  1119,  1120,  1121,  1122,  1123,  1124,  1125,  1126,
    1127,  1128,  1129,  1130,  1131,  1682,  1132,  1133,  1134,  1135,
    1136,  1137,  1138,  1449,  1687,  1139,  1689,  1690,  1691,  1140,
    1141,  1142,  1143,  1696,  1697,  1698,  1699,  1700,  1701,  1702,
    1144,  1704,  1145,  1197,  1146,  1147,  1148,  1149,  1150,  1151,
    1152,  1717,  1718,  1719,  1720,  1721,  1722,  1723,  1724,  1725,
    1726,  1727,  1728,  1729,  1730,  1731,  1153,  1154,  1155,  1156,
    1157,  1735,  1736,  1737,  1738,  1739,  1740,  1741,  1158,  1159,
    1160,  1161,  1162,  1745,  1746,  1163,  1747,  1164,  1165,  1166,
    1167,  1168,  1169,  1170,  1171,  1172,  1173,  1174,  1175,  1176,
    1191,  1621,  1623,  1192,  1760,  1193,  1761,  1194,  1195,  1196,
    1198,  1199,  1766,  1767,  1768,  1200,  1201,  1202,  1221,  1222,
    1225,  1774,  1776,  1778,  1779,  1780,  1781,  1782,  1227,  1783,
    1784,  1228,  1785,  1786,  1787,  1788,  1789,  1790,  1229,  1792,
    1793,  1794,  1795,  1796,  1797,  1798,  1799,  1230,  1231,  1802,
    1232,  1804,  1805,  1233,  1807,  1808,  1809,   234,   236,  1234,
    1235,   346,   348,   350,   352,   354,   356,   358,   360,   362,
     364,   366,   368,   370,   405,  1236,  1237,  1238,  1239,  1240,
    1241,  1834,  1835,  1242,  1243,   651,  1244,  1840,  1245,  1842,
    1843,  1246,  1247,  1248,  1255,  1258,  1254,  1250,  1251,  1850,
    1252,  1259,  1267,  1263,   766,   767,   768,   769,   770,   771,
     772,   773,   774,  1261,   775,   776,   777,   778,   779,   780,
     781,   782,   783,   784,   785,   786,   787,   788,   789,   790,
     791,   792,   793,   794,   795,  1264,  1266,  1265,  1268,  1269,
    1273,  1271,  1270,  1274,  1272,  1275,   916,   917,   918,   919,
     796,   797,    32,   288,   289,   290,   291,   292,   293,   294,
     295,   296,    42,   297,    44,   298,   299,    47,   300,   301,
     302,   303,  1077,  1276,  1277,  1278,  1279,  1280,  1281,   920,
    1282,  1283,  1284,  1285,  1286,  1287,  1288,   921,  1289,  1290,
    1291,  1292,  1293,  1294,  1295,  1296,  1297,  1298,   922,  1299,
    1300,  1301,   923,  1302,  1303,  1304,  1305,  1306,  1307,  1308,
    1309,  1310,  1311,  1312,  1313,  1314,  1315,   234,   236,  1317,
    1319,  1463,  1474,  1320,  1316,  1476,  1331,  1332,  1321,  1322,
    1323,  1324,   346,   348,   350,   352,   354,   356,   358,   360,
     362,   364,   366,   368,   370,   924,   405,   925,   926,   927,
    1325,  1326,  1327,  1328,  1329,  1330,  1333,  1334,   928,   929,
    1336,  1337,  1338,  1339,   930,   931,   932,   933,  1340,  1347,
    1348,  1349,  1350,  1351,  1352,  1365,  1355,  1464,  1366,   934,
     935,   936,   937,   938,  1354,   939,   940,  1356,   941,  1357,
    1358,  1359,  1367,   942,   943,   944,   945,   946,   947,   948,
     949,   950,   951,   952,   953,   954,   955,   956,  1369,  1370,
    1371,  1372,  1373,  1374,  1375,  1376,  1377,  1379,  1380,  1382,
    1383,  1384,  1385,  1386,  1387,  1388,  1389,  1390,  1391,  1392,
    1393,  1394,  1395,  1396,  1397,  1398,  1399,  1400,  1401,  1402,
    1403,  1404,  1405,  1406,  1407,  1408,  1409,  1410,  1411,  1412,
    1413,  1414,  1415,  1416,  1417,  1418,  1419,  2126,  2127,  1420,
    1421,  1422,  1425,  1426,  1427,  1428,  1429,  1535,  1536,  1433,
    1431,  1435,  1436,  1430,  1438,  1439,  1434,  1440,  1441,  1445,
    1443,  1602,  1444,  1446,  1447,  1498,  1499,  1674,  1676,  1504,
    1749,  1769,  1833,  2259,  1683,  1677,  1679,  1684,  1685,  2124,
    1489,  1734,  2397,  1750,  1851,  1857,  1927,  1848,  1488,  1852,
    1928,  2398,  1854,  2404,  1855,  1856,  1858,  1859,   957,  2146,
    1860,  1861,  1862,  1863,  1864,  1865,  1866,  1655,  1869,  1656,
    1867,  1868,  1870,  1658,  1659,  1661,  1871,  1662,  1663,  1872,
    1873,  1874,  1875,  1876,  1877,  1878,  1881,  1882,  1666,  1883,
    1678,  1884,  1887,  1891,  1885,  1886,  1888,   904,  1895,  1896,
    1841,  1892,  1893,  1894,  1897,  1898,  1899,  1900,  1903,  1904,
    1837,  2128,  1905,  1912,  1759,  1906,  1909,  1910,  1911,  2260,
    1913,  1914,  1915,  1916,  1917,  1918,  1919,  1920,  1921,  1922,
    1923,  1924,  1925,  1926,  1929,  1930,  1931,  1932,  1933,  1935,
    1934,  1936,  1937,  2233,  2234,  2235,  2236,  1938,  2237,  1939,
    2238,  1940,  1941,  1942,  1943,  1944,  2241,  2242,  2243,  1945,
    1946,  2244,  2245,  2246,  2247,  1948,  2248,  1947,  2249,  1949,
    2250,  2017,  1950,  2251,  2252,  2253,  2254,  1951,  1952,  1953,
    2255,  1956,  1957,  2257,  1958,  1959,  1960,  1961,  1962,  1963,
    1964,  1965,  1966,  1967,  2261,  1970,  2262,  1968,  1969,  1971,
    2266,  2267,  1972,  2268,  2269,  2270,  2271,  2272,  2273,  2274,
    2275,  2276,  2277,  2278,  2279,  1973,  2280,  1974,  1975,  1976,
    1977,  1978,  1979,  1980,  1981,  2288,  2289,  2290,  2291,  2292,
    2293,  2294,  2295,  2296,  1982,  1983,  1984,  1985,  1986,  1987,
    1988,  1989,  1990,  1991,  2007,  2129,  2130,  2305,  2306,  2307,
    2308,  1992,  1993,  1994,  2311,  2312,  2313,  2314,  1997,  1998,
    1999,  2000,  2001,  2006,  2319,  2320,  2321,  2322,  2323,  2324,
    2325,  2326,  2327,  2328,  2329,  2008,  2013,  2014,  2019,  2020,
    2021,  2022,  2330,  2331,  2332,  2023,  2333,  2334,  2024,  2336,
    2337,  2025,  2026,  2339,  2449,  2340,  2027,  2342,  2131,  2028,
    2029,  2034,  2035,  2036,  2037,  2038,  2343,  2039,  2040,  2345,
    2043,  2044,  2045,  2046,  2048,  2047,  2052,  2351,  2353,  2050,
    2054,  1908,  2060,  2357,  2061,  2064,  2065,  2066,  2067,  2363,
    2068,  2069,  2364,  2365,  2070,  2366,  2367,  2368,  2071,  2072,
    2073,  2074,  2075,  2076,  2132,  2078,  2079,  2081,  3270,  2082,
    2077,  2374,  2083,  2375,  2080,  2084,  2085,  2086,  2087,  2088,
    2089,  2090,  2091,  2396,  2093,  2618,  2095,  2376,  2096,  2092,
    2097,  2094,  2098,  2099,  2100,  2101,  2102,  2103,  2104,  2105,
    2106,  2107,  2378,  2115,  2379,  2109,  1765,  1641,  2110,  2380,
    2113,  2114,  2116,  2117,  2118,  2381,  2119,  2120,  2121,  2383,
    2384,  2122,  2385,  2387,  2388,  2123,  2389,  2390,  2136,  2137,
    2393,  2394,  2138,  2395,  2139,  2140,  2144,  2145,  2148,  2151,
    2152,  2153,  2155,  2157,  2164,  2219,  2405,  2406,  2160,  2165,
    2408,  2161,  2409,  2410,  2411,  2166,  2167,  2170,  2171,  2172,
    2412,  2175,  2619,  2413,  2179,  2414,  2176,  2180,  2177,  2415,
    2416,  2417,  2178,  2418,  2181,  2182,  2183,  2184,  2185,  2419,
    2186,  2189,  2420,  2354,  2421,  2187,  2422,  2423,  2424,  2188,
    2190,  2191,  2192,  2193,  2194,  2197,  2620,  2425,  2426,  2632,
    2212,  2427,  2198,  2199,  2200,  2201,  2428,  2429,  2430,  2431,
    2432,  2433,  2204,  2434,  2435,  2436,  2205,  2437,  2438,  2439,
    2440,  2441,  2208,  2209,  2442,  2443,  2444,  2445,  2210,  2448,
    2211,  2215,  2216,  2217,  2218,  2220,  2221,  2222,  2224,  1642,
    2227,  2225,  2226,  2228,  2230,  2347,  2348,  2229,  2349,  2369,
    2370,  2382,  2452,  2772,  2453,  2887,  2455,  2621,  2450,  2451,
    2457,  2454,  2459,  2456,  2458,  2460,  2461,  2462,  2463,  2481,
    2464,  2465,  2467,  2622,  2964,  2466,  2472,  2468,   881,  2469,
    2470,  2471,  2477,  2473,  2474,  2475,  2476,  2478,  2479,  2480,
    2482,  2483,  2484,  2485,  2490,  2488,  2491,  2489,  2492,  2493,
    2495,  2494,   392,  2496,   393,   394,   880,  2497,  2498,  2499,
    2500,  2501,  2502,  2503,  2504,  2505,  2506,  2507,  2508,  2509,
     395,  2510,  2511,  2512,  2513,  2514,  2515,  2516,  2517,  2518,
    2519,  2520,  2521,  2522,  2523,  2524,  2526,  2525,  2527,  2528,
    2529,  2530,  2531,  2532,  2534,  2533,  2535,  2536,  2537,  2538,
    2539,  2540,   396,  2888,  2544,  2541,  2545,  2546,  2542,  2543,
    2547,  2548,  2549,  2616,  2617,  2550,  2016,  3115,  1643,  2553,
    2623,  2557,  2554,  2555,  2556,  2558,  2559,  2560,  2561,  2562,
    2563,  2564,  2589,  2565,  2566,  2567,  2568,  2569,  2571,  2574,
    2573,  2575,  2577,  2578,  2579,  2580,  2581,  2582,  2583,  2584,
    2586,  2587,  2585,  2588,  2590,  2592,  2615,  2593,  2591,  2596,
     882,   885,  2594,  2605,  2595,  2344,  2597,  2598,  2606,  1619,
    2607,  2608,  2609,  2610,  2611,  2612,  2613,  2614,  2624,  2625,
    2626,  2627,  2631,  1645,  3226,  2633,  2634,  2635,  2640,  2636,
    2637,  2638,  2639,  2641,  1644,  2642,  2643,  2644,  2645,  2646,
    2647,  2648,  2649,  2650,  2651,  2652,  2653,  2654,  2655,  2658,
    2659,  2660,  2661,  2662,  2676,  1487,  2677,   397,  2678,  2675,
    2679,  2663,  2666,  2667,  2668,  2680,  2681,  2669,  2682,  2683,
    2684,  2685,  2670,  2686,  2687,  2688,  2689,  2671,  2672,  2755,
    2690,  2809,  2812,  2691,  2693,  2813,  2814,  2816,  2815,  2699,
    2817,  2819,  2818,  2823,  2700,  2820,  2701,  2702,  2703,  2704,
    2705,  2706,  2707,  2708,  2821,  2709,  2711,  2713,  2714,  2715,
    2716,  2717,  2718,  2719,  2720,  2721,  2722,  2723,  2724,  2822,
    2725,  2824,  2825,  2827,  2828,  2829,  1680,  2847,  2731,  2832,
    2833,   884,  2732,  2733,  2834,  2843,  2844,  2845,  2846,  2852,
    2853,  2854,  2736,  2737,  2855,  2858,  2859,  2860,  2861,  2862,
    2863,  2864,  2738,  2739,  2740,  2741,  2742,  3097,  2743,  2744,
    2865,  2745,  2746,  2866,  2867,  2868,  2747,  2748,  2869,  2870,
    2749,  2750,  2751,  2752,  2694,  2871,  2872,  2695,  2873,  2874,
    2875,  2876,  2878,  2877,     0,  2754,   398,  2879,     0,  2880,
    2881,  2756,  2882,  2883,  2884,  2758,  2885,  2759,  2760,  2886,
    2889,  2890,  2892,  2891,  2893,  2894,  2895,  2765,  2766,  2767,
    2896,  2898,  2770,  2771,  2897,  2899,  2900,  2903,  2904,  2905,
    2906,  2907,  2911,  2912,  2910,  2773,  2917,  2775,  2918,  2776,
    2777,  2914,  2778,  2779,  2780,  2781,  2782,  2783,  2784,  2785,
    2915,  2786,  2787,  2788,  2789,  2790,  2791,  2792,  2793,  2794,
    2916,  2795,  2796,  2797,  2798,  2919,  2920,  2921,  2922,  2923,
    2924,  2925,  2926,  2927,  2928,  2801,  2802,  2803,  2804,  2929,
    2930,  2807,  2808,  2931,  2932,  2933,  2934,  2935,  2936,     0,
    2940,  2941,  2942,  2937,  2938,  2939,  2944,     0,  2948,  2943,
    2945,  2946,  2949,  2947,  3036,  3035,  3037,  3038,  3041,  3039,
    3042,  3040,  3043,  3044,  3049,  3047,     0,  3048,     0,  3052,
       0,  3053,  3058,  3059,  3060,  3061,  3062,  3063,  3064,  3065,
    3066,  3067,  3068,  3071,  3069,  3073,  3074,  3075,  2913,     0,
    3076,     0,     0,  3077,  3078,  3079,  3080,  3081,  3082,  3083,
    3086,  3087,  3090,  3091,  3092,  3093,  3094,  3096,  3099,  3100,
    3101,  3095,  3098,  3102,  3106,  3107,     0,  3105,  3108,  3110,
     883,     0,  3109,  3111,  3112,  3116,  3113,  3114,  3117,  3118,
    3119,  3120,  3121,  3122,  3184,  3123,  3124,     0,  3125,  3185,
    3189,  3186,  3187,  3188,  3190,  3191,  3192,  3193,  3194,  3195,
    3196,  3197,  3198,  3199,  3200,     0,  3204,     0,  3206,  3207,
       0,  3201,  3209,  3205,  3210,  3211,  3208,  3212,  3214,  3213,
    3215,  2950,  2951,  3216,  2952,  2953,  3217,  2954,  2955,  3220,
    2956,  2957,  2958,  3218,  2959,  2960,  3219,  3221,  2962,  3222,
    3223,  3224,  3225,  2965,  2966,  3228,  2967,  3235,  2968,  3227,
    2969,     0,  2970,  2971,  2972,  2973,  2974,  3229,  3230,  3231,
    2975,  2976,  2977,  2978,  2979,  2980,  3232,  2981,  2983,  2985,
    2987,  2988,  2989,  2990,  3233,  2991,  2992,  2993,  2994,  2995,
    3234,  2997,  3236,  3237,  3238,  3241,  2998,  2999,  3242,  3000,
    3001,  3002,  3003,  3004,  3005,  3243,  3006,  3007,  3008,  3009,
    3278,  3010,  3279,  3280,  3281,  3012,  3286,  3013,  3287,  3014,
       0,  3283,  3015,  3284,  3016,  3017,  3285,  3018,  3288,  3289,
    3290,  3291,  3292,  3293,  3021,  3294,  3023,  2961,  3295,  3024,
    3025,  2963,  3296,  3299,  3302,  3303,  3304,  3306,  3311,  3307,
    3310,  3314,  3336,  3337,  3338,  3026,  3027,  3028,  3029,  3030,
    3339,  3340,  3341,  3342,  3343,  3032,  3033,  3034,  3345,  3344,
    3346,  3347,  3348,  3349,  3351,  3350,  3354,     0,  3352,  3353,
    3372,  3370,  3374,  3371,  3373,  3375,  3377,  3376,  3379,  3378,
    3380,  3388,  3389,  3390,  3393,  3391,  3392,  3394,  3402,  3399,
       0,  3400,  3401,  3412,     0,  3406,  3407,  3408,  3413,  3418,
    3414,  3417,  3420,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  3126,     0,     0,  3127,  3128,
    3129,     0,     0,     0,  3130,     0,  3131,  3132,     0,     0,
       0,     0,  3135,  3136,     0,  3137,     0,  3138,  3139,  3140,
    3141,  3142,  3143,     0,  3144,  3145,  3146,  3147,  3148,  3149,
    2985,     0,  2985,     0,     0,  2985,  2985,  3154,  3155,  3156,
       0,     0,     0,     0,     0,  3161,  3162,     0,     0,  3163,
       0,     0,     0,  3164,  3165,  3166,     0,     0,  3167,     0,
       0,     0,     0,     0,  3168,  3169,     0,     0,  3170,  3171,
       0,     0,  3173,     0,  3175,  3176,     0,     0,  3177,  3178,
       0,  3179,     0,  3181,  3182,  3183,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3134,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  3244,  3245,  3246,  3247,     0,
    3249,  3250,     0,     0,  3251,     0,     0,     0,     0,     0,
       0,  3252,     0,  3253,     0,  3254,     0,     0,  3255,     0,
       0,     0,     0,  2985,     0,     0,     0,     0,  3257,  3258,
       0,  3259,     0,  3260,     0,  3261,  3262,  3263,     0,  3264,
    3265,     0,  3267,     0,  3269,     0,  3271,  3272,  3273,     0,
       0,  3275,  3276,  3277,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3315,     0,     0,     0,  3317,  3318,     0,     0,     0,  3319,
       0,  3320,  3321,     0,  3322,  3323,     0,     0,     0,  3325,
       0,     0,  3327,  3328,  3329,     0,  3330,  3331,     0,  3332,
    3333,     0,     0,  3334,  3335,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3359,     0,     0,     0,
       0,     0,  3360,  3361,  3362,     0,     0,     0,  3363,  3364,
       0,     0,  3366,  3367,     0,     0,  3368,     0,   178,     0,
     230,   230,   230,     0,     0,     0,     0,     0,     0,     0,
    3381,  3382,     0,  3383,     0,  3384,   246,     0,  3386,   250,
       0,     0,   257,     0,     0,   257,     0,     0,  3395,     0,
    3396,  3397,  3398,     0,     0,     0,     0,     0,     0,  3403,
    3404,  3405,     0,     0,     0,     0,  3409,  3410,  3411,     0,
     304,   257,     0,  3415,  3416,     0,     0,  3419,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,     0,
       0,     0,     0,   257,   257,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   178,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     230,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   230,   230,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     257,     0,   257,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   257,   257,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   257,     0,
       0,     0,     0,     0,     0,     0,     0,   652,   652,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   736,   652,   736,
     736,   736,   736,   736,   736,   748,     0,     0,     0,     0,
     802,   803,   804,   736,   807,   808,   809,   810,   811,   812,
     813,   814,     0,     0,     0,     0,   819,   821,     0,     0,
     257,   736,   844,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   304,   257,     0,     0,     0,
       0,     0,   257,     0,   861,   862,   863,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   257,   257,
     257,   257,     0,     0,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   736,   652,     0,   230,     0,   230,
     230,     0,   390,   736,   652,     0,     0,     0,     0,     1,
       0,     2,     3,     4,     0,     5,     0,   230,     0,     0,
       0,     0,     0,     0,     0,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,     0,     0,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,     0,     0,     0,     0,    29,     0,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,     0,     0,    54,    55,    56,    57,     0,    58,    59,
       0,   257,     0,     0,     0,     0,     0,  1076,  1076,   652,
    1084,   257,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    60,    61,    62,    63,    64,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      65,     0,     0,     0,     0,    66,     0,     0,     0,     0,
       0,     0,    67,    68,    69,    70,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1076,  1076,  1076,  1076,  1076,  1076,  1076,  1076,  1076,  1076,
    1076,  1076,  1076,   736,     0,     0,     0,     0,     0,     0,
      71,    72,     0,     0,     0,     0,     0,     0,  1076,     0,
       0,     0,     0,     0,     0,    73,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    74,     0,
      75,     0,     0,     0,     0,     0,    76,    77,    78,    79,
      80,    81,     0,    82,     0,     0,   257,     0,     0,     0,
       0,     0,     0,   736,   736,  1257,     0,     0,     0,     0,
     736,   736,   736,   736,   736,   736,   736,   736,   736,   736,
     736,   736,   736,   736,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    83,    84,    85,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   257,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,     0,   103,   104,     0,     0,   105,     0,     0,
       0,     0,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   257,     0,   114,   115,   116,   117,   118,   119,   120,
       0,   121,     0,     0,     0,     0,   122,     0,   123,   124,
       0,     0,     0,   125,   126,   127,   128,   257,   129,     0,
       0,   257,     0,     0,     0,   130,   131,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   132,     0,     0,     0,     0,   133,   134,     0,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   257,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1076,  1076,   652,   257,     0,     0,     0,     0,     0,
       0,   257,     0,     0,     0,     0,  1076,  1076,  1076,  1076,
    1076,  1076,  1076,  1076,  1076,  1076,  1076,  1076,  1076,     0,
    1076,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   257,     0,     0,     0,     0,  1452,     0,
       0,     0,     0,     0,  1458,     0,     0,  1462,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   736,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   257,     0,   257,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1502,     0,     0,     0,     0,   652,
     652,  1509,   736,   736,  1512,  1513,  1514,  1515,  1516,   736,
    1518,  1519,  1520,  1521,  1522,     0,  1525,  1526,  1527,  1528,
       0,   736,   736,  1534,     0,     0,  1537,  1538,  1539,  1540,
    1541,  1542,  1543,  1544,  1545,   736,  1547,  1548,  1549,  1550,
    1551,  1552,  1553,  1554,  1555,  1556,  1557,  1558,  1559,   736,
     736,   736,   736,   736,  1565,  1566,  1567,  1568,  1569,     0,
       0,   257,   257,  1574,  1575,  1576,  1577,  1578,  1579,  1580,
    1581,  1582,  1583,  1584,  1585,  1586,   736,  1588,  1589,  1590,
    1591,  1592,  1593,   736,   736,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   736,
     736,   736,  1599,   736,   736,     0,   736,   736,   736,   736,
     257,     0,   652,     0,   652,  1617,   736,   736,  1076,  1076,
    1076,  1076,  1076,  1076,  1076,  1076,  1076,  1076,   736,   736,
     736,   736,   736,     0,     0,   257,   257,   257,     0,     0,
     257,     0,     0,     0,     0,     0,     0,   257,     0,     0,
       0,     0,   257,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   736,     0,     0,
     736,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1686,     0,  1688,     0,     0,     0,  1692,  1693,  1694,
    1695,     0,     0,     0,     0,     0,     0,     0,  1703,     0,
    1705,  1706,  1707,  1709,  1710,  1712,  1714,  1715,  1716,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1732,     0,   736,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1742,  1743,  1744,     0,
       0,     0,     0,     0,     0,     0,     0,   257,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   257,  1763,  1764,     0,     0,
       0,     0,     0,     0,   257,  1771,     0,  1772,  1773,  1775,
    1777,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   736,     0,     0,     0,
       0,     0,     0,     0,     0,  1800,   736,     0,   736,     0,
       0,  1806,     0,     0,     0,   736,  1811,     0,     0,     0,
     736,   736,   736,   257,   736,  1820,     0,  1822,     0,     0,
     736,   257,     0,   736,   736,   736,   736,   736,     0,     0,
       0,   257,     0,   652,   257,     0,     0,     0,     0,   257,
     257,   257,     0,   257,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1076,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,  2011,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   736,     0,     0,   736,     0,     0,
       0,   736,  2056,  2057,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   736,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   257,     1,
       0,     2,     3,     4,     0,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   652,     0,     0,
       0,     0,     0,    14,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    25,    26,     0,
       0,     0,     0,     0,     0,    29,     0,    30,     0,    32,
     203,   204,   205,   237,   206,   207,     0,   232,   209,     0,
       0,     0,     0,     0,     0,   210,     0,   211,   212,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   257,     0,     0,     0,
    2232,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2239,  2240,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    60,    61,    62,    63,    64,
    2256,     0,   736,     0,     0,     0,     0,     0,     0,   652,
       0,     0,     0,     0,     0,   213,   736,  2265,     0,     0,
       0,     0,     0,    68,     0,   214,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2281,  2282,   736,   736,  2285,
    2286,  2287,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2297,     0,  2298,  2299,  2300,
    2301,  2302,     0,  2303,  2304,     0,     0,     0,     0,   736,
     736,     0,     0,     0,     0,    73,  2315,   257,     0,     0,
    2317,  2318,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2335,     0,    74,  2338,
      75,     0,     0,     0,   736,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   736,     0,  2346,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   257,
       0,     0,   257,   257,   257,   257,   257,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   736,     0,     0,     0,     0,     0,  2373,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    88,    89,     0,     0,     0,     0,     0,  2377,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     652,     0,     0,     0,     0,     0,  2391,  2392,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2407,     0,     0,
       0,     0,     0,    91,    92,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,     0,   103,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   106,   107,   108,   109,   110,   111,   112,
     113,     0,     0,   114,   115,   116,   117,   118,   119,   120,
       0,     0,     0,     0,     0,   652,   736,     0,     0,     0,
       0,     0,     0,     0,     0,   127,   128,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   144,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   162,     0,     0,   162,   162,   162,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       2,   200,   201,     0,   202,     0,   162,     0,     0,     0,
       0,     0,     0,  1614,     0,     0,     0,     0,     0,     0,
       0,     0,    14,    15,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    25,    26,     0,     0,
       0,     0,     0,     0,    29,     0,    30,     0,    32,   203,
     204,   205,   237,  1615,   207,     0,   208,   209,     0,     0,
       0,     0,     0,     0,   210,     0,   211,   212,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   257,   257,
     162,     0,     0,     0,    60,    61,    62,    63,    64,     0,
       0,     0,     0,     0,     0,     0,   162,     0,     0,     0,
       0,     0,     0,     0,   213,     0,     0,     0,     0,     0,
       0,  2692,    68,     0,   214,  2696,  2698,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2710,  2712,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2726,
    2727,  2728,  2729,  2730,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    73,     0,   736,     0,     0,   736,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    74,     0,    75,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   257,
     162,     0,     0,   650,   650,     0,     0,     0,     0,     0,
       0,     0,  2757,     0,     0,     0,     0,     0,   736,     0,
     736,     0,   736,     0,   736,     0,     0,     0,  2768,  2769,
       0,     0,     0,   735,   650,   735,   735,   735,   735,   735,
     735,     0,     0,     0,  2774,     0,     0,     0,   735,   735,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      88,    89,     0,     0,     0,   840,     0,   735,     0,     0,
       0,     0,     0,     0,     0,  2799,     0,     0,     0,     0,
       0,   736,     0,     0,     0,     0,     0,   736,   736,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     735,   650,     0,   162,   840,   162,   162,     0,     0,   735,
    1012,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,     0,   103,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   106,   107,   215,   216,   217,   218,   219,   220,
       0,     0,   221,   222,   223,   224,   225,   226,   227,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   127,   128,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2696,     0,     0,     0,  2696,
       0,     0,     0,   650,   650,   650,     0,     0,   144,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1617,  1617,  1617,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2996,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   257,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   736,  3020,     0,
       0,     0,     0,  3022,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   735,
       0,   736,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   650,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   735,
     735,   735,     0,     0,     0,     0,   735,   735,   735,   735,
     735,   735,   735,   735,   735,   735,   735,   735,   735,   735,
       0,     0,     0,     0,     0,     0,   257,     0,     0,  2696,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1617,     0,
    1617,     0,     0,  1617,  1617,     0,     0,     0,  3157,  3158,
    3159,  3160,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3172,
       0,  3174,     0,     0,     0,     0,     0,     0,     0,     0,
     736,     0,     0,     0,     0,     0,     0,   840,   840,   840,
       0,   840,   840,   840,   840,   840,   840,   840,   840,   840,
     840,   840,   840,   840,   840,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1617,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3266,
       0,  3268,     0,     0,     0,     0,     0,     0,   736,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   736,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   257,     0,     0,     0,     0,     0,  1012,  1012,  1012,
       0,     0,     0,     0,     0,     0,   736,     0,     0,   736,
       0,     0,  1012,  1012,  1012,  1012,  1012,  1012,  1012,  1012,
    1012,  1012,  1012,  1012,  1012,     0,  1012,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   197,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3365,     0,
     247,     0,     0,   735,     0,     0,   736,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3385,     0,     0,     0,   736,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   650,   650,     0,   735,   735,
       0,     0,     0,     0,     0,   735,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   735,   735,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   735,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   735,   735,   735,   735,   735,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   735,     0,     0,     0,     0,     0,   197,   735,
     735,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   735,   735,   735,     0,   735,
     735,     0,   735,   735,   735,   735,     0,     0,   650,     0,
     650,     0,   735,   735,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   735,   735,   735,   735,   735,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   735,     0,     0,   735,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   517,   518,     0,     0,     0,
       0,   672,   672,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   735,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   738,   672,   738,   738,   738,   738,   738,   738,     0,
       0,     0,     0,     0,     0,     0,   738,   738,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   738,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   735,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   735,     0,   735,     0,     0,     0,     0,     0,
       0,   735,     0,     0,     0,     0,   735,   735,   735,     0,
     735,     0,     0,     0,     0,     0,   735,     0,     0,   735,
     735,   735,   735,   735,     0,     0,     0,     0,     0,   650,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   738,   672,
       0,     0,     0,     0,     0,     0,   979,   738,  1017,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   650,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   672,   672,   672,  1085,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   251,   254,   256,
       0,     0,   260,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   306,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   672,   672,   672,   672,   672,   672,
     672,   672,   672,   672,   672,   672,   672,   738,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     735,     0,   672,   735,     0,     0,     0,   735,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     375,   376,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   735,     0,
       0,     0,     0,     0,     0,     0,     0,   738,   738,   738,
       0,     0,     0,     0,   738,   738,   738,   738,   738,   738,
     738,   738,   738,   738,   738,   738,   738,   738,     0,     0,
       0,     0,     0,   650,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   452,     0,   454,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   456,   457,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   461,     0,     0,     0,     0,
       0,     0,     0,     0,   649,   649,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   735,     0,
       0,     0,     0,     0,     0,   650,     0,     0,     0,     0,
       0,     0,   735,     0,     0,     0,     0,   842,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   735,   735,     0,     1,     0,     2,   200,
     201,     0,   202,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   853,     0,     0,     0,     0,     0,   859,
      14,    15,     0,     0,     0,   735,   735,     0,     0,     0,
       0,     0,     0,     0,    25,    26,     0,   867,   868,     0,
       0,     0,    29,     0,    30,     0,    32,   203,   204,   205,
     237,   206,   207,     0,   208,   209,     0,     0,     0,     0,
       0,     0,   210,     0,   211,   212,     0,     0,     0,     0,
     735,  1011,     0,     0,     0,   672,   672,   672,     0,     0,
       0,     0,   735,     0,     0,     0,     0,     0,     0,     0,
     672,   672,   672,   672,   672,   672,   672,   672,   672,   672,
     672,   672,   672,     0,   672,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   735,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    60,    61,    62,    63,    64,     0,     0,     0,
       0,   738,     0,     0,     0,     0,     0,     0,   979,     0,
       0,     0,   213,     0,  1485,     0,     0,  1070,  1072,     0,
      68,     0,   214,     0,     0,     0,     0,     0,  1087,     0,
       0,     0,     0,     0,     0,     0,   650,     0,     0,     0,
       0,     0,     0,   672,   672,     0,   738,   738,     0,     0,
       0,     0,     0,   738,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   738,   738,     0,     0,     0,
       0,     0,    73,     0,     0,     0,     0,     0,     0,   738,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   738,   738,   738,   738,   738,     0,     0,
       0,     0,     0,  1570,  1571,    74,     0,    75,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     738,     0,     0,     0,     0,     0,     0,   738,   738,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   650,   735,   738,   738,   738,     0,   738,   738,     0,
     738,   738,   738,   738,     0,     0,   672,     0,   672,     0,
     738,   738,   672,   672,   672,   672,   672,   672,   672,   672,
     672,   672,   738,   738,   738,   738,   738,     0,    88,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   671,   671,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1249,     0,     0,     0,     0,     0,     0,
       0,   738,     0,     0,   738,     0,     0,     0,     0,     0,
       0,   737,   741,   742,   743,   744,   745,   746,   747,     0,
       0,     0,     0,     0,     0,     0,   805,   806,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   843,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     738,     0,     0,     0,     0,     0,     0,     0,     0,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,     0,
     103,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     106,   107,   215,   216,   217,   218,   219,   220,     0,     0,
     221,   222,   223,   224,   225,   226,   227,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   127,   128,     0,     0,     0,     0,   906,   908,
     738,  1343,     0,     0,     0,     0,     0,   982,  1014,     0,
     738,     0,   738,     0,     0,     0,     0,     0,     0,   738,
       0,  1812,  1813,  1814,   738,   738,   738,     0,   738,     0,
    1821,     0,  1823,  1824,   738,     0,   144,   738,   738,   738,
     738,   738,     0,     0,     0,     0,     0,   672,  1368,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1378,     0,     0,     0,  1381,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     672,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   735,     0,     0,   735,     0,     0,  1424,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1087,     0,     0,     0,     0,     0,     0,  1424,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1448,     0,     0,     0,   735,     0,   735,     0,   735,     0,
     735,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2012,     0,     0,     0,     0,     0,     0,     0,  1494,     0,
    1497,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1500,     0,     0,     0,     0,   649,   735,     0,     0,
       0,     0,     0,   735,   735,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   979,     0,   738,     0,
       0,   738,     0,     0,     0,   738,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1572,  1573,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   738,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1607,     0,  1610,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   672,  1652,  1653,  1654,     0,     0,  1657,     0,     0,
       0,     0,     0,     0,  1664,     0,     0,     0,     0,  1669,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       0,     2,   200,   201,     0,   202,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    14,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    25,    26,     0,
       0,     0,     0,     0,     0,    29,     0,    30,     0,    32,
     203,   204,   205,   237,  1615,   207,     0,   208,   209,     0,
       0,     0,     0,     0,     0,   210,     0,   211,   212,     0,
       0,     0,     0,   735,  1748,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   738,     0,     0,     0,
       0,     0,  1762,   672,     0,     0,     0,     0,     0,     0,
     738,  1770,     0,     0,     0,     0,     0,   735,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   738,   738,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    60,    61,    62,    63,    64,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1818,     0,     0,   738,   738,   213,     0,     0,  1827,     0,
       0,     0,     0,    68,     0,   214,     0,     0,  1836,     0,
     649,  1839,     0,     0,     0,     0,  1844,  1845,  1846,     0,
    1847,     0,     0,     0,  1849,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   738,     0,
       0,  1472,     0,     0,     0,     0,     0,     0,     0,     0,
     738,     0,     0,     0,     0,    73,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   671,  1508,   738,  1510,  1511,    74,     0,
      75,     0,     0,  1517,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1532,  1533,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1546,
       0,     0,     0,     0,     0,     0,   735,     0,     0,     0,
       0,     0,     0,  1560,  1561,  1562,  1563,  1564,     0,     0,
       0,     0,     0,     0,   672,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1587,    88,    89,     0,     0,     0,     0,  1594,  1595,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1596,  1597,  1598,     0,  1600,  1601,     0,
    1603,  1604,  1605,  1606,     0,     0,  1612,     0,  1613,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   735,     0,     0,     0,     0,   672,
     738,  1681,     0,     0,  1613,     0,     0,     0,     0,     0,
       0,     0,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,     0,   103,   735,     0,     0,     0,     0,     0,
       0,     0,     0,   106,   107,   215,   216,   217,   218,   219,
     220,     0,     0,   221,   222,   223,   224,   225,   226,   227,
       0,     0,   735,     0,     0,   735,     0,     0,     0,     0,
    1733,     0,     0,     0,     0,   127,   128,     0,     0,     0,
       0,     0,     0,     0,     0,  2125,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   144,
       0,     0,   735,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1791,     0,     0,     0,   735,     0,     0,     0,     0,     0,
    1801,     0,  1803,     0,     0,     0,     0,     0,     0,  1810,
       0,     0,     0,     0,  1815,  1816,  1817,     0,  1819,     0,
       0,     0,     0,     0,  1825,     0,     0,  1828,  1829,  1830,
    1831,  1832,     0,  2231,     0,     0,     0,   671,     0,     0,
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
       0,     0,     0,     0,  2316,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     738,     0,     0,   738,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2350,  2352,     0,     0,  2355,     0,  2356,  2358,
    2359,  2360,  2361,  2362,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   738,     0,   738,     0,   738,     0,   738,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2051,     0,
       0,     0,     0,     0,     0,  2055,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   738,     0,     0,     0,     0,
       0,   738,   738,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2108,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2147,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     2,     3,     4,     0,     5,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
       0,     0,     0,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,     0,     0,     0,     0,    29,     0,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,     0,     0,    54,    55,    56,    57,
       0,    58,    59,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2258,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2263,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2283,  2284,     0,     0,     0,     0,     0,    60,    61,
      62,    63,    64,     0,     0,     0,     0,     0,     0,     0,
       0,   738,     0,    65,     0,     0,     0,     0,    66,     0,
       0,     0,     0,  2309,  2310,    67,    68,    69,    70,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   738,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    71,    72,     0,     0,     0,  2341,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    73,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2673,  2674,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    74,     0,    75,     0,     0,     0,     0,     0,    76,
      77,    78,    79,    80,    81,     0,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    83,    84,    85,
       0,     0,     0,     0,  2386,     0,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   738,     0,  2753,     0,     0,     0,
       0,     0,    90,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    92,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2446,
    2447,     0,     0,     0,     0,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,     0,   103,   104,     0,     0,
     105,     0,     0,     0,     0,     0,   106,   107,   108,   109,
     110,   111,   112,   113,     0,     0,   114,   115,   116,   117,
     118,   119,   120,     0,   121,     0,     0,     0,     0,   122,
       0,   123,   124,     0,     0,     0,   125,   126,   127,   128,
       0,   129,   738,     0,     0,     0,     0,     0,   130,   131,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   132,     0,     0,     0,     0,
     133,   134,   738,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     738,     0,     0,   738,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,     2,   983,   984,     0,   985,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    14,    15,     0,
     738,   986,   534,   987,     0,     0,     0,     0,     0,     0,
       0,    25,    26,     0,     0,     0,     0,     0,     0,    29,
       0,    30,   738,    32,   203,   204,   205,   237,   739,   207,
     988,   232,   209,   989,     0,   537,     0,     0,     0,   210,
     990,   211,   212,     0,     0,     0,     0,     0,     0,     0,
       0,   991,     0,     0,   992,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3011,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    60,
     538,    62,    63,    64,   539,   540,   541,   542,   543,   544,
     545,   546,     0,   547,     0,   548,   549,   550,   551,   552,
     553,   554,     0,   555,   556,     0,     0,    68,     0,   557,
    2734,     0,     0,  2735,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   558,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,     0,     0,     0,     0,   571,    73,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2761,     0,  2762,     0,  2763,     0,  2764,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,    74,   585,    75,   586,   587,   588,   589,   590,
       0,     0,     0,  3133,     0,     0,   591,     0,     0,     0,
     958,   959,   960,     0,     0,   592,   593,   594,   595,   961,
     962,   963,   964,   596,     0,     0,   965,   597,     0,     0,
       0,     0,     0,     0,     0,  2800,     0,     0,     0,     0,
       0,  2805,  2806,     0,   598,   599,   600,   601,     0,     0,
       0,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,     0,     0,    88,    89,   966,     0,     0,
     967,   968,   969,   970,     0,   971,   972,   614,   615,   993,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   994,    91,    92,     0,
       0,     0,     0,     0,     0,  3248,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   616,   617,   618,   619,    93,   995,    95,    96,
     996,    98,    99,   100,   101,   102,     0,   103,     0,   620,
     621,     0,   997,     0,     0,     0,     0,   106,   107,   998,
     999,  1000,  1001,  1002,  1003,     0,     0,  1004,  1005,  1006,
    1007,  1008,  1009,  1010,   635,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   127,
     128,   636,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   637,   638,   639,   640,     0,   641,   642,  3316,   974,
     975,   976,   643,   644,     0,   977,     0,   978,   645,   646,
     647,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   144,     0,     0,     1,     0,     2,   983,
     984,     0,   985,     0,     0,     0,     0,     0,     0,     0,
       0,  3019,     0,     0,     0,     0,     0,     0,     0,     0,
      14,    15,     0,     0,   533,   534,     0,     0,     0,     0,
       0,     0,     0,     0,    25,    26,     0,     0,     0,     0,
       0,     0,    29,     0,    30,  3031,    32,   203,   204,   205,
     237,   739,   207,   536,   232,   209,     0,     0,   537,     0,
       0,     0,   210,     0,   211,   212,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    60,   538,    62,    63,    64,   539,   540,   541,
     542,   543,   544,   545,   546,     0,   547,     0,   548,   549,
     550,   551,   552,   553,   554,     0,   555,   556,     0,     0,
      68,     0,   557,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,     0,     0,     0,
       0,   571,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3180,     0,     0,     0,     0,     0,
       0,     0,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,    74,   585,    75,   586,   587,
     588,   589,   590,     0,     0,     0,     0,     0,     0,   591,
       0,     0,     0,     0,     0,     0,     0,     0,   592,   593,
     594,   595,     0,     0,     0,     0,   596,     0,     0,     0,
     597,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   598,   599,   600,
     601,     0,     0,     0,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,     0,     0,    88,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     614,   615,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3274,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3305,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      91,    92,     0,     0,     0,     0,     0,     0,     0,     0,
    3324,     0,     0,  3326,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   616,   617,   618,   619,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,     0,
     103,     0,   620,   621,     0,     0,     0,     0,     0,     0,
     106,   107,   998,   999,  1000,  1001,  1002,  1003,     0,     0,
    1004,  1005,  1006,  1007,  1008,  1009,  1010,   635,     0,     0,
    3369,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   127,   128,   636,     0,     0,     0,     0,     0,
       0,     0,  3387,     0,   637,   638,   639,   640,     0,   641,
     642,     0,     0,     0,     0,   643,   644,     0,     0,     0,
       0,   645,   646,   647,     1,     0,     2,   529,   530,     0,
     531,     0,     0,     0,   532,     0,   144,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    14,    15,
       0,     0,   533,   534,     0,     0,     0,     0,     0,     0,
       0,     0,    25,    26,     0,     0,     0,     0,     0,     0,
      29,     0,    30,     0,    32,   203,   204,   205,   237,   535,
     207,   536,   208,   209,     0,     0,   537,     0,     0,     0,
     210,     0,   211,   212,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      60,   538,    62,    63,    64,   539,   540,   541,   542,   543,
     544,   545,   546,     0,   547,     0,   548,   549,   550,   551,
     552,   553,   554,     0,   555,   556,     0,     0,    68,     0,
     557,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,     0,     0,     0,     0,   571,
      73,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,    74,   585,    75,   586,   587,   588,   589,
     590,     0,     0,     0,     0,     0,     0,   591,     0,     0,
       0,     0,     0,     0,     0,     0,   592,   593,   594,   595,
       0,     0,     0,     0,   596,     0,     0,     0,   597,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   598,   599,   600,   601,     0,
       0,     0,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,     0,     0,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   614,   615,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   616,   617,   618,   619,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,     0,   103,     0,
     620,   621,     0,     0,     0,     0,     0,     0,   106,   107,
     622,   623,   624,   625,   626,   627,     0,     0,   628,   629,
     630,   631,   632,   633,   634,   635,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     127,   128,   636,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   637,   638,   639,   640,     0,   641,   642,     0,
       0,     0,     0,   643,   644,     0,     0,     0,     0,   645,
     646,   647,     1,     0,     2,   529,   530,     0,   531,     0,
       0,     0,  1608,     0,   144,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    14,    15,     0,     0,
     533,   534,     0,     0,     0,     0,     0,     0,     0,     0,
      25,    26,     0,     0,     0,     0,     0,     0,    29,     0,
      30,     0,    32,   203,   204,   205,   237,  1609,   207,   536,
     208,   209,     0,     0,   537,     0,     0,     0,   210,     0,
     211,   212,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    60,   538,
      62,    63,    64,   539,   540,   541,   542,   543,   544,   545,
     546,     0,   547,     0,   548,   549,   550,   551,   552,   553,
     554,     0,   555,   556,     0,     0,    68,     0,   557,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     558,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,     0,     0,     0,     0,   571,    73,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,    74,   585,    75,   586,   587,   588,   589,   590,     0,
       0,     0,     0,     0,     0,   591,     0,     0,     0,     0,
       0,     0,     0,     0,   592,   593,   594,   595,     0,     0,
       0,     0,   596,     0,     0,     0,   597,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   598,   599,   600,   601,     0,     0,     0,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,     0,     0,    88,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   614,   615,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   616,   617,   618,   619,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,     0,   103,     0,   620,   621,
       0,     0,     0,     0,     0,     0,   106,   107,   622,   623,
     624,   625,   626,   627,     0,     0,   628,   629,   630,   631,
     632,   633,   634,   635,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   127,   128,
     636,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     637,   638,   639,   640,     0,   641,   642,     0,     0,     0,
       0,   643,   644,     0,     0,     0,     0,   645,   646,   647,
       1,     0,     2,   529,   530,     0,   531,     0,     0,     0,
       0,     0,   144,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    14,    15,     0,     0,   533,   534,
       0,     0,     0,     0,     0,     0,     0,     0,    25,    26,
       0,     0,     0,     0,     0,     0,    29,     0,    30,     0,
      32,   203,   204,   205,   237,   739,   207,   536,   208,   209,
       0,     0,   537,     0,     0,     0,   210,     0,   211,   212,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    60,   538,    62,    63,
      64,   539,   540,   541,   542,   543,   544,   545,   546,     0,
     547,     0,   548,   549,   550,   551,   552,   553,   554,     0,
     555,   556,     0,     0,    68,     0,   557,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   558,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,     0,     0,     0,     0,   571,    73,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,    74,
     585,    75,   586,   587,   588,   589,   590,     0,     0,     0,
       0,     0,     0,   591,     0,     0,     0,     0,     0,     0,
       0,     0,   592,   593,   594,   595,     0,     0,     0,     0,
     596,     0,     0,     0,   597,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   598,   599,   600,   601,     0,     0,     0,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
       0,     0,    88,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   614,   615,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   616,
     617,   618,   619,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,     0,   103,     0,   620,   621,     0,     0,
       0,     0,     0,     0,   106,   107,   622,   623,   624,   625,
     626,   627,     0,     0,   628,   629,   630,   631,   632,   633,
     634,   635,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   127,   128,   636,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   637,   638,
     639,   640,     0,   641,   642,     0,     0,     0,     0,   643,
     644,     0,     0,     0,     0,   645,   646,   647,     1,     0,
       2,   983,   984,     0,   985,     0,     0,     0,     0,     0,
     144,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    15,     0,     0,   533,   534,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    30,     0,    32,   203,
     204,   205,     0,   739,   207,   536,   232,   209,     0,     0,
     537,     0,     0,     0,   210,     0,   211,   212,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    60,   538,    62,    63,    64,   539,
     540,   541,   542,   543,   544,   545,   546,     0,   547,     0,
     548,   549,   550,   551,   552,   553,   554,     0,   555,   556,
       0,     0,     0,     0,   557,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   558,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,     0,
       0,     0,     0,   571,    73,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,    74,   585,    75,
     586,   587,   588,   589,   590,     0,     0,     0,     0,     0,
       0,   591,     0,     0,     0,     0,     0,     0,     0,     0,
     592,   593,   594,   595,     0,     0,     0,     0,   596,     0,
       0,     0,   597,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   598,
     599,   600,   601,     0,     0,     0,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,     0,     0,
      88,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   614,   615,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   616,   617,   618,
     619,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,     0,   103,     0,   620,   621,     0,     0,     0,     0,
       0,     0,   106,   107,   998,   999,  1000,  1001,  1002,  1003,
       0,     0,  1004,  1005,  1006,  1007,  1008,  1009,  1010,   635,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   127,   128,   636,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   637,   638,   639,   640,
       0,   641,   642,     0,     0,     0,     0,   643,   644,     0,
       0,     0,     0,   645,   646,   647,     1,     0,     2,   529,
     530,     0,   531,     0,     0,     0,     0,     0,   144,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    15,     0,     0,   533,   534,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    30,     0,    32,   203,   204,   205,
       0,   739,   207,   536,   208,   209,     0,     0,   537,     0,
       0,     0,   210,     0,   211,   212,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    60,   538,    62,    63,    64,   539,   540,   541,
     542,   543,   544,   545,   546,     0,   547,     0,   548,   549,
     550,   551,   552,   553,   554,     0,   555,   556,     0,     0,
       0,     0,   557,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,     0,     0,     0,
       0,   571,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,    74,   585,    75,   586,   587,
     588,   589,   590,     0,     0,     0,     0,     0,     0,   591,
       0,     0,     0,     0,     0,     0,     0,     0,   592,   593,
     594,   595,     0,     0,     0,     0,   596,     0,     0,     0,
     597,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   598,   599,   600,
     601,     0,     0,     0,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,     0,     0,    88,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     614,   615,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   616,   617,   618,   619,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,     0,
     103,     0,   620,   621,     0,     0,     0,     0,     0,     0,
     106,   107,   622,   623,   624,   625,   626,   627,     0,     0,
     628,   629,   630,   631,   632,   633,   634,   635,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   127,   128,   636,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   637,   638,   639,   640,     0,   641,
     642,     0,     0,     0,     0,   643,   644,     0,     0,     0,
       0,   645,   646,   647,     1,     0,     2,   529,   530,     0,
    1901,     0,     0,     0,     0,     0,   144,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    15,
       0,     0,   533,   534,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    30,     0,    32,   203,   204,   205,     0,   739,
     207,   536,   208,   209,     0,     0,   537,     0,     0,     0,
     210,     0,   211,   212,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      60,   538,    62,    63,    64,   539,   540,   541,   542,   543,
     544,   545,   546,     0,   547,     0,   548,   549,   550,   551,
     552,   553,   554,     0,   555,   556,     0,     0,     0,     0,
     557,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,     0,     0,     0,     0,   571,
      73,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,    74,   585,    75,   586,   587,   588,   589,
     590,     0,     0,     0,     0,     0,     0,   591,     0,     0,
       0,     0,     0,     0,     0,     0,   592,   593,   594,   595,
       0,     0,     0,     0,   596,     0,     0,     0,   597,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   598,   599,   600,   601,     0,
       0,     0,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,     0,     0,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   614,   615,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     0,     0,   715,
     716,     0,   717,   616,   617,   618,   619,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,     0,   103,     0,
     620,   621,     0,     0,   533,   534,     0,     0,   106,   107,
     622,   623,   624,   625,   626,   627,     0,     0,   628,   629,
     630,   631,   632,   633,   634,   635,    32,     0,     0,     0,
       0,   718,   207,   536,     0,     0,     0,     0,   537,     0,
     127,   128,   636,     0,   211,   212,     0,     0,     0,     0,
       0,     0,   637,   638,   639,   640,     0,   641,   642,     0,
       0,     0,     0,   643,   644,     0,     0,     0,     0,   645,
     646,   647,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   144,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   719,     0,     0,     0,   539,   540,   541,
     542,   543,   544,   545,   546,     0,   547,     0,   548,   549,
     550,   551,   720,   553,   554,     0,   555,   556,     0,     0,
       0,     0,   721,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,     0,     0,     0,
       0,   571,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,     0,   585,     0,   586,   587,
     588,   589,   590,     0,     0,     0,     0,     0,     0,   591,
       0,     0,     0,     0,     0,     0,     0,     0,   592,   593,
     594,   595,     0,     0,     0,     0,   596,     0,     0,     0,
     597,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   598,   599,   600,
     601,     0,     0,     0,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     614,   615,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       0,   715,   716,     0,   717,   616,   617,   618,   619,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,     0,
       0,     0,   620,   621,     0,     0,   533,   534,     0,     0,
       0,     0,   722,   723,   724,   725,   726,   727,     0,     0,
     728,   729,   730,   731,   732,   733,   734,   635,    32,     0,
       0,     0,     0,   718,   207,   536,     0,     0,     0,     0,
     537,     0,     0,     0,   636,     0,   211,   212,     0,     0,
       0,     0,     0,     0,   637,   638,   639,   640,     0,   641,
     642,     0,     0,     0,     0,   643,   644,     0,     0,     0,
       0,   645,   646,   647,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   144,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   719,     0,     0,     0,   539,
     540,   541,   542,   543,   544,   545,   546,     0,   547,     0,
     548,   549,   550,   551,   720,   553,   554,     0,   555,   556,
       0,     0,     0,     0,   721,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   558,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,     0,
       0,     0,     0,   571,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,     0,   585,     0,
     586,   587,   588,   589,   590,     0,     0,     0,     0,     0,
       0,   591,     0,     0,     0,     0,     0,     0,     0,     0,
     592,   593,   594,   595,     0,     0,     0,     0,   596,     0,
       0,     0,   597,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   598,
     599,   600,   601,     0,     0,     0,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   614,   615,   981,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     0,   715,   716,     0,   717,   616,   617,   618,
     619,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   620,   621,     0,     0,   533,   534,
       0,     0,     0,     0,   722,   723,   724,   725,   726,   727,
       0,     0,   728,   729,   730,   731,   732,   733,   734,   635,
      32,     0,     0,     0,     0,   718,   207,   536,     0,     0,
       0,     0,   537,     0,     0,     0,   636,     0,   211,   212,
       0,     0,     0,     0,     0,     0,   637,   638,   639,   640,
       0,   641,   642,     0,     0,     0,     0,   643,   644,     0,
       0,     0,     0,   645,   646,   647,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   144,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   719,     0,     0,
       0,   539,   540,   541,   542,   543,   544,   545,   546,     0,
     547,     0,   548,   549,   550,   551,   720,   553,   554,     0,
     555,   556,     0,     0,     0,     0,   721,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   558,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,     0,     0,     0,     0,   571,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,     0,
     585,     0,   586,   587,   588,   589,   590,     0,     0,     0,
       0,     0,     0,   591,     0,     0,     0,     0,     0,     0,
       0,     0,   592,   593,   594,   595,     0,     0,     0,     0,
     596,     0,     0,     0,   597,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   598,   599,   600,   601,     0,     0,     0,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   614,   615,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     0,   715,   716,     0,  2053,   616,
     617,   618,   619,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   620,   621,     0,     0,
     533,   534,     0,     0,     0,     0,   722,   723,   724,   725,
     726,   727,     0,     0,   728,   729,   730,   731,   732,   733,
     734,   635,    32,     0,     0,     0,     0,   718,   207,   536,
       0,     0,     0,     0,   537,     0,     0,     0,   636,     0,
     211,   212,     0,     0,     0,     0,     0,     0,   637,   638,
     639,   640,     0,   641,   642,     0,     0,     0,     0,   643,
     644,     0,     0,     0,     0,   645,   646,   647,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     144,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   719,
       0,     0,     0,   539,   540,   541,   542,   543,   544,   545,
     546,     0,   547,     0,   548,   549,   550,   551,   720,   553,
     554,     0,   555,   556,     0,     0,     0,     0,   721,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     558,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,     0,     0,     0,     0,   571,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,     0,   585,     0,   586,   587,   588,   589,   590,     0,
       0,     0,     0,     0,     0,   591,     0,     0,     0,     0,
       0,     0,     0,     0,   592,   593,   594,   595,     0,     0,
       0,     0,   596,     0,     0,     0,   597,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   598,   599,   600,   601,     0,     0,     0,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,     0,     0,     0,     0,     0,     0,     1,     0,
       2,     3,     4,     0,     5,     0,   614,   615,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    15,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    30,     0,    32,   203,
     204,   205,     0,   206,   207,     0,   232,   209,     0,     0,
       0,     0,     0,     0,   210,     0,   211,   212,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   616,   617,   618,   619,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   620,   621,
       0,     0,     0,     0,     0,     0,     0,     0,   722,   723,
     724,   725,   726,   727,     0,     0,   728,   729,   730,   731,
     732,   733,   734,   635,    60,    61,    62,    63,    64,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
     636,     2,   200,   201,   213,   202,     0,     0,     0,     0,
     637,   638,   639,   640,   214,   641,   642,     0,     0,     0,
       0,   643,   644,     0,    15,     0,     0,   645,   646,   647,
       0,     0,     0,     0,     0,     0,     0,     1,     0,     2,
     200,   201,   144,  1023,     0,     0,     0,    30,     0,    32,
     203,   204,   205,     0,   206,   207,     0,   208,   209,     0,
       0,     0,    15,     0,    73,   210,     0,   211,   212,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    30,     0,    32,   203,   204,
     205,     0,   206,   207,     0,   208,   209,    74,     0,    75,
       0,     0,     0,   210,     0,   211,   212,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    60,    61,    62,    63,    64,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   213,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   214,     0,     0,     0,     0,
      88,    89,     0,    60,    61,    62,    63,    64,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   213,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   214,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    73,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,     0,     0,     0,     0,    74,     0,
      75,     0,     0,    73,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,     0,   103,     0,     0,     0,    74,     0,    75,     0,
       0,     0,   106,   107,   108,   109,   110,   111,   112,   113,
       0,     0,   114,   115,   116,   117,   118,   119,   120,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    88,    89,     0,   127,   128,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    88,
      89,     0,     0,     0,     0,     0,     0,     0,   144,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,     0,   103,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   106,   107,   215,   216,   217,   218,   219,
     220,     0,     0,   221,   222,   223,   224,   225,   226,   227,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
       0,   103,     0,     0,     0,   127,   128,     0,     0,     0,
       0,   106,   107,   215,   216,   217,   218,   219,   220,     0,
       0,   221,   222,   223,   224,   225,   226,   227,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   127,   128,     0,     0,     0,     0,   144,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   144
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
         0,    45,   374,   436,   280,   409,   410,   449,    23,    52,
     382,    42,    43,   411,   412,   413,   414,    50,    56,    34,
     142,    37,    22,    23,    42,    57,     7,   431,   432,    10,
      11,    63,    13,   529,   530,     0,     0,    51,    51,    51,
      52,     7,    19,    75,    76,    19,    22,    14,    64,    56,
      19,    31,    14,    13,    50,    19,    13,    22,    74,   289,
      56,    31,    19,   344,   345,    45,    46,    19,     5,     6,
      20,    31,    19,    53,    20,    45,    46,    57,  2857,  2858,
    2859,    61,    46,    53,    65,    45,    46,    57,    13,    21,
      15,    61,    13,    53,    19,     5,    76,    57,    21,    13,
     121,    61,   146,    22,    15,    20,    76,     7,     8,    23,
     154,    56,    12,     5,     6,    13,    76,   398,    53,    53,
      34,   142,    57,    57,   124,    70,   622,   623,   624,   625,
     626,   627,   628,   629,   630,   631,   632,   633,   634,   635,
      13,    76,    76,     2,     3,     4,   146,    14,    13,   379,
     380,   381,   382,    58,   650,    19,    61,   121,    19,   135,
     174,    13,   131,   132,    31,   142,   130,   131,   142,   183,
     183,   138,   139,   142,   121,   141,   138,   139,    45,    46,
     218,   146,   146,    57,    23,   142,    53,    13,   138,   139,
      57,   171,   138,   139,    61,    34,   121,    19,   236,   136,
     137,   171,    76,   135,   218,   218,    49,    50,    19,    76,
     121,   171,   135,    56,   226,   227,   135,   142,    15,   715,
     716,   239,   218,   138,   139,    19,   722,   723,   724,   725,
     726,   727,   728,   729,   730,   731,   732,   733,   734,   735,
     236,    10,    11,   243,   136,   137,   236,   237,   238,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,    63,   263,    13,    57,   266,   131,   132,   269,
     131,   132,   138,   139,    75,   275,   276,    13,   142,   279,
     280,   142,    13,    57,    76,   285,    57,   287,   278,    10,
      11,  3070,   202,  3072,    13,   169,  3075,  3076,   288,   289,
      31,    13,    76,   162,   171,    76,    13,   307,   308,    13,
     310,   276,    19,   156,    45,    46,    57,    13,   236,   237,
     238,    62,    53,    19,    20,    57,    57,    13,   122,   123,
      61,   375,    14,    19,   377,    76,   336,   337,    20,   339,
     340,   200,   201,    19,    76,    76,    14,    13,   236,   237,
     238,   473,    20,    19,   398,    23,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     288,    14,   410,   138,   139,   218,   341,    20,    19,    22,
      23,    13,    63,   383,   400,    10,    11,    19,    20,   379,
     380,   381,   382,   236,    75,   169,   239,   240,   241,   242,
     288,   289,   440,    14,    13,    53,    15,   440,    56,    20,
      13,    20,    23,   377,   410,    19,   447,   448,   449,   450,
     401,   402,     4,   423,   424,     7,     8,   427,   271,   272,
     273,   529,   530,    13,  3213,    15,   436,   169,    19,    19,
     171,   441,   442,    14,   440,   445,   448,   449,   480,    20,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
      57,    58,    59,    13,   479,    15,    63,    13,    13,    19,
      15,   436,   453,   454,   455,   456,   457,   458,    75,    76,
     461,   462,   463,   464,   465,   466,   467,   983,   984,    14,
      14,   379,   380,   381,   382,    20,    20,    13,    23,    15,
     220,   221,   998,   999,  1000,  1001,  1002,  1003,  1004,  1005,
    1006,  1007,  1008,  1009,  1010,    13,  1012,    13,    14,   220,
     221,    19,   522,    19,   622,   623,   624,   625,   626,   627,
     628,   629,   630,   631,   632,   633,   634,   635,    57,    58,
      59,    13,    13,    15,    63,    14,   527,   406,   407,   408,
      13,    20,   650,    13,    13,    15,    75,    76,     0,    19,
      14,   404,   405,    13,    14,    13,    20,   410,    13,    19,
     429,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     423,   226,   227,    13,    14,    13,    14,     3,     4,    19,
      14,    19,    14,   274,   275,   276,    20,   440,    20,    13,
      13,    14,   283,   284,   285,   286,    19,    14,    13,   290,
      15,    10,    11,    20,   166,    13,   344,   715,   716,    13,
      13,   531,    15,  1056,   722,   723,   724,   725,   726,   727,
     728,   729,   730,   731,   732,   733,   734,   735,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   138,   139,
     331,    14,    13,   334,   335,   336,   337,    20,   339,   340,
      13,    13,   343,    15,   344,   345,   218,   219,   220,   221,
     529,   530,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    14,    16,  1214,  1215,  1216,  1217,
      20,    22,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    14,   487,   488,   489,   490,
     491,    20,   712,  1209,  1210,  1211,  1212,  1213,  1214,  1215,
    1216,  1217,  1218,  1219,  1220,  1221,  1222,  1223,  1224,    14,
      51,    52,   346,    14,   348,    20,   350,   351,    20,    20,
      22,    20,    13,    22,   358,    13,   162,   361,   362,   363,
     364,   365,   366,   367,   368,    14,    14,    13,   400,   401,
      13,    20,    20,   622,   623,   624,   625,   626,   627,   628,
     629,   630,   631,   632,   633,   634,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   399,    14,    14,    13,   403,
      14,   650,    20,    20,   408,   409,    20,    14,    41,    17,
      14,  1212,  1213,    20,   848,   419,    20,   717,  1212,  1213,
     424,   425,    13,   857,    13,  1091,  1214,  1215,  1216,  1217,
    1218,  1219,   503,   504,   505,    14,    14,    14,   509,    14,
     511,    20,    20,    20,    14,    20,    14,    14,    14,    13,
      20,    13,    20,    20,    20,   845,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,    14,    14,   415,
     416,    14,    14,    20,    20,   983,   984,    20,    20,     4,
      14,    18,    14,    14,    13,    13,    20,    15,    20,    20,
     998,   999,  1000,  1001,  1002,  1003,  1004,  1005,  1006,  1007,
    1008,  1009,  1010,    31,  1012,    13,    13,    15,    14,    14,
      14,  1218,  1219,    14,    20,    20,    20,    45,    46,    20,
      14,    14,    14,    31,    14,    53,    20,    20,    20,    57,
      20,    13,    13,    61,    14,    14,    14,    45,    46,    13,
      20,    20,    20,   134,    14,    53,    14,    13,    76,    57,
      20,    14,    20,    61,    19,    14,    14,    20,    14,    14,
    1342,    20,    20,  1345,    20,    20,   431,   432,    76,    13,
      13,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   140,    14,    19,    14,
      19,    14,  1498,    20,    89,    20,    91,    20,    13,    13,
      95,    96,    97,   429,   430,   100,   101,   102,   103,   104,
     105,   106,   107,    19,    15,    15,    19,   112,    14,  1029,
    1030,  1031,  1032,  1033,  1034,  1035,    19,  1037,  1038,    19,
      14,    14,  1042,  1043,  1044,  1045,  1046,  1047,  1048,    19,
    1050,   446,  1052,   171,  1054,  1055,  1498,  1057,  1058,  1059,
    1060,  1061,   374,   343,    14,    14,  1066,  1067,  1068,  1069,
      20,    20,    14,   171,    14,   985,    14,    53,    20,    15,
      20,    53,    20,   487,   488,   489,   490,   491,  1088,    54,
      53,  1091,  1092,   405,   406,   407,   408,   409,    62,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,  1209,  1210,  1211,    20,   174,    14,    79,    14,    50,
      14,    20,    13,    13,   983,   984,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,   998,
     999,  1000,  1001,  1002,  1003,  1004,  1005,  1006,  1007,  1008,
    1009,  1010,    13,  1012,    13,    13,    13,    13,    13,  1435,
      13,    13,    13,    13,   407,    19,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,  1086,    13,    13,    13,
      13,   142,  1226,  1679,    13,    13,    13,   499,    20,    13,
      13,    13,    13,    19,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,  1204,   517,  1206,  1207,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    13,
      13,    13,    13,    13,    19,  1235,    13,    13,    13,    13,
    1240,  1674,  1242,  1243,    17,  1245,  1246,  1247,  1248,    19,
      19,  1251,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,  1265,    13,    13,    13,    13,
      13,    13,    13,    12,  1274,    13,  1276,  1277,  1278,    13,
      13,    13,    13,  1283,  1284,  1285,  1286,  1287,  1288,  1289,
      13,  1291,    13,    19,    13,    13,    13,    13,    13,    13,
      13,  1301,  1302,  1303,  1304,  1305,  1306,  1307,  1308,  1309,
    1310,  1311,  1312,  1313,  1314,  1315,    13,    13,    13,    13,
      13,  1321,  1322,  1323,  1324,  1325,  1326,  1327,    13,    13,
      13,    13,    13,  1333,  1334,    13,  1336,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,  1210,  1211,    13,  1354,    13,  1356,    13,    13,    13,
      13,    13,  1362,  1363,  1364,    13,    13,    13,    18,   134,
      19,  1371,  1372,  1373,  1374,  1375,  1376,  1377,    13,  1379,
    1380,    13,  1382,  1383,  1384,  1385,  1386,  1387,    13,  1389,
    1390,  1391,  1392,  1393,  1394,  1395,  1396,    13,    13,  1399,
      13,  1401,  1402,    13,  1404,  1405,  1406,   823,   824,    13,
      13,   827,   828,   829,   830,   831,   832,   833,   834,   835,
     836,   837,   838,   839,   840,    13,    13,    13,    13,    13,
      13,  1431,  1432,    13,    13,  1435,    13,  1437,    13,  1439,
    1440,    13,    13,    13,    20,    19,    14,    16,    15,  1449,
      16,    13,    16,    14,   174,   175,   176,   177,   178,   179,
     180,   181,   182,    19,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,    19,    14,    20,    14,    14,
      20,    14,    16,    13,    16,    13,   236,   237,   238,   239,
     220,   221,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,  2018,    13,    13,    13,    13,    13,    13,   269,
      13,    13,    13,    13,    13,    13,    13,   277,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,   288,    13,
      13,    13,   292,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,   983,   984,    14,
      14,    55,    64,    16,    20,    70,    14,    14,    20,    20,
      20,    20,   998,   999,  1000,  1001,  1002,  1003,  1004,  1005,
    1006,  1007,  1008,  1009,  1010,   335,  1012,   337,   338,   339,
      20,    20,    20,    20,    20,    20,    20,    20,   348,   349,
      20,    14,    14,    20,   354,   355,   356,   357,    14,    14,
      14,    14,    14,    13,    13,    16,    14,    62,    13,   369,
     370,   371,   372,   373,    20,   375,   376,    20,   378,    20,
      20,    20,    13,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,  1751,  1752,    13,
      13,    13,    13,    13,    13,    13,    13,   218,   218,    13,
      15,    13,    13,    19,    13,    13,    19,    13,    13,    13,
      20,   502,    19,    16,    16,    14,    14,   142,   142,   344,
     470,   142,   278,   142,    13,    16,    14,    13,    13,  1749,
      55,    13,  2124,    20,    14,    14,    13,    20,    64,    20,
      13,  2133,    20,  2135,    20,    20,    20,    14,   508,  1769,
      20,    14,    14,    14,    20,    20,    20,    58,    14,    59,
      20,    20,    14,    60,    59,    61,    20,    61,    61,    20,
      20,    20,    14,    20,    14,    20,    14,    14,    70,    20,
      70,    20,    14,    14,    20,    20,    19,   440,    14,    14,
      74,    20,    20,    20,    14,    14,    14,    20,    14,    20,
     398,    56,    19,    14,  1352,    20,    20,    20,    20,    53,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    13,    13,    20,
      14,    20,    20,  1853,  1854,  1855,  1856,    20,  1858,    20,
    1860,    20,    20,    20,    20,    14,  1866,  1867,  1868,    14,
      14,  1871,  1872,  1873,  1874,    14,  1876,    20,  1878,    20,
    1880,    16,    20,  1883,  1884,  1885,  1886,    20,    20,    20,
    1890,    20,    20,  1893,    20,    20,    20,    20,    20,    14,
      20,    20,    20,    20,  1904,    14,  1906,    20,    20,    14,
    1910,  1911,    20,  1913,  1914,  1915,  1916,  1917,  1918,  1919,
    1920,  1921,  1922,  1923,  1924,    20,  1926,    20,    20,    20,
      20,    20,    20,    20,    20,  1935,  1936,  1937,  1938,  1939,
    1940,  1941,  1942,  1943,    20,    20,    20,    14,    14,    14,
      14,    14,    14,    14,    14,    56,    56,  1957,  1958,  1959,
    1960,    20,    20,    20,  1964,  1965,  1966,  1967,    20,    20,
      20,    20,    13,    20,  1974,  1975,  1976,  1977,  1978,  1979,
    1980,  1981,  1982,  1983,  1984,    14,    14,    20,    13,    13,
      13,    13,  1992,  1993,  1994,    13,  1996,  1997,    14,  1999,
    2000,    14,    14,  2003,    74,  2005,    20,    22,    56,    20,
      20,    20,    20,    20,    20,    20,  2016,    20,    14,  2019,
      20,    14,    20,    20,    14,    20,    14,  2027,  2028,    16,
      14,    20,    14,  2033,    20,    14,    14,    14,    14,  2039,
      14,    14,  2042,  2043,    14,  2045,  2046,  2047,    14,    14,
      14,    14,    14,    14,    56,    14,    14,    14,   142,    14,
      20,  2061,    14,  2063,    20,    14,    14,    14,    14,    14,
      14,    14,    14,   471,    14,    56,    14,  2077,    14,    20,
      14,    20,    14,    20,    14,    14,    14,    14,    14,    20,
      14,    14,  2092,    14,  2094,    20,  1360,  1220,    20,  2099,
      20,    20,    20,    20,    20,  2105,    20,    20,    20,  2109,
    2110,    14,  2112,  2113,  2114,    20,  2116,  2117,    20,    20,
    2120,  2121,    14,  2123,    20,    20,    20,    14,    14,    14,
      14,    20,    20,    14,    14,    13,  2136,  2137,    20,    14,
    2140,    20,  2142,  2143,  2144,    14,    14,    14,    14,    20,
    2150,    14,    56,  2153,    14,  2155,    20,    14,    20,  2159,
    2160,  2161,    20,  2163,    14,    14,    14,    14,    14,  2169,
      14,    14,  2172,    70,  2174,    20,  2176,  2177,  2178,    20,
      14,    20,    14,    14,    14,    20,    56,  2187,  2188,    22,
      14,  2191,    20,    20,    20,    20,  2196,  2197,  2198,  2199,
    2200,  2201,    20,  2203,  2204,  2205,    20,  2207,  2208,  2209,
    2210,  2211,    20,    20,  2214,  2215,  2216,  2217,    20,  2219,
      20,    20,    20,    20,    20,    16,    16,    14,    14,  1221,
      14,    16,    20,    14,    14,    14,    14,    20,    14,    14,
      14,    14,    53,  2615,    14,    22,    14,    56,    20,    20,
      14,    20,    14,    20,    20,    20,    14,    14,    14,  2259,
      14,    20,    14,    56,    53,    20,    14,    20,   418,    20,
      20,    20,    14,    20,    20,    20,    20,    14,    14,    20,
      14,    20,    20,    14,    14,    20,    14,    20,    14,    14,
      14,    20,   146,    20,   146,   146,   417,    20,    20,    20,
      20,    20,    20,    20,    14,    20,    20,    20,    20,    20,
     146,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      14,    20,    20,    20,    20,    20,    14,    20,    14,    20,
      14,    14,    14,    20,    14,    20,    14,    14,    14,    20,
      14,    14,   146,    22,    14,    20,    14,    14,    20,    20,
      14,    14,    14,  2397,  2398,    14,    22,    22,  1222,    20,
    2404,    14,    20,    20,    20,    20,    20,    14,    20,    20,
      14,    14,  2372,    14,    20,    20,    14,    14,    20,    14,
      20,    14,    14,    14,    14,    14,    20,    14,    14,    14,
      14,    14,    20,    14,    14,    14,  2396,    14,    20,    14,
     419,   422,    20,    14,    20,  2018,    20,    20,    20,  1208,
      20,    20,    20,    20,    20,    20,    20,    14,    14,    20,
      20,    20,    14,  1224,    22,    20,    20,    20,    14,    20,
      20,    20,    20,    20,  1223,    20,    20,    20,    20,    20,
      20,    20,    20,    14,    20,    20,    20,    20,    14,    14,
      14,    14,    14,    14,  2454,  1063,  2456,   146,  2458,    14,
    2460,    20,    20,    20,    20,  2465,  2466,    20,  2468,  2469,
    2470,  2471,    20,  2473,  2474,  2475,  2476,    20,    20,    14,
    2480,    14,    20,  2483,  2484,    14,    20,    14,    20,  2489,
      20,    14,    20,    14,  2494,    20,  2496,  2497,  2498,  2499,
    2500,  2501,  2502,  2503,    20,  2505,  2506,  2507,  2508,  2509,
    2510,  2511,  2512,  2513,  2514,  2515,  2516,  2517,  2518,    20,
    2520,    20,    20,    20,    20,    14,    19,    14,  2528,    20,
      20,   421,  2532,  2533,    20,    20,    20,    20,    20,    20,
      20,    20,  2542,  2543,    20,    20,    20,    20,    20,    20,
      20,    14,  2552,  2553,  2554,  2555,  2556,    16,  2558,  2559,
      20,  2561,  2562,    20,    20,    20,  2566,  2567,    20,    20,
    2570,  2571,  2572,  2573,  2484,    20,    14,  2487,    14,    14,
      14,    20,    14,    20,    -1,  2585,   146,    20,    -1,    20,
      20,  2591,    20,    20,    20,  2595,    14,  2597,  2598,    20,
      20,    14,    14,    20,    20,    14,    20,  2607,  2608,  2609,
      14,    14,  2612,  2613,    20,    20,    14,    14,    20,    20,
      14,    20,    14,    14,    20,  2625,    14,  2627,    14,  2629,
    2630,    20,  2632,  2633,  2634,  2635,  2636,  2637,  2638,  2639,
      20,  2641,  2642,  2643,  2644,  2645,  2646,  2647,  2648,  2649,
      20,  2651,  2652,  2653,  2654,    20,    20,    14,    14,    14,
      14,    14,    14,    14,    14,  2665,  2666,  2667,  2668,    14,
      14,  2671,  2672,    14,    14,    14,    14,    20,    20,    -1,
      14,    14,    14,    20,    20,    20,    14,    -1,    14,    20,
      20,    20,    14,    20,    14,    20,    14,    20,    14,    20,
      14,    20,    14,    20,    14,    20,    -1,    20,    -1,    20,
      -1,    20,    20,    20,    20,    20,    20,    14,    20,    20,
      20,    20,    20,    14,    20,    14,    14,    20,  2772,    -1,
      20,    -1,    -1,    20,    20,    20,    20,    20,    20,    20,
      20,    14,    14,    14,    14,    20,    20,    14,    14,    14,
      14,    20,    20,    14,    14,    14,    -1,    20,    20,    14,
     420,    -1,    20,    20,    20,    14,    20,    20,    14,    20,
      20,    14,    20,    20,    14,    20,    20,    -1,    20,    20,
      14,    20,    20,    20,    20,    20,    14,    14,    20,    14,
      14,    14,    14,    14,    14,    -1,    14,    -1,    14,    14,
      -1,    20,    14,    20,    14,    14,    20,    14,    14,    20,
      14,  2811,  2812,    14,  2814,  2815,    14,  2817,  2818,    14,
    2820,  2821,  2822,    20,  2824,  2825,    20,    20,  2828,    14,
      20,    14,    20,  2833,  2834,    14,  2836,    14,  2838,    20,
    2840,    -1,  2842,  2843,  2844,  2845,  2846,    20,    20,    20,
    2850,  2851,  2852,  2853,  2854,  2855,    20,  2857,  2858,  2859,
    2860,  2861,  2862,  2863,    20,  2865,  2866,  2867,  2868,  2869,
      20,  2871,    20,    20,    20,    20,  2876,  2877,    20,  2879,
    2880,  2881,  2882,  2883,  2884,    20,  2886,  2887,  2888,  2889,
      14,  2891,    14,    20,    14,  2895,    14,  2897,    14,  2899,
      -1,    20,  2902,    20,  2904,  2905,    20,  2907,    14,    20,
      14,    20,    20,    14,  2914,    20,  2916,  2827,    20,  2919,
    2920,  2831,    14,    20,    20,    20,    20,    20,    14,    20,
      20,    20,    20,    14,    14,  2935,  2936,  2937,  2938,  2939,
      14,    14,    14,    20,    20,  2945,  2946,  2947,    14,    20,
      14,    14,    20,    20,    14,    20,    14,    -1,    20,    20,
      14,    20,    14,    20,    20,    20,    14,    20,    14,    20,
      20,    20,    14,    20,    14,    20,    20,    14,    14,    20,
      -1,    20,    20,    14,    -1,    20,    20,    20,    20,    14,
      20,    20,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3035,    -1,    -1,  3038,  3039,
    3040,    -1,    -1,    -1,  3044,    -1,  3046,  3047,    -1,    -1,
      -1,    -1,  3052,  3053,    -1,  3055,    -1,  3057,  3058,  3059,
    3060,  3061,  3062,    -1,  3064,  3065,  3066,  3067,  3068,  3069,
    3070,    -1,  3072,    -1,    -1,  3075,  3076,  3077,  3078,  3079,
      -1,    -1,    -1,    -1,    -1,  3085,  3086,    -1,    -1,  3089,
      -1,    -1,    -1,  3093,  3094,  3095,    -1,    -1,  3098,    -1,
      -1,    -1,    -1,    -1,  3104,  3105,    -1,    -1,  3108,  3109,
      -1,    -1,  3112,    -1,  3114,  3115,    -1,    -1,  3118,  3119,
      -1,  3121,    -1,  3123,  3124,  3125,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3051,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3185,  3186,  3187,  3188,    -1,
    3190,  3191,    -1,    -1,  3194,    -1,    -1,    -1,    -1,    -1,
      -1,  3201,    -1,  3203,    -1,  3205,    -1,    -1,  3208,    -1,
      -1,    -1,    -1,  3213,    -1,    -1,    -1,    -1,  3218,  3219,
      -1,  3221,    -1,  3223,    -1,  3225,  3226,  3227,    -1,  3229,
    3230,    -1,  3232,    -1,  3234,    -1,  3236,  3237,  3238,    -1,
      -1,  3241,  3242,  3243,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3280,    -1,    -1,    -1,  3284,  3285,    -1,    -1,    -1,  3289,
      -1,  3291,  3292,    -1,  3294,  3295,    -1,    -1,    -1,  3299,
      -1,    -1,  3302,  3303,  3304,    -1,  3306,  3307,    -1,  3309,
    3310,    -1,    -1,  3313,  3314,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3336,    -1,    -1,    -1,
      -1,    -1,  3342,  3343,  3344,    -1,    -1,    -1,  3348,  3349,
      -1,    -1,  3352,  3353,    -1,    -1,  3356,    -1,     0,    -1,
       2,     3,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3370,  3371,    -1,  3373,    -1,  3375,    18,    -1,  3378,    21,
      -1,    -1,    24,    -1,    -1,    27,    -1,    -1,  3388,    -1,
    3390,  3391,  3392,    -1,    -1,    -1,    -1,    -1,    -1,  3399,
    3400,  3401,    -1,    -1,    -1,    -1,  3406,  3407,  3408,    -1,
      52,    53,    -1,  3413,  3414,    -1,    -1,  3417,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,    -1,   125,   126,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   146,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,   201,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     242,    -1,   244,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   258,   259,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   270,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   279,   280,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   309,   310,   311,
     312,   313,   314,   315,   316,   317,    -1,    -1,    -1,    -1,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,    -1,    -1,    -1,    -1,   338,   339,    -1,    -1,
     342,   343,   344,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   377,   378,    -1,    -1,    -1,
      -1,    -1,   384,    -1,   386,   387,   388,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   400,   401,
     402,   403,    -1,    -1,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   426,   427,    -1,   429,    -1,   431,
     432,    -1,     0,   435,   436,    -1,    -1,    -1,    -1,     7,
      -1,     9,    10,    11,    -1,    13,    -1,   449,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    -1,    -1,    -1,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    -1,    -1,    81,    82,    83,    84,    -1,    86,    87,
      -1,   523,    -1,    -1,    -1,    -1,    -1,   529,   530,   531,
     532,   533,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     158,    -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,
      -1,    -1,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     622,   623,   624,   625,   626,   627,   628,   629,   630,   631,
     632,   633,   634,   635,    -1,    -1,    -1,    -1,    -1,    -1,
     208,   209,    -1,    -1,    -1,    -1,    -1,    -1,   650,    -1,
      -1,    -1,    -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   256,    -1,
     258,    -1,    -1,    -1,    -1,    -1,   264,   265,   266,   267,
     268,   269,    -1,   271,    -1,    -1,   708,    -1,    -1,    -1,
      -1,    -1,    -1,   715,   716,   717,    -1,    -1,    -1,    -1,
     722,   723,   724,   725,   726,   727,   728,   729,   730,   731,
     732,   733,   734,   735,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   312,   313,   314,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   327,
     328,   329,   330,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   377,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   401,   402,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   846,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,    -1,   441,   442,    -1,    -1,   445,    -1,    -1,
      -1,    -1,    -1,   451,   452,   453,   454,   455,   456,   457,
     458,   893,    -1,   461,   462,   463,   464,   465,   466,   467,
      -1,   469,    -1,    -1,    -1,    -1,   474,    -1,   476,   477,
      -1,    -1,    -1,   481,   482,   483,   484,   919,   486,    -1,
      -1,   923,    -1,    -1,    -1,   493,   494,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   510,    -1,    -1,    -1,    -1,   515,   516,    -1,
     518,   519,   520,   521,   522,   523,   524,   525,   526,   527,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   973,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   983,   984,   985,   986,    -1,    -1,    -1,    -1,    -1,
      -1,   993,    -1,    -1,    -1,    -1,   998,   999,  1000,  1001,
    1002,  1003,  1004,  1005,  1006,  1007,  1008,  1009,  1010,    -1,
    1012,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1025,    -1,    -1,    -1,    -1,  1030,    -1,
      -1,    -1,    -1,    -1,  1036,    -1,    -1,  1039,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1049,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1073,    -1,  1075,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1086,    -1,    -1,    -1,    -1,  1091,
    1092,  1093,  1094,  1095,  1096,  1097,  1098,  1099,  1100,  1101,
    1102,  1103,  1104,  1105,  1106,    -1,  1108,  1109,  1110,  1111,
      -1,  1113,  1114,  1115,    -1,    -1,  1118,  1119,  1120,  1121,
    1122,  1123,  1124,  1125,  1126,  1127,  1128,  1129,  1130,  1131,
    1132,  1133,  1134,  1135,  1136,  1137,  1138,  1139,  1140,  1141,
    1142,  1143,  1144,  1145,  1146,  1147,  1148,  1149,  1150,    -1,
      -1,  1153,  1154,  1155,  1156,  1157,  1158,  1159,  1160,  1161,
    1162,  1163,  1164,  1165,  1166,  1167,  1168,  1169,  1170,  1171,
    1172,  1173,  1174,  1175,  1176,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1191,
    1192,  1193,  1194,  1195,  1196,    -1,  1198,  1199,  1200,  1201,
    1202,    -1,  1204,    -1,  1206,  1207,  1208,  1209,  1210,  1211,
    1212,  1213,  1214,  1215,  1216,  1217,  1218,  1219,  1220,  1221,
    1222,  1223,  1224,    -1,    -1,  1227,  1228,  1229,    -1,    -1,
    1232,    -1,    -1,    -1,    -1,    -1,    -1,  1239,    -1,    -1,
      -1,    -1,  1244,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1259,    -1,    -1,
    1262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1273,    -1,  1275,    -1,    -1,    -1,  1279,  1280,  1281,
    1282,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1290,    -1,
    1292,  1293,  1294,  1295,  1296,  1297,  1298,  1299,  1300,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1316,    -1,  1318,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1328,  1329,  1330,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1339,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1357,  1358,  1359,    -1,    -1,
      -1,    -1,    -1,    -1,  1366,  1367,    -1,  1369,  1370,  1371,
    1372,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1388,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1397,  1398,    -1,  1400,    -1,
      -1,  1403,    -1,    -1,    -1,  1407,  1408,    -1,    -1,    -1,
    1412,  1413,  1414,  1415,  1416,  1417,    -1,  1419,    -1,    -1,
    1422,  1423,    -1,  1425,  1426,  1427,  1428,  1429,    -1,    -1,
      -1,  1433,    -1,  1435,  1436,    -1,    -1,    -1,    -1,  1441,
    1442,  1443,    -1,  1445,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1498,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,  1608,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1676,    -1,    -1,  1679,    -1,    -1,
      -1,  1683,  1684,  1685,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1734,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1750,     7,
      -1,     9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1769,    -1,    -1,
      -1,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    55,    -1,    57,
      58,    59,    60,    61,    62,    63,    -1,    65,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    -1,    75,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1848,    -1,    -1,    -1,
    1852,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1864,  1865,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,
    1892,    -1,  1894,    -1,    -1,    -1,    -1,    -1,    -1,  1901,
      -1,    -1,    -1,    -1,    -1,   163,  1908,  1909,    -1,    -1,
      -1,    -1,    -1,   171,    -1,   173,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1927,  1928,  1929,  1930,  1931,
    1932,  1933,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1947,    -1,  1949,  1950,  1951,
    1952,  1953,    -1,  1955,  1956,    -1,    -1,    -1,    -1,  1961,
    1962,    -1,    -1,    -1,    -1,   223,  1968,  1969,    -1,    -1,
    1972,  1973,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1998,    -1,   256,  2001,
     258,    -1,    -1,    -1,  2006,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2018,    -1,  2020,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2031,
      -1,    -1,  2034,  2035,  2036,  2037,  2038,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2053,    -1,    -1,    -1,    -1,    -1,  2059,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   329,   330,    -1,    -1,    -1,    -1,    -1,  2080,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2112,    -1,    -1,    -1,    -1,    -1,  2118,  2119,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2139,    -1,    -1,
      -1,    -1,    -1,   401,   402,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,    -1,   441,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   451,   452,   453,   454,   455,   456,   457,
     458,    -1,    -1,   461,   462,   463,   464,   465,   466,   467,
      -1,    -1,    -1,    -1,    -1,  2217,  2218,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   483,   484,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   527,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     0,    -1,    -1,     3,     4,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,
       9,    10,    11,    -1,    13,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    -1,    55,    -1,    57,    58,
      59,    60,    61,    62,    63,    -1,    65,    66,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    -1,    75,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2450,  2451,
     146,    -1,    -1,    -1,   143,   144,   145,   146,   147,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   162,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,    -1,
      -1,  2483,   171,    -1,   173,  2487,  2488,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2505,  2506,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2521,
    2522,  2523,  2524,  2525,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   223,    -1,  2538,    -1,    -1,  2541,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   256,    -1,   258,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2581,
     276,    -1,    -1,   279,   280,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2594,    -1,    -1,    -1,    -1,    -1,  2600,    -1,
    2602,    -1,  2604,    -1,  2606,    -1,    -1,    -1,  2610,  2611,
      -1,    -1,    -1,   309,   310,   311,   312,   313,   314,   315,
     316,    -1,    -1,    -1,  2626,    -1,    -1,    -1,   324,   325,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     329,   330,    -1,    -1,    -1,   341,    -1,   343,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2657,    -1,    -1,    -1,    -1,
      -1,  2663,    -1,    -1,    -1,    -1,    -1,  2669,  2670,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     426,   427,    -1,   429,   430,   431,   432,    -1,    -1,   435,
     436,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,    -1,   441,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   451,   452,   453,   454,   455,   456,   457,   458,
      -1,    -1,   461,   462,   463,   464,   465,   466,   467,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   483,   484,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2827,    -1,    -1,    -1,  2831,
      -1,    -1,    -1,   529,   530,   531,    -1,    -1,   527,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2857,  2858,  2859,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2870,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2893,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2909,  2910,    -1,
      -1,    -1,    -1,  2915,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   622,   623,   624,   625,
     626,   627,   628,   629,   630,   631,   632,   633,   634,   635,
      -1,  2943,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   650,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   715,
     716,   717,    -1,    -1,    -1,    -1,   722,   723,   724,   725,
     726,   727,   728,   729,   730,   731,   732,   733,   734,   735,
      -1,    -1,    -1,    -1,    -1,    -1,  3048,    -1,    -1,  3051,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3070,    -1,
    3072,    -1,    -1,  3075,  3076,    -1,    -1,    -1,  3080,  3081,
    3082,  3083,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3111,
      -1,  3113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3122,    -1,    -1,    -1,    -1,    -1,    -1,   823,   824,   825,
      -1,   827,   828,   829,   830,   831,   832,   833,   834,   835,
     836,   837,   838,   839,   840,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3231,
      -1,  3233,    -1,    -1,    -1,    -1,    -1,    -1,  3240,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3270,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3283,    -1,    -1,    -1,    -1,    -1,   983,   984,   985,
      -1,    -1,    -1,    -1,    -1,    -1,  3298,    -1,    -1,  3301,
      -1,    -1,   998,   999,  1000,  1001,  1002,  1003,  1004,  1005,
    1006,  1007,  1008,  1009,  1010,    -1,  1012,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     0,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3350,    -1,
      18,    -1,    -1,  1049,    -1,    -1,  3358,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3376,    -1,    -1,    -1,  3380,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1091,  1092,    -1,  1094,  1095,
      -1,    -1,    -1,    -1,    -1,  1101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1113,  1114,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1141,  1142,  1143,  1144,  1145,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1168,    -1,    -1,    -1,    -1,    -1,   146,  1175,
    1176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1191,  1192,  1193,    -1,  1195,
    1196,    -1,  1198,  1199,  1200,  1201,    -1,    -1,  1204,    -1,
    1206,    -1,  1208,  1209,  1210,  1211,  1212,  1213,  1214,  1215,
    1216,  1217,  1218,  1219,  1220,  1221,  1222,  1223,  1224,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1259,    -1,    -1,  1262,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   273,   274,    -1,    -1,    -1,
      -1,   279,   280,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1318,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   309,   310,   311,   312,   313,   314,   315,   316,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   324,   325,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   343,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1388,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1398,    -1,  1400,    -1,    -1,    -1,    -1,    -1,
      -1,  1407,    -1,    -1,    -1,    -1,  1412,  1413,  1414,    -1,
    1416,    -1,    -1,    -1,    -1,    -1,  1422,    -1,    -1,  1425,
    1426,  1427,  1428,  1429,    -1,    -1,    -1,    -1,    -1,  1435,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   426,   427,
      -1,    -1,    -1,    -1,    -1,    -1,   434,   435,   436,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1498,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   529,   530,   531,   532,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,
      -1,    -1,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   622,   623,   624,   625,   626,   627,
     628,   629,   630,   631,   632,   633,   634,   635,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1676,    -1,   650,  1679,    -1,    -1,    -1,  1683,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     125,   126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1734,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   715,   716,   717,
      -1,    -1,    -1,    -1,   722,   723,   724,   725,   726,   727,
     728,   729,   730,   731,   732,   733,   734,   735,    -1,    -1,
      -1,    -1,    -1,  1769,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   242,    -1,   244,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   258,   259,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   270,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   279,   280,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1894,    -1,
      -1,    -1,    -1,    -1,    -1,  1901,    -1,    -1,    -1,    -1,
      -1,    -1,  1908,    -1,    -1,    -1,    -1,   342,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1929,  1930,    -1,     7,    -1,     9,    10,
      11,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   378,    -1,    -1,    -1,    -1,    -1,   384,
      31,    32,    -1,    -1,    -1,  1961,  1962,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    -1,   402,   403,    -1,
      -1,    -1,    53,    -1,    55,    -1,    57,    58,    59,    60,
      61,    62,    63,    -1,    65,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    -1,    75,    76,    -1,    -1,    -1,    -1,
    2006,   436,    -1,    -1,    -1,   983,   984,   985,    -1,    -1,
      -1,    -1,  2018,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     998,   999,  1000,  1001,  1002,  1003,  1004,  1005,  1006,  1007,
    1008,  1009,  1010,    -1,  1012,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2053,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   143,   144,   145,   146,   147,    -1,    -1,    -1,
      -1,  1049,    -1,    -1,    -1,    -1,    -1,    -1,  1056,    -1,
      -1,    -1,   163,    -1,  1062,    -1,    -1,   522,   523,    -1,
     171,    -1,   173,    -1,    -1,    -1,    -1,    -1,   533,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2112,    -1,    -1,    -1,
      -1,    -1,    -1,  1091,  1092,    -1,  1094,  1095,    -1,    -1,
      -1,    -1,    -1,  1101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1113,  1114,    -1,    -1,    -1,
      -1,    -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,  1127,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1141,  1142,  1143,  1144,  1145,    -1,    -1,
      -1,    -1,    -1,  1151,  1152,   256,    -1,   258,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1168,    -1,    -1,    -1,    -1,    -1,    -1,  1175,  1176,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2217,  2218,  1191,  1192,  1193,    -1,  1195,  1196,    -1,
    1198,  1199,  1200,  1201,    -1,    -1,  1204,    -1,  1206,    -1,
    1208,  1209,  1210,  1211,  1212,  1213,  1214,  1215,  1216,  1217,
    1218,  1219,  1220,  1221,  1222,  1223,  1224,    -1,   329,   330,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   279,   280,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   708,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1259,    -1,    -1,  1262,    -1,    -1,    -1,    -1,    -1,
      -1,   309,   310,   311,   312,   313,   314,   315,   316,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   324,   325,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   343,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1318,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,    -1,
     441,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     451,   452,   453,   454,   455,   456,   457,   458,    -1,    -1,
     461,   462,   463,   464,   465,   466,   467,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   483,   484,    -1,    -1,    -1,    -1,   426,   427,
    1388,   846,    -1,    -1,    -1,    -1,    -1,   435,   436,    -1,
    1398,    -1,  1400,    -1,    -1,    -1,    -1,    -1,    -1,  1407,
      -1,  1409,  1410,  1411,  1412,  1413,  1414,    -1,  1416,    -1,
    1418,    -1,  1420,  1421,  1422,    -1,   527,  1425,  1426,  1427,
    1428,  1429,    -1,    -1,    -1,    -1,    -1,  1435,   893,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   919,    -1,    -1,    -1,   923,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1498,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2538,    -1,    -1,  2541,    -1,    -1,   973,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   986,    -1,    -1,    -1,    -1,    -1,    -1,   993,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1025,    -1,    -1,    -1,  2600,    -1,  2602,    -1,  2604,    -1,
    2606,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1608,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1073,    -1,
    1075,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1086,    -1,    -1,    -1,    -1,  1091,  2663,    -1,    -1,
      -1,    -1,    -1,  2669,  2670,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1674,    -1,  1676,    -1,
      -1,  1679,    -1,    -1,    -1,  1683,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1153,  1154,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1734,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1202,    -1,  1204,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1769,  1227,  1228,  1229,    -1,    -1,  1232,    -1,    -1,
      -1,    -1,    -1,    -1,  1239,    -1,    -1,    -1,    -1,  1244,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,
      -1,     9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    55,    -1,    57,
      58,    59,    60,    61,    62,    63,    -1,    65,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    -1,    75,    76,    -1,
      -1,    -1,    -1,  2909,  1339,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1894,    -1,    -1,    -1,
      -1,    -1,  1357,  1901,    -1,    -1,    -1,    -1,    -1,    -1,
    1908,  1366,    -1,    -1,    -1,    -1,    -1,  2943,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1929,  1930,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1415,    -1,    -1,  1961,  1962,   163,    -1,    -1,  1423,    -1,
      -1,    -1,    -1,   171,    -1,   173,    -1,    -1,  1433,    -1,
    1435,  1436,    -1,    -1,    -1,    -1,  1441,  1442,  1443,    -1,
    1445,    -1,    -1,    -1,  1449,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2006,    -1,
      -1,  1049,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2018,    -1,    -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1091,  1092,  2053,  1094,  1095,   256,    -1,
     258,    -1,    -1,  1101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1113,  1114,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1127,
      -1,    -1,    -1,    -1,    -1,    -1,  3122,    -1,    -1,    -1,
      -1,    -1,    -1,  1141,  1142,  1143,  1144,  1145,    -1,    -1,
      -1,    -1,    -1,    -1,  2112,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1168,   329,   330,    -1,    -1,    -1,    -1,  1175,  1176,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1191,  1192,  1193,    -1,  1195,  1196,    -1,
    1198,  1199,  1200,  1201,    -1,    -1,  1204,    -1,  1206,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3240,    -1,    -1,    -1,    -1,  2217,
    2218,  1259,    -1,    -1,  1262,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,    -1,   441,  3270,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   451,   452,   453,   454,   455,   456,   457,
     458,    -1,    -1,   461,   462,   463,   464,   465,   466,   467,
      -1,    -1,  3298,    -1,    -1,  3301,    -1,    -1,    -1,    -1,
    1318,    -1,    -1,    -1,    -1,   483,   484,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1750,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   527,
      -1,    -1,  3358,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1388,    -1,    -1,    -1,  3380,    -1,    -1,    -1,    -1,    -1,
    1398,    -1,  1400,    -1,    -1,    -1,    -1,    -1,    -1,  1407,
      -1,    -1,    -1,    -1,  1412,  1413,  1414,    -1,  1416,    -1,
      -1,    -1,    -1,    -1,  1422,    -1,    -1,  1425,  1426,  1427,
    1428,  1429,    -1,  1848,    -1,    -1,    -1,  1435,    -1,    -1,
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
      -1,    -1,    -1,    -1,  1969,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2538,    -1,    -1,  2541,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2027,  2028,    -1,    -1,  2031,    -1,  2033,  2034,
    2035,  2036,  2037,  2038,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2600,    -1,  2602,    -1,  2604,    -1,  2606,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1676,    -1,
      -1,    -1,    -1,    -1,    -1,  1683,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2663,    -1,    -1,    -1,    -1,
      -1,  2669,  2670,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1734,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1769,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     7,    -1,     9,    10,    11,    -1,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    -1,    -1,    -1,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    -1,    -1,    81,    82,    83,    84,
      -1,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1894,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1908,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1929,  1930,    -1,    -1,    -1,    -1,    -1,   143,   144,
     145,   146,   147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2909,    -1,   158,    -1,    -1,    -1,    -1,   163,    -1,
      -1,    -1,    -1,  1961,  1962,   170,   171,   172,   173,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2943,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   208,   209,    -1,    -1,    -1,  2006,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   223,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2450,  2451,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   256,    -1,   258,    -1,    -1,    -1,    -1,    -1,   264,
     265,   266,   267,   268,   269,    -1,   271,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   312,   313,   314,
      -1,    -1,    -1,    -1,  2112,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   327,   328,   329,   330,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3122,    -1,  2581,    -1,    -1,    -1,
      -1,    -1,   377,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   401,   402,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2217,
    2218,    -1,    -1,    -1,    -1,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,    -1,   441,   442,    -1,    -1,
     445,    -1,    -1,    -1,    -1,    -1,   451,   452,   453,   454,
     455,   456,   457,   458,    -1,    -1,   461,   462,   463,   464,
     465,   466,   467,    -1,   469,    -1,    -1,    -1,    -1,   474,
      -1,   476,   477,    -1,    -1,    -1,   481,   482,   483,   484,
      -1,   486,  3240,    -1,    -1,    -1,    -1,    -1,   493,   494,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   510,    -1,    -1,    -1,    -1,
     515,   516,  3270,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3298,    -1,    -1,  3301,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     7,    -1,     9,    10,    11,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,
    3358,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      -1,    55,  3380,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    -1,    -1,    -1,    73,
      74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    -1,    -1,    88,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2893,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,    -1,   157,    -1,   159,   160,   161,   162,   163,
     164,   165,    -1,   167,   168,    -1,    -1,   171,    -1,   173,
    2538,    -1,    -1,  2541,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,    -1,    -1,    -1,    -1,   222,   223,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2600,    -1,  2602,    -1,  2604,    -1,  2606,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
      -1,    -1,    -1,  3048,    -1,    -1,   270,    -1,    -1,    -1,
     274,   275,   276,    -1,    -1,   279,   280,   281,   282,   283,
     284,   285,   286,   287,    -1,    -1,   290,   291,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2663,    -1,    -1,    -1,    -1,
      -1,  2669,  2670,    -1,   308,   309,   310,   311,    -1,    -1,
      -1,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,    -1,    -1,   329,   330,   331,    -1,    -1,
     334,   335,   336,   337,    -1,   339,   340,   341,   342,   343,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   400,   401,   402,    -1,
      -1,    -1,    -1,    -1,    -1,  3190,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,    -1,   441,    -1,   443,
     444,    -1,   446,    -1,    -1,    -1,    -1,   451,   452,   453,
     454,   455,   456,   457,   458,    -1,    -1,   461,   462,   463,
     464,   465,   466,   467,   468,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   483,
     484,   485,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   495,   496,   497,   498,    -1,   500,   501,  3283,   503,
     504,   505,   506,   507,    -1,   509,    -1,   511,   512,   513,
     514,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   527,    -1,    -1,     7,    -1,     9,    10,
      11,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2909,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    -1,    -1,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    -1,    55,  2943,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    -1,    69,    -1,
      -1,    -1,    73,    -1,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    -1,   157,    -1,   159,   160,
     161,   162,   163,   164,   165,    -1,   167,   168,    -1,    -1,
     171,    -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,    -1,    -1,    -1,
      -1,   222,   223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3122,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,    -1,    -1,    -1,    -1,    -1,    -1,   270,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   279,   280,
     281,   282,    -1,    -1,    -1,    -1,   287,    -1,    -1,    -1,
     291,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   308,   309,   310,
     311,    -1,    -1,    -1,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,    -1,    -1,   329,   330,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     341,   342,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     401,   402,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3298,    -1,    -1,  3301,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,    -1,
     441,    -1,   443,   444,    -1,    -1,    -1,    -1,    -1,    -1,
     451,   452,   453,   454,   455,   456,   457,   458,    -1,    -1,
     461,   462,   463,   464,   465,   466,   467,   468,    -1,    -1,
    3358,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   483,   484,   485,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3380,    -1,   495,   496,   497,   498,    -1,   500,
     501,    -1,    -1,    -1,    -1,   506,   507,    -1,    -1,    -1,
      -1,   512,   513,   514,     7,    -1,     9,    10,    11,    -1,
      13,    -1,    -1,    -1,    17,    -1,   527,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
      -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    -1,    55,    -1,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    -1,    69,    -1,    -1,    -1,
      73,    -1,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,   157,    -1,   159,   160,   161,   162,
     163,   164,   165,    -1,   167,   168,    -1,    -1,   171,    -1,
     173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,    -1,    -1,    -1,    -1,   222,
     223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,    -1,    -1,    -1,    -1,    -1,    -1,   270,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   279,   280,   281,   282,
      -1,    -1,    -1,    -1,   287,    -1,    -1,    -1,   291,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   308,   309,   310,   311,    -1,
      -1,    -1,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,    -1,    -1,   329,   330,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   341,   342,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   439,    -1,   441,    -1,
     443,   444,    -1,    -1,    -1,    -1,    -1,    -1,   451,   452,
     453,   454,   455,   456,   457,   458,    -1,    -1,   461,   462,
     463,   464,   465,   466,   467,   468,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     483,   484,   485,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   495,   496,   497,   498,    -1,   500,   501,    -1,
      -1,    -1,    -1,   506,   507,    -1,    -1,    -1,    -1,   512,
     513,   514,     7,    -1,     9,    10,    11,    -1,    13,    -1,
      -1,    -1,    17,    -1,   527,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      55,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    -1,    69,    -1,    -1,    -1,    73,    -1,
      75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,   157,    -1,   159,   160,   161,   162,   163,   164,
     165,    -1,   167,   168,    -1,    -1,   171,    -1,   173,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,    -1,    -1,    -1,    -1,   222,   223,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,    -1,
      -1,    -1,    -1,    -1,    -1,   270,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   279,   280,   281,   282,    -1,    -1,
      -1,    -1,   287,    -1,    -1,    -1,   291,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   308,   309,   310,   311,    -1,    -1,    -1,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,    -1,    -1,   329,   330,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   341,   342,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,    -1,   441,    -1,   443,   444,
      -1,    -1,    -1,    -1,    -1,    -1,   451,   452,   453,   454,
     455,   456,   457,   458,    -1,    -1,   461,   462,   463,   464,
     465,   466,   467,   468,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   483,   484,
     485,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     495,   496,   497,   498,    -1,   500,   501,    -1,    -1,    -1,
      -1,   506,   507,    -1,    -1,    -1,    -1,   512,   513,   514,
       7,    -1,     9,    10,    11,    -1,    13,    -1,    -1,    -1,
      -1,    -1,   527,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    55,    -1,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    -1,    69,    -1,    -1,    -1,    73,    -1,    75,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,    -1,
     157,    -1,   159,   160,   161,   162,   163,   164,   165,    -1,
     167,   168,    -1,    -1,   171,    -1,   173,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,    -1,    -1,    -1,    -1,   222,   223,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,    -1,    -1,    -1,
      -1,    -1,    -1,   270,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   279,   280,   281,   282,    -1,    -1,    -1,    -1,
     287,    -1,    -1,    -1,   291,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   308,   309,   310,   311,    -1,    -1,    -1,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
      -1,    -1,   329,   330,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   341,   342,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,    -1,   441,    -1,   443,   444,    -1,    -1,
      -1,    -1,    -1,    -1,   451,   452,   453,   454,   455,   456,
     457,   458,    -1,    -1,   461,   462,   463,   464,   465,   466,
     467,   468,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   483,   484,   485,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   495,   496,
     497,   498,    -1,   500,   501,    -1,    -1,    -1,    -1,   506,
     507,    -1,    -1,    -1,    -1,   512,   513,   514,     7,    -1,
       9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,
     527,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    57,    58,
      59,    60,    -1,    62,    63,    64,    65,    66,    -1,    -1,
      69,    -1,    -1,    -1,    73,    -1,    75,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,    -1,   157,    -1,
     159,   160,   161,   162,   163,   164,   165,    -1,   167,   168,
      -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,    -1,
      -1,    -1,    -1,   222,   223,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,    -1,    -1,    -1,    -1,    -1,
      -1,   270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     279,   280,   281,   282,    -1,    -1,    -1,    -1,   287,    -1,
      -1,    -1,   291,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   308,
     309,   310,   311,    -1,    -1,    -1,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,    -1,    -1,
     329,   330,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   341,   342,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   401,   402,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,    -1,   441,    -1,   443,   444,    -1,    -1,    -1,    -1,
      -1,    -1,   451,   452,   453,   454,   455,   456,   457,   458,
      -1,    -1,   461,   462,   463,   464,   465,   466,   467,   468,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   483,   484,   485,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   495,   496,   497,   498,
      -1,   500,   501,    -1,    -1,    -1,    -1,   506,   507,    -1,
      -1,    -1,    -1,   512,   513,   514,     7,    -1,     9,    10,
      11,    -1,    13,    -1,    -1,    -1,    -1,    -1,   527,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    -1,    -1,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    -1,    57,    58,    59,    60,
      -1,    62,    63,    64,    65,    66,    -1,    -1,    69,    -1,
      -1,    -1,    73,    -1,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    -1,   157,    -1,   159,   160,
     161,   162,   163,   164,   165,    -1,   167,   168,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,    -1,    -1,    -1,
      -1,   222,   223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,    -1,    -1,    -1,    -1,    -1,    -1,   270,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   279,   280,
     281,   282,    -1,    -1,    -1,    -1,   287,    -1,    -1,    -1,
     291,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   308,   309,   310,
     311,    -1,    -1,    -1,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,    -1,    -1,   329,   330,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     341,   342,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,    -1,
     441,    -1,   443,   444,    -1,    -1,    -1,    -1,    -1,    -1,
     451,   452,   453,   454,   455,   456,   457,   458,    -1,    -1,
     461,   462,   463,   464,   465,   466,   467,   468,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   483,   484,   485,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   495,   496,   497,   498,    -1,   500,
     501,    -1,    -1,    -1,    -1,   506,   507,    -1,    -1,    -1,
      -1,   512,   513,   514,     7,    -1,     9,    10,    11,    -1,
      13,    -1,    -1,    -1,    -1,    -1,   527,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    -1,    57,    58,    59,    60,    -1,    62,
      63,    64,    65,    66,    -1,    -1,    69,    -1,    -1,    -1,
      73,    -1,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,   157,    -1,   159,   160,   161,   162,
     163,   164,   165,    -1,   167,   168,    -1,    -1,    -1,    -1,
     173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,    -1,    -1,    -1,    -1,   222,
     223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,    -1,    -1,    -1,    -1,    -1,    -1,   270,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   279,   280,   281,   282,
      -1,    -1,    -1,    -1,   287,    -1,    -1,    -1,   291,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   308,   309,   310,   311,    -1,
      -1,    -1,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,    -1,    -1,   329,   330,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   341,   342,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,    -1,    10,
      11,    -1,    13,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   439,    -1,   441,    -1,
     443,   444,    -1,    -1,    35,    36,    -1,    -1,   451,   452,
     453,   454,   455,   456,   457,   458,    -1,    -1,   461,   462,
     463,   464,   465,   466,   467,   468,    57,    -1,    -1,    -1,
      -1,    62,    63,    64,    -1,    -1,    -1,    -1,    69,    -1,
     483,   484,   485,    -1,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,   495,   496,   497,   498,    -1,   500,   501,    -1,
      -1,    -1,    -1,   506,   507,    -1,    -1,    -1,    -1,   512,
     513,   514,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   527,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   144,    -1,    -1,    -1,   148,   149,   150,
     151,   152,   153,   154,   155,    -1,   157,    -1,   159,   160,
     161,   162,   163,   164,   165,    -1,   167,   168,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,    -1,    -1,    -1,
      -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,    -1,   257,    -1,   259,   260,
     261,   262,   263,    -1,    -1,    -1,    -1,    -1,    -1,   270,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   279,   280,
     281,   282,    -1,    -1,    -1,    -1,   287,    -1,    -1,    -1,
     291,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   308,   309,   310,
     311,    -1,    -1,    -1,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     341,   342,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,
      -1,    10,    11,    -1,    13,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,    -1,
      -1,    -1,   443,   444,    -1,    -1,    35,    36,    -1,    -1,
      -1,    -1,   453,   454,   455,   456,   457,   458,    -1,    -1,
     461,   462,   463,   464,   465,   466,   467,   468,    57,    -1,
      -1,    -1,    -1,    62,    63,    64,    -1,    -1,    -1,    -1,
      69,    -1,    -1,    -1,   485,    -1,    75,    76,    -1,    -1,
      -1,    -1,    -1,    -1,   495,   496,   497,   498,    -1,   500,
     501,    -1,    -1,    -1,    -1,   506,   507,    -1,    -1,    -1,
      -1,   512,   513,   514,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   527,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   144,    -1,    -1,    -1,   148,
     149,   150,   151,   152,   153,   154,   155,    -1,   157,    -1,
     159,   160,   161,   162,   163,   164,   165,    -1,   167,   168,
      -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,    -1,
      -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,    -1,   257,    -1,
     259,   260,   261,   262,   263,    -1,    -1,    -1,    -1,    -1,
      -1,   270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     279,   280,   281,   282,    -1,    -1,    -1,    -1,   287,    -1,
      -1,    -1,   291,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   308,
     309,   310,   311,    -1,    -1,    -1,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   341,   342,   343,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       7,    -1,    -1,    10,    11,    -1,    13,   426,   427,   428,
     429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   443,   444,    -1,    -1,    35,    36,
      -1,    -1,    -1,    -1,   453,   454,   455,   456,   457,   458,
      -1,    -1,   461,   462,   463,   464,   465,   466,   467,   468,
      57,    -1,    -1,    -1,    -1,    62,    63,    64,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,   485,    -1,    75,    76,
      -1,    -1,    -1,    -1,    -1,    -1,   495,   496,   497,   498,
      -1,   500,   501,    -1,    -1,    -1,    -1,   506,   507,    -1,
      -1,    -1,    -1,   512,   513,   514,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   527,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,    -1,    -1,
      -1,   148,   149,   150,   151,   152,   153,   154,   155,    -1,
     157,    -1,   159,   160,   161,   162,   163,   164,   165,    -1,
     167,   168,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,    -1,    -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
     257,    -1,   259,   260,   261,   262,   263,    -1,    -1,    -1,
      -1,    -1,    -1,   270,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   279,   280,   281,   282,    -1,    -1,    -1,    -1,
     287,    -1,    -1,    -1,   291,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   308,   309,   310,   311,    -1,    -1,    -1,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   341,   342,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     7,    -1,    -1,    10,    11,    -1,    13,   426,
     427,   428,   429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   443,   444,    -1,    -1,
      35,    36,    -1,    -1,    -1,    -1,   453,   454,   455,   456,
     457,   458,    -1,    -1,   461,   462,   463,   464,   465,   466,
     467,   468,    57,    -1,    -1,    -1,    -1,    62,    63,    64,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,   485,    -1,
      75,    76,    -1,    -1,    -1,    -1,    -1,    -1,   495,   496,
     497,   498,    -1,   500,   501,    -1,    -1,    -1,    -1,   506,
     507,    -1,    -1,    -1,    -1,   512,   513,   514,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     527,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,
      -1,    -1,    -1,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,   157,    -1,   159,   160,   161,   162,   163,   164,
     165,    -1,   167,   168,    -1,    -1,    -1,    -1,   173,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,    -1,    -1,    -1,    -1,   222,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,    -1,   257,    -1,   259,   260,   261,   262,   263,    -1,
      -1,    -1,    -1,    -1,    -1,   270,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   279,   280,   281,   282,    -1,    -1,
      -1,    -1,   287,    -1,    -1,    -1,   291,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   308,   309,   310,   311,    -1,    -1,    -1,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,
       9,    10,    11,    -1,    13,    -1,   341,   342,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    57,    58,
      59,    60,    -1,    62,    63,    -1,    65,    66,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    -1,    75,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   426,   427,   428,   429,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   443,   444,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   453,   454,
     455,   456,   457,   458,    -1,    -1,   461,   462,   463,   464,
     465,   466,   467,   468,   143,   144,   145,   146,   147,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,
     485,     9,    10,    11,   163,    13,    -1,    -1,    -1,    -1,
     495,   496,   497,   498,   173,   500,   501,    -1,    -1,    -1,
      -1,   506,   507,    -1,    32,    -1,    -1,   512,   513,   514,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,     9,
      10,    11,   527,    13,    -1,    -1,    -1,    55,    -1,    57,
      58,    59,    60,    -1,    62,    63,    -1,    65,    66,    -1,
      -1,    -1,    32,    -1,   223,    73,    -1,    75,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    -1,    57,    58,    59,
      60,    -1,    62,    63,    -1,    65,    66,   256,    -1,   258,
      -1,    -1,    -1,    73,    -1,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,
     329,   330,    -1,   143,   144,   145,   146,   147,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   401,   402,    -1,    -1,    -1,    -1,   256,    -1,
     258,    -1,    -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,    -1,   441,    -1,    -1,    -1,   256,    -1,   258,    -1,
      -1,    -1,   451,   452,   453,   454,   455,   456,   457,   458,
      -1,    -1,   461,   462,   463,   464,   465,   466,   467,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   329,   330,    -1,   483,   484,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   329,
     330,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   527,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,    -1,   441,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   451,   452,   453,   454,   455,   456,   457,
     458,    -1,    -1,   461,   462,   463,   464,   465,   466,   467,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
      -1,   441,    -1,    -1,    -1,   483,   484,    -1,    -1,    -1,
      -1,   451,   452,   453,   454,   455,   456,   457,   458,    -1,
      -1,   461,   462,   463,   464,   465,   466,   467,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   483,   484,    -1,    -1,    -1,    -1,   527,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   527
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  Parser::yystos_[] =
  {
         0,     7,     9,    10,    11,    13,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    53,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    81,    82,    83,    84,    86,    87,
     143,   144,   145,   146,   147,   158,   163,   170,   171,   172,
     173,   208,   209,   223,   256,   258,   264,   265,   266,   267,
     268,   269,   271,   312,   313,   314,   327,   328,   329,   330,
     377,   401,   402,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   441,   442,   445,   451,   452,   453,   454,
     455,   456,   457,   458,   461,   462,   463,   464,   465,   466,
     467,   469,   474,   476,   477,   481,   482,   483,   484,   486,
     493,   494,   510,   515,   516,   518,   519,   520,   521,   522,
     523,   524,   525,   526,   527,   529,   530,   531,   532,   533,
     534,   537,   538,   539,   540,   544,   545,   546,   547,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   611,   612,
      10,    11,    13,    58,    59,    60,    62,    63,    65,    66,
      73,    75,    76,   163,   173,   453,   454,   455,   456,   457,
     458,   461,   462,   463,   464,   465,   466,   467,   554,   555,
     570,   609,    65,   555,   595,   555,   595,    61,   568,   569,
     570,   608,    13,    13,    13,   480,   570,   609,    53,   611,
     570,   547,   568,   608,   547,   568,   547,   570,    13,    13,
     547,   131,   132,   142,   131,   132,   142,   131,   132,   142,
     142,    19,    19,   122,   123,    13,   142,    19,   142,    13,
      13,   531,   611,    19,    19,    15,   121,    15,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    68,    70,    71,
      73,    74,    75,    76,   570,   612,   547,    13,    13,    13,
      13,    15,    13,    13,    15,    13,    15,    13,    19,    19,
      19,    19,    13,    13,    13,    15,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,   555,   595,   555,   595,   555,
     595,   555,   595,   555,   595,   555,   595,   555,   595,   555,
     595,   555,   595,   555,   595,   555,   595,   555,   595,   555,
     595,   611,   548,   549,   568,   547,   547,    13,    13,    13,
      70,   611,   611,    13,    13,    13,    13,    13,    13,     0,
       0,   531,   532,   533,   534,   537,   538,   539,   540,   531,
      10,    11,   138,   139,   555,   595,     7,     8,    12,    10,
      11,     5,     6,   136,   137,   138,   139,    17,     4,    18,
     134,    21,   135,    13,    15,    19,   121,   142,   140,     7,
     141,    10,    11,    19,   121,   121,   142,    19,    19,    19,
      19,    15,    15,    19,    19,    13,    19,    19,    14,    14,
      19,    14,   547,   568,   547,    19,   547,   547,   568,   568,
     568,   547,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   374,   405,   406,
     407,   408,   409,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   499,   517,   346,   348,   350,
     351,   358,   361,   362,   363,   364,   365,   366,   367,   368,
     399,   403,   408,   409,   419,   424,   425,   609,   609,   568,
     568,   608,    42,    43,   447,   448,   449,   450,   446,    10,
      11,    13,    17,    35,    36,    62,    64,    69,   144,   148,
     149,   150,   151,   152,   153,   154,   155,   157,   159,   160,
     161,   162,   163,   164,   165,   167,   168,   173,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   222,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   257,   259,   260,   261,   262,
     263,   270,   279,   280,   281,   282,   287,   291,   308,   309,
     310,   311,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   341,   342,   426,   427,   428,   429,
     443,   444,   453,   454,   455,   456,   457,   458,   461,   462,
     463,   464,   465,   466,   467,   468,   485,   495,   496,   497,
     498,   500,   501,   506,   507,   512,   513,   514,   542,   547,
     554,   568,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   609,   542,    41,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   407,    42,   239,   568,
     343,   568,    15,   568,   568,    10,    11,    13,    62,   144,
     163,   173,   453,   454,   455,   456,   457,   458,   461,   462,
     463,   464,   465,   466,   467,   554,   570,   589,   609,    62,
     568,   589,   589,   589,   589,   589,   589,   589,   570,   166,
     218,   219,   220,   221,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   220,   221,   220,   221,
     220,   221,   570,   570,   570,   589,   589,   570,   570,   570,
     570,   570,   570,   570,   570,    53,    53,   568,   568,   570,
     568,   570,   568,    10,    11,    13,    65,   453,   454,   455,
     456,   457,   458,   461,   462,   463,   464,   465,   466,   467,
     554,   608,   547,   589,   570,   142,   473,    54,   548,   531,
      75,   611,   612,   547,    53,   536,   535,   548,   568,   547,
      62,   570,   570,   570,   531,   545,   545,   547,   547,   555,
     555,   555,   556,   556,   558,   558,   558,   558,   559,   559,
     560,   561,   562,   563,   565,   564,   568,   568,    49,    50,
     156,   218,   236,   239,   240,   241,   242,   271,   272,   273,
     404,   405,   410,   423,   440,   611,   589,   568,   589,   555,
     595,   595,   556,   596,   556,   596,   236,   237,   238,   239,
     269,   277,   288,   292,   335,   337,   338,   339,   348,   349,
     354,   355,   356,   357,   369,   370,   371,   372,   373,   375,
     376,   378,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   508,   274,   275,
     276,   283,   284,   285,   286,   290,   331,   334,   335,   336,
     337,   339,   340,   343,   503,   504,   505,   509,   511,   609,
     610,   343,   589,    10,    11,    13,    35,    37,    64,    67,
      74,    85,    88,   343,   400,   431,   434,   446,   453,   454,
     455,   456,   457,   458,   461,   462,   463,   464,   465,   466,
     467,   547,   554,   568,   589,   590,   608,   609,   610,    79,
     568,   568,   568,    13,   553,    20,    14,    14,    14,    20,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    20,
     547,   568,   547,    13,    13,    13,   570,   574,   575,   575,
     569,   589,    58,    59,   570,   609,    13,   547,    13,    19,
      19,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    19,    13,    13,
      13,    13,    19,    13,    13,    13,    19,    19,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,   575,   575,   575,
     575,   575,   575,   575,   575,   575,   575,   575,   575,   575,
     575,    13,    13,    13,    13,    13,    13,    19,    13,    13,
      13,    13,    13,    14,    20,   575,    13,    15,   142,     4,
       7,     8,    10,    11,     5,     6,   136,   137,   138,   139,
      17,    18,   134,    21,   135,    19,    14,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,   547,
      16,    15,    16,   568,    14,    20,   569,   570,    19,    13,
      19,    19,    13,    14,    19,    20,    14,    16,    14,    14,
      16,    14,    16,    20,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    20,    14,    20,    14,
      16,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    14,    14,    20,    20,    14,    20,    14,    14,    20,
      14,   568,   541,   547,   550,   479,   531,    14,    14,    14,
      14,    13,    13,   531,    20,    14,    20,    20,    20,    20,
      22,    14,    20,    22,    23,    16,    13,    13,   547,    13,
      13,    13,    13,    13,    13,    13,    13,    13,   547,    13,
      13,   547,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,   547,    13,    13,    13,    13,    13,
      19,    15,    15,    13,    19,    13,    13,    15,    13,    13,
      13,    13,    20,    20,    19,    13,    16,    16,   547,    12,
     568,   568,   570,   568,   568,   568,   568,   568,   570,   568,
     568,    62,   570,    55,    62,   568,   568,   568,   568,   568,
     568,   568,   589,   568,    64,   568,    70,   568,   568,   610,
     568,   568,   568,   568,   568,   609,    64,   590,    64,    55,
     568,   568,   568,   568,   547,    58,    61,   547,    14,    14,
     547,   569,   570,   568,   344,   344,   345,   542,   589,   570,
     589,   589,   570,   570,   570,   570,   570,   589,   570,   570,
     570,   570,   570,    51,    52,   570,   570,   570,   570,    51,
     183,   218,   589,   589,   570,   218,   218,   570,   570,   570,
     570,   570,   570,   570,   570,   570,   589,   570,   570,   570,
     570,   570,   570,   570,   570,   570,   570,   570,   570,   570,
     589,   589,   589,   589,   589,   570,   570,   570,   570,   570,
     609,   609,   547,   547,   570,   570,   570,   570,   570,   570,
     570,   570,   570,   570,   570,   570,   570,   589,   570,   570,
     570,   570,   570,   570,   589,   589,   589,   589,   589,   570,
     589,   589,   502,   589,   589,   589,   589,   547,    17,    62,
     547,   568,   589,   589,    22,    62,   568,   570,   613,   588,
     575,   555,   575,   555,   575,   556,   576,   556,   576,   558,
     579,   558,   579,   558,   579,   558,   579,   558,   580,   558,
     580,   581,   583,   584,   586,   585,   289,   379,   380,   381,
     382,   531,   547,   547,   547,    58,    59,   547,    60,    59,
     568,    61,    61,    61,   547,   568,    70,   568,   568,   547,
     568,   568,   568,   568,   142,   568,   142,    16,    70,    14,
      19,   589,   568,    13,    13,    13,   570,   568,   570,   568,
     568,   568,   570,   570,   570,   570,   568,   568,   568,   568,
     568,   568,   568,   570,   568,   570,   570,   570,   169,   570,
     570,   169,   570,   169,   570,   570,   570,   568,   568,   568,
     568,   568,   568,   568,   568,   568,   568,   568,   568,   568,
     568,   568,   570,   589,    13,   568,   568,   568,   568,   568,
     568,   568,   570,   570,   570,   568,   568,   568,   547,   470,
      20,   548,   548,   487,   488,   489,   490,   491,   543,   543,
     568,   568,   547,   570,   570,   566,   568,   568,   568,   142,
     547,   570,   570,   570,   568,   570,   568,   570,   568,   568,
     568,   568,   568,   568,   568,   568,   568,   568,   568,   568,
     568,   589,   568,   568,   568,   568,   568,   568,   568,   568,
     570,   589,   568,   589,   568,   568,   570,   568,   568,   568,
     589,   570,   609,   609,   609,   589,   589,   589,   547,   589,
     570,   609,   570,   609,   609,   589,    14,   547,   589,   589,
     589,   589,   589,   278,   568,   568,   547,   398,   542,   547,
     568,    74,   568,   568,   547,   547,   547,   547,    20,   547,
     568,    14,    20,    20,    20,    20,    20,    14,    20,    14,
      20,    14,    14,    14,    20,    20,    20,    20,    20,    14,
      14,    20,    20,    20,    20,    14,    20,    14,    20,    14,
      20,    14,    14,    20,    20,    20,    20,    14,    19,    14,
      20,    14,    20,    20,    20,    14,    14,    14,    14,    14,
      20,    13,   574,    14,    20,    19,    20,    14,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    14,    20,    13,    13,    20,
      20,    20,    13,    13,    14,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    14,    14,    14,    20,    14,    20,
      20,    20,    20,    20,    14,    20,    20,    20,    20,    20,
      20,    20,    20,    14,    20,    20,    20,    20,    20,    20,
      14,    14,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    14,    14,    14,    14,    14,
      14,    14,    20,    20,    20,    14,    20,    20,    20,    20,
      20,    13,    14,    20,    14,    20,    20,    14,    14,    58,
      59,   570,   609,    14,    20,    16,    22,    16,    22,    13,
      13,    13,    13,    13,    14,    14,    14,    20,    20,    20,
      14,    20,    14,    20,    20,    20,    20,    20,    20,    20,
      14,    14,    20,    20,    14,    20,    20,    20,    14,   610,
      16,   589,    14,    13,    14,   589,   570,   570,    14,    20,
      14,    20,    14,    20,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    20,    14,    14,
      20,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    14,    20,    14,    20,    14,    14,    14,    14,    20,
      14,    14,    14,    14,    14,    20,    14,    14,   589,    20,
      20,    14,    20,    20,    20,    14,    20,    20,    20,    20,
      20,    20,    14,    20,   568,   547,   531,   531,    56,    56,
      56,    56,    56,    14,    20,    14,    20,    20,    14,    20,
      20,    14,    20,    23,    20,    14,   568,   589,    14,    14,
      20,    14,    14,    20,    14,    20,    14,    14,    14,    20,
      20,    20,    14,    20,    14,    14,    14,    14,    14,    20,
      14,    14,    20,    14,    20,    14,    20,    20,    20,    14,
      14,    14,    14,    14,    14,    14,    14,    20,    20,    14,
      14,    20,    14,    14,    14,    14,    20,    20,    20,    20,
      20,    20,    14,    20,    20,    20,    14,    20,    20,    20,
      20,    20,    14,    14,    20,    20,    20,    20,    20,    13,
      16,    16,    14,    14,    14,    16,    20,    14,    14,    20,
      14,   547,   570,   568,   568,   568,   568,   568,   568,   570,
     570,   568,   568,   568,   568,   568,   568,   568,   568,   568,
     568,   568,   568,   568,   568,   568,   570,   568,   589,   142,
      53,   568,   568,   589,    53,   570,   568,   568,   568,   568,
     568,   568,   568,   568,   568,   568,   568,   568,   568,   568,
     568,   570,   570,   589,   589,   570,   570,   570,   568,   568,
     568,   568,   568,   568,   568,   568,   568,   570,   570,   570,
     570,   570,   570,   570,   570,   568,   568,   568,   568,   589,
     589,   568,   568,   568,   568,   570,   547,   570,   570,   568,
     568,   568,   568,   568,   568,   568,   568,   568,   568,   568,
     568,   568,   568,   568,   568,   570,   568,   568,   570,   568,
     568,   589,    22,   568,   587,   568,   570,    14,    14,    14,
     547,   568,   547,   568,    70,   547,   547,   568,   547,   547,
     547,   547,   547,   568,   568,   568,   568,   568,   568,    14,
      14,    14,    20,   570,   568,   568,   568,   570,   568,   568,
     568,   568,    14,   568,   568,   568,   589,   568,   568,   568,
     568,   570,   570,   568,   568,   568,   471,   548,   548,   487,
     488,   489,   490,   491,   548,   568,   568,   570,   568,   568,
     568,   568,   568,   568,   568,   568,   568,   568,   568,   568,
     568,   568,   568,   568,   568,   568,   568,   568,   568,   568,
     568,   568,   568,   568,   568,   568,   568,   568,   568,   568,
     568,   568,   568,   568,   568,   568,   589,   589,   568,    74,
      20,    20,    53,    14,    20,    14,    20,    14,    20,    14,
      20,    14,    14,    14,    14,    20,    20,    14,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    14,    14,    14,
      20,   568,    14,    20,    20,    14,    14,    20,    20,    20,
      14,    14,    14,    14,    20,    14,    20,    20,    20,    20,
      20,    20,    20,    20,    14,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    14,
      20,    20,    20,    20,    20,    20,    14,    14,    20,    14,
      14,    14,    20,    20,    14,    14,    14,    14,    20,    14,
      14,    20,    20,    20,    14,    14,    14,    14,    14,    14,
      14,    14,    20,    20,    20,    20,    20,    14,    20,    20,
      14,    20,    20,    14,    14,    14,    20,    20,    14,    14,
      20,    20,    20,    20,    14,    14,    14,    14,    14,    14,
      14,    20,    14,    14,    14,    20,    14,    14,    14,   568,
      14,    20,    14,    14,    20,    20,    14,    20,    20,    14,
      20,    14,    20,    14,    20,    14,    20,    20,    20,    20,
      20,    20,    20,    20,    14,   568,   531,   531,    56,    56,
      56,    56,    56,   531,    14,    20,    20,    20,    14,    20,
      23,    14,    22,    20,    20,    20,    20,    20,    20,    20,
      14,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      14,    20,    20,    20,    20,    14,    14,    20,    14,    14,
      14,    14,    14,    20,    14,    20,    20,    20,    20,    20,
      20,    20,    20,   547,   547,    14,   568,   568,   568,   568,
     568,   568,   568,   568,   568,   568,   568,   568,   568,   568,
     568,   568,   570,   568,   569,   569,   570,    53,   570,   568,
     568,   568,   568,   568,   568,   568,   568,   568,   568,   568,
     570,   568,   570,   568,   568,   568,   568,   568,   568,   568,
     568,   568,   568,   568,   568,   568,   570,   570,   570,   570,
     570,   568,   568,   568,   589,   589,   568,   568,   568,   568,
     568,   568,   568,   568,   568,   568,   568,   568,   568,   568,
     568,   568,   568,   547,   568,    14,   568,   570,   568,   568,
     568,   589,   589,   589,   589,   568,   568,   568,   570,   570,
     568,   568,   548,   568,   570,   568,   568,   568,   568,   568,
     568,   568,   568,   568,   568,   568,   568,   568,   568,   568,
     568,   568,   568,   568,   568,   568,   568,   568,   568,   570,
     589,   568,   568,   568,   568,   589,   589,   568,   568,    14,
      14,    20,    20,    14,    20,    20,    14,    20,    20,    14,
      20,    20,    20,    14,    20,    20,    14,    20,    20,    14,
      14,    20,    20,    20,    20,    14,    20,    14,    20,    14,
      20,    14,    20,    20,    20,    20,    20,    14,    14,    14,
      20,    20,    20,    20,    20,    20,    14,    20,    20,    20,
      20,    20,    20,    20,    14,    20,    20,    20,    20,    20,
      20,    20,    14,    14,    14,    14,    20,    20,    14,    20,
      20,    20,    20,    20,    20,    14,    20,    22,    22,    20,
      14,    20,    14,    20,    14,    20,    14,    20,    14,    20,
      14,    14,    20,    14,    20,    20,    14,    20,    14,    20,
      20,    14,    14,   531,    20,    20,    20,    14,    14,    20,
      20,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    20,    20,    20,    20,    20,
      14,    14,    14,    20,    14,    20,    20,    20,    14,    14,
     568,   568,   568,   568,   568,   568,   568,   568,   568,   568,
     568,   569,   568,   569,    53,   568,   568,   568,   568,   568,
     568,   568,   568,   568,   568,   568,   568,   568,   568,   568,
     568,   568,   613,   568,   613,   568,   613,   568,   568,   568,
     568,   568,   568,   568,   568,   568,   570,   568,   568,   568,
     568,   568,   568,   568,   568,   568,   568,   568,   568,   568,
     568,   547,   568,   568,   568,   568,   568,   568,   568,   589,
     570,   568,   570,   568,   568,   568,   568,   568,   568,   568,
     568,   589,   568,   568,   568,    20,    14,    14,    20,    20,
      20,    14,    14,    14,    20,    14,    20,    20,    20,    14,
      14,    20,    20,    20,    14,    20,    14,    20,    20,    20,
      20,    20,    20,    14,    20,    20,    20,    20,    20,    20,
      20,    14,    20,    14,    14,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    14,    20,    20,    14,    14,    20,
      14,    14,    14,    20,    20,    20,    14,    16,    20,    14,
      14,    14,    14,    14,    20,    20,    14,    14,    20,    20,
      14,    20,    20,    20,    20,    22,    14,    14,    20,    20,
      14,    20,    20,    20,    20,    20,   568,   568,   568,   568,
     568,   568,   568,   547,   569,   568,   568,   568,   568,   568,
     568,   568,   568,   568,   568,   568,   568,   568,   568,   568,
     613,   613,   613,   613,   568,   568,   568,   570,   570,   570,
     570,   568,   568,   568,   568,   568,   568,   568,   568,   568,
     568,   568,   570,   568,   570,   568,   568,   568,   568,   568,
     589,   568,   568,   568,    14,    20,    20,    20,    20,    14,
      20,    20,    14,    14,    20,    14,    14,    14,    14,    14,
      14,    20,    14,    20,    14,    20,    14,    14,    20,    14,
      14,    14,    14,    20,    14,    14,    14,    14,    20,    20,
      14,    20,    14,    20,    14,    20,    22,    20,    14,    20,
      20,    20,    20,    20,    20,    14,    20,    20,    20,    14,
      20,    20,    20,    20,   568,   568,   568,   568,   547,   568,
     568,   568,   568,   568,   568,   568,   613,   568,   568,   568,
     568,   568,   568,   568,   568,   568,   570,   568,   570,   568,
     142,   568,   568,   568,   589,   568,   568,   568,    14,    14,
      20,    14,    14,    20,    20,    20,    14,    14,    14,    20,
      14,    20,    20,    14,    20,    20,    14,    14,    20,    20,
      14,    20,    20,    20,    20,   589,    20,    20,    14,    20,
      20,    14,    14,    20,    20,   568,   547,   568,   568,   568,
     568,   568,   568,   568,   589,   568,   589,   568,   568,   568,
     568,   568,   568,   568,   568,   568,    20,    14,    14,    14,
      14,    14,    20,    20,    20,    14,    14,    14,    20,    20,
      20,    14,    20,    20,    14,    14,    20,    14,    20,   568,
     568,   568,   568,   568,   568,   570,   568,   568,   568,   589,
      20,    20,    14,    20,    14,    20,    20,    14,    20,    14,
      20,   568,   568,   568,   568,   570,   568,   589,    20,    14,
      20,    20,    20,    14,    14,   568,   568,   568,   568,    20,
      20,    20,    14,   568,   568,   568,    20,    20,    20,   568,
     568,   568,    14,    20,    20,   568,   568,    20,    14,   568,
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
     775,   776,   777,   778,   779,   780,   781,   126
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  Parser::yyr1_[] =
  {
         0,   528,   529,   529,   530,   530,   530,   530,   530,   530,
     530,   530,   530,   530,   530,   530,   530,   530,   530,   530,
     531,   531,   532,   532,   532,   532,   533,   533,   535,   534,
     536,   534,   537,   538,   539,   539,   539,   539,   539,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   541,   541,   542,   542,   542,   542,
     542,   542,   542,   542,   542,   542,   542,   542,   542,   542,
     542,   542,   542,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   544,   544,   545,   545,   545,   545,
     545,   545,   545,   546,   546,   546,   547,   548,   549,   550,
     551,   551,   551,   551,   551,   551,   551,   551,   552,   552,
     552,   552,   552,   552,   552,   552,   552,   552,   552,   552,
     552,   552,   552,   552,   552,   552,   552,   552,   552,   552,
     552,   552,   552,   552,   552,   552,   552,   552,   552,   552,
     552,   552,   552,   552,   552,   552,   552,   552,   552,   552,
     552,   552,   552,   552,   552,   552,   552,   552,   552,   552,
     552,   552,   552,   552,   552,   552,   552,   552,   552,   552,
     552,   552,   552,   552,   552,   552,   552,   552,   552,   552,
     552,   552,   552,   553,   553,   553,   553,   553,   553,   553,
     553,   553,   553,   553,   553,   553,   553,   553,   553,   553,
     553,   554,   554,   555,   555,   556,   556,   556,   556,   557,
     557,   557,   558,   559,   559,   559,   559,   559,   560,   560,
     560,   560,   560,   561,   561,   562,   562,   563,   563,   564,
     564,   565,   565,   566,   566,   567,   568,   569,   569,   569,
     569,   569,   569,   569,   569,   569,   569,   569,   570,   570,
     571,   571,   571,   571,   571,   571,   571,   571,   571,   571,
     571,   571,   571,   571,   571,   571,   571,   571,   571,   571,
     571,   571,   571,   571,   571,   571,   571,   571,   571,   571,
     571,   571,   571,   571,   571,   571,   571,   571,   571,   571,
     571,   571,   571,   571,   571,   571,   571,   571,   571,   571,
     571,   571,   571,   571,   571,   571,   571,   571,   571,   571,
     571,   571,   571,   571,   571,   571,   571,   571,   571,   571,
     571,   571,   571,   571,   571,   571,   571,   571,   571,   571,
     571,   571,   571,   571,   571,   571,   571,   571,   571,   571,
     571,   571,   571,   571,   571,   571,   571,   571,   571,   571,
     571,   571,   571,   571,   571,   571,   571,   571,   571,   571,
     571,   571,   571,   571,   571,   571,   571,   571,   571,   571,
     571,   571,   571,   571,   571,   571,   571,   571,   571,   571,
     571,   571,   571,   571,   571,   571,   571,   571,   571,   571,
     571,   571,   571,   571,   571,   571,   571,   571,   572,   572,
     573,   574,   574,   574,   574,   574,   574,   574,   574,   574,
     574,   574,   574,   574,   574,   574,   574,   574,   574,   575,
     575,   576,   576,   576,   576,   576,   576,   577,   578,   578,
     578,   578,   578,   579,   580,   580,   580,   580,   580,   580,
     580,   580,   580,   581,   581,   581,   581,   581,   582,   582,
     583,   584,   584,   585,   585,   586,   586,   587,   587,   588,
     588,   589,   590,   590,   590,   590,   591,   591,   591,   592,
     592,   593,   594,   594,   594,   594,   594,   594,   594,   594,
     594,   594,   594,   594,   594,   594,   594,   594,   594,   594,
     595,   596,   596,   596,   596,   597,   597,   597,   597,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   609,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   611,   612,   612,   612,   612,   612,   612,   612,   612,
     612,   612,   612,   612,   612,   612,   612,   612,   612,   612,
     612,   612,   613,   613,   613,   613
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Parser::yyr2_[] =
  {
         0,     2,     0,     2,     1,     2,     2,     3,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     2,
       1,     1,     8,    10,     6,     2,     4,     6,     0,     8,
       0,     8,     4,     2,     3,     1,     2,     5,     2,     1,
       1,     1,     1,     1,     1,     4,     6,     6,     6,     6,
       3,     3,     6,     6,     3,     3,     3,     3,     6,     3,
       3,     3,     6,     6,     8,     6,     8,     3,     5,     3,
       5,     8,     8,     3,     1,     1,     1,     1,     8,     4,
       4,     1,     2,     2,     2,     1,     3,     3,     3,     6,
       6,    16,     2,     2,     3,     2,     2,     3,     3,     2,
       2,     3,     2,     6,     2,     2,     5,     2,     1,     1,
       2,     2,     4,     4,     2,     2,     2,     2,     1,     4,
       3,     2,     2,    10,     6,     3,     6,     6,     8,    28,
       8,     8,     3,     8,    12,     6,     6,    16,     8,    16,
      10,     6,    10,     8,    10,    14,     8,    12,     6,     8,
       6,     6,     6,    10,     6,    10,    10,    12,     6,     6,
      12,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     8,     3,     3,     3,     3,     3,     3,
      12,    16,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,    10,     6,    14,     6,     8,     6,     6,     8,
       6,    10,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     3,     3,     4,     3,     6,     6,     4,
       4,     6,    10,    10,    10,     6,     6,     6,     6,     6,
      10,     6,    10,     6,     6,     6,     3,     6,     6,    10,
      10,     6,     6,     6,     3,     3,     3,     3,     6,     6,
       3,     6,     6,     8,    10,     3,     6,     3,     4,    20,
       6,    10,     6,     3,     3,     6,     3,     6,     8,     6,
       6,     8,    16,     6,     3,     6,     8,     3,    12,    12,
      12,    10,     3,     3,     8,     8,    10,     8,    10,    12,
       6,     8,     8,    10,    16,    18,    12,     6,    18,    16,
      12,    10,    10,    10,     6,    10,     6,     6,     6,     8,
       1,     4,     4,     8,     4,    18,     4,     1,     1,     6,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     6,     8,     6,    10,     6,     8,     8,     8,
       8,     6,     3,     4,     1,     1,     1,     1,     1,     1,
      30,    24,     4,     8,     1,     3,     0,     1,     3,     1,
       3,     2,     4,     2,     4,     1,     3,     2,     4,     2,
       4,     1,     3,     0,     2,     2,     2,     2,     2,     4,
       4,     4,     4,     4,     1,     1,     1,     6,     6,     6,
       1,     3,     1,     1,     3,     3,     1,     3,     0,     0,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     4,
       6,     8,    10,    10,    10,     8,     6,     3,     3,     3,
       3,     3,     3,     6,     4,    10,     4,    10,     4,     4,
       4,     4,     4,     4,     7,     7,     7,     9,     7,     6,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     6,     8,    10,    12,    10,    12,     8,
       6,     8,     8,     8,     8,     6,     8,     8,     8,    12,
       6,     6,     6,     6,     4,     4,     4,     1,     6,     6,
       6,     3,     6,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     1,     1,     4,     1,     3,     3,     3,     1,
       3,     3,     1,     1,     3,     3,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     5,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     4,
       2,     4,    16,    14,    16,     4,     4,     4,     1,    10,
      12,     8,     1,     4,     6,     6,     6,     8,     8,     6,
       6,     8,     8,    10,    10,    12,    12,    10,     4,    10,
       4,     6,     4,     4,     4,    12,     4,    12,    12,    16,
      20,    10,    12,     4,     6,     6,     6,     4,     4,     6,
       4,     6,     6,     6,     4,    10,    16,    10,     8,    12,
      10,     8,    12,     8,    12,     8,    12,     3,     3,     8,
       8,     3,     6,    12,    12,    14,    12,    12,    16,     4,
       8,    10,    12,    10,    12,    10,    12,    12,    14,    12,
       8,    14,     4,     4,     4,     4,     3,     3,     3,     6,
       6,     6,     6,     8,    14,    12,    14,    12,     6,     8,
      10,    10,    12,     6,     6,     6,     6,     6,     6,     6,
       6,     8,    10,     4,     4,    10,    10,     4,     6,     6,
      12,    30,     8,     5,     6,     5,     5,     6,     6,     4,
       6,     4,     6,     4,     4,    18,     8,     6,     1,     3,
       1,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       4,     1,     3,     3,     3,     3,     3,     1,     1,     3,
       3,     3,     3,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       1,     1,     3,     1,     3,     1,     3,     1,     5,     1,
       3,     1,     1,     3,     8,     4,     6,     1,     4,     1,
       3,     1,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     1,     3,     3,     3,     1,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     6,     6,     8,     8,     4,     6,     6,
       6,     6,     3,     2,     4,     1,     4,     6,     1,     4,
       4,    10,     6,    16,    18,    10,    20,    14,     8,     4,
       6,     8,     8,    12,    16,    16,    18,    14,    14,    16,
      20,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,    11,     7,     1,     1
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
  "T_SetName", "T_GetName", "T_GetOutput", "T_GetDiffCoeff", "ASTRING",
  "ABLOCK", "NUMBER", "IDENTIFIER", "VAR_IMAGE", "VAR_FLOAT", "VAR_INT",
  "VAR_UCHAR", "VAR_STRING", "VAR_IMAGEDRAW", "VAR_SURFACE",
  "VAR_SURFDRAW", "VAR_MATRIX", "VAR_FILE", "VAR_C_FUNCTION",
  "VAR_C_PROCEDURE", "VAR_C_IMAGE_FUNCTION", "VAR_AMI_FUNCTION",
  "VAR_AMI_CLASS", "VAR_AMI_OBJECT", "VAR_PARAMWIN", "VAR_GLTRANSFORM",
  "VAR_ARRAY_SURFACE", "VAR_ARRAY_IMAGE", "T_del", "T_delvars",
  "T_Comments", "ENDOP", "T_global", "T_local", "T_global_new",
  "T_local_new", "T_context", "T_wait", "T_schedule", "T_ParamWin",
  "T_BeginPanel", "T_EndPanel", "T_BeginBoxPanel", "T_EndBoxPanel",
  "T_BeginBook", "T_EndBook", "T_AddPage", "T_AddFloat", "T_AddInt",
  "T_CreateWin", "T_Display", "T_AddButton", "T_AddBoolean", "T_AddEnum",
  "T_AddEnumChoice", "T_AddImageChoice", "T_AddString", "T_AddFilename",
  "T_AddLabel", "T_ShowSlider", "T_SetCallback", "T_SetDragCallback",
  "T_SetPositionProp", "T_BeginBox", "T_EndBox", "T_BeginHorizontal",
  "T_EndHorizontal", "T_redraw", "T_Enable", "T_EnableBox",
  "T_EnablePanel", "RIGHT_ASSIGN", "LEFT_ASSIGN", "ADD_ASSIGN",
  "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "AND_ASSIGN",
  "XOR_ASSIGN", "OR_ASSIGN", "RIGHT_OP", "INC_OP", "DEC_OP", "PTR_OP",
  "AND_OP", "OR_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "TRANSPOSE_OP",
  "POINTWISE_MULT", "ASSIGN_OP", "T_COUNT", "T_MAX", "T_argmax", "T_MIN",
  "T_MEDIAN", "OpImage", "FILTER", "NormGrad", "T_DiscNormGrad",
  "T_gradient", "SecDerGrad", "SecDerGrad2", "SubImage", "PutImage",
  "T_AutoCrop", "T_DiscSecDerGrad", "T_EDPdilate", "T_EDPerode",
  "T_EDPopen", "T_EDPclose", "AnisoGS", "AnisoSmoothGS", "T_vtkAnisoGS",
  "T_SetDistMap", "T_DiscMeanCurvature", "T_vtkMedian3D", "T_NULL",
  "T_InitTime", "T_TimeSpent", "T_EndTime", "T_LevelSetsCURV",
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
  "T_import_wii", "T_import_filters", "T_import_sys", "T_amiOFCorr2D",
  "T_amiOFVar2D", "'~'", "$accept", "start", "list_commands", "end_instr",
  "loop_inst", "cond_inst", "proc_decl", "$@1", "$@2", "class_decl",
  "object_decl", "func_inst", "command", "exprstringlist", "param_list",
  "param_list_decl", "primary_expr_string", "postfix_expr_string",
  "additive_expr_string", "expr_string", "instr_block", "begin_block",
  "end_block", "primary_expr", "postfix_expr", "unary_expr",
  "unary_operator", "cast_expr", "multiplicative_expr", "additive_expr",
  "shift_expr", "relational_expr", "equality_expr", "and_expr",
  "exclusive_or_expr", "inclusive_or_expr", "logical_and_expr",
  "logical_or_expr", "conditional_expr", "assignment_expr", "expr",
  "basic_type", "var_image", "image", "primary_image", "postfix_image",
  "unary_image", "cast_image", "multiplicative_image", "additive_image2",
  "additive_image", "shift_image", "relational_image", "equality_image",
  "and_image", "exclusive_or_image", "inclusive_or_image",
  "logical_and_image", "logical_or_image", "conditional_image",
  "assignment_image", "expr_image", "gltransform", "matrix",
  "primary_matrix", "postfix_matrix", "unary_matrix", "cast_matrix",
  "multiplicative_matrix", "additive_matrix", "shift_matrix",
  "relational_matrix", "equality_matrix", "and_matrix",
  "exclusive_or_matrix", "inclusive_or_matrix", "logical_and_matrix",
  "logical_or_matrix", "conditional_matrix", "assignment_matrix",
  "expr_matrix", "var_surface", "surface", "identifier", "variable",
  "image_extent", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Parser::rhs_number_type
  Parser::yyrhs_[] =
  {
       529,     0,    -1,    -1,   530,     0,    -1,   531,    -1,   530,
     531,    -1,   540,   531,    -1,   530,   540,   531,    -1,   532,
      -1,   530,   532,    -1,   533,    -1,   530,   533,    -1,   539,
      -1,   530,   539,    -1,   534,    -1,   530,   534,    -1,   537,
      -1,   530,   537,    -1,   538,    -1,   530,   538,    -1,    34,
      -1,    23,    -1,   469,   611,   142,   568,   470,   568,   548,
     531,    -1,   469,   611,   142,   568,   470,   568,   471,   568,
     548,   531,    -1,   469,   611,   473,   541,   548,   531,    -1,
     474,   548,    -1,   477,   568,   548,   531,    -1,   477,   568,
     548,   479,   548,   531,    -1,    -1,   493,   611,   535,    13,
     543,    14,   548,   531,    -1,    -1,   493,    70,   536,    13,
     543,    14,   548,   531,    -1,   494,   611,   548,   531,    -1,
      71,   611,    -1,   481,   547,   531,    -1,   481,    -1,   482,
     547,    -1,    70,    13,   542,    14,   531,    -1,    70,   531,
      -1,    33,    -1,   476,    -1,    81,    -1,    83,    -1,    84,
      -1,    82,    -1,    86,    13,   568,    14,    -1,    87,    13,
     568,    20,    70,    14,    -1,   611,   142,   343,    15,   568,
      16,    -1,   611,   121,   343,    15,   568,    16,    -1,   611,
     142,    35,    15,   568,    16,    -1,   611,   142,   589,    -1,
     611,   121,   589,    -1,   611,   142,    67,    13,   542,    14,
      -1,    76,    15,   568,    16,   142,   589,    -1,   611,   142,
     608,    -1,   611,   142,   590,    -1,    65,   142,   568,    -1,
      65,   142,   608,    -1,    75,    15,   568,    16,   142,   610,
      -1,   611,   142,    85,    -1,   611,   142,   610,    -1,   609,
     121,   610,    -1,    75,   121,   343,    15,   568,    16,    -1,
     611,   142,   434,    13,   568,    14,    -1,   611,   142,   434,
      13,   568,    14,    20,   547,    -1,   611,   142,   431,    13,
     568,    14,    -1,   611,   142,   431,    13,   568,    14,    20,
     547,    -1,   611,   142,   568,    -1,   611,   142,   568,    20,
     547,    -1,   611,   142,   547,    -1,   611,   142,   547,    20,
     547,    -1,   611,   142,   446,    13,   547,    20,    53,    14,
      -1,    66,   142,   446,    13,   547,    20,    53,    14,    -1,
      66,    19,   450,    -1,    24,    -1,    25,    -1,    26,    -1,
      27,    -1,    28,    13,   547,    20,   547,    20,   547,    14,
      -1,    29,    13,   568,    14,    -1,    30,    13,   547,    14,
      -1,    40,    -1,    38,   570,    -1,    41,   570,    -1,    38,
     609,    -1,   377,    -1,   570,   142,   589,    -1,   570,   121,
     589,    -1,   570,   142,   568,    -1,   570,    15,   568,    16,
     142,   589,    -1,   570,    15,   568,    16,   142,   568,    -1,
     570,    13,   568,    22,   568,    20,   568,    22,   568,    20,
     568,    22,   568,    14,   142,   589,    -1,    58,   131,    -1,
      58,   132,    -1,    58,   142,   568,    -1,    59,   131,    -1,
      59,   132,    -1,    59,   142,   568,    -1,    60,   142,   568,
      -1,    60,   131,    -1,    60,   132,    -1,    61,   142,   547,
      -1,    38,   480,    -1,   612,    19,    79,    13,   547,    14,
      -1,    77,   612,    -1,    78,   547,    -1,    77,    75,    15,
     568,    16,    -1,    47,   547,    -1,    48,    -1,    39,    -1,
      39,   611,    -1,    39,    53,    -1,    66,    19,    42,   547,
      -1,    66,    19,    43,   547,    -1,    42,   547,    -1,    43,
     547,    -1,    42,   608,    -1,    44,   547,    -1,   608,    -1,
      66,    19,    42,   568,    -1,    66,    19,   447,    -1,    42,
     568,    -1,    43,   568,    -1,    62,    19,   405,    13,   568,
      20,   568,    20,   568,    14,    -1,    62,    19,   406,    13,
     568,    14,    -1,    62,    19,   407,    -1,    62,    19,   408,
      13,   570,    14,    -1,    62,    19,   408,    13,    62,    14,
      -1,    62,    19,   411,    13,    62,    20,   570,    14,    -1,
      62,    19,   499,    13,   568,    20,   568,    20,   568,    20,
     568,    20,   568,    20,   568,    20,   568,    20,   568,    20,
     568,    20,   568,    20,   568,    20,   568,    14,    -1,    62,
      19,   409,    13,    55,    20,   570,    14,    -1,    62,    19,
     412,    13,   568,    20,   568,    14,    -1,    62,    19,   413,
      -1,    62,    19,   414,    13,   568,    20,   568,    14,    -1,
      62,    19,   415,    13,   568,    20,   568,    20,   568,    20,
     568,    14,    -1,    62,    19,   416,    13,   568,    14,    -1,
      62,    19,   417,    13,   568,    14,    -1,    62,    19,   418,
      13,   568,    20,   568,    20,   568,    20,   568,    20,   568,
      20,   568,    14,    -1,    62,    19,   419,    13,   568,    20,
     568,    14,    -1,    62,    19,   421,    13,   568,    20,   568,
      20,   568,    20,   568,    20,   568,    20,   568,    14,    -1,
      62,    19,   420,    13,   589,    20,   568,    20,   568,    14,
      -1,    62,    19,   422,    13,    64,    14,    -1,    62,    19,
     293,    13,   568,    20,   570,    20,   568,    14,    -1,    62,
      19,   293,    13,   570,    20,   568,    14,    -1,    62,    19,
     294,    13,   568,    20,   568,    20,   568,    14,    -1,    62,
      19,   294,    13,   568,    20,   568,    20,   568,    20,   568,
      20,   568,    14,    -1,    62,    19,   295,    13,   568,    20,
     568,    14,    -1,    62,    19,   296,    13,   568,    20,   568,
      20,   568,    20,   568,    14,    -1,    62,    19,   297,    13,
     568,    14,    -1,    62,    19,   298,    13,   568,    20,   568,
      14,    -1,    62,    19,   517,    13,    70,    14,    -1,    62,
      19,   374,    13,   570,    14,    -1,   570,    19,   423,    13,
     568,    14,    -1,   570,    19,   423,    13,   568,    20,   568,
      20,   568,    14,    -1,   570,    19,   404,    13,   568,    14,
      -1,   570,    19,   404,    13,   568,    20,   568,    20,   568,
      14,    -1,   570,    19,   405,    13,   568,    20,   568,    20,
     568,    14,    -1,   570,    19,   156,    13,   570,    20,   568,
      20,   568,    20,   568,    14,    -1,   570,    19,   156,    13,
     570,    14,    -1,   570,    19,    49,    13,   547,    14,    -1,
     163,    19,   218,    13,   570,    20,   568,    20,   568,    20,
     568,    14,    -1,   163,    19,   219,    13,   568,    14,    -1,
     163,    19,   166,    13,   568,    14,    -1,   163,    19,   224,
      13,   568,    14,    -1,   163,    19,   225,    13,   568,    14,
      -1,   163,    19,   228,    13,   570,    14,    -1,   163,    19,
     229,    13,   570,    14,    -1,   163,    19,   230,    13,   570,
      14,    -1,   163,    19,   231,    13,   570,    14,    -1,   163,
      19,   232,    13,   568,    14,    -1,   163,    19,   233,    13,
     568,    14,    -1,   163,    19,   234,    13,   568,    14,    -1,
     163,    19,   235,    13,   568,    14,    -1,   163,    19,   219,
      13,   568,    20,   568,    14,    -1,   163,    19,   220,    -1,
     163,    19,   221,    -1,   208,    19,   220,    -1,   208,    19,
     221,    -1,   209,    19,   220,    -1,   209,    19,   221,    -1,
     173,    19,   191,    13,   568,    20,   568,    20,   568,    20,
     568,    14,    -1,   173,    19,   191,    13,   568,    20,   568,
      20,   568,    20,   568,    20,   568,    20,   568,    14,    -1,
     173,    19,   175,    13,   568,    14,    -1,   173,    19,   176,
      13,   568,    14,    -1,   173,    19,   177,    13,   568,    14,
      -1,   173,    19,   190,    13,   568,    14,    -1,   173,    19,
     194,    13,   568,    14,    -1,   173,    19,   199,    13,   568,
      14,    -1,   173,    19,   200,    13,   568,    14,    -1,   173,
      19,   201,    13,   568,    14,    -1,   173,    19,   202,    13,
     568,    14,    -1,   173,    19,   197,    13,   568,    14,    -1,
     173,    19,   198,    13,   568,    20,   568,    20,   568,    14,
      -1,   173,    19,   203,    13,   568,    14,    -1,   173,    19,
     204,    13,   568,    20,   568,    20,   568,    20,   568,    20,
     568,    14,    -1,   173,    19,   192,    13,   568,    14,    -1,
     173,    19,   178,    13,   570,    20,   568,    14,    -1,   173,
      19,   179,    13,   568,    14,    -1,   173,    19,   180,    13,
     570,    14,    -1,   173,    19,   193,    13,   568,    20,   568,
      14,    -1,   173,    19,   182,    13,   570,    14,    -1,   173,
      19,   181,    13,   570,    20,   570,    20,   570,    14,    -1,
     173,    19,   184,    13,   570,    14,    -1,   173,    19,   185,
      13,   570,    14,    -1,   173,    19,   186,    13,   570,    14,
      -1,   173,    19,   189,    13,   570,    14,    -1,   173,    19,
     187,    13,   570,    14,    -1,   173,    19,   188,    13,   570,
      14,    -1,   173,    19,   184,    13,   169,    14,    -1,   173,
      19,   186,    13,   169,    14,    -1,   173,    19,   187,    13,
     169,    14,    -1,   173,    19,   195,    13,   568,    14,    -1,
     173,    19,   196,    13,   568,    14,    -1,   173,    19,   220,
      -1,   173,    19,   221,    -1,   570,    19,   239,   547,    -1,
     570,    19,   240,    -1,   570,    19,   241,    13,   570,    14,
      -1,   570,    19,   242,    13,   570,    14,    -1,   609,    19,
     239,   547,    -1,   609,    19,   292,   547,    -1,   609,    19,
     354,    13,   568,    14,    -1,   609,    19,   369,    13,   568,
      20,   568,    20,   568,    14,    -1,   609,    19,   370,    13,
     568,    20,   568,    20,   568,    14,    -1,   609,    19,   371,
      13,   568,    20,   568,    20,   568,    14,    -1,   609,    19,
     372,    13,   568,    14,    -1,   609,    19,   373,    13,   568,
      14,    -1,   609,    19,   375,    13,   568,    14,    -1,   609,
      19,   376,    13,   568,    14,    -1,   609,    19,   357,    13,
     568,    14,    -1,   609,    19,   355,    13,   568,    20,   568,
      20,   568,    14,    -1,   609,    19,   392,    13,   570,    14,
      -1,   609,    19,   356,    13,   589,    20,   568,    20,   568,
      14,    -1,   609,    19,   356,    13,   589,    14,    -1,   609,
      19,   378,    13,   570,    14,    -1,   609,    19,   385,    13,
     568,    14,    -1,   609,    19,   386,    -1,   609,    19,   269,
      13,   568,    14,    -1,   609,    19,   387,    13,   589,    14,
      -1,   609,    19,   390,    13,   568,    20,   568,    20,   568,
      14,    -1,   609,    19,   391,    13,   568,    20,   568,    20,
     568,    14,    -1,   609,    19,   393,    13,   568,    14,    -1,
     609,    19,   277,    13,   568,    14,    -1,   609,    19,   383,
      13,   589,    14,    -1,   609,    19,   384,    -1,   609,    19,
     338,    -1,   609,    19,   388,    -1,   609,    19,   389,    -1,
     609,    19,   337,    13,   568,    14,    -1,   609,    19,   339,
      13,   568,    14,    -1,   609,    19,   335,    -1,   609,    19,
     349,    13,   568,    14,    -1,   609,    19,   348,    13,   568,
      14,    -1,   609,    19,   348,    13,   568,    20,   568,    14,
      -1,   609,    19,   394,    13,   568,    20,   568,    20,   568,
      14,    -1,   609,    19,   395,    -1,   609,    19,   397,    13,
     568,    14,    -1,   609,    19,   396,    -1,   515,    13,   547,
      14,    -1,   516,    13,    62,    20,   568,    20,   568,    20,
     568,    20,   568,    20,   568,    20,   568,    20,   568,    20,
     568,    14,    -1,   609,    19,   508,    13,   589,    14,    -1,
      64,    19,   346,    13,   568,    20,   568,    20,   568,    14,
      -1,    64,    19,   350,    13,   610,    14,    -1,    64,   122,
     609,    -1,    64,   123,   609,    -1,    64,    19,   367,    13,
     609,    14,    -1,    64,    19,   368,    -1,    64,    19,   348,
      13,   568,    14,    -1,    64,    19,   348,    13,   568,    20,
     568,    14,    -1,    64,    19,   351,    13,   568,    14,    -1,
      64,    19,   408,    13,    64,    14,    -1,    64,    19,   409,
      13,    55,    20,   570,    14,    -1,    64,    19,   424,    13,
     568,    20,   589,    20,   568,    20,   568,    20,   568,    20,
     568,    14,    -1,    64,    19,   425,    13,   568,    14,    -1,
      64,    19,   403,    -1,    64,    19,   399,    13,   590,    14,
      -1,    64,    19,   399,    13,   590,    20,   568,    14,    -1,
      64,    19,   358,    -1,    64,    19,   361,    13,   568,    20,
     568,    20,   568,    20,   568,    14,    -1,    64,    19,   362,
      13,   568,    20,   568,    20,   568,    20,   568,    14,    -1,
      64,    19,   363,    13,   568,    20,   568,    20,   568,    20,
     568,    14,    -1,    64,    19,   364,    13,   568,    20,   568,
      20,   568,    14,    -1,    64,    19,   365,    -1,    64,    19,
     366,    -1,    64,    19,   419,    13,   568,    20,   568,    14,
      -1,   264,    13,   570,    20,   568,    20,   568,    14,    -1,
     264,    13,   570,    20,   568,    20,   568,    20,   589,    14,
      -1,   265,    13,   570,    20,   568,    20,   568,    14,    -1,
     265,    13,   570,    20,   568,    20,   568,    20,   589,    14,
      -1,   265,    13,   570,    20,   568,    20,   568,    20,   589,
      20,   568,    14,    -1,   266,    13,   570,    20,   568,    14,
      -1,   266,    13,   570,    20,   568,    20,   589,    14,    -1,
     266,    13,   570,    20,   568,    20,   568,    14,    -1,   266,
      13,   570,    20,   568,    20,   568,    20,   589,    14,    -1,
     268,    13,   570,    20,   568,    20,   568,    20,   568,    20,
     568,    20,   568,    20,   568,    14,    -1,   268,    13,   570,
      20,   568,    20,   568,    20,   568,    20,   568,    20,   568,
      20,   568,    20,   589,    14,    -1,   267,    13,   570,    20,
     568,    20,   568,    20,   589,    20,   568,    14,    -1,   269,
      13,   570,    20,   568,    14,    -1,   314,    13,    53,    20,
     570,    20,   570,    20,   570,    20,   570,    20,   570,    20,
     570,    20,   589,    14,    -1,   314,    13,    53,    20,   570,
      20,   570,    20,   570,    20,   570,    20,   570,    20,   570,
      14,    -1,   313,    13,    53,    20,   570,    20,   570,    20,
     570,    20,   589,    14,    -1,   313,    13,    53,    20,   570,
      20,   570,    20,   570,    14,    -1,   271,    13,   570,    20,
     568,    20,   568,    20,   568,    14,    -1,   570,    19,   271,
      13,   568,    20,   568,    20,   568,    14,    -1,   570,    19,
     271,    13,   570,    14,    -1,   570,    19,   272,    13,   568,
      20,   568,    20,   568,    14,    -1,   570,    19,   272,    13,
     570,    14,    -1,   570,    19,   273,    13,   568,    14,    -1,
     158,    13,   570,    20,   570,    14,    -1,   158,    13,   570,
      20,   570,    20,   570,    14,    -1,   568,    -1,   327,    13,
     568,    14,    -1,   328,    13,   568,    14,    -1,   442,    13,
     589,    20,   547,    20,   568,    14,    -1,   445,    13,   570,
      14,    -1,   312,    13,   570,    20,   570,    20,   568,    20,
     568,    20,   568,    20,   568,    20,   568,    20,   568,    14,
      -1,   486,    13,    53,    14,    -1,   170,    -1,   172,    -1,
     611,   142,    88,    13,   547,    14,    -1,    73,    19,    93,
      -1,    73,    19,    94,    -1,    73,    19,    90,    -1,    73,
      19,    92,    -1,    73,    19,   113,    -1,    73,    19,   114,
      -1,    73,    19,   115,    -1,    73,    19,    98,    -1,    73,
      19,    99,    -1,    73,    19,    41,    -1,    73,    19,   116,
      -1,    73,    19,   407,    -1,    73,    19,   407,    13,   568,
      14,    -1,    73,    19,   108,    13,   568,    20,   568,    14,
      -1,    73,    19,   109,    13,    70,    14,    -1,    73,    19,
     111,    13,   568,    20,   568,    20,   568,    14,    -1,    73,
      19,   110,    13,   568,    14,    -1,    73,    19,   110,    13,
     568,    20,   568,    14,    -1,    73,    19,   117,    13,   568,
      20,   568,    14,    -1,    73,    19,   118,    13,   568,    20,
     568,    14,    -1,    73,    19,   119,    13,   568,    20,   568,
      14,    -1,   518,    13,   570,    20,   547,    14,    -1,    74,
      19,    42,    -1,    74,    19,   239,   547,    -1,   519,    -1,
     520,    -1,   521,    -1,   522,    -1,   523,    -1,   524,    -1,
     525,    13,   570,    20,   570,    20,   570,    20,   570,    20,
     570,    20,   570,    20,   570,    20,   568,    20,   568,    20,
     568,    20,   568,    20,   568,    20,   568,    20,   568,    14,
      -1,   526,    13,   570,    20,   570,    20,   568,    20,   568,
      20,   568,    20,   568,    20,   568,    20,   568,    20,   570,
      20,   570,    20,   568,    14,    -1,    68,    13,   542,    14,
      -1,   510,    13,   568,    20,   568,    20,   568,    14,    -1,
     547,    -1,   541,    20,   547,    -1,    -1,   568,    -1,   542,
      20,   568,    -1,   547,    -1,   542,    20,   547,    -1,    17,
      58,    -1,   542,    20,    17,    58,    -1,    17,    59,    -1,
     542,    20,    17,    59,    -1,   589,    -1,   542,    20,   589,
      -1,    17,   570,    -1,   542,    20,    17,   570,    -1,    17,
     609,    -1,   542,    20,    17,   609,    -1,    62,    -1,   542,
      20,    62,    -1,    -1,   490,    56,    -1,   491,    56,    -1,
     487,    56,    -1,   488,    56,    -1,   489,    56,    -1,   543,
      20,   490,    56,    -1,   543,    20,   491,    56,    -1,   543,
      20,   487,    56,    -1,   543,    20,   488,    56,    -1,   543,
      20,   489,    56,    -1,    53,    -1,    61,    -1,   544,    -1,
      46,    13,   547,    20,   568,    14,    -1,    45,    13,   547,
      14,    12,   568,    -1,    45,    13,   547,    14,    12,   547,
      -1,   171,    -1,   570,    19,    50,    -1,    31,    -1,   545,
      -1,   546,    10,   545,    -1,   546,    11,   545,    -1,   546,
      -1,   549,    54,   550,    -1,    -1,    -1,    55,    -1,    32,
      -1,   451,    -1,   452,    -1,    58,    -1,    59,    -1,    60,
      -1,    13,   568,    14,    -1,   551,    -1,   570,    13,   568,
      14,    -1,   570,    13,   568,    20,   568,    14,    -1,   570,
      13,   568,    20,   568,    20,   568,    14,    -1,   570,    19,
     410,    13,   568,    20,   568,    20,   568,    14,    -1,   570,
      13,   568,    20,   568,    20,   568,    20,   568,    14,    -1,
     570,    13,   568,    20,   568,    20,   568,    23,   568,    14,
      -1,   570,    13,   568,    20,   568,    23,   568,    14,    -1,
     570,    13,   568,    23,   568,    14,    -1,   570,    19,   218,
      -1,   570,    19,   611,    -1,   570,    19,   236,    -1,   609,
      19,   236,    -1,   609,    19,   237,    -1,   609,    19,   238,
      -1,   223,    13,   570,    20,   570,    14,    -1,   256,    13,
     570,    14,    -1,   329,    13,   570,    20,   568,    20,   568,
      20,   568,    14,    -1,   330,    13,   570,    14,    -1,   330,
      13,   568,    20,   568,    20,   568,    20,   568,    14,    -1,
     143,    13,   589,    14,    -1,   258,    13,   589,    14,    -1,
     144,    13,   589,    14,    -1,   145,    13,   589,    14,    -1,
     146,    13,   589,    14,    -1,   147,    13,   589,    14,    -1,
     144,    15,   589,    16,    13,   589,    14,    -1,   146,    15,
     589,    16,    13,   570,    14,    -1,   147,    15,   589,    16,
      13,   570,    14,    -1,   147,    15,   589,    16,    13,   570,
      20,   568,    14,    -1,   258,    15,   589,    16,    13,   589,
      14,    -1,   258,    13,   570,    20,   589,    14,    -1,   441,
      13,   547,    14,    -1,    62,    19,   303,    -1,    62,    19,
     304,    -1,    62,    19,   301,    -1,    62,    19,   302,    -1,
      62,    19,   299,    -1,    62,    19,   300,    -1,    62,    19,
     305,    -1,    62,    19,   306,    -1,    62,    19,   307,    -1,
     163,    19,   226,    -1,   163,    19,   227,    -1,   173,    19,
     174,    -1,    65,    13,   568,    20,   568,    14,    -1,    65,
      13,   568,    20,   568,    14,   142,   568,    -1,    73,    19,
      96,    13,    58,    20,   568,    20,   568,    14,    -1,    73,
      19,    96,    13,    58,    20,   547,    20,   568,    20,   568,
      14,    -1,    73,    19,    97,    13,    59,    20,   568,    20,
     568,    14,    -1,    73,    19,    97,    13,    59,    20,   547,
      20,   568,    20,   568,    14,    -1,    73,    19,   100,    13,
     547,    20,    70,    14,    -1,    73,    19,   101,    13,    60,
      14,    -1,    73,    19,   101,    13,    60,    20,   547,    14,
      -1,    73,    19,   104,    13,    61,    20,   547,    14,    -1,
      73,    19,   102,    13,    59,    20,   568,    14,    -1,    73,
      19,   102,    13,    59,    20,   547,    14,    -1,    73,    19,
     102,    13,    59,    14,    -1,    73,    19,   103,    13,   568,
      20,   547,    14,    -1,    73,    19,   105,    13,    61,    20,
     547,    14,    -1,    73,    19,   107,    13,   547,    20,   547,
      14,    -1,    73,    19,   106,    13,    61,    20,   547,    20,
     547,    20,   547,    14,    -1,    73,    19,   112,    13,   547,
      14,    -1,    73,    19,    95,    13,   547,    14,    -1,    73,
      19,    89,    13,   547,    14,    -1,    73,    19,    91,    13,
     547,    14,    -1,   483,    13,   611,    14,    -1,   483,    13,
     612,    14,    -1,   484,    13,   547,    14,    -1,   569,    -1,
      66,    19,   448,    13,   547,    14,    -1,    66,    19,   449,
      13,    58,    14,    -1,    66,    19,   449,    13,    61,    14,
      -1,   609,    19,   288,    -1,   144,    13,   568,    20,   568,
      14,    -1,   552,    -1,   554,   555,    -1,     9,   555,    -1,
      11,   555,    -1,    10,   555,    -1,   453,   555,    -1,   454,
     555,    -1,   464,   555,    -1,   465,   555,    -1,   466,   555,
      -1,   467,   555,    -1,   455,   555,    -1,   456,   555,    -1,
     457,   555,    -1,   458,   555,    -1,   461,   555,    -1,   463,
     555,    -1,   462,   555,    -1,     7,    -1,   527,    -1,   553,
      -1,    13,   569,    14,   553,    -1,   555,    -1,   556,     7,
     555,    -1,   556,     8,   555,    -1,   556,    12,   555,    -1,
     556,    -1,   557,    10,   556,    -1,   557,    11,   556,    -1,
     557,    -1,   558,    -1,   559,     6,   558,    -1,   559,     5,
     558,    -1,   559,   136,   558,    -1,   559,   137,   558,    -1,
     559,    -1,   560,   138,   559,    -1,   560,   139,   559,    -1,
     547,   138,   547,    -1,   547,   139,   547,    -1,   560,    -1,
     561,    17,   560,    -1,   561,    -1,   562,     4,   561,    -1,
     562,    -1,   563,    18,   562,    -1,   563,    -1,   564,   134,
     563,    -1,   564,    -1,   565,   135,   564,    -1,   565,    -1,
     565,    21,   565,    22,   566,    -1,   566,    -1,   567,    -1,
     430,    -1,   431,    -1,   432,    -1,   433,    -1,   434,    -1,
     435,    -1,   436,    -1,   437,    -1,   438,    -1,   439,    -1,
     570,    19,   440,    -1,    57,    -1,    76,    15,   568,    16,
      -1,    35,   547,    -1,    35,    13,   547,    14,    -1,    36,
      13,   568,    20,   568,    20,   569,    20,   568,    20,   547,
      20,   568,    20,   568,    14,    -1,    36,    13,   568,    20,
     568,    20,   568,    20,   569,    20,   568,    20,   547,    14,
      -1,    36,    13,   568,    20,   568,    20,   568,    20,   569,
      20,   568,    20,   568,    20,   547,    14,    -1,   308,    13,
     547,    14,    -1,   309,    13,   547,    14,    -1,    69,    13,
     542,    14,    -1,    35,    -1,    35,    13,   569,    20,   568,
      20,   568,    20,   568,    14,    -1,    35,    13,   569,    20,
     568,    20,   568,    20,   568,    20,   568,    14,    -1,    35,
      13,   569,    20,   568,    20,   570,    14,    -1,   570,    -1,
     570,    15,   568,    16,    -1,   259,    13,   589,    20,   568,
      14,    -1,   260,    13,   589,    20,   568,    14,    -1,   261,
      13,   589,    20,   568,    14,    -1,   262,    13,   589,    20,
     589,    20,   568,    14,    -1,   263,    13,   589,    20,   589,
      20,   568,    14,    -1,   144,    13,   589,    20,   589,    14,
      -1,   148,    13,   570,    20,    53,    14,    -1,   148,    13,
     570,    20,    53,    20,   569,    14,    -1,   148,    13,   570,
      20,   570,    20,    53,    14,    -1,   148,    13,   570,    20,
     570,    20,    53,    20,   569,    14,    -1,   148,    13,   570,
      20,   570,    20,   570,    20,    53,    14,    -1,   148,    13,
     570,    20,   570,    20,   570,    20,    53,    20,   569,    14,
      -1,   149,    13,   589,    20,   568,    20,   568,    20,   568,
      20,   568,    14,    -1,   501,    19,   502,    13,   570,    20,
     568,    20,   568,    14,    -1,   341,    13,   570,    14,    -1,
     168,    13,   570,    20,   568,    20,   568,    20,   568,    14,
      -1,   342,    13,   570,    14,    -1,   243,    13,   589,    20,
     568,    14,    -1,   244,    13,   570,    14,    -1,   245,    13,
     570,    14,    -1,   246,    13,   570,    14,    -1,   247,    13,
     570,    20,   570,    20,   568,    20,   568,    20,   568,    14,
      -1,   248,    13,   570,    14,    -1,   249,    13,   570,    20,
     570,    20,   570,    20,   568,    20,   570,    14,    -1,   250,
      13,   570,    20,   570,    20,   570,    20,   568,    20,   570,
      14,    -1,   251,    13,   570,    20,   570,    20,   570,    20,
     568,    20,   570,    20,   568,    20,   568,    14,    -1,   252,
      13,   570,    20,   570,    20,   570,    20,   568,    20,   570,
      20,   568,    20,   568,    20,   568,    20,   568,    14,    -1,
     253,    13,   570,    20,   570,    20,   570,    20,   570,    14,
      -1,   253,    13,   570,    20,   570,    20,   570,    20,   570,
      20,   568,    14,    -1,   254,    13,   570,    14,    -1,   254,
      13,   570,    20,   570,    14,    -1,   255,    13,   570,    20,
     570,    14,    -1,   150,    13,   589,    20,   568,    14,    -1,
     151,    13,   570,    14,    -1,   167,    13,   570,    14,    -1,
     152,    13,   570,    20,   568,    14,    -1,   270,    13,   570,
      14,    -1,   153,    13,   570,    20,   568,    14,    -1,   154,
      13,   570,    20,   568,    14,    -1,   157,    13,   589,    20,
     568,    14,    -1,   570,    15,   613,    16,    -1,   570,    15,
      22,    20,    22,    20,   568,    22,   568,    16,    -1,   155,
      13,   570,    20,   568,    20,   568,    20,   568,    20,   568,
      20,   568,    20,   568,    14,    -1,   159,    13,   570,    20,
     568,    20,   568,    20,   568,    14,    -1,   159,    13,   570,
      20,   568,    20,   568,    14,    -1,   159,    13,   570,    20,
     568,    20,   568,    20,   568,    20,   568,    14,    -1,   160,
      13,   570,    20,   568,    20,   568,    20,   568,    14,    -1,
     160,    13,   570,    20,   568,    20,   568,    14,    -1,   160,
      13,   570,    20,   568,    20,   568,    20,   568,    20,   568,
      14,    -1,   161,    13,   570,    20,   568,    20,   568,    14,
      -1,   161,    13,   570,    20,   568,    20,   568,    20,   568,
      20,   568,    14,    -1,   162,    13,   570,    20,   568,    20,
     568,    14,    -1,   162,    13,   570,    20,   568,    20,   568,
      20,   568,    20,   568,    14,    -1,   163,    19,    51,    -1,
     163,    19,    52,    -1,   173,    19,   218,    13,   570,    20,
     568,    14,    -1,   173,    19,   218,    13,   570,    20,   570,
      14,    -1,   173,    19,    51,    -1,   173,    19,   183,    13,
     570,    14,    -1,   163,    13,   570,    20,   568,    20,   568,
      20,   568,    20,   568,    14,    -1,   207,    13,   570,    20,
     570,    20,   568,    20,   568,    20,   568,    14,    -1,   165,
      13,   570,    20,   568,    20,   568,    20,   568,    20,   568,
      20,   568,    14,    -1,   164,    13,   570,    20,   568,    20,
     568,    20,   568,    20,   568,    14,    -1,   208,    19,   218,
      13,   570,    20,   568,    20,   568,    20,   568,    14,    -1,
     209,    19,   218,    13,   570,    20,   568,    20,   568,    20,
     568,    20,   568,    20,   568,    14,    -1,   210,    13,   570,
      14,    -1,   211,    13,   570,    20,   568,    20,   568,    14,
      -1,   211,    13,   570,    20,   568,    20,   568,    20,   613,
      14,    -1,   211,    13,   570,    20,   568,    20,   568,    20,
     568,    20,   613,    14,    -1,   212,    13,   570,    20,   568,
      20,   568,    20,   613,    14,    -1,   212,    13,   570,    20,
     568,    20,   568,    20,   568,    20,   613,    14,    -1,   213,
      13,   570,    20,   568,    20,   568,    20,   613,    14,    -1,
     214,    13,   570,    20,   568,    20,   568,    20,   568,    20,
     613,    14,    -1,   215,    13,   570,    20,   568,    20,   568,
      20,   568,    20,   613,    14,    -1,   216,    13,   570,    20,
     568,    20,   568,    20,   568,    20,   568,    20,   613,    14,
      -1,   217,    13,   570,    20,   568,    20,   568,    20,   568,
      20,   568,    14,    -1,   222,    13,   570,    20,   568,    20,
     568,    14,    -1,   257,    13,   570,    20,   568,    20,   568,
      20,   568,    20,   568,    20,   568,    14,    -1,   426,    13,
     570,    14,    -1,   427,    13,   570,    14,    -1,   428,    13,
     570,    14,    -1,   429,    13,   570,    14,    -1,    64,    19,
     344,    -1,    64,    19,   345,    -1,    62,    19,   344,    -1,
     279,    13,   570,    20,   568,    14,    -1,   280,    13,   570,
      20,   568,    14,    -1,   281,    13,   570,    20,   568,    14,
      -1,   282,    13,   570,    20,   568,    14,    -1,   205,    13,
     589,    20,   589,    20,   568,    14,    -1,   206,    13,   589,
      20,   589,    20,   568,    20,   568,    20,   568,    20,   568,
      14,    -1,   205,    13,   589,    20,   589,    20,   568,    20,
     568,    20,   568,    14,    -1,   205,    13,   589,    20,   589,
      20,   568,    20,   568,    20,   568,    20,   568,    14,    -1,
     205,    13,   589,    20,   589,    20,   570,    20,   568,    20,
     568,    14,    -1,   310,    13,   570,    20,   570,    14,    -1,
     311,    13,   570,    20,   570,    20,   589,    14,    -1,   315,
      13,   570,    20,   568,    20,   568,    20,   568,    14,    -1,
     316,    13,   570,    20,   568,    20,   568,    20,   568,    14,
      -1,   316,    13,   570,    20,   568,    20,   568,    20,   568,
      20,   568,    14,    -1,   317,    13,   570,    20,   568,    14,
      -1,   318,    13,   570,    20,   568,    14,    -1,   319,    13,
     570,    20,   568,    14,    -1,   320,    13,   570,    20,   568,
      14,    -1,   321,    13,   570,    20,   568,    14,    -1,   322,
      13,   570,    20,   568,    14,    -1,   323,    13,   570,    20,
     568,    14,    -1,   324,    13,   570,    20,   568,    14,    -1,
     324,    13,   570,    20,   568,    20,   568,    14,    -1,   325,
      13,   570,    20,   568,    20,   568,    20,   568,    14,    -1,
     326,    13,   589,    14,    -1,   570,    13,   589,    14,    -1,
     443,    13,   589,    20,   568,    20,   568,    20,   568,    14,
      -1,   444,    13,   589,    20,   568,    20,   568,    20,   568,
      14,    -1,   495,    13,   589,    14,    -1,   495,    13,   589,
      20,   568,    14,    -1,   498,    13,   589,    20,   568,    14,
      -1,   496,    13,   589,    20,   568,    20,   568,    20,   568,
      20,   568,    14,    -1,   497,    13,   570,    20,   570,    20,
     568,    20,   568,    20,   568,    20,   568,    20,   568,    20,
     568,    20,   568,    20,   568,    20,   568,    20,   568,    20,
     568,    20,   568,    14,    -1,   500,    13,   589,    20,   568,
      20,   568,    14,    -1,   609,    19,   380,    13,    14,    -1,
     609,    19,   289,    13,   568,    14,    -1,   609,    19,   381,
      13,    14,    -1,   609,    19,   382,    13,    14,    -1,   609,
      19,   379,    13,   570,    14,    -1,   506,    13,   589,    20,
     568,    14,    -1,   506,    13,   589,    14,    -1,   507,    13,
     589,    20,   568,    14,    -1,   507,    13,   589,    14,    -1,
     512,    13,   589,    20,   589,    14,    -1,   513,    13,   589,
      14,    -1,   514,    13,   547,    14,    -1,   485,    13,   589,
      20,   568,    20,   568,    20,   568,    20,   568,    20,   568,
      20,   568,    20,   568,    14,    -1,   287,    13,   609,    20,
     570,    20,   589,    14,    -1,   291,    13,   609,    20,   547,
      14,    -1,   571,    -1,    13,   589,    14,    -1,   572,    -1,
     573,    -1,   554,   575,    -1,    11,   575,    -1,    10,   575,
      -1,   453,   575,    -1,   454,   575,    -1,   464,   575,    -1,
     465,   575,    -1,   466,   575,    -1,   467,   575,    -1,   455,
     575,    -1,   456,   575,    -1,   457,   575,    -1,   458,   575,
      -1,   461,   575,    -1,   463,   575,    -1,   462,   575,    -1,
     468,   575,    -1,   574,    -1,    13,   569,    14,   574,    -1,
     575,    -1,   576,     7,   555,    -1,   576,     8,   555,    -1,
     576,     7,   575,    -1,   576,     8,   575,    -1,   576,     4,
     575,    -1,   576,    -1,   577,    -1,   578,    10,   556,    -1,
     578,    11,   556,    -1,   578,    10,   576,    -1,   578,    11,
     576,    -1,   578,    -1,   579,    -1,   580,     6,   579,    -1,
     580,     5,   579,    -1,   580,   136,   579,    -1,   580,   137,
     579,    -1,   580,     6,   558,    -1,   580,     5,   558,    -1,
     580,   136,   558,    -1,   580,   137,   558,    -1,   580,    -1,
     581,   138,   580,    -1,   581,   139,   580,    -1,   581,   138,
     558,    -1,   581,   139,   558,    -1,   581,    -1,   582,    17,
     581,    -1,   582,    -1,   583,    -1,   584,    18,   583,    -1,
     584,    -1,   585,   134,   584,    -1,   585,    -1,   586,   135,
     585,    -1,   586,    -1,   586,    21,   586,    22,   587,    -1,
     587,    -1,   574,   142,   588,    -1,   588,    -1,    74,    -1,
      64,    19,   398,    -1,   400,    13,    74,    20,    74,    20,
     568,    14,    -1,    37,    13,   547,    14,    -1,   401,    13,
     568,    20,   568,    14,    -1,    65,    -1,   402,    13,   608,
      14,    -1,   591,    -1,    13,   608,    14,    -1,   592,    -1,
     593,    -1,   554,   595,    -1,    11,   595,    -1,    10,   595,
      -1,   595,   140,    -1,   453,   595,    -1,   454,   595,    -1,
     464,   595,    -1,   465,   595,    -1,   466,   595,    -1,   467,
     595,    -1,   455,   595,    -1,   456,   595,    -1,   457,   595,
      -1,   458,   595,    -1,   461,   595,    -1,   463,   595,    -1,
     462,   595,    -1,   594,    -1,   595,    -1,   596,     7,   555,
      -1,   596,   141,   595,    -1,   596,     7,   595,    -1,   596,
      -1,   597,    10,   556,    -1,   597,    11,   556,    -1,   597,
      10,   596,    -1,   597,    11,   596,    -1,   597,    -1,   598,
      -1,   599,    -1,   600,    -1,   601,    -1,   602,    -1,   603,
      -1,   604,    -1,   605,    -1,   606,    -1,   607,    -1,    63,
      -1,    75,    15,   568,    16,    -1,   331,    13,   589,    20,
     568,    14,    -1,   334,    13,   570,    20,   568,    14,    -1,
     331,    13,   589,    20,   568,    20,   570,    14,    -1,   340,
      13,   589,    20,   568,    20,   589,    14,    -1,   335,    13,
     609,    14,    -1,   335,    13,   609,    20,   568,    14,    -1,
     336,    13,   570,    20,   568,    14,    -1,   337,    13,   609,
      20,   568,    14,    -1,   339,    13,   609,    20,   568,    14,
      -1,   343,    13,    14,    -1,   343,   547,    -1,   343,    13,
     547,    14,    -1,   343,    -1,   290,    13,   547,    14,    -1,
     290,    13,   547,    20,   568,    14,    -1,   609,    -1,   274,
      13,   570,    14,    -1,   275,    13,   609,    14,    -1,   275,
      13,   609,    20,   568,    20,   568,    20,   568,    14,    -1,
     276,    13,   609,    20,   568,    14,    -1,   283,    13,   609,
      20,   568,    20,   568,    20,   568,    20,   568,    20,   568,
      20,   568,    14,    -1,   284,    13,   589,    20,   568,    20,
     568,    20,   568,    20,   568,    20,   568,    20,   568,    20,
     568,    14,    -1,   285,    13,   589,    20,   568,    20,   568,
      20,   568,    14,    -1,   286,    13,   589,    20,   568,    20,
     568,    20,   568,    20,   568,    20,   568,    20,   568,    20,
     568,    20,   568,    14,    -1,   286,    13,   589,    20,   568,
      20,   568,    20,   568,    20,   568,    20,   568,    14,    -1,
     609,    19,   278,    13,   568,    20,   568,    14,    -1,   503,
      13,   589,    14,    -1,   503,    13,   589,    20,   568,    14,
      -1,   503,    13,   589,    20,   568,    20,   568,    14,    -1,
     505,    13,   589,    20,   568,    20,   568,    14,    -1,   504,
      13,   589,    20,   568,    20,   568,    20,   589,    20,   589,
      14,    -1,   504,    13,   589,    20,   568,    20,   568,    20,
     589,    20,   589,    20,   589,    20,   568,    14,    -1,   509,
      13,   589,    20,   589,    20,   589,    20,   568,    20,   568,
      20,   568,    20,   568,    14,    -1,   509,    13,   589,    20,
     589,    20,   589,    20,   568,    20,   568,    20,   568,    20,
     568,    20,   568,    14,    -1,   509,    13,   589,    20,   589,
      20,   589,    20,   568,    20,   568,    20,   568,    14,    -1,
     509,    13,   589,    20,   568,    20,   568,    20,   568,    20,
     568,    20,   568,    14,    -1,   511,    13,   589,    20,   589,
      20,   589,    20,   568,    20,   568,    20,   568,    20,   568,
      14,    -1,   511,    13,   589,    20,   589,    20,   589,    20,
     568,    20,   568,    20,   568,    20,   568,    20,   589,    20,
     589,    14,    -1,    56,    -1,    59,    -1,    58,    -1,    60,
      -1,   570,    -1,    62,    -1,    63,    -1,    64,    -1,    66,
      -1,    67,    -1,    68,    -1,    69,    -1,    70,    -1,    71,
      -1,    72,    -1,    61,    -1,    65,    -1,    74,    -1,    73,
      -1,    75,    -1,    76,    -1,   568,    22,   568,    20,   568,
      22,   568,    20,   568,    22,   568,    -1,   568,    22,   568,
      20,   568,    22,   568,    -1,   570,    -1,    62,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  Parser::yyprhs_[] =
  {
         0,     0,     3,     4,     7,     9,    12,    15,    19,    21,
      24,    26,    29,    31,    34,    36,    39,    41,    44,    46,
      49,    51,    53,    62,    73,    80,    83,    88,    95,    96,
     105,   106,   115,   120,   123,   127,   129,   132,   138,   141,
     143,   145,   147,   149,   151,   153,   158,   165,   172,   179,
     186,   190,   194,   201,   208,   212,   216,   220,   224,   231,
     235,   239,   243,   250,   257,   266,   273,   282,   286,   292,
     296,   302,   311,   320,   324,   326,   328,   330,   332,   341,
     346,   351,   353,   356,   359,   362,   364,   368,   372,   376,
     383,   390,   407,   410,   413,   417,   420,   423,   427,   431,
     434,   437,   441,   444,   451,   454,   457,   463,   466,   468,
     470,   473,   476,   481,   486,   489,   492,   495,   498,   500,
     505,   509,   512,   515,   526,   533,   537,   544,   551,   560,
     589,   598,   607,   611,   620,   633,   640,   647,   664,   673,
     690,   701,   708,   719,   728,   739,   754,   763,   776,   783,
     792,   799,   806,   813,   824,   831,   842,   853,   866,   873,
     880,   893,   900,   907,   914,   921,   928,   935,   942,   949,
     956,   963,   970,   977,   986,   990,   994,   998,  1002,  1006,
    1010,  1023,  1040,  1047,  1054,  1061,  1068,  1075,  1082,  1089,
    1096,  1103,  1110,  1121,  1128,  1143,  1150,  1159,  1166,  1173,
    1182,  1189,  1200,  1207,  1214,  1221,  1228,  1235,  1242,  1249,
    1256,  1263,  1270,  1277,  1281,  1285,  1290,  1294,  1301,  1308,
    1313,  1318,  1325,  1336,  1347,  1358,  1365,  1372,  1379,  1386,
    1393,  1404,  1411,  1422,  1429,  1436,  1443,  1447,  1454,  1461,
    1472,  1483,  1490,  1497,  1504,  1508,  1512,  1516,  1520,  1527,
    1534,  1538,  1545,  1552,  1561,  1572,  1576,  1583,  1587,  1592,
    1613,  1620,  1631,  1638,  1642,  1646,  1653,  1657,  1664,  1673,
    1680,  1687,  1696,  1713,  1720,  1724,  1731,  1740,  1744,  1757,
    1770,  1783,  1794,  1798,  1802,  1811,  1820,  1831,  1840,  1851,
    1864,  1871,  1880,  1889,  1900,  1917,  1936,  1949,  1956,  1975,
    1992,  2005,  2016,  2027,  2038,  2045,  2056,  2063,  2070,  2077,
    2086,  2088,  2093,  2098,  2107,  2112,  2131,  2136,  2138,  2140,
    2147,  2151,  2155,  2159,  2163,  2167,  2171,  2175,  2179,  2183,
    2187,  2191,  2195,  2202,  2211,  2218,  2229,  2236,  2245,  2254,
    2263,  2272,  2279,  2283,  2288,  2290,  2292,  2294,  2296,  2298,
    2300,  2331,  2356,  2361,  2370,  2372,  2376,  2377,  2379,  2383,
    2385,  2389,  2392,  2397,  2400,  2405,  2407,  2411,  2414,  2419,
    2422,  2427,  2429,  2433,  2434,  2437,  2440,  2443,  2446,  2449,
    2454,  2459,  2464,  2469,  2474,  2476,  2478,  2480,  2487,  2494,
    2501,  2503,  2507,  2509,  2511,  2515,  2519,  2521,  2525,  2526,
    2527,  2529,  2531,  2533,  2535,  2537,  2539,  2541,  2545,  2547,
    2552,  2559,  2568,  2579,  2590,  2601,  2610,  2617,  2621,  2625,
    2629,  2633,  2637,  2641,  2648,  2653,  2664,  2669,  2680,  2685,
    2690,  2695,  2700,  2705,  2710,  2718,  2726,  2734,  2744,  2752,
    2759,  2764,  2768,  2772,  2776,  2780,  2784,  2788,  2792,  2796,
    2800,  2804,  2808,  2812,  2819,  2828,  2839,  2852,  2863,  2876,
    2885,  2892,  2901,  2910,  2919,  2928,  2935,  2944,  2953,  2962,
    2975,  2982,  2989,  2996,  3003,  3008,  3013,  3018,  3020,  3027,
    3034,  3041,  3045,  3052,  3054,  3057,  3060,  3063,  3066,  3069,
    3072,  3075,  3078,  3081,  3084,  3087,  3090,  3093,  3096,  3099,
    3102,  3105,  3107,  3109,  3111,  3116,  3118,  3122,  3126,  3130,
    3132,  3136,  3140,  3142,  3144,  3148,  3152,  3156,  3160,  3162,
    3166,  3170,  3174,  3178,  3180,  3184,  3186,  3190,  3192,  3196,
    3198,  3202,  3204,  3208,  3210,  3216,  3218,  3220,  3222,  3224,
    3226,  3228,  3230,  3232,  3234,  3236,  3238,  3240,  3244,  3246,
    3251,  3254,  3259,  3276,  3291,  3308,  3313,  3318,  3323,  3325,
    3336,  3349,  3358,  3360,  3365,  3372,  3379,  3386,  3395,  3404,
    3411,  3418,  3427,  3436,  3447,  3458,  3471,  3484,  3495,  3500,
    3511,  3516,  3523,  3528,  3533,  3538,  3551,  3556,  3569,  3582,
    3599,  3620,  3631,  3644,  3649,  3656,  3663,  3670,  3675,  3680,
    3687,  3692,  3699,  3706,  3713,  3718,  3729,  3746,  3757,  3766,
    3779,  3790,  3799,  3812,  3821,  3834,  3843,  3856,  3860,  3864,
    3873,  3882,  3886,  3893,  3906,  3919,  3934,  3947,  3960,  3977,
    3982,  3991,  4002,  4015,  4026,  4039,  4050,  4063,  4076,  4091,
    4104,  4113,  4128,  4133,  4138,  4143,  4148,  4152,  4156,  4160,
    4167,  4174,  4181,  4188,  4197,  4212,  4225,  4240,  4253,  4260,
    4269,  4280,  4291,  4304,  4311,  4318,  4325,  4332,  4339,  4346,
    4353,  4360,  4369,  4380,  4385,  4390,  4401,  4412,  4417,  4424,
    4431,  4444,  4475,  4484,  4490,  4497,  4503,  4509,  4516,  4523,
    4528,  4535,  4540,  4547,  4552,  4557,  4576,  4585,  4592,  4594,
    4598,  4600,  4602,  4605,  4608,  4611,  4614,  4617,  4620,  4623,
    4626,  4629,  4632,  4635,  4638,  4641,  4644,  4647,  4650,  4653,
    4655,  4660,  4662,  4666,  4670,  4674,  4678,  4682,  4684,  4686,
    4690,  4694,  4698,  4702,  4704,  4706,  4710,  4714,  4718,  4722,
    4726,  4730,  4734,  4738,  4740,  4744,  4748,  4752,  4756,  4758,
    4762,  4764,  4766,  4770,  4772,  4776,  4778,  4782,  4784,  4790,
    4792,  4796,  4798,  4800,  4804,  4813,  4818,  4825,  4827,  4832,
    4834,  4838,  4840,  4842,  4845,  4848,  4851,  4854,  4857,  4860,
    4863,  4866,  4869,  4872,  4875,  4878,  4881,  4884,  4887,  4890,
    4893,  4895,  4897,  4901,  4905,  4909,  4911,  4915,  4919,  4923,
    4927,  4929,  4931,  4933,  4935,  4937,  4939,  4941,  4943,  4945,
    4947,  4949,  4951,  4956,  4963,  4970,  4979,  4988,  4993,  5000,
    5007,  5014,  5021,  5025,  5028,  5033,  5035,  5040,  5047,  5049,
    5054,  5059,  5070,  5077,  5094,  5113,  5124,  5145,  5160,  5169,
    5174,  5181,  5190,  5199,  5212,  5229,  5246,  5265,  5280,  5295,
    5312,  5333,  5335,  5337,  5339,  5341,  5343,  5345,  5347,  5349,
    5351,  5353,  5355,  5357,  5359,  5361,  5363,  5365,  5367,  5369,
    5371,  5373,  5375,  5387,  5395,  5397
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   957,   957,   958,   962,   962,   963,   964,   965,   965,
     966,   966,   967,   967,   968,   968,   969,   969,   970,   970,
     973,   974,   979,   998,  1021,  1056,  1078,  1093,  1114,  1113,
    1143,  1142,  1183,  1202,  1220,  1227,  1262,  1268,  1284,  1297,
    1305,  1309,  1323,  1337,  1351,  1361,  1377,  1397,  1409,  1420,
    1431,  1443,  1454,  1470,  1492,  1504,  1515,  1520,  1530,  1553,
    1562,  1574,  1592,  1614,  1627,  1646,  1659,  1678,  1691,  1710,
    1724,  1744,  1777,  1794,  1799,  1803,  1807,  1812,  1816,  1831,
    1841,  1852,  1855,  1893,  1913,  1944,  1961,  1973,  2013,  2026,
    2061,  2091,  2111,  2115,  2119,  2123,  2127,  2131,  2135,  2139,
    2143,  2147,  2152,  2156,  2167,  2180,  2190,  2199,  2210,  2218,
    2230,  2479,  2533,  2541,  2549,  2558,  2568,  2574,  2585,  2591,
    2598,  2604,  2614,  2624,  2640,  2652,  2662,  2710,  2725,  2746,
    2777,  2792,  2799,  2806,  2824,  2847,  2852,  2857,  2870,  2881,
    2890,  2900,  2908,  2925,  2941,  2958,  2978,  2993,  3011,  3024,
    3038,  3047,  3061,  3072,  3085,  3103,  3125,  3150,  3180,  3212,
    3217,  3235,  3240,  3245,  3250,  3255,  3260,  3274,  3289,  3306,
    3320,  3340,  3345,  3350,  3357,  3366,  3374,  3379,  3386,  3391,
    3396,  3416,  3440,  3445,  3450,  3455,  3460,  3465,  3470,  3475,
    3480,  3485,  3490,  3495,  3500,  3505,  3510,  3515,  3520,  3533,
    3538,  3543,  3551,  3556,  3561,  3566,  3571,  3576,  3581,  3586,
    3591,  3596,  3601,  3606,  3611,  3615,  3642,  3655,  3660,  3664,
    3670,  3683,  3689,  3695,  3701,  3708,  3715,  3722,  3731,  3742,
    3757,  3772,  3780,  3787,  3794,  3800,  3804,  3808,  3845,  3851,
    3858,  3865,  3876,  3884,  3901,  3911,  3916,  3923,  3930,  3938,
    3946,  3965,  3981,  3998,  4015,  4020,  4025,  4030,  4035,  4043,
    4144,  4178,  4185,  4193,  4199,  4206,  4216,  4225,  4232,  4239,
    4249,  4256,  4270,  4284,  4292,  4297,  4305,  4313,  4324,  4336,
    4348,  4360,  4366,  4375,  4384,  4397,  4404,  4415,  4437,  4463,
    4491,  4501,  4514,  4524,  4546,  4575,  4592,  4607,  4614,  4636,
    4655,  4673,  4687,  4692,  4697,  4706,  4711,  4720,  4734,  4741,
    4748,  4750,  4767,  4783,  4817,  4830,  4874,  4879,  4884,  4890,
    4907,  4913,  4919,  4925,  4932,  4938,  4944,  4950,  4956,  4971,
    4982,  4988,  5002,  5016,  5033,  5040,  5061,  5079,  5098,  5118,
    5138,  5158,  5165,  5170,  5176,  5181,  5186,  5191,  5196,  5201,
    5206,  5241,  5268,  5275,  5297,  5305,  5322,  5326,  5333,  5340,
    5348,  5356,  5365,  5372,  5379,  5386,  5393,  5400,  5407,  5414,
    5421,  5428,  5435,  5445,  5450,  5459,  5466,  5473,  5480,  5487,
    5494,  5501,  5508,  5515,  5523,  5528,  5543,  5549,  5563,  5579,
    5595,  5608,  5612,  5622,  5623,  5633,  5641,  5644,  5655,  5656,
    5659,  5660,  5668,  5676,  5685,  5689,  5693,  5697,  5705,  5706,
    5721,  5737,  5751,  5766,  5783,  5799,  5813,  5826,  5847,  5907,
    5928,  5947,  5954,  5962,  5967,  5972,  6000,  6006,  6017,  6036,
    6055,  6074,  6093,  6112,  6131,  6154,  6176,  6199,  6206,  6230,
    6253,  6261,  6271,  6281,  6291,  6301,  6311,  6321,  6335,  6352,
    6368,  6373,  6378,  6382,  6389,  6397,  6432,  6470,  6487,  6507,
    6519,  6536,  6556,  6589,  6608,  6630,  6646,  6664,  6688,  6709,
    6737,  6751,  6761,  6775,  6790,  6798,  6806,  6818,  6822,  6837,
    6844,  6854,  6866,  6879,  6880,  6881,  6882,  6883,  6884,  6885,
    6886,  6887,  6888,  6889,  6897,  6898,  6899,  6900,  6901,  6902,
    6903,  6908,  6909,  6913,  6915,  6931,  6932,  6933,  6934,  6938,
    6939,  6940,  6944,  6949,  6950,  6951,  6952,  6953,  6957,  6958,
    6959,  6960,  6961,  6965,  6966,  6974,  6975,  6979,  6983,  6990,
    6994,  7001,  7005,  7012,  7013,  7020,  7024,  7030,  7035,  7039,
    7043,  7047,  7051,  7055,  7059,  7063,  7067,  7071,  7079,  7084,
    7101,  7107,  7113,  7171,  7225,  7281,  7302,  7323,  7337,  7366,
    7374,  7393,  7419,  7432,  7510,  7577,  7585,  7593,  7603,  7613,
    7643,  7661,  7681,  7699,  7719,  7737,  7756,  7796,  7811,  7825,
    7841,  7864,  7878,  7892,  7906,  7920,  7955,  7969,  7990,  8011,
    8052,  8098,  8115,  8134,  8148,  8162,  8176,  8195,  8210,  8225,
    8242,  8263,  8280,  8296,  8308,  8337,  8357,  8402,  8414,  8425,
    8438,  8450,  8461,  8487,  8514,  8546,  8563,  8581,  8594,  8607,
    8627,  8650,  8664,  8679,  8713,  8750,  8785,  8818,  8835,  8852,
    8866,  8887,  8910,  8934,  8959,  8984,  9006,  9028,  9052,  9095,
    9119,  9151,  9165,  9202,  9239,  9276,  9311,  9316,  9325,  9330,
    9341,  9351,  9361,  9370,  9391,  9421,  9447,  9476,  9509,  9520,
    9536,  9546,  9556,  9571,  9585,  9599,  9612,  9625,  9637,  9649,
    9661,  9672,  9685,  9712,  9745,  9857,  9881,  9923,  9935,  9944,
    9953,  9976, 10001, 10014, 10024, 10061, 10079, 10097, 10107, 10117,
   10125, 10133, 10141, 10166, 10186, 10194, 10228, 10251, 10271, 10271,
   10273, 10275, 10276, 10277, 10278, 10279, 10280, 10281, 10282, 10283,
   10284, 10285, 10286, 10287, 10288, 10289, 10290, 10291, 10292, 10306,
   10307, 10329, 10330, 10336, 10338, 10339, 10340, 10343, 10348, 10349,
   10350, 10351, 10352, 10355, 10359, 10360, 10361, 10362, 10363, 10364,
   10365, 10366, 10367, 10371, 10372, 10373, 10374, 10375, 10379, 10380,
   10385, 10389, 10390, 10394, 10395, 10399, 10400, 10404, 10405, 10409,
   10410, 10413, 10417, 10427, 10440, 10451, 10468, 10475, 10485, 10500,
   10500, 10502, 10504, 10505, 10506, 10507, 10508, 10517, 10518, 10519,
   10520, 10521, 10522, 10523, 10524, 10525, 10526, 10527, 10528, 10529,
   10533, 10535, 10536, 10537, 10538, 10548, 10549, 10550, 10551, 10552,
   10555, 10559, 10563, 10567, 10572, 10576, 10580, 10584, 10588, 10592,
   10595, 10600, 10605, 10622, 10633, 10643, 10663, 10697, 10706, 10715,
   10724, 10733, 10741, 10747, 10753, 10759, 10785, 10799, 10815, 10825,
   10843, 10871, 10898, 10913, 10936, 10970, 11002, 11049, 11090, 11114,
   11124, 11147, 11159, 11172, 11209, 11252, 11300, 11352, 11395, 11423,
   11456, 11499, 11503, 11504, 11505, 11506, 11510, 11511, 11512, 11513,
   11514, 11515, 11516, 11517, 11518, 11519, 11520, 11521, 11522, 11523,
   11524, 11525, 11530, 11538, 11545, 11561
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
       2,     2,     2,     2,     2,     2,   527,     2,     2,     2,
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
     525,   526
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 16277;
  const int Parser::yynnts_ = 86;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 389;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 528;

  const unsigned int Parser::yyuser_token_number_max_ = 781;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // yyip

/* Line 1054 of lalr1.cc  */
#line 20403 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.tab.cpp"


/* Line 1056 of lalr1.cc  */
#line 11581 "/home/karl/projects/Sourceforge/amilab/branches/release-2.0.4/src/Language/improcess_bison.ypp"

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
  CB_ParamWin(&f);

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





