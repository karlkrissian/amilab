
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

#include "wrapfunction_class.h"


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
#line 392 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"


#include "improcess_bison.tab.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 944 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"


#include "driver.h"
#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex



/* Line 317 of lalr1.cc  */
#line 415 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"

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
#line 484 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
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
#line 937 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 591 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 57: /* "IDENTIFIER" */

/* Line 480 of lalr1.cc  */
#line 938 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 600 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 544: /* "primary_expr_string" */

/* Line 480 of lalr1.cc  */
#line 937 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 609 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 545: /* "postfix_expr_string" */

/* Line 480 of lalr1.cc  */
#line 937 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 618 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 546: /* "additive_expr_string" */

/* Line 480 of lalr1.cc  */
#line 937 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 627 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 547: /* "expr_string" */

/* Line 480 of lalr1.cc  */
#line 937 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 636 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 548: /* "instr_block" */

/* Line 480 of lalr1.cc  */
#line 939 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ablock); };

/* Line 480 of lalr1.cc  */
#line 645 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 611: /* "identifier" */

/* Line 480 of lalr1.cc  */
#line 938 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 654 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 613: /* "image_extent" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->imageextent); };

/* Line 480 of lalr1.cc  */
#line 663 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
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
#line 380 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}

/* Line 553 of lalr1.cc  */
#line 749 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"

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
#line 983 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1002 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1025 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1059 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1088 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1103 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1125 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_driver.procedure_declaration = true;
    }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 1130 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1154 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      // allow overriding current functions
      GB_driver.procedure_declaration = true;
    }
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 1160 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1196 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1214 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1236 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       //driver.res_print($2);
       driver.parse_script((yysemantic_stack_[(3) - (2)].astring));
       delete [] (yysemantic_stack_[(3) - (2)].astring);
     }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 1243 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1278 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      string_ptr inputstring( new std::string((yysemantic_stack_[(2) - (2)].astring)));
      driver.parse_string( *inputstring,
                          "'eval string' command");
     }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 1284 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        Variable*       var   = (yysemantic_stack_[(5) - (1)].variable);
        ParamList::ptr  param((yysemantic_stack_[(5) - (3)].paramlist));

        driver.yyip_call_function(var,param);


        }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 1293 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable*    var   = (yysemantic_stack_[(2) - (1)].variable);

          // Call the function
          driver.yyip_call_function(var);
        }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 1302 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1310 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1321 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1335 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1349 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1363 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1373 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1389 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1409 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1422 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1434 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1445 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1456 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1468 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1479 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1499 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1521 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1533 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1544 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr m1 = *((FloatMatrix::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer()));
          (*m1) = (yysemantic_stack_[(3) - (3)].adouble);
       }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 1549 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1559 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1582 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variables* contextptr = new Variables();
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
          contextptr->SetName(ident->GetName());

          Vars.AddVar(type_context,ident,(void*)contextptr);
        }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1591 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1603 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1621 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1643 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1656 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1675 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1688 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1707 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1720 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1739 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1753 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1773 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1806 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1823 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
            rewind(file.get());
        }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1828 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 1;
        }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1832 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 0;
        }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 1836 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 1;
      verbose = 1;
    }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 1841 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 0;
    }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 1845 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1860 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1870 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1880 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GB_main_wxFrame->Close(true);
        }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1884 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1934 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1954 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1999 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2011 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2023 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2063 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2076 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2111 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2141 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2161 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(float_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))++;
        }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 2165 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(float_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))--;
        }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 2169 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          *(*(float_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer()) = (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 2173 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(int_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))++;
        }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 2177 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(int_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))--;
        }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 2181 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          *(*(int_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer()) = (int) (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 2185 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           *(*(uchar_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer()) = (unsigned char) (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 2189 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (*(*(uchar_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))++;
        }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 2193 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (*(*(uchar_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))--;
        }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 2197 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          string_ptr newname( new std::string((yysemantic_stack_[(3) - (3)].astring)));
          (yysemantic_stack_[(3) - (1)].variable)->SetString(newname);
        }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 2202 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Vars.display();
        }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 2206 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2217 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2230 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2240 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2249 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2260 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2268 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2280 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2529 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2539 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2549 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2559 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        Displays the documentation relative to the wrapped c++ member.
    **/
       Variable*  var   = (yysemantic_stack_[(2) - (2)].variable);
        // call with NULL paramlist pointer to trigger help message
        (*(WrapClassMember::ptr*) var->Pointer())->CallProc(NULL);
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 2569 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 117:

/* Line 678 of lalr1.cc  */
#line 2623 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(4) - (1)].variable)->Pointer());
          string_ptr text( new std::string((yysemantic_stack_[(4) - (4)].astring)));

          fprintf(file.get(),"%s",text->c_str());
          fflush(file.get());
        }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 2631 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(4) - (1)].variable)->Pointer());
          string_ptr text( new std::string((yysemantic_stack_[(4) - (4)].astring)));

          fprintf(file.get(),"%s\n",text->c_str());
          fflush(file.get());
        }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 2639 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
          Description:
            Print a string
          **/
          driver.res_print((yysemantic_stack_[(2) - (2)].astring));
          delete [] (yysemantic_stack_[(2) - (2)].astring);
        }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 2648 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 121:

/* Line 678 of lalr1.cc  */
#line 2658 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=driver.matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
      }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 2664 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 123:

/* Line 678 of lalr1.cc  */
#line 2675 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=driver.matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
          }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 2681 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(4) - (1)].variable)->Pointer());

          fprintf(file.get(),"%5.10f",(yysemantic_stack_[(4) - (4)].adouble));
          fflush(file.get());
        }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 2688 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            printf("Files are not close anymore: delete the variable instead \n");
          //FILE_ptr file = *(FILE_ptr*) ($1->Pointer());
          //fclose(file.get());
        }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 2694 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 127:

/* Line 678 of lalr1.cc  */
#line 2704 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 128:

/* Line 678 of lalr1.cc  */
#line 2714 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 129:

/* Line 678 of lalr1.cc  */
#line 2730 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 130:

/* Line 678 of lalr1.cc  */
#line 2742 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          DessinImageParametres* param;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
          param = draw->GetParam();
          param->_MAJ.MAJCoupes();
          draw->Paint();
        }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 2752 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 132:

/* Line 678 of lalr1.cc  */
#line 2800 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 133:

/* Line 678 of lalr1.cc  */
#line 2815 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 134:

/* Line 678 of lalr1.cc  */
#line 2840 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 135:

/* Line 678 of lalr1.cc  */
#line 2867 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 136:

/* Line 678 of lalr1.cc  */
#line 2882 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(8) - (1)].variable)->Pointer());
          draw->SetVectorVisible( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 2889 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
          draw->CB_AfficheChampVect(draw.get(),NULL);
        }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 2896 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 139:

/* Line 678 of lalr1.cc  */
#line 2914 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 140:

/* Line 678 of lalr1.cc  */
#line 2937 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw= *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          draw->SetVectType((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 2942 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw= *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          draw->SetLineThickness((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 2947 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 143:

/* Line 678 of lalr1.cc  */
#line 2960 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          int width  = (int) (yysemantic_stack_[(8) - (5)].adouble);
          int height = (int) (yysemantic_stack_[(8) - (7)].adouble);

          DessinImage::ptr draw= *(DessinImage::ptr*) ((yysemantic_stack_[(8) - (1)].variable)->Pointer());
          draw->SetSize(width,height);
          draw->Update();


        }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 2971 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          ClasseCouleur c;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(16) - (1)].variable)->Pointer());
          c.FixeValeur((int)(yysemantic_stack_[(16) - (11)].adouble),(int)(yysemantic_stack_[(16) - (13)].adouble),(int)(yysemantic_stack_[(16) - (15)].adouble));
          draw->DessineCercle( (int) (yysemantic_stack_[(16) - (5)].adouble), (int) (yysemantic_stack_[(16) - (7)].adouble), (int) (yysemantic_stack_[(16) - (9)].adouble), c);
        }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 2980 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          // TODO: fix this memory problem ...
          InrImage* colmap=(InrImage*) driver.im_stack.GetLastImage();

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(10) - (1)].variable)->Pointer());
          draw->SetUserColormap( colmap,  (yysemantic_stack_[(10) - (7)].adouble),  (yysemantic_stack_[(10) - (9)].adouble));
          //      delete colmap;
        }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 2990 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          draw->SetGLWindow( *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer()));

        }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 2998 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 148:

/* Line 678 of lalr1.cc  */
#line 3015 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 149:

/* Line 678 of lalr1.cc  */
#line 3031 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 150:

/* Line 678 of lalr1.cc  */
#line 3048 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 151:

/* Line 678 of lalr1.cc  */
#line 3068 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 152:

/* Line 678 of lalr1.cc  */
#line 3083 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 153:

/* Line 678 of lalr1.cc  */
#line 3101 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 154:

/* Line 678 of lalr1.cc  */
#line 3114 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 155:

/* Line 678 of lalr1.cc  */
#line 3128 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            DessinImage::ptr draw;

            draw = *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
            draw->SetPaintCallback( (void*) CB_ParamWin, (void*) (yysemantic_stack_[(6) - (5)].variable));
            // may be a pb to call Paint() here since it will start another interpreter ??? to check
            //draw->Paint();
        }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 3137 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 157:

/* Line 678 of lalr1.cc  */
#line 3151 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 158:

/* Line 678 of lalr1.cc  */
#line 3162 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 159:

/* Line 678 of lalr1.cc  */
#line 3175 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 160:

/* Line 678 of lalr1.cc  */
#line 3193 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 161:

/* Line 678 of lalr1.cc  */
#line 3215 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 162:

/* Line 678 of lalr1.cc  */
#line 3245 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 163:

/* Line 678 of lalr1.cc  */
#line 3273 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 164:

/* Line 678 of lalr1.cc  */
#line 3304 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->FixeNom( (yysemantic_stack_[(6) - (5)].astring));
      delete [] (yysemantic_stack_[(6) - (5)].astring);
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 3310 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 166:

/* Line 678 of lalr1.cc  */
#line 3328 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_SetCoeffAnisoGS((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 3333 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetDistanceMap((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 3338 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseType((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 3343 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseSD((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 3348 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetMask(((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 3353 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 172:

/* Line 678 of lalr1.cc  */
#line 3367 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 173:

/* Line 678 of lalr1.cc  */
#line 3382 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 174:

/* Line 678 of lalr1.cc  */
#line 3399 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 175:

/* Line 678 of lalr1.cc  */
#line 3413 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 176:

/* Line 678 of lalr1.cc  */
#line 3433 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setdt((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 3438 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setneighborhood((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 3443 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_SetCoeffAnisoGS3D((yysemantic_stack_[(8) - (5)].adouble),(yysemantic_stack_[(8) - (7)].adouble));

    }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 3450 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float  error;

      error = Func_ItereAnisoGS();

      //driver.res_print("Error in AnisoGS.Iterate ");
    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 3459 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int res;

      res = Func_EndAnisoGS();

    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 3467 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 3472 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_EndWeickert();

    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 3479 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 3484 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_EndWeickert();
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 3489 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 186:

/* Line 678 of lalr1.cc  */
#line 3510 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 187:

/* Line 678 of lalr1.cc  */
#line 3533 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetMeanCurv( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 3538 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetAffineCurvature( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 3543 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetBalloonScheme( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 3548 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetDMmethod( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 3553 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetThreads( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 3558 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 3563 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityLowThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 3568 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityHighThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 3573 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbabilityHighThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 3578 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumGaussians( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 3583 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetGaussian( (int) (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 3588 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumInitPoints( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 3593 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetInitPoint( (int) (yysemantic_stack_[(14) - (5)].adouble), (int) (yysemantic_stack_[(14) - (7)].adouble), (int) (yysemantic_stack_[(14) - (9)].adouble), (int) (yysemantic_stack_[(14) - (11)].adouble), (int) (yysemantic_stack_[(14) - (13)].adouble));
    }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 3598 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSets_SetIsoContourBin( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 3603 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsVelocity(((InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get(),(yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 3608 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsExpansion((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 3613 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 204:

/* Line 678 of lalr1.cc  */
#line 3626 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsBandAndTube((int)(yysemantic_stack_[(8) - (5)].adouble),(int)(yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 3631 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSetCurvWeights( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 3636 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSetAdvectionField(
                ((InrImage::ptr*) (yysemantic_stack_[(10) - (5)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(10) - (7)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(10) - (9)].variable)->Pointer())->get());
        }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 3644 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetCurvatureData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 3649 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetDistanceMap( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 3654 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetAdvectionData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 3659 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetSkeleton( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 3664 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetVelocityData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 3669 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetExpansionData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 3674 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetCurvatureData( NULL );
        }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 3679 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetAdvectionData( NULL);
        }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 3684 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetVelocityData( NULL);
        }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 3689 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsSaveDistMap( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 3694 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsSaveSecDerGrad( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 3699 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.aint) = Func_LevelSets_Iterate();
    }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 3704 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_End();
    }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 3708 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 221:

/* Line 678 of lalr1.cc  */
#line 3735 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 222:

/* Line 678 of lalr1.cc  */
#line 3748 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_OrientField( ((InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->get() , ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );
        }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 3753 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       Func_OrientPositive( ((InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->get() , ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );
    }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 3757 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())->Write((yysemantic_stack_[(4) - (4)].astring));
      delete [] (yysemantic_stack_[(4) - (4)].astring);
    }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 3763 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 226:

/* Line 678 of lalr1.cc  */
#line 3776 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetOwnMaterial( (int) (yysemantic_stack_[(6) - (5)].adouble));

        }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 3782 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->GetMaterial()._ambient.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 3788 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->GetMaterial()._diffuse.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 3794 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->GetMaterial()._specular.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 3801 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->GetMaterial()._shininess= (yysemantic_stack_[(6) - (5)].adouble);

        }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 3808 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->GetMaterial()._opacity= (yysemantic_stack_[(6) - (5)].adouble);

    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 3815 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        Sets the object visible or not visible in the scene.
      **/
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetVisible( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 3824 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Enable/Disable colormaterial for the associated surface.
        **/

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->GetMaterial()._colormaterial = (unsigned char) ((yysemantic_stack_[(6) - (5)].adouble)>0.5);

    }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 3835 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 235:

/* Line 678 of lalr1.cc  */
#line 3850 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 236:

/* Line 678 of lalr1.cc  */
#line 3865 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());


      s->SetPointsColors( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

    }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 3873 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());
      InrImage::ptr i = InrImage::ptr(driver.im_stack.GetLastImage());
      // TODO: use smart pointer to image in SetColors ...
      s->SetColors( i.get() , (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 3880 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      InrImage::ptr i = InrImage::ptr(driver.im_stack.GetLastImage());
      s->SetColors( i.get() );

    }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 3887 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      s->Statistics( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

    }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 3893 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->MergePoints((yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 3897 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->Triangulate();
    }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 3901 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 243:

/* Line 678 of lalr1.cc  */
#line 3938 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      InrImage::ptr i = InrImage::ptr(driver.im_stack.GetLastImage());
      s->DisplacePoints( i.get() );
    }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 3944 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

      s->Translate( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble) );

    }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 3951 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

      s->Scale( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble),0 );

        }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 3958 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          int          w = (int) (yysemantic_stack_[(6) - (5)].adouble);

          Si w<1  AlorsFait w=1;
          Si w>10 AlorsFait w=10;

          s->_line_width = w;

        }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 3969 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

      s->RemoveLine((int)(yysemantic_stack_[(6) - (5)].adouble));
          s->GLRecomputeList();

    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 3977 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 249:

/* Line 678 of lalr1.cc  */
#line 3994 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Remove selected lines
    **/
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

        s->RemoveSelection();
        s->GLRecomputeList();
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 4004 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GLRecomputeList();

        }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 4009 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

      s->RecomputeNormals();

        }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 4016 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

      s->InvertNormals();

        }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 4023 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          Func_ApplyvtkSmooth(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 4031 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          Func_vtkWindowedSinc(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 4039 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 256:

/* Line 678 of lalr1.cc  */
#line 4058 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 257:

/* Line 678 of lalr1.cc  */
#line 4074 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 258:

/* Line 678 of lalr1.cc  */
#line 4091 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 259:

/* Line 678 of lalr1.cc  */
#line 4108 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());
      s->AddPoint((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 4113 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      s->NewLine();
    }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 4118 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      s->LineAddPointNumber( (int) (yysemantic_stack_[(6) - (5)].adouble) );
    }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 4123 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      s->EndLine();
    }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 4128 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      if (strlen((yysemantic_stack_[(4) - (3)].astring))<255) {
        strcpy(AMIFluid::FLUID_NAVIGATION_FILE,(yysemantic_stack_[(4) - (3)].astring));
      } else
        fprintf(stderr,"SetFluidNavFile() \t File too long \n");
      delete [] (yysemantic_stack_[(4) - (3)].astring);
        }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 4137 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 265:

/* Line 678 of lalr1.cc  */
#line 4237 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 266:

/* Line 678 of lalr1.cc  */
#line 4271 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->UserRotate((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 4278 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          SurfacePoly::ptr surf = SurfacePoly::ptr(driver.surf_stack.GetLastSurf());

          sdraw->GetCanvas()->AddSurface(surf);
          sdraw->Paint();
        }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 4286 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());
          sdraw->GetCanvas()->AddSurface(*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (3)].variable)->Pointer());
          //sdraw->Paint();
        }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 4292 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->RemoveSurface(*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (3)].variable)->Pointer());
          sdraw->Paint();
        }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 4299 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description: Removes the surface without swapping the 3D buffer
          **/
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->RemoveSurface(*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer());
          sdraw->Paint(false);
        }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 4309 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:  Swaps the 3D buffer
          **/
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->AfficheBuffer();
        }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 4318 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC ( (int) (yysemantic_stack_[(6) - (5)].adouble) );
          sdraw->Paint();
        }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 4325 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
          sdraw->Paint();
        }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 4332 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          Si sdraw->GetCanvas()->SetCurrentObject( (int) (yysemantic_stack_[(6) - (5)].adouble) ) Alors
            sdraw->Paint();
          Sinon
            fprintf(stderr," Incorrect index \n");
          FinSi
        }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 4342 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw1 = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          Viewer3D_ptr sdraw2 = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer());

          sdraw1->AddCompSurf(sdraw2);
        }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 4349 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 277:

/* Line 678 of lalr1.cc  */
#line 4363 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 278:

/* Line 678 of lalr1.cc  */
#line 4377 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Viewer3D_ptr draw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      int num = (int) (yysemantic_stack_[(6) - (5)].adouble);

      draw->GetCanvas()->HideFreeSection(num);

        }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 4385 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr glclass=*((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());
          glclass->GetCanvas()->PrintMatrices();
        }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 4390 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->SetObjectTransform(*tr);
              sdraw->Paint();
          delete tr;
        }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 4398 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->SetObjectTransform(*tr);
          if ((yysemantic_stack_[(8) - (7)].adouble)>0.5) sdraw->Paint();
          delete tr;
        }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 4406 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 283:

/* Line 678 of lalr1.cc  */
#line 4417 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 284:

/* Line 678 of lalr1.cc  */
#line 4429 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 285:

/* Line 678 of lalr1.cc  */
#line 4441 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 286:

/* Line 678 of lalr1.cc  */
#line 4453 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->SetBG((int)(yysemantic_stack_[(10) - (5)].adouble),(int)(yysemantic_stack_[(10) - (7)].adouble),(int)(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 4459 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Normalizes the 3D view based on the limits in space of the current objects
        **/
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->Normalize();
        }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 4468 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Centers the 3D view based on the limits in space of the current objects
        **/
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->Center();
        }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 4477 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 290:

/* Line 678 of lalr1.cc  */
#line 4490 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_StructureTensor(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                   (yysemantic_stack_[(8) - (3)].variable)->Name().c_str(),
                   (yysemantic_stack_[(8) - (5)].adouble), (yysemantic_stack_[(8) - (7)].adouble), NULL);
        }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 4497 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();

          Func_StructureTensor(
            ((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),
            (yysemantic_stack_[(10) - (3)].variable)->Name().c_str(),
            (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), mask);
          delete mask;
        }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 4508 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 293:

/* Line 678 of lalr1.cc  */
#line 4530 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 294:

/* Line 678 of lalr1.cc  */
#line 4556 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 295:

/* Line 678 of lalr1.cc  */
#line 4584 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_HessianMatrix(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(6) - (3)].variable)->Name().c_str(),
                 (yysemantic_stack_[(6) - (5)].adouble),   // sigma
                 0,   // gamma
                 NULL  // mask
                 );
        }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 4594 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 297:

/* Line 678 of lalr1.cc  */
#line 4607 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_HessianMatrix(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(8) - (3)].variable)->Name().c_str(),
                 (yysemantic_stack_[(8) - (5)].adouble),   // sigma
                 (yysemantic_stack_[(8) - (7)].adouble),   // gamma
                 NULL  // mask
                 );
        }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 4617 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 299:

/* Line 678 of lalr1.cc  */
#line 4639 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 300:

/* Line 678 of lalr1.cc  */
#line 4668 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 301:

/* Line 678 of lalr1.cc  */
#line 4686 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 302:

/* Line 678 of lalr1.cc  */
#line 4700 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_Curvatures(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
              (yysemantic_stack_[(6) - (3)].variable)->Name().c_str(),
              (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 4712 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 304:

/* Line 678 of lalr1.cc  */
#line 4733 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 305:

/* Line 678 of lalr1.cc  */
#line 4752 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 306:

/* Line 678 of lalr1.cc  */
#line 4769 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 307:

/* Line 678 of lalr1.cc  */
#line 4780 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get())->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 4785 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 4790 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im = *(InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer();
      (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetVoxelSize(
                                   im->VoxSizeX(),
                                   im->VoxSizeY(),
                                   im->VoxSizeZ());
    }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 4799 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->SetTranslation((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 4804 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im = *(InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer();
      (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetVoxelSize(
                                   im->TrX(),
                                   im->TrY(),
                                   im->TrZ());
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 4813 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 313:

/* Line 678 of lalr1.cc  */
#line 4827 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_DiscSecDerGrad(
        ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
        ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 4834 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_DiscSecDerGrad(
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (7)].variable)->Pointer())->get());
    }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 4840 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.aint)=1;}
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 4843 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 317:

/* Line 678 of lalr1.cc  */
#line 4860 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 318:

/* Line 678 of lalr1.cc  */
#line 4876 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 319:

/* Line 678 of lalr1.cc  */
#line 4915 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 320:

/* Line 678 of lalr1.cc  */
#line 4932 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 321:

/* Line 678 of lalr1.cc  */
#line 4972 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_GenRead((yysemantic_stack_[(4) - (3)].astring));
        }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 4977 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.InitCumul();
        }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 4982 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Debut();
        }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 4987 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Fin();
      cout << "time spent = " << driver.IP_time << endl;
        }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 4993 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description:
          Creates a new tab for controling parameters.
        Parameters:
          - identifier: name of the new ParamPanel
          - expr_string: title of the tab
       **/
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

  case 326:

/* Line 678 of lalr1.cc  */
#line 5017 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description:
        Ends a notebook.
    **/
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndBook();
    }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 5027 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 328:

/* Line 678 of lalr1.cc  */
#line 5042 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndPanel();
    }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 5048 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndPanel();
      pw->EndBox( );
    }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 5055 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndBox( );
    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 5061 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->BeginHorizontal( );
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 5067 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
        pw->EndHorizontal( );
        }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 5073 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          pw->CreeDialogue( );
        }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 5079 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 335:

/* Line 678 of lalr1.cc  */
#line 5094 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Hides the given parameter panel, the smart pointer copy is released
        **/
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

          GB_main_wxFrame->RemoveParamPanelPage(pw);
        }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 5105 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          pw->ReAfficheParametres();
        }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 5111 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 338:

/* Line 678 of lalr1.cc  */
#line 5125 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 339:

/* Line 678 of lalr1.cc  */
#line 5139 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 340:

/* Line 678 of lalr1.cc  */
#line 5156 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
          int n = pw->NbParameters();
            pw->ChangedValueCallback(n-1,(void*) CB_ParamWin, (void*) (yysemantic_stack_[(6) - (5)].variable) );
        }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 5166 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 342:

/* Line 678 of lalr1.cc  */
#line 5185 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 343:

/* Line 678 of lalr1.cc  */
#line 5203 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 344:

/* Line 678 of lalr1.cc  */
#line 5221 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 345:

/* Line 678 of lalr1.cc  */
#line 5241 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 346:

/* Line 678 of lalr1.cc  */
#line 5261 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 347:

/* Line 678 of lalr1.cc  */
#line 5281 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage::ptr   i = *(InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer();
          Func_VectorImage2StructuredGrid(i.get(),(yysemantic_stack_[(6) - (5)].astring));
          delete [] (yysemantic_stack_[(6) - (5)].astring);
        }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 5288 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(GLTransfMatrix_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->Print();
        }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 5293 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_SaveTransform(((GLTransfMatrix_ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())->get(),(yysemantic_stack_[(4) - (4)].astring));
          delete [] (yysemantic_stack_[(4) - (4)].astring);
        }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 5299 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapVTK();
        }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 5304 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapWII();
        }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 5309 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapFilters();
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 5320 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 354:

/* Line 678 of lalr1.cc  */
#line 5352 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 355:

/* Line 678 of lalr1.cc  */
#line 5376 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable*  var   = (yysemantic_stack_[(4) - (1)].variable);
          ParamList::ptr param((yysemantic_stack_[(4) - (3)].paramlist));
          ((void (*)(ParamList*)) var->Pointer())(param.get());
        }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 5383 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable*  var   = (yysemantic_stack_[(4) - (1)].variable);
          ParamList::ptr param((yysemantic_stack_[(4) - (3)].paramlist));
          (*(WrapClassMember::ptr*) var->Pointer())->CallProc(param.get());
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 5390 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5412 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = new std::list<std::string>();
            sl->push_back(string((yysemantic_stack_[(1) - (1)].astring)));
            delete [] (yysemantic_stack_[(1) - (1)].astring);
            (yyval.string_list) = sl;
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 5420 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = (yysemantic_stack_[(3) - (1)].string_list);
            sl->push_back(string((yysemantic_stack_[(3) - (3)].astring)));
            delete [] (yysemantic_stack_[(3) - (3)].astring);
            (yyval.string_list) = sl;
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 5436 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          (yyval.paramlist) = pl;
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 5441 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl(new ParamList);
          float_ptr* x = new float_ptr(new float((yysemantic_stack_[(1) - (1)].adouble)));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 5448 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);
          float_ptr* x= new float_ptr(new float((yysemantic_stack_[(3) - (3)].adouble)));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 5455 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5463 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5471 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5480 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          float_ptr*   x = new float_ptr(* ((float_ptr*)(yysemantic_stack_[(4) - (4)].variable)->Pointer()));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 5487 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          int_ptr*   x = new int_ptr(*((int_ptr*)(yysemantic_stack_[(2) - (2)].variable)->Pointer()));
          pl->AddParam(type_int, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 5494 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          int_ptr*   x = new int_ptr( *((int_ptr*)(yysemantic_stack_[(4) - (4)].variable)->Pointer()));
          pl->AddParam(type_int, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 5501 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          InrImage::ptr* i = new InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 5508 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(3) - (1)].paramlist);
          InrImage::ptr*   i = new InrImage::ptr( (InrImage*) driver.im_stack.GetLastImage());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 5515 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          InrImage::ptr*  i = new InrImage::ptr(*(InrImage::ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 5522 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          InrImage::ptr* i = new InrImage::ptr(*(InrImage::ptr*) (yysemantic_stack_[(4) - (4)].variable)->Pointer());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 5529 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          SurfacePoly::ptr*  s = new SurfacePoly::ptr(*(SurfacePoly::ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer());
          pl->AddParam(type_surface, s);
          (yyval.paramlist) = pl;
        }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 5536 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          SurfacePoly::ptr*  s = new SurfacePoly::ptr(*(SurfacePoly::ptr*) (yysemantic_stack_[(4) - (4)].variable)->Pointer());
          pl->AddParam(type_surface, s);
          (yyval.paramlist) = pl;
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 5543 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          DessinImage::ptr* i = new DessinImage::ptr(*(DessinImage::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer());
          pl->AddParam(type_imagedraw, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 5550 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(3) - (1)].paramlist);
          DessinImage::ptr*  i = new DessinImage::ptr(*(DessinImage::ptr*) (yysemantic_stack_[(3) - (3)].variable)->Pointer());
          pl->AddParam(type_imagedraw, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 5559 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      //      printf("no parameters \n");
      ParamListDecl* pl = new ParamListDecl;
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 5565 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5574 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_string);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 5581 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 5588 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 5595 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 5602 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_float);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 5609 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_string);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 5616 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 5623 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 5630 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 5638 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 5643 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5658 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
          //fflush(stdout);
        }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 5664 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5678 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5694 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5710 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 395:

/* Line 678 of lalr1.cc  */
#line 5726 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 396:

/* Line 678 of lalr1.cc  */
#line 5742 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 397:

/* Line 678 of lalr1.cc  */
#line 5765 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.astring)=(char*) (*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->Nom();
    }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 5769 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 399:

/* Line 678 of lalr1.cc  */
#line 5780 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 400:

/* Line 678 of lalr1.cc  */
#line 5799 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      char* res = new char[GB_scripts_dir.Len()+1];
      strcpy(res,(const char*)GB_scripts_dir.mb_str(wxConvUTF8));
      (yyval.astring)= res;
    }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 5810 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 403:

/* Line 678 of lalr1.cc  */
#line 5820 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          RemoveEndString((yysemantic_stack_[(3) - (1)].astring),(yysemantic_stack_[(3) - (3)].astring));
          (yyval.astring)=(yysemantic_stack_[(3) - (1)].astring);
        }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 5833 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        (yyval.ablock)=(yysemantic_stack_[(3) - (2)].ablock);
        if (GB_debug)
          cerr << format("ablock : %s")
                  % (yysemantic_stack_[(3) - (2)].ablock)->GetBody()
                << endl;
          }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 5847 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      returns the number of arguments in the command line
    **/
      (yyval.adouble)=GB_argc-GB_num_arg_parsed;
    }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 5855 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      Line number in the current script
    **/
      (yyval.adouble)=driver.yyiplineno;
    }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 5863 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        the constant Pi is set to
         3.14159265358979323846
      **/
      (yyval.adouble)= 3.14159265358979323846;
    }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 5872 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=*((float_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get();
    }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 5876 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = (float) *((int_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get();
    }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 5880 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = (float) *((uchar_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get();
    }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 5884 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(3) - (2)].adouble);
      fflush(stdout);
    }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 5893 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 418:

/* Line 678 of lalr1.cc  */
#line 5908 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 419:

/* Line 678 of lalr1.cc  */
#line 5924 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 420:

/* Line 678 of lalr1.cc  */
#line 5938 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 421:

/* Line 678 of lalr1.cc  */
#line 5953 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 422:

/* Line 678 of lalr1.cc  */
#line 5970 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 423:

/* Line 678 of lalr1.cc  */
#line 5986 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 424:

/* Line 678 of lalr1.cc  */
#line 6000 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 425:

/* Line 678 of lalr1.cc  */
#line 6013 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 426:

/* Line 678 of lalr1.cc  */
#line 6034 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 427:

/* Line 678 of lalr1.cc  */
#line 6094 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 428:

/* Line 678 of lalr1.cc  */
#line 6119 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 429:

/* Line 678 of lalr1.cc  */
#line 6141 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 430:

/* Line 678 of lalr1.cc  */
#line 6160 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

      (yyval.adouble) = s->GetNumberOfPoints();
    }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 6167 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

      (yyval.adouble) = s->GetNumberOfPolys();

    }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 6175 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_SNR(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 6180 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (yyval.adouble)=Func_eccentricity(((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());
        }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 6185 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 435:

/* Line 678 of lalr1.cc  */
#line 6213 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (yyval.adouble)=Func_ComputePositiveArea( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get() );
    }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 6219 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float val[4];

      val[0] = (yysemantic_stack_[(10) - (3)].adouble);
      val[1] = (yysemantic_stack_[(10) - (5)].adouble);
      val[2] = (yysemantic_stack_[(10) - (7)].adouble);
      val[3] = (yysemantic_stack_[(10) - (9)].adouble);
      (yyval.adouble)=Func_PositiveArea(val);
        }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 6230 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 438:

/* Line 678 of lalr1.cc  */
#line 6249 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 439:

/* Line 678 of lalr1.cc  */
#line 6268 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 440:

/* Line 678 of lalr1.cc  */
#line 6287 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 441:

/* Line 678 of lalr1.cc  */
#line 6306 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 442:

/* Line 678 of lalr1.cc  */
#line 6325 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 443:

/* Line 678 of lalr1.cc  */
#line 6344 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 444:

/* Line 678 of lalr1.cc  */
#line 6367 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 445:

/* Line 678 of lalr1.cc  */
#line 6389 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 446:

/* Line 678 of lalr1.cc  */
#line 6412 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();
          (yyval.adouble)=Func_med( ((InrImage::ptr*) (yysemantic_stack_[(9) - (6)].variable)->Pointer())->get(),(float) (yysemantic_stack_[(9) - (8)].adouble),mask);
          delete mask;
        }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 6419 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 448:

/* Line 678 of lalr1.cc  */
#line 6443 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 449:

/* Line 678 of lalr1.cc  */
#line 6466 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//    setlocale(LC_NUMERIC,"C");
      setlocale(LC_NUMERIC, "C");
      (yyval.adouble)=atof((yysemantic_stack_[(4) - (3)].astring));
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 6474 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._xmin;
        }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 6484 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._xmax;
        }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 6494 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._ymin;
        }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 6504 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._ymax;
        }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 6514 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._zmin;
        }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 6524 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._zmax;
        }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 6534 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 457:

/* Line 678 of lalr1.cc  */
#line 6548 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 458:

/* Line 678 of lalr1.cc  */
#line 6565 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 459:

/* Line 678 of lalr1.cc  */
#line 6581 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_AnisoGS_GetNoiseSD();
    }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 6586 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_AnisoGS_GetDAcoeff();
    }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 6591 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = Func_LevelSets_UpdateResult();
    }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 6595 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr mat = *(FloatMatrix::ptr*)(yysemantic_stack_[(6) - (1)].variable)->Pointer();
          int i = (int)(yysemantic_stack_[(6) - (3)].adouble);
          int j = (int)(yysemantic_stack_[(6) - (5)].adouble);
          (yyval.adouble) = (*mat)[i][j];
    }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 6602 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr mat = *(FloatMatrix::ptr*)(yysemantic_stack_[(8) - (1)].variable)->Pointer();
          int i = (int)(yysemantic_stack_[(8) - (3)].adouble);
          int j = (int)(yysemantic_stack_[(8) - (5)].adouble);
          (yyval.adouble)  =  ((*mat)[i][j] = (yysemantic_stack_[(8) - (8)].adouble));
    }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 6610 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 465:

/* Line 678 of lalr1.cc  */
#line 6645 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 466:

/* Line 678 of lalr1.cc  */
#line 6683 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 467:

/* Line 678 of lalr1.cc  */
#line 6700 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 468:

/* Line 678 of lalr1.cc  */
#line 6720 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 469:

/* Line 678 of lalr1.cc  */
#line 6732 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 470:

/* Line 678 of lalr1.cc  */
#line 6749 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 471:

/* Line 678 of lalr1.cc  */
#line 6769 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 472:

/* Line 678 of lalr1.cc  */
#line 6802 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 473:

/* Line 678 of lalr1.cc  */
#line 6821 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 474:

/* Line 678 of lalr1.cc  */
#line 6843 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 475:

/* Line 678 of lalr1.cc  */
#line 6859 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 476:

/* Line 678 of lalr1.cc  */
#line 6877 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 477:

/* Line 678 of lalr1.cc  */
#line 6901 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 478:

/* Line 678 of lalr1.cc  */
#line 6922 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 479:

/* Line 678 of lalr1.cc  */
#line 6950 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 480:

/* Line 678 of lalr1.cc  */
#line 6964 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    **/
      string_ptr label( new std::string((yysemantic_stack_[(6) - (5)].astring)));
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      int id = pw->AddPage( label->c_str());
      (yyval.adouble)=id;
    }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 6974 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 482:

/* Line 678 of lalr1.cc  */
#line 6987 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 483:

/* Line 678 of lalr1.cc  */
#line 7001 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 484:

/* Line 678 of lalr1.cc  */
#line 7016 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
    Check for the existence of a variable, returns 0
    **/
          (yyval.adouble)=0;
    }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 7024 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description: 
    Check for the existence of a variable, returns 1
    **/
          (yyval.adouble)=1;
    }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 7032 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 487:

/* Line 678 of lalr1.cc  */
#line 7044 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble) = (int) (yysemantic_stack_[(1) - (1)].aint);
    }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 7048 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 489:

/* Line 678 of lalr1.cc  */
#line 7063 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       float*  var = ((float_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get();
        FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
        setlocale(LC_NUMERIC, "C");
        (yyval.adouble) = fscanf(file.get(),"%f",var);
    }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 7070 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 491:

/* Line 678 of lalr1.cc  */
#line 7080 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 492:

/* Line 678 of lalr1.cc  */
#line 7092 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 494:

/* Line 678 of lalr1.cc  */
#line 7105 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(2) - (2)].adouble); }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 7106 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(!,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 7107 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(-,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 7108 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(+,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 7109 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(sin,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 7110 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(cos,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 7111 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(sqrt,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 7112 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(fabs,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 7113 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(round,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 7115 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:
                return the closest integer smaller than the given expression value.
           **/
          UNARYOP_EXPR(floor,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble))
        }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 7122 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(tan,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 7123 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(asin,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 7124 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(acos,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 7125 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(atan,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 7127 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 509:

/* Line 678 of lalr1.cc  */
#line 7139 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 510:

/* Line 678 of lalr1.cc  */
#line 7151 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 514:

/* Line 678 of lalr1.cc  */
#line 7174 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 516:

/* Line 678 of lalr1.cc  */
#line 7190 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)*(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 7191 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)/(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 7192 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)= ((int) round((yysemantic_stack_[(3) - (1)].adouble))) % ((int) round((yysemantic_stack_[(3) - (3)].adouble))); }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 7197 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)+(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 7198 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)-(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 7208 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)<(yysemantic_stack_[(3) - (3)].adouble));  }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 7209 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)>(yysemantic_stack_[(3) - (3)].adouble));  }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 7210 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)<=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 7211 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)>=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 7216 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)==(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 7217 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)!=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 7218 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(strcmp((yysemantic_stack_[(3) - (1)].astring),(yysemantic_stack_[(3) - (3)].astring))==0); }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 7219 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(strcmp((yysemantic_stack_[(3) - (1)].astring),(yysemantic_stack_[(3) - (3)].astring))!=0); }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 7225 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = ((int)(yysemantic_stack_[(3) - (1)].adouble)) & ((int)(yysemantic_stack_[(3) - (3)].adouble));
    }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 7238 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
        }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 7242 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = ((int)(yysemantic_stack_[(3) - (1)].adouble)) | ((int)(yysemantic_stack_[(3) - (3)].adouble));
        }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 7249 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
        }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 7253 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)&&(yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 7260 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
    }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 7264 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)||(yysemantic_stack_[(3) - (3)].adouble);
    }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 7272 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=((yysemantic_stack_[(5) - (1)].adouble)?(yysemantic_stack_[(5) - (3)].adouble):(yysemantic_stack_[(5) - (5)].adouble));
        }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 7289 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.err_print(" char format is not available: use unsigned char \n");
      (yyval.aint)=WT_UNSIGNED_CHAR;
    }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 7294 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.aint)=WT_UNSIGNED_CHAR;
       }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 7298 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_SHORT;
       }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 7302 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_SHORT;
       }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 7306 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_INT;
       }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 7310 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_INT;
       }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 7314 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT;
       }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 7318 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_DOUBLE;
       }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 7322 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_RGB;
       }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 7326 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT_VECTOR;
       }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 7330 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//        printf("format %d \n",(int) ( *(InrImage::ptr*) $1->Pointer())->GetFormat());
        (yyval.aint) = (int) (*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetFormat();
      }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 7338 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yysemantic_stack_[(1) - (1)].variable);
        }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 7343 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 560:

/* Line 678 of lalr1.cc  */
#line 7360 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     driver.im_stack.AddImage((yysemantic_stack_[(2) - (2)].astring));
     delete [] (yysemantic_stack_[(2) - (2)].astring);
       }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 7366 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     driver.im_stack.AddImage((yysemantic_stack_[(4) - (3)].astring));
     delete [] (yysemantic_stack_[(4) - (3)].astring);
       }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 7373 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 563:

/* Line 678 of lalr1.cc  */
#line 7431 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 564:

/* Line 678 of lalr1.cc  */
#line 7485 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 565:

/* Line 678 of lalr1.cc  */
#line 7540 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 566:

/* Line 678 of lalr1.cc  */
#line 7561 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 567:

/* Line 678 of lalr1.cc  */
#line 7582 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 568:

/* Line 678 of lalr1.cc  */
#line 7596 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 569:

/* Line 678 of lalr1.cc  */
#line 7625 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage* im;
        //printf(" ********** %d %f %f %f\n", $3, $5, $7, $9);
        im = new InrImage( (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble), (WORDTYPE) (yysemantic_stack_[(10) - (3)].aint));
        driver.im_stack.AddImage(im);
      }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 7633 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 571:

/* Line 678 of lalr1.cc  */
#line 7652 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 572:

/* Line 678 of lalr1.cc  */
#line 7678 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 573:

/* Line 678 of lalr1.cc  */
#line 7691 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 574:

/* Line 678 of lalr1.cc  */
#line 7769 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 575:

/* Line 678 of lalr1.cc  */
#line 7836 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im  = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res =Func_localmean( im, (int) (yysemantic_stack_[(6) - (5)].adouble));
      driver.im_stack.AddImage(res);
      delete im;
    }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 7844 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im  = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res =Func_localmean2( im, (int) (yysemantic_stack_[(6) - (5)].adouble));
      driver.im_stack.AddImage(res);
      delete im;
      }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 7852 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage* mean    = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* im      = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* res     = Func_localSD( im, mean, (int) (yysemantic_stack_[(8) - (7)].adouble));
    driver.im_stack.AddImage(res);
    delete im;
    delete mean;
      }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 7862 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage* mean    = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* im      = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* res     = Func_localSD2( im, mean, (int) (yysemantic_stack_[(8) - (7)].adouble));
    driver.im_stack.AddImage(res);
    delete im;
    delete mean;
      }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 7872 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 580:

/* Line 678 of lalr1.cc  */
#line 7902 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 581:

/* Line 678 of lalr1.cc  */
#line 7920 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 582:

/* Line 678 of lalr1.cc  */
#line 7940 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 583:

/* Line 678 of lalr1.cc  */
#line 7958 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 584:

/* Line 678 of lalr1.cc  */
#line 7978 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 585:

/* Line 678 of lalr1.cc  */
#line 7997 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 586:

/* Line 678 of lalr1.cc  */
#line 8018 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 587:

/* Line 678 of lalr1.cc  */
#line 8055 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 588:

/* Line 678 of lalr1.cc  */
#line 8070 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 589:

/* Line 678 of lalr1.cc  */
#line 8084 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 590:

/* Line 678 of lalr1.cc  */
#line 8100 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 591:

/* Line 678 of lalr1.cc  */
#line 8123 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 592:

/* Line 678 of lalr1.cc  */
#line 8137 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 593:

/* Line 678 of lalr1.cc  */
#line 8151 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 594:

/* Line 678 of lalr1.cc  */
#line 8165 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 595:

/* Line 678 of lalr1.cc  */
#line 8179 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 596:

/* Line 678 of lalr1.cc  */
#line 8214 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 597:

/* Line 678 of lalr1.cc  */
#line 8229 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 598:

/* Line 678 of lalr1.cc  */
#line 8250 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 599:

/* Line 678 of lalr1.cc  */
#line 8271 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 600:

/* Line 678 of lalr1.cc  */
#line 8312 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 601:

/* Line 678 of lalr1.cc  */
#line 8357 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 602:

/* Line 678 of lalr1.cc  */
#line 8374 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 603:

/* Line 678 of lalr1.cc  */
#line 8393 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 604:

/* Line 678 of lalr1.cc  */
#line 8407 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 605:

/* Line 678 of lalr1.cc  */
#line 8421 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 606:

/* Line 678 of lalr1.cc  */
#line 8437 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 607:

/* Line 678 of lalr1.cc  */
#line 8455 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 608:

/* Line 678 of lalr1.cc  */
#line 8470 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 609:

/* Line 678 of lalr1.cc  */
#line 8486 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 610:

/* Line 678 of lalr1.cc  */
#line 8501 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 611:

/* Line 678 of lalr1.cc  */
#line 8524 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 612:

/* Line 678 of lalr1.cc  */
#line 8541 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 613:

/* Line 678 of lalr1.cc  */
#line 8555 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

          InrImage* res;
          InrImage* im = (InrImage*) driver.im_stack.GetLastImage();

        res = Func_AutoCrop(im,(int)(yysemantic_stack_[(6) - (5)].adouble));

        driver.im_stack.AddImage(res);
        delete im;
    }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 8567 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 615:

/* Line 678 of lalr1.cc  */
#line 8599 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 616:

/* Line 678 of lalr1.cc  */
#line 8619 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 617:

/* Line 678 of lalr1.cc  */
#line 8661 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 618:

/* Line 678 of lalr1.cc  */
#line 8673 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 619:

/* Line 678 of lalr1.cc  */
#line 8684 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 620:

/* Line 678 of lalr1.cc  */
#line 8697 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 621:

/* Line 678 of lalr1.cc  */
#line 8709 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 622:

/* Line 678 of lalr1.cc  */
#line 8720 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 623:

/* Line 678 of lalr1.cc  */
#line 8748 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 624:

/* Line 678 of lalr1.cc  */
#line 8775 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 625:

/* Line 678 of lalr1.cc  */
#line 8807 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 626:

/* Line 678 of lalr1.cc  */
#line 8823 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 627:

/* Line 678 of lalr1.cc  */
#line 8840 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_AnisoGS_GetOutput();

    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 8853 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_AnisoGS_GetDiffusionCoeff();

    Si res==NULL Alors
      fprintf(stderr,"GetDiffCoeff() erreur ... \n");
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 8866 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 630:

/* Line 678 of lalr1.cc  */
#line 8886 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 631:

/* Line 678 of lalr1.cc  */
#line 8909 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

    InrImage*  res;

    res = Func_LevelSets_GetCurrentOutput();

    Si res==NULL Alors
      fprintf(stderr,"Func_LevelSets_GetOutput() error ... \n");
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 8923 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 633:

/* Line 678 of lalr1.cc  */
#line 8940 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 634:

/* Line 678 of lalr1.cc  */
#line 8973 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 635:

/* Line 678 of lalr1.cc  */
#line 9011 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 636:

/* Line 678 of lalr1.cc  */
#line 9046 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 637:

/* Line 678 of lalr1.cc  */
#line 9079 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 638:

/* Line 678 of lalr1.cc  */
#line 9096 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 639:

/* Line 678 of lalr1.cc  */
#line 9111 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 640:

/* Line 678 of lalr1.cc  */
#line 9127 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 641:

/* Line 678 of lalr1.cc  */
#line 9147 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 642:

/* Line 678 of lalr1.cc  */
#line 9170 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 643:

/* Line 678 of lalr1.cc  */
#line 9194 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 644:

/* Line 678 of lalr1.cc  */
#line 9220 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 645:

/* Line 678 of lalr1.cc  */
#line 9243 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 646:

/* Line 678 of lalr1.cc  */
#line 9265 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 647:

/* Line 678 of lalr1.cc  */
#line 9288 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 648:

/* Line 678 of lalr1.cc  */
#line 9312 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 649:

/* Line 678 of lalr1.cc  */
#line 9356 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 650:

/* Line 678 of lalr1.cc  */
#line 9380 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 651:

/* Line 678 of lalr1.cc  */
#line 9411 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 652:

/* Line 678 of lalr1.cc  */
#line 9433 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 653:

/* Line 678 of lalr1.cc  */
#line 9470 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 654:

/* Line 678 of lalr1.cc  */
#line 9507 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 655:

/* Line 678 of lalr1.cc  */
#line 9544 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 656:

/* Line 678 of lalr1.cc  */
#line 9579 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          driver.im_stack.AddImage((*(Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetCanvas()->GetGLImage());
        }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 9584 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          fprintf(stderr,"not available in new wxwidgets version of the 3D viewer ! \n");
          driver.im_stack.AddImage((InrImage*)NULL);
/*
          driver.im_stack.AddImage((*(Viewer3D_ptr*) $1->Pointer())->GetInrImage());
*/
    }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 9593 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.im_stack.AddImage((*(DessinImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetInrImage());
    }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 9598 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

    InrImage*    res;

      res = Func_ThresholdCrossing( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

          driver.im_stack.AddImage(res);

    }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 9609 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*    res;

      res = Func_IsocontourPoints( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

      driver.im_stack.AddImage(res);

    }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 9619 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*    res;

      res = Func_IsosurfDist( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

          driver.im_stack.AddImage(res);

    }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 9629 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*    res;

      res = Func_vtkIsoContourDist( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

          driver.im_stack.AddImage(res);
    }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 9638 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 664:

/* Line 678 of lalr1.cc  */
#line 9661 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 665:

/* Line 678 of lalr1.cc  */
#line 9690 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 666:

/* Line 678 of lalr1.cc  */
#line 9716 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 667:

/* Line 678 of lalr1.cc  */
#line 9747 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 668:

/* Line 678 of lalr1.cc  */
#line 9777 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      InrImage* res;
      res = Func_Convolve(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                  ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());

          driver.im_stack.AddImage(res);

        }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 9788 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 670:

/* Line 678 of lalr1.cc  */
#line 9804 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
      res = Func_Chamfer(((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));

          driver.im_stack.AddImage(res);

        }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 9814 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
      res = Func_Chamfer2(((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));

          driver.im_stack.AddImage(res);

        }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 9824 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 673:

/* Line 678 of lalr1.cc  */
#line 9839 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_Chamfer2(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                  0.92644, 1.34065, 1.65849,
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

      res = Func_Chamfer2Signed(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                    0.92644, 1.34065, 1.65849,
                    dmax);

          driver.im_stack.AddImage(res);

        }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 9867 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_vtkSignedBorgefors(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                    dmax);

          driver.im_stack.AddImage(res);

        }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 9880 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_vtkSignedFMDist(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                     dmax);

          driver.im_stack.AddImage(res);

        }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 9893 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_PropagationDistance(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                      dmax);

          driver.im_stack.AddImage(res);
        }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 9905 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_PropagationDistance2(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                      dmax);

          driver.im_stack.AddImage(res);
        }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 9917 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_PropagationDanielsson(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                       dmax);

          driver.im_stack.AddImage(res);
        }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 9929 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_vtkPropDanielsson(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                       -dmax,dmax);
          driver.im_stack.AddImage(res);
        }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 9940 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmin = (yysemantic_stack_[(8) - (5)].adouble);
        float dmax = (yysemantic_stack_[(8) - (7)].adouble);

      res = Func_vtkPropDanielsson(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                       dmin,dmax);

          driver.im_stack.AddImage(res);
        }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 9953 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 683:

/* Line 678 of lalr1.cc  */
#line 9980 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 684:

/* Line 678 of lalr1.cc  */
#line 10013 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 685:

/* Line 678 of lalr1.cc  */
#line 10129 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 686:

/* Line 678 of lalr1.cc  */
#line 10153 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 687:

/* Line 678 of lalr1.cc  */
#line 10195 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 688:

/* Line 678 of lalr1.cc  */
#line 10207 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* res;
      int dim = (int) (yysemantic_stack_[(6) - (5)].adouble);

      InrImage::ptr im = InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
      res = Func_MeanHalfSize(im.get(),dim);
      if (res!=NULL) driver.im_stack.AddImage(res);
    }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 10216 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage* res;
        int axis=(int) (yysemantic_stack_[(6) - (5)].adouble);

        InrImage::ptr im = InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
        res=Func_Flip(im,axis);
        driver.im_stack.AddImage(res);
    }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 10225 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 691:

/* Line 678 of lalr1.cc  */
#line 10248 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 692:

/* Line 678 of lalr1.cc  */
#line 10273 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 693:

/* Line 678 of lalr1.cc  */
#line 10286 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(5) - (1)].variable)->Pointer());


      res = s->GetImageLinesLength(  );

      if (res!=NULL) driver.im_stack.AddImage(res);
    }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 10296 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 695:

/* Line 678 of lalr1.cc  */
#line 10333 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 696:

/* Line 678 of lalr1.cc  */
#line 10351 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 697:

/* Line 678 of lalr1.cc  */
#line 10369 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());


      res = s->GetIntensities( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

      if (res!=NULL) driver.im_stack.AddImage(res);
        }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 10379 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;

      res = AMIFluid::Func_Altitude2Position(im,(int)(yysemantic_stack_[(6) - (5)].adouble));
      if (res!=NULL) driver.im_stack.AddImage(res);

      delete im;
    }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 10389 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_Altitude2Position(im);
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
    }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 10397 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im,(int)(yysemantic_stack_[(6) - (5)].adouble));
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
    }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 10405 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im);
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
    }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 10413 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 703:

/* Line 678 of lalr1.cc  */
#line 10438 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 704:

/* Line 678 of lalr1.cc  */
#line 10458 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* res;
      res= AMIFluid::Func_ReadFlow((char*)(yysemantic_stack_[(4) - (3)].astring));
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 10466 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 706:

/* Line 678 of lalr1.cc  */
#line 10500 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 707:

/* Line 678 of lalr1.cc  */
#line 10523 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 713:

/* Line 678 of lalr1.cc  */
#line 10548 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(-)               }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 10550 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sin)             }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 10551 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(cos)             }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 10552 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sqrt)            }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 10553 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(fabs)            }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 10554 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(round)           }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 10555 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(floor)           }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 10556 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(tan)             }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 10557 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(asin)            }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 10558 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(acos)            }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 10559 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(atan)            }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 10560 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(exp)             }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 10561 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(1.0/log(10.0)*log) }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 10562 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(log)             }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 10564 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 730:

/* Line 678 of lalr1.cc  */
#line 10579 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 732:

/* Line 678 of lalr1.cc  */
#line 10601 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(*,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 10607 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(/,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 10609 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  IMAGE_OP_IMAGE_2(*)   }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 10610 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(/)   }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 10611 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(^)   }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 10620 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(+,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 10621 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(-,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 10622 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(+)   }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 10623 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(-)   }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 10631 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<)    }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 10632 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>)    }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 10633 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<=)   }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 10634 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>=)   }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 10635 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<, (yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 10636 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>, (yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 10637 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<=,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 10638 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>=,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 10643 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(==)   }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 10644 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(!=)   }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 10645 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(==,(yysemantic_stack_[(3) - (3)].adouble))   }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 10646 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(!=,(yysemantic_stack_[(3) - (3)].adouble))   }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 10688 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         GLTransfMatrix* newglt;
         GLTransfMatrix_ptr glt = *(GLTransfMatrix_ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

         newglt = new GLTransfMatrix();
         (*newglt) = (*glt);
         driver.gltransf_stack.AddMatrix(newglt);

           }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 10699 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 774:

/* Line 678 of lalr1.cc  */
#line 10712 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         GLTransfMatrix* newglt = NULL;
         GLTransfMatrix_ptr glt1 = *(GLTransfMatrix_ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer();
         GLTransfMatrix_ptr glt2 = *(GLTransfMatrix_ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer();
         float coeff = (yysemantic_stack_[(8) - (7)].adouble);

         newglt = Func_InterpolateTransform(glt1.get(),glt2.get(),coeff);
         driver.gltransf_stack.AddMatrix(newglt);
       }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 10723 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 776:

/* Line 678 of lalr1.cc  */
#line 10740 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         FloatMatrix* m;
         m = new FloatMatrix((int)(yysemantic_stack_[(6) - (3)].adouble),(int)(yysemantic_stack_[(6) - (5)].adouble));
         driver.matrix_stack.AddMatrix(m);
       }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 10747 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      FloatMatrix* newmat;
      FloatMatrix::ptr mat = *(FloatMatrix::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

      newmat = new FloatMatrix( (*mat));

          driver.matrix_stack.AddMatrix(newmat);
       }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 10757 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 784:

/* Line 678 of lalr1.cc  */
#line 10777 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(-)               }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 10780 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix* mat;
          FloatMatrix* res;
          mat=driver.matrix_stack.GetLastMatrix();
          res = mat->Transpose();
          delete mat;
          driver.matrix_stack.AddMatrix(res);
        }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 10788 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sin)             }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 10789 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(cos)             }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 10790 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sqrt)            }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 10791 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(fabs)            }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 10792 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(round)           }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 10793 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(floor)           }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 10794 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(tan)             }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 10795 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(asin)            }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 10796 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(acos)            }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 10797 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(atan)            }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 10798 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(exp)             }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 10799 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(1.0/log(10.0)*log) }
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 10800 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(log)             }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 10807 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(*,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 10808 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(*)   }
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 10810 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         FloatMatrix* m2 = driver.matrix_stack.GetLastMatrix();
         FloatMatrix* m1 = driver.matrix_stack.GetLastMatrix();
             FloatMatrix* res = Multiply(m1, m2) ;
         driver.matrix_stack.AddMatrix(res);
         delete m1;
         delete m2;
           }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 10820 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(+,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 10821 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(-,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 10822 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(+)   }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 10823 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(-)   }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 10872 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yysemantic_stack_[(1) - (1)].variable);
        }
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 10877 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 823:

/* Line 678 of lalr1.cc  */
#line 10893 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 824:

/* Line 678 of lalr1.cc  */
#line 10904 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        SurfacePoly* surf;
        surf = Func_isosurf((*(InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer()),
                (yysemantic_stack_[(6) - (5)].adouble),
                NULL,
                2);
        driver.surf_stack.AddSurf(surf);
    }
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 10914 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 826:

/* Line 678 of lalr1.cc  */
#line 10934 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 827:

/* Line 678 of lalr1.cc  */
#line 10968 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_decimate(((SurfacePoly::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 10977 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_decimate(((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble) );
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 10986 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_vtkMarchingCubes(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),(yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 10995 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_vtkSmooth(((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 11004 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        SurfacePoly* surf;
        surf = Func_vtkWindowedSinc(((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
        if (surf==NULL) driver.err_print("vtkWindowedSinc failed!");
        driver.surf_stack.AddSurf(surf);
    }
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 11012 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf = new SurfacePoly();
      driver.surf_stack.AddSurf(surf);
    }
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 11018 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.surf_stack.AddSurf((yysemantic_stack_[(2) - (2)].astring));
      delete [] (yysemantic_stack_[(2) - (2)].astring);
    }
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 11024 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.surf_stack.AddSurf((yysemantic_stack_[(4) - (3)].astring));
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 11030 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 836:

/* Line 678 of lalr1.cc  */
#line 11056 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 837:

/* Line 678 of lalr1.cc  */
#line 11070 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 838:

/* Line 678 of lalr1.cc  */
#line 11086 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* newsurf;
      SurfacePoly::ptr surf = *(SurfacePoly::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

      newsurf = new SurfacePoly( (*surf) );

          driver.surf_stack.AddSurf(newsurf);
      }
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 11096 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 840:

/* Line 678 of lalr1.cc  */
#line 11114 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 841:

/* Line 678 of lalr1.cc  */
#line 11142 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 842:

/* Line 678 of lalr1.cc  */
#line 11169 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 843:

/* Line 678 of lalr1.cc  */
#line 11185 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 844:

/* Line 678 of lalr1.cc  */
#line 11208 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 845:

/* Line 678 of lalr1.cc  */
#line 11241 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 846:

/* Line 678 of lalr1.cc  */
#line 11277 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 847:

/* Line 678 of lalr1.cc  */
#line 11323 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 848:

/* Line 678 of lalr1.cc  */
#line 11361 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 849:

/* Line 678 of lalr1.cc  */
#line 11385 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr im = InrImage::ptr(driver.im_stack.GetLastImage());
      SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 11395 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 851:

/* Line 678 of lalr1.cc  */
#line 11418 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 852:

/* Line 678 of lalr1.cc  */
#line 11430 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 853:

/* Line 678 of lalr1.cc  */
#line 11443 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 854:

/* Line 678 of lalr1.cc  */
#line 11480 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 855:

/* Line 678 of lalr1.cc  */
#line 11523 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 856:

/* Line 678 of lalr1.cc  */
#line 11571 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 857:

/* Line 678 of lalr1.cc  */
#line 11623 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 858:

/* Line 678 of lalr1.cc  */
#line 11666 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 859:

/* Line 678 of lalr1.cc  */
#line 11694 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 860:

/* Line 678 of lalr1.cc  */
#line 11727 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 865:

/* Line 678 of lalr1.cc  */
#line 11777 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yysemantic_stack_[(1) - (1)].variable);
        }
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 11802 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent<float>* extent=new ImageExtent<float>( (float)(yysemantic_stack_[(11) - (1)].adouble),(float)(yysemantic_stack_[(11) - (3)].adouble),(float)(yysemantic_stack_[(11) - (5)].adouble),
                              (float)(yysemantic_stack_[(11) - (7)].adouble),(float)(yysemantic_stack_[(11) - (9)].adouble),(float)(yysemantic_stack_[(11) - (11)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        }
    break;

  case 884:

/* Line 678 of lalr1.cc  */
#line 11810 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent<float>* extent=new ImageExtent<float>((float)(yysemantic_stack_[(7) - (1)].adouble),(float)(yysemantic_stack_[(7) - (3)].adouble),(float)(yysemantic_stack_[(7) - (5)].adouble),(float)(yysemantic_stack_[(7) - (7)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        }
    break;

  case 885:

/* Line 678 of lalr1.cc  */
#line 11817 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 886:

/* Line 678 of lalr1.cc  */
#line 11833 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 14882 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
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
  const short int Parser::yypact_ninf_ = -2802;
  const short int
  Parser::yypact_[] =
  {
     14452, -2802,  8289,  3937,  3937,  3456, -2802, -2802, -2802, -2802,
   -2802,    37,    42,   128, -2802, -2802, -2802, -2802,   -39,   328,
   -2802,    -1,  3456,  5635,   784,   211,   249,   784, -2802,   259,
     272, -2802, -2802, -2802, -2802,    23,   120,   126,    26,    40,
   -2802,   245,    63,    61, -2802,   288,   302, -2802,   304,   210,
    -142,   307,   310,    29,   319,  1548,   784, -2802, -2802, -2802,
   -2802,   330,   354,   359,   125,   376,   331,   344,   394,   396,
   -2802, -2802, -2802, -2802,   406,   414,   434,   436,   447,   391,
     472,   492,   531,   535,   620,   632,   634,   706,   719,   731,
     736,   753,   773,   801,   824,   831, -2802, -2802, -2802, -2802,
   -2802, -2802, -2802, -2802, -2802, -2802,   835,   840,   844, -2802,
   -2802,  3937,  3937,  3937,  3937,  3937,  3937,  3937,  3937,  3937,
    3937,  3937,  3937,  3937,   210, -2802, -2802,  5635,   291,   784,
     848,   852,   868,    76,   210,   887,   926,   933,   966, -2802,
   -2802, -2802,   971,   989, -2802,   560,  9907, -2802, -2802, -2802,
   -2802, -2802, -2802, -2802,    70,   615, -2802,   279,   252, -2802,
   -2802, -2802,  3937, -2802,  1087,   558, -2802,    46,   430,   860,
     836,   964,   640,    27, -2802, -2802, -2802, -2802,    56, -2802,
   -2802, -2802, -2802,   863,    25,   654, -2802, -2802, -2802, -2802,
   -2802, -2802, -2802, -2802, -2802, -2802, -2802,    64,    11,   979,
    8289,  8289,  5635, -2802, -2802, -2802,  1041, -2802,  1060,  1056,
    -142,  1058,  1074,  1081,  1079,  1084,  8289,  8289,  8289,  8289,
    8289,  8289,  8289,  8289,  8289,  8289,  8289,  8289,  8289,  8289,
   -2802,   186,  1090,  1060, -2802,   863, -2802,   863, -2802,  1105,
    1106,   362,  1107,   784,  5635,   784, -2802, -2802, -2802, -2802,
   -2802, -2802, -2802, -2802, -2802, -2802,   252, -2802, -2802,   252,
   -2802, -2802,  1103,   784,   784, -2802,  1579,  1579, -2802, -2802,
    5635, -2802, -2802,  5635, -2802, -2802,  5635,   784,  1258,   823,
     115,   115,  5635,  3456,   -22,   677, 11509, 11509, 11509, -2802,
   -2802, -2802,   813,   -14,  5635,   780,  5635, -2802, -2802, -2802,
   -2802, -2802, -2802, -2802, -2802, -2802, -2802, -2802, -2802, -2802,
   -2802, -2802, -2802,  1113,  1081, -2802, -2802, -2802,  5635,  5635,
   15724, 12531, 15724, 15724, 15724, 15724, 15724, 15724,    -1,   438,
    1506,   454,   456,    -1,    -1, 15724, 15724,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1075,  1076,  5635,  5635,    -1,
    5635,  5635,   121,   784, 15724,    -1, -2802,   863, -2802,   863,
   -2802,   863, -2802,   863, -2802,   863, -2802,   863, -2802,   863,
   -2802,   863, -2802,   863, -2802,   863, -2802,   863, -2802,   863,
   -2802,   863,  -118, -2802,  1077, -2802, -2802,    70, -2802,   972,
     784,  1080, -2802, -2802, -2802,  5635,   784,  1068,    -1,    -1,
      -1, -2802, -2802, -2802, -2802, -2802, -2802, -2802, -2802, -2802,
      70, -2802,  5635,   784,   784,   784,   784, -2802,   863,  8289,
    8289,  8289,  8289,  8289,  8289,  8289,  8289,  8289,  8289,  8289,
    5635,  5635,  5635,  5635,  5635,  5635,  5635,  5635,   133, 15724,
   15724, 12531, -2802,  3937,   121,  3937,  3937,  1153,   -31, 15347,
   10483,  1052,   419,   295,   845,  5635,  5635,   586,   957,  5635,
      44,  -150, -2802,  9097,     3, -2802,  1116,  1123,  1124,  1102,
    1140,  1135, -2802,  1142,  1143, -2802, -2802, -2802, -2802,  1145,
    1146,  1147,  1148,  1149,  1150, -2802, -2802, -2802, -2802, -2802,
   -2802, -2802, -2802, -2802,  1151,  1152,  1154, -2802,  1155,  1156,
    1157,  1158, -2802,  1159,  1161,  1166,  1168,  1169,  1170,  1171,
    1173,  1174,  1183,  1184,  1185,  1186,  1187,  1189, -2802,  1190,
    1192,  1193,  1194, -2802, -2802,  1195, -2802,  1196, -2802,  1211,
    1213,  1214,  1219,  1220, -2802, -2802,  1216, -2802, -2802,  5635,
     784, -2802,  1224,  1226, -2802,  1227, 13471, 13471, 12531,   506,
     805,  1228,  1223,  1225,  1230,   455,  1233,  1234,  1235,  1236,
    1239,  1240,  1241,  1244,  1245,  1246,  1247,  1249,  1250,   398,
    1251,  1252,  1254,  1257,  1256,  1263,  1265,  1266,  1261,  1262,
    1269,  1270,  1271,  1272,  1273,  1274,  1275,  1276,  1277,  1279,
    1280,  1281,  1282,  1283,  1284,  1285,  1286,  1288,  1292,  1293,
    1294,  1295,  1303,  1305,  1306,  1307,  1308,  1309,  1310,  1311,
    1312,  1313,  1329,  1330,  1331,  1332,  1333,  1341,  1342,  1343,
    1344,  1345,  1348,  1350,  1351,  1352,  1353,  1354,  1355,  1356,
    1357,  1358,  1359,  1360,  1361,  1362,  1363,  1364,  1365, 13471,
   13471, 13471, 13471, 13471, 13471, 13471, 13471, 13471, 13471, 13471,
   13471, 13471, 15724,  1366,  1368,  1370,  1371,  1372,  1373,  1385,
    1374,  1378,  1379,  1394,  1401,   404,   252, 13471, -2802,   320,
   -2802, -2802, -2802,  1021, -2802,   516, -2802,   875, -2802,    58,
     815,  1406, -2802,  1411,  1287,    35, -2802, -2802, -2802,  1414,
     428,   449, -2802,  1422, -2802,  1423, -2802, -2802, -2802,  1424,
    1425,  1426,  1427, -2802, -2802,  1428,  1429,  1430,  1431,  1433,
    1434,  1435,  1437,  1438,  1439,  1440,  1441,  1442, -2802, -2802,
   -2802, -2802,  1443,  1445,  1447,  1448, -2802,   784,  1449,  1453,
    1454,  5635,  1455,  1451, 15724, 15724, 14933,  1444,  1459,   452,
    1456, 15724, 15724, 15724, 15724, 15724, 15724, 15724, 15724, 15724,
   15724, 15724, 15724, 15724, 15724,   489,  1460,  1458,  1223,  1461,
    1464,  1457,  1465,  1466,  1467,  1468,  1469,  1470,  1471,  1473,
    1474, -2802, -2802,  1475,  1476, -2802, -2802,  1478,  1480,  1484,
    1485,  1486,  1487,  1488,  1489, -2802,  1490,  1491,  1494,  1495,
    1496,  1497,  1503,  1504,  1505,  1507,  1508,  1509,  1510,  1511,
    1512,  1518,  1522,  1523,  1524,  1525,  1541,  1557,  1558,  1559,
    1560,  1561,  1564,  1565,  1566, -2802, -2802, -2802, -2802, -2802,
   -2802,  1499,  1567,    82,  1568,  1569,  1563,  1570,  1584,  1607,
    1608,  1609,  1610,  1611,  1612,  1613,  1572,  1573,  1614,  1615,
     413,  1638,   121,   121,   121, -2802,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
    1574,  1575,  1639,  1646,  5635,   784, -2802,   -10, -2802,  1647,
    1648,  1649,  1651,  1571,  1658,    70,  1673,  1701,  1696,  1697,
    1698,  1699, -2802,   252, -2802, -2802, -2802, -2802, -2802, -2802,
   -2802, -2802,  1087,  1087, -2802, -2802, -2802, -2802,    46,    46,
     430,   860,   836,   964,    13,   640,   342,  1704,  1708, -2802,
    1709, -2802, -2802,   784, -2802,  1710,  1711,  1712,  1713,  1714,
    1715,  1716,  1721,  1722, -2802, -2802, -2802, -2802, -2802, -2802,
   -2802,   863,   863,  1087,    25,  1087,    25, -2802, -2802, -2802,
     784,  1723,  1724, -2802,   784, -2802,  1725, -2802,  1726,  1727,
    1728,  1729,  1730,  1731,  1732,  1733,  1734,  1735,  1736,  1737,
    1738,  1739,  1740,  1741, -2802,  1742, -2802,  1743, -2802, -2802,
    1744,  1745,  1746,  1748,  1749, -2802, -2802,  1750,  1751,  1752,
    1753,  1754,  1755,  1756,  1758,  1759,  1760,  1761,  1762,  1763,
    1767,  1769,  1770,  1771,   950,  1772,  1773,  1774,  1775,  1776,
    1777, -2802,  1778, -2802, 13001, 13001, 10998,  1579,    16,  1779,
    1780,  1781, -2802, -2802,  1782,   705,  1785,  1787,  1788,  1789,
   13001, 13001, 13001, 13001, 13001, 13001, 13001, 13001, 13001, 13001,
   13001, 13001, 13001,    85, 13001,  1783, -2802, -2802, -2802,  1790,
   -2802,  1791,  1792,  1794,   129,  5635, -2802,   784, -2802, -2802,
    1795,  5635, -2802, -2802,  5635,  5635,  5635,  5635,  5635,  5635,
      -1,  5635,  5635,    66,  1757,  1517,  5635,  5635,  5635,  5635,
    5635,  5635,  5635, 15724,  5635,  1747,  5635,  1718,  5635,  5635,
     -31,  5635,  5635,  5635,  5635,  5635,   115,   -11,  1764,  1765,
    5635,  5635,  5635,  5635,   252, -2802, -2802,   784,    41,   784,
     432, -2802, -2802, -2802,  1797,  1800, -2802, -2802, -2802, -2802,
     116, -2802,  5635,   289,   554, 11509, 12531,    -1, 15724, 15724,
      -1,    -1,    -1,    -1,    -1, 15724,    -1,    -1,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    -1,     6, 15724, 15724,    -1,
    1593,  1594,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1, 15724,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1, 15724, 15724, 15724, 15724, 15724,
      -1,    -1,    -1,    -1,    -1,   115,   115,   784,   784,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1, 15724,    -1,    -1,    -1,    -1,    -1,    -1, 15724,
   15724, -2802, -2802, -2802, -2802, -2802, -2802, -2802, -2802, -2802,
   -2802, -2802, -2802, -2802, -2802, 15724, 15724, 15724,    -1, 15724,
   15724,  1314, 15724, 15724, 15724, 15724,   784, -2802, 12020, -2802,
   12531,  5150, 15724, 15724, 13471, 13471, 13471, 13471, 13471, 13471,
   13471, 13471, 13471, 13471, 15724, 15724, 15724, 15724, 15724,   146,
   -2802,    70,   784,   784,   784,  5635,  1766,  1768,   784,  1784,
    1786,  5635,  1793,  1796,  1798,   784,  5635,  1719,  5635,  5635,
     784,  5635,  5635,  5635,  5635, -2802,  1672,  5635,  1675,  1802,
   -2802,  1799,  1808,   439,  1479, 15724,   970,   -15, 15724, -2802,
      18,  5635, -2802,  1810, -2802, -2802,  1811, -2802,  1813,    -1,
    5635,    -1,  5635,  5635,  5635,    -1,    -1,    -1,    -1,  5635,
    5635,  5635,  5635,  5635,  5635,  5635,    -1,  5635,    -1,    -1,
      -1,    28,    -1,    97,   131,    -1,    -1,  5635,  5635,  5635,
    5635,  5635,  5635,  5635,  5635,  5635,  5635,  5635,  5635,  5635,
    5635,  5635,    -1, -2802, 15724, -2802,  1817,  5635,  5635,  5635,
    5635,  5635,  5635,  5635,    -1,    -1,    -1, -2802, -2802,  5635,
    5635, -2802,  5635, -2802, -2802,   784, -2802,  1367,  1812, -2802,
   -2802, -2802, -2802, -2802, -2802, -2802, -2802,   206,   206, -2802,
    5635, -2802,  5635,   784,    -1,    -1,  5635, -2802,  5635,  5635,
    5635,  1686,   784,    -1, -2802,    -1,    -1,  5635,  5635,  5635,
    5635,  5635,  5635,  5635, -2802,  5635,  5635, -2802,  5635,  5635,
    5635,  5635,  5635,  5635, 15724,  5635,  5635,  5635,  5635,  5635,
    5635,  5635,  5635,    -1, 15724,  5635, 15724,  5635,  5635,    -1,
    5635,  5635,  5635, 15724,    -1,   115,   115,   115, 15724, 15724,
   15724,   784, 15724,    -1,   115,    -1,   115,   115, 15724,   707,
   -2802, 15724, 15724, 15724, 15724, 15724,  1551,  5635, -2802,  5635,
     784,  -264, 11509,   784,  5635,  1801,  5635,  5635,   784,   784,
     784,    38,   784, -2802, -2802,  1814,  5635,  1821,  1816,   341,
    1818,  1819,  1822,  1823,  1824,  1827,  1828,  1829,  1833,  1835,
    1830,  1831,  1832,  1834,  1836,  1839,  1843,  1841,  1842,  1844,
    1845,  1849,  1846,  1853,  1848,   466,  1855,  1856,  1852,  1854,
    1858,  1859,  1861,  1840,   468,  1862,  1860,  1865,  1867,  1875,
    1876,  1877,  1878,  1879,  1883, 13941, -2802,  1884,  1885,  1888,
    1889, -2802, -2802, -2802,   518,   522,  1890,  1895,  1896,  1903,
    1899,  1900,  1902,  1904,  1905,  1906,  1907,  1908,  1909,  1910,
   -2802, -2802,  1911,  1913,  1921,  1916, -2802,  1924,  1927,  1933,
    1935,  1936,  1944,  1945,  1946,  1939,  1941,  1942,  1952,  1953,
    1954,  1955,  1956,  1957,  1964,  1965,  1966,  1961,  1968,  1963,
    1969,  1970,  1971,  1976,   523,  1977,  1978,  1979,  1980,  1981,
    1993,  1994,  2001,  1996,  1997,  1998,  1999,  2003,  2006,  2015,
    2016,  2012,  2014,  2017,  2018,  2019,  2020,  2021,  2022,  2023,
    2025,  2026,  2028,  2029,  2036,  2037,  2038,  2039,  2040,  2044,
    2045,  2041,  2043,  2046,   547,  2047,  2049,  2050,  2053,  2051,
     611,   612,  2057,  2064,  2065,   564,  1223,   252, -2802, -2802,
    2066,  2061,  1041,   613,   362,  1857, -2802, -2802, -2802, -2802,
   -2802, -2802,  1087,   516,  1087,   516, -2802, -2802, -2802, -2802,
   -2802, -2802, -2802, -2802, -2802,    58, -2802,    58,   815, -2802,
    1411,    21,  1287,  2052,  2069,  2070,  2071,  2072, -2802,  2073,
    2074,  2075,  2076,  2077,  2078,  2079,   616,   624,  2080,  2081,
    2082,  2083,  2084,  2085,  2093,   626,  2088,  2095,  2090,  2091,
    2092,  2099,   -31,  1881, 15724, -2802,  2100, 16101,  1592,  2096,
    2101, 15724,    -1,    -1,   629,  2103,  2098,   681,  2105,  2106,
    2108,  2110,  2111,  2112,  2113,  2115,  2116,  2117,  2118,  2119,
    2121,  2120,  2122,  2123,  2124,  2133,  2134,  2137,  2139,  2140,
    2141,  2142,  2143,  2144,  2145,  2146,  2147,  2148,  2150,  2149,
    2154,  2160,  2161,  2156,  2163,  2164,  2166,  2167,  2169,  2165,
    2172,  2173, 15724,  2171,  2174,   720,  2175,  2176,  2179,  2177,
    2180,  2182,  2184,  2188,  2189,  2185,  2190,  5635,   784,    70,
      70,  1866,  2034,  2104,  2107,  2155,   721,   723,  2191,  2193,
    2200,  2195,  2198, -2802,   254,  2199,  2207, 12531,  2208,   725,
    2209,  2210,  2211,   421,  2215,   448,  2227,   728,  2222,  2229,
     740,  2233,  2236,  2237,  2238,   748,  2239,  2240,  2235,   750,
    2242,  2241,  2244,  2245,  2243,  2246,  2248,  2252,  2253,  2254,
    2255,  2256,  2251,  2257,  2258,  2259,  2260,  2261,  2262,  2264,
     759,  2263,  2265,  2266,  2267,  2269,   760,  2270,  2271,   761,
    2272,  2273,  2274,  2275, -2802,  2268,   762,  2276,  2277,  2278,
    2279,  2287,  2285,  2286,  2289, -2802,   764,  2290,  2291,  2288,
    2292,  2295,  2293, -2802, -2802,  2296,   784,   252, -2802, -2802,
      -1,  5635,  5635,  5635,  5635, -2802,  5635, -2802,  5635, -2802,
   -2802, -2802,    -1,    -1,  5635,  5635,  5635, -2802, -2802,  5635,
    5635,  5635,  5635, -2802,  5635, -2802,  5635, -2802,  5635, -2802,
   -2802,  5635,  5635,  5635,  5635, -2802,  1583, -2802,  5635, -2802,
      -1,  5635, 15724, -2802,  1891, -2802, -2802, -2802,  2032, 12531,
   -2802, -2802,  5635,   -38,  5635, -2802, 15724,    72,  5635,  5635,
   -2802,  5635,  5635,  5635,  5635,  5635,  5635,  5635,  5635,  5635,
    5635,  5635,  5635, -2802,  5635,    -1,    -1, 15724, 15724,    -1,
      -1,    -1, -2802,  5635,  5635,  5635,  5635,  5635,  5635,  5635,
    5635,  5635, -2802, -2802, -2802,    -1, -2802,    -1,    -1,    -1,
      -1,    -1, -2802,    -1,    -1,  5635,  5635,  5635,  5635, 15724,
   15724, -2802,  5635,  5635,  5635,  5635,    -1,   784, -2802, -2802,
      -1,    -1,  5635,  5635,  5635,  5635,  5635,  5635,  5635,  5635,
    5635,  5635,  5635, -2802, -2802, -2802, -2802, -2802, -2802, -2802,
    5635,  5635,  5635, -2802,  5635,  5635,    -1,  5635,  5635,    -1,
   -2802,  5635, -2802,  5635, 15724, -2802, -2802, -2802, -2802, -2802,
   -2802, -2802,  2283, -2802,  5635, -2802, 15724,  5635,    -1,  2297,
    2298,  2300, -2802, -2802, -2802,  5635,  5635,  5635,  1988, -2802,
     784, -2802,  5635,   784,   784,   784,   784,   784,  5635, -2802,
   -2802,  5635,  5635, -2802,  5635,  5635,  5635, -2802, -2802, -2802,
   -2802, -2802, 15724, -2802,  2301,  2302,   787, -2802,    -1, -2802,
    5635, -2802,  5635, -2802, -2802, -2802, -2802, -2802, -2802, -2802,
   -2802, -2802, -2802, -2802, -2802, -2802,  5635, -2802, -2802,    -1,
   -2802, -2802, -2802, -2802, -2802, -2802, -2802, -2802, -2802, -2802,
   -2802,  5635, -2802,  5635, -2802, -2802, -2802, -2802,  5635, -2802,
   -2802, -2802, -2802, -2802,  5635, -2802, -2802,  2303,  5635,  5635,
   -2802, 12531,  5635,  5635, -2802,  5635,  5635,    -1,    -1,  5635,
    5635, -2802,  5635,  1619, -2802, -2802, -2802, -2802, -2802, -2802,
   -2802, -2802, -2802,   614, -2802,  5635,  5635, -2802,    -1,  5635,
   -2802,  5635,  5635,  5635, -2802, -2802, -2802, -2802, -2802,  5635,
   -2802, -2802,  5635, -2802,  5635, -2802, -2802, -2802,  5635,  5635,
    5635, -2802,  5635, -2802, -2802, -2802, -2802, -2802,  5635, -2802,
   -2802,  5635, -2802,  5635, -2802,  5635,  5635,  5635, -2802, -2802,
   -2802, -2802, -2802, -2802, -2802, -2802,  5635,  5635, -2802, -2802,
    5635, -2802, -2802, -2802, -2802,  5635,  5635,  5635,  5635,  5635,
    5635, -2802,  5635,  5635,  5635, -2802,  5635,  5635,  5635,  5635,
    5635, -2802, -2802,  5635,  5635,  5635, 12531, 15724,  5635, -2802,
   -2802, -2802, -2802, -2802, -2802,  2183,  2299,  2304,  2204, -2802,
    2306,  2305,  2307,  2308,  2309,  2310,  2312,  2311,  2313,  2315,
    2318,  2319,  2314,  2316,  2321,  2317,  2320,  2322,  2323,  2324,
    2325,  2326,  2327,  2328,  2330,  2335,  2336,  2331,  5635,  2338,
    2333,  2334,  2341,   788,  2337,  2339,  2342,  2344,  2346,  2347,
    2343,  2348,  2345,  2349,  2350,  2351,  2352,  2353,  2354,  2355,
    2362,  2357,  2358,  2359,  2363,  2364,  2365,  2366,  2368,  2369,
    2370,  2371,  2372,  2373,  2374,  2381,  2376,  2377,  2378,  2379,
    2380,  2383,  2387,  2390,  2385,  2392,  2393,  2394,  2389,  2391,
    2396,  2398,  2399,  2400,  2395,  2402,  2403,  2401,  2404,  2405,
    2406,  2408,  2409,  2413,  2414,  2415,  2416,   789,  2411,  2412,
    2417,  2418,  2419,  2420,  2421,  2422,  2423,  2424,  2425,  2428,
    2431,  2426,  2427, -2802,  2434,  2435, -2802, -2802, -2802,  2436,
     157,  2432,   182,  2433,  2437,  2440,    54,  2441,  2442,  2443,
    2444,  2439,  2446,  2447,  2448,  2445,  2449,  2450,  2452, -2802,
   -2802, -2802,  5635,  2453,  2451,  2454,  2455,  2456,  2457,  2458,
    2459,  2460, -2802,   790,   791,   792,  2461,  2462,  2463,  2465,
    2467,  2469,  2471,  2472,  2473,  2464,  5635,    70,    70,  2217,
    2224,  2282,  2284,  2361,    70,  2480,  2477,  2482,  2487,   360,
    2494,  2360,  2489,  2491,  2492,  2495,  2496,  2497,  2498,  2506,
    2501,  2502,  2503,  2505,  2514,  2529,  2531,  2532,  2533,  2540,
    2535,  2536,  2537,  2539,  2546,   799,  2547,  2550,  2551,  2552,
    2553,  2548,   825,  2549,  2554,  2555,  2556,  2557,  2558,  2559,
     784,   784,  2566, -2802,  5635, -2802,  5635, -2802,  5635, -2802,
    5635, -2802, -2802, -2802, -2802,  5635,  5635, -2802,  5635,  5635,
    5635,  5635, -2802,  5635,  5635,  5635,  5635, -2802, -2802, -2802,
    5635, -2802, -2802,  5635,  5635, -2802, -2802,   217,   274,  5635,
   -2802, -2802, -2802, -2802,  5635, -2802,  5635,  5635,  5635,  5635,
    5635,  5635,  5635,  5635, -2802,  5635,  5635,  5635,  5635,  5635,
    5635,  5635,  5635,  5635,  5635,  5635,  5635,  5635,  5635, -2802,
    5635,    -1,    -1,    -1,    -1,    -1, -2802, -2802,  5635, -2802,
   -2802, -2802,  5635,  5635, -2802, -2802, -2802, -2802, 15724, -2802,
   -2802, 15724,  5635,  5635, -2802, -2802, -2802, -2802, -2802, -2802,
   -2802, -2802,  5635,  5635,  5635,  5635,  5635, -2802,  5635,  5635,
   -2802,  5635,  5635, -2802, -2802, -2802,  5635,  5635, -2802, -2802,
   -2802,  5635,  5635,  5635,  5635, -2802, -2802, -2802, -2802, -2802,
   -2802, -2802,   784, -2802, -2802, -2802,  5635, -2802, -2802, -2802,
    2567, -2802,  5635, -2802, -2802,    -1,  5635, -2802,  5635,  5635,
   -2802, 15724, -2802, 15724, -2802, 15724, -2802, 15724,  5635,  5635,
    5635,    -1,    -1,  5635,  5635, -2802, -2802, -2802, -2802, -2802,
   -2802, -2802, -2802, -2802, -2802, -2802,  5635,    -1,  5635, -2802,
    5635,  5635, -2802,  5635,  5635,  5635,  5635,  5635,  5635,  5635,
    5635, -2802,  5635,  5635,  5635,  5635,  5635,  5635,  5635,  5635,
    5635, -2802,  5635,  5635,  5635,  5635, -2802, -2802,    -1, -2802,
   -2802, -2802, -2802, -2802, 15724, -2802,  5635,  5635,  5635,  5635,
   15724, 15724,  5635,  5635, -2802, -2802, -2802,  2573,   827,  2570,
    2579,  2574,  2575,  2584,  2580,  2586,  2585,  2587,  2589,  2590,
    2597,  2592,  2593,   465,  2594,  2595,  2603,  2599,   829,  2600,
    2601,  2604,   838,   846,   854,   855,  2605,  2607,  2610,  2611,
    2609,   508,   856,   371,  2612,  2613,  2614,  2615,   859,  2616,
    2617,  2621,  2622,  2625,  2626,  2633,  2628,  2629,  2630,  2631,
    2632,  2634,  2635,  2639,  2643,  2645,  2648,  2651,  2661,  2672,
    2667,  2668,  2669,  2670,  2671,  2673,  2678,  2674,  2397,  2679,
    2675,  2686,  2684,  2691,  2687,  2692, -2802,  2688,  2695,  2690,
    2697,  2693,  2698,   864,  2700,  2696,  2699,  2701,  2702,   923,
    2703,  2704,  2706,    70,  2705,  2707,  2708,  2710,  2712,  2709,
    2711,  2716,  2718,  2719,  2720,  2721,  2722,  2723,  2724,  2725,
    2726,  2727,  2728,  2729,  2730,  2731,  2732,  2733,  2734,  2735,
    2736,  2743,  2744,  2739,  2746,  2741,  2742,  2745,  2749,  2750,
   -2802, -2802,  5635,  5635, -2802,  5635,  5635, -2802,  5635,  5635,
   -2802,  5635,  5635,  5635, -2802,  5635,  5635, -2802,   217,  5635,
   -2802, -2802,   217,  2225,  5635,  5635, -2802,  5635, -2802,  5635,
   -2802,  5635, -2802,  5635,  5635,  5635,  5635,  5635, -2802, -2802,
   -2802,  5635,  5635,  5635,  5635,  5635,  5635, -2802,  6161,  6161,
    6161,  5635,  5635,  5635,  5635, -2802,  5635,  5635,  5635,  5635,
    5635,    -1,  5635, -2802, -2802, -2802, -2802,  5635,  5635, -2802,
    5635,  5635,  5635,  5635,  5635,  5635, -2802,  5635,  5635,  5635,
    5635, -2802,  5635, -2802,   784, -2802,  5635, -2802,  5635, -2802,
    5635, -2802, -2802,  5635, -2802,  5635,  5635, -2802,  5635, -2802,
   15724,    -1, -2802, -2802, -2802,  5635,    -1,  5635, -2802, -2802,
    5635,  5635, -2802, -2802, -2802, -2802, -2802, -2802, -2802, -2802,
   -2802, -2802, -2802, -2802, -2802, -2802,  5635,  5635,  5635,  5635,
    5635, -2802, -2802, -2802, 15724, -2802,  5635,  5635,  5635, -2802,
   -2802,  2747,  2752,  2754,  2751,  2753,  2755,  2756,  2758,  2760,
    2757,   927,  2759,  2761,  2762,   944,  2763,  2764,   969,   973,
    2765,  2766,  2767,  2768,  2769,  2776,  2771,  2772,  2773,  2774,
    2775,  2777,   513,  2782,   525,  2784,  2778,  2785,  2781,  2783,
    2786,  2787,  2788,  2789,  2790,  2791,  2792,   983,  2793,  2800,
     985,  2801,  2802,  2803,  2798,  2799,  2804,  2806,  2805,  2807,
    2808,  2809,  2811,  2812,   993,  2810,  2814,  2815,  2813,  2816,
    2817,  2818,  2819,  2820,  2821,  2780,  2823,  2830,  2827,  2834,
    2836,  2837,  2838,  2840,  2841,  2842,  5635, -2802, -2802,  5635,
    5635,  5635, -2802, -2802, -2802,  5635, -2802,  5635,  5635,   784,
   -2802, -2802,   217,  5635,  5635, -2802,  5635, -2802,  5635,  5635,
    5635,  5635,  5635,  5635, -2802,  5635,  5635,  5635,  5635,  5635,
    5635,  6161, -2802,  6161, -2802, -2802,  6161,  6161,  5635,  5635,
    5635,    -1,    -1,    -1,    -1, -2802,  5635,  5635, -2802, -2802,
    5635, -2802, -2802, -2802,  5635,  5635,  5635, -2802, -2802,  5635,
   -2802, -2802, -2802, -2802, -2802,  5635,  5635, -2802, -2802,  5635,
    5635, -2802,    -1,  5635,    -1,  5635,  5635, -2802, -2802,  5635,
    5635, -2802,  5635, 15724,  5635,  5635,  5635,  2849,  2846,  2848,
    2850,  2852,  2864,  2859,  2860,  2873,  2881,  2883,  2887,  2890,
    2891,  2892,  2895,  2902,  2901,   995,  2909,  2904,  2911,  2913,
    2912,  2915,  2917,  2920,  2923,  2919,  2926,  2927,  2928,  2929,
    2924,  2932,  2934,  2935,  2940,  2936,  2943,  2938,  2937,  2941,
    2946,  2942,  2944,  2945,  2951,  2952,  2953,  2949,  2954,  2955,
    2959,   996,  2960,  2961,  2962, -2802,  5635,  5635,  5635,  5635,
   -2802,  5635,  5635, -2802, -2802,  5635, -2802, -2802, -2802, -2802,
   -2802, -2802,  5635, -2802,  5635, -2802,  5635, -2802, -2802,  5635,
   -2802, -2802, -2802, -2802,  6161, -2802, -2802, -2802, -2802,  5635,
    5635, -2802,  5635, -2802,  5635, -2802,  5635,  5635,  5635, -2802,
    5635,  5635,    -1,  5635,    -1,  5635,  1949,  5635,  5635,  5635,
   -2802, 15724,  5635,  5635,  5635,  2969,  2970,  2965,  2972,   111,
    2967,  2968,  2971,  2975,  2976,  2978,  2973,  2980,  2977,  2979,
    2981,  2982,  2983, -2802,  2984,   997,  2985,  1004,  2986,  2987,
    2988, 15724,  2989,  2990,  1005,  2991,  2998,  1006,  2993, -2802,
   -2802,  5635, -2802, -2802,   784,  5635,  5635, -2802, -2802, -2802,
    5635, -2802,  5635,  5635, -2802,  5635,  5635, -2802, -2802, 15724,
    5635, -2802, 15724,  5635,  5635,  5635, -2802,  5635,  5635, -2802,
    5635,  5635, -2802, -2802,  5635,  5635,  2994,  3001,  3002,  3003,
    3004,  3005,  3000,  3006,  3007,  3008,  3009,  3010,  3011,  3012,
    3013,  3014,  3015,  3016,  3020,  1007,  1066,  5635, -2802, -2802,
   -2802, -2802, -2802,  5635,  5635,  5635, -2802, -2802, -2802,  5635,
    5635,    -1, -2802,  5635,  5635, -2802, -2802,  5635, -2802, 15724,
    3017,  3018,  3025,  3021,  3026,  3022,  3023,  3030,  3027,  3031,
    3028,  5635,  5635, -2802,  5635, -2802,  5635,    -1, -2802,  5635,
   -2802, 15724,  3029,  3032,  3033,  3034,  3035,  3036,  3037,  5635,
   -2802,  5635,  5635,  5635, -2802, -2802,  3038,  3039,  3040,  3042,
    5635,  5635,  5635, -2802,  3041,  3043,  3044,  5635,  5635,  5635,
    3048,  3045,  3047, -2802,  5635,  5635,  3052,  3054,  5635, -2802,
    3059, -2802
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  Parser::yydefact_[] =
  {
         2,   511,     0,     0,     0,     0,    21,    75,    76,    77,
      78,     0,     0,     0,   400,   409,    39,    20,     0,   110,
      82,     0,     0,     0,     0,     0,     0,     0,   109,     0,
       0,   388,   408,   861,   558,   412,   413,   414,   389,     0,
     821,     0,   777,     0,   870,   871,   872,   873,   874,   875,
     876,     0,     0,   881,   882,     0,     0,    41,    44,    42,
      43,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     322,   323,   396,   324,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   547,   548,   549,   550,
     551,   552,   553,   554,   555,   556,     0,     0,     0,   410,
     411,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   406,    40,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   350,
     351,   352,     0,     0,   512,     0,     0,     4,     8,    10,
      14,    16,    18,    12,     0,   390,   401,   404,     0,   416,
     493,   513,     0,   515,   519,   522,   523,   528,   533,   535,
     537,   539,   541,   543,   545,   546,   315,   487,     0,   779,
     781,   782,   800,   801,   805,   810,   811,   812,   813,   814,
     815,   816,   817,   818,   819,   820,   123,     0,     0,     0,
       0,     0,     0,   412,   413,   414,     0,   821,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     495,     0,     0,   777,   497,   785,   496,   784,   389,     0,
     487,     0,     0,     0,     0,     0,   103,    83,    85,   116,
     113,   114,   115,   112,   111,    84,   119,   126,   121,   120,
     127,   122,     0,     0,     0,   108,     0,     0,    93,    94,
       0,    96,    97,     0,   100,   101,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   360,   360,   360,    38,
      33,   428,     0,     0,     0,     0,     0,   863,   862,   864,
     877,   866,   867,   868,   878,   869,   871,   872,   874,   875,
     876,   880,   879,   881,   882,   865,   105,   106,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   498,   787,   499,   788,
     504,   793,   505,   794,   506,   795,   507,   796,   508,   797,
     510,   799,   509,   798,   500,   789,   501,   790,   502,   791,
     503,   792,     0,    25,     0,   406,    35,     0,    36,     0,
       0,     0,    30,    28,   406,     0,     0,     0,     0,     0,
       0,     1,     3,     5,     9,    11,    15,    17,    19,    13,
       0,     6,     0,     0,     0,     0,     0,   494,   783,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   786,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   415,     0,     0,   780,     0,     0,     0,     0,
       0,     0,   881,     0,     0,    95,    98,    99,   102,     0,
       0,     0,     0,     0,     0,   454,   455,   452,   453,   450,
     451,   456,   457,   458,     0,     0,     0,   130,     0,     0,
       0,     0,   137,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   282,     0,
       0,     0,     0,   287,   288,     0,   271,     0,   279,     0,
       0,     0,     0,     0,   268,   269,     0,    57,    58,     0,
       0,   125,     0,     0,    74,     0,     0,     0,     0,     0,
     568,     0,   375,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,   363,     0,   361,   572,
     708,   710,   711,   729,   731,   737,   738,   743,   744,   753,
     758,   760,   761,   763,   765,   767,   769,   771,   369,     0,
       0,     0,   335,     0,   328,     0,   329,   481,   326,     0,
       0,     0,     0,   333,   334,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   330,   331,
     332,   336,     0,     0,     0,   337,   348,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   572,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   179,   180,     0,     0,   459,   460,     0,     0,     0,
       0,     0,     0,     0,     0,   461,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   218,   219,   181,   182,   183,
     184,     0,     0,   572,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   777,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   407,     0,    34,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,   394,   395,   402,   403,   531,   532,   516,
     517,   518,   520,   521,   525,   524,   526,   527,   529,   530,
     534,   536,   538,   540,     0,   542,     0,     0,     0,   397,
       0,   425,   427,     0,   221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   557,   426,    88,    87,    89,    86,
     802,   804,   803,   806,   808,   807,   809,   429,   430,   431,
       0,     0,     0,   491,     0,   255,     0,   250,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   249,     0,   241,     0,   251,   252,
       0,     0,     0,     0,     0,   260,   262,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   835,     0,     0,     0,     0,     0,
     838,    62,     0,    52,     0,     0,     0,     0,   568,     0,
       0,     0,   772,    60,     0,   835,     0,   548,   551,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,     0,    68,    51,    56,    55,   838,
      61,     0,     0,     0,     0,     0,   514,     0,    80,    81,
       0,     0,   398,   399,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   117,   124,   118,     0,     0,     0,
     572,   729,   714,   713,   487,     0,   365,   367,   371,   373,
       0,   560,     0,     0,     0,   360,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   715,   716,   721,   722,   723,   724,   725,   727,   726,
     717,   718,   719,   720,   728,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   355,     0,   712,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     356,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   349,   822,     0,   559,     0,
      45,     0,     0,   572,     0,     0,     0,     0,     0,   437,
       0,     0,   439,     0,   440,   441,     0,   442,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   433,     0,   438,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   316,   317,     0,
       0,   435,     0,   778,   449,     0,   319,     0,   406,   358,
     405,   406,    26,   484,   485,   486,   321,   377,   377,    32,
       0,   263,     0,     0,     0,     0,     0,   417,     0,     0,
       0,     0,     0,     0,   220,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   224,     0,     0,   225,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     833,     0,     0,     0,     0,     0,     0,     0,    47,     0,
       0,     0,   360,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   822,   559,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   709,     0,     0,     0,
       0,   658,   656,   657,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     627,   628,     0,     0,     0,     0,   631,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   376,   364,   362,   370,
       0,     0,   886,     0,   885,     0,   770,   736,   732,   734,
     733,   735,   739,   741,   740,   742,   750,   746,   749,   745,
     751,   747,   752,   748,   756,   754,   757,   755,   759,   762,
     764,     0,   766,     0,     0,     0,     0,     0,    37,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   544,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   832,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   773,     0,     0,     0,     0,
       0,     0,     0,    71,    69,     0,     0,   393,   392,   391,
       0,     0,     0,     0,     0,   153,     0,   156,     0,   129,
     132,   131,     0,     0,     0,     0,     0,   140,   141,     0,
       0,     0,     0,   146,     0,   155,     0,   272,     0,   267,
     274,     0,     0,     0,     0,   270,     0,   280,     0,   275,
       0,     0,     0,   278,   462,   488,   489,   490,     0,     0,
     730,   561,     0,     0,     0,   567,     0,     0,     0,     0,
     607,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   608,     0,     0,     0,     0,     0,     0,
       0,     0,   639,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   592,   593,   594,     0,   596,     0,     0,     0,
       0,     0,   603,     0,     0,     0,     0,     0,     0,     0,
       0,   610,     0,     0,     0,     0,     0,     0,   565,   566,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   683,   588,   590,   652,   653,   654,   655,
       0,     0,     0,   687,     0,     0,     0,     0,     0,     0,
     699,     0,   701,     0,     0,   703,   704,   366,   368,   372,
     374,   684,     0,   573,     0,   614,     0,     0,     0,     0,
       0,     0,   482,   483,   480,     0,     0,     0,     0,   469,
       0,   474,     0,     0,     0,     0,     0,     0,     0,   340,
     342,     0,     0,   479,     0,     0,     0,   338,    59,    63,
      54,    46,     0,   492,     0,     0,     0,   313,     0,   167,
       0,   166,     0,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   187,   188,   189,     0,   202,   203,     0,
     205,   213,   207,   208,   214,   209,   215,   211,   212,   210,
     190,     0,   200,     0,   191,   216,   217,   196,     0,   192,
     193,   194,   195,   198,     0,   432,   448,     0,     0,     0,
     295,     0,     0,     0,   302,     0,     0,     0,     0,     0,
       0,   776,     0,   406,   359,    24,    27,   380,   381,   382,
     378,   379,   406,     0,   406,     0,     0,   347,     0,     0,
     418,     0,     0,     0,   424,    91,    90,   164,   163,     0,
     222,   223,     0,   309,     0,   311,   312,   159,     0,     0,
       0,   157,     0,   242,   247,   253,   254,   257,     0,   256,
     226,     0,   238,     0,   234,     0,     0,     0,   230,   231,
     232,   233,   239,   248,   240,   243,     0,     0,   236,   246,
       0,   261,   265,   839,   840,     0,     0,     0,     0,     0,
       0,   836,     0,     0,     0,   827,     0,     0,     0,     0,
       0,   834,   849,     0,     0,     0,     0,     0,     0,    49,
      50,   775,    53,   325,    48,     0,    66,    64,     0,   104,
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
       0,     0,     0,   768,     0,     0,   693,   695,   696,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   443,
     444,   445,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   447,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    79,     0,   148,     0,   151,     0,   154,
       0,   135,   133,   136,   138,     0,     0,   143,     0,     0,
       0,     0,   273,     0,     0,     0,     0,   281,   276,   289,
       0,   463,    73,     0,     0,   579,   580,     0,     0,     0,
     606,   609,   611,   612,     0,   613,     0,     0,     0,     0,
       0,     0,     0,     0,   632,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   591,
       0,     0,     0,     0,     0,     0,   604,   605,     0,   574,
     575,   576,     0,     0,   659,   660,   661,   662,     0,   707,
     668,     0,     0,     0,   673,   674,   675,   676,   677,   678,
     679,   680,     0,     0,     0,     0,     0,   688,     0,     0,
     689,     0,     0,   698,   700,   702,     0,     0,   694,   697,
     327,     0,     0,     0,     0,   468,   470,   473,   472,   475,
     471,   476,     0,   477,   339,   343,     0,   344,   345,   346,
       0,   314,     0,   178,   201,     0,     0,   204,     0,     0,
     290,     0,   292,     0,   297,     0,   296,     0,     0,     0,
       0,     0,     0,     0,     0,   318,   406,    22,    31,   385,
     386,   387,   383,   384,    29,   357,     0,     0,     0,   419,
       0,     0,   423,     0,     0,     0,     0,     0,     0,     0,
       0,   258,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   842,     0,     0,     0,     0,   837,   823,     0,   824,
     828,   829,   830,   831,     0,   850,     0,     0,     0,     0,
       0,     0,     0,     0,    67,    65,    72,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   487,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   446,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     147,   149,     0,     0,   128,     0,     0,   145,     0,     0,
     266,     0,     0,     0,   286,     0,     0,   571,     0,     0,
     581,   582,     0,     0,     0,     0,   618,     0,   621,     0,
     623,     0,   625,     0,     0,     0,     0,     0,   629,   630,
     663,     0,     0,     0,     0,     0,     0,   640,     0,     0,
       0,     0,     0,     0,     0,   650,     0,     0,     0,     0,
       0,     0,     0,   577,   578,   706,   669,     0,     0,   681,
       0,     0,     0,     0,     0,     0,   692,     0,     0,     0,
       0,   464,     0,   466,     0,   341,     0,   206,     0,   197,
       0,   291,   293,     0,   298,     0,     0,   307,     0,   306,
       0,     0,   434,   436,    23,     0,     0,     0,   421,   422,
       0,     0,   308,   310,   160,   161,   420,   158,   235,   237,
     227,   228,   229,   244,   245,   259,     0,     0,     0,     0,
       0,   825,   826,   851,     0,   852,     0,     0,     0,   848,
     774,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   884,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   152,   139,     0,
       0,     0,   283,   284,   285,     0,   569,     0,     0,     0,
     583,   584,     0,     0,     0,   617,     0,   620,     0,     0,
       0,     0,     0,     0,   589,     0,     0,     0,     0,     0,
       0,     0,   641,     0,   643,   645,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   601,     0,     0,   670,   671,
       0,   682,   685,   686,     0,     0,     0,   587,   615,     0,
     465,   467,   478,   165,   185,     0,     0,   294,   301,     0,
       0,   305,     0,     0,     0,     0,     0,   162,   841,     0,
       0,   845,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   150,     0,     0,     0,     0,
     570,     0,     0,   585,   586,     0,   619,   622,   624,   626,
     633,   636,     0,   665,     0,   667,     0,   634,   637,     0,
     642,   644,   646,   647,     0,   649,   595,   597,   598,     0,
       0,   602,     0,   672,     0,   690,     0,     0,     0,   199,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     853,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   883,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   142,
     144,     0,   277,   563,     0,     0,     0,   635,   666,   664,
       0,   648,     0,     0,   651,     0,     0,   186,   299,     0,
       0,   304,     0,     0,     0,     0,    92,     0,     0,   847,
       0,     0,   858,   857,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   564,   562,
     616,   638,   599,     0,     0,     0,   300,   320,   303,     0,
       0,     0,   843,     0,     0,   854,   855,     0,   859,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   705,     0,   264,     0,     0,   844,     0,
     856,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     600,     0,     0,     0,   846,   860,     0,     0,     0,     0,
       0,     0,     0,   354,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   134,     0,     0,     0,     0,     0,   353,
       0,   691
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
     -2802, -2802, -2802,   -47,  2138,  2218,  2220, -2802, -2802,  2221,
    2571,  2602,  2623, -2802,  -282,   717, -2802,   639, -2802,  7402,
    -383, -2802, -2802, -2802, -2802,  -460,  6131,   571,  -405, -2802,
    -417,   635,  1892,  1887,  2002,  2048,  2000,  1934,  1088, -2802,
       0,    91,  3425, -2802, -2802, -2802,  -531,  -133,  -149, -2802,
   -2802,  -635,  -132,  1229, -2802,  1325,  1500,  1222,  1324,   573,
    1513,  7782,  1634, -2802, -2802, -2802, -2802,   119,   668, -2802,
   -2802, -2802, -2802, -2802, -2802, -2802, -2802, -2802, -2802, -2802,
      14,  6746,  -446,    30,   -21, -2801
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,   145,   146,   147,   148,   149,   150,   874,   873,   151,
     152,   153,   154,  1368,   665,  1786,   155,   156,   157,   158,
     383,   384,  1370,   159,   160,   161,   229,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     239,   177,   241,   670,   671,   672,   673,   674,   675,   676,
     677,   678,   679,   680,   681,   682,   683,   684,   685,   686,
     687,   688,  1037,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     242,   232,  1001,   925,   199,  1645
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int Parser::yytable_ninf_ = -879;
  const short int
  Parser::yytable_[] =
  {
       176,   289,   867,  1046,  1040,   690,   691,   894,   895,   896,
     897,   875,   909,     6,   196,  1101,  1101,   892,   893,    34,
     539,   540,   257,   260,    17,   207,  1009,   864,   726,  1110,
     198,  1459,   443,   207,   316,  1386,   258,  1556,   212,   213,
     933,   935,  -863,  2046,   294,  -877,   212,    14,   434,   254,
     243,   424,   425,   909,  1513,   244,  1247,    34,  1556,   278,
      33,    25,    26,  1238,  1239,  1012,    29,    30,  2607,   436,
      31,   437,  1550,  1551,    34,   438,   282,   213,   238,   290,
     284,   386,  -878,   447,  1532,  1533,    34,  3013,  3015,  3017,
     937,   938,   939,     6,   213,  1288,   240,  1231,   291,   403,
    1522,    33,  1344,  1523,    17,  1469,   213,   411,  1101,  1101,
    1101,  1101,  1101,  1101,  1101,  1101,  1101,  1101,  1101,  1101,
    1101,  1101,   235,   237,    34,  3313,  2293,   385,     1,  1488,
      34,   842,   843,    33,   844,   449,  1101,  1865,   321,  -862,
     322,   245,   943,  1387,   213,  -864,   176,    14,   392,  1388,
     213,   435,  1390,   295,   382,    34,   450,   268,   269,  1248,
     196,    25,    26,   393,   394,   435,    29,    30,   270,   444,
      31,   277,  1557,  1248,    34,   213,   198,  2601,   238,   207,
     439,   440,   908,   909,   785,   426,   427,   845,   448,    34,
      33,    72,   212,  1557,   213,   415,   416,  1240,  1241,   459,
    1736,   441,  2603,  1101,  1101,   460,   285,  1558,   283,   213,
    1101,  1101,  1101,  1101,  1101,  1101,  1101,  1101,  1101,  1101,
    1101,  1101,  1101,  1101,   263,   911,   415,   416,  1558,   727,
     357,   359,   361,   363,   365,   367,   369,   371,   373,   375,
     377,   379,   381,   912,   467,   473,   474,   979,   980,   981,
     775,   776,   415,   416,   271,   272,   982,   983,   984,   985,
     274,   275,   264,   986,   279,   273,   911,    33,  2170,  1739,
     475,   276,   266,   476,  2171,    34,   477,  2172,   937,   938,
     939,   418,   536,   537,   912,   267,   668,   668,   668,   413,
     414,    72,   910,   240,   728,   213,   730,   538,   415,   416,
    3181,   286,  3182,  1741,   987,  3183,  3184,   988,   989,   990,
     991,  1673,   992,   993,     6,   287,   994,   288,   732,   733,
    1861,   759,    14,   415,   416,    17,   292,     6,  2728,   293,
     943,  1673,    34,  1230,   296,  1231,    25,    26,    17,   464,
     868,    29,    30,   318,   324,    31,   325,   836,   837,    34,
     839,   841,   213,   238,   459,   911,  1387,   326,   865,   327,
     464,  1881,  1388,   882,  1389,  1390,   860,   319,   870,   213,
     280,   281,   320,   912,  2659,   459,   913,   914,   915,   916,
    2660,   464,   249,  2661,   459,    33,   937,   938,   939,   323,
     464,  2882,  1016,   415,   416,   876,   250,   251,   252,   253,
    1674,  1675,  1676,  1677,   335,   924,   336,   328,   917,   918,
     919,  1130,   884,  1102,  1103,   329,   922,  1131,  1227,   869,
    1674,  1675,  1676,  1677,  1228,   330,   459,  1361,   541,   542,
     543,   544,   464,   331,   459,  2183,   906,   907,   943,  1673,
     464,   928,  1250,  3287,   246,  1230,   924,  1231,  1228,   333,
    1035,   460,  1288,   332,  1231,  1042,  1043,   922,  1708,  1044,
     334,   459,  2185,  1251,  1038,  1130,    72,   464,  1116,  1228,
     322,  1286,  1371,  1101,  1101,   995,   996,   997,   459,  2857,
    1907,   998,  1917,   999,   464,   337,  1908,   924,  1918,  1101,
    1101,  1101,  1101,  1101,  1101,  1101,  1101,  1101,  1101,  1101,
    1101,  1101,  1288,  1101,  1231,   338,  1201,  1202,  1203,  1204,
    1205,  1206,  1207,  1208,  1209,  1210,  1211,  1212,  1213,  1214,
    1233,   459,  2879,  1234,  1235,    94,    95,   464,  1674,  1675,
    1676,  1677,  1935,  3101,  1229,  2044,  1292,  1982,  1228,  1095,
     920,   921,  1936,  1983,   339,  3103,   922,  2044,   340,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   923,
     401,  2023,   931,   932,    34,  1106,  1107,  2024,   422,   423,
     207,   428,   429,   230,   234,   236,   924,   846,   847,   848,
     849,   850,   851,   212,   213,   852,   853,   854,   855,   856,
     857,   858,   485,   486,   487,   488,   489,   490,   491,   492,
     493,  1102,  1103,  1657,  1659,  1661,  1663,   768,  1201,  1202,
    1203,  1204,  1205,  1206,  1207,  1208,  1209,  1210,  1211,  1212,
    1213,  1229,    34,  2037,  2038,  2030,  2032,   412,   207,  2043,
    2059,  2031,  2033,   341,  1506,  2044,  2060,  1531,  2061,  1104,
    2070,   212,   213,  2087,  2062,   342,  2071,   343,   144,  2088,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     769,   770,   771,   772,   445,   446,   773,   774,   775,   776,
     777,   778,   779,   780,   781,   782,   783,   784,   817,   818,
     819,   820,   356,   358,   360,   362,   364,   366,   368,   370,
     372,   374,   376,   378,   380,  2091,  1781,  1782,  1783,  1784,
    1785,  2092,  1101,  1101,  1101,  1101,  1101,  1101,  1101,  1101,
    1101,  1101,  1101,  1101,  1101,  1101,  1101,  1101,  1449,   344,
    1464,  1854,   485,   486,   487,   488,   489,   490,   491,   492,
     493,  1279,   345,   417,  2140,  2162,    14,  2164,    14,  2178,
    2141,  2163,  2187,  2163,   346,  2179,   542,   543,  2188,   347,
      25,    26,    25,    26,  2191,    29,    30,    29,    30,    31,
    2192,    31,  2197,    34,  2202,    34,   348,   238,  2198,   238,
    2203,   234,   236,  2224,  2231,  2235,  2242,   433,  2252,  2225,
    2232,  2236,  2243,   213,  1228,   213,   349,   356,   358,   360,
     362,   364,   366,   368,   370,   372,   374,   376,   378,   380,
     417,  2401,  2516,  2581,  2630,  2632,  2634,  2402,  2517,  2582,
    2631,  2633,  2635,  2687,   350,    14,   775,   776,  1110,  2688,
    1372,  1656,  1658,  1660,  1662,  1664,  1666,  1282,  1379,    25,
      26,  1652,  1654,  1534,    29,    30,    14,   351,    31,  2695,
     431,  2841,    34,  2861,   352,  2696,   238,  2842,   353,  2862,
      25,    26,  2866,   354,   692,    29,    30,   355,  2867,    31,
    2868,   389,   213,    34,  1367,   390,  2869,   238,  2870,  2872,
    2880,  1102,  1103,  2887,  2871,  2873,  2881,   430,  2932,  2888,
      72,   391,    72,   213,  2933,  1236,  1237,  1201,  1202,  1203,
    1204,  1205,  1206,  1207,  1208,  1209,  1210,  1211,  1212,  1213,
     395,  1229,  1532,  1533,   693,   694,   695,   696,   697,   698,
     699,   700,   701,   702,   703,   704,   705,   706,   707,   708,
     709,   710,   711,   712,   713,   714,   715,   716,   717,   718,
     719,   720,   721,   722,   723,   724,   693,  2939,   695,   396,
     697,  3076,   699,  2940,   701,   702,   397,  3077,   705,   706,
     707,   708,   709,   710,   711,   712,  1242,  1243,  3081,    72,
     717,   235,   237,  1449,  3082,   357,   359,   361,   363,   365,
     367,   369,   371,   373,   375,   377,   379,   381,   418,   398,
      72,    14,   432,  3085,   399,  1779,  1458,  3087,  1780,  3086,
     889,   890,   891,  3088,  1930,    25,    26,  3115,   451,  3119,
      29,    30,   400,  3116,    31,  3120,   442,  3134,    34,  3233,
    3270,  3328,   238,  3135,   930,  3234,  3271,  3329,  3331,  3339,
    3343,  3386,  1550,  1551,  3332,  3340,  3344,  3387,   213,    33,
      34,   297,   298,   299,   300,   301,   302,   303,   304,   305,
      44,   306,   307,    47,   308,   309,   310,   311,   312,   472,
     314,  1477,   885,   886,  1478,  1480,  1481,  1482,  1483,  1484,
     452,  1486,  1487,   898,   899,  1046,  1492,  1493,  1494,  1495,
    1496,  1497,  1498,   282,  1500,   453,  1502,   454,  1504,  1505,
    3388,  1507,  1508,  1509,  1510,  1511,  3389,  1653,  1655,   455,
    1517,  1518,  1519,  1520,   419,   420,   456,  1104,   457,   421,
    1647,  1649,  1651,   458,  2429,  2430,  2431,  2432,  2433,   461,
    1665,  1667,  1530,   934,   936,   668,   759,   234,   236,   462,
     463,   465,   469,   235,   237,    72,   545,   729,   731,   834,
     835,   878,   866,  1041,   872,   785,  1047,  1048,  1049,   357,
     359,   361,   363,   365,   367,   369,   371,   373,   375,   377,
     379,   381,   909,   418,  1050,  1051,  1052,  1053,  1054,  1055,
    1056,  1057,  1058,  1059,  1060,  1061,  1232,  1062,  1063,  1064,
    1065,  1066,  1067,   514,  1068,   515,  1930,   516,   517,  1069,
    1866,  1070,  1071,  1072,  1073,   518,  1074,  1075,   519,   520,
     521,   522,   523,   524,   525,   526,  1076,  1077,  1078,  1079,
    1080,  1528,  1081,  1082,  1678,  1083,  1084,  1085,  1086,  1087,
     356,   358,   360,   362,   364,   366,   368,   370,   372,   374,
     376,   378,   380,   725,  1088,   527,  1089,  1090,  1638,   528,
    1044,  1643,  1091,  1092,   529,   530,  1093,  1097,   417,  1098,
    1099,  1112,  1113,  1115,  1114,   531,  1117,  1118,  1119,  1120,
     532,   533,  1121,  1122,  1123,  1682,  2078,  1124,  1125,  1126,
    1127,  1688,  1128,  1129,  1132,  1133,  1693,  1134,  1695,  1696,
    1135,  1698,  1699,  1700,  1701,  1136,  1137,  1703,  1138,  1139,
    1140,  1141,  1142,  1143,  1144,  1145,  1146,  1147,  1148,  1149,
    1150,  1710,  1151,  1152,  1153,  1154,  1155,  1156,  1157,  1158,
    1715,  1159,  1717,  1718,  1719,  1160,  1161,  1162,  1163,  1724,
    1725,  1726,  1727,  1728,  1729,  1730,  1164,  1732,  1165,  1166,
    1167,  1168,  1169,  1170,  1171,  1172,  1173,  1745,  1746,  1747,
    1748,  1749,  1750,  1751,  1752,  1753,  1754,  1755,  1756,  1757,
    1758,  1759,  1174,  1175,  1176,  1177,  1178,  1763,  1764,  1765,
    1766,  1767,  1768,  1769,  1179,  1180,  1181,  1182,  1183,  1773,
    1774,  1184,  1775,  1185,  1186,  1187,  1188,  1189,  1190,  1191,
    1192,  1193,  1194,  1195,  1196,  1197,  1198,  1199,  1200,  1215,
    1788,  1216,  1789,  1217,  1218,  1219,  1220,  1222,  1794,  1795,
    1796,  1223,  1224,   937,   938,   939,   940,  1802,  1804,  1806,
    1807,  1808,  1809,  1810,  1221,  1811,  1812,  1225,  1813,  1814,
    1815,  1816,  1817,  1818,  1226,  1820,  1821,  1822,  1823,  1824,
    1825,  1826,  1827,  1244,  1246,  1830,   941,  1832,  1833,  1245,
    1835,  1836,  1837,  1249,   942,  1252,  1253,  1254,  1255,  1256,
    1257,  1258,  1259,  1260,  1261,   943,  1262,  1263,  1264,   944,
    1265,  1266,  1267,  1268,  1269,  1270,  1271,  1862,  1272,  1863,
    1273,  1274,   668,  1284,  1868,  1276,  1870,  1871,  1277,  1280,
    1278,  1281,  1285,  1293,  1289,  1287,  1878,  1290,  1292,  1294,
    1295,  1291,  1297,  1296,  1300,  1298,  1301,  1302,  1303,  1304,
    1299,  1305,   945,  1306,   946,   947,   948,  1307,  1308,  1309,
    1310,  1311,  1312,  1313,  1314,   949,   950,  1315,  1316,  1317,
    1318,   951,   952,   953,   954,  1101,  1319,  1320,  1321,  1342,
    1322,  1323,  1324,  1325,  1326,  1327,   955,   956,   957,   958,
     959,  1328,   960,   961,   962,  1329,  1330,  1331,  1332,   963,
     964,   965,   966,   967,   968,   969,   970,   971,   972,   973,
     974,   975,   976,   977,  1333,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
    1334,  1335,  1336,  1337,  1338,   234,   236,  1339,  1340,  1341,
    1491,  1343,  1345,  1347,  1377,  1346,  1357,  1358,  1363,  1364,
    1348,   356,   358,   360,   362,   364,   366,   368,   370,   372,
     374,   376,   378,   380,  1349,   417,    34,   297,   298,   299,
     300,   301,   302,   303,   304,   305,    44,   306,   307,    47,
     308,   309,   310,   311,   312,   313,   314,  1350,  1351,  1352,
    1353,  1354,  1355,  1356,  1359,  1360,   494,    34,   297,   298,
     299,   300,   301,   302,   303,   304,   305,    44,   306,   307,
      47,   308,   309,   310,   311,   312,   472,   314,  1362,  1365,
    1366,  1373,  1374,  1375,   978,  1376,   495,   496,   497,   498,
     499,  1378,   500,   501,   502,   503,   504,   505,   506,   507,
     508,   509,   510,   511,   785,   786,   787,   788,   789,   790,
     791,   792,   793,  1380,   794,   795,   796,   797,   798,   799,
     800,   801,   802,   803,   804,   805,   806,   807,   808,   809,
     810,   811,   812,   813,   814,  1381,  1382,  1383,  1384,  1385,
    1391,  1392,  1393,  1395,  1396,  1397,  1398,  1399,  1400,  1401,
     815,   816,  2155,  2156,  1402,  1403,  1405,  1406,  1408,  1409,
    1410,  1411,  1412,  1413,  1414,  1415,  1416,  1417,  1418,  1419,
    1420,  1421,  1422,  1423,  1424,  1425,  1426,  1427,  1428,  1429,
     512,  1430,  1431,  1432,  1433,  1434,  1435,  1436,  1437,  1438,
    2427,  1439,  1440,  1441,  1442,  1443,  1444,  2153,   513,  2428,
    1445,  2434,  1446,  1447,  1448,  1451,  1452,  1453,  1454,  1455,
    1503,  1694,  1460,  1457,  1462,  1463,  1456,  2175,  1465,  1461,
    1466,  1467,  1468,  1470,  1472,  1648,  1650,  1476,  1473,  1471,
    1474,  1525,  1501,  1490,  1526,  1562,  1563,  1702,  1705,  1629,
    1704,  1516,  1707,  1711,  1712,  1683,  1713,  1531,  1684,  1515,
    1762,  1797,  1778,  1861,  1876,  1879,  1880,  1885,  1882,  1883,
    1777,  1887,  1884,  1889,  1886,  1686,  1687,  1890,  1888,  1891,
    1892,  1893,  1894,  1897,  1895,  1689,  1896,  1898,  1690,  1916,
    1691,  1899,  1900,  1903,  1901,  1902,  1904,  1905,  1906,  1909,
    1910,  1706,  1911,  2045,  1912,  1915,  1919,  1869,  1913,  1914,
    1920,  2262,  2263,  2264,  2265,  1921,  2266,  1922,  2267,  1923,
    1924,  1925,  1926,  1927,  2270,  2271,  2272,  2079,  1931,  2273,
    2274,  2275,  2276,  1928,  2277,  1932,  2278,  1933,  2279,  1934,
    1937,  2280,  2281,  2282,  2283,  1938,  1939,  1940,  2284,  1941,
    1942,  2286,  1943,  2157,  1944,  1945,  1946,  1947,  1948,  1949,
    1950,  1951,  2290,  1952,  2291,  1953,  1954,  1955,  2295,  2296,
    1956,  2297,  2298,  2299,  2300,  2301,  2302,  2303,  2304,  2305,
    2306,  2307,  2308,  1957,  2309,  1958,  1959,  1960,  1961,  1963,
    1962,  1964,  1965,  2317,  2318,  2319,  2320,  2321,  2322,  2323,
    2324,  2325,  1966,  1967,  1968,  1969,  1970,  1971,  1972,  1973,
    1974,  1975,  1976,  1977,  1865,  2334,  2335,  2336,  2337,  1978,
    1979,  1980,  2340,  2341,  2342,  2343,  1981,  1984,  1985,  1986,
    1987,  1988,  2348,  2349,  2350,  2351,  2352,  2353,  2354,  2355,
    2356,  2357,  2358,  1989,  1990,  1991,  1992,  1993,  1994,  1995,
    2359,  2360,  2361,  1996,  2362,  2363,  1997,  2365,  2366,  1998,
    1999,  2368,  2000,  2369,  2001,   924,  2288,  2002,  2003,  2004,
    2005,  2006,  2007,  2008,  2372,  2009,  2010,  2374,  2011,  2012,
    2013,  2014,  2015,  2016,  2017,  2379,  2381,  2383,  2018,  2019,
    2384,  2020,  2387,  2021,  2029,  2047,  2022,  2025,  2393,  2026,
    2027,  2394,  2395,  2028,  2396,  2397,  2398,  2034,  2035,  2036,
    2041,  2042,  2048,  2049,  2050,  2051,  2289,  2052,  2053,  2054,
    2404,  2158,  2405,  2426,  3301,  1787,  2055,  2056,  2057,  2058,
    2063,  2064,  2065,  2066,  2067,  2068,  2406,  2069,  2072,  2073,
    2074,  2075,  2076,  2077,  2081,  2083,  1936,  2089,  2090,  2093,
    2094,  2408,  2095,  2409,  2096,  2097,  2098,  2099,  2410,  2100,
    2101,  2102,  2103,  2104,  2411,  2105,  2107,  2108,  2413,  2414,
    2106,  2415,  2417,  2418,  2109,  2419,  2420,  2110,  2111,  2423,
    2424,  2112,  2425,  2113,  2114,  2115,  2116,  2117,  2118,  2119,
    2120,  2159,  2122,  2124,  2160,  2435,  2436,  2121,  2125,  2438,
    2123,  2439,  2440,  2441,  2126,  2127,  2128,  2129,  2130,  2442,
    2131,  2132,  2443,  2133,  2444,  2134,  2135,  2136,  2445,  2446,
    2447,  2138,  2448,  2144,  2139,  2142,  2143,  2145,  2449,  2151,
    2146,  2450,  2147,  2451,  2148,  2452,  2453,  2454,  2149,  2150,
    2152,  2165,  2161,  2166,  2167,  2168,  2455,  2456,  2169,  2173,
    2457,  2174,  2177,  2180,  2181,  2458,  2459,  2460,  2461,  2462,
    2463,  2182,  2464,  2465,  2466,  2184,  2467,  2468,  2469,  2470,
    2471,  2186,  2189,  2472,  2473,  2474,  2475,  2193,  2478,  2190,
    2194,  2195,  2196,  2199,  2200,  2201,  2204,  2208,  2482,  2479,
    2209,  2205,  2210,  2803,  2206,  2207,  2211,  2212,  2213,  2214,
    2215,  2216,  2218,  2219,  2649,  2221,  2222,  2217,  2223,  2995,
    2220,  2650,  2241,  2226,   404,  2227,  2228,  2229,  2511,  2230,
    2233,  2234,  2237,  2238,  2239,  2240,  2244,  2245,  2246,  2247,
    2248,  2249,  2250,  2251,  2253,  2371,  2256,  2254,  2255,  2257,
    2259,  2376,  2377,  2258,  2378,  2399,  2400,  2412,   901,  2480,
    2483,  2485,   900,  2487,  2481,  2484,  2489,  2491,  2486,  2492,
    2488,  2490,  2493,  2494,  2495,  2497,  2496,  2498,  2502,  2651,
    2499,  2652,  2500,  2501,  2507,  2503,  2504,  2505,  2506,  2508,
    2509,  2510,  2512,  2513,  2514,  2515,  2520,  2518,  2521,  2519,
    2522,  2523,  2525,  2524,   405,  2526,   406,   407,   904,  2527,
    2528,  2529,  2530,  2531,  2532,  2533,  2534,  2535,  2536,  2537,
    2647,  2648,  2663,  2538,  2539,  2540,  2541,  2654,  2542,  2543,
    2544,  2545,  2546,  2547,  2548,  2549,  2550,  2551,  2552,  2553,
    2554,  2556,  2620,  2555,  2557,  2558,  2559,  2560,  2561,  2562,
    2564,  2563,  2565,  2566,  2567,  2568,  2569,  2570,  2653,  2918,
    2574,  2571,  2575,  2576,  2572,  2573,  2646,  2577,  2578,  2579,
    2580,  2583,  2584,  2587,   902,   905,  2590,  2585,  2586,  2593,
    2588,  2589,  2594,  2591,  2592,  2595,  2596,  2597,  2598,  2599,
    2600,  2605,  2602,  2604,  2606,  2608,  2609,  2610,  2611,  2612,
    2613,  2614,  2615,  2617,  2618,  2616,  2619,  2621,  2623,  2624,
    1672,  2622,  2627,  1668,  1793,  2636,  2625,  2626,  2645,  2628,
    2629,   903,  2637,  2638,  2707,  2639,  2708,  2640,  2709,  2641,
    2710,  2642,  2643,  2644,  2655,  2711,  2712,  2656,  2713,  2714,
    2715,  2716,  2657,  2717,  2718,  2719,  2720,  2658,  2662,  2664,
    2721,  2665,  2666,  2722,  2724,  2667,  2668,  2669,  2670,  2730,
    2671,  2672,  2673,  2674,  2731,  2675,  2732,  2733,  2734,  2735,
    2736,  2737,  2738,  2739,  2676,  2740,  2742,  2744,  2745,  2746,
    2747,  2748,  2749,  2750,  2751,  2752,  2753,  2754,  2755,  2677,
    2756,  2678,  2679,  2680,  2681,  2682,  2683,  2684,  2762,  2685,
    2686,  2689,  2763,  2764,  2690,  2691,  2692,  2693,  2694,  2697,
    1669,  1671,  2767,  2768,  2698,  2699,  2700,  2701,  2702,  2703,
    2706,  2786,  2769,  2770,  2771,  2772,  2773,  2840,  2774,  2775,
    2843,  2776,  2777,  2844,  2845,  2846,  2778,  2779,  2847,  2850,
    2848,  2780,  2781,  2782,  2783,  2725,  2849,  2851,  2726,  2852,
    2853,  2854,  2855,  2856,  2858,  2859,  2785,  2860,  1708,  2373,
    2863,  2864,  2787,  2878,  2865,  2874,  2789,  2875,  2790,  2791,
    2876,  2877,  2883,  2884,  2885,  2886,  2889,  2890,  2796,  2797,
    2798,  2891,  2892,  2801,  2802,  2893,  2894,  2895,  2896,  2897,
    2898,  2899,  2900,  2903,  2901,  2902,  2804,  2904,  2806,  2905,
    2807,  2808,  2906,  2809,  2810,  2811,  2812,  2813,  2814,  2815,
    2816,  2907,  2817,  2818,  2819,  2820,  2821,  2822,  2823,  2824,
    2825,  2908,  2826,  2827,  2828,  2829,  2909,  2910,  2911,  2912,
    2913,  2914,  2916,  2915,  2917,  2920,  2832,  2833,  2834,  2835,
    2921,  2919,  2838,  2839,  2922,  2923,  2925,  2924,  2926,  2927,
    2928,  2929,  2931,  2930,  2934,  2937,  2935,   408,  2942,  2936,
    2943,  1514,  2938,  2941,  2948,  2945,  2949,  2946,  2947,  2950,
    2952,  2951,  2953,  2954,  2955,  2956,  2957,  2958,  2959,  2960,
    2961,  2962,  2963,  2964,  2965,  1646,  1670,     0,   409,     0,
    2971,  2966,  2967,  2968,  2969,  2970,  2944,  2972,  2973,  2974,
    2975,  2976,  2977,  2979,  2980,  2978,  3067,  3066,  3068,   410,
    3072,  3069,  3073,  3070,  3074,  3071,  3080,  3075,     0,  3078,
       0,  3079,     0,  3083,  3084,  3089,  3090,  3091,  3092,  3093,
    3094,  3095,  3096,  3097,  3098,  3099,  3102,  3100,  3104,  3105,
    2044,  3106,  3146,  3107,     0,     0,  3108,  3109,  3110,  3111,
    3112,  3113,  3114,  3117,  3118,  3121,  3122,  3123,  3124,  3125,
    3127,  3128,  3130,  3131,  3126,  3132,  3133,  3129,  3137,  3138,
    3136,  3141,     0,  3139,     0,     0,  3140,  3147,  3142,  3143,
    3144,  3145,  2981,  2982,  3148,  2983,  2984,  3149,  2985,  2986,
    3151,  2987,  2988,  2989,  3150,  2990,  2991,  3152,  3153,  2993,
    3154,  3155,  3156,  3215,  2996,  2997,  3216,  2998,  3217,  2999,
    3218,  3000,  3219,  3001,  3002,  3003,  3004,  3005,  3220,  3221,
    3222,  3006,  3007,  3008,  3009,  3010,  3011,  3223,  3012,  3014,
    3016,  3018,  3019,  3020,  3021,  3224,  3022,  3023,  3024,  3025,
    3026,  3226,  3028,  3225,  3227,  3228,  3229,  3029,  3030,  3230,
    3031,  3032,  3033,  3034,  3035,  3036,  3231,  3037,  3038,  3039,
    3040,  3232,  3041,  3235,  3236,  3237,  3043,  3238,  3044,  3240,
    3045,  3241,  3239,  3046,  3242,  3047,  3048,  3243,  3049,  3244,
    3245,  3246,  3247,  3248,  3249,  3052,     0,  3054,  3251,  2992,
    3055,  3056,  3250,  2994,  3253,  3252,  3254,  3255,  3256,  3257,
    3259,  3258,  3260,  3266,  3261,  3262,  3057,  3058,  3059,  3060,
    3061,  3263,  3264,  3265,  3267,  3268,  3063,  3064,  3065,  3269,
    3272,  3273,  3274,  3309,  3310,  3311,  3312,  3314,  3315,  3317,
    3318,  3316,  3319,  3320,  3321,  3324,     0,  3322,  3327,  3323,
       0,     0,  3325,  3326,     0,  3330,  3333,  3334,  3335,  3337,
    3338,  3341,  3342,  3345,  3367,  3368,  3369,  3370,  3371,  3372,
    3373,     0,  3376,  3377,  3378,     0,  3374,  3375,  3382,     0,
       0,  3379,  3380,  3381,  3385,  3383,  3384,  3401,  3402,  3403,
    3405,  3404,  3406,  3407,  3408,  3410,  3420,  3409,  3411,  3419,
    3424,  3425,     0,  3421,  3422,  3423,  3433,     0,  3430,  3431,
    3432,  3437,  3443,  3438,  3439,  3444,  3157,  3445,  3449,  3158,
    3159,  3160,  3448,  3451,     0,  3161,     0,  3162,  3163,     0,
       0,     0,     0,  3166,  3167,     0,  3168,     0,  3169,  3170,
    3171,  3172,  3173,  3174,     0,  3175,  3176,  3177,  3178,  3179,
    3180,  3016,     0,  3016,     0,     0,  3016,  3016,  3185,  3186,
    3187,     0,     0,     0,     0,     0,  3192,  3193,     0,     0,
    3194,     0,     0,     0,  3195,  3196,  3197,     0,     0,  3198,
       0,     0,     0,     0,     0,  3199,  3200,     0,     0,  3201,
    3202,     0,     0,  3204,     0,  3206,  3207,     0,     0,  3208,
    3209,     0,  3210,     0,  3212,  3213,  3214,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3165,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3275,  3276,  3277,  3278,
       0,  3280,  3281,     0,     0,  3282,     0,     0,     0,     0,
       0,     0,  3283,     0,  3284,     0,  3285,     0,     0,  3286,
       0,     0,     0,     0,  3016,     0,     0,     0,     0,  3288,
    3289,     0,  3290,     0,  3291,     0,  3292,  3293,  3294,     0,
    3295,  3296,     0,  3298,     0,  3300,     0,  3302,  3303,  3304,
       0,     0,  3306,  3307,  3308,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3346,     0,     0,     0,  3348,  3349,     0,     0,     0,
    3350,     0,  3351,  3352,     0,  3353,  3354,     0,     0,     0,
    3356,     0,     0,  3358,  3359,  3360,     0,  3361,  3362,     0,
    3363,  3364,     0,     0,  3365,  3366,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3390,     0,     0,
       0,     0,     0,  3391,  3392,  3393,     0,     0,     0,  3394,
    3395,     0,     0,  3397,  3398,     0,     0,  3399,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3412,  3413,     0,  3414,     0,  3415,     0,     0,  3417,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3426,
       0,  3427,  3428,  3429,     0,   178,     0,   231,   231,   231,
    3434,  3435,  3436,     0,     0,     0,     0,  3440,  3441,  3442,
       0,     0,     0,   247,  3446,  3447,   255,     0,  3450,   262,
       0,     0,   262,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,     2,     3,     4,     0,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     315,   262,     0,     0,     0,     0,     0,    14,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    25,    26,     0,     0,     0,    29,    30,     0,     0,
      31,     0,    32,     0,    34,   203,   204,   205,   238,   206,
     207,     0,   233,   209,     0,     0,     0,     0,     0,     0,
     210,   211,     0,   212,   213,     0,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,     0,
       0,     0,     0,   262,   262,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   178,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   231,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    63,    64,    65,    66,    67,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   214,     0,     0,   231,   231,     0,     0,     0,
       0,    72,     0,   215,     0,     0,     0,     0,     0,     0,
       0,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   262,     0,
     262,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    77,     0,     0,     0,     0,   262,   262,
       0,   315,   315,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   262,     0,     0,     0,     0,     0,     0,     0,
       0,   669,   669,   669,     0,     0,    78,     0,    79,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   755,   669,   755,   755,   755,
     755,   755,   755,   767,     0,     0,     0,     0,   821,   822,
     823,   755,   826,   827,   828,   829,   830,   831,   832,   833,
       0,     0,     0,     0,   838,   840,     0,     0,   262,   755,
     863,     0,     0,     0,     0,     0,     0,     0,     0,    92,
      93,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   315,   262,     0,     0,     0,     0,
       0,   262,     0,   879,   880,   881,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   262,   262,
     262,   262,     0,     0,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,     0,     0,     0,     0,     0,
      94,    95,     0,     0,   755,   755,   669,     0,   231,     0,
     231,   231,     0,     0,   755,   669,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   231,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,     0,
     106,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     109,   110,   111,   112,   113,   114,   115,   116,     0,     0,
     117,   118,   119,   120,   121,   122,   123,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   130,   131,     1,     0,     2,     3,     4,     0,
       5,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   262,     0,     0,     0,    15,
       0,  1100,  1100,   669,  1108,   262,     0,     0,     0,     0,
       0,     0,     0,   144,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    32,     0,    34,   203,   204,   205,     0,
     206,   207,     0,   233,   209,     0,     0,     0,     0,     0,
       0,   210,   211,     0,   212,   213,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1100,  1100,  1100,  1100,  1100,  1100,
    1100,  1100,  1100,  1100,  1100,  1100,  1100,   755,     0,     0,
       0,     0,     0,    63,    64,    65,    66,    67,     0,     0,
       0,     0,  1100,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   214,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   215,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   262,     0,     0,     0,     0,     0,     0,   755,
     755,  1283,     0,     0,    77,     0,   755,   755,   755,   755,
     755,   755,   755,   755,   755,   755,   755,   755,   755,   755,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,     0,    79,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,    93,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     262,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   262,     0,
       0,    94,    95,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   262,     0,     0,     0,   262,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
       0,   106,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   109,   110,   111,   112,   113,   114,   115,   116,     0,
       0,   117,   118,   119,   120,   121,   122,   123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   262,
       0,     0,     0,   130,   131,     0,     0,     0,     0,  1100,
    1100,   669,   315,   262,     0,     0,     0,     0,     0,     0,
     262,     0,     0,     0,     0,  1100,  1100,  1100,  1100,  1100,
    1100,  1100,  1100,  1100,  1100,  1100,  1100,  1100,     0,  1100,
       0,     0,     0,     0,   144,     0,     0,     0,     0,     0,
       0,     0,   262,     0,     0,     0,     0,     0,     0,  1479,
       0,     0,     0,     0,     0,  1485,     0,     0,  1489,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   755,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   262,     0,   262,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1529,     0,     0,     0,     0,
     669,   669,  1536,   755,   755,  1539,  1540,  1541,  1542,  1543,
     755,  1545,  1546,  1547,  1548,  1549,     0,  1552,  1553,  1554,
    1555,     0,   755,   755,  1561,     0,     0,  1564,  1565,  1566,
    1567,  1568,  1569,  1570,  1571,  1572,   755,  1574,  1575,  1576,
    1577,  1578,  1579,  1580,  1581,  1582,  1583,  1584,  1585,  1586,
     755,   755,   755,   755,   755,  1592,  1593,  1594,  1595,  1596,
       0,     0,   262,   262,  1601,  1602,  1603,  1604,  1605,  1606,
    1607,  1608,  1609,  1610,  1611,  1612,  1613,   755,  1615,  1616,
    1617,  1618,  1619,  1620,   755,   755,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     755,   755,   755,  1626,   755,   755,     0,   755,   755,   755,
     755,   262,     0,   669,     0,   669,  1644,   755,   755,  1100,
    1100,  1100,  1100,  1100,  1100,  1100,  1100,  1100,  1100,   755,
     755,   755,   755,   755,     0,     0,     0,   262,   262,   262,
       0,     0,     0,   262,     0,     0,     0,     0,     0,     0,
     262,     0,     0,     0,     0,   262,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     755,     0,     0,   755,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1714,     0,  1716,     0,     0,     0,
    1720,  1721,  1722,  1723,     0,     0,     0,     0,     0,     0,
       0,  1731,     0,  1733,  1734,  1735,  1737,  1738,  1740,  1742,
    1743,  1744,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1760,     0,   755,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1770,
    1771,  1772,     0,     0,     0,     0,     0,     0,     0,     0,
     262,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   262,  1791,
    1792,     0,     0,     0,     0,     0,     0,   262,  1799,     0,
    1800,  1801,  1803,  1805,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   755,
       0,     0,     0,     0,     0,     0,     0,     0,  1828,   755,
       0,   755,     0,     0,  1834,     0,     0,     0,   755,  1839,
       0,     0,     0,   755,   755,   755,   262,   755,  1848,     0,
    1850,     0,     0,   755,   262,     0,   755,   755,   755,   755,
     755,     0,     0,     0,     0,   262,     0,   669,   262,     0,
       0,     0,     0,   262,   262,   262,     0,   262,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
    2039,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   755,
       0,     0,   755,     0,     0,     0,   755,  2085,  2086,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     0,     2,
     200,   201,     0,   202,     0,     0,     0,     0,     0,     0,
       0,     0,  1641,     0,     0,     0,     0,     0,     0,     0,
       0,    14,    15,     0,     0,     0,     0,   755,     0,     0,
       0,     0,     0,     0,     0,    25,    26,     0,     0,     0,
      29,    30,     0,   262,    31,     0,    32,     0,    34,   203,
     204,   205,   238,  1642,   207,     0,   208,   209,     0,     0,
       0,     0,   669,     0,   210,   211,     0,   212,   213,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    63,    64,    65,    66,
      67,   262,     0,     0,     0,  2261,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   214,  2268,  2269,     0,
       0,     0,     0,     0,     0,    72,     0,   215,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2285,     0,   755,     0,     0,
       0,     0,     0,     0,   669,     0,     0,     0,     0,     0,
       0,   755,  2294,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    77,     0,     0,
    2310,  2311,   755,   755,  2314,  2315,  2316,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2326,     0,  2327,  2328,  2329,  2330,  2331,     0,  2332,  2333,
      78,     0,    79,     0,   755,   755,     0,     0,     0,     0,
       0,  2344,   262,     0,     0,  2346,  2347,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2364,     0,     0,  2367,     0,     0,     0,     0,   755,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   755,     0,  2375,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    92,    93,   262,     0,     0,   262,   262,
     262,   262,   262,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   755,     0,     0,
       0,     0,     0,  2403,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2407,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   669,     0,     0,     0,
       0,     0,  2421,  2422,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,  2437,   106,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   109,   110,   216,   217,   218,   219,
     220,   221,     0,     0,   222,   223,   224,   225,   226,   227,
     228,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   130,   131,     0,     0,
       0,     0,     1,     0,     2,   200,   201,     0,   202,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    14,    15,     0,     0,
       0,   669,   755,     0,     0,     0,     0,   144,     0,     0,
      25,    26,     0,     0,     0,    29,    30,     0,     0,    31,
       0,    32,     0,    34,   203,   204,   205,   238,   206,   207,
       0,   208,   209,     0,     0,     0,     0,     0,     0,   210,
     211,     0,   212,   213,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    63,    64,    65,    66,    67,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   214,     0,     0,     0,     0,     0,     0,     0,     0,
      72,     0,   215,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    77,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,     0,    79,     0,     0,
       0,     0,     0,     0,     0,   262,   262,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2723,     0,
       0,     0,  2727,  2729,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2741,  2743,     0,     0,     0,     0,     0,     0,    92,    93,
       0,     0,     0,     0,     0,     0,  2757,  2758,  2759,  2760,
    2761,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   755,     0,     0,   755,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   262,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2788,     0,     0,     0,     0,     0,   755,     0,   755,     0,
     755,     0,   755,     0,     0,     0,  2799,  2800,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,     0,   106,
       0,     0,  2805,     0,     0,     0,     0,     0,     0,   109,
     110,   216,   217,   218,   219,   220,   221,     0,     0,   222,
     223,   224,   225,   226,   227,   228,     0,     0,     0,     0,
       0,     0,     0,  2830,     0,     0,     0,     0,     0,   755,
       0,   130,   131,     0,     0,   755,   755,     0,     0,     0,
       0,   162,     0,     0,   162,   162,   162,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   162,     0,     0,     0,     0,     0,     0,
       0,     0,   144,     0,     0,     0,     0,     0,     1,     0,
       2,   200,   201,     0,   202,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    14,    15,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    25,    26,     0,     0,
       0,    29,    30,     0,     0,    31,     0,    32,     0,    34,
     203,   204,   205,   238,  1642,   207,     0,   208,   209,     0,
       0,     0,     0,     0,     0,   210,   211,     0,   212,   213,
       0,     0,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   162,     0,     0,
       0,     0,     0,  2727,     0,     0,     0,  2727,     0,     0,
       0,     0,     0,   162,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    63,    64,    65,
      66,    67,     0,  1644,  1644,  1644,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3027,   214,     0,     0,
       0,     0,     0,     0,     0,     0,    72,     0,   215,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   262,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   755,  3051,     0,     0,     0,
       0,  3053,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    77,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   755,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   162,     0,     0,   667,   667,   667,
       0,    78,     0,    79,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   754,   667,   754,   754,   754,   754,   754,   754,     0,
       0,     0,     0,     0,     0,     0,   754,   754,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   859,     0,   754,     0,     0,     0,     0,
       0,     0,     0,     0,    92,    93,     0,     0,     0,     0,
       0,     0,     0,     0,   262,     0,     0,  2727,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1644,     0,  1644,     0,
       0,  1644,  1644,     0,     0,     0,  3188,  3189,  3190,  3191,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3203,     0,  3205,
     754,   754,   667,     0,   162,   859,   162,   162,   755,     0,
     754,  1034,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,     0,   106,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   109,   110,   216,   217,   218,
     219,   220,   221,     0,     0,   222,   223,   224,   225,   226,
     227,   228,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   130,   131,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1644,
       0,     0,     0,     0,     0,     0,     0,   667,   667,   667,
       0,     0,     0,     0,     0,     0,     0,  3297,   144,  3299,
       0,     0,     0,     0,     0,     0,   755,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   755,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   262,
       0,     0,     0,     0,     0,     0,   197,     0,     0,     0,
       0,     0,     0,     0,   755,     0,     0,   755,     0,     0,
       0,     0,     0,     0,   248,     0,     0,     0,     0,     0,
     667,   667,   667,   667,   667,   667,   667,   667,   667,   667,
     667,   667,   667,   754,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   667,     0,
       0,     0,     0,     0,     0,     0,  3396,     0,     0,     0,
       0,     0,     0,     0,   755,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3416,     0,     0,     0,   755,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   754,   754,   754,     0,     0,
       0,     0,   754,   754,   754,   754,   754,   754,   754,   754,
     754,   754,   754,   754,   754,   754,     0,     0,     0,     0,
       0,     0,   197,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   859,   859,   859,     0,   859,   859,   859,
     859,   859,   859,   859,   859,   859,   859,   859,   859,   859,
     859,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   534,   535,     0,     0,
       0,     0,   689,   689,   689,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   757,   689,   757,   757,
     757,   757,   757,   757,     0,     0,     0,     0,     0,     0,
       0,   757,   757,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     757,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1034,  1034,  1034,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1034,  1034,  1034,  1034,  1034,  1034,  1034,  1034,  1034,
    1034,  1034,  1034,  1034,     0,  1034,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   757,   757,   689,     0,     0,
       0,     0,     0,     0,  1000,   757,  1039,     0,     0,     0,
       0,     0,     0,     0,   754,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   667,   667,     0,   754,
     754,     0,     0,     0,     0,     0,   754,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   754,   754,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   754,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   689,   689,   689,  1109,   754,   754,   754,   754,
     754,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   754,     0,     0,     0,     0,     0,     0,
     754,   754,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   754,   754,   754,     0,
     754,   754,     0,   754,   754,   754,   754,     0,     0,   667,
       0,   667,     0,   754,   754,   667,   667,   667,   667,   667,
     667,   667,   667,   667,   667,   754,   754,   754,   754,   754,
       0,     0,     0,     0,     0,   689,   689,   689,   689,   689,
     689,   689,   689,   689,   689,   689,   689,   689,   757,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   689,     0,     0,   754,     0,     0,   754,
       0,     0,     0,     0,   256,   259,   261,     0,     0,   265,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   317,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   754,     0,     0,     0,     0,
     757,   757,   757,     0,     0,     0,     0,   757,   757,   757,
     757,   757,   757,   757,   757,   757,   757,   757,   757,   757,
     757,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     387,   388,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   754,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   754,     0,   754,     0,     0,
       0,     0,     0,     0,   754,     0,     0,     0,     0,   754,
     754,   754,     0,   754,     0,     0,     0,     0,     0,   754,
       0,     0,   754,   754,   754,   754,   754,     0,     0,     0,
       0,     0,     0,   667,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   466,     0,   468,     0,     0,
       0,     0,     0,     0,     0,     0,   667,     0,     0,     0,
       0,     0,     0,     0,     0,   470,   471,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   478,
       0,     0,     0,     0,     0,     0,     0,     0,   666,   666,
     666,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     689,   689,   689,     0,     0,   861,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   689,   689,   689,   689,
     689,   689,   689,   689,   689,   689,   689,   689,   689,     0,
     689,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   871,     0,     0,     0,     0,     0,   877,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   883,     0,     0,   887,   888,   757,
       0,     0,     0,     0,     0,     0,  1000,     0,     0,     0,
       0,     0,  1512,     0,     0,   754,     0,     0,   754,     0,
       0,     0,   754,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1033,     0,     0,     0,     0,     0,     0,     0,
       0,   689,   689,     0,   757,   757,     0,     0,     0,     0,
       0,   757,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   757,   757,     0,     0,     0,     0,     0,
       0,     0,     0,   754,     0,     0,     0,   757,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   757,   757,   757,   757,   757,     0,     0,     0,     0,
       0,  1597,  1598,     0,     0,     0,     0,     0,   667,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   757,     0,
       0,  1094,  1096,     0,     0,   757,   757,     0,     0,     0,
       0,     0,  1111,     0,     0,     0,     0,     0,     0,     0,
       0,   757,   757,   757,     0,   757,   757,     0,   757,   757,
     757,   757,     0,     0,   689,     0,   689,     0,   757,   757,
     689,   689,   689,   689,   689,   689,   689,   689,   689,   689,
     757,   757,   757,   757,   757,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   757,     0,     0,   757,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   754,     0,     0,     0,     0,     0,     0,
     667,     0,     0,     0,     0,     0,     0,   754,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   754,   754,
     757,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   756,   760,   761,   762,   763,   764,   765,   766,
       0,     0,     0,     0,     0,     0,     0,   824,   825,     0,
     754,   754,     0,     0,     0,     0,     0,     0,     0,  1275,
       0,     0,     0,     0,     0,     0,   862,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     757,     0,     0,     0,     0,   754,     0,     0,     0,     0,
     757,     0,   757,     0,     0,     0,     0,   754,     0,   757,
       0,  1840,  1841,  1842,   757,   757,   757,     0,   757,     0,
    1849,     0,  1851,  1852,   757,     0,     0,   757,   757,   757,
     757,   757,     0,     0,     0,     0,     0,     0,   689,     0,
       0,     0,     0,   754,     0,     0,     0,     0,     0,     0,
       0,   926,   927,   929,     0,     0,     0,     0,     0,     0,
       0,  1003,  1036,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1369,     0,     0,
       0,   689,   667,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     0,     2,   200,
     201,     0,   202,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1394,     0,     0,     0,     0,
       0,    15,     0,     0,     0,     0,     0,     0,     0,     0,
    1105,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1404,     0,     0,    32,  1407,    34,   203,   204,
     205,     0,   206,   207,     0,   208,   209,     0,     0,     0,
       0,     0,     0,   210,   211,     0,   212,   213,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   667,   754,     0,
       0,  2040,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1450,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1111,     0,     0,     0,     0,     0,     0,  1450,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    63,    64,    65,    66,    67,
       0,     0,     0,     0,     0,     0,     0,     0,  1000,  1475,
     757,     0,     0,   757,     0,   214,     0,   757,     0,     0,
       0,     0,     0,     0,     0,     0,   215,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1521,
       0,  1524,     0,     0,     0,     0,     0,     0,   757,     0,
       0,     0,  1527,     0,     0,     0,    77,   666,  1105,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   689,     0,     0,     0,     0,     0,    78,
       0,    79,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1599,
    1600,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,    93,     0,     0,     0,     0,  1634,     0,
    1637,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1679,  1680,  1681,     0,     0,     0,
    1685,     0,     0,     0,     0,     0,     0,  1692,   757,     0,
       0,     0,  1697,     0,     0,   689,     0,     0,     0,     0,
       0,     0,   757,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   754,
       0,     0,   754,   757,   757,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,     0,   106,     0,   757,   757,     0,     0,     0,
       0,     0,     0,   109,   110,   216,   217,   218,   219,   220,
     221,     0,     0,   222,   223,   224,   225,   226,   227,   228,
       0,     0,   754,     0,   754,     0,   754,  1776,   754,     0,
       0,     0,     0,     0,     0,   130,   131,     0,     0,     0,
     757,     0,     0,     0,     0,  1790,     0,     0,  1105,     0,
       0,     0,   757,     0,  1798,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   144,     0,     0,     0,
       0,     0,     0,     0,     0,   754,     0,     0,   757,     0,
       0,   754,   754,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1846,     0,     0,     0,     0,     0,     0,
       0,  1855,     0,     0,     0,  1499,     0,     0,     0,     0,
       0,     0,  1864,     0,   666,  1867,     0,     0,     0,     0,
    1872,  1873,  1874,     0,  1875,     0,     0,     0,  1877,     0,
       0,     0,     0,     0,     0,     0,     0,   689,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1535,     0,
    1537,  1538,     0,     0,     0,     0,     0,  1544,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1559,
    1560,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1573,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1587,  1588,  1589,
    1590,  1591,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1614,     0,     0,     0,     0,     0,
       0,  1621,  1622,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   689,   757,     0,     0,     0,  1623,  1624,  1625,
       0,  1627,  1628,     0,  1630,  1631,  1632,  1633,     0,     0,
    1639,     0,  1640,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1709,     0,     0,
    1640,   754,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,   754,     2,   200,   201,     0,
    1045,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1761,     0,     0,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    32,     0,    34,   203,   204,   205,     0,
     206,   207,     0,   208,   209,     0,     0,     0,     0,     0,
       0,   210,   211,     0,   212,   213,     0,     0,     0,     0,
    2154,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1819,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1829,     0,  1831,     0,
       0,     0,     0,     0,     0,  1838,     0,     0,     0,     0,
    1843,  1844,  1845,     0,  1847,     0,     0,     0,     0,     0,
    1853,     0,     0,  1856,  1857,  1858,  1859,  1860,     0,     0,
       0,     0,     0,    63,    64,    65,    66,    67,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   214,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   215,     0,     0,     0,  2260,     0,
       0,     0,     0,     0,   754,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   757,     0,     0,   757,     0,     0,
       0,     0,     0,     0,    77,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,     0,    79,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   757,     0,   757,
       0,   757,     0,   757,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2345,
       0,     0,   754,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,    93,   754,     0,     0,     0,     0,     0,     0,     0,
     757,     0,     0,     0,     0,     0,   757,   757,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2380,  2382,
     754,     0,  2385,   754,  2386,  2388,  2389,  2390,  2391,  2392,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2080,     0,     0,     0,
       0,     0,     0,  2084,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     754,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
       0,   106,   754,     0,  2137,     0,     0,     0,     0,     0,
       0,   109,   110,   216,   217,   218,   219,   220,   221,     0,
       0,   222,   223,   224,   225,   226,   227,   228,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2176,
       0,     0,     0,   130,   131,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   144,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   757,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2287,     0,     0,     0,     0,     0,
       0,  1105,     0,     0,     0,     0,     0,     0,  2292,     0,
     757,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2312,
    2313,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2338,  2339,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2370,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1105,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2704,  2705,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   757,
       0,     0,     0,     0,     0,     0,     0,   402,     0,     0,
       0,     0,     0,     0,     1,     0,     2,     3,     4,     0,
       5,     0,     0,  2416,     0,     0,     0,     0,     0,     0,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,     0,     0,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,    29,    30,     0,
       0,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,     0,     0,
      57,    58,    59,    60,     0,    61,    62,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2784,     0,     0,   757,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2476,  2477,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   757,     0,     0,
       0,     0,     0,    63,    64,    65,    66,    67,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    68,     0,
       0,     0,     0,    69,     0,   757,     0,     0,   757,     0,
      70,    71,    72,    73,    74,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    75,
      76,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    77,   757,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   757,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,     0,    79,
       0,     0,     0,     0,     0,    80,    81,    82,    83,    84,
      85,     0,    86,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    87,    88,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,    91,
      92,    93,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    95,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3042,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
    2765,   106,   107,  2766,     0,   108,     0,     0,     0,     0,
       0,   109,   110,   111,   112,   113,   114,   115,   116,     0,
       0,   117,   118,   119,   120,   121,   122,   123,     0,   124,
       0,     0,     0,     0,   125,     0,   126,   127,     0,     0,
       0,   128,   129,   130,   131,     0,   132,     0,     0,     0,
       0,     0,     0,   133,   134,     0,     0,     0,     0,     0,
       0,     0,     0,  2792,     0,  2793,     0,  2794,     0,  2795,
     135,     0,     0,     0,     0,   136,   137,     0,   138,   139,
     140,   141,   142,   143,   144,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2831,     0,     0,     0,
       0,  3164,  2836,  2837,     0,     0,     0,     0,     0,     0,
       1,     0,     2,  1004,  1005,     0,  1006,     0,     0,     0,
    1007,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    14,    15,     0,     0,  1008,   551,
    1009,     0,     0,     0,     0,     0,     0,     0,    25,    26,
       0,     0,     0,    29,    30,     0,     0,    31,     0,    32,
       0,    34,   203,   204,   205,   238,   758,   207,  1010,   233,
     209,  1011,     0,     0,   554,     0,     0,   210,   211,  1012,
     212,   213,     0,     0,     0,     0,     0,     0,     0,     0,
    1013,     0,     0,  1014,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3279,     0,     0,     0,     0,     0,    63,
     555,    65,    66,    67,   556,   557,   558,   559,   560,   561,
     562,   563,     0,   564,     0,   565,   566,   567,   568,   569,
     570,   571,     0,   572,   573,     0,     0,     0,    72,     0,
     574,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,     0,     0,     0,     0,   588,
      77,     0,     0,     0,     0,     0,  3347,     0,     0,     0,
       0,     0,  3050,     0,     0,     0,     0,     0,     0,     0,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   600,   601,    78,   602,    79,   603,   604,   605,   606,
     607,     0,     0,     0,     0,     0,  3062,   608,     0,     0,
       0,   979,   980,   981,     0,     0,   609,   610,   611,   612,
     982,   983,   984,   985,   613,     0,     0,   986,   614,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   615,   616,   617,   618,     0,
       0,     0,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   628,   629,   630,     0,     0,    92,    93,   987,     0,
       0,   988,   989,   990,   991,     0,   992,   993,   631,   632,
    1015,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1016,    94,    95,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   633,   634,   635,   636,    96,  1017,    98,    99,
    1018,   101,   102,   103,   104,   105,     0,   106,     0,   637,
     638,     0,  1019,     0,     0,  3211,     0,   109,   110,  1020,
    1021,  1022,  1023,  1024,  1025,     0,     0,  1026,  1027,  1028,
    1029,  1030,  1031,  1032,   652,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   130,
     131,   653,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   654,   655,   656,   657,     0,   658,   659,     0,   995,
     996,   997,   660,   661,     0,   998,     0,   999,   662,   663,
     664,     0,     0,     0,     0,     1,     0,     2,  1004,  1005,
     144,  1006,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    14,
      15,     0,     0,   550,   551,     0,     0,     0,     0,     0,
       0,     0,     0,    25,    26,     0,     0,     0,    29,    30,
       0,     0,    31,  3305,    32,     0,    34,   203,   204,   205,
     238,   758,   207,   553,   233,   209,     0,     0,     0,   554,
       0,     0,   210,   211,     0,   212,   213,     0,     0,     0,
       0,     0,     0,  3336,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3355,     0,     0,  3357,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    63,   555,    65,    66,    67,   556,
     557,   558,   559,   560,   561,   562,   563,     0,   564,     0,
     565,   566,   567,   568,   569,   570,   571,     0,   572,   573,
       0,  3400,     0,    72,     0,   574,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3418,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
       0,     0,     0,     0,   588,    77,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   598,   599,   600,   601,    78,   602,
      79,   603,   604,   605,   606,   607,     0,     0,     0,     0,
       0,     0,   608,     0,     0,     0,     0,     0,     0,     0,
       0,   609,   610,   611,   612,     0,     0,     0,     0,   613,
       0,     0,     0,   614,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     615,   616,   617,   618,     0,     0,     0,   619,   620,   621,
     622,   623,   624,   625,   626,   627,   628,   629,   630,     0,
       0,    92,    93,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   631,   632,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    95,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   633,   634,   635,
     636,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,     0,   106,     0,   637,   638,     0,     0,     0,     0,
       0,     0,   109,   110,  1020,  1021,  1022,  1023,  1024,  1025,
       0,     0,  1026,  1027,  1028,  1029,  1030,  1031,  1032,   652,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   130,   131,   653,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   654,   655,   656,   657,
       0,   658,   659,     0,     0,     0,     0,   660,   661,     0,
       0,     0,     0,   662,   663,   664,     1,     0,     2,   546,
     547,     0,   548,     0,     0,   144,   549,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      14,    15,     0,     0,   550,   551,     0,     0,     0,     0,
       0,     0,     0,     0,    25,    26,     0,     0,     0,    29,
      30,     0,     0,    31,     0,    32,     0,    34,   203,   204,
     205,   238,   552,   207,   553,   208,   209,     0,     0,     0,
     554,     0,     0,   210,   211,     0,   212,   213,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    63,   555,    65,    66,    67,
     556,   557,   558,   559,   560,   561,   562,   563,     0,   564,
       0,   565,   566,   567,   568,   569,   570,   571,     0,   572,
     573,     0,     0,     0,    72,     0,   574,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,     0,     0,     0,     0,   588,    77,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   600,   601,    78,
     602,    79,   603,   604,   605,   606,   607,     0,     0,     0,
       0,     0,     0,   608,     0,     0,     0,     0,     0,     0,
       0,     0,   609,   610,   611,   612,     0,     0,     0,     0,
     613,     0,     0,     0,   614,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   615,   616,   617,   618,     0,     0,     0,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   628,   629,   630,
       0,     0,    92,    93,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   631,   632,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   633,   634,
     635,   636,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,     0,   106,     0,   637,   638,     0,     0,     0,
       0,     0,     0,   109,   110,   639,   640,   641,   642,   643,
     644,     0,     0,   645,   646,   647,   648,   649,   650,   651,
     652,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   130,   131,   653,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   654,   655,   656,
     657,     0,   658,   659,     0,     0,     0,     0,   660,   661,
       0,     0,     0,     0,   662,   663,   664,     1,     0,     2,
     546,   547,     0,   548,     0,     0,   144,  1635,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    14,    15,     0,     0,   550,   551,     0,     0,     0,
       0,     0,     0,     0,     0,    25,    26,     0,     0,     0,
      29,    30,     0,     0,    31,     0,    32,     0,    34,   203,
     204,   205,   238,  1636,   207,   553,   208,   209,     0,     0,
       0,   554,     0,     0,   210,   211,     0,   212,   213,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    63,   555,    65,    66,
      67,   556,   557,   558,   559,   560,   561,   562,   563,     0,
     564,     0,   565,   566,   567,   568,   569,   570,   571,     0,
     572,   573,     0,     0,     0,    72,     0,   574,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,     0,     0,     0,     0,   588,    77,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   600,   601,
      78,   602,    79,   603,   604,   605,   606,   607,     0,     0,
       0,     0,     0,     0,   608,     0,     0,     0,     0,     0,
       0,     0,     0,   609,   610,   611,   612,     0,     0,     0,
       0,   613,     0,     0,     0,   614,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   615,   616,   617,   618,     0,     0,     0,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   628,   629,
     630,     0,     0,    92,    93,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   631,   632,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   633,
     634,   635,   636,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,     0,   106,     0,   637,   638,     0,     0,
       0,     0,     0,     0,   109,   110,   639,   640,   641,   642,
     643,   644,     0,     0,   645,   646,   647,   648,   649,   650,
     651,   652,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   130,   131,   653,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   654,   655,
     656,   657,     0,   658,   659,     0,     0,     0,     0,   660,
     661,     0,     0,     0,     0,   662,   663,   664,     1,     0,
       2,   546,   547,     0,   548,     0,     0,   144,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    14,    15,     0,     0,   550,   551,     0,     0,
       0,     0,     0,     0,     0,     0,    25,    26,     0,     0,
       0,    29,    30,     0,     0,    31,     0,    32,     0,    34,
     203,   204,   205,   238,   758,   207,   553,   208,   209,     0,
       0,     0,   554,     0,     0,   210,   211,     0,   212,   213,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    63,   555,    65,
      66,    67,   556,   557,   558,   559,   560,   561,   562,   563,
       0,   564,     0,   565,   566,   567,   568,   569,   570,   571,
       0,   572,   573,     0,     0,     0,    72,     0,   574,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,     0,     0,     0,     0,   588,    77,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,    78,   602,    79,   603,   604,   605,   606,   607,     0,
       0,     0,     0,     0,     0,   608,     0,     0,     0,     0,
       0,     0,     0,     0,   609,   610,   611,   612,     0,     0,
       0,     0,   613,     0,     0,     0,   614,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   615,   616,   617,   618,     0,     0,     0,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   628,
     629,   630,     0,     0,    92,    93,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   631,   632,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     633,   634,   635,   636,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,     0,   106,     0,   637,   638,     0,
       0,     0,     0,     0,     0,   109,   110,   639,   640,   641,
     642,   643,   644,     0,     0,   645,   646,   647,   648,   649,
     650,   651,   652,     0,     0,     0,     0,     0,     1,     0,
       2,  1004,  1005,     0,  1006,     0,     0,   130,   131,   653,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   654,
     655,   656,   657,    15,   658,   659,   550,   551,     0,     0,
     660,   661,     0,     0,     0,     0,   662,   663,   664,     0,
       0,     0,     0,     0,     0,     0,     0,    32,   144,    34,
     203,   204,   205,     0,   758,   207,   553,   233,   209,     0,
       0,     0,   554,     0,     0,   210,   211,     0,   212,   213,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    63,   555,    65,
      66,    67,   556,   557,   558,   559,   560,   561,   562,   563,
       0,   564,     0,   565,   566,   567,   568,   569,   570,   571,
       0,   572,   573,     0,     0,     0,     0,     0,   574,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,     0,     0,     0,     0,   588,    77,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,    78,   602,    79,   603,   604,   605,   606,   607,     0,
       0,     0,     0,     0,     0,   608,     0,     0,     0,     0,
       0,     0,     0,     0,   609,   610,   611,   612,     0,     0,
       0,     0,   613,     0,     0,     0,   614,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   615,   616,   617,   618,     0,     0,     0,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   628,
     629,   630,     0,     0,    92,    93,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   631,   632,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     633,   634,   635,   636,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,     0,   106,     0,   637,   638,     0,
       0,     0,     0,     0,     0,   109,   110,  1020,  1021,  1022,
    1023,  1024,  1025,     0,     0,  1026,  1027,  1028,  1029,  1030,
    1031,  1032,   652,     0,     0,     0,     0,     0,     1,     0,
       2,   546,   547,     0,   548,     0,     0,   130,   131,   653,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   654,
     655,   656,   657,    15,   658,   659,   550,   551,     0,     0,
     660,   661,     0,     0,     0,     0,   662,   663,   664,     0,
       0,     0,     0,     0,     0,     0,     0,    32,   144,    34,
     203,   204,   205,     0,   758,   207,   553,   208,   209,     0,
       0,     0,   554,     0,     0,   210,   211,     0,   212,   213,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    63,   555,    65,
      66,    67,   556,   557,   558,   559,   560,   561,   562,   563,
       0,   564,     0,   565,   566,   567,   568,   569,   570,   571,
       0,   572,   573,     0,     0,     0,     0,     0,   574,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,     0,     0,     0,     0,   588,    77,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,    78,   602,    79,   603,   604,   605,   606,   607,     0,
       0,     0,     0,     0,     0,   608,     0,     0,     0,     0,
       0,     0,     0,     0,   609,   610,   611,   612,     0,     0,
       0,     0,   613,     0,     0,     0,   614,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   615,   616,   617,   618,     0,     0,     0,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   628,
     629,   630,     0,     0,    92,    93,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   631,   632,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     633,   634,   635,   636,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,     0,   106,     0,   637,   638,     0,
       0,     0,     0,     0,     0,   109,   110,   639,   640,   641,
     642,   643,   644,     0,     0,   645,   646,   647,   648,   649,
     650,   651,   652,     0,     0,     0,     0,     0,     1,     0,
       2,   546,   547,     0,  1929,     0,     0,   130,   131,   653,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   654,
     655,   656,   657,    15,   658,   659,   550,   551,     0,     0,
     660,   661,     0,     0,     0,     0,   662,   663,   664,     0,
       0,     0,     0,     0,     0,     0,     0,    32,   144,    34,
     203,   204,   205,     0,   758,   207,   553,   208,   209,     0,
       0,     0,   554,     0,     0,   210,   211,     0,   212,   213,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    63,   555,    65,
      66,    67,   556,   557,   558,   559,   560,   561,   562,   563,
       0,   564,     0,   565,   566,   567,   568,   569,   570,   571,
       0,   572,   573,     0,     0,     0,     0,     0,   574,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,     0,     0,     0,     0,   588,    77,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,    78,   602,    79,   603,   604,   605,   606,   607,     0,
       0,     0,     0,     0,     0,   608,     0,     0,     0,     0,
       0,     0,     0,     0,   609,   610,   611,   612,     0,     0,
       0,     0,   613,     0,     0,     0,   614,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   615,   616,   617,   618,     0,     0,     0,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   628,
     629,   630,     0,     0,    92,    93,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   631,   632,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     633,   634,   635,   636,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,     0,   106,     0,   637,   638,     0,
       0,     0,     0,     0,     0,   109,   110,   639,   640,   641,
     642,   643,   644,     0,     0,   645,   646,   647,   648,   649,
     650,   651,   652,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   130,   131,   653,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   654,
     655,   656,   657,     0,   658,   659,     0,     0,     0,     0,
     660,   661,     0,     0,     0,     0,   662,   663,   664,     1,
       0,     2,     3,     4,     0,     5,     0,     0,   144,     0,
       0,     0,     0,     0,     0,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,     0,     0,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,     0,    29,    30,     0,     0,    31,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,     0,     0,    57,    58,    59,    60,     0,
      61,    62,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,    64,
      65,    66,    67,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    68,     0,     0,     0,     0,    69,     0,
       0,     0,     0,     0,     0,    70,    71,    72,    73,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    75,    76,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    77,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    78,     0,    79,     0,     0,     0,     0,     0,
      80,    81,    82,    83,    84,    85,     0,    86,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    87,    88,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    90,    91,    92,    93,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    94,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,     0,   106,   107,     0,     0,
     108,     0,     0,     0,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   116,     0,     0,   117,   118,   119,   120,
     121,   122,   123,     0,   124,     0,     0,     0,     0,   125,
       0,   126,   127,     0,     0,     0,   128,   129,   130,   131,
       1,   132,     0,   734,   735,     0,   736,     0,   133,   134,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   135,     0,     0,   550,   551,
     136,   137,     0,   138,   139,   140,   141,   142,   143,   144,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    34,     0,     0,     0,     0,   737,   207,   553,     0,
       0,     0,     0,     0,   554,     0,     0,     0,     0,     0,
     212,   213,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     738,     0,     0,     0,   556,   557,   558,   559,   560,   561,
     562,   563,     0,   564,     0,   565,   566,   567,   568,   739,
     570,   571,     0,   572,   573,     0,     0,     0,     0,     0,
     740,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,     0,     0,     0,     0,   588,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   600,   601,     0,   602,     0,   603,   604,   605,   606,
     607,     0,     0,     0,     0,     0,     0,   608,     0,     0,
       0,     0,     0,     0,     0,     0,   609,   610,   611,   612,
       0,     0,     0,     0,   613,     0,     0,     0,   614,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   615,   616,   617,   618,     0,
       0,     0,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   628,   629,   630,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   631,   632,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     0,     0,   734,   735,     0,
     736,     0,   633,   634,   635,   636,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,     0,     0,     0,   637,
     638,     0,   550,   551,     0,     0,     0,     0,     0,   741,
     742,   743,   744,   745,   746,     0,     0,   747,   748,   749,
     750,   751,   752,   753,   652,    34,     0,     0,     0,     0,
     737,   207,   553,     0,     0,     0,     0,     0,   554,     0,
       0,   653,     0,     0,   212,   213,     0,     0,     0,     0,
       0,   654,   655,   656,   657,     0,   658,   659,     0,     0,
       0,     0,   660,   661,     0,     0,     0,     0,   662,   663,
     664,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     144,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   738,     0,     0,     0,   556,   557,
     558,   559,   560,   561,   562,   563,     0,   564,     0,   565,
     566,   567,   568,   739,   570,   571,     0,   572,   573,     0,
       0,     0,     0,     0,   740,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,     0,
       0,     0,     0,   588,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,     0,   602,     0,
     603,   604,   605,   606,   607,     0,     0,     0,     0,     0,
       0,   608,     0,     0,     0,     0,     0,     0,     0,     0,
     609,   610,   611,   612,     0,     0,     0,     0,   613,     0,
       0,     0,   614,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   615,
     616,   617,   618,     0,     0,     0,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   628,   629,   630,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   631,   632,  1002,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     0,   734,   735,     0,   736,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   550,
     551,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   633,   634,   635,   636,
       0,     0,    34,     0,     0,     0,     0,   737,   207,   553,
       0,     0,     0,   637,   638,   554,     0,     0,     0,     0,
       0,   212,   213,   741,   742,   743,   744,   745,   746,     0,
       0,   747,   748,   749,   750,   751,   752,   753,   652,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   653,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   654,   655,   656,   657,     0,
     658,   659,     0,     0,     0,     0,   660,   661,     0,     0,
       0,     0,   662,   663,   664,     0,     0,     0,     0,     0,
       0,   738,     0,     0,   144,   556,   557,   558,   559,   560,
     561,   562,   563,     0,   564,     0,   565,   566,   567,   568,
     739,   570,   571,     0,   572,   573,     0,     0,     0,     0,
       0,   740,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,     0,     0,     0,     0,
     588,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   600,   601,     0,   602,     0,   603,   604,   605,
     606,   607,     0,     0,     0,     0,     0,     0,   608,     0,
       0,     0,     0,     0,     0,     0,     0,   609,   610,   611,
     612,     0,     0,     0,     0,   613,     0,     0,     0,   614,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   615,   616,   617,   618,
       0,     0,     0,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   628,   629,   630,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   631,
     632,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       0,   734,   735,     0,  2082,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   550,   551,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   633,   634,   635,   636,     0,     0,    34,
       0,     0,     0,     0,   737,   207,   553,     0,     0,     0,
     637,   638,   554,     0,     0,     0,     0,     0,   212,   213,
     741,   742,   743,   744,   745,   746,     0,     0,   747,   748,
     749,   750,   751,   752,   753,   652,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   653,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   654,   655,   656,   657,     0,   658,   659,     0,
       0,     0,     0,   660,   661,     0,     0,     0,     0,   662,
     663,   664,     0,     0,     0,     0,     0,     0,   738,     0,
       0,   144,   556,   557,   558,   559,   560,   561,   562,   563,
       0,   564,     0,   565,   566,   567,   568,   739,   570,   571,
       0,   572,   573,     0,     0,     0,     0,     0,   740,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,     0,     0,     0,     0,   588,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,     0,   602,     0,   603,   604,   605,   606,   607,     0,
       0,     0,     0,     0,     0,   608,     0,     0,     0,     0,
       0,     0,     0,     0,   609,   610,   611,   612,     0,     0,
       0,     0,   613,     0,     0,     0,   614,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   615,   616,   617,   618,     0,     0,     0,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   628,
     629,   630,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   631,   632,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     633,   634,   635,   636,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   637,   638,     0,
       0,     0,     0,     0,     0,     0,     0,   741,   742,   743,
     744,   745,   746,     0,     0,   747,   748,   749,   750,   751,
     752,   753,   652,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   653,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   654,
     655,   656,   657,     0,   658,   659,     0,     0,     0,     0,
     660,   661,     0,     0,     0,     0,   662,   663,   664,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   144
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
         0,    48,   385,   463,   450,   287,   288,   424,   425,   426,
     427,   394,    50,    23,     0,   546,   547,   422,   423,    58,
      42,    43,    22,    23,    34,    64,    37,   145,    42,    13,
       0,    15,     7,    64,    55,    22,    22,    52,    77,    78,
     445,   446,    19,    22,    15,    19,    77,    31,    21,    19,
      13,     5,     6,    50,    65,    13,    21,    58,    52,    19,
      57,    45,    46,     5,     6,    76,    50,    51,    14,    13,
      54,    15,    52,    53,    58,    19,    13,    78,    62,    49,
      19,   128,    19,    19,   348,   349,    58,  2888,  2889,  2890,
     240,   241,   242,    23,    78,    13,     5,    15,   240,   146,
      59,    57,    20,    62,    34,    20,    78,   154,   639,   640,
     641,   642,   643,   644,   645,   646,   647,   648,   649,   650,
     651,   652,     3,     4,    58,    14,    54,   127,     7,    63,
      58,    10,    11,    57,    13,   124,   667,   401,    13,    19,
      15,    13,   292,    14,    78,    19,   146,    31,    72,    20,
      78,   138,    23,   124,   124,    58,   145,   134,   135,   138,
     146,    45,    46,   133,   134,   138,    50,    51,   145,   144,
      54,   145,   187,   138,    58,    78,   146,    20,    62,    64,
     124,   125,    49,    50,   178,   139,   140,    66,   124,    58,
      57,   175,    77,   187,    78,   141,   142,   139,   140,    13,
     172,   145,    20,   734,   735,    19,   145,   222,   145,    78,
     741,   742,   743,   744,   745,   746,   747,   748,   749,   750,
     751,   752,   753,   754,    13,   222,   141,   142,   222,   243,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   240,   244,   266,   267,   278,   279,   280,
     230,   231,   141,   142,   134,   135,   287,   288,   289,   290,
     134,   135,    13,   294,    19,   145,   222,    57,    14,   172,
     270,   145,    13,   273,    20,    58,   276,    23,   240,   241,
     242,   162,   282,   283,   240,    13,   286,   287,   288,    10,
      11,   175,   159,   202,   294,    78,   296,   283,   141,   142,
    3101,    13,  3103,   172,   335,  3106,  3107,   338,   339,   340,
     341,   293,   343,   344,    23,    13,   347,    13,   318,   319,
     282,   321,    31,   141,   142,    34,    19,    23,    54,    19,
     292,   293,    58,    13,    15,    15,    45,    46,    34,    19,
     387,    50,    51,    13,    13,    54,    15,   347,   348,    58,
     350,   351,    78,    62,    13,   222,    14,    13,   476,    15,
      19,    20,    20,   410,    22,    23,   352,    13,   389,    78,
     125,   126,    13,   240,    14,    13,   243,   244,   245,   246,
      20,    19,    54,    23,    13,    57,   240,   241,   242,    13,
      19,    20,   403,   141,   142,   395,    68,    69,    70,    71,
     382,   383,   384,   385,    13,   443,    15,    13,   275,   276,
     277,    13,   412,   546,   547,    19,   413,    19,    14,   389,
     382,   383,   384,   385,    20,    19,    13,    14,   450,   451,
     452,   453,    19,    19,    13,    14,   436,   437,   292,   293,
      19,   441,    14,  3244,   483,    13,   443,    15,    20,    13,
     450,    19,    13,    19,    15,   455,   456,   413,    19,   459,
      13,    13,    14,    14,   450,    13,   175,    19,    13,    20,
      15,    19,   482,  1004,  1005,   506,   507,   508,    13,    14,
      14,   512,    14,   514,    19,    13,    20,   443,    20,  1020,
    1021,  1022,  1023,  1024,  1025,  1026,  1027,  1028,  1029,  1030,
    1031,  1032,    13,  1034,    15,    13,   639,   640,   641,   642,
     643,   644,   645,   646,   647,   648,   649,   650,   651,   652,
       4,    13,    14,     7,     8,   404,   405,    19,   382,   383,
     384,   385,    14,    20,   667,    22,    14,    14,    20,   539,
     407,   408,    20,    20,    13,    20,   413,    22,    13,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   426,
       0,    14,   443,   444,    58,    59,    60,    20,    10,    11,
      64,   141,   142,     2,     3,     4,   443,   456,   457,   458,
     459,   460,   461,    77,    78,   464,   465,   466,   467,   468,
     469,   470,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   734,   735,  1238,  1239,  1240,  1241,   169,   741,   742,
     743,   744,   745,   746,   747,   748,   749,   750,   751,   752,
     753,   754,    58,    59,    60,    14,    14,    12,    64,    16,
      14,    20,    20,    13,  1080,    22,    20,   348,    14,   548,
      14,    77,    78,    14,    20,    13,    20,    13,   527,    20,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     222,   223,   224,   225,    10,    11,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   224,   225,
     224,   225,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,    14,   490,   491,   492,   493,
     494,    20,  1233,  1234,  1235,  1236,  1237,  1238,  1239,  1240,
    1241,  1242,  1243,  1244,  1245,  1246,  1247,  1248,    13,    13,
      15,    14,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   731,    13,   162,    14,    14,    31,    14,    31,    14,
      20,    20,    14,    20,    13,    20,   451,   452,    20,    13,
      45,    46,    45,    46,    14,    50,    51,    50,    51,    54,
      20,    54,    14,    58,    14,    58,    13,    62,    20,    62,
      20,   200,   201,    14,    14,    14,    14,   137,    14,    20,
      20,    20,    20,    78,    20,    78,    13,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,    14,    14,    14,    14,    14,    14,    20,    20,    20,
      20,    20,    20,    14,    13,    31,   230,   231,    13,    20,
     867,  1238,  1239,  1240,  1241,  1242,  1243,   736,   875,    45,
      46,  1236,  1237,  1115,    50,    51,    31,    13,    54,    14,
       4,    14,    58,    14,    13,    20,    62,    20,    13,    20,
      45,    46,    14,    13,    41,    50,    51,    13,    20,    54,
      14,    13,    78,    58,   864,    13,    20,    62,    14,    14,
      14,  1004,  1005,    14,    20,    20,    20,    17,    14,    20,
     175,    13,   175,    78,    20,    10,    11,  1020,  1021,  1022,
    1023,  1024,  1025,  1026,  1027,  1028,  1029,  1030,  1031,  1032,
      13,  1034,   348,   349,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,    91,    14,    93,    13,
      95,    14,    97,    20,    99,   100,    13,    20,   103,   104,
     105,   106,   107,   108,   109,   110,   141,   142,    14,   175,
     115,   842,   843,    13,    20,   846,   847,   848,   849,   850,
     851,   852,   853,   854,   855,   856,   857,   858,   859,    13,
     175,    31,    18,    14,    13,  1368,  1007,    14,  1371,    20,
     419,   420,   421,    20,  1525,    45,    46,    14,    19,    14,
      50,    51,    13,    20,    54,    20,   143,    14,    58,    14,
      14,    14,    62,    20,   443,    20,    20,    20,    14,    14,
      14,    14,    52,    53,    20,    20,    20,    20,    78,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,  1051,   413,   414,  1054,  1055,  1056,  1057,  1058,  1059,
      19,  1061,  1062,   428,   429,  1525,  1066,  1067,  1068,  1069,
    1070,  1071,  1072,    13,  1074,    19,  1076,    19,  1078,  1079,
      14,  1081,  1082,  1083,  1084,  1085,    20,  1236,  1237,    15,
    1090,  1091,  1092,  1093,     7,     8,    15,  1006,    19,    12,
    1233,  1234,  1235,    19,   490,   491,   492,   493,   494,    19,
    1242,  1243,  1112,   445,   446,  1115,  1116,   546,   547,    14,
      14,    14,    19,  1004,  1005,   175,   449,   347,    15,    54,
      54,    63,    55,    81,    54,   178,    20,    14,    14,  1020,
    1021,  1022,  1023,  1024,  1025,  1026,  1027,  1028,  1029,  1030,
    1031,  1032,    50,  1034,    14,    20,    14,    14,    13,    13,
      13,    13,    13,    13,    13,    13,   145,    13,    13,    13,
      13,    13,    13,   350,    13,   352,  1707,   354,   355,    13,
    1462,    13,    13,    13,    13,   362,    13,    13,   365,   366,
     367,   368,   369,   370,   371,   372,    13,    13,    13,    13,
      13,  1110,    13,    13,  1251,    13,    13,    13,    13,    13,
     639,   640,   641,   642,   643,   644,   645,   646,   647,   648,
     649,   650,   651,   410,    13,   402,    13,    13,  1228,   406,
    1230,  1231,    13,    13,   411,   412,    20,    13,   667,    13,
      13,    13,    19,    13,    19,   422,    13,    13,    13,    13,
     427,   428,    13,    13,    13,  1255,  1702,    13,    13,    13,
      13,  1261,    13,    13,    13,    13,  1266,    13,  1268,  1269,
      13,  1271,  1272,  1273,  1274,    19,    13,  1277,    13,    13,
      19,    19,    13,    13,    13,    13,    13,    13,    13,    13,
      13,  1291,    13,    13,    13,    13,    13,    13,    13,    13,
    1300,    13,  1302,  1303,  1304,    13,    13,    13,    13,  1309,
    1310,  1311,  1312,  1313,  1314,  1315,    13,  1317,    13,    13,
      13,    13,    13,    13,    13,    13,    13,  1327,  1328,  1329,
    1330,  1331,  1332,  1333,  1334,  1335,  1336,  1337,  1338,  1339,
    1340,  1341,    13,    13,    13,    13,    13,  1347,  1348,  1349,
    1350,  1351,  1352,  1353,    13,    13,    13,    13,    13,  1359,
    1360,    13,  1362,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
    1380,    13,  1382,    13,    13,    13,    13,    13,  1388,  1389,
    1390,    13,    13,   240,   241,   242,   243,  1397,  1398,  1399,
    1400,  1401,  1402,  1403,    19,  1405,  1406,    13,  1408,  1409,
    1410,  1411,  1412,  1413,    13,  1415,  1416,  1417,  1418,  1419,
    1420,  1421,  1422,    17,   137,  1425,   273,  1427,  1428,    18,
    1430,  1431,  1432,    19,   281,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,   292,    13,    13,    13,   296,
      13,    13,    13,    13,    13,    13,    13,  1457,    13,  1459,
      13,    13,  1462,    19,  1464,    16,  1466,  1467,    15,    14,
      16,    20,    13,    16,    14,    19,  1476,    19,    14,    14,
      14,    20,    14,    16,    13,    16,    13,    13,    13,    13,
      20,    13,   339,    13,   341,   342,   343,    13,    13,    13,
      13,    13,    13,    13,    13,   352,   353,    13,    13,    13,
      13,   358,   359,   360,   361,  2046,    13,    13,    13,    20,
      13,    13,    13,    13,    13,    13,   373,   374,   375,   376,
     377,    13,   379,   380,   381,    13,    13,    13,    13,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,    13,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
      13,    13,    13,    13,    13,  1004,  1005,    13,    13,    13,
      63,    14,    14,    20,    13,    16,    14,    14,    14,    14,
      20,  1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,  1028,
    1029,  1030,  1031,  1032,    20,  1034,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    20,    20,    20,
      20,    20,    20,    20,    20,    20,   378,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    20,    20,
      14,    14,    14,    14,   511,    14,   408,   409,   410,   411,
     412,    13,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   178,   179,   180,   181,   182,   183,
     184,   185,   186,    20,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,    14,    20,    20,    20,    20,
      16,    13,    13,    13,    13,    13,    13,    13,    13,    13,
     224,   225,  1779,  1780,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
     502,    13,    13,    13,    13,    13,    13,    13,    13,    13,
    2153,    13,    13,    13,    13,    13,    13,  1777,   520,  2162,
      13,  2164,    13,    13,    13,    13,    13,    13,    13,    13,
      72,    72,    13,    15,    13,    13,    19,  1797,    13,    19,
      13,    13,    13,    20,    13,  1234,  1235,    12,    16,    19,
      16,    14,    65,    56,    14,   222,   222,   145,    16,   505,
     145,    56,    14,    13,    13,    59,    13,   348,    60,    65,
      13,   145,    20,   282,    20,    14,    20,    14,    20,    20,
     473,    14,    20,    14,    20,    61,    60,    14,    20,    14,
      20,    20,    20,    14,    20,    62,    20,    14,    62,    19,
      62,    20,    20,    14,    20,    20,    20,    14,    20,    14,
      14,    72,    20,    16,    20,    14,    14,    76,    20,    20,
      20,  1881,  1882,  1883,  1884,    20,  1886,    20,  1888,    14,
      14,    14,    14,    14,  1894,  1895,  1896,    16,    14,  1899,
    1900,  1901,  1902,    20,  1904,    20,  1906,    19,  1908,    20,
      20,  1911,  1912,  1913,  1914,    20,    20,    14,  1918,    20,
      20,  1921,    20,    57,    20,    20,    20,    20,    20,    20,
      20,    20,  1932,    20,  1934,    14,    20,    13,  1938,  1939,
      13,  1941,  1942,  1943,  1944,  1945,  1946,  1947,  1948,  1949,
    1950,  1951,  1952,    20,  1954,    20,    20,    13,    13,    20,
      14,    20,    20,  1963,  1964,  1965,  1966,  1967,  1968,  1969,
    1970,  1971,    20,    20,    20,    20,    20,    20,    14,    14,
      14,    20,    14,    20,   401,  1985,  1986,  1987,  1988,    20,
      20,    20,  1992,  1993,  1994,  1995,    20,    20,    20,    20,
      20,    20,  2002,  2003,  2004,  2005,  2006,  2007,  2008,  2009,
    2010,  2011,  2012,    20,    20,    14,    20,    20,    20,    20,
    2020,  2021,  2022,    20,  2024,  2025,    20,  2027,  2028,    14,
      14,  2031,    20,  2033,    20,   443,   145,    20,    20,    20,
      20,    20,    20,    20,  2044,    20,    20,  2047,    20,    20,
      14,    14,    14,    14,    14,  2055,  2056,  2057,    14,    14,
      72,    20,  2062,    20,    13,    13,    20,    20,  2068,    20,
      20,  2071,  2072,    20,  2074,  2075,  2076,    20,    14,    14,
      14,    20,    13,    13,    13,    13,    54,    14,    14,    14,
    2090,    57,  2092,   474,   145,  1378,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,  2106,    14,    20,    14,
      20,    20,    20,    14,    14,    14,    20,    14,    20,    14,
      14,  2121,    14,  2123,    14,    14,    14,    14,  2128,    14,
      14,    14,    14,    14,  2134,    14,    14,    14,  2138,  2139,
      20,  2141,  2142,  2143,    20,  2145,  2146,    14,    14,  2149,
    2150,    14,  2152,    14,    14,    14,    14,    14,    14,    14,
      14,    57,    14,    14,    57,  2165,  2166,    20,    14,  2169,
      20,  2171,  2172,  2173,    14,    14,    20,    14,    14,  2179,
      14,    14,  2182,    14,  2184,    20,    14,    14,  2188,  2189,
    2190,    20,  2192,    14,    20,    20,    20,    20,  2198,    14,
      20,  2201,    20,  2203,    20,  2205,  2206,  2207,    20,    20,
      20,    20,    57,    20,    14,    20,  2216,  2217,    20,    20,
    2220,    14,    14,    14,    14,  2225,  2226,  2227,  2228,  2229,
    2230,    20,  2232,  2233,  2234,    20,  2236,  2237,  2238,  2239,
    2240,    14,    20,  2243,  2244,  2245,  2246,    14,  2248,    20,
      14,    14,    14,    14,    14,    20,    14,    14,    54,    76,
      14,    20,    14,  2646,    20,    20,    14,    14,    14,    14,
      14,    20,    14,    14,    57,    14,    14,    20,    14,    54,
      20,    57,    14,    20,   146,    20,    20,    20,  2288,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      13,    16,    16,    14,    14,    22,    14,    16,    20,    14,
      14,    14,    14,    20,    14,    14,    14,    14,   431,    20,
      14,    14,   430,    14,    20,    20,    14,    14,    20,    14,
      20,    20,    14,    14,    20,    14,    20,    20,    14,    57,
      20,    57,    20,    20,    14,    20,    20,    20,    20,    14,
      14,    20,    14,    20,    20,    14,    14,    20,    14,    20,
      14,    14,    14,    20,   146,    20,   146,   146,   434,    20,
      20,    20,    20,    20,    20,    20,    14,    20,    20,    20,
    2427,  2428,    22,    20,    20,    20,    20,  2434,    20,    20,
      20,    20,    20,    20,    20,    14,    20,    20,    20,    20,
      20,    14,  2402,    20,    14,    20,    14,    14,    14,    20,
      14,    20,    14,    14,    14,    20,    14,    14,    57,    22,
      14,    20,    14,    14,    20,    20,  2426,    14,    14,    14,
      14,    20,    20,    14,   432,   435,    14,    20,    20,    14,
      20,    20,    14,    20,    20,    14,    20,    20,    14,    14,
      14,    14,    20,    20,    14,    14,    14,    14,    14,    20,
      14,    14,    14,    14,    14,    20,    14,    14,    14,    14,
    1248,    20,    14,  1244,  1386,    14,    20,    20,    14,    20,
      20,   433,    20,    20,  2484,    20,  2486,    20,  2488,    20,
    2490,    20,    20,    20,    14,  2495,  2496,    20,  2498,  2499,
    2500,  2501,    20,  2503,  2504,  2505,  2506,    20,    14,    20,
    2510,    20,    20,  2513,  2514,    20,    20,    20,    20,  2519,
      14,    20,    20,    20,  2524,    20,  2526,  2527,  2528,  2529,
    2530,  2531,  2532,  2533,    20,  2535,  2536,  2537,  2538,  2539,
    2540,  2541,  2542,  2543,  2544,  2545,  2546,  2547,  2548,    20,
    2550,    20,    20,    20,    14,    20,    20,    20,  2558,    20,
      14,    14,  2562,  2563,    14,    14,    14,    14,    20,    20,
    1245,  1247,  2572,  2573,    20,    20,    20,    20,    20,    20,
      14,    14,  2582,  2583,  2584,  2585,  2586,    14,  2588,  2589,
      20,  2591,  2592,    14,    20,    20,  2596,  2597,    14,    14,
      20,  2601,  2602,  2603,  2604,  2514,    20,    20,  2517,    20,
      20,    14,    20,    20,    20,    20,  2616,    14,    19,  2046,
      20,    20,  2622,    14,    20,    20,  2626,    20,  2628,  2629,
      20,    20,    20,    20,    20,    20,    20,    20,  2638,  2639,
    2640,    20,    20,  2643,  2644,    20,    20,    14,    20,    20,
      20,    20,    20,    14,    20,    20,  2656,    14,  2658,    14,
    2660,  2661,    14,  2663,  2664,  2665,  2666,  2667,  2668,  2669,
    2670,    20,  2672,  2673,  2674,  2675,  2676,  2677,  2678,  2679,
    2680,    20,  2682,  2683,  2684,  2685,    14,    20,    20,    20,
      20,    20,    14,    20,    20,    20,  2696,  2697,  2698,  2699,
      14,    22,  2702,  2703,    20,    14,    14,    20,    20,    14,
      20,    14,    14,    20,    14,    14,    20,   146,    14,    20,
      14,  1087,    20,    20,    14,    20,    14,    20,    20,    20,
      14,    20,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    14,  1232,  1246,    -1,   146,    -1,
      14,    20,    20,    20,    20,    20,  2803,    14,    14,    20,
      14,    20,    20,    14,    14,    20,    14,    20,    14,   146,
      14,    20,    14,    20,    14,    20,    14,    20,    -1,    20,
      -1,    20,    -1,    20,    20,    20,    20,    20,    20,    20,
      14,    20,    20,    20,    20,    20,    14,    20,    14,    14,
      22,    20,    22,    20,    -1,    -1,    20,    20,    20,    20,
      20,    20,    20,    20,    14,    14,    14,    14,    20,    20,
      14,    16,    14,    14,    20,    14,    14,    20,    14,    14,
      20,    14,    -1,    20,    -1,    -1,    20,    14,    20,    20,
      20,    20,  2842,  2843,    14,  2845,  2846,    20,  2848,  2849,
      14,  2851,  2852,  2853,    20,  2855,  2856,    20,    20,  2859,
      20,    20,    20,    14,  2864,  2865,    20,  2867,    20,  2869,
      20,  2871,    20,  2873,  2874,  2875,  2876,  2877,    14,    20,
      20,  2881,  2882,  2883,  2884,  2885,  2886,    14,  2888,  2889,
    2890,  2891,  2892,  2893,  2894,    14,  2896,  2897,  2898,  2899,
    2900,    14,  2902,    20,    14,    14,    14,  2907,  2908,    14,
    2910,  2911,  2912,  2913,  2914,  2915,    14,  2917,  2918,  2919,
    2920,    20,  2922,    14,    20,    14,  2926,    14,  2928,    14,
    2930,    14,    20,  2933,    14,  2935,  2936,    14,  2938,    20,
      14,    14,    14,    14,    20,  2945,    -1,  2947,    14,  2858,
    2950,  2951,    20,  2862,    14,    20,    20,    14,    20,    22,
      14,    20,    20,    14,    20,    20,  2966,  2967,  2968,  2969,
    2970,    20,    20,    20,    20,    20,  2976,  2977,  2978,    20,
      20,    20,    20,    14,    14,    20,    14,    20,    20,    14,
      14,    20,    14,    20,    14,    14,    -1,    20,    14,    20,
      -1,    -1,    20,    20,    -1,    20,    20,    20,    20,    20,
      20,    20,    14,    20,    20,    14,    14,    14,    14,    14,
      20,    -1,    14,    14,    14,    -1,    20,    20,    14,    -1,
      -1,    20,    20,    20,    14,    20,    20,    20,    20,    14,
      14,    20,    20,    20,    14,    14,    14,    20,    20,    20,
      14,    14,    -1,    20,    20,    20,    14,    -1,    20,    20,
      20,    20,    14,    20,    20,    20,  3066,    20,    14,  3069,
    3070,  3071,    20,    14,    -1,  3075,    -1,  3077,  3078,    -1,
      -1,    -1,    -1,  3083,  3084,    -1,  3086,    -1,  3088,  3089,
    3090,  3091,  3092,  3093,    -1,  3095,  3096,  3097,  3098,  3099,
    3100,  3101,    -1,  3103,    -1,    -1,  3106,  3107,  3108,  3109,
    3110,    -1,    -1,    -1,    -1,    -1,  3116,  3117,    -1,    -1,
    3120,    -1,    -1,    -1,  3124,  3125,  3126,    -1,    -1,  3129,
      -1,    -1,    -1,    -1,    -1,  3135,  3136,    -1,    -1,  3139,
    3140,    -1,    -1,  3143,    -1,  3145,  3146,    -1,    -1,  3149,
    3150,    -1,  3152,    -1,  3154,  3155,  3156,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3082,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3216,  3217,  3218,  3219,
      -1,  3221,  3222,    -1,    -1,  3225,    -1,    -1,    -1,    -1,
      -1,    -1,  3232,    -1,  3234,    -1,  3236,    -1,    -1,  3239,
      -1,    -1,    -1,    -1,  3244,    -1,    -1,    -1,    -1,  3249,
    3250,    -1,  3252,    -1,  3254,    -1,  3256,  3257,  3258,    -1,
    3260,  3261,    -1,  3263,    -1,  3265,    -1,  3267,  3268,  3269,
      -1,    -1,  3272,  3273,  3274,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3311,    -1,    -1,    -1,  3315,  3316,    -1,    -1,    -1,
    3320,    -1,  3322,  3323,    -1,  3325,  3326,    -1,    -1,    -1,
    3330,    -1,    -1,  3333,  3334,  3335,    -1,  3337,  3338,    -1,
    3340,  3341,    -1,    -1,  3344,  3345,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3367,    -1,    -1,
      -1,    -1,    -1,  3373,  3374,  3375,    -1,    -1,    -1,  3379,
    3380,    -1,    -1,  3383,  3384,    -1,    -1,  3387,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3401,  3402,    -1,  3404,    -1,  3406,    -1,    -1,  3409,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3419,
      -1,  3421,  3422,  3423,    -1,     0,    -1,     2,     3,     4,
    3430,  3431,  3432,    -1,    -1,    -1,    -1,  3437,  3438,  3439,
      -1,    -1,    -1,    18,  3444,  3445,    21,    -1,  3448,    24,
      -1,    -1,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     7,    -1,     9,    10,    11,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    -1,    -1,    -1,    50,    51,    -1,    -1,
      54,    -1,    56,    -1,    58,    59,    60,    61,    62,    63,
      64,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      74,    75,    -1,    77,    78,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,    -1,
      -1,    -1,    -1,   128,   129,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   146,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   146,   147,   148,   149,   150,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   166,    -1,    -1,   200,   201,    -1,    -1,    -1,
      -1,   175,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,    -1,
     245,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,   263,   264,
      -1,   266,   267,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   277,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   286,   287,   288,    -1,    -1,   260,    -1,   262,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   320,   321,   322,   323,   324,
     325,   326,   327,   328,    -1,    -1,    -1,    -1,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
      -1,    -1,    -1,    -1,   349,   350,    -1,    -1,   353,   354,
     355,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   333,
     334,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   389,   390,    -1,    -1,    -1,    -1,
      -1,   396,    -1,   398,   399,   400,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   413,   414,
     415,   416,    -1,    -1,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,    -1,    -1,    -1,    -1,    -1,
     404,   405,    -1,    -1,   439,   440,   441,    -1,   443,    -1,
     445,   446,    -1,    -1,   449,   450,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   463,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,    -1,
     444,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     454,   455,   456,   457,   458,   459,   460,   461,    -1,    -1,
     464,   465,   466,   467,   468,   469,   470,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   486,   487,     7,    -1,     9,    10,    11,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   540,    -1,    -1,    -1,    32,
      -1,   546,   547,   548,   549,   550,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   527,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    -1,    58,    59,    60,    61,    -1,
      63,    64,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    75,    -1,    77,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   639,   640,   641,   642,   643,   644,
     645,   646,   647,   648,   649,   650,   651,   652,    -1,    -1,
      -1,    -1,    -1,   146,   147,   148,   149,   150,    -1,    -1,
      -1,    -1,   667,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   727,    -1,    -1,    -1,    -1,    -1,    -1,   734,
     735,   736,    -1,    -1,   227,    -1,   741,   742,   743,   744,
     745,   746,   747,   748,   749,   750,   751,   752,   753,   754,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   260,    -1,   262,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     333,   334,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     865,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   913,    -1,
      -1,   404,   405,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   940,    -1,    -1,    -1,   944,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
      -1,   444,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   454,   455,   456,   457,   458,   459,   460,   461,    -1,
      -1,   464,   465,   466,   467,   468,   469,   470,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   994,
      -1,    -1,    -1,   486,   487,    -1,    -1,    -1,    -1,  1004,
    1005,  1006,  1007,  1008,    -1,    -1,    -1,    -1,    -1,    -1,
    1015,    -1,    -1,    -1,    -1,  1020,  1021,  1022,  1023,  1024,
    1025,  1026,  1027,  1028,  1029,  1030,  1031,  1032,    -1,  1034,
      -1,    -1,    -1,    -1,   527,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1047,    -1,    -1,    -1,    -1,    -1,    -1,  1054,
      -1,    -1,    -1,    -1,    -1,  1060,    -1,    -1,  1063,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1073,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1097,    -1,  1099,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1110,    -1,    -1,    -1,    -1,
    1115,  1116,  1117,  1118,  1119,  1120,  1121,  1122,  1123,  1124,
    1125,  1126,  1127,  1128,  1129,  1130,    -1,  1132,  1133,  1134,
    1135,    -1,  1137,  1138,  1139,    -1,    -1,  1142,  1143,  1144,
    1145,  1146,  1147,  1148,  1149,  1150,  1151,  1152,  1153,  1154,
    1155,  1156,  1157,  1158,  1159,  1160,  1161,  1162,  1163,  1164,
    1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,  1173,  1174,
      -1,    -1,  1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,
    1185,  1186,  1187,  1188,  1189,  1190,  1191,  1192,  1193,  1194,
    1195,  1196,  1197,  1198,  1199,  1200,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1215,  1216,  1217,  1218,  1219,  1220,    -1,  1222,  1223,  1224,
    1225,  1226,    -1,  1228,    -1,  1230,  1231,  1232,  1233,  1234,
    1235,  1236,  1237,  1238,  1239,  1240,  1241,  1242,  1243,  1244,
    1245,  1246,  1247,  1248,    -1,    -1,    -1,  1252,  1253,  1254,
      -1,    -1,    -1,  1258,    -1,    -1,    -1,    -1,    -1,    -1,
    1265,    -1,    -1,    -1,    -1,  1270,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1285,    -1,    -1,  1288,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1299,    -1,  1301,    -1,    -1,    -1,
    1305,  1306,  1307,  1308,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1316,    -1,  1318,  1319,  1320,  1321,  1322,  1323,  1324,
    1325,  1326,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1342,    -1,  1344,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1354,
    1355,  1356,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1365,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1383,  1384,
    1385,    -1,    -1,    -1,    -1,    -1,    -1,  1392,  1393,    -1,
    1395,  1396,  1397,  1398,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1414,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1423,  1424,
      -1,  1426,    -1,    -1,  1429,    -1,    -1,    -1,  1433,  1434,
      -1,    -1,    -1,  1438,  1439,  1440,  1441,  1442,  1443,    -1,
    1445,    -1,    -1,  1448,  1449,    -1,  1451,  1452,  1453,  1454,
    1455,    -1,    -1,    -1,    -1,  1460,    -1,  1462,  1463,    -1,
      -1,    -1,    -1,  1468,  1469,  1470,    -1,  1472,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1525,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
    1635,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1704,
      -1,    -1,  1707,    -1,    -1,    -1,  1711,  1712,  1713,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,     9,
      10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    -1,    -1,    -1,    -1,  1762,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,
      50,    51,    -1,  1778,    54,    -1,    56,    -1,    58,    59,
      60,    61,    62,    63,    64,    -1,    66,    67,    -1,    -1,
      -1,    -1,  1797,    -1,    74,    75,    -1,    77,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,   149,
     150,  1876,    -1,    -1,    -1,  1880,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   166,  1892,  1893,    -1,
      -1,    -1,    -1,    -1,    -1,   175,    -1,   177,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1920,    -1,  1922,    -1,    -1,
      -1,    -1,    -1,    -1,  1929,    -1,    -1,    -1,    -1,    -1,
      -1,  1936,  1937,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,    -1,    -1,
    1955,  1956,  1957,  1958,  1959,  1960,  1961,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1975,    -1,  1977,  1978,  1979,  1980,  1981,    -1,  1983,  1984,
     260,    -1,   262,    -1,  1989,  1990,    -1,    -1,    -1,    -1,
      -1,  1996,  1997,    -1,    -1,  2000,  2001,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2026,    -1,    -1,  2029,    -1,    -1,    -1,    -1,  2034,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2046,    -1,  2048,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   333,   334,  2060,    -1,    -1,  2063,  2064,
    2065,  2066,  2067,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2082,    -1,    -1,
      -1,    -1,    -1,  2088,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2141,    -1,    -1,    -1,
      -1,    -1,  2147,  2148,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,  2168,   444,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   454,   455,   456,   457,   458,   459,
     460,   461,    -1,    -1,   464,   465,   466,   467,   468,   469,
     470,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   486,   487,    -1,    -1,
      -1,    -1,     7,    -1,     9,    10,    11,    -1,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,
      -1,  2246,  2247,    -1,    -1,    -1,    -1,   527,    -1,    -1,
      45,    46,    -1,    -1,    -1,    50,    51,    -1,    -1,    54,
      -1,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      75,    -1,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   146,   147,   148,   149,   150,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     175,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   260,    -1,   262,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2480,  2481,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2513,    -1,
      -1,    -1,  2517,  2518,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2535,  2536,    -1,    -1,    -1,    -1,    -1,    -1,   333,   334,
      -1,    -1,    -1,    -1,    -1,    -1,  2551,  2552,  2553,  2554,
    2555,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2568,    -1,    -1,  2571,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2612,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2625,    -1,    -1,    -1,    -1,    -1,  2631,    -1,  2633,    -1,
    2635,    -1,  2637,    -1,    -1,    -1,  2641,  2642,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,    -1,   444,
      -1,    -1,  2657,    -1,    -1,    -1,    -1,    -1,    -1,   454,
     455,   456,   457,   458,   459,   460,   461,    -1,    -1,   464,
     465,   466,   467,   468,   469,   470,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2688,    -1,    -1,    -1,    -1,    -1,  2694,
      -1,   486,   487,    -1,    -1,  2700,  2701,    -1,    -1,    -1,
      -1,     0,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   527,    -1,    -1,    -1,    -1,    -1,     7,    -1,
       9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,
      -1,    50,    51,    -1,    -1,    54,    -1,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    -1,    66,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    75,    -1,    77,    78,
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,    -1,    -1,
      -1,    -1,    -1,  2858,    -1,    -1,    -1,  2862,    -1,    -1,
      -1,    -1,    -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,
     149,   150,    -1,  2888,  2889,  2890,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2901,   166,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   175,    -1,   177,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2924,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2940,  2941,    -1,    -1,    -1,
      -1,  2946,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2974,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   283,    -1,    -1,   286,   287,   288,
      -1,   260,    -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   320,   321,   322,   323,   324,   325,   326,   327,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   335,   336,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   352,    -1,   354,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   333,   334,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3079,    -1,    -1,  3082,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3101,    -1,  3103,    -1,
      -1,  3106,  3107,    -1,    -1,    -1,  3111,  3112,  3113,  3114,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3142,    -1,  3144,
     439,   440,   441,    -1,   443,   444,   445,   446,  3153,    -1,
     449,   450,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,    -1,   444,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   454,   455,   456,   457,   458,
     459,   460,   461,    -1,    -1,   464,   465,   466,   467,   468,
     469,   470,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   486,   487,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3244,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   546,   547,   548,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3262,   527,  3264,
      -1,    -1,    -1,    -1,    -1,    -1,  3271,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3301,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3314,
      -1,    -1,    -1,    -1,    -1,    -1,     0,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3329,    -1,    -1,  3332,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,
     639,   640,   641,   642,   643,   644,   645,   646,   647,   648,
     649,   650,   651,   652,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   667,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3381,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3389,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3407,    -1,    -1,    -1,  3411,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   734,   735,   736,    -1,    -1,
      -1,    -1,   741,   742,   743,   744,   745,   746,   747,   748,
     749,   750,   751,   752,   753,   754,    -1,    -1,    -1,    -1,
      -1,    -1,   146,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   842,   843,   844,    -1,   846,   847,   848,
     849,   850,   851,   852,   853,   854,   855,   856,   857,   858,
     859,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   280,   281,    -1,    -1,
      -1,    -1,   286,   287,   288,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   320,   321,   322,   323,
     324,   325,   326,   327,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   335,   336,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     354,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1004,  1005,  1006,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,  1028,
    1029,  1030,  1031,  1032,    -1,  1034,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   439,   440,   441,    -1,    -1,
      -1,    -1,    -1,    -1,   448,   449,   450,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1073,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1115,  1116,    -1,  1118,
    1119,    -1,    -1,    -1,    -1,    -1,  1125,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1137,  1138,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   546,   547,   548,   549,  1165,  1166,  1167,  1168,
    1169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1192,    -1,    -1,    -1,    -1,    -1,    -1,
    1199,  1200,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1215,  1216,  1217,    -1,
    1219,  1220,    -1,  1222,  1223,  1224,  1225,    -1,    -1,  1228,
      -1,  1230,    -1,  1232,  1233,  1234,  1235,  1236,  1237,  1238,
    1239,  1240,  1241,  1242,  1243,  1244,  1245,  1246,  1247,  1248,
      -1,    -1,    -1,    -1,    -1,   639,   640,   641,   642,   643,
     644,   645,   646,   647,   648,   649,   650,   651,   652,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   667,    -1,    -1,  1285,    -1,    -1,  1288,
      -1,    -1,    -1,    -1,    22,    23,    24,    -1,    -1,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1344,    -1,    -1,    -1,    -1,
     734,   735,   736,    -1,    -1,    -1,    -1,   741,   742,   743,
     744,   745,   746,   747,   748,   749,   750,   751,   752,   753,
     754,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     128,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1414,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1424,    -1,  1426,    -1,    -1,
      -1,    -1,    -1,    -1,  1433,    -1,    -1,    -1,    -1,  1438,
    1439,  1440,    -1,  1442,    -1,    -1,    -1,    -1,    -1,  1448,
      -1,    -1,  1451,  1452,  1453,  1454,  1455,    -1,    -1,    -1,
      -1,    -1,    -1,  1462,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   243,    -1,   245,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1525,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   263,   264,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   277,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   286,   287,
     288,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1004,  1005,  1006,    -1,    -1,   353,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1020,  1021,  1022,  1023,
    1024,  1025,  1026,  1027,  1028,  1029,  1030,  1031,  1032,    -1,
    1034,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   390,    -1,    -1,    -1,    -1,    -1,   396,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   412,    -1,    -1,   415,   416,  1073,
      -1,    -1,    -1,    -1,    -1,    -1,  1080,    -1,    -1,    -1,
      -1,    -1,  1086,    -1,    -1,  1704,    -1,    -1,  1707,    -1,
      -1,    -1,  1711,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   450,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1115,  1116,    -1,  1118,  1119,    -1,    -1,    -1,    -1,
      -1,  1125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1137,  1138,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1762,    -1,    -1,    -1,  1151,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1165,  1166,  1167,  1168,  1169,    -1,    -1,    -1,    -1,
      -1,  1175,  1176,    -1,    -1,    -1,    -1,    -1,  1797,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1192,    -1,
      -1,   539,   540,    -1,    -1,  1199,  1200,    -1,    -1,    -1,
      -1,    -1,   550,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1215,  1216,  1217,    -1,  1219,  1220,    -1,  1222,  1223,
    1224,  1225,    -1,    -1,  1228,    -1,  1230,    -1,  1232,  1233,
    1234,  1235,  1236,  1237,  1238,  1239,  1240,  1241,  1242,  1243,
    1244,  1245,  1246,  1247,  1248,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1285,    -1,    -1,  1288,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1922,    -1,    -1,    -1,    -1,    -1,    -1,
    1929,    -1,    -1,    -1,    -1,    -1,    -1,  1936,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1957,  1958,
    1344,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   320,   321,   322,   323,   324,   325,   326,   327,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   335,   336,    -1,
    1989,  1990,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   727,
      -1,    -1,    -1,    -1,    -1,    -1,   354,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1414,    -1,    -1,    -1,    -1,  2034,    -1,    -1,    -1,    -1,
    1424,    -1,  1426,    -1,    -1,    -1,    -1,  2046,    -1,  1433,
      -1,  1435,  1436,  1437,  1438,  1439,  1440,    -1,  1442,    -1,
    1444,    -1,  1446,  1447,  1448,    -1,    -1,  1451,  1452,  1453,
    1454,  1455,    -1,    -1,    -1,    -1,    -1,    -1,  1462,    -1,
      -1,    -1,    -1,  2082,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   439,   440,   441,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   449,   450,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   865,    -1,    -1,
      -1,  1525,  2141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,     9,    10,
      11,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   913,    -1,    -1,    -1,    -1,
      -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     548,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   940,    -1,    -1,    56,   944,    58,    59,    60,
      61,    -1,    63,    64,    -1,    66,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    75,    -1,    77,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2246,  2247,    -1,
      -1,  1635,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   994,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1008,    -1,    -1,    -1,    -1,    -1,    -1,  1015,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1702,  1047,
    1704,    -1,    -1,  1707,    -1,   166,    -1,  1711,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1097,
      -1,  1099,    -1,    -1,    -1,    -1,    -1,    -1,  1762,    -1,
      -1,    -1,  1110,    -1,    -1,    -1,   227,  1115,   736,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1797,    -1,    -1,    -1,    -1,    -1,   260,
      -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1177,
    1178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   333,   334,    -1,    -1,    -1,    -1,  1226,    -1,
    1228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1252,  1253,  1254,    -1,    -1,    -1,
    1258,    -1,    -1,    -1,    -1,    -1,    -1,  1265,  1922,    -1,
      -1,    -1,  1270,    -1,    -1,  1929,    -1,    -1,    -1,    -1,
      -1,    -1,  1936,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2568,
      -1,    -1,  2571,  1957,  1958,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,    -1,   444,    -1,  1989,  1990,    -1,    -1,    -1,
      -1,    -1,    -1,   454,   455,   456,   457,   458,   459,   460,
     461,    -1,    -1,   464,   465,   466,   467,   468,   469,   470,
      -1,    -1,  2631,    -1,  2633,    -1,  2635,  1365,  2637,    -1,
      -1,    -1,    -1,    -1,    -1,   486,   487,    -1,    -1,    -1,
    2034,    -1,    -1,    -1,    -1,  1383,    -1,    -1,  1006,    -1,
      -1,    -1,  2046,    -1,  1392,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   527,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2694,    -1,    -1,  2082,    -1,
      -1,  2700,  2701,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1441,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1449,    -1,    -1,    -1,  1073,    -1,    -1,    -1,    -1,
      -1,    -1,  1460,    -1,  1462,  1463,    -1,    -1,    -1,    -1,
    1468,  1469,  1470,    -1,  1472,    -1,    -1,    -1,  1476,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2141,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1116,    -1,
    1118,  1119,    -1,    -1,    -1,    -1,    -1,  1125,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1137,
    1138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1151,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1165,  1166,  1167,
    1168,  1169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1192,    -1,    -1,    -1,    -1,    -1,
      -1,  1199,  1200,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2246,  2247,    -1,    -1,    -1,  1215,  1216,  1217,
      -1,  1219,  1220,    -1,  1222,  1223,  1224,  1225,    -1,    -1,
    1228,    -1,  1230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1285,    -1,    -1,
    1288,  2940,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     7,  2974,     9,    10,    11,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1344,    -1,    -1,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    -1,    58,    59,    60,    61,    -1,
      63,    64,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    75,    -1,    77,    78,    -1,    -1,    -1,    -1,
    1778,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1414,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1424,    -1,  1426,    -1,
      -1,    -1,    -1,    -1,    -1,  1433,    -1,    -1,    -1,    -1,
    1438,  1439,  1440,    -1,  1442,    -1,    -1,    -1,    -1,    -1,
    1448,    -1,    -1,  1451,  1452,  1453,  1454,  1455,    -1,    -1,
      -1,    -1,    -1,   146,   147,   148,   149,   150,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,  1876,    -1,
      -1,    -1,    -1,    -1,  3153,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2568,    -1,    -1,  2571,    -1,    -1,
      -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   260,    -1,   262,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2631,    -1,  2633,
      -1,  2635,    -1,  2637,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1997,
      -1,    -1,  3271,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     333,   334,  3301,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2694,    -1,    -1,    -1,    -1,    -1,  2700,  2701,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2056,  2057,
    3329,    -1,  2060,  3332,  2062,  2063,  2064,  2065,  2066,  2067,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1704,    -1,    -1,    -1,
      -1,    -1,    -1,  1711,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3389,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
      -1,   444,  3411,    -1,  1762,    -1,    -1,    -1,    -1,    -1,
      -1,   454,   455,   456,   457,   458,   459,   460,   461,    -1,
      -1,   464,   465,   466,   467,   468,   469,   470,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1797,
      -1,    -1,    -1,   486,   487,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   527,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2940,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1922,    -1,    -1,    -1,    -1,    -1,
      -1,  1929,    -1,    -1,    -1,    -1,    -1,    -1,  1936,    -1,
    2974,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1957,
    1958,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1989,  1990,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2034,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2082,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2480,  2481,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3153,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,    -1,    -1,
      -1,    -1,    -1,    -1,     7,    -1,     9,    10,    11,    -1,
      13,    -1,    -1,  2141,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    51,    -1,
      -1,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    -1,    -1,
      83,    84,    85,    86,    -1,    88,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2612,    -1,    -1,  3271,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2246,  2247,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3301,    -1,    -1,
      -1,    -1,    -1,   146,   147,   148,   149,   150,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,    -1,
      -1,    -1,    -1,   166,    -1,  3329,    -1,    -1,  3332,    -1,
     173,   174,   175,   176,   177,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,
     213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   227,  3389,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3411,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   260,    -1,   262,
      -1,    -1,    -1,    -1,    -1,   268,   269,   270,   271,   272,
     273,    -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   316,   317,   318,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   331,   332,
     333,   334,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   404,   405,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2924,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
    2568,   444,   445,  2571,    -1,   448,    -1,    -1,    -1,    -1,
      -1,   454,   455,   456,   457,   458,   459,   460,   461,    -1,
      -1,   464,   465,   466,   467,   468,   469,   470,    -1,   472,
      -1,    -1,    -1,    -1,   477,    -1,   479,   480,    -1,    -1,
      -1,   484,   485,   486,   487,    -1,   489,    -1,    -1,    -1,
      -1,    -1,    -1,   496,   497,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2631,    -1,  2633,    -1,  2635,    -1,  2637,
     513,    -1,    -1,    -1,    -1,   518,   519,    -1,   521,   522,
     523,   524,   525,   526,   527,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2694,    -1,    -1,    -1,
      -1,  3079,  2700,  2701,    -1,    -1,    -1,    -1,    -1,    -1,
       7,    -1,     9,    10,    11,    -1,    13,    -1,    -1,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      -1,    -1,    -1,    50,    51,    -1,    -1,    54,    -1,    56,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    -1,    71,    -1,    -1,    74,    75,    76,
      77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    -1,    -1,    90,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3221,    -1,    -1,    -1,    -1,    -1,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,    -1,   160,    -1,   162,   163,   164,   165,   166,
     167,   168,    -1,   170,   171,    -1,    -1,    -1,   175,    -1,
     177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,
     227,    -1,    -1,    -1,    -1,    -1,  3314,    -1,    -1,    -1,
      -1,    -1,  2940,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,    -1,    -1,    -1,    -1,    -1,  2974,   274,    -1,    -1,
      -1,   278,   279,   280,    -1,    -1,   283,   284,   285,   286,
     287,   288,   289,   290,   291,    -1,    -1,   294,   295,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   312,   313,   314,   315,    -1,
      -1,    -1,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,    -1,    -1,   333,   334,   335,    -1,
      -1,   338,   339,   340,   341,    -1,   343,   344,   345,   346,
     347,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   403,   404,   405,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,    -1,   444,    -1,   446,
     447,    -1,   449,    -1,    -1,  3153,    -1,   454,   455,   456,
     457,   458,   459,   460,   461,    -1,    -1,   464,   465,   466,
     467,   468,   469,   470,   471,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   486,
     487,   488,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   498,   499,   500,   501,    -1,   503,   504,    -1,   506,
     507,   508,   509,   510,    -1,   512,    -1,   514,   515,   516,
     517,    -1,    -1,    -1,    -1,     7,    -1,     9,    10,    11,
     527,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    -1,    -1,    -1,    50,    51,
      -1,    -1,    54,  3271,    56,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    71,
      -1,    -1,    74,    75,    -1,    77,    78,    -1,    -1,    -1,
      -1,    -1,    -1,  3301,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3329,    -1,    -1,  3332,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,    -1,   160,    -1,
     162,   163,   164,   165,   166,   167,   168,    -1,   170,   171,
      -1,  3389,    -1,   175,    -1,   177,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3411,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,    -1,   226,   227,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,    -1,    -1,    -1,    -1,
      -1,    -1,   274,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   283,   284,   285,   286,    -1,    -1,    -1,    -1,   291,
      -1,    -1,    -1,   295,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     312,   313,   314,   315,    -1,    -1,    -1,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,    -1,
      -1,   333,   334,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   345,   346,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   404,   405,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,    -1,   444,    -1,   446,   447,    -1,    -1,    -1,    -1,
      -1,    -1,   454,   455,   456,   457,   458,   459,   460,   461,
      -1,    -1,   464,   465,   466,   467,   468,   469,   470,   471,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   486,   487,   488,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   498,   499,   500,   501,
      -1,   503,   504,    -1,    -1,    -1,    -1,   509,   510,    -1,
      -1,    -1,    -1,   515,   516,   517,     7,    -1,     9,    10,
      11,    -1,    13,    -1,    -1,   527,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    -1,    -1,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,    50,
      51,    -1,    -1,    54,    -1,    56,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    -1,    -1,    74,    75,    -1,    77,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,    -1,   160,
      -1,   162,   163,   164,   165,   166,   167,   168,    -1,   170,
     171,    -1,    -1,    -1,   175,    -1,   177,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,    -1,    -1,    -1,    -1,   226,   227,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,    -1,    -1,    -1,
      -1,    -1,    -1,   274,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   283,   284,   285,   286,    -1,    -1,    -1,    -1,
     291,    -1,    -1,    -1,   295,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   312,   313,   314,   315,    -1,    -1,    -1,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
      -1,    -1,   333,   334,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   345,   346,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,    -1,   444,    -1,   446,   447,    -1,    -1,    -1,
      -1,    -1,    -1,   454,   455,   456,   457,   458,   459,   460,
     461,    -1,    -1,   464,   465,   466,   467,   468,   469,   470,
     471,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   486,   487,   488,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   498,   499,   500,
     501,    -1,   503,   504,    -1,    -1,    -1,    -1,   509,   510,
      -1,    -1,    -1,    -1,   515,   516,   517,     7,    -1,     9,
      10,    11,    -1,    13,    -1,    -1,   527,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    -1,    -1,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,
      50,    51,    -1,    -1,    54,    -1,    56,    -1,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    -1,
      -1,    71,    -1,    -1,    74,    75,    -1,    77,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,    -1,
     160,    -1,   162,   163,   164,   165,   166,   167,   168,    -1,
     170,   171,    -1,    -1,    -1,   175,    -1,   177,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    -1,    -1,    -1,    -1,   226,   227,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,    -1,    -1,
      -1,    -1,    -1,    -1,   274,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   283,   284,   285,   286,    -1,    -1,    -1,
      -1,   291,    -1,    -1,    -1,   295,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   312,   313,   314,   315,    -1,    -1,    -1,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,    -1,    -1,   333,   334,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   345,   346,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,    -1,   444,    -1,   446,   447,    -1,    -1,
      -1,    -1,    -1,    -1,   454,   455,   456,   457,   458,   459,
     460,   461,    -1,    -1,   464,   465,   466,   467,   468,   469,
     470,   471,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   486,   487,   488,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   498,   499,
     500,   501,    -1,   503,   504,    -1,    -1,    -1,    -1,   509,
     510,    -1,    -1,    -1,    -1,   515,   516,   517,     7,    -1,
       9,    10,    11,    -1,    13,    -1,    -1,   527,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    -1,    -1,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,
      -1,    50,    51,    -1,    -1,    54,    -1,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      -1,    -1,    71,    -1,    -1,    74,    75,    -1,    77,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
      -1,   160,    -1,   162,   163,   164,   165,   166,   167,   168,
      -1,   170,   171,    -1,    -1,    -1,   175,    -1,   177,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    -1,    -1,    -1,    -1,   226,   227,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,    -1,
      -1,    -1,    -1,    -1,    -1,   274,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   283,   284,   285,   286,    -1,    -1,
      -1,    -1,   291,    -1,    -1,    -1,   295,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   312,   313,   314,   315,    -1,    -1,    -1,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,    -1,    -1,   333,   334,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   345,   346,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,    -1,   444,    -1,   446,   447,    -1,
      -1,    -1,    -1,    -1,    -1,   454,   455,   456,   457,   458,
     459,   460,   461,    -1,    -1,   464,   465,   466,   467,   468,
     469,   470,   471,    -1,    -1,    -1,    -1,    -1,     7,    -1,
       9,    10,    11,    -1,    13,    -1,    -1,   486,   487,   488,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   498,
     499,   500,   501,    32,   503,   504,    35,    36,    -1,    -1,
     509,   510,    -1,    -1,    -1,    -1,   515,   516,   517,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,   527,    58,
      59,    60,    61,    -1,    63,    64,    65,    66,    67,    -1,
      -1,    -1,    71,    -1,    -1,    74,    75,    -1,    77,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
      -1,   160,    -1,   162,   163,   164,   165,   166,   167,   168,
      -1,   170,   171,    -1,    -1,    -1,    -1,    -1,   177,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    -1,    -1,    -1,    -1,   226,   227,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,    -1,
      -1,    -1,    -1,    -1,    -1,   274,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   283,   284,   285,   286,    -1,    -1,
      -1,    -1,   291,    -1,    -1,    -1,   295,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   312,   313,   314,   315,    -1,    -1,    -1,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,    -1,    -1,   333,   334,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   345,   346,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   404,   405,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,    -1,   444,    -1,   446,   447,    -1,
      -1,    -1,    -1,    -1,    -1,   454,   455,   456,   457,   458,
     459,   460,   461,    -1,    -1,   464,   465,   466,   467,   468,
     469,   470,   471,    -1,    -1,    -1,    -1,    -1,     7,    -1,
       9,    10,    11,    -1,    13,    -1,    -1,   486,   487,   488,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   498,
     499,   500,   501,    32,   503,   504,    35,    36,    -1,    -1,
     509,   510,    -1,    -1,    -1,    -1,   515,   516,   517,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,   527,    58,
      59,    60,    61,    -1,    63,    64,    65,    66,    67,    -1,
      -1,    -1,    71,    -1,    -1,    74,    75,    -1,    77,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
      -1,   160,    -1,   162,   163,   164,   165,   166,   167,   168,
      -1,   170,   171,    -1,    -1,    -1,    -1,    -1,   177,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    -1,    -1,    -1,    -1,   226,   227,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,    -1,
      -1,    -1,    -1,    -1,    -1,   274,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   283,   284,   285,   286,    -1,    -1,
      -1,    -1,   291,    -1,    -1,    -1,   295,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   312,   313,   314,   315,    -1,    -1,    -1,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,    -1,    -1,   333,   334,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   345,   346,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,    -1,   444,    -1,   446,   447,    -1,
      -1,    -1,    -1,    -1,    -1,   454,   455,   456,   457,   458,
     459,   460,   461,    -1,    -1,   464,   465,   466,   467,   468,
     469,   470,   471,    -1,    -1,    -1,    -1,    -1,     7,    -1,
       9,    10,    11,    -1,    13,    -1,    -1,   486,   487,   488,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   498,
     499,   500,   501,    32,   503,   504,    35,    36,    -1,    -1,
     509,   510,    -1,    -1,    -1,    -1,   515,   516,   517,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,   527,    58,
      59,    60,    61,    -1,    63,    64,    65,    66,    67,    -1,
      -1,    -1,    71,    -1,    -1,    74,    75,    -1,    77,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
      -1,   160,    -1,   162,   163,   164,   165,   166,   167,   168,
      -1,   170,   171,    -1,    -1,    -1,    -1,    -1,   177,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    -1,    -1,    -1,    -1,   226,   227,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,    -1,
      -1,    -1,    -1,    -1,    -1,   274,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   283,   284,   285,   286,    -1,    -1,
      -1,    -1,   291,    -1,    -1,    -1,   295,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   312,   313,   314,   315,    -1,    -1,    -1,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,    -1,    -1,   333,   334,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   345,   346,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,    -1,   444,    -1,   446,   447,    -1,
      -1,    -1,    -1,    -1,    -1,   454,   455,   456,   457,   458,
     459,   460,   461,    -1,    -1,   464,   465,   466,   467,   468,
     469,   470,   471,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   486,   487,   488,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   498,
     499,   500,   501,    -1,   503,   504,    -1,    -1,    -1,    -1,
     509,   510,    -1,    -1,    -1,    -1,   515,   516,   517,     7,
      -1,     9,    10,    11,    -1,    13,    -1,    -1,   527,    -1,
      -1,    -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    51,    -1,    -1,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    -1,    -1,    83,    84,    85,    86,    -1,
      88,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,
     148,   149,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   161,    -1,    -1,    -1,    -1,   166,    -1,
      -1,    -1,    -1,    -1,    -1,   173,   174,   175,   176,   177,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   212,   213,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   260,    -1,   262,    -1,    -1,    -1,    -1,    -1,
     268,   269,   270,   271,   272,   273,    -1,   275,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   316,   317,
     318,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   331,   332,   333,   334,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   404,   405,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,    -1,   444,   445,    -1,    -1,
     448,    -1,    -1,    -1,    -1,    -1,   454,   455,   456,   457,
     458,   459,   460,   461,    -1,    -1,   464,   465,   466,   467,
     468,   469,   470,    -1,   472,    -1,    -1,    -1,    -1,   477,
      -1,   479,   480,    -1,    -1,    -1,   484,   485,   486,   487,
       7,   489,    -1,    10,    11,    -1,    13,    -1,   496,   497,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   513,    -1,    -1,    35,    36,
     518,   519,    -1,   521,   522,   523,   524,   525,   526,   527,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    -1,    -1,    -1,    -1,    63,    64,    65,    -1,
      -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,
      77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     147,    -1,    -1,    -1,   151,   152,   153,   154,   155,   156,
     157,   158,    -1,   160,    -1,   162,   163,   164,   165,   166,
     167,   168,    -1,   170,   171,    -1,    -1,    -1,    -1,    -1,
     177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,    -1,   261,    -1,   263,   264,   265,   266,
     267,    -1,    -1,    -1,    -1,    -1,    -1,   274,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   283,   284,   285,   286,
      -1,    -1,    -1,    -1,   291,    -1,    -1,    -1,   295,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   312,   313,   314,   315,    -1,
      -1,    -1,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   345,   346,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     7,    -1,    -1,    10,    11,    -1,
      13,    -1,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,    -1,    -1,    -1,   446,
     447,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,   456,
     457,   458,   459,   460,   461,    -1,    -1,   464,   465,   466,
     467,   468,   469,   470,   471,    58,    -1,    -1,    -1,    -1,
      63,    64,    65,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,   488,    -1,    -1,    77,    78,    -1,    -1,    -1,    -1,
      -1,   498,   499,   500,   501,    -1,   503,   504,    -1,    -1,
      -1,    -1,   509,   510,    -1,    -1,    -1,    -1,   515,   516,
     517,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     527,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,   151,   152,
     153,   154,   155,   156,   157,   158,    -1,   160,    -1,   162,
     163,   164,   165,   166,   167,   168,    -1,   170,   171,    -1,
      -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,    -1,
      -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,    -1,   261,    -1,
     263,   264,   265,   266,   267,    -1,    -1,    -1,    -1,    -1,
      -1,   274,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     283,   284,   285,   286,    -1,    -1,    -1,    -1,   291,    -1,
      -1,    -1,   295,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   312,
     313,   314,   315,    -1,    -1,    -1,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   345,   346,   347,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     7,    -1,    -1,    10,    11,    -1,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   429,   430,   431,   432,
      -1,    -1,    58,    -1,    -1,    -1,    -1,    63,    64,    65,
      -1,    -1,    -1,   446,   447,    71,    -1,    -1,    -1,    -1,
      -1,    77,    78,   456,   457,   458,   459,   460,   461,    -1,
      -1,   464,   465,   466,   467,   468,   469,   470,   471,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   488,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   498,   499,   500,   501,    -1,
     503,   504,    -1,    -1,    -1,    -1,   509,   510,    -1,    -1,
      -1,    -1,   515,   516,   517,    -1,    -1,    -1,    -1,    -1,
      -1,   147,    -1,    -1,   527,   151,   152,   153,   154,   155,
     156,   157,   158,    -1,   160,    -1,   162,   163,   164,   165,
     166,   167,   168,    -1,   170,   171,    -1,    -1,    -1,    -1,
      -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,
     226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,   261,    -1,   263,   264,   265,
     266,   267,    -1,    -1,    -1,    -1,    -1,    -1,   274,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   283,   284,   285,
     286,    -1,    -1,    -1,    -1,   291,    -1,    -1,    -1,   295,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   312,   313,   314,   315,
      -1,    -1,    -1,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   345,
     346,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,
      -1,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   429,   430,   431,   432,    -1,    -1,    58,
      -1,    -1,    -1,    -1,    63,    64,    65,    -1,    -1,    -1,
     446,   447,    71,    -1,    -1,    -1,    -1,    -1,    77,    78,
     456,   457,   458,   459,   460,   461,    -1,    -1,   464,   465,
     466,   467,   468,   469,   470,   471,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   488,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   498,   499,   500,   501,    -1,   503,   504,    -1,
      -1,    -1,    -1,   509,   510,    -1,    -1,    -1,    -1,   515,
     516,   517,    -1,    -1,    -1,    -1,    -1,    -1,   147,    -1,
      -1,   527,   151,   152,   153,   154,   155,   156,   157,   158,
      -1,   160,    -1,   162,   163,   164,   165,   166,   167,   168,
      -1,   170,   171,    -1,    -1,    -1,    -1,    -1,   177,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,    -1,   261,    -1,   263,   264,   265,   266,   267,    -1,
      -1,    -1,    -1,    -1,    -1,   274,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   283,   284,   285,   286,    -1,    -1,
      -1,    -1,   291,    -1,    -1,    -1,   295,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   312,   313,   314,   315,    -1,    -1,    -1,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   345,   346,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     429,   430,   431,   432,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   446,   447,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   456,   457,   458,
     459,   460,   461,    -1,    -1,   464,   465,   466,   467,   468,
     469,   470,   471,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   488,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   498,
     499,   500,   501,    -1,   503,   504,    -1,    -1,    -1,    -1,
     509,   510,    -1,    -1,    -1,    -1,   515,   516,   517,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   527
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
      74,    75,    76,    77,    78,    79,    80,    83,    84,    85,
      86,    88,    89,   146,   147,   148,   149,   150,   161,   166,
     173,   174,   175,   176,   177,   212,   213,   227,   260,   262,
     268,   269,   270,   271,   272,   273,   275,   316,   317,   318,
     331,   332,   333,   334,   404,   405,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   444,   445,   448,   454,
     455,   456,   457,   458,   459,   460,   461,   464,   465,   466,
     467,   468,   469,   470,   472,   477,   479,   480,   484,   485,
     486,   487,   489,   496,   497,   513,   518,   519,   521,   522,
     523,   524,   525,   526,   527,   529,   530,   531,   532,   533,
     534,   537,   538,   539,   540,   544,   545,   546,   547,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   611,   612,
      10,    11,    13,    59,    60,    61,    63,    64,    66,    67,
      74,    75,    77,    78,   166,   177,   456,   457,   458,   459,
     460,   461,   464,   465,   466,   467,   468,   469,   470,   554,
     555,   570,   609,    66,   555,   595,   555,   595,    62,   568,
     569,   570,   608,    13,    13,    13,   483,   570,   609,    54,
      68,    69,    70,    71,   611,   570,   547,   568,   608,   547,
     568,   547,   570,    13,    13,   547,    13,    13,   134,   135,
     145,   134,   135,   145,   134,   135,   145,   145,    19,    19,
     125,   126,    13,   145,    19,   145,    13,    13,    13,   531,
     611,   240,    19,    19,    15,   124,    15,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    69,    70,    72,    73,
      74,    75,    76,    77,    78,   570,   612,   547,    13,    13,
      13,    13,    15,    13,    13,    15,    13,    15,    13,    19,
      19,    19,    19,    13,    13,    13,    15,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,   555,   595,   555,   595,
     555,   595,   555,   595,   555,   595,   555,   595,   555,   595,
     555,   595,   555,   595,   555,   595,   555,   595,   555,   595,
     555,   595,   611,   548,   549,   568,   531,   547,   547,    13,
      13,    13,    72,   611,   611,    13,    13,    13,    13,    13,
      13,     0,     0,   531,   532,   533,   534,   537,   538,   539,
     540,   531,    12,    10,    11,   141,   142,   555,   595,     7,
       8,    12,    10,    11,     5,     6,   139,   140,   141,   142,
      17,     4,    18,   137,    21,   138,    13,    15,    19,   124,
     125,   145,   143,     7,   144,    10,    11,    19,   124,   124,
     145,    19,    19,    19,    19,    15,    15,    19,    19,    13,
      19,    19,    14,    14,    19,    14,   547,   568,   547,    19,
     547,   547,    77,   612,   612,   568,   568,   568,   547,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   378,   408,   409,   410,   411,   412,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   502,   520,   350,   352,   354,   355,   362,   365,
     366,   367,   368,   369,   370,   371,   372,   402,   406,   411,
     412,   422,   427,   428,   609,   609,   568,   568,   608,    42,
      43,   450,   451,   452,   453,   449,    10,    11,    13,    17,
      35,    36,    63,    65,    71,   147,   151,   152,   153,   154,
     155,   156,   157,   158,   160,   162,   163,   164,   165,   166,
     167,   168,   170,   171,   177,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   226,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   261,   263,   264,   265,   266,   267,   274,   283,
     284,   285,   286,   291,   295,   312,   313,   314,   315,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   345,   346,   429,   430,   431,   432,   446,   447,   456,
     457,   458,   459,   460,   461,   464,   465,   466,   467,   468,
     469,   470,   471,   488,   498,   499,   500,   501,   503,   504,
     509,   510,   515,   516,   517,   542,   547,   554,   568,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   609,
     542,   542,    41,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   410,    42,   243,   568,   347,
     568,    15,   568,   568,    10,    11,    13,    63,   147,   166,
     177,   456,   457,   458,   459,   460,   461,   464,   465,   466,
     467,   468,   469,   470,   554,   570,   589,   609,    63,   568,
     589,   589,   589,   589,   589,   589,   589,   570,   169,   222,
     223,   224,   225,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   224,   225,   224,   225,   224,
     225,   570,   570,   570,   589,   589,   570,   570,   570,   570,
     570,   570,   570,   570,    54,    54,   568,   568,   570,   568,
     570,   568,    10,    11,    13,    66,   456,   457,   458,   459,
     460,   461,   464,   465,   466,   467,   468,   469,   470,   554,
     608,   547,   589,   570,   145,   476,    55,   548,   531,   611,
     612,   547,    54,   536,   535,   548,   568,   547,    63,   570,
     570,   570,   531,   547,   568,   545,   545,   547,   547,   555,
     555,   555,   556,   556,   558,   558,   558,   558,   559,   559,
     560,   561,   562,   563,   565,   564,   568,   568,    49,    50,
     159,   222,   240,   243,   244,   245,   246,   275,   276,   277,
     407,   408,   413,   426,   443,   611,   589,   589,   568,   589,
     555,   595,   595,   556,   596,   556,   596,   240,   241,   242,
     243,   273,   281,   292,   296,   339,   341,   342,   343,   352,
     353,   358,   359,   360,   361,   373,   374,   375,   376,   377,
     379,   380,   381,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   511,   278,
     279,   280,   287,   288,   289,   290,   294,   335,   338,   339,
     340,   341,   343,   344,   347,   506,   507,   508,   512,   514,
     609,   610,   347,   589,    10,    11,    13,    17,    35,    37,
      65,    68,    76,    87,    90,   347,   403,   434,   437,   449,
     456,   457,   458,   459,   460,   461,   464,   465,   466,   467,
     468,   469,   470,   547,   554,   568,   589,   590,   608,   609,
     610,    81,   568,   568,   568,    13,   553,    20,    14,    14,
      14,    20,    14,    14,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    20,   547,   568,   547,    13,    13,    13,
     570,   574,   575,   575,   569,   589,    59,    60,   570,   609,
      13,   547,    13,    19,    19,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    19,    13,    13,    13,    13,    19,    13,    13,    13,
      19,    19,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,   575,   575,   575,   575,   575,   575,   575,   575,   575,
     575,   575,   575,   575,   575,    13,    13,    13,    13,    13,
      13,    19,    13,    13,    13,    13,    13,    14,    20,   575,
      13,    15,   145,     4,     7,     8,    10,    11,     5,     6,
     139,   140,   141,   142,    17,    18,   137,    21,   138,    19,
      14,    14,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,   547,    16,    15,    16,   568,
      14,    20,   569,   570,    19,    13,    19,    19,    13,    14,
      19,    20,    14,    16,    14,    14,    16,    14,    16,    20,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    20,    14,    20,    14,    16,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    14,    14,    20,
      20,    14,    20,    14,    14,    20,    14,   568,   541,   547,
     550,   482,   531,    14,    14,    14,    14,    13,    13,   531,
      20,    14,    20,    20,    20,    20,    22,    14,    20,    22,
      23,    16,    13,    13,   547,    13,    13,    13,    13,    13,
      13,    13,    13,    13,   547,    13,    13,   547,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
     547,    13,    13,    13,    13,    13,    19,    15,   612,    15,
      13,    19,    13,    13,    15,    13,    13,    13,    13,    20,
      20,    19,    13,    16,    16,   547,    12,   568,   568,   570,
     568,   568,   568,   568,   568,   570,   568,   568,    63,   570,
      56,    63,   568,   568,   568,   568,   568,   568,   568,   589,
     568,    65,   568,    72,   568,   568,   610,   568,   568,   568,
     568,   568,   609,    65,   590,    65,    56,   568,   568,   568,
     568,   547,    59,    62,   547,    14,    14,   547,   569,   570,
     568,   348,   348,   349,   542,   589,   570,   589,   589,   570,
     570,   570,   570,   570,   589,   570,   570,   570,   570,   570,
      52,    53,   570,   570,   570,   570,    52,   187,   222,   589,
     589,   570,   222,   222,   570,   570,   570,   570,   570,   570,
     570,   570,   570,   589,   570,   570,   570,   570,   570,   570,
     570,   570,   570,   570,   570,   570,   570,   589,   589,   589,
     589,   589,   570,   570,   570,   570,   570,   609,   609,   547,
     547,   570,   570,   570,   570,   570,   570,   570,   570,   570,
     570,   570,   570,   570,   589,   570,   570,   570,   570,   570,
     570,   589,   589,   589,   589,   589,   570,   589,   589,   505,
     589,   589,   589,   589,   547,    17,    63,   547,   568,   589,
     589,    22,    63,   568,   570,   613,   588,   575,   555,   575,
     555,   575,   556,   576,   556,   576,   558,   579,   558,   579,
     558,   579,   558,   579,   558,   580,   558,   580,   581,   583,
     584,   586,   585,   293,   382,   383,   384,   385,   531,   547,
     547,   547,   568,    59,    60,   547,    61,    60,   568,    62,
      62,    62,   547,   568,    72,   568,   568,   547,   568,   568,
     568,   568,   145,   568,   145,    16,    72,    14,    19,   589,
     568,    13,    13,    13,   570,   568,   570,   568,   568,   568,
     570,   570,   570,   570,   568,   568,   568,   568,   568,   568,
     568,   570,   568,   570,   570,   570,   172,   570,   570,   172,
     570,   172,   570,   570,   570,   568,   568,   568,   568,   568,
     568,   568,   568,   568,   568,   568,   568,   568,   568,   568,
     570,   589,    13,   568,   568,   568,   568,   568,   568,   568,
     570,   570,   570,   568,   568,   568,   547,   473,    20,   548,
     548,   490,   491,   492,   493,   494,   543,   543,   568,   568,
     547,   570,   570,   566,   568,   568,   568,   145,   547,   570,
     570,   570,   568,   570,   568,   570,   568,   568,   568,   568,
     568,   568,   568,   568,   568,   568,   568,   568,   568,   589,
     568,   568,   568,   568,   568,   568,   568,   568,   570,   589,
     568,   589,   568,   568,   570,   568,   568,   568,   589,   570,
     609,   609,   609,   589,   589,   589,   547,   589,   570,   609,
     570,   609,   609,   589,    14,   547,   589,   589,   589,   589,
     589,   282,   568,   568,   547,   401,   542,   547,   568,    76,
     568,   568,   547,   547,   547,   547,    20,   547,   568,    14,
      20,    20,    20,    20,    20,    14,    20,    14,    20,    14,
      14,    14,    20,    20,    20,    20,    20,    14,    14,    20,
      20,    20,    20,    14,    20,    14,    20,    14,    20,    14,
      14,    20,    20,    20,    20,    14,    19,    14,    20,    14,
      20,    20,    20,    14,    14,    14,    14,    14,    20,    13,
     574,    14,    20,    19,    20,    14,    20,    20,    20,    20,
      14,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    14,    20,    13,    13,    20,    20,    20,
      13,    13,    14,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    14,    14,    14,    20,    14,    20,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    20,    20,    20,
      20,    14,    20,    20,    20,    20,    20,    20,    14,    14,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    14,    14,    14,    14,    14,    14,    14,
      20,    20,    20,    14,    20,    20,    20,    20,    20,    13,
      14,    20,    14,    20,    20,    14,    14,    59,    60,   570,
     609,    14,    20,    16,    22,    16,    22,    13,    13,    13,
      13,    13,    14,    14,    14,    20,    20,    20,    20,    14,
      20,    14,    20,    20,    20,    20,    20,    20,    20,    14,
      14,    20,    20,    14,    20,    20,    20,    14,   610,    16,
     589,    14,    13,    14,   589,   570,   570,    14,    20,    14,
      20,    14,    20,    14,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    20,    14,    14,    20,
      14,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    20,    14,    20,    14,    14,    14,    14,    20,    14,
      14,    14,    14,    14,    20,    14,    14,   589,    20,    20,
      14,    20,    20,    20,    14,    20,    20,    20,    20,    20,
      20,    14,    20,   568,   547,   531,   531,    57,    57,    57,
      57,    57,    14,    20,    14,    20,    20,    14,    20,    20,
      14,    20,    23,    20,    14,   568,   589,    14,    14,    20,
      14,    14,    20,    14,    20,    14,    14,    14,    20,    20,
      20,    14,    20,    14,    14,    14,    14,    14,    20,    14,
      14,    20,    14,    20,    14,    20,    20,    20,    14,    14,
      14,    14,    14,    14,    14,    14,    20,    20,    14,    14,
      20,    14,    14,    14,    14,    20,    20,    20,    20,    20,
      20,    14,    20,    20,    20,    14,    20,    20,    20,    20,
      20,    14,    14,    20,    20,    20,    20,    20,    13,    16,
      16,    14,    14,    14,    16,    20,    14,    14,    20,    14,
     547,   570,   568,   568,   568,   568,   568,   568,   570,   570,
     568,   568,   568,   568,   568,   568,   568,   568,   568,   568,
     568,   568,   568,   568,   568,   570,   568,   589,   145,    54,
     568,   568,   589,    54,   570,   568,   568,   568,   568,   568,
     568,   568,   568,   568,   568,   568,   568,   568,   568,   568,
     570,   570,   589,   589,   570,   570,   570,   568,   568,   568,
     568,   568,   568,   568,   568,   568,   570,   570,   570,   570,
     570,   570,   570,   570,   568,   568,   568,   568,   589,   589,
     568,   568,   568,   568,   570,   547,   570,   570,   568,   568,
     568,   568,   568,   568,   568,   568,   568,   568,   568,   568,
     568,   568,   568,   568,   570,   568,   568,   570,   568,   568,
     589,    22,   568,   587,   568,   570,    14,    14,    14,   568,
     547,   568,   547,   568,    72,   547,   547,   568,   547,   547,
     547,   547,   547,   568,   568,   568,   568,   568,   568,    14,
      14,    14,    20,   570,   568,   568,   568,   570,   568,   568,
     568,   568,    14,   568,   568,   568,   589,   568,   568,   568,
     568,   570,   570,   568,   568,   568,   474,   548,   548,   490,
     491,   492,   493,   494,   548,   568,   568,   570,   568,   568,
     568,   568,   568,   568,   568,   568,   568,   568,   568,   568,
     568,   568,   568,   568,   568,   568,   568,   568,   568,   568,
     568,   568,   568,   568,   568,   568,   568,   568,   568,   568,
     568,   568,   568,   568,   568,   568,   589,   589,   568,    76,
      20,    20,    54,    14,    20,    14,    20,    14,    20,    14,
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
      14,    20,    20,    20,    20,    14,    14,    14,    14,    14,
      14,    14,    20,    14,    14,    14,    20,    14,    14,    14,
     568,    14,    20,    14,    14,    20,    20,    14,    20,    20,
      14,    20,    14,    20,    14,    20,    14,    20,    20,    20,
      20,    20,    20,    20,    20,    14,   568,   531,   531,    57,
      57,    57,    57,    57,   531,    14,    20,    20,    20,    14,
      20,    23,    14,    22,    20,    20,    20,    20,    20,    20,
      20,    14,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    14,    20,    20,    20,    20,    14,    14,    20,    14,
      14,    14,    14,    14,    20,    14,    20,    20,    20,    20,
      20,    20,    20,    20,   547,   547,    14,   568,   568,   568,
     568,   568,   568,   568,   568,   568,   568,   568,   568,   568,
     568,   568,   568,   570,   568,   569,   569,   570,    54,   570,
     568,   568,   568,   568,   568,   568,   568,   568,   568,   568,
     568,   570,   568,   570,   568,   568,   568,   568,   568,   568,
     568,   568,   568,   568,   568,   568,   568,   570,   570,   570,
     570,   570,   568,   568,   568,   589,   589,   568,   568,   568,
     568,   568,   568,   568,   568,   568,   568,   568,   568,   568,
     568,   568,   568,   568,   547,   568,    14,   568,   570,   568,
     568,   568,   589,   589,   589,   589,   568,   568,   568,   570,
     570,   568,   568,   548,   568,   570,   568,   568,   568,   568,
     568,   568,   568,   568,   568,   568,   568,   568,   568,   568,
     568,   568,   568,   568,   568,   568,   568,   568,   568,   568,
     570,   589,   568,   568,   568,   568,   589,   589,   568,   568,
      14,    14,    20,    20,    14,    20,    20,    14,    20,    20,
      14,    20,    20,    20,    14,    20,    20,    14,    20,    20,
      14,    14,    20,    20,    20,    20,    14,    20,    14,    20,
      14,    20,    14,    20,    20,    20,    20,    20,    14,    14,
      14,    20,    20,    20,    20,    20,    20,    14,    20,    20,
      20,    20,    20,    20,    20,    14,    20,    20,    20,    20,
      20,    20,    20,    14,    14,    14,    14,    20,    20,    14,
      20,    20,    20,    20,    20,    20,    14,    20,    22,    22,
      20,    14,    20,    14,    20,    14,    20,    14,    20,    14,
      20,    14,    14,    20,    14,    20,    20,    14,    20,    14,
      20,    20,    14,    14,   531,    20,    20,    20,    14,    14,
      20,    20,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    20,    20,    20,    20,
      20,    14,    14,    14,    20,    14,    20,    20,    20,    14,
      14,   568,   568,   568,   568,   568,   568,   568,   568,   568,
     568,   568,   569,   568,   569,    54,   568,   568,   568,   568,
     568,   568,   568,   568,   568,   568,   568,   568,   568,   568,
     568,   568,   568,   613,   568,   613,   568,   613,   568,   568,
     568,   568,   568,   568,   568,   568,   568,   570,   568,   568,
     568,   568,   568,   568,   568,   568,   568,   568,   568,   568,
     568,   568,   547,   568,   568,   568,   568,   568,   568,   568,
     589,   570,   568,   570,   568,   568,   568,   568,   568,   568,
     568,   568,   589,   568,   568,   568,    20,    14,    14,    20,
      20,    20,    14,    14,    14,    20,    14,    20,    20,    20,
      14,    14,    20,    20,    20,    14,    20,    14,    20,    20,
      20,    20,    20,    20,    14,    20,    20,    20,    20,    20,
      20,    20,    14,    20,    14,    14,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    14,    20,    20,    14,    14,
      20,    14,    14,    14,    20,    20,    20,    14,    16,    20,
      14,    14,    14,    14,    14,    20,    20,    14,    14,    20,
      20,    14,    20,    20,    20,    20,    22,    14,    14,    20,
      20,    14,    20,    20,    20,    20,    20,   568,   568,   568,
     568,   568,   568,   568,   547,   569,   568,   568,   568,   568,
     568,   568,   568,   568,   568,   568,   568,   568,   568,   568,
     568,   613,   613,   613,   613,   568,   568,   568,   570,   570,
     570,   570,   568,   568,   568,   568,   568,   568,   568,   568,
     568,   568,   568,   570,   568,   570,   568,   568,   568,   568,
     568,   589,   568,   568,   568,    14,    20,    20,    20,    20,
      14,    20,    20,    14,    14,    20,    14,    14,    14,    14,
      14,    14,    20,    14,    20,    14,    20,    14,    14,    20,
      14,    14,    14,    14,    20,    14,    14,    14,    14,    20,
      20,    14,    20,    14,    20,    14,    20,    22,    20,    14,
      20,    20,    20,    20,    20,    20,    14,    20,    20,    20,
      14,    20,    20,    20,    20,   568,   568,   568,   568,   547,
     568,   568,   568,   568,   568,   568,   568,   613,   568,   568,
     568,   568,   568,   568,   568,   568,   568,   570,   568,   570,
     568,   145,   568,   568,   568,   589,   568,   568,   568,    14,
      14,    20,    14,    14,    20,    20,    20,    14,    14,    14,
      20,    14,    20,    20,    14,    20,    20,    14,    14,    20,
      20,    14,    20,    20,    20,    20,   589,    20,    20,    14,
      20,    20,    14,    14,    20,    20,   568,   547,   568,   568,
     568,   568,   568,   568,   568,   589,   568,   589,   568,   568,
     568,   568,   568,   568,   568,   568,   568,    20,    14,    14,
      14,    14,    14,    20,    20,    20,    14,    14,    14,    20,
      20,    20,    14,    20,    20,    14,    14,    20,    14,    20,
     568,   568,   568,   568,   568,   568,   570,   568,   568,   568,
     589,    20,    20,    14,    20,    14,    20,    20,    14,    20,
      14,    20,   568,   568,   568,   568,   570,   568,   589,    20,
      14,    20,    20,    20,    14,    14,   568,   568,   568,   568,
      20,    20,    20,    14,   568,   568,   568,    20,    20,    20,
     568,   568,   568,    14,    20,    20,   568,   568,    20,    14,
     568,    14
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
     540,   540,   540,   540,   540,   540,   540,   540,   541,   541,
     542,   542,   542,   542,   542,   542,   542,   542,   542,   542,
     542,   542,   542,   542,   542,   542,   542,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   544,   544,
     545,   545,   545,   545,   545,   545,   545,   545,   545,   545,
     545,   546,   546,   546,   547,   548,   549,   550,   551,   551,
     551,   551,   551,   551,   551,   551,   552,   552,   552,   552,
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
     612,   612,   612,   613,   613,   613,   613
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
       1,     2,     2,     2,     2,     2,     2,     4,     4,     2,
       2,     2,     2,     1,     4,     3,     2,     2,    10,     6,
       3,     6,     6,     8,    28,     8,     8,     3,     8,    12,
       6,     6,    16,     8,    16,    10,     6,    10,     8,    10,
      14,     8,    12,     6,     8,     6,     6,     6,    10,     6,
      10,    10,    12,     6,     6,    12,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     8,     3,
       3,     3,     3,     3,     3,    12,    16,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,    10,     6,    14,
       6,     8,     6,     6,     8,     6,    10,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     3,     3,
       4,     3,     6,     6,     4,     4,     6,    10,    10,    10,
       6,     6,     6,     6,     6,    10,     6,    10,     6,     6,
       6,     3,     6,     6,    10,    10,     6,     6,     6,     3,
       3,     3,     3,     6,     6,     3,     6,     6,     8,    10,
       3,     6,     3,     4,    20,     6,    10,     6,     3,     3,
       6,     3,     6,     8,     6,     6,     8,    16,     6,     3,
       6,     8,     3,    12,    12,    12,    10,     3,     3,     8,
       8,    10,     8,    10,    12,     6,     8,     8,    10,    16,
      18,    12,     6,    18,    16,    12,    10,    10,    10,     6,
      10,     6,     6,     6,     8,     1,     4,     4,     8,     4,
      18,     4,     1,     1,     1,     6,     3,     8,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     6,     8,
       6,    10,     6,     8,     8,     8,     8,     6,     3,     4,
       1,     1,     1,    30,    24,     4,     4,     8,     1,     3,
       0,     1,     3,     1,     3,     2,     4,     2,     4,     1,
       3,     2,     4,     2,     4,     1,     3,     0,     2,     2,
       2,     2,     2,     4,     4,     4,     4,     4,     1,     1,
       1,     6,     6,     6,     3,     3,     1,     3,     4,     4,
       1,     1,     3,     3,     1,     3,     0,     0,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     4,     6,     8,
      10,    10,    10,     8,     6,     3,     3,     3,     2,     3,
       3,     3,     6,     4,    10,     4,    10,     4,     4,     4,
       4,     4,     4,     7,     7,     7,     9,     7,     6,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     6,     8,    10,    12,    10,    12,     8,     6,
       8,     8,     8,     8,     6,     8,     8,     8,    12,     6,
       6,     3,     6,     6,     4,     4,     4,     1,     6,     6,
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
       1,     1,     1,    11,     7,     1,     1
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
  "VAR_C_FUNCTION", "VAR_C_PROCEDURE", "VAR_CLASS_PROCEDURE",
  "VAR_C_IMAGE_FUNCTION", "VAR_AMI_FUNCTION", "VAR_AMI_CLASS",
  "VAR_AMI_OBJECT", "VAR_PARAMWIN", "VAR_GLTRANSFORM", "VAR_ARRAY_SURFACE",
  "VAR_ARRAY_IMAGE", "T_del", "T_delvars", "T_Comments", "ENDOP",
  "T_global", "T_local", "T_global_new", "T_local_new", "T_context",
  "T_wait", "T_schedule", "T_ParamWin", "T_BeginPanel", "T_EndPanel",
  "T_BeginBoxPanel", "T_EndBoxPanel", "T_BeginBook", "T_EndBook",
  "T_AddPage", "T_SelectPage", "T_AddFloat", "T_AddInt", "T_CreateWin",
  "T_Display", "T_AddButton", "T_AddBoolean", "T_AddEnum",
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
  "T_RestartTime", "T_InitTime", "T_TimeSpent", "T_EndTime",
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
       529,     0,    -1,    -1,   530,     0,    -1,   531,    -1,   530,
     531,    -1,   540,   531,    -1,   530,   540,   531,    -1,   532,
      -1,   530,   532,    -1,   533,    -1,   530,   533,    -1,   539,
      -1,   530,   539,    -1,   534,    -1,   530,   534,    -1,   537,
      -1,   530,   537,    -1,   538,    -1,   530,   538,    -1,    34,
      -1,    23,    -1,   472,   611,   145,   568,   473,   568,   548,
     531,    -1,   472,   611,   145,   568,   473,   568,   474,   568,
     548,   531,    -1,   472,   611,   476,   541,   548,   531,    -1,
     477,   548,    -1,   480,   568,   548,   531,    -1,   480,   568,
     548,   482,   548,   531,    -1,    -1,   496,   611,   535,    13,
     543,    14,   548,   531,    -1,    -1,   496,    72,   536,    13,
     543,    14,   548,   531,    -1,   497,   611,   548,   531,    -1,
      73,   611,    -1,   484,   547,   531,    -1,   484,   531,    -1,
     485,   547,    -1,    72,    13,   542,    14,   531,    -1,    72,
     531,    -1,    33,    -1,   479,    -1,    83,    -1,    85,    -1,
      86,    -1,    84,    -1,    88,    13,   568,    14,    -1,    89,
      13,   568,    20,    72,    14,    -1,   611,   145,    17,   612,
      -1,   611,   145,   347,    15,   568,    16,    -1,   611,   124,
     347,    15,   568,    16,    -1,   611,   145,    35,    15,   568,
      16,    -1,   611,   145,   589,    -1,   611,   124,   589,    -1,
     611,   145,    68,    13,   542,    14,    -1,    78,    15,   568,
      16,   145,   589,    -1,   611,   145,   608,    -1,   611,   145,
     590,    -1,    66,   145,   568,    -1,    66,   145,   608,    -1,
      77,    15,   568,    16,   145,   610,    -1,   611,   145,    87,
      -1,   611,   145,   610,    -1,   609,   124,   610,    -1,    77,
     124,   347,    15,   568,    16,    -1,   611,   145,   437,    13,
     568,    14,    -1,   611,   145,   437,    13,   568,    14,    20,
     547,    -1,   611,   145,   434,    13,   568,    14,    -1,   611,
     145,   434,    13,   568,    14,    20,   547,    -1,   611,   145,
     568,    -1,   611,   145,   568,    20,   547,    -1,   611,   145,
     547,    -1,   611,   145,   547,    20,   547,    -1,   611,   145,
     449,    13,   547,    20,    54,    14,    -1,    67,   145,   449,
      13,   547,    20,    54,    14,    -1,    67,    19,   453,    -1,
      24,    -1,    25,    -1,    26,    -1,    27,    -1,    28,    13,
     547,    20,   547,    20,   547,    14,    -1,    29,    13,   568,
      14,    -1,    30,    13,   547,    14,    -1,    40,    -1,    38,
     570,    -1,    41,   570,    -1,    38,   609,    -1,   570,   145,
     589,    -1,   570,   125,   589,    -1,   570,   124,   589,    -1,
     570,   145,   568,    -1,   570,    15,   568,    16,   145,   589,
      -1,   570,    15,   568,    16,   145,   568,    -1,   570,    13,
     568,    22,   568,    20,   568,    22,   568,    20,   568,    22,
     568,    14,   145,   589,    -1,    59,   134,    -1,    59,   135,
      -1,    59,   145,   568,    -1,    60,   134,    -1,    60,   135,
      -1,    60,   145,   568,    -1,    61,   145,   568,    -1,    61,
     134,    -1,    61,   135,    -1,    62,   145,   547,    -1,    38,
     483,    -1,   612,    19,    81,    13,   547,    14,    -1,    79,
     612,    -1,    80,   547,    -1,    79,    77,    15,   568,    16,
      -1,    47,   547,    -1,    48,    -1,    39,    -1,    39,   611,
      -1,    39,    71,    -1,    39,    68,    -1,    39,    69,    -1,
      39,    70,    -1,    39,    54,    -1,    67,    19,    42,   547,
      -1,    67,    19,    43,   547,    -1,    42,   547,    -1,    43,
     547,    -1,    42,   608,    -1,    44,   547,    -1,   608,    -1,
      67,    19,    42,   568,    -1,    67,    19,   450,    -1,    42,
     568,    -1,    43,   568,    -1,    63,    19,   408,    13,   568,
      20,   568,    20,   568,    14,    -1,    63,    19,   409,    13,
     568,    14,    -1,    63,    19,   410,    -1,    63,    19,   411,
      13,   570,    14,    -1,    63,    19,   411,    13,    63,    14,
      -1,    63,    19,   414,    13,    63,    20,   570,    14,    -1,
      63,    19,   502,    13,   568,    20,   568,    20,   568,    20,
     568,    20,   568,    20,   568,    20,   568,    20,   568,    20,
     568,    20,   568,    20,   568,    20,   568,    14,    -1,    63,
      19,   412,    13,    56,    20,   570,    14,    -1,    63,    19,
     415,    13,   568,    20,   568,    14,    -1,    63,    19,   416,
      -1,    63,    19,   417,    13,   568,    20,   568,    14,    -1,
      63,    19,   418,    13,   568,    20,   568,    20,   568,    20,
     568,    14,    -1,    63,    19,   419,    13,   568,    14,    -1,
      63,    19,   420,    13,   568,    14,    -1,    63,    19,   421,
      13,   568,    20,   568,    20,   568,    20,   568,    20,   568,
      20,   568,    14,    -1,    63,    19,   422,    13,   568,    20,
     568,    14,    -1,    63,    19,   424,    13,   568,    20,   568,
      20,   568,    20,   568,    20,   568,    20,   568,    14,    -1,
      63,    19,   423,    13,   589,    20,   568,    20,   568,    14,
      -1,    63,    19,   425,    13,    65,    14,    -1,    63,    19,
     297,    13,   568,    20,   570,    20,   568,    14,    -1,    63,
      19,   297,    13,   570,    20,   568,    14,    -1,    63,    19,
     298,    13,   568,    20,   568,    20,   568,    14,    -1,    63,
      19,   298,    13,   568,    20,   568,    20,   568,    20,   568,
      20,   568,    14,    -1,    63,    19,   299,    13,   568,    20,
     568,    14,    -1,    63,    19,   300,    13,   568,    20,   568,
      20,   568,    20,   568,    14,    -1,    63,    19,   301,    13,
     568,    14,    -1,    63,    19,   302,    13,   568,    20,   568,
      14,    -1,    63,    19,   520,    13,    72,    14,    -1,    63,
      19,   378,    13,   570,    14,    -1,   570,    19,   426,    13,
     568,    14,    -1,   570,    19,   426,    13,   568,    20,   568,
      20,   568,    14,    -1,   570,    19,   407,    13,   568,    14,
      -1,   570,    19,   407,    13,   568,    20,   568,    20,   568,
      14,    -1,   570,    19,   408,    13,   568,    20,   568,    20,
     568,    14,    -1,   570,    19,   159,    13,   570,    20,   568,
      20,   568,    20,   568,    14,    -1,   570,    19,   159,    13,
     570,    14,    -1,   570,    19,    49,    13,   547,    14,    -1,
     166,    19,   222,    13,   570,    20,   568,    20,   568,    20,
     568,    14,    -1,   166,    19,   223,    13,   568,    14,    -1,
     166,    19,   169,    13,   568,    14,    -1,   166,    19,   228,
      13,   568,    14,    -1,   166,    19,   229,    13,   568,    14,
      -1,   166,    19,   232,    13,   570,    14,    -1,   166,    19,
     233,    13,   570,    14,    -1,   166,    19,   234,    13,   570,
      14,    -1,   166,    19,   235,    13,   570,    14,    -1,   166,
      19,   236,    13,   568,    14,    -1,   166,    19,   237,    13,
     568,    14,    -1,   166,    19,   238,    13,   568,    14,    -1,
     166,    19,   239,    13,   568,    14,    -1,   166,    19,   223,
      13,   568,    20,   568,    14,    -1,   166,    19,   224,    -1,
     166,    19,   225,    -1,   212,    19,   224,    -1,   212,    19,
     225,    -1,   213,    19,   224,    -1,   213,    19,   225,    -1,
     177,    19,   195,    13,   568,    20,   568,    20,   568,    20,
     568,    14,    -1,   177,    19,   195,    13,   568,    20,   568,
      20,   568,    20,   568,    20,   568,    20,   568,    14,    -1,
     177,    19,   179,    13,   568,    14,    -1,   177,    19,   180,
      13,   568,    14,    -1,   177,    19,   181,    13,   568,    14,
      -1,   177,    19,   194,    13,   568,    14,    -1,   177,    19,
     198,    13,   568,    14,    -1,   177,    19,   203,    13,   568,
      14,    -1,   177,    19,   204,    13,   568,    14,    -1,   177,
      19,   205,    13,   568,    14,    -1,   177,    19,   206,    13,
     568,    14,    -1,   177,    19,   201,    13,   568,    14,    -1,
     177,    19,   202,    13,   568,    20,   568,    20,   568,    14,
      -1,   177,    19,   207,    13,   568,    14,    -1,   177,    19,
     208,    13,   568,    20,   568,    20,   568,    20,   568,    20,
     568,    14,    -1,   177,    19,   196,    13,   568,    14,    -1,
     177,    19,   182,    13,   570,    20,   568,    14,    -1,   177,
      19,   183,    13,   568,    14,    -1,   177,    19,   184,    13,
     570,    14,    -1,   177,    19,   197,    13,   568,    20,   568,
      14,    -1,   177,    19,   186,    13,   570,    14,    -1,   177,
      19,   185,    13,   570,    20,   570,    20,   570,    14,    -1,
     177,    19,   188,    13,   570,    14,    -1,   177,    19,   189,
      13,   570,    14,    -1,   177,    19,   190,    13,   570,    14,
      -1,   177,    19,   193,    13,   570,    14,    -1,   177,    19,
     191,    13,   570,    14,    -1,   177,    19,   192,    13,   570,
      14,    -1,   177,    19,   188,    13,   172,    14,    -1,   177,
      19,   190,    13,   172,    14,    -1,   177,    19,   191,    13,
     172,    14,    -1,   177,    19,   199,    13,   568,    14,    -1,
     177,    19,   200,    13,   568,    14,    -1,   177,    19,   224,
      -1,   177,    19,   225,    -1,   570,    19,   243,   547,    -1,
     570,    19,   244,    -1,   570,    19,   245,    13,   570,    14,
      -1,   570,    19,   246,    13,   570,    14,    -1,   609,    19,
     243,   547,    -1,   609,    19,   296,   547,    -1,   609,    19,
     358,    13,   568,    14,    -1,   609,    19,   373,    13,   568,
      20,   568,    20,   568,    14,    -1,   609,    19,   374,    13,
     568,    20,   568,    20,   568,    14,    -1,   609,    19,   375,
      13,   568,    20,   568,    20,   568,    14,    -1,   609,    19,
     376,    13,   568,    14,    -1,   609,    19,   377,    13,   568,
      14,    -1,   609,    19,   379,    13,   568,    14,    -1,   609,
      19,   380,    13,   568,    14,    -1,   609,    19,   361,    13,
     568,    14,    -1,   609,    19,   359,    13,   568,    20,   568,
      20,   568,    14,    -1,   609,    19,   395,    13,   570,    14,
      -1,   609,    19,   360,    13,   589,    20,   568,    20,   568,
      14,    -1,   609,    19,   360,    13,   589,    14,    -1,   609,
      19,   381,    13,   570,    14,    -1,   609,    19,   388,    13,
     568,    14,    -1,   609,    19,   389,    -1,   609,    19,   273,
      13,   568,    14,    -1,   609,    19,   390,    13,   589,    14,
      -1,   609,    19,   393,    13,   568,    20,   568,    20,   568,
      14,    -1,   609,    19,   394,    13,   568,    20,   568,    20,
     568,    14,    -1,   609,    19,   396,    13,   568,    14,    -1,
     609,    19,   281,    13,   568,    14,    -1,   609,    19,   386,
      13,   589,    14,    -1,   609,    19,   387,    -1,   609,    19,
     342,    -1,   609,    19,   391,    -1,   609,    19,   392,    -1,
     609,    19,   341,    13,   568,    14,    -1,   609,    19,   343,
      13,   568,    14,    -1,   609,    19,   339,    -1,   609,    19,
     353,    13,   568,    14,    -1,   609,    19,   352,    13,   568,
      14,    -1,   609,    19,   352,    13,   568,    20,   568,    14,
      -1,   609,    19,   397,    13,   568,    20,   568,    20,   568,
      14,    -1,   609,    19,   398,    -1,   609,    19,   400,    13,
     568,    14,    -1,   609,    19,   399,    -1,   518,    13,   547,
      14,    -1,   519,    13,    63,    20,   568,    20,   568,    20,
     568,    20,   568,    20,   568,    20,   568,    20,   568,    20,
     568,    14,    -1,   609,    19,   511,    13,   589,    14,    -1,
      65,    19,   350,    13,   568,    20,   568,    20,   568,    14,
      -1,    65,    19,   354,    13,   610,    14,    -1,    65,   125,
     609,    -1,    65,   126,   609,    -1,    65,    19,   371,    13,
     609,    14,    -1,    65,    19,   372,    -1,    65,    19,   352,
      13,   568,    14,    -1,    65,    19,   352,    13,   568,    20,
     568,    14,    -1,    65,    19,   355,    13,   568,    14,    -1,
      65,    19,   411,    13,    65,    14,    -1,    65,    19,   412,
      13,    56,    20,   570,    14,    -1,    65,    19,   427,    13,
     568,    20,   589,    20,   568,    20,   568,    20,   568,    20,
     568,    14,    -1,    65,    19,   428,    13,   568,    14,    -1,
      65,    19,   406,    -1,    65,    19,   402,    13,   590,    14,
      -1,    65,    19,   402,    13,   590,    20,   568,    14,    -1,
      65,    19,   362,    -1,    65,    19,   365,    13,   568,    20,
     568,    20,   568,    20,   568,    14,    -1,    65,    19,   366,
      13,   568,    20,   568,    20,   568,    20,   568,    14,    -1,
      65,    19,   367,    13,   568,    20,   568,    20,   568,    20,
     568,    14,    -1,    65,    19,   368,    13,   568,    20,   568,
      20,   568,    14,    -1,    65,    19,   369,    -1,    65,    19,
     370,    -1,    65,    19,   422,    13,   568,    20,   568,    14,
      -1,   268,    13,   570,    20,   568,    20,   568,    14,    -1,
     268,    13,   570,    20,   568,    20,   568,    20,   589,    14,
      -1,   269,    13,   570,    20,   568,    20,   568,    14,    -1,
     269,    13,   570,    20,   568,    20,   568,    20,   589,    14,
      -1,   269,    13,   570,    20,   568,    20,   568,    20,   589,
      20,   568,    14,    -1,   270,    13,   570,    20,   568,    14,
      -1,   270,    13,   570,    20,   568,    20,   589,    14,    -1,
     270,    13,   570,    20,   568,    20,   568,    14,    -1,   270,
      13,   570,    20,   568,    20,   568,    20,   589,    14,    -1,
     272,    13,   570,    20,   568,    20,   568,    20,   568,    20,
     568,    20,   568,    20,   568,    14,    -1,   272,    13,   570,
      20,   568,    20,   568,    20,   568,    20,   568,    20,   568,
      20,   568,    20,   589,    14,    -1,   271,    13,   570,    20,
     568,    20,   568,    20,   589,    20,   568,    14,    -1,   273,
      13,   570,    20,   568,    14,    -1,   318,    13,    54,    20,
     570,    20,   570,    20,   570,    20,   570,    20,   570,    20,
     570,    20,   589,    14,    -1,   318,    13,    54,    20,   570,
      20,   570,    20,   570,    20,   570,    20,   570,    20,   570,
      14,    -1,   317,    13,    54,    20,   570,    20,   570,    20,
     570,    20,   589,    14,    -1,   317,    13,    54,    20,   570,
      20,   570,    20,   570,    14,    -1,   275,    13,   570,    20,
     568,    20,   568,    20,   568,    14,    -1,   570,    19,   275,
      13,   568,    20,   568,    20,   568,    14,    -1,   570,    19,
     275,    13,   570,    14,    -1,   570,    19,   276,    13,   568,
      20,   568,    20,   568,    14,    -1,   570,    19,   276,    13,
     570,    14,    -1,   570,    19,   277,    13,   568,    14,    -1,
     161,    13,   570,    20,   570,    14,    -1,   161,    13,   570,
      20,   570,    20,   570,    14,    -1,   568,    -1,   331,    13,
     568,    14,    -1,   332,    13,   568,    14,    -1,   445,    13,
     589,    20,   547,    20,   568,    14,    -1,   448,    13,   570,
      14,    -1,   316,    13,   570,    20,   570,    20,   568,    20,
     568,    20,   568,    20,   568,    20,   568,    20,   568,    14,
      -1,   489,    13,    54,    14,    -1,   173,    -1,   174,    -1,
     176,    -1,   611,   145,    90,    13,   547,    14,    -1,    75,
      19,    96,    -1,    75,    19,    98,    13,   568,    20,   568,
      14,    -1,    75,    19,    92,    -1,    75,    19,    94,    -1,
      75,    19,   116,    -1,    75,    19,   117,    -1,    75,    19,
     118,    -1,    75,    19,   101,    -1,    75,    19,   102,    -1,
      75,    19,    41,    -1,    75,    19,   119,    -1,    75,    19,
     410,    -1,    75,    19,   410,    13,   568,    14,    -1,    75,
      19,   111,    13,   568,    20,   568,    14,    -1,    75,    19,
     112,    13,    72,    14,    -1,    75,    19,   114,    13,   568,
      20,   568,    20,   568,    14,    -1,    75,    19,   113,    13,
     568,    14,    -1,    75,    19,   113,    13,   568,    20,   568,
      14,    -1,    75,    19,   120,    13,   568,    20,   568,    14,
      -1,    75,    19,   121,    13,   568,    20,   568,    14,    -1,
      75,    19,   122,    13,   568,    20,   568,    14,    -1,   521,
      13,   570,    20,   547,    14,    -1,    76,    19,    42,    -1,
      76,    19,   243,   547,    -1,   522,    -1,   523,    -1,   524,
      -1,   525,    13,   570,    20,   570,    20,   570,    20,   570,
      20,   570,    20,   570,    20,   570,    20,   568,    20,   568,
      20,   568,    20,   568,    20,   568,    20,   568,    20,   568,
      14,    -1,   526,    13,   570,    20,   570,    20,   568,    20,
     568,    20,   568,    20,   568,    20,   568,    20,   568,    20,
     570,    20,   570,    20,   568,    14,    -1,    69,    13,   542,
      14,    -1,    70,    13,   542,    14,    -1,   513,    13,   568,
      20,   568,    20,   568,    14,    -1,   547,    -1,   541,    20,
     547,    -1,    -1,   568,    -1,   542,    20,   568,    -1,   547,
      -1,   542,    20,   547,    -1,    17,    59,    -1,   542,    20,
      17,    59,    -1,    17,    60,    -1,   542,    20,    17,    60,
      -1,   589,    -1,   542,    20,   589,    -1,    17,   570,    -1,
     542,    20,    17,   570,    -1,    17,   609,    -1,   542,    20,
      17,   609,    -1,    63,    -1,   542,    20,    63,    -1,    -1,
     493,    57,    -1,   494,    57,    -1,   490,    57,    -1,   491,
      57,    -1,   492,    57,    -1,   543,    20,   493,    57,    -1,
     543,    20,   494,    57,    -1,   543,    20,   490,    57,    -1,
     543,    20,   491,    57,    -1,   543,    20,   492,    57,    -1,
      54,    -1,    62,    -1,   544,    -1,    46,    13,   547,    20,
     568,    14,    -1,    45,    13,   547,    14,    12,   568,    -1,
      45,    13,   547,    14,    12,   547,    -1,   544,    12,   547,
      -1,   544,    12,   568,    -1,   175,    -1,   570,    19,    50,
      -1,    50,    13,   612,    14,    -1,    51,    13,   612,    14,
      -1,    31,    -1,   545,    -1,   546,    10,   545,    -1,   546,
      11,   545,    -1,   546,    -1,   549,    55,   550,    -1,    -1,
      -1,    56,    -1,    32,    -1,   454,    -1,   455,    -1,    59,
      -1,    60,    -1,    61,    -1,    13,   568,    14,    -1,   551,
      -1,   570,    13,   568,    14,    -1,   570,    13,   568,    20,
     568,    14,    -1,   570,    13,   568,    20,   568,    20,   568,
      14,    -1,   570,    19,   413,    13,   568,    20,   568,    20,
     568,    14,    -1,   570,    13,   568,    20,   568,    20,   568,
      20,   568,    14,    -1,   570,    13,   568,    20,   568,    20,
     568,    23,   568,    14,    -1,   570,    13,   568,    20,   568,
      23,   568,    14,    -1,   570,    13,   568,    23,   568,    14,
      -1,   570,    19,   222,    -1,   570,    19,   611,    -1,   570,
      19,   240,    -1,    74,   240,    -1,   609,    19,   240,    -1,
     609,    19,   241,    -1,   609,    19,   242,    -1,   227,    13,
     570,    20,   570,    14,    -1,   260,    13,   570,    14,    -1,
     333,    13,   570,    20,   568,    20,   568,    20,   568,    14,
      -1,   334,    13,   570,    14,    -1,   334,    13,   568,    20,
     568,    20,   568,    20,   568,    14,    -1,   146,    13,   589,
      14,    -1,   262,    13,   589,    14,    -1,   147,    13,   589,
      14,    -1,   148,    13,   589,    14,    -1,   149,    13,   589,
      14,    -1,   150,    13,   589,    14,    -1,   147,    15,   589,
      16,    13,   589,    14,    -1,   149,    15,   589,    16,    13,
     570,    14,    -1,   150,    15,   589,    16,    13,   570,    14,
      -1,   150,    15,   589,    16,    13,   570,    20,   568,    14,
      -1,   262,    15,   589,    16,    13,   589,    14,    -1,   262,
      13,   570,    20,   589,    14,    -1,   444,    13,   547,    14,
      -1,    63,    19,   307,    -1,    63,    19,   308,    -1,    63,
      19,   305,    -1,    63,    19,   306,    -1,    63,    19,   303,
      -1,    63,    19,   304,    -1,    63,    19,   309,    -1,    63,
      19,   310,    -1,    63,    19,   311,    -1,   166,    19,   230,
      -1,   166,    19,   231,    -1,   177,    19,   178,    -1,    66,
      13,   568,    20,   568,    14,    -1,    66,    13,   568,    20,
     568,    14,   145,   568,    -1,    75,    19,    99,    13,    59,
      20,   568,    20,   568,    14,    -1,    75,    19,    99,    13,
      59,    20,   547,    20,   568,    20,   568,    14,    -1,    75,
      19,   100,    13,    60,    20,   568,    20,   568,    14,    -1,
      75,    19,   100,    13,    60,    20,   547,    20,   568,    20,
     568,    14,    -1,    75,    19,   103,    13,   547,    20,    72,
      14,    -1,    75,    19,   104,    13,    61,    14,    -1,    75,
      19,   104,    13,    61,    20,   547,    14,    -1,    75,    19,
     107,    13,    62,    20,   547,    14,    -1,    75,    19,   105,
      13,    60,    20,   568,    14,    -1,    75,    19,   105,    13,
      60,    20,   547,    14,    -1,    75,    19,   105,    13,    60,
      14,    -1,    75,    19,   106,    13,   568,    20,   547,    14,
      -1,    75,    19,   108,    13,    62,    20,   547,    14,    -1,
      75,    19,   110,    13,   547,    20,   547,    14,    -1,    75,
      19,   109,    13,    62,    20,   547,    20,   547,    20,   547,
      14,    -1,    75,    19,   115,    13,   547,    14,    -1,    75,
      19,    97,    13,   547,    14,    -1,    75,    19,    95,    -1,
      75,    19,    91,    13,   547,    14,    -1,    75,    19,    93,
      13,   547,    14,    -1,   486,    13,   611,    14,    -1,   486,
      13,   612,    14,    -1,   487,    13,   547,    14,    -1,   569,
      -1,    67,    19,   451,    13,   547,    14,    -1,    67,    19,
     452,    13,    59,    14,    -1,    67,    19,   452,    13,    62,
      14,    -1,   609,    19,   292,    -1,   147,    13,   568,    20,
     568,    14,    -1,   552,    -1,   554,   555,    -1,     9,   555,
      -1,    11,   555,    -1,    10,   555,    -1,   456,   555,    -1,
     457,   555,    -1,   467,   555,    -1,   468,   555,    -1,   469,
     555,    -1,   470,   555,    -1,   458,   555,    -1,   459,   555,
      -1,   460,   555,    -1,   461,   555,    -1,   464,   555,    -1,
     466,   555,    -1,   465,   555,    -1,     7,    -1,   527,    -1,
     553,    -1,    13,   569,    14,   553,    -1,   555,    -1,   556,
       7,   555,    -1,   556,     8,   555,    -1,   556,    12,   555,
      -1,   556,    -1,   557,    10,   556,    -1,   557,    11,   556,
      -1,   557,    -1,   558,    -1,   559,     6,   558,    -1,   559,
       5,   558,    -1,   559,   139,   558,    -1,   559,   140,   558,
      -1,   559,    -1,   560,   141,   559,    -1,   560,   142,   559,
      -1,   547,   141,   547,    -1,   547,   142,   547,    -1,   560,
      -1,   561,    17,   560,    -1,   561,    -1,   562,     4,   561,
      -1,   562,    -1,   563,    18,   562,    -1,   563,    -1,   564,
     137,   563,    -1,   564,    -1,   565,   138,   564,    -1,   565,
      -1,   565,    21,   565,    22,   566,    -1,   566,    -1,   567,
      -1,   433,    -1,   434,    -1,   435,    -1,   436,    -1,   437,
      -1,   438,    -1,   439,    -1,   440,    -1,   441,    -1,   442,
      -1,   570,    19,   443,    -1,    58,    -1,    78,    15,   568,
      16,    -1,    35,   547,    -1,    35,    13,   547,    14,    -1,
      36,    13,   568,    20,   568,    20,   569,    20,   568,    20,
     547,    20,   568,    20,   568,    14,    -1,    36,    13,   568,
      20,   568,    20,   568,    20,   569,    20,   568,    20,   547,
      14,    -1,    36,    13,   568,    20,   568,    20,   568,    20,
     569,    20,   568,    20,   568,    20,   547,    14,    -1,   312,
      13,   547,    14,    -1,   313,    13,   547,    14,    -1,    71,
      13,   542,    14,    -1,    35,    -1,    35,    13,   569,    20,
     568,    20,   568,    20,   568,    14,    -1,    35,    13,   569,
      20,   568,    20,   568,    20,   568,    20,   568,    14,    -1,
      35,    13,   569,    20,   568,    20,   570,    14,    -1,   570,
      -1,   570,    15,   568,    16,    -1,   263,    13,   589,    20,
     568,    14,    -1,   264,    13,   589,    20,   568,    14,    -1,
     265,    13,   589,    20,   568,    14,    -1,   266,    13,   589,
      20,   589,    20,   568,    14,    -1,   267,    13,   589,    20,
     589,    20,   568,    14,    -1,   147,    13,   589,    20,   589,
      14,    -1,   151,    13,   570,    20,    54,    14,    -1,   151,
      13,   570,    20,    54,    20,   569,    14,    -1,   151,    13,
     570,    20,   570,    20,    54,    14,    -1,   151,    13,   570,
      20,   570,    20,    54,    20,   569,    14,    -1,   151,    13,
     570,    20,   570,    20,   570,    20,    54,    14,    -1,   151,
      13,   570,    20,   570,    20,   570,    20,    54,    20,   569,
      14,    -1,   152,    13,   589,    20,   568,    20,   568,    20,
     568,    20,   568,    14,    -1,   504,    19,   505,    13,   570,
      20,   568,    20,   568,    14,    -1,   345,    13,   570,    14,
      -1,   171,    13,   570,    20,   568,    20,   568,    20,   568,
      14,    -1,   346,    13,   570,    14,    -1,   247,    13,   589,
      20,   568,    14,    -1,   248,    13,   570,    14,    -1,   249,
      13,   570,    14,    -1,   250,    13,   570,    14,    -1,   251,
      13,   570,    20,   570,    20,   568,    20,   568,    20,   568,
      14,    -1,   252,    13,   570,    14,    -1,   253,    13,   570,
      20,   570,    20,   570,    20,   568,    20,   570,    14,    -1,
     254,    13,   570,    20,   570,    20,   570,    20,   568,    20,
     570,    14,    -1,   255,    13,   570,    20,   570,    20,   570,
      20,   568,    20,   570,    20,   568,    20,   568,    14,    -1,
     256,    13,   570,    20,   570,    20,   570,    20,   568,    20,
     570,    20,   568,    20,   568,    20,   568,    20,   568,    14,
      -1,   257,    13,   570,    20,   570,    20,   570,    20,   570,
      14,    -1,   257,    13,   570,    20,   570,    20,   570,    20,
     570,    20,   568,    14,    -1,   258,    13,   570,    14,    -1,
     258,    13,   570,    20,   570,    14,    -1,   259,    13,   570,
      20,   570,    14,    -1,   153,    13,   589,    20,   568,    14,
      -1,   154,    13,   570,    14,    -1,   170,    13,   570,    14,
      -1,   155,    13,   570,    20,   568,    14,    -1,   274,    13,
     570,    14,    -1,   156,    13,   570,    20,   568,    14,    -1,
     157,    13,   570,    20,   568,    14,    -1,   160,    13,   589,
      20,   568,    14,    -1,   570,    15,   613,    16,    -1,   570,
      15,    22,    20,    22,    20,   568,    22,   568,    16,    -1,
     158,    13,   570,    20,   568,    20,   568,    20,   568,    20,
     568,    20,   568,    20,   568,    14,    -1,   162,    13,   570,
      20,   568,    20,   568,    20,   568,    14,    -1,   162,    13,
     570,    20,   568,    20,   568,    14,    -1,   162,    13,   570,
      20,   568,    20,   568,    20,   568,    20,   568,    14,    -1,
     163,    13,   570,    20,   568,    20,   568,    20,   568,    14,
      -1,   163,    13,   570,    20,   568,    20,   568,    14,    -1,
     163,    13,   570,    20,   568,    20,   568,    20,   568,    20,
     568,    14,    -1,   164,    13,   570,    20,   568,    20,   568,
      14,    -1,   164,    13,   570,    20,   568,    20,   568,    20,
     568,    20,   568,    14,    -1,   165,    13,   570,    20,   568,
      20,   568,    14,    -1,   165,    13,   570,    20,   568,    20,
     568,    20,   568,    20,   568,    14,    -1,   166,    19,    52,
      -1,   166,    19,    53,    -1,   177,    19,   222,    13,   570,
      20,   568,    14,    -1,   177,    19,   222,    13,   570,    20,
     570,    14,    -1,   177,    19,    52,    -1,   177,    19,   187,
      13,   570,    14,    -1,   166,    13,   570,    20,   568,    20,
     568,    20,   568,    20,   568,    14,    -1,   211,    13,   570,
      20,   570,    20,   568,    20,   568,    20,   568,    14,    -1,
     168,    13,   570,    20,   568,    20,   568,    20,   568,    20,
     568,    20,   568,    14,    -1,   167,    13,   570,    20,   568,
      20,   568,    20,   568,    20,   568,    14,    -1,   212,    19,
     222,    13,   570,    20,   568,    20,   568,    20,   568,    14,
      -1,   213,    19,   222,    13,   570,    20,   568,    20,   568,
      20,   568,    20,   568,    20,   568,    14,    -1,   214,    13,
     570,    14,    -1,   215,    13,   570,    20,   568,    20,   568,
      14,    -1,   215,    13,   570,    20,   568,    20,   568,    20,
     613,    14,    -1,   215,    13,   570,    20,   568,    20,   568,
      20,   568,    20,   613,    14,    -1,   216,    13,   570,    20,
     568,    20,   568,    20,   613,    14,    -1,   216,    13,   570,
      20,   568,    20,   568,    20,   568,    20,   613,    14,    -1,
     217,    13,   570,    20,   568,    20,   568,    20,   613,    14,
      -1,   218,    13,   570,    20,   568,    20,   568,    20,   568,
      20,   613,    14,    -1,   219,    13,   570,    20,   568,    20,
     568,    20,   568,    20,   613,    14,    -1,   220,    13,   570,
      20,   568,    20,   568,    20,   568,    20,   568,    20,   613,
      14,    -1,   221,    13,   570,    20,   568,    20,   568,    20,
     568,    20,   568,    14,    -1,   226,    13,   570,    20,   568,
      20,   568,    14,    -1,   261,    13,   570,    20,   568,    20,
     568,    20,   568,    20,   568,    20,   568,    14,    -1,   429,
      13,   570,    14,    -1,   430,    13,   570,    14,    -1,   431,
      13,   570,    14,    -1,   432,    13,   570,    14,    -1,    65,
      19,   348,    -1,    65,    19,   349,    -1,    63,    19,   348,
      -1,   283,    13,   570,    20,   568,    14,    -1,   284,    13,
     570,    20,   568,    14,    -1,   285,    13,   570,    20,   568,
      14,    -1,   286,    13,   570,    20,   568,    14,    -1,   209,
      13,   589,    20,   589,    20,   568,    14,    -1,   210,    13,
     589,    20,   589,    20,   568,    20,   568,    20,   568,    20,
     568,    14,    -1,   209,    13,   589,    20,   589,    20,   568,
      20,   568,    20,   568,    14,    -1,   209,    13,   589,    20,
     589,    20,   568,    20,   568,    20,   568,    20,   568,    14,
      -1,   209,    13,   589,    20,   589,    20,   570,    20,   568,
      20,   568,    14,    -1,   314,    13,   570,    20,   570,    14,
      -1,   315,    13,   570,    20,   570,    20,   589,    14,    -1,
     319,    13,   570,    20,   568,    20,   568,    20,   568,    14,
      -1,   320,    13,   570,    20,   568,    20,   568,    20,   568,
      14,    -1,   320,    13,   570,    20,   568,    20,   568,    20,
     568,    20,   568,    14,    -1,   321,    13,   570,    20,   568,
      14,    -1,   322,    13,   570,    20,   568,    14,    -1,   323,
      13,   570,    20,   568,    14,    -1,   324,    13,   570,    20,
     568,    14,    -1,   325,    13,   570,    20,   568,    14,    -1,
     326,    13,   570,    20,   568,    14,    -1,   327,    13,   570,
      20,   568,    14,    -1,   328,    13,   570,    20,   568,    14,
      -1,   328,    13,   570,    20,   568,    20,   568,    14,    -1,
     329,    13,   570,    20,   568,    20,   568,    20,   568,    14,
      -1,   330,    13,   589,    14,    -1,   570,    13,   589,    14,
      -1,   446,    13,   589,    20,   568,    20,   568,    20,   568,
      14,    -1,   447,    13,   589,    20,   568,    20,   568,    20,
     568,    14,    -1,   498,    13,   589,    14,    -1,   498,    13,
     589,    20,   568,    14,    -1,   501,    13,   589,    20,   568,
      14,    -1,   499,    13,   589,    20,   568,    20,   568,    20,
     568,    20,   568,    14,    -1,   500,    13,   570,    20,   570,
      20,   568,    20,   568,    20,   568,    20,   568,    20,   568,
      20,   568,    20,   568,    20,   568,    20,   568,    20,   568,
      20,   568,    20,   568,    14,    -1,   503,    13,   589,    20,
     568,    20,   568,    14,    -1,   609,    19,   383,    13,    14,
      -1,   609,    19,   293,    13,   568,    14,    -1,   609,    19,
     384,    13,    14,    -1,   609,    19,   385,    13,    14,    -1,
     609,    19,   382,    13,   570,    14,    -1,   509,    13,   589,
      20,   568,    14,    -1,   509,    13,   589,    14,    -1,   510,
      13,   589,    20,   568,    14,    -1,   510,    13,   589,    14,
      -1,   515,    13,   589,    20,   589,    14,    -1,   516,    13,
     589,    14,    -1,   517,    13,   547,    14,    -1,   488,    13,
     589,    20,   568,    20,   568,    20,   568,    20,   568,    20,
     568,    20,   568,    20,   568,    14,    -1,   291,    13,   609,
      20,   570,    20,   589,    14,    -1,   295,    13,   609,    20,
     547,    14,    -1,   571,    -1,    13,   589,    14,    -1,   572,
      -1,   573,    -1,   554,   575,    -1,    11,   575,    -1,    10,
     575,    -1,   456,   575,    -1,   457,   575,    -1,   467,   575,
      -1,   468,   575,    -1,   469,   575,    -1,   470,   575,    -1,
     458,   575,    -1,   459,   575,    -1,   460,   575,    -1,   461,
     575,    -1,   464,   575,    -1,   466,   575,    -1,   465,   575,
      -1,   471,   575,    -1,   574,    -1,    13,   569,    14,   574,
      -1,   575,    -1,   576,     7,   555,    -1,   576,     8,   555,
      -1,   576,     7,   575,    -1,   576,     8,   575,    -1,   576,
       4,   575,    -1,   576,    -1,   577,    -1,   578,    10,   556,
      -1,   578,    11,   556,    -1,   578,    10,   576,    -1,   578,
      11,   576,    -1,   578,    -1,   579,    -1,   580,     6,   579,
      -1,   580,     5,   579,    -1,   580,   139,   579,    -1,   580,
     140,   579,    -1,   580,     6,   558,    -1,   580,     5,   558,
      -1,   580,   139,   558,    -1,   580,   140,   558,    -1,   580,
      -1,   581,   141,   580,    -1,   581,   142,   580,    -1,   581,
     141,   558,    -1,   581,   142,   558,    -1,   581,    -1,   582,
      17,   581,    -1,   582,    -1,   583,    -1,   584,    18,   583,
      -1,   584,    -1,   585,   137,   584,    -1,   585,    -1,   586,
     138,   585,    -1,   586,    -1,   586,    21,   586,    22,   587,
      -1,   587,    -1,   574,   145,   588,    -1,   588,    -1,    76,
      -1,    65,    19,   401,    -1,   403,    13,    76,    20,    76,
      20,   568,    14,    -1,    37,    13,   547,    14,    -1,   404,
      13,   568,    20,   568,    14,    -1,    66,    -1,   405,    13,
     608,    14,    -1,   591,    -1,    13,   608,    14,    -1,   592,
      -1,   593,    -1,   554,   595,    -1,    11,   595,    -1,    10,
     595,    -1,   595,   143,    -1,   456,   595,    -1,   457,   595,
      -1,   467,   595,    -1,   468,   595,    -1,   469,   595,    -1,
     470,   595,    -1,   458,   595,    -1,   459,   595,    -1,   460,
     595,    -1,   461,   595,    -1,   464,   595,    -1,   466,   595,
      -1,   465,   595,    -1,   594,    -1,   595,    -1,   596,     7,
     555,    -1,   596,   144,   595,    -1,   596,     7,   595,    -1,
     596,    -1,   597,    10,   556,    -1,   597,    11,   556,    -1,
     597,    10,   596,    -1,   597,    11,   596,    -1,   597,    -1,
     598,    -1,   599,    -1,   600,    -1,   601,    -1,   602,    -1,
     603,    -1,   604,    -1,   605,    -1,   606,    -1,   607,    -1,
      64,    -1,    77,    15,   568,    16,    -1,   335,    13,   589,
      20,   568,    14,    -1,   338,    13,   570,    20,   568,    14,
      -1,   335,    13,   589,    20,   568,    20,   570,    14,    -1,
     344,    13,   589,    20,   568,    20,   589,    14,    -1,   339,
      13,   609,    14,    -1,   339,    13,   609,    20,   568,    14,
      -1,   340,    13,   570,    20,   568,    14,    -1,   341,    13,
     609,    20,   568,    14,    -1,   343,    13,   609,    20,   568,
      14,    -1,   347,    13,    14,    -1,   347,   547,    -1,   347,
      13,   547,    14,    -1,   347,    -1,   294,    13,   547,    14,
      -1,   294,    13,   547,    20,   568,    14,    -1,   609,    -1,
     278,    13,   570,    14,    -1,   279,    13,   609,    14,    -1,
     279,    13,   609,    20,   568,    20,   568,    20,   568,    14,
      -1,   280,    13,   609,    20,   568,    14,    -1,   287,    13,
     609,    20,   568,    20,   568,    20,   568,    20,   568,    20,
     568,    20,   568,    14,    -1,   288,    13,   589,    20,   568,
      20,   568,    20,   568,    20,   568,    20,   568,    20,   568,
      20,   568,    14,    -1,   289,    13,   589,    20,   568,    20,
     568,    20,   568,    14,    -1,   290,    13,   589,    20,   568,
      20,   568,    20,   568,    20,   568,    20,   568,    20,   568,
      20,   568,    20,   568,    14,    -1,   290,    13,   589,    20,
     568,    20,   568,    20,   568,    20,   568,    20,   568,    14,
      -1,   609,    19,   282,    13,   568,    20,   568,    14,    -1,
     506,    13,   589,    14,    -1,   506,    13,   589,    20,   568,
      14,    -1,   506,    13,   589,    20,   568,    20,   568,    14,
      -1,   508,    13,   589,    20,   568,    20,   568,    14,    -1,
     507,    13,   589,    20,   568,    20,   568,    20,   589,    20,
     589,    14,    -1,   507,    13,   589,    20,   568,    20,   568,
      20,   589,    20,   589,    20,   589,    20,   568,    14,    -1,
     512,    13,   589,    20,   589,    20,   589,    20,   568,    20,
     568,    20,   568,    20,   568,    14,    -1,   512,    13,   589,
      20,   589,    20,   589,    20,   568,    20,   568,    20,   568,
      20,   568,    20,   568,    14,    -1,   512,    13,   589,    20,
     589,    20,   589,    20,   568,    20,   568,    20,   568,    14,
      -1,   512,    13,   589,    20,   568,    20,   568,    20,   568,
      20,   568,    20,   568,    14,    -1,   514,    13,   589,    20,
     589,    20,   589,    20,   568,    20,   568,    20,   568,    20,
     568,    14,    -1,   514,    13,   589,    20,   589,    20,   589,
      20,   568,    20,   568,    20,   568,    20,   568,    20,   589,
      20,   589,    14,    -1,    57,    -1,    60,    -1,    59,    -1,
      61,    -1,   570,    -1,    63,    -1,    64,    -1,    65,    -1,
      67,    -1,    68,    -1,    69,    -1,    70,    -1,    71,    -1,
      72,    -1,    73,    -1,    74,    -1,    62,    -1,    66,    -1,
      76,    -1,    75,    -1,    77,    -1,    78,    -1,   568,    22,
     568,    20,   568,    22,   568,    20,   568,    22,   568,    -1,
     568,    22,   568,    20,   568,    22,   568,    -1,   570,    -1,
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
     476,   478,   481,   484,   487,   490,   493,   496,   501,   506,
     509,   512,   515,   518,   520,   525,   529,   532,   535,   546,
     553,   557,   564,   571,   580,   609,   618,   627,   631,   640,
     653,   660,   667,   684,   693,   710,   721,   728,   739,   748,
     759,   774,   783,   796,   803,   812,   819,   826,   833,   844,
     851,   862,   873,   886,   893,   900,   913,   920,   927,   934,
     941,   948,   955,   962,   969,   976,   983,   990,   997,  1006,
    1010,  1014,  1018,  1022,  1026,  1030,  1043,  1060,  1067,  1074,
    1081,  1088,  1095,  1102,  1109,  1116,  1123,  1130,  1141,  1148,
    1163,  1170,  1179,  1186,  1193,  1202,  1209,  1220,  1227,  1234,
    1241,  1248,  1255,  1262,  1269,  1276,  1283,  1290,  1297,  1301,
    1305,  1310,  1314,  1321,  1328,  1333,  1338,  1345,  1356,  1367,
    1378,  1385,  1392,  1399,  1406,  1413,  1424,  1431,  1442,  1449,
    1456,  1463,  1467,  1474,  1481,  1492,  1503,  1510,  1517,  1524,
    1528,  1532,  1536,  1540,  1547,  1554,  1558,  1565,  1572,  1581,
    1592,  1596,  1603,  1607,  1612,  1633,  1640,  1651,  1658,  1662,
    1666,  1673,  1677,  1684,  1693,  1700,  1707,  1716,  1733,  1740,
    1744,  1751,  1760,  1764,  1777,  1790,  1803,  1814,  1818,  1822,
    1831,  1840,  1851,  1860,  1871,  1884,  1891,  1900,  1909,  1920,
    1937,  1956,  1969,  1976,  1995,  2012,  2025,  2036,  2047,  2058,
    2065,  2076,  2083,  2090,  2097,  2106,  2108,  2113,  2118,  2127,
    2132,  2151,  2156,  2158,  2160,  2162,  2169,  2173,  2182,  2186,
    2190,  2194,  2198,  2202,  2206,  2210,  2214,  2218,  2222,  2229,
    2238,  2245,  2256,  2263,  2272,  2281,  2290,  2299,  2306,  2310,
    2315,  2317,  2319,  2321,  2352,  2377,  2382,  2387,  2396,  2398,
    2402,  2403,  2405,  2409,  2411,  2415,  2418,  2423,  2426,  2431,
    2433,  2437,  2440,  2445,  2448,  2453,  2455,  2459,  2460,  2463,
    2466,  2469,  2472,  2475,  2480,  2485,  2490,  2495,  2500,  2502,
    2504,  2506,  2513,  2520,  2527,  2531,  2535,  2537,  2541,  2546,
    2551,  2553,  2555,  2559,  2563,  2565,  2569,  2570,  2571,  2573,
    2575,  2577,  2579,  2581,  2583,  2585,  2589,  2591,  2596,  2603,
    2612,  2623,  2634,  2645,  2654,  2661,  2665,  2669,  2673,  2676,
    2680,  2684,  2688,  2695,  2700,  2711,  2716,  2727,  2732,  2737,
    2742,  2747,  2752,  2757,  2765,  2773,  2781,  2791,  2799,  2806,
    2811,  2815,  2819,  2823,  2827,  2831,  2835,  2839,  2843,  2847,
    2851,  2855,  2859,  2866,  2875,  2886,  2899,  2910,  2923,  2932,
    2939,  2948,  2957,  2966,  2975,  2982,  2991,  3000,  3009,  3022,
    3029,  3036,  3040,  3047,  3054,  3059,  3064,  3069,  3071,  3078,
    3085,  3092,  3096,  3103,  3105,  3108,  3111,  3114,  3117,  3120,
    3123,  3126,  3129,  3132,  3135,  3138,  3141,  3144,  3147,  3150,
    3153,  3156,  3158,  3160,  3162,  3167,  3169,  3173,  3177,  3181,
    3183,  3187,  3191,  3193,  3195,  3199,  3203,  3207,  3211,  3213,
    3217,  3221,  3225,  3229,  3231,  3235,  3237,  3241,  3243,  3247,
    3249,  3253,  3255,  3259,  3261,  3267,  3269,  3271,  3273,  3275,
    3277,  3279,  3281,  3283,  3285,  3287,  3289,  3291,  3295,  3297,
    3302,  3305,  3310,  3327,  3342,  3359,  3364,  3369,  3374,  3376,
    3387,  3400,  3409,  3411,  3416,  3423,  3430,  3437,  3446,  3455,
    3462,  3469,  3478,  3487,  3498,  3509,  3522,  3535,  3546,  3551,
    3562,  3567,  3574,  3579,  3584,  3589,  3602,  3607,  3620,  3633,
    3650,  3671,  3682,  3695,  3700,  3707,  3714,  3721,  3726,  3731,
    3738,  3743,  3750,  3757,  3764,  3769,  3780,  3797,  3808,  3817,
    3830,  3841,  3850,  3863,  3872,  3885,  3894,  3907,  3911,  3915,
    3924,  3933,  3937,  3944,  3957,  3970,  3985,  3998,  4011,  4028,
    4033,  4042,  4053,  4066,  4077,  4090,  4101,  4114,  4127,  4142,
    4155,  4164,  4179,  4184,  4189,  4194,  4199,  4203,  4207,  4211,
    4218,  4225,  4232,  4239,  4248,  4263,  4276,  4291,  4304,  4311,
    4320,  4331,  4342,  4355,  4362,  4369,  4376,  4383,  4390,  4397,
    4404,  4411,  4420,  4431,  4436,  4441,  4452,  4463,  4468,  4475,
    4482,  4495,  4526,  4535,  4541,  4548,  4554,  4560,  4567,  4574,
    4579,  4586,  4591,  4598,  4603,  4608,  4627,  4636,  4643,  4645,
    4649,  4651,  4653,  4656,  4659,  4662,  4665,  4668,  4671,  4674,
    4677,  4680,  4683,  4686,  4689,  4692,  4695,  4698,  4701,  4704,
    4706,  4711,  4713,  4717,  4721,  4725,  4729,  4733,  4735,  4737,
    4741,  4745,  4749,  4753,  4755,  4757,  4761,  4765,  4769,  4773,
    4777,  4781,  4785,  4789,  4791,  4795,  4799,  4803,  4807,  4809,
    4813,  4815,  4817,  4821,  4823,  4827,  4829,  4833,  4835,  4841,
    4843,  4847,  4849,  4851,  4855,  4864,  4869,  4876,  4878,  4883,
    4885,  4889,  4891,  4893,  4896,  4899,  4902,  4905,  4908,  4911,
    4914,  4917,  4920,  4923,  4926,  4929,  4932,  4935,  4938,  4941,
    4944,  4946,  4948,  4952,  4956,  4960,  4962,  4966,  4970,  4974,
    4978,  4980,  4982,  4984,  4986,  4988,  4990,  4992,  4994,  4996,
    4998,  5000,  5002,  5007,  5014,  5021,  5030,  5039,  5044,  5051,
    5058,  5065,  5072,  5076,  5079,  5084,  5086,  5091,  5098,  5100,
    5105,  5110,  5121,  5128,  5145,  5164,  5175,  5196,  5211,  5220,
    5225,  5232,  5241,  5250,  5263,  5280,  5297,  5316,  5331,  5346,
    5363,  5384,  5386,  5388,  5390,  5392,  5394,  5396,  5398,  5400,
    5402,  5404,  5406,  5408,  5410,  5412,  5414,  5416,  5418,  5420,
    5422,  5424,  5426,  5428,  5440,  5448,  5450
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   959,   959,   960,   964,   964,   965,   966,   967,   967,
     968,   968,   969,   969,   970,   970,   971,   971,   972,   972,
     975,   976,   981,  1000,  1023,  1058,  1087,  1102,  1125,  1124,
    1154,  1153,  1194,  1213,  1235,  1242,  1277,  1283,  1292,  1302,
    1310,  1320,  1334,  1348,  1362,  1372,  1388,  1408,  1421,  1433,
    1444,  1455,  1467,  1478,  1498,  1520,  1532,  1543,  1548,  1558,
    1581,  1590,  1602,  1620,  1642,  1655,  1674,  1687,  1706,  1719,
    1738,  1752,  1772,  1805,  1822,  1827,  1831,  1835,  1840,  1844,
    1859,  1869,  1880,  1883,  1933,  1953,  1998,  2010,  2022,  2062,
    2075,  2110,  2140,  2160,  2164,  2168,  2172,  2176,  2180,  2184,
    2188,  2192,  2196,  2201,  2205,  2216,  2229,  2239,  2248,  2259,
    2267,  2279,  2528,  2538,  2548,  2558,  2568,  2622,  2630,  2638,
    2647,  2657,  2663,  2674,  2680,  2687,  2693,  2703,  2713,  2729,
    2741,  2751,  2799,  2814,  2835,  2866,  2881,  2888,  2895,  2913,
    2936,  2941,  2946,  2959,  2970,  2979,  2989,  2997,  3014,  3030,
    3047,  3067,  3082,  3100,  3113,  3127,  3136,  3150,  3161,  3174,
    3192,  3214,  3242,  3272,  3304,  3309,  3327,  3332,  3337,  3342,
    3347,  3352,  3366,  3381,  3398,  3412,  3432,  3437,  3442,  3449,
    3458,  3466,  3471,  3478,  3483,  3488,  3508,  3532,  3537,  3542,
    3547,  3552,  3557,  3562,  3567,  3572,  3577,  3582,  3587,  3592,
    3597,  3602,  3607,  3612,  3625,  3630,  3635,  3643,  3648,  3653,
    3658,  3663,  3668,  3673,  3678,  3683,  3688,  3693,  3698,  3703,
    3707,  3734,  3747,  3752,  3756,  3762,  3775,  3781,  3787,  3793,
    3800,  3807,  3814,  3823,  3834,  3849,  3864,  3872,  3879,  3886,
    3892,  3896,  3900,  3937,  3943,  3950,  3957,  3968,  3976,  3993,
    4003,  4008,  4015,  4022,  4030,  4038,  4057,  4073,  4090,  4107,
    4112,  4117,  4122,  4127,  4135,  4236,  4270,  4277,  4285,  4291,
    4298,  4308,  4317,  4324,  4331,  4341,  4348,  4362,  4376,  4384,
    4389,  4397,  4405,  4416,  4428,  4440,  4452,  4458,  4467,  4476,
    4489,  4496,  4507,  4529,  4555,  4583,  4593,  4606,  4616,  4638,
    4667,  4684,  4699,  4706,  4728,  4747,  4765,  4779,  4784,  4789,
    4798,  4803,  4812,  4826,  4833,  4840,  4842,  4859,  4875,  4914,
    4927,  4971,  4976,  4981,  4986,  4992,  5016,  5026,  5041,  5047,
    5054,  5060,  5066,  5072,  5078,  5093,  5104,  5110,  5124,  5138,
    5155,  5162,  5183,  5201,  5220,  5240,  5260,  5280,  5287,  5292,
    5298,  5303,  5308,  5313,  5348,  5375,  5382,  5389,  5411,  5419,
    5436,  5440,  5447,  5454,  5462,  5470,  5479,  5486,  5493,  5500,
    5507,  5514,  5521,  5528,  5535,  5542,  5549,  5559,  5564,  5573,
    5580,  5587,  5594,  5601,  5608,  5615,  5622,  5629,  5637,  5642,
    5657,  5663,  5677,  5693,  5709,  5725,  5741,  5765,  5769,  5780,
    5798,  5808,  5809,  5819,  5827,  5830,  5841,  5842,  5845,  5846,
    5854,  5862,  5871,  5875,  5879,  5883,  5891,  5892,  5907,  5923,
    5937,  5952,  5969,  5985,  5999,  6012,  6033,  6093,  6118,  6140,
    6159,  6166,  6174,  6179,  6184,  6212,  6218,  6229,  6248,  6267,
    6286,  6305,  6324,  6343,  6366,  6388,  6411,  6418,  6442,  6465,
    6473,  6483,  6493,  6503,  6513,  6523,  6533,  6547,  6564,  6580,
    6585,  6590,  6594,  6601,  6609,  6644,  6682,  6699,  6719,  6731,
    6748,  6768,  6801,  6820,  6842,  6858,  6876,  6900,  6921,  6949,
    6963,  6973,  6986,  7000,  7015,  7023,  7031,  7043,  7047,  7062,
    7069,  7079,  7091,  7104,  7105,  7106,  7107,  7108,  7109,  7110,
    7111,  7112,  7113,  7114,  7122,  7123,  7124,  7125,  7126,  7138,
    7150,  7166,  7167,  7171,  7173,  7189,  7190,  7191,  7192,  7196,
    7197,  7198,  7202,  7207,  7208,  7209,  7210,  7211,  7215,  7216,
    7217,  7218,  7219,  7223,  7224,  7232,  7233,  7237,  7241,  7248,
    7252,  7259,  7263,  7270,  7271,  7278,  7282,  7288,  7293,  7297,
    7301,  7305,  7309,  7313,  7317,  7321,  7325,  7329,  7337,  7342,
    7359,  7365,  7371,  7429,  7483,  7539,  7560,  7581,  7595,  7624,
    7632,  7651,  7677,  7690,  7768,  7835,  7843,  7851,  7861,  7871,
    7901,  7919,  7939,  7957,  7977,  7995,  8014,  8054,  8069,  8083,
    8099,  8122,  8136,  8150,  8164,  8178,  8213,  8227,  8248,  8269,
    8310,  8356,  8373,  8392,  8406,  8420,  8434,  8453,  8468,  8483,
    8500,  8521,  8538,  8554,  8566,  8595,  8615,  8660,  8672,  8683,
    8696,  8708,  8719,  8745,  8772,  8804,  8821,  8839,  8852,  8865,
    8885,  8908,  8922,  8937,  8971,  9008,  9043,  9076,  9093,  9110,
    9124,  9145,  9168,  9192,  9217,  9242,  9264,  9286,  9310,  9353,
    9377,  9409,  9432,  9469,  9506,  9543,  9578,  9583,  9592,  9597,
    9608,  9618,  9628,  9637,  9658,  9688,  9714,  9743,  9776,  9787,
    9803,  9813,  9823,  9838,  9852,  9866,  9879,  9892,  9904,  9916,
    9928,  9939,  9952,  9979, 10012, 10128, 10152, 10194, 10206, 10215,
   10224, 10247, 10272, 10285, 10295, 10332, 10350, 10368, 10378, 10388,
   10396, 10404, 10412, 10437, 10457, 10465, 10499, 10522, 10542, 10542,
   10544, 10546, 10547, 10548, 10549, 10550, 10551, 10552, 10553, 10554,
   10555, 10556, 10557, 10558, 10559, 10560, 10561, 10562, 10563, 10577,
   10578, 10600, 10601, 10607, 10609, 10610, 10611, 10614, 10619, 10620,
   10621, 10622, 10623, 10626, 10630, 10631, 10632, 10633, 10634, 10635,
   10636, 10637, 10638, 10642, 10643, 10644, 10645, 10646, 10650, 10651,
   10656, 10660, 10661, 10665, 10666, 10670, 10671, 10675, 10676, 10680,
   10681, 10684, 10688, 10698, 10711, 10722, 10739, 10746, 10756, 10771,
   10771, 10773, 10775, 10776, 10777, 10778, 10779, 10788, 10789, 10790,
   10791, 10792, 10793, 10794, 10795, 10796, 10797, 10798, 10799, 10800,
   10804, 10806, 10807, 10808, 10809, 10819, 10820, 10821, 10822, 10823,
   10826, 10830, 10834, 10838, 10843, 10847, 10851, 10855, 10859, 10863,
   10866, 10871, 10876, 10892, 10903, 10913, 10933, 10967, 10976, 10985,
   10994, 11003, 11011, 11017, 11023, 11029, 11055, 11069, 11085, 11095,
   11113, 11141, 11168, 11183, 11206, 11240, 11272, 11319, 11360, 11384,
   11394, 11417, 11429, 11442, 11479, 11522, 11570, 11622, 11665, 11693,
   11726, 11769, 11773, 11774, 11775, 11776, 11780, 11781, 11782, 11783,
   11784, 11785, 11786, 11787, 11788, 11789, 11790, 11791, 11792, 11793,
   11794, 11795, 11796, 11801, 11809, 11816, 11832
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
  const int Parser::yylast_ = 16628;
  const int Parser::yynnts_ = 86;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 401;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 528;

  const unsigned int Parser::yyuser_token_number_max_ = 781;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // yyip

/* Line 1054 of lalr1.cc  */
#line 20806 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"


/* Line 1056 of lalr1.cc  */
#line 11852 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"

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





