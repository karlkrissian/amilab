
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
#line 941 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"


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
#line 934 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 590 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 57: /* "IDENTIFIER" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 599 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 543: /* "primary_expr_string" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 608 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 544: /* "postfix_expr_string" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 617 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 545: /* "additive_expr_string" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 626 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 546: /* "expr_string" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 635 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 547: /* "instr_block" */

/* Line 480 of lalr1.cc  */
#line 936 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ablock); };

/* Line 480 of lalr1.cc  */
#line 644 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 610: /* "identifier" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 653 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 612: /* "image_extent" */

/* Line 480 of lalr1.cc  */
#line 937 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 980 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 999 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1022 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1056 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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


      //          printf(" block = %s \n",$7);
          int res;
      //driver.yyiplineno = $2->GetStartingLine();

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
#line 1085 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 27:

/* Line 678 of lalr1.cc  */
#line 1100 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 28:

/* Line 678 of lalr1.cc  */
#line 1122 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_driver.procedure_declaration = true;
    }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 1127 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1151 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      // allow overriding current functions
      GB_driver.procedure_declaration = true;
    }
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 1157 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1193 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1211 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1233 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       //driver.res_print($2);
       driver.parse_script((yysemantic_stack_[(3) - (2)].astring));
       delete [] (yysemantic_stack_[(3) - (2)].astring);
     }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 1240 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 36:

/* Line 678 of lalr1.cc  */
#line 1275 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      string_ptr inputstring( new std::string((yysemantic_stack_[(2) - (2)].astring)));
      driver.parse_string( *inputstring,
                          "'eval string' command");
     }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 1281 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        Variable*       var   = (yysemantic_stack_[(5) - (1)].variable);
        ParamList::ptr  param((yysemantic_stack_[(5) - (3)].paramlist));

        driver.yyip_call_function(var,param);


        }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 1290 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable*    var   = (yysemantic_stack_[(2) - (1)].variable);

          // Call the function
          driver.yyip_call_function(var);
        }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 1299 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1307 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 41:

/* Line 678 of lalr1.cc  */
#line 1318 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1332 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1346 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1360 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1370 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1386 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1406 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Creates a new variable that is a reference to an existing one.
          Parameters:
            - new variable name;
            - existing variable name.
        **/
            IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (1)].ident));
            Vars.AddVarPtr((yysemantic_stack_[(4) - (4)].variable)->Type(),ident,(yysemantic_stack_[(4) - (4)].variable)->Pointer());
          }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1419 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1431 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 50:

/* Line 678 of lalr1.cc  */
#line 1442 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 51:

/* Line 678 of lalr1.cc  */
#line 1453 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 52:

/* Line 678 of lalr1.cc  */
#line 1465 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 53:

/* Line 678 of lalr1.cc  */
#line 1476 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 54:

/* Line 678 of lalr1.cc  */
#line 1496 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 55:

/* Line 678 of lalr1.cc  */
#line 1518 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 56:

/* Line 678 of lalr1.cc  */
#line 1530 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 57:

/* Line 678 of lalr1.cc  */
#line 1541 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr m1 = *((FloatMatrix::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer()));
          (*m1) = (yysemantic_stack_[(3) - (3)].adouble);
       }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 1546 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr m1 = *((FloatMatrix::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer()));
          FloatMatrix* m2 = driver.matrix_stack.GetLastMatrix();
          (*m1) = m2;
          printf("delete m2\n");
          delete m2;
          printf("delete m2 end\n");
       }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 1556 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 60:

/* Line 678 of lalr1.cc  */
#line 1579 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variables* contextptr = new Variables();
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
          contextptr->SetName(ident->GetName());

          Vars.AddVar(type_context,ident,(void*)contextptr);
        }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1588 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 62:

/* Line 678 of lalr1.cc  */
#line 1600 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 63:

/* Line 678 of lalr1.cc  */
#line 1618 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 64:

/* Line 678 of lalr1.cc  */
#line 1640 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 65:

/* Line 678 of lalr1.cc  */
#line 1653 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 66:

/* Line 678 of lalr1.cc  */
#line 1672 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 67:

/* Line 678 of lalr1.cc  */
#line 1685 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 68:

/* Line 678 of lalr1.cc  */
#line 1704 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 69:

/* Line 678 of lalr1.cc  */
#line 1717 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 70:

/* Line 678 of lalr1.cc  */
#line 1736 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 71:

/* Line 678 of lalr1.cc  */
#line 1750 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 72:

/* Line 678 of lalr1.cc  */
#line 1770 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 73:

/* Line 678 of lalr1.cc  */
#line 1803 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 74:

/* Line 678 of lalr1.cc  */
#line 1820 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
            rewind(file.get());
        }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1825 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 1;
        }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1829 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 0;
        }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 1833 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 1;
      verbose = 1;
    }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 1838 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 0;
    }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 1842 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 80:

/* Line 678 of lalr1.cc  */
#line 1857 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 81:

/* Line 678 of lalr1.cc  */
#line 1867 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 82:

/* Line 678 of lalr1.cc  */
#line 1877 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GB_main_wxFrame->Close(true);
        }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1881 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 84:

/* Line 678 of lalr1.cc  */
#line 1931 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 85:

/* Line 678 of lalr1.cc  */
#line 1951 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 86:

/* Line 678 of lalr1.cc  */
#line 1996 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage::ptr i1 = *(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          InrImage::ptr i2 = InrImage::ptr(driver.im_stack.GetLastImage());

          if (i2.get()) {
            // copy option
            if (!((*i1)=(*i2))) driver.err_print(" Error in images assignement\n");
          } else {
            if (driver.err_print("Error\n")==wxID_YES) YYABORT;
          }
        }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 2008 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage::ptr i1 = *(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          InrImage::ptr i2 = InrImage::ptr(driver.im_stack.GetLastImage());

          if (i2.get()) {
            // copy option
            (*i1)+=(*i2);
          } else {
            driver.err_print("Error\n");
          }
        }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 2020 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 89:

/* Line 678 of lalr1.cc  */
#line 2060 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 90:

/* Line 678 of lalr1.cc  */
#line 2073 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 91:

/* Line 678 of lalr1.cc  */
#line 2108 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 92:

/* Line 678 of lalr1.cc  */
#line 2138 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 93:

/* Line 678 of lalr1.cc  */
#line 2158 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(float_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))++;
        }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 2162 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(float_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))--;
        }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 2166 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          *(*(float_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer()) = (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 2170 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(int_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))++;
        }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 2174 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(int_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))--;
        }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 2178 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          *(*(int_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer()) = (int) (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 2182 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           *(*(uchar_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer()) = (unsigned char) (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 2186 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (*(*(uchar_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))++;
        }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 2190 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (*(*(uchar_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))--;
        }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 2194 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          string_ptr newname( new std::string((yysemantic_stack_[(3) - (3)].astring)));
          (yysemantic_stack_[(3) - (1)].variable)->SetString(newname);
        }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 2199 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Vars.display();
        }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 2203 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 105:

/* Line 678 of lalr1.cc  */
#line 2214 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 106:

/* Line 678 of lalr1.cc  */
#line 2227 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 107:

/* Line 678 of lalr1.cc  */
#line 2237 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          VarArray::ptr array = *(VarArray::ptr*) ((yysemantic_stack_[(5) - (2)].variable)->Pointer());;
          int  i = (int) (yysemantic_stack_[(5) - (4)].adouble);

          if (array->GetVar(i).Pointer()!=NULL) {
            array->GetVar(i).FreeMemory();
          }
      }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 2246 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 109:

/* Line 678 of lalr1.cc  */
#line 2257 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description:
        Calls system 'ls' command (for unix systems)
      **/
         std::system("ls");
           }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 2265 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 111:

/* Line 678 of lalr1.cc  */
#line 2277 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 112:

/* Line 678 of lalr1.cc  */
#line 2526 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 113:

/* Line 678 of lalr1.cc  */
#line 2536 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 114:

/* Line 678 of lalr1.cc  */
#line 2546 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 115:

/* Line 678 of lalr1.cc  */
#line 2556 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 116:

/* Line 678 of lalr1.cc  */
#line 2610 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(4) - (1)].variable)->Pointer());
          string_ptr text( new std::string((yysemantic_stack_[(4) - (4)].astring)));

          fprintf(file.get(),"%s",text->c_str());
          fflush(file.get());
        }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 2618 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(4) - (1)].variable)->Pointer());
          string_ptr text( new std::string((yysemantic_stack_[(4) - (4)].astring)));

          fprintf(file.get(),"%s\n",text->c_str());
          fflush(file.get());
        }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 2626 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
          Description:
            Print a string
          **/
          driver.res_print((yysemantic_stack_[(2) - (2)].astring));
          delete [] (yysemantic_stack_[(2) - (2)].astring);
        }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 2635 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 120:

/* Line 678 of lalr1.cc  */
#line 2645 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=driver.matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
      }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 2651 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 122:

/* Line 678 of lalr1.cc  */
#line 2662 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=driver.matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
          }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 2668 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(4) - (1)].variable)->Pointer());

          fprintf(file.get(),"%5.10f",(yysemantic_stack_[(4) - (4)].adouble));
          fflush(file.get());
        }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 2675 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            printf("Files are not close anymore: delete the variable instead \n");
          //FILE_ptr file = *(FILE_ptr*) ($1->Pointer());
          //fclose(file.get());
        }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 2681 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 126:

/* Line 678 of lalr1.cc  */
#line 2691 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 127:

/* Line 678 of lalr1.cc  */
#line 2701 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 128:

/* Line 678 of lalr1.cc  */
#line 2717 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 129:

/* Line 678 of lalr1.cc  */
#line 2729 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          DessinImageParametres* param;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
          param = draw->GetParam();
          param->_MAJ.MAJCoupes();
          draw->Paint();
        }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 2739 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 131:

/* Line 678 of lalr1.cc  */
#line 2787 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 132:

/* Line 678 of lalr1.cc  */
#line 2802 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 133:

/* Line 678 of lalr1.cc  */
#line 2827 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 134:

/* Line 678 of lalr1.cc  */
#line 2854 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 135:

/* Line 678 of lalr1.cc  */
#line 2869 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(8) - (1)].variable)->Pointer());
          draw->SetVectorVisible( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 2876 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
          draw->CB_AfficheChampVect(draw.get(),NULL);
        }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 2883 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 138:

/* Line 678 of lalr1.cc  */
#line 2901 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 139:

/* Line 678 of lalr1.cc  */
#line 2924 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw= *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          draw->SetVectType((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 2929 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw= *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          draw->SetLineThickness((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 2934 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 142:

/* Line 678 of lalr1.cc  */
#line 2947 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          int width  = (int) (yysemantic_stack_[(8) - (5)].adouble);
          int height = (int) (yysemantic_stack_[(8) - (7)].adouble);

          DessinImage::ptr draw= *(DessinImage::ptr*) ((yysemantic_stack_[(8) - (1)].variable)->Pointer());
          draw->SetSize(width,height);
          draw->Update();


        }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 2958 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          ClasseCouleur c;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(16) - (1)].variable)->Pointer());
          c.FixeValeur((int)(yysemantic_stack_[(16) - (11)].adouble),(int)(yysemantic_stack_[(16) - (13)].adouble),(int)(yysemantic_stack_[(16) - (15)].adouble));
          draw->DessineCercle( (int) (yysemantic_stack_[(16) - (5)].adouble), (int) (yysemantic_stack_[(16) - (7)].adouble), (int) (yysemantic_stack_[(16) - (9)].adouble), c);
        }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 2967 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          // TODO: fix this memory problem ...
          InrImage* colmap=(InrImage*) driver.im_stack.GetLastImage();

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(10) - (1)].variable)->Pointer());
          draw->SetUserColormap( colmap,  (yysemantic_stack_[(10) - (7)].adouble),  (yysemantic_stack_[(10) - (9)].adouble));
          //      delete colmap;
        }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 2977 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          draw->SetGLWindow( *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer()));

        }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 2985 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 147:

/* Line 678 of lalr1.cc  */
#line 3002 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 148:

/* Line 678 of lalr1.cc  */
#line 3018 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 149:

/* Line 678 of lalr1.cc  */
#line 3035 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 150:

/* Line 678 of lalr1.cc  */
#line 3055 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 151:

/* Line 678 of lalr1.cc  */
#line 3070 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 152:

/* Line 678 of lalr1.cc  */
#line 3088 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 153:

/* Line 678 of lalr1.cc  */
#line 3101 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 154:

/* Line 678 of lalr1.cc  */
#line 3115 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            DessinImage::ptr draw;

            draw = *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
            draw->SetPaintCallback( (void*) CB_ParamWin, (void*) (yysemantic_stack_[(6) - (5)].variable));
            // may be a pb to call Paint() here since it will start another interpreter ??? to check
            //draw->Paint();
        }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 3124 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 156:

/* Line 678 of lalr1.cc  */
#line 3138 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 157:

/* Line 678 of lalr1.cc  */
#line 3149 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 158:

/* Line 678 of lalr1.cc  */
#line 3162 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 159:

/* Line 678 of lalr1.cc  */
#line 3180 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 160:

/* Line 678 of lalr1.cc  */
#line 3202 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 161:

/* Line 678 of lalr1.cc  */
#line 3232 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 162:

/* Line 678 of lalr1.cc  */
#line 3260 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 163:

/* Line 678 of lalr1.cc  */
#line 3291 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->FixeNom( (yysemantic_stack_[(6) - (5)].astring));
      delete [] (yysemantic_stack_[(6) - (5)].astring);
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 3297 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 165:

/* Line 678 of lalr1.cc  */
#line 3315 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_SetCoeffAnisoGS((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 3320 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetDistanceMap((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 3325 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseType((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 3330 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseSD((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 3335 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetMask(((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 3340 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 171:

/* Line 678 of lalr1.cc  */
#line 3354 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 172:

/* Line 678 of lalr1.cc  */
#line 3369 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 173:

/* Line 678 of lalr1.cc  */
#line 3386 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 174:

/* Line 678 of lalr1.cc  */
#line 3400 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 175:

/* Line 678 of lalr1.cc  */
#line 3420 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setdt((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 3425 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setneighborhood((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 3430 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_SetCoeffAnisoGS3D((yysemantic_stack_[(8) - (5)].adouble),(yysemantic_stack_[(8) - (7)].adouble));

    }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 3437 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float  error;

      error = Func_ItereAnisoGS();

      //driver.res_print("Error in AnisoGS.Iterate ");
    }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 3446 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int res;

      res = Func_EndAnisoGS();

    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 3454 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 3459 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_EndWeickert();

    }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 3466 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 3471 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_EndWeickert();
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 3476 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 185:

/* Line 678 of lalr1.cc  */
#line 3497 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 186:

/* Line 678 of lalr1.cc  */
#line 3520 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetMeanCurv( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 3525 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetAffineCurvature( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 3530 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetBalloonScheme( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 3535 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetDMmethod( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 3540 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetThreads( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 3545 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 3550 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityLowThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 3555 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityHighThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 3560 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbabilityHighThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 3565 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumGaussians( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 3570 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetGaussian( (int) (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 3575 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumInitPoints( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 3580 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetInitPoint( (int) (yysemantic_stack_[(14) - (5)].adouble), (int) (yysemantic_stack_[(14) - (7)].adouble), (int) (yysemantic_stack_[(14) - (9)].adouble), (int) (yysemantic_stack_[(14) - (11)].adouble), (int) (yysemantic_stack_[(14) - (13)].adouble));
    }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 3585 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSets_SetIsoContourBin( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 3590 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsVelocity(((InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get(),(yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 3595 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsExpansion((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 3600 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 203:

/* Line 678 of lalr1.cc  */
#line 3613 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsBandAndTube((int)(yysemantic_stack_[(8) - (5)].adouble),(int)(yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 3618 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSetCurvWeights( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 3623 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSetAdvectionField(
                ((InrImage::ptr*) (yysemantic_stack_[(10) - (5)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(10) - (7)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(10) - (9)].variable)->Pointer())->get());
        }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 3631 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetCurvatureData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 3636 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetDistanceMap( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 3641 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetAdvectionData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 3646 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetSkeleton( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 3651 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetVelocityData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 3656 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetExpansionData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 3661 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetCurvatureData( NULL );
        }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 3666 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetAdvectionData( NULL);
        }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 3671 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetVelocityData( NULL);
        }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 3676 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsSaveDistMap( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 3681 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsSaveSecDerGrad( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 3686 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.aint) = Func_LevelSets_Iterate();
    }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 3691 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_End();
    }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 3695 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 220:

/* Line 678 of lalr1.cc  */
#line 3722 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 221:

/* Line 678 of lalr1.cc  */
#line 3735 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_OrientField( ((InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->get() , ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );
        }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 3740 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       Func_OrientPositive( ((InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->get() , ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );
    }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 3744 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())->Write((yysemantic_stack_[(4) - (4)].astring));
      delete [] (yysemantic_stack_[(4) - (4)].astring);
    }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 3750 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 225:

/* Line 678 of lalr1.cc  */
#line 3763 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetOwnMaterial( (int) (yysemantic_stack_[(6) - (5)].adouble));

        }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 3769 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->GetMaterial()._ambient.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 3775 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->GetMaterial()._diffuse.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 3781 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->GetMaterial()._specular.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 3788 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->GetMaterial()._shininess= (yysemantic_stack_[(6) - (5)].adouble);

        }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 3795 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->GetMaterial()._opacity= (yysemantic_stack_[(6) - (5)].adouble);

    }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 3802 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        Sets the object visible or not visible in the scene.
      **/
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetVisible( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 3811 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Enable/Disable colormaterial for the associated surface.
        **/

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->GetMaterial()._colormaterial = (unsigned char) ((yysemantic_stack_[(6) - (5)].adouble)>0.5);

    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 3822 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 234:

/* Line 678 of lalr1.cc  */
#line 3837 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 235:

/* Line 678 of lalr1.cc  */
#line 3852 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());


      s->SetPointsColors( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

    }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 3860 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());
      InrImage::ptr i = InrImage::ptr(driver.im_stack.GetLastImage());
      // TODO: use smart pointer to image in SetColors ...
      s->SetColors( i.get() , (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 3867 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      InrImage::ptr i = InrImage::ptr(driver.im_stack.GetLastImage());
      s->SetColors( i.get() );

    }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 3874 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      s->Statistics( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

    }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 3880 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->MergePoints((yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 3884 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->Triangulate();
    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 3888 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 242:

/* Line 678 of lalr1.cc  */
#line 3925 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      InrImage::ptr i = InrImage::ptr(driver.im_stack.GetLastImage());
      s->DisplacePoints( i.get() );
    }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 3931 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

      s->Translate( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble) );

    }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 3938 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

      s->Scale( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble),0 );

        }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 3945 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          int          w = (int) (yysemantic_stack_[(6) - (5)].adouble);

          Si w<1  AlorsFait w=1;
          Si w>10 AlorsFait w=10;

          s->_line_width = w;

        }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 3956 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

      s->RemoveLine((int)(yysemantic_stack_[(6) - (5)].adouble));
          s->GLRecomputeList();

    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 3964 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 248:

/* Line 678 of lalr1.cc  */
#line 3981 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Remove selected lines
    **/
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

        s->RemoveSelection();
        s->GLRecomputeList();
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 3991 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GLRecomputeList();

        }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 3996 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

      s->RecomputeNormals();

        }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 4003 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

      s->InvertNormals();

        }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 4010 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          Func_ApplyvtkSmooth(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 4018 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          Func_vtkWindowedSinc(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 4026 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 255:

/* Line 678 of lalr1.cc  */
#line 4045 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 256:

/* Line 678 of lalr1.cc  */
#line 4061 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 257:

/* Line 678 of lalr1.cc  */
#line 4078 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 258:

/* Line 678 of lalr1.cc  */
#line 4095 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());
      s->AddPoint((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 4100 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      s->NewLine();
    }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 4105 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      s->LineAddPointNumber( (int) (yysemantic_stack_[(6) - (5)].adouble) );
    }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 4110 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      s->EndLine();
    }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 4115 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      if (strlen((yysemantic_stack_[(4) - (3)].astring))<255) {
        strcpy(AMIFluid::FLUID_NAVIGATION_FILE,(yysemantic_stack_[(4) - (3)].astring));
      } else
        fprintf(stderr,"SetFluidNavFile() \t File too long \n");
      delete [] (yysemantic_stack_[(4) - (3)].astring);
        }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 4124 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 264:

/* Line 678 of lalr1.cc  */
#line 4224 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 265:

/* Line 678 of lalr1.cc  */
#line 4258 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->UserRotate((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 4265 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          SurfacePoly::ptr surf = SurfacePoly::ptr(driver.surf_stack.GetLastSurf());

          sdraw->GetCanvas()->AddSurface(surf);
          sdraw->Paint();
        }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 4273 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());
          sdraw->GetCanvas()->AddSurface(*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (3)].variable)->Pointer());
          //sdraw->Paint();
        }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 4279 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->RemoveSurface(*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (3)].variable)->Pointer());
          sdraw->Paint();
        }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 4286 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description: Removes the surface without swapping the 3D buffer
          **/
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->RemoveSurface(*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer());
          sdraw->Paint(false);
        }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 4296 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:  Swaps the 3D buffer
          **/
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->AfficheBuffer();
        }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 4305 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC ( (int) (yysemantic_stack_[(6) - (5)].adouble) );
          sdraw->Paint();
        }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 4312 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
          sdraw->Paint();
        }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 4319 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          Si sdraw->GetCanvas()->SetCurrentObject( (int) (yysemantic_stack_[(6) - (5)].adouble) ) Alors
            sdraw->Paint();
          Sinon
            fprintf(stderr," Incorrect index \n");
          FinSi
        }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 4329 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw1 = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          Viewer3D_ptr sdraw2 = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer());

          sdraw1->AddCompSurf(sdraw2);
        }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 4336 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 276:

/* Line 678 of lalr1.cc  */
#line 4350 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 277:

/* Line 678 of lalr1.cc  */
#line 4364 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Viewer3D_ptr draw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      int num = (int) (yysemantic_stack_[(6) - (5)].adouble);

      draw->GetCanvas()->HideFreeSection(num);

        }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 4372 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr glclass=*((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());
          glclass->GetCanvas()->PrintMatrices();
        }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 4377 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->SetObjectTransform(*tr);
              sdraw->Paint();
          delete tr;
        }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 4385 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->SetObjectTransform(*tr);
          if ((yysemantic_stack_[(8) - (7)].adouble)>0.5) sdraw->Paint();
          delete tr;
        }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 4393 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 282:

/* Line 678 of lalr1.cc  */
#line 4404 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 283:

/* Line 678 of lalr1.cc  */
#line 4416 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 284:

/* Line 678 of lalr1.cc  */
#line 4428 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 285:

/* Line 678 of lalr1.cc  */
#line 4440 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->SetBG((int)(yysemantic_stack_[(10) - (5)].adouble),(int)(yysemantic_stack_[(10) - (7)].adouble),(int)(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 4446 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Normalizes the 3D view based on the limits in space of the current objects
        **/
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->Normalize();
        }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 4455 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Centers the 3D view based on the limits in space of the current objects
        **/
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->Center();
        }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 4464 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 289:

/* Line 678 of lalr1.cc  */
#line 4477 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_StructureTensor(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                   (yysemantic_stack_[(8) - (3)].variable)->Name().c_str(),
                   (yysemantic_stack_[(8) - (5)].adouble), (yysemantic_stack_[(8) - (7)].adouble), NULL);
        }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 4484 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();

          Func_StructureTensor(
            ((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),
            (yysemantic_stack_[(10) - (3)].variable)->Name().c_str(),
            (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), mask);
          delete mask;
        }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 4495 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 292:

/* Line 678 of lalr1.cc  */
#line 4517 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 293:

/* Line 678 of lalr1.cc  */
#line 4543 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 294:

/* Line 678 of lalr1.cc  */
#line 4571 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_HessianMatrix(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(6) - (3)].variable)->Name().c_str(),
                 (yysemantic_stack_[(6) - (5)].adouble),   // sigma
                 0,   // gamma
                 NULL  // mask
                 );
        }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 4581 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 296:

/* Line 678 of lalr1.cc  */
#line 4594 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_HessianMatrix(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(8) - (3)].variable)->Name().c_str(),
                 (yysemantic_stack_[(8) - (5)].adouble),   // sigma
                 (yysemantic_stack_[(8) - (7)].adouble),   // gamma
                 NULL  // mask
                 );
        }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 4604 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 298:

/* Line 678 of lalr1.cc  */
#line 4626 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 299:

/* Line 678 of lalr1.cc  */
#line 4655 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 300:

/* Line 678 of lalr1.cc  */
#line 4673 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 301:

/* Line 678 of lalr1.cc  */
#line 4687 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_Curvatures(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
              (yysemantic_stack_[(6) - (3)].variable)->Name().c_str(),
              (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 4699 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 303:

/* Line 678 of lalr1.cc  */
#line 4720 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 304:

/* Line 678 of lalr1.cc  */
#line 4739 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 305:

/* Line 678 of lalr1.cc  */
#line 4756 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 306:

/* Line 678 of lalr1.cc  */
#line 4767 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get())->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 4772 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 4777 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im = *(InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer();
      (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetVoxelSize(
                                   im->VoxSizeX(),
                                   im->VoxSizeY(),
                                   im->VoxSizeZ());
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 4786 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->SetTranslation((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 4791 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im = *(InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer();
      (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetVoxelSize(
                                   im->TrX(),
                                   im->TrY(),
                                   im->TrZ());
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 4800 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 312:

/* Line 678 of lalr1.cc  */
#line 4814 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_DiscSecDerGrad(
        ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
        ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 4821 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_DiscSecDerGrad(
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (7)].variable)->Pointer())->get());
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 4827 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.aint)=1;}
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 4830 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 316:

/* Line 678 of lalr1.cc  */
#line 4847 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 317:

/* Line 678 of lalr1.cc  */
#line 4863 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 318:

/* Line 678 of lalr1.cc  */
#line 4902 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 319:

/* Line 678 of lalr1.cc  */
#line 4919 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 320:

/* Line 678 of lalr1.cc  */
#line 4959 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_GenRead((yysemantic_stack_[(4) - (3)].astring));
        }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 4964 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.InitCumul();
        }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 4969 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Debut();
        }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 4974 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Fin();
      cout << "time spent = " << driver.IP_time << endl;
        }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 4980 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 325:

/* Line 678 of lalr1.cc  */
#line 4997 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description:
        Ends a notebook.
    **/
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndBook();
    }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 5007 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 327:

/* Line 678 of lalr1.cc  */
#line 5022 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndPanel();
    }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 5028 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndPanel();
      pw->EndBox( );
    }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 5035 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndBox( );
    }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 5041 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->BeginHorizontal( );
    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 5047 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
        pw->EndHorizontal( );
        }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 5053 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          pw->CreeDialogue( );
        }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 5059 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 334:

/* Line 678 of lalr1.cc  */
#line 5074 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Hides the given parameter panel, the smart pointer copy is released
        **/
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

          GB_main_wxFrame->RemoveParamPanelPage(pw);
        }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 5085 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          pw->ReAfficheParametres();
        }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 5091 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 337:

/* Line 678 of lalr1.cc  */
#line 5105 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 338:

/* Line 678 of lalr1.cc  */
#line 5119 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 339:

/* Line 678 of lalr1.cc  */
#line 5136 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
          int n = pw->NbParameters();
            pw->ChangedValueCallback(n-1,(void*) CB_ParamWin, (void*) (yysemantic_stack_[(6) - (5)].variable) );
        }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 5146 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 341:

/* Line 678 of lalr1.cc  */
#line 5165 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 342:

/* Line 678 of lalr1.cc  */
#line 5183 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 343:

/* Line 678 of lalr1.cc  */
#line 5201 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 344:

/* Line 678 of lalr1.cc  */
#line 5221 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 345:

/* Line 678 of lalr1.cc  */
#line 5241 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 346:

/* Line 678 of lalr1.cc  */
#line 5261 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage::ptr   i = *(InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer();
          Func_VectorImage2StructuredGrid(i.get(),(yysemantic_stack_[(6) - (5)].astring));
          delete [] (yysemantic_stack_[(6) - (5)].astring);
        }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 5268 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(GLTransfMatrix_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->Print();
        }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 5273 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_SaveTransform(((GLTransfMatrix_ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())->get(),(yysemantic_stack_[(4) - (4)].astring));
          delete [] (yysemantic_stack_[(4) - (4)].astring);
        }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 5279 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapVTK();
        }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 5284 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapWII();
        }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 5289 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapFilters();
        }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 5300 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 353:

/* Line 678 of lalr1.cc  */
#line 5332 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 354:

/* Line 678 of lalr1.cc  */
#line 5356 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable*  var   = (yysemantic_stack_[(4) - (1)].variable);
          ParamList::ptr param((yysemantic_stack_[(4) - (3)].paramlist));
          ((void (*)(ParamList*)) var->Pointer())(param.get());
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 5363 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 356:

/* Line 678 of lalr1.cc  */
#line 5385 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = new std::list<std::string>();
            sl->push_back(string((yysemantic_stack_[(1) - (1)].astring)));
            delete [] (yysemantic_stack_[(1) - (1)].astring);
            (yyval.string_list) = sl;
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 5393 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = (yysemantic_stack_[(3) - (1)].string_list);
            sl->push_back(string((yysemantic_stack_[(3) - (3)].astring)));
            delete [] (yysemantic_stack_[(3) - (3)].astring);
            (yyval.string_list) = sl;
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 5409 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          (yyval.paramlist) = pl;
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 5414 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl(new ParamList);
          float_ptr* x = new float_ptr(new float((yysemantic_stack_[(1) - (1)].adouble)));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 5421 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);
          float_ptr* x= new float_ptr(new float((yysemantic_stack_[(3) - (3)].adouble)));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 5428 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          string_ptr* x = new string_ptr(new string((yysemantic_stack_[(1) - (1)].astring)));
          delete [] (yysemantic_stack_[(1) - (1)].astring);
          pl->AddParam(type_string, x);
          (yyval.paramlist) = pl;
         }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 5436 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);
          string_ptr* x = new string_ptr(new string((yysemantic_stack_[(3) - (3)].astring)));
          delete [] (yysemantic_stack_[(3) - (3)].astring);
          pl->AddParam(type_string, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 5444 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  new ParamList();
          // creating reference
          float_ptr* x = new float_ptr(*((float_ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer()));

          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 5453 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          float_ptr*   x = new float_ptr(* ((float_ptr*)(yysemantic_stack_[(4) - (4)].variable)->Pointer()));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 5460 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          int_ptr*   x = new int_ptr(*((int_ptr*)(yysemantic_stack_[(2) - (2)].variable)->Pointer()));
          pl->AddParam(type_int, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 5467 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          int_ptr*   x = new int_ptr( *((int_ptr*)(yysemantic_stack_[(4) - (4)].variable)->Pointer()));
          pl->AddParam(type_int, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 5474 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          InrImage::ptr* i = new InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 5481 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(3) - (1)].paramlist);
          InrImage::ptr*   i = new InrImage::ptr( (InrImage*) driver.im_stack.GetLastImage());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 5488 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          InrImage::ptr*  i = new InrImage::ptr(*(InrImage::ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 5495 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          InrImage::ptr* i = new InrImage::ptr(*(InrImage::ptr*) (yysemantic_stack_[(4) - (4)].variable)->Pointer());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 5502 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          SurfacePoly::ptr*  s = new SurfacePoly::ptr(*(SurfacePoly::ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer());
          pl->AddParam(type_surface, s);
          (yyval.paramlist) = pl;
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 5509 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          SurfacePoly::ptr*  s = new SurfacePoly::ptr(*(SurfacePoly::ptr*) (yysemantic_stack_[(4) - (4)].variable)->Pointer());
          pl->AddParam(type_surface, s);
          (yyval.paramlist) = pl;
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 5516 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          DessinImage::ptr* i = new DessinImage::ptr(*(DessinImage::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer());
          pl->AddParam(type_imagedraw, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 5523 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(3) - (1)].paramlist);
          DessinImage::ptr*  i = new DessinImage::ptr(*(DessinImage::ptr*) (yysemantic_stack_[(3) - (3)].variable)->Pointer());
          pl->AddParam(type_imagedraw, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 5532 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      //      printf("no parameters \n");
      ParamListDecl* pl = new ParamListDecl;
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 5538 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      cout << "param_list_decl: T_NUM IDENTIFIER" << endl;
      cout << ident->GetName().c_str() << endl;
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_float);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 5547 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_string);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 5554 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 5561 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 5568 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 5575 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_float);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 5582 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_string);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 5589 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 5596 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 5603 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 5611 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 5616 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 388:

/* Line 678 of lalr1.cc  */
#line 5631 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
          //fflush(stdout);
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 5637 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 390:

/* Line 678 of lalr1.cc  */
#line 5651 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 391:

/* Line 678 of lalr1.cc  */
#line 5667 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 392:

/* Line 678 of lalr1.cc  */
#line 5683 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 393:

/* Line 678 of lalr1.cc  */
#line 5706 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.astring)=(char*) (*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->Nom();
    }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 5710 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 395:

/* Line 678 of lalr1.cc  */
#line 5721 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description:
        Returns the name of the object instance to which this variable belongs. If this variable does not belong to an object, returns an empty string.
    **/
      boost::shared_ptr<Variables> context = (yysemantic_stack_[(4) - (3)].variable)->GetContext();
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

  case 396:

/* Line 678 of lalr1.cc  */
#line 5740 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      char* res = new char[GB_scripts_dir.Len()+1];
      strcpy(res,(const char*)GB_scripts_dir.mb_str(wxConvUTF8));
      (yyval.astring)= res;
    }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 5751 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 399:

/* Line 678 of lalr1.cc  */
#line 5761 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          RemoveEndString((yysemantic_stack_[(3) - (1)].astring),(yysemantic_stack_[(3) - (3)].astring));
          (yyval.astring)=(yysemantic_stack_[(3) - (1)].astring);
        }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 5771 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        Uses the class boost::format to create the result of 
        the format as a string, using a string expression as a parameter.
    **/
      boost::format bf((yysemantic_stack_[(3) - (1)].astring));
      delete [] (yysemantic_stack_[(3) - (1)].astring);
      std::string resstr = (bf % (yysemantic_stack_[(3) - (3)].astring)).str();
      char* res = new char[resstr.length()+1];
      strcpy(res,resstr.c_str());
      (yyval.astring)= res;
      delete [] (yysemantic_stack_[(3) - (3)].astring);
    }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 5787 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        Uses the class boost::format to create the result of 
        the format as a string, only one numerical parameter 
        is accepted.
    **/
      boost::format bf((yysemantic_stack_[(3) - (1)].astring));
      delete [] (yysemantic_stack_[(3) - (1)].astring);
      std::string resstr = (bf % (yysemantic_stack_[(3) - (3)].adouble)).str();
      char* res = new char[resstr.length()+1];
      strcpy(res,resstr.c_str());
      (yyval.astring)= res;
    }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 5806 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5820 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5828 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5836 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5845 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=*((float_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get();
    }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 5849 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = (float) *((int_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get();
    }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 5853 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = (float) *((uchar_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get();
    }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 5857 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(3) - (2)].adouble);
      fflush(stdout);
    }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 5866 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5881 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5897 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5911 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5926 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5943 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5959 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5973 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5986 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6007 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6067 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6092 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description:
          Prints the object information
      **/
      AMIObject::ptr o = *(AMIObject::ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer();
      
      if (o.get()) {
        cout << "var   name = " << (yysemantic_stack_[(2) - (1)].variable)->Name() <<endl;
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

  case 427:

/* Line 678 of lalr1.cc  */
#line 6114 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6133 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

      (yyval.adouble) = s->GetNumberOfPoints();
    }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 6140 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

      (yyval.adouble) = s->GetNumberOfPolys();

    }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 6148 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_SNR(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 6153 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (yyval.adouble)=Func_eccentricity(((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());
        }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 6158 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6186 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (yyval.adouble)=Func_ComputePositiveArea( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get() );
    }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 6192 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6203 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6222 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6241 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6260 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6279 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6298 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6317 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6340 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6362 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6385 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();
          (yyval.adouble)=Func_med( ((InrImage::ptr*) (yysemantic_stack_[(9) - (6)].variable)->Pointer())->get(),(float) (yysemantic_stack_[(9) - (8)].adouble),mask);
          delete mask;
        }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 6392 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6416 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6439 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//    setlocale(LC_NUMERIC,"C");
      setlocale(LC_NUMERIC, "C");
      (yyval.adouble)=atof((yysemantic_stack_[(4) - (3)].astring));
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 6447 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6457 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6467 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6477 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6487 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6497 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6507 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          DessinImageParametres* param;
          string comment;
          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
          param = draw->GetParam();
          (yyval.adouble)=param->_pos._x;
          comment = str(format(" //  xpos=%3d") % param->_pos._x);
          if (driver.InConsole())
            GB_main_wxFrame->GetConsole()
                           ->IncCommand(wxString::FromAscii(comment.c_str()));
        }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 6521 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;
      string comment;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_pos._y;

      comment = str( format(" //  ypos=%3d") % param->_pos._y);
      if (driver.InConsole())
        GB_main_wxFrame->GetConsole()
                       ->IncCommand(wxString::FromAscii(comment.c_str()));

    }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 6538 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;
      string comment;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_pos._z;

      comment = str( format(" //  xpos=%3d") % param->_pos._z);
      if (driver.InConsole())
        GB_main_wxFrame->GetConsole()
                        ->IncCommand(wxString::FromAscii(comment.c_str()));
    }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 6554 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_AnisoGS_GetNoiseSD();
    }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 6559 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_AnisoGS_GetDAcoeff();
    }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 6564 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = Func_LevelSets_UpdateResult();
    }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 6568 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr mat = *(FloatMatrix::ptr*)(yysemantic_stack_[(6) - (1)].variable)->Pointer();
          int i = (int)(yysemantic_stack_[(6) - (3)].adouble);
          int j = (int)(yysemantic_stack_[(6) - (5)].adouble);
          (yyval.adouble) = (*mat)[i][j];
    }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 6575 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr mat = *(FloatMatrix::ptr*)(yysemantic_stack_[(8) - (1)].variable)->Pointer();
          int i = (int)(yysemantic_stack_[(8) - (3)].adouble);
          int j = (int)(yysemantic_stack_[(8) - (5)].adouble);
          (yyval.adouble)  =  ((*mat)[i][j] = (yysemantic_stack_[(8) - (8)].adouble));
    }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 6583 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6618 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6656 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6673 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6693 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6705 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6722 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6742 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6775 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6794 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6816 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6832 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6850 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6874 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6895 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6923 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6937 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6947 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6960 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6974 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6989 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6997 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7005 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7017 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble) = (int) (yysemantic_stack_[(1) - (1)].aint);
    }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 7021 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7036 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       float*  var = ((float_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get();
        FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
        setlocale(LC_NUMERIC, "C");
        (yyval.adouble) = fscanf(file.get(),"%f",var);
    }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 7043 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7053 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7065 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7078 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(2) - (2)].adouble); }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 7079 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(!,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 7080 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(-,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 7081 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(+,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 7082 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(sin,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 7083 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(cos,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 7084 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(sqrt,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 7085 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(fabs,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 7086 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(round,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 7088 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7095 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(tan,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 7096 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(asin,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 7097 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(acos,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 7098 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(atan,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 7100 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7112 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7124 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7147 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7163 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)*(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 7164 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)/(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 7165 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)= ((int) round((yysemantic_stack_[(3) - (1)].adouble))) % ((int) round((yysemantic_stack_[(3) - (3)].adouble))); }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 7170 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)+(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 7171 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)-(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 7181 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)<(yysemantic_stack_[(3) - (3)].adouble));  }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 7182 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)>(yysemantic_stack_[(3) - (3)].adouble));  }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 7183 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)<=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 7184 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)>=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 7189 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)==(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 7190 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)!=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 7191 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(strcmp((yysemantic_stack_[(3) - (1)].astring),(yysemantic_stack_[(3) - (3)].astring))==0); }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 7192 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(strcmp((yysemantic_stack_[(3) - (1)].astring),(yysemantic_stack_[(3) - (3)].astring))!=0); }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 7198 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = ((int)(yysemantic_stack_[(3) - (1)].adouble)) & ((int)(yysemantic_stack_[(3) - (3)].adouble));
    }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 7211 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
        }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 7215 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = ((int)(yysemantic_stack_[(3) - (1)].adouble)) | ((int)(yysemantic_stack_[(3) - (3)].adouble));
        }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 7222 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
        }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 7226 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)&&(yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 7233 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
    }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 7237 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)||(yysemantic_stack_[(3) - (3)].adouble);
    }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 7245 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=((yysemantic_stack_[(5) - (1)].adouble)?(yysemantic_stack_[(5) - (3)].adouble):(yysemantic_stack_[(5) - (5)].adouble));
        }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 7262 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.err_print(" char format is not available: use unsigned char \n");
      (yyval.aint)=WT_UNSIGNED_CHAR;
    }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 7267 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.aint)=WT_UNSIGNED_CHAR;
       }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 7271 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_SHORT;
       }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 7275 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_SHORT;
       }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 7279 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_INT;
       }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 7283 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_INT;
       }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 7287 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT;
       }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 7291 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_DOUBLE;
       }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 7295 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_RGB;
       }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 7299 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT_VECTOR;
       }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 7303 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//        printf("format %d \n",(int) ( *(InrImage::ptr*) $1->Pointer())->GetFormat());
        (yyval.aint) = (int) (*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetFormat();
      }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 7311 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yysemantic_stack_[(1) - (1)].variable);
        }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 7316 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7333 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     driver.im_stack.AddImage((yysemantic_stack_[(2) - (2)].astring));
     delete [] (yysemantic_stack_[(2) - (2)].astring);
       }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 7339 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     driver.im_stack.AddImage((yysemantic_stack_[(4) - (3)].astring));
     delete [] (yysemantic_stack_[(4) - (3)].astring);
       }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 7346 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7404 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7458 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7513 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7534 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7555 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7569 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

          if (driver.InConsole())
            GB_main_wxFrame->GetConsole()
                            ->IncCommand(wxString::FromAscii(inc_cmd.c_str()));
      }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 7598 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage* im;
        //printf(" ********** %d %f %f %f\n", $3, $5, $7, $9);
        im = new InrImage( (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble), (WORDTYPE) (yysemantic_stack_[(10) - (3)].aint));
        driver.im_stack.AddImage(im);
      }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 7606 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7625 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7651 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7664 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7742 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7809 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im  = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res =Func_localmean( im, (int) (yysemantic_stack_[(6) - (5)].adouble));
      driver.im_stack.AddImage(res);
      delete im;
    }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 7817 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im  = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res =Func_localmean2( im, (int) (yysemantic_stack_[(6) - (5)].adouble));
      driver.im_stack.AddImage(res);
      delete im;
      }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 7825 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7835 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7845 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7875 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7893 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7913 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7931 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7951 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7970 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 7991 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8028 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8043 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8057 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8073 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8096 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8110 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8124 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8138 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8152 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8187 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8202 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8223 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8244 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8285 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8330 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8347 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8366 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8380 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8394 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8410 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8428 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8443 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8459 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8474 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8497 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8514 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8528 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8540 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8572 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8592 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8634 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8646 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8657 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8670 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8682 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8693 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8721 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8748 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8780 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8796 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8813 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8826 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8839 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8859 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8882 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8896 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8913 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8946 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 8984 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9019 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9052 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9069 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9084 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9100 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9120 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9143 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9167 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9193 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9216 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9238 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9261 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9285 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9329 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9353 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9384 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9406 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9443 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9480 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9517 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9552 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          driver.im_stack.AddImage((*(Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetCanvas()->GetGLImage());
        }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 9557 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9566 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.im_stack.AddImage((*(DessinImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetInrImage());
    }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 9571 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

    InrImage*    res;

      res = Func_ThresholdCrossing( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

          driver.im_stack.AddImage(res);

    }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 9582 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*    res;

      res = Func_IsocontourPoints( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

      driver.im_stack.AddImage(res);

    }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 9592 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*    res;

      res = Func_IsosurfDist( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

          driver.im_stack.AddImage(res);

    }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 9602 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*    res;

      res = Func_vtkIsoContourDist( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

          driver.im_stack.AddImage(res);
    }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 9611 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9634 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9663 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9689 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9720 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9750 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      InrImage* res;
      res = Func_Convolve(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                  ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());

          driver.im_stack.AddImage(res);

        }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 9761 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9777 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
      res = Func_Chamfer(((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));

          driver.im_stack.AddImage(res);

        }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 9787 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
      res = Func_Chamfer2(((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));

          driver.im_stack.AddImage(res);

        }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 9797 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9812 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9826 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9840 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9853 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9866 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9878 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9890 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9902 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9913 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9926 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9953 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 9986 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10102 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10126 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10168 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10180 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10189 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10198 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10221 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10246 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10259 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(5) - (1)].variable)->Pointer());


      res = s->GetImageLinesLength(  );

      if (res!=NULL) driver.im_stack.AddImage(res);
    }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 10269 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10306 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10324 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10342 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());


      res = s->GetIntensities( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

      if (res!=NULL) driver.im_stack.AddImage(res);
        }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 10352 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10362 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10370 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10378 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10386 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10411 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10431 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* res;
      res= AMIFluid::Func_ReadFlow((char*)(yysemantic_stack_[(4) - (3)].astring));
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 10439 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10473 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10496 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10521 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(-)               }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 10523 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sin)             }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 10524 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(cos)             }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 10525 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sqrt)            }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 10526 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(fabs)            }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 10527 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(round)           }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 10528 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(floor)           }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 10529 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(tan)             }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 10530 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(asin)            }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 10531 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(acos)            }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 10532 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(atan)            }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 10533 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(exp)             }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 10534 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(1.0/log(10.0)*log) }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 10535 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(log)             }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 10537 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10552 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10574 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(*,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 10580 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(/,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 10582 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  IMAGE_OP_IMAGE_2(*)   }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 10583 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(/)   }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 10584 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(^)   }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 10593 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(+,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 10594 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(-,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 10595 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(+)   }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 10596 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(-)   }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 10604 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<)    }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 10605 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>)    }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 10606 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<=)   }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 10607 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>=)   }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 10608 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<, (yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 10609 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>, (yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 10610 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<=,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 10611 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>=,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 10616 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(==)   }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 10617 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(!=)   }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 10618 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(==,(yysemantic_stack_[(3) - (3)].adouble))   }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 10619 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(!=,(yysemantic_stack_[(3) - (3)].adouble))   }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 10661 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10672 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10685 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10696 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10713 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         FloatMatrix* m;
         m = new FloatMatrix((int)(yysemantic_stack_[(6) - (3)].adouble),(int)(yysemantic_stack_[(6) - (5)].adouble));
         driver.matrix_stack.AddMatrix(m);
       }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 10720 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      FloatMatrix* newmat;
      FloatMatrix::ptr mat = *(FloatMatrix::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

      newmat = new FloatMatrix( (*mat));

          driver.matrix_stack.AddMatrix(newmat);
       }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 10730 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10750 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(-)               }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 10753 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10761 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sin)             }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 10762 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(cos)             }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 10763 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sqrt)            }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 10764 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(fabs)            }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 10765 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(round)           }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 10766 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(floor)           }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 10767 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(tan)             }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 10768 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(asin)            }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 10769 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(acos)            }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 10770 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(atan)            }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 10771 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(exp)             }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 10772 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(1.0/log(10.0)*log) }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 10773 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(log)             }
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 10780 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(*,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 10781 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(*)   }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 10783 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10793 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(+,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 10794 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(-,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 10795 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(+)   }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 10796 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(-)   }
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 10845 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yysemantic_stack_[(1) - (1)].variable);
        }
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 10850 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10866 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10877 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10887 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10907 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10941 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10950 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10959 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10968 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10977 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        SurfacePoly* surf;
        surf = Func_vtkWindowedSinc(((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
        if (surf==NULL) driver.err_print("vtkWindowedSinc failed!");
        driver.surf_stack.AddSurf(surf);
    }
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 10985 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf = new SurfacePoly();
      driver.surf_stack.AddSurf(surf);
    }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 10991 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.surf_stack.AddSurf((yysemantic_stack_[(2) - (2)].astring));
      delete [] (yysemantic_stack_[(2) - (2)].astring);
    }
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 10997 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.surf_stack.AddSurf((yysemantic_stack_[(4) - (3)].astring));
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 11003 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 834:

/* Line 678 of lalr1.cc  */
#line 11029 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 11043 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 11059 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* newsurf;
      SurfacePoly::ptr surf = *(SurfacePoly::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

      newsurf = new SurfacePoly( (*surf) );

          driver.surf_stack.AddSurf(newsurf);
      }
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 11069 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 11087 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 11115 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 11142 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 11158 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 11181 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 11214 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 11250 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 11296 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 11334 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 11358 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 11368 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 11391 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 11403 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 11416 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 11453 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 11496 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 11544 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 11596 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 11639 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 11667 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 11700 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 11750 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yysemantic_stack_[(1) - (1)].variable);
        }
    break;

  case 880:

/* Line 678 of lalr1.cc  */
#line 11774 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent<float>* extent=new ImageExtent<float>( (float)(yysemantic_stack_[(11) - (1)].adouble),(float)(yysemantic_stack_[(11) - (3)].adouble),(float)(yysemantic_stack_[(11) - (5)].adouble),
                              (float)(yysemantic_stack_[(11) - (7)].adouble),(float)(yysemantic_stack_[(11) - (9)].adouble),(float)(yysemantic_stack_[(11) - (11)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        }
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 11782 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent<float>* extent=new ImageExtent<float>((float)(yysemantic_stack_[(7) - (1)].adouble),(float)(yysemantic_stack_[(7) - (3)].adouble),(float)(yysemantic_stack_[(7) - (5)].adouble),(float)(yysemantic_stack_[(7) - (7)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        }
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 11789 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          //extent->print();
          (yyval.imageextent)=extent;
       }
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 11805 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        if (driver.InConsole()) GB_main_wxFrame->GetConsole()->IncCommand(comment);

        (yyval.imageextent)=extent;
       }
    break;



/* Line 678 of lalr1.cc  */
#line 14848 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
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
  const short int Parser::yypact_ninf_ = -2801;
  const short int
  Parser::yypact_[] =
  {
     14231, -2801,  8122,  3929,  3929,  3449, -2801, -2801, -2801, -2801,
   -2801,    74,   115,   129, -2801, -2801, -2801, -2801,   -38,   339,
   -2801,    95,  3449,  9554,   215,   153,   176,   215, -2801,   188,
     210, -2801, -2801, -2801, -2801,    30,   108,   219,    37,   225,
   -2801,   181,    34,    42, -2801,   262, -2801,   346,   231,    86,
     302,   322,    62,   366,   676,   215, -2801, -2801, -2801, -2801,
     382,   404,   428,   442,   437,   488,   589,   456,   502, -2801,
   -2801, -2801, -2801,   544,   575,   605,   618,   633,   799,   645,
     687,   718,   798,   824,   828,   832,   865,   870,   935,   958,
     970,   973,   981,   997,  1001, -2801, -2801, -2801, -2801, -2801,
   -2801, -2801, -2801, -2801, -2801,  1043,  1047,  1082, -2801, -2801,
    3929,  3929,  3929,  3929,  3929,  3929,  3929,  3929,  3929,  3929,
    3929,  3929,  3929,   231, -2801, -2801,  9554,   919,   215,  1101,
    1106,  1112,    32,   231,  1136,  1144,  1148,  1209, -2801, -2801,
   -2801,  1210,  1228, -2801,   385,  5704, -2801, -2801, -2801, -2801,
   -2801, -2801, -2801,   106, -2801, -2801,   420,    92, -2801, -2801,
   -2801,  3929, -2801,   526,   474, -2801,    69,   410,   785,   717,
     808,   713,     4, -2801, -2801, -2801, -2801,    82, -2801, -2801,
   -2801, -2801,   803,    36,   561, -2801, -2801, -2801, -2801, -2801,
   -2801, -2801, -2801, -2801, -2801, -2801,    52,   -21,   956,  8122,
    8122,  9554, -2801, -2801, -2801,   959, -2801,  1236,  1083,    86,
    1134,  1170,  1191,  1232,  1235,  8122,  8122,  8122,  8122,  8122,
    8122,  8122,  8122,  8122,  8122,  8122,  8122,  8122,  8122, -2801,
      77,  1238,  1236, -2801,   803, -2801,   803, -2801,  1241,  1244,
     284,  1245,   215,  9554,   215, -2801, -2801, -2801, -2801, -2801,
   -2801, -2801, -2801, -2801,    92, -2801, -2801,    92, -2801,  1240,
    1243,   215,   215,  1240,  1492,  1492, -2801, -2801,  9554, -2801,
   -2801,  9554, -2801, -2801,  9554,   215,   724,   590,    29,    29,
    9554,  3449,    12,   817, 11294, 11294, -2801, -2801, -2801,   812,
     -12,  9554,   914,  9554, -2801, -2801, -2801, -2801, -2801, -2801,
   -2801, -2801, -2801, -2801, -2801, -2801, -2801, -2801, -2801,  1255,
    1191, -2801, -2801,  1240,  9554,  9554, 15047, 12314, 15047, 15047,
   15047, 15047, 15047, 15047,    95,   432,  1627,   362,   396,    95,
      95, 15047, 15047,    95,    95,    95,    95,    95,    95,    95,
      95,  1219,  1223,  9554,  9554,    95,  9554,  9554,   124,   215,
   15047,    95, -2801,   803, -2801,   803, -2801,   803, -2801,   803,
   -2801,   803, -2801,   803, -2801,   803, -2801,   803, -2801,   803,
   -2801,   803, -2801,   803, -2801,   803, -2801,   803,  -117, -2801,
    1226, -2801, -2801,   288,  1240,  1371,   215,  1224, -2801, -2801,
   -2801,  9554,   215,  1208,    95,    95,    95, -2801, -2801, -2801,
   -2801, -2801, -2801, -2801, -2801, -2801,   106, -2801,   215,   215,
    9554,   215,   215,   215, -2801,   803,  8122,  8122,  8122,  8122,
    8122,  8122,  8122,  8122,  8122,  8122,  8122,  9554,  9554,  9554,
    9554,  9554,  9554,  9554,  9554,   112, 15047, 15047, 12314, -2801,
    3929,   124,  3929,  3929,  1345,   -30, 14670, 10084,  1194,   369,
     191,   531,  9554,  9554,   451,  1098,  9554,   -45,    99, -2801,
   15897,    16, -2801,   134,  1262,   850,  1230,   885,   147, -2801,
    1268,  1269, -2801, -2801, -2801,  1240,  1271,  1272,  1274,  1275,
    1276,  1277, -2801, -2801, -2801, -2801, -2801, -2801, -2801, -2801,
   -2801,  1278,  1279,  1280, -2801,  1281,  1283,  1287,  1288, -2801,
    1289,  1290,  1298,  1300,  1301,  1302,  1303,  1304,  1305,  1306,
    1307,  1308,  1324,  1325,  1326, -2801,  1327,  1328,  1336,  1337,
   -2801, -2801,  1338, -2801,  1339, -2801,  1340,  1343,  1346,  1347,
    1348, -2801, -2801,  1342, -2801, -2801,  9554,   215, -2801,  1350,
    1351, -2801,  1352, 13252, 13252, 12314,   306,    93,  1353,  1349,
    1354,  1356,   934,  1357,  1358,  1359,  1361,  1363,  1365,  1366,
    1367,  1368,  1369,  1373,  1374,  1375,   554,  1376,  1377,  1378,
    1386,  1383,  1396,  1405,  1406,  1402,  1430,  1411,  1437,  1438,
    1440,  1442,  1443,  1445,  1447,  1450,  1451,  1452,  1453,  1454,
    1455,  1456,  1457,  1459,  1460,  1461,  1462,  1463,  1464,  1465,
    1466,  1467,  1468,  1471,  1487,  1488,  1489,  1491,  1493,  1494,
    1495,  1496,  1497,  1498,  1499,  1501,  1502,  1503,  1506,  1507,
    1508,  1511,  1512,  1514,  1515,  1516,  1518,  1519,  1520,  1522,
    1523,  1524,  1525,  1526,  1527,  1528, 13252, 13252, 13252, 13252,
   13252, 13252, 13252, 13252, 13252, 13252, 13252, 13252, 13252, 15047,
    1529,  1530,  1531,  1532,  1533,  1534,  1486,  1535,  1557,  1558,
    1561,  1562,   314,    92, 13252, -2801,   507, -2801, -2801, -2801,
    1214, -2801,   545, -2801,   771, -2801,   151,   675,  1559, -2801,
    1560,  1231,    67, -2801, -2801, -2801,  1563,   583, -2801,  1564,
   -2801,  1566, -2801, -2801, -2801,  1567,  1568,  1570,  1588, -2801,
   -2801,  1590,  1591,  1592,  1593,  1594,  1595,  1596,  1597,  1598,
    1599,  1600,  1601,  1602, -2801, -2801, -2801, -2801,  1603,  1605,
    1606,  1607, -2801,   215,  1608,  1611,  1612,  9554,  1609,  1610,
   15047, 15047,  4751,  1613,  1614,   609,  1615, 15047, 15047, 15047,
   15047, 15047, 15047, 15047, 15047, 15047, 15047, 15047, 15047, 15047,
   15047,  1046,  1617,  1616,  1349,  1618,  1619,  1621,  1625,  1628,
    1631,  1629,  1632,  1630,  1636,  1638,  1639, -2801, -2801,  1640,
    1641, -2801, -2801,  1642,  1643,  1644,  1645,  1646,  1660,  1662,
    1663, -2801,  1664,  1665,  1666,  1667,  1668,  1669,  1671,  1675,
    1676,  1677,  1678,  1679,  1680,  1681,  1682,  1685,  1686,  1687,
    1688,  1693,  1694,  1695,  1696,  1697,  1698,  1699,  1700,  1701,
    1702, -2801, -2801, -2801, -2801, -2801, -2801,  1706,  1708,   510,
    1713,  1729,  1726,  1727,  1728,  1730,  1731,  1732,  1733,  1734,
    1735,  1736,  1743,  1744,  1739,  1740,   226,  1741,   124,   124,
     124, -2801,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,  1748,  1059,  1745,  1749,
    9554,   215, -2801,   -13, -2801,  1750,  1752,  1110,  1753,  1703,
    1755,   106,  1751,  1114,  1754,  1756,  1757,  1759, -2801, -2801,
   -2801, -2801,   890,  1240,  1240, -2801, -2801, -2801,   526,   526,
   -2801, -2801, -2801, -2801,    69,    69,   410,   785,   717,   808,
      11,   713,   426,  1765,  1760, -2801,  1762, -2801, -2801,   215,
   -2801,  1769,  1770,  1771,  1772,  1773,  1774,  1775,  1776,  1777,
   -2801, -2801, -2801, -2801, -2801, -2801, -2801,   803,   803,   526,
      36,   526,    36, -2801, -2801, -2801,   215,  1778,  1780, -2801,
     215, -2801,  1781, -2801,  1782,  1783,  1784,  1785,  1786,  1787,
    1788,  1800,  1822,  1823,  1824,  1825,  1826,  1827,  1828,  1829,
   -2801,  1830, -2801,  1831, -2801, -2801,  1832,  1833,  1834,  1835,
    1836, -2801, -2801,  1839,  1840,  1841,  1843,  1844,  1845,  1846,
    1847,  1848,  1849,  1850,  1851,  1852,  1853,  1854,  1855,  1856,
    1472,  1857,  1858,  1859,  1860,  1861,  1622, -2801,  1865, -2801,
   12783, 12783, 10782,  1492,   793,  1862,  1863,  1871, -2801, -2801,
    1872,  1105,  1873,  1874,  1875,  1879, 12783, 12783, 12783, 12783,
   12783, 12783, 12783, 12783, 12783, 12783, 12783, 12783, 12783,    58,
   12783,  1878, -2801, -2801, -2801,  1881, -2801,  1880,  1886,  1888,
     157,  9554, -2801,   215, -2801, -2801,  1737,  9554, -2801, -2801,
    9554,  9554,  9554,  9554,  9554,  9554,    95,  9554,  9554,   273,
    1565,  1707,  9554,  9554,  9554,  9554,  9554,  9554,  9554, 15047,
    9554,  1866,  9554,  1551,  9554,  9554,   -30,  9554,  9554,  9554,
    9554,  9554,    29,    -8,  1867,  1573,  9554,  9554,  9554,  9554,
      92, -2801,  1240,   215,   670,   215,   516, -2801, -2801, -2801,
    1891,  1896, -2801, -2801, -2801, -2801,   -14,  1240,  9554,    96,
     658, 11294, 12314,    95, 15047, 15047,    95,    95,    95,    95,
      95, 15047,    95,    95,    95,    95,    95,    -1,    95,    95,
      95,    95,    10, 15047, 15047,    95,  1690,  1691,    95,    95,
      95,    95,    95,    95,    95,    95,    95, 15047,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95, 15047, 15047, 15047, 15047, 15047,    95,    95,    95,    95,
      95,    29,    29,   215,   215,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95, 15047,    95,
      95,    95,    95,    95,    95, 15047, 15047, -2801, -2801, -2801,
   -2801, -2801, -2801, -2801, -2801, -2801, -2801, -2801, -2801, -2801,
   -2801, 15047, 15047, 15047,    95, 15047, 15047,  1410, 15047, 15047,
   15047, 15047,   215, -2801, 11804, -2801, 12314,  6566, 15047, 15047,
   13252, 13252, 13252, 13252, 13252, 13252, 13252, 13252, 13252, 13252,
   15047, 15047, 15047, 15047, 15047,   174,   106,   215,   215,   215,
    9554,  1864,  1868,   215,  1869,  1890,  9554,  1889,  1892,  1893,
     215,  9554,  1877,  9554,  9554,   215,  9554,  9554,  9554,  9554,
    1240,  1791,  9554,  1808,  1899, -2801,  1882,  1903,   551,  1571,
   15047,   966,     6, 15047, -2801,    -9,  9554, -2801,  1906, -2801,
   -2801,  1907, -2801,  1908,    95,  9554,    95,  9554,  9554,  9554,
      95,    95,    95,    95,  9554,  9554,  9554,  9554,  9554,  9554,
    9554,    95,  9554,    95,    95,    95,    91,    95,   265,   271,
      95,    95,  9554,  9554,  9554,  9554,  9554,  9554,  9554,  9554,
    9554,  9554,  9554,  9554,  9554,  9554,  9554,    95, -2801, 15047,
   -2801,  1909,  9554,  9554,  9554,  9554,  9554,  9554,  9554,    95,
      95,    95, -2801, -2801,  9554,  9554, -2801,  9554, -2801, -2801,
     215, -2801,  1484,  1904,  1240, -2801, -2801, -2801, -2801, -2801,
   -2801, -2801,   206,   206, -2801,  9554, -2801,  9554,   215,    95,
      95,  9554, -2801,  9554,  9554,  9554,  1813,   215,    95,  1240,
      95,    95,  9554,  9554,  9554,  9554,  9554,  9554,  9554,  1240,
    9554,  9554,  1240,  9554,  9554,  9554,  9554,  9554,  9554, 15047,
    9554,  9554,  9554,  9554,  9554,  9554,  9554,  9554,    95, 15047,
    9554, 15047,  9554,  9554,    95,  9554,  9554,  9554, 15047,    95,
      29,    29,    29, 15047, 15047, 15047,   215, 15047,    95,    29,
      95,    29,    29, 15047,    14,  1240, 15047, 15047, 15047, 15047,
   15047,  1689,  9554, -2801,  9554,   215,  -268, 11294,   215,  9554,
    1894,  9554,  9554,   215,   215,   215,    -5,   215, -2801, -2801,
     252,  9554,  1911,  1947,   467,  1948,  1951,  1952,  1912,  1953,
    1960,  1955,  1962,  1963,  1964,  1959,  1965,  1966,  1971,  1972,
    1970,  1979,  1974,  1975,  1976,  1988,  1995,  1990,  1997,  1992,
     705,  1999,  2000,  1998,  2001,  2004,  2005,  2013,  2010,   706,
    2016,  2011,  2012,  2014,  2019,  2021,  1140,  2022,  2023,   312,
   13721, -2801,  1146,  2018,  2024,  2020, -2801, -2801, -2801,   708,
     710,  2025,  2026,  2027,  2030,  2028,  2029,  2033,  2034,  2035,
    2036,  2038,  2039,  2040,  2041, -2801, -2801,  2042,  2044,  2051,
    2048, -2801,  2059,  2060,  2054,  2055,  2056,  2064,  2065,  2066,
    2061,  2062,  2063,  2068,  2069,  2070,  2071,  2072,  2073,  2080,
    2081,  2082,  2077,  2084,  2079,  2083,  2085,  2086,  2087,   753,
    2088,  2089,  2090,  2091,  2092,  2093,  2094,  2101,  2097,  2099,
    2100,  2102,  2104,  2105,  1150,  1161,  2106,  2107,  2108,  2110,
    2111,  2112,  2115,  2119,  2122,  2123,  2126,  2128,  2129,  2136,
    2137,  2138,  2139,  2140,  2141,  2142,  2143,  2145,  2149,   754,
    2150,  2151,  2152,  2153,  2144,   755,   756,  2155,  2148,  1165,
     501,  1349,    92, -2801, -2801,  2162,  2158,   959,   761,   284,
    2164, -2801, -2801, -2801, -2801, -2801, -2801,   526,   545,   526,
     545, -2801, -2801, -2801, -2801, -2801, -2801, -2801, -2801, -2801,
     151, -2801,   151,   675, -2801,  1560,    60,  1231,  2146,  2168,
    2169,  2173,  2175, -2801,  1166,  1169,  1172,  2170,  2171,  2172,
     315,   764,   765,  2174,  2177,  2179,  2183,   372,  2184,  2181,
     766,  2185,  1176,  2186,  2187,  2188,  2195,   -30,  2194, 15047,
   -2801,  2199, 15424,  1637,  2196,  2200, 15047,    95,    95,   787,
    2203,  2198,   789,  2205,  2212,  2216,  2222,  2223,  2228,  2230,
    2231,  2232,  2233,  2234,  2235,  2236,  2237,  2238,  2239,  2240,
    2241,  2242,  2244,  2245,  2247,  2249,  2250,  2251,  2252,  2253,
    2254,  2255,  2256,  2257,  2258,  2259,  2260,  2262,  2261,  2264,
    2265,  2266,  2268,  2270,  2267,  2271,  2272, 15047,  2269,  2273,
     790,  2274,  2275,  2276,  2277,  2278,  2279,  2280,  2281,  2282,
    2289,   417,  9554,   215,   106,   106,  1984,  2043,  2045,  2047,
    2132,   813,   814,  2284,  2285,  1177,  2286,  2287, -2801,   348,
    2288,  2295, 12314,  1180,   815,  2296,  2297,  2292,   582,  2293,
     630,  2300,   822,  2298,  2299,   826,  2301,  2302,  2303,  2306,
     834,  2307,  2308,  2304,   836,  2309,  2305,  2310,  2311,  2312,
    2313,  2314,  2315,  2318,  2319,  2320,  2321,  2316,  2317,  2324,
    2325,  2322,  2326,  2327,  2329,   838,  2328,  2330,  2331,  2332,
    2333,    80,  2334,  2335,   843,  2336,  2337,  2338,  2339, -2801,
    1181,   845,  2340,  2341,  2342,  2343,  2283,  2348,  2349,  1184,
   -2801,   847,  1185,  2350,  2347,  2354,  2355,   447,  1240,  1240,
    1189,   215,    92, -2801, -2801,    95,  9554,  9554,  9554,  9554,
   -2801,  9554, -2801,  9554, -2801, -2801, -2801,    95,    95,  9554,
    9554,  9554, -2801, -2801,  9554,  9554,  9554,  9554, -2801,  9554,
   -2801,  9554, -2801,  9554, -2801, -2801,  9554,  9554,  9554,  9554,
   -2801,  1684, -2801,  9554, -2801,    95,  9554, 15047, -2801,  1942,
   -2801, -2801, -2801,  2067, 12314, -2801, -2801,  9554,   -26,  9554,
   -2801, 15047,   241,  9554,  9554, -2801,  9554,  9554,  9554,  9554,
    9554,  9554,  9554,  9554,  9554,  9554,  9554,  9554, -2801,  9554,
      95,    95, 15047, 15047,    95,    95,    95, -2801,  9554,  9554,
    9554,  9554,  9554,  9554,  9554,  9554,  9554, -2801, -2801, -2801,
      95, -2801,    95,    95,    95,    95,    95, -2801,    95,    95,
    9554,  9554,  9554,  9554, 15047, 15047, -2801,  9554,  9554,  9554,
    9554,    95,   215, -2801, -2801,    95,    95,  9554,  9554,  9554,
    9554,  9554,  9554,  9554,  9554,  9554,  9554,  9554, -2801, -2801,
   -2801, -2801, -2801, -2801, -2801,  9554,  9554,  9554, -2801,  9554,
    9554,    95,  9554,  9554,    95, -2801,  9554, -2801,  9554, 15047,
   -2801, -2801, -2801, -2801, -2801, -2801, -2801,  2229, -2801,  9554,
   -2801, 15047,  9554,    95,  2356,  2357,  2358, -2801, -2801, -2801,
    9554,  9554,  9554,  2217, -2801,   215, -2801,  9554,   215,   215,
     215,   215,   215,  9554, -2801, -2801,  9554,  9554, -2801,  9554,
    9554,  9554, -2801, -2801, -2801, -2801, -2801, 15047, -2801,  2359,
    2360,   852, -2801,    95, -2801,  9554, -2801,  9554, -2801, -2801,
   -2801, -2801, -2801, -2801, -2801, -2801, -2801, -2801, -2801, -2801,
   -2801,  9554, -2801, -2801,    95, -2801, -2801, -2801, -2801, -2801,
   -2801, -2801, -2801, -2801, -2801, -2801,  9554, -2801,  9554, -2801,
   -2801, -2801, -2801,  9554, -2801, -2801, -2801, -2801, -2801,  9554,
   -2801, -2801,  2361,  9554,  9554, -2801, 12314,  9554,  9554, -2801,
    9554,  9554,    95,    95,  9554,  9554, -2801,  9554,  1796,  1240,
   -2801, -2801, -2801, -2801, -2801, -2801, -2801, -2801,   679, -2801,
    9554,  9554, -2801,    95,  9554, -2801,  9554,  9554,  9554, -2801,
   -2801, -2801, -2801, -2801,  9554, -2801, -2801,  9554, -2801,  9554,
   -2801, -2801, -2801,  9554,  9554,  9554, -2801,  9554, -2801, -2801,
   -2801, -2801, -2801,  9554, -2801, -2801,  9554, -2801,  9554, -2801,
    9554,  9554,  9554, -2801, -2801, -2801, -2801, -2801, -2801, -2801,
   -2801,  9554,  9554, -2801, -2801,  9554, -2801, -2801, -2801, -2801,
    9554,  9554,  9554,  9554,  9554,  9554, -2801,  9554,  9554,  9554,
   -2801,  9554,  9554,  9554,  9554,  9554, -2801, -2801,  9554,  9554,
    9554, 12314, 15047,  9554, -2801, -2801, -2801, -2801, -2801, -2801,
    2323,  2362,  2364,  2290, -2801,  1190,  2365,  2366,  2367,  2372,
    2368,  2375,  2370,  2377,  2378,  2379,  2380,  2376,  2381,  2385,
    2382,  2383,  2384,  2386,  2391,  2387,  2388,  2389,  2390,  2397,
    2398,  2399,  2394,  9554,  2401,  2396,  2400,  2403,   857,  2402,
    2404,  2405,  2409,  2411,  2412,  2407,  2414,  2410,  2413,  2415,
    2416,  2417,  2418,  2419,  2420,  2427,  2422,  2423,  2424,  2425,
    2426,  2428,  2429,  2430,  2431,  2432,  2433,  2434,  2435,  2436,
    2443,  2438,  2439,  2440,  2441,  2442,  2444,  2449,  2451,  2446,
    2453,  2454,  2455,  2450,  2452,  2457,  2459,  2460,  2461,  2456,
    1193,  2463,  2458,  2462,  2464,  2466,  2472,  2473,  2474,  2475,
    2478,  2483,   859,  2482,  2484,  2486,  2487,  2489,  2490,  2491,
    2498,  2493,  2495,  2502,  2503,  2504,  2500,  2509, -2801,  2530,
    2532, -2801, -2801, -2801,  2533,   110,  2528,   113,  2529,  2536,
    1216,   138,  2537,  1217,  1220,  1221,   458,  1225,  2538,  2540,
    2535,  2542,  2545,  2546, -2801, -2801, -2801,  9554,  2547,  2543,
    2548,  2550,  2549,  2551,  2552,  2553,  2554, -2801,   860,   861,
     862,  2556,  2555,  2562,  2565,  2568,  2569,  2574,  2575,  2580,
    2558,  9554,   106,   106,  2197,  2214,  2374,  2508,  2519,   106,
    2587,  2582,  2583,  2584,   431,  2591,  2373,  2586,  2588,  2589,
    2590,  2592,  2593,  2594,  2601,  2596,  2598,  2599,  2600,  2602,
    2605,  2606,  2607,  2608,  2615,  2610,  2611,  2612,  2616,  2623,
     920,  2626,  2627,  2628,  2629,  2630,  2625,   932,  2632,  2634,
    2637,  2646,  2656,  2661,  2662,   215,   215,  2633, -2801,  9554,
   -2801,  9554, -2801,  9554, -2801,  9554, -2801, -2801, -2801, -2801,
    9554,  9554, -2801,  9554,  9554,  9554,  9554, -2801,  9554,  9554,
    9554,  9554, -2801, -2801, -2801,  9554, -2801, -2801,  9554,  9554,
   -2801, -2801,   107,   272,  9554, -2801, -2801, -2801, -2801,  9554,
   -2801,  9554,  9554,  9554,  9554,  9554,  9554,  9554,  9554, -2801,
    9554,  9554,  9554,  9554,  9554,  9554,  9554,  9554,  9554,  9554,
    9554,  9554,  9554,  9554, -2801,  9554,    95,    95,    95,    95,
      95, -2801, -2801,  9554, -2801, -2801, -2801,  9554,  9554, -2801,
   -2801, -2801, -2801, 15047, -2801, -2801, 15047,  9554,  9554, -2801,
   -2801, -2801, -2801, -2801, -2801, -2801, -2801,  9554,  9554,  9554,
    9554,  9554, -2801,  9554,  9554, -2801,  9554,  9554, -2801, -2801,
   -2801,  9554,  9554, -2801, -2801, -2801,  9554,  9554,  9554,  9554,
   -2801, -2801, -2801, -2801, -2801, -2801, -2801,   215, -2801, -2801,
   -2801,  9554, -2801, -2801, -2801,  2635, -2801,  9554, -2801, -2801,
      95,  9554, -2801,  9554,  9554, -2801, 15047, -2801, 15047, -2801,
   15047, -2801, 15047,  9554,  9554,  9554,    95,    95,  9554,  9554,
   -2801, -2801, -2801, -2801, -2801, -2801, -2801, -2801, -2801, -2801,
   -2801,  9554,    95,  9554, -2801,  9554,  9554, -2801,  9554,  9554,
    9554,  9554,  9554,  9554,  9554,  9554, -2801,  9554,  9554,  9554,
    9554,  9554,  9554,  9554,  9554,  9554, -2801,  9554,  9554,  9554,
    9554, -2801, -2801,    95, -2801, -2801, -2801, -2801, -2801, 15047,
   -2801,  9554,  9554,  9554,  9554, 15047, 15047,  9554,  9554,  1240,
    1240, -2801,  2636,   948,  2663,  2670,  2665,  2666,  2673,  2668,
    2669,  2676,  2675,  2679,  2680,  2682,  2681,  2683,   638,  2684,
    2685,  2688,  2687,   952,  2689,  2690,  2691,   960,   962,   965,
     979,  2692,  2693,  2694,  2695,  2702,   704,   983,   549,  2697,
    2698,  2699,  2700,   984,  2701,  2703,  2704,  2705,  2706,  2707,
    2708,  2709,  2710,  2711,  2712,  2713,  2714,  2715,  2722,  2723,
    2724,  2725,  2720,  2721,  2728,  2726,  2727,  2729,  2730,  2731,
    2733,  2734,  2735,  2585,  2624,  2736,  2740,  2737,  2744,   459,
    2745, -2801,  2741,  2746,  2742,  2749,  2747,  2750,   988,  2751,
    2748,  2752,  2755,  2753,   993,  2754,  2756,  2757,   106,  2758,
    2759,  2760,  2761,  2762,  2763,  2764,  2767,  2768,  2771,  2772,
    2773,  2774,  2775,  2776,  2777,  2778,  2779,  2780,  2781,  2782,
    2783,  2784,  2785,  2786,  2787,  2788,  2794,  2795,  2790,  2797,
    2792,  2793,  2796,  2800,  2801, -2801, -2801,  9554,  9554, -2801,
    9554,  9554, -2801,  9554,  9554, -2801,  9554,  9554,  9554, -2801,
    9554,  9554, -2801,   107,  9554, -2801, -2801,   107,  2291,  9554,
    9554, -2801,  9554, -2801,  9554, -2801,  9554, -2801,  9554,  9554,
    9554,  9554,  9554, -2801, -2801, -2801,  9554,  9554,  9554,  9554,
    9554,  9554, -2801, 15754, 15754, 15754,  9554,  9554,  9554,  9554,
   -2801,  9554,  9554,  9554,  9554,  9554,    95,  9554, -2801, -2801,
   -2801, -2801,  9554,  9554, -2801,  9554,  9554,  9554,  9554,  9554,
    9554, -2801,  9554,  9554,  9554,  9554, -2801,  9554, -2801,   215,
   -2801,  9554, -2801,  9554, -2801,  9554, -2801, -2801,  9554, -2801,
    9554,  9554, -2801,  9554, -2801, 15047,    95, -2801, -2801, -2801,
    9554,    95,  9554, -2801, -2801,  9554,  9554, -2801, -2801, -2801,
   -2801, -2801, -2801, -2801, -2801, -2801, -2801, -2801, -2801, -2801,
   -2801,  9554,  9554,  9554,  9554,  9554, -2801, -2801, -2801, 15047,
   -2801,  9554,  9554,  9554, -2801, -2801,  2798,  2803,  2805,  2802,
    2804,  2806,  2807,  2809,  2811,  2808,   995,  2810,  2812,  2813,
    1021,  2814,  2815,  1022,  1023,  2816,  2819,  2822,  2825,  2829,
    2817,  2832,  2833,  2835,  2836,  2837,  2838,  1218,  2847,  1222,
    2849,  2686,  2851,  2853,  2854,  2855,  2862,  2870,  2876,  2878,
    2879,  2880,  1024,  2881,  2890,  1025,  2897,  2902,  2904,  2899,
    2900,  2906,  2908,  2363,  2907,  2910,  2915,  1233,  2918,  1026,
    2916,  2921,  2923,  2919,  2924,  2927,  2928,  2929,  2930,  2931,
    2845,  2933,  2938,  2934,  2935,  2939,  2936,  2937,  2940,  2946,
    2947,  9554, -2801, -2801,  9554,  9554,  9554, -2801, -2801, -2801,
    9554, -2801,  9554,  9554,   215, -2801, -2801,   107,  9554,  9554,
   -2801,  9554, -2801,  9554,  9554,  9554,  9554,  9554,  9554, -2801,
    9554,  9554,  9554,  9554,  9554,  9554, 15754, -2801, 15754, -2801,
   -2801, 15754, 15754,  9554,  9554,  9554,    95,    95,    95,    95,
   -2801,  9554,  9554, -2801, -2801,  9554, -2801, -2801, -2801,  9554,
    9554,  9554, -2801, -2801,  9554, -2801, -2801, -2801, -2801, -2801,
    9554,  9554, -2801, -2801,  9554,  9554, -2801,    95,  9554,    95,
    9554,  9554, -2801, -2801,  9554,  9554, -2801,  9554, 15047,  9554,
    9554,  9554,  2944,  2948,  2949,  2950,  2954,  2945,  2955,   462,
    2962,  2963,  2958,  2965,  2966,  2967,  2968,  2969,  2970,  2971,
    1062,  2972,  2973,  2974,  2975,  2976,  2978,  2980,  2981,  2983,
    2979,  2984,  2986,  2987,  2988,  2985,  2989,  2990,  2991,  2992,
    2993,  2994,  2995,  2996,  2997,  2998,  2999,  3000,  3001,  3002,
    3003,  3004,  3011,  3006,  3007,  3008,  1076,  3009,  3010,  3012,
   -2801,  9554,  9554,  9554,  9554, -2801,  9554,  9554, -2801, -2801,
    9554, -2801, -2801, -2801, -2801, -2801, -2801,  9554, -2801,  9554,
   -2801,  9554, -2801, -2801,  9554, -2801, -2801, -2801, -2801, 15754,
   -2801, -2801, -2801, -2801,  9554,  9554, -2801,  9554, -2801,  9554,
   -2801,  9554,  9554,  9554, -2801,  9554,  9554,    95,  9554,    95,
    9554,  2147,  9554,  9554,  9554, -2801, 15047,  9554,  9554,  9554,
    3017,  3019,  3014,  3021,   179,  3016,  3018,  3020,  3023,  3025,
    3027,  3022,  3029,  3024,  3026,  3031,  3028,  3030, -2801,  3033,
    1080,  3032,  1089,  3034,  3035,  3036, 15047,  3037,  3038,  1090,
    3039,  3046,  1093,  3042, -2801, -2801,  9554, -2801, -2801,   215,
    9554,  9554, -2801, -2801, -2801,  9554, -2801,  9554,  9554, -2801,
    9554,  9554, -2801, -2801, 15047,  9554, -2801, 15047,  9554,  9554,
    9554, -2801,  9554,  9554, -2801,  9554,  9554, -2801, -2801,  9554,
    9554,  3043,  1234,  3053,  3054,  3055,  3057,  3056,  3060,  3062,
    3061,  3063,  3075,  3077,  3079,  3080,  3092,  3087,  3088,  3095,
    1103,  1107,  9554, -2801, -2801, -2801, -2801, -2801,  9554,  9554,
    9554, -2801, -2801, -2801,  9554,  9554,    95, -2801,  9554,  9554,
   -2801, -2801,  9554, -2801, 15047,  3090,  3093,  3100,  3096,  3103,
    3098,  3102,  3109,  3105,  3112,  3107,  9554,  9554, -2801,  9554,
   -2801,  9554,    95, -2801,  9554, -2801, 15047,  3108,  3115,  3113,
    3116,  3117,  3118,  3125,  9554, -2801,  9554,  9554,  9554, -2801,
   -2801,  3122,  3123,  3126,  3134,  9554,  9554,  9554, -2801,  3132,
    3133,  3135,  9554,  9554,  9554,  3140,  3136,  3137, -2801,  9554,
    9554,  3139,  3146,  9554, -2801,  3147, -2801
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  Parser::yydefact_[] =
  {
         2,   509,     0,     0,     0,     0,    21,    75,    76,    77,
      78,     0,     0,     0,   396,   407,    39,    20,     0,   110,
      82,     0,     0,     0,     0,     0,     0,     0,   109,     0,
       0,   386,   406,   859,   556,   410,   411,   412,   387,     0,
     819,     0,   775,     0,   868,   869,   870,   871,   872,   873,
       0,     0,   878,   879,     0,     0,    41,    44,    42,    43,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   321,
     322,   392,   323,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   545,   546,   547,   548,   549,
     550,   551,   552,   553,   554,     0,     0,     0,   408,   409,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   404,    40,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   349,   350,
     351,     0,     0,   510,     0,     0,     4,     8,    10,    14,
      16,    18,    12,     0,   388,   397,   400,     0,   414,   491,
     511,     0,   513,   517,   520,   521,   526,   531,   533,   535,
     537,   539,   541,   543,   544,   314,   485,     0,   777,   779,
     780,   798,   799,   803,   808,   809,   810,   811,   812,   813,
     814,   815,   816,   817,   818,   122,     0,     0,     0,     0,
       0,     0,   410,   411,   412,     0,   819,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   493,
       0,     0,   775,   495,   783,   494,   782,   387,     0,   485,
       0,     0,     0,     0,     0,   103,    83,    85,   115,   113,
     114,   112,   111,    84,   118,   125,   120,   119,   126,   121,
       0,     0,     0,   108,     0,     0,    93,    94,     0,    96,
      97,     0,   100,   101,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   358,   358,    38,    33,   426,     0,
       0,     0,     0,     0,   861,   860,   862,   874,   864,   865,
     866,   875,   867,   869,   871,   872,   873,   877,   876,   878,
     879,   863,   105,   106,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   496,   785,   497,   786,   502,   791,   503,   792,
     504,   793,   505,   794,   506,   795,   508,   797,   507,   796,
     498,   787,   499,   788,   500,   789,   501,   790,     0,    25,
       0,   404,    35,     0,    36,     0,     0,     0,    30,    28,
     404,     0,     0,     0,     0,     0,     0,     1,     3,     5,
       9,    11,    15,    17,    19,    13,     0,     6,     0,     0,
       0,     0,     0,     0,   492,   781,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   784,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   413,
       0,     0,   778,     0,     0,     0,     0,     0,     0,   878,
       0,     0,    95,    98,    99,   102,     0,     0,     0,     0,
       0,     0,   452,   453,   450,   451,   448,   449,   454,   455,
     456,     0,     0,     0,   129,     0,     0,     0,     0,   136,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   281,     0,     0,     0,     0,
     286,   287,     0,   270,     0,   278,     0,     0,     0,     0,
       0,   267,   268,     0,    57,    58,     0,     0,   124,     0,
       0,    74,     0,     0,     0,     0,     0,   566,     0,   373,
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
       0,     0,     0,   361,     0,   359,   570,   706,   708,   709,
     727,   729,   735,   736,   741,   742,   751,   756,   758,   759,
     761,   763,   765,   767,   769,   367,     0,     0,   334,     0,
     327,     0,   328,   479,   325,     0,     0,     0,     0,   332,
     333,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   329,   330,   331,   335,     0,     0,
       0,   336,   347,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   570,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   178,   179,     0,
       0,   457,   458,     0,     0,     0,     0,     0,     0,     0,
       0,   459,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   217,   218,   180,   181,   182,   183,     0,     0,   570,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   775,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   405,     0,    34,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,   398,
     399,   402,   401,   529,   530,   514,   515,   516,   518,   519,
     523,   522,   524,   525,   527,   528,   532,   534,   536,   538,
       0,   540,     0,     0,     0,   393,     0,   423,   425,     0,
     220,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     555,   424,    88,    87,    89,    86,   800,   802,   801,   804,
     806,   805,   807,   427,   428,   429,     0,     0,     0,   489,
       0,   254,     0,   249,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     248,     0,   240,     0,   250,   251,     0,     0,     0,     0,
       0,   259,   261,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     833,     0,     0,     0,     0,     0,   836,    62,     0,    52,
       0,     0,     0,     0,   566,     0,     0,     0,   770,    60,
       0,   833,     0,   546,   549,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    70,
       0,    68,    51,    56,    55,   836,    61,     0,     0,     0,
       0,     0,   512,     0,    80,    81,     0,     0,   394,   395,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     116,   123,   117,     0,     0,     0,   570,   727,   712,   711,
     485,     0,   363,   365,   369,   371,     0,   558,     0,     0,
       0,   358,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   713,   714,   719,
     720,   721,   722,   723,   725,   724,   715,   716,   717,   718,
     726,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   354,     0,   710,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     348,   820,     0,   557,     0,    45,     0,     0,   570,     0,
       0,     0,     0,     0,   435,     0,     0,   437,     0,   438,
     439,     0,   440,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   431,     0,
     436,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   315,   316,     0,     0,   433,     0,   776,   447,
       0,   318,     0,   404,   356,   403,   404,    26,   482,   483,
     484,   320,   375,   375,    32,     0,   262,     0,     0,     0,
       0,     0,   415,     0,     0,     0,     0,     0,     0,   219,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   223,
       0,     0,   224,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   831,     0,     0,     0,     0,
       0,     0,     0,    47,     0,     0,     0,   358,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   820,   557,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   707,     0,     0,     0,     0,   656,   654,   655,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   625,   626,     0,     0,     0,
       0,   629,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   374,   362,   360,   368,     0,     0,   883,     0,   882,
       0,   768,   734,   730,   732,   731,   733,   737,   739,   738,
     740,   748,   744,   747,   743,   749,   745,   750,   746,   754,
     752,   755,   753,   757,   760,   762,     0,   764,     0,     0,
       0,     0,     0,    37,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   542,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   830,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     771,     0,     0,     0,     0,     0,     0,     0,    71,    69,
       0,     0,   391,   390,   389,     0,     0,     0,     0,     0,
     152,     0,   155,     0,   128,   131,   130,     0,     0,     0,
       0,     0,   139,   140,     0,     0,     0,     0,   145,     0,
     154,     0,   271,     0,   266,   273,     0,     0,     0,     0,
     269,     0,   279,     0,   274,     0,     0,     0,   277,   460,
     486,   487,   488,     0,     0,   728,   559,     0,     0,     0,
     565,     0,     0,     0,     0,   605,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   606,     0,
       0,     0,     0,     0,     0,     0,     0,   637,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   590,   591,   592,
       0,   594,     0,     0,     0,     0,     0,   601,     0,     0,
       0,     0,     0,     0,     0,     0,   608,     0,     0,     0,
       0,     0,     0,   563,   564,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   681,   586,
     588,   650,   651,   652,   653,     0,     0,     0,   685,     0,
       0,     0,     0,     0,     0,   697,     0,   699,     0,     0,
     701,   702,   364,   366,   370,   372,   682,     0,   571,     0,
     612,     0,     0,     0,     0,     0,     0,   480,   481,   478,
       0,     0,     0,     0,   467,     0,   472,     0,     0,     0,
       0,     0,     0,     0,   339,   341,     0,     0,   477,     0,
       0,     0,   337,    59,    63,    54,    46,     0,   490,     0,
       0,     0,   312,     0,   166,     0,   165,     0,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   186,   187,
     188,     0,   201,   202,     0,   204,   212,   206,   207,   213,
     208,   214,   210,   211,   209,   189,     0,   199,     0,   190,
     215,   216,   195,     0,   191,   192,   193,   194,   197,     0,
     430,   446,     0,     0,     0,   294,     0,     0,     0,   301,
       0,     0,     0,     0,     0,     0,   774,     0,   404,   357,
      24,    27,   378,   379,   380,   376,   377,   404,     0,   404,
       0,     0,   346,     0,     0,   416,     0,     0,     0,   422,
      91,    90,   163,   162,     0,   221,   222,     0,   308,     0,
     310,   311,   158,     0,     0,     0,   156,     0,   241,   246,
     252,   253,   256,     0,   255,   225,     0,   237,     0,   233,
       0,     0,     0,   229,   230,   231,   232,   238,   247,   239,
     242,     0,     0,   235,   245,     0,   260,   264,   837,   838,
       0,     0,     0,     0,     0,     0,   834,     0,     0,     0,
     825,     0,     0,     0,     0,     0,   832,   847,     0,     0,
       0,     0,     0,     0,    49,    50,   773,    53,   324,    48,
       0,    66,    64,     0,   104,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,   766,     0,
       0,   691,   693,   694,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   441,   442,   443,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   445,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    79,     0,
     147,     0,   150,     0,   153,     0,   134,   132,   135,   137,
       0,     0,   142,     0,     0,     0,     0,   272,     0,     0,
       0,     0,   280,   275,   288,     0,   461,    73,     0,     0,
     577,   578,     0,     0,     0,   604,   607,   609,   610,     0,
     611,     0,     0,     0,     0,     0,     0,     0,     0,   630,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   589,     0,     0,     0,     0,     0,
       0,   602,   603,     0,   572,   573,   574,     0,     0,   657,
     658,   659,   660,     0,   705,   666,     0,     0,     0,   671,
     672,   673,   674,   675,   676,   677,   678,     0,     0,     0,
       0,     0,   686,     0,     0,   687,     0,     0,   696,   698,
     700,     0,     0,   692,   695,   326,     0,     0,     0,     0,
     466,   468,   471,   470,   473,   469,   474,     0,   475,   338,
     342,     0,   343,   344,   345,     0,   313,     0,   177,   200,
       0,     0,   203,     0,     0,   289,     0,   291,     0,   296,
       0,   295,     0,     0,     0,     0,     0,     0,     0,     0,
     317,   404,    22,    31,   383,   384,   385,   381,   382,    29,
     355,     0,     0,     0,   417,     0,     0,   421,     0,     0,
       0,     0,     0,     0,     0,     0,   257,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   840,     0,     0,     0,
       0,   835,   821,     0,   822,   826,   827,   828,   829,     0,
     848,     0,     0,     0,     0,     0,     0,     0,     0,    67,
      65,    72,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     485,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   444,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   146,   148,     0,     0,   127,
       0,     0,   144,     0,     0,   265,     0,     0,     0,   285,
       0,     0,   569,     0,     0,   579,   580,     0,     0,     0,
       0,   616,     0,   619,     0,   621,     0,   623,     0,     0,
       0,     0,     0,   627,   628,   661,     0,     0,     0,     0,
       0,     0,   638,     0,     0,     0,     0,     0,     0,     0,
     648,     0,     0,     0,     0,     0,     0,     0,   575,   576,
     704,   667,     0,     0,   679,     0,     0,     0,     0,     0,
       0,   690,     0,     0,     0,     0,   462,     0,   464,     0,
     340,     0,   205,     0,   196,     0,   290,   292,     0,   297,
       0,     0,   306,     0,   305,     0,     0,   432,   434,    23,
       0,     0,     0,   419,   420,     0,     0,   307,   309,   159,
     160,   418,   157,   234,   236,   226,   227,   228,   243,   244,
     258,     0,     0,     0,     0,     0,   823,   824,   849,     0,
     850,     0,     0,     0,   846,   772,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   881,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   151,   138,     0,     0,     0,   282,   283,   284,
       0,   567,     0,     0,     0,   581,   582,     0,     0,     0,
     615,     0,   618,     0,     0,     0,     0,     0,     0,   587,
       0,     0,     0,     0,     0,     0,     0,   639,     0,   641,
     643,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     599,     0,     0,   668,   669,     0,   680,   683,   684,     0,
       0,     0,   585,   613,     0,   463,   465,   476,   164,   184,
       0,     0,   293,   300,     0,     0,   304,     0,     0,     0,
       0,     0,   161,   839,     0,     0,   843,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     149,     0,     0,     0,     0,   568,     0,     0,   583,   584,
       0,   617,   620,   622,   624,   631,   634,     0,   663,     0,
     665,     0,   632,   635,     0,   640,   642,   644,   645,     0,
     647,   593,   595,   596,     0,     0,   600,     0,   670,     0,
     688,     0,     0,     0,   198,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   851,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   880,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   141,   143,     0,   276,   561,     0,
       0,     0,   633,   664,   662,     0,   646,     0,     0,   649,
       0,     0,   185,   298,     0,     0,   303,     0,     0,     0,
       0,    92,     0,     0,   845,     0,     0,   856,   855,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   562,   560,   614,   636,   597,     0,     0,
       0,   299,   319,   302,     0,     0,     0,   841,     0,     0,
     852,   853,     0,   857,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   703,     0,
     263,     0,     0,   842,     0,   854,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   598,     0,     0,     0,   844,
     858,     0,     0,     0,     0,     0,     0,     0,   353,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   133,     0,
       0,     0,     0,     0,   352,     0,   689
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
     -2801, -2801, -2801,   -46,  2201,  2202,  2204, -2801, -2801,  2621,
    2652,  2653,  2654, -2801,  -281,  1005, -2801,   640,  1747,  7705,
    -379, -2801, -2801, -2801, -2801,  -451,  6124,   572,  -401, -2801,
    -416,   666,  1954,  2006,  1989,  2002,  1968,  2346,   911, -2801,
       0,    81,  3420, -2801, -2801, -2801,  -528,  -132,  -127, -2801,
   -2801,  -299,  -109,  1207, -2801,  1188,  1578,  1404,  1485,   702,
    1479,  8085,  1661, -2801, -2801, -2801, -2801,   644,   723, -2801,
   -2801, -2801, -2801, -2801, -2801, -2801, -2801, -2801, -2801, -2801,
      13,  6781,  -444,    50,   -40, -2800
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,   144,   145,   146,   147,   148,   149,   870,   869,   150,
     151,   152,   153,  1363,   662,  1781,   154,   155,   156,   157,
     379,   380,  1365,   158,   159,   160,   228,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     238,   176,   240,   667,   668,   669,   670,   671,   672,   673,
     674,   675,   676,   677,   678,   679,   680,   681,   682,   683,
     684,  1101,  1033,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     241,   231,   997,   921,   198,  1640
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int Parser::yytable_ninf_ = -876;
  const short int
  Parser::yytable_[] =
  {
       175,   286,   863,  1036,   687,   890,   891,   892,   893,  1042,
       6,   871,    33,   195,   312,  1097,  1097,    14,   888,   889,
      34,    17,   255,   258,   905,   431,   206,   860,  1849,  1005,
     722,    25,    26,  1381,   206,   256,    29,    30,   211,   212,
      31,   929,   931,   440,    34,    14,   211,   280,   237,  -861,
     197,  1545,  1546,  -875,   536,   537,  -874,  1508,  1551,    25,
      26,   282,  1551,   212,    29,    30,   905,  1008,    31,   252,
     411,   444,    34,    33,   421,   422,   237,   291,  1464,  1527,
    1528,   382,  2041,  3008,  3010,  3012,   239,   242,  1243,    33,
     456,   212,   411,   206,  2226,   433,   457,   434,   287,   399,
    2227,   435,   446,   388,   411,   211,  1106,   407,  1097,  1097,
    1097,  1097,  1097,  1097,  1097,  1097,  1097,  1097,  1097,  1097,
    1097,  1097,   411,   447,    14,   411,   381,  -860,   243,     6,
    2596,     1,  1860,  2598,   838,   839,  1097,   840,    25,    26,
      17,   432,   244,    29,    30,   175,   411,    31,   432,    34,
     411,    34,  2602,    34,  1043,   237,  1234,  1235,   195,   411,
      71,   904,   905,   266,   267,    34,   261,  1047,   212,    33,
     212,  1382,   212,   378,   268,   445,   907,  1383,   281,   441,
    1385,   275,   389,   390,   212,   292,   283,   781,    71,   262,
     841,   411,  1552,  3308,   908,   197,  1552,  1244,   412,   413,
     277,   264,  1097,  1097,  1244,   436,   437,   423,   424,  1097,
    1097,  1097,  1097,  1097,  1097,  1097,  1097,  1097,  1097,  1097,
    1097,  1097,  1097,   265,   470,   471,   438,  1553,   771,   772,
     723,  1553,   412,   413,   933,   934,   935,   907,  -862,   456,
    1356,   269,   270,   464,   276,   461,    14,   975,   976,   977,
     412,   413,   271,   412,   413,   908,   978,   979,   980,   981,
      25,    26,  1731,   982,   411,    29,    30,    71,   472,    31,
     906,   473,  1871,    34,   474,   284,  1856,   237,   412,   413,
     533,   534,   239,  1668,   665,   665,   939,  1668,    33,  1236,
    1237,   724,   212,   726,   535,  2288,  3176,   456,  3177,    34,
     411,  3178,  3179,   461,   983,   278,   279,   984,   985,   986,
     987,     6,   988,   989,   728,   729,   990,   755,   212,   412,
     413,   289,    17,    34,   411,   288,  2723,   411,  1223,    34,
      34,    34,  1923,   907,  1224,  2053,  1483,   864,   933,   934,
     935,   290,   212,   832,   833,   866,   835,   837,   212,   212,
     212,   908,   272,   273,   909,   910,   911,   912,   861,   285,
     878,   856,  2165,   274,    34,  1102,  1103,   918,  2166,     6,
     206,  2167,  1669,  1670,  1671,  1672,  1669,  1670,  1671,  1672,
      17,   293,   211,   212,   411,   397,   913,   914,   915,    71,
     939,   872,  2062,   248,  1012,   314,    33,   920,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   249,   250,   251,
     881,  1098,  1099,   933,   934,   935,   920,   315,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   918,   411,
     408,   409,   410,   902,   903,   865,  1734,  2147,   924,  3282,
    1382,   316,  1736,  1526,   245,  2654,  1383,  1031,  1384,  1385,
     319,  2655,  1038,  1039,  2656,   317,  1040,   318,   920,   411,
    1034,   538,   539,   540,   541,   939,  1668,  2253,  1366,   324,
     411,   411,  1097,  1097,   411,   991,   992,   993,  2607,  2919,
     456,   994,  3217,   995,   419,   420,   461,  1876,  1097,  1097,
    1097,  1097,  1097,  1097,  1097,  1097,  1097,  1097,  1097,  1097,
    1097,   320,  1097,   321,  1197,  1198,  1199,  1200,  1201,  1202,
    1203,  1204,  1205,  1206,  1207,  1208,  1209,  1210,   916,   917,
    1226,   325,  1227,  1283,   918,  1227,   461,    93,    94,  1226,
    1339,  1227,  1225,   416,   417,   457,  1091,   919,   418,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,  1229,
     425,   426,  1230,  1231,   920,  1669,  1670,  1671,  1672,    34,
    2032,  2033,   456,   326,  1283,   206,  1227,  1126,   461,  2877,
    1703,   442,   443,  1127,   229,   233,   235,   211,   212,   842,
     843,   844,   845,   846,   847,   813,   814,   848,   849,   850,
     851,   852,   853,   854,   327,   456,  2178,  1246,  1098,  1099,
     764,   461,   322,  1224,   323,  1197,  1198,  1199,  1200,  1201,
    1202,  1203,  1204,  1205,  1206,  1207,  1208,  1209,  1225,   815,
     816,   689,  1126,   691,   328,   693,  1100,   695,  1281,   697,
     698,   329,  1501,   701,   702,   703,   704,   705,   706,   707,
     708,   539,   540,   456,  2180,   713,   330,   234,   236,   461,
     143,   456,  2852,   765,   766,   767,   768,   461,   333,   769,
     770,   771,   772,   773,   774,   775,   776,   777,   778,   779,
     780,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     771,   772,   352,   354,   356,   358,   360,   362,   364,   366,
     368,   370,   372,   374,   376,  1776,  1777,  1778,  1779,  1780,
     334,  1097,  1097,  1097,  1097,  1097,  1097,  1097,  1097,  1097,
    1097,  1097,  1097,  1097,  1097,  1097,  1097,   456,  2874,  1902,
    1912,   428,  1930,   461,  1287,  1903,  1913,  1274,  1224,  1517,
    1931,   335,  1518,   414,    34,   294,   295,   296,   297,   298,
     299,   300,   301,   302,    44,   303,    46,   304,   305,   306,
     307,   308,   309,   310,   353,   355,   357,   359,   361,   363,
     365,   367,   369,   371,   373,   375,   377,  1977,  2018,  2025,
    2027,   233,   235,  1978,  2019,  2026,  2028,  2038,  2054,  2056,
    2065,  1232,  1233,  2039,  2055,  2057,  2066,   352,   354,   356,
     358,   360,   362,   364,   366,   368,   370,   372,   374,   376,
     414,  2082,   427,  2086,  2135,   415,  1106,  2083,  1454,  2087,
    2136,   336,   331,  1277,   332,  1238,  1239,  1367,  1651,  1653,
    1655,  1657,  1659,  1661,    14,  1374,   429,  2157,  2159,  2173,
    1529,  1647,  1649,  2158,  2158,  2174,  2182,   337,    25,    26,
    2186,   338,  2183,    29,    30,   339,  2187,    31,  2192,   430,
    2197,    34,  2219,   688,  2193,   237,  2198,  2230,  2220,  2237,
    1362,  2247,   411,  2231,  1045,  2238,  2396,  1224,  1098,  1099,
     212,  2511,  2397,  2576,  2625,  2627,  2629,  2512,   340,  2577,
    2626,  2628,  2630,   341,  1197,  1198,  1199,  1200,  1201,  1202,
    1203,  1204,  1205,  1206,  1207,  1208,  1209,   411,  1225,  1046,
     408,   409,   689,   690,   691,   692,   693,   694,   695,   696,
     697,   698,   699,   700,   701,   702,   703,   704,   705,   706,
     707,   708,   709,   710,   711,   712,   713,   714,   715,   716,
     717,   718,   719,   720,  2682,  1652,  1654,  1656,  1658,   511,
    2683,   512,     6,   513,   514,   439,  2690,  1112,   342,   318,
      14,   515,  2691,    17,   516,   517,   518,   519,   520,   521,
     522,   523,  2836,  1453,    25,    26,  2856,    71,  2837,    29,
      30,   343,  2857,    31,  2861,   448,  2863,    34,   449,  2865,
    2862,   237,  2864,   344,  1774,  2866,   345,  1775,   885,   886,
     887,   524,  1925,  2867,   346,   525,   212,  2875,  2882,  2868,
     526,   527,  2927,  2876,  2883,  1527,  1528,  2934,  2928,  3071,
     347,   528,   926,  2935,   348,  3072,   529,   530,  1545,  1546,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,  3076,  3080,  3082,  3110,  3114,
    3129,  3077,  3081,  3083,  3111,  3115,  3130,  1472,   879,   880,
    1473,  1475,  1476,  1477,  1478,  1479,   349,  1481,  1482,  1283,
     350,  1227,  1487,  1488,  1489,  1490,  1491,  1492,  1493,  1042,
    1495,   411,  1497,  1359,  1499,  1500,  3228,  1502,  1503,  1504,
    1505,  1506,  3229,  1100,   927,   928,  1512,  1513,  1514,  1515,
    3265,   894,   895,    71,  3323,   351,  3266,  1642,  1644,  1646,
    3324,   491,   450,  3326,  3334,  1648,  1650,  3338,  1525,  3327,
    3335,   665,   755,  3339,   385,   233,   235,  3381,  1444,   386,
    1459,  3383,   411,  3382,  1370,   387,   411,  3384,  1376,  1660,
    1662,   492,   493,   494,   495,   496,    14,   497,   498,   499,
     500,   501,   502,   503,   504,   505,   506,   507,   508,   391,
      25,    26,   411,   451,  1920,    29,    30,   392,   411,    31,
    1926,   393,   411,    34,  1993,   930,   932,   237,  2424,  2425,
    2426,  2427,  2428,   411,  1925,  1994,  1861,   411,   411,  2031,
    2047,   411,   212,  2048,   411,   452,  2049,  1523,   411,   411,
    2068,  2162,   411,   411,  2172,  2236,   411,   411,  2246,  2248,
    1673,   411,   411,  2254,  2478,   411,   453,  2564,   352,   354,
     356,   358,   360,   362,   364,   366,   368,   370,   372,   374,
     376,   721,   394,   395,  1633,   509,  1040,  1638,   411,   411,
    2601,  2604,   411,   411,  2605,  2606,   414,   411,  3096,  2608,
    2039,   396,  3098,   510,  2039,   411,   411,  3127,  3363,   280,
    1677,   454,   411,  2073,   455,   459,  1683,   458,   460,   462,
     725,  1688,   466,  1690,  1691,   542,  1693,  1694,  1695,  1696,
     727,   874,  1698,   830,  1037,   781,  1044,   831,   868,    71,
     905,   862,  1048,  1049,  1050,  1051,  1705,  1052,  1053,  1054,
    1055,  1056,  1057,  1058,  1059,  1710,  1060,  1712,  1713,  1714,
    1061,  1062,  1063,  1064,  1719,  1720,  1721,  1722,  1723,  1724,
    1725,  1065,  1727,  1066,  1067,  1068,  1069,  1070,  1071,  1072,
    1073,  1074,  1740,  1741,  1742,  1743,  1744,  1745,  1746,  1747,
    1748,  1749,  1750,  1751,  1752,  1753,  1754,  1075,  1076,  1077,
    1078,  1079,  1758,  1759,  1760,  1761,  1762,  1763,  1764,  1080,
    1081,  1082,  1083,  1084,  1768,  1769,  1085,  1770,  1228,  1086,
    1087,  1088,  1089,  1093,  1094,  1095,  1108,  1242,  1109,  1111,
    1113,  1114,  1115,  1110,  1116,  1783,  1117,  1784,  1118,  1119,
    1120,  1121,  1122,  1789,  1790,  1791,  1123,  1124,  1125,  1128,
    1129,  1130,  1797,  1799,  1801,  1802,  1803,  1804,  1805,  1131,
    1806,  1807,  1132,  1808,  1809,  1810,  1811,  1812,  1813,  1133,
    1815,  1816,  1817,  1818,  1819,  1820,  1821,  1822,  1134,  1135,
    1825,  1136,  1827,  1828,  1138,  1830,  1831,  1832,    33,    34,
     294,   295,   296,   297,   298,   299,   300,   301,   302,    44,
     303,    46,   304,   305,   306,   307,   308,   469,   310,  1137,
    1139,  1140,  1857,  1141,  1858,  1142,  1143,   665,  1144,  1863,
    1145,  1865,  1866,  1146,  1147,  1148,  1149,  1150,  1151,  1152,
    1153,  1873,  1154,  1155,  1156,  1157,  1158,  1159,  1160,  1161,
    1162,  1163,   234,   236,  1164,  1444,   353,   355,   357,   359,
     361,   363,   365,   367,   369,   371,   373,   375,   377,   415,
    1165,  1166,  1167,    14,  1168,  1217,  1169,  1170,  1171,  1172,
    1173,  1174,  1175,  1097,  1176,  1177,  1178,    25,    26,  1179,
    1180,  1181,    29,    30,  1182,  1183,    31,  1184,  1185,  1186,
      34,  1187,  1188,  1189,   237,  1190,  1191,  1192,  1193,  1194,
    1195,  1196,  1211,  1212,  1213,  1214,  1215,  1216,  1218,   212,
      34,   294,   295,   296,   297,   298,   299,   300,   301,   302,
      44,   303,    46,   304,   305,   306,   307,   308,   469,   310,
    1219,  1220,   233,   235,  1221,  1222,  1240,  1247,  1241,  1248,
    1249,  1250,  1245,  1251,   933,   934,   935,   936,   352,   354,
     356,   358,   360,   362,   364,   366,   368,   370,   372,   374,
     376,  1252,   414,  1253,  1254,  1255,  1256,  1257,  1258,  1259,
    1260,  1261,  1262,  1263,  1264,  1265,  1266,   937,  1267,  1268,
    1269,  1485,  1498,  1275,  1271,   938,  1272,  1280,  1273,  1511,
    1276,  1284,  1279,  1287,  1282,  1285,   939,  1288,  1286,  1289,
     940,  1451,  1290,  1292,   234,   236,    71,  1291,  1293,  1295,
    1294,  1296,  1297,  1298,  1299,  1300,  1301,  1302,  1303,  1304,
     353,   355,   357,   359,   361,   363,   365,   367,   369,   371,
     373,   375,   377,  1305,   415,  1306,  1307,  1308,  1309,  1310,
    1311,  1312,  1313,   941,  1314,   942,   943,   944,  1315,  1316,
    1317,  1318,  1319,  1320,  1321,  1322,   945,   946,  1323,  1324,
    1325,  1326,   947,   948,   949,   950,  1327,  1328,  1329,  1330,
    1331,  1332,  1333,  1334,  1335,  1336,  1372,   951,   952,   953,
     954,   955,  1338,   956,   957,   958,  1337,  1340,  2150,  2151,
     959,   960,   961,   962,   963,   964,   965,   966,   967,   968,
     969,   970,   971,   972,   973,  1341,  1342,  1343,  1344,  1471,
    1345,  1346,  1347,  1348,  1349,  1350,  1351,  1352,  1353,  1354,
    1355,  1357,  1358,  1361,  1368,  1360,  1369,  1371,  1373,  2422,
    1486,  1375,  2148,  1387,  1377,  1388,  1378,  1379,  2423,  1380,
    2429,  1386,  1390,  1391,  1392,  1393,  1394,  1395,  1396,  1397,
    1398,  1400,  2170,  1401,  1403,  1404,  1405,  1406,  1407,  1408,
    1409,  1410,  1643,  1645,   781,   782,   783,   784,   785,   786,
     787,   788,   789,  1411,   790,   791,   792,   793,   794,   795,
     796,   797,   798,   799,   800,   801,   802,   803,   804,   805,
     806,   807,   808,   809,   810,  1412,  1413,  1414,  1415,  1416,
    1417,  1418,  1419,  1420,  1421,  1422,  1423,  1424,  1425,  1426,
     811,   812,  1427,  1428,  1429,   974,  1430,  1431,  1432,  1433,
    1434,  1435,  1436,  1437,  1438,  1439,  1440,  1441,  1442,  1443,
    1446,  1447,  1448,  1449,  1450,  1455,  2257,  2258,  2259,  2260,
    1452,  2261,  1456,  2262,  1457,  1458,  1460,  1461,  1462,  2265,
    2266,  2267,  1463,  1467,  2268,  2269,  2270,  2271,  1465,  2272,
    1466,  2273,  1468,  2274,  1469,  1520,  2275,  2276,  2277,  2278,
    1521,  1557,  1558,  2279,  1624,  1700,  2281,  1702,  1526,  1706,
    1707,  1708,  1757,  1678,  1773,  1874,  1880,  2285,  1679,  2286,
    1681,  1496,  1510,  2290,  2291,  1697,  2292,  2293,  2294,  2295,
    2296,  2297,  2298,  2299,  2300,  2301,  2302,  2303,  1689,  2304,
    1682,  1684,  1699,  1701,  1685,  1686,  1772,  1792,  2312,  2313,
    2314,  2315,  2316,  2317,  2318,  2319,  2320,  1875,  1877,  1864,
    1856,  1878,  1879,  1881,  1882,  1883,  1884,  1885,  1886,  1887,
    2329,  2330,  2331,  2332,  1892,  1888,  1889,  2335,  2336,  2337,
    2338,  1890,  1891,  1893,  1894,  1895,  1896,  2343,  2344,  2345,
    2346,  2347,  2348,  2349,  2350,  2351,  2352,  2353,  1897,  1898,
    1899,  1900,  1901,  1904,  1905,  2354,  2355,  2356,  1906,  2357,
    2358,  1907,  2360,  2361,  1908,  1909,  2363,  1910,  2364,  1911,
    1914,  1915,  1916,  1918,  1917,  1919,  1921,  1922,  1927,  2367,
    1929,  2152,  2369,  1928,  1935,  1932,  1933,  1934,  1936,  1937,
    2374,  2376,  2378,  1938,  1939,  1940,  1941,  2382,  1942,  1943,
    1944,  1945,  1946,  2388,  1947,  1948,  2389,  2390,  1949,  2391,
    2392,  2393,  1950,  1951,  1952,  1953,  1954,  1955,  1956,   920,
    1957,  1958,  1959,  1960,  1860,  2399,  2283,  2400,  1961,  1962,
    1963,  1964,  1965,  1966,  1967,  1968,  1969,  1970,  1971,  1972,
    2153,  2401,  2154,  1973,  2155,  1974,  1975,  1976,  1979,  1980,
    1981,  1982,  1983,  1984,  1985,  1986,  2403,  1987,  2404,  1988,
    1989,  2284,  1990,  2405,  1991,  1992,  1995,  1996,  1997,  2406,
    1998,  1999,  2000,  2408,  2409,  2001,  2410,  2412,  2413,  2002,
    2414,  2415,  2003,  2004,  2418,  2419,  2005,  2420,  2006,  2007,
    2008,  2009,  2010,  2011,  2012,  2013,  2014,  2024,   882,  2042,
    2430,  2431,  2030,  2015,  2433,  2016,  2434,  2435,  2436,  2017,
    2020,  2021,  2022,  2023,  2437,  2029,  2036,  2438,  2037,  2439,
    2040,  2043,  2044,  2440,  2441,  2442,  2045,  2443,  2046,  2156,
    2050,  2051,  2052,  2444,  2058,  2064,  2445,  2059,  2446,  2060,
    2447,  2448,  2449,  2061,  2063,  2067,  2069,  2070,  2071,  2072,
    2074,  2450,  2451,  2076,  2078,  2452,  1931,  2084,  2085,  2088,
    2453,  2454,  2455,  2456,  2457,  2458,  2089,  2459,  2460,  2461,
    2090,  2462,  2463,  2464,  2465,  2466,  2091,  2092,  2467,  2468,
    2469,  2470,  2093,  2473,  2094,  2095,  2096,  2097,  2098,  2099,
    2100,  2366,  2102,  2103,  2644,  2105,  2106,  2101,  2107,  2108,
    2104,  2109,  2798,  2110,  2111,  2112,  2113,  2114,  2115,  2421,
    2117,  2645,  2119,  2120,  2121,  2116,  2122,  2118,  2124,  2125,
    2126,  2123,  2127,  2506,  2128,  2130,  2131,  2129,  2379,  2133,
    2139,  3296,  1788,  2134,  2137,  2138,  2243,  2140,  2141,  2142,
    2143,  2144,  2145,  2146,  2160,  2161,  2163,  2164,  2168,  2169,
    2175,  2176,  2177,  2179,  2181,  2188,  2189,  2190,  2184,  2185,
    2191,  2194,  2195,  2199,  2196,  2200,  2203,  2204,  2205,  2206,
    2201,  2202,  2207,  2208,  2209,  2210,  2211,  2212,  2213,  2214,
    2216,  2217,  2215,  2218,  2477,  2990,   400,   401,  2221,   402,
    2222,  2223,  2224,  2225,  2228,  2229,  2232,  2233,  2234,  2235,
    2239,  2240,  2241,  2242,  2244,  2245,  2249,  2250,  2251,  2252,
    2371,  2372,  2373,  2394,  2395,  2407,  2642,  2643,  1782,  3123,
    2480,   896,  2475,  2649,  2476,  2479,  2482,  2481,  2483,  2484,
    2485,  2486,  2487,  2488,  2489,  2658,  2490,  2615,  2474,  2492,
     901,  2491,  2493,  2494,  2495,  2497,  2496,  2498,  2499,  2500,
    2501,  2502,  2503,  2504,  2505,  2507,  2508,  2510,   898,  2515,
    2509,  2641,  2513,  2516,  2514,  2517,  2518,  2519,  2520,  1664,
    2521,  2646,   899,  2522,   897,  2523,  2524,  2525,  2526,  2527,
    2528,  2529,  2530,  2531,  2532,  2533,  2534,  1663,  2535,  2536,
    2537,  2538,  2539,  2540,  2541,  2542,  2543,  2544,  2545,  2546,
    2547,  2548,  2549,  2551,  2550,  2552,  2553,  2554,  2555,  2556,
    2557,  2559,  2558,  2560,  2561,  2562,  2563,  2565,  2566,  2702,
    2569,  2703,  2567,  2704,  2568,  2705,  2570,  2571,  2572,  2573,
    2706,  2707,  2574,  2708,  2709,  2710,  2711,  2575,  2712,  2713,
    2714,  2715,  2578,  2582,  2579,  2716,  2580,  2581,  2717,  2719,
    2583,  2584,  2585,  2586,  2725,  2587,  2588,  2589,  2590,  2726,
    2591,  2727,  2728,  2729,  2730,  2731,  2732,  2733,  2734,  2592,
    2735,  2737,  2739,  2740,  2741,  2742,  2743,  2744,  2745,  2746,
    2747,  2748,  2749,  2750,  2593,  2751,  2594,  2595,  2597,  2599,
    2600,  2603,  2609,  2757,  2610,  2611,  2612,  2758,  2759,  2613,
    2614,  2616,  2618,  2617,  2619,  2647,  2622,  2762,  2763,  2620,
    2631,  2621,  2640,  2623,  2624,  2632,  2648,  2764,  2765,  2766,
    2767,  2768,  2633,  2769,  2770,  2634,  2771,  2772,  2635,  2636,
    2720,  2773,  2774,  2721,  2637,  2638,  2775,  2776,  2777,  2778,
    2639,  2650,  2651,  2652,  2653,  2657,  2659,  2913,  2660,  2661,
    2662,  2780,  2663,  2664,  2665,  2666,  2667,  2782,  2668,  2669,
    2670,  2784,  2671,  2785,  2786,  2672,  2673,  2674,  2675,  2676,
    2677,  2678,  2679,  2791,  2792,  2793,  2680,  2681,  2796,  2797,
    2684,  2685,  2686,  2687,  2688,  2689,  2914,  2701,  1667,  2781,
    2835,  2799,  2692,  2801,  2693,  2802,  2803,  2694,  2804,  2805,
    2806,  2807,  2808,  2809,  2810,  2811,  2695,  2812,  2813,  2814,
    2815,  2816,  2817,  2818,  2819,  2820,  2696,  2821,  2822,  2823,
    2824,  2697,  2698,  2838,  2839,  2840,  2841,  2842,  2843,  2844,
    2845,  2827,  2828,  2829,  2830,  2846,  2849,  2833,  2834,  2847,
    2848,  2850,  2855,  2851,  2853,  2854,  1703,  1641,  2039,  2858,
    2859,  2860,  2869,  2870,  2871,  2872,  2873,  2878,  2879,  2880,
    2881,  2884,  2890,  2885,  2886,  2887,  2888,  2889,  1666,  2891,
    2892,  2893,  2894,  2895,  2896,  2897,  2898,  2899,  2900,  2901,
    2902,  2903,  2904,  2368,  1509,     0,  2905,  2906,  2911,  2907,
    2908,  2909,  2939,  2910,  2916,  2912,  2915,  2917,  2918,  2920,
    2922,  2921,  2923,  2924,  2926,  2929,   403,  2925,  2930,  2932,
    2937,  2938,  2931,  2933,  2936,  2943,  2944,   900,  2940,  2941,
    2942,  2947,  2948,  2945,  2946,  2949,  2950,  2951,  2952,  2953,
    2954,  2955,  2956,  2957,  2958,  2959,  2960,   404,   405,   406,
       0,     0,  2966,  2961,  2962,  2963,  2964,  2965,  2967,  2968,
    2969,  2970,  2971,  2972,  2974,  2975,  2973,  3062,  3061,  3063,
    1665,  3067,  3064,  3068,  3065,  3069,  3066,  3075,  3070,     0,
    3073,  3089,  3074,     0,  3078,  3079,  3084,  2976,  2977,  3085,
    2978,  2979,  3086,  2980,  2981,  3087,  2982,  2983,  2984,  3088,
    2985,  2986,  3090,  3091,  2988,  3092,  3093,  3094,  3095,  2991,
    2992,  3097,  2993,  3099,  2994,  3100,  2995,  3141,  2996,  2997,
    2998,  2999,  3000,  3101,  3102,  3103,  3001,  3002,  3003,  3004,
    3005,  3006,  3104,  3007,  3009,  3011,  3013,  3014,  3015,  3016,
    3105,  3017,  3018,  3019,  3020,  3021,  3106,  3023,  3107,  3108,
    3109,  3112,  3024,  3025,  3113,  3026,  3027,  3028,  3029,  3030,
    3031,  3116,  3032,  3033,  3034,  3035,  3117,  3036,  3118,  3119,
    3120,  3038,  3122,  3039,  3125,  3040,  3121,  3124,  3041,  3126,
    3042,  3043,  3128,  3044,  2987,  3132,  3131,  3133,  2989,  3134,
    3047,  3136,  3049,     0,  3135,  3050,  3051,  3142,  3137,  3138,
    3139,  3140,  3143,  3146,  3144,  3145,  3147,  3148,  3210,  3215,
    3149,  3052,  3053,  3054,  3055,  3056,  3150,  3151,  3211,  3212,
    3213,  3058,  3059,  3060,  3214,  3216,  3218,  3219,  3220,  3221,
    3222,  3223,  3224,  3225,  3226,     0,  3230,     0,  3232,  3233,
       0,  3227,  3235,  3231,  3236,  3237,  3234,  3238,  3240,  3239,
    3241,  3242,  3243,     0,  3246,  3244,  3248,     0,  3250,  3245,
       0,  3247,  3254,  3249,     0,  3251,     0,  3253,  3252,  3255,
    3256,  3257,  3258,  3259,  3260,  3261,  3262,  3263,  3264,  3267,
    3268,  3304,  3269,  3305,  3306,  3307,  3309,  3312,  3310,  3313,
    3311,  3314,  3315,  3316,  3317,  3319,  3318,  3322,  3320,     0,
    3321,     0,  3325,     0,  3328,  3329,  3330,  3332,  3333,  3336,
    3337,  3152,  3340,  3362,  3153,  3154,  3155,  3364,  3365,  3366,
    3156,  3367,  3157,  3158,     0,  3371,  3368,  3372,  3161,  3162,
    3369,  3163,  3370,  3164,  3165,  3166,  3167,  3168,  3169,  3373,
    3170,  3171,  3172,  3173,  3174,  3175,  3011,  3374,  3011,  3375,
    3376,  3011,  3011,  3180,  3181,  3182,  3377,  3378,  3379,  3380,
    3396,  3187,  3188,  3397,  3398,  3189,  3399,  3400,  3401,  3190,
    3191,  3192,  3402,  3403,  3193,  3404,  3405,  3406,  3414,  3415,
    3194,  3195,  3419,  3416,  3196,  3197,  3417,  3418,  3199,  3420,
    3201,  3202,  3425,  3426,  3203,  3204,  3427,  3205,  3428,  3207,
    3208,  3209,  3432,  3433,  3438,  3434,  3439,  3440,  3160,  3443,
    3444,  3446,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3270,  3271,  3272,  3273,     0,  3275,  3276,     0,     0,
    3277,     0,     0,     0,     0,     0,     0,  3278,     0,  3279,
       0,  3280,     0,     0,  3281,     0,     0,     0,     0,  3011,
       0,     0,     0,     0,  3283,  3284,     0,  3285,     0,  3286,
       0,  3287,  3288,  3289,     0,  3290,  3291,     0,  3293,     0,
    3295,     0,  3297,  3298,  3299,     0,     0,  3301,  3302,  3303,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3341,     0,     0,     0,
    3343,  3344,     0,     0,     0,  3345,     0,  3346,  3347,     0,
    3348,  3349,     0,     0,     0,  3351,     0,     0,  3353,  3354,
    3355,     0,  3356,  3357,     0,  3358,  3359,     0,     0,  3360,
    3361,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3385,     0,     0,     0,     0,     0,  3386,  3387,
    3388,     0,     0,     0,  3389,  3390,     0,     0,  3392,  3393,
       0,     0,  3394,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3407,  3408,     0,  3409,
       0,  3410,     0,     0,  3412,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3421,     0,  3422,  3423,  3424,     0,
     177,     0,   230,   230,   230,  3429,  3430,  3431,     0,     0,
       0,     0,  3435,  3436,  3437,     0,     0,     0,   246,  3441,
    3442,   253,     0,  3445,   260,     0,     0,   260,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     0,     2,     3,
       4,     0,     5,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   311,   260,     0,     0,     0,     0,
      14,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    25,    26,     0,     0,     0,    29,
      30,     0,     0,    31,     0,    32,     0,    34,   202,   203,
     204,   237,   205,   206,     0,   232,   208,     0,     0,     0,
       0,     0,   209,   210,     0,   211,   212,     0,     0,     0,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,     0,     0,     0,     0,   260,   260,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   177,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   230,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    62,    63,    64,    65,    66,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   213,     0,     0,     0,     0,   230,
     230,     0,     0,    71,     0,   214,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   260,     0,   260,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    76,     0,     0,     0,     0,
       0,   260,   260,     0,   311,   311,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   260,     0,     0,     0,     0,
       0,     0,     0,     0,   666,   666,     0,     0,    77,     0,
      78,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   751,   666,   751,   751,
     751,   751,   751,   751,   763,     0,     0,     0,     0,   817,
     818,   819,   751,   822,   823,   824,   825,   826,   827,   828,
     829,     0,     0,     0,     0,   834,   836,     0,     0,   260,
     751,   859,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    92,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   311,   260,     0,     0,     0,
       0,     0,   260,     0,   875,   876,   877,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   260,   260,
       0,   260,   260,   260,     0,     0,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,     0,     0,     0,
       0,     0,    93,    94,     0,     0,   751,   751,   666,     0,
     230,     0,   230,   230,     0,     0,   751,   666,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     230,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,     0,   105,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   108,   109,   110,   111,   112,   113,   114,   115,
       0,     0,   116,   117,   118,   119,   120,   121,   122,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   129,   130,     1,     0,     2,     3,
       4,     0,     5,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   260,     0,     0,
       0,    15,     0,  1096,  1096,   666,  1104,   260,     0,     0,
       0,     0,     0,     0,     0,   143,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    32,     0,    34,   202,   203,
     204,     0,   205,   206,     0,   232,   208,     0,     0,     0,
       0,     0,   209,   210,     0,   211,   212,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1096,  1096,  1096,  1096,
    1096,  1096,  1096,  1096,  1096,  1096,  1096,  1096,  1096,   751,
       0,     0,     0,     0,    62,    63,    64,    65,    66,     0,
       0,     0,     0,     0,  1096,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   213,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   214,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   260,     0,     0,     0,     0,     0,     0,
     751,   751,  1278,     0,     0,    76,     0,   751,   751,   751,
     751,   751,   751,   751,   751,   751,   751,   751,   751,   751,
     751,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    77,     0,
      78,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    92,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   260,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   260,
       0,     0,    93,    94,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   260,     0,     0,     0,
     260,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,     0,   105,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   108,   109,   110,   111,   112,   113,   114,   115,
       0,     0,   116,   117,   118,   119,   120,   121,   122,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     260,     0,     0,     0,   129,   130,     0,     0,     0,     0,
    1096,  1096,   666,   311,   260,     0,     0,     0,     0,     0,
       0,   260,     0,     0,     0,     0,  1096,  1096,  1096,  1096,
    1096,  1096,  1096,  1096,  1096,  1096,  1096,  1096,  1096,     0,
    1096,     0,     0,     0,     0,   143,     0,     0,     0,     0,
       0,     0,     0,   260,     0,     0,     0,     0,     0,     0,
    1474,     0,     0,     0,     0,     0,  1480,     0,     0,  1484,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   751,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   260,     0,   260,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1524,     0,     0,     0,
       0,   666,   666,  1531,   751,   751,  1534,  1535,  1536,  1537,
    1538,   751,  1540,  1541,  1542,  1543,  1544,     0,  1547,  1548,
    1549,  1550,     0,   751,   751,  1556,     0,     0,  1559,  1560,
    1561,  1562,  1563,  1564,  1565,  1566,  1567,   751,  1569,  1570,
    1571,  1572,  1573,  1574,  1575,  1576,  1577,  1578,  1579,  1580,
    1581,   751,   751,   751,   751,   751,  1587,  1588,  1589,  1590,
    1591,     0,     0,   260,   260,  1596,  1597,  1598,  1599,  1600,
    1601,  1602,  1603,  1604,  1605,  1606,  1607,  1608,   751,  1610,
    1611,  1612,  1613,  1614,  1615,   751,   751,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   751,   751,   751,  1621,   751,   751,     0,   751,   751,
     751,   751,   260,     0,   666,     0,   666,  1639,   751,   751,
    1096,  1096,  1096,  1096,  1096,  1096,  1096,  1096,  1096,  1096,
     751,   751,   751,   751,   751,     0,     0,   260,   260,   260,
       0,     0,     0,   260,     0,     0,     0,     0,     0,     0,
     260,     0,     0,     0,     0,   260,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     751,     0,     0,   751,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1709,     0,  1711,     0,     0,     0,
    1715,  1716,  1717,  1718,     0,     0,     0,     0,     0,     0,
       0,  1726,     0,  1728,  1729,  1730,  1732,  1733,  1735,  1737,
    1738,  1739,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1755,     1,   751,
       0,   730,   731,     0,   732,     0,     0,     0,     0,  1765,
    1766,  1767,     0,     0,     0,     0,     0,     0,     0,     0,
     260,     0,     0,     0,     0,     0,   547,   548,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   260,  1786,
    1787,     0,     0,     0,     0,     0,     0,   260,  1794,    34,
    1795,  1796,  1798,  1800,   733,   206,   550,     0,     0,     0,
       0,   551,     0,     0,     0,     0,     0,   211,   212,   751,
       0,     0,     0,     0,     0,     0,     0,     0,  1823,   751,
       0,   751,     0,     0,  1829,     0,     0,     0,   751,  1834,
       0,     0,     0,   751,   751,   751,   260,   751,  1843,     0,
    1845,     0,     0,   751,   260,     0,   751,   751,   751,   751,
     751,     0,     0,     0,     0,   260,     0,   666,   260,     0,
       0,     0,     0,   260,   260,   260,     0,   260,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   734,     0,     0,
       0,   553,   554,   555,   556,   557,   558,   559,   560,     0,
     561,     0,   562,   563,   564,   565,   735,   567,   568,     0,
     569,   570,     0,     0,     0,     0,     0,   736,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1096,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,     0,     0,     0,     0,   585,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
       0,   599,     0,   600,   601,   602,   603,   604,     0,     0,
       0,     0,     0,     0,   605,     0,     0,     0,     0,     0,
       0,     0,     0,   606,   607,   608,   609,     0,     0,     0,
       0,   610,     0,     0,     0,   611,     0,     0,     0,     0,
    2034,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   612,   613,   614,   615,     0,     0,     0,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   628,   629,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   751,
       0,     0,   751,     0,     0,     0,   751,  2080,  2081,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   751,     0,   630,
     631,   632,   633,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   260,     0,     0,   634,   635,     0,     0,
       0,     0,     0,     0,     0,     0,   737,   738,   739,   740,
     741,   742,   666,     0,   743,   744,   745,   746,   747,   748,
     749,   649,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   650,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   651,   652,
     653,   654,     0,   655,   656,     0,     0,     0,     0,   657,
     658,     0,     0,     0,     0,   659,   660,   661,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   143,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   260,     0,     0,     0,  2256,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2263,  2264,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2280,     0,   751,     0,     0,
       0,     0,     0,     0,   666,     0,     0,     0,     0,     0,
       0,   751,  2289,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2305,  2306,   751,   751,  2309,  2310,  2311,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2321,     0,  2322,  2323,  2324,  2325,  2326,     0,  2327,  2328,
       0,     0,     0,     0,   751,   751,     0,     0,     0,     0,
       0,  2339,   260,     0,     0,  2341,  2342,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2359,     0,     0,  2362,     0,     0,     0,     0,   751,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   751,     0,  2370,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   260,     0,     0,   260,   260,
     260,   260,   260,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   751,     0,     0,
       0,     0,     0,  2398,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2402,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   666,     0,     0,     0,
       0,     0,  2416,  2417,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2432,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   666,   751,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   398,     0,     0,     0,     0,     0,
       0,     1,     0,     2,     3,     4,     0,     5,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,     0,
       0,     0,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,     0,    29,    30,     0,     0,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,     0,     0,    56,    57,    58,    59,
       0,    60,    61,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    62,
      63,    64,    65,    66,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    67,     0,     0,     0,     0,    68,
       0,     0,     0,     0,     0,     0,    69,    70,    71,    72,
      73,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   260,   260,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    74,    75,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2718,     0,
      76,     0,  2722,  2724,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2736,  2738,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    77,     0,    78,  2752,  2753,  2754,  2755,
    2756,    79,    80,    81,    82,    83,    84,     0,    85,     0,
       0,     0,     0,   751,     0,     0,   751,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
      87,    88,     0,     0,     0,     0,     0,   260,     0,     0,
       0,     0,     0,     0,    89,    90,    91,    92,     0,     0,
    2783,     0,     0,     0,     0,     0,   751,     0,   751,     0,
     751,     0,   751,     0,     0,     0,  2794,  2795,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2800,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2825,     0,     0,     0,    93,    94,   751,
       0,     0,     0,     0,     0,   751,   751,     0,     0,     0,
       0,     0,     0,     0,   161,     0,     0,   161,   161,   161,
       0,     0,     0,     0,     0,     0,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   161,   105,   106,     0,
       0,   107,     0,     0,     0,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,     0,     0,   116,   117,   118,
     119,   120,   121,   122,     0,   123,     0,     0,     0,     0,
     124,     0,   125,   126,     0,     0,     0,   127,   128,   129,
     130,     0,   131,     0,     0,     0,     0,     0,     0,   132,
     133,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   134,     0,     0,     0,
       0,   135,   136,     0,   137,   138,   139,   140,   141,   142,
     143,     0,     0,     0,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   161,   161,   161,   161,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   161,
       0,     0,     0,  2722,     0,     0,     0,  2722,     0,     0,
       0,     0,     0,     0,     0,   161,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1639,  1639,  1639,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3022,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   260,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   751,  3046,     0,     0,     0,
       0,  3048,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   751,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   161,     0,     0,   664,   664,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     750,   664,   750,   750,   750,   750,   750,   750,     0,     0,
       0,     0,     0,     0,     0,   750,   750,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   855,     0,   750,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   260,     0,     0,  2722,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1639,     0,  1639,     0,
       0,  1639,  1639,     0,     0,     0,  3183,  3184,  3185,  3186,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3198,     0,  3200,
     750,   750,   664,     0,   161,   855,   161,   161,   751,     0,
     750,  1030,     0,     1,     0,     2,   199,   200,     0,   201,
       0,     0,     0,     0,     0,     0,     0,     0,  1636,     0,
       0,     0,     0,     0,     0,     0,     0,    14,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    25,    26,     0,     0,     0,    29,    30,     0,     0,
      31,     0,    32,     0,    34,   202,   203,   204,   237,  1637,
     206,     0,   207,   208,     0,     0,     0,     0,     0,   209,
     210,     0,   211,   212,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1639,
       0,     0,     0,     0,     0,     0,     0,   664,   664,   664,
       0,     0,     0,     0,     0,     0,     0,  3292,     0,  3294,
       0,     0,     0,     0,     0,     0,   751,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    62,    63,    64,    65,    66,   751,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   260,
       0,   213,     0,     0,     0,     0,     0,     0,     0,     0,
      71,     0,   214,     0,   751,     0,     0,   751,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     664,   664,   664,   664,   664,   664,   664,   664,   664,   664,
     664,   664,   664,   750,     0,     0,     0,     0,     0,     0,
       0,   196,     0,     0,     0,     0,     0,     0,   664,     0,
       0,     0,    76,     0,     0,     0,  3391,     0,     0,   247,
       0,     0,     0,     0,   751,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3411,     0,     0,    77,   751,    78,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   750,   750,   750,     0,     0,     0,
       0,   750,   750,   750,   750,   750,   750,   750,   750,   750,
     750,   750,   750,   750,   750,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    91,    92,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   196,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   855,   855,   855,     0,   855,   855,   855,   855,
     855,   855,   855,   855,   855,   855,   855,   855,   855,   855,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,     0,   105,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   108,
     109,   215,   216,   217,   218,   219,   220,     0,     0,   221,
     222,   223,   224,   225,   226,   227,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   129,   130,     0,     0,     0,     0,     0,     0,   531,
     532,     0,     0,     0,     0,   686,   686,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   143,     0,     0,     0,     0,   753,   686,   753,
     753,   753,   753,   753,   753,     0,     0,     0,     0,     0,
       0,     0,   753,   753,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1030,  1030,  1030,     0,     0,     0,
       0,   753,     0,     0,     0,     0,     0,     0,     0,     0,
    1030,  1030,  1030,  1030,  1030,  1030,  1030,  1030,  1030,  1030,
    1030,  1030,  1030,     0,  1030,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   750,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   753,   753,   686,
       0,     0,     0,     0,     0,     0,   996,   753,  1035,     0,
       0,     0,     0,     0,     0,   664,   664,     0,   750,   750,
       0,     0,     0,     0,     0,   750,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   750,   750,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   750,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   750,   750,   750,   750,   750,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   750,     0,     0,     0,     0,     0,     0,   750,
     750,     0,     0,     0,   686,   686,   686,  1105,     0,     0,
       0,     0,     0,     0,     0,   750,   750,   750,     0,   750,
     750,     0,   750,   750,   750,   750,     0,     0,   664,     0,
     664,     0,   750,   750,   664,   664,   664,   664,   664,   664,
     664,   664,   664,   664,   750,   750,   750,   750,   750,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   750,     0,     0,   750,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   686,   686,   686,
     686,   686,   686,   686,   686,   686,   686,   686,   686,   686,
     753,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   686,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   750,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   753,   753,   753,     0,     0,     0,     0,   753,   753,
     753,   753,   753,   753,   753,   753,   753,   753,   753,   753,
     753,   753,     0,   750,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   750,     0,   750,     0,     0,     0,     0,
       0,     0,   750,     0,     0,     0,     0,   750,   750,   750,
       0,   750,     0,     0,     0,     0,     0,   750,     0,     0,
     750,   750,   750,   750,   750,     0,     0,     0,     0,     0,
       0,   664,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   664,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   254,   257,   259,
       0,     0,   263,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     313,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   686,   686,   686,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   686,   686,   686,
     686,   686,   686,   686,   686,   686,   686,   686,   686,   686,
       0,   686,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   750,     0,     0,   750,     0,     0,     0,
     750,     0,   383,   384,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     753,     0,     0,     0,     0,     0,     0,   996,     0,     0,
       0,     0,     0,  1507,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   750,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   686,   686,     0,   753,   753,     0,     0,     0,
       0,     0,   753,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   753,   753,   664,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   753,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   753,   753,   753,   753,   753,   463,     0,   465,
       0,     0,  1592,  1593,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   467,   468,     0,   753,
       0,     0,     0,     0,     0,     0,   753,   753,     0,     0,
     475,     0,     0,     0,     0,     0,     0,     0,     0,   663,
     663,     0,   753,   753,   753,     0,   753,   753,     0,   753,
     753,   753,   753,     0,     0,   686,     0,   686,     0,   753,
     753,   686,   686,   686,   686,   686,   686,   686,   686,   686,
     686,   753,   753,   753,   753,   753,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   750,     0,     0,     0,     0,     0,     0,   664,     0,
       0,     0,     0,     0,   857,   750,     0,     0,     0,     0,
       0,   753,     0,     0,   753,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   750,   750,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   867,     0,     0,     0,     0,     0,   873,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   750,   750,
       0,     0,     0,     0,     0,     0,     0,   883,   884,     0,
     753,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       0,     2,   199,   200,     0,   201,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1029,   750,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   750,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    32,     0,
      34,   202,   203,   204,     0,   205,   206,     0,   207,   208,
     753,     0,     0,     0,     0,   209,   210,     0,   211,   212,
     753,   750,   753,     0,     0,     0,     0,     0,     0,   753,
       0,  1835,  1836,  1837,   753,   753,   753,     0,   753,     0,
    1844,     0,  1846,  1847,   753,     0,     0,   753,   753,   753,
     753,   753,     0,     0,     0,     0,     0,     0,   686,     0,
       0,  1090,  1092,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1107,     0,     0,     0,     0,     0,     0,     0,
     664,     0,     0,     0,     0,     0,     0,    62,    63,    64,
      65,    66,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   213,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   214,     0,
       0,   686,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    76,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   664,   750,     0,     0,   685,
     685,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    77,     0,    78,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   752,   756,   757,   758,   759,   760,   761,   762,     0,
       0,  2035,     0,     0,     0,     0,   820,   821,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1270,     0,
       0,     0,     0,     0,     0,   858,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    91,    92,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   996,     0,
     753,     0,     0,   753,     0,     0,     0,   753,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   922,   923,   925,     0,     0,     0,     0,     0,     0,
       0,   999,  1032,     0,     0,     0,     0,     0,   753,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,     0,   105,  1364,     0,     0,     0,
       0,     0,     0,   686,     0,   108,   109,   215,   216,   217,
     218,   219,   220,     0,     0,   221,   222,   223,   224,   225,
     226,   227,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   129,   130,     0,
       0,     0,     0,     0,  1389,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1399,     0,     0,     0,  1402,     0,     0,   143,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   750,     0,     0,
     750,     0,     0,     0,     0,  1445,     0,     0,   753,     0,
       0,     0,     0,     0,     0,   686,     0,     0,     0,  1107,
       0,     0,   753,     0,     0,     0,  1445,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   753,   753,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1470,     0,
     750,     0,   750,     0,   750,     0,   750,     0,     0,     0,
       0,     0,     0,     0,     0,   753,   753,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1516,     0,
    1519,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     753,  1522,     0,   750,     0,     0,   663,     0,     0,   750,
     750,     0,   753,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   753,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1594,  1595,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   686,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1629,     0,  1632,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1674,  1675,  1676,     0,     0,     0,  1680,     0,
       0,     0,     0,     0,     0,  1687,     0,     0,     0,     0,
    1692,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   686,   753,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   750,
       0,     0,     0,     0,     0,  1771,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1785,     0,     0,     0,     0,     0,     0,
       0,     0,  1793,   750,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1841,     0,     0,     0,     0,     0,     0,     0,  1850,
       0,     0,     0,     0,  1494,     0,     0,     0,     0,     0,
    1859,     0,   663,  1862,     0,     0,     0,     0,  1867,  1868,
    1869,     0,  1870,     0,     0,     0,  1872,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   685,  1530,     0,  1532,
    1533,     0,     0,     0,     0,     0,  1539,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1554,  1555,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1568,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1582,  1583,  1584,  1585,
    1586,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   750,  1609,     0,     0,     0,     0,     0,     0,
    1616,  1617,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1618,  1619,  1620,     0,
    1622,  1623,     0,  1625,  1626,  1627,  1628,     0,     0,  1634,
       0,  1635,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   753,     0,     0,   753,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1704,     0,     0,  1635,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     750,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   753,     0,   753,
       0,   753,     0,   753,     0,     0,     0,     0,     0,     0,
     750,     0,     0,     0,  1756,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   750,     0,
       0,   750,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     753,     0,     0,     0,     0,     0,   753,   753,  2149,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1814,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1824,     0,  1826,     0,   750,     0,
       0,     0,     0,  1833,     0,     0,     0,     0,  1838,  1839,
    1840,     0,  1842,     0,     0,     0,     0,     0,  1848,     0,
     750,  1851,  1852,  1853,  1854,  1855,     0,     0,     0,     0,
       0,     0,   685,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     2,   199,   200,     0,   201,     0,     0,
       0,     0,     0,     0,     0,     0,  2255,     0,     0,     0,
       0,     0,     0,     0,     0,    14,    15,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    25,
      26,     0,     0,     0,    29,    30,     0,     0,    31,     0,
      32,     0,    34,   202,   203,   204,   237,   205,   206,     0,
     207,   208,     0,     0,     0,     0,     0,   209,   210,     0,
     211,   212,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2340,     0,    62,
      63,    64,    65,    66,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   753,     0,     0,   213,
       0,     0,     0,     0,     0,     0,     0,     0,    71,     0,
     214,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     753,     0,     0,     0,     0,     0,  2375,  2377,     0,     0,
    2380,     0,  2381,  2383,  2384,  2385,  2386,  2387,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      76,     0,     0,     0,  2075,     0,     0,     0,     0,     0,
       0,  2079,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    77,     0,    78,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2132,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2171,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    92,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   753,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,     0,   105,     0,     0,
       0,     0,  2282,     0,     0,     0,     0,   108,   109,   215,
     216,   217,   218,   219,   220,     0,  2287,   221,   222,   223,
     224,   225,   226,   227,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2307,  2308,   129,
     130,     0,     0,     0,     0,     0,     0,   753,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2333,
    2334,     0,     0,     0,     0,     0,     0,   753,     0,     0,
     143,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     2,  1000,  1001,     0,  1002,     0,     0,
       0,  1003,     0,     0,     0,   753,     0,     0,   753,     0,
       0,     0,     0,     0,  2365,    14,    15,     0,     0,  1004,
     548,  1005,     0,     0,     0,     0,     0,     0,     0,    25,
      26,     0,     0,     0,    29,    30,     0,     0,    31,     0,
      32,     0,    34,   202,   203,   204,   237,   754,   206,  1006,
     232,   208,  1007,     0,   551,     0,     0,   209,   210,  1008,
     211,   212,     0,     0,     0,   753,     0,     0,     0,     0,
    1009,     0,     0,  1010,     0,     0,     0,     0,     0,     0,
    2699,  2700,     0,     0,     0,     0,     0,   753,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2411,     0,     0,     0,     0,     0,     0,     0,    62,
     552,    64,    65,    66,   553,   554,   555,   556,   557,   558,
     559,   560,     0,   561,     0,   562,   563,   564,   565,   566,
     567,   568,     0,   569,   570,     0,     0,     0,    71,     0,
     571,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,     0,     0,     0,     0,   585,
      76,     0,  2779,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2471,  2472,     0,     0,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,    77,   599,    78,   600,   601,   602,   603,
     604,     0,     0,     0,     0,     0,     0,   605,     0,     0,
       0,   975,   976,   977,     0,     0,   606,   607,   608,   609,
     978,   979,   980,   981,   610,     0,     0,   982,   611,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   612,   613,   614,   615,     0,
       0,     0,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,     0,     0,    91,    92,   983,     0,
       0,   984,   985,   986,   987,     0,   988,   989,   628,   629,
    1011,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1012,    93,    94,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   630,   631,   632,   633,    95,  1013,    97,    98,
    1014,   100,   101,   102,   103,   104,     0,   105,     0,   634,
     635,     0,  1015,     0,     0,     0,     0,   108,   109,  1016,
    1017,  1018,  1019,  1020,  1021,     0,     0,  1022,  1023,  1024,
    1025,  1026,  1027,  1028,   649,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   129,
     130,   650,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   651,   652,   653,   654,     0,   655,   656,     0,   991,
     992,   993,   657,   658,     0,   994,     0,   995,   659,   660,
     661,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     143,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3037,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2760,     0,
       0,  2761,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2787,     0,  2788,     0,  2789,     0,  2790,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2826,     0,     0,     0,     0,  3159,
    2831,  2832,     0,     0,     0,     0,     0,     0,     0,     1,
       0,     2,  1000,  1001,     0,  1002,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    14,    15,     0,     0,   547,   548,     0,
       0,     0,     0,     0,     0,     0,     0,    25,    26,     0,
       0,     0,    29,    30,     0,     0,    31,     0,    32,     0,
      34,   202,   203,   204,   237,   754,   206,   550,   232,   208,
       0,     0,   551,     0,     0,   209,   210,     0,   211,   212,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3274,     0,     0,     0,     0,     0,    62,   552,    64,
      65,    66,   553,   554,   555,   556,   557,   558,   559,   560,
       0,   561,     0,   562,   563,   564,   565,   566,   567,   568,
       0,   569,   570,     0,     0,     0,    71,     0,   571,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,     0,     0,     0,     0,   585,    76,     0,
       0,     0,     0,     0,  3342,     0,     0,     0,     0,     0,
    3045,     0,     0,     0,     0,     0,     0,     0,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,    77,   599,    78,   600,   601,   602,   603,   604,     0,
       0,     0,     0,     0,  3057,   605,     0,     0,     0,     0,
       0,     0,     0,     0,   606,   607,   608,   609,     0,     0,
       0,     0,   610,     0,     0,     0,   611,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   612,   613,   614,   615,     0,     0,     0,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,     0,     0,    91,    92,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   628,   629,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    93,    94,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     630,   631,   632,   633,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,     0,   105,     0,   634,   635,     0,
       0,     0,     0,  3206,     0,   108,   109,  1016,  1017,  1018,
    1019,  1020,  1021,     0,     0,  1022,  1023,  1024,  1025,  1026,
    1027,  1028,   649,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   129,   130,   650,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   651,
     652,   653,   654,     0,   655,   656,     0,     0,     0,     0,
     657,   658,     0,     0,     0,     0,   659,   660,   661,     0,
       0,     1,     0,     2,   543,   544,     0,   545,   143,     0,
       0,   546,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    14,    15,     0,     0,   547,
     548,     0,     0,     0,     0,     0,     0,     0,     0,    25,
      26,     0,     0,     0,    29,    30,     0,     0,    31,     0,
      32,  3300,    34,   202,   203,   204,   237,   549,   206,   550,
     207,   208,     0,     0,   551,     0,     0,   209,   210,     0,
     211,   212,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3331,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3350,
       0,     0,  3352,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    62,
     552,    64,    65,    66,   553,   554,   555,   556,   557,   558,
     559,   560,     0,   561,     0,   562,   563,   564,   565,   566,
     567,   568,     0,   569,   570,     0,     0,     0,    71,  3395,
     571,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3413,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,     0,     0,     0,     0,   585,
      76,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,    77,   599,    78,   600,   601,   602,   603,
     604,     0,     0,     0,     0,     0,     0,   605,     0,     0,
       0,     0,     0,     0,     0,     0,   606,   607,   608,   609,
       0,     0,     0,     0,   610,     0,     0,     0,   611,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   612,   613,   614,   615,     0,
       0,     0,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,     0,     0,    91,    92,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   628,   629,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   630,   631,   632,   633,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,     0,   105,     0,   634,
     635,     0,     0,     0,     0,     0,     0,   108,   109,   636,
     637,   638,   639,   640,   641,     0,     0,   642,   643,   644,
     645,   646,   647,   648,   649,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   129,
     130,   650,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   651,   652,   653,   654,     0,   655,   656,     0,     0,
       0,     0,   657,   658,     0,     0,     0,     0,   659,   660,
     661,     1,     0,     2,   543,   544,     0,   545,     0,     0,
     143,  1630,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    14,    15,     0,     0,   547,
     548,     0,     0,     0,     0,     0,     0,     0,     0,    25,
      26,     0,     0,     0,    29,    30,     0,     0,    31,     0,
      32,     0,    34,   202,   203,   204,   237,  1631,   206,   550,
     207,   208,     0,     0,   551,     0,     0,   209,   210,     0,
     211,   212,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    62,
     552,    64,    65,    66,   553,   554,   555,   556,   557,   558,
     559,   560,     0,   561,     0,   562,   563,   564,   565,   566,
     567,   568,     0,   569,   570,     0,     0,     0,    71,     0,
     571,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,     0,     0,     0,     0,   585,
      76,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,    77,   599,    78,   600,   601,   602,   603,
     604,     0,     0,     0,     0,     0,     0,   605,     0,     0,
       0,     0,     0,     0,     0,     0,   606,   607,   608,   609,
       0,     0,     0,     0,   610,     0,     0,     0,   611,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   612,   613,   614,   615,     0,
       0,     0,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,     0,     0,    91,    92,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   628,   629,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   630,   631,   632,   633,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,     0,   105,     0,   634,
     635,     0,     0,     0,     0,     0,     0,   108,   109,   636,
     637,   638,   639,   640,   641,     0,     0,   642,   643,   644,
     645,   646,   647,   648,   649,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   129,
     130,   650,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   651,   652,   653,   654,     0,   655,   656,     0,     0,
       0,     0,   657,   658,     0,     0,     0,     0,   659,   660,
     661,     1,     0,     2,   543,   544,     0,   545,     0,     0,
     143,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    14,    15,     0,     0,   547,
     548,     0,     0,     0,     0,     0,     0,     0,     0,    25,
      26,     0,     0,     0,    29,    30,     0,     0,    31,     0,
      32,     0,    34,   202,   203,   204,   237,   754,   206,   550,
     207,   208,     0,     0,   551,     0,     0,   209,   210,     0,
     211,   212,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    62,
     552,    64,    65,    66,   553,   554,   555,   556,   557,   558,
     559,   560,     0,   561,     0,   562,   563,   564,   565,   566,
     567,   568,     0,   569,   570,     0,     0,     0,    71,     0,
     571,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,     0,     0,     0,     0,   585,
      76,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,    77,   599,    78,   600,   601,   602,   603,
     604,     0,     0,     0,     0,     0,     0,   605,     0,     0,
       0,     0,     0,     0,     0,     0,   606,   607,   608,   609,
       0,     0,     0,     0,   610,     0,     0,     0,   611,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   612,   613,   614,   615,     0,
       0,     0,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,     0,     0,    91,    92,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   628,   629,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   630,   631,   632,   633,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,     0,   105,     0,   634,
     635,     0,     0,     0,     0,     0,     0,   108,   109,   636,
     637,   638,   639,   640,   641,     0,     0,   642,   643,   644,
     645,   646,   647,   648,   649,     0,     0,     0,     0,     0,
       1,     0,     2,  1000,  1001,     0,  1002,     0,     0,   129,
     130,   650,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   651,   652,   653,   654,    15,   655,   656,   547,   548,
       0,     0,   657,   658,     0,     0,     0,     0,   659,   660,
     661,     0,     0,     0,     0,     0,     0,     0,     0,    32,
     143,    34,   202,   203,   204,     0,   754,   206,   550,   232,
     208,     0,     0,   551,     0,     0,   209,   210,     0,   211,
     212,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    62,   552,
      64,    65,    66,   553,   554,   555,   556,   557,   558,   559,
     560,     0,   561,     0,   562,   563,   564,   565,   566,   567,
     568,     0,   569,   570,     0,     0,     0,     0,     0,   571,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,     0,     0,     0,     0,   585,    76,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   598,    77,   599,    78,   600,   601,   602,   603,   604,
       0,     0,     0,     0,     0,     0,   605,     0,     0,     0,
       0,     0,     0,     0,     0,   606,   607,   608,   609,     0,
       0,     0,     0,   610,     0,     0,     0,   611,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   612,   613,   614,   615,     0,     0,
       0,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,     0,     0,    91,    92,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   628,   629,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    93,    94,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   630,   631,   632,   633,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,     0,   105,     0,   634,   635,
       0,     0,     0,     0,     0,     0,   108,   109,  1016,  1017,
    1018,  1019,  1020,  1021,     0,     0,  1022,  1023,  1024,  1025,
    1026,  1027,  1028,   649,     0,     0,     0,     0,     0,     1,
       0,     2,   543,   544,     0,   545,     0,     0,   129,   130,
     650,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     651,   652,   653,   654,    15,   655,   656,   547,   548,     0,
       0,   657,   658,     0,     0,     0,     0,   659,   660,   661,
       0,     0,     0,     0,     0,     0,     0,     0,    32,   143,
      34,   202,   203,   204,     0,   754,   206,   550,   207,   208,
       0,     0,   551,     0,     0,   209,   210,     0,   211,   212,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    62,   552,    64,
      65,    66,   553,   554,   555,   556,   557,   558,   559,   560,
       0,   561,     0,   562,   563,   564,   565,   566,   567,   568,
       0,   569,   570,     0,     0,     0,     0,     0,   571,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,     0,     0,     0,     0,   585,    76,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,    77,   599,    78,   600,   601,   602,   603,   604,     0,
       0,     0,     0,     0,     0,   605,     0,     0,     0,     0,
       0,     0,     0,     0,   606,   607,   608,   609,     0,     0,
       0,     0,   610,     0,     0,     0,   611,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   612,   613,   614,   615,     0,     0,     0,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,     0,     0,    91,    92,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   628,   629,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     630,   631,   632,   633,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,     0,   105,     0,   634,   635,     0,
       0,     0,     0,     0,     0,   108,   109,   636,   637,   638,
     639,   640,   641,     0,     0,   642,   643,   644,   645,   646,
     647,   648,   649,     0,     0,     0,     0,     0,     1,     0,
       2,   543,   544,     0,  1924,     0,     0,   129,   130,   650,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   651,
     652,   653,   654,    15,   655,   656,   547,   548,     0,     0,
     657,   658,     0,     0,     0,     0,   659,   660,   661,     0,
       0,     0,     0,     0,     0,     0,     0,    32,   143,    34,
     202,   203,   204,     0,   754,   206,   550,   207,   208,     0,
       0,   551,     0,     0,   209,   210,     0,   211,   212,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    62,   552,    64,    65,
      66,   553,   554,   555,   556,   557,   558,   559,   560,     0,
     561,     0,   562,   563,   564,   565,   566,   567,   568,     0,
     569,   570,     0,     0,     0,     0,     0,   571,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,     0,     0,     0,     0,   585,    76,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
      77,   599,    78,   600,   601,   602,   603,   604,     0,     0,
       0,     0,     0,     0,   605,     0,     0,     0,     0,     0,
       0,     0,     0,   606,   607,   608,   609,     0,     0,     0,
       0,   610,     0,     0,     0,   611,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   612,   613,   614,   615,     0,     0,     0,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,     0,     0,    91,    92,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   628,   629,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   630,
     631,   632,   633,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,     0,   105,     0,   634,   635,     0,     0,
       0,     0,     0,     0,   108,   109,   636,   637,   638,   639,
     640,   641,     0,     0,   642,   643,   644,   645,   646,   647,
     648,   649,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   129,   130,   650,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   651,   652,
     653,   654,     0,   655,   656,     0,     0,     0,     0,   657,
     658,     0,     0,     0,     0,   659,   660,   661,     1,     0,
       2,     3,     4,     0,     5,     0,     0,   143,     0,     0,
       0,     0,     0,     0,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,     0,     0,     0,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
       0,    29,    30,     0,     0,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,     0,     0,    56,    57,    58,    59,     0,    60,    61,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    62,    63,    64,    65,
      66,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    67,     0,     0,     0,     0,    68,     0,     0,     0,
       0,     0,     0,    69,    70,    71,    72,    73,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,    75,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    76,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      77,     0,    78,     0,     0,     0,     0,     0,    79,    80,
      81,    82,    83,    84,     0,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    86,    87,    88,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    89,    90,    91,    92,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    93,    94,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,     0,   105,   106,     0,     1,   107,     0,
     730,   731,     0,   732,   108,   109,   110,   111,   112,   113,
     114,   115,     0,     0,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,     0,   547,   548,   124,     0,   125,
     126,     0,     0,     0,   127,   128,   129,   130,     0,   131,
       0,     0,     0,     0,     0,     0,   132,   133,    34,     0,
       0,     0,     0,   733,   206,   550,     0,     0,     0,     0,
     551,     0,     0,   134,     0,     0,   211,   212,   135,   136,
       0,   137,   138,   139,   140,   141,   142,   143,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   734,     0,     0,     0,
     553,   554,   555,   556,   557,   558,   559,   560,     0,   561,
       0,   562,   563,   564,   565,   735,   567,   568,     0,   569,
     570,     0,     0,     0,     0,     0,   736,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,     0,     0,     0,     0,   585,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,     0,
     599,     0,   600,   601,   602,   603,   604,     0,     0,     0,
       0,     0,     0,   605,     0,     0,     0,     0,     0,     0,
       0,     0,   606,   607,   608,   609,     0,     0,     0,     0,
     610,     0,     0,     0,   611,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   612,   613,   614,   615,     0,     0,     0,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   628,   629,   998,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     0,     0,   730,   731,     0,
     732,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   547,   548,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   630,   631,
     632,   633,     0,     0,     0,    34,     0,     0,     0,     0,
     733,   206,   550,     0,     0,   634,   635,   551,     0,     0,
       0,     0,     0,   211,   212,   737,   738,   739,   740,   741,
     742,     0,     0,   743,   744,   745,   746,   747,   748,   749,
     649,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   650,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   651,   652,   653,
     654,     0,   655,   656,     0,     0,     0,     0,   657,   658,
       0,     0,     0,     0,   659,   660,   661,     0,     0,     0,
       0,     0,     0,   734,     0,     0,   143,   553,   554,   555,
     556,   557,   558,   559,   560,     0,   561,     0,   562,   563,
     564,   565,   735,   567,   568,     0,   569,   570,     0,     0,
       0,     0,     0,   736,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,     0,     0,
       0,     0,   585,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,     0,   599,     0,   600,
     601,   602,   603,   604,     0,     0,     0,     0,     0,     0,
     605,     0,     0,     0,     0,     0,     0,     0,     0,   606,
     607,   608,   609,     0,     0,     0,     0,   610,     0,     0,
       0,   611,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   612,   613,
     614,   615,     0,     0,     0,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   628,   629,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     0,   730,   731,     0,  2077,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   547,
     548,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   630,   631,   632,   633,     0,
       0,     0,    34,     0,     0,     0,     0,   733,   206,   550,
       0,     0,   634,   635,   551,     0,     0,     0,     0,     0,
     211,   212,   737,   738,   739,   740,   741,   742,     0,     0,
     743,   744,   745,   746,   747,   748,   749,   649,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   650,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   651,   652,   653,   654,     0,   655,
     656,     0,     0,     0,     0,   657,   658,     0,     0,     0,
       0,   659,   660,   661,     0,     0,     0,     0,     0,     0,
     734,     0,     0,   143,   553,   554,   555,   556,   557,   558,
     559,   560,     0,   561,     0,   562,   563,   564,   565,   735,
     567,   568,     0,   569,   570,     0,     0,     0,     0,     0,
     736,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,     0,     0,     0,     0,   585,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,     0,   599,     0,   600,   601,   602,   603,
     604,     0,     0,     0,     0,     0,     0,   605,     0,     0,
       0,     0,     0,     0,     0,     0,   606,   607,   608,   609,
       0,     0,     0,     0,   610,     0,     0,     0,   611,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   612,   613,   614,   615,     0,
       0,     0,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     2,   199,   200,     0,   201,   628,   629,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    14,    15,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    25,
      26,     0,     0,     0,    29,    30,     0,     0,    31,     0,
      32,     0,    34,   202,   203,   204,   237,  1637,   206,     0,
     207,   208,     0,     0,     0,     0,     0,   209,   210,     0,
     211,   212,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   630,   631,   632,   633,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   634,
     635,     0,     0,     0,     0,     0,     0,     0,     0,   737,
     738,   739,   740,   741,   742,     0,     0,   743,   744,   745,
     746,   747,   748,   749,   649,     0,     0,     0,     0,    62,
      63,    64,    65,    66,     1,     0,     2,   199,   200,     0,
    1041,   650,     0,     0,     0,     0,     0,     0,     0,   213,
       0,   651,   652,   653,   654,     0,   655,   656,    71,    15,
     214,     0,   657,   658,     0,     0,     0,     0,   659,   660,
     661,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     143,     0,     0,    32,     0,    34,   202,   203,   204,     0,
     205,   206,     0,   207,   208,     0,     0,     0,     0,     0,
     209,   210,     0,   211,   212,     0,     0,     0,     0,     0,
      76,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    77,     0,    78,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    62,    63,    64,    65,    66,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   213,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   214,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    92,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    76,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    77,     0,    78,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,     0,   105,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   108,   109,   215,
     216,   217,   218,   219,   220,     0,     0,   221,   222,   223,
     224,   225,   226,   227,     0,     0,     0,     0,     0,    91,
      92,     0,     0,     0,     0,     0,     0,     0,     0,   129,
     130,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     143,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,     0,
     105,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     108,   109,   215,   216,   217,   218,   219,   220,     0,     0,
     221,   222,   223,   224,   225,   226,   227,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   129,   130,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   143
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
         0,    47,   381,   447,   285,   421,   422,   423,   424,   460,
      23,   390,    57,     0,    54,   543,   544,    31,   419,   420,
      58,    34,    22,    23,    50,    21,    64,   144,    14,    37,
      42,    45,    46,    22,    64,    22,    50,    51,    76,    77,
      54,   442,   443,     7,    58,    31,    76,    13,    62,    19,
       0,    52,    53,    19,    42,    43,    19,    65,    52,    45,
      46,    19,    52,    77,    50,    51,    50,    75,    54,    19,
      12,    19,    58,    57,     5,     6,    62,    15,    20,   347,
     348,   127,    22,  2883,  2884,  2885,     5,    13,    21,    57,
      13,    77,    12,    64,    14,    13,    19,    15,    48,   145,
      20,    19,   123,    71,    12,    76,    13,   153,   636,   637,
     638,   639,   640,   641,   642,   643,   644,   645,   646,   647,
     648,   649,    12,   144,    31,    12,   126,    19,    13,    23,
      20,     7,   400,    20,    10,    11,   664,    13,    45,    46,
      34,   137,    13,    50,    51,   145,    12,    54,   137,    58,
      12,    58,    14,    58,    20,    62,     5,     6,   145,    12,
     174,    49,    50,   133,   134,    58,    13,    20,    77,    57,
      77,    14,    77,   123,   144,   123,   221,    20,   144,   143,
      23,   144,   132,   133,    77,   123,   144,   177,   174,    13,
      66,    12,   186,    14,   239,   145,   186,   137,   140,   141,
      19,    13,   730,   731,   137,   123,   124,   138,   139,   737,
     738,   739,   740,   741,   742,   743,   744,   745,   746,   747,
     748,   749,   750,    13,   264,   265,   144,   221,   229,   230,
     242,   221,   140,   141,   239,   240,   241,   221,    19,    13,
      14,   133,   134,   243,    19,    19,    31,   277,   278,   279,
     140,   141,   144,   140,   141,   239,   286,   287,   288,   289,
      45,    46,   171,   293,    12,    50,    51,   174,   268,    54,
     158,   271,    20,    58,   274,    13,   281,    62,   140,   141,
     280,   281,   201,   292,   284,   285,   291,   292,    57,   138,
     139,   291,    77,   293,   281,    54,  3096,    13,  3098,    58,
      12,  3101,  3102,    19,   334,   124,   125,   337,   338,   339,
     340,    23,   342,   343,   314,   315,   346,   317,    77,   140,
     141,    19,    34,    58,    12,   239,    54,    12,    14,    58,
      58,    58,    20,   221,    20,    20,    63,   383,   239,   240,
     241,    19,    77,   343,   344,   385,   346,   347,    77,    77,
      77,   239,   133,   134,   242,   243,   244,   245,   475,    13,
     406,   348,    14,   144,    58,    59,    60,   412,    20,    23,
      64,    23,   381,   382,   383,   384,   381,   382,   383,   384,
      34,    15,    76,    77,    12,     0,   274,   275,   276,   174,
     291,   391,    20,    54,   402,    13,    57,   442,   302,   303,
     304,   305,   306,   307,   308,   309,   310,    68,    69,    70,
     410,   543,   544,   239,   240,   241,   442,    13,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   412,    12,
      10,    11,    12,   433,   434,   385,   171,    20,   438,  3239,
      14,    13,   171,   347,   482,    14,    20,   447,    22,    23,
      13,    20,   452,   453,    23,    13,   456,    15,   442,    12,
     447,   449,   450,   451,   452,   291,   292,    20,   481,    13,
      12,    12,  1000,  1001,    12,   505,   506,   507,    20,    20,
      13,   511,    20,   513,    10,    11,    19,    20,  1016,  1017,
    1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,
    1028,    13,  1030,    15,   636,   637,   638,   639,   640,   641,
     642,   643,   644,   645,   646,   647,   648,   649,   406,   407,
      13,    19,    15,    13,   412,    15,    19,   403,   404,    13,
      20,    15,   664,     7,     8,    19,   536,   425,    12,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,     4,
     140,   141,     7,     8,   442,   381,   382,   383,   384,    58,
      59,    60,    13,    19,    13,    64,    15,    13,    19,    20,
      19,    10,    11,    19,     2,     3,     4,    76,    77,   455,
     456,   457,   458,   459,   460,   223,   224,   463,   464,   465,
     466,   467,   468,   469,    19,    13,    14,    14,   730,   731,
     168,    19,    13,    20,    15,   737,   738,   739,   740,   741,
     742,   743,   744,   745,   746,   747,   748,   749,   750,   223,
     224,    90,    13,    92,    19,    94,   545,    96,    19,    98,
      99,    13,  1076,   102,   103,   104,   105,   106,   107,   108,
     109,   450,   451,    13,    14,   114,    13,     3,     4,    19,
     526,    13,    14,   221,   222,   223,   224,    19,    13,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     229,   230,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   489,   490,   491,   492,   493,
      13,  1229,  1230,  1231,  1232,  1233,  1234,  1235,  1236,  1237,
    1238,  1239,  1240,  1241,  1242,  1243,  1244,    13,    14,    14,
      14,     4,    14,    19,    14,    20,    20,   727,    20,    59,
      20,    13,    62,   161,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,    14,    14,    14,
      14,   199,   200,    20,    20,    20,    20,    16,    14,    14,
      14,    10,    11,    22,    20,    20,    20,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,    14,    17,    14,    14,   161,    13,    20,    15,    20,
      20,    13,    13,   732,    15,   140,   141,   863,  1234,  1235,
    1236,  1237,  1238,  1239,    31,   871,    18,    14,    14,    14,
    1111,  1232,  1233,    20,    20,    20,    14,    13,    45,    46,
      14,    13,    20,    50,    51,    13,    20,    54,    14,   136,
      14,    58,    14,    41,    20,    62,    20,    14,    20,    14,
     860,    14,    12,    20,    14,    20,    14,    20,  1000,  1001,
      77,    14,    20,    14,    14,    14,    14,    20,    13,    20,
      20,    20,    20,    13,  1016,  1017,  1018,  1019,  1020,  1021,
    1022,  1023,  1024,  1025,  1026,  1027,  1028,    12,  1030,    14,
      10,    11,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,    14,  1234,  1235,  1236,  1237,   349,
      20,   351,    23,   353,   354,   142,    14,    13,    13,    15,
      31,   361,    20,    34,   364,   365,   366,   367,   368,   369,
     370,   371,    14,  1003,    45,    46,    14,   174,    20,    50,
      51,    13,    20,    54,    14,    19,    14,    58,    19,    14,
      20,    62,    20,    13,  1363,    20,    13,  1366,   416,   417,
     418,   401,  1520,    14,    13,   405,    77,    14,    14,    20,
     410,   411,    14,    20,    20,   347,   348,    14,    20,    14,
      13,   421,   440,    20,    13,    20,   426,   427,    52,    53,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,    14,    14,    14,    14,    14,
      14,    20,    20,    20,    20,    20,    20,  1047,   408,   409,
    1050,  1051,  1052,  1053,  1054,  1055,    13,  1057,  1058,    13,
      13,    15,  1062,  1063,  1064,  1065,  1066,  1067,  1068,  1520,
    1070,    12,  1072,    14,  1074,  1075,    14,  1077,  1078,  1079,
    1080,  1081,    20,  1002,   440,   441,  1086,  1087,  1088,  1089,
      14,   425,   426,   174,    14,    13,    20,  1229,  1230,  1231,
      20,   377,    19,    14,    14,  1232,  1233,    14,  1108,    20,
      20,  1111,  1112,    20,    13,   543,   544,    14,    13,    13,
      15,    14,    12,    20,    14,    13,    12,    20,    14,  1238,
    1239,   407,   408,   409,   410,   411,    31,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,    13,
      45,    46,    12,    19,    14,    50,    51,    13,    12,    54,
      14,    13,    12,    58,    14,   442,   443,    62,   489,   490,
     491,   492,   493,    12,  1702,    14,  1457,    12,    12,    14,
      14,    12,    77,    14,    12,    15,    14,  1106,    12,    12,
      14,    14,    12,    12,    14,    14,    12,    12,    14,    14,
    1246,    12,    12,    14,    14,    12,    15,    14,   636,   637,
     638,   639,   640,   641,   642,   643,   644,   645,   646,   647,
     648,   409,    13,    13,  1224,   501,  1226,  1227,    12,    12,
      14,    14,    12,    12,    14,    14,   664,    12,    20,    14,
      22,    13,    20,   519,    22,    12,    12,    14,    14,    13,
    1250,    19,    12,  1697,    19,    14,  1256,    19,    14,    14,
     346,  1261,    19,  1263,  1264,   448,  1266,  1267,  1268,  1269,
      15,    63,  1272,    54,    80,   177,    14,    54,    54,   174,
      50,    55,    14,    14,    13,    13,  1286,    13,    13,    13,
      13,    13,    13,    13,    13,  1295,    13,  1297,  1298,  1299,
      13,    13,    13,    13,  1304,  1305,  1306,  1307,  1308,  1309,
    1310,    13,  1312,    13,    13,    13,    13,    13,    13,    13,
      13,    13,  1322,  1323,  1324,  1325,  1326,  1327,  1328,  1329,
    1330,  1331,  1332,  1333,  1334,  1335,  1336,    13,    13,    13,
      13,    13,  1342,  1343,  1344,  1345,  1346,  1347,  1348,    13,
      13,    13,    13,    13,  1354,  1355,    13,  1357,   144,    13,
      13,    13,    20,    13,    13,    13,    13,   136,    19,    13,
      13,    13,    13,    19,    13,  1375,    13,  1377,    13,    13,
      13,    13,    13,  1383,  1384,  1385,    13,    13,    13,    13,
      13,    13,  1392,  1393,  1394,  1395,  1396,  1397,  1398,    13,
    1400,  1401,    19,  1403,  1404,  1405,  1406,  1407,  1408,    13,
    1410,  1411,  1412,  1413,  1414,  1415,  1416,  1417,    13,    13,
    1420,    19,  1422,  1423,    13,  1425,  1426,  1427,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    19,
      13,    13,  1452,    13,  1454,    13,    13,  1457,    13,  1459,
      13,  1461,  1462,    13,    13,    13,    13,    13,    13,    13,
      13,  1471,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,   838,   839,    13,    13,   842,   843,   844,   845,
     846,   847,   848,   849,   850,   851,   852,   853,   854,   855,
      13,    13,    13,    31,    13,    19,    13,    13,    13,    13,
      13,    13,    13,  2041,    13,    13,    13,    45,    46,    13,
      13,    13,    50,    51,    13,    13,    54,    13,    13,    13,
      58,    13,    13,    13,    62,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    77,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      13,    13,  1000,  1001,    13,    13,    17,    13,    18,    13,
      13,    13,    19,    13,   239,   240,   241,   242,  1016,  1017,
    1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,
    1028,    13,  1030,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,   272,    13,    13,
      13,    56,    71,    14,    16,   280,    15,    13,    16,    56,
      20,    14,    19,    14,    19,    19,   291,    16,    20,    14,
     295,    19,    14,    14,  1000,  1001,   174,    16,    16,    13,
      20,    13,    13,    13,    13,    13,    13,    13,    13,    13,
    1016,  1017,  1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,
    1026,  1027,  1028,    13,  1030,    13,    13,    13,    13,    13,
      13,    13,    13,   338,    13,   340,   341,   342,    13,    13,
      13,    13,    13,    13,    13,    13,   351,   352,    13,    13,
      13,    13,   357,   358,   359,   360,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,   372,   373,   374,
     375,   376,    14,   378,   379,   380,    20,    14,  1774,  1775,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,    16,    20,    20,    20,    12,
      20,    20,    20,    20,    20,    20,    20,    14,    14,    20,
      20,    20,    14,    14,    14,    20,    14,    14,    13,  2148,
      63,    20,  1772,    13,    20,    13,    20,    20,  2157,    20,
    2159,    16,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,  1792,    13,    13,    13,    13,    13,    13,    13,
      13,    13,  1230,  1231,   177,   178,   179,   180,   181,   182,
     183,   184,   185,    13,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
     223,   224,    13,    13,    13,   510,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,  1876,  1877,  1878,  1879,
      15,  1881,    19,  1883,    13,    13,    13,    13,    13,  1889,
    1890,  1891,    13,    13,  1894,  1895,  1896,  1897,    20,  1899,
      19,  1901,    16,  1903,    16,    14,  1906,  1907,  1908,  1909,
      14,   221,   221,  1913,   504,    16,  1916,    14,   347,    13,
      13,    13,    13,    59,    20,    14,    14,  1927,    60,  1929,
      61,    65,    65,  1933,  1934,   144,  1936,  1937,  1938,  1939,
    1940,  1941,  1942,  1943,  1944,  1945,  1946,  1947,    71,  1949,
      60,    62,   144,    71,    62,    62,   472,   144,  1958,  1959,
    1960,  1961,  1962,  1963,  1964,  1965,  1966,    20,    20,    75,
     281,    20,    20,    20,    14,    20,    14,    14,    14,    20,
    1980,  1981,  1982,  1983,    14,    20,    20,  1987,  1988,  1989,
    1990,    20,    20,    14,    20,    20,    20,  1997,  1998,  1999,
    2000,  2001,  2002,  2003,  2004,  2005,  2006,  2007,    20,    14,
      20,    14,    20,    14,    14,  2015,  2016,  2017,    20,  2019,
    2020,    20,  2022,  2023,    20,    20,  2026,    14,  2028,    19,
      14,    20,    20,    14,    20,    14,    14,    14,    20,  2039,
      20,    57,  2042,    19,    14,    20,    20,    20,    20,    20,
    2050,  2051,  2052,    20,    20,    20,    20,  2057,    20,    20,
      20,    20,    20,  2063,    20,    14,  2066,  2067,    20,  2069,
    2070,  2071,    13,    13,    20,    20,    20,    13,    13,   442,
      14,    20,    20,    20,   400,  2085,   144,  2087,    20,    20,
      20,    20,    20,    20,    14,    14,    14,    20,    14,    20,
      57,  2101,    57,    20,    57,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    14,  2116,    20,  2118,    20,
      20,    54,    20,  2123,    20,    20,    20,    20,    20,  2129,
      20,    20,    20,  2133,  2134,    20,  2136,  2137,  2138,    20,
    2140,  2141,    20,    20,  2144,  2145,    20,  2147,    20,    20,
      14,    14,    14,    14,    14,    14,    14,    13,   411,    13,
    2160,  2161,    14,    20,  2164,    20,  2166,  2167,  2168,    20,
      20,    20,    20,    20,  2174,    20,    14,  2177,    20,  2179,
      16,    13,    13,  2183,  2184,  2185,    13,  2187,    13,    57,
      20,    20,    20,  2193,    20,    14,  2196,    20,  2198,    20,
    2200,  2201,  2202,    20,    20,    20,    20,    20,    20,    14,
      16,  2211,  2212,    14,    14,  2215,    20,    14,    20,    14,
    2220,  2221,  2222,  2223,  2224,  2225,    14,  2227,  2228,  2229,
      14,  2231,  2232,  2233,  2234,  2235,    14,    14,  2238,  2239,
    2240,  2241,    14,  2243,    14,    14,    14,    14,    14,    14,
      14,    22,    14,    14,    57,    14,    14,    20,    14,    14,
      20,    14,  2641,    14,    14,    14,    14,    14,    14,   473,
      14,    57,    14,    14,    14,    20,    14,    20,    14,    14,
      14,    20,    14,  2283,    14,    14,    14,    20,    71,    20,
      14,   144,  1381,    20,    20,    20,    13,    20,    20,    20,
      20,    20,    20,    14,    20,    20,    20,    20,    20,    14,
      14,    14,    20,    20,    14,    14,    14,    14,    20,    20,
      14,    14,    14,    14,    20,    20,    14,    14,    14,    14,
      20,    20,    14,    14,    14,    14,    20,    20,    14,    14,
      14,    14,    20,    14,    54,    54,   145,   145,    20,   145,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    16,    16,    16,    20,    14,    14,
      14,    14,    14,    14,    14,    14,  2422,  2423,  1373,    16,
      14,   427,    20,  2429,    20,    20,    14,    20,    20,    14,
      20,    14,    14,    14,    14,    22,    20,  2397,    75,    14,
     432,    20,    20,    20,    20,    14,    20,    20,    20,    20,
      20,    14,    14,    14,    20,    14,    20,    14,   429,    14,
      20,  2421,    20,    14,    20,    14,    14,    20,    14,  1241,
      20,    57,   430,    20,   428,    20,    20,    20,    20,    20,
      20,    14,    20,    20,    20,    20,    20,  1240,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    14,    20,    20,
      20,    20,    20,    14,    20,    14,    20,    14,    14,    14,
      20,    14,    20,    14,    14,    14,    20,    14,    20,  2479,
      14,  2481,    20,  2483,    20,  2485,    14,    14,    14,    14,
    2490,  2491,    14,  2493,  2494,  2495,  2496,    14,  2498,  2499,
    2500,  2501,    20,    14,    20,  2505,    20,    20,  2508,  2509,
      20,    20,    14,    20,  2514,    20,    14,    14,    14,  2519,
      20,  2521,  2522,  2523,  2524,  2525,  2526,  2527,  2528,    20,
    2530,  2531,  2532,  2533,  2534,  2535,  2536,  2537,  2538,  2539,
    2540,  2541,  2542,  2543,    14,  2545,    14,    14,    20,    20,
      14,    14,    14,  2553,    14,    20,    14,  2557,  2558,    14,
      14,    14,    14,    20,    14,    57,    14,  2567,  2568,    20,
      14,    20,    14,    20,    20,    20,    57,  2577,  2578,  2579,
    2580,  2581,    20,  2583,  2584,    20,  2586,  2587,    20,    20,
    2509,  2591,  2592,  2512,    20,    20,  2596,  2597,  2598,  2599,
      20,    14,    20,    20,    20,    14,    20,    22,    20,    20,
      20,  2611,    20,    20,    20,    14,    20,  2617,    20,    20,
      20,  2621,    20,  2623,  2624,    20,    20,    20,    20,    14,
      20,    20,    20,  2633,  2634,  2635,    20,    14,  2638,  2639,
      14,    14,    14,    14,    14,    20,    22,    14,  1244,    14,
      14,  2651,    20,  2653,    20,  2655,  2656,    20,  2658,  2659,
    2660,  2661,  2662,  2663,  2664,  2665,    20,  2667,  2668,  2669,
    2670,  2671,  2672,  2673,  2674,  2675,    20,  2677,  2678,  2679,
    2680,    20,    20,    20,    14,    20,    20,    14,    20,    20,
      14,  2691,  2692,  2693,  2694,    20,    14,  2697,  2698,    20,
      20,    20,    14,    20,    20,    20,    19,  1228,    22,    20,
      20,    20,    20,    20,    20,    20,    14,    20,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    20,  1243,    20,
      20,    20,    20,    20,    20,    20,    14,    14,    14,    14,
      20,    20,    14,  2041,  1083,    -1,    20,    20,    14,    20,
      20,    20,  2798,    20,    14,    20,    20,    20,    14,    14,
      14,    20,    20,    14,    14,    14,   145,    20,    20,    14,
      14,    14,    20,    20,    20,    14,    14,   431,    20,    20,
      20,    14,    14,    20,    20,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    14,   145,   145,   145,
      -1,    -1,    14,    20,    20,    20,    20,    20,    14,    14,
      20,    14,    20,    20,    14,    14,    20,    14,    20,    14,
    1242,    14,    20,    14,    20,    14,    20,    14,    20,    -1,
      20,    14,    20,    -1,    20,    20,    20,  2837,  2838,    20,
    2840,  2841,    20,  2843,  2844,    20,  2846,  2847,  2848,    20,
    2850,  2851,    20,    20,  2854,    20,    20,    20,    20,  2859,
    2860,    14,  2862,    14,  2864,    14,  2866,    22,  2868,  2869,
    2870,  2871,  2872,    20,    20,    20,  2876,  2877,  2878,  2879,
    2880,  2881,    20,  2883,  2884,  2885,  2886,  2887,  2888,  2889,
      20,  2891,  2892,  2893,  2894,  2895,    20,  2897,    20,    20,
      20,    20,  2902,  2903,    14,  2905,  2906,  2907,  2908,  2909,
    2910,    14,  2912,  2913,  2914,  2915,    14,  2917,    14,    20,
      20,  2921,    14,  2923,    14,  2925,    20,    20,  2928,    14,
    2930,  2931,    14,  2933,  2853,    14,    20,    14,  2857,    20,
    2940,    14,  2942,    -1,    20,  2945,  2946,    14,    20,    20,
      20,    20,    14,    14,    20,    20,    20,    20,    14,    14,
      20,  2961,  2962,  2963,  2964,  2965,    20,    20,    20,    20,
      20,  2971,  2972,  2973,    20,    20,    14,    14,    20,    14,
      14,    14,    14,    14,    14,    -1,    14,    -1,    14,    14,
      -1,    20,    14,    20,    14,    14,    20,    14,    14,    20,
      14,    14,    14,    -1,    14,    20,    14,    -1,    14,    20,
      -1,    20,    14,    20,    -1,    20,    -1,    20,    22,    20,
      20,    20,    20,    20,    20,    14,    20,    20,    20,    20,
      20,    14,    20,    14,    20,    14,    20,    14,    20,    14,
      20,    14,    20,    14,    20,    14,    20,    14,    20,    -1,
      20,    -1,    20,    -1,    20,    20,    20,    20,    20,    20,
      14,  3061,    20,    20,  3064,  3065,  3066,    14,    14,    14,
    3070,    14,  3072,  3073,    -1,    14,    20,    14,  3078,  3079,
      20,  3081,    20,  3083,  3084,  3085,  3086,  3087,  3088,    14,
    3090,  3091,  3092,  3093,  3094,  3095,  3096,    20,  3098,    20,
      20,  3101,  3102,  3103,  3104,  3105,    14,    20,    20,    14,
      20,  3111,  3112,    20,    14,  3115,    20,    14,    20,  3119,
    3120,  3121,    20,    14,  3124,    20,    14,    20,    20,    14,
    3130,  3131,    14,    20,  3134,  3135,    20,    20,  3138,    14,
    3140,  3141,    20,    20,  3144,  3145,    20,  3147,    14,  3149,
    3150,  3151,    20,    20,    14,    20,    20,    20,  3077,    20,
      14,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3211,  3212,  3213,  3214,    -1,  3216,  3217,    -1,    -1,
    3220,    -1,    -1,    -1,    -1,    -1,    -1,  3227,    -1,  3229,
      -1,  3231,    -1,    -1,  3234,    -1,    -1,    -1,    -1,  3239,
      -1,    -1,    -1,    -1,  3244,  3245,    -1,  3247,    -1,  3249,
      -1,  3251,  3252,  3253,    -1,  3255,  3256,    -1,  3258,    -1,
    3260,    -1,  3262,  3263,  3264,    -1,    -1,  3267,  3268,  3269,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3306,    -1,    -1,    -1,
    3310,  3311,    -1,    -1,    -1,  3315,    -1,  3317,  3318,    -1,
    3320,  3321,    -1,    -1,    -1,  3325,    -1,    -1,  3328,  3329,
    3330,    -1,  3332,  3333,    -1,  3335,  3336,    -1,    -1,  3339,
    3340,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3362,    -1,    -1,    -1,    -1,    -1,  3368,  3369,
    3370,    -1,    -1,    -1,  3374,  3375,    -1,    -1,  3378,  3379,
      -1,    -1,  3382,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3396,  3397,    -1,  3399,
      -1,  3401,    -1,    -1,  3404,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3414,    -1,  3416,  3417,  3418,    -1,
       0,    -1,     2,     3,     4,  3425,  3426,  3427,    -1,    -1,
      -1,    -1,  3432,  3433,  3434,    -1,    -1,    -1,    18,  3439,
    3440,    21,    -1,  3443,    24,    -1,    -1,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,     9,    10,
      11,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,    50,
      51,    -1,    -1,    54,    -1,    56,    -1,    58,    59,    60,
      61,    62,    63,    64,    -1,    66,    67,    -1,    -1,    -1,
      -1,    -1,    73,    74,    -1,    76,    77,    -1,    -1,    -1,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,    -1,    -1,    -1,    -1,   127,   128,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   145,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   145,   146,   147,   148,   149,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   165,    -1,    -1,    -1,    -1,   199,
     200,    -1,    -1,   174,    -1,   176,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   242,    -1,   244,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,
      -1,   261,   262,    -1,   264,   265,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   275,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   284,   285,    -1,    -1,   259,    -1,
     261,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   316,   317,   318,   319,
     320,   321,   322,   323,   324,    -1,    -1,    -1,    -1,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,    -1,    -1,    -1,    -1,   345,   346,    -1,    -1,   349,
     350,   351,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   332,   333,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   385,   386,    -1,    -1,    -1,
      -1,    -1,   392,    -1,   394,   395,   396,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   408,   409,
      -1,   411,   412,   413,    -1,    -1,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,    -1,    -1,    -1,
      -1,    -1,   403,   404,    -1,    -1,   436,   437,   438,    -1,
     440,    -1,   442,   443,    -1,    -1,   446,   447,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     460,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,    -1,   443,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   453,   454,   455,   456,   457,   458,   459,   460,
      -1,    -1,   463,   464,   465,   466,   467,   468,   469,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   485,   486,     7,    -1,     9,    10,
      11,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   537,    -1,    -1,
      -1,    32,    -1,   543,   544,   545,   546,   547,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   526,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    -1,    58,    59,    60,
      61,    -1,    63,    64,    -1,    66,    67,    -1,    -1,    -1,
      -1,    -1,    73,    74,    -1,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   636,   637,   638,   639,
     640,   641,   642,   643,   644,   645,   646,   647,   648,   649,
      -1,    -1,    -1,    -1,   145,   146,   147,   148,   149,    -1,
      -1,    -1,    -1,    -1,   664,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   165,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   176,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   723,    -1,    -1,    -1,    -1,    -1,    -1,
     730,   731,   732,    -1,    -1,   226,    -1,   737,   738,   739,
     740,   741,   742,   743,   744,   745,   746,   747,   748,   749,
     750,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   259,    -1,
     261,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   332,   333,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   861,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   909,
      -1,    -1,   403,   404,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   936,    -1,    -1,    -1,
     940,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,    -1,   443,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   453,   454,   455,   456,   457,   458,   459,   460,
      -1,    -1,   463,   464,   465,   466,   467,   468,   469,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     990,    -1,    -1,    -1,   485,   486,    -1,    -1,    -1,    -1,
    1000,  1001,  1002,  1003,  1004,    -1,    -1,    -1,    -1,    -1,
      -1,  1011,    -1,    -1,    -1,    -1,  1016,  1017,  1018,  1019,
    1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,  1028,    -1,
    1030,    -1,    -1,    -1,    -1,   526,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1043,    -1,    -1,    -1,    -1,    -1,    -1,
    1050,    -1,    -1,    -1,    -1,    -1,  1056,    -1,    -1,  1059,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1069,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1093,    -1,  1095,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1106,    -1,    -1,    -1,
      -1,  1111,  1112,  1113,  1114,  1115,  1116,  1117,  1118,  1119,
    1120,  1121,  1122,  1123,  1124,  1125,  1126,    -1,  1128,  1129,
    1130,  1131,    -1,  1133,  1134,  1135,    -1,    -1,  1138,  1139,
    1140,  1141,  1142,  1143,  1144,  1145,  1146,  1147,  1148,  1149,
    1150,  1151,  1152,  1153,  1154,  1155,  1156,  1157,  1158,  1159,
    1160,  1161,  1162,  1163,  1164,  1165,  1166,  1167,  1168,  1169,
    1170,    -1,    -1,  1173,  1174,  1175,  1176,  1177,  1178,  1179,
    1180,  1181,  1182,  1183,  1184,  1185,  1186,  1187,  1188,  1189,
    1190,  1191,  1192,  1193,  1194,  1195,  1196,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1211,  1212,  1213,  1214,  1215,  1216,    -1,  1218,  1219,
    1220,  1221,  1222,    -1,  1224,    -1,  1226,  1227,  1228,  1229,
    1230,  1231,  1232,  1233,  1234,  1235,  1236,  1237,  1238,  1239,
    1240,  1241,  1242,  1243,  1244,    -1,    -1,  1247,  1248,  1249,
      -1,    -1,    -1,  1253,    -1,    -1,    -1,    -1,    -1,    -1,
    1260,    -1,    -1,    -1,    -1,  1265,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1280,    -1,    -1,  1283,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1294,    -1,  1296,    -1,    -1,    -1,
    1300,  1301,  1302,  1303,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1311,    -1,  1313,  1314,  1315,  1316,  1317,  1318,  1319,
    1320,  1321,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1337,     7,  1339,
      -1,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,  1349,
    1350,  1351,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1360,    -1,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1378,  1379,
    1380,    -1,    -1,    -1,    -1,    -1,    -1,  1387,  1388,    58,
    1390,  1391,  1392,  1393,    63,    64,    65,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    76,    77,  1409,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1418,  1419,
      -1,  1421,    -1,    -1,  1424,    -1,    -1,    -1,  1428,  1429,
      -1,    -1,    -1,  1433,  1434,  1435,  1436,  1437,  1438,    -1,
    1440,    -1,    -1,  1443,  1444,    -1,  1446,  1447,  1448,  1449,
    1450,    -1,    -1,    -1,    -1,  1455,    -1,  1457,  1458,    -1,
      -1,    -1,    -1,  1463,  1464,  1465,    -1,  1467,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,    -1,    -1,
      -1,   150,   151,   152,   153,   154,   155,   156,   157,    -1,
     159,    -1,   161,   162,   163,   164,   165,   166,   167,    -1,
     169,   170,    -1,    -1,    -1,    -1,    -1,   176,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1520,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
      -1,   260,    -1,   262,   263,   264,   265,   266,    -1,    -1,
      -1,    -1,    -1,    -1,   273,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   282,   283,   284,   285,    -1,    -1,    -1,
      -1,   290,    -1,    -1,    -1,   294,    -1,    -1,    -1,    -1,
    1630,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   311,   312,   313,   314,    -1,    -1,    -1,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   344,   345,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1699,
      -1,    -1,  1702,    -1,    -1,    -1,  1706,  1707,  1708,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1757,    -1,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,  1773,    -1,    -1,   445,   446,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   455,   456,   457,   458,
     459,   460,  1792,    -1,   463,   464,   465,   466,   467,   468,
     469,   470,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   487,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   497,   498,
     499,   500,    -1,   502,   503,    -1,    -1,    -1,    -1,   508,
     509,    -1,    -1,    -1,    -1,   514,   515,   516,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   526,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1871,    -1,    -1,    -1,  1875,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1887,  1888,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1915,    -1,  1917,    -1,    -1,
      -1,    -1,    -1,    -1,  1924,    -1,    -1,    -1,    -1,    -1,
      -1,  1931,  1932,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1950,  1951,  1952,  1953,  1954,  1955,  1956,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1970,    -1,  1972,  1973,  1974,  1975,  1976,    -1,  1978,  1979,
      -1,    -1,    -1,    -1,  1984,  1985,    -1,    -1,    -1,    -1,
      -1,  1991,  1992,    -1,    -1,  1995,  1996,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2021,    -1,    -1,  2024,    -1,    -1,    -1,    -1,  2029,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2041,    -1,  2043,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2055,    -1,    -1,  2058,  2059,
    2060,  2061,  2062,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2077,    -1,    -1,
      -1,    -1,    -1,  2083,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2104,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2136,    -1,    -1,    -1,
      -1,    -1,  2142,  2143,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2163,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2241,  2242,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     0,    -1,    -1,    -1,    -1,    -1,
      -1,     7,    -1,     9,    10,    11,    -1,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    50,    51,    -1,    -1,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    -1,    -1,    82,    83,    84,    85,
      -1,    87,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,   165,
      -1,    -1,    -1,    -1,    -1,    -1,   172,   173,   174,   175,
     176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2475,  2476,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   211,   212,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2508,    -1,
     226,    -1,  2512,  2513,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2530,  2531,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   259,    -1,   261,  2546,  2547,  2548,  2549,
    2550,   267,   268,   269,   270,   271,   272,    -1,   274,    -1,
      -1,    -1,    -1,  2563,    -1,    -1,  2566,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   315,
     316,   317,    -1,    -1,    -1,    -1,    -1,  2607,    -1,    -1,
      -1,    -1,    -1,    -1,   330,   331,   332,   333,    -1,    -1,
    2620,    -1,    -1,    -1,    -1,    -1,  2626,    -1,  2628,    -1,
    2630,    -1,  2632,    -1,    -1,    -1,  2636,  2637,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2652,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2683,    -1,    -1,    -1,   403,   404,  2689,
      -1,    -1,    -1,    -1,    -1,  2695,  2696,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     0,    -1,    -1,     3,     4,     5,
      -1,    -1,    -1,    -1,    -1,    -1,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,    22,   443,   444,    -1,
      -1,   447,    -1,    -1,    -1,    -1,    -1,   453,   454,   455,
     456,   457,   458,   459,   460,    -1,    -1,   463,   464,   465,
     466,   467,   468,   469,    -1,   471,    -1,    -1,    -1,    -1,
     476,    -1,   478,   479,    -1,    -1,    -1,   483,   484,   485,
     486,    -1,   488,    -1,    -1,    -1,    -1,    -1,    -1,   495,
     496,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   512,    -1,    -1,    -1,
      -1,   517,   518,    -1,   520,   521,   522,   523,   524,   525,
     526,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,
      -1,    -1,    -1,  2853,    -1,    -1,    -1,  2857,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   161,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2883,  2884,  2885,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2896,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2919,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2935,  2936,    -1,    -1,    -1,
      -1,  2941,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2969,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   281,    -1,    -1,   284,   285,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     316,   317,   318,   319,   320,   321,   322,   323,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   331,   332,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   348,    -1,   350,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3074,    -1,    -1,  3077,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3096,    -1,  3098,    -1,
      -1,  3101,  3102,    -1,    -1,    -1,  3106,  3107,  3108,  3109,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3137,    -1,  3139,
     436,   437,   438,    -1,   440,   441,   442,   443,  3148,    -1,
     446,   447,    -1,     7,    -1,     9,    10,    11,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    -1,    -1,    -1,    50,    51,    -1,    -1,
      54,    -1,    56,    -1,    58,    59,    60,    61,    62,    63,
      64,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    73,
      74,    -1,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3239,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   543,   544,   545,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3257,    -1,  3259,
      -1,    -1,    -1,    -1,    -1,    -1,  3266,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   145,   146,   147,   148,   149,  3296,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3309,
      -1,   165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     174,    -1,   176,    -1,  3324,    -1,    -1,  3327,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     636,   637,   638,   639,   640,   641,   642,   643,   644,   645,
     646,   647,   648,   649,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     0,    -1,    -1,    -1,    -1,    -1,    -1,   664,    -1,
      -1,    -1,   226,    -1,    -1,    -1,  3376,    -1,    -1,    18,
      -1,    -1,    -1,    -1,  3384,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3402,    -1,    -1,   259,  3406,   261,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   730,   731,   732,    -1,    -1,    -1,
      -1,   737,   738,   739,   740,   741,   742,   743,   744,   745,
     746,   747,   748,   749,   750,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   332,   333,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   145,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   838,   839,   840,    -1,   842,   843,   844,   845,
     846,   847,   848,   849,   850,   851,   852,   853,   854,   855,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,    -1,   443,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   453,
     454,   455,   456,   457,   458,   459,   460,    -1,    -1,   463,
     464,   465,   466,   467,   468,   469,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   485,   486,    -1,    -1,    -1,    -1,    -1,    -1,   278,
     279,    -1,    -1,    -1,    -1,   284,   285,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   526,    -1,    -1,    -1,    -1,   316,   317,   318,
     319,   320,   321,   322,   323,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   331,   332,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1000,  1001,  1002,    -1,    -1,    -1,
      -1,   350,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1016,  1017,  1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,
    1026,  1027,  1028,    -1,  1030,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1069,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   436,   437,   438,
      -1,    -1,    -1,    -1,    -1,    -1,   445,   446,   447,    -1,
      -1,    -1,    -1,    -1,    -1,  1111,  1112,    -1,  1114,  1115,
      -1,    -1,    -1,    -1,    -1,  1121,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1133,  1134,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1161,  1162,  1163,  1164,  1165,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1188,    -1,    -1,    -1,    -1,    -1,    -1,  1195,
    1196,    -1,    -1,    -1,   543,   544,   545,   546,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1211,  1212,  1213,    -1,  1215,
    1216,    -1,  1218,  1219,  1220,  1221,    -1,    -1,  1224,    -1,
    1226,    -1,  1228,  1229,  1230,  1231,  1232,  1233,  1234,  1235,
    1236,  1237,  1238,  1239,  1240,  1241,  1242,  1243,  1244,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1280,    -1,    -1,  1283,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   636,   637,   638,
     639,   640,   641,   642,   643,   644,   645,   646,   647,   648,
     649,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   664,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1339,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   730,   731,   732,    -1,    -1,    -1,    -1,   737,   738,
     739,   740,   741,   742,   743,   744,   745,   746,   747,   748,
     749,   750,    -1,  1409,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1419,    -1,  1421,    -1,    -1,    -1,    -1,
      -1,    -1,  1428,    -1,    -1,    -1,    -1,  1433,  1434,  1435,
      -1,  1437,    -1,    -1,    -1,    -1,    -1,  1443,    -1,    -1,
    1446,  1447,  1448,  1449,  1450,    -1,    -1,    -1,    -1,    -1,
      -1,  1457,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1520,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,
      -1,    -1,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1000,  1001,  1002,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1016,  1017,  1018,
    1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,  1028,
      -1,  1030,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1699,    -1,    -1,  1702,    -1,    -1,    -1,
    1706,    -1,   127,   128,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1069,    -1,    -1,    -1,    -1,    -1,    -1,  1076,    -1,    -1,
      -1,    -1,    -1,  1082,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1757,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1111,  1112,    -1,  1114,  1115,    -1,    -1,    -1,
      -1,    -1,  1121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1133,  1134,  1792,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1147,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1161,  1162,  1163,  1164,  1165,   242,    -1,   244,
      -1,    -1,  1171,  1172,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   261,   262,    -1,  1188,
      -1,    -1,    -1,    -1,    -1,    -1,  1195,  1196,    -1,    -1,
     275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,
     285,    -1,  1211,  1212,  1213,    -1,  1215,  1216,    -1,  1218,
    1219,  1220,  1221,    -1,    -1,  1224,    -1,  1226,    -1,  1228,
    1229,  1230,  1231,  1232,  1233,  1234,  1235,  1236,  1237,  1238,
    1239,  1240,  1241,  1242,  1243,  1244,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1917,    -1,    -1,    -1,    -1,    -1,    -1,  1924,    -1,
      -1,    -1,    -1,    -1,   349,  1931,    -1,    -1,    -1,    -1,
      -1,  1280,    -1,    -1,  1283,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1952,  1953,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   386,    -1,    -1,    -1,    -1,    -1,   392,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1984,  1985,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   412,   413,    -1,
    1339,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,
      -1,     9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   447,  2029,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2041,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,
      58,    59,    60,    61,    -1,    63,    64,    -1,    66,    67,
    1409,    -1,    -1,    -1,    -1,    73,    74,    -1,    76,    77,
    1419,  2077,  1421,    -1,    -1,    -1,    -1,    -1,    -1,  1428,
      -1,  1430,  1431,  1432,  1433,  1434,  1435,    -1,  1437,    -1,
    1439,    -1,  1441,  1442,  1443,    -1,    -1,  1446,  1447,  1448,
    1449,  1450,    -1,    -1,    -1,    -1,    -1,    -1,  1457,    -1,
      -1,   536,   537,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   547,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2136,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,
     148,   149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,    -1,
      -1,  1520,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2241,  2242,    -1,    -1,   284,
     285,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   259,    -1,   261,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   316,   317,   318,   319,   320,   321,   322,   323,    -1,
      -1,  1630,    -1,    -1,    -1,    -1,   331,   332,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   723,    -1,
      -1,    -1,    -1,    -1,    -1,   350,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   332,   333,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1697,    -1,
    1699,    -1,    -1,  1702,    -1,    -1,    -1,  1706,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   436,   437,   438,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   446,   447,    -1,    -1,    -1,    -1,    -1,  1757,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,    -1,   443,   861,    -1,    -1,    -1,
      -1,    -1,    -1,  1792,    -1,   453,   454,   455,   456,   457,
     458,   459,   460,    -1,    -1,   463,   464,   465,   466,   467,
     468,   469,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   485,   486,    -1,
      -1,    -1,    -1,    -1,   909,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   936,    -1,    -1,    -1,   940,    -1,    -1,   526,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2563,    -1,    -1,
    2566,    -1,    -1,    -1,    -1,   990,    -1,    -1,  1917,    -1,
      -1,    -1,    -1,    -1,    -1,  1924,    -1,    -1,    -1,  1004,
      -1,    -1,  1931,    -1,    -1,    -1,  1011,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1952,  1953,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1043,    -1,
    2626,    -1,  2628,    -1,  2630,    -1,  2632,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1984,  1985,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1093,    -1,
    1095,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2029,  1106,    -1,  2689,    -1,    -1,  1111,    -1,    -1,  2695,
    2696,    -1,  2041,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2077,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1173,  1174,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2136,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1222,    -1,  1224,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1247,  1248,  1249,    -1,    -1,    -1,  1253,    -1,
      -1,    -1,    -1,    -1,    -1,  1260,    -1,    -1,    -1,    -1,
    1265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2241,  2242,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2935,
      -1,    -1,    -1,    -1,    -1,  1360,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1378,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1387,  2969,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1436,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1444,
      -1,    -1,    -1,    -1,  1069,    -1,    -1,    -1,    -1,    -1,
    1455,    -1,  1457,  1458,    -1,    -1,    -1,    -1,  1463,  1464,
    1465,    -1,  1467,    -1,    -1,    -1,  1471,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1111,  1112,    -1,  1114,
    1115,    -1,    -1,    -1,    -1,    -1,  1121,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1133,  1134,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1161,  1162,  1163,  1164,
    1165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3148,  1188,    -1,    -1,    -1,    -1,    -1,    -1,
    1195,  1196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1211,  1212,  1213,    -1,
    1215,  1216,    -1,  1218,  1219,  1220,  1221,    -1,    -1,  1224,
      -1,  1226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2563,    -1,    -1,  2566,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1280,    -1,    -1,  1283,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3266,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2626,    -1,  2628,
      -1,  2630,    -1,  2632,    -1,    -1,    -1,    -1,    -1,    -1,
    3296,    -1,    -1,    -1,  1339,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3324,    -1,
      -1,  3327,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2689,    -1,    -1,    -1,    -1,    -1,  2695,  2696,  1773,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1409,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1419,    -1,  1421,    -1,  3384,    -1,
      -1,    -1,    -1,  1428,    -1,    -1,    -1,    -1,  1433,  1434,
    1435,    -1,  1437,    -1,    -1,    -1,    -1,    -1,  1443,    -1,
    3406,  1446,  1447,  1448,  1449,  1450,    -1,    -1,    -1,    -1,
      -1,    -1,  1457,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     7,    -1,     9,    10,    11,    -1,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1871,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    -1,    -1,    -1,    50,    51,    -1,    -1,    54,    -1,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    -1,
      66,    67,    -1,    -1,    -1,    -1,    -1,    73,    74,    -1,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1992,    -1,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2935,    -1,    -1,   165,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,    -1,
     176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2969,    -1,    -1,    -1,    -1,    -1,  2051,  2052,    -1,    -1,
    2055,    -1,  2057,  2058,  2059,  2060,  2061,  2062,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     226,    -1,    -1,    -1,  1699,    -1,    -1,    -1,    -1,    -1,
      -1,  1706,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   259,    -1,   261,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1757,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1792,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   332,   333,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3148,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,    -1,   443,    -1,    -1,
      -1,    -1,  1917,    -1,    -1,    -1,    -1,   453,   454,   455,
     456,   457,   458,   459,   460,    -1,  1931,   463,   464,   465,
     466,   467,   468,   469,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1952,  1953,   485,
     486,    -1,    -1,    -1,    -1,    -1,    -1,  3266,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1984,
    1985,    -1,    -1,    -1,    -1,    -1,    -1,  3296,    -1,    -1,
     526,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     7,    -1,     9,    10,    11,    -1,    13,    -1,    -1,
      -1,    17,    -1,    -1,    -1,  3324,    -1,    -1,  3327,    -1,
      -1,    -1,    -1,    -1,  2029,    31,    32,    -1,    -1,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    -1,    -1,    -1,    50,    51,    -1,    -1,    54,    -1,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    -1,    -1,    73,    74,    75,
      76,    77,    -1,    -1,    -1,  3384,    -1,    -1,    -1,    -1,
      86,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,
    2475,  2476,    -1,    -1,    -1,    -1,    -1,  3406,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,    -1,   159,    -1,   161,   162,   163,   164,   165,
     166,   167,    -1,   169,   170,    -1,    -1,    -1,   174,    -1,
     176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,    -1,    -1,    -1,    -1,   225,
     226,    -1,  2607,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2241,  2242,    -1,    -1,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,    -1,    -1,    -1,    -1,    -1,    -1,   273,    -1,    -1,
      -1,   277,   278,   279,    -1,    -1,   282,   283,   284,   285,
     286,   287,   288,   289,   290,    -1,    -1,   293,   294,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   311,   312,   313,   314,    -1,
      -1,    -1,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,    -1,    -1,   332,   333,   334,    -1,
      -1,   337,   338,   339,   340,    -1,   342,   343,   344,   345,
     346,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   402,   403,   404,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,    -1,   443,    -1,   445,
     446,    -1,   448,    -1,    -1,    -1,    -1,   453,   454,   455,
     456,   457,   458,   459,   460,    -1,    -1,   463,   464,   465,
     466,   467,   468,   469,   470,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   485,
     486,   487,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   497,   498,   499,   500,    -1,   502,   503,    -1,   505,
     506,   507,   508,   509,    -1,   511,    -1,   513,   514,   515,
     516,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     526,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2919,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2563,    -1,
      -1,  2566,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2626,    -1,  2628,    -1,  2630,    -1,  2632,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2689,    -1,    -1,    -1,    -1,  3074,
    2695,  2696,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,
      -1,     9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    -1,    -1,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,
      -1,    -1,    50,    51,    -1,    -1,    54,    -1,    56,    -1,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    -1,    70,    -1,    -1,    73,    74,    -1,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3216,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
      -1,   159,    -1,   161,   162,   163,   164,   165,   166,   167,
      -1,   169,   170,    -1,    -1,    -1,   174,    -1,   176,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,    -1,    -1,    -1,    -1,   225,   226,    -1,
      -1,    -1,    -1,    -1,  3309,    -1,    -1,    -1,    -1,    -1,
    2935,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,    -1,
      -1,    -1,    -1,    -1,  2969,   273,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,   403,   404,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,    -1,   443,    -1,   445,   446,    -1,
      -1,    -1,    -1,  3148,    -1,   453,   454,   455,   456,   457,
     458,   459,   460,    -1,    -1,   463,   464,   465,   466,   467,
     468,   469,   470,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   485,   486,   487,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   497,
     498,   499,   500,    -1,   502,   503,    -1,    -1,    -1,    -1,
     508,   509,    -1,    -1,    -1,    -1,   514,   515,   516,    -1,
      -1,     7,    -1,     9,    10,    11,    -1,    13,   526,    -1,
      -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    -1,    -1,    -1,    50,    51,    -1,    -1,    54,    -1,
      56,  3266,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    -1,    70,    -1,    -1,    73,    74,    -1,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3296,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3324,
      -1,    -1,  3327,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,    -1,   159,    -1,   161,   162,   163,   164,   165,
     166,   167,    -1,   169,   170,    -1,    -1,    -1,   174,  3384,
     176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3406,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,    -1,   443,    -1,   445,
     446,    -1,    -1,    -1,    -1,    -1,    -1,   453,   454,   455,
     456,   457,   458,   459,   460,    -1,    -1,   463,   464,   465,
     466,   467,   468,   469,   470,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   485,
     486,   487,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   497,   498,   499,   500,    -1,   502,   503,    -1,    -1,
      -1,    -1,   508,   509,    -1,    -1,    -1,    -1,   514,   515,
     516,     7,    -1,     9,    10,    11,    -1,    13,    -1,    -1,
     526,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,    -1,   443,    -1,   445,
     446,    -1,    -1,    -1,    -1,    -1,    -1,   453,   454,   455,
     456,   457,   458,   459,   460,    -1,    -1,   463,   464,   465,
     466,   467,   468,   469,   470,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   485,
     486,   487,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   497,   498,   499,   500,    -1,   502,   503,    -1,    -1,
      -1,    -1,   508,   509,    -1,    -1,    -1,    -1,   514,   515,
     516,     7,    -1,     9,    10,    11,    -1,    13,    -1,    -1,
     526,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,    -1,   443,    -1,   445,
     446,    -1,    -1,    -1,    -1,    -1,    -1,   453,   454,   455,
     456,   457,   458,   459,   460,    -1,    -1,   463,   464,   465,
     466,   467,   468,   469,   470,    -1,    -1,    -1,    -1,    -1,
       7,    -1,     9,    10,    11,    -1,    13,    -1,    -1,   485,
     486,   487,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   497,   498,   499,   500,    32,   502,   503,    35,    36,
      -1,    -1,   508,   509,    -1,    -1,    -1,    -1,   514,   515,
     516,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
     526,    58,    59,    60,    61,    -1,    63,    64,    65,    66,
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
     167,    -1,   169,   170,    -1,    -1,    -1,    -1,    -1,   176,
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
      -1,    -1,    -1,    -1,    -1,    -1,   403,   404,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,    -1,   443,    -1,   445,   446,
      -1,    -1,    -1,    -1,    -1,    -1,   453,   454,   455,   456,
     457,   458,   459,   460,    -1,    -1,   463,   464,   465,   466,
     467,   468,   469,   470,    -1,    -1,    -1,    -1,    -1,     7,
      -1,     9,    10,    11,    -1,    13,    -1,    -1,   485,   486,
     487,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     497,   498,   499,   500,    32,   502,   503,    35,    36,    -1,
      -1,   508,   509,    -1,    -1,    -1,    -1,   514,   515,   516,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,   526,
      58,    59,    60,    61,    -1,    63,    64,    65,    66,    67,
      -1,    -1,    70,    -1,    -1,    73,    74,    -1,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
      -1,   159,    -1,   161,   162,   163,   164,   165,   166,   167,
      -1,   169,   170,    -1,    -1,    -1,    -1,    -1,   176,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,    -1,    -1,    -1,    -1,   225,   226,    -1,
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
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,    -1,   443,    -1,   445,   446,    -1,
      -1,    -1,    -1,    -1,    -1,   453,   454,   455,   456,   457,
     458,   459,   460,    -1,    -1,   463,   464,   465,   466,   467,
     468,   469,   470,    -1,    -1,    -1,    -1,    -1,     7,    -1,
       9,    10,    11,    -1,    13,    -1,    -1,   485,   486,   487,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   497,
     498,   499,   500,    32,   502,   503,    35,    36,    -1,    -1,
     508,   509,    -1,    -1,    -1,    -1,   514,   515,   516,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,   526,    58,
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
     169,   170,    -1,    -1,    -1,    -1,    -1,   176,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,    -1,    -1,    -1,   225,   226,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,    -1,    -1,
      -1,    -1,    -1,    -1,   273,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   282,   283,   284,   285,    -1,    -1,    -1,
      -1,   290,    -1,    -1,    -1,   294,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   311,   312,   313,   314,    -1,    -1,    -1,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,    -1,    -1,   332,   333,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   344,   345,    -1,    -1,    -1,
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
       9,    10,    11,    -1,    13,    -1,    -1,   526,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    51,    -1,    -1,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    -1,    -1,    82,    83,    84,    85,    -1,    87,    88,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   160,    -1,    -1,    -1,    -1,   165,    -1,    -1,    -1,
      -1,    -1,    -1,   172,   173,   174,   175,   176,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   211,   212,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     259,    -1,   261,    -1,    -1,    -1,    -1,    -1,   267,   268,
     269,   270,   271,   272,    -1,   274,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   315,   316,   317,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   330,   331,   332,   333,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   403,   404,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,    -1,   443,   444,    -1,     7,   447,    -1,
      10,    11,    -1,    13,   453,   454,   455,   456,   457,   458,
     459,   460,    -1,    -1,   463,   464,   465,   466,   467,   468,
     469,    -1,   471,    -1,    -1,    35,    36,   476,    -1,   478,
     479,    -1,    -1,    -1,   483,   484,   485,   486,    -1,   488,
      -1,    -1,    -1,    -1,    -1,    -1,   495,   496,    58,    -1,
      -1,    -1,    -1,    63,    64,    65,    -1,    -1,    -1,    -1,
      70,    -1,    -1,   512,    -1,    -1,    76,    77,   517,   518,
      -1,   520,   521,   522,   523,   524,   525,   526,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   344,   345,   346,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     7,    -1,    -1,    10,    11,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,   429,
     430,   431,    -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,
      63,    64,    65,    -1,    -1,   445,   446,    70,    -1,    -1,
      -1,    -1,    -1,    76,    77,   455,   456,   457,   458,   459,
     460,    -1,    -1,   463,   464,   465,   466,   467,   468,   469,
     470,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   487,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   497,   498,   499,
     500,    -1,   502,   503,    -1,    -1,    -1,    -1,   508,   509,
      -1,    -1,    -1,    -1,   514,   515,   516,    -1,    -1,    -1,
      -1,    -1,    -1,   146,    -1,    -1,   526,   150,   151,   152,
     153,   154,   155,   156,   157,    -1,   159,    -1,   161,   162,
     163,   164,   165,   166,   167,    -1,   169,   170,    -1,    -1,
      -1,    -1,    -1,   176,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,    -1,    -1,
      -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,    -1,   260,    -1,   262,
     263,   264,   265,   266,    -1,    -1,    -1,    -1,    -1,    -1,
     273,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   282,
     283,   284,   285,    -1,    -1,    -1,    -1,   290,    -1,    -1,
      -1,   294,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   311,   312,
     313,   314,    -1,    -1,    -1,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   344,   345,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     7,    -1,    -1,    10,    11,    -1,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   428,   429,   430,   431,    -1,
      -1,    -1,    58,    -1,    -1,    -1,    -1,    63,    64,    65,
      -1,    -1,   445,   446,    70,    -1,    -1,    -1,    -1,    -1,
      76,    77,   455,   456,   457,   458,   459,   460,    -1,    -1,
     463,   464,   465,   466,   467,   468,   469,   470,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   487,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   497,   498,   499,   500,    -1,   502,
     503,    -1,    -1,    -1,    -1,   508,   509,    -1,    -1,    -1,
      -1,   514,   515,   516,    -1,    -1,    -1,    -1,    -1,    -1,
     146,    -1,    -1,   526,   150,   151,   152,   153,   154,   155,
     156,   157,    -1,   159,    -1,   161,   162,   163,   164,   165,
     166,   167,    -1,   169,   170,    -1,    -1,    -1,    -1,    -1,
     176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,    -1,    -1,    -1,    -1,   225,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,    -1,   260,    -1,   262,   263,   264,   265,
     266,    -1,    -1,    -1,    -1,    -1,    -1,   273,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   282,   283,   284,   285,
      -1,    -1,    -1,    -1,   290,    -1,    -1,    -1,   294,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   311,   312,   313,   314,    -1,
      -1,    -1,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     7,    -1,     9,    10,    11,    -1,    13,   344,   345,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    -1,    -1,    -1,    50,    51,    -1,    -1,    54,    -1,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    -1,
      66,    67,    -1,    -1,    -1,    -1,    -1,    73,    74,    -1,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   428,   429,   430,   431,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   445,
     446,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   455,
     456,   457,   458,   459,   460,    -1,    -1,   463,   464,   465,
     466,   467,   468,   469,   470,    -1,    -1,    -1,    -1,   145,
     146,   147,   148,   149,     7,    -1,     9,    10,    11,    -1,
      13,   487,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,
      -1,   497,   498,   499,   500,    -1,   502,   503,   174,    32,
     176,    -1,   508,   509,    -1,    -1,    -1,    -1,   514,   515,
     516,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     526,    -1,    -1,    56,    -1,    58,    59,    60,    61,    -1,
      63,    64,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,
      73,    74,    -1,    76,    77,    -1,    -1,    -1,    -1,    -1,
     226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   259,    -1,   261,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   145,   146,   147,   148,   149,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   176,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   332,   333,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   259,    -1,   261,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,    -1,   443,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   453,   454,   455,
     456,   457,   458,   459,   460,    -1,    -1,   463,   464,   465,
     466,   467,   468,   469,    -1,    -1,    -1,    -1,    -1,   332,
     333,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   485,
     486,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     526,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,    -1,
     443,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     453,   454,   455,   456,   457,   458,   459,   460,    -1,    -1,
     463,   464,   465,   466,   467,   468,   469,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   485,   486,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   526
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
     331,   332,   333,   403,   404,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   443,   444,   447,   453,   454,
     455,   456,   457,   458,   459,   460,   463,   464,   465,   466,
     467,   468,   469,   471,   476,   478,   479,   483,   484,   485,
     486,   488,   495,   496,   512,   517,   518,   520,   521,   522,
     523,   524,   525,   526,   528,   529,   530,   531,   532,   533,
     536,   537,   538,   539,   543,   544,   545,   546,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   610,   611,    10,
      11,    13,    59,    60,    61,    63,    64,    66,    67,    73,
      74,    76,    77,   165,   176,   455,   456,   457,   458,   459,
     460,   463,   464,   465,   466,   467,   468,   469,   553,   554,
     569,   608,    66,   554,   594,   554,   594,    62,   567,   568,
     569,   607,    13,    13,    13,   482,   569,   608,    54,    68,
      69,    70,   610,   569,   546,   567,   607,   546,   567,   546,
     569,    13,    13,   546,    13,    13,   133,   134,   144,   133,
     134,   144,   133,   134,   144,   144,    19,    19,   124,   125,
      13,   144,    19,   144,    13,    13,   530,   610,   239,    19,
      19,    15,   123,    15,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    69,    71,    72,    73,    74,    75,    76,
      77,   569,   611,   546,    13,    13,    13,    13,    15,    13,
      13,    15,    13,    15,    13,    19,    19,    19,    19,    13,
      13,    13,    15,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,   554,   594,   554,   594,   554,   594,   554,   594,
     554,   594,   554,   594,   554,   594,   554,   594,   554,   594,
     554,   594,   554,   594,   554,   594,   554,   594,   610,   547,
     548,   567,   530,   546,   546,    13,    13,    13,    71,   610,
     610,    13,    13,    13,    13,    13,    13,     0,     0,   530,
     531,   532,   533,   536,   537,   538,   539,   530,    10,    11,
      12,    12,   140,   141,   554,   594,     7,     8,    12,    10,
      11,     5,     6,   138,   139,   140,   141,    17,     4,    18,
     136,    21,   137,    13,    15,    19,   123,   124,   144,   142,
       7,   143,    10,    11,    19,   123,   123,   144,    19,    19,
      19,    19,    15,    15,    19,    19,    13,    19,    19,    14,
      14,    19,    14,   546,   567,   546,    19,   546,   546,    76,
     611,   611,   567,   567,   567,   546,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   377,   407,   408,   409,   410,   411,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   501,
     519,   349,   351,   353,   354,   361,   364,   365,   366,   367,
     368,   369,   370,   371,   401,   405,   410,   411,   421,   426,
     427,   608,   608,   567,   567,   607,    42,    43,   449,   450,
     451,   452,   448,    10,    11,    13,    17,    35,    36,    63,
      65,    70,   146,   150,   151,   152,   153,   154,   155,   156,
     157,   159,   161,   162,   163,   164,   165,   166,   167,   169,
     170,   176,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   225,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   260,
     262,   263,   264,   265,   266,   273,   282,   283,   284,   285,
     290,   294,   311,   312,   313,   314,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   344,   345,
     428,   429,   430,   431,   445,   446,   455,   456,   457,   458,
     459,   460,   463,   464,   465,   466,   467,   468,   469,   470,
     487,   497,   498,   499,   500,   502,   503,   508,   509,   514,
     515,   516,   541,   546,   553,   567,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   608,   541,    41,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   409,    42,   242,   567,   346,   567,    15,   567,   567,
      10,    11,    13,    63,   146,   165,   176,   455,   456,   457,
     458,   459,   460,   463,   464,   465,   466,   467,   468,   469,
     553,   569,   588,   608,    63,   567,   588,   588,   588,   588,
     588,   588,   588,   569,   168,   221,   222,   223,   224,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   223,   224,   223,   224,   223,   224,   569,   569,   569,
     588,   588,   569,   569,   569,   569,   569,   569,   569,   569,
      54,    54,   567,   567,   569,   567,   569,   567,    10,    11,
      13,    66,   455,   456,   457,   458,   459,   460,   463,   464,
     465,   466,   467,   468,   469,   553,   607,   546,   588,   569,
     144,   475,    55,   547,   530,   610,   611,   546,    54,   535,
     534,   547,   567,   546,    63,   569,   569,   569,   530,   544,
     544,   567,   545,   546,   546,   554,   554,   554,   555,   555,
     557,   557,   557,   557,   558,   558,   559,   560,   561,   562,
     564,   563,   567,   567,    49,    50,   158,   221,   239,   242,
     243,   244,   245,   274,   275,   276,   406,   407,   412,   425,
     442,   610,   588,   588,   567,   588,   554,   594,   594,   555,
     595,   555,   595,   239,   240,   241,   242,   272,   280,   291,
     295,   338,   340,   341,   342,   351,   352,   357,   358,   359,
     360,   372,   373,   374,   375,   376,   378,   379,   380,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   510,   277,   278,   279,   286,   287,
     288,   289,   293,   334,   337,   338,   339,   340,   342,   343,
     346,   505,   506,   507,   511,   513,   608,   609,   346,   588,
      10,    11,    13,    17,    35,    37,    65,    68,    75,    86,
      89,   346,   402,   433,   436,   448,   455,   456,   457,   458,
     459,   460,   463,   464,   465,   466,   467,   468,   469,   546,
     553,   567,   588,   589,   607,   608,   609,    80,   567,   567,
     567,    13,   552,    20,    14,    14,    14,    20,    14,    14,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    20,
     546,   567,   546,    13,    13,    13,   569,   573,   574,   574,
     568,   588,    59,    60,   569,   608,    13,   546,    13,    19,
      19,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    19,    13,    13,
      13,    13,    19,    13,    13,    13,    19,    19,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,   574,   574,   574,
     574,   574,   574,   574,   574,   574,   574,   574,   574,   574,
     574,    13,    13,    13,    13,    13,    13,    19,    13,    13,
      13,    13,    13,    14,    20,   574,    13,    15,   144,     4,
       7,     8,    10,    11,     5,     6,   138,   139,   140,   141,
      17,    18,   136,    21,   137,    19,    14,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
     546,    16,    15,    16,   567,    14,    20,   568,   569,    19,
      13,    19,    19,    13,    14,    19,    20,    14,    16,    14,
      14,    16,    14,    16,    20,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    20,    14,    20,
      14,    16,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    14,    14,    20,    20,    14,    20,    14,    14,
      20,    14,   567,   540,   546,   549,   481,   530,    14,    14,
      14,    14,    13,    13,   530,    20,    14,    20,    20,    20,
      20,    22,    14,    20,    22,    23,    16,    13,    13,   546,
      13,    13,    13,    13,    13,    13,    13,    13,    13,   546,
      13,    13,   546,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,   546,    13,    13,    13,    13,
      13,    19,    15,   611,    15,    13,    19,    13,    13,    15,
      13,    13,    13,    13,    20,    20,    19,    13,    16,    16,
     546,    12,   567,   567,   569,   567,   567,   567,   567,   567,
     569,   567,   567,    63,   569,    56,    63,   567,   567,   567,
     567,   567,   567,   567,   588,   567,    65,   567,    71,   567,
     567,   609,   567,   567,   567,   567,   567,   608,    65,   589,
      65,    56,   567,   567,   567,   567,   546,    59,    62,   546,
      14,    14,   546,   568,   569,   567,   347,   347,   348,   541,
     588,   569,   588,   588,   569,   569,   569,   569,   569,   588,
     569,   569,   569,   569,   569,    52,    53,   569,   569,   569,
     569,    52,   186,   221,   588,   588,   569,   221,   221,   569,
     569,   569,   569,   569,   569,   569,   569,   569,   588,   569,
     569,   569,   569,   569,   569,   569,   569,   569,   569,   569,
     569,   569,   588,   588,   588,   588,   588,   569,   569,   569,
     569,   569,   608,   608,   546,   546,   569,   569,   569,   569,
     569,   569,   569,   569,   569,   569,   569,   569,   569,   588,
     569,   569,   569,   569,   569,   569,   588,   588,   588,   588,
     588,   569,   588,   588,   504,   588,   588,   588,   588,   546,
      17,    63,   546,   567,   588,   588,    22,    63,   567,   569,
     612,   587,   574,   554,   574,   554,   574,   555,   575,   555,
     575,   557,   578,   557,   578,   557,   578,   557,   578,   557,
     579,   557,   579,   580,   582,   583,   585,   584,   292,   381,
     382,   383,   384,   530,   546,   546,   546,   567,    59,    60,
     546,    61,    60,   567,    62,    62,    62,   546,   567,    71,
     567,   567,   546,   567,   567,   567,   567,   144,   567,   144,
      16,    71,    14,    19,   588,   567,    13,    13,    13,   569,
     567,   569,   567,   567,   567,   569,   569,   569,   569,   567,
     567,   567,   567,   567,   567,   567,   569,   567,   569,   569,
     569,   171,   569,   569,   171,   569,   171,   569,   569,   569,
     567,   567,   567,   567,   567,   567,   567,   567,   567,   567,
     567,   567,   567,   567,   567,   569,   588,    13,   567,   567,
     567,   567,   567,   567,   567,   569,   569,   569,   567,   567,
     567,   546,   472,    20,   547,   547,   489,   490,   491,   492,
     493,   542,   542,   567,   567,   546,   569,   569,   565,   567,
     567,   567,   144,   546,   569,   569,   569,   567,   569,   567,
     569,   567,   567,   567,   567,   567,   567,   567,   567,   567,
     567,   567,   567,   567,   588,   567,   567,   567,   567,   567,
     567,   567,   567,   569,   588,   567,   588,   567,   567,   569,
     567,   567,   567,   588,   569,   608,   608,   608,   588,   588,
     588,   546,   588,   569,   608,   569,   608,   608,   588,    14,
     546,   588,   588,   588,   588,   588,   281,   567,   567,   546,
     400,   541,   546,   567,    75,   567,   567,   546,   546,   546,
     546,    20,   546,   567,    14,    20,    20,    20,    20,    20,
      14,    20,    14,    20,    14,    14,    14,    20,    20,    20,
      20,    20,    14,    14,    20,    20,    20,    20,    14,    20,
      14,    20,    14,    20,    14,    14,    20,    20,    20,    20,
      14,    19,    14,    20,    14,    20,    20,    20,    14,    14,
      14,    14,    14,    20,    13,   573,    14,    20,    19,    20,
      14,    20,    20,    20,    20,    14,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    14,    20,
      13,    13,    20,    20,    20,    13,    13,    14,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    14,    14,    14,
      20,    14,    20,    20,    20,    20,    20,    14,    20,    20,
      20,    20,    20,    20,    20,    20,    14,    20,    20,    20,
      20,    20,    20,    14,    14,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    14,    14,
      14,    14,    14,    14,    14,    20,    20,    20,    14,    20,
      20,    20,    20,    20,    13,    14,    20,    14,    20,    20,
      14,    14,    59,    60,   569,   608,    14,    20,    16,    22,
      16,    22,    13,    13,    13,    13,    13,    14,    14,    14,
      20,    20,    20,    20,    14,    20,    14,    20,    20,    20,
      20,    20,    20,    20,    14,    14,    20,    20,    14,    20,
      20,    20,    14,   609,    16,   588,    14,    13,    14,   588,
     569,   569,    14,    20,    14,    20,    14,    20,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    20,    14,    14,    20,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    20,    14,    20,    14,
      14,    14,    14,    20,    14,    14,    14,    14,    14,    20,
      14,    14,   588,    20,    20,    14,    20,    20,    20,    14,
      20,    20,    20,    20,    20,    20,    14,    20,   567,   546,
     530,   530,    57,    57,    57,    57,    57,    14,    20,    14,
      20,    20,    14,    20,    20,    14,    20,    23,    20,    14,
     567,   588,    14,    14,    20,    14,    14,    20,    14,    20,
      14,    14,    14,    20,    20,    20,    14,    20,    14,    14,
      14,    14,    14,    20,    14,    14,    20,    14,    20,    14,
      20,    20,    20,    14,    14,    14,    14,    14,    14,    14,
      14,    20,    20,    14,    14,    20,    14,    14,    14,    14,
      20,    20,    20,    20,    20,    20,    14,    20,    20,    20,
      14,    20,    20,    20,    20,    20,    14,    14,    20,    20,
      20,    20,    20,    13,    16,    16,    14,    14,    14,    16,
      20,    14,    14,    20,    14,   546,   569,   567,   567,   567,
     567,   567,   567,   569,   569,   567,   567,   567,   567,   567,
     567,   567,   567,   567,   567,   567,   567,   567,   567,   567,
     569,   567,   588,   144,    54,   567,   567,   588,    54,   569,
     567,   567,   567,   567,   567,   567,   567,   567,   567,   567,
     567,   567,   567,   567,   567,   569,   569,   588,   588,   569,
     569,   569,   567,   567,   567,   567,   567,   567,   567,   567,
     567,   569,   569,   569,   569,   569,   569,   569,   569,   567,
     567,   567,   567,   588,   588,   567,   567,   567,   567,   569,
     546,   569,   569,   567,   567,   567,   567,   567,   567,   567,
     567,   567,   567,   567,   567,   567,   567,   567,   567,   569,
     567,   567,   569,   567,   567,   588,    22,   567,   586,   567,
     569,    14,    14,    14,   567,   546,   567,   546,   567,    71,
     546,   546,   567,   546,   546,   546,   546,   546,   567,   567,
     567,   567,   567,   567,    14,    14,    14,    20,   569,   567,
     567,   567,   569,   567,   567,   567,   567,    14,   567,   567,
     567,   588,   567,   567,   567,   567,   569,   569,   567,   567,
     567,   473,   547,   547,   489,   490,   491,   492,   493,   547,
     567,   567,   569,   567,   567,   567,   567,   567,   567,   567,
     567,   567,   567,   567,   567,   567,   567,   567,   567,   567,
     567,   567,   567,   567,   567,   567,   567,   567,   567,   567,
     567,   567,   567,   567,   567,   567,   567,   567,   567,   567,
     567,   588,   588,   567,    75,    20,    20,    54,    14,    20,
      14,    20,    14,    20,    14,    20,    14,    14,    14,    14,
      20,    20,    14,    20,    20,    20,    20,    14,    20,    20,
      20,    20,    14,    14,    14,    20,   567,    14,    20,    20,
      14,    14,    20,    20,    20,    14,    14,    14,    14,    20,
      14,    20,    20,    20,    20,    20,    20,    20,    20,    14,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    14,    20,    20,    20,    20,    20,
      20,    14,    14,    20,    14,    14,    14,    20,    20,    14,
      14,    14,    14,    20,    14,    14,    20,    20,    20,    14,
      14,    14,    14,    14,    14,    14,    14,    20,    20,    20,
      20,    20,    14,    20,    20,    14,    20,    20,    14,    14,
      14,    20,    20,    14,    14,    14,    20,    20,    20,    20,
      14,    14,    14,    14,    14,    14,    14,    20,    14,    14,
      14,    20,    14,    14,    14,   567,    14,    20,    14,    14,
      20,    20,    14,    20,    20,    14,    20,    14,    20,    14,
      20,    14,    20,    20,    20,    20,    20,    20,    20,    20,
      14,   567,   530,   530,    57,    57,    57,    57,    57,   530,
      14,    20,    20,    20,    14,    20,    23,    14,    22,    20,
      20,    20,    20,    20,    20,    20,    14,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    14,    20,    20,    20,
      20,    14,    14,    20,    14,    14,    14,    14,    14,    20,
      14,    20,    20,    20,    20,    20,    20,    20,    20,   546,
     546,    14,   567,   567,   567,   567,   567,   567,   567,   567,
     567,   567,   567,   567,   567,   567,   567,   567,   569,   567,
     568,   568,   569,    54,   569,   567,   567,   567,   567,   567,
     567,   567,   567,   567,   567,   567,   569,   567,   569,   567,
     567,   567,   567,   567,   567,   567,   567,   567,   567,   567,
     567,   567,   569,   569,   569,   569,   569,   567,   567,   567,
     588,   588,   567,   567,   567,   567,   567,   567,   567,   567,
     567,   567,   567,   567,   567,   567,   567,   567,   567,   546,
     567,    14,   567,   569,   567,   567,   567,   588,   588,   588,
     588,   567,   567,   567,   569,   569,   567,   567,   547,   567,
     569,   567,   567,   567,   567,   567,   567,   567,   567,   567,
     567,   567,   567,   567,   567,   567,   567,   567,   567,   567,
     567,   567,   567,   567,   567,   569,   588,   567,   567,   567,
     567,   588,   588,   567,   567,    14,    14,    20,    20,    14,
      20,    20,    14,    20,    20,    14,    20,    20,    20,    14,
      20,    20,    14,    20,    20,    14,    14,    20,    20,    20,
      20,    14,    20,    14,    20,    14,    20,    14,    20,    20,
      20,    20,    20,    14,    14,    14,    20,    20,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    20,    20,    20,
      14,    20,    20,    20,    20,    20,    20,    20,    14,    14,
      14,    14,    20,    20,    14,    20,    20,    20,    20,    20,
      20,    14,    20,    22,    22,    20,    14,    20,    14,    20,
      14,    20,    14,    20,    14,    20,    14,    14,    20,    14,
      20,    20,    14,    20,    14,    20,    20,    14,    14,   530,
      20,    20,    20,    14,    14,    20,    20,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    20,    20,    20,    20,    20,    14,    14,    14,    20,
      14,    20,    20,    20,    14,    14,   567,   567,   567,   567,
     567,   567,   567,   567,   567,   567,   567,   568,   567,   568,
      54,   567,   567,   567,   567,   567,   567,   567,   567,   567,
     567,   567,   567,   567,   567,   567,   567,   567,   612,   567,
     612,   567,   612,   567,   567,   567,   567,   567,   567,   567,
     567,   567,   569,   567,   567,   567,   567,   567,   567,   567,
     567,   567,   567,   567,   567,   567,   567,   546,   567,   567,
     567,   567,   567,   567,   567,   588,   569,   567,   569,   567,
     567,   567,   567,   567,   567,   567,   567,   588,   567,   567,
     567,    20,    14,    14,    20,    20,    20,    14,    14,    14,
      20,    14,    20,    20,    20,    14,    14,    20,    20,    20,
      14,    20,    14,    20,    20,    20,    20,    20,    20,    14,
      20,    20,    20,    20,    20,    20,    20,    14,    20,    14,
      14,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      14,    20,    20,    14,    14,    20,    14,    14,    14,    20,
      20,    20,    14,    16,    20,    14,    14,    14,    14,    14,
      20,    20,    14,    14,    20,    20,    14,    20,    20,    20,
      20,    22,    14,    14,    20,    20,    14,    20,    20,    20,
      20,    20,   567,   567,   567,   567,   567,   567,   567,   546,
     568,   567,   567,   567,   567,   567,   567,   567,   567,   567,
     567,   567,   567,   567,   567,   567,   612,   612,   612,   612,
     567,   567,   567,   569,   569,   569,   569,   567,   567,   567,
     567,   567,   567,   567,   567,   567,   567,   567,   569,   567,
     569,   567,   567,   567,   567,   567,   588,   567,   567,   567,
      14,    20,    20,    20,    20,    14,    20,    20,    14,    14,
      20,    14,    14,    14,    14,    14,    14,    20,    14,    20,
      14,    20,    14,    14,    20,    14,    14,    14,    14,    20,
      14,    14,    14,    14,    20,    20,    14,    20,    14,    20,
      14,    20,    22,    20,    14,    20,    20,    20,    20,    20,
      20,    14,    20,    20,    20,    14,    20,    20,    20,    20,
     567,   567,   567,   567,   546,   567,   567,   567,   567,   567,
     567,   567,   612,   567,   567,   567,   567,   567,   567,   567,
     567,   567,   569,   567,   569,   567,   144,   567,   567,   567,
     588,   567,   567,   567,    14,    14,    20,    14,    14,    20,
      20,    20,    14,    14,    14,    20,    14,    20,    20,    14,
      20,    20,    14,    14,    20,    20,    14,    20,    20,    20,
      20,   588,    20,    20,    14,    20,    20,    14,    14,    20,
      20,   567,   546,   567,   567,   567,   567,   567,   567,   567,
     588,   567,   588,   567,   567,   567,   567,   567,   567,   567,
     567,   567,    20,    14,    14,    14,    14,    14,    20,    20,
      20,    14,    14,    14,    20,    20,    20,    14,    20,    20,
      14,    14,    20,    14,    20,   567,   567,   567,   567,   567,
     567,   569,   567,   567,   567,   588,    20,    20,    14,    20,
      14,    20,    20,    14,    20,    14,    20,   567,   567,   567,
     567,   569,   567,   588,    20,    14,    20,    20,    20,    14,
      14,   567,   567,   567,   567,    20,    20,    20,    14,   567,
     567,   567,    20,    20,    20,   567,   567,   567,    14,    20,
      20,   567,   567,    20,    14,   567,    14
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
     775,   776,   777,   778,   779,   780,   126
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  Parser::yyr1_[] =
  {
         0,   527,   528,   528,   529,   529,   529,   529,   529,   529,
     529,   529,   529,   529,   529,   529,   529,   529,   529,   529,
     530,   530,   531,   531,   531,   531,   532,   532,   534,   533,
     535,   533,   536,   537,   538,   538,   538,   538,   538,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   540,   540,   541,   541,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   542,   542,   542,   542,   542,
     542,   542,   542,   542,   542,   542,   543,   543,   544,   544,
     544,   544,   544,   544,   544,   544,   544,   545,   545,   545,
     546,   546,   546,   547,   548,   549,   550,   550,   550,   550,
     550,   550,   550,   550,   551,   551,   551,   551,   551,   551,
     551,   551,   551,   551,   551,   551,   551,   551,   551,   551,
     551,   551,   551,   551,   551,   551,   551,   551,   551,   551,
     551,   551,   551,   551,   551,   551,   551,   551,   551,   551,
     551,   551,   551,   551,   551,   551,   551,   551,   551,   551,
     551,   551,   551,   551,   551,   551,   551,   551,   551,   551,
     551,   551,   551,   551,   551,   551,   551,   551,   551,   551,
     551,   551,   551,   551,   551,   551,   551,   551,   551,   551,
     551,   552,   552,   552,   552,   552,   552,   552,   552,   552,
     552,   552,   552,   552,   552,   552,   552,   552,   552,   553,
     553,   554,   554,   555,   555,   555,   555,   556,   556,   556,
     557,   558,   558,   558,   558,   558,   559,   559,   559,   559,
     559,   560,   560,   561,   561,   562,   562,   563,   563,   564,
     564,   565,   565,   566,   567,   568,   568,   568,   568,   568,
     568,   568,   568,   568,   568,   568,   569,   569,   570,   570,
     570,   570,   570,   570,   570,   570,   570,   570,   570,   570,
     570,   570,   570,   570,   570,   570,   570,   570,   570,   570,
     570,   570,   570,   570,   570,   570,   570,   570,   570,   570,
     570,   570,   570,   570,   570,   570,   570,   570,   570,   570,
     570,   570,   570,   570,   570,   570,   570,   570,   570,   570,
     570,   570,   570,   570,   570,   570,   570,   570,   570,   570,
     570,   570,   570,   570,   570,   570,   570,   570,   570,   570,
     570,   570,   570,   570,   570,   570,   570,   570,   570,   570,
     570,   570,   570,   570,   570,   570,   570,   570,   570,   570,
     570,   570,   570,   570,   570,   570,   570,   570,   570,   570,
     570,   570,   570,   570,   570,   570,   570,   570,   570,   570,
     570,   570,   570,   570,   570,   570,   570,   570,   570,   570,
     570,   570,   570,   570,   570,   570,   570,   570,   570,   570,
     570,   570,   570,   570,   570,   570,   570,   570,   570,   570,
     570,   570,   570,   570,   570,   570,   571,   571,   572,   573,
     573,   573,   573,   573,   573,   573,   573,   573,   573,   573,
     573,   573,   573,   573,   573,   573,   573,   574,   574,   575,
     575,   575,   575,   575,   575,   576,   577,   577,   577,   577,
     577,   578,   579,   579,   579,   579,   579,   579,   579,   579,
     579,   580,   580,   580,   580,   580,   581,   581,   582,   583,
     583,   584,   584,   585,   585,   586,   586,   587,   587,   588,
     589,   589,   589,   589,   590,   590,   590,   591,   591,   592,
     593,   593,   593,   593,   593,   593,   593,   593,   593,   593,
     593,   593,   593,   593,   593,   593,   593,   593,   594,   595,
     595,   595,   595,   596,   596,   596,   596,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     608,   609,   609,   609,   609,   609,   609,   609,   609,   609,
     609,   609,   609,   609,   609,   609,   609,   609,   609,   609,
     609,   609,   609,   609,   609,   609,   609,   609,   609,   609,
     609,   609,   609,   609,   609,   609,   609,   609,   609,   610,
     611,   611,   611,   611,   611,   611,   611,   611,   611,   611,
     611,   611,   611,   611,   611,   611,   611,   611,   611,   611,
     612,   612,   612,   612
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Parser::yyr2_[] =
  {
         0,     2,     0,     2,     1,     2,     2,     3,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     2,
       1,     1,     8,    10,     6,     2,     4,     6,     0,     8,
       0,     8,     4,     2,     3,     2,     2,     5,     2,     1,
       1,     1,     1,     1,     1,     4,     6,     4,     6,     6,
       6,     3,     3,     6,     6,     3,     3,     3,     3,     6,
       3,     3,     3,     6,     6,     8,     6,     8,     3,     5,
       3,     5,     8,     8,     3,     1,     1,     1,     1,     8,
       4,     4,     1,     2,     2,     2,     3,     3,     3,     3,
       6,     6,    16,     2,     2,     3,     2,     2,     3,     3,
       2,     2,     3,     2,     6,     2,     2,     5,     2,     1,
       1,     2,     2,     2,     2,     2,     4,     4,     2,     2,
       2,     2,     1,     4,     3,     2,     2,    10,     6,     3,
       6,     6,     8,    28,     8,     8,     3,     8,    12,     6,
       6,    16,     8,    16,    10,     6,    10,     8,    10,    14,
       8,    12,     6,     8,     6,     6,     6,    10,     6,    10,
      10,    12,     6,     6,    12,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     8,     3,     3,
       3,     3,     3,     3,    12,    16,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,    10,     6,    14,     6,
       8,     6,     6,     8,     6,    10,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     3,     3,     4,
       3,     6,     6,     4,     4,     6,    10,    10,    10,     6,
       6,     6,     6,     6,    10,     6,    10,     6,     6,     6,
       3,     6,     6,    10,    10,     6,     6,     6,     3,     3,
       3,     3,     6,     6,     3,     6,     6,     8,    10,     3,
       6,     3,     4,    20,     6,    10,     6,     3,     3,     6,
       3,     6,     8,     6,     6,     8,    16,     6,     3,     6,
       8,     3,    12,    12,    12,    10,     3,     3,     8,     8,
      10,     8,    10,    12,     6,     8,     8,    10,    16,    18,
      12,     6,    18,    16,    12,    10,    10,    10,     6,    10,
       6,     6,     6,     8,     1,     4,     4,     8,     4,    18,
       4,     1,     1,     1,     6,     3,     8,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     6,     8,     6,
      10,     6,     8,     8,     8,     8,     6,     3,     4,     1,
       1,     1,    30,    24,     4,     8,     1,     3,     0,     1,
       3,     1,     3,     2,     4,     2,     4,     1,     3,     2,
       4,     2,     4,     1,     3,     0,     2,     2,     2,     2,
       2,     4,     4,     4,     4,     4,     1,     1,     1,     6,
       6,     6,     1,     3,     4,     4,     1,     1,     3,     3,
       1,     3,     3,     3,     0,     0,     1,     1,     1,     1,
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
  "T_SetColorMaterial", "T_Statistics", "T_GetIntensities",
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
  "T_SaveStructuredGrid", "T_import_vtk", "T_import_wii",
  "T_import_filters", "T_amiOFCorr2D", "T_amiOFVar2D", "'~'", "$accept",
  "start", "list_commands", "end_instr", "loop_inst", "cond_inst",
  "proc_decl", "$@1", "$@2", "class_decl", "object_decl", "func_inst",
  "command", "exprstringlist", "param_list", "param_list_decl",
  "primary_expr_string", "postfix_expr_string", "additive_expr_string",
  "expr_string", "instr_block", "begin_block", "end_block", "primary_expr",
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
       528,     0,    -1,    -1,   529,     0,    -1,   530,    -1,   529,
     530,    -1,   539,   530,    -1,   529,   539,   530,    -1,   531,
      -1,   529,   531,    -1,   532,    -1,   529,   532,    -1,   538,
      -1,   529,   538,    -1,   533,    -1,   529,   533,    -1,   536,
      -1,   529,   536,    -1,   537,    -1,   529,   537,    -1,    34,
      -1,    23,    -1,   471,   610,   144,   567,   472,   567,   547,
     530,    -1,   471,   610,   144,   567,   472,   567,   473,   567,
     547,   530,    -1,   471,   610,   475,   540,   547,   530,    -1,
     476,   547,    -1,   479,   567,   547,   530,    -1,   479,   567,
     547,   481,   547,   530,    -1,    -1,   495,   610,   534,    13,
     542,    14,   547,   530,    -1,    -1,   495,    71,   535,    13,
     542,    14,   547,   530,    -1,   496,   610,   547,   530,    -1,
      72,   610,    -1,   483,   546,   530,    -1,   483,   530,    -1,
     484,   546,    -1,    71,    13,   541,    14,   530,    -1,    71,
     530,    -1,    33,    -1,   478,    -1,    82,    -1,    84,    -1,
      85,    -1,    83,    -1,    87,    13,   567,    14,    -1,    88,
      13,   567,    20,    71,    14,    -1,   610,   144,    17,   611,
      -1,   610,   144,   346,    15,   567,    16,    -1,   610,   123,
     346,    15,   567,    16,    -1,   610,   144,    35,    15,   567,
      16,    -1,   610,   144,   588,    -1,   610,   123,   588,    -1,
     610,   144,    68,    13,   541,    14,    -1,    77,    15,   567,
      16,   144,   588,    -1,   610,   144,   607,    -1,   610,   144,
     589,    -1,    66,   144,   567,    -1,    66,   144,   607,    -1,
      76,    15,   567,    16,   144,   609,    -1,   610,   144,    86,
      -1,   610,   144,   609,    -1,   608,   123,   609,    -1,    76,
     123,   346,    15,   567,    16,    -1,   610,   144,   436,    13,
     567,    14,    -1,   610,   144,   436,    13,   567,    14,    20,
     546,    -1,   610,   144,   433,    13,   567,    14,    -1,   610,
     144,   433,    13,   567,    14,    20,   546,    -1,   610,   144,
     567,    -1,   610,   144,   567,    20,   546,    -1,   610,   144,
     546,    -1,   610,   144,   546,    20,   546,    -1,   610,   144,
     448,    13,   546,    20,    54,    14,    -1,    67,   144,   448,
      13,   546,    20,    54,    14,    -1,    67,    19,   452,    -1,
      24,    -1,    25,    -1,    26,    -1,    27,    -1,    28,    13,
     546,    20,   546,    20,   546,    14,    -1,    29,    13,   567,
      14,    -1,    30,    13,   546,    14,    -1,    40,    -1,    38,
     569,    -1,    41,   569,    -1,    38,   608,    -1,   569,   144,
     588,    -1,   569,   124,   588,    -1,   569,   123,   588,    -1,
     569,   144,   567,    -1,   569,    15,   567,    16,   144,   588,
      -1,   569,    15,   567,    16,   144,   567,    -1,   569,    13,
     567,    22,   567,    20,   567,    22,   567,    20,   567,    22,
     567,    14,   144,   588,    -1,    59,   133,    -1,    59,   134,
      -1,    59,   144,   567,    -1,    60,   133,    -1,    60,   134,
      -1,    60,   144,   567,    -1,    61,   144,   567,    -1,    61,
     133,    -1,    61,   134,    -1,    62,   144,   546,    -1,    38,
     482,    -1,   611,    19,    80,    13,   546,    14,    -1,    78,
     611,    -1,    79,   546,    -1,    78,    76,    15,   567,    16,
      -1,    47,   546,    -1,    48,    -1,    39,    -1,    39,   610,
      -1,    39,    70,    -1,    39,    68,    -1,    39,    69,    -1,
      39,    54,    -1,    67,    19,    42,   546,    -1,    67,    19,
      43,   546,    -1,    42,   546,    -1,    43,   546,    -1,    42,
     607,    -1,    44,   546,    -1,   607,    -1,    67,    19,    42,
     567,    -1,    67,    19,   449,    -1,    42,   567,    -1,    43,
     567,    -1,    63,    19,   407,    13,   567,    20,   567,    20,
     567,    14,    -1,    63,    19,   408,    13,   567,    14,    -1,
      63,    19,   409,    -1,    63,    19,   410,    13,   569,    14,
      -1,    63,    19,   410,    13,    63,    14,    -1,    63,    19,
     413,    13,    63,    20,   569,    14,    -1,    63,    19,   501,
      13,   567,    20,   567,    20,   567,    20,   567,    20,   567,
      20,   567,    20,   567,    20,   567,    20,   567,    20,   567,
      20,   567,    20,   567,    14,    -1,    63,    19,   411,    13,
      56,    20,   569,    14,    -1,    63,    19,   414,    13,   567,
      20,   567,    14,    -1,    63,    19,   415,    -1,    63,    19,
     416,    13,   567,    20,   567,    14,    -1,    63,    19,   417,
      13,   567,    20,   567,    20,   567,    20,   567,    14,    -1,
      63,    19,   418,    13,   567,    14,    -1,    63,    19,   419,
      13,   567,    14,    -1,    63,    19,   420,    13,   567,    20,
     567,    20,   567,    20,   567,    20,   567,    20,   567,    14,
      -1,    63,    19,   421,    13,   567,    20,   567,    14,    -1,
      63,    19,   423,    13,   567,    20,   567,    20,   567,    20,
     567,    20,   567,    20,   567,    14,    -1,    63,    19,   422,
      13,   588,    20,   567,    20,   567,    14,    -1,    63,    19,
     424,    13,    65,    14,    -1,    63,    19,   296,    13,   567,
      20,   569,    20,   567,    14,    -1,    63,    19,   296,    13,
     569,    20,   567,    14,    -1,    63,    19,   297,    13,   567,
      20,   567,    20,   567,    14,    -1,    63,    19,   297,    13,
     567,    20,   567,    20,   567,    20,   567,    20,   567,    14,
      -1,    63,    19,   298,    13,   567,    20,   567,    14,    -1,
      63,    19,   299,    13,   567,    20,   567,    20,   567,    20,
     567,    14,    -1,    63,    19,   300,    13,   567,    14,    -1,
      63,    19,   301,    13,   567,    20,   567,    14,    -1,    63,
      19,   519,    13,    71,    14,    -1,    63,    19,   377,    13,
     569,    14,    -1,   569,    19,   425,    13,   567,    14,    -1,
     569,    19,   425,    13,   567,    20,   567,    20,   567,    14,
      -1,   569,    19,   406,    13,   567,    14,    -1,   569,    19,
     406,    13,   567,    20,   567,    20,   567,    14,    -1,   569,
      19,   407,    13,   567,    20,   567,    20,   567,    14,    -1,
     569,    19,   158,    13,   569,    20,   567,    20,   567,    20,
     567,    14,    -1,   569,    19,   158,    13,   569,    14,    -1,
     569,    19,    49,    13,   546,    14,    -1,   165,    19,   221,
      13,   569,    20,   567,    20,   567,    20,   567,    14,    -1,
     165,    19,   222,    13,   567,    14,    -1,   165,    19,   168,
      13,   567,    14,    -1,   165,    19,   227,    13,   567,    14,
      -1,   165,    19,   228,    13,   567,    14,    -1,   165,    19,
     231,    13,   569,    14,    -1,   165,    19,   232,    13,   569,
      14,    -1,   165,    19,   233,    13,   569,    14,    -1,   165,
      19,   234,    13,   569,    14,    -1,   165,    19,   235,    13,
     567,    14,    -1,   165,    19,   236,    13,   567,    14,    -1,
     165,    19,   237,    13,   567,    14,    -1,   165,    19,   238,
      13,   567,    14,    -1,   165,    19,   222,    13,   567,    20,
     567,    14,    -1,   165,    19,   223,    -1,   165,    19,   224,
      -1,   211,    19,   223,    -1,   211,    19,   224,    -1,   212,
      19,   223,    -1,   212,    19,   224,    -1,   176,    19,   194,
      13,   567,    20,   567,    20,   567,    20,   567,    14,    -1,
     176,    19,   194,    13,   567,    20,   567,    20,   567,    20,
     567,    20,   567,    20,   567,    14,    -1,   176,    19,   178,
      13,   567,    14,    -1,   176,    19,   179,    13,   567,    14,
      -1,   176,    19,   180,    13,   567,    14,    -1,   176,    19,
     193,    13,   567,    14,    -1,   176,    19,   197,    13,   567,
      14,    -1,   176,    19,   202,    13,   567,    14,    -1,   176,
      19,   203,    13,   567,    14,    -1,   176,    19,   204,    13,
     567,    14,    -1,   176,    19,   205,    13,   567,    14,    -1,
     176,    19,   200,    13,   567,    14,    -1,   176,    19,   201,
      13,   567,    20,   567,    20,   567,    14,    -1,   176,    19,
     206,    13,   567,    14,    -1,   176,    19,   207,    13,   567,
      20,   567,    20,   567,    20,   567,    20,   567,    14,    -1,
     176,    19,   195,    13,   567,    14,    -1,   176,    19,   181,
      13,   569,    20,   567,    14,    -1,   176,    19,   182,    13,
     567,    14,    -1,   176,    19,   183,    13,   569,    14,    -1,
     176,    19,   196,    13,   567,    20,   567,    14,    -1,   176,
      19,   185,    13,   569,    14,    -1,   176,    19,   184,    13,
     569,    20,   569,    20,   569,    14,    -1,   176,    19,   187,
      13,   569,    14,    -1,   176,    19,   188,    13,   569,    14,
      -1,   176,    19,   189,    13,   569,    14,    -1,   176,    19,
     192,    13,   569,    14,    -1,   176,    19,   190,    13,   569,
      14,    -1,   176,    19,   191,    13,   569,    14,    -1,   176,
      19,   187,    13,   171,    14,    -1,   176,    19,   189,    13,
     171,    14,    -1,   176,    19,   190,    13,   171,    14,    -1,
     176,    19,   198,    13,   567,    14,    -1,   176,    19,   199,
      13,   567,    14,    -1,   176,    19,   223,    -1,   176,    19,
     224,    -1,   569,    19,   242,   546,    -1,   569,    19,   243,
      -1,   569,    19,   244,    13,   569,    14,    -1,   569,    19,
     245,    13,   569,    14,    -1,   608,    19,   242,   546,    -1,
     608,    19,   295,   546,    -1,   608,    19,   357,    13,   567,
      14,    -1,   608,    19,   372,    13,   567,    20,   567,    20,
     567,    14,    -1,   608,    19,   373,    13,   567,    20,   567,
      20,   567,    14,    -1,   608,    19,   374,    13,   567,    20,
     567,    20,   567,    14,    -1,   608,    19,   375,    13,   567,
      14,    -1,   608,    19,   376,    13,   567,    14,    -1,   608,
      19,   378,    13,   567,    14,    -1,   608,    19,   379,    13,
     567,    14,    -1,   608,    19,   360,    13,   567,    14,    -1,
     608,    19,   358,    13,   567,    20,   567,    20,   567,    14,
      -1,   608,    19,   394,    13,   569,    14,    -1,   608,    19,
     359,    13,   588,    20,   567,    20,   567,    14,    -1,   608,
      19,   359,    13,   588,    14,    -1,   608,    19,   380,    13,
     569,    14,    -1,   608,    19,   387,    13,   567,    14,    -1,
     608,    19,   388,    -1,   608,    19,   272,    13,   567,    14,
      -1,   608,    19,   389,    13,   588,    14,    -1,   608,    19,
     392,    13,   567,    20,   567,    20,   567,    14,    -1,   608,
      19,   393,    13,   567,    20,   567,    20,   567,    14,    -1,
     608,    19,   395,    13,   567,    14,    -1,   608,    19,   280,
      13,   567,    14,    -1,   608,    19,   385,    13,   588,    14,
      -1,   608,    19,   386,    -1,   608,    19,   341,    -1,   608,
      19,   390,    -1,   608,    19,   391,    -1,   608,    19,   340,
      13,   567,    14,    -1,   608,    19,   342,    13,   567,    14,
      -1,   608,    19,   338,    -1,   608,    19,   352,    13,   567,
      14,    -1,   608,    19,   351,    13,   567,    14,    -1,   608,
      19,   351,    13,   567,    20,   567,    14,    -1,   608,    19,
     396,    13,   567,    20,   567,    20,   567,    14,    -1,   608,
      19,   397,    -1,   608,    19,   399,    13,   567,    14,    -1,
     608,    19,   398,    -1,   517,    13,   546,    14,    -1,   518,
      13,    63,    20,   567,    20,   567,    20,   567,    20,   567,
      20,   567,    20,   567,    20,   567,    20,   567,    14,    -1,
     608,    19,   510,    13,   588,    14,    -1,    65,    19,   349,
      13,   567,    20,   567,    20,   567,    14,    -1,    65,    19,
     353,    13,   609,    14,    -1,    65,   124,   608,    -1,    65,
     125,   608,    -1,    65,    19,   370,    13,   608,    14,    -1,
      65,    19,   371,    -1,    65,    19,   351,    13,   567,    14,
      -1,    65,    19,   351,    13,   567,    20,   567,    14,    -1,
      65,    19,   354,    13,   567,    14,    -1,    65,    19,   410,
      13,    65,    14,    -1,    65,    19,   411,    13,    56,    20,
     569,    14,    -1,    65,    19,   426,    13,   567,    20,   588,
      20,   567,    20,   567,    20,   567,    20,   567,    14,    -1,
      65,    19,   427,    13,   567,    14,    -1,    65,    19,   405,
      -1,    65,    19,   401,    13,   589,    14,    -1,    65,    19,
     401,    13,   589,    20,   567,    14,    -1,    65,    19,   361,
      -1,    65,    19,   364,    13,   567,    20,   567,    20,   567,
      20,   567,    14,    -1,    65,    19,   365,    13,   567,    20,
     567,    20,   567,    20,   567,    14,    -1,    65,    19,   366,
      13,   567,    20,   567,    20,   567,    20,   567,    14,    -1,
      65,    19,   367,    13,   567,    20,   567,    20,   567,    14,
      -1,    65,    19,   368,    -1,    65,    19,   369,    -1,    65,
      19,   421,    13,   567,    20,   567,    14,    -1,   267,    13,
     569,    20,   567,    20,   567,    14,    -1,   267,    13,   569,
      20,   567,    20,   567,    20,   588,    14,    -1,   268,    13,
     569,    20,   567,    20,   567,    14,    -1,   268,    13,   569,
      20,   567,    20,   567,    20,   588,    14,    -1,   268,    13,
     569,    20,   567,    20,   567,    20,   588,    20,   567,    14,
      -1,   269,    13,   569,    20,   567,    14,    -1,   269,    13,
     569,    20,   567,    20,   588,    14,    -1,   269,    13,   569,
      20,   567,    20,   567,    14,    -1,   269,    13,   569,    20,
     567,    20,   567,    20,   588,    14,    -1,   271,    13,   569,
      20,   567,    20,   567,    20,   567,    20,   567,    20,   567,
      20,   567,    14,    -1,   271,    13,   569,    20,   567,    20,
     567,    20,   567,    20,   567,    20,   567,    20,   567,    20,
     588,    14,    -1,   270,    13,   569,    20,   567,    20,   567,
      20,   588,    20,   567,    14,    -1,   272,    13,   569,    20,
     567,    14,    -1,   317,    13,    54,    20,   569,    20,   569,
      20,   569,    20,   569,    20,   569,    20,   569,    20,   588,
      14,    -1,   317,    13,    54,    20,   569,    20,   569,    20,
     569,    20,   569,    20,   569,    20,   569,    14,    -1,   316,
      13,    54,    20,   569,    20,   569,    20,   569,    20,   588,
      14,    -1,   316,    13,    54,    20,   569,    20,   569,    20,
     569,    14,    -1,   274,    13,   569,    20,   567,    20,   567,
      20,   567,    14,    -1,   569,    19,   274,    13,   567,    20,
     567,    20,   567,    14,    -1,   569,    19,   274,    13,   569,
      14,    -1,   569,    19,   275,    13,   567,    20,   567,    20,
     567,    14,    -1,   569,    19,   275,    13,   569,    14,    -1,
     569,    19,   276,    13,   567,    14,    -1,   160,    13,   569,
      20,   569,    14,    -1,   160,    13,   569,    20,   569,    20,
     569,    14,    -1,   567,    -1,   330,    13,   567,    14,    -1,
     331,    13,   567,    14,    -1,   444,    13,   588,    20,   546,
      20,   567,    14,    -1,   447,    13,   569,    14,    -1,   315,
      13,   569,    20,   569,    20,   567,    20,   567,    20,   567,
      20,   567,    20,   567,    20,   567,    14,    -1,   488,    13,
      54,    14,    -1,   172,    -1,   173,    -1,   175,    -1,   610,
     144,    89,    13,   546,    14,    -1,    74,    19,    95,    -1,
      74,    19,    97,    13,   567,    20,   567,    14,    -1,    74,
      19,    91,    -1,    74,    19,    93,    -1,    74,    19,   115,
      -1,    74,    19,   116,    -1,    74,    19,   117,    -1,    74,
      19,   100,    -1,    74,    19,   101,    -1,    74,    19,    41,
      -1,    74,    19,   118,    -1,    74,    19,   409,    -1,    74,
      19,   409,    13,   567,    14,    -1,    74,    19,   110,    13,
     567,    20,   567,    14,    -1,    74,    19,   111,    13,    71,
      14,    -1,    74,    19,   113,    13,   567,    20,   567,    20,
     567,    14,    -1,    74,    19,   112,    13,   567,    14,    -1,
      74,    19,   112,    13,   567,    20,   567,    14,    -1,    74,
      19,   119,    13,   567,    20,   567,    14,    -1,    74,    19,
     120,    13,   567,    20,   567,    14,    -1,    74,    19,   121,
      13,   567,    20,   567,    14,    -1,   520,    13,   569,    20,
     546,    14,    -1,    75,    19,    42,    -1,    75,    19,   242,
     546,    -1,   521,    -1,   522,    -1,   523,    -1,   524,    13,
     569,    20,   569,    20,   569,    20,   569,    20,   569,    20,
     569,    20,   569,    20,   567,    20,   567,    20,   567,    20,
     567,    20,   567,    20,   567,    20,   567,    14,    -1,   525,
      13,   569,    20,   569,    20,   567,    20,   567,    20,   567,
      20,   567,    20,   567,    20,   567,    20,   569,    20,   569,
      20,   567,    14,    -1,    69,    13,   541,    14,    -1,   512,
      13,   567,    20,   567,    20,   567,    14,    -1,   546,    -1,
     540,    20,   546,    -1,    -1,   567,    -1,   541,    20,   567,
      -1,   546,    -1,   541,    20,   546,    -1,    17,    59,    -1,
     541,    20,    17,    59,    -1,    17,    60,    -1,   541,    20,
      17,    60,    -1,   588,    -1,   541,    20,   588,    -1,    17,
     569,    -1,   541,    20,    17,   569,    -1,    17,   608,    -1,
     541,    20,    17,   608,    -1,    63,    -1,   541,    20,    63,
      -1,    -1,   492,    57,    -1,   493,    57,    -1,   489,    57,
      -1,   490,    57,    -1,   491,    57,    -1,   542,    20,   492,
      57,    -1,   542,    20,   493,    57,    -1,   542,    20,   489,
      57,    -1,   542,    20,   490,    57,    -1,   542,    20,   491,
      57,    -1,    54,    -1,    62,    -1,   543,    -1,    46,    13,
     546,    20,   567,    14,    -1,    45,    13,   546,    14,    12,
     567,    -1,    45,    13,   546,    14,    12,   546,    -1,   174,
      -1,   569,    19,    50,    -1,    50,    13,   611,    14,    -1,
      51,    13,   611,    14,    -1,    31,    -1,   544,    -1,   545,
      10,   544,    -1,   545,    11,   544,    -1,   545,    -1,   546,
      12,   545,    -1,   545,    12,   567,    -1,   548,    55,   549,
      -1,    -1,    -1,    56,    -1,    32,    -1,   453,    -1,   454,
      -1,    59,    -1,    60,    -1,    61,    -1,    13,   567,    14,
      -1,   550,    -1,   569,    13,   567,    14,    -1,   569,    13,
     567,    20,   567,    14,    -1,   569,    13,   567,    20,   567,
      20,   567,    14,    -1,   569,    19,   412,    13,   567,    20,
     567,    20,   567,    14,    -1,   569,    13,   567,    20,   567,
      20,   567,    20,   567,    14,    -1,   569,    13,   567,    20,
     567,    20,   567,    23,   567,    14,    -1,   569,    13,   567,
      20,   567,    23,   567,    14,    -1,   569,    13,   567,    23,
     567,    14,    -1,   569,    19,   221,    -1,   569,    19,   610,
      -1,   569,    19,   239,    -1,    73,   239,    -1,   608,    19,
     239,    -1,   608,    19,   240,    -1,   608,    19,   241,    -1,
     226,    13,   569,    20,   569,    14,    -1,   259,    13,   569,
      14,    -1,   332,    13,   569,    20,   567,    20,   567,    20,
     567,    14,    -1,   333,    13,   569,    14,    -1,   333,    13,
     567,    20,   567,    20,   567,    20,   567,    14,    -1,   145,
      13,   588,    14,    -1,   261,    13,   588,    14,    -1,   146,
      13,   588,    14,    -1,   147,    13,   588,    14,    -1,   148,
      13,   588,    14,    -1,   149,    13,   588,    14,    -1,   146,
      15,   588,    16,    13,   588,    14,    -1,   148,    15,   588,
      16,    13,   569,    14,    -1,   149,    15,   588,    16,    13,
     569,    14,    -1,   149,    15,   588,    16,    13,   569,    20,
     567,    14,    -1,   261,    15,   588,    16,    13,   588,    14,
      -1,   261,    13,   569,    20,   588,    14,    -1,   443,    13,
     546,    14,    -1,    63,    19,   306,    -1,    63,    19,   307,
      -1,    63,    19,   304,    -1,    63,    19,   305,    -1,    63,
      19,   302,    -1,    63,    19,   303,    -1,    63,    19,   308,
      -1,    63,    19,   309,    -1,    63,    19,   310,    -1,   165,
      19,   229,    -1,   165,    19,   230,    -1,   176,    19,   177,
      -1,    66,    13,   567,    20,   567,    14,    -1,    66,    13,
     567,    20,   567,    14,   144,   567,    -1,    74,    19,    98,
      13,    59,    20,   567,    20,   567,    14,    -1,    74,    19,
      98,    13,    59,    20,   546,    20,   567,    20,   567,    14,
      -1,    74,    19,    99,    13,    60,    20,   567,    20,   567,
      14,    -1,    74,    19,    99,    13,    60,    20,   546,    20,
     567,    20,   567,    14,    -1,    74,    19,   102,    13,   546,
      20,    71,    14,    -1,    74,    19,   103,    13,    61,    14,
      -1,    74,    19,   103,    13,    61,    20,   546,    14,    -1,
      74,    19,   106,    13,    62,    20,   546,    14,    -1,    74,
      19,   104,    13,    60,    20,   567,    14,    -1,    74,    19,
     104,    13,    60,    20,   546,    14,    -1,    74,    19,   104,
      13,    60,    14,    -1,    74,    19,   105,    13,   567,    20,
     546,    14,    -1,    74,    19,   107,    13,    62,    20,   546,
      14,    -1,    74,    19,   109,    13,   546,    20,   546,    14,
      -1,    74,    19,   108,    13,    62,    20,   546,    20,   546,
      20,   546,    14,    -1,    74,    19,   114,    13,   546,    14,
      -1,    74,    19,    96,    13,   546,    14,    -1,    74,    19,
      94,    -1,    74,    19,    90,    13,   546,    14,    -1,    74,
      19,    92,    13,   546,    14,    -1,   485,    13,   610,    14,
      -1,   485,    13,   611,    14,    -1,   486,    13,   546,    14,
      -1,   568,    -1,    67,    19,   450,    13,   546,    14,    -1,
      67,    19,   451,    13,    59,    14,    -1,    67,    19,   451,
      13,    62,    14,    -1,   608,    19,   291,    -1,   146,    13,
     567,    20,   567,    14,    -1,   551,    -1,   553,   554,    -1,
       9,   554,    -1,    11,   554,    -1,    10,   554,    -1,   455,
     554,    -1,   456,   554,    -1,   466,   554,    -1,   467,   554,
      -1,   468,   554,    -1,   469,   554,    -1,   457,   554,    -1,
     458,   554,    -1,   459,   554,    -1,   460,   554,    -1,   463,
     554,    -1,   465,   554,    -1,   464,   554,    -1,     7,    -1,
     526,    -1,   552,    -1,    13,   568,    14,   552,    -1,   554,
      -1,   555,     7,   554,    -1,   555,     8,   554,    -1,   555,
      12,   554,    -1,   555,    -1,   556,    10,   555,    -1,   556,
      11,   555,    -1,   556,    -1,   557,    -1,   558,     6,   557,
      -1,   558,     5,   557,    -1,   558,   138,   557,    -1,   558,
     139,   557,    -1,   558,    -1,   559,   140,   558,    -1,   559,
     141,   558,    -1,   546,   140,   546,    -1,   546,   141,   546,
      -1,   559,    -1,   560,    17,   559,    -1,   560,    -1,   561,
       4,   560,    -1,   561,    -1,   562,    18,   561,    -1,   562,
      -1,   563,   136,   562,    -1,   563,    -1,   564,   137,   563,
      -1,   564,    -1,   564,    21,   564,    22,   565,    -1,   565,
      -1,   566,    -1,   432,    -1,   433,    -1,   434,    -1,   435,
      -1,   436,    -1,   437,    -1,   438,    -1,   439,    -1,   440,
      -1,   441,    -1,   569,    19,   442,    -1,    58,    -1,    77,
      15,   567,    16,    -1,    35,   546,    -1,    35,    13,   546,
      14,    -1,    36,    13,   567,    20,   567,    20,   568,    20,
     567,    20,   546,    20,   567,    20,   567,    14,    -1,    36,
      13,   567,    20,   567,    20,   567,    20,   568,    20,   567,
      20,   546,    14,    -1,    36,    13,   567,    20,   567,    20,
     567,    20,   568,    20,   567,    20,   567,    20,   546,    14,
      -1,   311,    13,   546,    14,    -1,   312,    13,   546,    14,
      -1,    70,    13,   541,    14,    -1,    35,    -1,    35,    13,
     568,    20,   567,    20,   567,    20,   567,    14,    -1,    35,
      13,   568,    20,   567,    20,   567,    20,   567,    20,   567,
      14,    -1,    35,    13,   568,    20,   567,    20,   569,    14,
      -1,   569,    -1,   569,    15,   567,    16,    -1,   262,    13,
     588,    20,   567,    14,    -1,   263,    13,   588,    20,   567,
      14,    -1,   264,    13,   588,    20,   567,    14,    -1,   265,
      13,   588,    20,   588,    20,   567,    14,    -1,   266,    13,
     588,    20,   588,    20,   567,    14,    -1,   146,    13,   588,
      20,   588,    14,    -1,   150,    13,   569,    20,    54,    14,
      -1,   150,    13,   569,    20,    54,    20,   568,    14,    -1,
     150,    13,   569,    20,   569,    20,    54,    14,    -1,   150,
      13,   569,    20,   569,    20,    54,    20,   568,    14,    -1,
     150,    13,   569,    20,   569,    20,   569,    20,    54,    14,
      -1,   150,    13,   569,    20,   569,    20,   569,    20,    54,
      20,   568,    14,    -1,   151,    13,   588,    20,   567,    20,
     567,    20,   567,    20,   567,    14,    -1,   503,    19,   504,
      13,   569,    20,   567,    20,   567,    14,    -1,   344,    13,
     569,    14,    -1,   170,    13,   569,    20,   567,    20,   567,
      20,   567,    14,    -1,   345,    13,   569,    14,    -1,   246,
      13,   588,    20,   567,    14,    -1,   247,    13,   569,    14,
      -1,   248,    13,   569,    14,    -1,   249,    13,   569,    14,
      -1,   250,    13,   569,    20,   569,    20,   567,    20,   567,
      20,   567,    14,    -1,   251,    13,   569,    14,    -1,   252,
      13,   569,    20,   569,    20,   569,    20,   567,    20,   569,
      14,    -1,   253,    13,   569,    20,   569,    20,   569,    20,
     567,    20,   569,    14,    -1,   254,    13,   569,    20,   569,
      20,   569,    20,   567,    20,   569,    20,   567,    20,   567,
      14,    -1,   255,    13,   569,    20,   569,    20,   569,    20,
     567,    20,   569,    20,   567,    20,   567,    20,   567,    20,
     567,    14,    -1,   256,    13,   569,    20,   569,    20,   569,
      20,   569,    14,    -1,   256,    13,   569,    20,   569,    20,
     569,    20,   569,    20,   567,    14,    -1,   257,    13,   569,
      14,    -1,   257,    13,   569,    20,   569,    14,    -1,   258,
      13,   569,    20,   569,    14,    -1,   152,    13,   588,    20,
     567,    14,    -1,   153,    13,   569,    14,    -1,   169,    13,
     569,    14,    -1,   154,    13,   569,    20,   567,    14,    -1,
     273,    13,   569,    14,    -1,   155,    13,   569,    20,   567,
      14,    -1,   156,    13,   569,    20,   567,    14,    -1,   159,
      13,   588,    20,   567,    14,    -1,   569,    15,   612,    16,
      -1,   569,    15,    22,    20,    22,    20,   567,    22,   567,
      16,    -1,   157,    13,   569,    20,   567,    20,   567,    20,
     567,    20,   567,    20,   567,    20,   567,    14,    -1,   161,
      13,   569,    20,   567,    20,   567,    20,   567,    14,    -1,
     161,    13,   569,    20,   567,    20,   567,    14,    -1,   161,
      13,   569,    20,   567,    20,   567,    20,   567,    20,   567,
      14,    -1,   162,    13,   569,    20,   567,    20,   567,    20,
     567,    14,    -1,   162,    13,   569,    20,   567,    20,   567,
      14,    -1,   162,    13,   569,    20,   567,    20,   567,    20,
     567,    20,   567,    14,    -1,   163,    13,   569,    20,   567,
      20,   567,    14,    -1,   163,    13,   569,    20,   567,    20,
     567,    20,   567,    20,   567,    14,    -1,   164,    13,   569,
      20,   567,    20,   567,    14,    -1,   164,    13,   569,    20,
     567,    20,   567,    20,   567,    20,   567,    14,    -1,   165,
      19,    52,    -1,   165,    19,    53,    -1,   176,    19,   221,
      13,   569,    20,   567,    14,    -1,   176,    19,   221,    13,
     569,    20,   569,    14,    -1,   176,    19,    52,    -1,   176,
      19,   186,    13,   569,    14,    -1,   165,    13,   569,    20,
     567,    20,   567,    20,   567,    20,   567,    14,    -1,   210,
      13,   569,    20,   569,    20,   567,    20,   567,    20,   567,
      14,    -1,   167,    13,   569,    20,   567,    20,   567,    20,
     567,    20,   567,    20,   567,    14,    -1,   166,    13,   569,
      20,   567,    20,   567,    20,   567,    20,   567,    14,    -1,
     211,    19,   221,    13,   569,    20,   567,    20,   567,    20,
     567,    14,    -1,   212,    19,   221,    13,   569,    20,   567,
      20,   567,    20,   567,    20,   567,    20,   567,    14,    -1,
     213,    13,   569,    14,    -1,   214,    13,   569,    20,   567,
      20,   567,    14,    -1,   214,    13,   569,    20,   567,    20,
     567,    20,   612,    14,    -1,   214,    13,   569,    20,   567,
      20,   567,    20,   567,    20,   612,    14,    -1,   215,    13,
     569,    20,   567,    20,   567,    20,   612,    14,    -1,   215,
      13,   569,    20,   567,    20,   567,    20,   567,    20,   612,
      14,    -1,   216,    13,   569,    20,   567,    20,   567,    20,
     612,    14,    -1,   217,    13,   569,    20,   567,    20,   567,
      20,   567,    20,   612,    14,    -1,   218,    13,   569,    20,
     567,    20,   567,    20,   567,    20,   612,    14,    -1,   219,
      13,   569,    20,   567,    20,   567,    20,   567,    20,   567,
      20,   612,    14,    -1,   220,    13,   569,    20,   567,    20,
     567,    20,   567,    20,   567,    14,    -1,   225,    13,   569,
      20,   567,    20,   567,    14,    -1,   260,    13,   569,    20,
     567,    20,   567,    20,   567,    20,   567,    20,   567,    14,
      -1,   428,    13,   569,    14,    -1,   429,    13,   569,    14,
      -1,   430,    13,   569,    14,    -1,   431,    13,   569,    14,
      -1,    65,    19,   347,    -1,    65,    19,   348,    -1,    63,
      19,   347,    -1,   282,    13,   569,    20,   567,    14,    -1,
     283,    13,   569,    20,   567,    14,    -1,   284,    13,   569,
      20,   567,    14,    -1,   285,    13,   569,    20,   567,    14,
      -1,   208,    13,   588,    20,   588,    20,   567,    14,    -1,
     209,    13,   588,    20,   588,    20,   567,    20,   567,    20,
     567,    20,   567,    14,    -1,   208,    13,   588,    20,   588,
      20,   567,    20,   567,    20,   567,    14,    -1,   208,    13,
     588,    20,   588,    20,   567,    20,   567,    20,   567,    20,
     567,    14,    -1,   208,    13,   588,    20,   588,    20,   569,
      20,   567,    20,   567,    14,    -1,   313,    13,   569,    20,
     569,    14,    -1,   314,    13,   569,    20,   569,    20,   588,
      14,    -1,   318,    13,   569,    20,   567,    20,   567,    20,
     567,    14,    -1,   319,    13,   569,    20,   567,    20,   567,
      20,   567,    14,    -1,   319,    13,   569,    20,   567,    20,
     567,    20,   567,    20,   567,    14,    -1,   320,    13,   569,
      20,   567,    14,    -1,   321,    13,   569,    20,   567,    14,
      -1,   322,    13,   569,    20,   567,    14,    -1,   323,    13,
     569,    20,   567,    14,    -1,   324,    13,   569,    20,   567,
      14,    -1,   325,    13,   569,    20,   567,    14,    -1,   326,
      13,   569,    20,   567,    14,    -1,   327,    13,   569,    20,
     567,    14,    -1,   327,    13,   569,    20,   567,    20,   567,
      14,    -1,   328,    13,   569,    20,   567,    20,   567,    20,
     567,    14,    -1,   329,    13,   588,    14,    -1,   569,    13,
     588,    14,    -1,   445,    13,   588,    20,   567,    20,   567,
      20,   567,    14,    -1,   446,    13,   588,    20,   567,    20,
     567,    20,   567,    14,    -1,   497,    13,   588,    14,    -1,
     497,    13,   588,    20,   567,    14,    -1,   500,    13,   588,
      20,   567,    14,    -1,   498,    13,   588,    20,   567,    20,
     567,    20,   567,    20,   567,    14,    -1,   499,    13,   569,
      20,   569,    20,   567,    20,   567,    20,   567,    20,   567,
      20,   567,    20,   567,    20,   567,    20,   567,    20,   567,
      20,   567,    20,   567,    20,   567,    14,    -1,   502,    13,
     588,    20,   567,    20,   567,    14,    -1,   608,    19,   382,
      13,    14,    -1,   608,    19,   292,    13,   567,    14,    -1,
     608,    19,   383,    13,    14,    -1,   608,    19,   384,    13,
      14,    -1,   608,    19,   381,    13,   569,    14,    -1,   508,
      13,   588,    20,   567,    14,    -1,   508,    13,   588,    14,
      -1,   509,    13,   588,    20,   567,    14,    -1,   509,    13,
     588,    14,    -1,   514,    13,   588,    20,   588,    14,    -1,
     515,    13,   588,    14,    -1,   516,    13,   546,    14,    -1,
     487,    13,   588,    20,   567,    20,   567,    20,   567,    20,
     567,    20,   567,    20,   567,    20,   567,    14,    -1,   290,
      13,   608,    20,   569,    20,   588,    14,    -1,   294,    13,
     608,    20,   546,    14,    -1,   570,    -1,    13,   588,    14,
      -1,   571,    -1,   572,    -1,   553,   574,    -1,    11,   574,
      -1,    10,   574,    -1,   455,   574,    -1,   456,   574,    -1,
     466,   574,    -1,   467,   574,    -1,   468,   574,    -1,   469,
     574,    -1,   457,   574,    -1,   458,   574,    -1,   459,   574,
      -1,   460,   574,    -1,   463,   574,    -1,   465,   574,    -1,
     464,   574,    -1,   470,   574,    -1,   573,    -1,    13,   568,
      14,   573,    -1,   574,    -1,   575,     7,   554,    -1,   575,
       8,   554,    -1,   575,     7,   574,    -1,   575,     8,   574,
      -1,   575,     4,   574,    -1,   575,    -1,   576,    -1,   577,
      10,   555,    -1,   577,    11,   555,    -1,   577,    10,   575,
      -1,   577,    11,   575,    -1,   577,    -1,   578,    -1,   579,
       6,   578,    -1,   579,     5,   578,    -1,   579,   138,   578,
      -1,   579,   139,   578,    -1,   579,     6,   557,    -1,   579,
       5,   557,    -1,   579,   138,   557,    -1,   579,   139,   557,
      -1,   579,    -1,   580,   140,   579,    -1,   580,   141,   579,
      -1,   580,   140,   557,    -1,   580,   141,   557,    -1,   580,
      -1,   581,    17,   580,    -1,   581,    -1,   582,    -1,   583,
      18,   582,    -1,   583,    -1,   584,   136,   583,    -1,   584,
      -1,   585,   137,   584,    -1,   585,    -1,   585,    21,   585,
      22,   586,    -1,   586,    -1,   573,   144,   587,    -1,   587,
      -1,    75,    -1,    65,    19,   400,    -1,   402,    13,    75,
      20,    75,    20,   567,    14,    -1,    37,    13,   546,    14,
      -1,   403,    13,   567,    20,   567,    14,    -1,    66,    -1,
     404,    13,   607,    14,    -1,   590,    -1,    13,   607,    14,
      -1,   591,    -1,   592,    -1,   553,   594,    -1,    11,   594,
      -1,    10,   594,    -1,   594,   142,    -1,   455,   594,    -1,
     456,   594,    -1,   466,   594,    -1,   467,   594,    -1,   468,
     594,    -1,   469,   594,    -1,   457,   594,    -1,   458,   594,
      -1,   459,   594,    -1,   460,   594,    -1,   463,   594,    -1,
     465,   594,    -1,   464,   594,    -1,   593,    -1,   594,    -1,
     595,     7,   554,    -1,   595,   143,   594,    -1,   595,     7,
     594,    -1,   595,    -1,   596,    10,   555,    -1,   596,    11,
     555,    -1,   596,    10,   595,    -1,   596,    11,   595,    -1,
     596,    -1,   597,    -1,   598,    -1,   599,    -1,   600,    -1,
     601,    -1,   602,    -1,   603,    -1,   604,    -1,   605,    -1,
     606,    -1,    64,    -1,    76,    15,   567,    16,    -1,   334,
      13,   588,    20,   567,    14,    -1,   337,    13,   569,    20,
     567,    14,    -1,   334,    13,   588,    20,   567,    20,   569,
      14,    -1,   343,    13,   588,    20,   567,    20,   588,    14,
      -1,   338,    13,   608,    14,    -1,   338,    13,   608,    20,
     567,    14,    -1,   339,    13,   569,    20,   567,    14,    -1,
     340,    13,   608,    20,   567,    14,    -1,   342,    13,   608,
      20,   567,    14,    -1,   346,    13,    14,    -1,   346,   546,
      -1,   346,    13,   546,    14,    -1,   346,    -1,   293,    13,
     546,    14,    -1,   293,    13,   546,    20,   567,    14,    -1,
     608,    -1,   277,    13,   569,    14,    -1,   278,    13,   608,
      14,    -1,   278,    13,   608,    20,   567,    20,   567,    20,
     567,    14,    -1,   279,    13,   608,    20,   567,    14,    -1,
     286,    13,   608,    20,   567,    20,   567,    20,   567,    20,
     567,    20,   567,    20,   567,    14,    -1,   287,    13,   588,
      20,   567,    20,   567,    20,   567,    20,   567,    20,   567,
      20,   567,    20,   567,    14,    -1,   288,    13,   588,    20,
     567,    20,   567,    20,   567,    14,    -1,   289,    13,   588,
      20,   567,    20,   567,    20,   567,    20,   567,    20,   567,
      20,   567,    20,   567,    20,   567,    14,    -1,   289,    13,
     588,    20,   567,    20,   567,    20,   567,    20,   567,    20,
     567,    14,    -1,   608,    19,   281,    13,   567,    20,   567,
      14,    -1,   505,    13,   588,    14,    -1,   505,    13,   588,
      20,   567,    14,    -1,   505,    13,   588,    20,   567,    20,
     567,    14,    -1,   507,    13,   588,    20,   567,    20,   567,
      14,    -1,   506,    13,   588,    20,   567,    20,   567,    20,
     588,    20,   588,    14,    -1,   506,    13,   588,    20,   567,
      20,   567,    20,   588,    20,   588,    20,   588,    20,   567,
      14,    -1,   511,    13,   588,    20,   588,    20,   588,    20,
     567,    20,   567,    20,   567,    20,   567,    14,    -1,   511,
      13,   588,    20,   588,    20,   588,    20,   567,    20,   567,
      20,   567,    20,   567,    20,   567,    14,    -1,   511,    13,
     588,    20,   588,    20,   588,    20,   567,    20,   567,    20,
     567,    14,    -1,   511,    13,   588,    20,   567,    20,   567,
      20,   567,    20,   567,    20,   567,    14,    -1,   513,    13,
     588,    20,   588,    20,   588,    20,   567,    20,   567,    20,
     567,    20,   567,    14,    -1,   513,    13,   588,    20,   588,
      20,   588,    20,   567,    20,   567,    20,   567,    20,   567,
      20,   588,    20,   588,    14,    -1,    57,    -1,    60,    -1,
      59,    -1,    61,    -1,   569,    -1,    63,    -1,    64,    -1,
      65,    -1,    67,    -1,    68,    -1,    69,    -1,    70,    -1,
      71,    -1,    72,    -1,    73,    -1,    62,    -1,    66,    -1,
      75,    -1,    74,    -1,    76,    -1,    77,    -1,   567,    22,
     567,    20,   567,    22,   567,    20,   567,    22,   567,    -1,
     567,    22,   567,    20,   567,    22,   567,    -1,   569,    -1,
      63,    -1
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
     144,   146,   148,   150,   152,   154,   159,   166,   171,   178,
     185,   192,   196,   200,   207,   214,   218,   222,   226,   230,
     237,   241,   245,   249,   256,   263,   272,   279,   288,   292,
     298,   302,   308,   317,   326,   330,   332,   334,   336,   338,
     347,   352,   357,   359,   362,   365,   368,   372,   376,   380,
     384,   391,   398,   415,   418,   421,   425,   428,   431,   435,
     439,   442,   445,   449,   452,   459,   462,   465,   471,   474,
     476,   478,   481,   484,   487,   490,   493,   498,   503,   506,
     509,   512,   515,   517,   522,   526,   529,   532,   543,   550,
     554,   561,   568,   577,   606,   615,   624,   628,   637,   650,
     657,   664,   681,   690,   707,   718,   725,   736,   745,   756,
     771,   780,   793,   800,   809,   816,   823,   830,   841,   848,
     859,   870,   883,   890,   897,   910,   917,   924,   931,   938,
     945,   952,   959,   966,   973,   980,   987,   994,  1003,  1007,
    1011,  1015,  1019,  1023,  1027,  1040,  1057,  1064,  1071,  1078,
    1085,  1092,  1099,  1106,  1113,  1120,  1127,  1138,  1145,  1160,
    1167,  1176,  1183,  1190,  1199,  1206,  1217,  1224,  1231,  1238,
    1245,  1252,  1259,  1266,  1273,  1280,  1287,  1294,  1298,  1302,
    1307,  1311,  1318,  1325,  1330,  1335,  1342,  1353,  1364,  1375,
    1382,  1389,  1396,  1403,  1410,  1421,  1428,  1439,  1446,  1453,
    1460,  1464,  1471,  1478,  1489,  1500,  1507,  1514,  1521,  1525,
    1529,  1533,  1537,  1544,  1551,  1555,  1562,  1569,  1578,  1589,
    1593,  1600,  1604,  1609,  1630,  1637,  1648,  1655,  1659,  1663,
    1670,  1674,  1681,  1690,  1697,  1704,  1713,  1730,  1737,  1741,
    1748,  1757,  1761,  1774,  1787,  1800,  1811,  1815,  1819,  1828,
    1837,  1848,  1857,  1868,  1881,  1888,  1897,  1906,  1917,  1934,
    1953,  1966,  1973,  1992,  2009,  2022,  2033,  2044,  2055,  2062,
    2073,  2080,  2087,  2094,  2103,  2105,  2110,  2115,  2124,  2129,
    2148,  2153,  2155,  2157,  2159,  2166,  2170,  2179,  2183,  2187,
    2191,  2195,  2199,  2203,  2207,  2211,  2215,  2219,  2226,  2235,
    2242,  2253,  2260,  2269,  2278,  2287,  2296,  2303,  2307,  2312,
    2314,  2316,  2318,  2349,  2374,  2379,  2388,  2390,  2394,  2395,
    2397,  2401,  2403,  2407,  2410,  2415,  2418,  2423,  2425,  2429,
    2432,  2437,  2440,  2445,  2447,  2451,  2452,  2455,  2458,  2461,
    2464,  2467,  2472,  2477,  2482,  2487,  2492,  2494,  2496,  2498,
    2505,  2512,  2519,  2521,  2525,  2530,  2535,  2537,  2539,  2543,
    2547,  2549,  2553,  2557,  2561,  2562,  2563,  2565,  2567,  2569,
    2571,  2573,  2575,  2577,  2581,  2583,  2588,  2595,  2604,  2615,
    2626,  2637,  2646,  2653,  2657,  2661,  2665,  2668,  2672,  2676,
    2680,  2687,  2692,  2703,  2708,  2719,  2724,  2729,  2734,  2739,
    2744,  2749,  2757,  2765,  2773,  2783,  2791,  2798,  2803,  2807,
    2811,  2815,  2819,  2823,  2827,  2831,  2835,  2839,  2843,  2847,
    2851,  2858,  2867,  2878,  2891,  2902,  2915,  2924,  2931,  2940,
    2949,  2958,  2967,  2974,  2983,  2992,  3001,  3014,  3021,  3028,
    3032,  3039,  3046,  3051,  3056,  3061,  3063,  3070,  3077,  3084,
    3088,  3095,  3097,  3100,  3103,  3106,  3109,  3112,  3115,  3118,
    3121,  3124,  3127,  3130,  3133,  3136,  3139,  3142,  3145,  3148,
    3150,  3152,  3154,  3159,  3161,  3165,  3169,  3173,  3175,  3179,
    3183,  3185,  3187,  3191,  3195,  3199,  3203,  3205,  3209,  3213,
    3217,  3221,  3223,  3227,  3229,  3233,  3235,  3239,  3241,  3245,
    3247,  3251,  3253,  3259,  3261,  3263,  3265,  3267,  3269,  3271,
    3273,  3275,  3277,  3279,  3281,  3283,  3287,  3289,  3294,  3297,
    3302,  3319,  3334,  3351,  3356,  3361,  3366,  3368,  3379,  3392,
    3401,  3403,  3408,  3415,  3422,  3429,  3438,  3447,  3454,  3461,
    3470,  3479,  3490,  3501,  3514,  3527,  3538,  3543,  3554,  3559,
    3566,  3571,  3576,  3581,  3594,  3599,  3612,  3625,  3642,  3663,
    3674,  3687,  3692,  3699,  3706,  3713,  3718,  3723,  3730,  3735,
    3742,  3749,  3756,  3761,  3772,  3789,  3800,  3809,  3822,  3833,
    3842,  3855,  3864,  3877,  3886,  3899,  3903,  3907,  3916,  3925,
    3929,  3936,  3949,  3962,  3977,  3990,  4003,  4020,  4025,  4034,
    4045,  4058,  4069,  4082,  4093,  4106,  4119,  4134,  4147,  4156,
    4171,  4176,  4181,  4186,  4191,  4195,  4199,  4203,  4210,  4217,
    4224,  4231,  4240,  4255,  4268,  4283,  4296,  4303,  4312,  4323,
    4334,  4347,  4354,  4361,  4368,  4375,  4382,  4389,  4396,  4403,
    4412,  4423,  4428,  4433,  4444,  4455,  4460,  4467,  4474,  4487,
    4518,  4527,  4533,  4540,  4546,  4552,  4559,  4566,  4571,  4578,
    4583,  4590,  4595,  4600,  4619,  4628,  4635,  4637,  4641,  4643,
    4645,  4648,  4651,  4654,  4657,  4660,  4663,  4666,  4669,  4672,
    4675,  4678,  4681,  4684,  4687,  4690,  4693,  4696,  4698,  4703,
    4705,  4709,  4713,  4717,  4721,  4725,  4727,  4729,  4733,  4737,
    4741,  4745,  4747,  4749,  4753,  4757,  4761,  4765,  4769,  4773,
    4777,  4781,  4783,  4787,  4791,  4795,  4799,  4801,  4805,  4807,
    4809,  4813,  4815,  4819,  4821,  4825,  4827,  4833,  4835,  4839,
    4841,  4843,  4847,  4856,  4861,  4868,  4870,  4875,  4877,  4881,
    4883,  4885,  4888,  4891,  4894,  4897,  4900,  4903,  4906,  4909,
    4912,  4915,  4918,  4921,  4924,  4927,  4930,  4933,  4936,  4938,
    4940,  4944,  4948,  4952,  4954,  4958,  4962,  4966,  4970,  4972,
    4974,  4976,  4978,  4980,  4982,  4984,  4986,  4988,  4990,  4992,
    4994,  4999,  5006,  5013,  5022,  5031,  5036,  5043,  5050,  5057,
    5064,  5068,  5071,  5076,  5078,  5083,  5090,  5092,  5097,  5102,
    5113,  5120,  5137,  5156,  5167,  5188,  5203,  5212,  5217,  5224,
    5233,  5242,  5255,  5272,  5289,  5308,  5323,  5338,  5355,  5376,
    5378,  5380,  5382,  5384,  5386,  5388,  5390,  5392,  5394,  5396,
    5398,  5400,  5402,  5404,  5406,  5408,  5410,  5412,  5414,  5416,
    5418,  5430,  5438,  5440
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   956,   956,   957,   961,   961,   962,   963,   964,   964,
     965,   965,   966,   966,   967,   967,   968,   968,   969,   969,
     972,   973,   978,   997,  1020,  1055,  1084,  1099,  1122,  1121,
    1151,  1150,  1191,  1210,  1232,  1239,  1274,  1280,  1289,  1299,
    1307,  1317,  1331,  1345,  1359,  1369,  1385,  1405,  1418,  1430,
    1441,  1452,  1464,  1475,  1495,  1517,  1529,  1540,  1545,  1555,
    1578,  1587,  1599,  1617,  1639,  1652,  1671,  1684,  1703,  1716,
    1735,  1749,  1769,  1802,  1819,  1824,  1828,  1832,  1837,  1841,
    1856,  1866,  1877,  1880,  1930,  1950,  1995,  2007,  2019,  2059,
    2072,  2107,  2137,  2157,  2161,  2165,  2169,  2173,  2177,  2181,
    2185,  2189,  2193,  2198,  2202,  2213,  2226,  2236,  2245,  2256,
    2264,  2276,  2525,  2535,  2545,  2555,  2609,  2617,  2625,  2634,
    2644,  2650,  2661,  2667,  2674,  2680,  2690,  2700,  2716,  2728,
    2738,  2786,  2801,  2822,  2853,  2868,  2875,  2882,  2900,  2923,
    2928,  2933,  2946,  2957,  2966,  2976,  2984,  3001,  3017,  3034,
    3054,  3069,  3087,  3100,  3114,  3123,  3137,  3148,  3161,  3179,
    3201,  3229,  3259,  3291,  3296,  3314,  3319,  3324,  3329,  3334,
    3339,  3353,  3368,  3385,  3399,  3419,  3424,  3429,  3436,  3445,
    3453,  3458,  3465,  3470,  3475,  3495,  3519,  3524,  3529,  3534,
    3539,  3544,  3549,  3554,  3559,  3564,  3569,  3574,  3579,  3584,
    3589,  3594,  3599,  3612,  3617,  3622,  3630,  3635,  3640,  3645,
    3650,  3655,  3660,  3665,  3670,  3675,  3680,  3685,  3690,  3694,
    3721,  3734,  3739,  3743,  3749,  3762,  3768,  3774,  3780,  3787,
    3794,  3801,  3810,  3821,  3836,  3851,  3859,  3866,  3873,  3879,
    3883,  3887,  3924,  3930,  3937,  3944,  3955,  3963,  3980,  3990,
    3995,  4002,  4009,  4017,  4025,  4044,  4060,  4077,  4094,  4099,
    4104,  4109,  4114,  4122,  4223,  4257,  4264,  4272,  4278,  4285,
    4295,  4304,  4311,  4318,  4328,  4335,  4349,  4363,  4371,  4376,
    4384,  4392,  4403,  4415,  4427,  4439,  4445,  4454,  4463,  4476,
    4483,  4494,  4516,  4542,  4570,  4580,  4593,  4603,  4625,  4654,
    4671,  4686,  4693,  4715,  4734,  4752,  4766,  4771,  4776,  4785,
    4790,  4799,  4813,  4820,  4827,  4829,  4846,  4862,  4901,  4914,
    4958,  4963,  4968,  4973,  4979,  4996,  5006,  5021,  5027,  5034,
    5040,  5046,  5052,  5058,  5073,  5084,  5090,  5104,  5118,  5135,
    5142,  5163,  5181,  5200,  5220,  5240,  5260,  5267,  5272,  5278,
    5283,  5288,  5293,  5328,  5355,  5362,  5384,  5392,  5409,  5413,
    5420,  5427,  5435,  5443,  5452,  5459,  5466,  5473,  5480,  5487,
    5494,  5501,  5508,  5515,  5522,  5532,  5537,  5546,  5553,  5560,
    5567,  5574,  5581,  5588,  5595,  5602,  5610,  5615,  5630,  5636,
    5650,  5666,  5682,  5706,  5710,  5721,  5739,  5749,  5750,  5760,
    5768,  5770,  5786,  5803,  5814,  5815,  5818,  5819,  5827,  5835,
    5844,  5848,  5852,  5856,  5864,  5865,  5880,  5896,  5910,  5925,
    5942,  5958,  5972,  5985,  6006,  6066,  6091,  6113,  6132,  6139,
    6147,  6152,  6157,  6185,  6191,  6202,  6221,  6240,  6259,  6278,
    6297,  6316,  6339,  6361,  6384,  6391,  6415,  6438,  6446,  6456,
    6466,  6476,  6486,  6496,  6506,  6520,  6537,  6553,  6558,  6563,
    6567,  6574,  6582,  6617,  6655,  6672,  6692,  6704,  6721,  6741,
    6774,  6793,  6815,  6831,  6849,  6873,  6894,  6922,  6936,  6946,
    6959,  6973,  6988,  6996,  7004,  7016,  7020,  7035,  7042,  7052,
    7064,  7077,  7078,  7079,  7080,  7081,  7082,  7083,  7084,  7085,
    7086,  7087,  7095,  7096,  7097,  7098,  7099,  7111,  7123,  7139,
    7140,  7144,  7146,  7162,  7163,  7164,  7165,  7169,  7170,  7171,
    7175,  7180,  7181,  7182,  7183,  7184,  7188,  7189,  7190,  7191,
    7192,  7196,  7197,  7205,  7206,  7210,  7214,  7221,  7225,  7232,
    7236,  7243,  7244,  7251,  7255,  7261,  7266,  7270,  7274,  7278,
    7282,  7286,  7290,  7294,  7298,  7302,  7310,  7315,  7332,  7338,
    7344,  7402,  7456,  7512,  7533,  7554,  7568,  7597,  7605,  7624,
    7650,  7663,  7741,  7808,  7816,  7824,  7834,  7844,  7874,  7892,
    7912,  7930,  7950,  7968,  7987,  8027,  8042,  8056,  8072,  8095,
    8109,  8123,  8137,  8151,  8186,  8200,  8221,  8242,  8283,  8329,
    8346,  8365,  8379,  8393,  8407,  8426,  8441,  8456,  8473,  8494,
    8511,  8527,  8539,  8568,  8588,  8633,  8645,  8656,  8669,  8681,
    8692,  8718,  8745,  8777,  8794,  8812,  8825,  8838,  8858,  8881,
    8895,  8910,  8944,  8981,  9016,  9049,  9066,  9083,  9097,  9118,
    9141,  9165,  9190,  9215,  9237,  9259,  9283,  9326,  9350,  9382,
    9405,  9442,  9479,  9516,  9551,  9556,  9565,  9570,  9581,  9591,
    9601,  9610,  9631,  9661,  9687,  9716,  9749,  9760,  9776,  9786,
    9796,  9811,  9825,  9839,  9852,  9865,  9877,  9889,  9901,  9912,
    9925,  9952,  9985, 10101, 10125, 10167, 10179, 10188, 10197, 10220,
   10245, 10258, 10268, 10305, 10323, 10341, 10351, 10361, 10369, 10377,
   10385, 10410, 10430, 10438, 10472, 10495, 10515, 10515, 10517, 10519,
   10520, 10521, 10522, 10523, 10524, 10525, 10526, 10527, 10528, 10529,
   10530, 10531, 10532, 10533, 10534, 10535, 10536, 10550, 10551, 10573,
   10574, 10580, 10582, 10583, 10584, 10587, 10592, 10593, 10594, 10595,
   10596, 10599, 10603, 10604, 10605, 10606, 10607, 10608, 10609, 10610,
   10611, 10615, 10616, 10617, 10618, 10619, 10623, 10624, 10629, 10633,
   10634, 10638, 10639, 10643, 10644, 10648, 10649, 10653, 10654, 10657,
   10661, 10671, 10684, 10695, 10712, 10719, 10729, 10744, 10744, 10746,
   10748, 10749, 10750, 10751, 10752, 10761, 10762, 10763, 10764, 10765,
   10766, 10767, 10768, 10769, 10770, 10771, 10772, 10773, 10777, 10779,
   10780, 10781, 10782, 10792, 10793, 10794, 10795, 10796, 10799, 10803,
   10807, 10811, 10816, 10820, 10824, 10828, 10832, 10836, 10839, 10844,
   10849, 10865, 10876, 10886, 10906, 10940, 10949, 10958, 10967, 10976,
   10984, 10990, 10996, 11002, 11028, 11042, 11058, 11068, 11086, 11114,
   11141, 11156, 11179, 11213, 11245, 11292, 11333, 11357, 11367, 11390,
   11402, 11415, 11452, 11495, 11543, 11595, 11638, 11666, 11699, 11742,
   11746, 11747, 11748, 11749, 11753, 11754, 11755, 11756, 11757, 11758,
   11759, 11760, 11761, 11762, 11763, 11764, 11765, 11766, 11767, 11768,
   11773, 11781, 11788, 11804
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
       2,     2,     2,     2,     2,     2,   526,     2,     2,     2,
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
     525
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 16423;
  const int Parser::yynnts_ = 86;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 397;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 527;

  const unsigned int Parser::yyuser_token_number_max_ = 780;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // yyip

/* Line 1054 of lalr1.cc  */
#line 20727 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"


/* Line 1056 of lalr1.cc  */
#line 11824 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"

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





